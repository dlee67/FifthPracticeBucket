package main

import (
    "context"
    "fmt"
    "log"

	"go.mongodb.org/mongo-driver/mongo"
	"go.mongodb.org/mongo-driver/mongo/options"
	"go.mongodb.org/mongo-driver/bson"
)

type Student struct {
    Name   string   `bson:"name"`
	Alias  string   `bson:"alias"`
	SpecialInterest string `bson:"specialization"`
	Note   string `bson:"note"`
}

func main() {
    clientOptions := options.Client().ApplyURI("mongodb://localhost:27017")
    client, err := mongo.Connect(context.TODO(), clientOptions)
	if err != nil {
		panic(err)
	}

    err = client.Ping(context.TODO(), nil)
    
    if err != nil {
		log.Fatal(err)
	}
    fmt.Println("Connected to MongoDB successfully")
    
    collection := client.Database("students").Collection("cs")

    if err != nil {
		log.Fatal(err)
    }
    
    queryResult := &Student{}
    filter := bson.M{"name": "Economic", "specialization": "None"}
    result := collection.FindOne(context.TODO(), filter)
    err = result.Decode(queryResult)
    
    if err != nil {
		log.Fatal(err)
	}

    fmt.Println("Note: ", queryResult.Note)
    err = client.Disconnect(context.TODO())
	if err != nil {
		panic(err)
	}
	fmt.Println("Disconnected from MongoDB")
}