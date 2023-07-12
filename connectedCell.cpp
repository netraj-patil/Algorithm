#include<iostream>
#include<conio.h>
using namespace std;

/*
to find largest possible region of 1 in a matrix
eg
11110
01100
00101
10001
01011

output 7
*/

int getVal(int (*a)[5],int i,int j,int l, int h){
    if(i<0 || i>=l ||j<0 ||j>=h) return 0;
    return a[i][j];
}

void findMaxBlock(int (*a)[5],int r, int c, int L, int H, int size, bool **cntarr, int *maxsize){
    if(r>=L || c>=H){
        return;
    }
    cntarr[r][c]=true;
    size++;

    if(size>*maxsize){
        *maxsize=size;
    }

    //search in eight dir

    int dir[][2]={{-1,0},{-1,-1},{0,-1}, {1,-1},{1,0}, {1,1}, {0,1}, {-1,1}};
    for(int i=0;i<8;i++){
        int ni=r+dir[i][0];
        int nj= c+dir[i][1];
        int val= getVal(a, ni, nj, L, H);
        if(val>0 && cntarr[ni][nj]==false){
            findMaxBlock(a, ni, nj, L, H, size, cntarr, maxsize);
        }
    }
    cntarr[r][c]=false;
}

int getMaxOnes(int (*a)[5], int rmax, int colmax){
    int maxsize=0, size=0;
    bool** cntarr=new bool*[5];
    for(int i=0;i<rmax;i++){
        cntarr[i]= new bool[5];   
    }
    for(int i=0;i<rmax;i++){
        for(int j=0;j<colmax;j++){
            cntarr[i][j]=false;
        }   
    }
    for(int i=0;i<rmax;i++){
        for(int j=0;j<colmax;j++){
            if(a[i][j]==1)
                findMaxBlock(a, i, j, rmax, colmax, 0, cntarr, & maxsize);
        }   
    }

    return maxsize;
}

int main(){
    int zarr[][5]={{1,1,1,1,0},{0,1,1,0,0}, {0,0,1,0,1},{1,0,0,0,1},{0,1,0,1,1}};
    int m=getMaxOnes(zarr,5,5);
    cout<<"\nNumber of max 1 is : "<<m;
    return 0;
}