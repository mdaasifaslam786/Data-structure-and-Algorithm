#include<iostream>
#include<conio.h>
using namespace std;
class BSearch{
private:
    int *arr,n,left,right,middle;
public:
    BSearch(void);
    void enterValue(void);
    void BinarySearch(int val);
};
BSearch::BSearch(void){
    cout<<"Enter size of array:";
    cin>>n;
    arr=new int[n];
    left=0;
    right=n-1;
    middle=0;
}
void BSearch::enterValue(void){
    cout<<"Enter data in sored way:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}
void BSearch::BinarySearch(int val){
    while(left<=right){
        middle=(left+right)/2;
        if(arr[middle]==val){
            cout<<"Value found at position:"<<middle+1<<"\n";
            return;
        }
        else if(arr[middle]<val){
            left=middle+1;
        }
        else{
            right=middle-1;
        }
    }
    if(left>right){
        cout<<"Value not found.\n";
    }
}
int main(void){
BSearch bs;
        bs.enterValue();
        cout<<"Enter value to search:";
        int val;
        cin>>val;
        bs.BinarySearch(val);
return 0;
}

