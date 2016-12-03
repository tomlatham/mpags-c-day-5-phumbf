
// Standard Library includes
#include <iostream>
#include <memory>
#include <string>

// Our project headers
#include "FactoryFunction.hpp"
#include "CaesarCipher.hpp"
#include "PlayfairCipher.hpp"
#include "VigenereCipher.hpp"


std::unique_ptr<Cipher> cipherFactory(const CipherType type, const std::string& key) 
{
    switch(type){
    
        case CipherType::Caesar : 
	    {
		// We have the key as a string, but the Caesar cipher needs an unsigned long, so we first need to convert it
		// We default to having a key of 0, i.e. no encryption, if no key was provided on the command line
		size_t caesarkey {0};
		if ( ! key.empty() ) {
		    // Before doing the conversion we should check that the string contains a valid positive integer.
		    // Here we do that by looping through each character and checking that it is a digit.
		    for ( const auto& elem : key ) {
			if ( ! std::isdigit(elem) ) {
			    std::cerr << "[error] cipher key must be an unsigned long integer for Caesar cipher,\n"
				<< "the supplied key (" << key << ") could not be successfully converted" << std::endl;
			    return std::unique_ptr<Cipher>();
			}
		    }
		    caesarkey = std::stoul(key);
		}
		return std::make_unique<CaesarCipher>(caesarkey);
	    }
            
        case CipherType::Playfair :
            return std::make_unique<PlayfairCipher>(key);
            
        case CipherType::Vigenere :
            return std::make_unique<VigenereCipher>(key);
            
        
    }
    
    return std::unique_ptr<Cipher>();

}
