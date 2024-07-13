#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->next = nullptr;
    }
    Node(int data)
    {
        this->next = nullptr;
        this->data = data;
    }

    ~Node()
    {
        int value = this->data;
    }
};

void insertAtTail(Node *&tail, int data)
{
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

void print(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node *findMiddle(Node *&head)
{

    Node *slow = head;
    Node *fast = head->next;

    while (fast != nullptr)
    {
        fast = fast->next;
        if (fast != nullptr)
        {
            fast = fast->next;
        }
        slow = slow->next;
    }
    return slow;
}

int findLength(Node *head)
{
    int len = 0;
    while (head != nullptr)
    {
        head = head->next;
        len++;
    }

    return len;
}

Node *reverse(Node *&head)
{

    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node *chotiHead = reverse(head->next);
    head->next->next = head;
    head->next = nullptr;

    return chotiHead;
}

bool Palindrome(Node *temp1, Node *temp2)
{
    while (temp2 != nullptr)
    {
        if (temp1->data != temp2->data)
        {
            return false;
        }
        temp2 = temp2->next;
        temp1 = temp1->next;
    }
    return true;
}
int main()
{

    Node *node1 = new Node(-1);
    Node *head = node1;
    Node *tail = node1;
    Node *newHead = nullptr;
    insertAtTail(tail, -2);
    insertAtTail(tail,0);
    insertAtTail(tail, -3);
    insertAtTail(tail, -1);

    print(head);
    int len = findLength(head);
    cout << "length " << len << endl;
    Node *middle = findMiddle(head);
    cout << middle->data << endl;
    if (len % 2 == 0)
    {
        newHead = reverse(middle);
    }
    else
    {
        newHead = reverse(middle->next);
    }

    print(newHead);
    print(head);

    if(Palindrome(head,newHead)){
        cout<<"Palindrome"<<endl;
    }else{
        cout<<"Not a Palindrome"<<endl;

    }

    return 0;
}