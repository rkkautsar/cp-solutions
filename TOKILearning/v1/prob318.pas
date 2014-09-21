program HelloWorld;
type
long=1..1000000;
var
x,n,i:longint;

function faktorial(n : integer):long;
begin
if (n=0) then
	faktorial:=1
else
	faktorial:=n*faktorial(n-1);
end;
function expo(a,b:integer):longint;
begin
	if (b=0) then
	expo:=1
	else if (b=1) then
	expo:=a
	else begin
		if (b mod 2=1) then
		expo:=expo(a,b-1)*expo(a,1)
		else
		expo:=expo(a,b div 2)*expo(a,b div 2)
	end;
end;

begin
readln(x);
n:=0;
for i:=1 to 100 do begin
	n:=n+i*(x div expo(5,i));
end;
writeln(n);
end.
