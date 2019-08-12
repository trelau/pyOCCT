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
#include <pyOCCT_Common.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_OutOfRange.hxx>
#include <BRepMesh_PairOfIndex.hxx>

void bind_BRepMesh_PairOfIndex(py::module &mod){

py::class_<BRepMesh_PairOfIndex, std::unique_ptr<BRepMesh_PairOfIndex, Deleter<BRepMesh_PairOfIndex>>> cls_BRepMesh_PairOfIndex(mod, "BRepMesh_PairOfIndex", "This class represents a pair of integer indices to store element indices connected to link. It is restricted to store more than two indices in it.");

// Constructors
cls_BRepMesh_PairOfIndex.def(py::init<>());

// Fields

// Methods
cls_BRepMesh_PairOfIndex.def("Clear", (void (BRepMesh_PairOfIndex::*)()) &BRepMesh_PairOfIndex::Clear, "Clears indices.");
cls_BRepMesh_PairOfIndex.def("Append", (void (BRepMesh_PairOfIndex::*)(const Standard_Integer)) &BRepMesh_PairOfIndex::Append, "Appends index to the pair.", py::arg("theIndex"));
cls_BRepMesh_PairOfIndex.def("Prepend", (void (BRepMesh_PairOfIndex::*)(const Standard_Integer)) &BRepMesh_PairOfIndex::Prepend, "Prepends index to the pair.", py::arg("theIndex"));
cls_BRepMesh_PairOfIndex.def("IsEmpty", (Standard_Boolean (BRepMesh_PairOfIndex::*)() const) &BRepMesh_PairOfIndex::IsEmpty, "Returns is pair is empty.");
cls_BRepMesh_PairOfIndex.def("Extent", (Standard_Integer (BRepMesh_PairOfIndex::*)() const) &BRepMesh_PairOfIndex::Extent, "Returns number of initialized indeces.");
cls_BRepMesh_PairOfIndex.def("FirstIndex", (Standard_Integer (BRepMesh_PairOfIndex::*)() const) &BRepMesh_PairOfIndex::FirstIndex, "Returns first index of pair.");
cls_BRepMesh_PairOfIndex.def("LastIndex", (Standard_Integer (BRepMesh_PairOfIndex::*)() const) &BRepMesh_PairOfIndex::LastIndex, "Returns last index of pair");
cls_BRepMesh_PairOfIndex.def("Index", (Standard_Integer (BRepMesh_PairOfIndex::*)(const Standard_Integer) const) &BRepMesh_PairOfIndex::Index, "Returns index corresponding to the given position in the pair.", py::arg("thePairPos"));
cls_BRepMesh_PairOfIndex.def("SetIndex", (void (BRepMesh_PairOfIndex::*)(const Standard_Integer, const Standard_Integer)) &BRepMesh_PairOfIndex::SetIndex, "Sets index corresponding to the given position in the pair.", py::arg("thePairPos"), py::arg("theIndex"));
cls_BRepMesh_PairOfIndex.def("RemoveIndex", (void (BRepMesh_PairOfIndex::*)(const Standard_Integer)) &BRepMesh_PairOfIndex::RemoveIndex, "Remove index from the given position.", py::arg("thePairPos"));

// Enums

}