struct Node{
    int data;
    Node* next;
    Node(int x){
        data=x;
        next=NULL;
    }
};

class MyLinkedList {
    Node* head;
    Node* tail;
    int length;
    
public:
    MyLinkedList() {
        head=NULL;
        tail=NULL;
        length=0;
    }
    
    int get(int index) {
        
        Node* temp=head;
        
        if(length<=index)
            return -1;
        
        for(int i=0;i<index;i++){
            temp=temp->next;
        }   
        return temp->data;
    }
    
    void addAtHead(int val) {
        
        Node* temp=new Node(val);
        
        temp->next=head;
        head=temp;
        length++;
        if(length==1){
            tail=head;
        }
    }
    
    void addAtTail(int val) {
        
        Node* temp=new Node(val);
        if(tail!=NULL)
             tail->next=temp;
        
        tail=temp;
        length++;
        if(length==1){
            head=tail;
        }
    }
    
    void addAtIndex(int index, int val) {
        if(index>length){
            return;
        }
        if(index==0){
            addAtHead(val);
            return;
        }
        if(index==length){
            addAtTail(val);
            return;
        }
        
        Node* prev=head;
        Node* newNode=new Node(val);
        
        for(int i=0;i<index-1;i++){
            prev=prev->next;
        }
        newNode->next=prev->next;
        prev->next=newNode;
        length++;
    }
    
    void deleteAtIndex(int index) {
        if(index>=length){
            return;
        }
        Node* temp=head;
        
        if(index==0){
            head=head->next;
            delete temp;
            length--;
            return;
        }
   
        for(int i=0;i<index-1;i++){
            temp=temp->next;
        }
        Node* q=temp->next;
        temp->next=q->next;
        
        if(tail==q){
            tail=temp;
        }
        delete q;
        length--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
