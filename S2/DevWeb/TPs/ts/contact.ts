window.onload = () => {
    const errorCont: HTMLDivElement = document.getElementById("ErrorContainer") as HTMLDivElement;
    const inp: HTMLInputElement = document.getElementById(errorCont?.children[0]?.getAttribute("name") + "") as HTMLInputElement;
    if (inp?.name == "genreContact") {
        inp?.parentElement?.insertBefore(errorCont, inp.previousElementSibling);
    }
    else {
        inp?.parentNode?.insertBefore(errorCont, inp);
    }

    const form: HTMLButtonElement = document.getElementById("submitBtn") as HTMLButtonElement;
    form.onclick = (ev) => {
        const genreDiv: HTMLDivElement = document.getElementById("genreContactDiv") as HTMLDivElement;
        const genreInp: HTMLInputElement = document.getElementById("genreContact") as HTMLInputElement;
        genreDiv.childNodes.forEach((val) => {
            const inp = val as HTMLInputElement;
            if (inp.checked) {
                genreInp.value = inp.id;
            }
        });
    };
}

