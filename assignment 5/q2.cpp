// Write a program to count the number of occurrences of a given key in a singly linked
// list and then delete all the occurrences. For example, if given linked list is 1->2->1-
// >2->1->3->1 and given key is 1, then output should be 4. After deletion of all the
// occurrences of 1, the linked list is 2->2->3
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() { head = nullptr; }

    // Insert at end (to build list easily)
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    // Count and delete all occurrences of key
    int countAndDelete(int key) {
        int count = 0;

        // Handle if head nodes contain the key
        while (head && head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
            count++;
        }

        // Traverse the rest of the list
        Node* temp = head;
        while (temp && temp->next) {
            if (temp->next->data == key) {
                Node* del = temp->next;
                temp->next = del->next;
                delete del;
                count++;
            } else {
                temp = temp->next;
            }
        }

        return count;
    }

    // Display the list
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;

    // Example input: 1->2->1->2->1->3->1
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(1);
    list.insertAtEnd(3);
    list.insertAtEnd(1);

    cout << "Original List: ";
    list.display();

    int key = 1;
    int count = list.countAndDelete(key);

    cout << "Number of occurrences of " << key << " = " << count << endl;
    cout << "List after deleting all occurrences of " << key << ": ";
    list.display();

    return 0;
}
