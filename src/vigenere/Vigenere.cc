#include "Vigenere.h"

using namespace easy::encryption::vigenere;

int Vigenere::index(char c) {
    for (int i = 0; i < AVAILABLE_CHARS_SIZE; i++)
        if (AVAILABLE_CHARS[i] == c)
            return i;
    return -1;
}

std::string Vigenere::extend_key(const std::string &string, const std::string &key) {
    int i, j, stringLen = string.size(), keyLen = key.size();
    std::string newKey(stringLen, 'x');

    // Generating new key
    for (i = 0, j = 0; i < stringLen; ++i, ++j) {
        if (j == keyLen) j = 0;
        newKey[i] = key[j];
    }

    newKey[i] = '\0';

    return newKey;
}

std::string Vigenere::encrypt(const std::string &decryptedString, const std::string &key) {
    int i, decryptedStringLen = decryptedString.size();
    std::string encryptedString(decryptedStringLen, 'x');
    std::string newKey = extend_key(decryptedString, key);

    // Encryption
    for (i = 0; i < decryptedStringLen; ++i)
        encryptedString[i] = isalnum(decryptedString[i]) or decryptedString[i] == ' ' ? AVAILABLE_CHARS[((index(decryptedString[i]) + index(newKey[i])) % AVAILABLE_CHARS_SIZE)] : decryptedString[i];
    encryptedString[i] = '\0';

    return encryptedString;
}

std::string Vigenere::decrypt(const std::string &encryptedString, const std::string &key) {
    int i, encryptedStringLen = encryptedString.size();
    std::string decryptedString(encryptedStringLen, 'x');
    std::string newKey = extend_key(encryptedString, key);

    // Decryption
    for (i = 0; i < encryptedStringLen; ++i)
        decryptedString[i] = isalnum(encryptedString[i]) or encryptedString[i] == ' ' ? AVAILABLE_CHARS[(((index(encryptedString[i]) - index(newKey[i])) + AVAILABLE_CHARS_SIZE) % AVAILABLE_CHARS_SIZE)] : encryptedString[i];
    decryptedString[i] = '\0';

    return decryptedString;
}
