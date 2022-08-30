class Solution {
public:
    using N = TreeNode;
    int amountOfTime(N* root, int start) {
        int time = 0;    
        
        unordered_map<N*,N*> parent;
        markParent(root,parent);
        
        N* target = findNode(root,start);
        
        queue<N*> q;
        unordered_map<N*, bool> vis;       

        q.push(target);
        vis[target] = true;

        while(!q.empty())
        {
            int n = q.size();
            while(n--)
            {
                auto node = q.front();
                q.pop();
                vis[node] = true;

                if(node->left and !vis[node->left])
                {
                    q.push(node->left);
                    vis[node->left] = true;
                }

                if(node->right and !vis[node->right])
                {
                    q.push(node->right);
                    vis[node->right] = true;
                }

                if(parent[node] and !vis[parent[node]])
                {
                    q.push(parent[node]);
                    vis[parent[node]] = true;
                }
            }
            // Completed one level, so we increase time
            time++;
        }
        
        return time-1;
    }

    
    
private:
    N* findNode(N* node, int key) 
    {
        if(node)
        {
            if(node->val == key) return node;        
            else {
                N* foundNode = findNode(node->left,key);
                if(!foundNode) foundNode = findNode(node->right,key);              
                return foundNode;
             }
        } 
        else return NULL;

    }

    void markParent(N* root, unordered_map<N*, N*> &parent)
    {
        if(!root)return;

        if(root->left) parent[root->left] = root;     
        if(root->right) parent[root->right] = root;

        markParent(root->left,parent);
        markParent(root->right,parent);
    }
    
};