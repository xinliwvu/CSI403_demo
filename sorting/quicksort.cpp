// This is a clever implementation of quicksort
// except one weakness - no comments at all
// No matter how smart you are, please remember to add comments
// to your codes because you are doing others a favor


//#include < iostream.h >
#include < stdio.h >
#include < conio.h >
#include <iostream>
using namespace std;
#define len 8

    void print(int a[]) {
  for (int i = 0; i < len; i++) {
    cout << a[i] << "-";
  }
  cout << endl;
}

	// p - start; r - finish
int partition(int a[], int p, int r) {
	// pivot: last element
  int x = a[r];
  int j = p - 1;

  // scanning the whole sequence
  for (int i = p; i < r; i++) {

    if (x >= a[i]) {
      j = j + 1;
      int temp = a[j];
      a[j] = a[i];
      a[i] = temp;
    }
  }
  // push the pivot to the correct position: j+1
  a[r] = a[j + 1];
  a[j + 1] = x;

  return (j + 1);
}

void quickSort(int a[], int p, int r) {
  if (p < r) {
    int q = partition(a, p, r);
	print(a);
    quickSort(a, p, q - 1);
    quickSort(a, q + 1, r);
	print(a);
  }
}

void main() {

  //int a[] = {1, 9, 0, 5, 6, 7, 8, 2, 4, 3};
	int a[] = {6,5,3,1,8,7,2,4};
	//int a[] = {8,7,6,5,4,3,2,1};
  quickSort(a, 0, len-1);
  print(a);
  getch();
}