    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root==NULL) return result;
        vector<int> level;
        queue<TreeNode*> cont;
        cont.push(root);
        while(cont.size()){
            queue<TreeNode*> tmp;
            while(cont.size()){
                root = cont.front();
                cont.pop();
                level.push_back(root->val);
                if(root->left) tmp.push(root->left);
                if(root->right) tmp.push(root->right);
            }
            result.push_back(level);
            level.clear();
            cont=tmp;
        }
        
        return result;
    }
