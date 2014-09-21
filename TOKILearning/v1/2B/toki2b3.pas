{ # Rotasi Matriks #
* Pak Dengklek memberikan Anda dua buah matriks berukuran N x N (1 Ã¢ÂÂ¤ N Ã¢ÂÂ¤ 75),
* yang setiap elemennya adalah sebuah bilangan bulat antara 1 sampai 100. 
* Periksalah apakah kedua matriks tersebut identik rotasional. Matriks A 
* dan B identik rotasional jika B diputar (dirotasi) akan menghasilkan A. 
* Putaran yang diperbolehkan tentu saja antara 0, 90, 180 atau 270 derajat 
* searah jarum jam. }
type matrix=array[1..100,1..100] of byte;
var a,b,c:matrix;
n,i,j,t:byte;
found:boolean;

procedure copymatrix(var x,y:matrix);
begin
for i:=1 to n do
	for j:=1 to n do
		y[i,j]:=x[i,j];
end;

procedure rotmatrix(var x:matrix);
begin
for i:=1 to n do
	for j:=1 to n do 
		c[i,j]:=x[n+1-j,i];
copymatrix(c,a);
end;



function cekmatrix(var x,y:matrix):boolean;
begin
cekmatrix:=true;
for i:=1 to n do
	for j:=1 to n do
		if x[i,j]<>y[i,j] then cekmatrix:=false;
end;

 
begin
{input}
readln(n,n);
for i:=1 to n do
	for j:=1 to n do read(a[i,j]);
readln(n,n);
for i:=1 to n do
	for j:=1 to n do read(b[i,j]);

t:=0;
found:=false;
while (not found) and (t<4) do begin
	if cekmatrix(a,b) then found:=true else t+=1;
	rotmatrix(a);
end;

if found then case t of
	0: writeln(0);
	1: writeln(90);
	2: writeln(180);
	3: writeln(270);
end else writeln('tidak sama');

end.
