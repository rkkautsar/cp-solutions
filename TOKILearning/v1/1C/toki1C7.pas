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
    a:array[1..10000] of real;
    jml:real;
    n,i:1..10000;
    rata,max,min:real;
begin
	readln(n);
	jml:=0;
	for i:=1 to n do begin
		readln(a[i]);
		jml:=jml+a[i];
	end;
	rata:=jml/n;
	max:=a[1];
	min:=a[1];
	clrscr;
	for i:=2 to n do
	begin
		if a[i] > max then max:=a[i];
		if a[i] < min then min:=a[i];
	end;
	writeln(min:0:2,' ',max:0:2,' ',rata:0:2);
end.
