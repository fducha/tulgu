program example12;
var s, t, v, r: real;
begin
write('������ ����ﭨ� (��): ');
readln(s);
write('������ �६� �������� (��): ');
readln(t);
v := s/t;
writeln('������� ��������: ', v:1:2, ' ��/�');
if (v < 120) and (v > 90) then r := 6*s/100
else r := 8*s/100;
writeln('���室 ⮯����: ', r:1:2, ' �');
end.
