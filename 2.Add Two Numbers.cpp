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

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy, *iter;
        int temp, carry = 0;
        dummy = new ListNode(1);
        iter = dummy;
		while(l1 || l2){
			temp = carry;
			if(l1)
				temp += l1->val;
			if(l2)
				temp += l2->val;
				
			carry = temp/10;
			temp = temp%10;
			iter->next  = new ListNode(temp);
			
			iter = iter->next;
			if(l1)
				l1 = l1->next;
			if(l2)
				l2 = l2->next;
		} 
		if(carry)
			iter->next = new ListNode(1);
		
		return dummy->next;

    }
    void test(){
		ListNode *a,*b,*c,*d,*e,*f,*g;
		a = new ListNode(2);
		b = new ListNode(4);
		c = new ListNode(3);
		d = new ListNode(5);
		e = new ListNode(6);
		f = new ListNode(6);
		g = new ListNode(9);
		a->next = b;
		b->next = c;
		d->next = e;
		e->next = f;
		f->next = g;
		ListNode *res = addTwoNumbers(a,e);
		for(;res;res = res->next){
			cout<<res->val<<" ";
		}
		cout<<endl;
		//a->next = b;
		//a->next = b;
		
	}
};

int main(){
	Solution A;
	A.test();
	system("pause");
}


