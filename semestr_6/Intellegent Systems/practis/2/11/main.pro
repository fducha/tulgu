% Copyright

implement main
    open core, console

domains
    intList = integer*.
    strList = string_list.

class predicates
    rom2Arab : (string, integer [out]).
    translateR2A : (strList, intList [out]).

clauses
    rom2Arab(R, A) :-
        if R = "I" then
            A = 1
        elseif R = "II" then
            A = 2
        elseif R = "III" then
            A = 3
        elseif R = "IV" then
            A = 4
        elseif R = "V" then
            A = 5
        elseif R = "VI" then
            A = 6
        elseif R = "VII" then
            A = 7
        elseif R = "VII" then
            A = 8
        elseif R = "IX" then
            A = 9
        elseif R = "X" then
            A = 10
        elseif R = "XI" then
            A = 11
        elseif R = "XII" then
            A = 12
        elseif R = "XIII" then
            A = 13
        elseif R = "XIV" then
            A = 14
        elseif R = "XV" then
            A = 15
        elseif R = "XVI" then
            A = 16
        elseif R = "XVII" then
            A = 17
        elseif R = "XVIII" then
            A = 18
        elseif R = "XIX" then
            A = 19
        elseif R = "XX" then
            A = 20
        else
            A = 0
        end if.

    translateR2A([], []) :-
        !.
    translateR2A([DH | DT], [SH | Out]) :-
        rom2Arab(DH, SH),
        translateR2A(DT, Out).

    run() :-
        RL = ["XX", "XIII", "VII", "IX"],
        stdio::writef("Список  римскх цифр: %", RL),
        nl,
        translateR2A(RL, L11),
        stdio::writef("Список арабских цифр: %", L11),
        _ = stdio::readLine().

end implement main

goal
    console::runUtf8(main::run).
