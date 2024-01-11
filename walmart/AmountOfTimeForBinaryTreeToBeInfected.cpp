class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;
    //Don't forget to keep track of visited nodes
    void dfs(TreeNode* root) {
        if (!root) return;
        if (root->right) {
            parent[root->right] = root;
            dfs(root->right);
        }
        if (root->left) {
            parent[root->left] = root;
            dfs(root->left);
        }
    }

    TreeNode* search(TreeNode* root, int start) {
        if (root == NULL) return NULL;
        if (root->val == start) return root;
        TreeNode* leftResult = search(root->left, start);
        return leftResult ? leftResult : search(root->right, start);
    }

    int amountOfTime(TreeNode* root, int start) {
        if (!root->left && !root->right) return 0;
        int ans = 0;
        queue<TreeNode*> q;
        TreeNode* strt = search(root, start);
        q.push(strt);
        cout<<strt->val;
        parent[root] = NULL;
        dfs(root);
        unordered_map<TreeNode*, int>vis;
        vis[strt]=1;

        while (!q.empty()) {
            int s = q.size();
            bool change=false;
            for (int i = 0; i < s; i++) {
                TreeNode* temp = q.front();
                q.pop();
                if (parent[temp] && vis[parent[temp]]!=1)
                    { q.push(parent[temp]);
                      vis[parent[temp]]=1;
                      change=true;

                    }
                if (temp->left && vis[temp->left]!=1){
                    vis[temp->left]=1;
                     q.push(temp->left);
                     change=true;
                }
                   
                if (temp->right && vis[temp->right]!=1){
                    vis[temp->right]=1;
                    q.push(temp->right);
                    change=true;
                }
                    
            }
            if(change)
            ans++;
        }
        return ans;
    }
};
