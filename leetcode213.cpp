class Solution {
public:
    int rob(vector<int>& nums) {
      int len=nums.size();
		if(len==0)
			return 0;
		else if(len==1)
			return nums[0];

		int *dp=new int [len+1];
		for(int i=0;i<=len;i++)
			dp[i]=0;
	
		dp[1]=nums[0];
		for(int i=2;i<len;i++)
		{
			if((dp[i-2]+nums[i-1])>dp[i-1])
				dp[i]+=dp[i-2]+nums[i-1];
			else
				dp[i]+=dp[i-1];
		}
		int res=dp[len-1];

		
		for(int i=0;i<len;i++)
			dp[i]=0;
		dp[1]=nums[1];

		for(int i=2;i<len;i++)
		{
			if((dp[i-2]+nums[i])>dp[i-1])
				dp[i]+=dp[i-2]+nums[i];
			else
				dp[i]+=dp[i-1];
		}


		return max(res,dp[len-1]);
    }
};