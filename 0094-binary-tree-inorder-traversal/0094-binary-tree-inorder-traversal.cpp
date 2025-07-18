class Solution {
public:
    void inOrder(TreeNode* node, vector<int>& res) {
        if (!node) return;
        inOrder(node->left, res);
        res.push_back(node->val);
        inOrder(node->right, res);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inOrder(root, res);
        return res;
    }
};