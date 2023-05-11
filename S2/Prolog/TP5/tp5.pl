:- use_module(library(clpfd)).

% Ecrire un prédicat qui applique la valeur absolue à tous les éléments d'une liste en utilisant la fonction maplist vue en cours.

absList(Inp, Res):-
    maplist(my_abs, Inp, Res).

my_abs(X, X):-
    X #>= 0.

my_abs(X, Y):-
    X #< 0,
    Y #= -X.
    
% Ecrire un prédicat qui calcule la somme des valeurs absolues des éléments d'une liste en utilisant la fonction foldl vue en cours. 

absSumList(Inp, Res):-
    absList(Inp, X),
    foldl(my_plus, X, 0, Res).

my_plus(X, Y, Res):-
    Res #= X + Y.

% Ecrire le quicksort en utilisant le prédicat partition vue en cours.
quicksort([], []).

quicksort([X|R], Res):-
    partition(superior(X), R, L1, L2),
    quicksort(L1, LR1),
    quicksort(L2, LR2),
    append(LR1, [X|LR2], Res).

superior(X, Y):-
    X #> Y.
    
