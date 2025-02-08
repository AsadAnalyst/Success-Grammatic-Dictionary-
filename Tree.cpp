#include "Tree.h"
#include <windows.h>
#include <conio.h>
#include <fstream>
using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
Node::Node()
{
    data = "";
    meaning = "";
    flag = false;
    for (int i = 0; i < 26; i++)
    {
        child[i] = nullptr;
    }
}

Tree::Tree()
{
    root = new Node;
}

Node* Tree::getroot() // just return the root
{
    return root;
}

bool Tree::insertWord(string word, string mean) // insert data into the tri tree
{
    Node* temp = root;                      // make a temp for root
    bool already_exist = true;              // for repeated word that should not be insert in the tree
    for (int i = 0; i < word.length(); i++) //  run when length of word is done
    {
        char ch = word[i];                 // take ith char
        if (temp->child[ch - 'a'] == NULL) // if this position is null
        {
            temp->child[ch - 'a'] = new Node;              // then make a  new node on this poition
            temp->child[ch - 'a']->data = temp->data + ch; // and insert data on that poition
            already_exist = false;                         // it means this is not already_exist in tree
        }
        temp = temp->child[ch - 'a']; // now triverse the tree
    }
    if (temp) // if temp is not null
    {
        if (already_exist && temp->flag) // if already_exist and temp both are true then
        {
            // cout << "This word Already Exist " << endl;
            return false; // it means This word Already Exist
        }
        temp->flag = true;    // else this is a new word in the tree also in Distionary
        temp->meaning = mean; // and this is a meaning of that word
    }
    else
    {
        cout << "your pointing on nullptr" << endl; // it means your temp is point on null
    }
    return true; // it means your word is inserted in tree successfully
}

// it check child exist or not
bool Tree::checkChild(Node* root)
{
    for (int i = 0; i < 26; i++)
    {
        if (root->child[i] != NULL)
        {
            return false;
        }
    }
    return true;
}

bool Tree::present(string word) // check this word is present in our tree or not
{
    for (int i = 0; i < word.length(); i++) // run when length of word is done
    {
        if (word[i] < 'a' || word[i] > 'z') // if word[i] is out of alphabate
        {
            return false; // it means this not alphabate
        }
    }

    if (root == NULL) // if root is null
    {
        return false; // also return flase
    }
    Node* temp = root;                      // window = temp
    for (int i = 0; i < word.length(); i++) // run when length of word is done
    {
        if (temp->child[word[i] - 'a'] == NULL) // if word[i] = 'a' it means (a - a) = '0' index
        {
            return false;
        }
        temp = temp->child[word[i] - 'a']; // if word[i] = 'b' it means (b - a) = '1' index
    }
    return true; // finally it means this is present word
}

void Tree::storeData(Node* root, bool flag = true) // write back data in Dictionary
{
    if (root == NULL) // when root is null
    {
        return;
    }

    string output;
    output += root->data; // make a word recursivly when root->flag == true
    if (root->flag)
    {
        if (!flag)
        {
            ofstream out;
            out.open("Dictionary.txt", ios::app); // open the Dictionary file for write the data
            if (out.is_open())
            {
                out << endl << output << "|" << root->meaning << "|"; // write
                out.close();
            }
            else
            {
                cout << " \n\n\n\t\tFile Not Found\n\n";
            }
                                             // close file
        }
        flag = false;
        output = "";
    }
    for (int i = 0; i < 26; i++) // call 26 time because total maximum alphabate is 26
    {
        storeData(root->child[i], flag);
    }
}

void Tree::getSuggestion(Node* temp, string word, string suggestion[], string meaningArr[], int& count, bool& f)
{
    // if temp(root) no child exist && also  word(flag) indicate false || 10 suggestion(counter) completed
    // then stop (return)
    if ((checkChild(temp) && !temp->flag) || count == 10)
    {
        return;
    }
    if (f) // we triverse your entered word only ones
    {
        for (int i = 0; i < word.length(); i++)
        {
            temp = temp->child[word[i] - 'a'];
        }
        f = false;
    }
    if (temp != NULL) // to avoid to get access to nullptr(error)
    {
        if (temp->flag) // word(flag) true  means word exist
        {
            suggestion[count] = temp->data;    // store word
            meaningArr[count] = temp->meaning; // store meaning
            count++;
        }
        for (int i = 0; i < 26; i++) // check all array
        {
            if (temp->child[i] != NULL) // call if child not null
            {
                //   Recursive call  function
                getSuggestion(temp->child[i], word, suggestion, meaningArr, count, f);
            }
        }
    }
    return; // other base case (root == nullptr)
}

void Tree::loadData() // load data from file
{
    string word;
    string mean;
    ifstream in;
    in.open("Dictionary.txt");
    if (in.is_open())
    {
        while (!in.eof())
        {
            getline(in, word, '|'); // Read a line until '|' is come
            word = removeSpaces(word); // just remove the space from word

            getline(in, mean, '|');    // Read a line until '|' is come
            mean = removeSpaces(mean); // just remove the space from word

            insertWord(word, mean); // call for insert data into the tree
            word = "";
            mean = "";
        }
        in.close();
    }
    else
    {
        cout << " \n\n\t\t\t File Not Found\n";
    }
   
}

string Tree::removeSpaces(const string& input)
{
    string result = "";
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (!isspace(input[i])) // check its space or not
        {
            result += input[i]; // if space is not
        }
    }
    return result;
}

bool Tree::addWord(string word, string mean) // all new word and meaning in the tree and file
{
    if (insertWord(word, mean)) // insert new word in tree
    {
        ofstream out;
        out.open("Dictionary.txt", ios::app);
        if (out.is_open())
        {
            out << endl << word << "|" << mean << "|"; // insert new word in file
            out.close();
            return true;
        }
        else
        {
            cout << "\n\n\n\t\t File Not Found\n\n";
        }   
    }
    return false;
}

bool Tree::deleteWord(string word, int mood)
{
    system("cls");                          // clear the screen
    Node* temp = root;                      // make a temp for root
    bool already_exist = true;              // for repeated word that should not be insert in the tree
    for (int i = 0; i < word.length(); i++) //  run when length of word is done
    {
        char ch = word[i];                 // take ith char
        if (temp->child[ch - 'a'] == NULL) // if this position is null
        {
            temp->child[ch - 'a'] = new Node;              // then make a  new node on this poition
            temp->child[ch - 'a']->data = temp->data + ch; // and insert data on that poition
            already_exist = false;                         // it means this is not already_exist in tree
        }
        temp = temp->child[ch - 'a']; // now triverse the tree
    }
    if (already_exist && temp->flag && mood == 1) // if already_exist and temp both are true and (1 means delete orignally )
    {
        bool reget = true;
        char choice;
        PlaySound(TEXT("wantDelete.wav"), NULL, SND_ASYNC); // play Music
        do                                                  // for take choice y or N only
        {
            cout << " \n\n\n\n\n\t\t\t\t\tDo You Want to delete The Word : \n\t\t\t\t\tEnter Y.(yes) , N.(No) : ";
            char ch = _getch();
            if (ch == 'y' || ch == 'Y' || ch == 'n' || ch == 'N')
            {
                choice = ch;
                reget = false;
            }
            system("cls"); // clear the screen
        } while (reget);
        PlaySound(TEXT("BackgroundMusic.wav"), NULL, SND_ASYNC); // play Music

        if (choice == 'y' || choice == 'Y')
        {
            temp->flag = false; // first we false the flag from tree of word
            temp->meaning = "";
            ofstream out;
            out.open("Dictionary.txt"); // open file and remove all data from file
            if (out.is_open())
            {
                out.close();
            }
            else
            {
                cout << " \n\n\n\t\tFile Not Found\n\n";
                return false;
            }
            
            PlaySound(TEXT("updating.wav"), NULL, SND_ASYNC); // play Music
            cout << "\n\nDictoinary File Is Updating Please Wait For A Moment.......";
            Sleep(3000);
            PlaySound(TEXT("BackgroundMusic.wav"), NULL, SND_ASYNC); // play Music
            storeData(root);                                       // now updated insert data into file it take your some time because data is more
            return true;
        }
        return false;
    }
    if (already_exist && temp->flag && mood == 2) // (mood 2 means delete for update)
    {
        temp->flag = false;
        temp->meaning = "";
        return true;
    }
    else if (!already_exist)
    {
        SetConsoleTextAttribute(hConsole, 11);
        cout << " \n\n\n\t\t\tWord Not Found...!";
        SetConsoleTextAttribute(hConsole, 12);
        cout << " \n\n\n\t\t\tEnter BACKSPACE For Back...!";
        SetConsoleTextAttribute(hConsole, 15);
    }
    return false;
}

bool Tree::updateWord(string word, string new_word, string new_meaning)
{
    if (deleteWord(word, 2)) // delete old word (mood 2 means delete for update)
    {
        insertWord(new_word, new_meaning); // insert new wor and meaning in the tree
        ofstream out;
        out.open("Dictionary.txt");                       // open file and remove all data from file
        if (out.is_open())
        {
            PlaySound(TEXT("updating.wav"), NULL, SND_ASYNC); // play Music
            cout << "\n\nDictoinary File Is Updating Please Wait For A Moment.......";
            Sleep(3000);
            PlaySound(TEXT("BackgroundMusic.wav"), NULL, SND_ASYNC); // play Music
            storeData(root);                                       // now updated insert data into file it take your 
            //some time because data is more
            out.close();
            return true;
        }
        else
        {
            cout << "\n\n\n\t\tFile Not Find\n\n";
        }      
    }
    return false;
}