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
	string intToRoman(int num) {
        char dic1[]= {'I','X','C','M'};
		char dic2[]= {'V','L','D'};
		int step = 1000;
		int flag = 3;
		string res = "";
		
		while(num){
			int count = num/step;
			if(!count)
				;
			else if(count<4){
				res += (count * dic1[flag]);
				//for(int i = 0;i < count; i++)
				//	res += dic1[flag]; 
			}
			else if(count == 4){
				res += dic1[flag];
				res += dic2[flag];
			}	
			else if(count < 9){

				res += dic2[flag];
				//res += ((count - 5) * dic1[flag]);
				for(int i =0;i<(count-5);i++)
					res += dic1[flag];
			}
			else{
				res += dic1[flag];
				res += dic1[flag + 1]; 
			}
			flag --;
			num = num - count*step;
			step/=10;	 
		}
		
		return res;
    }
    void test(){
		cout<<intToRoman(1984)<<endl;
		cout<<intToRoman(1666)<<endl;
		cout<<intToRoman(0)<<endl;
	}
};

int main(){
	Solution A;
	A.test();
	system("pause");
}


