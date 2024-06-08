#include <fstream>
#include "Base64.h"

using namespace easy::encryption;

int Base64::index(char c) {
    for (int i = 0; i < BASE64_AVAILABLE_CHARS_SIZE; ++i)
        if (BASE64_AVAILABLE_CHARS[i] == c)
            return i;
    return -1;
}

std::string Base64::encode(const std::string &data) {
    unsigned long long int inStringLen = data.size();
    int valA = 0, valB = -6;
    std::string out;

    for (int i = 0; i < inStringLen; i++) {
        valA = (valA << 8) + data[i];
        valB += 8;

        while (valB >= 0) {
            out.push_back(BASE64_AVAILABLE_CHARS[(valA >> valB) & 0x3F]);
            valB -= 6;
        }
    }

    if (valB > -6)
        out.push_back(BASE64_AVAILABLE_CHARS[((valA << 8) >> (valB + 8)) & 0x3F]);

    while (out.size() % 4)
        out.push_back(0x3D);

    return out;
}

std::string Base64::decode(const std::string &data) {
    unsigned long long int inStringLen = data.size();
    std::string out;

    int valA = 0, valB = -8;
    for (int i = 0; i < inStringLen; i++) {
        int charIndex = index(data[i]);
        if (charIndex < 0) break;

        valA = (valA << 6) + charIndex;
        valB += 6;

        if (valB >= 0) {
            out.push_back(char((valA >> valB) & 0xFF));
            valB -= 8;
        }
    }

    return out;
}

std::string Base64::encodeFromFile(const std::string &inFileName) {
    std::ifstream in;
    in.open(inFileName.c_str(), std::ios::binary);

    if (!in.good())
        throw std::invalid_argument(std::string("can't open file ") + inFileName);

    std::string encodedBytes;
    while (in.good())
        encodedBytes.push_back((char) in.get());

    encodedBytes.pop_back();
    in.close();

    return Base64::encode(encodedBytes);
}

void Base64::decodeToFile(const std::string &outFileName, const std::string &encodedString) {
    std::ofstream out;
    out.open(outFileName.c_str(), std::ios::binary);

    if (!out.good())
        throw std::invalid_argument(std::string("can't open file ") + outFileName);

    std::string decodedString = Base64::decode(encodedString);
    for (unsigned int i = 0; i < decodedString.size(); ++i)
        out.put(decodedString[i]);

    out.close();
}
