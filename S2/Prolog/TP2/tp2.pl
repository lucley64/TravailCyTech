% Exercice: Réécrire le prédicat permettant de résoudre le problème graphe en utilisant une 
% liste pour retourner le chemin résultat. Pour éviter de parcourir les cycles infinis, vous 
% pourrez utiliser le prédicat length, qui permet d'énumérer les listes par tailles croissantes.

arc(a,b,2).
arc(a,g,6).
arc(b,e,2).
arc(b,c,7).
arc(g,e,1).
arc(g,h,4).
arc(e,f,2).
arc(f,c,3).
arc(f,h,2).
arc(c,d,3).
arc(h,d,2).
chemin(X,Y) :- arc(X,Y,_).
chemin(X,Y) :- arc(X,Z,_),chemin(Z,Y).

