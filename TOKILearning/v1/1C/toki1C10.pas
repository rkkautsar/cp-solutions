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
	
{FUNCTION jmlfaktor(x:TInt):shortint;
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
 end;}
 
function jmlfaktor(number:TInt):shortint;
begin 
jmlfaktor:=0;
  for i := 1 to round(sqrt(number)) - 1 do
    if number mod i = 0 then
      inc(jmlfaktor,2);
  i := round(sqrt(number));
  if i*i = number then
     inc(jmlfaktor)
  else if number mod i = 0 then
     inc(jmlfaktor,2);
end;


BEGIN
	repeat
		readln(n);
	until (n in [1..8]);
	SetLength(a,n);
	for i:=1 to n do begin
	repeat
	repeat
		readln(a[i]);
	until (a[i]>=1);
	until (a[i]<=1000000000);
	end;

	for j:=1 to n do begin
		if (jmlfaktor(a[j])<=4) then
			writeln('YA')
		else
			writeln('TIDAK');
	end;
END.
