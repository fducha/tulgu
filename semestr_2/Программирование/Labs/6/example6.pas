program example6;
var x, y: real;
    a, b, h, sum: real;
begin
write('������ a, b, h: ');
read(a, b, h);
x := a;
sum := 0;
while (x <= b) do begin
  if (x > 0) then y := sqr(x)
  else y := sqr(x) * x;
  sum := sum + y;
  x := x + h;
end;
write('�㬬� ࠢ�� ');
writeln(sum:1:2);
end.
