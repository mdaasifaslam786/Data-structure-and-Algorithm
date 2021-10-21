#include<iostream>
#include<conio.h>
#include<stdio.h>
using namespace std;
class doublyCircularLinkedList *head=NULL,*node=NULL,*tail=NULL;
class doublyCircularLinkedList
{
private:
    doublyCircularLinkedList *prev,*next;
    int data;
    static int count;
public:
    void enterValue(void)
    {
        if(count>0){
            cout<<"Value already exist.\n\n";
            return;
        }
        cout<<"Enter number of data you  want to enter:";
        int num;
        cin>>num;
        if(num<1){
            cout<<"Enter correct number.\n";
            return enterValue();
        }
        doublyCircularLinkedList *temp=NULL;
        cout<<"Enter value:";
        for(int i=1;i<=num;i++){
            int value;
            cin>>value;
            node=new doublyCircularLinkedList;
            node->next=NULL;
            node->prev=NULL;
            if(i==1){
                head=temp=node;
            }
            else{
                temp->next=node;
                node->prev=temp;
                temp=temp->next;
            }
            node->data=value;
            tail=temp;
            tail->next=head;
            head->prev=tail;
            count++;
        }
    }
    void traversing(void){
        if(count==0){
                head=NULL;
                tail=NULL;
            cout<<"Enter value first.\n";
            return enterValue();
        }
        doublyCircularLinkedList *temp=head;
        while(temp->next!=head){
            cout<<temp->data<<"\t";
            temp=temp->next;
        }
        cout<<temp->data<<"\n";
    }
    void insertion(void){
        if(count==0){
                head=NULL;
                tail=NULL;
            cout<<"Enter value first.\n";
            return enterValue();
        }
        cout<<"Enter at which position you want to insert:";
        int pos;
        cin>>pos;
        if(pos>0 && pos<=count+1){
            cout<<"Enter value:";
            int value;
            cin>>value;
            node=new doublyCircularLinkedList;
            node->data=value;
            node->next=NULL;
            node->prev=NULL;
            doublyCircularLinkedList *temp=head;
            if(pos==1){
                node->next=temp;
                temp->prev=node;
                head=node;
                head->prev=tail;
                tail->next=head;
            }
            else{
                for(int i=1;i<pos-1;i++){
                    temp=temp->next;
                }
                node->prev=temp;
                if(pos==count+1){
                    temp->next=node;
                    node->next=head;
                    tail=node;
                }
                else{
                    node->next=temp->next;
                    temp->next->prev=node;
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
    void deletion(void){
        if(count==0){
                head=NULL;
                tail=NULL;
            cout<<"Enter value first.\n";
            return enterValue();
        }
        cout<<"Enter which position's value you want to delete:";
        int pos;
        cin>>pos;
        if(pos<=0 || pos>count){
            cout<<"Enter correct position.\n";
            return deletion();
        }
        else{
                doublyCircularLinkedList *temp=head;
            for(int a=1;a<pos-1;a++){
                temp=temp->next;
            }
            if(pos==1){
                head=head->next;
                delete temp;
                tail->next=head;
                head->prev=tail;
            }
            else{
                doublyCircularLinkedList *temp_2=temp->next;
                temp->next=temp_2->next;
                temp_2->next->prev=temp_2->prev;
                if(pos==count){
                        tail=temp;
                    }
                delete temp_2;
            }
        }
        count--;
    }
    void reversing(void){
        if(count==0){
                head=NULL;
                tail=NULL;
            cout<<"Enter value first.\n";
            return enterValue();
        }
        if(count==1){
            cout<<"Not making sense to reverse a single value.\n";
            return;
        }
        doublyCircularLinkedList *cur=NULL,*aft=NULL,*pr=NULL;
        cur=aft=pr=head;
        pr=cur->next;
        aft=pr->next;
        while(aft!=head){
            pr->next=cur;
            pr->prev=aft;
            cur=pr;
            pr=aft;
            aft=aft->next;
        }
        pr->next=cur;
        pr->prev=head;
        doublyCircularLinkedList *temp=head;
        head=tail;
        tail=temp;
        tail->next=head;
        tail->prev=temp->next;
    }
};
int doublyCircularLinkedList:: count=0;

int main(void){
bool looping=true;
    while(looping==true){
        doublyCircularLinkedList ob1;
        int choice;
        cout<<"Press 1 to enter value:-\n";
        cout<<"Press 2 to insert value:-\n";
        cout<<"Press 3 to delete value:-\n";
        cout<<"Press 4 to reverse value:-\n";
        cout<<"Press 5 to traverse value:-\n";
        cout<<"Press 6 to exit:-\n";
        cout<<"Enter your choice:";
        cin>>choice;
        switch(choice){
            case 1:
                ob1.enterValue();
                break;
            case 2:
                ob1.traversing();
                break;
            case 3:
                ob1.insertion();
                break;
            case 4:
                ob1.deletion();
                break;
            case 5:
                ob1.reversing();
                break;
            case 6:
                looping=false;
                break;
            default :
                cout<<"Enter correct choice.\n\n";
        }
    }
return 0;
}
