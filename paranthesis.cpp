#include<iostream>
#include<conio.h>
#include<vector>
#include<stdlib.h>
#include<string.h>
using namespace std;

int matchSymbol(char a, char b){
    if(a=='[' && b==']'){
        return 1;
    }
    if(a=='(' && b==')'){
        return 1;
    }
    if(a=='{' && b=='}'){
        return 1;
    }
    return 0;
}

int checkExression(string exp){
    int cnt;
    char temp;
    vector<char> ch;
    for(cnt=0;cnt<exp.size();cnt++){
        if(exp[cnt]=='[' || exp[cnt]=='(' || exp[cnt]=='{'){
            ch.push_back(exp[cnt]);
        }
        if(exp[cnt]==']' || exp[cnt]==')' || exp[cnt]=='}'){
            if(ch.empty()){
                return 0;
            }
            else{
                temp = ch[ch.size()-1];
                ch.pop_back();
                if(!matchSymbol(temp,exp[cnt])){
                    return 0;
                }
            }
        }
    }

    if(ch.empty()){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    int c;
    c=checkExression("[a+b*(c-d)/{e+f}]");
    if(c==1){
        cout<<"\nExpression is valid";
    }
    else{
        cout<<"\nExpression is not valid";
    }
    return 0;
}