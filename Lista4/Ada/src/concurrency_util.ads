with Ada.Finalization;
with  Text_IO; use Text_IO;

package Concurrency_Util is

protected type Semaphore (New_Capacity: Natural) is
    entry Wait;
    procedure Signal;
    private Capacity: Natural := New_Capacity;
end;

type Integer_Array is array(Natural range <>) of Integer;
type Boolean_Array is array(Natural range <>) of Boolean;
type Semaphore_Array is array(Natural range <>) of access Semaphore;

type Monitor (Number_Of_Philosophers: Positive; Number_Of_Meals: Positive) is new Ada.Finalization.Controlled with record
    -- monitor functionality
    S: access Semaphore;
    Fork: Integer_Array(1 .. Number_Of_Philosophers);
    OK_To_Eat_S: Semaphore_Array(1 .. Number_Of_Philosophers);
    OK_To_Eat_C: Integer_Array(1 .. Number_Of_Philosophers);
    -- roster functionality
    Roster: Boolean_Array(1 .. Number_Of_Philosophers);
    Meals_Left: Integer_Array(1 .. Number_Of_Philosophers);
end record;

procedure Initialize (Self: in out Monitor);

procedure Take_Forks (M: in out Monitor; I: Positive);

procedure Release_Forks (M: in out Monitor; I: Positive);

procedure Add_To_Roster (M: in out Monitor; I: Positive);

procedure Remove_From_Roster (M: in out Monitor; I: Positive);

end Concurrency_Util;