#include "String.h"

void String::copy(const char* string)
{
	len = strlen(string);
    str = new char[len + 1];
    strcpy(str, string);
}

//Constructors
String::String() { len = 0; copy(""); }

String::String(const char* string) { copy(string); }

String::String(const String& string) { copy(string.get_string()); }
    
//Destructors
String::~String() { delete [] str; }
    
//operator=
String& String::operator=(const String& other)
{
	if(this != &other)
	{
    	delete [] str;
    	copy(other.get_string());
	}
	
    return *this;
}

String& String::operator=(const char* string)
{
	if(strcmp(str, string) == 0) goto exit;
	
	delete [] str;
	copy(string);

exit:
	return *this;
}

//operator[]
char String::operator[](size_t index) const
{
	assert(index >= 0 && index <= len - 1);
	return str[index];
}

//operator!=
bool String::operator!=(const String& string) const { return strcmp(str, string.get_string()) != 0; }

bool String::operator!=(const char* string) const { return strcmp(str, string) != 0; }

bool operator!=(const char* str, const String& string) { return strcmp(str, string.get_string()) != 0; }

bool operator!=(const String& string, const char* str) { return strcmp(string.get_string(), str) != 0; }

//operator==
bool String::operator==(const String& string) const { return strcmp(str, string.get_string()) == 0; } 

bool String::operator==(const char* string) const { return strcmp(str, string) == 0; } 

bool operator==(const char* str, const String& string) { return strcmp(str, string.get_string()) == 0; }

bool operator==(const String& string, const char* str) { return strcmp(string.get_string(), str) == 0; }

//operator>=
bool String::operator>=(const String& string) const { return strcmp(str, string.get_string()) == 1; }

bool String::operator>=(const char* string) const { return strcmp(str, string) == 1; }

bool operator>=(const char* str, const String& string) { return strcmp(str, string.get_string()) == 1; }

bool operator>=(const String& string, const char* str) { return strcmp(string.get_string(), str) == 1; }
    
//operator<=
bool String::operator<=(const String& string) const { return strcmp(str, string.get_string()) == -1; }

bool String::operator<=(const char* string) const { return strcmp(str, string) == -1; }

bool operator<=(const char* str, const String& string) { return strcmp(str, string.get_string()) == -1; }

bool operator<=(const String& string, const char* str) { return strcmp(string.get_string(), str) == -1; }
    
//operator>
bool String::operator>(const String& string) const { return !(str < string); }

bool String::operator>(const char* string) const { return !(str < string); }

bool operator>(const char* string, const String& str) { return !(string < str); }

//operator<
bool String::operator<(const String& string) const
{
    if (len < string.get_length()) return true;
    
    for (size_t i = 0; i < len; i++)
        if (str[i] >= string.str[i]) return false;
        
    return true;
}

bool String::operator<(const char* string) const
{
    if (len < strlen(string) + 1) return true;
    
    for (size_t i = 0; i < len; i++)
        if (str[i] >= string[i]) return false;
        
    return true;
}

bool operator<(const char* string, const String& str)
{
    if (strlen(string) + 1 < str.get_length()) return true;
    
    for (size_t i = 0; i < str.get_length(); i++)
        if (str.str[i] >= string[i]) return false;
        
    return true;
}

bool operator<(const String& string, const char* str)
{
    if (string.get_length() < strlen(str) + 1) return true;
    
    for (size_t i = 0; i < string.get_length(); i++)
        if (string.str[i] >= str[i]) return false;
        
    return true;
}

//opeartor+
String operator+(String& str1, String& str2) { return str1 += str2; }

String operator+(const String& str1, const String& str2)
{
	String tmp = str1;
	tmp += str2;
	
	return tmp;
}
String operator+(const char* str, const String& string)
{
	String tmp(str);
	tmp += string;
	
	return tmp;
}

String operator+(const String& string, const char* str)
{
	String tmp = string;
	tmp += str;
	
	return tmp;
}

//operator+=
String& String::operator+=(const String& other)
{
    String temp;
    temp.str = new char[len + other.get_length() + 1];
    
    for(size_t i = 0; i < len; i++) temp.str[i] = str[i];
    
    for(size_t i = len; i < len + other.len; i++) temp.str[i] = other.str[i - len];

    delete [] str;
    
    len += other.len;
    str = new char[len + 1];
    
    for (size_t i = 0; i < len; i++) str[i] = temp.str[i];
    
    return *this;
}

String& String::operator+=(const char* string)
{
    String temp;
    temp.str = new char[len + strlen(string) + 1];
    
    for (size_t i = 0; i < len; i++) temp.str[i] = str[i];
    
    for (size_t i = len; i < len + strlen(string) + 1; i++) temp.str[i] = string[i - len];
    
    delete [] str;
    
    len += strlen(string);
    str = new char[len + 1];
    
    for (size_t i = 0; i < len; i++) str[i] = temp.str[i];
    
    return *this;
}

String& String::operator+=(const char sym)
{
    String temp;
    temp.str = new char[len + 2];
    
    for (size_t i = 0; i < len; i++) temp.str[i] = str[i];
    temp.str[len] = sym;
    
    delete [] str;
    
    str = new char[++len + 1];
    
    for (size_t i = 0; i < len; i++) str[i] = temp.str[i];
    
    return *this;
}


//operator<<
std::ostream& operator<<(std::ostream& os, const String& string) { os << string.str; return os; }

//operator>>
std::istream& operator>>(std::istream& is, String& string)
{
	const size_t buff_size = 100;	
	char buff[buff_size];

	is.get(buff, buff_size, '\n');

	string = String(buff);

	is.clear();
	is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	return is;
}

bool String::empty(void) const { return str == nullptr && len == 0; }

//Getters
char* String::get_string() const { return str; }

size_t String::get_length() const { return len; }

//Setters
void String::set_string(const char* string)
{
	if(str == nullptr) copy(string);
	else { delete [] str; copy(string); }
}

bool String::contains(const char* substr) const
{
	const char* tmp = substr;
	char* copy = str;   

	if (strlen(substr) > len) return false;
	else if (strcmp(str, substr) == 0) return true;
	
	while (*copy++)
	{
		if (*tmp == *copy) tmp++;
	}
	
	return *tmp == '\0';
}

bool String::contains(const String& str) const { return contains(str.get_string()); }

String String::substr(size_t from) const
{
	assert(from >= 0 && from <= len - 1);
	
	return String(str + from);
}

String String::substr(size_t from, size_t till) const
{
	assert (from >= 0 && from <= len - 1);

	char* tmp = str + from;

	String res(tmp);

	while (from++ != till || *tmp != '\0') res += *tmp;
	
	return res; 
}

String& String::operator*(size_t mult) { while (mult--) *this += str; return *this; }
    
String& String::operator*=(size_t mult) { return (*this) * mult; }
