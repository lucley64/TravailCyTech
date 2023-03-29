function resizeIFrameToFitContent(iFrame: HTMLIFrameElement) {
    if (iFrame.contentWindow) {
        const size = iFrame.contentWindow.document.body.scrollHeight + 50;
        if (size > window.innerHeight) {
            iFrame.height = size + "px";
        }
        else {
            iFrame.height = window.innerHeight + "px";
        }
    }
}

function changeUrl(ev: MouseEvent, link: string) {
    ev.preventDefault();
    const iFrame: HTMLIFrameElement = document.querySelector("#main-frame") as HTMLIFrameElement;
    iFrame.src = link;
    const btns: NodeListOf<HTMLButtonElement> = document.querySelectorAll("button.nav");
    btns.forEach(btn => {
        btn.className = "nav";
        btn.disabled = false;
    });
    (ev.target as HTMLButtonElement).className += " active";
    (ev.target as HTMLButtonElement).disabled = true;
    window.history.replaceState(null, document.title, updateUrlParameter(window.location.href, "menu", link));

}

window.onload = () => {
    (document.querySelector("#this") as HTMLAnchorElement).click();
    if (window.innerWidth >= 750)
        (document.querySelector("button#navBtn") as HTMLButtonElement).click();
}

window.onchange = () => {
    if (window.innerWidth >= 750)
        (document.querySelector("button#navBtn") as HTMLButtonElement).click();
}

function toggleNav(elem: HTMLElement) {
    elem.hidden = !elem.hidden;
}

function updateUrlParameter(url: string, param: string, value: string){
    var newUrl = "";
    var tempArray = url.split("?");
    const additionalUrl = tempArray[1];
    var temp = "";
    if (additionalUrl){
        tempArray = additionalUrl.split("?");
        for (var i = 0; i < tempArray.length; i++){
            if (tempArray[i].split('=')[0] != param){
                newUrl += temp + tempArray[i];
                temp = "&";
            }
        }
    }
    const rows_txt = temp + "" + param + "=" + value;
    return "?" + newUrl + rows_txt;
}