program example12;
var s, t, v, r: real;
begin
write('Введите расстояние (км): ');
readln(s);
write('Введите время движения (час): ');
readln(t);
v := s/t;
writeln('Скорость движения: ', v:1:2, ' км/ч');
if (v < 120) and (v > 90) then r := 6*s/100
else r := 8*s/100;
writeln('Расход топлива: ', r:1:2, ' л');
end.
