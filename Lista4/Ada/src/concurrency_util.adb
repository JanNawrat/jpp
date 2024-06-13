package body Concurrency_Util is

protected body Semaphore is
    entry Wait when Capacity > 0 is
    begin
        Capacity := Capacity - 1;
    end Wait;

    procedure Signal is
    begin
        Capacity := Capacity + 1;
    end Signal;
end;

procedure Initialize (Self: in out Monitor) is 
begin
    Self.S := new Semaphore(1);
    Self.Fork := (others => 2);
    Self.OK_To_Eat_S := (others => new Semaphore(0));
    Self.OK_To_Eat_C := (others => 0);
    Self.Roster := (others => FALSE);
    Self.Meals_Left := (others => Self.Number_Of_Meals);
end Initialize;

procedure Take_Forks (M: in out Monitor; I: Positive) is
    Fork_To_The_Left: Natural := (if I < M.Number_Of_Philosophers then I + 1 else 1);
    Fork_To_The_Right: Natural := (if I > 1 then I - 1 else M.Number_Of_Philosophers);
begin
    M.S.Wait;
    if (M.Fork (I) /= 2) then
        M.OK_To_Eat_C (I) := M.OK_To_Eat_C (I) + 1;
        M.S.Signal;
        M.OK_To_Eat_S (I).Wait;
        M.S.Wait;
        M.OK_To_Eat_C (I) := M.OK_To_Eat_C (I) - 1;
    end if;
    M.Fork (Fork_To_The_Left) := M.Fork (Fork_To_The_Left) - 1;
    M.Fork (Fork_To_The_Right) := M.Fork (Fork_To_The_Right) - 1;
    Add_To_Roster(M, I);
    M.S.Signal;
end Take_Forks;

procedure Release_Forks (M: in out Monitor; I: Positive) is
    Fork_To_The_Left: Natural := (if I < M.Number_Of_Philosophers then I + 1 else 1);
    Fork_To_The_Right: Natural := (if I > 1 then I - 1 else M.Number_Of_Philosophers);
begin
    M.S.Wait;
    M.Fork (Fork_To_The_Left) := M.Fork (Fork_To_The_Left) + 1;
    M.Fork (Fork_To_The_Right) := M.Fork (Fork_To_The_Right) + 1;
    if (M.Fork (Fork_To_The_Left) = 2) then
        if (M.OK_To_Eat_C (Fork_To_The_Left) /= 0) then
            M.OK_To_Eat_S (Fork_To_The_Left).Signal;
        end if;
    end if;
    if (M.Fork (Fork_To_The_Right) = 2) then
        if (M.OK_To_Eat_C (Fork_To_The_Right) /= 0) then
            M.OK_To_Eat_S (Fork_To_The_Right).Signal;
        end if;
    end if;
    Remove_From_Roster(M, I);
    M.S.Signal;
end Release_Forks;

procedure Add_To_Roster (M: in out Monitor; I: Positive) is
begin
    M.Roster (I) := TRUE;
    Put_Line("=============");
    Put_Line("Philosopher" & Positive'Image(I) & " started eating");
    Put("(");
    Put((if M.Roster (1) then "1" else "_"));
    for J in 2 .. M.Number_Of_Philosophers loop
        Put((if M.Roster (J) then "," & Positive'Image(J) else ", _"));
    end loop;
    Put_Line(")");
end Add_To_Roster;

procedure Remove_From_Roster (M: in out Monitor; I: Positive) is
begin
    M.Roster (I) := FALSE;
    M.Meals_Left (I) := M.Meals_Left (I) - 1;
    Put_Line("=============");
    Put_Line("Philosopher" & Positive'Image(I) & " stopped eating");
    if (M.Meals_Left (I) > 0) then
        Put_Line("Meals left:" & Positive'Image(M.Meals_Left (I)));
    else 
        Put_Line("Philosopher" & Positive'Image(I) & " finished all of their meals");
    end if;
    Put("(");
    Put((if M.Roster (1) then "1" else "_"));
    for J in 2 .. M.Number_Of_Philosophers loop
        Put((if M.Roster (J) then "," & Positive'Image(J) else ", _"));
    end loop;
    Put_Line(")");
end Remove_From_Roster;

end Concurrency_Util;