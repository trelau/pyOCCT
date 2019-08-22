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
#include <TopOpeBRepTool_OutCurveType.hxx>
#include <TopOpeBRepTool_GeomTool.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Curve.hxx>
#include <Geom2d_Curve.hxx>
#include <TopoDS_Shape.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <TopOpeBRepTool_CurveTool.hxx>

void bind_TopOpeBRepTool_CurveTool(py::module &mod){

py::class_<TopOpeBRepTool_CurveTool> cls_TopOpeBRepTool_CurveTool(mod, "TopOpeBRepTool_CurveTool", "None");

// Constructors
cls_TopOpeBRepTool_CurveTool.def(py::init<>());
cls_TopOpeBRepTool_CurveTool.def(py::init<const TopOpeBRepTool_OutCurveType>(), py::arg("OCT"));
cls_TopOpeBRepTool_CurveTool.def(py::init<const TopOpeBRepTool_GeomTool &>(), py::arg("GT"));

// Fields

// Methods
// cls_TopOpeBRepTool_CurveTool.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepTool_CurveTool::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepTool_CurveTool.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepTool_CurveTool::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_CurveTool.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepTool_CurveTool::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepTool_CurveTool.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepTool_CurveTool::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_CurveTool.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepTool_CurveTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepTool_CurveTool.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepTool_CurveTool::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepTool_CurveTool.def("ChangeGeomTool", (TopOpeBRepTool_GeomTool & (TopOpeBRepTool_CurveTool::*)()) &TopOpeBRepTool_CurveTool::ChangeGeomTool, "None");
cls_TopOpeBRepTool_CurveTool.def("GetGeomTool", (const TopOpeBRepTool_GeomTool & (TopOpeBRepTool_CurveTool::*)() const) &TopOpeBRepTool_CurveTool::GetGeomTool, "None");
cls_TopOpeBRepTool_CurveTool.def("SetGeomTool", (void (TopOpeBRepTool_CurveTool::*)(const TopOpeBRepTool_GeomTool &)) &TopOpeBRepTool_CurveTool::SetGeomTool, "None", py::arg("GT"));
cls_TopOpeBRepTool_CurveTool.def("MakeCurves", [](TopOpeBRepTool_CurveTool &self, const Standard_Real min, const Standard_Real max, const opencascade::handle<Geom_Curve> & C3D, const opencascade::handle<Geom2d_Curve> & PC1, const opencascade::handle<Geom2d_Curve> & PC2, const TopoDS_Shape & S1, const TopoDS_Shape & S2, opencascade::handle<Geom_Curve> & C3DN, opencascade::handle<Geom2d_Curve> & PC1N, opencascade::handle<Geom2d_Curve> & PC2N, Standard_Real & Tol3d, Standard_Real & Tol2d){ Standard_Boolean rv = self.MakeCurves(min, max, C3D, PC1, PC2, S1, S2, C3DN, PC1N, PC2N, Tol3d, Tol2d); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, Tol3d, Tol2d); }, "Approximates curves. Returns False in the case of failure", py::arg("min"), py::arg("max"), py::arg("C3D"), py::arg("PC1"), py::arg("PC2"), py::arg("S1"), py::arg("S2"), py::arg("C3DN"), py::arg("PC1N"), py::arg("PC2N"), py::arg("Tol3d"), py::arg("Tol2d"));
cls_TopOpeBRepTool_CurveTool.def_static("MakeBSpline1fromPnt_", (opencascade::handle<Geom_Curve> (*)(const TColgp_Array1OfPnt &)) &TopOpeBRepTool_CurveTool::MakeBSpline1fromPnt, "None", py::arg("P"));
cls_TopOpeBRepTool_CurveTool.def_static("MakeBSpline1fromPnt2d_", (opencascade::handle<Geom2d_Curve> (*)(const TColgp_Array1OfPnt2d &)) &TopOpeBRepTool_CurveTool::MakeBSpline1fromPnt2d, "None", py::arg("P"));
cls_TopOpeBRepTool_CurveTool.def_static("IsProjectable_", (Standard_Boolean (*)(const TopoDS_Shape &, const opencascade::handle<Geom_Curve> &)) &TopOpeBRepTool_CurveTool::IsProjectable, "None", py::arg("S"), py::arg("C"));
cls_TopOpeBRepTool_CurveTool.def_static("MakePCurveOnFace_", [](const TopoDS_Shape & S, const opencascade::handle<Geom_Curve> & C, Standard_Real & TolReached2d, const Standard_Real first, const Standard_Real last){ opencascade::handle<Geom2d_Curve> rv = TopOpeBRepTool_CurveTool::MakePCurveOnFace(S, C, TolReached2d, first, last); return std::tuple<opencascade::handle<Geom2d_Curve>, Standard_Real &>(rv, TolReached2d); }, "None", py::arg("S"), py::arg("C"), py::arg("TolReached2d"), py::arg("first"), py::arg("last"));

// Enums

}