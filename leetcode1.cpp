struct NumberSet
{
	int numbers;
	int index;
	NumberSet(int n,int i):numbers(n),index(i){}
};
bool my_order(struct NumberSet a,struct NumberSet b)
{
	return (a.numbers<=b.numbers);
}
class Solution {  
public:  
    vector<int> twoSum(vector<int> &numbers, int target) {  
		vector <NumberSet> v;
		vector <int> result;
		for(int i=0;i<numbers.size();i++)
		{
			v.push_back(NumberSet(numbers[i],i));
		}
		sort(v.begin(),v.end(),my_order);

		int i=0,j=numbers.size()-1;
		while(i<=j)
		{
			if(v[i].numbers+v[j].numbers==target)
			{
				result.push_back(v[i].index);
				result.push_back(v[j].index);
				sort(result.begin(),result.end());
				return result;
			}
			if(v[i].numbers+v[j].numbers>target)
				j--;
			else
				i++;
		}
    }  
}; 