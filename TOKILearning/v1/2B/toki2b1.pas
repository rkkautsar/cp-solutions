var a:array[1..100,1..100] of byte;
i,j,p,q:byte;

begin
readln(p,q);

for i:=1 to p do
for j:=1 to q do read(a[i,j]);

for j:=1 to q do begin
	for i:=p downto 1 do begin
	write(a[i,j]);
	if i<>1 then write(' ');
	end;
writeln;
end;

end.
