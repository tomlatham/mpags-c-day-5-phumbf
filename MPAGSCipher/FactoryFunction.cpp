
#include "FactoryFunction.hpp"
#include "CaesarCipher.hpp"
#include "PlayfairCipher.hpp"
#include "VigenereCipher.hpp"
#include <iostream>


std::unique_ptr<Cipher> cipherFactory(const CipherType type, const std::string& key) 

{
    switch(type){
    
        case CipherType::Caesar : 
            if ( ! key.empty() ) {
                for ( const auto& elem : key ) {
                    if ( ! std::isdigit(elem) ) {
                        
                        std::cerr << "[error] cipher key must be an unsigned long integer for Caesar cipher,\n"
                        << "the supplied key (" << key << ") could not be successfully converted" << std::endl;
                        
                        return std::unique_ptr<Cipher>();
                    }
                }
                size_t caesarkey = std::stoul(key);
                return std::make_unique<CaesarCipher>(caesarkey);
                
            }
	
	      else{
               return std::unique_ptr<Cipher>();

          }
            
        case CipherType::Playfair :
            return std::make_unique<PlayfairCipher>(key);
            
        case CipherType::Vigenere :
            return std::make_unique<VigenereCipher>(key);
            
        
    }
    
    return std::unique_ptr<Cipher>();

}
