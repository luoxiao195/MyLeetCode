class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int len=nums.size();
		if(len==0)
			return 0;
		int res=0;
		for(int i=0;i<len;i++)
			res^=nums[i];
		return res;
    }
};