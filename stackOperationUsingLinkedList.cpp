#include<iostream>
#include<conio.h>
using namespace std;
class stackLinkedList;
stackLinkedList *newnode=NULL,*head=NULL;
class stackLinkedList
{
private:
    int data;
    stackLinkedList *next;
    static int value;
    static int siz;
public:
    void maxValue(void){
        cout<<"Enter maximum value you want to enter:";
        cin>>value;
        if(value<1){
            cout<<"Enter correct value.\n\n";
            maxValue();
        }
    }
    void push(void);
    void pop(void);
    void peek(void);
    bool isEmpty(void);
    bool isFull(void);
    void display(void);

};
int stackLinkedList:: siz=0;
int stackLinkedList:: value=0;
void stackLinkedList:: push(void){
        if(isFull()){
            cout<<"Stack is already full.\n\n";
            return;
        }
        cout<<"Enter value:";
        int da;
        cin>>da;
        newnode=new stackLinkedList;
        newnode->data=da;
        newnode->next=head;
        head=newnode;
        siz++;
    }
    void stackLinkedList:: pop(void){
        if(isEmpty()){
            cout<<"Stack is empty.\n\n";
            return;
        }
        stackLinkedList *temp=head;
            head=temp->next;
            delete temp;
            siz--;
    }
    void stackLinkedList:: peek(void){
        if(isEmpty()){
            cout<<"Stack is empty.\n\n";
            return;
        }
        cout<<head->data<<"\n\n";
    }
    bool stackLinkedList:: isEmpty(void){
        if(siz==0){
            return true;
        }
        return false;
    }
    bool stackLinkedList:: isFull(void){
        if(siz==value){
            return true;
        }
        return false;
    }
    void stackLinkedList:: display(void){
        if(isEmpty()){
            cout<<"Stack is empty.\n\n";
            return;
        }
        stackLinkedList *temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"\t";
            temp=temp->next;
        }
        cout<<endl;
    }

int main(void){
int option;
stackLinkedList op1;
bool repeat=true;
op1.maxValue();
    while(repeat){
        cout<<"Press 1 to push operation.\n";
        cout<<"Press 2 to pop operation.\n";
        cout<<"Press 3 to peek operation.\n";
        cout<<"Press 4 to check where the stack is empty or not.\n";
        cout<<"Press 5 to check where the stack is full or not.\n";
        cout<<"Press 6 to display the data.\n";
        cout<<"Press 7 to exit.\n";
        cout<<"Enter your choice:-............\n";
        cin>>option;
        switch(option){
            case 1:
                op1.push();
                break;
            case 2:
                op1.pop();
                break;
            case 3:
                op1.peek();
                break;
            case 4:
                if(op1.isEmpty()){
                    cout<<"Stack is empty.\n\n";
                }
                else{
                    cout<<"Stack is not empty.\n\n";
                }
                break;
            case 5:
                if(op1.isFull()){
                    cout<<"Stack is Full.\n\n";
                }
                else{
                    cout<<"Stack is not full.\n\n";
                }
                break;
            case 6:
                op1.display();
                break;
            case 7:
                repeat=false;
                break;
            default:
                cout<<"Enter correct choice.\n\n";
        }
    }
return 0;
}
