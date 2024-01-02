class Solution {
public:
    long lcm(long a, long b){
        return (a/__gcd(a, b)) * b;
    }

    long minimizeSet(long d1, long d2, long u1, long u2) {
        auto ok = [&](long &m){
            long d = m/lcm(d1, d2);
            long n1 = m/d2 - d;
            long n2 = m/d1 - d;

            long left = m - n1 - n2 - d;

            n1 = max(0l, u1 - n1);
            n2 = max(0l, u2 - n2);

            return (n1 + n2) <= left;
        };
        
        long l = u1+u2, h = 2*(u1 + u2);
        long ans = h;

        while(l <= h){
            long m = (h - l)/2 + l;

            if(ok(m)){
                ans = m;
                h = m-1;
            } else {
                l = m+1;
            }
        }

        return ans;
    }
};