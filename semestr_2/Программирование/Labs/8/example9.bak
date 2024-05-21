program example9;
var a, b: array[1..20] of word;
    k, m, i: byte;
begin
write('Введите размерность массива: ');
readln(k);
m := 0;
for i := 1 to k do begin
  write('A[', i, '] = ');
  readln(a[i]);
  if (a[i] mod 2 = 0) then begin
    m := m + 1;
    b[m] := a[i];
  end;
end;
if (m <> 0) then
  for i := 1 to m do
    write(b[i], ' ')
else write('В массиве нет четных чисел');
end.
