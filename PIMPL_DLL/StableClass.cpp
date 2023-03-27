// PIMPL_DLL.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "StableClass.h"
#include "SomeContainedClass1.h"
#include "SomeContainedClass2.h"


class StableClass::StableClassImpl {

    public:
	    StableClassImpl(void) : m_SomeContainedClass1(nullptr), m_SomeContainedClass2(nullptr) {}

	    void StableClass::Method1(int i) {}

	    void StableClass::Method2(int i) {}

	    SomeContainedClass1* GetSomeContainedClass1() {
            return m_SomeContainedClass1;
        }

	    SomeContainedClass2* GetSomeContainedClass2() {
            return m_SomeContainedClass2;
        }

    private:
	    SomeContainedClass1* m_SomeContainedClass1;
	    SomeContainedClass2* m_SomeContainedClass2;
};

StableClass::StableClass() : stableClassImpl(new StableClassImpl()) {}

StableClass::~StableClass() {
    delete stableClassImpl;
}

void StableClass::Method1(int i) {
    stableClassImpl->Method1(i);
}

void StableClass::Method2(int i) {
    stableClassImpl->Method2(i);
}

SomeContainedClass1* StableClass::GetSomeContainedClass1() {
    return stableClassImpl->GetSomeContainedClass1();
}

SomeContainedClass2* StableClass::GetSomeContainedClass2() {
    return stableClassImpl->GetSomeContainedClass2();
}
