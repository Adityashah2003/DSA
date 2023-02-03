#include <iostream>

using namespace std;

//binary search (recursive)

int bSearchRec(int arr[], int h, int l, int elem){//if bSearchRec() returns -1 ----> element not found......else returns index at which element is found
    if(h>l){
        int mid = (h+l)/2;
        if(arr[mid]==elem){
            return mid;
        }
        if(elem>arr[mid]){
            l = mid+1;
            return bSearchRec(arr, h, l, elem);
        }
        if(elem<arr[mid]){
            h = mid-1;
            return bSearchRec(arr, h, l, elem);
        }
    }
    return -1;

}

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

    int mid;
    int h=n-1, l=0;

    int idx = bSearchRec(arr, h, l, searchElem);
    //cout<<"idx:"<<idx;
    if(idx!=-1){
        cout<<"Element found at index "<<idx<<endl;
    }
    else{
        cout<<"Element not found";
    }
    return 0;
}
