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
    unordered_map<UndirectedGraphNode*,UndirectedGraphNode*> traveled;    
public:
    // use a queue to travel the graph
    // use a map from old grpah to new graph, avoid duplicated copy.
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node==NULL) return NULL;
        queue<UndirectedGraphNode*> q;
        q.push(node);
        UndirectedGraphNode* new_node = new UndirectedGraphNode(node->label);
        traveled.insert({node,new_node});
        
        while(!q.empty()){
            UndirectedGraphNode* r = q.front();
            q.pop();
            for(auto a:r->neighbors){
              if(traveled.find(a)==traveled.end()){  //new node
                UndirectedGraphNode* new_a = new UndirectedGraphNode(a->label);
                traveled[r]->neighbors.push_back(new_a);
                traveled.insert({a,new_a});
                q.push(a);
              }
              else traveled[r]->neighbors.push_back(traveled[a]); //traveled node
            }
        }
        return new_node;
    }
};
