uses math,sysutils;
var
  a : array[1..1001] of longint;
  m : array[1..5] of longint;
  sum,i,t,n,j,index   : longint;

function binary_search(element: longint; list: array of longint): longint;
var
    l, m, h: longint;
begin
    l := 1;
    h := n;
    binary_search := -1;
    while l <= h do
    begin
        m := (l + h) div 2;
        if list[m] > element then
        begin
            h := m - 1;
        end
        else if list[m] < element then
        begin
            l := m + 1;
        end
        else
        begin
            binary_search := m;
            break;
        end;
    end;
end;

begin
readln(t);
for i:=1 to t do begin
	readln(n);
	for j:=1 to n do read(a[j]);
	sum:=0;
	for j:=1 to 5 do begin
	m[j]:=maxvalue(a);
	writeln(m[j],' ',binary_search(m[j],a));
	index:=binary_search(m[j],a);
	a[index]:=-sizeof(integer);
	sum+=m[j];
	end;
	writeln(sum);
end;
end.
