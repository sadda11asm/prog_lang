cartesian([], X, []).
cartesian(X, [], []).
cartesian( [ F | R ], X, C3 ) :- cartesian( R, X, C2 ),
                                 product( F, X, C1 ),
                                 append( C1, C2, C3 ).

product( X, [], [] ). 
product( [], X, [] ). 
product( X, [ F | R ], [ pair(X,F) | L ] ) :- product( X, R, L ).

deepmember(X, [X | R]).
deepmember(X, [F | R]):-deepmember(X, F), not(deepmember(X, R)). 
deepmember(X, [F | R]):-deepmember(X, R), not(deepmember(X, F)).
deepmember(X, [F | R]):-deepmember(X, F), deepmember(X, R), !.


notcontains(X, []).
notcontains(X, [Y | []]):- X\=Y, !.
notcontains(X, [F | R]):- F\=X , notcontains(X, R).

setinsertion(X, [Y], L):- var(Y), X\=Y, L = [X, Y].
setinsertion(X, L1, L2):- notcontains(X, L1), append([X], L1, L2).
setinsertion(X, L1, L2):- not(notcontains(X, L1)), L2 = L1.

graph1( [ [ 1, 2 ], [ 1, 3 ], [ 2, 3 ], [ 3, 4 ], [ 4, 1 ] ] ).
graph2( [ [ 1, 2 ], [ 2, 3 ], [ 2, 4 ], [ 3, 4 ], [ 4, 3 ], [ 3, 1 ], [ 4, 1 ] ] ).
graph3( [ [ 1, 2 ], [ 1, 3 ], [ 2, 3 ], [ 3, 2 ], [ 3, 4 ], [ 2, 4 ], [ 4, 6 ], [ 4, 5 ], [ 5, 6 ], [ 6, 5 ], [ 6, 7 ], [ 5, 7 ], [ 7, 1 ] ] ).

allvertices([], []).
allvertices([[L1, L2] | []], L):- setinsertion(L2, [L1], L), !.
allvertices([[F, R] | G1], L):- allvertices(G1, L1), setinsertion(F, L1, L2), setinsertion(R, L2, L).

connected(V0, V1, []):-false.
connected(V0, V1, [V0, V1]):-var(V0), var(V1).
connected(V0, V1, [[V0, V1] | G1]).
connected(V0, V1, [[F1, F2] | G1]):- connected(V0, V1, G1).

path(G, Vend, 1, Forbidden, [Vend], Vend).

path(G, Vbegin, N, Forbidden, Path, Vend):- 	K is N-1, connected(Vbegin, V1, G), notcontains(V1, Forbidden), 
						setinsertion(V1, Forbidden, F1), path(G, V1, K, F1, Path2, Vend),  
						append([Vbegin], Path2, Path).
hamiltoniancircuit( G, C ) :-
				allvertices( G, Vert ),
				Vert = [ V0 | _ ],
				length( Vert, N ),
				path( G, V0, N, [ V0 ], C, LastV ),
				connected( LastV, V0, G ).



