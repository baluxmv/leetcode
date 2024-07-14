#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string countOfAtoms(string formula) {
        // Stack of maps to keep track of the count of atoms in each 
        // section of the formula, where a new section starts with '('
        // and ends with ')', with the starting section being the only
        // possible exception. 
        stack<unordered_map<string, int>> stack;
        stack.push(unordered_map<string, int>());

        int i = 0;
        while (i < formula.length()) {
            // If we reach the start of a new section of the formula
            if (formula[i] == '(') {
                stack.push(unordered_map<string, int>());
                i++;
            }

            // If we reach the end of a section of the formula
            else if (formula[i] == ')') {
                unordered_map<string, int> finishedSection = stack.top();
                stack.pop();

                i++;
                // Get the number that comes after the closing parantheses
                string elementCount;
                while (i < formula.length() && isdigit(formula[i])) {
                    elementCount += formula[i];
                    i++;   
                }
                int multiplier;
                if (elementCount.empty()) {
                    multiplier = 1;
                }
                else {
                    multiplier = stoi(elementCount);                
                }

                // Every element in the section that just ended is 
                // multiplied by the number that came after the ')'
                for (auto& [element, count] : finishedSection) {
                    finishedSection[element] *= multiplier;
                }
                
                // Add the finished section to the current section
                unordered_map<string, int>& currentSection = stack.top();
                for (auto& [element, count] : finishedSection) {
                    currentSection[element] += finishedSection[element];
                }
            }

            // If we encounter an element on the formula (uppercase character)
            else {
                string element;
                element += formula[i];
                i++;

                // if the element has two characters 
                if (i < formula.length() && islower(formula[i])) {
                    element += formula[i];
                    i++;
                }
                
                string elementCount;
                while (i < formula.length() && isdigit(formula[i])) {
                    elementCount += formula[i];
                    i++;   
                }

                // Stores the element count as an integer
                int count;
                if (elementCount.empty()) {
                    count = 1;
                }
                else {
                    count = stoi(elementCount);                
                }

                // Get the current map for the current section of the formula
                unordered_map<string, int>& currentMap = stack.top();
                // Increment the count of the current element
                currentMap[element] += count;
            }
        }

        unordered_map<string, int>& unorderedFormulaMap = stack.top();

        // Sorted map containing the whole formula
        map<string, int> orderedFormulaMap
            (unorderedFormulaMap.begin(), unorderedFormulaMap.end());

        // Complete formula string
        string res = "";
        for (auto& [element, count] : orderedFormulaMap) {
            res += element;
            if (count > 1) {
                res += to_string(count);
            }
        }
        return res;
    }
};
