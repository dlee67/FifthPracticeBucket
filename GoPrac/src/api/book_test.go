package api

import (
	"testing"
	"github.com/stretchr/testify/assert"
)

func TestBookToJSON(t *testing.T) {
	book := Book{Title: "Assembly Language Step-by-Step, Third Edition", Author: "Jeff Duntemann", ISBN: "978-0470497029"}
	json := book.ToJSON() 

	assert.Equal(t, "{\"title\":\"Assembly Language Step-by-Step, Third Edition\",\"author\":\"Jeff Duntemann\",\"isbn\":\"978-0470497029\"}", 
		string(json), "Book JSON marshalling wrong.")
}

func TestBookFromJSON(t *testing.T) {
	json := []byte(`{"title": "Assembly Language Step-by-Step, Third Edition", "author": "Jeff Duntemann", "isbn": "978-0470497029"}`)
	book := FromJSON(json)

	assert.Equal(t, Book{Title: "Assembly Language Step-by-Step, Third Edition", Author: "Jeff Duntemann", ISBN: "978-0470497029"}, 
		book, "Book JSON unmarshalling wrong.")
}