class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor==0)
			return false;

		bool isNeg=(dividend^divisor)>>32==1;
		int res;
		if(dividend==0)
			return 0;
		dividend=abs(dividend);
		divisor=abs(divisor);
		int digit=0;
		while(divisor<=(dividend>>1))
		{
			divisor<<=1;
			digit++;
		}
		while(digit>=0)
		{
			if(dividend>=divisor)
			{
				res+=1<<digit;
				dividend-=divisor;
			}
			divisor>>=1;
			digit--;
		}
		return isNeg?-res:res;
    }
};