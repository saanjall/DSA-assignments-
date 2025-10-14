#include <iostream>
using namespace std;

// ========== DOUBLY LINKED LIST ==========
class DoublyList {
    struct Node {
        int data;
        Node* prev;
        Node* next;
    };
    Node* head;

public:
    DoublyList() : head(NULL) {}

    void insertAtBeginning(int value) {
        Node* newNode = new Node{value, NULL, head};
        if (head) head->prev = newNode;
        head = newNode;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node{value, NULL, NULL};
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    void insertAfter(int key, int value) {
        Node* temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) {
            cout << "Node not found!\n";
            return;
        }
        Node* newNode = new Node{value, temp, temp->next};
        if (temp->next) temp->next->prev = newNode;
        temp->next = newNode;
    }

    void insertBefore(int key, int value) {
        if (!head) return;
        if (head->data == key) {
            insertAtBeginning(value);
            return;
        }
        Node* temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) {
            cout << "Node not found!\n";
            return;
        }
        Node* newNode = new Node{value, temp->prev, temp};
        temp->prev->next = newNode;
        temp->prev = newNode;
    }

    void deleteNode(int key) {
        if (!head) return;
        Node* temp = head;

        // If head node is to be deleted
        if (temp->data == key) {
            head = temp->next;
            if (head) head->prev = NULL;
            delete temp;
            return;
        }

        while (temp && temp->data != key) temp = temp->next;
        if (!temp) {
            cout << "Node not found!\n";
            return;
        }

        if (temp->next) temp->next->prev = temp->prev;
        if (temp->prev) temp->prev->next = temp->next;
        delete temp;
    }

    void search(int key) {
        Node* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->data == key) {
                cout << "Node " << key << " found at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Node not found!\n";
    }

    void display() {
        Node* temp = head;
        cout << "Doubly Linked List: ";
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

// ========== CIRCULAR LINKED LIST ==========
class CircularList {
    struct Node {
        int data;
        Node* next;
    };
    Node* head;

public:
    CircularList() : head(NULL) {}

    void insertAtBeginning(int value) {
        Node* newNode = new Node{value, NULL};
        if (!head) {
            head = newNode;
            newNode->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head) temp = temp->next;
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node{value, NULL};
        if (!head) {
            head = newNode;
            newNode->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head) temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }

    void insertAfter(int key, int value) {
        Node* temp = head;
        if (!head) return;
        do {
            if (temp->data == key) {
                Node* newNode = new Node{value, temp->next};
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Node not found!\n";
    }

    void deleteNode(int key) {
        if (!head) return;
        Node *temp = head, *prev = NULL;

        // If head needs to be deleted
        if (head->data == key) {
            Node* last = head;
            while (last->next != head) last = last->next;
            if (head == head->next) {
                delete head;
                head = NULL;
                return;
            }
            last->next = head->next;
            delete head;
            head = last->next;
            return;
        }

        do {
            prev = temp;
            temp = temp->next;
        } while (temp != head && temp->data != key);

        if (temp->data != key) {
            cout << "Node not found!\n";
            return;
        }
        prev->next = temp->next;
        delete temp;
    }

    void search(int key) {
        if (!head) return;
        Node* temp = head;
        int pos = 1;
        do {
            if (temp->data == key) {
                cout << "Node " << key << " found at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        } while (temp != head);
        cout << "Node not found!\n";
    }

    void display() {
        if (!head) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = head;
        cout << "Circular Linked List: ";
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to head)\n";
    }
};

// ========== MAIN MENU ==========
int main() {
    DoublyList dlist;
    CircularList clist;
    int choice, listType, val, key;

    while (true) {
        cout << "\n--- MAIN MENU ---\n";
        cout << "1. Doubly Linked List\n";
        cout << "2. Circular Linked List\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> listType;
        if (listType == 3) break;

        cout << "1. Insert at Beginning\n2. Insert at End\n3. Insert After\n4. Insert Before\n";
        cout << "5. Delete Node\n6. Search Node\n7. Display\n8. Back to Main Menu\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (listType == 1) {
            switch (choice) {
                case 1: cout << "Enter value: "; cin >> val; dlist.insertAtBeginning(val); break;
                case 2: cout << "Enter value: "; cin >> val; dlist.insertAtEnd(val); break;
                case 3: cout << "Enter key and value: "; cin >> key >> val; dlist.insertAfter(key, val); break;
                case 4: cout << "Enter key and value: "; cin >> key >> val; dlist.insertBefore(key, val); break;
                case 5: cout << "Enter key to delete: "; cin >> key; dlist.deleteNode(key); break;
                case 6: cout << "Enter key to search: "; cin >> key; dlist.search(key); break;
                case 7: dlist.display(); break;
                default: continue;
