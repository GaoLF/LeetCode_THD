#include<iostream>
#include<algorithm>
#include<string>
#include<unordered_set>
#include<unordered_map>
#include<stack> 
#include<limits>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

    int reverse(int x) {
        int sign = x < 0 ? -1 : 1;//1 means positive
       // if(x == INT_MIN)
        //	return 0;
        x = abs(x);
		int res = 0;
		
		while(x){
			int temp = x % 10;
			x = x / 10;
			if(res > INT_MAX/10 || (res == INT_MAX/10 && temp >= 8))
				return 0;
			res = res * 10 + temp;
		}
		//if(res == )
		return res*sign; 
		
    }
    void test(){
		cout<<reverse(123)<<endl;
		cout<<reverse(-12342)<<endl;
		cout<<reverse(-123420000)<<endl;
		cout<<reverse(-123004200)<<endl;
		cout<<INT_MAX<<endl;//2147483647
		cout<<reverse(1563847412)<<endl;
		cout<<reverse(1463847412)<<endl;
		cout<<reverse(-1463847412)<<endl;
		//cout<<reverse(INT_MAX)<<endl;
		cout<<reverse(INT_MAX)<<endl;
		cout<<reverse(INT_MIN)<<endl;
		//cout<<reverse(123)<<endl;
	}
};

int main(){
	Solution A;
	A.test();
	system("pause");
}


