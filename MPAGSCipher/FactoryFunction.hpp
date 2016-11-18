#ifndef MPAGSCIPHER_FACTORYFUNCTION_HPP
#define MPAGSCIPHER_FACTORYFUNCTION_HPP

#include <string>
#include "Cipher.hpp"
#include "CipherType.hpp"
#include <memory>

std::unique_ptr<Cipher> cipherFactory(const CipherType type, const std::string& key);


#endif
