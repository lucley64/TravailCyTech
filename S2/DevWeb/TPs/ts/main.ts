function resizeIFrameToFitContent(iFrame: HTMLIFrameElement) {
    if (iFrame.contentWindow) {
        const size = iFrame.contentWindow.document.body.scrollHeight + 50;
        if (size > window.innerHeight){
            iFrame.height = size + "px";
        }
        else{
            iFrame.height = window.innerHeight + "px";
        }
    }
}

function changeUrl(ev: MouseEvent, item: HTMLAnchorElement) {
    ev.preventDefault();
    const iFrame: HTMLIFrameElement = document.querySelector("#main-frame") as HTMLIFrameElement;
    iFrame.src = item.href;

}

window.onload = () => {
    (document.querySelector("a#lien-accueil") as HTMLAnchorElement).click();
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