#include<iostream>
#include<algorithm>
#include<string>
#include<unordered_set>
#include<unordered_map>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
		
		for(int i = 0; i < n; i++){
			vector<string> temp;
			if(res.empty())
				temp.push_back("()");
			else{
				for(int j = 0;j < res.size(); j++){
					string str = res[j];
					for(int m = 0;m < str.length(); m++){
						string cur = str;
						cur.insert(m,"()");
						if(find(temp.begin(),temp.end(),cur)==temp.end())
							temp.push_back(cur);
					}
				}
			}
			res = temp;
		}
		
		return res;
    }
    void test(){
		vector<string> A = generateParenthesis(3);
		for(int i = 0;i < A.size();i++){
			cout<<A[i]<<" ";
		}
		cout<<endl;
	}
};

int main(){
	Solution A;
	A.test();
	system("pause");
}


