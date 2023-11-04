#include <cassert>
#include <math.h>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr)
            return true;
        if(height(root) == -1)
            return false;
        return true;
    }
    int height(TreeNode* root){
        if(root == nullptr)
            return 0;
        int lefth = height(root->left);
        int righth = height(root->right);
        if(lefth == -1 || righth == -1 || abs(lefth-righth) > 1)
            return -1;
        return max(lefth, righth) +1;
    }
};

int main(){

}