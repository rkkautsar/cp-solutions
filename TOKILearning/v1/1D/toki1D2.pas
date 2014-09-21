PROGRAM fungsi;

var a:-100..100;

function Faktorial(n: integer): longint;
begin
    if (n = 0) then
        Faktorial := 1
    else
        Faktorial := n * Faktorial (n - 1);
end;

BEGIN
readln(a);
case a of
	0..10: writeln(faktorial(a));
	else writeln('ditolak');
end;
END.
