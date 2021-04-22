template<typename T>
class Structure {
public:

    virtual void push(const T &value) = 0;

    virtual T pop() = 0;

    virtual T peek() = 0;

    virtual int getSize() const = 0;

    friend std::ostream& operator<<(std::ostream &out, const Structure<T> *p)
    {
        return p->print(out);
    }

    virtual std::ostream& print(std::ostream& out) const
    {
        out << "Parent";
        return out;
    }
};