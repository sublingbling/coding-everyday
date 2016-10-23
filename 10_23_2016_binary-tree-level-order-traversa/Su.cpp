    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root==NULL) return result;
        vector<int> level;
        queue<TreeNode*> cont1;
        queue<TreeNode*> cont2;
        cont1.push(root);
        while(cont1.size() || cont2.size()){
            while(cont1.size()){
                root = cont1.front();
                cont1.pop();
                level.push_back(root->val);
                if(root->left) cont2.push(root->left);
                if(root->right) cont2.push(root->right);
                if(!cont1.size()) {
                    result.push_back(level);
                    level.clear();
                }
            }
            while(cont2.size()){
                root = cont2.front();
                cont2.pop();
                level.push_back(root->val);
                if(root->left) cont1.push(root->left);
                if(root->right) cont1.push(root->right);
                if(!cont2.size()) {
                    result.push_back(level);
                    level.clear();
                }
            }
        }
        
        return result;
    }
