#include "Tests.h"

void constuctors(void)
{
	String strs[] = { 
						String(), String("Testing strings"), String(strs[1]), 
					  	String(strs[2], 3, 7), String("Hello world!", 12), String(10, 'x')
					};
	for (size_t i = 0; i < 6; i++) std::cout << "S" << i << ") = " << strs[i] << std::endl;
	
}

void operators(void)
{
	String tmp("Testing string");
	
	//operator=
	String s1 = tmp, s2 = "Other tests", s3 = 'x';
	
	std::cout << "S1 = " << s1 << std::endl;
	std::cout << "S2 = " << s2 << std::endl;
	std::cout << "S3 = " << s3 << std::endl;
}

void relational_operators(void)
{
	String s1, s2, s3;
	//operator[]
	std::cout << s2[2] << std::endl;
	
	//operator!=
	std::cout << std::boolalpha << "S1 != S2 " << (s1 != s2) << std::endl;
	std::cout << std::boolalpha << "S1 != S3 " << (s1 != s3) << std::endl;
	std::cout << std::boolalpha << "S2 != S3 " << (s2 != s3) << std::endl;
	//std::cout << std::boolalpha << "S3 != something" << (s3 != "something") << std::endl;

	//operator==
	std::cout << std::boolalpha << "S1 == S2 " << (s1 == s2) << std::endl;
	std::cout << std::boolalpha << "S1 == S3 " << (s1 == s3) << std::endl;
	std::cout << std::boolalpha << "S2 == S3 " << (s2 == s3) << std::endl;
	//std::cout << std::boolalpha << "S3 == something" << (s3 == "something") << std::endl;

	//operator>=
	std::cout << std::boolalpha << "S1 >= S2 " << (s1 >= s2) << std::endl;
	std::cout << std::boolalpha << "S1 >= S3 " << (s1 >= s3) << std::endl;
	std::cout << std::boolalpha << "S2 >= S3 " << (s2 >= s3) << std::endl;
	//std::cout << std::boolalpha << "S3 >= something" << (s3 >= "something") << std::endl;

	//operator<=
	std::cout << std::boolalpha << "S1 <= S2 " << (s1 <= s2) << std::endl;
	std::cout << std::boolalpha << "S1 <= S3 " << (s1 <= s3) << std::endl;
	std::cout << std::boolalpha << "S2 <= S3 " << (s2 <= s3) << std::endl;
	//std::cout << std::boolalpha << "S3 <= something" << (s3 <= "something") << std::endl;

	//operator>
	std::cout << std::boolalpha << "S1 > S2 " << (s1 > s2) << std::endl;
	std::cout << std::boolalpha << "S1 > S3 " << (s1 > s3) << std::endl;
	std::cout << std::boolalpha << "S2 > S3 " << (s2 > s3) << std::endl;
	//std::cout << std::boolalpha << "S3 > something" << (s3 > "something") << std::endl;

	//operator<
	std::cout << std::boolalpha << "S1 < S2 " << (s1 < s2) << std::endl;
	std::cout << std::boolalpha << "S1 < S3 " << (s1 < s3) << std::endl;
	std::cout << std::boolalpha << "S2 < S3 " << (s2 < s3) << std::endl;
	//std::cout << std::boolalpha << "S3 < something" << (s3 < "something") << std::endl;

	//operator+
	//s1 + s2;
	//s2 + "operator+(char*)";
	//s3 + 'c';
	
	std::cout << "S1 = " << s1 << std::endl;
	std::cout << "S2 = " << s2 << std::endl;
	std::cout << "S3 = " << s3 << std::endl;

	//operator+=
	s1 += s2;
	s2 += "operator+(char*)";
	s3 += 'c';
	
	std::cout << "S1 = " << s1 << std::endl;
	std::cout << "S2 = " << s2 << std::endl;
	std::cout << "S3 = " << s3 << std::endl;
}

void input_output_operators(void)
{
	String s;
	
	//operator>>
	std::cin >> s;
	
	//operator<<
	std::cout << s << std::endl;
}

void getters_and_setters(void)
{
	String s1, s2("Testing strings"), s3(s2);
	
	//Getters
	std::cout << s1.length() << std::endl;
	std::cout << s2.c_str() << std::endl;
	std::cout << s3.length() << std::endl;

	//Setters
	std::cout << s1.c_str() << std::endl;
}

void run(void)
{
	constuctors();
	operators();
	input_output_operators();
	getters_and_setters();
}

