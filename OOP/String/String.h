#include <cstring>

class String
{
private:
    char* str;
    size_t len;
    
public:
    //Constructors
    String();
    String(const char*);
    String(const String&);
    
    //Destructors
    ~String();
    
    //Operator=
    String operator=(const String&);
    String operator=(const char*);

    //operator!=
    bool operator!=(const String&);
    bool operator!=(const char*);
    friend bool operator!=(const char*, const String&);

    //operator==
    bool operator==(const String&);
    bool operator==(const char*);
    friend bool operator==(const char*, const String&);

    //operator>=
    bool operator>=(const String&);
    bool operator>=(const char*);
    friend bool operator>=(const char*, const String&);
    
    //operator<=
    bool operator<=(const String&);
    bool operator<=(const char*);
    friend bool operator<=(const char*, const String&);
    
    //operator>
    bool operator>(const String&);
    bool operator>(const char*);
    friend bool operator>(const char*, const String&);
    
    //operator<
    bool operator<(const String&);
    bool operator<(const char*);
    friend bool operator<(const char*, const String&);

    //operator+=
    String operator+=(const String&);
    String operator+=(const char*);
    
    //operator<<
    friend std::ostream& operator<<(std::ostream&, const String&);

    //Getters
    char* get_string() const;
    size_t get_length() const;

    //Setters
    void set_string(const char*);
    
    //Funcs
    void print() const;
};
    
#include "String.cpp"

