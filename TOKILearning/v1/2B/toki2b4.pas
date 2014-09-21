type matrix=array [1..75,1..75] of byte;
var
	a,b:matrix;
	i,j,m,n:byte;

function check(m1,m2:matrix):boolean;
begin
	check:=true;
	for i:=1 to m do
		for j:=1 to n do
			if m1[i,j]<>m2[i,j] then check:=false;
end;

function v(m1:matrix):matrix;
begin
	for i:=1 to m do
	for j:=n downto 1 do
		v[i,n-j+1]:=m1[i,j];
end;

function h(m1:matrix):matrix;
begin
	for i:=m downto 1 do
	for j:=1 to n do
		h[m-i+1,j]:=m1[i,j];
end;

function d1(m1:matrix):matrix;
begin
	for i:=1 to m do
	for j:=1 to n do
		d1[i,j]:=m1[n-j+1,m-i+1];
end;

function d2(m1:matrix):matrix;
begin
	for i:=1 to m do
	for j:=1 to n do
		d2[i,j]:=m1[j,i];
end;

begin
readln(m,n);
for i:=1 to m do
for j:=1 to n do
read(a[i,j]);
readln(m,n);
for i:=1 to m do
for j:=1 to n do
read(b[i,j]);

if check(a,b) then writeln('identik')
else if check(v(a),b) then writeln('vertikal')
else if check(h(a),b) then writeln('horisontal')
else if check(d1(a),b) then writeln('diagonal kiri bawah')
else if check(d2(a),b) then writeln('diagonal kanan bawah')
else writeln('tidak identik');
end.
