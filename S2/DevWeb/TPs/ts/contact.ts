window.onload = () => {
    const form: HTMLFormElement = document.querySelector("#formContact") as HTMLFormElement;
    form.onsubmit = (ev: SubmitEvent) => {
        const form = ev.currentTarget as HTMLFormElement;
        const elems = form.elements;

        const nom = elems.namedItem("nomContact") as HTMLInputElement;

        const nomValid = nom.value.length > 0;

        if (!nomValid) {
            (nom.nextElementSibling as HTMLSpanElement).innerHTML = "Erreur cet element est requis";
            (nom.nextElementSibling as HTMLSpanElement).className = "error active";
            nom.className = "invalid";
        }

        const prenom = elems.namedItem("prenomContact") as HTMLInputElement;

        const prenomValid = prenom.value.length > 0;

        if (!prenomValid) {
            (prenom.nextElementSibling as HTMLSpanElement).innerHTML = "Erreur cet element est requis";
            (prenom.nextElementSibling as HTMLSpanElement).className = "error active";
            prenom.className = "invalid";
        }

        const mail = elems.namedItem("mailContact") as HTMLInputElement;

        const mailValid = mail.value.length > 0 && mail.value.match(/^[a-zA-Z0-9.!#$%&'*+\/=?^_`{|}~-]+@[a-zA-Z0-9-]+(?:\.[a-zA-Z0-9-]+)*$/);

        if (!mailValid) {
            (mail.nextElementSibling as HTMLSpanElement).innerHTML = "Erreur cet element est requis";
            (mail.nextElementSibling as HTMLSpanElement).className = "error active";
            mail.className = "invalid";
        }

        const dateNaiss = elems.namedItem("dateNaiss") as HTMLInputElement;

        const dateNaissValid = new Date(dateNaiss.value) < new Date()

        if (!dateNaissValid) {
            (dateNaiss.nextElementSibling as HTMLSpanElement).innerHTML = "Erreur la date doit être inférieur à aujourd'hui";
            (dateNaiss.nextElementSibling as HTMLSpanElement).className = "error active";
            dateNaiss.className = "invalid";
        }

        const sujet = elems.namedItem("sujetContact") as HTMLInputElement;

        const sujetValid = sujet.value.length > 0;

        if (!sujetValid) {
            (sujet.nextElementSibling as HTMLSpanElement).innerHTML = "Erreur cet element est requis";
            (sujet.nextElementSibling as HTMLSpanElement).className = "error active";
            sujet.className = "invalid";
        }


        const contenu = elems.namedItem("contenuContact") as HTMLTextAreaElement;

        const contenuValid = contenu.value.length > 0;

        if (!contenuValid) {
            (contenu.nextElementSibling as HTMLSpanElement).innerHTML = "Erreur cet element est requis";
            (contenu.nextElementSibling as HTMLSpanElement).className = "error active";
            contenu.className = "invalid";
        }

        if (!(nomValid && prenomValid && mailValid && dateNaissValid && sujetValid && contenuValid)) {
            ev.preventDefault();
        }
    }

    const inputs = document.querySelectorAll("input[type=text],select,textarea,input[type=email],input[type=date]") as NodeListOf<HTMLInputElement|HTMLTextAreaElement>;
    inputs.forEach(inp =>{
        inp.oninput = (ev) => {
            const elem = ev.target as HTMLInputElement|HTMLTextAreaElement;
            const cont = elem.nextElementSibling as HTMLSpanElement;
            cont.innerText = "";
            cont.className = "error";
            elem.className = "";
        }
    })
}
