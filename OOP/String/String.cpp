#include "String.h"

//Constructors
String::String():len(0), str(nullptr) {}

String::String(const char* string)
{
    len = strlen(string) + 1;
    str = new char[len];
    strcpy(str, string);
}

String::String(const String& string)
{
    len = string.get_length();
    str = new char[len + 1];
    strcpy(str, string.get_string());
}
    
//Destructors
String::~String() { delete [] str; }
    
//Operator=
String String::operator=(const String& string)
{
	if(this != &other)
	{
    	len = string.get_length() + 1;
        
    	str = new char[len];
    	strcpy(str, string.get_string());
	}
	
    return *this;
}
String String::operator=(const char* string)
{
	if(this != &other)
	{
		len = strlen(string) + 1;

		str = new char[len];
		strcpy(str, string);
	}

    return *this;
}

//operator!=
bool String::operator!=(const String& string) { return !(str == string.get_string()); }

bool String::operator!=(const char* string) { return !(str == string); }

bool operator!=(const char* string, const String& str) { return !(string == str); }

//operator==
bool String::operator==(const String& string)
{
    if(len != string.get_length()) return false;
    
    for (size_t i = 0; i < len; i++)
        if (str[i] != string.str[i]) return false;

    return true;
}

bool String::operator==(const char* string)
{
    if (len != strlen(string) + 1) return false;
    
    for (size_t i = 0; i < len; i++)
        if (str[i] != string[i]) return false;

    return true;
}

bool operator==(const char* string, const String& str)
{
    if(strlen(string) + 1 != str.get_length()) return false;

	size_t len = str.get_length();
	
    for (size_t i = 0; i < len; i++)
        if (string[i] != str.str[i]) return false;

    return true;
}

//operator>=
bool String::operator>=(const String& string) { return !(str <= string); }

bool String::operator>=(const char* string) { return !(str <= string); }

bool operator>=(const char* string, const String& str) { return !(string <= str); }
    
//operator<=
bool String::operator<=(const String& string)
{
    if (len <= string.get_length()) return true;

    for (size_t i = 0; i < len; i++)
        if (str[i] <= string.str[i]) return true;

    return false;
}

bool String::operator<=(const char* string)
{
    if (len <= strlen(string) + 1) return true;
    
    for (size_t i = 0; i < len; i++)
        if (str[i] <= string[i]) return true;
        
    return false;
}

bool operator<=(const char* string, const String& str)
{
    if (strlen(string) + 1 <= str.get_length()) return true; 
    
    for (size_t i = 0; i < str.get_length(); i++)
        if (string[i] <= str.str[i]) return true;
        
    return false;
}
    
//operator>
bool String::operator>(const String& string) { return !(str < string); }

bool String::operator>(const char* string) { return !(str < string); }

bool operator>(const char* string, const String& str) { return !(string < str); }
    
//operator<
bool String::operator<(const String& string)
{
    if (len < string.get_length()) return true;
    
    for (size_t i = 0; i < len; i++)
        if (str[i] < string.str[i]) return true;
        
    return false;
}

bool String::operator<(const char* string)
{
    if (len < strlen(string) + 1) return true;
    
    for (size_t i = 0; i < len; i++)
        if (str[i] < string[i]) return true;
        
    return false;
}

bool operator<(const char* string, const String& str)
{
    if (strlen(string) + 1 < str.get_length()) return true;
    
    for (size_t i = 0; i < str.get_length(); i++)
        if (str.str[i] < string[i]) return true;
        
    return false;
}

//operator+=
String String::operator+=(const String& other)
{
    String temp;
    temp.str = new char[len + other.len];
    
    for(size_t i = 0; i < len; i++) temp.str[i] = str[i];
    
    for(size_t i = len; i < len + other.len; i++) temp.str[i] = other.str[i - len];

    delete [] str;
    
    len = len + other.len;
    str = new char[len];
    
    for (size_t i = 0; i < len; i++) str[i] = temp.str[i];
    
    return *this;
}
String String::operator+=(const char* string)
{
    String temp;
    temp.str = new char[len + strlen(string) + 1];
    
    for (size_t i = 0; i < len; i++) temp.str[i] = str[i];
    
    for (size_t i = len; i < len + strlen(string) + 1; i++) temp.str[i] = string[i - len];
    
    delete [] str;
    
    len = len + strlen(string) + 1;
    str = new char[len];
    
    for (size_t i = 0; i < len; i++) str[i] = temp.str[i];
    
    return *this;
}

//opeartor<<
std::ostream& operator<<(std::ostream& os, const String& string)
{
	os << string;

	return os;
}

//Getters
char* String::get_string() const { return str; }

size_t String::get_length() const { return len; }

//Setters
void String::set_string(const char* string)
{
    len = strlen(string) + 1;
    
    if(str != nullptr) delete [] str;
    
    str = new char[len];
    strcpy(str, string);
}

//Funcs
void String::print()const
{
    for (size_t i = 0; i < len; i++) std::cout << str[i];
    
    std::cout << std::endl;
}
