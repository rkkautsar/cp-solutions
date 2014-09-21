var
st:ansistring;
i,j,n:dword;

procedure remzeros(var s:ansistring);
begin
i:=length(s);
while(st[i]='0') do begin
	delete(s,i,1);
	i-=1;
end;
end;
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
	readln(n);
	for j:=1 to n do begin
	readln(st);
	if st<>'0' then remzeros(st);
	reverse(st);
	writeln(st);
	end;
end.
