#include <iostream>
#include "Tree.h"
#include <windows.h>
#include <fstream>
#include <sstream>
#include <cctype>
#include <iomanip>
using namespace std;

void searchMenu();
int selectSuggestion(int count);                // select suggestion limit is count == 10
void printSuggestions(string arr[], int count); // just display given suggestion array
void move_cursor_to_xy(int x, int y);           // for move curser when dispkly suggestion is display
void printDictionaryLogo(const string& text, int color);
void mainManu();
bool hasOnlyLowerCase(const string& str);      // check alphabate

int main()
{
    PlaySound(TEXT("wlcome.wav"), NULL, SND_ASYNC); // play Music with welcome
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    bool flag = true;
    ofstream out;
    ifstream in;
    string typed_word = "", suggest_word = "";
    Tree tree;
    string suggestion[10];
    string meaningArr[10];
    int suggestion_size = 0;
    string choice = "\0";
    string line[8] = {
        "\t\t\t\tDDDDDD      II    CCCCCCCC    TTTTTTTTTTTTT   II      OOOOO        NN         NN     AAAAAA     RRRRRRR      YY         YY",
        "\t\t\t\tDD    DD    II    CC                TT        II    OO     OO      NN NN      NN    AA    AA    RR    RR      YY       YY",
        "\t\t\t\tDD    DD    II    CC                TT        II    OO     OO      NN  NN     NN    AA    AA    RR    RR       YY     YY",
        "\t\t\t\tDD    DD    II    CC                TT        II    OO     OO      NN   NN    NN    AA    AA    RR    RR        YY   YY",
        "\t\t\t\tDD    DD    II    CC                TT        II    OO     OO      NN    NN   NN    AAAAAAAA    RRRRRRRR         YYYY",
        "\t\t\t\tDD    DD    II    CC                TT        II    OO     OO      NN     NN  NN    AA    AA    RR RR             YY",
        "\t\t\t\tDD    DD    II    CC                TT        II    OO     OO      NN      NN NN    AA    AA    RR   RR          YY",
        "\t\t\t\tDDDDDD      II    CCCCCCCC          TT        II      OOOOO        NN         NN    AA    AA    RR    RR       YY" };
    cout << "\n\n\n";
    for (int i = 0; i < 8; i++)
    {
        printDictionaryLogo(line[i], i + 1);
        Sleep(1000);
    }
    cout << "\n\n\n\n\t\t\t\t\t\t";
    SetConsoleTextAttribute(hConsole, 11);
    cout << "Dictoinary File Is Loading Plz Wait For A Moment.......";
    tree.loadData();
start:
    typed_word = "";
    system("cls");
    mainManu();
    cin >> choice;
    SetConsoleTextAttribute(hConsole, 15);
    if (choice == "1")
    {
        SetConsoleTextAttribute(hConsole, 11);
        cout << "Dictoinary File Is Loading Plz Wait For A Moment.......";
        tree.loadData();
        system("cls");
        goto start;
    }
    else if (choice == "2")
    {
        system("cls");
        SetConsoleTextAttribute(hConsole, 10);
        string word, mean;
  
start1: 
        cin.ignore();
        cout << "\n\n\n\n\t\t\t\t\t Enter Your Word : ";
        cin >> word;
start2:
        cin.ignore();
        cout << "\t\t\t\t\t Enter Meaning oF " << word << " : ";
        cin >> mean;
        if (!hasOnlyLowerCase(word))
        {
            system("cls");
            goto start1;
            
        }
        if (!hasOnlyLowerCase(mean))
        {
            system("cls");
            goto start2;
            
        }     
        if (tree.addWord(word, mean))
        {
            cout << "\n\n\t\t\t\t\t Word Inserted Successfully...!\n";
            Sleep(2000);
            system("cls");
        }
        else
        {
            cout << " \n\n\n\t\t This Word is Already Exist\n";
            Sleep(2000);
            system("cls");
        }
        SetConsoleTextAttribute(hConsole, 15);
        goto start;
    }
    else if (choice == "3")
    {
        system("cls"); // clear the screen
        searchMenu();
        while (true)  // infinite loop
        {
            if (GetAsyncKeyState(0x41)) // ascci : 0x41 == a
            {
                typed_word = typed_word + 'a';
                cout << "a";
                while (GetAsyncKeyState(0x41))
                {
                } // wait until a is released
            }
            if (GetAsyncKeyState(0x42))
            {
                typed_word = typed_word + 'b';
                cout << "b";
                while (GetAsyncKeyState(0x42))
                {
                }
            }
            if (GetAsyncKeyState(0x43))
            {
                typed_word = typed_word + 'c';
                cout << "c";
                while (GetAsyncKeyState(0x43))
                {
                }
            }
            if (GetAsyncKeyState(0x44))
            {
                typed_word = typed_word + 'd';
                cout << "d";
                while (GetAsyncKeyState(0x44))
                {
                }
            }
            if (GetAsyncKeyState(0x45))
            {
                typed_word = typed_word + 'e';
                cout << "e";
                while (GetAsyncKeyState(0x45))
                {
                }
            }
            if (GetAsyncKeyState(0x46))
            {
                typed_word = typed_word + 'f';
                cout << "f";
                while (GetAsyncKeyState(0x46))
                {
                }
            }
            if (GetAsyncKeyState(0x47))
            {
                typed_word = typed_word + 'g';
                cout << "g";
                while (GetAsyncKeyState(0x47))
                {
                }
            }
            if (GetAsyncKeyState(0x48))
            {
                typed_word = typed_word + 'h';
                cout << "h";
                while (GetAsyncKeyState(0x48))
                {
                }
            }
            if (GetAsyncKeyState(0x49))
            {
                typed_word = typed_word + 'i';
                cout << "i";
                while (GetAsyncKeyState(0x49))
                {
                }
            }
            if (GetAsyncKeyState(0x4A))
            {
                typed_word = typed_word + 'j';
                cout << "j";
                while (GetAsyncKeyState(0x4A))
                {
                }
            }
            if (GetAsyncKeyState(0x4B))
            {
                typed_word = typed_word + 'k';
                cout << "k";
                while (GetAsyncKeyState(0x4B))
                {
                }
            }
            if (GetAsyncKeyState(0x4C))
            {
                typed_word = typed_word + 'l';
                cout << "l";
                while (GetAsyncKeyState(0x4C))
                {
                }
            }
            if (GetAsyncKeyState(0x4D))
            {
                typed_word = typed_word + 'm';
                cout << "m";
                while (GetAsyncKeyState(0x4D))
                {
                }
            }
            if (GetAsyncKeyState(0x4E))
            {
                typed_word = typed_word + 'n';
                cout << "n";
                while (GetAsyncKeyState(0x4E))
                {
                }
            }
            if (GetAsyncKeyState(0x4F))
            {
                typed_word = typed_word + 'o';
                cout << "o";
                while (GetAsyncKeyState(0x4F))
                {
                }
            }
            if (GetAsyncKeyState(0x50))
            {
                typed_word = typed_word + 'p';
                cout << "p";
                while (GetAsyncKeyState(0x50))
                {
                }
            }
            if (GetAsyncKeyState(0x51))
            {
                typed_word = typed_word + 'q';
                cout << "q";
                while (GetAsyncKeyState(0x51))
                {
                }
            }
            if (GetAsyncKeyState(0x52))
            {
                typed_word = typed_word + 'r';
                cout << "r";
                while (GetAsyncKeyState(0x52))
                {
                }
            }
            if (GetAsyncKeyState(0x53))
            {
                typed_word = typed_word + 's';
                cout << "s";
                while (GetAsyncKeyState(0x53))
                {
                }
            }
            if (GetAsyncKeyState(0x54))
            {
                typed_word = typed_word + 't';
                cout << "t";
                while (GetAsyncKeyState(0x54))
                {
                }
            }
            if (GetAsyncKeyState(0x55))
            {
                typed_word = typed_word + 'u';
                cout << "u";
                while (GetAsyncKeyState(0x55))
                {
                }
            }
            if (GetAsyncKeyState(0x56))
            {
                typed_word = typed_word + 'v';
                cout << "v";
                while (GetAsyncKeyState(0x56))
                {
                }
            }
            if (GetAsyncKeyState(0x57))
            {
                typed_word = typed_word + 'w';
                cout << "w";
                while (GetAsyncKeyState(0x57))
                {
                }
            }
            if (GetAsyncKeyState(0x58))
            {
                typed_word = typed_word + 'x';
                cout << "x";
                while (GetAsyncKeyState(0x58))
                {
                }
            }
            if (GetAsyncKeyState(0x59))
            {
                typed_word = typed_word + 'y';
                cout << 'y';
                while (GetAsyncKeyState(0x59))
                {
                }
            }
            if (GetAsyncKeyState(0x5A))
            {
                typed_word = typed_word + 'z';
                cout << 'z';
                while (GetAsyncKeyState(0x5A))
                {
                }
            }
            if (GetAsyncKeyState(VK_BACK))
            {
                if (typed_word != "")
                {
                    typed_word.pop_back();
                }
                system("cls");
                searchMenu();
                cout << typed_word;
                while (GetAsyncKeyState(VK_BACK))
                {
                }
            }
            if (GetAsyncKeyState(VK_TAB)) // Check if the TAB key is pressed
            {
                if (typed_word == "") // Check if no word is typed
                {
                    PlaySound(TEXT("forSegition.wav"), NULL, SND_ASYNC); // play Music with noSegition
                    cout << "\n\n For suggestion You must Write atleast one Alphabet...!\n";
                    Sleep(3000); // delay
                    system("cls");
                    PlaySound(TEXT("BackgroundMusic.wav"), NULL, SND_ASYNC); // play Music
                    searchMenu();                                            // Go back to the search menu
                }
                else
                {
                    bool flag = true;
                    int selected;                // to select choice
                    Node* temp = tree.getroot(); // Get the root of a tree data structure
                    // Check if 'typed_word' exists in the tree data structure
                    if (tree.present(typed_word))
                    {
                        // to 'typed_word' and store them in 'suggestion' and 'meaningArr' arrays
                        tree.getSuggestion(temp, typed_word, suggestion, meaningArr, suggestion_size, flag);
                        system("cls");
                        printSuggestions(suggestion, suggestion_size); // Display suggestions
                        selected = selectSuggestion(suggestion_size);  // Select a suggestion
                        // bool cond = 1;// condition flag

                        if (selected >= 0 && selected < suggestion_size) // check validity of selected vriable
                        {
                            typed_word = suggestion[selected]; // Get the selected suggestion

                            string suggest_word_meaning = meaningArr[selected]; // Get the meaning of the selected suggestion
                            system("cls");
                            SetConsoleTextAttribute(hConsole, 14);
                            cout << "\n\n\t\t" << setfill('*') << setw(34) << ""
                                << "\n\n";
                            cout << setfill(' '); // Reset setfill
                            SetConsoleTextAttribute(hConsole, 15);
                            cout << "\t\t" << setw(15) << left << "|Word"
                                << "|" << setw(15) << left << "Meaning"
                                << "\n";
                            cout << "\t\t----------------------------------\n";
                            SetConsoleTextAttribute(hConsole, 11);
                            cout << "\t\t" << setw(15) << left << typed_word << "|" << setw(15) << left << suggest_word_meaning << endl;
                            SetConsoleTextAttribute(hConsole, 14);
                            cout << "\n\n\t\t" << setfill('*') << setw(34) << ""
                                << "\n\n";
                            cout << setfill(' '); // Reset setfill

                            cout << " \n\n\n\t\t\tEnter BACKSPACE For Back...!";
                        }
                        else
                        {
                            system("cls");
                            searchMenu(); // Go back to the search menu
                        }
                    }
                    else
                    {
                        system("cls");
                        // Display a message indicating no suggestions found
                        PlaySound(TEXT("noSegition.wav"), NULL, SND_ASYNC); // play Music with noSegition
                        SetConsoleTextAttribute(hConsole, 14);
                        cout << "\n\n\t\t\t*************************************************\n\n";
                        cout << "\t\t\tWe Have No Suggestions for your Entered Word";
                        cout << "\n\n\t\t\t*************************************************\n\n";
                        Sleep(3000);
                        system("cls");
                        PlaySound(TEXT("BackgroundMusic.wav"), NULL, SND_ASYNC); // play Music
                        searchMenu();                                            // Go back to the search menu
                    }
                    suggestion_size = 0; // Reset suggestion size
                }
                while (GetAsyncKeyState(VK_TAB))
                {
                } // Wait until TAB key is released
            }
            if (GetAsyncKeyState(VK_DELETE))
            {
                if (typed_word == "")
                {
                    PlaySound(TEXT("fordelete.wav"), NULL, SND_ASYNC); // play Music
                    cout << "\n\n For Delation You must Write atleast one Alphabate...!\n";
                    Sleep(3000);
                    system("cls");
                    PlaySound(TEXT("BackgroundMusic.wav"), NULL, SND_ASYNC); // play Music
                    searchMenu();
                }
                else
                {
                    string str;
                    str = typed_word;
                    typed_word = "";
                    tree.deleteWord(str, 1);
                }
                while (GetAsyncKeyState(VK_DELETE))
                {
                }
            }
            if (GetAsyncKeyState(VK_INSERT))
            {
                if (typed_word == "")
                {
                    PlaySound(TEXT("forUpdates.wav"), NULL, SND_ASYNC); // play Music
                    cout << "\n\n For Updates You must Write atleast one Alphabate...!\n";
                    Sleep(3000);
                    system("cls");
                    PlaySound(TEXT("BackgroundMusic.wav"), NULL, SND_ASYNC); // play Music
                    searchMenu();
                }
                else
                {
                    SetConsoleTextAttribute(hConsole, 13);
                    string word, mean;
                start3:
                    cin.ignore();
                    cout << "\n\n\n\n\t\t\t\t\t Enter Your New Word : ";
                    cin >> word;
                start4:
                    cin.ignore();
                    cout << "\t\t\t\t\t Enter Meaning oF " << word << " : ";
                    cin >> mean;
                    if (!hasOnlyLowerCase(word))
                    {
                        system("cls");
                        goto start3;

                    }
                    if (!hasOnlyLowerCase(mean))
                    {
                        system("cls");
                        goto start4;

                    }
                    tree.updateWord(typed_word, word, mean); // call for update the new word
                    SetConsoleTextAttribute(hConsole, 15);
                }
                while (GetAsyncKeyState(VK_INSERT))
                {
                }
            }
            if (GetAsyncKeyState(VK_ESCAPE))
            {
                while (GetAsyncKeyState(VK_ESCAPE))
                {
                }
                goto start;
            }
        }
    }
    else if (choice == "0")
    {
        cout << "\n\n\n\n\t\t\t\t";
        PlaySound(TEXT("Thanks.wav"), NULL, SND_ASYNC); // play Music
        string end = "Thanks For Using Our SuccessGrammatica dictionary by Asad Raza! and Sharaz\n\n\n\n";
        SetConsoleTextAttribute(hConsole, 12);
        for (int i = 0; i < end.length(); i++)
        {
            Sleep(100);
            cout << end[i];
        }
        exit(1);
    }
    else
    {
        cout << "\n\n\t\t**********************************\n\n";
        cout << "\t\t\tError...! \n";
        cout << "\t\t\tAlways Choose a Best Choice...!";
        cout << "\n\n\t\t**********************************\n\n";
        Sleep(2000);
        goto start;
    }
    system("pause");
}

int selectSuggestion(int count)
{
    int x = 0, y = 0;        // initializing x and y coordinates
    move_cursor_to_xy(x, y); // Moving the cursor to coordinates (0, 0)
    while (1)
    {
        if (GetAsyncKeyState(VK_DOWN)) // Checking if the down arrow key is pressed
        {
            if (y >= count) // Checking if y is greater than or equal to count
            {
                y = 0; // If true, resetting y to 0
            }
            else
            {
                y++;
            }
            move_cursor_to_xy(x, y); // Moving the cursor to the new y position
        }
        if (GetAsyncKeyState(VK_UP)) // Checking if the up arrow key is pressed
        {
            if (y <= 0) // Checking if y is less than or equal to 0
            {
                y = count; // If true, setting y to the count value
            }
            else
            {
                y--;
            }
            move_cursor_to_xy(x, y); // Moving the cursor to the new y position
        }
        if (GetAsyncKeyState(VK_LSHIFT)) // Checking if the left shift key is pressed
        {
            break;
        }
    }
    return y; // Returning the final y value
}

void move_cursor_to_xy(int x, int y)
{
    static HANDLE h = NULL; // Declaring a static HANDLE variable
    if (!h)                 // Checking if h is NULL
    {
        h = GetStdHandle(STD_OUTPUT_HANDLE); // Getting the handle to the console output
    }
    COORD coordinates;                        // Declaring a COORD structure
    coordinates.X = x;                        // Assigning x coordinate
    coordinates.Y = y;                        // Assigning y coordinate
    SetConsoleCursorPosition(h, coordinates); // Setting the console cursor position to the specified coordinates
    Sleep(200);
}

void printSuggestions(string arr[], int count)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int x = 0;
    for (int i = 0; i < count; i++)
    {
        cout << i + 1 << " - ";
        SetConsoleTextAttribute(hConsole, 11);
        cout << arr[i] << endl;
        SetConsoleTextAttribute(hConsole, 15);
        x = i;
    }
    SetConsoleTextAttribute(hConsole, 12);
    cout << x + 2 << " - Not Select" << endl;
    SetConsoleTextAttribute(hConsole, 14);
    cout << "\n\n\t\t\t\t**************************************\n\n";
    SetConsoleTextAttribute(hConsole, 15);
    cout << "\t\t\t\tSelect Word - Left Shift\n";
    SetConsoleTextAttribute(hConsole, 11);
    cout << "\t\t\t\tYou Can Go UP & DOWN ( with Arraw keys )\n";
    SetConsoleTextAttribute(hConsole, 14);
    cout << "\n\n\t\t\t\t***************************************\n\n";
}

void searchMenu()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 11);

    cout << "==================\t\t\t\t==================\t\t\t\t==================\t\t\t\t=====================\n";

    SetConsoleTextAttribute(hConsole, 10);
    cout << "| Tab - Suggestion|\t\t\t\t|";

    SetConsoleTextAttribute(hConsole, 11);
    cout << " Del - Delete    ";

    SetConsoleTextAttribute(hConsole, 12);
    cout << "|\t\t\t\t|";

    SetConsoleTextAttribute(hConsole, 13);
    cout << " Insert - Update  ";

    SetConsoleTextAttribute(hConsole, 14);
    cout << "|\t\t\t\t|";

    SetConsoleTextAttribute(hConsole, 14);
    cout << " ESC - Back To Menu |\n";

    SetConsoleTextAttribute(hConsole, 11);
    cout << "==================\t\t\t\t==================\t\t\t\t==================\t\t\t\t=====================\n";

    SetConsoleTextAttribute(hConsole, 15);
    cout << "\n\n\n\n\n\t\t\t\t\t\t Enter word : ";
}

void printDictionaryLogo(const string& text, int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
    cout << text << endl;
    SetConsoleTextAttribute(hConsole, 7); // Reset to default color (white)
}

void mainManu()
{
    cout << "\n\n\n\n\n\n\n";

    // Print the top border of the box
    cout << "\t\t\t\t\t\t";
    cout << "\033[1;31m"; // Set text color to red
    for (int i = 0; i < 50; i++)
    {
        cout << "=";
    }
    cout << "\033[0m\n"; // Reset text color

    cout << "\t\t\t\t\t\t";
    cout << "\033[1;33m"; // Set text color to yellow
    cout << "1 - Load Dictionary\n";
    cout << "\t\t\t\t\t\t";
    cout << "2 - Insert New Word\n";
    cout << "\t\t\t\t\t\t";
    cout << "3 - Search Page\n";
    cout << "\t\t\t\t\t\t";
    cout << "0 - Exit\n";
    cout << "\033[0m";

    cout << "\t\t\t\t\t\t";
    cout << "\033[1;34m"; // Set text color to blue
    for (int i = 0; i < 50; i++)
    {
        cout << "=";
    }
    cout << "\033[0m\n";

    cout << "\t\t\t\t\t\t";
    cout << "\033[1;36m"; // Set text color to cyan
    cout << "Enter Your Choice: ";
    cout << "\033[0m";
}
bool hasOnlyLowerCase(const string& str)
{
    for (char c : str)
    {
        if (!islower(c))
        {
            return false; // Found a character that is not lowercase
        }
    }
    return true; // All characters are lowercase
}