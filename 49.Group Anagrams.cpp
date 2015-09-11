#include<iostream>
#include<algorithm>
#include<string>
#include<unordered_set>
#include<unordered_map>
#include<math.h>
#include<stack> 
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > res;
		unordered_map<string,vector<string> > map;
		for(int i = 0;i < strs.size();i ++){
			string temp = strs[i];
			sort(temp.begin(),temp.end());
			if(map.find(temp) == map.end()){
				vector<string> vec;
				vec.push_back(strs[i]);
				map.insert(make_pair(temp,vec));
			}
			else{
				map[temp].push_back(strs[i]);
			}
		}
		for(auto iter = map.begin();iter != map.end();iter ++){
			sort(iter->second.begin(),iter->second.end());
			res.push_back(iter->second);
		}
		
		return res;
    }
    void test(){
    	string X[] = {"eat","tea","nat","bat","tan","ate"};
    	vector<string> A(X,X+6);
		vector<vector<string> > res = groupAnagrams(A);
		for(int i = 0;i < res.size(); i++){
			for(int j = 0;j < res[i].size();j ++)
				cout<<res[i][j]<<" ";
			cout<<endl;
		}
	}
};

int main(){
	Solution A;
	A.test();
	system("pause");
}


