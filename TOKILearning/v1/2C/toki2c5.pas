var
s1,s2,r:ansistring;
i:longint;

function pal(s:ansistring):boolean;
begin
	pal:=true;
	for i:=1 to length(s) div 2 do
		if s[i]<>s[length(s)-i+1] then begin
			pal:=false;
			break;
		end;
end;

begin
readln(s1);
s1+=' ';
r:='';
while s1<>'' do begin
	i:=1;
	s2:='';
	while s1[i]<>' ' do begin
		s2+=s1[i];
		i+=1;
	end;
	delete(s1,1,i);
	if pal(s2) then r+=s2+' ';
end;
delete(r,length(r),1);
writeln(r);
end.
