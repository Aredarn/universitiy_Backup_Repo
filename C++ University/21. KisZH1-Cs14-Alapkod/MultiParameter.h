#ifndef MULTIPARAMETER_H
#define MULTIPARAMETER_H
#include <iostream>
#include <string>
#include <exception>

using namespace std;

namespace util{

template <typename T, typename U> class MultiParameter{
private:
    T* first;
    U* second;

    class null_pointer_exception : public exception
    {
    private:
        string msg;
    public:
        null_pointer_exception(const string& param)
        {
            msg = "Invalid pointer(s) " + param;
        }

        const char* what() const noexcept override{
            return msg.c_str();
        }

    };


public:
    MultiParameter():first(nullptr),second(nullptr){};

    MultiParameter(T* first, U* second)
    {
        this->first = first;
        this->second = second;
    }

    T getFirst() const {
          if(first == nullptr) return T();
          return *first;
      }

    U getSecond() const
    {
        if(second == nullptr)
            return U();
        return *second;
    }

    static MultiParameter make(T* first, U* second)
    {
        bool shouldThrow = false;
        string msg;
        if(first == nullptr)
        {
            msg += "first";
            shouldThrow = true;
        }
        if(second == nullptr)
        {
            msg += "second";
            shouldThrow = true;
        }

        if(shouldThrow)
            throw null_pointer_exception(msg);
        return MultiParameter(first, second);
    }
};
}
#endif // MULTIPARAMETER_H
