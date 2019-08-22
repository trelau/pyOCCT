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
#include <ShapeAnalysis_BoxBndTree.hxx>
#include <NCollection_UBTree.hxx>
#include <Standard_Handle.hxx>
#include <TopTools_HArray1OfShape.hxx>
#include <Standard_TypeDef.hxx>
#include <ShapeExtend.hxx>
#include <Bnd_Box.hxx>
#include <TopoDS_Vertex.hxx>
#include <gp_Pnt.hxx>
#include <ShapeExtend_Status.hxx>
#include <TColStd_MapOfInteger.hxx>
#include <TColStd_Array1OfInteger.hxx>

void bind_ShapeAnalysis_BoxBndTreeSelector(py::module &mod){

py::class_<ShapeAnalysis_BoxBndTreeSelector, ShapeAnalysis_BoxBndTree::Selector> cls_ShapeAnalysis_BoxBndTreeSelector(mod, "ShapeAnalysis_BoxBndTreeSelector", "None");

// Constructors
// cls_ShapeAnalysis_BoxBndTreeSelector.def(py::init<opencascade::handle<TopTools_HArray1OfShape>, Standard_Boolean>(), py::arg("theSeq"), py::arg("theShared"));

// Fields

// Methods
cls_ShapeAnalysis_BoxBndTreeSelector.def("DefineBoxes", (void (ShapeAnalysis_BoxBndTreeSelector::*)(const Bnd_Box &, const Bnd_Box &)) &ShapeAnalysis_BoxBndTreeSelector::DefineBoxes, "None", py::arg("theFBox"), py::arg("theLBox"));
cls_ShapeAnalysis_BoxBndTreeSelector.def("DefineVertexes", (void (ShapeAnalysis_BoxBndTreeSelector::*)(TopoDS_Vertex, TopoDS_Vertex)) &ShapeAnalysis_BoxBndTreeSelector::DefineVertexes, "None", py::arg("theVf"), py::arg("theVl"));
cls_ShapeAnalysis_BoxBndTreeSelector.def("DefinePnt", (void (ShapeAnalysis_BoxBndTreeSelector::*)(gp_Pnt, gp_Pnt)) &ShapeAnalysis_BoxBndTreeSelector::DefinePnt, "None", py::arg("theFPnt"), py::arg("theLPnt"));
cls_ShapeAnalysis_BoxBndTreeSelector.def("GetNb", (Standard_Integer (ShapeAnalysis_BoxBndTreeSelector::*)()) &ShapeAnalysis_BoxBndTreeSelector::GetNb, "None");
cls_ShapeAnalysis_BoxBndTreeSelector.def("SetNb", (void (ShapeAnalysis_BoxBndTreeSelector::*)(Standard_Integer)) &ShapeAnalysis_BoxBndTreeSelector::SetNb, "None", py::arg("theNb"));
cls_ShapeAnalysis_BoxBndTreeSelector.def("LoadList", (void (ShapeAnalysis_BoxBndTreeSelector::*)(Standard_Integer)) &ShapeAnalysis_BoxBndTreeSelector::LoadList, "None", py::arg("elem"));
cls_ShapeAnalysis_BoxBndTreeSelector.def("SetStop", (void (ShapeAnalysis_BoxBndTreeSelector::*)()) &ShapeAnalysis_BoxBndTreeSelector::SetStop, "None");
cls_ShapeAnalysis_BoxBndTreeSelector.def("SetTolerance", (void (ShapeAnalysis_BoxBndTreeSelector::*)(Standard_Real)) &ShapeAnalysis_BoxBndTreeSelector::SetTolerance, "None", py::arg("theTol"));
cls_ShapeAnalysis_BoxBndTreeSelector.def("ContWire", (Standard_Boolean (ShapeAnalysis_BoxBndTreeSelector::*)(Standard_Integer)) &ShapeAnalysis_BoxBndTreeSelector::ContWire, "None", py::arg("nbWire"));
cls_ShapeAnalysis_BoxBndTreeSelector.def("LastCheckStatus", (Standard_Boolean (ShapeAnalysis_BoxBndTreeSelector::*)(const ShapeExtend_Status) const) &ShapeAnalysis_BoxBndTreeSelector::LastCheckStatus, "None", py::arg("theStatus"));
cls_ShapeAnalysis_BoxBndTreeSelector.def("Reject", (Standard_Boolean (ShapeAnalysis_BoxBndTreeSelector::*)(const Bnd_Box &) const) &ShapeAnalysis_BoxBndTreeSelector::Reject, "None", py::arg("theBnd"));
cls_ShapeAnalysis_BoxBndTreeSelector.def("Accept", (Standard_Boolean (ShapeAnalysis_BoxBndTreeSelector::*)(const Standard_Integer &)) &ShapeAnalysis_BoxBndTreeSelector::Accept, "None", py::arg(""));

// Enums

}