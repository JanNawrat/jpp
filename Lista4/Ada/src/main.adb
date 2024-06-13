with Text_IO; use Text_IO;
with Concurrency_Util; use Concurrency_Util;
with Tasks; use Tasks;

procedure Main is
    M: Monitor_Access;
    Number_Of_Philosophers: Positive := 5;
    Number_Of_Meals: Positive := 5;
    Philosophers: Philosopher_Array(1 .. Number_Of_Philosophers);
begin
    M := new Monitor(Number_Of_Philosophers, Number_Of_Meals);
    for I in 1 .. Number_Of_Philosophers loop
        Philosophers (I).Start(I, Number_Of_Meals, 1000, M);
    end loop;
end Main;