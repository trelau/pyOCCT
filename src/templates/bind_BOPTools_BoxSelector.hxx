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
#ifndef __BOPTools_BoxSelector__
#define __BOPTools_BoxSelector__

#include <NCollection_UBTree.hxx>
#include <Standard_TypeDef.hxx>
#include <BOPTools_BoxSelector.hxx>
#include <TColStd_ListOfInteger.hxx>

template <typename BoxType>
void bind_BOPTools_BoxSelector(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<BOPTools_BoxSelector<BoxType>, typename NCollection_UBTree<Standard_Integer, BoxType>::Selector> cls_BOPTools_BoxSelector(mod, name.c_str(), "Template Selector for the unbalanced binary tree of overlapped bounding boxes.", local);

// Constructors
cls_BOPTools_BoxSelector.def(py::init<>());

// Methods
cls_BOPTools_BoxSelector.def("Reject", (Standard_Boolean (BOPTools_BoxSelector<BoxType>::*)(const BoxType &) const) &BOPTools_BoxSelector<BoxType>::Reject, "Checks if the box should be rejected", py::arg("theOther"));
cls_BOPTools_BoxSelector.def("Accept", (Standard_Boolean (BOPTools_BoxSelector<BoxType>::*)(const Standard_Integer &)) &BOPTools_BoxSelector<BoxType>::Accept, "Accepts the index", py::arg("theIndex"));
cls_BOPTools_BoxSelector.def("Clear", (void (BOPTools_BoxSelector<BoxType>::*)()) &BOPTools_BoxSelector<BoxType>::Clear, "Clears the indices");
cls_BOPTools_BoxSelector.def("SetBox", (void (BOPTools_BoxSelector<BoxType>::*)(const BoxType &)) &BOPTools_BoxSelector<BoxType>::SetBox, "Sets the box", py::arg("theBox"));
cls_BOPTools_BoxSelector.def("Indices", (const TColStd_ListOfInteger & (BOPTools_BoxSelector<BoxType>::*)() const) &BOPTools_BoxSelector<BoxType>::Indices, "Returns the list of accepted indices");

}

#endif
