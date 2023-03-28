homme(albert).
homme(jean).
homme(paul).
homme('Paul').
homme(bertrand).
homme(louis).
homme(benoit).
femme(germaine).
femme(christiane).
femme(simone).
femme(marie).
femme(sophie).
pere_enfant(albert,jean).   
pere_enfant(jean,paul).
pere_enfant(paul,bertrand).
pere_enfant(paul,sophie).
pere_enfant(jean,simone).
pere_enfant(louis,benoit).
mere_enfant(germaine,jean).
mere_enfant(christiane,simone).
mere_enfant(christiane,paul).
mere_enfant(simone,benoit).
mere_enfant(marie,bertrand).
mere_enfant(marie,sophie).



parent_enfant(X, Y) :- 
    mere_enfant(X, Y).

parent_enfant(X, Y) :- 
    pere_enfant(X, Y).

fils_parent(X, Y) :-
    homme(X),
    parent_enfant(Y, X).

fille_parent(X, Y) :- 
    femme(X),
    parent_enfant(Y,X).

grandPere_petitEnfant(X, Y) :- 
    pere_enfant(X, Z),
    pere_enfant(Z, Y).

grandMere_petitEnfant(X, Y) :-
    mere_enfant(X, Z),
    mere_enfant(Z, Y).

frere_frereOuSoeur(X, Y) :- 
    fils_parent(X, Z),
    parent_enfant(Z, Y).

soeur_frereOuSoeur(X, Y) :-
    fille_parent(X, Z),
    parent_enfant(Z, Y).


aime(marie, vin).
aime(pierre, X) :- aime(X, vin).

est(pierre, voleur).

voler(X, Y) :- est(X, voleur), aime(X, Y).













factorial(0,1).
factorial(N,F) :- N>0, N1 is N-1, factorial(N1,F1), F is N * F1.
