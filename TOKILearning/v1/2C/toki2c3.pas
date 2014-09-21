var
st:ansistring;
i:integer;

procedure swap(var a,b:char);
var temp:char;
begin
	temp:=a;
	a:=b;
	b:=temp;
end;
procedure reverse(var s:ansistring);
begin
for i:=1 to length(s) div 2 do
	swap(s[i],s[length(s)-i+1]);
end;

begin
	readln(st);
	reverse(st);
	writeln(st);
end.
