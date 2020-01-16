package api

import (
	"encoding/json"
	"net/http"
	"io/ioutil"
)

type Book struct {
	Title string `json:"title"` // In a textual form, the memember would look like { "title": ... }
	Author string `json:"author"`
	ISBN string `json:"isbn"`
}

var Books = map[string]Book{
	"9781617293641": Book{Title: "Testing Angular Applications", Author: "Michael Giambalvo, Jesse Palmer, Craig Nishina, Corinna Cohn", ISBN: "9781617293641"},
	"9781449308292": Book{Title: "Embedded Android", Author: "Karim Yaghmour", ISBN: "9781449308292"},
}

// ToJSON to be used for marshalling of Book type
func (b Book) ToJSON() []byte {
	ToJSON, err := json.Marshal(b)
	if err != nil {
		panic(err)
	}
	return ToJSON
}

// FromJSON to be used for unmarshalling of Book type
func FromJSON(data []byte) Book {
	book := Book{}
	err := json.Unmarshal(data, &book)
	if err != nil {
		panic(err)
	}
	return book
}


// BooksHandleFunc to be used as http.HandleFunc for Book API
func BooksHandleFunc(w http.ResponseWriter, r *http.Request) {
	switch method := r.Method; method {
	case http.MethodGet:
		books := AllBooks()
		writeJSON(w, books)
	case http.MethodPost:
		body, err := ioutil.ReadAll(r.Body)
		if err != nil {
			w.WriteHeader(http.StatusInternalServerError)
		}
		book := FromJSON(body)
		isbn, created := CreateBook(book)
		if created {
			w.Header().Add("Location", "/api/books/"+isbn)
			w.WriteHeader(http.StatusCreated)
		} else {
			w.WriteHeader(http.StatusConflict)
		}
	default:
		w.WriteHeader(http.StatusBadRequest)
		w.Write([]byte("Unsupported request method."))
	}
}

// CreateBook creates a new Book if it does not exist
func CreateBook(book Book) (string, bool) {
	_, exists := Books[book.ISBN]
	if exists {
		return "", false
	}
	Books[book.ISBN] = book
	return book.ISBN, true
}

// AllBooks returns a slice of all books
func AllBooks() []Book {
	values := make([]Book, len(Books))
	idx := 0
	for _, book := range Books {
		values[idx] = book
		idx++
	}
	return values
}

func writeJSON(w http.ResponseWriter, i interface{}) {
	b, err := json.Marshal(i)
	if err != nil {
		panic(err)
	}
	w.Header().Add("Content-Type", "application/json; charset=utf-8")
	w.Write(b)
}