#include <iostream>
using namespace std;

class ListNode {
public:
    int data;
    ListNode* next;

    ListNode() : data(0), next(nullptr) {}
    ListNode(int value) : data(value), next(nullptr) {}
    ~ListNode() {}
};

class LinkedList {
private:
    ListNode* head;
    ListNode* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    ~LinkedList() {
        clear();
    }

    void insertAtHead(int value) {
        ListNode* newNode = new ListNode(value);
        newNode->next = head;
        head = newNode;
        if (tail == nullptr) {
            tail = head;
        }
    }

    void insertAtTail(int value) {
        ListNode* newNode = new ListNode(value);
        if (tail != nullptr) {
            tail->next = newNode;
        }
        tail = newNode;
        if (head == nullptr) {
            head = tail;
        }
    }

    void display() const {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
        ListNode* current = head;
        while (current != nullptr) {
            cout << current->data;
            if (current->next != nullptr) {
            cout << " <- ";
            }
            current = current->next;
        }
    }

    void search(int value) const {
        ListNode* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                cout << "Element " << value << " found in the list." << endl;
                return;
            }
            current = current->next;
        }
        cout << "Element " << value << " not found in the list." << endl;
    }

    int getHead() const {
        if (head != nullptr) {
            return head->data;
        } else {
            cout << "Error: List is empty" << endl;
            return -1;
        }
    }

    int getTail() const {
        if (tail != nullptr) {
            return tail->data;
        } else {
            cout << "Error: List is empty" << endl;
            return -1;
        }
    }

    void clear() {
        ListNode* current = head;
        while (current != nullptr) {
            ListNode* temp = current;
            current = current->next;
            delete temp;
        }
        head = tail = nullptr;
    }

    void moveElementFrom(int from, int position) {
    if (position <= 0) {
        cout << "Invalid position. Position must be greater than 0.\n";
        return;
    }

    if (head == nullptr) {
        cout << "List is empty. Nothing to move.\n";
        return;
    }

    int valueToMove;

    if (from == 1) {
        valueToMove = head->data;
        ListNode* temp = head;
        head = head->next;
        delete temp;

        if (head == nullptr) {
            tail = nullptr;
        }
    } else if (from == 2) {
        valueToMove = tail->data;

        if (head == tail) {
            delete tail;
            head = tail = nullptr;
        } else {
            ListNode* current = head;
            while (current->next != tail) {
                current = current->next;
            }
            delete tail;
            tail = current;
            tail->next = nullptr;
        }
    } else {
        cout << "Invalid choice. Choose 1 for head or 2 for tail.\n";
        return;
    }

    ListNode* newNode = new ListNode(valueToMove);

    if (position == 1) {
        newNode->next = head;
        head = newNode;
        if (tail == nullptr) {
            tail = head;
        }
    } else {
        ListNode* current = head;
        int currentPosition = 1;

        while (current != nullptr && currentPosition < position - 1) {
            current = current->next;
            currentPosition++;
        }

        if (current == nullptr) {
            cout << "Position exceeds the length of the list. Adding to the end.\n";
            tail->next = newNode;
            tail = newNode;
        } else {
            newNode->next = current->next;
            current->next = newNode;

            if (newNode->next == nullptr) {
                tail = newNode;
            }
        }
    }

    cout << "Element moved successfully.\n";
    display();
};
};

int lab_13() {
    int n1, n2, n3, n4, n5, choice;
    LinkedList list;

    cout << "Put your 5 numbers to create list\n";
    cin >> n1 >> n2 >> n3 >> n4 >> n5;

    list.insertAtHead(n1);
    list.insertAtHead(n2);
    list.insertAtHead(n3);
    list.insertAtHead(n4);
    list.insertAtHead(n5);

    do {
        cout << "\nWhat do you want to do now?\n";
        cout << "1. Search for a list item\n";
        cout << "2. Move element from head/tail at position\n";
        cout << "3. Show head and tail of the list\n";
        cout << "4. Show list\n";
        cout << "5. Clear list\n";
        cout << "6. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1: {
                int value;
                cout << "What number do you want to find?\n";
                cin >> value;
                list.search(value);
                break;
            }
            case 2: {
                int from, position;
                cout << "From where? (1 for head, 2 for tail)\n";
                cin >> from;
                cout << "At which position to insert?\n";
                cin >> position;
                list.moveElementFrom(from, position);
                break;
            }
            case 3: {
                cout << "Head of the list: " << list.getHead() << endl;
                cout << "Tail of the list: " << list.getTail() << endl;
                break;
            }
            case 4: {
                cout << "List: ";
                list.display();
                break;
            }
            case 5: {
                list.clear();
                cout << "List after clearing: ";
                list.display();
                break;
            }
            case 6: {
                cout << "Exiting...\n";
                break;
            }
            default: {
                cout << "Wrong option\n";
                break;
            }
        }
    } while (choice != 6);

    return 0;
}