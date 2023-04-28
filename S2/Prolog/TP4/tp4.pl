:- use_module(library(clpfd)).

% 1.01 (*) Find the last element of a list.
% Example:
% ?- my_last(X,[a,b,c,d]).
% X = d
my_last(X, [X]).
my_last(X, [_|Ls]) :-
    my_last(X, Ls).

% 1.02 (*) Find the last but one element of a list.
% (de: zweitletztes Element, fr: avant-dernier élément)
my_last_but_one(X, [X,_]).
my_last_but_one(X, [_|Ls]) :-
    my_last_but_one(X, Ls).

% 1.03 (*) Find the K'th element of a list.
% The first element in the list is number 1.
% Example:
% ?- element_at(X,[a,b,c,d,e],3).
% X = c

% 1.04 (*) Find the number of elements of a list.

% 1.05 (*) Reverse a list.
reverse_list(X, Y):-
    reverse_list(X, Y, []).
reverse_list([], Acc, Acc).
reverse_list([X|Y], Rev, Acc):-
    reverse_list(Y, Rev, [X|Acc]).

% 1.06 (*) Find out whether a list is a palindrome.
% A palindrome can be read forward or backward; e.g. [x,a,m,a,x].
palindrome(X):-
    reverse(X, X).

% 1.07 (**) Flatten a nested list structure.
% Transform a list, possibly holding lists as elements into a 'flat' list by replacing each list with its elements (recursively).

% Example:
% ?- my_flatten([a, [b, [c, d], e]], X).
% X = [a, b, c, d, e]

% Hint: Use the predefined predicates is_list/1 and append/3

% 1.08 (**) Eliminate consecutive duplicates of list elements.
% If a list contains repeated elements they should be replaced with a single copy of the element. The order of the elements should not be changed.

% Example:
% ?- compress([a,a,a,a,b,c,c,a,a,d,e,e,e,e],X).
% X = [a,b,c,a,d,e]
compress([],[]).
compress([X], [X]).
compress([X, X|R], Res) :-
    compress([X|R], Res).
compress([X, Y|R], [X|Res]) :-
    dif(X, Y),
    compress([Y|R], Res).

% 1.09 (**) Pack consecutive duplicates of list elements into sublists.
% If a list contains repeated elements they should be placed in separate sublists.

% Example:
% ?- pack([a,a,a,a,b,c,c,a,a,d,e,e,e,e],X).
% X = [[a,a,a,a],[b],[c,c],[a,a],[d],[e,e,e,e]]
pack([],[]).
pack([X|L], [P|S]):-
    pack_aux(X, L, R, P),
    pack(R, S).

pack_aux(X, [], [], [X]).

pack_aux(X, [Y|L], [Y|L], [X]):-
    dif(X,Y).

pack_aux(X, [X|L], NR, [X|P]):-
    pack_aux(X, L, NR, P).

% 1.10 (*) Run-length encoding of a list.
% Use the result of problem 1.09 to implement the so-called run-length encoding data compression method. Consecutive duplicates of elements are encoded as terms [N,E] where N is the number of duplicates of the element E.

% Example:
% ?- encode([a,a,a,a,b,c,c,a,a,d,e,e,e,e],X).
% X = [[4,a],[1,b],[2,c],[2,a],[1,d],[4,e]]

encode([],[]).
encode([X|L], [[Y,X]|S]):-
    pack_aux(X, L, R, P),
    length(P, Y),
    encode(R, S).


% 1.11 (*) Modified run-length encoding.
% Modify the result of problem 1.10 in such a way that if an element has no duplicates it is simply copied into the result list. Only elements with duplicates are transferred as [N,E] terms.

% Example:
% ?- encode_modified([a,a,a,a,b,c,c,a,a,d,e,e,e,e],X).
% X = [[4,a],b,[2,c],[2,a],d,[4,e]]

encode_modified([],[]).
encode_modified([X|L], [YX|S]):-
    pack_aux(X, L, R, P),
    encode_modified_aux(P, YX, X),
    encode_modified(R, S).

encode_modified_aux([P|R], P, _) :-
    length([P|R], 1).

encode_modified_aux(P, [Y,X], X) :-
    length(P, Y),
    dif(Y,1).

% 1.12 (**) Decode a run-length encoded list.
% Given a run-length code list generated as specified in problem 1.11. Construct its uncompressed version.

% 1.13 (**) Run-length encoding of a list (direct solution).
% Implement the so-called run-length encoding data compression method directly. I.e. don't explicitly create the sublists containing the duplicates, as in problem 1.09, but only count them. As in problem 1.11, simplify the result list by replacing the singleton terms [1,X] by X.

% Example:
% ?- encode_direct([a,a,a,a,b,c,c,a,a,d,e,e,e,e],X).
% X = [[4,a],b,[2,c],[2,a],d,[4,e]]

% 1.14 (*) Duplicate the elements of a list.
% Example:
% ?- dupli([a,b,c,c,d],X).
% X = [a,a,b,b,c,c,c,c,d,d]

% 1.15 (**) Duplicate the elements of a list a given number of times.
% Example:
% ?- dupli([a,b,c],3,X).
% X = [a,a,a,b,b,b,c,c,c]

% What are the results of the goal:
% ?- dupli(X,3,Y).

% 1.16 (**) Drop every N'th element from a list.
% Example:
% ?- drop([a,b,c,d,e,f,g,h,i,k],3,X).
% X = [a,b,d,e,g,h,k]

% 1.17 (*) Split a list into two parts; the length of the first part is given.
% Do not use any predefined predicates.

% Example:
% ?- split([a,b,c,d,e,f,g,h,i,k],3,L1,L2).
% L1 = [a,b,c]
% L2 = [d,e,f,g,h,i,k]

% 1.18 (**) Extract a slice from a list.
% Given two indices, I and K, the slice is the list containing the elements between the I'th and K'th element of the original list (both limits included). Start counting the elements with 1.

% Example:
% ?- slice([a,b,c,d,e,f,g,h,i,k],3,7,L).
%  L = [c,d,e,f,g]

% 1.19 (**) Rotate a list N places to the left.
% Examples:
% ?- rotate([a,b,c,d,e,f,g,h],3,X).
% X = [d,e,f,g,h,a,b,c]

% ?- rotate([a,b,c,d,e,f,g,h],-2,X).
% X = [g,h,a,b,c,d,e,f]

% Hint: Use the predefined predicates length/2 and append/3, as well as the result of problem 1.17.

% 1.20 (*) Remove the K'th element from a list.
% Example:
% ?- remove_at(X,[a,b,c,d],2,R).
% X = b
% R = [a,c,d]

% 1.21 (*) Insert an element at a given position into a list.
% Example:
% ?- insert_at(alfa,[a,b,c,d],2,L).
% L = [a,alfa,b,c,d]

% 1.22 (*) Create a list containing all integers within a given range.
% Example:
% ?- range(4,9,L).
% L = [4,5,6,7,8,9]

% 1.23 (**) Extract a given number of randomly selected elements from a list.
% The selected items shall be put into a result list.
% Example:
% ?- rnd_select([a,b,c,d,e,f,g,h],3,L).
% L = [e,d,a]

% Hint: Use the built-in random number generator random/2 and the result of problem 1.20.

% 1.24 (*) Lotto: Draw N different random numbers from the set 1..M.
% The selected numbers shall be put into a result list.
% Example:
% ?- lotto(6,49,L).
% L = [23,1,17,33,21,37]

% Hint: Combine the solutions of problems 1.22 and 1.23.

% 1.25 (*) Generate a random permutation of the elements of a list.
% Example:
% ?- rnd_permu([a,b,c,d,e,f],L).
% L = [b,a,d,c,e,f]

% Hint: Use the solution of problem 1.23.

% 1.26 (**) Generate the combinations of K distinct objects chosen from the N elements of a list
% In how many ways can a committee of 3 be chosen from a group of 12 people? We all know that there are C(12,3) = 220 possibilities (C(N,K) denotes the well-known binomial coefficients). For pure mathematicians, this result may be great. But we want to really generate all the possibilities (via backtracking).

% Example:
% ?- combination(3,[a,b,c,d,e,f],L).
% L = [a,b,c] ;
% L = [a,b,d] ;
% L = [a,b,e] ;
% ...

% 1.27 (**) Group the elements of a set into disjoint subsets.
% a) In how many ways can a group of 9 people work in 3 disjoint subgroups of 2, 3 and 4 persons? Write a predicate that generates all the possibilities via backtracking.

% Example:
% ?- group3([aldo,beat,carla,david,evi,flip,gary,hugo,ida],G1,G2,G3).
% G1 = [aldo,beat], G2 = [carla,david,evi], G3 = [flip,gary,hugo,ida]
% ...

% b) Generalize the above predicate in a way that we can specify a list of group sizes and the predicate will return a list of groups.

% Example:
% ?- group([aldo,beat,carla,david,evi,flip,gary,hugo,ida],[2,2,5],Gs).
% Gs = [[aldo,beat],[carla,david],[evi,flip,gary,hugo,ida]]
% ...

% Note that we do not want permutations of the group members; i.e. [[aldo,beat],...] is the same solution as [[beat,aldo],...]. However, we make a difference between [[aldo,beat],[carla,david],...] and [[carla,david],[aldo,beat],...].

% You may find more about this combinatorial problem in a good book on discrete mathematics under the term "multinomial coefficients".

% 1.28 (**) Sorting a list of lists according to length of sublists
% a) We suppose that a list (InList) contains elements that are lists themselves. The objective is to sort the elements of InList according to their length. E.g. short lists first, longer lists later, or vice versa.

% Example:
% ?- lsort([[a,b,c],[d,e],[f,g,h],[d,e],[i,j,k,l],[m,n],[o]],L).
% L = [[o], [d, e], [d, e], [m, n], [a, b, c], [f, g, h], [i, j, k, l]]

% b) Again, we suppose that a list (InList) contains elements that are lists themselves. But this time the objective is to sort the elements of InList according to their length frequency; i.e. in the default, where sorting is done ascendingly, lists with rare lengths are placed first, others with a more frequent length come later.

% Example:
% ?- lfsort([[a,b,c],[d,e],[f,g,h],[d,e],[i,j,k,l],[m,n],[o]],L).
% L = [[i, j, k, l], [o], [a, b, c], [f, g, h], [d, e], [d, e], [m, n]]

% Note that in the above example, the first two lists in the result L have length 4 and 1, both lengths appear just once. The third and forth list have length 3; there are two list of this length. And finally, the last three lists have length 2. This is the most frequent length.

% 2.01 (**) Determine whether a given integer number is prime.
% Example:
% ?- is_prime(7).
% Yes

is_prime(2).
is_prime(N):-
    N#>2,
    NM1 #= N-1,
    non_div(N, NM1).

non_div(N,2):- 
    N mod 2 #\= 0.

non_div(N,I):- 
    N mod I #\= 0,
    IM1 #= I-1,
    non_div(N,IM1).


% 2.02 (**) Determine the prime factors of a given positive integer.
% Construct a flat list containing the prime factors in ascending order.
% Example:
% ?- prime_factors(315, L).
% L = [3,3,5,7]

% 2.03 (**) Determine the prime factors of a given positive integer (2).
% Construct a list containing the prime factors and their multiplicity.
% Example:
% ?- prime_factors_mult(315, L).
% L = [[3,2],[5,1],[7,1]]

% Hint: The solution of problem 1.10 may be helpful.

% 2.04 (*) A list of prime numbers.
% Given a range of integers by its lower and upper limit, construct a list of all prime numbers in that range.

prime_list(Low, Up, [Low|Res]) :-
    dif(Low, Up),
    is_prime(Low),
    LowP1 #= Low + 1,
    prime_list(LowP1, Up, Res).

prime_list(Low, Up, Res) :-
    \+ is_prime(Low),
    dif(Low, Up),
    LowP1 #= Low + 1,
    prime_list(LowP1, Up, Res).

prime_list(S, S, [S]):-
    is_prime(S).

prime_list(S, S, []) :-
    \+ is_prime(S).

% 2.05 (**) Goldbach's conjecture.
% Goldbach's conjecture says that every positive even number greater than 2 is the sum of two prime numbers. 
% Example: 28 = 5 + 23. It is one of the most famous facts in number theory that has not been proved to be correct in the general case. 
% It has been numerically confirmed up to very large numbers (much larger than we can go with our Prolog system). 
% Write a predicate to find the two prime numbers that sum up to a given even integer.


% Example:
% ?- goldbach(28, L).
% L = [5,23]
goldbach(S, [X, Y]):-
    S #> 2, X #< S, Y #< S,
    is_prime(X),
    is_prime(Y),
    S #= X + Y.

% 2.06 (**) A list of Goldbach compositions.
% Given a range of integers by its lower and upper limit, print a list of all even numbers and their Goldbach composition.

% Example:
% ?- goldbach_list(9,20).
% 10 = 3 + 7
% 12 = 5 + 7
% 14 = 3 + 11
% 16 = 3 + 13
% 18 = 5 + 13
% 20 = 3 + 17

% In most cases, if an even number is written as the sum of two prime numbers, one of them is very small. Very rarely, the primes are both bigger than say 50. Try to find out how many such cases there are in the range 2..3000.

% Example (for a print limit of 50):
% ?- goldbach_list(1,2000,50).
% 992 = 73 + 919
% 1382 = 61 + 1321
% 1856 = 67 + 1789
% 1928 = 61 + 1867

% 2.07 (**) Determine the greatest common divisor of two positive integer numbers.
% Use Euclid's algorithm.
% Example:
% ?- gcd(36, 63, G).
% G = 9

% Define gcd as an arithmetic function; so you can use it like this:
% ?- G is gcd(36,63).
% G = 9



% 2.08 (*) Determine whether two positive integer numbers are coprime.
% Two numbers are coprime if their greatest common divisor equals 1.
% Example:
% ?- coprime(35, 64).
% Yes

% 2.09 (**) Calculate Euler's totient function phi(m).
% Euler's so-called totient function phi(m) is defined as the number of positive integers r (1 <= r < m) that are coprime to m.

% Example: m = 10: r = 1,3,7,9; thus phi(m) = 4. Note the special case: phi(1) = 1.

% ?- Phi is totient_phi(10).
% Phi = 4

% Find out what the value of phi(m) is if m is a prime number. Euler's totient function plays an important role in one of the most widely used public key cryptography methods (RSA). In this exercise you should use the most primitive method to calculate this function. There is a smarter way that we shall use in 2.10.

% 2.10 (**) Calculate Euler's totient function phi(m) (2).
% See problem 2.09 for the definition of Euler's totient function. If the list of the prime factors of a number m is known in the form of problem 2.03 then the function phi(m) can be efficiently calculated as follows: Let [[p1,m1],[p2,m2],[p3,m3],...] be the list of prime factors (and their multiplicities) of a given number m. Then phi(m) can be calculated with the following formula:

% phi(m) = (p1 - 1) * p1**(m1 - 1) * (p2 - 1) * p2**(m2 - 1) * (p3 - 1) * p3**(m3 - 1) * ...

% Note that a**b stands for the b'th power of a.

% 2.11 (*) Compare the two methods of calculating Euler's totient function.
% Use the solutions of problems 2.09 and 2.10 to compare the algorithms. Take the number of logical inferences as a measure for efficiency. Try to calculate phi(10090) as an example.
