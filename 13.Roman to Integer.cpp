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
    int romanToInt(string s) {
    	vector<int> vec;
    	int res = 0;
    	for(int i = 0;i < s.length(); i++ ){
    		switch(s[i]){
    			case 'I': vec.push_back(1);break;
    			case 'V': vec.push_back(5);break;
    			case 'X': vec.push_back(10);break;
    			case 'L': vec.push_back(50);break;
    			case 'C': vec.push_back(100);break;
    			case 'D': vec.push_back(500);break;
    			case 'M': vec.push_back(1000);break;
    		}
		}
		for(int i = 0;i < s.size(); i++){
			if(i + 1 < vec.size() && vec[i] < vec[i+1])
				res -= vec[i];
			else
				res += vec[i];
		}
		
		return res;
	}
    void test(){
		cout<<romanToInt("")<<endl;
		cout<<romanToInt("XXXIV")<<endl;
		cout<<romanToInt("MDCLXVI")<<endl;
		cout<<romanToInt("MDCCCLXXXVIII")<<endl;
	}
};

int main(){
	Solution A;
	A.test();
	system("pause");
}


