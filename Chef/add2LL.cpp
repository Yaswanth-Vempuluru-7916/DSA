#include<iostream>
using namespace std;
  class Node {
  public:
       int data;
       Node *next;
       Node() {
           this->data = 0;
           this->next = nullptr;
       }
       Node(int data) {
           this->data = data;
           this->next = nullptr;
       }
       Node (int data, Node *next) {
           this->data = data;
           this->next = next;
       }
  };
 

Node *add(Node *&head1, Node *&head2)
{
    int carry = 0, sum = 0, val1 = 0, val2 = 0, val = 0;

    Node *temp1 = head1;
    Node *prev = head1;
    Node *temp2 = head2;

    while (temp1 != nullptr && temp2 != nullptr)
    {
        val1 = temp1->data;
        val2 = temp2->data;
        val = val1 + val2 + carry;
        sum = val % 10;
        carry = val / 10;

        temp1->data = sum;
        prev = temp1;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    while (!temp1)
    {
        val1 = temp1->data;
        val = val1 + carry;
        sum = val % 10;
        carry = val / 10;
        temp1->data = sum;
        prev = temp1;
        temp1 = temp1->next;
    }

    if (carry)
    {
        Node *newNode = new Node(carry);
        prev->next = newNode;
    }

    return head1;
}
int findlength(Node *num)
{
    int l = 0;
    Node *temp = num;
    while (temp != nullptr)
    {
        l++;
        temp = temp->next;
    }

    return l;
}

Node *reverse(Node *&head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node *choti = reverse(head->next);
    head->next->next = head;
    head->next = nullptr;
    return choti;
}
Node *addTwoNumbers(Node *num1, Node *num2)
{
    if (num1 == nullptr)
    {
        return num2;
    }
    if (num2 == nullptr)
    {
        return num1;
    }

    int len1 = findlength(num1);
    int len2 = findlength(num2);

    Node *newh1 = reverse(num1);
    Node *newh2 = reverse(num2);

    Node *res = nullptr;
    if (len1 > len2)
    {
        res = add(newh1, newh2);
    }
    else
    {
        res = add(newh2, newh1);
    }

    return reverse(res);
}
int main(){
    
}