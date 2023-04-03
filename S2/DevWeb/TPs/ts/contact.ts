window.onload = () => {
    const form: HTMLFormElement = document.querySelector("#formContact") as HTMLFormElement;
    form.onsubmit = (ev: SubmitEvent) => {
        ev.preventDefault();
        console.log(ev);
        const form = ev.currentTarget as HTMLFormElement;
        const elems = form.elements;

        const nom = elems.namedItem("nomContact") as HTMLInputElement;
        
        const nomValid = nom.value.length > 0;
        
    }
}
