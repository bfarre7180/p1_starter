#include <iostream>
#include <string>
#include "hash.h"
#include <cmath>
#include <climits>

using namespace std;

int hash_function(string text) {
    // Implement your own hash function here
    int hash = 1;
    int multiplier = 3;

    for(char c: text) {
        hash = (hash * 31 * c) * multiplier;
        multiplier += c;
    }

    return (hash >= 0) ? hash: -1 * hash;
}