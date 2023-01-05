#include <bits/stdc++.h>
using namespace std;

int main(){
    int i=0;
    int j=0;
    int n=5;

    for(i=0;i<n;i++){
        cout<<endl;
        cout<<"       ";
        for(j=0;j<=i;j++){
            cout<<" ";
            cout<<'*';
        }
    }
    for(i=n;i>=0;i--){
        cout<<endl;
        cout<<"       ";
        for(j=0;j<=i;j++){
            cout<<" ";
            cout<<'*';
        }
    }
}