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

    string longestCommonPrefix(vector<string>& strs) {
    	if(strs.empty()) 
    		return "";
        return Prefix(strs,0,strs.size()-1);
    }
    string Prefix(vector<string>& strs,int begin,int end){
    	string s1,s2;
		if(begin == end){
    		return strs[begin];
		}
		if(end - begin == 1){
			s1 = strs[begin];
			s2 = strs[end];
		}
    	else{
    		s1 = Prefix(strs,begin,(begin+end)/2);
    		s2 = Prefix(strs,(begin+end)/2+1,end);
		}
    	
		return merge(s1,s2); 
	} 
	string merge(string s1,string s2){
		int len1 = s1.length();
		int len2 = s2.length();
		int res = 0;
		
		for(int i = 0;i < len1 && i < len2; i++){
			if(s1[i] == s2[i])
				res ++;
			else
				break;
		}
		return s1.substr(0,res);
	}
    void test(){
		vector<string> a;
		a.push_back("abcdef");
		a.push_back("abcdxx");
		a.push_back("abcdraf");
		a.push_back("xccdef");
		cout<<longestCommonPrefix(a)<<endl;
	}
};

int main(){
	Solution A;
	A.test();
	system("pause");
}


