/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC (info@laughlinresearch.com)

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/
#ifndef __SMDS_Templates_Header__
#define __SMDS_Templates_Header__

#include <pyOCCT_Common.hxx>

#include <SMDS_Iterator.hxx>
#include <SMDS_IteratorOnIterators.hxx>
#include <SMDS_SetIterator.hxx>
#include <SMDS_StdIterator.hxx>

// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_Iterator.hxx
template <typename VALUE>
void bind_SMDS_Iterator(py::object &mod, std::string const &name) {

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_Iterator.hxx
	py::class_<SMDS_Iterator<VALUE>, boost::shared_ptr<SMDS_Iterator<VALUE>>> cls(mod, name.c_str(), "//////////////////////////////////////////////////////////////////////////// Abstract class for iterators");
	cls.def("more", (bool (SMDS_Iterator<VALUE>::*)()) &SMDS_Iterator<VALUE>::more, "Return true if and only if there are other object in this iterator");
	cls.def("next", (VALUE (SMDS_Iterator<VALUE>::*)()) &SMDS_Iterator<VALUE>::next, "Return the current object and step to the next one");
	cls.def("remove", (void (SMDS_Iterator<VALUE>::*)()) &SMDS_Iterator<VALUE>::remove, "Delete the current element and step to the next one");

};

// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_IteratorOnIterators.hxx
template <typename VALUE, typename CONTAINER_OF_ITERATORS>
void bind_SMDS_IteratorOnIterators(py::object &mod, std::string const &name) {

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_IteratorOnIterators.hxx
	py::class_<SMDS_IteratorOnIterators<VALUE, CONTAINER_OF_ITERATORS>, std::unique_ptr<SMDS_IteratorOnIterators<VALUE, CONTAINER_OF_ITERATORS>, Deleter<SMDS_IteratorOnIterators<VALUE, CONTAINER_OF_ITERATORS>>>, SMDS_Iterator<VALUE>> cls(mod, name.c_str(), "//////////////////////////////////////////////////////////////////////////// SMDS_Iterator iterating over all elements provided by other iterators");
	cls.def(py::init<const CONTAINER_OF_ITERATORS &>(), py::arg("iterators"));
	cls.def("more", (bool (SMDS_IteratorOnIterators<VALUE, CONTAINER_OF_ITERATORS>::*)()) &SMDS_IteratorOnIterators<VALUE, CONTAINER_OF_ITERATORS>::more, "Return true iff there are other object in this iterator");
	cls.def("next", (VALUE (SMDS_IteratorOnIterators<VALUE, CONTAINER_OF_ITERATORS>::*)()) &SMDS_IteratorOnIterators<VALUE, CONTAINER_OF_ITERATORS>::next, "Return the current object and step to the next one");

};

// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_SetIterator.hxx
template <typename VALUE, typename VALUE_SET_ITERATOR, typename ACCESOR, typename VALUE_FILTER>
void bind_SMDS_SetIterator(py::object &mod, std::string const &name) {

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_SetIterator.hxx
	py::class_<SMDS_SetIterator<VALUE, VALUE_SET_ITERATOR, ACCESOR, VALUE_FILTER>, std::unique_ptr<SMDS_SetIterator<VALUE, VALUE_SET_ITERATOR, ACCESOR, VALUE_FILTER>, Deleter<SMDS_SetIterator<VALUE, VALUE_SET_ITERATOR, ACCESOR, VALUE_FILTER>>>, SMDS_Iterator<VALUE>> cls(mod, name.c_str(), "//////////////////////////////////////////////////////////////////////////// SMDS_Iterator iterating over abstract set of values like STL containers");
	cls.def(py::init<const VALUE_SET_ITERATOR &, const VALUE_SET_ITERATOR &>(), py::arg("begin"), py::arg("end"));
	cls.def(py::init<const VALUE_SET_ITERATOR &, const VALUE_SET_ITERATOR &, const VALUE_FILTER &>(), py::arg("begin"), py::arg("end"), py::arg("filter"));
	cls.def("init", [](SMDS_SetIterator<VALUE, VALUE_SET_ITERATOR, ACCESOR, VALUE_FILTER> &self, const VALUE_SET_ITERATOR & a0, const VALUE_SET_ITERATOR & a1) -> void { return self.init(a0, a1); }, py::arg("begin"), py::arg("end"));
	cls.def("init", (void (SMDS_SetIterator<VALUE, VALUE_SET_ITERATOR, ACCESOR, VALUE_FILTER>::*)(const VALUE_SET_ITERATOR &, const VALUE_SET_ITERATOR &, const VALUE_FILTER &)) &SMDS_SetIterator<VALUE, VALUE_SET_ITERATOR, ACCESOR, VALUE_FILTER>::init, "Initialization", py::arg("begin"), py::arg("end"), py::arg("filter"));
	cls.def("more", (bool (SMDS_SetIterator<VALUE, VALUE_SET_ITERATOR, ACCESOR, VALUE_FILTER>::*)()) &SMDS_SetIterator<VALUE, VALUE_SET_ITERATOR, ACCESOR, VALUE_FILTER>::more, "Return true iff there are other object in this iterator");
	cls.def("next", (VALUE (SMDS_SetIterator<VALUE, VALUE_SET_ITERATOR, ACCESOR, VALUE_FILTER>::*)()) &SMDS_SetIterator<VALUE, VALUE_SET_ITERATOR, ACCESOR, VALUE_FILTER>::next, "Return the current object and step to the next one");

};

// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_StdIterator.hxx
template <typename VALUE, typename PtrSMDSIterator, typename EqualVALUE>
void bind_SMDS_StdIterator(py::object &mod, std::string const &name) {

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_StdIterator.hxx
	py::class_<SMDS_StdIterator<VALUE, PtrSMDSIterator, EqualVALUE>, std::unique_ptr<SMDS_StdIterator<VALUE, PtrSMDSIterator, EqualVALUE>, Deleter<SMDS_StdIterator<VALUE, PtrSMDSIterator, EqualVALUE>>>, std::iterator<std::input_iterator_tag, VALUE>> cls(mod, name.c_str(), "Wrapper over pointer to SMDS_Iterator, like SMDS_ElemIteratorPtr, enabling its usage in std-like way: provide operators ++, *, etc.");
	cls.def(py::init<PtrSMDSIterator>(), py::arg("pItr"));
	cls.def(py::init<>());
	cls.def("__mul__", (VALUE (SMDS_StdIterator<VALUE, PtrSMDSIterator, EqualVALUE>::*)() const ) &SMDS_StdIterator<VALUE, PtrSMDSIterator, EqualVALUE>::operator*, py::is_operator(), "Return the current object");
	cls.def("plus_plus", (typename SMDS_StdIterator<VALUE, PtrSMDSIterator, EqualVALUE>::_Self & (SMDS_StdIterator<VALUE, PtrSMDSIterator, EqualVALUE>::*)()) &SMDS_StdIterator<VALUE, PtrSMDSIterator, EqualVALUE>::operator++, py::is_operator(), "None");
	cls.def("plus_plus", (typename SMDS_StdIterator<VALUE, PtrSMDSIterator, EqualVALUE>::_Self (SMDS_StdIterator<VALUE, PtrSMDSIterator, EqualVALUE>::*)(int)) &SMDS_StdIterator<VALUE, PtrSMDSIterator, EqualVALUE>::operator++, py::is_operator(), "None", py::arg(""));
	cls.def("__ne__", (bool (SMDS_StdIterator<VALUE, PtrSMDSIterator, EqualVALUE>::*)(const typename SMDS_StdIterator<VALUE, PtrSMDSIterator, EqualVALUE>::_Self &) const ) &SMDS_StdIterator<VALUE, PtrSMDSIterator, EqualVALUE>::operator!=, py::is_operator(), "None", py::arg("__x"));
	cls.def("__eq__", (bool (SMDS_StdIterator<VALUE, PtrSMDSIterator, EqualVALUE>::*)(const typename SMDS_StdIterator<VALUE, PtrSMDSIterator, EqualVALUE>::_Self &) const ) &SMDS_StdIterator<VALUE, PtrSMDSIterator, EqualVALUE>::operator==, py::is_operator(), "None", py::arg("__x"));

};

// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_SetIterator.hxx
template <typename M>
void bind_SMDS_mapIterator(py::object &mod, std::string const &name) {

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_SetIterator.hxx
	py::class_<SMDS_mapIterator<M>, std::unique_ptr<SMDS_mapIterator<M>, Deleter<SMDS_mapIterator<M>>>, SMDS_SetIterator<typename M::mapped_type, typename M::const_iterator, SMDS::ValueAccessor<typename M::mapped_type, typename M::const_iterator> >> cls(mod, name.c_str(), "iterator on values of a map");
	cls.def(py::init<const M &>(), py::arg("m"));

};

// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_SetIterator.hxx
template <typename M>
void bind_SMDS_mapKeyIterator(py::object &mod, std::string const &name) {

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_SetIterator.hxx
	py::class_<SMDS_mapKeyIterator<M>, std::unique_ptr<SMDS_mapKeyIterator<M>, Deleter<SMDS_mapKeyIterator<M>>>, SMDS_SetIterator<typename M::key_type, typename M::const_iterator, SMDS::KeyAccessor<typename M::key_type, typename M::const_iterator> >> cls(mod, name.c_str(), "iterator on keys of a map");
	cls.def(py::init<const M &>(), py::arg("m"));

};

// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_SetIterator.hxx
template <typename M>
void bind_SMDS_mapKeyReverseIterator(py::object &mod, std::string const &name) {

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_SetIterator.hxx
	py::class_<SMDS_mapKeyReverseIterator<M>, std::unique_ptr<SMDS_mapKeyReverseIterator<M>, Deleter<SMDS_mapKeyReverseIterator<M>>>, SMDS_SetIterator<typename M::key_type, typename M::const_iterator, SMDS::KeyAccessor<typename M::key_type, typename M::const_iterator> >> cls(mod, name.c_str(), "reverse iterator on keys of a map");
	cls.def(py::init<const M &>(), py::arg("m"));

};

// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_SetIterator.hxx
template <typename M>
void bind_SMDS_mapReverseIterator(py::object &mod, std::string const &name) {

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMDS_SetIterator.hxx
	py::class_<SMDS_mapReverseIterator<M>, std::unique_ptr<SMDS_mapReverseIterator<M>, Deleter<SMDS_mapReverseIterator<M>>>, SMDS_SetIterator<typename M::mapped_type, typename M::const_reverse_iterator, SMDS::ValueAccessor<typename M::mapped_type, typename M::const_reverse_iterator> >> cls(mod, name.c_str(), "reverse iterator on values of a map");
	cls.def(py::init<const M &>(), py::arg("m"));

};

#endif