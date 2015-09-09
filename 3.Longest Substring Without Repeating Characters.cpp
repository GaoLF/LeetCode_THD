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

    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> map;
		int len = s.length();
		int start = 0;
		int res = 0;
		
		for(int i=0;i<len;i++){
			char ch = s[i];
			auto iter = map.find(ch);
			if(iter!=map.end()){
				int end = iter->second + 1;
				for(int j=start;j<end;j++)
					map.erase(s[j]); 
				start = end;  
			}
			else{
				res= max(res,i-start+1);
				
			}
			map.insert(make_pair(ch,i));
		}
		
		return res;
		 
    }
    void test(){
		cout<<lengthOfLongestSubstring("bbbbb")<<endl;
		cout<<lengthOfLongestSubstring("tmmzuxt")<<endl;
		cout<<lengthOfLongestSubstring("abcabcdefbb")<<endl;
		cout<<lengthOfLongestSubstring("abcdefg")<<endl;
	}
};

int main(){
	Solution A;
	A.test();
	system("pause");
}


