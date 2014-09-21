uses math,sysutils;

var i:cardinal;
b:byte;
st,temp:string;
n:qword;

function reverse(s:string):string;
var i:integer;
var tmp:char;
begin
    for i:=1 to length(s) div 2 do
      begin
       tmp:=s[i];
       s[i]:=s[length(s)+1-i];
       s[length(s)+1-i]:=tmp;
       reverse:=s;
      end;
end;

begin

readln(n,b);
i:=1;

for i:=1 to trunc(logn(b,n)) do begin
temp:=inttostr(n mod b);
st[i]:=temp[1];
n:=n div b;
end;

writeln(st);

end.
