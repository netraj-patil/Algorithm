#include<iostream>
#include<conio.h>
using namespace std;

/*n=number of disc
s= source rod
a= auxillary rod
d= destination rod
*/
void towerOfHanoi(int n, char s, char a, char d){
    if(n==0) return;
    towerOfHanoi(n-1,s,d,a);

    cout<<"\nMove disc from "<<s<<" to "<<d;

    towerOfHanoi(n-1,a,s,d);
}

int main(){
    towerOfHanoi(3,'A','B','c');
    return 0;
}