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
#include <AppDef_MultiLine.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <TColgp_Array1OfVec.hxx>
#include <TColgp_Array1OfVec2d.hxx>
#include <Approx_Status.hxx>
#include <AppDef_MyLineTool.hxx>

void bind_AppDef_MyLineTool(py::module &mod){

py::class_<AppDef_MyLineTool> cls_AppDef_MyLineTool(mod, "AppDef_MyLineTool", "example of MultiLine tool corresponding to the tools of the packages AppParCurves and Approx. For Approx, the tool will not addd points if the algorithms want some.");

// Constructors

// Fields

// Methods
// cls_AppDef_MyLineTool.def_static("operator new_", (void * (*)(size_t)) &AppDef_MyLineTool::operator new, "None", py::arg("theSize"));
// cls_AppDef_MyLineTool.def_static("operator delete_", (void (*)(void *)) &AppDef_MyLineTool::operator delete, "None", py::arg("theAddress"));
// cls_AppDef_MyLineTool.def_static("operator new[]_", (void * (*)(size_t)) &AppDef_MyLineTool::operator new[], "None", py::arg("theSize"));
// cls_AppDef_MyLineTool.def_static("operator delete[]_", (void (*)(void *)) &AppDef_MyLineTool::operator delete[], "None", py::arg("theAddress"));
// cls_AppDef_MyLineTool.def_static("operator new_", (void * (*)(size_t, void *)) &AppDef_MyLineTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AppDef_MyLineTool.def_static("operator delete_", (void (*)(void *, void *)) &AppDef_MyLineTool::operator delete, "None", py::arg(""), py::arg(""));
cls_AppDef_MyLineTool.def_static("FirstPoint_", (Standard_Integer (*)(const AppDef_MultiLine &)) &AppDef_MyLineTool::FirstPoint, "Returns the first index of multipoints of the MultiLine.", py::arg("ML"));
cls_AppDef_MyLineTool.def_static("LastPoint_", (Standard_Integer (*)(const AppDef_MultiLine &)) &AppDef_MyLineTool::LastPoint, "Returns the last index of multipoints of the MultiLine.", py::arg("ML"));
cls_AppDef_MyLineTool.def_static("NbP2d_", (Standard_Integer (*)(const AppDef_MultiLine &)) &AppDef_MyLineTool::NbP2d, "Returns the number of 2d points of a MultiLine.", py::arg("ML"));
cls_AppDef_MyLineTool.def_static("NbP3d_", (Standard_Integer (*)(const AppDef_MultiLine &)) &AppDef_MyLineTool::NbP3d, "Returns the number of 3d points of a MultiLine.", py::arg("ML"));
cls_AppDef_MyLineTool.def_static("Value_", (void (*)(const AppDef_MultiLine &, const Standard_Integer, TColgp_Array1OfPnt &)) &AppDef_MyLineTool::Value, "returns the 3d points of the multipoint <MPointIndex> when only 3d points exist.", py::arg("ML"), py::arg("MPointIndex"), py::arg("tabPt"));
cls_AppDef_MyLineTool.def_static("Value_", (void (*)(const AppDef_MultiLine &, const Standard_Integer, TColgp_Array1OfPnt2d &)) &AppDef_MyLineTool::Value, "returns the 2d points of the multipoint <MPointIndex> when only 2d points exist.", py::arg("ML"), py::arg("MPointIndex"), py::arg("tabPt2d"));
cls_AppDef_MyLineTool.def_static("Value_", (void (*)(const AppDef_MultiLine &, const Standard_Integer, TColgp_Array1OfPnt &, TColgp_Array1OfPnt2d &)) &AppDef_MyLineTool::Value, "returns the 3d and 2d points of the multipoint <MPointIndex>.", py::arg("ML"), py::arg("MPointIndex"), py::arg("tabPt"), py::arg("tabPt2d"));
cls_AppDef_MyLineTool.def_static("Tangency_", (Standard_Boolean (*)(const AppDef_MultiLine &, const Standard_Integer, TColgp_Array1OfVec &)) &AppDef_MyLineTool::Tangency, "returns the 3d points of the multipoint <MPointIndex> when only 3d points exist.", py::arg("ML"), py::arg("MPointIndex"), py::arg("tabV"));
cls_AppDef_MyLineTool.def_static("Tangency_", (Standard_Boolean (*)(const AppDef_MultiLine &, const Standard_Integer, TColgp_Array1OfVec2d &)) &AppDef_MyLineTool::Tangency, "returns the 2d tangency points of the multipoint <MPointIndex> only when 2d points exist.", py::arg("ML"), py::arg("MPointIndex"), py::arg("tabV2d"));
cls_AppDef_MyLineTool.def_static("Tangency_", (Standard_Boolean (*)(const AppDef_MultiLine &, const Standard_Integer, TColgp_Array1OfVec &, TColgp_Array1OfVec2d &)) &AppDef_MyLineTool::Tangency, "returns the 3d and 2d points of the multipoint <MPointIndex>.", py::arg("ML"), py::arg("MPointIndex"), py::arg("tabV"), py::arg("tabV2d"));
cls_AppDef_MyLineTool.def_static("Curvature_", (Standard_Boolean (*)(const AppDef_MultiLine &, const Standard_Integer, TColgp_Array1OfVec &)) &AppDef_MyLineTool::Curvature, "returns the 3d curvatures of the multipoint <MPointIndex> when only 3d points exist.", py::arg("ML"), py::arg("MPointIndex"), py::arg("tabV"));
cls_AppDef_MyLineTool.def_static("Curvature_", (Standard_Boolean (*)(const AppDef_MultiLine &, const Standard_Integer, TColgp_Array1OfVec2d &)) &AppDef_MyLineTool::Curvature, "returns the 2d curvatures of the multipoint <MPointIndex> only when 2d points exist.", py::arg("ML"), py::arg("MPointIndex"), py::arg("tabV2d"));
cls_AppDef_MyLineTool.def_static("Curvature_", (Standard_Boolean (*)(const AppDef_MultiLine &, const Standard_Integer, TColgp_Array1OfVec &, TColgp_Array1OfVec2d &)) &AppDef_MyLineTool::Curvature, "returns the 3d and 2d curvatures of the multipoint <MPointIndex>.", py::arg("ML"), py::arg("MPointIndex"), py::arg("tabV"), py::arg("tabV2d"));
cls_AppDef_MyLineTool.def_static("WhatStatus_", (Approx_Status (*)(const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer)) &AppDef_MyLineTool::WhatStatus, "returns NoPointsAdded", py::arg("ML"), py::arg("I1"), py::arg("I2"));
cls_AppDef_MyLineTool.def_static("MakeMLBetween_", (AppDef_MultiLine (*)(const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const Standard_Integer)) &AppDef_MyLineTool::MakeMLBetween, "Is never called in the algorithms. Nothing is done.", py::arg("ML"), py::arg("I1"), py::arg("I2"), py::arg("NbPMin"));
cls_AppDef_MyLineTool.def_static("MakeMLOneMorePoint_", (Standard_Boolean (*)(const AppDef_MultiLine &, const Standard_Integer, const Standard_Integer, const Standard_Integer, AppDef_MultiLine &)) &AppDef_MyLineTool::MakeMLOneMorePoint, "Is never called in the algorithms. Nothing is done.", py::arg("ML"), py::arg("I1"), py::arg("I2"), py::arg("indbad"), py::arg("OtherLine"));

// Enums

}