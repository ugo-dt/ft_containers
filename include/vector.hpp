/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:23:36 by ugdaniel          #+#    #+#             */
/*   Updated: 2022/05/29 20:39:09 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

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

	allocator_type         getAllocator() const;

	iterator               begin();
	const_iterator         begin() const;
	iterator               end();
	const_iterator         end() const;

	reverse_iterator       rbegin();
	const_reverse_iterator rbegin() const;
	reverse_iterator       rend();
	const_reverse_iterator rend() const;

	size_type size() const;
	size_type max_size() const;
	void resize(size_type n, value_type val = value_type());
	size_type capacity() const;
	bool empty() const;
	void reserve(size_type n);

	reference       operator[] (size_type n);
	const_reference operator[] (size_type n) const;
	reference       at(size_type n);
	const_reference at(size_type n) const;

	reference       front();
	const_reference front() const;
	reference       back();
	const_reference back() const;

	template <class InputIterator>
		void assign(InputIterator first, InputIterator last);
	void assign(size_type n, const value_type& val);
	void push_back(const value_type& val);
	void pop_back();
	iterator insert(iterator position, const value_type& val);
  		void insert(iterator position, size_type n, const value_type& val);
	template <class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last);
	iterator erase(iterator position);
	iterator erase(iterator first, iterator last);
	void swap(vector& v);
	void clear();
};

}  // ft

*/

# include "algorithm.hpp"
# include "iterator.hpp"
# include "type_traits.hpp"
# include <stdexcept>

namespace ft
{

template <class Tp, class Allocator>
class _vector_base
{
public:
	typedef Allocator                                allocator_type;
	typedef typename allocator_type::size_type       size_type;

protected:
	typedef Tp                                       value_type;
	typedef	value_type&                              reference;
	typedef const value_type&                        const_reference;
	typedef typename allocator_type::pointer         pointer;
	typedef typename allocator_type::const_pointer   const_pointer;
	typedef typename allocator_type::difference_type difference_type;

protected:
	pointer        _begin;   // Pointer to the first element of the array
	pointer        _end;     // Pointer past the last element of the array
	pointer        _end_cap; // Pointer to the end of the currently allocated storage
	allocator_type _alloc;   // Object used to allocate storage

	allocator_type& _allocator()
		{return _alloc;}
	const allocator_type& _allocator() const
		{return _alloc;}
	pointer& _end_capacity()
		{return _end_cap;}
	const pointer& _end_capacity() const
		{return _end_cap;}
	
	_vector_base();
	_vector_base(const allocator_type& a);
	~_vector_base();

	void _destruct_at_end(pointer new_last);

	void clear() {_destruct_at_end(_begin);}
	size_type capacity() const {return static_cast<size_type>(_end_capacity() - _begin);}

	void _throw_length_error() const {throw std::length_error("vector");}
	void _throw_out_of_range() const {throw std::out_of_range("vector");}

	void _copy_assign_alloc(const _vector_base& c)
	{
		if (_allocator() != c._allocator())
		{
			clear();
			this->_alloc.deallocate(_begin, capacity());
			_begin = _end = _end_capacity() = 0;
		}
		_allocator() = c._allocator();
	}
};

template <class Tp, class Allocator>
inline void
_vector_base<Tp, Allocator>::_destruct_at_end(pointer new_last)
{
	pointer soon_to_be_end = _end;
	while (new_last != soon_to_be_end)
		_alloc.destroy(--soon_to_be_end);
	_end = new_last;
}

template <class Tp, class Allocator>
inline
_vector_base<Tp, Allocator>::_vector_base()
	: _begin(0),
	  _end(0),
	  _end_cap(0),
	  _alloc(allocator_type())
{
}

template <class Tp, class Allocator>
inline
_vector_base<Tp, Allocator>::_vector_base(const allocator_type& a)
	: _begin(0),
	  _end(0),
	  _end_cap(0),
	  _alloc(a)
{
}

template <class Tp, class Allocator>
_vector_base<Tp, Allocator>::~_vector_base()
{
	if (_begin != 0)
	{
		clear();
		_alloc.deallocate(_begin, capacity());
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
	typedef typename _base::pointer                      pointer;
	typedef typename _base::const_pointer                const_pointer;
	typedef typename _base::size_type                    size_type;
	typedef typename _base::difference_type              difference_type;
	typedef typename _base::reference                    reference;
	typedef typename _base::const_reference              const_reference;
	typedef ft::random_access_iterator<value_type>       iterator;
	typedef ft::random_access_iterator<const value_type> const_iterator;
	typedef ft::reverse_iterator<iterator>               reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>         const_reverse_iterator;

public:
	explicit vector(const allocator_type& a = allocator_type()) : _base(a) {}
	explicit vector(size_type n, const value_type& val = value_type(),
					const allocator_type& alloc = allocator_type());
	template <class InputIterator>
		vector(InputIterator first, InputIterator last,
				const allocator_type& alloc = allocator_type(),
				typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type* = 0);
	vector(const vector& x);
	vector&	operator=(const vector& x);

	template <class InputIterator>
		void assign(InputIterator first, InputIterator last,
					typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type* = 0);
	void assign(size_type n, const value_type& val);
	void push_back(const value_type& val);
	void pop_back();
	void reserve(size_type n);
	void resize(size_type n, value_type val = value_type());

	inline iterator        begin()
		{return _make_iter(this->_begin);}
	inline const_iterator  begin() const
		{return _make_iter(this->_begin);}
	inline iterator        end()
		{return _make_iter(this->_end);}
	inline const_iterator  end() const
		{return _make_iter(this->_end);}

	reverse_iterator       rbegin()
		{return reverse_iterator(end());}
	const_reverse_iterator rbegin() const
		{return const_reverse_iterator(end());}

	reverse_iterator       rend()
		{return reverse_iterator(begin());}
	const_reverse_iterator rend() const
		{return const_reverse_iterator(begin());}

	allocator_type get_allocator() const
		{return this->_alloc;}
	size_type max_size() const
		{return this->_alloc.max_size();}
	size_type size() const
		{return static_cast<size_type>(this->_end - this->_begin);}
	size_type capacity() const
		{return _base::capacity();}
	bool empty() const
		{return this->_begin == this->_end;}
	void clear()
		{_base::clear();}

	reference       operator[] (size_type n);
	const_reference operator[] (size_type n) const;

	reference       at(size_type n);
	const_reference at(size_type n) const;

	reference       front()
		{return *this->_begin;}
	const_reference front() const
		{return *this->_begin;}
	reference       back()
		{return *(this->_end - 1);}
	const_reference back() const
		{return *(this->_end - 1);}

	iterator insert(iterator position, const value_type& val);
	void insert(iterator position, size_type n, const value_type& val);
	template <class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last,
					typename enable_if<!is_integral<
						InputIterator>::value, InputIterator>::type* = 0);
	iterator erase(iterator position);
	iterator erase(iterator first, iterator last);
	void swap(vector& v);

private:
	void _vallocate(size_type n);
	void _vdeallocate();
	size_type _recommend(size_type new_size) const;
	void _construct_at_end(size_type n);
	void _construct_at_end(size_type n, const_reference x);
	template <class ForwardIterator>
		void _construct_at_end(ForwardIterator first, ForwardIterator last, size_type n,
                               typename enable_if<!is_integral<
                                   ForwardIterator>::value, ForwardIterator>::type* = 0);
	void _destruct_at_end(pointer new_last) {_base::_destruct_at_end(new_last);}
	void _insert_in_array(pointer p, size_type n, iterator position, const value_type& x);
	template <class InputIterator>
		void _insert_in_array(pointer p, iterator position, InputIterator first, InputIterator last,
                              typename enable_if<!is_integral<
                                  InputIterator>::value, InputIterator>::type* = 0);
	void _append(size_type n, const_reference x);
	iterator _make_iter(pointer pos);
	const_iterator _make_iter(pointer pos) const;
};

template <class Tp, class Allocator>
void
vector<Tp, Allocator>::_vallocate(size_type n)
{
	if (n > max_size())
		this->_throw_length_error();
	this->_begin = this->_end = this->_alloc.allocate(n);
	this->_end_capacity() = this->_begin + n;
}

template <class Tp, class Allocator>
inline void
vector<Tp, Allocator>::_vdeallocate()
{
	if (this->_begin != 0)
	{
		clear();
		this->_alloc.deallocate(this->_begin, this->capacity());
		this->_begin = this->_end = this->_end_capacity() = 0;
	}
}

//  Precondition:  new_size > capacity()
template <class Tp, class Allocator>
inline
typename vector<Tp, Allocator>::size_type
vector<Tp, Allocator>::_recommend(size_type new_size) const
{
    const size_type ms = max_size();
    if (new_size > ms)
        this->_throw_length_error();
    const size_type cap = capacity();
    if (cap >= ms / 2)
        return ms;
    return ft::max<size_type>(2 * cap, new_size);
}

//  Default constructs n objects starting at _end
//  throws if construction throws
//  Precondition:  n > 0
//  Precondition:  size() + n <= capacity()
//  Postcondition:  size() == size() + n
template <class Tp, class Allocator>
void
vector<Tp, Allocator>::_construct_at_end(size_type n)
{
	_construct_at_end(n, value_type());
}

//  Copy constructs n objects starting at _end from x
//  throws if construction throws
//  Precondition:  n > 0
//  Precondition:  size() + n <= capacity()
//  Postcondition:  size() == old size() + n
//  Postcondition:  [i] == x for all i in [size() - n, n)
template <class Tp, class Allocator>
inline void
vector<Tp, Allocator>::_construct_at_end(size_type n, const_reference x)
{
	if (size() + n > capacity())
		return ;
	while (n-- > 0)
		this->_alloc.construct(this->_end++, x);
}

template <class Tp, class Allocator>
template <class ForwardIterator>
void
vector<Tp, Allocator>::_construct_at_end(ForwardIterator first, ForwardIterator last, size_type n,
                                         typename enable_if<!is_integral<
                                             ForwardIterator>::value, ForwardIterator>::type*)
{
	if (size() + n > capacity() || n == 0)
		return ;
	for (; first != last; first++)
		this->_alloc.construct(this->_end++, *first);
}

/** @returns An iterator to the element p */
template <class Tp, class Allocator>
inline typename ft::vector<Tp, Allocator>::iterator
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
	: _base(x._allocator())
{
	size_type n = x.size();
	if (n < 0)
		return ;
	_vallocate(n);
	_construct_at_end(x._begin, x._end, n);
}

template <class Tp, class Allocator>
inline
vector<Tp, Allocator>::vector(size_type n, const value_type& x, const allocator_type& a)
	: _base(a)
{
	if (n < 0)
		return ;
	_vallocate(n);
	_construct_at_end(n, x);
}

/* The function template argument InputIterator shall be an input iterator type that
 * points to elements of a type from which value_type objects can be constructed. */
template <class Tp, class Allocator>
template <class InputIterator>
inline
vector<Tp, Allocator>::vector(InputIterator first, InputIterator last, const allocator_type& a,
                              typename enable_if<!is_integral<
                                  InputIterator>::value, InputIterator>::type*)
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
		// make sure capacity is the same
		this->reserve(x.capacity());
		assign(x._begin, x._end);
	}
	return *this;
}

template <class Tp, class Allocator>
void
vector<Tp, Allocator>::assign(size_type n, const value_type& x)
{
	if (n <= capacity())
	{
		size_type s = size();
		ft::fill_n(this->_begin, ft::min(n, s), x);
		if (n > s)
			_construct_at_end(n - s, x);
		else
			this->_destruct_at_end(this->_begin + n);
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
vector<Tp, Allocator>::assign(InputIterator first, InputIterator last,
                              typename enable_if<!is_integral<
                                  InputIterator>::value, InputIterator>::type*)
{
	clear();
	for (; first != last; first++)
		push_back(*first);
}

template <class Tp, class Allocator>
inline void
vector<Tp, Allocator>::push_back(const value_type& x)
{
	if (this->_end != this->_end_capacity())
		this->_construct_at_end(1, x);
	else
	{
		vector	v(_recommend(size() + 1), value_type(), this->_allocator());
		v.assign(this->_begin, this->_end);
		v._alloc.construct(v._end++, x);
		swap(v);
	}
}

template <class Tp, class Allocator>
inline void
vector<Tp, Allocator>::pop_back()
{
	this->_destruct_at_end(this->_end - 1);
}

template <class Tp, class Allocator>
inline void
vector<Tp, Allocator>::_insert_in_array(pointer p, size_type n, iterator position, const value_type& x)
{
	int i = 0;
	iterator it;

	for (it = this->begin(); it != position; it++)
		p[i++] = *it;
	while (n--)
		p[i++] = x;
	for (; it != this->end(); it++)
		p[i++] = *it;
}

template <class Tp, class Allocator>
template <class InputIterator>
inline void
vector<Tp, Allocator>::_insert_in_array(pointer p, iterator position, InputIterator first, InputIterator last,
                                        typename enable_if<!is_integral<
                                            InputIterator>::value, InputIterator>::type*)
{
	int i = 0;
	iterator it;

	for (it = this->begin(); it != position; it++)
		p[i++] = *it;
	for (; first != last; first++)
		p[i++] = *first;
	for (; it != this->end(); it++)
		p[i++] = *it;
}

template <class Tp, class Allocator>
typename vector<Tp, Allocator>::iterator
vector<Tp, Allocator>::insert(iterator position, const value_type& x)
{
	difference_type d = position - this->begin();
	pointer p = this->_begin + d;
	if (this->_end < this->_end_capacity())
	{
		if (p == this->_end)
		{
			push_back(x);
		}
		else
		{
			_insert_in_array(this->_begin, 1, position, x);
			this->_end++;
		}
	}
	else
	{
		vector   v(size() + 1, value_type(), this->_allocator());
		_insert_in_array(v._begin, 1, position, x);
		swap(v);
	}
	return (_make_iter(this->_begin + d));
}

template <class Tp, class Allocator>
void
vector<Tp, Allocator>::insert(iterator position, size_type n, const value_type& x)
{
	if (n < 0)
		return ;
	if (n <= static_cast<size_type>(this->_end_capacity() - this->_end))
	{
		_insert_in_array(this->_begin, n, position, x);
		this->_end += n;
	}
	else
	{
		vector   v(size() + n, value_type(), this->_allocator());
		_insert_in_array(v._begin, n, position, x);
		swap(v);
	}
}

template <class Tp, class Allocator>
template <class InputIterator>
void
vector<Tp, Allocator>::insert(iterator position, InputIterator first, InputIterator last,
                              typename enable_if<!is_integral<
                                  InputIterator>::value, InputIterator>::type*)
{
	size_type n = 0;
	for (InputIterator tmp = first; tmp != last; tmp++)
		n++;
	if (n < 0)
		return ;
	if (n <= static_cast<size_type>(this->_end_capacity() - this->_end))
	{
		_insert_in_array(this->_begin, position, first, last);
		this->_end += n;
	}
	else
	{
		vector	v(size() + n, value_type(), this->_allocator());
		_insert_in_array(v._begin, position, first, last);
		swap(v);
	}
}

template <class Tp, class Allocator>
inline
typename ft::vector<Tp, Allocator>::iterator
vector<Tp, Allocator>::erase(iterator position)
{
	return (erase(position, position + 1));
}

template <class Tp, class Allocator>
typename ft::vector<Tp, Allocator>::iterator
vector<Tp, Allocator>::erase(iterator first, iterator last)
{
	iterator r = first;
	size_type n = 0;
	for (iterator tmp = first; tmp != last; tmp++)
		n++;
	for (; last != this->end(); ++first, ++last)
		*first = *last;
	while (n--)
		this->_destruct_at_end(this->_end - 1);
	return (r);
}

template <class Tp, class Allocator>
inline
typename ft::vector<Tp, Allocator>::reference
vector<Tp, Allocator>::operator[](size_type n)
{
	return this->_begin[n];
}

template <class Tp, class Allocator>
inline
typename ft::vector<Tp, Allocator>::const_reference
vector<Tp, Allocator>::operator[](size_type n) const
{
	return this->_begin[n];
}

template <class Tp, class Allocator>
typename ft::vector<Tp, Allocator>::reference
vector<Tp, Allocator>::at(size_type n)
{
	if (n >= this->size())
		this->_throw_out_of_range();
	return (this->_begin[n]);
}

template <class Tp, class Allocator>
typename ft::vector<Tp, Allocator>::const_reference
vector<Tp, Allocator>::at(size_type n) const
{
	if (n >= this->size())
		this->_throw_out_of_range();
	return (this->_begin[n]);
}

template <class Tp, class Allocator>
void
vector<Tp, Allocator>::reserve(size_type n)
{
	if (n >= max_size())
		this->_throw_length_error();
	if (n > capacity())
	{
		size_type cs = size();
		vector	v(this->_allocator());
		v._vallocate(n);
		v._construct_at_end(begin(), begin() + cs, cs);
		swap(v);
	}
}

template <class Tp, class Allocator>
void
vector<Tp, Allocator>::_append(size_type n, const_reference x)
{
	if (static_cast<size_type>(this->_end_capacity() - this->_end) >= n)
		this->_construct_at_end(n, x);
	else
	{
		size_type cs = size();
		vector v(this->_allocator());
		v._vallocate(_recommend(cs + n));
		v._construct_at_end(begin(), begin() + cs, cs);
		v._construct_at_end(n, x);
		swap(v);
	}
}

template <class Tp, class Allocator>
void
vector<Tp, Allocator>::resize(size_type n, value_type val)
{
	size_type cs = size();
	if (cs < n)
		this->_append(n - cs, val);
	else if (cs > n)
		this->_destruct_at_end(this->_begin + n);
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
	ft::swap(this->_begin, v._begin);
	ft::swap(this->_end, v._end);
	ft::swap(this->_end_cap, v._end_cap);
	ft::swap(this->_alloc, v._alloc);
}

template <class Tp, class Allocator>
inline bool
operator==(const vector<Tp, Allocator>& x, const vector<Tp, Allocator>& y)
{
	const typename vector<Tp, Allocator>::size_type	sz = x.size();
	return sz == y.size() && ft::equal(x.begin(), x.end(), y.begin());
}

template <class Tp, class Allocator>
inline bool
operator!=(const vector<Tp, Allocator>& x, const vector<Tp, Allocator>& y)
{
	return !(x == y);
}

template <class Tp, class Allocator>
inline bool
operator<(const vector<Tp, Allocator>& x, const vector<Tp, Allocator>& y)
{
	return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
}

template <class Tp, class Allocator>
inline bool
operator>(const vector<Tp, Allocator>& x, const vector<Tp, Allocator>& y)
{
	return y < x;
}

template <class Tp, class Allocator>
inline bool
operator<=(const vector<Tp, Allocator>& x, const vector<Tp, Allocator>& y)
{
	return !(y < x);
}

template <class Tp, class Allocator>
inline bool
operator>=(const vector<Tp, Allocator>& x, const vector<Tp, Allocator>& y)
{
	return !(x < y);
}

/**
 * @brief The contents of container x are exchanged with those of y.
 * Both container objects must be of the same type (same template parameters),
 * although sizes may differ.
 * 
 * After the call to this member function, the elements in x are those which
 * were in y before the call, and the elements of y are those which were in x.
 * All iterators, references and pointers remain valid for the swapped objects.
 * 
 * This is an overload of the generic algorithm swap that improves its performance
 * by mutually transferring ownership over their assets to the other container
 * (i.e., the containers exchange references to their data, without actually
 * performing any element copy or movement): It behaves as if x.swap(y) was
 * called.
 * 
 * @param x,y vector containers of the same type (i.e.,
 * having both the same template parameters, T and Alloc).
 */
template <class Tp, class Allocator>
inline void
swap(vector<Tp, Allocator>& x, vector<Tp, Allocator>& y)
{
	x.swap(y);
}

}  // ft

#endif // VECTOR_HPP
