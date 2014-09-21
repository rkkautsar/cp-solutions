var i,j,n:cardinal;
a:array [1..16,1..16] of cardinal;

begin

readln(n);

for i:=1 to n do begin 
	a[1,i]:=i*(i+1) div 2;
	a[i,1]:=i*(i+1) div 2;
end;
if n>1 then 
begin
	for i:=2 to n do
	for j:=2 to n do
		a[i,j]:=a[i,j-1]+a[i-1,j];
end;

for i:=1 to n do
for j:=1 to n do begin
write(a[i,j]);
if j<>n then write(' ') else writeln;
end;

end.
