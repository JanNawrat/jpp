with Concurrency_Util; use Concurrency_Util;
with Ada.Numerics.Discrete_Random;
with Text_IO; use Text_IO;

package Tasks is

type Monitor_Access is access all Monitor;

task type Philosopher  is
    entry Start(I: Positive; Number_Of_Meals: Positive; Wait_Time: Positive; M: Monitor_Access);
end Philosopher;

type Philosopher_Array is array(Natural range <>) of Philosopher;

end Tasks;