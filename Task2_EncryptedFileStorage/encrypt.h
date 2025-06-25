// encrypt.h
 
#ifndef ENCRYPT_H
#define ENCRYPT_H
 
#include <string>
 
std::string encrypt(const std::string& data, const std::string& key);
std::string decrypt(const std::string& data, const std::string& key);
 
#endif
