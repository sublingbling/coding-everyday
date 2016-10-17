public class Solution {
    /** 
     *@param A : an integer sorted array
     *@param target :  an integer to be inserted
     *return : a list of length 2, [index1, index2]
     */
    public int[] searchRange(int[] A, int target) {
        // write your code here
        int[] bound = new int[]{-1, -1};
        if (A == null || A.length == 0) {
            return bound;
        }
        //search for the left bound
        int start = 0;
        int end = A.length - 1;
        
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (A[mid] == target) {
                end = mid;
            }else if (A[mid] < target) {
                start = mid;
            }else {
                end = mid;
            }
        }
        
        if (A[start] == target) {
            bound[0] = start;
        }else if (A[end] == target) {
            bound[0] = end;
        }
        
        //search for the right bound
        start = 0;
        end = A.length - 1;
        
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (A[mid] == target) {
                start = mid;
            }else if (A[mid] < target) {
                start = mid;
            }else {
                end = mid;
            }
        }
        
        if (A[end] == target) {
            bound[1] = end;
        }else if (A[start] == target) {
            bound[1] = start;
        }
        
        return bound;

        
    }
}
