#include <iostream>
#include "HashTable/HashTable.h"
#include "Scanner/Scanner.h"
#include "FiniteAutomaton/FiniteAutomaton.h"

using namespace std;
void testHashTable() {
    HashTable<string> hashTable;

    // Insert some values
    int position1 = hashTable.addValue("apple");
    int position2 = hashTable.addValue("banana");
    int position3 = hashTable.addValue("cherry");

    // Check if values are in the correct positions
    if (hashTable.findPosition("apple") != position1)
        cout << "Test failed: Position of 'apple' is incorrect." << endl;
    if (hashTable.findPosition("banana") != position2)
        cout << "Test failed: Position of 'banana' is incorrect." << endl;
    if (hashTable.findPosition("cherry") != position3)
        cout << "Test failed: Position of 'cherry' is incorrect." << endl;

    // Check if values can be found
    if (hashTable.containsValue("apple") != position1)
        cout << "Test failed: 'apple' not found." << endl;
    if (hashTable.containsValue("banana") != position2)
        cout << "Test failed: 'banana' not found." << endl;
    if (hashTable.containsValue("cherry") != position3)
        cout << "Test failed: 'cherry' not found." << endl;

    // Remove a value
    hashTable.deleteValue("banana");

    // Check if 'banana' is removed
    if (hashTable.containsValue("banana") == -1)
        cout << "Test delete: 'banana' was removed." << endl;
}

int main() {
    //testHashTable();

    int main() {
        int choice;
        do {
            cout << "1. Test HashTable\n";
            cout << "2. Test Scanner\n";
            cout << "3. Test Finite Automaton\n";
            cout << "0. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    // Test HashTable
                    testHashTable();
                    break;
                case 2: {
                    // Test Scanner
                    Scanner ST;
                    string fileName = "C:\\Users\\Naomi\\Desktop\\University Year 3\\lftc\\LFTC\\Lab2_HashTable\\Files\\p1err.txt";
                    ST.scanning(fileName);
                    break;
                }
                case 3: {
                    // Test Finite Automaton
                    FiniteAutomaton finiteAutomaton("FA.in");
                    finiteAutomaton.readFromFile();

                    // Display elements of the Finite Automaton
                    finiteAutomaton.displayElements();

                    // Test a sequence with the Finite Automaton
                    std::string sequence;
                    cout << "Enter a sequence to test: ";
                    cin >> sequence;

                    if (finiteAutomaton.verifySequence(sequence)) {
                        std::cout << "Sequence '" << sequence << "' is accepted by the Finite Automaton.\n";
                    } else {
                        std::cout << "Sequence '" << sequence << "' is not accepted by the Finite Automaton.\n";
                    }
                    break;
                }
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

//    Scanner ST;
//    string fileName = "C:\\Users\\Naomi\\Desktop\\University Year 3\\lftc\\LFTC\\Lab2_HashTable\\Files\\p1err.txt";
//    ST.scanning(fileName);
    return 0;
}
