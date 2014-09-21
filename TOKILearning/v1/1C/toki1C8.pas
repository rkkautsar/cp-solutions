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


program CekBilPrima;

uses 
crt;
var
	a,i:integer;
	
function prime(n:integer):boolean;
begin
	prime:=true;
	if (n<2) then begin
		prime:=false;
		exit;
	end;
	for i:=2 to trunc(sqrt(n)) do
		if (n mod i=0) then prime:=false;
end;


BEGIN
	while not eof(input) do begin
	readln(a);
	if (prime(a)) then
		writeln('YA')
	else
		writeln('TIDAK');
	end;
END.
