#include <iostream>
#include "FiniteAutomaton/FiniteAutomaton.h"

using namespace std;

// Function to handle additional choices for FiniteAutomaton
void additionalChoices(FiniteAutomaton* finiteAutomaton) {
    int subChoice;
    do {
        cout << "\nAdditional choices for Finite Automaton:\n";
        cout << "1. Display more details\n";
        cout << "2. Test another sequence\n";
        cout << "3. Return to main menu\n";
        cout << "Enter your choice: ";
        cin >> subChoice;

        switch (subChoice) {
            case 1:
                finiteAutomaton->displayElements();
                break;
            case 2: {
                string sequence;
                cout << "Enter a new sequence to test: ";
                cin >> sequence;
                if (finiteAutomaton->verifySequence(sequence)) {
                    cout << "Sequence '" << sequence << "' is accepted by the Finite Automaton.\n";
                } else {
                    cout << "Sequence '" << sequence << "' is not accepted by the Finite Automaton.\n";
                }
                break;
            }
            case 3:
                cout << "Returning to main menu...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (subChoice != 3);
}

int main() {
    // Load FiniteAutomaton from file
    FiniteAutomaton finiteAutomaton("C:\\Users\\Naomi\\Desktop\\University Year 3\\lftc\\LFTC\\Lab2_HashTable\\FA.in");
    finiteAutomaton.readFromFile();
    // Display information after reading from file
    cout << "\nAfter reading from file:\n";
    finiteAutomaton.displayElements();


    int choice;
    do {
        cout << "1. Display elements of the Finite Automaton\n";
        cout << "2. Test a sequence with the Finite Automaton\n";
        cout << "3. Additional choices for Finite Automaton\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                finiteAutomaton.displayElements();
                break;
            case 2: {
                string sequence;
                cout << "Enter a sequence to test: ";
                cin >> sequence;
                if (finiteAutomaton.verifySequence(sequence)) {
                    cout << "Sequence '" << sequence << "' is accepted by the Finite Automaton.\n";
                } else {
                    cout << "Sequence '" << sequence << "' is not accepted by the Finite Automaton.\n";
                }
                break;
            }
            case 3:
                additionalChoices(&finiteAutomaton);
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 0);

    return 0;
}
