// bloody ugly one...

int search(int* nums, int numsSize, int target) {
    if (!nums || 0==numsSize) return -1;    
    if (target == nums[0]) return 0;
    
    if (nums[0] < nums[numsSize/2])
    {
        // if pivot is at right half
        if (target>=nums[0] && target<nums[numsSize/2])
        {
            // left half
            return search(nums, numsSize/2, target);
        }
        else
        {
            // right half
            int retVal = search(nums+numsSize/2, numsSize - numsSize/2, target);
            if (retVal >=0) return numsSize/2 + retVal;
            else return retVal;
        }
    }
    else
    {
        // pivot is at left half
        if (target>=nums[numsSize/2] && target<=nums[numsSize-1])
        {
            // right half
            int retVal = search(nums+numsSize/2, numsSize - numsSize/2, target);
            if (retVal >=0) return numsSize/2 + retVal;
            else return retVal;
        }
        else
        {
            // right half
            return search(nums, numsSize/2, target);
        }
    }

    return -1;
}
