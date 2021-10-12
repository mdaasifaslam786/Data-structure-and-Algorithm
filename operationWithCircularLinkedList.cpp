#include<iostream>
#include<conio.h>
using namespace std;
class circularLinkedList *node=NULL,*head=NULL;
class circularLinkedList
{
private:
    int data;
    circularLinkedList *next;
    static int count;
public:
    void enterValue(void);
    void traversing(void);
    void insertion(void);
    void deletion(void);
};
int circularLinkedList:: count=0;

void circularLinkedList:: enterValue(void){
    if(count!=0){
        cout<<"Data already exist.\n";
        return;
    }
    cout<<"Enter number of data you want to enter:";
    int num;
    cin>>num;
    if(num<1){
        cout<<"Enter correct number.\n";
        return enterValue();
    }
    cout<<"Enter value:";
    circularLinkedList *temp=NULL;
    for(int i=0;i<num;i++){
            int value;
            cin>>value;
        node=new circularLinkedList;
        if(head==NULL){
            temp=head=node;
        }
        else{
            temp->next=node;
            temp=temp->next;
        }
        temp->next=NULL;
            temp->data=value;
            count++;
        if(i==num-1){
            temp->next=head;
        }

    }
}

void circularLinkedList:: traversing(void){
    if(count==0){
        cout<<"There is no data, first store data.\n";
        return;
    }
    circularLinkedList *temp=head;
    while(temp->next!=head){
        cout<<temp->data<<"\t";
        temp=temp->next;
    }
    cout<<temp->data<<"\n\n";
}
void circularLinkedList:: insertion(void){
    if(count==0){
        cout<<"There is no data, first store data.\n";
        return;
    }
    cout<<"At which position you want to insert data:";
    int pos;
    cin>>pos;
    if(pos>=1 && pos<=count+1){
            cout<<"Enter data:";
            int val;
            cin>>val;
            node=new circularLinkedList;
            node->data=val;
            circularLinkedList *temp=head;
        if(pos==1){
            node->next=head;
            while(temp->next!=head){
                temp=temp->next;
            }
            temp->next=node;
            head=node;
        }
        else{
            for(int i=1;i<pos-1;i++){
                temp=temp->next;
            }
            if(temp->next==head){
                temp->next=node;
                node->next=head;
            }
            else{
                node->next=temp->next;
                temp->next=node;
            }
        }
        count++;
    }
    else{
        cout<<"Enter correct position.\n";
        return insertion();
    }
}
void circularLinkedList:: deletion(void){
    if(count==0){
        cout<<"There is no data, first store data.\n";
        return;
    }
    cout<<"Enter which position's data you want to delete:";
    int pos;
    cin>>pos;
    if(pos<1 || pos >count){
        cout<<"Enter correct position.\n";
        return deletion();
    }
    else{
        circularLinkedList *temp=head;
        if(pos==1){
            circularLinkedList *temp2=head;
            while(temp2->next!=head){
                temp2=temp2->next;
            }
            head=head->next;
            temp2->next=head;
            delete temp;
        }
        else{
            for(int i=1;i<pos-1;i++){
                temp=temp->next;
            }
            circularLinkedList *temp2=temp->next;
            temp->next=temp2->next;
            delete temp2;
        }
        count--;
        if(count==0){
            head=NULL;
        }
    }
}
int main(void){
    while(true){
        int choice;
        circularLinkedList op1;
        cout<<"Which operation you want to perform:-\n";
        cout<<"press 1 for inter value:-\n";
        cout<<"Press 2 for traversing:-\n";
        cout<<"Press 3 for insertion:-\n";
        cout<<"Press 4 for deletion:-\n";
        cout<<"Press 5 for exit:-\n";
        cout<<"Enter your choice:";
        cin>>choice;
        switch(choice){

            case 1:
                op1.enterValue();
                break;
            case 2:
                op1.traversing();
                break;
            case 3:
                op1.insertion();
                break;
            case 4:
                op1.deletion();
                break;
            case 5:
                return 0;
                break;
            default:
                cout<<"Enter correct choice:-\n";
        }
    }
return 0;
}
