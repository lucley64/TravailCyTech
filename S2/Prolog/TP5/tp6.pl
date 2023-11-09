:- use_module(library(clpfd)).
% Adapter le  programme permettant de résoudre un sudoku à partir d'un fichier texte au format csv

sudoku(Rows) :-
    length(Rows, 9), maplist(same_length(Rows), Rows),
    append(Rows, Vs), Vs ins 1..9,
    maplist(all_distinct, Rows),
    transpose(Rows, Columns),
    maplist(all_distinct, Columns),
    Rows = [As,Bs,Cs,Ds,Es,Fs,Gs,Hs,Is],
    blocks(As, Bs, Cs),
    blocks(Ds, Es, Fs),
    blocks(Gs, Hs, Is).
blocks([], [], []).
blocks([N1,N2,N3|Ns1], [N4,N5,N6|Ns2], [N7,N8,N9|Ns3]) :-
    all_distinct([N1,N2,N3,N4,N5,N6,N7,N8,N9]),
    blocks(Ns1, Ns2, Ns3).

sudoku_file(Filename, Rows):-
    csv_read_file(Filename, RowsR),
    maplist(to_list, RowsR, Rows),
    sudoku(Rows).

to_list(X, L):-
    X =.. [_|R],
    maplist(replace_, R, L).

replace_(L, _):-
    L = '_'.

replace_(L, L):-
    dif(L, '_').
    


% Résoudre en utilisant la programmation par contrainte les problèmes suivants		
 %: https://projecteuler.net/problem=43


number_to_list(N, []):-
    N #= 0.
number_to_list(Number, [N1|L]):-
    Number #\= 0,
    N1 #= Number mod 10,
    N2 #= div(Number, 10),
    number_to_list(N2, L).

pandigital(N):-
    length(L, 10),
    L ins 0..9,
    all_distinct(L),
    L=[_, D2, D3, D4, D5, D6, D7, D8, D9, D10],
    est_div(D2, D3, D4, 2),
    est_div(D3, D4, D5, 3),
    est_div(D4, D5, D6, 5),
    est_div(D5, D6, D7, 7),
    est_div(D6, D7, D8, 11),
    est_div(D7, D8, D9, 13),
    est_div(D8, D9, D10, 17),
    reverse(L, LR), label(L),
    number_to_list(N, LR).

est_div(X1, X2, X3, Div):-
    (X3 + X2 * 10 + X1 * 100) mod Div #= 0.

q2(S):-
    findall(P, pandigital(P), L),
    foldl(plus, L, 0, S).
    
    
    

 %: https://codingcompetitions.withgoogle.com/codejam/round/0000000000432b33/0000000000432be6
