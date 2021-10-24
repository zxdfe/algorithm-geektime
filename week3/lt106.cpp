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
    unordered_map<int, int> in_pos;
    vector<int> post;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int in_len = inorder.size();
        for(int i=0 ; i < in_len; ++ i){
            in_pos[inorder[i]] = i;
        }
        
        post = postorder;
        
        TreeNode* root = buildTree(0, in_len - 1, 0, post.size() - 1);
        return root;   
    }
    
    TreeNode* buildTree(int in_left, int in_right, int post_left, int post_right){
        if(in_left > in_right || post_left > post_right) return NULL;
        
        int root_val = post[post_right];
        int root_pos = in_pos[root_val];
        TreeNode* node = new TreeNode(root_val);
        
        node->left = buildTree(in_left, root_pos - 1, post_left, post_left + root_pos - in_left - 1);
        node->right = buildTree(root_pos + 1, in_right, post_left + root_pos - in_left, post_right - 1);
        
        return node;        
    }
};