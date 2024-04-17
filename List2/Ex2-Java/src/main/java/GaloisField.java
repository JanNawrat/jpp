public class GaloisField implements Comparable<GaloisField>{
    private static final int size = 1234577;
    private int value;

    // constructors
    public GaloisField() {
        value = 0;
    }

    public GaloisField(int v) {
        while(v < 0) {
            v += size;
        }
        value = v % size;
    }

    // private methods
    private static int modular_multiplication(int a, int b) {
        int res = 0;
        while(b > 0) {
            int partialSum = a;
            int i;
            for(i = 2; i <= b; i*=2) {
                partialSum = (2 * partialSum) % size;
            }
            res = (res + partialSum) % size;
            b -= i/2;
        }
        return res;
    }
    private static int modular_multiplicative_inverse(int v) {
        int r0 = size;
        int r1 = v;
        if(r1 == 0) {
            throw new ArithmeticException(v + " does not have a modular multiplicative inverse in Galois field of size " + size);
        }

        int q, tmp, s0 = 1, s1 = 0, t0 = 0, t1 = 1;

        while (r1 != 0) {
            q = r0/r1;
            tmp = r1;
            r1 = r0 - r1*q;
            r0 = tmp;

            tmp = s1;
            s1 = s0 - s1*q;
            s0 = tmp;

            tmp = t1;
            t1 = t0 - t1*q;
            t0 = tmp;
        }

        if (r0 != 1) {
            throw new ArithmeticException(v + " does not have a modular multiplicative inverse in Galois field of size " + size);
        }

        while(t0 < 0) {
            t0 += size;
        }

        return t0 % size;
    }

    // comparison methods
    @Override
    public boolean equals(Object obj) {
        if (obj instanceof GaloisField) {
            return value == ((GaloisField) obj).value;
        } else {
            return false;
        }
    }
    @Override
    public int compareTo(GaloisField obj) {
        if (value > obj.value) {
            return  1;
        } else if (value < obj.value) {
            return -1;
        } else {
            return 0;
        }
    }

    // arithmetic methods
    public static GaloisField add(GaloisField obj1, GaloisField obj2) {return new GaloisField(obj1.value + obj2.value);}
    public static GaloisField subtract(GaloisField obj1, GaloisField obj2) {return new GaloisField(obj1.value - obj2.value);}
    public static GaloisField mutiply(GaloisField obj1, GaloisField obj2) {return new GaloisField(modular_multiplication(obj1.value, obj2.value));}
    public static GaloisField divide(GaloisField obj1, GaloisField obj2) {
        try {
            int inverse = modular_multiplicative_inverse(obj2.value);
            return new GaloisField(modular_multiplication(obj1.value, inverse));
        } catch (Exception e) {
            throw e;
        }
    }

    // assignment methods
    public void clone(GaloisField obj) {value = obj.value;}
    public void add(GaloisField obj) {value = (value + obj.value) % size;}
    public void subtract(GaloisField obj) {value = (value - obj.value + size) % size;}
    public void multiply(GaloisField obj) {value = modular_multiplication(value, obj.value);}
    public void divide(GaloisField obj) {
        try {
            int inverse = modular_multiplicative_inverse(obj.value);
            value = modular_multiplication(value, inverse);
        } catch (Exception e) {
            throw e;
        }
    }

    // conversion methods
    public int toInt() {return value;}
    public String toString() {return "Value " + value + " in Galois field of size " + size;}
}
