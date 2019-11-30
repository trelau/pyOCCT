/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC
Copyright (C) 2019 Trevor Laughlin and the pyOCCT contributors

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
#ifndef __NCollection_DefaultHasher__
#define __NCollection_DefaultHasher__

#include <Standard_TypeDef.hxx>
#include <NCollection_DefaultHasher.hxx>

template <typename TheKeyType>
void bind_NCollection_DefaultHasher(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<NCollection_DefaultHasher<TheKeyType>> cls_NCollection_DefaultHasher(mod, name.c_str(), "Purpose: The DefaultHasher is a Hasher that is used by default in NCollection maps. To compute the hash code of the key is used the global function HashCode. To compare two keys is used the global function IsEqual.", local);

// Constructors
cls_NCollection_DefaultHasher.def(py::init<>());

// Methods
cls_NCollection_DefaultHasher.def_static("HashCode_", (Standard_Integer (*)(const TheKeyType &, const Standard_Integer)) &NCollection_DefaultHasher<TheKeyType>::HashCode, "Returns hash code for the given key, in the range [1, theUpperBound]", py::arg("theKey"), py::arg("theUpperBound"));
cls_NCollection_DefaultHasher.def_static("IsEqual_", (Standard_Boolean (*)(const TheKeyType &, const TheKeyType &)) &NCollection_DefaultHasher<TheKeyType>::IsEqual, "None", py::arg("theKey1"), py::arg("theKey2"));

}

#endif