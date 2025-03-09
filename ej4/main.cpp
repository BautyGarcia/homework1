#include <iostream>
#include "main.h"
#include <chrono>

using namespace std;

int main() {
    string s1 = "Hola soy pepe, me gustan los perros y las golosinas. Nose que mas texto poner ayuda.";
    string s2 = "Hola soy pepe, me gustan los perros y las golosinas. Nose que mas texto poner ayuda.";

    char* c1 = new char[s1.length()];
    char* c2 = new char[s2.length()];

    for (int i = 0; i < s1.length(); i++) {
        c1[i] = s1[i];
        c2[i] = s2[i];
    }

    auto start = chrono::high_resolution_clock::now();
    cout << are_equal(c1, c2) << endl;
    auto end = chrono::high_resolution_clock::now();
    cout << "(Char*) Time taken: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " nanoseconds" << endl;

    auto start2 = chrono::high_resolution_clock::now();
    cout << are_equal(s1, s2) << endl;
    auto end2 = chrono::high_resolution_clock::now();
    cout << "(String) Time taken: " << chrono::duration_cast<chrono::nanoseconds>(end2 - start2).count() << " nanoseconds" << endl;


    // Tiempo de compilacion (C)

    constexpr const char* compile_s1 = "Hola soy pepe, me gustan los perros y las golosinas. Nose que mas texto poner ayuda.";
    constexpr const char* compile_s2 = "Hola soy pepe, me gustan los perros y las golosinas. Nose que mas texto poner ayuda.";
    
    auto start3 = chrono::high_resolution_clock::now();
    constexpr bool result = are_equal_compilation(compile_s1, compile_s2);
    cout << result << endl;
    auto end3 = chrono::high_resolution_clock::now();
    cout << "(Compile-time) Time taken: " << chrono::duration_cast<chrono::nanoseconds>(end3 - start3).count() << " nanoseconds" << endl;

    return 0;
}

bool are_equal(string s1, string s2) {
    if (s1.length() != s2.length()) return false;

    if (s1.empty() && s2.empty()) return true;

    if (s1[0] == s2[0]) return are_equal(s1.substr(1), s2.substr(1));

    return false;
}

bool are_equal(char* s1, char* s2) {
    if (strlen(s1) != strlen(s2)) return false;

    if (strlen(s1) == 0 && strlen(s2) == 0) return true;

    if (s1[0] == s2[0]) return are_equal(s1 + 1, s2 + 1);

    return false;
}