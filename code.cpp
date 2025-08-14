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
    int findmin(TreeNode* root){
        while(root->left!=NULL){
            root=root->left;
        }
        return root->val;
    }
    TreeNode* check(TreeNode* root , int key){
        if(root==NULL) return root;
        if(root->val==key){
            if(root->left==NULL && root->right==NULL){
                delete(root);
                return NULL;
            }
            else if(root->left==NULL && root->right!=NULL){
                TreeNode* check1 = root->right;
                delete(root);
                return check1;
            }
            else if(root->right==NULL && root->left!=NULL){
                TreeNode* check1 = root->left;
                delete(root);
                return check1;
            }
            else{
                int min = findmin(root->right);
                root->val = min;
                root->right = check(root->right , min);
                return root;
            }
        }
        else if(key>root->val){
            root->right = check(root->right , key);
        }
        else{
            root->left = check(root->left , key);
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        return check(root , key);
    }
};
