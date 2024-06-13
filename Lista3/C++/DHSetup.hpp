#include <random>

static const int p = 1234567891;

template <typename T>
class DHSetup
{
private:
    T generator;
public:
    DHSetup() {
        // generate vector of prime divisors of p - 1
        int upperBound = floor(sqrt(p - 1));
        int remainingInteger = p - 1;
        std::vector<bool> isPrime(upperBound + 1, true);
        std::vector<int> exponents;
        int i = 2;
        while(i < upperBound + 1) {
            if(isPrime[i]) {
                for(int j = i * 2; j < upperBound + 1; j += i) {
                    isPrime[j] = false;
                }
                if(remainingInteger % i == 0) {
                    exponents.push_back(i);
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
        std::random_device rd;
        std::mt19937 mt{rd()};
        bool isGenerator;
        do {
            std::uniform_int_distribution<int> dist(1, p - 1);
            generator = dist(mt);
            isGenerator = true;
            for(int i = 0; i < exponents.size(); i++) {
                if(power(generator, exponents[i]) == T(1)) {
                    isGenerator = false;
                    break;
                }
            }
        } while(!isGenerator);
    }

    T getGenerator() {
        return generator;
    }

    static T power(T a, unsigned long b) {
        T result = 1;
        while(b != 0) {
            T partial = a;
            unsigned long i = 2;
            while(i < b) {
                partial *= partial;
                i *= 2;
            }
            result *= partial;
            b -= i/2;
        }
        return result;
    }
};
