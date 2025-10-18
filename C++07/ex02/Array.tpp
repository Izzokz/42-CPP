/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@d42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:31:34 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/10/16 14:31:34 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <stdint.h>

template <typename T> const typename Array<T>::OutOfBoundsException		Array<T>::OOBE;
template <typename T> const typename Array<T>::EmptyArrayException		Array<T>::EAE;
template <typename T> const typename Array<T>::SizeMaxReachedException	Array<T>::SMRE;

template <typename T> Array<T>::Array(void)
{
	_arr = new T[0]();
	_size = 0;
}

template <typename T> Array<T>::Array(const std::size_t &n)
{
	_arr = new T[n]();
	_size = n;
}

template <typename T> Array<T>::Array(const Array &cpy)
{
	_arr = 0;
	*this = cpy;
}

template <typename T> Array<T>::~Array(void)
{
	delete [](_arr);
}

template <typename T> Array<T>	&Array<T>::operator=(const Array &cpy)
{
	if (_arr)
		delete [](_arr);
	_arr = new T[cpy._size]();
	for (std::size_t i = 0; i < cpy._size; ++i)
		*(_arr + i) = *(cpy._arr + i);
	_size = cpy._size;
	return (*this);
}

template <typename T> Array<T>	Array<T>::operator+(const Array &add) const
{
	if (_size == SIZE_MAX)
		return (*this);
	const std::size_t	N = SIZE_MAX - _size > add._size ? _size + add._size : SIZE_MAX;
	Array				newArr(N);

	for (std::size_t i = 0; i < N; ++i)
		*(newArr._arr + i) = i < _size ? *(_arr + i) : *(add._arr + i - _size);
	return (newArr);
}

template <typename T> Array<T>	&Array<T>::operator+=(const Array &add)
{
	return (*this = *this + add);
}

template <typename T> void	Array<T>::pushBack(const T &obj)
{
	if (_size == SIZE_MAX)
		throw (SMRE);
	T *const	oldArr = _arr;
	_arr = new T[_size + 1];
	for (std::size_t i = 0; i < _size; ++i)
		*(_arr + i) = *(oldArr + i);
	*(_arr + _size++) = obj;
	delete [](oldArr);
}

template <typename T> void	Array<T>::pushFront(const T &obj)
{
	if (_size == SIZE_MAX)
		throw (SMRE);
	T *const		oldArr = _arr;
	_arr = new T[_size + 1];
	{
		T *const	tmp = _arr + 1;
		for (std::size_t i = 0; i < _size; ++i)
			*(tmp + i) = *(oldArr + i);
	}
	*_arr = obj;
	++_size;
	delete [](oldArr);
}

template <typename T> void	Array<T>::remove(const std::size_t &idx)
{
	if (!_size)
		throw (EAE);
	if (idx >= _size)
		throw (OOBE);
	T *const		oldArr = _arr;
	_arr = new T[_size - 1];
	for (std::size_t i = 0, j = -1; i < _size; ++i)
	{
		if (i == idx)
			continue ;
		*(_arr + ++j) = *(oldArr + i);
	}
	--_size;
	delete [](oldArr);
}

template <typename T> void	Array<T>::print(void) const
{
	std::cout << *this;
}

template <typename T> T	&Array<T>::operator[](const std::size_t &idx)
{
	if (idx >= _size)
		throw (OOBE);
	return (*(_arr + idx));
}

template <typename T> const T	&Array<T>::operator[](const std::size_t &idx) const
{
	if (idx >= _size)
		throw (OOBE);
	return (*(_arr + idx));
}

template <typename T> std::ostream	&operator<<(std::ostream &lhs, const Array<T> &rhs)
{
	lhs << &rhs << '[';
	const std::size_t	&size = rhs.size();
	for (std::size_t i = 0; i < size; ++i)
		lhs << '\n' << rhs[i];
	lhs << "\n]" << std::endl;
	return (lhs);
}
