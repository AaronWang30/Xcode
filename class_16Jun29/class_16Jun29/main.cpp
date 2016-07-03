//
//  main.cpp
//  test1
//
//  Created by WZJ on 16/6/29.
//  Copyright © 2016年 WZJ. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;
class complex
{
public:
    complex(double r=0, double i=0):re(r), im(i) {}
    double real() const {return re;}//interface to get access to private members
    double image() const {return im;}
    complex& operator += (const complex &a)
    {
        re+=a.real();
        im+=a.image();
        return *this;
    }
    
private:
    double re;//data -> private
    double im;
};
//inline complex & complex::operator+=(<#const complex &a#>){
//    this->re+=a->re;
//    this->im+=a->im;
//    return *this;
//}

//For class contains pointers, you need to write construction/deconstruction functions manually.
//浅拷贝（指针指向变动, string a(..),b(..), b=a）/ 如果类中含有指针变量，默认的拷贝构造函数必定出错。
class String{
public:
    String(const char *cstr=0){
        if(cstr){
            m_data=new char[strlen(cstr)+1];
            strcmp(m_data,cstr);
        }
    }
    String(const String &str);
    String & operator = (const String &str);
    ~String(){
        delete[] m_data;
    }
    char * get_c_str() const{return m_data;}
private:
    char *m_data;
};

int main () {
    complex a(1,2), b(3,4), c(5,6);
    //a(1,2);
    //b(3,4);
    a+=b+=c;
    cout << a.real() << " "<< a.image()<<endl;
}