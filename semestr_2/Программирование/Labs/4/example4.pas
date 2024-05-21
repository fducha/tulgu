program example4;
var x, y: real;
begin
writeln(' x      ', ' y    ');
x := -2;
while (x <= 3) do begin
  if (x > 0) then y := sqr(x)
  else y := sqr(x) * x;
  if (x >= 0) then write(' ');
  write(x:1:3);
  if (y >= 0) then write('   ')
  else write('  ');
  writeln(y:1:3);
  x := x + 1;
end;
end.
