function login() {
    const form = document.querySelector('form#login') as HTMLFormElement;
    form.submit();
}

function signin() {
    const form = document.querySelector('form#signin') as HTMLFormElement;
    const login = form.elements['login'] as HTMLInputElement;
    const mail = form.elements['mail'] as HTMLInputElement;
    const password = form.elements['mdp'] as HTMLInputElement;
    const passwordConfirmation = form.elements['mdp2'] as HTMLInputElement;

    if (login.value.length == 0) {
        const err = login.nextElementSibling as HTMLSpanElement;
        err.className = 'error active';
        err.innerHTML = 'Veuillez remplir ce champ.';
        login.className = 'invalid';
    } else if (mail.value.length == 0) {
        const err = mail.nextElementSibling as HTMLSpanElement;
        err.className = 'error active';
        err.innerHTML = 'Veuillez remplir ce champ.';
        mail.className = 'invalid';
    } else if (!mail.value.match(/^[a-zA-Z0-9.!#$%&'*+/=?^_`{|}~-]+@[a-zA-Z0-9-]+(?:\.[a-zA-Z0-9-]+)*$/)) {
        const err = mail.nextElementSibling as HTMLSpanElement;
        err.className = 'error active';
        err.innerHTML = 'Veuillez inserer un mail valide.';
        mail.className = 'invalid';
    } else if (password.value.length < 8){
        const err = password.nextElementSibling as HTMLSpanElement;
        err.className = 'error active';
        err.innerHTML = 'Le mot de passe doit être de plus de 8 caractères';
        password.className = 'invalid';
    } else if (password.value != passwordConfirmation.value){
        const err = passwordConfirmation.nextElementSibling as HTMLSpanElement;
        err.className = 'error active';
        err.innerHTML = 'Le mot de passe doit être identique';
        passwordConfirmation.className = 'invalid';
    }
    else {
        form.submit()
    }

}