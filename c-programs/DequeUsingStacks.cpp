// iHaala Madrid - A Gunner
#include<iostream>
#include<stdio.h>
#include<string>
#include<stack>

using namespace std;

class Deque{
	private:
		stack<int> a,b;	
	public:						
		bool empty(){
			int size = a.size() + b.size() ;
			if(!size)	return true;
			else		return false;
		}
		
		void push_back(int i){
			a.push(i);
		}
		
		void push_front(int i){
			b.push(i);
		}

		int pop_front(){			
			if(b.size()==0){
				while(a.size()!=0){
					b.push(a.top());
					a.pop();
				}
			}
			
			int popped=b.top();
			b.pop();
			return popped;						
		}
		
		int pop_back(){
			if(a.size()==0){
				while(b.size()!=0){
					a.push(b.top());
					b.pop();
				}
			}
			
			int popped=a.top();
			a.pop();
			return popped;
		}
		
		int front(){
			if(b.size()==0){
				while(a.size()!=0){
					b.push(a.top());
					a.pop();
				}
			}
			
			return b.top();
		}
		
		int back(){
			if(a.size()==0){
				while(b.size()!=0){
					a.push(b.top());
					b.pop();
				}
			}
			
			return a.top();
		}
		
};

int main(){	
	Deque dq;
	
	dq.push_back(2);
	dq.push_back(3);
	dq.push_back(4);
	cout<<dq.pop_back();
	cout<<dq.pop_front();
	dq.push_front(5);
	cout<<dq.pop_front();
	return 0;	
}