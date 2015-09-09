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
    int strStr(string haystack, string needle) {
        int size_h = haystack.size();
		int size_n = needle.size();
		int i,j;
		if(needle.empty())
			return 0;
			 
		for(i = 0;i < (size_h - size_n);i ++){
			for(j = 0;j < size_n;j ++){
				if(haystack[i + j] == needle[j])
					continue;
				else
					break;
			}
			if(j == size_n)
				return i;
		}
		return -1;
    }
    void test(){
		cout<<strStr("abcdefghigh","cde")<<endl;
		cout<<strStr("abcdefghigh","")<<endl;
		cout<<strStr("a","a")<<endl;
	}
};

int main(){
	Solution A;
	A.test();
	system("pause");
}


