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
    string multiply(string num1, string num2) {
		if(num1.length() < num2.length())
			swap(num1,num2);
		string res = "";
		int size1 = num1.length(),size2 = num2.length();
		if(!size1 || !size2)
			return res;
		for(int i = 0;i < size2;i ++){
			int times = num2[i] - '0';
			string temp = "0";
			for(int j = 0;j < times; j ++)
				temp = add(temp, num1);
			res += "0";
			res = add(res,temp);
		}
		return res;
    }
    string add(string s1,string s2){
    	if(s1.length() < s2.length())
    		swap(s1,s2);
    	for(int i = s2.length();i < s1.length();i ++)
    		s2 = "0" + s2;
    	int size = s1.length();
    	string res = "";
		if(!size)
    		return "0";
    	int carry = 0;
    	for(int i = size - 1;i >= 0;i --){
    		int sum = carry + int(s1[i] - '0') + int(s2[i] - '0');
    		carry = sum / 10;
    		sum = sum % 10;
    		res = char('0' + sum) + res;
		}
		if(carry)
			res = "1" + res;
		return res;
	}
    void test(){
    	cout<<multiply("4751356","7542")<<endl;
    	cout<<multiply("0","0")<<endl;
    	cout<<add("1234","12")<<endl;

	}
};

int main(){
	Solution A;
	A.test();
	system("pause");
}


