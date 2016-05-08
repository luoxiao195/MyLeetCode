class Solution {
public:
    int singleNumber(vector<int>& nums) {
          int len=nums.size();
		if(len==0)
			return 0;
		int bitnum[32]={0};
		for(int i=0;i<32;i++)
			for(int j=0;j<len;j++)
			{
				bitnum[i]+=(nums[j]>>i)&1;
			}
		int res=0;
		for(int i=0;i<32;i++)
			res+=(bitnum[i]%3)<<i;
		return res;
    }
};