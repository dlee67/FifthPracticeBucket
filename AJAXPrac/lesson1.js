// https://developer.mozilla.org/en-US/docs/Glossary/AJAX
// https://developer.mozilla.org/en-US/docs/Web/API/XMLHttpRequest

var output = document.querySelector("#output");
var xhr = new XMLHttpRequest();
var url = "https://api.chucknorris.io/jokes/random";
xhr.onreadystatechange = function() {
    console.log(xhr.readyState);
    if(xhr.readyState == 4) {
        console.log(xhr.response);
        var str = xhr.responseText;
        var obj = JSON.parse(str);
        output.innerHTML = obj.value + '<img src="'+obj.icon_url+'">';
        console.log(obj);
    }
}
xhr.open("GET", url);
xhr.send();
console.log(xhr);