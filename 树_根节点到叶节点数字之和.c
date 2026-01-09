/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sumNumbers(struct TreeNode* root) {

    int sum = 0;

    if (root == NULL) {
        return 0;
    }

    if (root->left != NULL) {
        root->left->val += root->val * 10;
        sum += sumNumbers(root->left);
    }

    if (root->right != NULL) {
        root->right->val += root->val * 10;
        sum += sumNumbers(root->right);
    }

    if (root->right == NULL && root->left == NULL) {
        return root->val;
    }

    return sum;
}

/////////////////////////////////////////////////////

/*

int recur(struct TreeNode* root, int sum) {

    if (root == NULL) {
        return 0;
    }

    sum = sum * 10 + root->val;

    if (root->left == NULL && root->right == NULL) {
        return sum;
    }

    return recur(root->left, sum) + recur(root->right, sum);
}

int sumNumbers(struct TreeNode* root) { return recur(root, 0); }

*/
