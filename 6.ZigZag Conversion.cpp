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

    string convert(string s, int numRows) {
    	if(numRows<=1)
			return s; 
        int step = 2*(numRows - 1);
		int len = s.length();
		int k = len/step;
		string res;

		for(int i = 0; i < numRows; i++){
			for(int j = 0; j <= k; j ++){
				int first = step * j + i;
				int second = step * (j + 1) - i;
				if(first < len)
					res += s[first];
				if(second < len && (first != second && second - first != step) )
					res += s[second];	
			}
		}
		return res;
    }
    void test(){
		cout<<convert("PAYPALISHIRING", 3);
	}
};

int main(){
	Solution A;
	A.test();
	system("pause");
}


