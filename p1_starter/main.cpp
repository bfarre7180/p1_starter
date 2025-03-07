/*
CSE 310 Hash Function DIY Contest
Instructor: Yiran "Lawrence" Luo
Your name(s): Brandon Farrell
Your team alias: N/A
*/

#include <iostream>
#include <iomanip>
#include <string>
#include "hash.h"
#include <cmath>
using namespace std;


struct Node {
    string key;
    Node* next = nullptr;

    Node(string key) {
        this->key = key;
        this->next = nullptr;
    }
    Node(string newKey, Node* newNext) {
        key = newKey;
        next = newNext;
    }
};

struct List {
    Node* head = nullptr;
    int length = 0;

    void add(string key) {
        length++;
        if(head == nullptr) {
            head = new Node(key);
            return;
        }
        struct Node* temp = head;
        while(temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = new Node(key);
    }

    void toString() {
        Node* temp = head;
        while(temp != nullptr) {
            cout << temp->key << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

void computeSTDev(double mean, List hashtable[], int n, int k);

int main() {

    int k = 0;
    int n = 0;
    string texts[500];

    // WARNING: Start of the tokenizer that loads the input from std::cin, DO NOT change this part!
    cin >> k;
    string line;
    getline(cin, line);

    while (getline(cin, line)) {
        texts[n] = line;
        n++;
    }
    // WARNING: End of the tokenizer, DO NOT change this part!

    // By this point, k is the # of slots, and n is the # of tokens to fit in
    // texts[] stores the input sequence of tokens/keys to be inserted into your hash table

    // The template is able to be compiled by running 
    //   make
    //   ./encoder < inputs/sample_input.txt
    // which puts out the placeholders only.

    // Your time to shine starts now

    List* hashtable = new List[k];

    for(int i = 0; i < n; i++) {
        hashtable[hash_function(texts[i]) % k].add(texts[i]);
    }
    

    cout << "==== Printing the contents of the first 5 slots ====" << endl;

    for(int i = 0; i < 5; i++) {
        cout << "Slot " << i << ": ";
        hashtable[i].toString();
    }

    cout << "==== Printing the slot lengths ====" << endl;
    double mean = 0;
    for(int i = 0; i < k; i++) {
        int len = hashtable[i].length;
        mean += len;
        cout << "Slot " << i << ": " << len << endl;
    }

    mean /= n;

    cout << "==== Printing the standard deviation =====" << endl;

    computeSTDev(mean,hashtable,n,k);

    delete[] hashtable;
    return 0;
}

void computeSTDev(double mean, List hashtable[], int n, int k) {
    if(n <= 0){
        return;
    }
    double ans = 0;
    for(int i = 0; i < k; i++) {
        ans += ((double)hashtable[i].length - mean) * ((double) hashtable[i].length - mean);
    }
    ans = ans / (double)n;
    ans = sqrt(ans);
    cout << fixed << setprecision(5) << ans << endl;
}