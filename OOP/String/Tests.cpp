#include "Tests.h"

void constuctors(void)
{
	String s1, s2("Testing strings"), s3(s2);
	
	std::cout << "S1 = " << s1 << std::endl;
	std::cout << "S2 = " << s2 << std::endl;
	std::cout << "S3 = " << s3 << std::endl;
}

void operators(void)
{
	String s1, s2("Testing strings"), s3(s2);
	
	//operator=
	s1 = s3;
	s2 = "Other tests";
	
	std::cout << "S1 = " << s1 << std::endl;
	std::cout << "S2 = " << s2 << std::endl;
	std::cout << "S3 = " << s3 << std::endl;
	
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
	std::cout << s1.get_length() << std::endl;
	std::cout << s2.get_string() << std::endl;
	std::cout << s3.get_length() << std::endl;

	//Setters
	s1.set_string("Other tests");
	std::cout << s1.get_string() << std::endl;
}

void run(void)
{
	constuctors();
	operators();
	input_output_operators();
	getters_and_setters();
}

void hw_tests(void)
{
	String s1(); //""
	String s2("Test");

	s2.substr(2); // st

	s2.substr(1, 2); // es

	s1 = "pronto";	

	s2.contains(s1); //false

	String s3 = s1 + s2; // prontoTest

	s3 *= 3; //prontoTestprontoTestprontoTest

	std::cin >> s3;
	std::cout << s3 << std::endl;

	s3 == s1; //false;
}


