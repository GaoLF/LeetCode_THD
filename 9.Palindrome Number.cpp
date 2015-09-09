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

    bool isPalindrome(int x) {
        double temp = 1;
        int width;
        //x = abs(x);
        if(x<0)
            return 0;
		while(int(x/temp))
			temp *= 10;
		//cout<<"!"<<temp<<endl;
		width = temp/10;
		//cout<<width;
		
		while(x){
			if(x%10 != x/width)
				return 0;
			x = (x%width)/10;
			width/=100;
		}
		return 1;	
    }
    void test(){
		cout<<isPalindrome(INT_MIN)<<endl;
		cout<<isPalindrome( 1000000001)<<endl;
		cout<<isPalindrome(  123442321)<<endl;
		cout<<isPalindrome(-1234542321)<<endl;
	}
};

int main(){
	Solution A;
	A.test();
	system("pause");
}


