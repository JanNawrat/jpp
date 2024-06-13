package body Tasks is

task body Philosopher is
    T_I: Positive;
    T_Number_Of_Meals: Positive;
    T_Wait_Time: Positive;
    T_M: access Monitor;

    Random_Wait_Time: Duration;
    type Random_Range is range 100 .. 1000;
    package My_Random is new Ada.Numerics.Discrete_Random(Random_Range);
    use My_Random;
    G: Generator;
    X: Random_Range;
begin
    Reset(G);

    accept Start(I: Positive; Number_Of_Meals: Positive; Wait_Time: Positive; M: Monitor_Access) do
        T_I := I;
        T_Number_Of_Meals := Number_Of_Meals;
        T_Wait_Time := Wait_Time;
        T_M := M;
    end Start;

    for J in 1 .. T_Number_Of_Meals loop
        -- think
        X := Random(G);
        Random_Wait_Time := Duration(X) / 1000.0;
        delay Random_Wait_Time;
        -- grab forks
        Take_Forks(T_M.all, T_I);
        -- eat
        X := Random(G);
        Random_Wait_Time := Duration(X) / 1000.0;
        delay Random_Wait_Time;
        -- release forks
        Release_Forks(T_M.all, T_I);
    end loop;
end Philosopher;

end Tasks;