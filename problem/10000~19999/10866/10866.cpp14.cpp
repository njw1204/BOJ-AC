#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <deque>
using namespace std;


/*
stack<int> adsf;

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++){
		string op;
		cin >> op;
		if(op=="push"){
			int x;
			cin >> x;
			adsf.push(x);
		}
		if(op=="pop"){
			if(!adsf.empty()){
				cout << adsf.top() << '\n';
				adsf.pop();
			}else{
				cout << -1 << '\n';
			}
		}
		if(op=="size"){
			cout << adsf.size() << '\n';
		}
		if(op=="empty"){
			if(adsf.empty()){
				cout << 1 << '\n';
			}else{
				cout << 0 << '\n';
			}
		}
		if(op=="top"){
			if(adsf.empty()){
				cout << -1 << '\n';
			}else{
				cout << adsf.top() << '\n';
			}
		}
	}
	return 0;
}

*/

/*
queue<int> asdf;

int main(){
	int N;
	cin >> N;
	for (int i = 0; i < N; i++){
		string op;
		cin >> op;
		if(op=="push"){
			int x;
			cin >> x;
			asdf.push(x);
		}
		else if(op=="pop"){
			if(!asdf.empty()){
				cout << asdf.front() << '\n';
				asdf.pop();
			}else{
				cout << -1 << '\n';
			}
		}
		else if(op=="size"){
			cout << asdf.size() << '\n';
		}
		else if(op=="empty"){
			if(asdf.empty()){
				cout << 1 << '\n';
			}else{
				cout << 0 << '\n';
			}
		}
		else if(op=="front"){
			if(asdf.empty()){
				cout << -1 << '\n';
			}else{
				cout << asdf.front() << '\n';
			}
		}
		else if(op=="back"){
			if(asdf.empty()){
				cout << -1 << '\n';
			}else{
				cout << asdf.back() << '\n';
			}
		}
	}
}
*/
deque<int> asdf;

int main(){
	int N;
	cin >> N;
	for (int i = 0; i < N; i++){
		string op;
		cin >> op;
		if(op=="push_front"){
			int x;
			cin >> x;
			asdf.push_front(x);
		}
		if(op=="push_back"){
			int x;
			cin >> x;
			asdf.push_back(x);
		}
		else if(op=="pop_front"){
			if(!asdf.empty()){
				cout << asdf.front() << '\n';
				asdf.pop_front();
			}else{
				cout << -1 << '\n';
			}
		}
		else if(op=="pop_back"){
			if(!asdf.empty()){
				cout << asdf.back() << '\n';
				asdf.pop_back();
			}else{
				cout << -1 << '\n';
			}
		}
		else if(op=="size"){
			cout << asdf.size() << '\n';
		}
		else if(op=="empty"){
			if(asdf.empty()){
				cout << 1 << '\n';
			}else{
				cout << 0 << '\n';
			}
		}
		else if(op=="front"){
			if(asdf.empty()){
				cout << -1 << '\n';
			}else{
				cout << asdf.front() << '\n';
			}
		}
		else if(op=="back"){
			if(asdf.empty()){
				cout << -1 << '\n';
			}else{
				cout << asdf.back() << '\n';
			}
		}
	}
}