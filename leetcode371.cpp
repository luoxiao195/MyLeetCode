class Solution {
public:
    int getSum(int a, int b) {
        int sum=a^b;
		int carry=a&b;
		while(carry!=0)
		{
			a=sum;
			b=carry<<1;
			sum=a^b;
			carry=a&b;
		}
		return sum;
    }
};