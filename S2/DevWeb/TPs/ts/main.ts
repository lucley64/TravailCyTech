window.onload = () => {
    const links: NodeListOf<HTMLAnchorElement> | null = document.querySelectorAll("body>div#menu>ul>li>a");

    links.forEach(l => l.href = window.location.href + l.getAttribute("link"));

}

function changeContent(ev: MouseEvent) {
    const iframe: HTMLIFrameElement | null = document.querySelector("#main-frame");
    ev.preventDefault;

    const elem: HTMLAnchorElement = ev.target as HTMLAnchorElement;

    const lnk = elem.getAttribute("link");

    if (iframe && lnk) {
        iframe.src = lnk;
    }
}