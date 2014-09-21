{
        toki1B2.pas
        
        Copyright 2012 Rakha Kanz Kautsar <rkkautsar@Portege-T110>
        
        This program is free software; you can redistribute it and/or modify
        it under the terms of the GNU General Public License as published by
        the Free Software Foundation; either version 2 of the License, or
        (at your option) any later version.
        
        This program is distributed in the hope that it will be useful,
        but WITHOUT ANY WARRANTY; without even the implied warranty of
        MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
        GNU General Public License for more details.
        
        You should have received a copy of the GNU General Public License
        along with this program; if not, write to the Free Software
        Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
        MA 02110-1301, USA.
        
        
}


program untitled;

uses 
crt;

var
    n,i,j,a,b: 0..10;
    
begin
	a:=0;
    readln(n);
    for i:=1 to n do begin
		b:=1;
		while(b<=i) do begin
			j:=a;
			write(j);
			if (a<9) then
			a:=j+1
			else a:=0;
			b:=b+1;
		end;
		writeln();
	end;
end.

