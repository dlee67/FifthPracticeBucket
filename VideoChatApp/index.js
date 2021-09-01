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
            // https://socket.io/docs/v4/emitting-events/
            socket.emit("created")
        } else if (room.size == 1) {
            socket.join(roomName)
            socket.emit("joined")
        } else {
            socket.emit("full")
        }
        console.log(rooms)
    })

    // Following the pattern of creating signaling server.
    socket.on("ready", function (roomName) {
        console.log("Ready")
        socket.broadcast.to(roomName).emit("ready")
    })

    socket.on("candidate", function(candidate, roomName) {
        console.log("candidate")
        socket.broadcast.to(roomName).emit("candidate", candidate)
    })
    
    socket.on("offer", function (offer, roomName) {
        console.log("offer")
        socket.broadcast.to(roomName).emit("offer", offer)
    })

    socket.on("answer", function (candidate, roomName) {
        console.log("answer")
        socket.broadcast.to(roomName).emit("answer", candidate)
    })
})