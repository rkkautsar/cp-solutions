uses math;
var
bip,s,p,bil,k,n:qword;

begin
    readln(k);
    readln(n);
    bip:=0;
    p:=10**k;
    bil:=2*n;
    s:=2;
    if(bil>=p) then begin
        bip+=1;
        bil:=bil mod p;
    end;
    while(bil<>n) do begin
        bil+=n;
        s+=1;
        if(bil>=p) then begin
            bip+=1;
            bil:=bil mod p;
        end;
    end;
    writeln(s,' ',bip);
end.
