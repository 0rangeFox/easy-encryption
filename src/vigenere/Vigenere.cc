#include "Vigenere.h"

using namespace easy::encryption;

int Vigenere::index(char c) {
    for (int i = 0; i < VIGENERE_AVAILABLE_CHARS_SIZE; i++)
        if (VIGENERE_AVAILABLE_CHARS[i] == c)
            return i;
    return -1;
}

std::string Vigenere::extend_key(const std::string &string, const std::string &key) {
    unsigned long long int keyLen = key.size();
    std::string newKey(string.size(), 0x0);

    // Generating new key
    for (int i = 0, j = 0; i < newKey.size(); ++i, ++j)
        newKey[i] = key[j == keyLen ? j = 0 : j];

    return newKey;
}

std::string Vigenere::encrypt(const std::string &decryptedString, const std::string &key) {
    std::string newKey = extend_key(decryptedString, key);
    std::string encryptedString(decryptedString.size(), 0x0);

    // Encryption
    for (int i = 0; i < encryptedString.size(); ++i)
        encryptedString[i] = isalnum(decryptedString[i]) ? VIGENERE_AVAILABLE_CHARS[((index(decryptedString[i]) + index(newKey[i])) % VIGENERE_AVAILABLE_CHARS_SIZE)] : decryptedString[i];

    return encryptedString;
}

std::string Vigenere::decrypt(const std::string &encryptedString, const std::string &key) {
    std::string newKey = extend_key(encryptedString, key);
    std::string decryptedString(encryptedString.size(), 0x0);

    // Decryption
    for (int i = 0; i < decryptedString.size(); ++i)
        decryptedString[i] = index(encryptedString[i]) >= 0 ? VIGENERE_AVAILABLE_CHARS[(((index(encryptedString[i]) - index(newKey[i])) + VIGENERE_AVAILABLE_CHARS_SIZE) % VIGENERE_AVAILABLE_CHARS_SIZE)] : encryptedString[i];

    return decryptedString;
}
