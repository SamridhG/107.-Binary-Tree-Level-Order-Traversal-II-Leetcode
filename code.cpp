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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>res;
        vector<int>A;
        queue<TreeNode *>B;
        if(root!=NULL)
        {
            B.push(root);
            while(!B.empty())
            {
                int size=B.size();
                for(int i=0;i<size;i++)
                {
                    TreeNode *temp=B.front();
                    B.pop();
                    A.push_back(temp->val);
                    if(temp->left)B.push(temp->left);
                    if(temp->right)B.push(temp->right);
                }
                res.push_back(A);
                A.clear();
            }
            reverse(res.begin(),res.end());
        }
        return res;
    }
};
