/**
Coding is addictive!!

URL : https://leetcode.com/problems/subtree-of-another-tree/#/description
Test cases :
Algo :
Notes :
**/

#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    bool isIdentical(TreeNode* a, TreeNode* b){
            if(a==NULL && b==NULL) return true;
            if(a==NULL || b==NULL) return false;
            if(a->val!=b->val) return false;

            return isIdentical(a->left,b->left) &&
                isIdentical(a->right,b->right) ;
    }

    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s==NULL || t==NULL) return false;
        if(isIdentical(s,t)) return true;

        return isSubtree(s->left,t) ||
            isSubtree(s->right,t);
    }
};

int main(){
    Solution *s = new Solution();
    cout<<s->
}
