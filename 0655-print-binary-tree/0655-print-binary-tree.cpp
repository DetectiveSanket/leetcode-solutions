class Solution {
public:
    vector<vector<string>> printTree(TreeNode* root) {
        // Step 1: Calculate the height of the tree
        int height = getHeight(root);
        
        // Step 2: Calculate dimensions and initialize the matrix
        int m = height + 1;
        int n = (1 << (height + 1)) - 1; // Equivalent to 2^(height+1) - 1
        vector<vector<string>> res(m, vector<string>(n, ""));
        
        // Step 3: Populate the matrix with node values
        populate(root, 0, (n - 1) / 2, height, res);
        
        return res;
    }

private:
    // Helper function to get the 0-indexed height of the tree
    int getHeight(TreeNode* node) {
        if (!node) return -1;
        return 1 + max(getHeight(node->left), getHeight(node->right));
    }

    // Helper function to place nodes in the correct positions
    void populate(TreeNode* node, int r, int c, int height, vector<vector<string>>& res) {
        if (!node) return;
        
        // Place the current node's value
        res[r][c] = to_string(node->val);
        
        // Recursively place left and right children
        if (node->left) {
            int offset = 1 << (height - r - 1); // Calculate only when needed
            populate(node->left, r + 1, c - offset, height, res);
        }
        if (node->right) {
            int offset = 1 << (height - r - 1); // Calculate only when needed
            populate(node->right, r + 1, c + offset, height, res);
        }
    }
};