import random
import os
from DHSetup import DHSetup

class encryptionKeyNotSet(Exception):
    pass

class User:
    def __init__(self, setup : DHSetup):
        self._setup = setup
        self._encryptionKeySet = False
        random.seed(os.urandom(8))
        self._secret = random.randint(1, 2147483647)

    def getPublicKey(self):
        return self._setup.power(self._setup.getGenerator(), self._secret)

    def setKey(self, a):
        self._encryptionKey = self._setup.power(a, self._secret)
        self._encryptionKeySet = True

    def encrypt(self, m):
        if not self._encryptionKeySet:
            raise encryptionKeyNotSet('Encryption key is not set')
        return m * self._encryptionKey

    def decrypt(self, c):
        if not self._encryptionKeySet:
            raise encryptionKeyNotSet('Encryption key is not set')
        return c / self._encryptionKey