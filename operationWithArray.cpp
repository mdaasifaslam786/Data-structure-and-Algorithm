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
    void rotateArray(void);
    void rearrangeData(void);
    void smallestLargest(void);
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
/*Rotate operation from certain position*/
void operationWithArray:: rotateArray(void){
    if(insertionCheck){
        cout<<"Filled value first.\n";
        return;
    }
    cout<<"After which position you want to rotate the data:";
    int rot;
    cin>>rot;
    if(rot<1 || rot>=siz){
        cout<<"Enter correct position.\n\n";
        return rotateArray();
    }
    int temp[rot];
    for(int i=0;i<rot;i++){
        temp[i]=arr[i];
    }
    for(int i=0;i<siz-rot;i++){
        arr[i]=arr[i+rot];
        if(i==siz-rot-1){
            int j=0;
            while(j<rot && i<siz){
                arr[i+1]=temp[j];
                i++;
                j++;
            }
        }
    }

}
/* Rearrange the data such that  arr[i]=i */
void operationWithArray:: rearrangeData(void){
    for(int i=0;i<siz;i++){
        for(int j=0;j<siz;j++){
            if(arr[j]==i){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
                break;
            }
        }
    }
}
/* Finding largest and smallest number in array operation*/
void operationWithArray:: smallestLargest(void){
    int small=arr[0],large=arr[0];
    for(int i=1;i<siz;i++){
        if(arr[i]>large){
            large=arr[i];
        }
        if(arr[i]<small){
            small=arr[i];
        }
    }
    cout<<"Smallest number:"<<small<<"\n";
    cout<<"Largest number:"<<large<<"\n";
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
        cout<<"Enter 6 to rotate the data:-\n";
        cout<<"Enter 7 to rearrange the data:-\n";
        cout<<"Enter 8 to find smallest and largest number:-\n";
        cout<<"Press 9 to exit:-\n";
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
                op1.rotateArray();
                break;
            case 7:
                op1.rearrangeData();
                break;
            case 8:
                op1.smallestLargest();
                break;
            case 9:
                cout<<"Program ended.\n";
                looping=false;
                break;
            default:
                cout<<"Enter correct choice:-\n";
        }
    }
return 0;
}

