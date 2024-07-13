#include <bits/stdc++.h> 
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
        };


Node* addNodes(Node* head, int n, int m) {
   Node* trav =head;
   Node* temp =head;
   Node* prev =head;
   while(trav!=nullptr){
	   
   int k=m;
   int sum=0;

   while(k&& temp!=nullptr){
	   temp = temp->next;
	   k--;
   }

   Node* curr = temp;
   while(n&&curr!=nullptr){
	   sum+=curr->data;
	   prev = curr;
	   curr = curr->next;
   }
	Node* newNode = new Node(sum);
	prev->next = newNode;
	newNode->next = curr;

	trav = curr;
   }
}