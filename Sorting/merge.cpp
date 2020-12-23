#include <iostream>
using namespace std;

void merge(int *arr, int start, int end, int mid){
    int i, j, k, c[end+1];
    i = start;
    k = start;
    j = mid + 1;
    while (i <= mid && j <= end){
        if (arr[i] < arr[j]){
            c[k] = arr[i];
            k++;
            i++;
        }
        else{
            c[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid){
        c[k] = arr[i];
        k++;
        i++;
    }
    while (j <= end){
        c[k] = arr[j];
        k++;
        j++;
    }
    for (i = start; i < k; i++){
        arr[i] = c[i];
    }
}

void mergeS(int *arr, int start, int end){
    if (start < end){
        int mid = (start+end)/2;
        mergeS(arr, start, mid);
        mergeS(arr, mid+1, end);
        merge(arr, start, end, mid);
    }
}

int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int ar[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> ar[i];
    mergeS(ar, 0, n-1);
    cout<<"Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << ar[i] << " ";
}