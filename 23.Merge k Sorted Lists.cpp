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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    	if(lists.empty())
    		return NULL;
        return mergeHelper(lists,0,lists.size()-1); 
    }
    ListNode* mergeHelper(vector<ListNode*>& lists,int begin,int end){
    	if(begin == end)
    		return lists[begin];
    	if(end - begin == 1)
    		return merge(lists[begin],lists[end]);
    	ListNode* l1 = mergeHelper(lists,begin,(begin+end)/2);
    	ListNode* l2 = mergeHelper(lists,(begin+end)/2+1,end);
    	
		return merge(l1,l2);
	}
	ListNode* merge(ListNode* l1,ListNode* l2){
		ListNode* dummy = new ListNode(0);
		ListNode* temp = dummy;
		while(l1||l2){
			if(l1&&l2){
				if(l1->val < l2->val){
					temp->next = l1;
					l1 = l1->next;
				}
				else{
					temp->next = l2;
					l2 = l2->next;
				}	
				temp = temp->next;
			}
			else if(l1){
				temp->next = l1;
				break;
			}
			else{
				temp->next = l2;
				break;
			}
		}
		return dummy->next;
	}
    void test(){
		ListNode *a,*b,*c,*d,*e;
		a = new ListNode(0);
		b = new ListNode(1);
		c = new ListNode(2);
		d = new ListNode(3);
		e = new ListNode(4);
		vector<ListNode*> vec;
		vec.push_back(a);
		vec.push_back(b);
		vec.push_back(c);
		vec.push_back(d);
		vec.push_back(e);
		ListNode *res = mergeKLists(vec);
		while(res){
			cout<<res->val<<" ";
			res = res->next;
		}
		cout<<endl;
	}
};

int main(){
	Solution A;
	A.test();
	system("pause");
}


