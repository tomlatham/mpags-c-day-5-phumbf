//! Unit Tests for MPAGSCipher Cipher Class
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "CaesarCipher.hpp"
#include "PlayfairCipher.hpp"
#include "VigenereCipher.hpp"
#include "Cipher.hpp"


bool testCipher( const Cipher& cipher, const CipherMode mode, const std::string& inputText, const std::string& outputText)
{
 return cipher.applyCipher(inputText, mode) == outputText;
}

TEST_CASE("VigenereCipher encryption", "[vigenere]") {
  VigenereCipher vc{"key"};
  REQUIRE( testCipher(vc, CipherMode::Encrypt, "HELLOWORLD", "RIJVSUYVJN" ));
}

TEST_CASE("VigenereCipher decryption", "[vigenere]") {
  VigenereCipher vc{"key"};
  REQUIRE( testCipher(vc, CipherMode::Decrypt,"RIJVSUYVJN", "HELLOWORLD" ));
}

TEST_CASE("Caesar Cipher encryption", "[caesar]") {
  CaesarCipher cc{10};
  REQUIRE( testCipher(cc, CipherMode::Encrypt, "HELLOWORLD", "ROVVYGYBVN"));
}
  
TEST_CASE("Caesar Cipher decryption", "[caesar]") {
  CaesarCipher cc{10};
  REQUIRE( testCipher(cc, CipherMode::Decrypt,"ROVVYGYBVN" ,"HELLOWORLD" ));
}
  
TEST_CASE("Playfair Cipher encryption", "[playfair]") {
  PlayfairCipher pc{"hello"};
  REQUIRE( testCipher(pc, CipherMode::Encrypt, "BOBISSOMESORTOFJUNIORCOMPLEXXENOPHONEONEZEROTHING", "FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA"));
}
  
TEST_CASE("Playfair Cipher decryption", "[playfair]") {
  PlayfairCipher pc{"hello"};
  REQUIRE( testCipher(pc, CipherMode::Decrypt, "FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA", "BOBISXSOMESORTOFIUNIORCOMPLEXQXENOPHONEONEZEROTHINGZ"));
}  
