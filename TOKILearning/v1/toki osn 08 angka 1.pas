var i,n:cardinal;
a:qword;

begin

readln(n);

for i:=1 to n do begin
	a:=(i*(i+1) div 2); //pola bil. segitiga -> (n*(n+1))/2
	writeln(a);
end;

end.
