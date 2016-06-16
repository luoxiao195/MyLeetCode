class Solution {
public:
    int numDecodings(string s) {
       int n=s.length();
        if(n==0 ) return 0;
        int i;  
        int *dp=new int[n+1];
		fill(dp,dp+n+1,0);

		dp[0]=1;

		if(isdigit(s[0])&&s[0]!='0')
		{
			dp[1]=1;
		}
		else
			dp[1]=0;
		for(i=1;i<n;i++)
		{
			if(isdigit(s[i])&&s[i]!='0')
				dp[i+1]+=dp[i];
			if(s[i-1]=='1'&&s[i]>='0'&&s[i]<='9'||s[i]>='0'&&s[i]<='6'&&s[i-1]=='2')
			{
				dp[i+1]+=dp[i-1];
			}
		}
		return dp[n];

    
    }
};