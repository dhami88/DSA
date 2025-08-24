class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int a=1;
        int b=2;
        int suma=1;
        int sumb=2;
        for(int i=1;i<n;i++){
            a+=2;
            suma+=a;
            b+=2;
            sumb+=b;
        }
        cout<<suma<<sumb;
        return gcd(suma,sumb);
    }
};