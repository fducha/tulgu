program example11;
var c: array[1..50] of integer;
    i, j, n: byte;
    s: word;
    pr: boolean;
begin
randomize;
write('Введите размерность массива (меньше 50): ');
readln(n);
for i := 1 to n do begin
  c[i] := random(100);
end;
for i := 1 to n do write(c[i], ' ');
writeln;
s := 0;
for i := 1 to n do begin
  pr := true;
  for j := 2 to c[i] div 2 do
    if (c[i] mod j = 0) then begin
      pr := false;
      break;
    end;
  if (pr = true) then s := s + c[i];
end;
writeln('Сумма простых чисел массива: ', s);
end.
