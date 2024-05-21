program example8;
var a, p: real;
    i, n: word;
begin
write('Введите основание степени a = ');
readln(a);
write('Введите показатель степени n = ');
readln(n);
p := 1;
for i := 1 to n do p := p * a;
writeln('p = ', p:2:3);
end.
