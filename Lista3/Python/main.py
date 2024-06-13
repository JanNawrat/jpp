from GaloisField import GaloisField
from DHSetup import DHSetup
from User import User

def main():
    setup = DHSetup(lambda x: GaloisField(x))
    print(setup.getGenerator())
    user1 = User(setup)
    user2 = User(setup)
    print(user1.getPublicKey())
    print(user2.getPublicKey())
    user1.setKey(user2.getPublicKey())
    user2.setKey(user1.getPublicKey())
    m = user1.encrypt(GaloisField(98765))
    print(m)
    print(user2.decrypt(m))

if __name__ == '__main__':
    main()