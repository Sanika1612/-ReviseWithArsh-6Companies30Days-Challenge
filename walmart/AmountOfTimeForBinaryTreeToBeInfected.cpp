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

//One pass solution
class Solution {
private:
    int maxDistance = 0;

public:
    int amountOfTime(TreeNode* root, int start) {
        traverse(root, start);
        return maxDistance;
    }

    int traverse(TreeNode* root, int start) {
        int depth = 0;
        if (root == nullptr) {
            return depth;
        }

        int leftDepth = traverse(root->left, start);
        int rightDepth = traverse(root->right, start);

        if (root->val == start) {
            maxDistance = max(leftDepth, rightDepth);
            depth = -1;
        } else if (leftDepth >= 0 && rightDepth >= 0) {
            depth = max(leftDepth, rightDepth) + 1;
        } else {
            int distance = abs(leftDepth) + abs(rightDepth);
            maxDistance = max(maxDistance, distance);
            depth = min(leftDepth, rightDepth) - 1;
        }

        return depth;
    }
};
