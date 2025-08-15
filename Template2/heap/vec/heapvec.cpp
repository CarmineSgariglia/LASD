
namespace lasd {

/* ************************************************************************** */
// Specific constructors
template<typename Data>
HeapVec<Data>::HeapVec(const TraversableContainer<Data> & con):  SortableVector<Data>(con) {
    Heapify();
}

template<typename Data>
HeapVec<Data>::HeapVec(MappableContainer<Data> && con):  SortableVector<Data>(std::move(con)) {
    Heapify();
}

template<typename Data>
HeapVec<Data>::HeapVec(const HeapVec<Data>& heapvec): SortableVector<Data>(heapvec) {
    Heapify();
}

template<typename Data>
HeapVec<Data>::HeapVec(HeapVec<Data> && heapvec) noexcept:  SortableVector<Data>(std::move(heapvec)) {
    Heapify();
}



// Copy & Move assignment
template<typename Data>
HeapVec<Data> & HeapVec<Data>::operator=(const HeapVec<Data> & heap) {
    if(*this != heap) {

        SortableVector<Data>::operator=(heap);
    }
    return *this;

}
template<typename Data>
HeapVec<Data> & HeapVec<Data>::operator=(HeapVec<Data> && heap) noexcept {
    SortableVector<Data>::operator=(std::move(heap));
    return *this;

}

//Comparison operator
template<typename Data>
bool HeapVec<Data>::operator==(const HeapVec & heap) const noexcept {
    return SortableVector<Data>::operator==(heap);
}
template<typename Data>
bool HeapVec<Data>::operator!=(const HeapVec & heap) const noexcept {
    return !(*this == heap);
}

template<typename Data>
bool HeapVec<Data>::IsHeap() const  {
    ulong indexLeft = 0;
    ulong indexRight = 0;
    for(ulong i = 0; i < size / 2; i++) {
        indexLeft = GetChildSx(i);
        indexRight = GetChildDx(i);
        if(indexLeft < size && this->Elements[i] < this->Elements[indexLeft]) {
            return false;
        }
        if(indexRight < size && this->Elements[i] < this->Elements[indexRight]) {
            return false;
        }

    }
    return true;
}

template<typename Data>
void HeapVec<Data>::Heapify()   {
    if(size < 2) return;

    ulong i = size / 2; 
    while(i > 0) {
        --i;
        heapify(size, i);
    }
}
template<typename Data>
void HeapVec<Data>::Sort() noexcept {
    if(size < 2) return;
    Heapify();
    ulong index = size - 1;
    while(index > 0) {
        std::swap(this->Elements[0], this->Elements[index]);
        heapify(index--, 0);

    }

}

template<typename Data>
const Data& HeapVec<Data>::operator[](ulong index) const   {
    return Vector<Data>::operator[](index);
}

template<typename Data>
Data& HeapVec<Data>::operator[](ulong index)  {
    return Vector<Data>::operator[](index);
}


template<typename Data>
void HeapVec<Data>::Clear() {
    this->Resize(0);
}

/* ************************************************************************** */

template<typename Data>
void HeapVec<Data>::heapify(ulong n, ulong i) {
    ulong m = i;
    ulong l = GetChildSx(i);
    ulong r = GetChildDx(i);
    if((l < n) && (this->Elements[m] < this->Elements[l])) {                 
                                                                            
        m = l;
    }
    if((r < n) && (this->Elements[m] < this->Elements[r])) {
        m = r;
    }
    if(m != i) {
        std::swap(this->Elements[i], this->Elements[m]);
        heapify(n, m);
    }
}



template<typename Data>
ulong HeapVec<Data>::GetChildSx(ulong i) const {
    return 2 * i + 1;
}

template<typename Data>
ulong HeapVec<Data>::GetChildDx(ulong i) const {
    return 2 * i + 2;
}
}

