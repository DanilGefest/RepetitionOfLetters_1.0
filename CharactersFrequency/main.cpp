#include <fstream>
#include <iostream>
using namespace std;

int main() {
    int arrayForCountingSingleRepetitionsOfLetters[128];
    fstream fileText;
    char character;

    fileText.open("Cleopatra.txt");
    if (!fileText) {
        cout << "ERROR 404";
        return 1;
    }

    for (int repiter = 0; repiter < 128; ++repiter) {
        arrayForCountingSingleRepetitionsOfLetters[repiter] = 0;
    }

    character = fileText.get();
    while (character != EOF) {
        character = toupper(character);
        ++arrayForCountingSingleRepetitionsOfLetters[character];
        character = fileText.get();
    }

    cout << endl << "Single letters frequencies in this file are:" << endl;
    for (char character = 'A'; character <= 'Z'; ++character) {
        if (arrayForCountingSingleRepetitionsOfLetters[character]) {
            cout << character << " : " << arrayForCountingSingleRepetitionsOfLetters[character] << endl;
        }
    }

    int arrayForCountingCombinationsOfTwoLetters[128][128];
    fstream doublesFile;

    doublesFile.open("Cleopatra.txt");

    for (int firstIterator = 0; firstIterator < 128; ++firstIterator) {
        for (int secondIterator = 0; secondIterator < 128; ++secondIterator) {
            arrayForCountingCombinationsOfTwoLetters[firstIterator][secondIterator] = 0;
        }
    }

    char firstLetter, secondLetter;
    firstLetter = doublesFile.get();
    secondLetter = doublesFile.get();

    while (secondLetter != EOF) {
        firstLetter = toupper(firstLetter);
        secondLetter = toupper(secondLetter);
        ++arrayForCountingCombinationsOfTwoLetters[firstLetter][secondLetter];
        firstLetter = secondLetter;
        secondLetter = doublesFile.get();
    }

    cout << endl << "Double letter frequencies in this file are:" << endl;
    for (char firstLetter = 'A'; firstLetter <= 'Z'; ++firstLetter) {
        for (char secondLetter = 'A'; secondLetter <= 'Z'; ++secondLetter) {

            if (arrayForCountingCombinationsOfTwoLetters[firstLetter][secondLetter]) {
                cout << firstLetter << secondLetter << " : " << arrayForCountingCombinationsOfTwoLetters[firstLetter][secondLetter] << endl;
            }
        }
    }

    return 0;
}