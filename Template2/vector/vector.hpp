
#ifndef VECTOR_HPP
#define VECTOR_HPP

/* ************************************************************************** */

#include "../container/linear.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Vector: virtual public ResizableContainer, virtual public MutableLinearContainer<Data> {

  private:

  protected:

    using Container::size;
    Data * Elements = nullptr;

  public:

    // Default constructor
    Vector() = default;

    /* ************************************************************************ */

    // Specific constructors
    Vector(const ulong) ; 
    Vector(const TraversableContainer<Data> &);  
    Vector(MappableContainer<Data> &&); 

    /* ************************************************************************ */

    // Copy constructor
    Vector(const Vector &);

    // Move constructor
    Vector(Vector &&) noexcept;

    /* ************************************************************************ */

    // Destructor
    virtual ~Vector();

    /* ************************************************************************ */

    // Copy assignment
    Vector & operator=(const Vector &);

    // Move assignment
    Vector & operator=(Vector &&) noexcept;

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const Vector &) const noexcept;
    bool  operator!=(const Vector &) const noexcept;

    /* ************************************************************************ */

    // Specific member functions (inherited from MutableLinearContainer)

    Data &  operator[](ulong) override; 

    Data & Front() override; 

    Data & Back() override; 

    /* ************************************************************************ */

    // Specific member functions (inherited from LinearContainer)

    const Data & operator[](ulong) const override; 

    const Data & Front() const override; 

    const Data & Back() const override; 

    /* ************************************************************************ */

    // Specific member function (inherited from ResizableContainer)

    void Resize(ulong) override;

    /* ************************************************************************ */

    // Specific member function (inherited from ClearableContainer)


    void Clear() override; 
  
};

/* ************************************************************************** */

template <typename Data>
class SortableVector: public Vector<Data>, virtual public SortableLinearContainer<Data> {


  private:

  protected:

  public:

    // Default constructor
    SortableVector() = default;

    /* ************************************************************************ */

    // Specific constructors
    SortableVector(const ulong);
    SortableVector(const TraversableContainer<Data> &) ; 
    SortableVector(MappableContainer<Data> &&) ; 

    /* ************************************************************************ */

    // Copy constructor
    SortableVector(const SortableVector &);

    // Move constructor
    SortableVector(SortableVector &&) noexcept ;

    /* ************************************************************************ */

    // Destructor
    virtual ~SortableVector() = default;

    /* ************************************************************************ */

    // Copy assignment
    SortableVector & operator=(const SortableVector &);

    // Move assignment
    SortableVector & operator=(SortableVector &&) noexcept;

};

/* ************************************************************************** */

}

#include "vector.cpp"

#endif
