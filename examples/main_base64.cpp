#include <iostream>
#include "../src/base64/Base64.h"

using namespace easy::encryption;

int main() {
    std::string msg = "HELLO WORLD";

    std::string encodedMsg = Base64::encode(msg);
    std::string decodedMsg = Base64::decode(encodedMsg);

    std::cout << "Base64 =================================" << std::endl
              << "Original Message: " << msg << std::endl
              << "Encoded Message: " << encodedMsg << std::endl
              << "Decoded Message: " << decodedMsg << std::endl
              << "Is message identical: " << (msg == decodedMsg ? "True" : "False") << std::endl
              << "========================================" << std::endl;

    return 0;
}
