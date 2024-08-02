#ifndef CHARSTACK_H
#define CHARSTACK_H


/**
 * @brief Character Stack Implementation
 */
class CharStack
{
private:
    char *stackArray{};
    int stackSize{};
    int top{};

public:
    //Bir nesneyi baska bir nesneye kopyalama
    CharStack(const CharStack&);
    //Atama
    CharStack& operator=(const CharStack &rhs);
    CharStack(int);
    //Default destructor and constructor
    ~CharStack();
    CharStack();
    // Push, pop for stacks
    bool push(char);
    bool pop(char &);
    bool isFull(void);
    bool isEmpty(void);
};

#endif