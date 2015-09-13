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
    int uniquePaths(int m, int n) {
    	unordered_map<int,int> map;
		return solveHelper(map,m,n);
    }
    int solveHelper(unordered_map<int,int> &map,int m, int n){
    	if(!m || !n)
			return 0;
		if(m == 1 || n == 1)
			return 1;
		auto iter = map.find((m<<16)+n);
		if(iter != map.end())
			return iter->second;
		int res = solveHelper(map,m-1,n) + solveHelper(map,m,n-1);   
		//map[(m<<16)+n] = res;
		map.insert(make_pair((m<<16)+n,res));
		//cout<<res<<endl;
		return res;
		
	}
    void test(){
		cout<<uniquePaths(23,12)<<endl;
	}
};

int main(){
	Solution A;
	A.test();
	system("pause");
}


