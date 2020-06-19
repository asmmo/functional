template <class T>
struct refWrapper{
    operator T&(){
        return member;
    }
    explicit myRef(T& ref):member{ref}{}
private:
    T& member;
};
template <class T>
refWrapper<T> myRef( T& arg)
{
    return refWrapper{arg};
}
