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
	x1,x2,y1,y2,a,b: -1000000000..1000000000;

BEGIN
	readln(x1,y1,x2,y2);
	if (x1>x2) then
	a:=x1-x2
	else
	a:=x2-x1;
	if (y1>y2) then
	b:=y1-y2
	else
	b:=y2-y1;
	writeln(a+b);
END.

