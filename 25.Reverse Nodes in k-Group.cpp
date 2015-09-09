#include<iostream>
#include<algorithm>
#include<string>
#include<unordered_set>
#include<unordered_map>
#include<stack>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
		dummy->next = head;
		ListNode* temp = dummy;
		
		while(temp->next){
			stack<ListNode*> vec;
			ListNode* iter = temp->next;
			for(int i = 0;i < k; i++){
				if(iter)
					vec.push(iter);
				else
					return dummy->next;
				iter = iter->next;
			}
			for(int i = 0;i < k; i++){
				temp->next = vec.top();
				vec.pop();
				temp = temp->next;
			}
			temp->next = iter;
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
		c->next = d;
		d->next = e;
		//e->next = f;
		ListNode*res = reverseKGroup(a,5);
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


