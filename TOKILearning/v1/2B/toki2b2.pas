{	# Perkalian Matriks #
* Pak Dengklek memberikan Anda dua buah matriks. Matriks pertama berukuran 
* A x B sedangkan matriks kedua berukuran C x D (1 Ã¢ÂÂ¤ A, B, C, D Ã¢ÂÂ¤ 75; B = C). 
* Tiap elemen pada kedua matriks tersebut adalah sebuah bilangan bulat 
* antara 1 sampai 100. Kalikan kedua matriks tersebut lalu cetak hasilnya.}

var a,b,c:array[1..100,1..100] of byte;
i,j,k,m,p,n:byte;
 
begin
{input}
readln(m,n);
for i:=1 to m do
	for j:=1 to n do read(a[i,j]);
readln(n,p);
for i:=1 to n do
	for j:=1 to p do read(b[i,j]);

for i:=1 to m do
	for j:=1 to p do begin
	c[i,j]:=0;
	for k:=1 to n do
		c[i,j]+=a[i,k]*b[k,j];
	end;

{output}
for i:=1 to m do
	for j:=1 to p do begin
	write(c[i,j]);
	if j<>p then write(' ') else writeln;
	end;
end.
