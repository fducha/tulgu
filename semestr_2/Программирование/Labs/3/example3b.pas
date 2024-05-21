program example3b;
var x, y: real;
begin
write('Введите значение x: ');
read(x);
if (x>0) then y := sqr(x)
else y := sqr(x) * x;
write('x = ', x:3:2, ' y = ', y:3:2);
end.