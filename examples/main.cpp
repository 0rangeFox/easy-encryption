#include <iostream>
#include "../src/EasyEncryption.h"

using namespace easy::encryption;

int main() {
 	std::string msg = "{\"id\":1,\"method\":\"service.subscribe\",\"params\":[\"myapp/0.1c\", null,\"0.0.0.0\",\"80\"]}";
    std::string key = "THISISMYKEY";

    std::string encryptedMsg = EasyEncryption::encrypt(msg, key);
    std::string decryptedMsg = EasyEncryption::decrypt(encryptedMsg, key);

    std::cout << "Easy Encryption =================================" << std::endl
              << "Key: " << key << std::endl
              << "Original Message: " << msg << std::endl
              << "Encrypted Message: " << encryptedMsg << std::endl
              << "Decrypted Message: " << decryptedMsg << std::endl
              << "Is message identical: " << (msg == decryptedMsg ? "True" : "False") << std::endl
              << "=================================================" << std::endl;

    return 0;
}
