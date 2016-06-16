#include <iostream>
#include <cmath>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <unordered_set>

using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		unordered_set<int> nums;
		for(auto x:nums1){
			nums.insert(x);
		}
		vector<int> r;
		unordered_set<int> dup;
		for(auto x:nums2){
			if(nums.count(x)){
				if(!dup.count(x))
					r.push_back(x);
				dup.insert(x);
			}
		}
		return r;
    }
};