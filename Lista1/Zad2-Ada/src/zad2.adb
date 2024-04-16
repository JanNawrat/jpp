with Text_IO; use Text_IO;
with Ada.Integer_Text_IO; use Ada.Integer_Text_IO;
with Ada_Library; use Ada_Library;
with Test; use Test;

procedure zad2 is
   option : Integer;
   a, b, c : Integer;
   result : Integer;
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
            result := factorial_loop(a);
            Put_Line("Result: " & Integer'Image(result));
         when 2 =>
            Put_Line("Input n");
            Get(a);
            result := factorial_recursive(a);
            Put_Line("Result: " & Integer'Image(result));
         when 3 =>
            Put_Line("Input a and b");
            Get(a);
            Get(b);
            result := gcd_loop(a, b);
            Put_Line("Result: " & Integer'Image(result));
         when 4 =>
            Put_Line("Input a and b");
            Get(a);
            Get(b);
            result := gcd_recursive(a, b);
            Put_Line("Result: " & Integer'Image(result));
         when 5 =>
            Put_Line("Input a, b and c");
            Get(a);
            Get(b);
            Get(c);
            resultSrtuct := diophantic_loop(a, b, c);
            if resultSrtuct.r = 0 then
               Put_Line("Result: x = " & Integer'Image(resultSrtuct.x) & ", y = " & Integer'Image(resultSrtuct.y));
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
            resultSrtuct := diophantic_recursive(a, b, c);
            if resultSrtuct.r = 0 then
               Put_Line("Result: x = " & Integer'Image(resultSrtuct.x) & ", y = " & Integer'Image(resultSrtuct.y));
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
end zad2;
