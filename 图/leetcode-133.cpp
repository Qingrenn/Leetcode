class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr)    return nullptr;

        Node* total_nodes[110] = {nullptr};
        Node* root = dfsClone(node, total_nodes);
        return root;
    }

    Node* dfsClone(Node* node, Node* total_nodes[]) {
        
        if ( total_nodes[node->val] != nullptr ) 
            return total_nodes[node->val];
        
        Node* cur = new Node(node->val);
        total_nodes[node->val] = cur;    

        for (int i = 0; i < node->neighbors.size(); i++) 
            cur->neighbors.push_back( dfsClone(node->neighbors[i], total_nodes) );

        return cur;
    }

};