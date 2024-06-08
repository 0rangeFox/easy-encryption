#include <iostream>
#include <sstream>

#include "../src/EasyEncryption.h"

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cout << "Usage: ./a.out message key (0:encrypt|1:decrypt)" << std::endl
                  << "./a.out \"Hello world\" MYPRIVATEKEY 0" << std::endl
                  << "./a.out ttz9JqxZHBClNtu= MYPRIVATEKEY 1" << std::endl;

        return -1;
    }

    std::string msg = argv[1];
    std::string key = argv[2];
    int encrypt_flag = 0;

    std::stringstream(argv[3]) >> encrypt_flag;

    if (!encrypt_flag)
        std::cout << EasyEncryption::encrypt(msg, key) << std::endl;
    else
        std::cout << EasyEncryption::decrypt(msg, key) << std::endl;

    return 0;
}
