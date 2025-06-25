#include <iostream>
#include <fstream>
#include <filesystem>
#include "encrypt.h"
 
namespace fs = std::filesystem;
 
int main() {
    std::string mode;
    std::cout << "Enter mode (store/retrieve): ";
    std::cin >> mode;
 
    std::string country, state, district, description, path, filename = "info.dat";
    std::string key = "mysecret"; // Your encryption key
 
    if (mode == "store") {
        std::cout << "Enter Country: ";
        std::cin >> country;
        std::cout << "Enter State: ";
        std::cin >> state;
        std::cout << "Enter District: ";
        std::cin >> district;
        std::cin.ignore();
        std::cout << "Enter Description: ";
        std::getline(std::cin, description);
 
        path = "./data/" + country + "/" + state + "/" + district;
        fs::create_directories(path);
 
        std::string content = "Country: " + country + "\nState: " + state + "\nDistrict: " + district + "\nDescription: " + description;
        std::string encrypted = encrypt(content, key);
 
        std::ofstream out(path + "/" + filename, std::ios::binary);
        out << encrypted;
        out.close();
        std::cout << "Data saved and encrypted.\n";
 
    } else if (mode == "retrieve") {
        std::cout << "Enter Country: ";
        std::cin >> country;
        std::cout << "Enter State: ";
        std::cin >> state;
        std::cout << "Enter District: ";
        std::cin >> district;
 
        path = "./data/" + country + "/" + state + "/" + district + "/" + filename;
 
        std::ifstream in(path, std::ios::binary);
        if (!in) {
            std::cerr << "File not found.\n";
            return 1;
        }
 
        std::string encrypted((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
        in.close();
 
        std::string decrypted = decrypt(encrypted, key);
        std::cout << "\nDecrypted Content:\n" << decrypted << "\n";
    }
 
    return 0;
}
 