#pragma once

#include <string>
#include <vector>
#include "../EasyEncryptionConsts.h"

namespace easy {
    namespace encryption {

        class Base64 {
        public:
            static std::string encode(const std::string& data);
            static std::string decode(const std::string& data);
            static std::string encodeFromFile(const std::string& inFileName);
            static void decodeToFile(const std::string& outFileName, const std::string& encodedString);
        private:
            static int index(char c);
        };

    }
}
