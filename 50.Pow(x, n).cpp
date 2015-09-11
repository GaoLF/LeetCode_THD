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
    double myPow(double x, int n) {
    	if(int(x) == 0)
			return 0;
		if(!n)
			return 1;
		int step = 1;
		double res = 1;
		double num = x;
		int sign = n>0?1:0;
		n = abs(n); 
		while(n){
			if(step<n){
				res*=num;
				n-=step;
				num*=num;
				step*=2;
			}else{
				step=1;
				num=x;
				res*=num;
				n-=step;
			}
		}   
		if(sign) 
			return res;
		else
			return 1/res;
    }
    void test(){
		cout<<myPow(3,5)<<endl;
		cout<<myPow(23,2)<<endl;
		cout<<myPow(2,10)<<endl;
	}
};

int main(){
	Solution A;
	A.test();
	system("pause");
}


