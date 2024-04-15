with Interfaces.C; use Interfaces.C;
with Ada.Text_IO;  use Ada.Text_IO;

procedure main is
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

   V : DiophanticResult;
begin
   V := diophantic_loop(240, 46, 28);
   Put_Line ("Result is " & int'Image (V.r));
   Put_Line ("Result is " & int'Image (V.x));
   Put_Line ("Result is " & int'Image (V.y));
end main;