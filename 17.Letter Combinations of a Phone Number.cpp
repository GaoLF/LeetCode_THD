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
    vector<string> letterCombinations(string digits) {
    	vector<string> res;
		
		for(int i = 0; i < digits.size(); i++){
			vector<string> temp;
			string dic;
			switch(digits[i]){
				case '2': dic = "abc";break; 
				case '3': dic = "def";break;
				case '4': dic = "ghi";break;
				case '5': dic = "jkl";break;
				case '6': dic = "mno";break;
				case '7': dic = "pqrs";break;
				case '8': dic = "tuv";break;
				case '9': dic = "wxyz";break;
				case '0': dic = " ";break;
			}
			if(res.empty()){
				for(int j = 0;j < dic.length(); j++){
					string cur = "1";
					cur[0] = dic[j];
					//cout<<cur<<" "<<dic[j]<<endl;
					temp.push_back(cur);
				}
					
			}
			else{
				for(int j = 0;j < dic.length(); j++){
					for(int m = 0;m < res.size(); m ++){
						string foo = res[m];
						foo += dic[j];
						temp.push_back(foo);
					}
				}
			}
			res = temp;
		}
		
		return res;
    }
    void test(){
    	vector<string> A;
    	A = letterCombinations("");
    	for(int i = 0;i < A.size(); i ++){
    		cout<<A[i]<<endl;
		}
	}
};

int main(){
	Solution A;
	A.test();
	system("pause");
}


