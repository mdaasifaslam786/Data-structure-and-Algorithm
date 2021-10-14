#include<iostream>
using namespace std;
class operationWithArray
{
private:
    static int siz,insertionCheck;
    int arr[50];
public:
    void enterValue(void);
    void traversing(void);
    void insertion(void);
    void deletion(void);
    void reversing(void);
};
int operationWithArray:: insertionCheck=true;
int operationWithArray:: siz;
void operationWithArray:: enterValue(void){
    if(insertionCheck){
        cout<<"Enter size of list: ";
        cin>>siz;
        cout<<"Enter all value:\n";
        for(int x=0;x<siz;x++){
            cin>>arr[x];
        }
        insertionCheck=false;
    }
    else{
        cout<<"Insertion already completed.\n";
    }

}
void operationWithArray:: traversing(void){
    if(insertionCheck){
        cout<<"Filled value first.\n";
        return;
    }
    cout<<"Your all values are: ";
    for(int x=0;x<siz;x++){
        cout<<arr[x]<<"\t";
    }
    cout<<"\n";
}
void operationWithArray:: insertion(void){
    int pos,value;
    if(insertionCheck){
        cout<<"Filled value first.\n";
        return;
    }
    cout<<"At which position you want to enter value:";
    cin>>pos;
    if(pos>0 && pos<=siz+1){
            cout<<"Enter value:";
            cin>>value;
        for(int x=siz;x>=pos-1;x--){
                if(x==pos-1){
                    arr[x]=value;
                    break;
                }
                else if(pos==siz+1){
                        arr[siz]=value;
                        siz++;
                }
            arr[x]=arr[x-1];
        }
        siz++;
    }
    else{
        cout<<"Enter correct choice\n";
        insertion();
    }
}
void operationWithArray:: deletion(void){
    if(insertionCheck){
        cout<<"Filled value first.\n";
        return;
    }
    int pos;
    cout<<"Enter which position you want to delete:";
    cin>>pos;
    if(pos>0 && pos<=siz){
        if(pos==siz){
            siz--;
        }
        else{
            for(int x=pos;x<=siz-1;x++){
                arr[x-1]=arr[x];
            }
            siz--;
        }
    }
    else{
        cout<<"Enter correct position:";
        deletion();
    }

    if(siz==0){
        insertionCheck=true;
        cout<<"You have successfully deleted all data.\n";
    }
}
void operationWithArray:: reversing(void){
    for(int i=siz-1,j=0;i>j;i--,j++){
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
}
int main(void){
    bool looping=true;
    while(looping==true){
            int choice;
        operationWithArray op1;
        cout<<"Which operation you want to perform:-\n";
        cout<<"press 1 for inter value:-\n";
        cout<<"Press 2 for traversing:-\n";
        cout<<"Press 3 for insertion:-\n";
        cout<<"Press 4 for deletion:-\n";
        cout<<"Enter 5 to reverse the data:-\n";
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

