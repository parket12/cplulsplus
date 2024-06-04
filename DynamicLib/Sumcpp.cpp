#include "Header.h"
#include <unordered_set>
extern "C" __declspec(dllexport) bool FindBukv(const char* input, const char* characters)
{
    std::unordered_set<char> inputSet(input, input + strlen(input));

    for (size_t i = 0; i < strlen(characters); i++) {
        if (inputSet.find(characters[i]) == inputSet.end()) {
            return false; 
        }
    }

    return true; 
}