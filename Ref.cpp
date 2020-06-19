#include <iostream>

template <class T>
struct refWrapper{
    operator T&() {
        return member;
    }
    explicit refWrapper(T& ref):member{ref}{}
private:
    T& member;
};
template <class T>
refWrapper<T> myRef( T& arg)
{
    return refWrapper{arg};
}

template<class T>
void test(T arg)
{
    arg++;
}
int main(){

    int x = 6;
    test(myRef(x));
    std::cout << x;//prints 7


    auto rw1 = refWrapper(x);
    auto rw2 = rw1;
    test(rw2);
    std::cout << "\n" << x;//prints 8
}
