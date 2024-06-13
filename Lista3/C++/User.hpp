#include "DHSetup.hpp"

class encryptionKeyNotSet : public std::exception {
    public:
char * what () {
        return "Encryption key is not set";
    }
};

template <typename T>
class User
{
private:
    DHSetup<T>& setup;
    int secret;
    T encryptionKey;
    bool encryptionKeySet = false;
public:
    User(DHSetup<T>& setup) : setup(setup) {
        std::random_device rd;
        std::mt19937 mt{rd()};
        std::uniform_int_distribution<int> dist(1, INT32_MAX);
        secret = dist(mt);
    }

    T getPublicKey() {
        return setup.power(setup.getGenerator(), secret);
    }

    void setKey(T a) {
        encryptionKey = setup.power(a, secret);
        encryptionKeySet = true;
    }

    T encrypt(T m) {
        if(!encryptionKeySet) {
            throw encryptionKeyNotSet();
        }
        return m * encryptionKey;
    }

    T decrypt(T c) {
        if(!encryptionKeySet) {
            throw encryptionKeyNotSet();
        }
        return c / encryptionKey;
    }
};
