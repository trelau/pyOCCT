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
#ifndef __BasicsGenericDestructor_Templates_Header__
#define __BasicsGenericDestructor_Templates_Header__

#include <pyOCCT_Common.hxx>

#include <BasicsGenericDestructor.hxx>

// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\BasicsGenericDestructor.hxx
template <typename TYPE>
void bind_DESTRUCTOR_OF(py::object &mod, std::string const &name) {

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\BasicsGenericDestructor.hxx
	py::class_<DESTRUCTOR_OF<TYPE>, std::unique_ptr<DESTRUCTOR_OF<TYPE>, Deleter<DESTRUCTOR_OF<TYPE>>>, GENERIC_DESTRUCTOR> cls(mod, name.c_str(), "The DESTRUCTOR_OF class allows the user to program - at any moment - the destruction of an object at the end of the process.");
	cls.def(py::init<TYPE &>(), py::arg("anObject"));
	cls.def("__call__", (void (DESTRUCTOR_OF<TYPE>::*)()) &DESTRUCTOR_OF<TYPE>::operator(), py::is_operator(), "Performs the destruction of the object. This method really destroys the object pointed by _objectPtr. It should be called at the end of the process (i.e. at exit).");

};

#endif