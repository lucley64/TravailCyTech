% 1.01
my_last(X, [X]).
my_last(X, [_|Ls]) :-
    my_last(X, Ls).

%1.02
my_last_but_one(X, [X,_]).
my_last_but_one(X, [_|Ls]) :-
    my_last_but_one(X, Ls).

%1.05
reverse_list(X, Y):-
    reverse_list(X, Y, []).
reverse_list([], Acc, Acc).
reverse_list([X|Y], Rev, Acc):-
    reverse_list(Y, Rev, [X|Acc]).

%1.06
palindrome(X):-
    reverse(X, X).

%1.08
compress([],[]).
compress([X], [X]).
compress([X, X|R], Res) :-
    compress([X|R], Res).
compress([X, Y|R], [X|Res]) :-
    dif(X, Y),
    compress([Y|R], Res).


% 1.09
pack([],[]).
pack([X], [X]).

