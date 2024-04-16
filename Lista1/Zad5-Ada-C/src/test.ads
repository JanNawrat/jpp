with Ada.Assertions; use Ada.Assertions;
with Interfaces.C; use Interfaces.C;

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