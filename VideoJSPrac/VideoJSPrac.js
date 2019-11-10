console.log('VideoJSPrac invoked.');
const videojs = require('./node_modules/video.js/dist/video.cjs');
var video = videojs(document.querySelector('#my-video'), {
    controlbar: {
        fullscreenToggle: false
    }
});