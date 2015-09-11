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
    vector<int> findSubstring(string s, vector<string>& words) {
    	unordered_map<string,int> map;
    	vector<int> res;
    	int j;
    	
		if(s.empty()||words.empty())
	   		return res; 
	   	int step = words[0].size();
	   	int count = words.size();
	   	//cout<<step<<" "<<count<<" "<<s.length()<<endl;
	   	for(int i = 0;i < count;i ++){
	   		map[words[i]] += 1;	
		}
		for(int i = 0;i < (int(s.length()) - count*step + 1);i ++){
			//cout<<i<<" "<<s.length() - count*step<<endl;
			unordered_map<string,int> temp = map;
			for(j = 0;j < count;j ++){
				string sub = s.substr(i + j*step,step);
				cout<<sub<<endl;
				if(temp[sub] > 0)
					temp[sub] --;
				else
					break;
			}
			if(j == count)
				res.push_back(i);
		}
		return res;
    }
    void test(){
		vector<int> vec;
		vector<string> words;
		words.push_back("word");
		words.push_back("good");
		words.push_back("best");
		words.push_back("good");
		vec = findSubstring("wordgoodgoodgoodbestword",words);
		for(int i = 0;i < vec.size();i ++)
			cout<<vec[i]<<" ";
		cout<<endl;
	}
};

int main(){
	Solution A;
	A.test();
	system("pause");
}


