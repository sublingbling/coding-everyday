class Solution {
public:
    int searchNum(vector<int> &num, int start, int end, int target)
    {
        if (start > end) return -1;
        if (target<num[start] || target>num[end]) return -1;

        while (start <= end)
        {
            int mid = (start+end+1)/2;
            if (target == num[mid])
                return mid;
            else if (target > num[mid])
                start = mid+1;
            else
                end = mid-1;
        }
        return -1;
    }
    
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> retVec;
        
        int size = numbers.size();
        if (size < 2) return retVec;
        
        for (int i=0; i<size-1; i++)
        {
            int num = target - numbers[i];
            int index = searchNum(numbers, i+1, size-1, num);
            if (index > 0)
            {
                retVec.push_back(i+1);
                retVec.push_back(index+1);
                return retVec;
            }
        }
        return retVec;
    }
};
