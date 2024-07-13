#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node(){
        int value = this->data;

        if(this->next!=nullptr){
            delete next;
            this->next = nullptr;
        }
    cout<<"memory is free for with data "<<value<<endl;
    }
};


void deleteNode(int position,Node *&head,Node* &tail){

    Node* temp = head;
    if(position==1){
        head = head->next;
        delete temp;
    }
    else{
        //delete any middle node
    }



}
void insertAtHead(Node *&head, int d)
{
    // new node

    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&tail, int d)
{

    // new node
    Node *temp = new Node(d);
    tail->next = temp;
    tail = tail->next;
}

void insertAtPosition(Node *&head,int pos,int data,Node *&tail){

    if(pos==1){
        insertAtHead(head,data);
    }
    Node* nodeToInsert = new Node(data);
    Node* temp = head;
    int count =1;


    while(count<pos-1){
        temp=temp->next;
        count++;
    }

    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;

    if(temp->next==NULL){
        insertAtTail(tail,data);
    }
}


void print(Node *&head)
{

    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{

    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;

    print(head);
    insertAtHead(head, 9);
    insertAtHead(head, 6);
    insertAtHead(head, 13);
    insertAtHead(head, 58);
    print(head);

    insertAtTail(tail,35);
    print(head);

    insertAtPosition(head,1,25,tail);
    print(head);
    insertAtPosition(head,9,195,tail);
    print(head);

    cout<<"head"<<head->data<<endl;
    cout<<"tail"<<tail->data<<endl;

    return 0;
}