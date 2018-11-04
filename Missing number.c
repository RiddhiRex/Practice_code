int missingNumber(int* nums, int numsSize) {
    int i=0;
    int sum=0;
    int true_sum=0;
    for(i=0;i<=numsSize;i++){
        sum+=i;
    }
    for(i=0;i<numsSize;i++){
        true_sum+=nums[i];
    }
    return (sum-true_sum);
}
