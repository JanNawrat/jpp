#include <iostream>
#include "User.hpp"
#include "GaloisField.hpp"

int main() {
    DHSetup<GaloisField> setup = DHSetup<GaloisField>();
    std::cout << setup.getGenerator() << '\n';
    User<GaloisField> user1 = User<GaloisField>(setup);
    User<GaloisField> user2 = User<GaloisField>(setup);
    std::cout << user1.getPublicKey() << '\n';
    std::cout << user2.getPublicKey() << '\n';
    user1.setKey(user2.getPublicKey());
    user2.setKey(user1.getPublicKey());
    GaloisField m = user1.encrypt(98765);
    std::cout << m << '\n';
    std::cout << user2.decrypt(m) << '\n';

    return 0;
}