// {Approach 1}
// Time Complexity : O(n) ...... N is total number of elements in tree
// Space Complexity : O(n/2) == O(n) .... n/2 is size of queue in worst case which is all leaf nodes being added in queue
//
// {Approach 2}
// Time Complexity : O(n) ...... N is total number of elements in tree
// Space Complexity : O(n) ... because hashmap is used to store all the nodes.
//
// {Approach 3}
// Time Complexity : O(n) ...... N is total number of elements in tree
// Space Complexity : O(1) 
// Did this code successfully run on Leetcode : Yes
// Any problem you faced while coding this :

/*
Leetcode : https://leetcode.com/problems/binary-tree-level-order-traversal/description/

Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).
*/



/**
 * 
 * Approach 1 : Using BFS
 * 
 * Queue is used to store the nodes.
 * At each iteration in while llop, nodes at same height are added to the queue.
 * 
*/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>result;
        if(root == nullptr) return result;
        queue<TreeNode*>q;

        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int> temp;
            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                temp.push_back(node->val);
                q.pop();
                if(node->left != nullptr) q.push(node->left);
                if(node->right != nullptr) q.push(node->right);
            }
            result.push_back(temp);
        }
        return result;

    }
};


/**
 * 
 * Approach 2 : Using DFS (Depth First) i.e, using recursive
 * 
 * Tree is traversed using recursion and local variable level is passed to fuction which
 * tracks the level of the node. Each node is added to array in hash map using level as a key.
 * 
 * Here, unordered_map is not used. Map is ordered map by default. Which is required in this solution
 * as we need to display output in order.
 * 
*/


class Solution {
    map<int, vector<int>>hMap;
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>result;
        helper(root, 0);

        for(auto &pair : hMap){
            result.push_back(pair.second);
        }
        return result;
    }

    void helper (TreeNode* root, int level){
        if(root == nullptr) return;

        hMap[level].push_back(root->val);
        helper(root->left, level+1);
        helper(root->right, level+1);

        return;
    } 
};



/**
 * 
 * Approach 3 : Using DFS but no extra space
 * 
 * This approach is similar to Approach 2, but extra space is not used.
 * Output vector array is directly accessed to store the data.
 * 
*/

class Solution {
    vector<vector<int>>result;
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        helper(root, 0);
        return result;
    }

    void helper (TreeNode* root, int level){
        if(root == nullptr) return;

        if(level == result.size()){
            result.push_back({root->val});
        } else {
            result[level].push_back(root->val);
        }


        helper(root->left, level+1);
        helper(root->right, level+1);

        return;
    } 
};