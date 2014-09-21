type matrix=array [1..100,1..100] of char;
const 	r:array[1..8] of smallint=(1, 1, 1,-1,-1,-1, 0, 0);
		c:array[1..8] of smallint=(0, 1,-1, 0, 1,-1, 1,-1);
var
mat:matrix;
i,j,k,m,t,n,x,cur,p,q:shortint;
st:string;
found:boolean;

begin
	readln(m,n);
	for i:=1 to m do begin
		j:=1;
		while j<=n do begin
		read(mat[i,j]);
		if ((mat[i,j]) in ['A'..'Z']) then j+=1;
		end;
	end;
	readln(t);
	for i:=1 to t do begin
		readln(st);	
		found:=false;
		for j:=1 to m do
		for k:=1 to n do
			if (mat[j,k]=st[1]) then begin
			for x:=1 to 8 do begin
				cur:=1;p:=j;q:=k;
				while (mat[p,q]=st[cur]) do begin
					cur+=1;
					p+=r[x];
					q+=c[x];
				end;
				if cur>length(st) then found:=true;
			end;
			end;
		if found then writeln(st,' Y')
		else writeln(st,' T');	
	end;
end.
