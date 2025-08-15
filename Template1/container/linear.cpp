namespace lasd {

/* ************************************************************************** */
template<typename Data>
inline bool LinearContainer<Data>::operator==(const LinearContainer<Data> & con) const noexcept {
    if(size == con.size) {
        for(ulong i = 0; i < size; ++i) {
            if(operator[](i) != con.operator[](i)) {
                return false;
            }
        }
        return true;
    } else {
        return false;
    }
}

template<typename Data>
inline bool LinearContainer<Data>::operator!=(const LinearContainer<Data> & con) const noexcept {
    return !(*this == con);
}

template<typename Data>
inline const Data & LinearContainer<Data>::Front() const {
    if(this->Empty()) {
        throw std::length_error("Empty container");
    } else {
        return operator[](0);
    }
}
template<typename Data>
inline const Data & LinearContainer<Data>::Back() const {
    if(this->Empty()) {
        throw std::length_error("Empty container");
    } else {
        return operator[](size - 1);
    }
}

template<typename Data>
inline void LinearContainer<Data>::Traverse(TraverseFun fun) const {
    PreOrderTraverse(fun);
}
template<typename Data>
inline void LinearContainer<Data>::PreOrderTraverse(TraverseFun fun) const {
    for(ulong i = 0; i < size; ++i) {
        fun(operator[](i));
    }

}
template<typename Data>
inline void LinearContainer<Data>::PostOrderTraverse(TraverseFun fun) const {
    ulong i = size;
    while(i > 0) {
        fun(operator[](--i));
    }
}
/* ************************************************************************** */
template <typename Data>
inline Data & MutableLinearContainer<Data>::Front() {
    if(this->Empty()) {
        throw std::length_error("Empty container");
    } else {
        return operator[](0);

    }
}

template <typename Data>
inline Data & MutableLinearContainer<Data>::Back() {
    if(this->Empty()) {
        throw std::length_error("Empty container");
    } else {
        return operator[](size - 1);

    }
}

template<typename Data>
inline void MutableLinearContainer<Data>::Map(MapFun fun) {
    PreOrderMap(fun);
}
template<typename Data>
inline void MutableLinearContainer<Data>::PreOrderMap(MapFun fun) {
    for(ulong i = 0; i < size; ++i) {
        fun(operator[](i));
    }
}

template<typename Data>
inline void MutableLinearContainer<Data>::PostOrderMap(MapFun fun) {
    ulong i = size;
    while(i > 0) {
        fun(operator[](--i));
    }
}
/* ************************************************************************** */
template<typename Data>
void SortableLinearContainer<Data>::Sort() noexcept {
    if(this->size <= 0) {
     return;
    } else {
        QuickSort(0, size - 1);

    }
}

template<typename Data>
void SortableLinearContainer<Data>::QuickSort(ulong p, ulong r) noexcept {
    if(p < r) {
        ulong q = Partition(p, r);
        QuickSort(p, q);
        QuickSort(q + 1, r);
    }
}

template<typename Data>
ulong SortableLinearContainer<Data>::Partition(ulong p, ulong r) noexcept {
    Data x = this->operator[](p);
    ulong i = p - 1;
    ulong j = r + 1;
    do {
        do {
            j--;
        } while(x < this->operator[](j));
        do {
            i++;
        } while(x > this->operator[](i));
        if(i < j) {
            std::swap(this->operator[](i), this->operator[](j));
        }
    } while(i < j);
    return j;
}

/* ************************************************************************** */

}
