program toki2a3;

uses crt,math;

var
	x:array of integer;
	i:1..10000;
	
begin
	i:=1;
	repeat
		readln(x[i]);
		inc(i);
	until eof(input);
end.
