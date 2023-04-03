window.onload = function () {
    var form = document.querySelector("#formContact");
    form.onsubmit = function (ev) {
        ev.preventDefault();
        console.log(ev);
        var form = ev.currentTarget;
        var elems = form.elements;
        var nom = elems.namedItem("nomContact");
        var nomValid = nom.value.match(/^[A-Z]([a-z]|-[A-Z])*/g);
    };
};
