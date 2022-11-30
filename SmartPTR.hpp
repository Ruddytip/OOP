#pragma once

template<typename T>
class SmartPTR{
private:
    T* ptr;
public:
    SmartPTR(): ptr(nullptr) {}
    SmartPTR(T* in): ptr(in) {}
    ~SmartPTR(){ delete ptr; }
    T* operator->() { return ptr; }
    T& operator*() { return *ptr; }
};
