program example14_3;
var c: array[1..50] of integer;
    i, j, n: byte;
    s: word;
begin
randomize;
write('������ ࠧ��୮��� ���ᨢ� (����� 50): ');
readln(n);
for i := 1 to n do begin
  c[i] := random(100);
end;
for i := 1 to n do write(c[i], ' ');
writeln;
s := 0;
for i := 1 to n do
  if (c[i] mod 4 = 0) then s := s + c[i];
writeln('�㬬� �ᥫ � ����⥫�� 4: ', s);
end.
