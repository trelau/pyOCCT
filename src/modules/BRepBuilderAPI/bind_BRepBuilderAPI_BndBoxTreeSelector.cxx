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
#include <BRepBuilderAPI_BndBoxTreeSelector.hxx>
#include <NCollection_UBTree.hxx>
#include <Standard_TypeDef.hxx>
#include <Bnd_Box.hxx>
#include <TColStd_ListOfInteger.hxx>

void bind_BRepBuilderAPI_BndBoxTreeSelector(py::module &mod){

py::class_<BRepBuilderAPI_BndBoxTreeSelector, std::unique_ptr<BRepBuilderAPI_BndBoxTreeSelector>, BRepBuilderAPI_BndBoxTree::Selector> cls_BRepBuilderAPI_BndBoxTreeSelector(mod, "BRepBuilderAPI_BndBoxTreeSelector", "Class BRepBuilderAPI_BndBoxTreeSelector derived from UBTree::Selector This class is used to select overlapping boxes, stored in NCollection::UBTree; contains methods to maintain the selection condition and to retrieve selected objects after search.");

// Constructors
cls_BRepBuilderAPI_BndBoxTreeSelector.def(py::init<>());

// Fields

// Methods
cls_BRepBuilderAPI_BndBoxTreeSelector.def("Reject", (Standard_Boolean (BRepBuilderAPI_BndBoxTreeSelector::*)(const Bnd_Box &) const) &BRepBuilderAPI_BndBoxTreeSelector::Reject, "Implementation of rejection method", py::arg("theBox"));
cls_BRepBuilderAPI_BndBoxTreeSelector.def("Accept", (Standard_Boolean (BRepBuilderAPI_BndBoxTreeSelector::*)(const Standard_Integer &)) &BRepBuilderAPI_BndBoxTreeSelector::Accept, "Implementation of acceptance method This method is called when the bounding box intersect with the current. It stores the object - the index of box in the list of accepted objects.", py::arg("theObj"));
cls_BRepBuilderAPI_BndBoxTreeSelector.def("ClearResList", (void (BRepBuilderAPI_BndBoxTreeSelector::*)()) &BRepBuilderAPI_BndBoxTreeSelector::ClearResList, "Clear the list of intersecting boxes");
cls_BRepBuilderAPI_BndBoxTreeSelector.def("SetCurrent", (void (BRepBuilderAPI_BndBoxTreeSelector::*)(const Bnd_Box &)) &BRepBuilderAPI_BndBoxTreeSelector::SetCurrent, "Set current box to search for overlapping with him", py::arg("theBox"));
cls_BRepBuilderAPI_BndBoxTreeSelector.def("ResInd", (const TColStd_ListOfInteger & (BRepBuilderAPI_BndBoxTreeSelector::*)()) &BRepBuilderAPI_BndBoxTreeSelector::ResInd, "Get list of indexes of boxes intersecting with the current box");

// Enums

}