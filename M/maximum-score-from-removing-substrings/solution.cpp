#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int totalScore = 0;
        string highPriorityPair;
        string lowPriorityPair;
        
        // The pair with the higher priority to be removed is the 
        // one that gives the greater amount of points
        if (x > y) {
            highPriorityPair = "ab";
            lowPriorityPair = "ba";
        }
        else {
            highPriorityPair = "ba";
            lowPriorityPair = "ab";
        }

        // First pass: remove high priority pair
        string stringAfterFirstPass = 
            removeSubstring(s, highPriorityPair);
        // Calculate removed pairs from first pass
        int removedPairsCount = 
            (s.length() - stringAfterFirstPass.length()) / 2;
        // Calculate score from first pass and add to total
        totalScore += removedPairsCount * max(x, y);


        // Second pass: remove low priority pair
        string stringAfterSecondPass = 
            removeSubstring(stringAfterFirstPass, lowPriorityPair);
        // Calculate removed pairs from second pass
        removedPairsCount = 
         (stringAfterFirstPass.length() - stringAfterSecondPass.length()) / 2;
        // Calculate score from second pass and add to total
        totalScore += removedPairsCount * min(x, y);

        return totalScore;
    }

private:
    string removeSubstring(const string& input, const string& pair) {
        stack<char> stack;
        
        // Iterate through each character in the input string
        for (char currentChar : input) {
            // Check if current character forms the target pair with 
            // the top of the stack
            if (currentChar == pair[1] && !stack.empty() && 
                stack.top() == pair[0]) {
                // Remove the matching character from the stack
                stack.pop();
            }
            else {
                stack.push(currentChar);
            }
        }

        // Reconstruct the remaining string after removing the pairs
        string remainingChars;
        while (!stack.empty()) {
            remainingChars += stack.top();
            stack.pop();
        }
        reverse(remainingChars.begin(), remainingChars.end());

        // Return the updated string without the removed pairs
        return remainingChars;
    }
};


