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
#include <Standard_Handle.hxx>
#include <StepGeom_SurfaceCurve.hxx>
#include <StepGeom_Surface.hxx>
#include <StepGeom_Pcurve.hxx>
#include <StepShape_Edge.hxx>
#include <StepShape_EdgeLoop.hxx>
#include <Geom_Curve.hxx>
#include <StepToTopoDS_GeometricTool.hxx>

void bind_StepToTopoDS_GeometricTool(py::module &mod){

py::class_<StepToTopoDS_GeometricTool> cls_StepToTopoDS_GeometricTool(mod, "StepToTopoDS_GeometricTool", "This class contains some algorithmic services specific to the mapping STEP to CAS.CADE");

// Constructors

// Fields

// Methods
// cls_StepToTopoDS_GeometricTool.def_static("operator new_", (void * (*)(size_t)) &StepToTopoDS_GeometricTool::operator new, "None", py::arg("theSize"));
// cls_StepToTopoDS_GeometricTool.def_static("operator delete_", (void (*)(void *)) &StepToTopoDS_GeometricTool::operator delete, "None", py::arg("theAddress"));
// cls_StepToTopoDS_GeometricTool.def_static("operator new[]_", (void * (*)(size_t)) &StepToTopoDS_GeometricTool::operator new[], "None", py::arg("theSize"));
// cls_StepToTopoDS_GeometricTool.def_static("operator delete[]_", (void (*)(void *)) &StepToTopoDS_GeometricTool::operator delete[], "None", py::arg("theAddress"));
// cls_StepToTopoDS_GeometricTool.def_static("operator new_", (void * (*)(size_t, void *)) &StepToTopoDS_GeometricTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepToTopoDS_GeometricTool.def_static("operator delete_", (void (*)(void *, void *)) &StepToTopoDS_GeometricTool::operator delete, "None", py::arg(""), py::arg(""));
cls_StepToTopoDS_GeometricTool.def_static("PCurve_", [](const opencascade::handle<StepGeom_SurfaceCurve> & a0, const opencascade::handle<StepGeom_Surface> & a1, opencascade::handle<StepGeom_Pcurve> & a2) -> Standard_Integer { return StepToTopoDS_GeometricTool::PCurve(a0, a1, a2); });
cls_StepToTopoDS_GeometricTool.def_static("PCurve_", (Standard_Integer (*)(const opencascade::handle<StepGeom_SurfaceCurve> &, const opencascade::handle<StepGeom_Surface> &, opencascade::handle<StepGeom_Pcurve> &, const Standard_Integer)) &StepToTopoDS_GeometricTool::PCurve, "None", py::arg("SC"), py::arg("S"), py::arg("PC"), py::arg("last"));
cls_StepToTopoDS_GeometricTool.def_static("IsSeamCurve_", (Standard_Boolean (*)(const opencascade::handle<StepGeom_SurfaceCurve> &, const opencascade::handle<StepGeom_Surface> &, const opencascade::handle<StepShape_Edge> &, const opencascade::handle<StepShape_EdgeLoop> &)) &StepToTopoDS_GeometricTool::IsSeamCurve, "None", py::arg("SC"), py::arg("S"), py::arg("E"), py::arg("EL"));
cls_StepToTopoDS_GeometricTool.def_static("IsLikeSeam_", (Standard_Boolean (*)(const opencascade::handle<StepGeom_SurfaceCurve> &, const opencascade::handle<StepGeom_Surface> &, const opencascade::handle<StepShape_Edge> &, const opencascade::handle<StepShape_EdgeLoop> &)) &StepToTopoDS_GeometricTool::IsLikeSeam, "None", py::arg("SC"), py::arg("S"), py::arg("E"), py::arg("EL"));
cls_StepToTopoDS_GeometricTool.def_static("UpdateParam3d_", [](const opencascade::handle<Geom_Curve> & C, Standard_Real & w1, Standard_Real & w2, const Standard_Real preci){ Standard_Boolean rv = StepToTopoDS_GeometricTool::UpdateParam3d(C, w1, w2, preci); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, w1, w2); }, "None", py::arg("C"), py::arg("w1"), py::arg("w2"), py::arg("preci"));

// Enums

}