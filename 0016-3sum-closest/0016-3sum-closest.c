#include <stdlib.h>

// Compare function for qsort
int cmpfunc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int threeSumClosest(int* nums, int numsSize, int target) {
    // Sort the array
    qsort(nums, numsSize, sizeof(int), cmpfunc);

    // Initialize closest sum to the sum of the first 3 elements
    int closest = nums[0] + nums[1] + nums[2];

    for (int i = 0; i < numsSize - 2; i++) {
        int left = i + 1;
        int right = numsSize - 1;

        while (left < right) {
            int currentSum = nums[i] + nums[left] + nums[right];

            // If this sum is closer to target than previous closest, update
            if (abs(currentSum - target) < abs(closest - target)) {
                closest = currentSum;
            }

            // Move pointers to try to get closer to target
            if (currentSum < target) {
                left++;
            } else if (currentSum > target) {
                right--;
            } else {
                // Exact match
                return currentSum;
            }
        }
    }
    return closest;
}
    
