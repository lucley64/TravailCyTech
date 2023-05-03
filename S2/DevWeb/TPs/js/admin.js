function iframeTo(elem) {
    var iframe = document.querySelector("#main");
    iframe.src = "tables.php?table=" + elem.innerHTML;
}
window.onload = function () {
    var tab = document.querySelector("table");
    if (tab) {
        var check = tab.querySelector("input[type=checkbox]");
        console.log(check);
    }
};
