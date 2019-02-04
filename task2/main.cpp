#include <iostream>
#include <vector>
#include <exception>

template<class T>
class Deque{
private:
    struct Element{
        T data;
        Element* back;
        Element* next;
    };

    T& GetByIndex(unsigned long index){
        Element *el = head;
        for(unsigned long i = 0; i < index; ++i)
        {
            el = el->next;
        }
        return el->data;
    }

    Element *head, *tail;
    unsigned long _count;
    bool head_trig;
    bool tail_trig;

public:
    Deque():_count(0), head_trig(true), tail_trig(true)
    {
        head = new Element;
        tail = new Element;
        head->next = tail;
        head->back = nullptr;
        tail->next = nullptr;
        tail->back = head;
    }
    bool isEmpty( )const{return !static_cast<bool>(_count);}
    unsigned long Count()const{return _count;}
    void PushFront(T data)
    {
        if(head_trig)
        {
            head->data = data;
            head_trig = false;
        }
        else
        {
            Element *swap= new Element;
            swap = head;
            Element *el = new Element;
            el->data = data;
            el->next = swap;
            el->back = nullptr;
            head = el;
            swap->back = head;
        }

        _count++;
    }
    void PushBack(T data)
    {
        if(tail_trig)
        {
            tail->data = data;
            tail_trig = false;
        }
        else
        {
            Element *swap= new Element;
            swap = tail;
            Element *el = new Element;
            el->data = data;
            el->next = nullptr;
            el->back = swap;
            tail = el;
            swap->next = tail;
        }
        _count++;
    }
    T& Front() const
    {
        return head->data;
    }
    T& Back() const
    {
        return tail->data;
    }

    T& Front()
    {
        return head->data;
    }
    T& Back()
    {
        return tail->data;
    }

    T& operator[](size_t index)
    {
        return GetByIndex(index);
    }
    const T& operator[](size_t index)const
    {
        return GetByIndex(index);
    }

    T& At(unsigned long index)
    {
        if(index < 0 || index >= _count) throw std::out_of_range("Index out of range.");
        return GetByIndex(index);
    }

};

int main()
{
    Deque<int> dec;

    dec.PushBack(1);
    dec.PushBack(2);
    dec.PushBack(3);
    dec.PushBack(4);
    dec.PushBack(5);
    dec.PushBack(6);
    dec.PushBack(7);
    dec.PushBack(8);
    dec.PushBack(9);
    dec.PushBack(10);
    dec.PushFront(99);
    dec.PushFront(199);
    dec.PushFront(29);
    dec.PushFront(87);
    dec.PushFront(34);

    std::cout << dec.At(0) << std::endl;
    std::cout << dec[0] << std::endl;
    std::cout << dec.Front() << std::endl;
    std::cout << dec.Back() << std::endl;
    std::cout << dec.isEmpty() << std::endl;
    std::cout << dec.Count() << std::endl;

    try{
        std::cout << dec.At(89);
    }
    catch(std::exception *ex){
        std::cout << ex->what();
    }


    return 0;
}
