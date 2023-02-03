#include <iostream>

using namespace std;

//Binary  search (iterative)
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
    int searchElem ;
    cout<<"Enter the element to be searched: ";
    cin>>searchElem;
    bool found = false;
    int mid;
    int h=n-1, l=0;
    while(h>=l){
        mid = (h+l)/2;
        if(arr[mid]==searchElem){
            found = true;
            break;
        }
        else if(arr[mid]<searchElem){
            l = mid+1;
        }
        else if(mid>searchElem){
            h = mid-1;
        }
    }
    if(found){
        cout<<"Element found at index"<<mid<<endl;
    }
    else{
        cout<<"Element not found";
    }

    return 0;
}
