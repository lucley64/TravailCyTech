function openTab(tab: string) {
    const tabs: NodeListOf<HTMLDivElement> = document.querySelectorAll("div.tab");
    tabs.forEach(tab => tab.hidden = true);
    const openTab: HTMLDivElement = document.getElementById(tab) as HTMLDivElement;
    openTab.hidden = false;
}

var stock: boolean = true;
function afficherStock() {
    stock = !stock;
    const colStocks: NodeListOf<HTMLElement> = document.querySelectorAll(".qte");
    colStocks.forEach(elem => elem.hidden = stock);
}