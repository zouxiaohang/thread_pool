thread_pool
===========

c++11 thread pool


####usage:  
    
    tp::thread_pool tp;
    vector<std::future<int>> v;
    for (int i = 0; i != 10; ++i){
		auto ans = tp.submit([](int answer) { return answer; }, i);
		v.push_back(std::move(ans));
	}
	for (int i = 0; i != v.size(); ++i){
		cout << v[i].get() << endl;
	}
