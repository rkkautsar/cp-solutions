var arr:array[1..100001] of longint;
t,a,b,r,c:longint;
begin
readln(c);
 
for a:=1 to c do begin
readln(b);
inc(arr[b]);
end;
 
t:=arr[100000];
r:=100000;
 
for a:=length(arr)-1 downto 1 do
if arr[a]>t then begin
t:=arr[a];r:=a;
end;
 
writeln(r);
 
end.
