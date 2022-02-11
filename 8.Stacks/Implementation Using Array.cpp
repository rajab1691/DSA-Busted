class Stack{
    int *a;
    int arrSize;
    int top;
public:
    
    Stack(int n){
        a=new int[n];
        top=-1;
        arrSize=n;
    }

    int peek(){

        if(top<0){
            return -1;
        }
        return a[top];
    }
    bool push(int val){

        if(top>=(arrSize-1)){
            return false;
        }
        top++;
        a[top]=val;
        return true;
    }

    int pop(){

        if(top<0){
            return false;
        }
        int elem=a[top];
        top--;
        return elem;
    }

    bool isEmpty(){
        if(top<0)
            return true;
        return false;
    }

    int getSize(){
        return top+1;
    }
};


int32_t main() {

   Stack s1(9);

   for(int i=0;i<20;i++){
        s1.push(i+1);
   }

   cout<<s1.getSize()<<endl;

   s1.push(6);

   cout<<s1.getSize()<<endl;

   s1.pop();
   s1.pop();
   s1.pop();

   cout<<s1.getSize()<<endl;

}
    

