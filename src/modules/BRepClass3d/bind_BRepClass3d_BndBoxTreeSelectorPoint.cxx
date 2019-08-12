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
#include <BRepClass3d_BndBoxTree.hxx>
#include <NCollection_UBTree.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <Standard_TypeDef.hxx>
#include <Bnd_Box.hxx>
#include <gp_Pnt.hxx>

void bind_BRepClass3d_BndBoxTreeSelectorPoint(py::module &mod){

py::class_<BRepClass3d_BndBoxTreeSelectorPoint, std::unique_ptr<BRepClass3d_BndBoxTreeSelectorPoint, Deleter<BRepClass3d_BndBoxTreeSelectorPoint>>, BRepClass3d_BndBoxTree::Selector> cls_BRepClass3d_BndBoxTreeSelectorPoint(mod, "BRepClass3d_BndBoxTreeSelectorPoint", "None");

// Constructors
// cls_BRepClass3d_BndBoxTreeSelectorPoint.def(py::init<const TopTools_IndexedMapOfShape &>(), py::arg("theMapOfShape"));

// Fields

// Methods
cls_BRepClass3d_BndBoxTreeSelectorPoint.def("Reject", (Standard_Boolean (BRepClass3d_BndBoxTreeSelectorPoint::*)(const Bnd_Box &) const) &BRepClass3d_BndBoxTreeSelectorPoint::Reject, "None", py::arg("theBox"));
cls_BRepClass3d_BndBoxTreeSelectorPoint.def("Accept", (Standard_Boolean (BRepClass3d_BndBoxTreeSelectorPoint::*)(const Standard_Integer &)) &BRepClass3d_BndBoxTreeSelectorPoint::Accept, "None", py::arg("theObj"));
cls_BRepClass3d_BndBoxTreeSelectorPoint.def("SetCurrentPoint", (void (BRepClass3d_BndBoxTreeSelectorPoint::*)(const gp_Pnt &)) &BRepClass3d_BndBoxTreeSelectorPoint::SetCurrentPoint, "None", py::arg("theP"));

// Enums

}