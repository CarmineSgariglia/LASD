
#ifndef PQ_HPP
#define PQ_HPP

/* ************************************************************************** */

#include "../container/linear.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class PQ: virtual public LinearContainer<Data>, virtual public ClearableContainer {

  private:

  protected:

  public:

    // Destructor
    virtual ~PQ() = default;

    /* ************************************************************************ */

    // Copy assignment
    PQ & operator=(const PQ &) = delete; 

    // Move assignment
    PQ & operator=(PQ &&) noexcept = delete; 

    /* ************************************************************************ */

    // Specific member functions

    virtual const Data & Tip() const = 0; 
    virtual void RemoveTip() = 0; 
    virtual Data TipNRemove() = 0; 

    virtual void Insert(const Data &)  = 0; 
    virtual void Insert(Data &&) = 0; 

    virtual void Change(ulong index, const Data &) = 0; 
    virtual void Change(ulong index, Data &&) = 0;

};

/* ************************************************************************** */

}

#endif
