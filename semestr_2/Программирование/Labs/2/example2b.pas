program example2b;
var x, y: real;
begin
write('Введите значение x: ');
read(x);
y := sqr(x);
write('x = ', x:0:3, ' y = ', y:0:3);
readln;
end.