Program TOKI_2C_Correction;
 
function charToNum(x:char):integer;
Begin
    case x of
        'a' : charToNum:=1;
        'b' : charToNum:=2;
        'c' : charToNum:=3;
        'd' : charToNum:=4;
        'e' : charToNum:=5;
        'f' : charToNum:=6;
        'g' : charToNum:=7;
        'h' : charToNum:=8;
        'i' : charToNum:=9;
        'j' : charToNum:=10;
        'k' : charToNum:=11;
        'l' : charToNum:=12;
        'm' : charToNum:=13;
        'n' : charToNum:=14;
        'o' : charToNum:=15;
        'p' : charToNum:=16;
        'q' : charToNum:=17;
        'r' : charToNum:=18;
        's' : charToNum:=19;
        't' : charToNum:=20;
        'u' : charToNum:=21;
        'v' : charToNum:=22;
        'w' : charToNum:=23;
        'x' : charToNum:=24;
        'y' : charToNum:=25;
        'z' : charToNum:=26;
    End;    
End;
 
function numToChar(x:integer):char;
Begin
    case x of
        1 : numToChar:='a';
        2 : numToChar:='b';
        3 : numToChar:='c';
        4 : numToChar:='d';
        5 : numToChar:='e';
        6 : numToChar:='f';
        7 : numToChar:='g';
        8 : numToChar:='h';
        9 : numToChar:='i';
        10 : numToChar:='j';
        11 : numToChar:='k';
        12 : numToChar:='l';
        13 : numToChar:='m';
        14 : numToChar:='n';
        15 : numToChar:='o';
        16 : numToChar:='p';
        17 : numToChar:='q';
        18 : numToChar:='r';
        19 : numToChar:='s';
        20 : numToChar:='t';
        21 : numToChar:='u';
        22 : numToChar:='v';
        23 : numToChar:='w';
        24 : numToChar:='x';
        25 : numToChar:='y';
        26 : numToChar:='z';
    End;    
End;
 
function correct(word:string;K:integer;dictionary:array of string):string;
Var
    counter,counter2,counter3,tempValue,temp,tempWord,tempDictionary2,temporary:integer;
    tempDictionary,numDictionary:string;
Begin
    tempValue:=32000;
 
        for counter:=1 to K do
        Begin
            tempDictionary:=copy(dictionary[counter],1,length(word));
            temp:=0;
 
            for counter2:=1 to length(word) do
            Begin
                tempWord:=charToNum(Word[counter2]);
                tempDictionary2:=charToNum(tempDictionary[counter2]);
                if tempDictionary2<tempWord then temporary:=tempWord-tempDictionary2 else temporary:=tempDictionary2-tempWord;
                if temporary>13 then temporary:=26-temporary;
                temp:=temp+temporary;
            End;
 
            if tempValue>temp then
            Begin
                numDictionary:=tempDictionary;
                tempValue:=temp;
            End;
        End;
 
    correct:=numDictionary;
End;
 
Var
    K,counter:integer;
    dictionary:array[1..5000] of string;
    word,temp:string;
Begin
    readln(K);
 
    for counter:=1 to K do
    Begin
        readln(dictionary[counter]);
    End;
 
    readln(word);
 
    for counter:=1 to length(word) do
    Begin
        temp:=copy(word,1,counter);
        temp:=correct(temp,K,dictionary);
        writeln(temp);
    End;
End.