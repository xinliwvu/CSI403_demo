#include <cstdio> // printf, puts
#include <cstdlib> // srand, rand
#include <ctime> // time, clock, time_t
#define MAX 100000 // array size
#define RANGE 100000 // range
#define scale 1
 
void generate(int*, int);
void write(int*, int);
 
void quick_sort(int *, int, int);
void counting_sort(int *, int, int);
 
int main(int argc, char** argv) {
  int* T = new int[MAX];
  long start, end;
  long dif;
  srand(time(NULL));
 
  puts("quicksort, O(nlog(n))");
  generate(T, MAX);
  //write(T,MAX);
  start = clock();
  quick_sort(T, 0, MAX - 1);
  end = clock();
  dif = end - start;
  //write(T,MAX);
  printf("%ld\n", dif / scale);
 
  puts("counting sort, O(n)");
  generate(T, MAX);
  //write(T,MAX);
  start = clock();
  counting_sort(T, MAX, RANGE);
  end = clock();
  dif = end - start;
  //write(T,MAX);
  printf("%ld\n", dif / scale);
 
  delete[] T;
  return 0;
}
 
// helpers
 
void generate(int* a, int max) {
  for (int i = 0; i < max; ++i)
    a[i] = rand() % RANGE;
}
 
void write(int* a, int max) {
  for (int i = 0; i < max; ++i)
    printf(" %d", a[i]);
  printf("\n");
}
 
// sorting functions
 
void quick_sort(int *a, int s, int k) {
  int left = s, right = k, med = a[(s + k) / 2], tmp;
  do {
    while (a[left] < med)
      ++left;
    while (a[right] > med)
      --right;
    if (left <= right) {
      tmp = a[left];
      a[left] = a[right];
      a[right] = tmp;
      ++left;
      --right;
    }
  } while (left < right);
  if (left < k)
    quick_sort(a, left, k);
  if (s < right)
    quick_sort(a, s, right);
}
 
// assumptions:
// - values of A are greater than 0
// - max value of A is known
void counting_sort(int *A, int size, int range) {
	int i;
  // tmp array
  int *B = new int[size];
  // array for counting indexes
  int *C = new int[range + 1];
  for (i = 0; i <= range; ++i)
    C[i] = 0;
  // count appearances of values
  for (i = 0; i < size; ++i)
    ++C[A[i]];
  // count the places where values
  // should be after sorting -
  // just add previous indexes counts
  for (i = 1; i <= range; ++i)
    C[i] += C[i - 1];
  // copy values from A to the right
  // place in B, and decrement C[A[i]] by one -
  // because you already place value on this index
  for (i = size - 1; i >= 0; --i) {
    B[C[A[i]] - 1] = A[i];
    --C[A[i]];
  }
  // copying back to A
  for (i = 0; i < size; ++i)
    A[i] = B[i];
  delete[] B;
  delete[] C;
}