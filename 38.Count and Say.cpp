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
    string countAndSay(int n) {
    	string res = "1";
		if(!n)
			return "";
		for(int i = 1;i < n;i ++){
			string temp = "";
			for(int j = 0,count = 1;j < res.length();j ++){
				//cout<<count<<endl;
				if(j + 1 < res.length() && res[j] == res[j + 1]){
					count += 1;
				}
				else{
					char cur[100] ;
					sprintf(cur,"%d",count);
					
					temp += cur;
					temp += res[j];
					count = 1;
				}
			}
			res = temp;
		} 
		return res;
    }
    void test(){
		cout<<countAndSay(1)<<endl;
		cout<<countAndSay(2)<<endl;
		cout<<countAndSay(3)<<endl;
		cout<<countAndSay(4)<<endl;
	}
};

int main(){
	Solution A;
	A.test();
	system("pause");
}


