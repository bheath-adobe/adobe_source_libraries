/*
    Copyright 2013 Adobe
    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
*/
/**************************************************************************************************/

#ifndef ADOBE_ALGORITHM_IDENTITY_ELEMENT_HPP
#define ADOBE_ALGORITHM_IDENTITY_ELEMENT_HPP

#include <adobe/config.hpp>

#include <algorithm>
#include <functional>

/**************************************************************************************************/

namespace adobe {

/**************************************************************************************************/
/*!
    \defgroup misc_functional Miscellaneous Functional Operators
    \ingroup adobe_functional

    \brief utility class to obtain the identity element for an operation
*/
template <typename Op>
struct identity_element {
    /// the type of the identity is the same as the result tyupe of the operation
    typedef typename Op::result_type result_type;

    /// Yields the identitiy element
    result_type operator()() const;
};

/*!
    \ingroup misc_functional

    \brief specialization of identity_element for std::plus<T>
*/
template <typename T>
struct identity_element<std::plus<T>> {
    /// the type of the identity is the same as the result tyupe of the operation
    typedef T result_type;

    /// Yields the identitiy element for addition
    result_type operator()() const { return T(0); }
};

/*!
    \ingroup misc_functional

    \brief specialization of identity_element for std::multiplies<T>
*/
template <typename T>
struct identity_element<std::multiplies<T>> {
    /// the type of the identity is the same as the result tyupe of the operation
    typedef T result_type;

    /// Yields the identitiy element for multiplication
    result_type operator()() const { return T(1); }
};

/**************************************************************************************************/

} // namespace adobe

/**************************************************************************************************/

#endif

/**************************************************************************************************/
