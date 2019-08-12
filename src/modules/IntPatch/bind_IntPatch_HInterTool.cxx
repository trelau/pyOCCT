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
#include <Adaptor3d_HSurface.hxx>
#include <Adaptor2d_HCurve2d.hxx>
#include <gp_Pnt2d.hxx>
#include <Adaptor3d_HVertex.hxx>
#include <gp_Pnt.hxx>
#include <IntPatch_HInterTool.hxx>

void bind_IntPatch_HInterTool(py::module &mod){

py::class_<IntPatch_HInterTool, std::unique_ptr<IntPatch_HInterTool, Deleter<IntPatch_HInterTool>>> cls_IntPatch_HInterTool(mod, "IntPatch_HInterTool", "Tool for the intersection between 2 surfaces. Regroupe pour l instant les methodes hors Adaptor3d...");

// Constructors
cls_IntPatch_HInterTool.def(py::init<>());

// Fields

// Methods
// cls_IntPatch_HInterTool.def_static("operator new_", (void * (*)(size_t)) &IntPatch_HInterTool::operator new, "None", py::arg("theSize"));
// cls_IntPatch_HInterTool.def_static("operator delete_", (void (*)(void *)) &IntPatch_HInterTool::operator delete, "None", py::arg("theAddress"));
// cls_IntPatch_HInterTool.def_static("operator new[]_", (void * (*)(size_t)) &IntPatch_HInterTool::operator new[], "None", py::arg("theSize"));
// cls_IntPatch_HInterTool.def_static("operator delete[]_", (void (*)(void *)) &IntPatch_HInterTool::operator delete[], "None", py::arg("theAddress"));
// cls_IntPatch_HInterTool.def_static("operator new_", (void * (*)(size_t, void *)) &IntPatch_HInterTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntPatch_HInterTool.def_static("operator delete_", (void (*)(void *, void *)) &IntPatch_HInterTool::operator delete, "None", py::arg(""), py::arg(""));
cls_IntPatch_HInterTool.def_static("SingularOnUMin_", (Standard_Boolean (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &IntPatch_HInterTool::SingularOnUMin, "None", py::arg("S"));
cls_IntPatch_HInterTool.def_static("SingularOnUMax_", (Standard_Boolean (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &IntPatch_HInterTool::SingularOnUMax, "None", py::arg("S"));
cls_IntPatch_HInterTool.def_static("SingularOnVMin_", (Standard_Boolean (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &IntPatch_HInterTool::SingularOnVMin, "None", py::arg("S"));
cls_IntPatch_HInterTool.def_static("SingularOnVMax_", (Standard_Boolean (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &IntPatch_HInterTool::SingularOnVMax, "None", py::arg("S"));
cls_IntPatch_HInterTool.def_static("NbSamplesU_", (Standard_Integer (*)(const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real, const Standard_Real)) &IntPatch_HInterTool::NbSamplesU, "None", py::arg("S"), py::arg("u1"), py::arg("u2"));
cls_IntPatch_HInterTool.def_static("NbSamplesV_", (Standard_Integer (*)(const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real, const Standard_Real)) &IntPatch_HInterTool::NbSamplesV, "None", py::arg("S"), py::arg("v1"), py::arg("v2"));
cls_IntPatch_HInterTool.def("NbSamplePoints", (Standard_Integer (IntPatch_HInterTool::*)(const opencascade::handle<Adaptor3d_HSurface> &)) &IntPatch_HInterTool::NbSamplePoints, "None", py::arg("S"));
cls_IntPatch_HInterTool.def("SamplePoint", [](IntPatch_HInterTool &self, const opencascade::handle<Adaptor3d_HSurface> & S, const Standard_Integer Index, Standard_Real & U, Standard_Real & V){ self.SamplePoint(S, Index, U, V); return std::tuple<Standard_Real &, Standard_Real &>(U, V); }, "None", py::arg("S"), py::arg("Index"), py::arg("U"), py::arg("V"));
cls_IntPatch_HInterTool.def_static("HasBeenSeen_", (Standard_Boolean (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &IntPatch_HInterTool::HasBeenSeen, "Returns True if all the intersection point and edges are known on the Arc. The intersection point are given as vertices. The intersection edges are given as intervals between two vertices.", py::arg("C"));
cls_IntPatch_HInterTool.def_static("NbSamplesOnArc_", (Standard_Integer (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &IntPatch_HInterTool::NbSamplesOnArc, "returns the number of points which is used to make a sample on the arc. this number is a function of the Surface and the CurveOnSurface complexity.", py::arg("A"));
cls_IntPatch_HInterTool.def_static("Bounds_", [](const opencascade::handle<Adaptor2d_HCurve2d> & C, Standard_Real & Ufirst, Standard_Real & Ulast){ IntPatch_HInterTool::Bounds(C, Ufirst, Ulast); return std::tuple<Standard_Real &, Standard_Real &>(Ufirst, Ulast); }, "Returns the parametric limits on the arc C. These limits must be finite : they are either the real limits of the arc, for a finite arc, or a bounding box for an infinite arc.", py::arg("C"), py::arg("Ufirst"), py::arg("Ulast"));
cls_IntPatch_HInterTool.def_static("Project_", [](const opencascade::handle<Adaptor2d_HCurve2d> & C, const gp_Pnt2d & P, Standard_Real & Paramproj, gp_Pnt2d & Ptproj){ Standard_Boolean rv = IntPatch_HInterTool::Project(C, P, Paramproj, Ptproj); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Paramproj); }, "Projects the point P on the arc C. If the methods returns Standard_True, the projection is successful, and Paramproj is the parameter on the arc of the projected point, Ptproj is the projected Point. If the method returns Standard_False, Param proj and Ptproj are not significant.", py::arg("C"), py::arg("P"), py::arg("Paramproj"), py::arg("Ptproj"));
cls_IntPatch_HInterTool.def_static("Tolerance_", (Standard_Real (*)(const opencascade::handle<Adaptor3d_HVertex> &, const opencascade::handle<Adaptor2d_HCurve2d> &)) &IntPatch_HInterTool::Tolerance, "Returns the parametric tolerance used to consider that the vertex and another point meet, i-e if Abs(parameter(Vertex) - parameter(OtherPnt))<= Tolerance, the points are 'merged'.", py::arg("V"), py::arg("C"));
cls_IntPatch_HInterTool.def_static("Parameter_", (Standard_Real (*)(const opencascade::handle<Adaptor3d_HVertex> &, const opencascade::handle<Adaptor2d_HCurve2d> &)) &IntPatch_HInterTool::Parameter, "Returns the parameter of the vertex V on the arc A.", py::arg("V"), py::arg("C"));
cls_IntPatch_HInterTool.def_static("NbPoints_", (Standard_Integer (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &IntPatch_HInterTool::NbPoints, "Returns the number of intersection points on the arc A.", py::arg("C"));
cls_IntPatch_HInterTool.def_static("Value_", [](const opencascade::handle<Adaptor2d_HCurve2d> & C, const Standard_Integer Index, gp_Pnt & Pt, Standard_Real & Tol, Standard_Real & U){ IntPatch_HInterTool::Value(C, Index, Pt, Tol, U); return std::tuple<Standard_Real &, Standard_Real &>(Tol, U); }, "Returns the value (Pt), the tolerance (Tol), and the parameter (U) on the arc A , of the intersection point of range Index.", py::arg("C"), py::arg("Index"), py::arg("Pt"), py::arg("Tol"), py::arg("U"));
cls_IntPatch_HInterTool.def_static("IsVertex_", (Standard_Boolean (*)(const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Integer)) &IntPatch_HInterTool::IsVertex, "Returns True if the intersection point of range Index corresponds with a vertex on the arc A.", py::arg("C"), py::arg("Index"));
cls_IntPatch_HInterTool.def_static("Vertex_", (void (*)(const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Integer, opencascade::handle<Adaptor3d_HVertex> &)) &IntPatch_HInterTool::Vertex, "When IsVertex returns True, this method returns the vertex on the arc A.", py::arg("C"), py::arg("Index"), py::arg("V"));
cls_IntPatch_HInterTool.def_static("NbSegments_", (Standard_Integer (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &IntPatch_HInterTool::NbSegments, "returns the number of part of A solution of the of intersection problem.", py::arg("C"));
cls_IntPatch_HInterTool.def_static("HasFirstPoint_", [](const opencascade::handle<Adaptor2d_HCurve2d> & C, const Standard_Integer Index, Standard_Integer & IndFirst){ Standard_Boolean rv = IntPatch_HInterTool::HasFirstPoint(C, Index, IndFirst); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, IndFirst); }, "Returns True when the segment of range Index is not open at the left side. In that case, IndFirst is the range in the list intersection points (see NbPoints) of the one which defines the left bound of the segment. Otherwise, the method has to return False, and IndFirst has no meaning.", py::arg("C"), py::arg("Index"), py::arg("IndFirst"));
cls_IntPatch_HInterTool.def_static("HasLastPoint_", [](const opencascade::handle<Adaptor2d_HCurve2d> & C, const Standard_Integer Index, Standard_Integer & IndLast){ Standard_Boolean rv = IntPatch_HInterTool::HasLastPoint(C, Index, IndLast); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, IndLast); }, "Returns True when the segment of range Index is not open at the right side. In that case, IndLast is the range in the list intersection points (see NbPoints) of the one which defines the right bound of the segment. Otherwise, the method has to return False, and IndLast has no meaning.", py::arg("C"), py::arg("Index"), py::arg("IndLast"));
cls_IntPatch_HInterTool.def_static("IsAllSolution_", (Standard_Boolean (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &IntPatch_HInterTool::IsAllSolution, "Returns True when the whole restriction is solution of the intersection problem.", py::arg("C"));

// Enums

}