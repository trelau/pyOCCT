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
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <TopTools_HArray2OfShape.hxx>
#include <BRepFill_TransitionStyle.hxx>
#include <gp_Ax2.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Shape.hxx>
#include <TopTools_ListOfShape.hxx>
#include <BOPDS_PDS.hxx>
#include <TopoDS_Vertex.hxx>
#include <gp_Pln.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <BRepFill_TrimShellCorner.hxx>

void bind_BRepFill_TrimShellCorner(py::module &mod){

py::class_<BRepFill_TrimShellCorner, std::unique_ptr<BRepFill_TrimShellCorner, Deleter<BRepFill_TrimShellCorner>>> cls_BRepFill_TrimShellCorner(mod, "BRepFill_TrimShellCorner", "Trims sets of faces in the corner to make proper parts of pipe");

// Constructors
cls_BRepFill_TrimShellCorner.def(py::init<const opencascade::handle<TopTools_HArray2OfShape> &, const BRepFill_TransitionStyle, const gp_Ax2 &>(), py::arg("theFaces"), py::arg("theTransition"), py::arg("theAxeOfBisPlane"));

// Fields

// Methods
// cls_BRepFill_TrimShellCorner.def_static("operator new_", (void * (*)(size_t)) &BRepFill_TrimShellCorner::operator new, "None", py::arg("theSize"));
// cls_BRepFill_TrimShellCorner.def_static("operator delete_", (void (*)(void *)) &BRepFill_TrimShellCorner::operator delete, "None", py::arg("theAddress"));
// cls_BRepFill_TrimShellCorner.def_static("operator new[]_", (void * (*)(size_t)) &BRepFill_TrimShellCorner::operator new[], "None", py::arg("theSize"));
// cls_BRepFill_TrimShellCorner.def_static("operator delete[]_", (void (*)(void *)) &BRepFill_TrimShellCorner::operator delete[], "None", py::arg("theAddress"));
// cls_BRepFill_TrimShellCorner.def_static("operator new_", (void * (*)(size_t, void *)) &BRepFill_TrimShellCorner::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepFill_TrimShellCorner.def_static("operator delete_", (void (*)(void *, void *)) &BRepFill_TrimShellCorner::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepFill_TrimShellCorner.def("AddBounds", (void (BRepFill_TrimShellCorner::*)(const opencascade::handle<TopTools_HArray2OfShape> &)) &BRepFill_TrimShellCorner::AddBounds, "None", py::arg("Bounds"));
cls_BRepFill_TrimShellCorner.def("AddUEdges", (void (BRepFill_TrimShellCorner::*)(const opencascade::handle<TopTools_HArray2OfShape> &)) &BRepFill_TrimShellCorner::AddUEdges, "None", py::arg("theUEdges"));
cls_BRepFill_TrimShellCorner.def("Perform", (void (BRepFill_TrimShellCorner::*)()) &BRepFill_TrimShellCorner::Perform, "None");
cls_BRepFill_TrimShellCorner.def("IsDone", (Standard_Boolean (BRepFill_TrimShellCorner::*)() const) &BRepFill_TrimShellCorner::IsDone, "None");
cls_BRepFill_TrimShellCorner.def("HasSection", (Standard_Boolean (BRepFill_TrimShellCorner::*)() const) &BRepFill_TrimShellCorner::HasSection, "None");
cls_BRepFill_TrimShellCorner.def("Modified", (void (BRepFill_TrimShellCorner::*)(const TopoDS_Shape &, TopTools_ListOfShape &)) &BRepFill_TrimShellCorner::Modified, "None", py::arg("S"), py::arg("theModified"));

// Enums

}