// PIMPL_DLL.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "StableClass.h"
#include "SomeContainedClass1.h"
#include "SomeContainedClass2.h"

class StableClassImpl {
public:
    StableClassImpl() : m_SomeContainedClass1(nullptr), m_SomeContainedClass2(nullptr) {};
    void Method1(int i);
    void Method2(int i);
    virtual ~StableClassImpl();
    SomeContainedClass1* m_SomeContainedClass1;
    SomeContainedClass2* m_SomeContainedClass2; // Newly Added
};

StableClass::StableClass(void)
{
    ptr = new StableClassImpl();
}

void StableClass::Method1(int i)
{
    ptr->Method1(i);
}

void StableClass::Method2(int i)
{
    ptr->Method2(i);
}

SomeContainedClass1* StableClass::GetSomeContainedClass1()
{
    return ptr->m_SomeContainedClass1;
}

SomeContainedClass2* StableClass::GetSomeContainedClass2()
{
    return ptr->m_SomeContainedClass2;
}

void StableClassImpl::Method1(int i) {

}

void StableClassImpl::Method2(int i) {

}

StableClassImpl::~StableClassImpl() {
    delete m_SomeContainedClass1;
    delete m_SomeContainedClass2;
}