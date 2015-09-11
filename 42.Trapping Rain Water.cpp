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
    int trap(vector<int>& height) {
    	int res = 0;
    	int begin = 0;
    	int size = height.size();
    	if(size <= 2)
    		return 0;
        for(int i = begin + 1;i < size;i ++){
        	if(height[i] >= height[begin]){
        		for(int j = begin + 1;j < i;j ++){
        			res += (height[begin] - height[j]);
				}
				begin = i;
			}
		} 
		vector<int> temp;
		for(int i = begin + 1;i < size; i++)
			temp.push_back(height[i]);
		res += trap(temp); 
		
		return res;
    }
    void test(){
		int A[] = {0,1,0,2,1,0,1,3,2,1,2,1};
		vector<int> vec(A,A+12);
		cout<<trap(vec)<<endl;
	}
};

int main(){
	Solution A;
	A.test();
	system("pause");
}


