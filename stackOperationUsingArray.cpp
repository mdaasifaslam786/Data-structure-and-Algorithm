#include<iostream>
#include<conio.h>
using namespace std;
int siz;
class stackOperation
{
private:
    static int top;
    int *stack;
public:
    void stackMaxSize(void);
    void push(void);
    void pop(void);
    bool isEmpty(void);
    bool isFull(void);
    void display(void);
    void topElement(void);
};
int stackOperation:: top=-1;
void stackOperation:: stackMaxSize(void){
    cout<<"Enter Maximum size of the stack:";
    cin>>siz;
    stack=new int[siz];
}
void stackOperation:: push(void){
    if(isFull()){
        cout<<"Stack is already full.\n\n";
        return;
    }
    top++;
    cout<<"Enter data:";
    cin>>stack[top];
}
void stackOperation:: pop(void){
    if(isEmpty()){
        cout<<"Stack is not Empty.\n\n";
        return;
    }
    cout<<" value "<<stack[top]<<" popped out.\n\n";
    top--;
}
bool stackOperation:: isEmpty(void){
    if(top==-1){
        return true;
    }
return false;
}
bool stackOperation:: isFull(void){
    if(top==siz-1){
        return true;
    }
return false;
}
void stackOperation:: display(void){
    if(isEmpty()){
        cout<<"Value is empty.\n\n";
        return;
    }
    else{
        for(int a=0;a<=top;a++){
            cout<<stack[a]<<"\t";
        }
    }
    cout<<endl;;
}
void stackOperation:: topElement(void){
    if(isEmpty()){
        cout<<"Stack is empty.\n\n";
        return;
    }
    cout<<"Peek value is: "<<stack[top]<<"\n\n";
}

int main(void){
stackOperation op1;
    op1.stackMaxSize();
int choice;
bool con=true;
    while(con){
        cout<<"Enter your choice:-\n";
        cout<<"Press 1 for push operation.\n";
        cout<<"Press 2 for pop operation.\n";
        cout<<"Press 3 to check whether the stack is empty or not.\n";
        cout<<"Press 4 to check whether the stack is full or not.\n";
        cout<<"Press 5 to display value:-\n";
        cout<<"Press 6 to display peek value:-\n";
        cout<<"press 7 to exit.\n";
        cin>>choice;
        bool emp,ful;
        switch(choice){
            case 1:
                op1.push();
                break;
            case 2:
                op1.pop();
                break;
            case 3:
                emp=op1.isEmpty();
                if(emp){
                    cout<<"Stack is Empty.\n\n";
                }
                else{
                    cout<<"Stack is not empty.\n\n";
                }
                break;
            case 4:
                ful=op1.isFull();
                if(ful){
                    cout<<"Stack is Full.\n\n";
                }
                else{
                    cout<<"Stack is not full.\n\n";
                }
                break;
            case 5:
                op1.display();
                break;
            case 6:
                op1.topElement();
                break;
            case 7:
                con=false;
                break;
            default:
                cout<<"Enter correct choice.\n\n";
        }
    }
return 0;
}
