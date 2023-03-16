window.onload = function () {
    var _a, _b, _c;
    var errorCont = document.getElementById("ErrorContainer");
    var inp = document.getElementById(((_a = errorCont === null || errorCont === void 0 ? void 0 : errorCont.children[0]) === null || _a === void 0 ? void 0 : _a.getAttribute("name")) + "");
    if ((inp === null || inp === void 0 ? void 0 : inp.name) == "genreContact") {
        (_b = inp === null || inp === void 0 ? void 0 : inp.parentElement) === null || _b === void 0 ? void 0 : _b.insertBefore(errorCont, inp.previousElementSibling);
    }
    else {
        (_c = inp === null || inp === void 0 ? void 0 : inp.parentNode) === null || _c === void 0 ? void 0 : _c.insertBefore(errorCont, inp);
    }
    var form = document.getElementById("submitBtn");
    form.onclick = function (ev) {
        var genreDiv = document.getElementById("genreContactDiv");
        var genreInp = document.getElementById("genreContact");
        genreDiv.childNodes.forEach(function (val) {
            var inp = val;
            if (inp.checked) {
                genreInp.value = inp.id;
            }
        });
    };
};
