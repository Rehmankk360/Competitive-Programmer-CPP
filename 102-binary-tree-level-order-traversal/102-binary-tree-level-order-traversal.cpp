class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>vt;
        if(root==NULL)
            return vt;
        queue<TreeNode*>pendingnodes;
        pendingnodes.push(root);
        
        while(pendingnodes.size()!=0){
            int qlen = pendingnodes.size();
            vector<int> row;
            for(int i=0;i<qlen;i++){
            TreeNode* front=pendingnodes.front();
            pendingnodes.pop();
            row.push_back(front->val);
            
            if(front->left!=NULL)
                pendingnodes.push(front->left);
            if(front->right!=NULL)
                pendingnodes.push(front->right);
            }
            vt.push_back(row);
        }
       return vt; 
    }
};