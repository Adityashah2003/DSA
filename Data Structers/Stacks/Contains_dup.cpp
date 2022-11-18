#include <bits/stdc++.h>
using namespace std;

int main(){
    cout<<"Enter the size of array: ";
    int num;
    cin>>num;
    int arr[num];
    int i,j,flag=0;
    cout<< "Enter the values"<<endl;
    for(i=0;i<num;i++){
        cin>>arr[i];
    }  
    for(i=0;i<num;i++){
        for(j=0;j<num;j++){
            if(arr[i]==arr[j])
                flag = 1;
            else 
                flag =0;
        }
    }
    if(flag == 1)
        cout<<"true";
    else      
        cout<<"false";
return 0;
}


