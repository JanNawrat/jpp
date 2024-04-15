with Interfaces.C; use Interfaces.C;

package body JPPLib is
    function factorial_loop(n: Integer) return Integer is
        factorial: Integer := 1;
        n_copy: Integer := n;
    begin
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
        a: Integer := a_in;
        b: Integer := b_in;
    begin
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

    function diophantic_loop(
        a : Integer;
        b : Integer;
        c : Integer) return DiophanticResult
    is
        r0 : Integer := a;
        r1 : Integer := b;
        s0 : Integer := 1;
        s1 : Integer := 0;
        t0 : Integer := 0;
        t1 : Integer := 1;
        q, tmp : Integer;
    begin
        if r0 = 0 and r1 = 0 then
            if c = 0 then
                return (r => 2, x => 0, y => 0);
            else
                return (r => 1, x => 0, y => 0);
            end if;
        end if;

        while r1 /= 0 loop
            q := r0/r1;
            tmp := r1;
            r1 := r0 - r1*q;
            r0 := tmp;  

            tmp := s1;
            s1 := s0 - s1*q;
            s0 := tmp;

            tmp := t1;
            t1 := t0 - t1*q;
            t0 := tmp;
        end loop;

        if c rem r0 /= 0 then
            return (r => 1, x => 0, y => 0);
        end if;

        return (r => 0, x => s0*c/r0, y => t0*c/r0);
    end diophantic_loop;

     function diophantic_recursive_call(
        r0 : Integer;
        r1 : Integer;
        c  : Integer) return DiophanticResult is
    begin
        return diophantic_recursive(r0, r1, c);
    end diophantic_recursive_call;

    function diophantic_recursive(
        r0_in : Integer;
        r1_in : Integer;
        c : Integer;
        s0_in : Integer := 1;
        s1_in : Integer := 0;
        t0_in : Integer := 0;
        t1_in : Integer := 1) return DiophanticResult
    is
        r0 : Integer := r0_in;
        r1 : Integer := r1_in;
        s0 : Integer := s0_in;
        s1 : integer := s1_in;
        t0 : Integer := t0_in;
        t1 : integer := t1_in;
        q, tmp : Integer;
    begin
        if r1 = 0 then
            if r0 = 0 then
                return (r => (if c = 0 then 2 else 1), others => <>);
            elsif c rem r0 /= 0 then
                return (r => 1, others => <>);
            else
                return (r => 0, x => s0*c/r0, y => t0*c/r0);
            end if;
        end if;

        q := r0/r1;

        tmp := r1;
        r1 := r0 - r1*q;
        r0 := tmp;  

        tmp := s1;
        s1 := s0 - s1*q;
        s0 := tmp;

        tmp := t1;
        t1 := t0 - t1*q;
        t0 := tmp;

        return diophantic_recursive(r0, r1, c, s0, s1, t0, t1);
    end diophantic_recursive;

end JPPLib;
