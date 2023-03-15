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
function changeUrl(ev, item) {
    ev.preventDefault();
    var iFrame = document.querySelector("#main-frame");
    iFrame.src = item.href;
}
window.onload = function () {
    document.querySelector("a#lien-accueil").click();
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
