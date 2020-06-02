const WebSocket = require('ws');

var exampleSocket = new WebSocket("ws://localhost:8080/", "protocolOne");
exampleSocket.onopen = function (event) {
    exampleSocket.send("Here's some text that the server is urgently awaiting!");
}
exampleSocket.onmessage = function (event) {
    console.debug("Client received: ", event.data);
}