#include <bits/stdc++.h>
using namespace std;

int main(){
    int i=0;
    int j=0;
    int n=5;
    int count=0;

    for(i=1;i<=n;i++){
        cout<<endl;
        for(j=0;j<i;j++){
            count++;
            cout<<count;
            cout<<" ";
        }
    }
}