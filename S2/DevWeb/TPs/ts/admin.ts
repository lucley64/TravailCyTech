function iframeTo(elem: HTMLButtonElement){
    const iframe = document.querySelector("#main") as HTMLIFrameElement;
    iframe.src = "tables.php?table="+elem.innerHTML;
}

window.onload = () => {
    const tab = document.querySelector("table") as HTMLTableElement;
    if (tab) {
        const check = tab.querySelectorAll("input[type=checkbox]") as NodeListOf<HTMLInputElement>;
        console.log(check);
        
    }
}