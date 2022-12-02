#include <bits/stdc++.h>
using namespace std;

int inversiones(int A[], int temp[], int izq, int der){
	int med, c = 0;
	if(der > izq){
		med = (der + izq) / 2;
		
		c = inversiones(A,temp,izq,med);
		c += inversiones(A,temp,med+1,der);
		
		c += merge(A,temp,izq,med+1,der);
		
	}
	return c;

}

int merge(int A[],int temp[],int izq,int med,int der){
	int i = izq, j = med, k = der;
	int c = 0;
	while ((i <= med- 1) && (j <= der))
		if (A[i] <= A[j])
			temp[k++] = A[i++];
		else {
			temp[k++] = A[j++];
			c += (med- i); // cuenta inversiones
		}
		
	while (i < med) temp[k++] = A[i++];
	while (j <= der) temp[k++] = A[j++];
	for (i = left; i <= right; i++)
		A[i] = temp[i];
	return c;
}