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
    void rotate(vector<vector<int>>& matrix) {
    	int size = matrix.size();
        for(int i = 0;i < (size / 2);i ++){
        	rotateHelper(matrix ,i ,size - i*2); 
		} 
    }
    void rotateHelper(vector<vector<int> > &m,int begin,int step){
    	step --;
    	for(int i = 0;i < (step );i ++){
    		int temp = m[begin + step][begin + step - i];
    		m[begin + step][begin + step - i] = m[begin + i][begin + step]; 
			m[begin + i][begin + step] = m[begin][begin + i];
			m[begin][begin + i] = m[begin + step - i][begin];
			m[begin + step - i][begin] = temp; 	
		}
	}
    void test(){
    	int A[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
		vector<int> vec1(A,A+4);
		vector<int> vec2(A+4,A+8);
		vector<int> vec3(A+8,A+12);
		vector<int> vec4(A+12,A+16);
		vector<vector<int> > res;
		res.push_back(vec1);
		res.push_back(vec2);
		res.push_back(vec3);
		res.push_back(vec4);
		rotate(res);
		int size = 4; 
		for(int i = 0;i < size;i ++){
			for(int j = 0;j < size;j ++ ){
				cout<<res[i][j]<<" ";
			}
			cout<<endl;
		}			
		cout<<endl;
	}
};

int main(){
	Solution A;
	A.test();
	system("pause");
}


