#include "EasyEncryption.h"

std::string EasyEncryption::encrypt(const std::string &decryptedString, const std::string &key) {
    return Vigenere::encrypt(Base64::encode(decryptedString), key);
}

std::string EasyEncryption::decrypt(const std::string &encryptedString, const std::string &key) {
    return Base64::decode(Vigenere::decrypt(encryptedString, key));
}
