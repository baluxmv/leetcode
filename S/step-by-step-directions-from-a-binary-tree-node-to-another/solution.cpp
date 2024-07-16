#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        // Stores the paths from the root to startValue and destValue
        vector<char> startPath;
        vector<char> destinationPath;

        // Find the paths from the root to startValue and destValue
        dfs(root, startValue, startPath);
        dfs(root, destValue, destinationPath);

        // Find the lowest common ancestor (LCA)
        // i.e the index where the paths diverge
        int i = 0;
        while (i < min(startPath.size(), destinationPath.size())){
            if (startPath[i] != destinationPath[i]) {
                break;
            }
            i++;
        }

        // Steps to move up from the startValue to the LCA
        string startToCommonAncestor(startPath.size() - i, 'U');

        // Steps to move from the LCA to the destValue
        string commonAncestorToDest(destinationPath.begin() + i, destinationPath.end());

        // Return the full path from startValue to destValue
        return startToCommonAncestor + commonAncestorToDest;
    } 

private:
    bool dfs(TreeNode* node, int target, vector<char>& currentPath) {
        // If the path reaches a null node
        if (node == nullptr) {
            return false;
        }

        // If this current path reaches the target
        if (node->val == target) {
            return true;
        }

        // Try reaching the target using the path to the left
        currentPath.push_back('L');
        if (dfs(node->left, target, currentPath)) {
            return true;
        }
        currentPath.pop_back();

        // Try reaching the target using the path to the right
        currentPath.push_back('R');
        if (dfs(node->right, target, currentPath)) {
            return true;
        }
        currentPath.pop_back();

        return false;   
    }   
};
