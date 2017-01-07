class Solution {
private:
    bool isoverflow(int pre,int last,int _sign){
        int last_max = (_sign==1)?INT_MAX%10:INT_MAX%10+1;
        if(pre>INT_MAX/10 || ((pre==INT_MAX/10)&& (last>INT_MAX%10))) return true;
        return false;
    }
public:
    int reverse(int x) {
        if(x==INT_MIN) return 0;
        int _sign = x<0?-1:1;
        x = x*_sign;
        int r=0;
        while(x){
            if(isoverflow(r,x%10,_sign)) return 0;
            r = r*10+x%10;
            x = x/10;
        }
        return r*_sign;
        
    }
};

class Solution {
public:
    int reverse(int x) {
        if(x==INT_MIN) return 0;
        int _sign = x<0?-1:1;
        x = x*_sign;
        int r=0;
        while(x){
            int tmp = r*10+x%10;
            if((tmp-x%10)/10!=r) return 0;
            r = tmp;
            x = x/10;
        }
        return r*_sign;
        
    }
};
