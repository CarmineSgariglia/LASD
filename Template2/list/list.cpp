
namespace lasd {

/* ************************************************************************** */
template<typename Data>
List<Data>::Node::Node(Data && dat) noexcept {
    std::swap(element, dat);
}
template<typename Data>
List<Data>::Node::Node(Node && node) noexcept {
    std::swap(element, node.element);
    std::swap(next, node.next);
}


template<typename Data>
List<Data>::Node::~Node() {
    delete next;
}

template<typename Data>
bool List<Data>::Node::operator==(const Node & node) const noexcept {
    return (element == node.element) \
           && ((next == nullptr && node.next == nullptr) || ((next != nullptr && node.next != nullptr) && (*next == *node.next)));
}

template<typename Data>
bool List<Data>::Node::operator!=(const Node & node) const noexcept {
    return !(*this == node);
}

template<typename Data>
typename List<Data>::Node * List<Data>::Node::Clone(Node * tail) {
    if(next == nullptr) {
        return tail;
    } else {
        tail->next = new Node(next->element);
        return next->Clone(tail->next);
    }
}

/* ************************************************************************** */

template<typename Data>
List<Data>::List(const TraversableContainer<Data> & con) {
    con.Traverse([this](const Data & dat) {
        InsertAtBack(dat);
    });
}

template<typename Data>
List<Data>::List(MappableContainer<Data> && con) {
    con.Map([this](Data & dat) {
        InsertAtBack(std::move(dat));
    });
}
/* ************************************************************************ */

template<typename Data>
List<Data>::List(const List<Data> & list) {
    if(list.tail != nullptr) {
        head = new Node(*list.head);
        tail = list.head->Clone(head);
        size = list.size;
    }
}

template<typename Data>
List<Data>::List(List<Data> && list) noexcept {
    std::swap(head, list.head);
    std::swap(tail, list.tail);
    std::swap(size, list.size);
}
/* ************************************************************************ */

template<typename Data>
List<Data>::~List() {
    delete head;
}
/* ************************************************************************ */

template<typename Data>
List<Data> & List<Data>::operator=(const List<Data> & list) {
    List<Data> tmp(list);
    std::swap(head, tmp.head);
    std::swap(tail, tmp.tail);
    std::swap(size, tmp.size);
    return *this;

}

template<typename Data>
List<Data> & List<Data>::operator=(List<Data> && list) noexcept {
    std::swap(head, list.head);
    std::swap(tail, list.tail);
    std::swap(size, list.size);
    return *this;
}
/* ************************************************************************ */

template<typename Data>
inline bool List<Data>::operator==(const List<Data> & list) const noexcept {
    return (size == list.size) \
           && ((head == nullptr && list.head == nullptr) || ((head != nullptr && list.head != nullptr) && (*head == *list.head)));
}

template<typename Data>
inline bool List<Data>::operator!=(const List<Data> & list) const noexcept {
    return !(*this == list);
}
/* ************************************************************************ */

template<typename Data>
void List<Data>::InsertAtFront(const Data & dat) {
    Node * ptr = new Node(dat);
    ptr->next = head;
    head = ptr;
    if(tail == nullptr) {
        tail = head;
    }
    ++size;
}

template<typename Data>
void List<Data>::InsertAtFront(Data && dat) {
    Node * ptr = new Node(std::move(dat));
    ptr->next = head;
    head = ptr;
    if(tail == nullptr) {
        tail = head;
    }
    ++size;
}
template<typename Data>
void List<Data>::RemoveFromFront() {
    if(head != nullptr) {
        Node * front = head;
        if(tail == head) {
            head = tail = nullptr;
        } else {
            head = head->next;
        }
        --size;
        front->next = nullptr;
        delete front;
    } else {
        throw std::length_error("Access to an empty list.");
    }
}

template<typename Data>
Data List<Data>::FrontNRemove() {
    if(head != nullptr) {
        Node * front = head;
        if(tail == head) {
            head = tail = nullptr;
        } else {
            head = head->next;
        }
        --size;
        front->next = nullptr;
        Data dat(std::move(front->element));
        delete front;
        return dat;
    } else {
        throw std::length_error("Access to an empty list.");
    }
}

template<typename Data>
void List<Data>::InsertAtBack(const Data & dat) {
    Node * end = new Node(dat);
    if(tail == nullptr) {
        head = end;
    } else {
        tail->next = end;
    }
    tail = end;
    ++size;
}
template<typename Data>
void List<Data>::InsertAtBack(Data && dat) {
    Node * end = new Node(std::move(dat));
    if(tail == nullptr) {
        head = end;
    } else {
        tail->next = end;
    }
    tail = end;
    ++size;
}
template<typename Data>
void List<Data>::RemoveFromBack() {
    if(head != nullptr) {
        if(head == tail) {
            delete tail;
            head = tail = nullptr;
        } else {
            Node* ptr = head;
            while(ptr->next != tail) {
                ptr = ptr->next;
            }
            delete tail;
            tail = ptr;
            tail->next = nullptr;
        }
        --size;
    } else {
        throw std::length_error("Remove from empty list.");
    }
}

template<typename Data>
Data List<Data>::BackNRemove() {
    if(head != nullptr) {
        Data d = tail->element;
        if(head == tail) {
            delete tail;
            head = tail = nullptr;
        } else {
            Node* ptr = head;
            while(ptr->next != tail) {
                ptr = ptr->next;
            }
            delete tail;
            tail = ptr;
            tail->next = nullptr;
        }
        --size;
        return d;
    } else {
        throw std::length_error("BackNRemove from empty list.");
    }
}
/* ************************************************************************ */

template<typename Data>
Data & List<Data>::operator[](const ulong index) {
    return const_cast<Data &>(static_cast<const List<Data>*>(this)->operator[](index));
}
template<typename Data>
Data & List<Data>::Front() {
    return const_cast<Data &>(static_cast<const List<Data>*>(this)->Front());
}
template<typename Data>
Data & List<Data>::Back() {
    return const_cast<Data &>(static_cast<const List<Data>*>(this)->Back());
}

/* ************************************************************************ */

template<typename Data>
const Data & List<Data>::operator[](const ulong index) const {
    if(index < size) {
        Node * cur = head;
        for(ulong idx = 0; idx < index; ++idx, cur = cur->next) {}
        return cur->element;
    } else {
        throw std::out_of_range("Access at index " + std::to_string(index) + "; list size " + std::to_string(size) + ".");
    }
}

template<typename Data>
const Data & List<Data>::Front() const {
    if(head != nullptr) {
        return head->element;
    } else {
        throw std::length_error("Access to an empty list.");
    }
}

template<typename Data>
const Data & List<Data>::Back() const {
    if(tail != nullptr) {
        return tail->element;
    } else {
        throw std::length_error("Access to an empty list.");
    }
}
/* ************************************************************************ */

template<typename Data>
inline void List<Data>::Map(MapFun fun) {
    PreOrderMap(fun, head);
}

template<typename Data>
inline void List<Data>::PreOrderMap(MapFun fun) {
    PreOrderMap(fun, head);
}

template<typename Data>
inline void List<Data>::PostOrderMap(MapFun fun) {
    PostOrderMap(fun, head);
}
/* ************************************************************************ */

template<typename Data>
inline void List<Data>::Traverse(TraverseFun fun) const {
    PreOrderTraverse(fun, head);
}

template<typename Data>
inline void List<Data>::PreOrderTraverse(TraverseFun fun) const {
    PreOrderTraverse(fun, head);
}

template<typename Data>
inline void List<Data>::PostOrderTraverse(TraverseFun fun) const {
    PostOrderTraverse(fun, head);
}

/* ************************************************************************ */

template<typename Data>
void List<Data>::Clear() {
    delete head;
    head = tail = nullptr;
    size = 0;
}

template<typename Data>
void List<Data>::PreOrderMap(MapFun fun, Node * cur) {
    while(cur != nullptr) {
        fun(cur->element);
        cur = cur->next;
    }
}

template<typename Data>
void List<Data>::PostOrderMap(MapFun fun, Node * cur) {
    if(cur != nullptr) {
        PostOrderMap(fun, cur->next);
        fun(cur->element);
    }
}

template<typename Data>
void List<Data>::PreOrderTraverse(TraverseFun fun, const Node * cur) const {
    while(cur != nullptr) {
        fun(cur->element);
        cur = cur->next;
    }
}

template<typename Data>
void List<Data>::PostOrderTraverse(TraverseFun fun, const Node * cur) const {
    if(cur != nullptr) {
        PostOrderTraverse(fun, cur->next);
        fun(cur->element);
    }
}

}
