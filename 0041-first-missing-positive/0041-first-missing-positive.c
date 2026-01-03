int firstMissingPositive(int* nums, int numsSize) {
    // Step 1: Replace out-of-range (<=0 or >numsSize) with a number >n
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] <= 0 || nums[i] > numsSize) {
            nums[i] = numsSize + 1;
        }
    }

    // Step 2: Mark presence by negating value at index (num-1)
    for (int i = 0; i < numsSize; ++i) {
        int val = nums[i];
        if (val < 0) val = -val;
        if (val <= numsSize) {
            if (nums[val - 1] > 0) {
                nums[val - 1] = -nums[val - 1];
            }
        }
    }

    // Step 3: First index with positive value gives the missing positive
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] > 0) {
            return i + 1;
        }
    }

    return numsSize + 1;
}