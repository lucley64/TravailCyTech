function resizeIFrameToFitContent(iFrame) {
    if (iFrame.contentWindow)
        iFrame.height = iFrame.contentWindow.document.body.scrollHeight + 50 + "px";
}
function changeUrl(ev, item) {
    ev.preventDefault();
    var iFrame = document.querySelector("#main-frame");
    iFrame.src = item.href;
}
window.onload = function () {
    document.querySelector("#lien-accueil").click();
};
