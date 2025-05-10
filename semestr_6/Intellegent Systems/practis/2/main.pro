% Copyright

implement main
    open core, console

domains
    intList = integer*.
    strList = string_list.

class predicates
    length : (intList, integer [out]).
    replaceFirst : (integer, integer, intList, intList [out]).
    replaceAll : (integer, integer, intList, intList [out]).
    genDown : (integer, intList [out]).
    genUpFromTo : (integer, integer, intList [out]).
    generate5 : (integer, intList [out]).
    generate6 : (integer, integer, integer, intList [out]).
    generate7 : (integer, integer, intList [out]).
    addNum : (integer, intList, intList [out]).
    d2s : (integer, string [out]).
    translate2Str : (intList, strList [out]).
    d2R : (integer, string [out]).
    translate2R : (intList, strList [out]).

    rom2Arab : (string, integer [out]).
    translateR2A : (strList, intList [out]).

    doubler : (intList, intList [out]).

    positiv : (intList, intList [out]).

    negPosImp : (intList, integer, intList [out]) determ.
    negPos : (intList, intList [out]) determ.

    delEven : (intList, intList [out]).

    splitPosNeg : (intList, intList [out], intList [out]).

    splitOddEven : (intList, intList [out], intList [out]) nondeterm.

    sublist : (intList, integer, intList [out]) nondeterm.

    del : (intList, intList [out]) determ.
    delFirst : (integer, intList, intList [out]) determ.
    reverseImp : (intList, intList, intList [out]).
    reverse : (intList, intList [out]).
    delLast : (integer, intList, intList [out]) determ.

    splitByPos : (intList, integer, intList [out], intList [out]) determ.

    splitByEndPos : (intList, integer, intList [out], intList [out]) determ.

    getPreLast : (intList, integer [out]) determ.

    delPreLast : (intList, intList [out]) determ.

clauses
%    length([], 0).
%    length([_ | T], L) :-
%        length(T, LT),
%        L = LT + 1.
%
%    replaceFirst(_, _, [], []).
%    replaceFirst(F, N, [F | T1], [N | T1]) :-
%        !.
%    replaceFirst(F, N, [Y | T1], [Y | T2]) :-
%        replaceFirst(F, N, T1, T2).
%
%    replaceAll(_, _, [], []) :-
%        !.
%    replaceAll(Old, New, [Old | Tail1], [New | Tail2]) :-
%        !,
%        replaceAll(Old, New, Tail1, Tail2).
%    replaceAll(Old, New, [Y | Tail1], [Y | Tail2]) :-
%        replaceAll(Old, New, Tail1, Tail2).
%
%    genDown(0, []) :-
%        !.
%    genDown(Counter, [Counter | Tail]) :-
%        genDown(Counter, Tail).
%
%    genUpFromTo(From, To, []) :-
%        From > To,
%        !.
%    genUpFromTo(From, To, [From | Tail]) :-
%        genUpFromTo(From + 1, To, Tail).
%
%    generate5(0, []) :-
%        !.
%    generate5(Count, [math::random(100) | Tail]) :-
%        generate5(Count - 1, Tail).
%
%    generate6(0, _, _, []) :-
%        !.
%    generate6(Count, RFrom, RTo, [RFrom + math::random(RTo - RFrom) | Tail]) :-
%        generate6(Count - 1, RFrom, RTo, Tail).
%
%    generate7(RFrom, RTo, List) :-
%        generate6(math::random(20), RFrom, RTo, List).
%
%    addNum(K, [X | Tail], [X + K | NewTail]) :-
%        addNum(K, Tail, NewTail).
%    addNum(_, [], []).
%
%    d2s(X, S) :-
%        if X = 0 then
%            S = "Ноль"
%        elseif X = 1 then
%            S = "Один"
%        elseif X = 2 then
%            S = "Два"
%        elseif X = 3 then
%            S = "Три"
%        elseif X = 4 then
%            S = "Четыре"
%        elseif X = 5 then
%            S = "Пять"
%        elseif X = 6 then
%            S = "Шесть"
%        elseif X = 7 then
%            S = "Семь"
%        elseif X = 8 then
%            S = "Восемь"
%        elseif X = 9 then
%            S = "Девять"
%        else
%            S = "ХЗ"
%        end if.
%    translate2Str([], []) :-
%        !.
%    translate2Str([DH | DT], [SH | Out]) :-
%        d2s(DH, SH),
%        translate2Str(DT, Out).
%    d2R(X, S) :-
%        if X = 10 then
%            S = "X"
%        elseif X = 1 then
%            S = "I"
%        elseif X = 2 then
%            S = "II"
%        elseif X = 3 then
%            S = "III"
%        elseif X = 4 then
%            S = "IV"
%        elseif X = 5 then
%            S = "V"
%        elseif X = 6 then
%            S = "VI"
%        elseif X = 7 then
%            S = "VII"
%        elseif X = 8 then
%            S = "VIII"
%        elseif X = 9 then
%            S = "IX"
%        else
%            S = "-"
%        end if.
%    translate2R([], []) :-
%        !.
%    translate2R([DH | DT], [SH | Out]) :-
%        d2R(DH, SH),
%        translate2R(DT, Out).
%
%    rom2Arab(R, A) :-
%        if R = "I" then
%            A = 1
%        elseif R = "II" then
%            A = 2
%        elseif R = "III" then
%            A = 3
%        elseif R = "IV" then
%            A = 4
%        elseif R = "V" then
%            A = 5
%        elseif R = "VI" then
%            A = 6
%        elseif R = "VII" then
%            A = 7
%        elseif R = "VII" then
%            A = 8
%        elseif R = "IX" then
%            A = 9
%        elseif R = "X" then
%            A = 10
%        elseif R = "XI" then
%            A = 11
%        elseif R = "XII" then
%            A = 12
%        elseif R = "XIII" then
%            A = 13
%        elseif R = "XIV" then
%            A = 14
%        elseif R = "XV" then
%            A = 15
%        elseif R = "XVI" then
%            A = 16
%        elseif R = "XVII" then
%            A = 17
%        elseif R = "XVIII" then
%            A = 18
%        elseif R = "XIX" then
%            A = 19
%        elseif R = "XX" then
%            A = 20
%        else
%            A = 0
%        end if.
%
%    translateR2A([], []) :-
%        !.
%    translateR2A([DH | DT], [SH | Out]) :-
%        rom2Arab(DH, SH),
%        translateR2A(DT, Out).

    doubler([H | T], [H * 2 | NT]) :-
        doubler(T, NT).
    doubler([], []).

    positiv([H | T], [math::abs(H) | NT]) :-
        positiv(T, NT).
    positiv([], []).

    negPosImp([], _, []) :-
        !.
    negPosImp([H | T], K, [K | T1]) :-
        H < 0,
        !,
        K1 = K + 1,
        negPosImp(T, K1, T1).
    negPosImp([H | T], K, T1) :-
        H >= 0,
        !,
        K1 = K + 1,
        negPosImp(T, K1, T1).
    negPos(L, R) :-
        negPosImp(L, 1, R).

    delEven([], []).
    delEven([X], [X]) :-
        !.
    delEven([X, _ | T], [X | T2]) :-
        delEven(T, T2).

    splitPosNeg([], [], []).
    splitPosNeg([H | T], [H | T1], T2) :-
        H < 0,
        !,
        splitPosNeg(T, T1, T2).
    splitPosNeg([H | T], T1, [H | T2]) :-
        splitPosNeg(T, T1, T2).

    splitOddEven([X], [X], []).
    splitOddEven([X, Y], [X], [Y]).
    splitOddEven([X, Y | T], [X | T1], [Y | T2]) :-
        splitOddEven(T, T1, T2).

    sublist(X, 0, X).
    sublist([_ | T], N, R) :-
        N1 = N - 1,
        sublist(T, N1, R).

    del([_ | T], T).
    delFirst(1, S, R) :-
        del(S, R),
        !.
    delFirst(N, S, R) :-
        N1 = N - 1,
        del(S, R1),
        delFirst(N1, R1, R).
    reverseImp([H | L1], L2, R) :-
        reverseImp(L1, [H | L2], R).
    reverseImp([], L, L).
    reverse(L, R) :-
        reverseImp(L, [], R).
    delLast(N, S, R) :-
        reverse(S, R1),
        delFirst(N, R1, R2),
        reverse(R2, R).

    splitByPos(L, 0, [], L) :-
        !.
    splitByPos([H | T], N, [H | Before], After) :-
        N1 = N - 1,
        splitByPos(T, N1, Before, After).

    splitByEndPos(L, N, R1, R2) :-
        reverse(L, T),
        splitByPos(T, N, T1, T2),
        reverse(T1, R1),
        reverse(T2, R2).

    getPreLast([H, _], H) :-
        !.
    getPreLast([_ | T], R) :-
        getPreLast(T, R).

    delPreLast([], _) :-
        fail.
    delPreLast([_, X], [X]) :-
        !.
    delPreLast([H | T], [H | R]) :-
        delPreLast(T, R).

    run() :-
%        length([1, 2, 3], R),
%        stdio::writef("Length [1, 2, 3] is %\n", R),
%        FL = [1, 2, 3, 4, 3],
%        stdio::writef("The list: %\n", FL),
%        replaceFirst(3, 7, FL, L),
%        stdio::writef("Replaced list: %\n", L),
%        replaceAll(3, 7, FL, L2),
%        stdio::writef("Replaced all list: %\n", L2),

%        stdio::write("Введите натуральное число: "),
%        N = stdio::read(),
%        hasDomain(integer, N),
%        genDown(N, L4),
%        stdio::writef("Список от % до 1: %", N, L4),

%        stdio::write("Введите натуральное число: "),
%        N = stdio::read(),
%        hasDomain(integer, N),
%        genUpFromTo(1, N, L3),
%        stdio::writef("Список от 1 до %: %", N, L3),

%        stdio::write("Введите натуральное число: "),
%        N = stdio::read(),
%        hasDomain(integer, N),
%        generate5(N, L5),
%        stdio::writef("Список случайных чисел из % элементов: %", N, L5),

%        stdio::write("Введите количество элементов: "),
%        N = stdio::read(),
%        hasDomain(integer, N),
%        stdio::write("Введите начало промежутка: "),
%        M = stdio::read(),
%        hasDomain(integer, M),
%        stdio::write("Введите окончание промежутка: "),
%        K = stdio::read(),
%        hasDomain(integer, K),
%        generate6(N, M, K, L6),
%        stdio::writef("Список случайных чисел из % элементов в промежутке от % до %: \n%", N, M, K, L6),

%        stdio::write("Введите начало промежутка: "),
%        M = stdio::read(),
%        hasDomain(integer, M),
%        stdio::write("Введите окончание промежутка: "),
%        K = stdio::read(),
%        hasDomain(integer, K),
%        generate7(M, K, L7),
%        stdio::writef("Список случайных чисел из элементов в промежутке от % до %: \n%", M, K, L7),

%        FL = [1, 2, 3, 4, 3],
%        stdio::writef("Исходный список: %", FL),
%        nl,
%        stdio::write("Введите значение увеличения: "),
%        K = stdio::read(),
%        hasDomain(integer, K),
%        addNum(K, FL, L8),
%        stdio::writef("Список с увеличенными на % элементами: %", K, L8),

%        L = [6, 3, 0, 9, 45],
%        stdio::writef("Список цифр: %", L),
%        nl,
%        translate2Str(L, L9),
%        stdio::writef("Список цифр словами: %", L9),

%        L = [6, 3, 1, 9, 8],
%        stdio::writef("Список цифр: %", L),
%        nl,
%        translate2R(L, L10),
%        stdio::writef("Список римских цифр: %", L10),

%        RL = ["XX", "XIII", "VII", "IX"],
%        stdio::writef("Список  римскх цифр: %", RL),
%        nl,
%        translateR2A(RL, L11),
%        stdio::writef("Список арабских цифр: %", L11),

%        L = [6, -3, 1, 9, -8, 14, 23, 7, -13],
%        stdio::writef("Список чисел: %", L),
%        nl,
%        stdio::write("Введите номер позиции (с конца) для разделения: "),
%        N = stdio::read(),
%        hasDomain(integer, N),
%        splitByEndPos(L, N, L21B, L21A),
%        stdio::writef("Список после % позиции (включительно): %\n", N, L21B),
%        stdio::writef("Список до % позиции: %", N, L21A),
%        fail
%        or
%        _ = stdio::readLine().

        L = [6, -3, 1, 9, -8, 14, 23, 7, -13],
        stdio::writef("Список чисел: %", L),
        nl,
        delPreLast(L, L23),
        stdio::writef("Список без предпоследнего элемента: %", L23),
        fail
        or
        _ = stdio::readLine().

end implement main

goal
    console::runUtf8(main::run).
