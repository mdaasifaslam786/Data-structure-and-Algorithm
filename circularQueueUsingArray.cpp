#include<iostream>
#include<conio.h>
#include<stdio.h>
using namespace std;
int siz;
class temp{
private:
    int *arr,head,tail;
public:
    temp(void){
        arr=NULL;
        head=tail=-1;
    }
    void sizeOfQueue(void){
        cout<<"Enter size of queue:";
        cin>>siz;
        arr=new int[siz];
        for(int i=0;i<siz;i++){
            arr[i]=0;
        }
    }
    void enqueue(int value){
        if(isFull()){
            cout<<"Queue is already full, this value cannot be stored.\n";
            return;
        }
        else if(isEmpty()){
            head=tail=0;
            arr[tail]=value;
        }
        else{
            tail=(tail+1)%siz;
            arr[tail]=value;
        }
    }
    int dequeue(void){
        int x;
        if(isEmpty()){
            cout<<"Queue is empty.\n";
            return 0;
        }
        else if(head==tail){
                x=arr[head];
                arr[head]=0;
            head=tail=-1;
        }
        else{
            x=arr[head];
            arr[head]=0;
            head=(head+1)%siz;
        }

      return x;
    }
    bool isEmpty(void){
        if(head==-1&&tail==-1){
            return true;
        }
        return false;
    }
    bool isFull(void){
        if(((tail+1)%siz==head)){
            return true;
        }
        return false;
    }
    void display(void){
        for(int i=0;i<siz;i++){
            cout<<arr[i]<<"\t";
        }
        cout<<"\n";
    }
};
int main(void){
    temp T1;
    T1.sizeOfQueue();
    int choice;
    do{
        cout<<"Press 1 to enqueue.\n";
        cout<<"Press 2 to dequeue.\n";
        cout<<"Press 3 to isEmpty.\n";
        cout<<"Press 4 to isFull.\n";
        cout<<"Press 5 to display.\n";
        cout<<"press 6 to clear screen.\n";
        cout<<"Press 0 to exit.\n";
        cin>>choice;
        int res;
        switch(choice){
            case 1:
                int value;
                cout<<"Enter value:";
                cin>>value;
                T1.enqueue(value);
                break;
            case 2:{
                int res=T1.dequeue();
                if(res){
                    cout<<"Dequeued value is:"<<res<<endl;
                }
                break;
            }
            case 3:
                if(T1.isEmpty()){
                    cout<<"Queue is empty.\n";
                }
                else{
                    cout<<"Queue is not empty.\n";
                }
                break;
            case 4:
                if(T1.isFull()){
                    cout<<"Queue is full.\n";
                }
                else{
                    cout<<"Queue is not full.\n";
                }
                break;
            case 5:
                T1.display();
                break;
            case 6:
                system("cls");
                break;
            case 0:
                break;
            default:
                cout<<"Enter correct choice.\n";
        }
    }while(choice);
return 0;
}
