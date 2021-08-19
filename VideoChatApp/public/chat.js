let socket = io.connect("http://localhost:4000")
let divVideoChatLobby = document.getElementById("video-chat-lobby");
let divVideoChat = document.getElementById("video-chat-room");
let joinButton = document.getElementById("join");
let userVideo = document.getElementById("user-video");
let peerVideo = document.getElementById("peer-video");
let roomInput = document.getElementById("roomName");

joinButton.addEventListener("click", function() {
    if (roomInput.value == "") {
        alert("Please enter a room name")
    } else {
        // https://socket.io/docs/v4/emitting-events/
        socket.emit("join", roomInput.value)
        navigator.getUserMedia(
            {
                // In all obviousness, when the audio: false, then, you don't get any sounds during the video chat.
                audio: true,
                video: true,
            },
            function(stream) {
                divVideoChatLobby.style = "display:none"
                userVideo.srcObject = stream;
                userVideo.onloadedmetadata = function(e) {
                    userVideo.play()
                };
            },
            function() {
                alert("Couldn't Access User Media")
            }
        )
    }
})