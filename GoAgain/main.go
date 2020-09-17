package main

import (
   "encoding/json"
   "fmt"
   "github.com/google/uuid"
   "gopkg.in/oauth2.v3/models"
   "log"
   "net/http"

   "gopkg.in/oauth2.v3/errors"
   "gopkg.in/oauth2.v3/manage"
   "gopkg.in/oauth2.v3/server"
   "gopkg.in/oauth2.v3/store"
)

// Pretty much the below tutorial with my comments.
// https://hackernoon.com/build-your-own-oauth2-server-in-go-7d0f660732c3

func main() {
	// https://godoc.org/gopkg.in/oauth2.v3/manage#NewDefaultManager
   manager := manage.NewDefaultManager()
   // https://godoc.org/gopkg.in/oauth2.v3/manage#Manager.SetAuthorizeCodeTokenCfg
   manager.SetAuthorizeCodeTokenCfg(manage.DefaultAuthorizeCodeTokenCfg) // https://godoc.org/gopkg.in/go-oauth2/oauth2.v3/manage
   // They don't have explanation on DefaultAuthorizeCodeTokenCfg
   // https://godoc.org/gopkg.in/oauth2.v3/manage#Manager.SetAuthorizeCodeTokenCfg
   manager.MustTokenStorage(store.NewMemoryTokenStore()) // Can't seemed to find any doc on NewMemoryTokenStore().
   // https://godoc.org/gopkg.in/oauth2.v3/store
   clientStore := store.NewClientStore()
   // https://godoc.org/gopkg.in/go-oauth2/oauth2.v3/manage#Manager.MapClientStorage
   manager.MapClientStorage(clientStore)

   //https://godoc.org/gopkg.in/oauth2.v3/server#NewDefaultServer
   //Will actually create a server that's specific to OAuth
   srv := server.NewDefaultServer(manager)
   srv.SetAllowGetAccessRequest(true) // Once again, no documentation on SetAllowGetAccessRequest() ...
   //https://godoc.org/gopkg.in/go-oauth2/oauth2.v3/server#Server.SetClientInfoHandler
   srv.SetClientInfoHandler(server.ClientFormHandler) // https://godoc.org/gopkg.in/go-oauth2/oauth2.v3/server#ClientFormHandler
   
   //https://godoc.org/gopkg.in/oauth2.v3/manage#Manager.SetRefreshTokenCfg
   manager.SetRefreshTokenCfg(manage.DefaultRefreshTokenCfg)

   srv.SetInternalErrorHandler(func(err error) (re *errors.Response) {
      log.Println("Internal Error:", err.Error())
      return
   })

   srv.SetResponseErrorHandler(func(re *errors.Response) {
      log.Println("Response Error:", re.Error.Error())
   })

   http.HandleFunc("/token", func(w http.ResponseWriter, r *http.Request) {
	  srv.HandleTokenRequest(w, r) // https://godoc.org/gopkg.in/oauth2.v3/server#Server.HandleTokenRequest
								// Decodes all the necessary data from the payload
	// Must call the above REST API with URL like ...
	// http://localhost:9096/token?grant_type=client_credentials&client_id=YOUR_CLIENT_ID&client_secret=YOUR_CLIENT_SECRET&scope=all															
   })

   http.HandleFunc("/credentials", func(w http.ResponseWriter, r *http.Request) {
	  // Creates two random strings
      clientId := uuid.New().String()[:8]
	  clientSecret := uuid.New().String()[:8]
	  
	  // Saves those two random strings to clientStore
      err := clientStore.Set(clientId, &models.Client{
         ID:     clientId,
         Secret: clientSecret,
         Domain: "http://localhost:9094",
      })
      if err != nil {
         fmt.Println(err.Error())
      }

      w.Header().Set("Content-Type", "application/json")
      json.NewEncoder(w).Encode(map[string]string{"CLIENT_ID": clientId, "CLIENT_SECRET": clientSecret})
   })

   http.HandleFunc("/protected", validateToken(func(w http.ResponseWriter, r *http.Request) {
      w.Write([]byte("Hello, I'm protected"))
   }, srv))

   log.Fatal(http.ListenAndServe(":9096", nil))
}

func validateToken(f http.HandlerFunc, srv *server.Server) http.HandlerFunc {
   return http.HandlerFunc(func(w http.ResponseWriter, r *http.Request) {
      _, err := srv.ValidationBearerToken(r) // https://godoc.org/gopkg.in/go-oauth2/oauth2.v3/server#Server.ValidationBearerToken
      if err != nil {
         http.Error(w, err.Error(), http.StatusBadRequest)
         return
      }

      f.ServeHTTP(w, r)
   })
}