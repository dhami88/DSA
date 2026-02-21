class Solution {
bool isprime(int n){
    if(n==1) return false;
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}

public:
    int countPrimeSetBits(int left, int right) {
        int count=0;
     for(int j=left;j<=right;j++){
       int setbits=__builtin_popcount(j);
       if(isprime(setbits)) count ++;
     }   
     return count;
    }
};