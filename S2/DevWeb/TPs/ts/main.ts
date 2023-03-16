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

function changeUrl(ev: MouseEvent, link: string) {
    ev.preventDefault();
    const iFrame: HTMLIFrameElement = document.querySelector("#main-frame") as HTMLIFrameElement;
    iFrame.src = link;
    const btns: NodeListOf<HTMLButtonElement> = document.querySelectorAll("button.nav");
    btns.forEach(btn => {
        btn.className = "nav";
    });
    (ev.target as HTMLButtonElement).className += " active";

}

window.onload = () => {
    (document.querySelector("#lien-accueil") as HTMLAnchorElement).click();
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