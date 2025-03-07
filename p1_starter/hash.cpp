#include <iostream>
#include <string>
#include "hash.h"
#include <cmath>

using namespace std;

int hash_function(string text) {
    // Implement your own hash function here
    int hash{};
    double intermediate{};
    for(char c: text) {
        intermediate += pow(31,(double)c) % INT_MAX;
        hash += intermediate;
    }

    return hash;
}