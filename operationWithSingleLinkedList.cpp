#include<conio.h>
#include<stdio.h>
#include<iostream>
using namespace std;
class operationWithlinkedList;
    operationWithlinkedList *newNode=NULL,*nodeOne=NULL,*lastNode=NULL;
class operationWithlinkedList
{
private:
    int data;
    operationWithlinkedList *nextNode;
    static int count;
public:
    void enterValue(void);
    void traversing(void);
    void insertion(void);
    void deletion(void);
};
int operationWithlinkedList:: count=0;
void operationWithlinkedList:: enterValue(void){
    cout<<"Enter number of data you want to enter:";
    int num;
    cin>>num;
    if(num<1){
        cout<<"Enter correct number.\n\n";
        return enterValue();
    }
    cout<<"Enter data:";
    operationWithlinkedList *temp=NULL;
    for(int i=0;i<num;i++){
        if(i==0){
            newNode=new operationWithlinkedList;
            temp=nodeOne=newNode;
        }
        else{
            newNode=new operationWithlinkedList;
            temp->nextNode=newNode;
            temp=temp->nextNode;
        }
        cin>>temp->data;
        count++;
        temp->nextNode=NULL;
        lastNode=temp;
    }
}

void operationWithlinkedList:: traversing(void){
    if(count==0){
        cout<<"No value found, enter value first.\n\n";
        return;
    }
    operationWithlinkedList *temp=nodeOne;
    cout<<"Your entered values are:";
    while(temp!=NULL){
        cout<<temp->data<<"\t";
        temp=temp->nextNode;
    }
    cout<<"\n";
}

void operationWithlinkedList:: insertion(void){
    if(count==0){
        cout<<"No value found, enter value first.\n\n";
        return;
    }

    cout<<"Enter at which position you want to insert:";
    int pos;
    cin>>pos;
    if(pos>0 && pos<=count+1){
                cout<<"Enter  data:";
        int val;
        cin>>val;
        operationWithlinkedList *temp=nodeOne;
        if(pos==1){
            newNode=new operationWithlinkedList;
            newNode->nextNode=temp;
            newNode->data=val;
            nodeOne=newNode;
            count++;
        }
        else if(pos==count+1){
            newNode=new operationWithlinkedList;
            lastNode->nextNode=newNode;
            newNode->data=val;
            newNode->nextNode=NULL;
            lastNode=newNode;
            count++;
        }
        else{
            for(int i=1;i<pos-1;i++){
                temp=temp->nextNode;
            }
            newNode=new operationWithlinkedList;
            newNode->data=val;
            newNode->nextNode=temp->nextNode;
            temp->nextNode=newNode;
            count++;
        }

    }
    else{
        cout<<"Enter correct position.\n";
        return insertion();
    }
}

void operationWithlinkedList:: deletion(void){
    if(count==0){
        cout<<"No value found, enter value first.\n\n";
        return;
    }
    cout<<"Enter which number of data you want to delete:";
    int num;
    cin>>num;
    if(num>0 && num<=count){
        operationWithlinkedList *temp=nodeOne;
        if(num==1){
            nodeOne=temp->nextNode;
            delete temp;
            count--;
        }
        else{
            for(int i=0;i<num-2;i++){
                temp=temp->nextNode;
            }
            if(num==count){
                lastNode=temp;
                temp=temp->nextNode;
                delete temp;
                lastNode->nextNode=NULL;
                --count;
            }
            else{
                operationWithlinkedList *temp2=temp->nextNode;
                temp->nextNode=temp2->nextNode;
                delete temp2;
                --count;
            }
        }
    }
    else{
        cout<<"Enter correct number of data you want to delete.\n";
        return deletion();
    }
}
int main(void){
    while(true){
        int choice;
        operationWithlinkedList op1;
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
            default:
                cout<<"Enter correct choice:-\n";
        }
    }
return 0;
}

