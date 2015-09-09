#include<iostream>
#include<algorithm>
#include<string>
#include<unordered_set>
#include<unordered_map>

using namespace std;

class Solution {
public:

    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        vector<int> res;
		if(!size)
        	return res;
        unordered_map<int,int> map;
        
		for(int i = 0; i < size; i++){
			auto temp = map.find(target - nums[i]);
			if( temp != map.end()){
				res.push_back(temp->second + 1);
				res.push_back(i + 1);
				break;
			}
			else
				map.insert(make_pair(nums[i],i));
		}
		return res;
    }
    void test(){
    	vector<int> a;
    	a.push_back(2);
    	a.push_back(7);
    	a.push_back(11);
    	a.push_back(15);
    	vector<int> res = twoSum(a,9);
    	for(int i = 0; i < res.size(); i ++)
    		cout<<res[i]<<" ";
		cout<<endl;
	}
};

int main(){
	Solution A;
	A.test();
	system("pause");
}


