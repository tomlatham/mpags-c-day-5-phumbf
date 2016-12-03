// Standard library includes
#include <string>
#include <algorithm>
#include <iostream>

// Out project headers
#include "Alphabet.hpp"
#include "VigenereCipher.hpp"

VigenereCipher::VigenereCipher(const std::string& key)
{
    //Set the given key
    setKey(key);
}


void VigenereCipher::setKey(const std::string& key )
{
    // Store the key
    key_ = key;
    
    // Make sure the key is uppercase
    std::transform( std::begin(key_), std::end(key_), std::begin(key_), ::toupper );
    
    // Remove non-alpha characters
    key_.erase( std::remove_if( std::begin(key_), std::end(key_), [](char c){ return !std::isalpha(c); } ),
		  std::end(key_) );
    
    // loop over the key
    for(const auto elem: key_){
	//Check that we don't repeat letters
	if(charlookup_.find(elem) != charlookup_.end())
	{
	    continue;
	}

	// Find the letter position in the alphabet
	size_t index = Alphabet::alphabet.find(elem);

	// Create a CaesarCipher using this position as a key
	CaesarCipher cipher {index};

	// Insert a std::pair of the letter and CaesarCipher into the lookup
	charlookup_.insert(std::make_pair(elem, cipher));

    }
}


std::string VigenereCipher::applyCipher(const std::string& inputText, const CipherMode cipherMode) const
{
    // Create output string
    std::string outputText{""};
    
    const int n = inputText.length(); 
    // For each letter in input
    for(int i = 0; i< n; i++){
        
        // Find the corresponding letter in the key
        // repeating/truncating as required
        char keyLetter { key_[i % key_.length()] };
        
        // Find the Caesar cipher from the lookup
        auto iter = charlookup_.find( keyLetter );
        auto& cip = (*iter).second;
        
        // Caesar Cipher (De)Encryption
        const std::string let{inputText[i]};
        
        // Add to the output text
        outputText += cip.applyCipher( let, cipherMode );
        
    }
    
    return outputText;
}
