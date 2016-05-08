class Solution {
public:
    vector<int> countBits(int num) {
        vector <int> ret;
		ret.push_back(0);

		int newFac=2;
		int oldFac=1;

		for(int i=1;i<=num;i++)
		{
			if(i<newFac&&i>=oldFac)
			{
				ret.push_back(ret[i-oldFac]+1);
			}
			else
			{
				i--;
				oldFac=newFac;
				newFac*=2;
			}
		}
		return ret;
    }
};