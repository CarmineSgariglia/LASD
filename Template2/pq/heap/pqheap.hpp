
#ifndef PQHEAP_HPP
#define PQHEAP_HPP

/* ************************************************************************** */

#include "../pq.hpp"
#include "../../heap/vec/heapvec.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class PQHeap: virtual public PQ<Data>, protected HeapVec<Data> {

  private:

  protected:

    using Container::size;
    ulong capacity = 0;

  public:

    // Default constructor
    PQHeap() = default;

    /* ************************************************************************ */

    // Specific constructors
    PQHeap(const TraversableContainer<Data> &); 
    PQHeap(MappableContainer<Data> &&); 

    /* ************************************************************************ */

    // Copy constructor
    PQHeap(const PQHeap &);

    // Move constructor
    PQHeap(PQHeap &&) noexcept;

    /* ************************************************************************ */

    // Destructor
    virtual ~PQHeap() = default;

    /* ************************************************************************ */

    // Copy assignment
    PQHeap & operator=(const PQHeap &);

    // Move assignment
    PQHeap & operator=(PQHeap &&) noexcept;

    /* ************************************************************************ */

    // Specific member functions (inherited from PQ)

    const Data &  Tip() const override; 
    void RemoveTip() override; 
    Data TipNRemove() override; 

    void Insert(const Data &) override; 
    void Insert(Data &&) override ;

    void Change(ulong index, const Data &) override; 
    void Change(ulong index, Data &&) override; 

    const Data & operator[](ulong) const override;

    void Clear() override;

    using LinearContainer<Data>::operator==;
    using LinearContainer<Data>::operator!=;
    using LinearContainer<Data>::Front;
    using LinearContainer<Data>::Back;
  protected:

    // Auxiliary functions
    void siftUp(ulong);
    
    void Resize(ulong);
};

/* ************************************************************************** */

}

#include "pqheap.cpp"

#endif
