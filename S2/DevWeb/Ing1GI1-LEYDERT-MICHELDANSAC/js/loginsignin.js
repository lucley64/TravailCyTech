function login() {
    var form = document.querySelector('form#login');
    form.submit();
}
function signin() {
    var form = document.querySelector('form#signin');
    var login = form.elements['login'];
    var mail = form.elements['mail'];
    var password = form.elements['mdp'];
    var passwordConfirmation = form.elements['mdp2'];
    if (login.value.length == 0) {
        var err = login.nextElementSibling;
        err.className = 'error active';
        err.innerHTML = 'Veuillez remplir ce champ.';
        login.className = 'invalid';
    }
    else if (mail.value.length == 0) {
        var err = mail.nextElementSibling;
        err.className = 'error active';
        err.innerHTML = 'Veuillez remplir ce champ.';
        mail.className = 'invalid';
    }
    else if (!mail.value.match(/^[a-zA-Z0-9.!#$%&'*+/=?^_`{|}~-]+@[a-zA-Z0-9-]+(?:\.[a-zA-Z0-9-]+)*$/)) {
        var err = mail.nextElementSibling;
        err.className = 'error active';
        err.innerHTML = 'Veuillez inserer un mail valide.';
        mail.className = 'invalid';
    }
    else if (password.value.length < 8) {
        var err = password.nextElementSibling;
        err.className = 'error active';
        err.innerHTML = 'Le mot de passe doit être de plus de 8 caractères';
        password.className = 'invalid';
    }
    else if (password.value != passwordConfirmation.value) {
        var err = passwordConfirmation.nextElementSibling;
        err.className = 'error active';
        err.innerHTML = 'Le mot de passe doit être identique';
        passwordConfirmation.className = 'invalid';
    }
    else {
        form.submit();
    }
}
