/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    unordered_map<Node*, Node*> visited;
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL)
            return node;
        if(visited[node])
            return visited[node];
        
        Node* cloned = new Node(node->val);
        visited[node] = cloned;
        
        for(auto nei: node->neighbors){
            cloned->neighbors.push_back(cloneGraph(nei));
        }
        return cloned;
        
    }
};
/*Steps for BFS are almost same. Most of the things are relatable if you have studied trees level order traversal.

So instead of the stack here, we use queue to process the nodes and their neighbours.
variable curr serves as the present root. We iterate over its children in the same way.
Inside the neigbour loop, if the neighbour is not visited, we do two things

Clone the neighbour and Put the entry of <neighbour, clonedNeighbour> into visited hashmap.
push the neighbour into queue. This is to process the children of the neighbours children in future iterations over queue.
We fill the neigbours vector/list in the same way.
BFS Solution*/

/*

Node* cloneGraph(Node* node){
        if(node == NULL)
            return node;
        unordered_map<Node*, Node*> visited;
        queue<Node*> Q;
        Q.push(node);
        visited[node] = new Node(node->val);
        while(!Q.empty()){
            int n = Q.size();
            Node* curr = Q.front();
            Q.pop();
            for(auto nei: curr->neighbors){
                if(!visited[nei]){
                     visited[nei] = new Node(nei->val);
                     Q.push(nei);
                }
                visited[curr]->neighbors.push_back(visited[nei]);
            }
        }
        return visited[node];

    }*/
