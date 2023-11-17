//
// Created by Naomi on 11/17/2023.
//

#ifndef MAIN_CPP_FINITEAUTOMATON_H
#define MAIN_CPP_FINITEAUTOMATON_H


#include <vector>
#include <string>

struct FA_Transition {
    std::string sourceState;
    std::string value;
    std::string destinationState;
};

class FiniteAutomaton {
private:
    std::string filePath;
    std::vector<std::string> states;
    std::vector<std::string> alphabet;
    std::vector<std::string> finalStates;
    std::string initialState;
    std::vector<FA_Transition> transitions;

    FA_Transition findTransitionBySourceAndValue(std::string source, std::string value);

    bool isDeterministic();

public:
    FiniteAutomaton(std::string filePath);

    void readFromFile();

    void displayElements();

    bool verifySequence(std::string sequence);

    std::string displayStates();

    std::string displayAlphabet();

    std::string displayInitialState();

    std::string displayFinalStates();

    std::string displayTransitions();
};

#endif //MAIN_CPP_FINITEAUTOMATON_H
