#pragma once

#include "../EasyEncryptionConsts.h"

namespace easy {
    namespace encryption {
        namespace base64 {
            class Base64 {
            public:
                static std::string encode(const std::string &in);
                static std::string decode(const std::string &in);
            };
        }
    }
}
