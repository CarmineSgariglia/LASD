
namespace lasd {

/* ************************************************************************** */

template <typename Data>
SetVec<Data>::SetVec(const TraversableContainer<Data> &con) {
    con.Traverse([this](const Data & dat) {
        Insert(dat);
    });
}

template <typename Data>
SetVec<Data>::SetVec(MappableContainer<Data> &&con) {
    con.Map([this](Data & dat) {
        Insert(std::move(dat));
    });
}

/* ************************************************************************** */

template <typename Data>
SetVec<Data>::SetVec(const SetVec<Data> &auxiliary) {
    this->Resize(auxiliary.capacity);
    this->size = auxiliary.size;
    this->head = auxiliary.head;
    this->tail = auxiliary.tail;
    this->capacity = auxiliary.capacity;
    for(ulong index = 0; index < this->size; index++) {
        ulong realIndex = (this->head + index) % this->capacity;
        ulong vectorIndex = (auxiliary.head + index) % auxiliary.capacity;
        vec[realIndex] = auxiliary.vec[vectorIndex];
    }
}



template <typename Data>
SetVec<Data>::SetVec(SetVec<Data> &&auxiliary) noexcept {
    vec = std::move(auxiliary.vec);
    std::swap(this->size, auxiliary.size);
    std::swap(this->head, auxiliary.head);
    std::swap(this->tail, auxiliary.tail);
    std::swap(this->capacity, auxiliary.capacity);


}

template <typename Data>
SetVec<Data> &SetVec<Data>::operator=(const SetVec<Data> &auxiliary) {
    this->Resize(auxiliary.capacity);
    this->size = auxiliary.size;
    this->head = auxiliary.head;
    this->tail = auxiliary.tail;
    this->capacity = auxiliary.capacity;

    for(ulong i = 0; i < this->size; ++i) {
        vec[i] = auxiliary.vec[i];
    }
    return *this;
}

template <typename Data>
SetVec<Data> &SetVec<Data>::operator=(SetVec<Data> &&auxiliary) noexcept {
    vec = std::move(auxiliary.vec);
    std::swap(this->size, auxiliary.size);
    std::swap(this->head, auxiliary.head);
    std::swap(this->capacity, auxiliary.capacity);
    std::swap(this->tail, auxiliary.tail);
    return *this;
}

template <typename Data>
bool SetVec<Data>::operator==(const SetVec<Data> &auxiliary) const noexcept {
    if(this->size != auxiliary.size)
        return false;

    // Usa la stessa logica di Exists
    for(ulong i = 0; i < this->size; ++i) {
        ulong realIdx = (this->head + i) % capacity;
        ulong auxiliaryRealIdx = (auxiliary.head + i) % auxiliary.capacity;
        if(vec[realIdx] != auxiliary.vec[auxiliaryRealIdx])
            return false;
    }

    return true;
}

template <typename Data>
bool SetVec<Data>::operator!=(const SetVec<Data> &auxiliary) const noexcept {
    return !(*this == auxiliary);
}

/* ************************************************************************** */

template <typename Data>
bool SetVec<Data>::Insert(const Data &val) {

    if(this->capacity == 0) {
        
        this->Resize(1);
        vec[0] = val;
        this->head = 0;
        this->tail = 1 ;
        this->size = 1;
        return true;
    }

    if((size * 100) / capacity >= 80) {
        this->Resize(capacity * 2);
    }

    ulong insertPos = 0;
    uint i  = 0;
    uint j = this->size;
    uint k = 0;

    while(i < j) {
        k = (i + j) / 2;
        if(val < vec[(this->head + k) % this->capacity]) {

            j = k;

        } else if(val > vec[(this->head + k) % this->capacity]) {

            i = k + 1;

        } else {
            return false;
        }
    }
    insertPos = i;

    for(ulong i = this->size; i > insertPos; --i) {
        ulong from = (this->head + i - 1) % this->capacity;
        ulong to = (this->head + i) % this->capacity;
        vec[to] = vec[from];
    }

    ulong realInsertIdx = (this->head + insertPos) % this->capacity;
    vec[realInsertIdx] = val;
    this->size++;
    this->tail = (this->head + this->size) % this->capacity;

    return true;
}

template <typename Data>
bool SetVec<Data>::Insert(Data &&val) {
    

    if(this->capacity == 0) {
        this->Resize(1);
        vec[0] = std::move(val);
        this->head = 0;
        this->tail = 1 ;
        this->size = 1;
        return true;
    }

    if((size * 100) / capacity >= 80) {
        this->Resize(capacity * 2);
    }

    ulong insertPos = 0;
    uint i  = 0;
    uint j = this->size;
    uint k = 0;

    while(i < j) {
        k = (i + j) / 2;
        if(val < vec[(this->head + k) % this->capacity]) {

            j = k;

        } else if(val > vec[(this->head + k) % this->capacity]) {

            i = k + 1;

        } else {
            return false;
        }
    }
    insertPos = i;

    for(ulong i = this->size; i > insertPos; --i) {
        ulong from = (this->head + i - 1) % this->capacity;
        ulong to = (this->head + i) % this->capacity;
        vec[to] = std::move(vec[from]);
    }

    ulong realInsertIdx = (this->head + insertPos) % this->capacity;;
    vec[realInsertIdx] = std::move(val);
    this->size++;

    this->tail = (this->head + this->size) % this->capacity;
    return true;
}


template <typename Data>
bool SetVec<Data>::Remove(const Data &val) {

    if(this->size == 0) {
        return false;
    }
    ulong i = 0;
    ulong j = size;
    while(i < j) {
        ulong k = (i + j) / 2;
        if(val < vec[(head + k) % capacity]) {
            j = k;
        } else if(val > vec[(head + k) % capacity]) {
            i = k + 1;
        } else {
            i = k;
            break;
        }
    }
    if(i >= size) {
        return false;
    }
    ulong pos = (head + i) % capacity;
    if(vec[pos] != val) {
        return false;
    }

    ulong read  = (pos + 1) % capacity;
    ulong write = pos;

    ulong end   = (head + size) % capacity;
    while(read != end) {
        vec[write] = std::move(vec[read]);
        write = read;
        read  = (read + 1) % capacity;
    }

    size--;
    tail = (tail + capacity - 1) % capacity;
    if((size * 100) / capacity <= 20) {
        this->Resize(capacity / 2);
    }

    return true;


}

/* ************************************************************************** */

template <typename Data>
const Data &SetVec<Data>::operator[](ulong index) const {
    if(index >= this->size || index < 0) {
        throw std::out_of_range("Index out of range");
    }
    ulong realIndex = (this->head + index) % this->capacity;

    return vec[realIndex];
}


template <typename Data>
const Data& SetVec<Data>::Min() const {
    if(this->size == 0) {
        throw std::length_error("Container is empty");
    }

    return vec[this->head];
}

template <typename Data>
Data SetVec<Data>::MinNRemove() {
    if(this->Empty()) {
        throw std::length_error("Container is empty");
    }
    Data d = vec[this->head];
    this->head = (this->head + 1) % capacity;
    size--;
    if((size * 100) / capacity <= 20) {
        this->Resize(capacity / 2);
    }
    return d;

}

template <typename Data>
void SetVec<Data>::RemoveMin() {
    if(this->Empty()) {
        throw std::length_error("Container is empty");
    }

    this->head = (this->head + 1) % capacity;
    size--;
    if((size * 100) / capacity <= 20) {
        this->Resize(capacity / 2);
    }
}


template <typename Data>
const Data& SetVec<Data>::Max() const {
    if(this->size == 0) {
        throw std::length_error("Container is empty");
    }
    ulong index = (this->tail + capacity - 1) % this->capacity;
    return vec[index];
}


template <typename Data>
Data SetVec<Data>::MaxNRemove() {
    if(this->Empty()) {
        throw std::length_error("Container is empty");
    }

    ulong index = (tail + capacity - 1) % capacity;
    Data max = vec[index];
    size--;
    tail = (tail + capacity - 1) % capacity;

    if((size * 100) / capacity <= 20) {
        this->Resize(capacity / 2);
    }
    return max;

}

template <typename Data>
void SetVec<Data>::RemoveMax() {
    if(this->Empty()) {
        throw std::length_error("Container is empty");
    }

    size--;
    tail = (tail + capacity - 1) % capacity;

    if((size * 100) / capacity <= 20) {
        this->Resize(capacity / 2);
    }
}

template <typename Data>
inline const Data& SetVec<Data>::Predecessor(const Data &key) const {
    if(this->size == 0) {
        throw std::length_error("Container is empty");
    }
    ulong i = 0;
    ulong j = this->size ;
    ulong p;
    bool found = false;
    while(i < j) {
        ulong k     = (i + j) / 2;
        if(vec[(this->head + k) % this->capacity] < key) {
            p = k;
            i = k + 1;

            found = true;
        } else {
            j = k;

        }
    }
    if(found == false) {
        throw std::length_error("No predecessor has been found");

    }
    return vec[(head + p) % capacity];
}

template <typename Data>
inline Data SetVec<Data>::PredecessorNRemove(const Data &key) {
    if(this->size == 0) {
        throw std::length_error("Container is empty");
    }
  ulong i = 0;
    ulong j = this->size ;
    ulong p;
    bool found = false;
    while(i < j) {
        ulong k     = (i + j) / 2;
        if(vec[(this->head + k) % this->capacity] < key) {
            p = k;
            i = k + 1;

            found = true;
        } else {
            j = k;

        }
    }
    if(found == false) {
        throw std::length_error("No predecessor has been found");

    }
    ulong realPos = (head + p) % capacity;
    Data d = vec[(head + p) % capacity];

    ulong read  = (realPos + 1) % capacity;
    ulong write = realPos;
    ulong end   = (head + size) % capacity;

    while(read != end) {
        vec[write] = std::move(vec[read]);
        write = read;
        read  = (read + 1) % capacity;
    }

    size--;
    tail = (tail == 0 ? capacity - 1 : tail - 1);
    if((size * 100) / capacity <= 20) {
        this->Resize(capacity / 2);
    }

    return d;
 
}


template <typename Data>
inline void SetVec<Data>::RemovePredecessor(const Data &key) {
      if(this->size == 0) {
        throw std::length_error("Container is empty");
    }

    ulong i = 0;
    ulong j = this->size ;
    ulong p;
    bool found = false;

    while(i < j) {
        ulong k     = (i + j) / 2;
        if(vec[(this->head + k) % this->capacity] < key) {

            p = k;
            i = k + 1;
            found = true;

        } else {

            j = k;

        }
    }
    if(found == false) {
        throw std::length_error("No predecessor has been found");

    }

    ulong realPos = (head + p) % capacity;
    ulong read  = (realPos + 1) % capacity;
    ulong write = realPos;
    ulong end   = (head + size) % capacity;

    while(read != end) {
        vec[write] = std::move(vec[read]);
        write = read;
        read  = (read + 1) % capacity;
    }

    size--;
    tail = (tail == 0 ? capacity - 1 : tail - 1);
    if((size * 100) / capacity <= 20) {
        this->Resize(capacity / 2);
    }

}

template <typename Data>
inline const Data& SetVec<Data>::Successor(const Data &key) const {
    if(this->size == 0) {
        throw std::length_error("Container is empty");
    }
    ulong i = 0;
    ulong j = this->size ;
    ulong s;
    bool found = false;
    while(i < j) {
        ulong k     = (i + j) / 2;
        if(vec[(this->head + k) % this->capacity] > key) {
            j = k;
            s = k;
            found = true;
        } else {

            i = k + 1;
        }
    }
    if(found == false) {
        throw std::length_error("No successor has been found");

    }
    return vec[(head + s) % capacity];

}

template <typename Data>
inline Data SetVec<Data>::SuccessorNRemove(const Data &key) {
    if(this->size == 0) {
        throw std::length_error("Container is empty");
    }

    ulong i = 0;
    ulong j = this->size ;
    ulong s;
    bool found = false;

    while(i < j) {
        ulong k     = (i + j) / 2;
        if(vec[(this->head + k) % this->capacity] > key) {

            j = k;
            s = k;
            found = true;

        } else {

            i = k + 1;
        }
    }
    if(found == false) {
        throw std::length_error("No successor has been found");

    }
    ulong realPos = (head + s) % capacity;
    Data d = vec[(head + s) % capacity];
    ulong read  = (realPos + 1) % capacity;
    ulong write = realPos;
    ulong end   = (head + size) % capacity;

    while(read != end) {
        vec[write] = std::move(vec[read]);
        write = read;
        read  = (read + 1) % capacity;
    }

    size--;
    tail = (tail == 0 ? capacity - 1 : tail - 1);
    if((size * 100) / capacity <= 20) {
        this->Resize(capacity / 2);
    }

    return d;
}


template <typename Data>
inline void SetVec<Data>::RemoveSuccessor(const Data &key) {
    if(this->size == 0) {
        throw std::length_error("Container is empty");
    }

    ulong i = 0;
    ulong j = this->size ;
    ulong s;
    bool found = false;
    while(i < j) {
        ulong k     = (i + j) / 2;
        if(vec[(this->head + k) % this->capacity] > key) {

            j = k;
            s = k;
            found = true;

        } else {

            i = k + 1;
        }
    }
    if(found == false) {
        throw std::length_error("No successor has been found");

    }

    ulong realPos = (head + s) % capacity;
    ulong read  = (realPos + 1) % capacity;
    ulong write = realPos;
    ulong end   = (head + size) % capacity;

    while(read != end) {
        vec[write] = std::move(vec[read]);
        write = read;
        read  = (read + 1) % capacity;
    }
    
    size--;
    tail = (tail == 0 ? capacity - 1 : tail - 1);
    if((size * 100) / capacity <= 20) {
        this->Resize(capacity / 2);
    }

}

/* ************************************************************************** */

template <typename Data>
bool SetVec<Data>::Exists(const Data &val) const noexcept {
    if(this->Size() == 0)
        return false;

    ulong i = 0, j = size;
    while(i < j) {
        ulong mid     = (i + j) / 2;
        ulong realMid = (head + mid) % capacity;
        if(val < vec[realMid]) {
            j = mid;
        } else if(val > vec[realMid]) {
            i = mid + 1;
        } else {
            i = mid;
            return true;
        }
    }

    return false;
}


template <typename Data>
void SetVec<Data>::Clear() {
    this->Resize(0);
}

/* ************************************************************************** */


template <typename Data>
void SetVec<Data>::Resize(ulong newSize) {

    if(newSize == 0) {
        vec.Clear();
        this->size = 0;
        this->head = 0;
        this->capacity = 0;
        this->tail = 0;
        return;
    }

    lasd::Vector<Data> newVec(newSize);
    ulong copySize = std::min(this->size, newSize);

    for(ulong i = 0; i < copySize; ++i) {
        newVec[i] = std::move(vec[(this->head + i) % this->capacity]);
    }

    vec = std::move(newVec);
    this->head = 0;
    this->tail = copySize;
    this->size = copySize;
    this->capacity = newSize;
}

}

/* ************************************************************************** */


