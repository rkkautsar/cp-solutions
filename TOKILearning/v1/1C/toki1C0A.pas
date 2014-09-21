PROGRAM progwhile;
VAR
n : string;

BEGIN
while not eof(input) do begin
readln(n);
writeln(n);
end;
end.
