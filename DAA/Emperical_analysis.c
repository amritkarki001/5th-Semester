#include <stdio.h>
#include <stdlib.h>     // For malloc, free, rand, srand
#include <sys/time.h>   // For gettimeofday
#include <time.h>       // For time() to seed srand
// #include <conio.h> // conio.h is non-standard, use getchar() instead if needed

// Function declarations
void bubblesort(int *, int);
void selectionsort(int *, int);
void insertionsort(int *, int);
void quicksort(int *, int, int);
int partition(int *, int, int);
void merge(int *, int, int, int);
void mergesort(int *, int, int);
void heapsort(int *, int);
void heapify(int *, int, int);
void init(int *, int);
void listcopy(int *, int *, int);

int main()
{
    int *A, *B, N;
    struct timeval start, stop;
    double msecs = 0; // Changed variable name for clarity (milliseconds)

    // Seed the random number generator
    srand(time(NULL));

    printf("\n Enter list size: ");
    scanf("%d", &N);

    // Basic input validation
    if (N <= 0) {
        fprintf(stderr, "Error: List size must be positive.\n");
        return 1;
    }


    // Allocate memory
    A = (int *)malloc(N * sizeof(int));
    B = (int *)malloc(N * sizeof(int));
    if (A == NULL || B == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        // Free whichever allocation succeeded, if any
        if (A) free(A);
        if (B) free(B);
        return 1; // Indicate error
    }

    // Initialize A with random data (Master Copy)
    printf("Initializing list with %d random numbers...\n", N);
    init(A, N);
    printf("Initialization complete.\n");

    // --- Bubble Sort ---
    printf("\nRunning Bubble Sort...\n");
    listcopy(B, A, N); // Copy original unsorted data from A to B
    gettimeofday(&start, NULL);
    bubblesort(B, N); // Sort B
    gettimeofday(&stop, NULL);
    // Calculate time difference in milliseconds
    msecs = (double)(stop.tv_sec - start.tv_sec) * 1000.0 + (double)(stop.tv_usec - start.tv_usec) / 1000.0;
    printf(" Time taken by bubblesort in msecs: %lf\n", msecs);

    // --- Selection Sort ---
    printf("\nRunning Selection Sort...\n");
    listcopy(B, A, N); // Copy original unsorted data from A to B
    gettimeofday(&start, NULL);
    selectionsort(B, N); // Sort B
    gettimeofday(&stop, NULL);
    // Calculate time difference in milliseconds
    msecs = (double)(stop.tv_sec - start.tv_sec) * 1000.0 + (double)(stop.tv_usec - start.tv_usec) / 1000.0;
    printf(" Time taken by selectionsort in msecs: %lf\n", msecs);

    // --- Insertion Sort ---
    printf("\nRunning Insertion Sort...\n");
    listcopy(B, A, N); // Copy original unsorted data from A to B
    gettimeofday(&start, NULL);
    insertionsort(B, N); // Sort B
    gettimeofday(&stop, NULL);
    // Calculate time difference in milliseconds
    msecs = (double)(stop.tv_sec - start.tv_sec) * 1000.0 + (double)(stop.tv_usec - start.tv_usec) / 1000.0;
    printf(" Time taken by insertionsort in msecs: %lf\n", msecs);

    // --- Quick Sort ---
    printf("\nRunning Quick Sort...\n");
    listcopy(B, A, N); // Copy original unsorted data from A to B
    gettimeofday(&start, NULL);
    quicksort(B, 0, N - 1); // Sort B
    gettimeofday(&stop, NULL);
    // Calculate time difference in milliseconds
    msecs = (double)(stop.tv_sec - start.tv_sec) * 1000.0 + (double)(stop.tv_usec - start.tv_usec) / 1000.0;
    printf(" Time taken by quicksort in msecs: %lf\n", msecs);

    // --- Merge Sort ---
    printf("\nRunning Merge Sort...\n");
    listcopy(B, A, N); // Copy original unsorted data from A to B
    gettimeofday(&start, NULL);
    mergesort(B, 0, N - 1); // Sort B
    gettimeofday(&stop, NULL);
    // Calculate time difference in milliseconds
    msecs = (double)(stop.tv_sec - start.tv_sec) * 1000.0 + (double)(stop.tv_usec - start.tv_usec) / 1000.0;
    printf(" Time taken by mergesort in msecs: %lf\n", msecs);

    // --- Heap Sort ---
    printf("\nRunning Heap Sort...\n");
    listcopy(B, A, N); // Copy original unsorted data from A to B
    gettimeofday(&start, NULL);
    heapsort(B, N); // Sort B
    gettimeofday(&stop, NULL);
    // Calculate time difference in milliseconds
    msecs = (double)(stop.tv_sec - start.tv_sec) * 1000.0 + (double)(stop.tv_usec - start.tv_usec) / 1000.0;
    printf(" Time taken by heapsort in msecs: %lf\n", msecs);

    printf("\nPress Enter to exit...\n");
    // getch(); // Non-standard, replace if needed
    // Consume the newline potentially left by scanf (especially if N was entered)
    while (getchar() != '\n' && getchar() != EOF) ;
    getchar(); // Wait for user to press Enter

    // Free allocated memory
    free(A);
    free(B);

    return 0;
}

// --- Sorting Functions (Remain Unchanged) ---

void bubblesort(int *A, int N)
{
    int i, j, tmp;
    int swapped; // Optimization: Flag to stop if already sorted
    for (i = 0; i < N - 1; i++)
    {
        swapped = 0;
        for (j = 0; j < N - i - 1; j++)
        {
            if (A[j] > A[j + 1])
            {
                tmp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = tmp;
                swapped = 1;
            }
        }
        // If no two elements were swapped by inner loop, then break
        if (swapped == 0)
            break;
    }
}

void selectionsort(int *A, int N)
{
    int i, j, imin, tmp;
    for (i = 0; i < N - 1; i++)
    {
        imin = i;
        for (j = i + 1; j < N; j++)
        {
            if (A[j] < A[imin])
            {
                imin = j;
            }
        }
        // Swap only if necessary
        if (imin != i) {
           tmp = A[i];
           A[i] = A[imin];
           A[imin] = tmp;
        }
    }
}

void insertionsort(int *A, int N)
{
    int i, j, key;

    for (i = 1; i < N; i++)  // Start from the second element
    {
        key = A[i];  // Store the element to be positioned
        j = i - 1;    // Start comparing with the previous element

        // Shift elements to the right until the correct position is found
        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];  // Shift element to the right
            j--;  // Move to the previous element
        }

        A[j + 1] = key;  // Insert key at the correct position
    }
}


int partition(int *A, int p, int r)
{
    int i, j, x, tmp;
    x = A[r]; // Pivot
    i = p - 1; // Index of smaller element boundary
    for (j = p; j < r; j++) // Iterate from p up to (but not including) r
    {
        // If current element is smaller than or equal to pivot
        if (A[j] <= x)
        {
            i++; // Advance smaller element boundary
            // Swap A[i] and A[j]
            tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
        }
    }
    // Swap the pivot (A[r]) with the element at A[i+1]
    // Now elements <= pivot are to the left, > pivot are to the right
    tmp = A[i + 1];
    A[i + 1] = A[r]; // Place pivot A[r] (which is x) at index i+1
    A[r] = tmp;      // Place the element originally at A[i+1] into A[r]
    return i + 1;    // Return the index where the pivot ended up
}

void quicksort(int *A, int p, int r)
{
    int q;
    if (p < r) // Base case: If subarray has size 0 or 1, it's sorted
    {
        q = partition(A, p, r); // Partition and get pivot index
        quicksort(A, p, q - 1); // Recursively sort left subarray (excluding pivot)
        quicksort(A, q + 1, r); // Recursively sort right subarray (excluding pivot)
    }
}

void mergesort(int *A, int l, int u)
{
    int mid;
    if (l < u) // Base case: If subarray has size 0 or 1, it's sorted
    {
        // Same as (l+u)/2, but avoids overflow for large l and u
        mid = l + (u - l) / 2;
        mergesort(A, l, mid);       // Recursively sort first half
        mergesort(A, mid + 1, u);   // Recursively sort second half
        merge(A, l, mid, u);        // Merge the two sorted halves
    }
}

// --- Merge Function with Memory Deallocation ---
void merge(int *A, int low, int mid, int up)
{
    int i, j, k;
    int n1 = mid - low + 1; // Size of left subarray
    int n2 = up - mid;      // Size of right subarray

    // Create temporary arrays
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    // Check for allocation failure
    if (L == NULL || R == NULL) {
        fprintf(stderr, "Memory allocation failed in merge!\n");
        if (L) free(L);
        if (R) free(R);
        exit(EXIT_FAILURE); // Exit if memory cannot be allocated
    }

    // Copy data to temp arrays L[] (from A[low...mid]) and R[] (from A[mid+1...up])
    for (i = 0; i < n1; i++)
        L[i] = A[low + i];
    for (j = 0; j < n2; j++)
        R[j] = A[mid + 1 + j];

    // Merge the temp arrays back into A[low..up]
    i = 0; // Initial index of first subarray (L)
    j = 0; // Initial index of second subarray (R)
    k = low; // Initial index of merged subarray (A)
    while (i < n1 && j < n2) { // While there are elements in BOTH L and R
        if (L[i] <= R[j]) { // Pick the smaller element
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++; // Move to next position in A
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }

    // Free the temporary arrays
    free(L);
    free(R);
}


void heapsort(int *A, int N)
{
    int i, temp;

    // Build max heap (rearrange array)
    // Start from the last non-leaf node (parent of last element) and go up
    for (i = N / 2 - 1; i >= 0; i--)
    {
        heapify(A, N, i); // Ensure subtree rooted at i is a max heap
    }

    // One by one extract elements from heap
    // The largest element is always at the root (index 0) after heapify
    for (i = N - 1; i > 0; i--) // Iterate from last index down to 1
    {
        // Move current root (max element) to end (its sorted position)
        temp = A[0];
        A[0] = A[i];
        A[i] = temp;

        // Call max heapify on the reduced heap (size is now 'i')
        // This ensures the new root element sifts down to maintain heap property
        heapify(A, i, 0);
    }
}

// To heapify a subtree rooted with node i which is an index in A[].
// N is size of heap (or subarray being considered).
void heapify(int *A, int N, int i)
{
    int largest = i;        // Initialize largest as root
    int left = 2 * i + 1;   // Index of left child
    int right = 2 * i + 2;  // Index of right child
    int temp;

    // If left child exists and is larger than root
    if (left < N && A[left] > A[largest])
        largest = left;

    // If right child exists and is larger than largest found so far
    if (right < N && A[right] > A[largest])
        largest = right;

    // If largest is not root (i.e., one of the children was larger)
    if (largest != i)
    {
        // Swap root (A[i]) with the largest child (A[largest])
        temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;

        // Recursively heapify the affected sub-tree (where the original root value went)
        // The subtree rooted at 'largest' might now violate heap property
        heapify(A, N, largest);
    }
}


// --- Utility Functions ---

void listcopy(int *dest, int *src, int N)
{
    int i;
    for (i = 0; i < N; i++)
    {
        dest[i] = src[i];
    }
}

void init(int *A, int N)
{
    int i;
    for (i = 0; i < N; i++)
    {
        A[i] = rand(); // Fill with pseudo-random numbers
    }
}
