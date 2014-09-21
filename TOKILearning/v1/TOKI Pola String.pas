var s:ansistring;
i,j,n:integer;

function issquare(x:longint):boolean;
begin
if frac(sqrt(x))=0 then issquare:=true else issquare:=false;
end;

function even(x:longint):boolean;
begin
even:=not boolean(x mod 2);
end;

begin

readln(s);

if (not issquare(length(s))) then 
	while not issquare(length(s)) do
	insert('.',s,length(s)+1);

n:=trunc(sqrt(length(s)));

for i:=1 to n do begin
if even(i) then
	for j:=n*i downto n*i-n+1 do begin
	write(s[j]);
	if j=n*i-n+1 then writeln;
	end
else
	for j:=n*i-n+1 to n*i do begin
	write(s[j]);
	if j=n*i then writeln;
	end;
end;

end.
