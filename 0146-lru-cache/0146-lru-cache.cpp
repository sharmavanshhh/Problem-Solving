class Node {
public:
    int key, value;
    Node* prev;
    Node* next;

    Node(int k, int v) {
        key = k;
        value = v;
        prev = next = NULL;
    }
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;
public:
    LRUCache(int cap) {
        capacity = cap;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void addNodeAtEnd(Node* node) {
        Node* prevNode = tail->prev;
        prevNode->next = node;
        node->prev = prevNode;
        node->next = tail;
        tail->prev = node;
    }

    int get(int key) {
        if (!mp.count(key)) return -1;

        Node* node = mp[key];
        removeNode(node);
        addNodeAtEnd(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if (mp.count(key)) {
            Node* existing = mp[key];
            removeNode(existing);
            mp.erase(key);
        }

        if (mp.size() == capacity) {
            Node* lru = head->next;
            removeNode(lru);
            mp.erase(lru->key);
        }

        Node* newNode = new Node(key, value);
        addNodeAtEnd(newNode);
        mp[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */