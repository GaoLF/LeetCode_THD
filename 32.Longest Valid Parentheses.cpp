#include<iostream>
#include<algorithm>
#include<string>
#include<unordered_set>
#include<unordered_map>
#include<stack> 
#include<math.h>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int longestValidParentheses(string s) {
		vector<int> vec;
		int res = 0;
		if(s.empty())
			return 0;
			
		for(int i = 0;i < s.length();i ++){
			if(s[i] == '(')
				vec.push_back(i);
			else if(vec.empty() || s[*(vec.end() - 1)] == ')')
				vec.push_back(i);
			else
				vec.erase(vec.end() - 1);
		} 
		for(int i = 0;i + 1 < vec.size(); i++){
			res = max(res,vec[i + 1] - vec[i] - 1);
		}
		res = max(res,vec[0]);
		res = max(res,(int)(s.length() - *(vec.end() - 1) - 1) );
		if(vec.empty())
			return s.length();
		else
			return res;
    }
    void test(){
		cout<<longestValidParentheses("(((())(()()()()())))")<<endl;
		cout<<longestValidParentheses(")()())")<<endl;
		cout<<longestValidParentheses("()(()")<<endl;
		
	}
};

int main(){
	Solution A;
	A.test();
	system("pause");
}


