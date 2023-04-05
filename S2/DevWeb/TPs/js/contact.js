window.onload = function () {
    var form = document.querySelector("#formContact");
    form.onsubmit = function (ev) {
        var form = ev.currentTarget;
        var elems = form.elements;
        var nom = elems.namedItem("nomContact");
        var nomValid = nom.value.length > 0;
        if (!nomValid) {
            nom.nextElementSibling.innerHTML = "Erreur cet element est requis";
            nom.nextElementSibling.className = "error active";
            nom.className = "invalid";
        }
        var prenom = elems.namedItem("prenomContact");
        var prenomValid = prenom.value.length > 0;
        if (!prenomValid) {
            prenom.nextElementSibling.innerHTML = "Erreur cet element est requis";
            prenom.nextElementSibling.className = "error active";
            prenom.className = "invalid";
        }
        var mail = elems.namedItem("mailContact");
        var mailValid = mail.value.length > 0 && mail.value.match(/^[a-zA-Z0-9.!#$%&'*+\/=?^_`{|}~-]+@[a-zA-Z0-9-]+(?:\.[a-zA-Z0-9-]+)*$/);
        if (!mailValid) {
            mail.nextElementSibling.innerHTML = "Erreur cet element est requis";
            mail.nextElementSibling.className = "error active";
            mail.className = "invalid";
        }
        var dateNaiss = elems.namedItem("dateNaiss");
        var dateNaissValid = new Date(dateNaiss.value) < new Date();
        if (!dateNaissValid) {
            dateNaiss.nextElementSibling.innerHTML = "Erreur la date doit être inférieur à aujourd'hui";
            dateNaiss.nextElementSibling.className = "error active";
            dateNaiss.className = "invalid";
        }
        var sujet = elems.namedItem("sujetContact");
        var sujetValid = sujet.value.length > 0;
        if (!sujetValid) {
            sujet.nextElementSibling.innerHTML = "Erreur cet element est requis";
            sujet.nextElementSibling.className = "error active";
            sujet.className = "invalid";
        }
        var contenu = elems.namedItem("contenuContact");
        var contenuValid = contenu.value.length > 0;
        if (!contenuValid) {
            contenu.nextElementSibling.innerHTML = "Erreur cet element est requis";
            contenu.nextElementSibling.className = "error active";
            contenu.className = "invalid";
        }
        if (!(nomValid && prenomValid && mailValid && dateNaissValid && sujetValid && contenuValid)) {
            ev.preventDefault();
        }
    };
    var inputs = document.querySelectorAll("input[type=text],select,textarea,input[type=email],input[type=date]");
    inputs.forEach(function (inp) {
        inp.oninput = function (ev) {
            var elem = ev.target;
            var cont = elem.nextElementSibling;
            cont.innerText = "";
            cont.className = "error";
            elem.className = "";
        };
    });
};
