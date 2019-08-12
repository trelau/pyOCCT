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
#include <Standard_TypeDef.hxx>
#include <TopoDS_Edge.hxx>
#include <HLRAlgo_EdgesBlock.hxx>
#include <HLRAlgo_EdgeStatus.hxx>
#include <HLRBRep_Curve.hxx>
#include <HLRBRep_EdgeData.hxx>

void bind_HLRBRep_EdgeData(py::module &mod){

py::class_<HLRBRep_EdgeData, std::unique_ptr<HLRBRep_EdgeData, Deleter<HLRBRep_EdgeData>>> cls_HLRBRep_EdgeData(mod, "HLRBRep_EdgeData", "None");

// Constructors
cls_HLRBRep_EdgeData.def(py::init<>());

// Fields

// Methods
// cls_HLRBRep_EdgeData.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_EdgeData::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_EdgeData.def_static("operator delete_", (void (*)(void *)) &HLRBRep_EdgeData::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_EdgeData.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_EdgeData::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_EdgeData.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_EdgeData::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_EdgeData.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_EdgeData::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_EdgeData.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_EdgeData::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_EdgeData.def("Set", (void (HLRBRep_EdgeData::*)(const Standard_Boolean, const Standard_Boolean, const TopoDS_Edge &, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Real, const Standard_ShortReal, const Standard_Real, const Standard_ShortReal)) &HLRBRep_EdgeData::Set, "None", py::arg("Reg1"), py::arg("RegN"), py::arg("EG"), py::arg("V1"), py::arg("V2"), py::arg("Out1"), py::arg("Out2"), py::arg("Cut1"), py::arg("Cut2"), py::arg("Start"), py::arg("TolStart"), py::arg("End"), py::arg("TolEnd"));
cls_HLRBRep_EdgeData.def("Selected", (Standard_Boolean (HLRBRep_EdgeData::*)() const) &HLRBRep_EdgeData::Selected, "None");
cls_HLRBRep_EdgeData.def("Selected", (void (HLRBRep_EdgeData::*)(const Standard_Boolean)) &HLRBRep_EdgeData::Selected, "None", py::arg("B"));
cls_HLRBRep_EdgeData.def("Rg1Line", (Standard_Boolean (HLRBRep_EdgeData::*)() const) &HLRBRep_EdgeData::Rg1Line, "None");
cls_HLRBRep_EdgeData.def("Rg1Line", (void (HLRBRep_EdgeData::*)(const Standard_Boolean)) &HLRBRep_EdgeData::Rg1Line, "None", py::arg("B"));
cls_HLRBRep_EdgeData.def("RgNLine", (Standard_Boolean (HLRBRep_EdgeData::*)() const) &HLRBRep_EdgeData::RgNLine, "None");
cls_HLRBRep_EdgeData.def("RgNLine", (void (HLRBRep_EdgeData::*)(const Standard_Boolean)) &HLRBRep_EdgeData::RgNLine, "None", py::arg("B"));
cls_HLRBRep_EdgeData.def("Vertical", (Standard_Boolean (HLRBRep_EdgeData::*)() const) &HLRBRep_EdgeData::Vertical, "None");
cls_HLRBRep_EdgeData.def("Vertical", (void (HLRBRep_EdgeData::*)(const Standard_Boolean)) &HLRBRep_EdgeData::Vertical, "None", py::arg("B"));
cls_HLRBRep_EdgeData.def("Simple", (Standard_Boolean (HLRBRep_EdgeData::*)() const) &HLRBRep_EdgeData::Simple, "None");
cls_HLRBRep_EdgeData.def("Simple", (void (HLRBRep_EdgeData::*)(const Standard_Boolean)) &HLRBRep_EdgeData::Simple, "None", py::arg("B"));
cls_HLRBRep_EdgeData.def("OutLVSta", (Standard_Boolean (HLRBRep_EdgeData::*)() const) &HLRBRep_EdgeData::OutLVSta, "None");
cls_HLRBRep_EdgeData.def("OutLVSta", (void (HLRBRep_EdgeData::*)(const Standard_Boolean)) &HLRBRep_EdgeData::OutLVSta, "None", py::arg("B"));
cls_HLRBRep_EdgeData.def("OutLVEnd", (Standard_Boolean (HLRBRep_EdgeData::*)() const) &HLRBRep_EdgeData::OutLVEnd, "None");
cls_HLRBRep_EdgeData.def("OutLVEnd", (void (HLRBRep_EdgeData::*)(const Standard_Boolean)) &HLRBRep_EdgeData::OutLVEnd, "None", py::arg("B"));
cls_HLRBRep_EdgeData.def("CutAtSta", (Standard_Boolean (HLRBRep_EdgeData::*)() const) &HLRBRep_EdgeData::CutAtSta, "None");
cls_HLRBRep_EdgeData.def("CutAtSta", (void (HLRBRep_EdgeData::*)(const Standard_Boolean)) &HLRBRep_EdgeData::CutAtSta, "None", py::arg("B"));
cls_HLRBRep_EdgeData.def("CutAtEnd", (Standard_Boolean (HLRBRep_EdgeData::*)() const) &HLRBRep_EdgeData::CutAtEnd, "None");
cls_HLRBRep_EdgeData.def("CutAtEnd", (void (HLRBRep_EdgeData::*)(const Standard_Boolean)) &HLRBRep_EdgeData::CutAtEnd, "None", py::arg("B"));
cls_HLRBRep_EdgeData.def("VerAtSta", (Standard_Boolean (HLRBRep_EdgeData::*)() const) &HLRBRep_EdgeData::VerAtSta, "None");
cls_HLRBRep_EdgeData.def("VerAtSta", (void (HLRBRep_EdgeData::*)(const Standard_Boolean)) &HLRBRep_EdgeData::VerAtSta, "None", py::arg("B"));
cls_HLRBRep_EdgeData.def("VerAtEnd", (Standard_Boolean (HLRBRep_EdgeData::*)() const) &HLRBRep_EdgeData::VerAtEnd, "None");
cls_HLRBRep_EdgeData.def("VerAtEnd", (void (HLRBRep_EdgeData::*)(const Standard_Boolean)) &HLRBRep_EdgeData::VerAtEnd, "None", py::arg("B"));
cls_HLRBRep_EdgeData.def("AutoIntersectionDone", (Standard_Boolean (HLRBRep_EdgeData::*)() const) &HLRBRep_EdgeData::AutoIntersectionDone, "None");
cls_HLRBRep_EdgeData.def("AutoIntersectionDone", (void (HLRBRep_EdgeData::*)(const Standard_Boolean)) &HLRBRep_EdgeData::AutoIntersectionDone, "None", py::arg("B"));
cls_HLRBRep_EdgeData.def("Used", (Standard_Boolean (HLRBRep_EdgeData::*)() const) &HLRBRep_EdgeData::Used, "None");
cls_HLRBRep_EdgeData.def("Used", (void (HLRBRep_EdgeData::*)(const Standard_Boolean)) &HLRBRep_EdgeData::Used, "None", py::arg("B"));
cls_HLRBRep_EdgeData.def("HideCount", (Standard_Integer (HLRBRep_EdgeData::*)() const) &HLRBRep_EdgeData::HideCount, "None");
cls_HLRBRep_EdgeData.def("HideCount", (void (HLRBRep_EdgeData::*)(const Standard_Integer)) &HLRBRep_EdgeData::HideCount, "None", py::arg("I"));
cls_HLRBRep_EdgeData.def("VSta", (Standard_Integer (HLRBRep_EdgeData::*)() const) &HLRBRep_EdgeData::VSta, "None");
cls_HLRBRep_EdgeData.def("VSta", (void (HLRBRep_EdgeData::*)(const Standard_Integer)) &HLRBRep_EdgeData::VSta, "None", py::arg("I"));
cls_HLRBRep_EdgeData.def("VEnd", (Standard_Integer (HLRBRep_EdgeData::*)() const) &HLRBRep_EdgeData::VEnd, "None");
cls_HLRBRep_EdgeData.def("VEnd", (void (HLRBRep_EdgeData::*)(const Standard_Integer)) &HLRBRep_EdgeData::VEnd, "None", py::arg("I"));
cls_HLRBRep_EdgeData.def("UpdateMinMax", (void (HLRBRep_EdgeData::*)(const HLRAlgo_EdgesBlock::MinMaxIndices &)) &HLRBRep_EdgeData::UpdateMinMax, "None", py::arg("theTotMinMax"));
cls_HLRBRep_EdgeData.def("MinMax", (HLRAlgo_EdgesBlock::MinMaxIndices & (HLRBRep_EdgeData::*)()) &HLRBRep_EdgeData::MinMax, "None");
cls_HLRBRep_EdgeData.def("Status", (HLRAlgo_EdgeStatus & (HLRBRep_EdgeData::*)()) &HLRBRep_EdgeData::Status, "None");
cls_HLRBRep_EdgeData.def("ChangeGeometry", (HLRBRep_Curve & (HLRBRep_EdgeData::*)()) &HLRBRep_EdgeData::ChangeGeometry, "None");
cls_HLRBRep_EdgeData.def("Geometry", (const HLRBRep_Curve & (HLRBRep_EdgeData::*)() const) &HLRBRep_EdgeData::Geometry, "None");
cls_HLRBRep_EdgeData.def("Curve", (HLRBRep_Curve * (HLRBRep_EdgeData::*)()) &HLRBRep_EdgeData::Curve, "None");
cls_HLRBRep_EdgeData.def("Tolerance", (Standard_ShortReal (HLRBRep_EdgeData::*)() const) &HLRBRep_EdgeData::Tolerance, "None");

// Enums

}