function openTab(tab) {
    var tabs = document.querySelectorAll("div.tab");
    tabs.forEach(function (tab) { return tab.hidden = true; });
    var openTab = document.getElementById(tab);
    openTab.hidden = false;
}
var stock = true;
function afficherStock() {
    stock = !stock;
    var colStocks = document.querySelectorAll(".qte");
    colStocks.forEach(function (elem) { return elem.hidden = stock; });
}
