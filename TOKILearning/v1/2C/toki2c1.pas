var
a,b,c,d:string;

begin
	readln(a);
	readln(b);
	readln(c);
	readln(d);
	delete(a,pos(b,a),length(b));
	insert(d,a,pos(c,a)+length(c));
	writeln(a);
end.
