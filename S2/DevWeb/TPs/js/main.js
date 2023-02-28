window.onload = function () {
    var links = document.querySelectorAll("body>div#menu>ul>li>a");
    links.forEach(function (l) { return l.href = window.location.href + l.getAttribute("link"); });
};
function changeContent(ev) {
    var iframe = document.querySelector("#main-frame");
    ev.preventDefault;
    var elem = ev.target;
    var lnk = elem.getAttribute("link");
    if (iframe && lnk) {
        iframe.src = lnk;
    }
}
