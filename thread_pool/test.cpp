#include <thread>
#include <vector>
#include <iostream>
#include <functional>

#include "thread_guard.h"
#include "thread_pool.h"

using namespace std;

int main(){
	/*std::vector<std::thread> v;
	for (int i = 0; i != 5; ++i){
		v.push_back(std::thread([=]{std::cout << "thread id " << i << std::endl; }));
	}
	tp::thread_guard<std::thread> tg(v);*/
	tp::thread_pool tp;
	vector<std::future<int>> v;
	for (int i = 0; i != 10; ++i){
		auto ans = tp.submit([](int answer) { return answer; }, i);
		v.push_back(std::move(ans));
	}
	for (int i = 0; i != v.size(); ++i){
		cout << v[i].get() << endl;
	}
	system("pause");
	return 0;
}