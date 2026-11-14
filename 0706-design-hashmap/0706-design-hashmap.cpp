class Node {
public:
    Node* next;
    int key, value;
    Node(int k, int v) {
        key = k;
        value = v;
        next = NULL;
    }
};
class MyHashMap {
public:
    Node* head;

    MyHashMap() {
        head = NULL;
    }

    void put(int key, int value) {
        Node* curr = head;
        while(curr != NULL) {
            if(curr->key == key) {
                curr->value = value;
                return;
            }
            curr = curr->next;
        }
        Node* temp = new Node(key, value);
        temp->next = head;
        head = temp;
    }

    int get(int key) {
        Node* curr = head;
        while(curr != NULL) {
            if(curr->key == key) {
                return curr->value;
            }
            curr = curr->next;
        }
        return -1;
    }

    void remove(int key) {
        if(head == NULL) return;

        if(head->key == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* curr = head;

        while(curr->next != NULL) {
            if(curr->next->key == key) {
                Node* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
                return;
            }
            curr = curr->next;
        }
    }
};