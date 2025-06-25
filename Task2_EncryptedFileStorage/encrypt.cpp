// encrypt.cpp
 
#include "encrypt.h"
 
std::string encrypt(const std::string& data, const std::string& key) {
    std::string result = data;
    for (size_t i = 0; i < data.size(); ++i) {
        result[i] ^= key[i % key.size()];
    }
    return result;
}
 
std::string decrypt(const std::string& data, const std::string& key) {
    // XOR decryption is the same as encryption
    return encrypt(data, key);
}