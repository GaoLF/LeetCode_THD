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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
		ListNode* temp = dummy;
		while(l1||l2){
			if(l1 && l2){
				if(l1->val < l2->val){
					temp->next = l1;
					l1 = l1->next;
					temp = temp->next;
				}
				else{
					temp->next = l2;
					l2 = l2->next;
					temp = temp->next;
				}
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
		ListNode *a,*b,*c,*d,*e,*f;
		a = new ListNode(1);
		b = new ListNode(3);
		c = new ListNode(5);
		d = new ListNode(2);
		e = new ListNode(4);
		f = new ListNode(6);
		a->next = b;
		b->next = c;
		d->next = e;
		e->next = f;
		ListNode*res = mergeTwoLists(NULL,d);
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


