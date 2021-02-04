# Cybersecurity: RSA cryptographic algorithm

This program consists of the RSA public-key cryptographic algorithm. There are two `.cpp` files, `main.cpp` and `keyGeneration.cpp`. The `keyGeneration.cpp` file generates a pair of private and a pair of public keys. It consists of functions that check whether a number is a prime number, a GCD finder, an extended Euclidean algorithm to find multiplicative inverses of numbers, a private key generator and a public key generator.

The `main.cpp` file contains functions to encrypt/decrypt texts. The user is prompted to enter a text file they would like to encrypt/decrypt. The program then opens that file then pushes the characters into a vector data structure. Then it iterates through the vector and encrypts/decrypts each character and writes that to another file. A function to calculate modular is included in this program to make it easier to deal with very large numbers. 

## Running the program

This program can be compiled and executed on a devise that is equipped with a C++ compiler.  

For example, if an individual gets access to the g++ compiler, they can type `g++ -o executable main.cpp` to compile and create an executable named *executable*, then run the program by typing `./executable` on the command line. 

