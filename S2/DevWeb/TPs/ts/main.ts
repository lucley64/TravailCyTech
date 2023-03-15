function resizeIFrameToFitContent(iFrame: HTMLIFrameElement) {
    if (iFrame.contentWindow)
        iFrame.height = iFrame.contentWindow.document.body.scrollHeight + 50 + "px";
}

function changeUrl(ev: MouseEvent, item: HTMLAnchorElement){
    ev.preventDefault();
    const iFrame: HTMLIFrameElement = document.querySelector("#main-frame") as HTMLIFrameElement;
    iFrame.src = item.href;
    
}

window.onload = () => {
    (document.querySelector("#lien-accueil") as HTMLAnchorElement).click();
}