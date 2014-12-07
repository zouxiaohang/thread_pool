#ifndef _THREAD_GUARD_H_
#define _THREAD_GUARD_H_

#include <utility>
#include <vector>

namespace tp{
	template<class ThreadType>
	class thread_guard{
	private:
		std::vector<ThreadType>& threads_;
	public:
		thread_guard(std::vector<ThreadType>& v) :threads_(v){}

		thread_guard(thread_guard&& tg) = delete;
		thread_guard& operator = (thread_guard&& tg) = delete;

		thread_guard(const thread_guard&) = delete;
		thread_guard& operator = (const thread_guard&) = delete;

		~thread_guard(){
			for (size_t i = 0; i != threads_.size(); ++i){
				if (threads_[i].joinable()){
					threads_[i].join();
				}
			}
		}
	};
}

#endif