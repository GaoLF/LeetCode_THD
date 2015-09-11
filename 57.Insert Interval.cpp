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
struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
     //bool operator <(const Interval &);
 };
 
bool operator <(const Interval& A,const Interval& B){
	return A.start < B.start;
}
class Solution {
public:
	vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval>  res;
        sort(intervals.begin(),intervals.end());
        for(int i = 0;i < intervals.size();i ++){
        	if(!i)
        		res.push_back(intervals[i]);
        	else{
        		int size = res.size() - 1;
				Interval temp = res[size];
				//cout<<intervals[i].start<<"!!"<<temp.start<<endl; 
				if(intervals[i].start > temp.end)
					res.push_back(intervals[i]);
				else{
					res[size].end = max(intervals[i].end,temp.end);
				}	
			}
		}
		return res;
    }
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        intervals.push_back(newInterval);
		return merge(intervals); 
    }
    void test(){
    	typedef Interval Int;
		vector<Int> res;
		vector<Int> X;
		Int a(1,3);
		Int b(2,6);
		Int c(8,10);
		Int d(15,18);
		X.push_back(a);
		X.push_back(b);
		X.push_back(c);
		//X.push_back(d);
		res = insert(X,d);
		for(int i = 0;i < res.size();i ++){
			cout<<res[i].start<<" "<<res[i].end<<endl;
		}
	}
};

int main(){
	Solution A;
	A.test();
	system("pause");
}


