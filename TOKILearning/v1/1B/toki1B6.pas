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

uses crt;
var
	a:real;
	flr,ceil: -1000000..1000000;

BEGIN
	readln(a);
	if (trunc(a)>0) then begin
		flr:=trunc(a);
		ceil:=trunc(a)+1;
	end else if (trunc(a)<0) then begin
		flr:=trunc(a)-1;
		ceil:=trunc(a);
	end;
	writeln(flr,' ',ceil);
END.

