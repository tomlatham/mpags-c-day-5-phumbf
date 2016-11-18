//! Unit Tests for MPAGSCipher VigenereCipher Class
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "VigenereCipher.hpp"

TEST_CASE("VigenereCipher encryption", "[vigenere]") {
  VigenereCipher vc{"key"};
  REQUIRE( vc.applyCipher("HELLOWORLD", CipherMode::Encrypt) == "RIJVSUYVJN");
}

TEST_CASE("VigenereCipher decryption", "[vigenere]") {
  VigenereCipher vc{"key"};
  REQUIRE( vc.applyCipher("RIJVSUYVJN", CipherMode::Decrypt) == "HELLOWORLD");
}
