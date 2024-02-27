#pragma GCC optimize("O3")
#pragma GCC optimize("fast-math")

#include <stdio.h>
#include <malloc.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int* nums, int l, int r) {
    int pivot = nums[r];
    int p = l - 1;
    for (int i = l; i < r; i++) {
        if (nums[i] <= pivot) {
            p++;
            swap(&nums[p], &nums[i]);
        }
    }
    p++;
    swap(&nums[p], &nums[r]);
    return p;
}

void quicksort(int* nums, int l, int r) {
    if (l >= r || l < 0) return;
    int p = partition(nums, l, r);
    quicksort(nums, l, p - 1);
    quicksort(nums, p + 1, r);
}

int main(void) {
    unsigned n;
    scanf("%u", &n);
    int* nums = malloc(n * sizeof(int));
    for (unsigned i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    quicksort(nums, 0, n - 1);
    for (unsigned i = 0; i < n; i++) {
        printf("%d\n", nums[i]);
    }
    free(nums);
    return 0;
}
