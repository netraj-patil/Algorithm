#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;

struct myArr{
    int tsize,usize;
    int* ptr;
};

void createArr(struct myArr* a,int size, int u_size){
    a->tsize=size;
    a->usize=u_size;
    a->ptr=new int(size);
    for(int i=0;i<u_size;i++){
        cout<<"Enter element "<<i+1<<" : ";
        cin>>(a->ptr)[i];
    }
}

void linSearch(struct myArr* a,int n){
    for(int i=0;i<a->usize;i++){
        if((a->ptr)[i]==n){
            cout<<"number found at index no. "<<i;
            return;
        }
    }

    cout<<"Number is not fond";
}

void sort(struct myArr* a){
    for(int i=0;i<a->usize-1;i++){
        for(int j=0;j<(a->usize-i-1);j++){
            if((a->ptr)[j]>(a->ptr)[j+1]){
                int temp=(a->ptr)[j];
                (a->ptr)[j] = (a->ptr)[j+1];
                (a->ptr)[j+1]=temp;
            }
        }
    }

    cout<<"\n----------------------------------------------";
    cout<<"\nsorted array: "<<endl;
    for(int i=0;i<a->usize;i++){
        cout<<"element no. : "<<i+1<<" : "<<(a->ptr)[i]<<endl;
    }
    cout<<"================================================"<<endl;
}
void binSearch(struct myArr* a, int n){
    sort(a);
    int low,high,mid;

    low=0;
    high=a->usize-1;
    if((a->ptr)[low]==n || (a->ptr)[high]==n){
        cout<<"element found";
        return;
    }

    do{
        mid=floor((low+high)/2);
        if((a->ptr)[mid]==n){
            cout<<"element found"<<endl;
            return;
        }
        else if((a->ptr)[mid]>n){
            high=mid;
        }
        else{
            low=mid;
        }
    }while((low+1) != high);

    cout<<"element not found"<<endl;
}

int main(){
    myArr arr;
    createArr(&arr,10,10);
    linSearch(&arr,20);
    binSearch(&arr,20);
    return 0;
}