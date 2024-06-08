#include <iostream>
#include "../src/vigenere/Vigenere.h"

using namespace easy::encryption;

int main() {
    std::string msg = "HELLO WORLD";
    std::string key = "THISISALONGPRIVATEKEY";

    std::string encryptedMsg = Vigenere::encrypt(msg, key);
    std::string decryptedMsg = Vigenere::decrypt(encryptedMsg, key);

    std::cout << "Vigenere =================================" << std::endl
              << "Key: " << key << std::endl
              << "Original Message: " << msg << std::endl
              << "Encrypted Message: " << encryptedMsg << std::endl
              << "Decrypted Message: " << decryptedMsg << std::endl
              << "Is message identical: " << (msg == decryptedMsg ? "True" : "False") << std::endl
              << "==========================================" << std::endl;

    return 0;
}
