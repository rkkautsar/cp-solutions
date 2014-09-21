program swap;

var
    a, b: integer;

procedure swap(var x,y: integer);
var
    temp: integer;
begin
    temp := x;
    x := y;
    y := temp;
end;

begin
    readln(a, b);
    swap(a, b);
    writeln(a, ' ', b);
end.
