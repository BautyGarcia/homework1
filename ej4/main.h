#include <string>

using namespace std;

bool are_equal(string s1, string s2);
bool are_equal(char* s1, char* s2);

constexpr bool are_equal_compilation(const char* s1, const char* s2) {
    if (*s1 == '\0' && *s2 == '\0') return true;
    
    if (*s1 == '\0' || *s2 == '\0') return false;

    if (*s1 != *s2) return false;

    return are_equal_compilation(s1 + 1, s2 + 1);
}