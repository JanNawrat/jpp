class GaloisField:
    _size = 1234567891

    # constructors
    def __init__(self):
        self._value = 0

    def __init__(self, v):
        v = int(v)
        while v < 0:
            v += self._size
        self._value = v % self._size

    # private methods
    def _modular_multiplication(self, a, b):
        res = 0
        while b > 0:
            partialSum = a
            i = 2
            while i <= b:
                partialSum = (2 * partialSum) % self._size
                i *= 2
            res = (res + partialSum) % self._size
            b -= i/2
        return res

    def _modular_multiplicative_inverse(self, v):
        if v == 0:
            raise ArithmeticError(f'{v} does not have a modular multiplicative inverse in Galois field of size {self._size}')

        r0 = self._size
        r1 = v
        t0 = 0
        t1 = 1

        while r1 != 0:
            q = r0//r1
            tmp = r1
            r1 = r0 - r1*q
            r0 = tmp

            tmp = t1
            t1 = t0 - t1*q
            t0 = tmp

        if r0 != 1:
            raise ArithmeticError(f'{v} does not have a modular multiplicative inverse in Galois field of size {self._size}')

        while t0 < 0:
            t0 += self._size

        return t0 % self._size

    # conversion operators
    def __int__(self):
        return self._value

    def __str__(self):
        return f'{self._value} in Galois field of size {self._size}'
    
    # comparisons operatos
    def __eq__(self, other):
        if isinstance(other, GaloisField):
            return self._value == other._value
        elif isinstance(other, int):
            return self._value == other
        else:
            return False
    
    def __ne__(self, other):
        return self._value != other._value
    
    def __le__(self, other):
        return self._value <= other._value
    
    def __ge__(self, other):
        return self._value >= other._value
    
    def __lt__(self, other):
        return self._value < other._value
    
    def __gt__(self, other):
        return self._value > self._value
    
    # arithmetic operations
    def __add__(self, other):
        return GaloisField(self._value + other._value)
    
    def __sub__(self, other):
        return GaloisField(self._value - other._value)
    
    def __mul__(self, other):
        return GaloisField(self._modular_multiplication(self._value, other._value))
    
    def __truediv__(self, other):
        try:
            inverse = self._modular_multiplicative_inverse(other._value)
            return GaloisField(self._modular_multiplication(self._value, inverse))
        except ArithmeticError as e:
            raise e
        
    # assingment operators
    def __iadd__(self, other):
        self._value = (self._value + other._value) % self._size
        return self

    def __isub__(self, other):
        self._value = (self._value - other._value + self._size) % self._size
        return self

    def __imul__(self, other):
        self._value = self._modular_multiplication(self._value, other._value)
        return self

    def __itruemul__(self, other):
        try:
            inverse = self._modular_multiplicative_inverse(other._value)
            self._value = self._modular_multiplication(self._value, inverse)
            return self
        except ArithmeticError as e:
            raise e
