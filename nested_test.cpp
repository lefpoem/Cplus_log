//嵌套类没有外围类成员，外围类没有嵌套类成员
template<class Type> class Queue{
private:
    struct QueueItem;
    QueueItem *head;
    QueueItem *tail;
}; 
template<class Type> struct Queue<Type>::QueueItem{
    QueueItem(const Type& t):item(t),next(o){}
    Type item;
    QueueItem *next;
};//嵌套类可直接引用外围类的静态成员，类型名和枚举成员
Queue<int> qi;//instantiates Queue<int> but not QueueItem<int>
