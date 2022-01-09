class Solution {
public:
    double myPow(double x, int n) {
   //Optimal 
        //ans variable is used to return final value
        double ans=1.0;
        //new_num is used for further modification so we dont use n directly 
        long long new_num=n;
        
        //anything raised to pow 0 is 1
        if(n==0)
            return 1;
        
        //when n is -ve make the negative n into positive n
        if(new_num<0)
            new_num=new_num*-1;
        
        //keep loop running as long as new_num!=0
        //loop is to find final ans 
        while(new_num>0)
        {
            //if number is even make org number x as double of itself and make new_num half
            if(new_num%2==0)
            {
                x=x*x;
                new_num=new_num/2;
            }
//if number is odd make ans=ans*x and reduce the new_num by 1
//the final step would always result in new_num being odd (i.e ==1) so ans=previous existing ans*x AND reduce new_num by 1 so that new_num becomes 0 and you break the loop
            if(new_num%2==1)
            {
                ans=ans*x;
                new_num=new_num-1;
            }
        }
        
        //if power n<0 then new ans would be 1/ans
        if(n<0)
           ans= 1.0/ans;
        
        return ans;    
    }
};
//TC: O(log2 n)[keep dividing new_num by 2 when even and reducing by 1 when odd] 
//SC: O(1) [no extra space is used]

/* BRUTE FORCE: ---------------------------------------------------------------------------------*/

/*class Solution {
public:
    double myPow(double x, int n) {
        
        //keep one variable for when power is +ve and one when -ve
        long double positive_ans = 1;
        long double negative_ans;
        int i, k;
        
        //anything raised to pow 0 is 1
        if(n==0)
            return 1;
        
         //since n is +ve directly return 
       if(n>0)
       {
           //keep traversing from 1 to n to multiply the number that many times 
            for(i=1;i<=n;i++)
            {
                positive_ans=positive_ans*x;
            } 
           return positive_ans;
       }
       
       
        //when n is -ve make the negative n into positive n and storing in new variable k
        //repeat process as we do for +ve numbers
        //divide by 1 because x^-n is 1/x^n
      if(n<0)
      {
          k=n*(-1);
          for(i=1;i<=k;i++)
        {
            positive_ans=positive_ans*x;
        }
           negative_ans= 1/positive_ans;
          return negative_ans;
      }
        return -1;
    }
};
//TC: O(n) [traversing from  1..n]
//SC: O(1)
*/