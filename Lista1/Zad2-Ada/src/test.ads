with Ada_Library; use Ada_Library;
with Ada.Assertions; use Ada.Assertions;

package Test is
    pragma Preelaborate;
    procedure test_factorial_loop;
    procedure test_factorial_recursive;
    procedure test_GCD_loop;
    procedure test_GCD_recursive;
    procedure test_diophantic_loop;
    procedure test_diophantic_recursive;
private
end Test;