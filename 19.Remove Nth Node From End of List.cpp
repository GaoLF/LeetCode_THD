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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy =new ListNode(0);
		dummy->next = head;
        ListNode *temp,*torev;
        temp = torev = dummy;
        int i = 0;
        if(!n)
        	return head;
		while(temp){
			if(i < (n+1)){
				temp = temp->next;
				i ++;
			}
			else{
				temp = temp->next;
				torev = torev->next;
			}
		} 
		if(i == (n+1)){
			temp = torev->next;
			torev->next = torev->next->next;
			free(temp);
		}
		
		return dummy->next;
    }
    void test(){
		ListNode *A,*B,*C,*D,*E;
		A =new ListNode(1);
		B =new ListNode(2);
		C =new ListNode(3);
		D =new ListNode(4);
		E =new ListNode(5);
		A->next = B;
		B->next = C;
		C->next = D;
		D->next = E;
		ListNode* res = removeNthFromEnd(A,0);
		for(auto x = res;x;x=x->next)
			cout<<x->val<<" ";
		cout<<endl;
	}
};

int main(){
	Solution A;
	A.test();
	system("pause");
}


