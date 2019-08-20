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
#include <Contap_HContTool.hxx>

void bind_Contap_HContTool(py::module &mod){

py::class_<Contap_HContTool, std::unique_ptr<Contap_HContTool>> cls_Contap_HContTool(mod, "Contap_HContTool", "Tool for the intersection between 2 surfaces. Regroupe pour l instant les methodes hors Adaptor3d...");

// Constructors

// Fields

// Methods
// cls_Contap_HContTool.def_static("operator new_", (void * (*)(size_t)) &Contap_HContTool::operator new, "None", py::arg("theSize"));
// cls_Contap_HContTool.def_static("operator delete_", (void (*)(void *)) &Contap_HContTool::operator delete, "None", py::arg("theAddress"));
// cls_Contap_HContTool.def_static("operator new[]_", (void * (*)(size_t)) &Contap_HContTool::operator new[], "None", py::arg("theSize"));
// cls_Contap_HContTool.def_static("operator delete[]_", (void (*)(void *)) &Contap_HContTool::operator delete[], "None", py::arg("theAddress"));
// cls_Contap_HContTool.def_static("operator new_", (void * (*)(size_t, void *)) &Contap_HContTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Contap_HContTool.def_static("operator delete_", (void (*)(void *, void *)) &Contap_HContTool::operator delete, "None", py::arg(""), py::arg(""));
cls_Contap_HContTool.def_static("NbSamplesU_", (Standard_Integer (*)(const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real, const Standard_Real)) &Contap_HContTool::NbSamplesU, "None", py::arg("S"), py::arg("u1"), py::arg("u2"));
cls_Contap_HContTool.def_static("NbSamplesV_", (Standard_Integer (*)(const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real, const Standard_Real)) &Contap_HContTool::NbSamplesV, "None", py::arg("S"), py::arg("v1"), py::arg("v2"));
cls_Contap_HContTool.def_static("NbSamplePoints_", (Standard_Integer (*)(const opencascade::handle<Adaptor3d_HSurface> &)) &Contap_HContTool::NbSamplePoints, "None", py::arg("S"));
cls_Contap_HContTool.def_static("SamplePoint_", [](const opencascade::handle<Adaptor3d_HSurface> & S, const Standard_Integer Index, Standard_Real & U, Standard_Real & V){ Contap_HContTool::SamplePoint(S, Index, U, V); return std::tuple<Standard_Real &, Standard_Real &>(U, V); }, "None", py::arg("S"), py::arg("Index"), py::arg("U"), py::arg("V"));
cls_Contap_HContTool.def_static("HasBeenSeen_", (Standard_Boolean (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &Contap_HContTool::HasBeenSeen, "Returns True if all the intersection point and edges are known on the Arc. The intersection point are given as vertices. The intersection edges are given as intervals between two vertices.", py::arg("C"));
cls_Contap_HContTool.def_static("NbSamplesOnArc_", (Standard_Integer (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &Contap_HContTool::NbSamplesOnArc, "returns the number of points which is used to make a sample on the arc. this number is a function of the Surface and the CurveOnSurface complexity.", py::arg("A"));
cls_Contap_HContTool.def_static("Bounds_", [](const opencascade::handle<Adaptor2d_HCurve2d> & C, Standard_Real & Ufirst, Standard_Real & Ulast){ Contap_HContTool::Bounds(C, Ufirst, Ulast); return std::tuple<Standard_Real &, Standard_Real &>(Ufirst, Ulast); }, "Returns the parametric limits on the arc C. These limits must be finite : they are either the real limits of the arc, for a finite arc, or a bounding box for an infinite arc.", py::arg("C"), py::arg("Ufirst"), py::arg("Ulast"));
cls_Contap_HContTool.def_static("Project_", [](const opencascade::handle<Adaptor2d_HCurve2d> & C, const gp_Pnt2d & P, Standard_Real & Paramproj, gp_Pnt2d & Ptproj){ Standard_Boolean rv = Contap_HContTool::Project(C, P, Paramproj, Ptproj); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Paramproj); }, "Projects the point P on the arc C. If the methods returns Standard_True, the projection is successful, and Paramproj is the parameter on the arc of the projected point, Ptproj is the projected Point. If the method returns Standard_False, Param proj and Ptproj are not significant.", py::arg("C"), py::arg("P"), py::arg("Paramproj"), py::arg("Ptproj"));
cls_Contap_HContTool.def_static("Tolerance_", (Standard_Real (*)(const opencascade::handle<Adaptor3d_HVertex> &, const opencascade::handle<Adaptor2d_HCurve2d> &)) &Contap_HContTool::Tolerance, "Returns the parametric tolerance used to consider that the vertex and another point meet, i-e if Abs(parameter(Vertex) - parameter(OtherPnt))<= Tolerance, the points are 'merged'.", py::arg("V"), py::arg("C"));
cls_Contap_HContTool.def_static("Parameter_", (Standard_Real (*)(const opencascade::handle<Adaptor3d_HVertex> &, const opencascade::handle<Adaptor2d_HCurve2d> &)) &Contap_HContTool::Parameter, "Returns the parameter of the vertex V on the arc A.", py::arg("V"), py::arg("C"));
cls_Contap_HContTool.def_static("NbPoints_", (Standard_Integer (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &Contap_HContTool::NbPoints, "Returns the number of intersection points on the arc A.", py::arg("C"));
cls_Contap_HContTool.def_static("Value_", [](const opencascade::handle<Adaptor2d_HCurve2d> & C, const Standard_Integer Index, gp_Pnt & Pt, Standard_Real & Tol, Standard_Real & U){ Contap_HContTool::Value(C, Index, Pt, Tol, U); return std::tuple<Standard_Real &, Standard_Real &>(Tol, U); }, "Returns the value (Pt), the tolerance (Tol), and the parameter (U) on the arc A , of the intersection point of range Index.", py::arg("C"), py::arg("Index"), py::arg("Pt"), py::arg("Tol"), py::arg("U"));
cls_Contap_HContTool.def_static("IsVertex_", (Standard_Boolean (*)(const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Integer)) &Contap_HContTool::IsVertex, "Returns True if the intersection point of range Index corresponds with a vertex on the arc A.", py::arg("C"), py::arg("Index"));
cls_Contap_HContTool.def_static("Vertex_", (void (*)(const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Integer, opencascade::handle<Adaptor3d_HVertex> &)) &Contap_HContTool::Vertex, "When IsVertex returns True, this method returns the vertex on the arc A.", py::arg("C"), py::arg("Index"), py::arg("V"));
cls_Contap_HContTool.def_static("NbSegments_", (Standard_Integer (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &Contap_HContTool::NbSegments, "returns the number of part of A solution of the of intersection problem.", py::arg("C"));
cls_Contap_HContTool.def_static("HasFirstPoint_", [](const opencascade::handle<Adaptor2d_HCurve2d> & C, const Standard_Integer Index, Standard_Integer & IndFirst){ Standard_Boolean rv = Contap_HContTool::HasFirstPoint(C, Index, IndFirst); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, IndFirst); }, "Returns True when the segment of range Index is not open at the left side. In that case, IndFirst is the range in the list intersection points (see NbPoints) of the one which defines the left bound of the segment. Otherwise, the method has to return False, and IndFirst has no meaning.", py::arg("C"), py::arg("Index"), py::arg("IndFirst"));
cls_Contap_HContTool.def_static("HasLastPoint_", [](const opencascade::handle<Adaptor2d_HCurve2d> & C, const Standard_Integer Index, Standard_Integer & IndLast){ Standard_Boolean rv = Contap_HContTool::HasLastPoint(C, Index, IndLast); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, IndLast); }, "Returns True when the segment of range Index is not open at the right side. In that case, IndLast is the range in the list intersection points (see NbPoints) of the one which defines the right bound of the segment. Otherwise, the method has to return False, and IndLast has no meaning.", py::arg("C"), py::arg("Index"), py::arg("IndLast"));
cls_Contap_HContTool.def_static("IsAllSolution_", (Standard_Boolean (*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &Contap_HContTool::IsAllSolution, "Returns True when the whole restriction is solution of the intersection problem.", py::arg("C"));

// Enums

}