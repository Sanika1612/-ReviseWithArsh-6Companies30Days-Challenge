class Solution {
public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        long long l=0, r=10000000000;
        //The main and powerful hint is We will get out ans at a+b-c >=uniqueCnt1+ uniqueCnt2 
        //a: Numbers which can be part of uniqueCnt1
        //b: Numbers which can be part of uniqueCnt2
        //c:  Numbers which can be part of both uniqueCnt1 and uniqueCnt2

         //By using set theory we can write a+b-c >=uniqueCnt1+ uniqueCnt2
         
        while(l<=r){
            long long mid=l+(r-l)/2;
            long long a=mid-(mid/divisor1); //Numbers which are not divisible d1
            long long b=mid-(mid/divisor2);  //Numbers which are not divisible d2
            long long lcm=(long long)((long long)divisor1*divisor2)/(long long)__gcd(divisor1, divisor2);
            long long c=mid- (mid/divisor1) -(mid/divisor2) +(mid/lcm); 
            //c is number of elements which are neither divisible by d1 nor by d2 (not divisible by both d1 and d2). this can be obtained by subtracting numbers which are divisible by either d1 or d2. While subtracting numbers which are divisible by both d1 and d2(mid /LCM of d1 and d2)gets subtracted twice so we have to add it once.
             

             //This is the main condition
            if(a>=uniqueCnt1 && b>=uniqueCnt2 && a+b-c>=(long long)uniqueCnt1+ uniqueCnt2){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
    
};
