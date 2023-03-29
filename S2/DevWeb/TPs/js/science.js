var lens;
var result;
var image;
function openTab(elem) {
    var tab = elem.innerHTML;
    var tabs = document.querySelectorAll("div.tab");
    tabs.forEach(function (tab) { return tab.hidden = true; });
    var btns = document.querySelectorAll("div#tab-buttons>button.menu");
    btns.forEach(function (btn) {
        btn.className = "menu";
    });
    elem.className += " active";
    var openTab = document.getElementById(tab);
    openTab.hidden = false;
}
var stock = true;
function afficherStock() {
    stock = !stock;
    var colStocks = document.querySelectorAll(".qte");
    colStocks.forEach(function (elem) { return elem.hidden = stock; });
}
function addCmd(elem) {
    var _a, _b, _c;
    var inp = elem.previousElementSibling;
    var qtestr = (_c = (_b = (_a = elem.parentElement) === null || _a === void 0 ? void 0 : _a.parentElement) === null || _b === void 0 ? void 0 : _b.parentElement) === null || _c === void 0 ? void 0 : _c.getElementsByClassName("qte")[0].textContent;
    if (qtestr && parseInt(inp.value) < parseInt(qtestr))
        inp.value = parseInt(inp.value) + 1 + "";
    var btn = inp.previousElementSibling;
    btn.disabled = false;
    if (qtestr && parseInt(inp.value) == parseInt(qtestr)) {
        elem.disabled = true;
    }
}
function remCmd(elem) {
    var inp = elem.nextElementSibling;
    if (parseInt(inp.value) > 0)
        inp.value = parseInt(inp.value) - 1 + "";
    var btn = inp.nextElementSibling;
    btn.disabled = false;
    if (parseInt(inp.value) == 0) {
        elem.disabled = true;
    }
}
function moveLens(ev) {
    ev.preventDefault();
    if (this instanceof HTMLImageElement)
        image = this;
    lens.hidden = false;
    result.hidden = false;
    result.style.backgroundImage = "url('" + image.src + "')";
    var cx = result.offsetWidth / lens.offsetWidth;
    var cy = result.offsetHeight / lens.offsetHeight;
    result.style.backgroundSize = (image.width * cx) + "px " + (image.height * cy) + "px";
    var pos = getCursorPos(image, ev);
    var x = pos.x - lens.offsetWidth / 2;
    var y = pos.y - lens.offsetHeight / 2;
    if (x > image.width - lens.offsetWidth)
        x = image.width - lens.offsetWidth;
    if (x < 0)
        x = 0;
    if (y > image.height - lens.offsetHeight)
        y = image.height - lens.offsetHeight;
    if (y < 0)
        y = 0;
    result.style.backgroundPosition = "-" + (x * cx) + "px -" + (y * cy) + "px";
    result.style.top = ev.clientY - result.offsetHeight - 10 + "px";
    result.style.left = ev.clientX + 10 + "px";
    x += image.x;
    y += image.y;
    lens.style.left = x + "px";
    lens.style.top = y + "px";
}
function getCursorPos(elem, ev) {
    var a = elem.getBoundingClientRect();
    var x = ev.pageX - a.left;
    var y = ev.pageY - a.top;
    x = x - window.scrollX;
    y = y - window.scrollY;
    return { x: x, y: y };
}
function term() {
    lens.hidden = true;
    result.hidden = true;
}
window.onload = function () {
    lens = document.getElementById("zoomLens");
    lens.addEventListener("mousemove", moveLens);
    lens.addEventListener("mouseleave", term);
    result = document.getElementById("zoomImage");
    var imgs = document.querySelectorAll(".image");
    imgs.forEach(function (image) {
        image.addEventListener("mousemove", moveLens);
    });
    document.querySelector("#this-btn").click();
};
