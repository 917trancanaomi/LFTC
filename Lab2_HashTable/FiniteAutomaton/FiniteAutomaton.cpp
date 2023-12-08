// FiniteAutomaton.cpp
#include "FiniteAutomaton.h"
#include <fstream>
#include <iostream>
#include <cstring>
#include <algorithm>

FA_Transition FiniteAutomaton::findTransitionBySourceAndValue(std::string source, std::string value) {
    for (const auto &item : this->transitions) {
        if (item.sourceState == source && item.value == value)
            return item;
    }
    return FA_Transition();
}

FiniteAutomaton::FiniteAutomaton(std::string filePath) : filePath(std::move(filePath)) {}

void FiniteAutomaton::readFromFile() {
    std::ifstream inputStream;
    inputStream.open(this->filePath);

    if (!inputStream.is_open()) {
        std::cerr << "Error opening file: " << this->filePath << std::endl;
        return;
    }

    // Read all states
    char states[100];
    inputStream.getline(states, 100);
    int i = 0;
    while (i < strlen(states)) {
        if (states[i] != ',') {
            std::string aux = "";
            aux.push_back(states[i]);
            this->states.push_back(aux);
        }
        i++;
    }

    // Read alphabet
    char alphabet[1024];
    inputStream.getline(alphabet, 1024);
    for (int j = 0; j < strlen(alphabet); j++) {
        if (alphabet[j] != ',') {
            std::string aux = "";
            aux.push_back(alphabet[j]);
            this->alphabet.push_back(aux);
        }
    }

    std::string initialState;
    inputStream >> initialState; // Read initial state as a string
    this->initialState = initialState;
    inputStream.get();

    char finalStates[100];
    inputStream.getline(finalStates, 100);
    for (int j = 0; j < strlen(finalStates); j++) {
        if (finalStates[j] != ',') {
            std::string aux = "";
            aux.push_back(finalStates[j]);
            this->finalStates.push_back(aux);
        }
    }

    char transition[100];
    while (inputStream.getline(transition, 100)) {
        std::string initial, val, final;
        initial.push_back(transition[0]); // First character is source state
        // Second character is ','
        val.push_back(transition[2]);     // Third character is value of transition
        // Fourth character is '='
        final.push_back(transition[4]);   // Fifth character is destination state
        FA_Transition aux;
        aux.sourceState = initial;
        aux.value = val;
        aux.destinationState = final;
        this->transitions.push_back(aux);
    }

    std::cout << "States after reading: ";
    for (const auto &item : this->states) {
        std::cout << item << " ";
    }
    std::cout << std::endl;

    std::cout << "Alphabet after reading: ";
    for (const auto &item : this->alphabet) {
        std::cout << item << " ";
    }
    std::cout << std::endl;

    std::cout << "Initial state after reading: " << this->initialState << std::endl;

    std::cout << "Final states after reading: ";
    for (const auto &item : this->finalStates) {
        std::cout << item << " ";
    }
    std::cout << std::endl;

    std::cout << "Transitions after reading:\n";
    for (const auto &item : this->transitions) {
        std::cout << "(" << item.sourceState << "," << item.value << ") = " << item.destinationState << "\n";
    }

    inputStream.close();
}


void FiniteAutomaton::displayElements() {
    std::cout << "States: ";
    for (const auto &item : this->states) {
        std::cout << item << " ";
    }

    std::cout << "\nAlphabet: ";
    for (const auto &item : this->alphabet) {
        std::cout << item << " ";
    }

    std::cout << "\nInitial state: " << this->initialState;

    std::cout << "\nFinal states: ";
    for (const auto &item : this->finalStates) {
        std::cout << item << " ";
    }

    std::cout << "\nTransitions:\n";
    for (const auto &item : this->transitions) {
        std::cout << "(" << item.sourceState << "," << item.value << ") = " << item.destinationState << "\n";
    }
}

bool FiniteAutomaton::verifySequence(std::string sequence) {
    if (!isDeterministic())
        return false;
    if (sequence.empty()) {
        if (finalStates.end() != std::find(finalStates.begin(), finalStates.end(), initialState)) // If the sequence is empty and the initial state is also a final one
            return true;
        return false;
    }

    std::string currentState = this->initialState;

    for (char i : sequence) {
        std::string value;
        value.push_back(i);
        FA_Transition currentTransition = findTransitionBySourceAndValue(currentState, value);
        if (currentTransition.sourceState.empty()) {
            return false;
        }
        currentState = currentTransition.destinationState;
    }

    return std::find(finalStates.begin(), finalStates.end(), currentState) != finalStates.end();
}

std::string FiniteAutomaton::displayStates() {
    std::string setOfStates;
    for (const auto &item : states) {
        setOfStates += item + " ";
    }
    return setOfStates;
}

std::string FiniteAutomaton::displayAlphabet() {
    std::string alphabetString;
    for (const auto &item : alphabet) {
        alphabetString += item + " ";
    }
    return alphabetString;
}

std::string FiniteAutomaton::displayInitialState() {
    return initialState;
}

std::string FiniteAutomaton::displayFinalStates() {
    std::string setOfFinalStates;
    for (const auto &item : finalStates) {
        setOfFinalStates += item + " ";
    }
    return setOfFinalStates;
}

std::string FiniteAutomaton::displayTransitions() {
    std::string allTransitions;
    for (const auto &item : this->transitions) {
        allTransitions += "(" + item.sourceState + "," + item.value + ") = " + item.destinationState + "\n";
    }
    return allTransitions;
}

bool FiniteAutomaton::isDeterministic() {
    for (size_t i = 0; i < transitions.size() - 1; i++)
        for (size_t j = i + 1; j < transitions.size(); j++) {
            FA_Transition t1 = transitions[i];
            FA_Transition t2 = transitions[j];
            if (t1.sourceState == t2.sourceState && t1.value == t2.value &&
                t1.destinationState != t2.destinationState)
                return false;
        }
    return true;
}
