procedure S;
begin
    if sym='a' or sym='^'
        then advance
        else if sym='('
            then begin
                advance;T;
                if sym=')' then advance;
                    else error;
                end
            else error
end;
procedure T;
begin
    S;T'
end;
procedure T';
begin
    if sym=','
        then begin
            advance
            S;T'
        end
end;

