program example7;
var fact, n, i: integer;
begin
write('Введите n = ');
readln(n);
fact := 1;
for i := 2 to n do fact := fact * i;
writeln(fact);
end.
