#include<iostream>
#include<conio.h>
using namespace std;
class linearSearch{
private:
    int *arr,n;
public:
    linearSearch(void);
    void enterValue(void);
    void lSearch(int val);
};
linearSearch::linearSearch(void){
    cout<<"Enter size of array:";
    cin>>n;
    arr=new int[n];
}
void linearSearch::enterValue(void){
    cout<<"Enter data:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}
void linearSearch::lSearch(int val){
    for(int i=0;i<n;i++){
        if(val==arr[i]){
            cout<<"Element found at location:"<<i+1<<"\n";
        }
        else if(i==n-1){
            cout<<"Element not found.\n";
        }
    }
}
int main(void){
linearSearch ls;
        ls.enterValue();
        cout<<"Enter value to search:";
        int val;
        cin>>val;
        ls.lSearch(val);
return 0;
}
