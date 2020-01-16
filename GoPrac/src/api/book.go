package api

import (
	"encoding/json"
	"net/http"
)

type Book struct {
	Title string `json:"title"` // In a textual form, the memember would look like { "title": ... }
	Author string `json:"author"`
	ISBN string `json:"isbn"`
}

var Books = []Book{
	Book{Title: "Testing Angular Applications", Author: "Michael Giambalvo, Jesse Palmer, Craig Nishina, Corinna Cohn", ISBN: "9781617293641"},
	Book{Title: "Embedded Android", Author: "Karim Yaghmour", ISBN: "9781449308292"},
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


func BooksHandleFunc(w http.ResponseWriter, r *http.Request) {
	b, err := json.Marshal(Books)
	if err != nil {
		panic(err)
	}
	w.Header().Add("Content-Type", "application/json; charset=utf-8")
	w.Write(b)
}