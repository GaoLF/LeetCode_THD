#include<iostream>
#include<algorithm>
#include<string>
#include<unordered_set>
#include<unordered_map>
#include<stack>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isValid(string s) {
        stack<char> vec;
        int size = s.length();
//		for(int i = 0;i < size;i ++)
//			vec.push_back(s[i]);
		for(int i = 0;i < size;i ++){
			if(s[i] == '(' ||s[i] == '['||s[i] == '{')
				vec.push(s[i]);
			else {
				//vector<char>::iterator iter;
				if(s[i] == ')'){
					if(vec.size() && vec.top() == '(')
						vec.pop();
					else
						return false;
				}
				else if(s[i] == ']'){
					if(vec.size() && vec.top() == '[')
						vec.pop();
					else
						return false;
				}
				else if(s[i] == '}'){
					if(vec.size() && vec.top() == '{')
						vec.pop();
					else
						return false;
				}
			}
		}
		if(vec.empty())
			return true;
		else
			return false; 
    }
    void test(){
		cout<<isValid("()")<<endl;
		cout<<isValid("({()}{{[]}})")<<endl;
		cout<<isValid("([)]")<<endl;
		cout<<isValid("({()}{{[]}})")<<endl;
	}
};

int main(){
	Solution A;
	A.test();
	system("pause");
}


