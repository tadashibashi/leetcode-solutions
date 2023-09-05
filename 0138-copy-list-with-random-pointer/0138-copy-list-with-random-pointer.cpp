/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        std::map<Node *, Node *>nodeMap;
        nodeMap[nullptr] = nullptr;

        auto n = head;
        while (n)
        {
            nodeMap[n] = new Node(n->val);
            n = n->next;
        }

        n = head;
        while (n)
        {
            auto copied = nodeMap[n];
            copied->next = nodeMap[n->next];
            copied->random = nodeMap[n->random];
            n = n->next;
        }

        return nodeMap[head];
    }
};