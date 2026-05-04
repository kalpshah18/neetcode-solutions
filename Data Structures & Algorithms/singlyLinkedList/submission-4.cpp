class LinkedList {
    struct Node{
        int val;
        Node* next;
        Node(int v) : val(v), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int nodes;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
        nodes = 0;
    }

    int get(int index) {
        if(index < 0 || index >= nodes) return -1;

        Node* curr = head;
        while(index--){
            curr = curr->next;
        }
        return curr->val;
    }

    void insertHead(int val) {
        Node* n = new Node(val);
        n->next = head;
        head = n;

        if(nodes == 0) tail = n;
        nodes++;
    }
    
    void insertTail(int val) {
        Node* n = new Node(val);

        if(nodes == 0){
            head = tail = n;
        } else {
            tail->next = n;
            tail = n;
        }
        nodes++;
    }

    bool remove(int index) {
        if(index < 0 || index >= nodes) return false;

        Node* del;

        if(index == 0){
            del = head;
            head = head->next;
            if(nodes == 1) tail = nullptr;
        } else {
            Node* curr = head;
            for(int i = 0; i < index - 1; i++){
                curr = curr->next;
            }
            del = curr->next;
            curr->next = del->next;

            if(del == tail) tail = curr;
        }

        delete del;
        nodes--;
        return true;
    }

    vector<int> getValues() {
        vector<int> values;
        Node* curr = head;

        while(curr){
            values.push_back(curr->val);
            curr = curr->next;
        }
        return values;
    }
};