import math
import random
import os

p = 1234567891

class DHSetup:
    def __init__(self, factory):
        self.factory = factory
        # generate vector of prime divisors of p - 1
        upperBound = math.floor(math.sqrt(p - 1))
        remainingInteger = p - 1
        isPrime = [True for _ in range(0, upperBound + 1)]
        exponents = []
        i = 2
        while i < upperBound + 1:
            if isPrime[i]:
                for j in range (i*2, upperBound + 1, i):
                    isPrime[j] = False
                if remainingInteger % i == 0:
                    exponents.append(i)
                    while remainingInteger % i == 0:
                        remainingInteger //= i
                    if remainingInteger < upperBound:
                        upperBound = remainingInteger
            i += 1

        # find a generator
        random.seed(os.urandom(8))
        isGenerator = False
        while not isGenerator:
            self._generator = self.factory(random.randint(1, p - 1))
            isGenerator = True
            for i in range(0, len(exponents)):
                if self.power(self._generator, exponents[i]) == 1:
                    isGenerator = False
                    break

    def getGenerator(self):
        return self._generator

    def power(self, a, b):
        result = self.factory(1)
        while b != 0:
            partial = self.factory(a)
            i = 2
            while i <= b:
                partial *= self.factory(a)
                i *= 2
            result *= partial
            b -= i//2
        return result
