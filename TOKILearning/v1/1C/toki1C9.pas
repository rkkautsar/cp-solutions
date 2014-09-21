PROGRAM faktorbil;
VAR
n,i : longint;

BEGIN
repeat
repeat
readln(n);
until n>=1;
until n<=1000000;
FOR i := n downto 1 do
begin
if n mod i = 0 then writeln(i);
end;
end.
