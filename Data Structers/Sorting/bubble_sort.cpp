#include <iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Enter the number of elements:";
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cout<<"Enter the element: ";
        cin>>arr[i];
    }

    for(int i=0; i<n-1; i++){
        int minEle = arr[i];
        for(int j=i+1; j<n; j++){
            if(arr[j]<minEle){
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
