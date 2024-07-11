# Reverse Substrings Between Each Pair of Parentheses

## Solutions
### Stack
>   Time Complexity: O(n<sup>2</sup>)
    Space Complexity: O(n)

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> openParenthesesIndices;
        string result = "";

        for (char currentChar : s) {
            if (currentChar == '(') {
                // Store the current length as the start index for 
                // a future reversal from (start, end)
                openParenthesesIndices.push(result.length());
            }
            else if (currentChar == ')') {
                int start = openParenthesesIndices.top();
                openParenthesesIndices.pop();
                // Reverse the substring between the matching parentheses
                reverse(result.begin() + start, result.end());
            }
            else {
                // Append non-parenthesis characters to the string
                result += currentChar;
            }
        }
        return result;
    }
};
```
