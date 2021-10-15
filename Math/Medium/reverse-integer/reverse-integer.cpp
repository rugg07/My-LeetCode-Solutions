class Solution {
public:
    int reverse(int x) {
        long quo=1;
        long rem=0;
        int temp=x;
        long digits=0;
        long k=1;
        while(x!=0)
        {
            x=x/10;
            digits++;
        }
        while(temp!=0)
        {
            quo=temp%10;
            rem=rem+quo*pow(10,digits-k);
            temp=temp/10;
            k++;
        }
        if(rem<pow(-2,31) || rem>(pow(2,31)-1))
            return 0;
        return rem;
    }
};