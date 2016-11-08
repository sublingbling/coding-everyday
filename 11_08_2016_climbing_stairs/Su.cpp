class Solution {
public:
    int climbStairs(int n) {
        if(n<=0) return 0;
        
        int base1, base2, sum;
        base1=base2=sum=1;
        while(--n){
            sum = base1+base2;
            base1 = base2;
            base2 = sum;
        }
        return sum;
    }
};
