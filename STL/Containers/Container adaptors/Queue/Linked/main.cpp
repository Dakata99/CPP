#include <iostream>
#include <string>

#include "Queue.h"

void tests(void)
{
	Queue<int> q;
	
	printf("Size: %ld\n", q.get_size());
	std::cout << std::boolalpha << q.empty() << std::endl;
	
	for (size_t i = 0; i < 10; i++) q.push(i);
	
	std::cout << std::boolalpha << q.empty() << std::endl;
	
	printf("Size: %ld\n", q.get_size());
	printf("Front: %d\n", q.front());
	printf("Back: %d\n", q.back());
		
	Queue<int> q2(q);
	
	printf("Size: %ld\n", q2.get_size());
	printf("Front: %d\n", q2.front());
	printf("Back: %d\n", q2.back());
	
	q.pop();
	
	Queue<int> q3 = q;
	printf("Size: %ld\n", q3.get_size());
	printf("Front: %d\n", q3.front());
	printf("Back: %d\n", q3.back());
	
	Queue<std::string> myqueue;

	myqueue.emplace ("First sentence");
	myqueue.emplace ("Second sentence");

	std::cout << "myqueue contains:\n";
	while (!myqueue.empty())
	{
		std::cout << myqueue.front() << '\n';
		myqueue.pop();
	}
	
	Queue<int> q4;
	
	for (size_t i = 10; i < 20; i++) q4.push(i);
	
	std::cout << q3 << q4;

	swap(q3, q4);
	
	std::cout << q3 << q4;
	
	std::cout << std::boolalpha << (q3 == q4) << std::endl;
	std::cout << std::boolalpha << !(q4 == q3) << std::endl;
}

int main(void)
{
	tests();
	
	return 0;
};
