class Solution {
public:
    //climbStairs(n)=climbStairs(n-1)+climbStairs(n-2);
    int climbStairs(int n) {
        if(n==1) return 1;
        if(n==2) return 2;
        int r, n1=1, n2=2;
        for(int i=3; i<=n; i++){
            r = n1 + n2;
            n1=n2; 
            n2=r;
        }
        return r;
    }
};
