:- use_module(library(clpfd)).


createListe(L, NbLst, NbElt):-
    length(L, NbLst),
    createListe(L, NbElt).

createListe([], _).

createListe([L1|R], NbElt):-
    length(L1, NbElt),
    createListe(R, NbElt).
pb(S):-
    createListe(S, 5, 5),
    faits(S).

a_cote(S, M1, M2):-
    nth1(I, S, M1), 
    nth1(J, S, M2), 
    abs(I-J) #= 1.


faits(S):-
    % Norvegien dans la premiere maison
    nth1(1, S, M),nth1(1, M, norvegien),
    % La maison à  coté de celle du norvégien est bleue,
    nth1(1, M2, norvegien), nth1(2, M3, bleue), a_cote(S, M2, M3),
    % L'habitant de la troisième maison boit du lait,
    nth1(3, S, M4),nth1(4, M4, lait),
    % L'anglais habite la maison rouge,
    member(M5, S),nth1(2, M5, rouge),nth1(1, M5, anglais),
    % L'habitant de la maison verte boit du café,
    member(M6, S),nth1(2, M6, verte),nth1(4, M6, cafe),
    % L'habitant de la maison jaune fume des kool
    member(M7, S),nth1(2, M7, jaune),nth1(5, M7, kool),
    % La maison blanche se trouve juste après la verte,
    nth1(2, M8, verte), nth1(2, M9, blanche), a_cote(S, M8, M9),
    % L'espagnol a un chien,
    member(M10, S),nth1(1, M10, espagnol),nth1(3, M10, chien),
    % L'ukrainien boit du thé,
    member(M11, S),nth1(1, M11, ukrainien),nth1(4, M11, the),
    % Le japonais fume des craven
    member(M12, S),nth1(1, M12, japonais),nth1(5, M12, craven),
    % Le fumeur de old gold a un escargot,
    member(M13, S),nth1(5, M13, old_gold),nth1(3, M13, escargot),
    % Le fumeur de gitane boit du vin,
    member(M14, S),nth1(5, M14, gitane),nth1(4, M14, vin),
    % Un voisin du fumeur de chesterfield a un renard,
    nth1(5, M15, chesterfield),nth1(3, M16, renard),a_cote(S, M15, M16),
    % Un voisin du fumeur de kool a un cheval.
    nth1(5, M17, kool),nth1(3, M18, cheval), a_cote(S, M17, M18).

qui_a(N, X):-
    createListe(S, 5, 5),
    faits(S),
    member(M, S),nth1(_, M, X),nth1(1, M, N).

betterThan(norvege, suede).
