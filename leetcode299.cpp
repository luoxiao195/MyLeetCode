class Solution {
public:
    string getHint(string secret, string guess) {
        if(secret.length()==0||guess.length()==0||secret.length()!=guess.length())
			return "0A0B";
		int countA=0;
		int countB=0;
		int temp[10]={0}; 
		int len=secret.length();
		for(int i=0;i<len;i++)
		{
			if(secret[i]==guess[i])
				countA++;
			else
			{
				temp[secret[i]-'0']++;
				if(temp[secret[i]-'0']<=0)
					countB++;
				temp[guess[i]-'0']--;
				if(temp[guess[i]-'0']>=0)
					countB++;
			}
		}
		char res[6];
		sprintf(res,"%dA%dB",countA,countB);
		return res;
    }
};