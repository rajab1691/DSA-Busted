/*
  1. Just traverse the array till the element to be inserted is less
  T.C-O(n)
*/

void insertSortedLL(Node* head,int val){

    Node* newNode=new Node(val);

    if(head==NULL or val<=head->data){
        newNode->next=head;
        head=newNode;
        return head;
    }

    Node* prev=NULL;
    Node* temp=head;

    while(temp and temp->data<=val){
        prev=temp;
        temp=temp->next;
    }

    newNode->next=prev->next;
    prev->next=newNode;
    return head;
}
