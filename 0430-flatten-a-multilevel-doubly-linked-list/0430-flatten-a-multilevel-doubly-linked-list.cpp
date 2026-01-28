/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head){
            return head;
        }
        flattenDFS(head);
        return head;
    }

    Node* flattenDFS(Node* head){
        Node* curr = head;
        Node* last = head;

        while(curr){
            Node* nextNode = curr->next;

            if(curr->child){
                Node* childHead = curr->child;
                Node* childTail = flattenDFS(childHead);

                curr->next = childHead;
                childHead->prev = curr;
                curr->child = nullptr;

                if(nextNode){
                    childTail->next = nextNode;
                    nextNode->prev = childTail;
                }

                last = childTail;
                curr = nextNode;
            }
            else{
                last = curr;
                curr = nextNode;
            }
        }
        return last;
    }
};