#include<iostream>
#include<conio.h>
using namespace std;
class Queue{
private:
    int arr[5],rear,head;
public:
    Queue(void){
        rear=head=-1;
        for(int i=0;i<5;i++){
            arr[i]=0;
        }
    }
    bool isEmpty(void){
        if(head==-1 && rear==-1){
            return true;
        }
        return false;
    }
    bool isFull(void){
        if(rear==4){
            return true;
        }
        return false;
    }
    void enqueue(int value){
        if(isFull()){
            cout<<"Queue is full, this value cannot be store in queue\n";
            return;
        }
        else if(isEmpty()){
            rear=head=0;
        }
        else{
            rear++;
        }
        arr[rear]=value;
    }
    int dequeue(void){
        int x;
        if(isEmpty()){
            cout<<"Queue is Empty\n";
            return 0;
        }

        else if(rear==head){
            x=arr[head];
            arr[head]=0;
            head=rear=-1;
        }
        else{
            x=arr[head];
            arr[head]=0;
            head++;
        }
        return x;

    }
    int count(void){
        if(isEmpty()){
            return 0;
        }
        return (rear-head+1);
    }
    void display(void){
        for(int i=0;i<5;i++){
            cout<<arr[i]<<"\t";
        }
        cout<<"\n";
    }
};
int main(void){
Queue q1;
int option,value;
    do{
        cout<<"Enter your choice..............\n";
        cout<<"1.enqueue.\n";
        cout<<"2.dequeue.\n";
        cout<<"3.isEmpty.\n";
        cout<<"4.isFull.\n";
        cout<<"5.count.\n";
        cout<<"6.display.\n";
        cout<<"7.clear screen.\n";
        cout<<"0.exit.\n";
        cin>>option;
        switch(option){
            case 1:
                cout<<"Enter the value to enqueue:";
                cin>>value;
                q1.enqueue(value);
                break;
            case 2:
                {
                    int val=q1.dequeue();
                if(val)
                    cout<<"Dequeue value is:"<<val<<"\n";

                }
                break;
            case 3:
                if(q1.isEmpty()){
                    cout<<"Queue is empty.\n";
                }
                else{
                    cout<<"Queue is not empty.\n";
                }
                break;
            case 4:
                if(q1.isFull()){
                    cout<<"Queue is full.\n";
                }
                else
                    cout<<"Que is not full.\n";
                break;
            case 5:
                cout<<"There is "<<q1.count()<<" value in queue.\n";
                break;
            case 6:
                q1.display();
                break;
            case 7:
                system("cls");
                break;
            case 0:
                option=0;
                break;
            default:
                cout<<"Enter correct choice.\n";
        }
    }while(option);
return 0;
}
