/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
private:
    unordered_map<int,UndirectedGraphNode*> traveled;    
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node==NULL) return NULL;
        if(traveled.find(node->label)!=traveled.end()) return traveled[node->label]; 
        UndirectedGraphNode* r = new UndirectedGraphNode(node->label);
        traveled.insert({node->label,r});
        for(auto a:node->neighbors) r->neighbors.push_back(cloneGraph(a));
        return r;
    }
};
