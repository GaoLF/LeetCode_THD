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
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(0);
		dummy->next = head;
		ListNode* temp = dummy;
		
		while(temp->next){
			if(temp->next->next){
				ListNode *_3follow = temp->next->next->next;
				ListNode *_1follow = temp->next;
				temp->next = _1follow->next;
				temp->next->next = _1follow;
				_1follow->next = _3follow;
				temp = _1follow;
			}
			else
				break;
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
		//a->next = b;
		//b->next = c;
		//c->next = d;
		//d->next = e;
		//e->next = f;
		ListNode*res = swapPairs(NULL);
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


