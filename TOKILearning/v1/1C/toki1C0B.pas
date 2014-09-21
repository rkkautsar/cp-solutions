PROGRAM progwhile;
VAR
n,jml : integer;

BEGIN
jml:=0;
while not eof(input) do begin
readln(n);
inc(jml,n);
end;
writeln(jml);
end.
