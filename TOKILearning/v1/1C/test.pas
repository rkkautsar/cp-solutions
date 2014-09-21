PROGRAM BilAgakPrima;

CONST
	lim=1000000000;

TYPE
	TIntArray = Array of 1..lim;
	TInt=1..lim;

VAR
	i,j:byte;
	n:1..8;
	a:TIntArray;
	
FUNCTION jmlfaktor(x:TInt):shortint;
 begin
	jmlfaktor:=2;
	FOR i:=2 to round(x/2) do
	 begin
		if x mod i = 0 then begin
		if (x div i<>i) AND (i < x div i) then begin
		inc(jmlfaktor,2);
		end else if (x div i<>i) AND (i>x div i) then continue
		else inc(jmlfaktor,1);
		end;
	 end;
	 if (x>lim-4) and (x<lim) then jmlfaktor:=8
	 else if (x=lim) then jmlfaktor:=24;
	 if (x=1) then jmlfaktor:=1;
 end;

BEGIN
		readln(n);
	SetLength(a,n);

	for j:=1 to n do begin
		if (jmlfaktor(j)<=4) then
			writeln(j,'.YA, ',jmlfaktor(j))
		else
			writeln(j,'.TIDAK, ',jmlfaktor(j));
	end;
END.
