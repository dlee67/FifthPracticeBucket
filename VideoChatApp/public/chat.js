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
var userStream

var iceServers = {
    iceServers: [
        { urls: "stun:stun.services.mozilla.com"},
        { urls: "stun:stun1.l.google.com:19302"}
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
        userStream = stream
        divVideoChatLobby.style = "display:none"
        userVideo.srcObject = stream;
        userVideo.onloadedmetadata = function(e) {
            userVideo.play()
        };
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
        rtcPeerConnection.addTrack(userStream.getTracks()[0], userStream)
        rtcPeerConnection.addTrack(userStream.getTracks()[1], userStream)
        // https://webrtc.org/getting-started/peer-connections-advanced
        rtcPeerConnection.createOffer().then(offer => {
            rtcPeerConnection.setLocalDescription(offer)
            socket.emit("offer", offer, roomName)
        });
        // The below is used in the tutorial, but the function is deprecated.
        // rtcPeerConnection.createOffer(function(offer){
        //     socket.emit("offer", offer, roomName)
        // }, function(error){
        //     console.log(error)
        // })
    }
})
socket.on("candidate", function(candidate){
    var icecandidate = new RTCPeerConnection(candidate)
    rtcPeerConnection.addIceCandidate(icecandidate)
})

socket.on("offer", function(offer){
    if(!creator) {
        rtcPeerConnection = new RTCPeerConnection(iceServers)
        rtcPeerConnection.onicecandidate = OnIceCandidateFunction
        rtcPeerConnection.ontrack = OnTrackFunction
        rtcPeerConnection.addTrack(userStream.getTracks()[0], userStream)
        rtcPeerConnection.addTrack(userStream.getTracks()[1], userStream)
        rtcPeerConnection.setRemoteDescription(offer);
        // https://webrtc.org/getting-started/peer-connections-advanced
        rtcPeerConnection.createAnswer().then(answer => {
            rtcPeerConnection.setLocalDescription(answer)
            socket.emit("answer", answer, roomName)
        });
    }
})
socket.on("answer", function(answer, roomName){
    rtcPeerConnection.setRemoteDescription(answer);  
    socket.broadcast.to(roomName).emit("answer", answer)
})

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