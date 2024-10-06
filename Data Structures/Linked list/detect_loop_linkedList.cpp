#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to push a new node onto the linked list
void push(Node** head_ref, int new_data) {
    Node* new_node = new Node;
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Function to detect a loop in the linked list
bool detectLoop(Node* head) {
    if (head == nullptr) return false;

    Node* slow = head;   // Tortoise
    Node* fast = head;   // Hare

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;           // Move slow pointer by 1
        fast = fast->next->next;     // Move fast pointer by 2

        // If they meet at some point, then there is a loop
        if (slow == fast) {
            return true;
        }
    }
    return false; // No loop found
}

int main() {
    Node* head = nullptr;

    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 10);

    // Creating a loop for testing
    head->next->next->next->next = head;

    if (detectLoop(head))
        cout << "Loop found";
    else
        cout << "No Loop";

    return 0;
}
