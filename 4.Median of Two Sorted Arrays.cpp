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

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
		int n = nums2.size();
		int mid = (m+n)/2;
		int flag = (m+n)%2;//0 odd 1 ev
		double res;
		int i1,i2;
		int first,second,in=0;
		
		if(mid==0){//either of nums1 and nums2 is empty 
			if(!m&&!n)
				return 0;
			if(m)
				return nums1[0];
			else
				return nums2[0];
		}
		for(i1=0,i2=0;(i1+i2)<mid;){
			if(i1 >= m){
				first = nums2[i2];
				if(i2+1<n)
					second = nums2[i2+1];
				else
					second = nums1[i1];
				i2 ++;
			}
			else if(i2 >= n){
				first = nums1[i1];
				if(i1+1<m)
					second = nums1[i1+1];
				else
					second = nums2[i2];
				i1 ++;	
			}
			else if(nums1[i1]>nums2[i2]){
				first = nums2[i2];
				if(i2+1<n)
					second = min(nums1[i1],nums2[i2+1]);
				else
					second = nums1[i1];
				i2 ++;
			}
			else{
				first = nums1[i1];
				if(i1+1<m)
					second = min(nums1[i1+1],nums2[i2]);
				else
					second = nums2[i2];
				i1 ++;			
			}
		}
		cout<<first<<" "<<second<<endl;
		if(flag)
			return second;
		else
			return ((double)first + (double)second)/2;
    }
    void test(){
		vector<int> A,B;
		A.push_back(1);
		//A.push_back(3);
		//A.push_back(4);
		B.push_back(2);
		//B.push_back(5);
		//B.push_back(6);
		//B.push_back(7);
		cout<<findMedianSortedArrays(A,B)<<endl;
	}
};

int main(){
	Solution A;
	A.test();
	system("pause");
}


