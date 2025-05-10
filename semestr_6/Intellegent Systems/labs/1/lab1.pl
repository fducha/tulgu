issister(kate, dasha).
issister(dasha, kate).
isbrother(kolya, sasha).
isbrother(sasha, kolya).
isparent(kolya, ivan).
isparent(kolya, kate).
isparent(kolya, dasha).
isparent(masha, ivan).
isparent(masha, kate).
isparent(masha, dasha).
isparent(vasya, lesha).
isparent(pasha, sasha).
isparent(pasha, kolya).
isgrandpa(X, Y) :- isparent(X, Z), isparent(Z, Y).
isuncle(X, Y) :- isbrother(X, Z), isparent(Z, Y).
ismarried(kolya, masha).
ismarried(masha, kolya).
ischildren(ivan,kate).
ischildren(ivan,dasha).
ischildren(kate,ivan).
ischildren(dasha,ivan).
isdever(X,Y) :- isbrother(X, Z), ismarried(Z, Y).
issnoxa(X,Y) :- ismarried(X, Z), isbrother(Z, Y).
isdescendant(ivan,kolya).
isdescendant(kate,kolya).
isdescendant(dasha,kolya).
isdescendant(ivan,masha).
isdescendant(kate,masha).
isdescendant(dasha,masha).
isdescendant(sasha,pasha).
isdescendant(kolya,pasha).
isdescendant(lesha,vasya).
issnoxa(X,Y) :- ismarried(X, Z), isdescendant(Z, Y).

isrelative(X, Y) :- issister(X,Y).
isrelative(X, Y) :- isbrother(X,Y).
isrelative(X, Y) :- ischildren(X,Y).
isrelative(X, Y) :- isparent(X,Y).
isrelative(X, Y) :- ismarried(X,Y).
isrelative(X, Y) :- isgrandpa(X,Y).
isrelative(X, Y) :- isuncle(X,Y).
isrelative(X, Y) :- isdever(X,Y).
isrelative(X, Y) :- issnoxa(X,Y).
isrelative(X, Y) :- isdescendant(X,Y).
isrelative(X, Y) :- isdescendant(X,Z), isdescendant(Z,Y).
isrelative(X, Y) :- isdescendant(X,Z), isbrother(Z,Y).