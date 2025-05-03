#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

// --- Linear Search ---
// Returns index of target if found, otherwise -1
int linear_search(int *arr, int size, int target) {
    int i; // Declare loop variable at the start of the block
    for (i = 0; i < size; i++) { // Initialize in the loop statement
        if (arr[i] == target) {
            return i; // Found
        }
    }
    return -1; // Not found
}

// --- Binary Search (Iterative) ---
// Returns index of target if found, otherwise -1
// Assumes arr is sorted
int binary_search(int *arr, int size, int target) {
    int low = 0;
    int high = size - 1;
    int mid; // Declare mid here

    while (low <= high) {
        // Calculate mid inside the loop
        mid = low + (high - low) / 2; // Avoids potential overflow

        if (arr[mid] == target) {
            return mid; // Found
        } else if (arr[mid] < target) {
            low = mid + 1; // Search in right half
        } else {
            high = mid - 1; // Search in left half
        }
    }
    return -1; // Not found
}

// --- Helper Functions ---

// Creates a sorted array (0, 1, 2, ... N-1)
void init_sorted_array(int *arr, int size) {
    int i; // Declare loop variable at the start of the block
    for (i = 0; i < size; i++) { // Initialize in the loop statement
        arr[i] = i;
    }
}

// Generates a random target value. Range allows for hits and misses.
int generate_target(int max_value) {
    // Generates target potentially inside or outside the array range [0, max_value-1]
    // Example: Range up to 1.5 * max_value increases chance of misses
    return rand() % (int)(max_value * 1.5);
}


int main() {
    int sizes[] = {1000, 10000, 100000, 1000000, 10000000}; // Array sizes to test
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
    int num_searches = 10000; // Number of searches to perform for averaging

    struct timeval start, stop;
    double linear_time_ms = 0;
    double binary_time_ms = 0;

    // Declare loop variables for main function's loops here
    int i, j, k;
    int N; // Declare N here as well
    int *arr = NULL; // Initialize pointers to NULL
    int *targets = NULL;

    srand(time(NULL)); // Seed random number generator

    printf("Empirical Analysis: Linear vs Binary Search (%d searches per size)\n", num_searches);
    printf("------------------------------------------------------------------\n");
    printf("| %-12s | %-25s | %-25s |\n", "Array Size", "Linear Search Time (ms)", "Binary Search Time (ms)");
    printf("|--------------|---------------------------|---------------------------|\n");

    // Loop through different array sizes
    for (i = 0; i < num_sizes; i++) { // Initialize i in the loop statement
        N = sizes[i];
        arr = (int *)malloc(N * sizeof(int));
        if (arr == NULL) {
            fprintf(stderr, "Memory allocation failed for array size %d\n", N);
            continue; // Skip to next size
        }

        // Create sorted array
        init_sorted_array(arr, N);

        // Allocate and generate targets
        targets = (int *)malloc(num_searches * sizeof(int));
        if (targets == NULL) {
             fprintf(stderr, "Target allocation failed for size %d\n", N);
             free(arr); // Free previously allocated memory
             continue; // Skip to next size
        }
        for(k = 0; k < num_searches; k++) { // Initialize k in the loop statement
            targets[k] = generate_target(N);
        }

        // --- Time Linear Search ---
        gettimeofday(&start, NULL);
        for (j = 0; j < num_searches; j++) { // Initialize j in the loop statement
            linear_search(arr, N, targets[j]);
        }
        gettimeofday(&stop, NULL);
        linear_time_ms = (double)(stop.tv_sec - start.tv_sec) * 1000.0 +
                         (double)(stop.tv_usec - start.tv_usec) / 1000.0;


        // --- Time Binary Search ---
        gettimeofday(&start, NULL);
        for (j = 0; j < num_searches; j++) { // Initialize j in the loop statement
            binary_search(arr, N, targets[j]);
        }
        gettimeofday(&stop, NULL);
        binary_time_ms = (double)(stop.tv_sec - start.tv_sec) * 1000.0 +
                         (double)(stop.tv_usec - start.tv_usec) / 1000.0;

        // Print results for this size
        printf("| %-12d | %-25.3f | %-25.3f |\n", N, linear_time_ms, binary_time_ms);

        // Free memory for this size
        free(arr);
        arr = NULL; // Avoid dangling pointer
        free(targets);
        targets = NULL; // Avoid dangling pointer
    }
    printf("------------------------------------------------------------------\n");

    return 0;
}
