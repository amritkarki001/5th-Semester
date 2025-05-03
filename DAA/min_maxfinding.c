#include<stdio.h> 

void main() {
	int A[6] = {45, 0, 304, 22, 5700, 8};
	int min, max;
	M(A, 0, 5, &min, &max);
	printf("\nMin: %d\t Max: %d", min, max);
}

void M(int* A, int i, int j, int* min, int* max) {
	int min1, max1, min2, max2, mid;
	if(i==j) {
		*min = *max = A[i];
	}
	else if(i == j-1) {
		if(A[i] < A[j]) {
			*min = A[i];
			*max = A[j];
		}
		else {
			*min = A[j];
			*max = A[i];
		}
	}
	else {
		mid = (i+j)/2;
		M(A, i, mid, &min1, &max1);
		M(A, mid+1, j, &min2, &max2);
		if(min1 < min2) {
			*min = min1;
		}
		else {
			*min = min2;
		}
		if(max1 < max2) {
			*max = max2;
		}
		else {
			*max = max1;
		}
	}
}
