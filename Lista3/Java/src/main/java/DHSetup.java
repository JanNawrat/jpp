import java.util.ArrayList;
import java.util.Random;

public class DHSetup<T extends Arithmetic> {
    private static final int p = 1234567891;
    private TFactory<T> factory;
    private final T generator;

    public DHSetup(TFactory<T> factory) {
        this.factory = factory;

        // generate vector of prime divisors of p - 1
        int upperBound = (int)Math.floor(Math.sqrt(p - 1));
        int remainingInteger = p - 1;
        ArrayList<Boolean> isPrime = new ArrayList<Boolean>(upperBound + 1);
        for(int i = 0; i < upperBound + 1; i++) {
            isPrime.add(true);
        }
        ArrayList<Integer> exponents = new ArrayList<Integer>();
        int i = 2;
        while(i < upperBound + 1) {
            if(isPrime.get(i)) {
                for(int j = i * 2; j < upperBound + 1; j += i) {
                    isPrime.set(j, false);
                }
                if(remainingInteger % i == 0) {
                    exponents.add(i);
                    while(remainingInteger % i == 0) {
                        remainingInteger /= i;
                    }
                    if(remainingInteger < upperBound) {
                        upperBound = remainingInteger;
                    }
                }
            }
            i += 1;
        }

        // find a generator
        Random rand = new Random();
        T generatorCandidate;
        Boolean isGenerator;
        do {
            generatorCandidate = this.factory.factory(rand.nextInt(1, p));
            isGenerator = true;
            for(i = 0; i < exponents.size(); i++) {
                if(power(generatorCandidate, exponents.get(i)) == this.factory.factory(1)) {
                    isGenerator = false;
                    break;
                }
            }
        } while(!isGenerator);
        generator = generatorCandidate;
    }

    public T getGenerator() {
        return this.generator;
    }

    public T power(T a, long b) {
        T result = this.factory.factory(1);
        while(b != 0) {
            T partial = factory.factory(0);
            partial.clone(a);
            long i = 2;
            while(i <= b) {
                partial.multiply(a);
                i *= 2;
            }
            result.multiply(partial);
            b -= i/2;
        }
        return result;
    }
}
