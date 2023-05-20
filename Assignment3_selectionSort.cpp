// selection sort

#include<iostream>
using namespace std;

void selectionSort(int arr[],int size){
    int minIndex = INT_MIN;

    for(int i = 0; i<size; i++){
        minIndex = i;
        for(int j = i; j<size; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[i],arr[minIndex]);
    }
}

void printArray(int arr[],int size){
    for(int i = 0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    cout<<"Enter Number of element : ";
    cin>>n;

    int arr[n];
    for(int i = 0; i<n; i++){
        cout<<"Enter element : ";
        cin>>arr[i];
    }

    printArray(arr,n);
    
    cout<<"Selection sort : ";
    selectionSort(arr,n);
    printArray(arr,n);

    return 0;
}