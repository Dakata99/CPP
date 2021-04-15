#pragma once
#include <iostream>
#include <cassert>
#include <cstring>
#include <limits>
 
class String
{
private:
    char* str;
    size_t len;
    
private:
	void copy(const char*);
	void copy(const String&);
    
public:
    //Constructors
    String();
    String(const char*);
    String(const String&);
    
    //Destructors
    ~String();
    
    //operator=
    String& operator=(const String&);
    String& operator=(const char*);
    
    //operator[]
    char operator[](size_t) const;

    //operator!=
    bool operator!=(const String&) const;
    bool operator!=(const char*) const;
    friend bool operator!=(const char*, const String&);
    friend bool operator!=(const String&, const char*);

    //operator==
    bool operator==(const String&) const;
    bool operator==(const char*) const;
    friend bool operator==(const char*, const String&);
    friend bool operator==(const String&, const char*);

    //operator>=
    bool operator>=(const String&) const;
    bool operator>=(const char*) const;
    friend bool operator>=(const char*, const String&);
    friend bool operator>=(const String&, const char*);
    
    //operator<=
    bool operator<=(const String&) const;
    bool operator<=(const char*) const;
    friend bool operator<=(const char*, const String&);
    friend bool operator<=(const String&, const char*);
    
    //operator>
    bool operator>(const String&) const;
    bool operator>(const char*) const;
    friend bool operator>(const char*, const String&);
    
    //operator<
    bool operator<(const String&) const;
    bool operator<(const char*) const;
    friend bool operator<(const char*, const String&);
    friend bool operator<(const String&, const char*);
    
    //operator+
    friend String operator+(const String&, const String&);
    friend String operator+(const char*, const String&);
    friend String operator+(const String&, const char*);

    //operator+=
    String& operator+=(const String&);
    String& operator+=(const char*);
    String& operator+=(const char);
    
    //operator>>
    friend std::istream& operator>>(std::istream&, String&);
    
    //operator<<
    friend std::ostream& operator<<(std::ostream&, const String&);

    //Getters
    char* get_string() const;
    size_t get_length() const;

    //Setters
    void set_string(const char*);
};
    
