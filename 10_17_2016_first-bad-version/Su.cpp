class Solution {
public:
    int firstBadVersion(int n) {
        int L=1;int R=n;
        while(L<R){
            int M=(L>>1) + (R>>1);
            if(isBadVersion(M)) R=M;
            else L=M+1;
        }
        return L;
    }
};
