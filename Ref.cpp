template <class T>
struct Ref{
    operator T&(){
        return member;
    }
    explicit myRef(T& ref):member{ref}{}
private:
    T& member;
};
