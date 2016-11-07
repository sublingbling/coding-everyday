/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
    map<UndirectedGraphNode*, UndirectedGraphNode*> cloneHash;
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) {
            return NULL;
        }
        if (cloneHash.find(node) == cloneHash.end()) {
            UndirectedGraphNode* clone = new UndirectedGraphNode(node->label);
            cloneHash[node] = clone;
            for (auto neighbor : node->neighbors) {
                (clone->neighbors).push_back(cloneGraph(neighbor));
            }
        }
        return cloneHash[node];
    }
};
