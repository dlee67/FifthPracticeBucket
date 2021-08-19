const express = require("express");
const socket = require("socket.io");
const app = express();

var server = app.listen(4000, function () {
    console.log("Server is running")
});

app.use(express.static("public"))

var io = socket(server)

// https://socket.io/docs/v4/listening-to-events/#socket-on-eventName-listener
// https://socket.io/docs/v3/server-api/index.html (look for Event: ‘connection’)
io.on("connection", function(socket) {
    // https://socket.io/docs/v3/server-api/index.html (look for socket.id)
    console.log("User Connected :" + socket.id)
    // https://socket.io/docs/v3/server-api/index.html#socket-on-eventName-callback
    socket.on("join", function(roomName) {
        // https://socket.io/docs/v4/adapter/
        // https://socket.io/docs/v4/rooms/
        var rooms = io.sockets.adapter.rooms;
        var room = io.sockets.adapter.rooms.get(roomName);
        if (room == undefined) {
            // https://socket.io/docs/v3/rooms/index.html
            socket.join(roomName)
            console.log("Room created")
        } else if (room.size == 1) {
            socket.join(roomName)
            console.log("Room joined")
        } else {
            console.log("Room Full for now")
        }
        console.log(rooms)
    })
})