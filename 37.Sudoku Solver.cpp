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
    void solveSudoku(vector<vector<char> >& board) {
        cout<<solve(board,0,0)<<endl; 
    }
    bool solve(vector<vector<char> >& b,int i,int j){
    	//cout<<i<<" "<<j<<endl;
    	if(i == 8 && j == 9){
    		cout<<"!!!!"<<endl; 
    		return true;
		}	
    	if(j == 9){
    		j = 0;
    		i ++;
		}
		if(b[i][j] != '.')
			return solve(b,i,j+1);
		for(char m = '1';m <= '9';m ++){
			b[i][j] = m;
			if(check(b,i,j)){
				//cout<<i<<" "<<j<<" "<<m<<endl; 
				if(solve(b,i,j+1))
					return true;
			}
			//cout<<m<<endl; 
		} 
		b[i][j] = '.';
		return false;
	}
    
    bool check(vector<vector<char> >& b,int i,int j){
    	char ch = b[i][j];
    	
		for(int m = 0;m < 9;m ++){
    		if(m!=i&&b[m][j] == ch)
    			return false;
    		if(m!=j&&b[i][m] == ch)
    			return false;
    		int p = i/3*3 + (m/3);
    		int q = j/3*3 + (m%3);
    		if((p!=i&&q!=j)&&b[p][q]==ch)
    			return false;
		}
		return true;
	}
    void test()    {
		vector<vector<char> > A;
		vector<char> B;
		B.push_back('.');
		B.push_back('.');
		B.push_back('9');
		B.push_back('7');
		B.push_back('4');
		B.push_back('8');
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
		B.push_back('.');	
		B.push_back('2');
		B.push_back('.');
		B.push_back('1');
		B.push_back('.');
		B.push_back('9');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		A.push_back(B);
		B.clear();	
		B.push_back('.');
		B.push_back('.');
		B.push_back('7');
		B.push_back('.');
		B.push_back('.');
		///B.push_back('.');
		B.push_back('.');
		B.push_back('2');
		B.push_back('4');
		B.push_back('.');
		A.push_back(B);
		B.clear();	
		B.push_back('.');
		B.push_back('6');
		B.push_back('4');
		B.push_back('.');
		B.push_back('1');
		B.push_back('.');
		B.push_back('5');
		B.push_back('9');
		B.push_back('.');
		A.push_back(B);
		B.clear();	
		B.push_back('.');
		B.push_back('9');
		B.push_back('8');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('3');
		B.push_back('.');
		B.push_back('.');
		A.push_back(B);
		B.clear();	
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('8');
		B.push_back('.');
		B.push_back('3');
		B.push_back('.');
		B.push_back('2');
		B.push_back('.');
		A.push_back(B);
		B.clear();	
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('6');
		A.push_back(B);
		B.clear();	
		B.push_back('.');
		B.push_back('.');
		B.push_back('.');
		B.push_back('2');
		B.push_back('7');
		B.push_back('5');
		B.push_back('9');
		B.push_back('.');
		B.push_back('.');
		A.push_back(B);
		solveSudoku(A);
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++)
				cout<<A[i][j];
			cout<<endl;
		}
	}
};

int main(){
	Solution A;
	A.test();
	system("pause");
}


