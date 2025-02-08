#pragma once
#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string data;     // word
    string meaning;  // Meaning of word
    Node* child[26]; // 26 Character so 26 child
    bool flag;       // as word indicator
    Node();          // construtor
};

class Tree
{
    Node* root;

public:
    Tree();
    Node* getroot();                           // it return the root
    bool insertWord(string word, string mean); // insert data to tree
    bool checkChild(Node* root);                // Return true or false to tell that the Node is extra or not
    bool present(string word);                 // check this wor is present in tree or not
    void getSuggestion(Node* root, string word, string sugesstion[], string meaningArr[], int& count, bool& flag);
    void storeData(Node* root, bool flag);                           // insert data into Dictionary file
    void loadData();                                                   // load data from Dictionary file
    string removeSpaces(const string& input);                          // just remove spaces of given word
    bool addWord(string word, string mean);                            // add new word and meaning in tree and file
    bool deleteWord(string word, int mood);                            // delete word and meaning from tree and file
    bool updateWord(string word, string new_word, string new_meaning); // Update word and meaning from tree and file
};