#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;

int LCS(string s1, string s2){
    int m= s1.size();
    int n= s2.size();
    int lcs[m+1][n+1];

    for(int i=0;i<=m;i++){
        lcs[i][n]=0;
    }
    for(int i=0;i<=n;i++){
        lcs[m][i]=0;
    }

    for(int i= m-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            lcs[i][j] = lcs[i+1][j+1];
            if(s1[i] == s2[j]){
                lcs[i][j]++;
            }
            if(lcs[i][j+1]>lcs[i][j]){
                lcs[i][j]= lcs[i][j+1];
            }
            else if(lcs[i+1][j]>lcs[i][j]){
                lcs[i][j]= lcs[i+1][j];
            }
        }
    }

    return lcs[0][0];
}

int main(){
    cout<<LCS("ABCBDAB","BDCABA");
    return 0; 
}