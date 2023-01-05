#include <bits/stdc++.h>
using namespace std;

int main(){
    int i=0;
    int j=0;
    int n=5;

    for(i=n;i>=0;i--){
        cout<<endl;
        for(int k =0;k<n-i;k++){
            cout<<"  ";
        }
        for(j=0;j<=2*i;j++){
            cout<<" ";
            cout<<'*';
        }
    }
}