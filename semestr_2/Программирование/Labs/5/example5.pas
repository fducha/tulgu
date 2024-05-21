program example5;
var x, y: real;
    a, b, h: real;
begin
write('Введите a, b, h: ');
read(a, b, h);
writeln(' x,      y');
x := a;
while (x <= b) do begin
  if (x > 0) then y := sqr(x)
  else y := sqr(x) * x;
  if (x >= 0) then write(' ');
  write(x:1:3);
  if (y >= 0) then write('   ')
  else write('  ');
  writeln(y:1:3);
  x := x + h;
end;
end.
