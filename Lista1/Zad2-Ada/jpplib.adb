package body JPPLib is
    function factorial_loop(n: Integer) return Integer is
        factorial: Integer;
        n_copy: Integer;
    begin
        factorial := 1;
        n_copy := n;
        while n_copy > 1 loop
            factorial := factorial * n_copy;
            n_copy := n_copy - 1;
        end loop;
        return factorial;
    end factorial_loop;

    function factorial_recursive(n: Integer) return Integer is
    begin
        if n <= 1 then
            return 1;
        end if;
        return n * factorial_recursive(n - 1);
    end factorial_recursive;

    function gcd_loop(
        a_in: Integer;
        b_in: Integer) return Integer
    is
        a: Integer;
        b: Integer;
    begin
        a := a_in;
        b := b_in;
        while a /= 0 and b /= 0 loop
            if a > b then
                a := a rem b;
            else
                b := b rem a;
            end if;
        end loop;
        if a = 0 then
            return b;
        else
            return a;
        end if;
    end gcd_loop;

    function gcd_recursive(
        a: Integer;
        b: Integer) return Integer
    is
    begin
        if a = 0 then
            return b;
        elsif b = 0 then
            return a;
        elsif a > b then
            return gcd_recursive(a rem b, b);
        else
            return gcd_recursive(a, b rem a);
        end if;
    end gcd_recursive;
end JPPLib;
