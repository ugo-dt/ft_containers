/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:23:36 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/04/29 22:02:05 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include "algorithm.hpp"
# include "iterator/iterator.hpp"
# include <stdexcept>

/*
	vector synopsis

namespace ft
{

template <class Tp, class Allocator = std::allocator<Tp> >
class vector
{
public:
	typedef Tp                                           value_type;
	typedef Allocator                                    allocator_type;	
	typedef typename allocator_type::reference           reference;
	typedef typename allocator_type::const_reference     const_reference;
	typedef typename allocator_type::pointer             pointer;
	typedef typename allocator_type::const_pointer       const_pointer;
	typedef typename allocator_type::difference_type     difference_type;
	typedef typename allocator_type::size_type           size_type;
	typedef ft::random_access_iterator<value_type>       iterator;
	typedef ft::random_access_iterator<const value_type> const_iterator;
	typedef ft::reverse_iterator<iterator>               reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>         const_reverse_iterator;

	vector(const vector& x);
	explicit vector(const allocator_type&);
	explicit vector(size_type n, const value_type& value, const allocator_type& = allocator_type());
	template <class InputIterator>
		vector(InputIterator first, InputIterator last, const allocator_type& = allocator_type());
	vector&	operator=(const vector& x);
	~vector();

	allocator_type			get_allocator() const;

	iterator				begin();
	const_iterator			begin() const;
	iterator				end();
	const_iterator			end() const;

	reverse_iterator		rbegin();
	const_reverse_iterator	rbegin() const;
	reverse_iterator		rend();
	const_reverse_iterator	rend() const;

	size_type size() const;
	size_type max_size() const;
	void resize(size_type n, value_type val = value_type());
	size_type capacity() const;
	bool empty() const;
	void reserve(size_type n);

	reference		operator[] (size_type n);
	const_reference	operator[] (size_type n) const;
	reference		at(size_type n);
	const_reference	at(size_type n) const;

	reference		front();
	const_reference	front() const;
	reference		back();
	const_reference	back() const;

	template <class InputIterator>
		void assign(InputIterator first, InputIterator last);
	void assign(size_type n, const value_type& val);
	void push_back(const value_type& val);
	void pop_back();
// TODO		iterator insert(iterator position, const value_type& val);
// TODO    		void insert(iterator position, size_type n, const value_type& val);
// TODO		template <class InputIterator>
// TODO			void insert(iterator position, InputIterator first, InputIterator last);
// TODO		iterator erase(iterator position);
// TODO		iterator erase(iterator first, iterator last);
	void swap(vector& v);
	void clear();
};

}  // ft

*/

namespace ft
{

template <class Tp, class Allocator>
class _vector_base
{
protected:
	typedef Tp                                       value_type;
	typedef Allocator                                allocator_type;
	typedef value_type&                              reference;
	typedef const value_type&                        const_reference;
	typedef typename allocator_type::pointer         pointer;
	typedef typename allocator_type::const_pointer   const_pointer;
	typedef typename allocator_type::difference_type difference_type;
	typedef typename allocator_type::size_type       size_type;

protected:
	pointer        _begin_;	  // Pointer to the first element of the array
	pointer        _end_;	  // Pointer past the last element of the array
	pointer        _end_cap_; // Pointer to the end of the currently allocated storage
	allocator_type _alloc_;	  // Object used to allocate storage

	allocator_type& _alloc()
		{return _alloc_;}
	const allocator_type& _alloc() const
		{return _alloc_;}
	pointer& _end_cap()
		{return _end_cap_;}
	const pointer& _end_cap() const
		{return _end_cap_;}
	
	_vector_base();
	_vector_base(const allocator_type& a);
	~_vector_base();

	void clear() {_destruct_at_end(_begin_);}
	size_type capacity() const {return static_cast<size_type>(_end_cap() - _begin_);}

	void _destruct_at_end(pointer new_last);

protected:
	void _throw_length_error() const {std::__throw_length_error("vector");}
	void _throw_out_of_range() const {std::__throw_out_of_range("vector");}

private:
	void _copy_assign_alloc(const _vector_base& c)
	{
		if (_alloc() != c._alloc())
		{
			clear();
			this->_alloc_.deallocate(_begin_, capacity());
			_begin_ = _end_ = _end_cap() = nullptr;
		}
		_alloc() = c._alloc();
	}
};

template <class Tp, class Allocator>
inline
void
_vector_base<Tp, Allocator>::_destruct_at_end(pointer new_last)
{
	pointer soon_to_be_end = _end_;
	while (new_last != soon_to_be_end)
		_alloc_.destroy(--soon_to_be_end);
	_end_ = new_last;
}

template <class Tp, class Allocator>
inline
_vector_base<Tp, Allocator>::_vector_base()
	:  _begin_(nullptr),
	  _end_(nullptr),
	  _end_cap_(nullptr),
	  _alloc_(allocator_type())
{
}

template <class Tp, class Allocator>
inline
_vector_base<Tp, Allocator>::_vector_base(const allocator_type& a)
	: _begin_(nullptr),
	  _end_(nullptr),
	  _end_cap_(nullptr),
	  _alloc_(a)
{
}

template <class Tp, class Allocator>
_vector_base<Tp, Allocator>::~_vector_base()
{
	if (_begin_ != nullptr)
	{
		clear();
		_alloc_.deallocate(_begin_, capacity());
	}
}

template <class Tp, class Allocator = std::allocator<Tp> >
class vector
	: private _vector_base<Tp, Allocator>
{
private:
	typedef _vector_base<Tp, Allocator>                  _base;
public:
	typedef Tp                                           value_type;
	typedef Allocator                                    allocator_type;	
	typedef typename _base::reference                    reference;
	typedef typename _base::const_reference              const_reference;
	typedef typename _base::pointer                      pointer;
	typedef typename _base::const_pointer                const_pointer;
	typedef typename _base::difference_type              difference_type;
	typedef typename _base::size_type                    size_type;
	typedef ft::random_access_iterator<value_type>       iterator;
	typedef ft::random_access_iterator<const value_type> const_iterator;
	typedef ft::reverse_iterator<iterator>               reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>         const_reverse_iterator;

public:
	explicit vector(const allocator_type& a = allocator_type())
		: _base(a)
	{
	}

	~vector()
	{
	}

	vector(const vector& x);
	explicit vector(size_type n, const value_type& val = value_type(),
					const allocator_type& alloc = allocator_type());
	template <class InputIterator>
		vector(InputIterator first, InputIterator last,
				const allocator_type& alloc = allocator_type());
	vector&	operator=(const vector& x);

	allocator_type get_allocator() const
		{return this->_alloc;}

	template <class InputIterator>
		void assign(InputIterator first, InputIterator last);
	void assign(size_type n, const value_type& val);
	void push_back(const value_type& val);
	void pop_back();
	void reserve(size_type n);
	void resize(size_type n, value_type val = value_type());

	iterator               begin();
	const_iterator         begin() const;
	iterator               end();
	const_iterator         end()const;

	reverse_iterator       rbegin()
		{return       reverse_iterator(end());}
	const_reverse_iterator rbegin() const
		{return       const_reverse_iterator(end());}

	reverse_iterator       rend()
		{return       reverse_iterator(begin());}
	const_reverse_iterator rend() const
		{return       const_reverse_iterator(begin());}

	size_type max_size() const
		{return this->_alloc_.max_size();}
	size_type size() const
		{return static_cast<size_type>(this->_end_ - this->_begin_);}
	size_type capacity() const
		{return _base::capacity();}
	bool empty() const
		{return this->_begin_ == this->_end_;}
	void clear()
		{_base::clear();}

	reference       operator[] (size_type n);
	const_reference operator[] (size_type n) const;

	reference       at(size_type n);
	const_reference at(size_type n) const;

	reference       front()
		{return *this->_begin_;}
	const_reference front() const
		{return *this->_begin_;}
	reference       back()
		{return *this->_end_ - 1;}
	const_reference back() const
		{return *this->_end_ - 1;}

	iterator insert(iterator position, const value_type& val);
	void insert(iterator position, size_type n, const value_type& val);
	template <class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last);
	iterator erase(iterator position);
	iterator erase(iterator first, iterator last);
	void swap(vector& v);

private:
	void _vallocate(size_type n);
	void _vdeallocate();

	void _construct_at_end(size_type n);
    void _construct_at_end(size_type n, const_reference x);
    template <class ForwardIterator>
		void _construct_at_end(ForwardIterator first, ForwardIterator last, size_type n);

	      iterator _make_iter(pointer pos);
	const_iterator _make_iter(pointer pos) const;
};	// vector

template <class Tp, class _Allocator>
void
vector<Tp, _Allocator>::_vallocate(size_type n)
{
    if (n > max_size())
        this->_throw_length_error();
    this->_begin_ = this->_end_ = this->_alloc_.allocate(n);
    this->_end_cap() = this->_begin_ + n;
}

template <class Tp, class Allocator>
inline
void
vector<Tp, Allocator>::_vdeallocate()
{
	if (this->_begin_ != nullptr)
	{
		clear();
		this->_alloc_.deallocate(this->_begin_, this->capacity());
		this->_begin_ = this->_end_ = this->_end_cap() = nullptr;
	}
}

//  Default constructs n objects starting at _end_
//  throws if construction throws
//  Precondition:  n > 0
//  Precondition:  size() + n <= capacity()
//  Postcondition:  size() == size() + n
template <class Tp, class _Allocator>
void
vector<Tp, _Allocator>::_construct_at_end(size_type n)
{
	_construct_at_end(n, value_type());
}

//  Copy constructs n objects starting at _end_ from x
//  throws if construction throws
//  Precondition:  n > 0
//  Precondition:  size() + n <= capacity()
//  Postcondition:  size() == old size() + n
//  Postcondition:  [i] == x for all i in [size() - n, n)
template <class Tp, class _Allocator>
inline
void
vector<Tp, _Allocator>::_construct_at_end(size_type n, const_reference x)
{
	if (size() + n > capacity())
		return ;
	while (n-- > 0)
		this->_alloc_.construct(this->_end_++, x);
}

template <class Tp, class _Allocator>
template <class ForwardIterator>
void
vector<Tp, _Allocator>::_construct_at_end(ForwardIterator first, ForwardIterator last, size_type n)
{
	if (size() + n > capacity() || n == 0)
		return ;
	for (; first != last; first++)
		this->_alloc_.construct(this->_end_++, *first);
}

/** @returns An iterator to the element p */
template <class Tp, class Allocator>
inline
typename ft::vector<Tp, Allocator>::iterator
vector<Tp, Allocator>::_make_iter(pointer p)
{
	return iterator(p);
}

/** @returns A constant iterator to the element p */
template <class Tp, class Allocator>
inline
typename ft::vector<Tp, Allocator>::const_iterator
vector<Tp, Allocator>::_make_iter(pointer p) const
{
	return const_iterator(p);
}

template <class Tp, class Allocator>
inline
vector<Tp, Allocator>::vector(const vector& x)
	: _base(x._alloc())
{
	size_type n = x.size();
    if (n > 0)
    {
        _vallocate(n);
        _construct_at_end(x._begin_, x._end_, n);
    }
}

template <class Tp, class Allocator>
inline
vector<Tp, Allocator>::vector(size_type n, const value_type& x, const allocator_type& a)
	: _base(a)
{
	if (n > 0)
    {
        _vallocate(n);
        _construct_at_end(n, x);
    }
}
	
template <class Tp, class Allocator>
template <class InputIterator>
inline
vector<Tp, Allocator>::vector(InputIterator first, InputIterator last, const allocator_type& a)
	: _base(a)
{
	for (; first != last; ++first)
        push_back(*first);
}

template <class Tp, class Allocator>
inline
vector<Tp, Allocator>&
vector<Tp, Allocator>::operator=(const vector& x)
{
	if (this != &x)
    {
        _base::_copy_assign_alloc(x);
        assign(x._begin_, x._end_);
    }
    return *this;
}

/* Returns an iterator pointing to the first element in the vector. */
template <class Tp, class Allocator>
typename ft::vector<Tp, Allocator>::iterator
vector<Tp, Allocator>::begin()
{
	return _make_iter(this->_begin_);
}

/* Returns a constant iterator pointing to the first element in the vector. */
template <class Tp, class Allocator>
typename ft::vector<Tp, Allocator>::const_iterator
vector<Tp, Allocator>::begin() const
{
	return _make_iter(this->_begin_);
}

/**
 * @brief Returns an iterator referring to the past-the-end element in the vector container.
 * The past-the-end element is the theoretical element that would follow the last element in
 * the vector. It does not point to any element, and thus shall not be dereferenced.
 * If the container is empty, this function returns the same as vector::begin.
 */
template <class Tp, class Allocator>
typename ft::vector<Tp, Allocator>::iterator
vector<Tp, Allocator>::end()
{
	return _make_iter(this->_end_);
}

template <class Tp, class Allocator>
typename ft::vector<Tp, Allocator>::const_iterator
vector<Tp, Allocator>::end() const
{
	return _make_iter(this->_end_);
}

template <class Tp, class Allocator>
void
vector<Tp, Allocator>::assign(size_type n, const value_type& x)
{
	if (n <= capacity())
    {
        size_type sz = size();
		for (size_type i = 0; i < n; i++)
			this->_alloc_.construct(this->_begin_ + i, x);
        if (n > sz)
            _construct_at_end(n - sz, x);
        else
            this->_destruct_at_end(this->_begin_ + n);
    }
    else
    {
        _vdeallocate();
        _vallocate(n);
        _construct_at_end(n, x);
    }
}

template <class Tp, class Allocator>
template <class InputIterator>
void
vector<Tp, Allocator>::assign(InputIterator first, InputIterator last)
{
	clear();
	for (; first != last; first++)
		push_back(*first);
}

template <class Tp, class Allocator>
void
vector<Tp, Allocator>::push_back(const value_type& x)
{
    if (this->_end_ != this->_end_cap())
		this->_alloc_.construct(this->_end_++, x);
    else
	{
		vector	v(size() + 1);
		v.assign(this->_begin_, this->_end_);
		v._alloc_.construct(v._end_++, x);
		swap(v);
	}
}

template <class Tp, class Allocator>
void
vector<Tp, Allocator>::pop_back()
{
	this->_destruct_at_end(this->_end_ - 1);
}

template <class Tp, class Allocator>
typename ft::vector<Tp, Allocator>::reference
vector<Tp, Allocator>::operator[](size_type n)
{
	return this->_begin_[n];
}

template <class Tp, class Allocator>
typename ft::vector<Tp, Allocator>::const_reference
vector<Tp, Allocator>::operator[](size_type n) const
{
	return this->_begin_[n];
}

template <class Tp, class Allocator>
typename ft::vector<Tp, Allocator>::reference
vector<Tp, Allocator>::at(size_type n)
{
	if (n >= this->size())
		this->_throw_out_of_range();
	return (this->_begin_[n]);
}

template <class Tp, class Allocator>
typename ft::vector<Tp, Allocator>::const_reference
vector<Tp, Allocator>::at(size_type n) const
{
	if (n >= this->_size)
		this->_throw_out_of_range();
	return (this->_begin_[n]);
}

template <class Tp, class Allocator>
void
vector<Tp, Allocator>::reserve(size_type n)
{
	if (n > capacity())
    {
		vector	v(n);

		v.assign(this->_begin_, this->_end_);
        swap(v);
    }
}

/**
 * @brief Exchanges the content of the container by the content of x,
 * which is another vector object of the same type. Sizes may differ.
 * 
 * @param v Another vector container of the same type (i.e., instantiated
 * with the same template parameters, T and Alloc) whose content is
 * swapped with that of this container.
 */
template <class Tp, class Allocator>
void
vector<Tp, Allocator>::swap(vector& v)
{
	ft::swap(this->_begin_, v._begin_);
	ft::swap(this->_end_, v._end_);
	ft::swap(this->_end_cap_, v._end_cap_);
	ft::swap(this->_alloc_, v._alloc_);
}

// vector non member functions
template <class Tp, class Allocator>
inline
bool
operator==(const vector<Tp, Allocator>& x, const vector<Tp, Allocator>& y)
{
	const typename vector<Tp, Allocator>::size_type	sz = x.size();
	return sz == y.size() && ft::equal(x.begin(), x.end(), y.begin());
}

template <class Tp, class Allocator>
inline
bool
operator!=(const vector<Tp, Allocator>& x, const vector<Tp, Allocator>& y)
{
	return !(x == y);
}

template <class Tp, class Allocator>
inline
bool
operator<(const vector<Tp, Allocator>& x, const vector<Tp, Allocator>& y)
{
	return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
}

template <class Tp, class Allocator>
inline
bool
operator>(const vector<Tp, Allocator>& x, const vector<Tp, Allocator>& y)
{
	return y < x;
}

template <class Tp, class Allocator>
inline
bool
operator<=(const vector<Tp, Allocator>& x, const vector<Tp, Allocator>& y)
{
	return !(y < x);
}

template <class Tp, class Allocator>
inline
bool
operator>=(const vector<Tp, Allocator>& x, const vector<Tp, Allocator>& y)
{
	return !(x < y);
}

/**
 * @brief The contents of container x are exchanged with those of y.
 * Both container objects must be of the same type (same template parameters),
 * although sizes may differ.
 * 
 * @param x,y vector containers of the same type (i.e.,
 * having both the same template parameters, T and Alloc).
 */
template <class Tp, class Allocator>
inline
void
swap(vector<Tp, Allocator>& x, vector<Tp, Allocator>& y)
{
	x.swap(y);
}

} // ft

#endif // VECTOR_HPP