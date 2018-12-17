my_last(X, [X]).
my_last(X, [F | R]):- my_last(X, R), !.


element_at(X, [X | R], 1).
element_at(X, [F | R], Y):- Y1 is Y-1, element_at(X, R, Y1), !.

compress([A, B], [A, B]):- A\=B.
compress([A, A], [A]).
compress([A, B | R], L):- A\=B, compress([B | R], L1), append([A], L1, L).
compress([A, A | R], L):- compress([A | R], L).  

divide([F | R], 1, [F], R).
divide([F | R], N, L1, L2):- N1 is N-1, divide(R, N1, T1, L2), append([F], T1, L1), !.



remove_at(X, [X | R], 1, R).
remove_at(X,[F | R],N,L):- N>1, N1 is N-1, remove_at(X, R, N1, R1), append([F], R1, L). 

deepmember(X, [X | R]).
deepmember(X, [F | R]):- deepmember(X, F), \+ deepmember(X, R).
deepmember(X, [F | R]):- deepmember(X, R), \+ deepmember(X, F).
deepmember(X, [F | R]):- deepmember(X, R), deepmember(X, F).




memberr(X, [], []).
memberr(X, [X | R], R).
memberr(X, [F | R], L):- X\=F, memberr(X, R, L1), append([F], L1, L).


