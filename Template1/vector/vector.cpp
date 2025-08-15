namespace lasd {

/* ************************************************************************** */

template <typename Data>
Vector<Data>::Vector(const ulong s) {
    size = s;
    Elements = new Data[size] {};
}

template<typename Data>
Vector<Data>::Vector(const TraversableContainer<Data> & con) : Vector(con.Size()) {
    ulong i = 0;
    con.Traverse([this, &i](const Data & dat) {
        Elements[i] = dat;
        i++;
    }
              );
}
template<typename Data>
Vector<Data>::Vector(MappableContainer<Data> && con) : Vector(con.Size()) {
    ulong i = 0;
    con.Map([this, &i](Data & dat) {
        Elements[i] = std::move(dat);
        i++;
    }
         );
}

template<typename Data>
Vector<Data>::Vector(const Vector<Data> & val) {
    size = val.size;
    Elements = new Data[size];
    std::copy(val.Elements, val.Elements + size, Elements);
}

template<typename Data>
Vector<Data>::Vector(Vector<Data> && val) noexcept {
    std::swap(size, val.size);
    std::swap(Elements, val.Elements);
}

template<typename Data>
Vector<Data>::~Vector() {
    delete[] Elements;
}

template<typename Data>
Vector<Data> & Vector<Data>::operator=(const Vector<Data> & val) {
    Vector<Data> * tmp = new Vector<Data>(val);
    std::swap(*tmp, *this);
    delete tmp;
    return *this;
}

template<typename Data>
Vector<Data> & Vector<Data>::operator=(Vector<Data> && val) noexcept {
    std::swap(size, val.size);
    std::swap(Elements, val.Elements);
    return *this;
}

template<typename Data>
bool Vector<Data>::operator==(const Vector<Data> & val) const noexcept {
    if(size == val.size) {

        for(ulong i = 0; i < size; ++i) {
            if(Elements[i] != val.Elements[i]) {
                return false;
            }
        }
        return true;
    } else {
        return false;
    }
}

template<typename Data>
bool Vector<Data>::operator!=(const Vector<Data> & val) const noexcept {
    return !(*this == val);
}

template<typename Data>
Data & Vector<Data>::operator[](const ulong index) {
    return const_cast<Data &>(static_cast<const Vector<Data>* >(this)->operator[](index));
}
template<typename Data>
Data & Vector<Data>::Front() {
    return const_cast<Data &>(static_cast<const Vector<Data>*>(this)->Front());
}
template<typename Data>
Data & Vector<Data>::Back() {
    return const_cast<Data &>(static_cast<const Vector<Data>*>(this)->Back());
}

template<typename Data>
const Data & Vector<Data>::operator[](const ulong index) const {
    if(index < size) {
        return Elements[index];
    } else {
        throw std::out_of_range("Access at index " + std::to_string(index) + "; vector size " + std::to_string(size) + ".");
    }
}

template<typename Data>
const Data & Vector<Data>::Front() const {
    if(size != 0) {
        return Elements[0];
    } else {
        throw std::length_error("Access to an empty vector.");
    }
}
template<typename Data>
const Data & Vector<Data>::Back() const {
    if(size != 0) {
        return Elements[size - 1];
    } else {
        throw std::length_error("Access to an empty vector.");
    }
}
//Resize & Clear
template<typename Data>
void Vector<Data>::Resize(const ulong newsize) {

    if(newsize == 0) {
        delete[] Elements;
        Elements = nullptr;
        size = 0;
    } else if(size != newsize) {
        Data * TmpE = new Data[newsize] {};
        ulong minsize = (size < newsize) ? size : newsize;
        for(ulong i = 0; i < minsize; i++) {
            std::swap(Elements[i], TmpE[i]);
        }
        std::swap(Elements, TmpE);
        size = newsize;
        delete[] TmpE;
    }
}

template<typename Data>
void Vector<Data>::Clear() {
    Resize(0);
}


/* ************************************************************************** */

template<typename Data>
SortableVector<Data>::SortableVector(const ulong s) : Vector<Data>(s) {}

template<typename Data>
SortableVector<Data>::SortableVector(const TraversableContainer<Data> & con) : Vector<Data>(con) {}

template<typename Data>
SortableVector<Data>::SortableVector(MappableContainer<Data> && con) : Vector<Data>(std::move(con)) {}

template<typename Data>
SortableVector<Data>::SortableVector(const SortableVector<Data> & v) : Vector<Data>(v) {}

template<typename Data>
SortableVector<Data>::SortableVector(SortableVector<Data> && v) noexcept : Vector<Data>(std::move(v)) {}

template<typename Data>
SortableVector<Data> & SortableVector<Data>::operator=(const SortableVector<Data> & val) {
    Vector<Data>::operator=(val);
    return *this;
}

template<typename Data>
SortableVector<Data> & SortableVector<Data>::operator=(SortableVector<Data> && val) noexcept {
    Vector<Data>::operator=(std::move(val));
    return *this;
}
/* ************************************************************************** */

}

