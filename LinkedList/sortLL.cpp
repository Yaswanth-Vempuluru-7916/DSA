#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node() : data(0), next(nullptr) {}
    Node(int data) : data(data), next(nullptr) {}
    Node(int data, Node* next) : data(data), next(next) {}
};

Node* solve(Node*& first, Node*& second) {
    Node* curr1 = first;
    Node* curr2 = second;
    Node* next1 = first->next;
    Node* next2 = curr2->next;

    while (next1 != nullptr && curr2 != nullptr) {
        if (curr2->data >= curr1->data && curr2->data <= next1->data) {
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;

            curr1 = curr2;
            curr2 = next2;
        } else {
            curr1 = next1;
            next1 = next1->next;
        }
    }

    if (next1 == nullptr && curr2 != nullptr) {
        curr1->next = curr2;
    }

    return first;
}

Node* mergeSort(Node* first, Node* second) {
    if (first == nullptr) {
        return second;
    }

    if (second == nullptr) {
        return first;
    }

    if (first->data <= second->data) {
        return solve(first, second);
    } else {
        return solve(second, first);
    }
}

Node* findMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head->next;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node* merge(Node*& head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    Node* middle = findMiddle(head);
    Node* left = head;
    Node* right = middle->next;
    middle->next = nullptr;
    merge(left);
    merge(right);
    return mergeSort(left, right);
}

Node* sortList(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    return merge(head);
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

int main() {
    Node* head = new Node(3);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    std::cout << "Original List: ";
    printList(head);

    head = sortList(head);

    std::cout << "Sorted List: ";
    printList(head);

    return 0;
}
