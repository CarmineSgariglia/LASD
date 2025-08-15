
#ifndef LIST_HPP
#define LIST_HPP

/* ************************************************************************** */

#include "../container/linear.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class List: virtual public ClearableContainer,  virtual public MutableLinearContainer<Data> {
  private:

  protected:
    using Container::size;


    struct Node {

        Data element;
        Node * next = nullptr;

        /* ********************************************************************** */

        // Specific constructors
        inline Node() = default;
        inline Node(const Data & dat) : element(dat) {};
        inline Node(Data &&) noexcept;

        /* ********************************************************************** */

        // Copy constructor
        inline Node(const Node & node) : element(node.element) {};


        // Move constructor
        inline Node(Node && node) noexcept;


        /* ********************************************************************** */

        // Destructor
        virtual ~Node();


        /* ********************************************************************** */

        // Comparison operators
        bool operator==(const Node &) const noexcept;
        bool operator!=(const Node &) const noexcept;

        /* ********************************************************************** */

        // Specific member functions

        virtual Node * Clone(Node *);


    };

    Node * head = nullptr;
    Node * tail = nullptr;


  public:

    // Default constructor
    List() = default;


    /* ************************************************************************ */

    // Specific constructor
    List(const TraversableContainer<Data> &); 
    List(MappableContainer<Data> &&);

    /* ************************************************************************ */

    // Copy constructor
    List(const List &);

    // Move constructor
    List(List &&) noexcept;


    /* ************************************************************************ */

    // Destructor
    virtual ~List();


    /* ************************************************************************ */

    // Copy assignment
    List & operator=(const List &);

    // Move assignment
    List & operator=(List &&) noexcept;

    /* ************************************************************************ */

    // Comparison operators
    inline bool operator==(const List &) const noexcept;
    inline bool operator!=(const List &) const noexcept;

    /* ************************************************************************ */

    // Specific member functions

    void InsertAtFront(const Data &);
    void InsertAtFront(Data &&); 
    void RemoveFromFront(); 
    Data FrontNRemove(); 

    void InsertAtBack(const Data &);
    void InsertAtBack(Data &&); 
    void RemoveFromBack() ; 
    Data BackNRemove() ; 

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

    // Specific member function (inherited from MappableContainer)

    using typename MappableContainer<Data>::MapFun;

    void Map(MapFun) override;


    /* ************************************************************************ */

    // Specific member function (inherited from PreOrderMappableContainer)

    void PreOrderMap(MapFun) override;

    /* ************************************************************************ */

    // Specific member function (inherited from PostOrderMappableContainer)

    void PostOrderMap(MapFun) override;

    /* ************************************************************************ */

    // Specific member function (inherited from TraversableContainer)

    using typename TraversableContainer<Data>::TraverseFun;

    void Traverse(TraverseFun) const override;

    /* ************************************************************************ */

    // Specific member function (inherited from PreOrderTraversableContainer)

    void PreOrderTraverse(TraverseFun) const override;

    /* ************************************************************************ */

    // Specific member function (inherited from PostOrderTraversableContainer)

    void PostOrderTraverse(TraverseFun) const override;

    /* ************************************************************************ */

    // Specific member function (inherited from ClearableContainer)

    void Clear() override;


  protected:

    // Auxiliary functions
    void PreOrderMap(MapFun, Node *);
    void PostOrderMap(MapFun, Node *);

    void PreOrderTraverse(TraverseFun, const Node *) const;
    void PostOrderTraverse(TraverseFun, const Node *) const;
};

/* ************************************************************************** */

}

#include "list.cpp"

#endif
