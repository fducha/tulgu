% Copyright

implement main
    open core, console

class facts
    x : real32 := 0.
    y : real32 := 0.
    xc : real32 := 0.
    yc : real32 := 0.
    r : real32 := 0.

class predicates
    dotInCircle : (real, real, real, real, real).

clauses
    dotInCircle(X, Y, XC, YC, RC) :-
        stdio::write("Точка ("),
        stdio::write(X),
        stdio::write(","),
        stdio::write(Y),
        if (X - XC) ^ 2 + (Y - YC) ^ 2 <= RC ^ 2 then
            stdio::write(") находится в круге")
        else
            stdio::write(") находится ВНЕ круга")
        end if.
    run() :-
        stdio::write("Введите координаты точки: "),
        nl,
        stdio::write("X = "),
        x := toTerm(stdio::readLine()),
        stdio::write("Y = "),
        y := toTerm(stdio::readLine()),
        stdio::write("Введите координаты центра круга: "),
        nl,
        stdio::write("X = "),
        xc := toTerm(stdio::readLine()),
        stdio::write("Y = "),
        yc := toTerm(stdio::readLine()),
        stdio::write("Введите радиус круга: "),
        r := toTerm(stdio::readLine()),

        dotInCircle(x, y, xc, yc, r),

        _ = stdio::readLine().

end implement main

goal
    console::runUtf8(main::run).
