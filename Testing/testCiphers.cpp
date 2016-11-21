//! Unit Tests for MPAGSCipher Cipher Class
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "CaesarCipher.hpp"
#include "PlayfairCipher.hpp"
#include "VigenereCipher.hpp"
#include "Cipher.hpp"
#include "CipherType.hpp"
#include "FactoryFunction.hpp"
#include <iostream>
#include <memory>
#include <vector>


TEST_CASE("Caesar, Playfair and Vigenere encryption and decryption tests"){
    
    // Declare strings for the keys
    std::string key1{"10"};
    std::string key2{"hello"};
    std::string key3{"key"};
    
    // Setup collection of Caesar, Playfair and Vigenere 
    std::vector<std::unique_ptr<Cipher>> testnumber;
    testnumber.push_back(cipherFactory(CipherType::Caesar, key1));
    testnumber.push_back(cipherFactory(CipherType::Playfair, key2));
    testnumber.push_back(cipherFactory(CipherType::Vigenere, key3));  
    
    // Strings to test with, i.e. encryption and decryption
    std::vector<std::string> encryption = {"HELLOWORLD", "THEDOGSATONTHEMATS", "HELLOWORLD"};
    std::vector<std::string> decryption = {"ROVVYGYBVN", "QOLCAFULYFTYELPLUT", "RIJVSUYVJN"};
    
    // Loop which checks whether encryption and decryption give the correct results
    for(size_t i{0}; i<testnumber.size(); i++){
        REQUIRE( testnumber[i]->applyCipher(encryption[i],CipherMode::Encrypt) == decryption[i]);
        REQUIRE( testnumber[i]->applyCipher(decryption[i],CipherMode::Decrypt) == encryption[i]);
}
}

