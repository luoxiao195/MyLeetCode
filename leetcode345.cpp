class Solution {
public:
    string reverseVowels(string s) {
       int len_s=s.length();
		int len_n=0;
		char  lch,rch;
		int i=0,j=len_s-1;
		while(i<j)
		{
			while(i<j)
			{
				if(s[i] == 'U' || s[i] == 'A' 
				|| s[i] == 'E' || s[i] == 'I' 
				|| s[i] == 'O' || s[i] == 'a' 
				|| s[i] == 'e' || s[i] == 'i' 
				|| s[i] == 'o' || s[i] == 'u')
				{
					lch=s[i];
					break;
				}
				i++;
			}
			while(i<j)
			{
				if(s[j] == 'U' || s[j] == 'A' 
				|| s[j] == 'E' || s[j] == 'I' 
				|| s[j] == 'O' || s[j] == 'a' 
				|| s[j] == 'e' || s[j] == 'i' 
				|| s[j] == 'o' || s[j] == 'u')
				{
					rch=s[j];
					break;
				}
				j--;
			}
			if(i<j)
			{
				s[i++]=rch;
				s[j--]=lch;
			}
		}
		return s;
    }
};