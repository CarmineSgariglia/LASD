

#ifndef LINEAR_HPP
#define LINEAR_HPP

/* ************************************************************************** */

#include "mappable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class LinearContainer: virtual public PreOrderTraversableContainer<Data>,  virtual public  PostOrderTraversableContainer<Data> {

  private:

  protected:

    using Container::size;

  public:

    // Destructor
    virtual ~LinearContainer() = default;

    /* ************************************************************************ */

    // Copy assignment
    LinearContainer & operator=(const LinearContainer &) = delete;

    // Move assignment
    LinearContainer & operator=(LinearContainer &&) noexcept = delete;


    /* ************************************************************************ */

    // Comparison operators
    inline bool operator==(const LinearContainer &) const noexcept;
    inline bool operator!=(const LinearContainer &) const noexcept;

    /* ************************************************************************ */

    // Specific member functions

    virtual const Data & operator[](ulong) const = 0;

    inline virtual const Data & Front() const; 

    inline virtual const Data & Back() const;

    /* ************************************************************************ */

    // Specific member function (inherited from TraversableContainer)

    using typename TraversableContainer<Data>::TraverseFun;

    inline void Traverse(TraverseFun) const override;

    /* ************************************************************************ */

    // Specific member function (inherited from PreOrderTraversableContainer)

    inline void PreOrderTraverse(TraverseFun) const override;

    /* ************************************************************************ */

    // Specific member function (inherited from PostOrderTraversableContainer)

    inline void PostOrderTraverse(TraverseFun) const override;

};

/* ************************************************************************** */

template <typename Data>
class MutableLinearContainer: virtual public LinearContainer<Data>, virtual public PreOrderMappableContainer<Data>, virtual public  PostOrderMappableContainer<Data> {

  private:

  protected:
    using Container::size;

  public:

    // Destructor
    virtual ~MutableLinearContainer() = default;

    /* ************************************************************************ */

    // Copy assignment
    MutableLinearContainer & operator=(const MutableLinearContainer &) = delete;
    // Move assignment
    MutableLinearContainer & operator=(MutableLinearContainer &&) noexcept = delete;

    /* ************************************************************************ */
    using LinearContainer<Data>::operator==;
    using LinearContainer<Data>::operator!=;
    // Specific member functions

    virtual Data & operator[](ulong) = 0; 

    inline virtual Data & Front(); 

    inline virtual Data & Back(); 
    /* ************************************************************************ */

    // Specific member functions (inherited from LinearContainer)
    using LinearContainer<Data>::operator[];
    using LinearContainer<Data>::Front;
    using LinearContainer<Data>::Back;

    /* ************************************************************************ */

    // Specific member function (inherited from MappableContainer)

    using typename MappableContainer<Data>::MapFun;

    inline void Map(MapFun) override;

    /* ************************************************************************ */

    // Specific member function (inherited from PreOrderMappableContainer)

    inline void PreOrderMap(MapFun) override;

    /* ************************************************************************ */

    // Specific member function (inherited from PostOrderMappableContainer)

    inline void PostOrderMap(MapFun) override;


};

template <typename Data>
class SortableLinearContainer: virtual public MutableLinearContainer<Data> {

  private:

  protected:
    using Container::size;

  public:

    // Destructor
    virtual ~SortableLinearContainer() = default;

    /* ************************************************************************ */

    // Copy assignment
    SortableLinearContainer & operator=(const SortableLinearContainer &) = delete;

    // Move assignment
    SortableLinearContainer & operator=(SortableLinearContainer &&) noexcept = delete;

    /* ************************************************************************ */
    using LinearContainer<Data>::operator==;
    using LinearContainer<Data>::operator!=;
    // Specific member function

    virtual void Sort() noexcept;

  protected:

    void QuickSort(ulong p, ulong r) noexcept;
    ulong Partition(ulong p, ulong r) noexcept;

};

/* ************************************************************************** */

}

#include "linear.cpp"

#endif
