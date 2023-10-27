#include <iostream>
#include "HashTable/HashTable.h"
#include "Scanner/Scanner.h"
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
    Scanner ST;
    ST.scanning();
    return 0;
}
