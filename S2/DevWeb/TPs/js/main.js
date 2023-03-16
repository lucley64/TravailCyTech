function resizeIFrameToFitContent(iFrame) {
    if (iFrame.contentWindow) {
        var size = iFrame.contentWindow.document.body.scrollHeight + 50;
        if (size > window.innerHeight) {
            iFrame.height = size + "px";
        }
        else {
            iFrame.height = window.innerHeight + "px";
        }
    }
}
function changeUrl(ev, link) {
    ev.preventDefault();
    var iFrame = document.querySelector("#main-frame");
    iFrame.src = link;
    var btns = document.querySelectorAll("button.nav");
    btns.forEach(function (btn) {
        btn.className = "nav";
    });
    ev.target.className += " active";
}
window.onload = function () {
    document.querySelector("#lien-accueil").click();
    if (window.innerWidth >= 750)
        document.querySelector("button#navBtn").click();
};
window.onchange = function () {
    if (window.innerWidth >= 750)
        document.querySelector("button#navBtn").click();
};
function toggleNav(elem) {
    elem.hidden = !elem.hidden;
}
