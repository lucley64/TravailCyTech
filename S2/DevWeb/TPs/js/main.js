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
        btn.disabled = false;
    });
    ev.target.className += " active";
    ev.target.disabled = true;
    window.history.replaceState(null, document.title, updateUrlParameter(window.location.href, "menu", link));
}
window.onload = function () {
    document.querySelector("#this").click();
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
function updateUrlParameter(url, param, value) {
    var newUrl = "";
    var tempArray = url.split("?");
    var additionalUrl = tempArray[1];
    var temp = "";
    if (additionalUrl) {
        tempArray = additionalUrl.split("?");
        for (var i = 0; i < tempArray.length; i++) {
            if (tempArray[i].split('=')[0] != param) {
                newUrl += temp + tempArray[i];
                temp = "&";
            }
        }
    }
    var rows_txt = temp + "" + param + "=" + value;
    return "?" + newUrl + rows_txt;
}
