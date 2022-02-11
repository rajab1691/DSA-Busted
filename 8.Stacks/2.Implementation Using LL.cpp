
struct Node{

    int data;
    Node *next;
    Node(int val){
        data=val;
        next=NULL;
    }
};

class Stack{
    Node* head;
public:
    Stack(){
        head=NULL;
    }
    //insert at head
    void push(int val){
        Node* temp=new Node(val);
        if(temp==NULL){
            cout<<"HEAP OVERFLOW"<<endl;
            exit(0);
        }
        temp->next=head;
        head=temp;
    }
    void pop(){
        if(head==NULL){
            cout<<"HEAP UNDERFLOW"<<endl;
            exit(0);
        }
        Node* temp=head;
        head=head->next;
        delete temp;
    }

    int peek(){
        if(head==NULL)
            return -1;
        return head->data;
    }

    int isEmpty(){
        return (head==NULL);
    }

};
int32_t main() {

    Stack s1;

    fo(i,10){
        s1.push(i+1);
    }

    while(s1.isEmpty()==false){
        cout<<s1.peek()<<endl;
        s1.pop();
    }
    
}
    
