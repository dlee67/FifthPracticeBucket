var socket = io.connect("http://localhost:4000")
var divVideoChatLobby = document.getElementById("video-chat-lobby");
var divVideoChat = document.getElementById("video-chat-room");
var joinButton = document.getElementById("join");
var userVideo = document.getElementById("user-video");
var peerVideo = document.getElementById("peer-video");
var roomInput = document.getElementById("roomName");
var roomName = roomInput.value
var creator = false
var rtcPeerConnection

var iceServers = {
    iceServers: [
        { urls: "stun:stun.services.mozilla.com"},
        { urls: "stun1.l.google.com:19302"}
    ],
}

joinButton.addEventListener("click", function() {
    if (roomInput.value == "") {
        alert("Please enter a room name")
    } else {
        socket.emit("join", roomName)
    }
})

// Only the user that initially created the room will emit this signal.
socket.on("created", function(){
    creator = true

    navigator.mediaDevices
    .getUserMedia({
        // In all obviousness, when the audio: false, then, you don't get any sounds during the video chat.
        audio: true,
        video: true,
    })
    .then(function (stream){
        divVideoChatLobby.style = "display:none"
    })
    .catch(function(err) {
        alert("Couldn't Access User Media")
    })
})

socket.on("joined", function(){
    creator = false
    navigator.mediaDevices
    .getUserMedia({
        // In all obviousness, when the audio: false, then, you don't get any sounds during the video chat.
        audio: true,
        video: true,
    })
    .then(function(stream) {
        userStream = stream
        divVideoChatLobby.style = "display:none"
        userVideo.srcObject = stream;
        userVideo.onloadedmetadata = function(e) {
            userVideo.play()
        };
    })
    .catch(function(err) {
        alert("Couldn't Access User Media")
    });
})

socket.on("full", function(){
    alert("Room is full, can't join")
})
socket.on("ready", function(){
    if(creator) {
        rtcPeerConnection = new RTCPeerConnection(iceServers)
        rtcPeerConnection.onicecandidate = OnIceCandidateFunction
        rtcPeerConnection.ontrack = OnTrackFunction
    }
})
socket.on("candidate", function(){})
socket.on("offer", function(){})
socket.on("answer", function(){})

function OnIceCandidateFunction(event) {
    if(event.candidate) {
        socket.emit("candidate", event.candidate, roomName)
    }
}

function OnTrackFunction(event) {
    peerVideo.srcObject = event.streams[0];
    peerVideo.onloadedmetadata = function(e) {
        peerVideo.play()
    };
}