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

    string longestPalindrome(string s) {
        
		int size = s.length();
		if(!size)
			return "";
		int max_v = 1;
		string res = s.substr(0,1);
		for(int i = 0;i < size; i++){
			if(i - max_v >= 1){
				string temp = s.substr(i-max_v-1,max_v+2);
				int flag = 0;
				for(int j = 0;j < (max_v + 2); j++){
					if(temp[j] != temp[max_v+1-j]){
						flag = 1;
						break;
					}
				}
				if(!flag){
					res = temp;
					max_v += 2;
					continue;
				} 
			}	
			if(i - max_v >= 0){
				string temp = s.substr(i-max_v,max_v+1);
				int flag = 0;
				for(int j = 0;j < (max_v + 1);j++){
					if(temp[j] != temp[max_v - j]){
						flag = 1;
						break;
					}
				}
				if(!flag){
					res = temp;
					max_v += 1;
				}
			}	
		}
		return res; 
    }
    
    void test(){
		cout<<longestPalindrome("aaaaaaavdddddd")<<endl;
		cout<<longestPalindrome("aabaaa")<<endl;
		cout<<longestPalindrome("a")<<endl;
		cout<<longestPalindrome("abcdeffedafg")<<endl;
	}
};

int main(){
	Solution A;
	A.test();
	system("pause");
}


