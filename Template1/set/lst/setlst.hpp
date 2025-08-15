
#ifndef SETLST_HPP
#define SETLST_HPP

/* ************************************************************************** */

#include "../set.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class SetLst: virtual public Set<Data>, virtual protected List<Data> {

  private:


  protected:

    using Container::size;

  public:

    // Default constructor
    SetLst() = default;

    /* ************************************************************************ */

    // Specific constructors
    SetLst(const TraversableContainer<Data>&); 
    SetLst(MappableContainer<Data>&&); 
    /* ************************************************************************ */

    // Copy constructor
    SetLst(const SetLst&);

    // Move constructor
    SetLst(SetLst&&) noexcept;

    /* ************************************************************************ */

    // Destructor
    virtual ~SetLst() = default;

    /* ************************************************************************ */

    // Copy assignment
    SetLst & operator=(const SetLst&);

    // Move assignment
    SetLst & operator=(SetLst&&) noexcept;

    /* ************************************************************************ */

    // Comparison operators
    bool operator == (const SetLst&) const noexcept;
    bool operator != (const SetLst&) const noexcept;
    /* ************************************************************************ */

    // Specific member functions (inherited from OrderedDictionaryContainer)

    const Data & Min() const override; 
    Data MinNRemove() override; 
    void RemoveMin() override; 

    const Data & Max()  const override; 
    Data MaxNRemove() override; 
    void RemoveMax() override; 

    const Data & Predecessor(const Data &) const override; 
    Data PredecessorNRemove(const Data &) override; 
    void  RemovePredecessor(const Data &) override; 

    const Data & Successor(const Data &) const override; 
    Data SuccessorNRemove(const Data &) override; 
    void  RemoveSuccessor(const Data &) override; 

    /* ************************************************************************ */

    // Specific member functions (inherited from DictionaryContainer)

    bool Insert(const Data &) override; 
    bool Insert(Data &&) override;  
    bool Remove(const Data&) override; 

    /* ************************************************************************ */

    // Specific member functions (inherited from LinearContainer)

    inline const Data& operator[](ulong) const override; 

    /* ************************************************************************** */

    // Specific member function (inherited from TestableContainer)

    bool Exists(const Data&) const noexcept override;

    /* ************************************************************************ */

    // Specific member function (inherited from ClearableContainer)

    void Clear() override;

  protected:
    using Node = typename List<Data>::Node;
    Data RemoveNode(Node *prev, Node *node);

};

/* ************************************************************************** */

}

#include "setlst.cpp"

#endif
