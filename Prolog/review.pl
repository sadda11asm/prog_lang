myerror([F, S], [F1, S1]):- F=F1, S\=S1. 
ispair(L, [F | []]):- not(myerror(L, F)).
ispair(L, [F | R]):- not(myerror(L, F)), ispair(L, R).
isfunctional([[X, Y]]).
isfunctional([F | R]):- ispair(F, R), isfunctional(R).


inverse([[X, Y]], [[Y, X]]).
inverse([[X, Y] | R], Z):-inverse(R, L), append([[Y, X]], L, Z). 


ischeck([F, F1], [[F1, F2] | R], Z):- Z = [F, F2].
ischeck([F, F1], [[F1, F2] | R], Z):- ischeck([F, F1], R, Z).
ischeck([F, F1], [[F2, F3] | R], Z):-ischeck([F, F1], R, Z). 

composition([F | R], Y, Z):- ischeck(F, Y, Z).
composition([F | R], Y, Z):- composition(R, Y, Z).
