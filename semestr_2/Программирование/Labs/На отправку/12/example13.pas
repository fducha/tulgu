program example13;
var k, i: integer;
    c: real;
begin
write('������ ����� ��㤥�� � ᯨ᪥ ��㯯�: ');
readln(k);
c := 1;
for i := 2 to k do c := c * i;
c := c * k;
writeln('C = ', c:1:0);
end.
