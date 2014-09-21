uses crt,math;
  
type
    arraydouble=array[0..10000] of double;
  
var
    x:arraydouble;
    n,i:1..10000;
    j,k:longint;
    jumlah:double;
    rata, sds,s, y:double;
function fmean(arr: array of double):double;
begin
    jumlah:=0;
    for j:=1 to n do begin
        jumlah:=jumlah+arr[j];
    end;
    fmean:=jumlah/n;
end;
  
function max(arr:array of double):double;
begin
    max:=x[1];
    for j:=1 to n do begin
        if max<arr[j] then max:=arr[j];
    end;
end;
  
function min(arr:array of double):double;
begin
    min:=x[1];
    for j:=1 to n do begin
        if min>arr[j] then min:=arr[j];
    end;
end;
      
begin
    readln(n);
    for i:=1 to n do
        readln(x[i]);
    rata:=fmean(x);
    s := 0;
    for k:=1 to n do begin
        y:=(x[k]-rata)**2;
        s += y;
    end;
    if n=1 then sds:=0
    else sds:= sqrt(s / (n-1));
    write(min(x):0:2,' ',max(x):0:2,' ');
    write(rata:0:2,' ',sds:0:2);
    writeln();
end.
