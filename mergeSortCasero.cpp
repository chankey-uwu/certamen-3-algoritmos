#include <bits/stdc++.h>
#include <time.h>
using namespace std;

int A[1024];

void merge(int start, int mid, int end){
    int i1 = start, i2 = mid + 1, i = 0;
    int *Atemp = new int[end - start + 1];
    while(i1 <= mid && i2 <= end){
        if(A[i1] < A[i2]) Atemp[i++] = A[i1++];
        else Atemp[i++] = A[i2++];
    }
    while(i1 <= mid) Atemp[i++] = A[i1++];
    while(i2 <= end) Atemp[i++] = A[i2++];
    for(int j = start; j <= end; j++) A[j] = Atemp[j - start];
    delete[] Atemp;
}

void mergeSort(int start, int end){
    if(start >= end){
        return;
    }else{
        int mid = (start + end)/2;
        mergeSort(start, mid);
        mergeSort(mid + 1, end);
        merge(start, mid, end);
    }
}

int main(int argc, char const *argv[]){
    int n;
    cin >> n; 
    for(int i = 0; i < n; i++) cin >> A[i];
    clock_t tStart = clock();
    mergeSort(0, n - 1);
    for(int i = 0; i<n;i++){
        cout << A[i] << " ";
    }
    cout << endl;
    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}