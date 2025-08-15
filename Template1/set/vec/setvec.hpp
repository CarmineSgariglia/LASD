
#ifndef SETVEC_HPP
#define SETVEC_HPP

/* ************************************************************************** */

#include "../set.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class SetVec: virtual public Set<Data>, virtual public ResizableContainer {
  
  private:

  protected:

    using Container::size;
    lasd::Vector<Data> vec;
    ulong head = 0;
    ulong tail = 0;
    ulong capacity = 0;
  public:

    // Default constructor
    SetVec() = default;

    /* ************************************************************************ */

    // Specific constructors
    SetVec(const TraversableContainer<Data>&); 
    SetVec(MappableContainer<Data>&&); 

    /* ************************************************************************ */

    // Copy constructor
    SetVec(const SetVec&);


    // Move constructor
    SetVec(SetVec&&) noexcept;


    /* ************************************************************************ */

    // Destructor
    virtual ~SetVec() = default;

    /* ************************************************************************ */

    // Copy assignment
    SetVec &operator=(const SetVec&);

    // Move assignment
    SetVec &operator=(SetVec&&) noexcept;

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const SetVec&) const noexcept;
    inline bool operator!=(const SetVec&) const noexcept;

    /* ************************************************************************ */

    // Specific member functions (inherited from OrderedDictionaryContainer)

    inline const Data& Min() const override;
    inline Data MinNRemove() override;
    inline void RemoveMin() override;

    inline const Data& Max() const override;
    inline Data MaxNRemove() override; 
    inline void RemoveMax() override; 

    inline const Data& Predecessor(const Data&) const override;
    inline Data PredecessorNRemove(const Data&) override; 
    inline void RemovePredecessor(const Data&) override;

    inline const Data& Successor(const Data&) const override;
    inline Data SuccessorNRemove(const Data&) override; 
    inline void RemoveSuccessor(const Data&) override; 

    /* ************************************************************************ */

    // Specific member functions (inherited from DictionaryContainer)

    bool Insert(const Data&) override;
    bool Insert(Data&&) override;
    bool Remove(const Data&) override; 
    /* ************************************************************************ */

    // Specific member functions (inherited from LinearContainer)

    const Data &operator[](ulong) const override; 

    /* ************************************************************************** */

    // Specific member function (inherited from TestableContainer)

    bool Exists(const Data&) const noexcept override;  

    /* ************************************************************************ */

    // Specific member function (inherited from ClearableContainer)

    inline void Clear() override;   

    /* ************************************************************************ */


  protected:

    void Resize(ulong) override; 


};

/* ************************************************************************** */

}

#include "setvec.cpp"

#endif

