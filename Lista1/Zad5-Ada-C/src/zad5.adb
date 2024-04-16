with Interfaces.C; use Interfaces.C;
with Ada.Text_IO;  use Ada.Text_IO;
with Ada.Integer_Text_IO; use Ada.Integer_Text_IO;
with Test; use Test;

procedure zad5 is
  type DiophanticResult is record
    r : Interfaces.C.int;
    x : Interfaces.C.int;
    y : interfaces.C.int;
  end record;
  pragma Convention (C, DiophanticResult);

  function factorial_loop(n : int) return int
    with
      Import        => True,
      Convention    => C;

  function factorial_recursive(n : int) return int
    with
      Import        => True,
      Convention    => C;

  function gcd_loop(a: int; b: int) return int
    with
      Import        => True,
      Convention    => C;

  function gcd_recursive(a: int; b: int) return int
    with
      Import        => True,
      Convention    => C;

  function diophantic_loop(r0: int; r1: int; c: int) return DiophanticResult
    with
      Import        => True,
      Convention    => C;

  function diophantic_recursive_body(r0: int; r1: int; c: int; s0: int; s1: int; t0: int; t1: int) return DiophanticResult
    with
      Import        => True,
      Convention    => C;

  function diophantic_recursive(a: int; b: int; c: int) return DiophanticResult
    with
      Import        => True,
      Convention    => C;

   option : Integer;
   a, b, c : Integer;
   result : interfaces.C.int;
   resultSrtuct : DiophanticResult;
   pragma Assertion_Policy (Assert => Check);
begin
   -- Test
   test_factorial_loop;
   test_factorial_recursive;
   test_GCD_loop;
   test_GCD_recursive;
   test_diophantic_loop;
   test_diophantic_recursive;
   Put_Line("All tests passed");
   -- Zad2
   Put_Line("Library in Ada!");
   loop
      Put_Line("1. Factorial loop");
      Put_Line("2. Factorial recursive");
      Put_Line("3. GCD loop");
      Put_Line("4. GCD recursive");
      Put_Line("5. Diophantic loop");
      Put_Line("6. Diophantic recursive");
      Put_Line("7. Exit");
      Get(option);
      case option is
         when 1 =>
            Put_Line("Input n");
            Get(a);
            result := factorial_loop(Interfaces.C.int(a));
            Put_Line("Result: " & Interfaces.C.int'Image(result));
         when 2 =>
            Put_Line("Input n");
            Get(a);
            result := factorial_recursive(Interfaces.C.int(a));
            Put_Line("Result: " & Interfaces.C.int'Image(result));
         when 3 =>
            Put_Line("Input a and b");
            Get(a);
            Get(b);
            result := gcd_loop(Interfaces.C.int(a), Interfaces.C.int(b));
            Put_Line("Result: " & Interfaces.C.int'Image(result));
         when 4 =>
            Put_Line("Input a and b");
            Get(a);
            Get(b);
            result := gcd_recursive(Interfaces.C.int(a), Interfaces.C.int(b));
            Put_Line("Result: " & Interfaces.C.int'Image(result));
         when 5 =>
            Put_Line("Input a, b and c");
            Get(a);
            Get(b);
            Get(c);
            resultSrtuct := diophantic_loop(Interfaces.C.int(a), Interfaces.C.int(b), Interfaces.C.int(c));
            if resultSrtuct.r = 0 then
               Put_Line("Result: x = " & Interfaces.C.int'Image(resultSrtuct.x) & ", y = " & Interfaces.C.int'Image(resultSrtuct.y));
            elsif resultSrtuct.r = 1 then
               Put_Line("No results");
            elsif resultSrtuct.r = 2 then
               Put_Line("Infinite number of results");
            end if;
         when 6 =>
            Put_Line("Input a, b and c");
            Get(a);
            Get(b);
            Get(c);
            resultSrtuct := diophantic_recursive(Interfaces.C.int(a), Interfaces.C.int(b), Interfaces.C.int(c));
            if resultSrtuct.r = 0 then
               Put_Line("Result: x = " & Interfaces.C.int'Image(resultSrtuct.x) & ", y = " & Interfaces.C.int'Image(resultSrtuct.y));
            elsif resultSrtuct.r = 1 then
               Put_Line("No results");
            elsif resultSrtuct.r = 2 then
               Put_Line("Infinite number of results");
            end if;
         when 7 =>
            exit;
         when others =>
            null;
      end case;
   end loop;
end zad5;
