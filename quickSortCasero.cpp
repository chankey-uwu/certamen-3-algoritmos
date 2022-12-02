#include <bits/stdc++.h>
#include <time.h>
using namespace std;

int A[1024];

void swap(int* m, int* n){
    int temp = *m; 
    *m = *n;
    *n = temp;
}

int partition(int i, int d){
    int piv = A[d];
    i--;
    do{
        i++;
        while(A[i] <= piv) i++;
        d--;
        while(i < d && A[d] >= piv) d--;
        if(i < d) swap(&A[i],&A[d]);
    }while(i < d);
    return i;
}

void quickSort(int i, int d){
    if(d - i <= 0) return;
    else if(d - i == 1){
        if(A[i] > A[d]) swap(&A[i], &A[d]);
        return;
    }
    else{
        int p = (i + d)/2;
        swap(&A[p],&A[d]);
        int k = partition(i,d);
        swap(&A[k],&A[d]);
        if(k == d - 1) k = d;
        quickSort(i, k - 1);
        quickSort(k + 1, d);
    }
}

int main(int argc, char const *argv[]){
    int n;
    cin >> n; 
    for(int i = 0; i < n; i++) cin >> A[i]; 
    clock_t tStart = clock();
    quickSort(0, n - 1);
    for(int i = 0; i < n; i++){
        cout << A[i] << " ";
    }
    cout << endl;
    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
