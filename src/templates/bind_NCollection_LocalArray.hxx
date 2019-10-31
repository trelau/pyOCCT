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
#pragma once

#include <pyOCCT_Common.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_LocalArray.hxx>

template <typename theItem, Standard_Integer MAX_ARRAY_SIZE>
void bind_NCollection_LocalArray(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<NCollection_LocalArray<theItem, MAX_ARRAY_SIZE>> cls_NCollection_LocalArray(mod, name.c_str(), "Auxiliary class optimizing creation of array buffer (using stack allocation for small arrays).", local);

// Constructors
cls_NCollection_LocalArray.def(py::init<const size_t>(), py::arg("theSize"));
cls_NCollection_LocalArray.def(py::init<>());

// Methods
cls_NCollection_LocalArray.def("Allocate", (void (NCollection_LocalArray<theItem, MAX_ARRAY_SIZE>::*)(const size_t)) &NCollection_LocalArray<theItem, MAX_ARRAY_SIZE>::Allocate, "None", py::arg("theSize"));
cls_NCollection_LocalArray.def("Size", (size_t (NCollection_LocalArray<theItem, MAX_ARRAY_SIZE>::*)() const) &NCollection_LocalArray<theItem, MAX_ARRAY_SIZE>::Size, "None");

}
