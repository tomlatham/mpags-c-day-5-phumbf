#ifndef MPAGSCIPHER_CIPHER_HPP
#define MPAGSCIPHER_CIPHER_HPP

/**
 * \file Cipher.hpp
 * \brief Contains the declaration of the Cipher class
 */

/**
 * \class Cipher
 * \brief The base class
 */


class Cipher{
    
public:
    
    Cipher() = default; 
    Cipher(const Cipher& rhs) = default; ///< Copy constructor
    Cipher(Cipher&& rhs) = default; ///< Move constructor
    Cipher& operator=(const Cipher& rhs) = default; ///< Copy assignment operator
    Cipher& operator=(Cipher&& rhs) = default; ///< Move assignment operator
    virtual ~Cipher() = default; ///< Destructor



virtual std::string applyCipher(const std::string& input, const CipherMode mode) const = 0;


};







#endif
