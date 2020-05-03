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
#ifndef __ObjectPool_Templates_Header__
#define __ObjectPool_Templates_Header__

#include <pyOCCT_Common.hxx>

#include <ObjectPool.hxx>

// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\ObjectPool.hxx
template <typename X>
void bind_ObjectPool(py::object &mod, std::string const &name) {

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\ObjectPool.hxx
	py::class_<ObjectPool<X>, std::unique_ptr<ObjectPool<X>, Deleter<ObjectPool<X>>>> cls(mod, name.c_str(), "None");
	cls.def(py::init<int>(), py::arg("nblk"));
	cls.def("getNew", (X * (ObjectPool<X>::*)()) &ObjectPool<X>::getNew, "None");
	cls.def("destroy", (void (ObjectPool<X>::*)(X *)) &ObjectPool<X>::destroy, "None", py::arg("obj"));
	cls.def("clear", (void (ObjectPool<X>::*)()) &ObjectPool<X>::clear, "None");

};

#endif