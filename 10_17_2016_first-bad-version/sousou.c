// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int firstBadVersion(int n) {
    if (0==n) return -1;
    
    unsigned int low=1, high=n, mid=(low+high)>>1;
    while(low<high)
    {
        mid=(low+high)>>1;
        if(isBadVersion(mid)) high=mid;
        else low=mid+1;
    }
    if (isBadVersion(high)) return high;
    else return -1;
}
