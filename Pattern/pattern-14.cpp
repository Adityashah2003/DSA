#include <bits/stdc++.h>
using namespace std;

int main(){
    int i=0;
    int j=0;
    char x='A';
    int n=5;

    for(i=n;i>=0;i--){
        cout<<endl;
        for(char ch='A';ch<'A'+i;ch++){
            cout<<ch;
        }
    }
}