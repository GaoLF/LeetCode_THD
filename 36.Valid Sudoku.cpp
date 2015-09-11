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
    bool isValidSudoku(vector<vector<char> >& board) {
        const int size = 9;
		for(int i = 0;i < size;i ++){
			unordered_set<int> set1,set2,set3;
			for(int j = 0;j < size;j ++){
				if(board[i][j]!='.'&&set1.find(board[i][j]) == set1.end())
					set1.insert(board[i][j]);
				else if(board[i][j]!='.')
					return false;
				if(board[j][i]!='.'&&set2.find(board[j][i]) == set2.end())
					set2.insert(board[j][i]);
				else if(board[j][i]!='.')
					return false;
				if(board[i/3*3+j/3][(i%3)*3+(j%3)]!='.'&&set3.find(board[i/3*3+j/3][i%3*3 + j%3]) == set3.end())
					set3.insert(board[i/3*3 + j/3][i%3*3 + j%3]);
				else if(board[i/3*3+j/3][(i%3)*3+j%3]!='.')
					return false;
			}
		} 
		return true;
    }
    void test(){
		vector<vector<char> > A;
		vector<char> B;
		B.push_back('.');
		B.push_back('8');
		B.push_back('7');
		B.push_back('6');
		B.push_back('5');
		B.push_back('4');
		B.push_back('3');
		B.push_back('2');
		B.push_back('1');
		A.push_back(B);
		B.clear();	
		B.push_back('2');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		A.push_back(B);
		B.clear();	
		B.push_back('3');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		A.push_back(B);
		B.clear();	
		B.push_back('4');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		A.push_back(B);
		B.clear();	
		B.push_back('5');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		A.push_back(B);
		B.clear();	
		B.push_back('6');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		A.push_back(B);
		B.clear();	
		B.push_back('7');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		A.push_back(B);
		B.clear();	
		B.push_back('8');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		A.push_back(B);
		B.clear();	
		B.push_back('9');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		A.push_back(B);
		cout<<isValidSudoku(A)<<endl;
	}
};

int main(){
	Solution A;
	A.test();
	system("pause");
}


