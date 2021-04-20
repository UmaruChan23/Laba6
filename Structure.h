template<typename T>
class Structure {
public:

    virtual void push(const T &value) = 0;

    virtual T pop() = 0;

    virtual T peek() = 0;

    virtual int getSize() const = 0;
};