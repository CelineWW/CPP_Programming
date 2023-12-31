#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    cout << "Let's Play Word Jumble!\n"
        << "\n"
        << "Enter 'hint' for a hint.\n"
        << "Enter 'exit' to exit.\n\n";

    // define a vector of possible words
//    vector<string> words { "guitar", "violin", "tapestry" };
    const int rows = 3;
    const int cols = 9;
    char words[rows][cols] = { "guitar", "violin", "tapestry" };


    // get random word from vector
    srand(time(nullptr));
    int index = rand() % rows;
    char word[cols] = "";
    for (int i = 0; i < cols; ++i) {
        word[i] = words[index][i];
    }

    // jumble the word

    char jumbled_word[cols] = "";
//    auto length = strlen(word);
    strncpy(jumbled_word, word, strlen(word));
//    auto length = word.size();
    
    for (int index1 = 0; index1 < strlen(jumbled_word); ++index1) {
        int index2 = rand() % strlen(jumbled_word);
        char temp = jumbled_word[index1];
        jumbled_word[index1] = jumbled_word[index2];
        jumbled_word[index2] = temp;
    }

    // display the jumbled word in upper case
    cout << "The jumble is...";
    for (char c : jumbled_word) {
        cout << (char)toupper(c);
    }
    cout << "\n\n";

    // loop until the user guesses the jumble or enters 'exit'
    int hint_count = 1;
    char guess[cols] = "";
    while ((strcmp(guess, "exit") != 0)) {
        cout << "Your guess: ";
        cin.getline(guess, cols);
        cin.ignore(1000, '\n');

        if ((strcmp(guess, word) == 0)) {
            cout << "Congratulations! You guessed it.\n\n";
            break;
        }
        else if ((strcmp(guess, "hint") == 0)) {
            cout << "Hint: ";
            for (int i = 0; i < strlen(word); ++i) {
                if (i < hint_count) {
                    cout << static_cast<char>(toupper(word[i])) << ' ';
                }
                else {
                    cout << '_' << ' ';
                }
            }
            cout << "\n\n";
            ++hint_count;
        }
        else if (strcmp(guess, "exit") == 0) {
            cout << "Bye! Let's play again soon.\n\n";
        }
        else {
            cout << "Nope. Try again!\n\n";
        }
    }
}
