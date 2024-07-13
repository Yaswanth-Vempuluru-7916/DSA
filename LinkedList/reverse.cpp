#include<iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }

    ~Node(){
        int value = this->data;
        if(this->next=NULL){
            delete next;
            this->next=NULL;

        }

        cout<<"Memory is free with the data "<<value<<endl;
    }
};

void insertAtHead(Node *&head, int d)
{
    // new node

    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void print(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;

}

Node* reverse(Node*& head){
    //base case
    if(head==NULL || head->next == NULL){
        return head;
    }
    
    Node* chotiHead = reverse(head->next);
    

    head->next->next=head;
    head->next=NULL;

    return chotiHead;
}



int main(){

    Node* head=new Node(1);

    insertAtHead(head,2);
    insertAtHead(head,3);
    insertAtHead(head,4);
    insertAtHead(head,5);

    print(head);

    Node* rHead = reverse(head);

    cout<<"After reverse"<<endl;
    print(rHead);

return 0;

}