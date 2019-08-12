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
#include <gp_Pnt2d.hxx>
#include <Standard_Handle.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <Adaptor2d_HCurve2d.hxx>
#include <Adaptor3d_HVertex.hxx>
#include <BRepBlend_BlendTool.hxx>

void bind_BRepBlend_BlendTool(py::module &mod){

py::class_<BRepBlend_BlendTool, std::unique_ptr<BRepBlend_BlendTool, Deleter<BRepBlend_BlendTool>>> cls_BRepBlend_BlendTool(mod, "BRepBlend_BlendTool", "None");

// Constructors

// Fields

// Methods
// cls_BRepBlend_BlendTool.def_static("operator new_", (void * (*)(size_t)) &BRepBlend_BlendTool::operator new, "None", py::arg("theSize"));
// cls_BRepBlend_BlendTool.def_static("operator delete_", (void (*)(void *)) &BRepBlend_BlendTool::operator delete, "None", py::arg("theAddress"));
// cls_BRepBlend_BlendTool.def_static("operator new[]_", (void * (*)(size_t)) &BRepBlend_BlendTool::operator new[], "None", py::arg("theSize"));
// cls_BRepBlend_BlendTool.def_static("operator delete[]_", (void (*)(void *)) &BRepBlend_BlendTool::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBlend_BlendTool.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBlend_BlendTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBlend_BlendTool.def_static("operator delete_", (void (*)(void *, void *)) &BRepBlend_BlendTool::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBlend_BlendTool.def_static("Project_", [](const gp_Pnt2d & P, const opencascade::handle<Adaptor3d_HSurface> & S, const opencascade::handle<Adaptor2d_HCurve2d> & C, Standard_Real & Paramproj, Standard_Real & Dist){ Standard_Boolean rv = BRepBlend_BlendTool::Project(P, S, C, Paramproj, Dist); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, Paramproj, Dist); }, "Projects the point P on the arc C. If the methods returns Standard_True, the projection is successful, and Paramproj is the parameter on the arc of the projected point, Dist is the distance between P and the curve.. If the method returns Standard_False, Param proj and Dist are not significant.", py::arg("P"), py::arg("S"), py::arg("C"), py::arg("Paramproj"), py::arg("Dist"));
cls_BRepBlend_BlendTool.def_static("Inters_", [](const gp_Pnt2d & P1, const gp_Pnt2d & P2, const opencascade::handle<Adaptor3d_HSurface> & S, const opencascade::handle<Adaptor2d_HCurve2d> & C, Standard_Real & Param, Standard_Real & Dist){ Standard_Boolean rv = BRepBlend_BlendTool::Inters(P1, P2, S, C, Param, Dist); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, Param, Dist); }, "None", py::arg("P1"), py::arg("P2"), py::arg("S"), py::arg("C"), py::arg("Param"), py::arg("Dist"));
cls_BRepBlend_BlendTool.def_static("Parameter_", (Standard_Real (*)(const opencascade::handle<Adaptor3d_HVertex> &, const opencascade::handle<Adaptor2d_HCurve2d> &)) &BRepBlend_BlendTool::Parameter, "Returns the parameter of the vertex V on the edge A.", py::arg("V"), py::arg("A"));
cls_BRepBlend_BlendTool.def_static("Tolerance_", (Standard_Real (*)(const opencascade::handle<Adaptor3d_HVertex> &, const opencascade::handle<Adaptor2d_HCurve2d> &)) &BRepBlend_BlendTool::Tolerance, "Returns the parametric tolerance on the arc A used to consider that the vertex and another point meet, i-e if Abs(Parameter(Vertex)-Parameter(OtherPnt))<= Tolerance, the points are 'merged'.", py::arg("V"), py::arg("A"));
cls_BRepBlend_BlendTool.def_static("SingularOnUMin_", (Standard_Boolean (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &BRepBlend_BlendTool::SingularOnUMin, "None", py::arg("S"));
cls_BRepBlend_BlendTool.def_static("SingularOnUMax_", (Standard_Boolean (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &BRepBlend_BlendTool::SingularOnUMax, "None", py::arg("S"));
cls_BRepBlend_BlendTool.def_static("SingularOnVMin_", (Standard_Boolean (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &BRepBlend_BlendTool::SingularOnVMin, "None", py::arg("S"));
cls_BRepBlend_BlendTool.def_static("SingularOnVMax_", (Standard_Boolean (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &BRepBlend_BlendTool::SingularOnVMax, "None", py::arg("S"));
cls_BRepBlend_BlendTool.def_static("NbSamplesU_", (Standard_Integer (*)(const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real, const Standard_Real)) &BRepBlend_BlendTool::NbSamplesU, "None", py::arg("S"), py::arg("u1"), py::arg("u2"));
cls_BRepBlend_BlendTool.def_static("NbSamplesV_", (Standard_Integer (*)(const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real, const Standard_Real)) &BRepBlend_BlendTool::NbSamplesV, "None", py::arg("S"), py::arg("v1"), py::arg("v2"));
cls_BRepBlend_BlendTool.def_static("Bounds_", [](const opencascade::handle<Adaptor2d_HCurve2d> & C, Standard_Real & Ufirst, Standard_Real & Ulast){ BRepBlend_BlendTool::Bounds(C, Ufirst, Ulast); return std::tuple<Standard_Real &, Standard_Real &>(Ufirst, Ulast); }, "Returns the parametric limits on the arc C. These limits must be finite : they are either the real limits of the arc, for a finite arc, or a bounding box for an infinite arc.", py::arg("C"), py::arg("Ufirst"), py::arg("Ulast"));
cls_BRepBlend_BlendTool.def_static("CurveOnSurf_", (opencascade::handle<Adaptor2d_HCurve2d> (*)(const opencascade::handle<Adaptor2d_HCurve2d> &, const opencascade::handle<Adaptor3d_HSurface> &)) &BRepBlend_BlendTool::CurveOnSurf, "None", py::arg("C"), py::arg("S"));

// Enums

}