#include<iostream>
#include<conio.h>
using namespace std;

/*this program display all possible binary numbers for given number of digits
eg if n=3 then numbes are
000 001 010 011 100 101 110 111
*/

void Binary(int o,int n,int arr[]){
    if(n==0) {
        for(int i=0;i<o;i++){
        cout<<arr[i];
    }
    cout<<endl;
        return;
    }

    arr[n-1]=0;
    Binary(o,n-1,arr);
    

    arr[n-1]=1;
    Binary(o,n-1,arr);
} 

int main(){
    int arr[4];
    Binary(4,4,arr);
    return 0;
}