#include<iostream>
#include<conio.h>
using namespace std;
class doublyLinkedList;
doublyLinkedList *node=NULL,*first=NULL;
class doublyLinkedList
{
private:
    doublyLinkedList *prev,*next;
    int data;
    static int count;
public:
    void enterValue(void);
    void traversing(void);
    void insertion(void);
    void deletion(void);
    void reversing(void);
};
int doublyLinkedList:: count=0;
void doublyLinkedList:: enterValue(void){
    if(count>0){
        cout<<"Data is already filled.\n\n";
        return;
    }
    cout<<"Enter how many data you want to enter:";
    int num;
    cin>>num;
    if(num<=0){
        cout<<"Enter correct number of data you want to enter.\n";
        return enterValue();
    }
    cout<<"Enter data:";
    doublyLinkedList *temp=NULL;
    for(int i=0;i<num;i++){
            node=new doublyLinkedList;
            node->next=NULL;
        if(i==0){
            temp=node;
            node->prev=NULL;
            first=node;
        }
        else{
            temp->next=node;
            node->prev=temp;
            temp=temp->next;
        }
        cin>>temp->data;
        count++;
    }
    cout<<endl;
}
void doublyLinkedList:: traversing(void){
    if(count==0){
        cout<<"First enter value to traverse.\n";
        return enterValue();
    }
    cout<<"Your data are:";
doublyLinkedList *temp=first;
    while(temp!=NULL){
        cout<<temp->data<<"\t";
        temp=temp->next;
    }
    cout<<"\n\n";
}
void doublyLinkedList:: insertion(void){
    if(count==0){
    cout<<"First enter value to traverse.\n";
    return enterValue();
    }
    cout<<"At which position you want to insert data:";
    int pos;
    cin>>pos;
    if(pos<1 || pos>count+1){
        cout<<"Enter correct position.\n";
        return insertion();
    }
    cout<<"Enter value to insert:";
    int val;
    cin>>val;
    doublyLinkedList *temp=first;
    node=new doublyLinkedList;
    if(pos==1){
        node->prev=NULL;
        node->next=temp;
        temp->prev=node;
        first=node;
    }
    else{
        for(int i=1;i<pos-1;i++){
            temp=temp->next;
        }
        if(pos==count+1){
            node->next=NULL;
            node->prev=temp;
            temp->next=node;
        }
        else{
            node->next=temp->next;
            node->prev=temp;
            node->next->prev=node;
            temp->next=node;
        }
    }
    node->data=val;
    count++;
    cout<<"\n\n";
}
void doublyLinkedList:: deletion(void){
    if(count==0){
        cout<<"First enter value to traverse.\n";
        return enterValue();
    }
    cout<<"Enter which position you want to delete:";
    int pos;
    cin>>pos;
    if(pos<1 || pos>count){
        cout<<"Enter correct position.\n";
        return deletion();
    }
    doublyLinkedList *temp=first;
    for(int i=1;i<pos;i++){
        temp=temp->next;
    }
    if(pos==1 && count==1){
        temp->next=NULL;
        temp->prev=NULL;
        first=NULL;
        node=NULL;
    }
    else if(pos==1){
        first=temp->next;
        first->prev=NULL;
    }
    else if(pos==count){
        temp->prev->next=NULL;
    }
    else{
        temp->next->prev=temp->prev;
        temp->prev->next=temp->next;
    }
    delete temp;
    count--;
}
void doublyLinkedList:: reversing(void){
    if(count==0){
        cout<<"First enter value to traverse.\n";
        return enterValue();
    }
    if(count==1){
        return;
    }
    doublyLinkedList *pr=NULL,*cu=NULL,*af=NULL;
    pr=cu=af=first;
    cu=pr->next;
    af=cu->next;
    while(af!=NULL){
        cu->next=pr;
        cu->prev=af;
        pr=cu;
        cu=af;
        af=af->next;
    }
    cu->next=pr;
    cu->prev=NULL;
    first->prev=first->next;
    first->next=NULL;
    first=cu;
}
int main(void){
bool looping=true;
    while(looping==true){
            int choice;
        doublyLinkedList op1;
        cout<<"Which operation you want to perform:-\n";
        cout<<"press 1 for inter value:-\n";
        cout<<"Press 2 for traversing:-\n";
        cout<<"Press 3 for insertion:-\n";
        cout<<"Press 4 for deletion:-\n";
        cout<<"Press 5 to reverse the data:-\n";
        cout<<"Press 6 to exit:-\n";
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
                op1.reversing();
                break;
            case 6:
                cout<<"Program ended.\n";
                looping=false;
                break;
            default:
                cout<<"Enter correct choice:-\n";
        }
    }
return 0;
}
