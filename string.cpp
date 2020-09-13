#include <iostream>
#include <cstring>
using namespace std;

class String{
private:
    char* m_str;
    int m_size;
public:
    String();
    String(const char*);
    const String& operator=(String&);
    const String& operator=(const char* str);
    String(String&);
    String(String&&);
    const String& operator=(String&&);
    friend String operator+(const String, const String);
    friend String operator+(const String, const char*);
    friend String operator+(const char*, const String);
    //String operator==(String&) const;
    String operator-=(String&);
    //String operator+(String&);
    String operator+=(String&);
    bool operator<(String&) const;
    bool operator<=(String&) const;
    bool operator>(String&) const;
    bool operator>=(String&) const;
    friend istream& operator>>(istream&, const String&);
    friend ostream& operator<<(ostream&, const String&);
    ~String();
};

inline String::String() { 
    m_size=0;
    m_str = new char[m_size];
}

inline String::String(const char *str) {
    m_size = strlen(str) + 1;
    m_str = new char[m_size];
    strcpy(m_str,str);
}

inline const String& String::operator=(String& obj) {
    delete [] m_str;
    m_size = strlen(obj.m_str) + 1;
    m_str = new char[m_size];
    strcpy(m_str,obj.m_str);
    return *this;
}

inline const String& String::operator=(const char* str) {
    m_size = strlen(str) + 1;
    m_str = new char[m_size];
    strcpy(m_str,str);

    return *this;
}

inline String::String(String& obj) {
    m_size = strlen(obj.m_str) + 1;
    m_str = new char[m_size];
    strcpy(m_str,obj.m_str);
}

inline String::String(String&& obj) {
    swap(m_str,obj.m_str);
    swap(m_size,obj.m_size);
    obj.m_str=nullptr;
}

inline const String& String::operator=(String&& obj) {
    swap(m_str,obj.m_str);
    obj.m_str=nullptr;
    return *this;
}

inline String operator+(const String obj1, const String obj2) {
    String timeStr;
    timeStr.m_size = strlen(obj1.m_str) + strlen(obj2.m_str);
    timeStr.m_str = new char[timeStr.m_size];
    strcpy(timeStr.m_str,obj1.m_str);
    strcat(timeStr.m_str,obj2.m_str);
    return timeStr;
}

inline String operator+(const String obj, const char* str) {
    String timeStr;
    timeStr.m_size = strlen(obj.m_str)+strlen(str);
    timeStr.m_str = new char[timeStr.m_size];
    strcpy(timeStr.m_str,obj.m_str);
    strcat(timeStr.m_str,str);
    return timeStr;
}

inline String operator+(const char* str, const String obj) {
    String timeStr;
    timeStr.m_size = strlen(obj.m_str) + strlen(str);
    timeStr.m_str = new char[timeStr.m_size];
    strcpy(timeStr.m_str,obj.m_str);
    strcat(timeStr.m_str,str);
    return timeStr;
}

inline ostream& operator<<(ostream& out, const String& obj) {
    out<<obj.m_str;
    return out;
}

inline istream& operator>>(istream& in, const String& obj) {
    in>>obj.m_str;
    return in;
}

inline String::~String() {
    delete [] m_str;
    m_str = nullptr;
}

int main() {
    String str1("Str1");
    String str2("Str2");
    String str3(str2);
    str3 = "Str3";
    String str4,str5,str8,str9,str10;

    str4 = str1 + str2 + "typidor" + str3 + "qwerty" + "uiop" + str5;
    cout<<str4<<endl;

    str8 = (str2<str3)?(str2):(str3);
    str9 = (str2>str3)?(str2):(str3);
    //STD::String str10;
    cin>>str10;
    (str10<=str2)?(std::cout<<str10<<std::endl):(std::cout<<str2<<std::endl);
    (str10>=str2)?(std::cout<<str10<<std::endl):(std::cout<<str2<<std::endl);
    //bool a = (str2==str3);
}