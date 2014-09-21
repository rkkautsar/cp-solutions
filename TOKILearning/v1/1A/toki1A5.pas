{
        toki1A1.pas
        
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
var a :array[1..9] of 1..100;

BEGIN
	readln(a[1],a[2],a[3]);
	readln(a[4],a[5],a[6]);
	readln(a[7],a[8],a[9]);
	writeln(a[1],' ',a[4],' ',a[7]);
	writeln(a[2],' ',a[5],' ',a[8]);
	writeln(a[3],' ',a[6],' ',a[9]);
END.

