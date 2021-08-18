const express = require("express");
const socket = require("socket.io");
const app = express();

var server = app.listen(4000, function () {
    console.log("Server is running")
});

app.use(express.static("public"))

var io = socket(server)

io.on("connection", function(socket) {
    console.log("User Connected :" + socket.id)

    socket.on("join", function(roomName) {
        var rooms = io.sockets.adapter.rooms;
        var room = io.sockets.adapter.rooms.get(roomName);
        if (room == undefined) {
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