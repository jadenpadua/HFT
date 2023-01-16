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
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;

        unordered_map<Node*,Node*> vis {};

        Node* first = new Node(node->val);
        vis[node] = first;

        queue<Node*> q;
        q.push(node);

        while(!q.empty()) {
            Node* popped = q.front(); q.pop();

            for(auto n: popped->neighbors) {
                if(vis.find(n) == vis.end()) {
                    vis[n] = new Node(n->val);
                    q.push(n);
                }
                vis[popped]->neighbors.push_back(vis[n]);
            }
        }
        return vis[node];
    }
};
