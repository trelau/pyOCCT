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
#include <Adaptor3d_HSurface.hxx>
#include <IntPatch_Polyhedron.hxx>
#include <Adaptor3d_TopolTool.hxx>
#include <Standard_TypeDef.hxx>
#include <IntSurf_ListOfPntOn2S.hxx>
#include <IntPatch_Line.hxx>
#include <IntPatch_PrmPrmIntersection_T3Bits.hxx>
#include <IntSurf_LineOn2S.hxx>
#include <IntPatch_SequenceOfLine.hxx>
#include <IntPatch_PrmPrmIntersection.hxx>

void bind_IntPatch_PrmPrmIntersection(py::module &mod){

py::class_<IntPatch_PrmPrmIntersection, std::unique_ptr<IntPatch_PrmPrmIntersection>> cls_IntPatch_PrmPrmIntersection(mod, "IntPatch_PrmPrmIntersection", "Implementation of the Intersection between two bi-parametrised surfaces.");

// Constructors
cls_IntPatch_PrmPrmIntersection.def(py::init<>());

// Fields

// Methods
// cls_IntPatch_PrmPrmIntersection.def_static("operator new_", (void * (*)(size_t)) &IntPatch_PrmPrmIntersection::operator new, "None", py::arg("theSize"));
// cls_IntPatch_PrmPrmIntersection.def_static("operator delete_", (void (*)(void *)) &IntPatch_PrmPrmIntersection::operator delete, "None", py::arg("theAddress"));
// cls_IntPatch_PrmPrmIntersection.def_static("operator new[]_", (void * (*)(size_t)) &IntPatch_PrmPrmIntersection::operator new[], "None", py::arg("theSize"));
// cls_IntPatch_PrmPrmIntersection.def_static("operator delete[]_", (void (*)(void *)) &IntPatch_PrmPrmIntersection::operator delete[], "None", py::arg("theAddress"));
// cls_IntPatch_PrmPrmIntersection.def_static("operator new_", (void * (*)(size_t, void *)) &IntPatch_PrmPrmIntersection::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntPatch_PrmPrmIntersection.def_static("operator delete_", (void (*)(void *, void *)) &IntPatch_PrmPrmIntersection::operator delete, "None", py::arg(""), py::arg(""));
cls_IntPatch_PrmPrmIntersection.def("Perform", (void (IntPatch_PrmPrmIntersection::*)(const opencascade::handle<Adaptor3d_HSurface> &, const IntPatch_Polyhedron &, const opencascade::handle<Adaptor3d_TopolTool> &, const opencascade::handle<Adaptor3d_HSurface> &, const IntPatch_Polyhedron &, const opencascade::handle<Adaptor3d_TopolTool> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &IntPatch_PrmPrmIntersection::Perform, "Performs the intersection between <Caro1> and <Caro2>. Associated Polyhedrons <Polyhedron1> and <Polyhedron2> are given.", py::arg("Caro1"), py::arg("Polyhedron1"), py::arg("Domain1"), py::arg("Caro2"), py::arg("Polyhedron2"), py::arg("Domain2"), py::arg("TolTangency"), py::arg("Epsilon"), py::arg("Deflection"), py::arg("Increment"));
cls_IntPatch_PrmPrmIntersection.def("Perform", (void (IntPatch_PrmPrmIntersection::*)(const opencascade::handle<Adaptor3d_HSurface> &, const IntPatch_Polyhedron &, const opencascade::handle<Adaptor3d_TopolTool> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &IntPatch_PrmPrmIntersection::Perform, "None", py::arg("Caro1"), py::arg("Polyhedron1"), py::arg("Domain1"), py::arg("TolTangency"), py::arg("Epsilon"), py::arg("Deflection"), py::arg("Increment"));
cls_IntPatch_PrmPrmIntersection.def("Perform", [](IntPatch_PrmPrmIntersection &self, const opencascade::handle<Adaptor3d_HSurface> & a0, const opencascade::handle<Adaptor3d_TopolTool> & a1, const opencascade::handle<Adaptor3d_HSurface> & a2, const opencascade::handle<Adaptor3d_TopolTool> & a3, const Standard_Real a4, const Standard_Real a5, const Standard_Real a6, const Standard_Real a7) -> void { return self.Perform(a0, a1, a2, a3, a4, a5, a6, a7); });
cls_IntPatch_PrmPrmIntersection.def("Perform", (void (IntPatch_PrmPrmIntersection::*)(const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean)) &IntPatch_PrmPrmIntersection::Perform, "Performs the intersection between <Caro1> and <Caro2>. The method computes the polyhedron on each surface.", py::arg("Caro1"), py::arg("Domain1"), py::arg("Caro2"), py::arg("Domain2"), py::arg("TolTangency"), py::arg("Epsilon"), py::arg("Deflection"), py::arg("Increment"), py::arg("ClearFlag"));
cls_IntPatch_PrmPrmIntersection.def("Perform", (void (IntPatch_PrmPrmIntersection::*)(const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, IntSurf_ListOfPntOn2S &)) &IntPatch_PrmPrmIntersection::Perform, "Performs the intersection between <Caro1> and <Caro2>. The method computes the polyhedron on each surface.", py::arg("Caro1"), py::arg("Domain1"), py::arg("Caro2"), py::arg("Domain2"), py::arg("TolTangency"), py::arg("Epsilon"), py::arg("Deflection"), py::arg("Increment"), py::arg("ListOfPnts"));
cls_IntPatch_PrmPrmIntersection.def("Perform", (void (IntPatch_PrmPrmIntersection::*)(const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &IntPatch_PrmPrmIntersection::Perform, "Performs the intersection between <Caro1> and <Caro2>. The method computes the polyhedron on each surface.", py::arg("Caro1"), py::arg("Domain1"), py::arg("Caro2"), py::arg("Domain2"), py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"), py::arg("TolTangency"), py::arg("Epsilon"), py::arg("Deflection"), py::arg("Increment"));
cls_IntPatch_PrmPrmIntersection.def("Perform", (void (IntPatch_PrmPrmIntersection::*)(const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &IntPatch_PrmPrmIntersection::Perform, "Performs the intersection between <Caro1> and <Caro2>. The method computes the polyhedron on each surface.", py::arg("Caro1"), py::arg("Domain1"), py::arg("TolTangency"), py::arg("Epsilon"), py::arg("Deflection"), py::arg("Increment"));
cls_IntPatch_PrmPrmIntersection.def("Perform", (void (IntPatch_PrmPrmIntersection::*)(const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const opencascade::handle<Adaptor3d_HSurface> &, const IntPatch_Polyhedron &, const opencascade::handle<Adaptor3d_TopolTool> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &IntPatch_PrmPrmIntersection::Perform, "Performs the intersection between <Caro1> and <Caro2>.", py::arg("Caro1"), py::arg("Domain1"), py::arg("Caro2"), py::arg("Polyhedron2"), py::arg("Domain2"), py::arg("TolTangency"), py::arg("Epsilon"), py::arg("Deflection"), py::arg("Increment"));
cls_IntPatch_PrmPrmIntersection.def("Perform", (void (IntPatch_PrmPrmIntersection::*)(const opencascade::handle<Adaptor3d_HSurface> &, const IntPatch_Polyhedron &, const opencascade::handle<Adaptor3d_TopolTool> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &IntPatch_PrmPrmIntersection::Perform, "Performs the intersection between <Caro1> and <Caro2>.", py::arg("Caro1"), py::arg("Polyhedron1"), py::arg("Domain1"), py::arg("Caro2"), py::arg("Domain2"), py::arg("TolTangency"), py::arg("Epsilon"), py::arg("Deflection"), py::arg("Increment"));
cls_IntPatch_PrmPrmIntersection.def("IsDone", (Standard_Boolean (IntPatch_PrmPrmIntersection::*)() const) &IntPatch_PrmPrmIntersection::IsDone, "Returns true if the calculus was succesfull.");
cls_IntPatch_PrmPrmIntersection.def("IsEmpty", (Standard_Boolean (IntPatch_PrmPrmIntersection::*)() const) &IntPatch_PrmPrmIntersection::IsEmpty, "Returns true if the is no intersection.");
cls_IntPatch_PrmPrmIntersection.def("NbLines", (Standard_Integer (IntPatch_PrmPrmIntersection::*)() const) &IntPatch_PrmPrmIntersection::NbLines, "Returns the number of intersection lines.");
cls_IntPatch_PrmPrmIntersection.def("Line", (const opencascade::handle<IntPatch_Line> & (IntPatch_PrmPrmIntersection::*)(const Standard_Integer) const) &IntPatch_PrmPrmIntersection::Line, "Returns the line of range Index. An exception is raised if Index<=0 or Index>NbLine.", py::arg("Index"));
cls_IntPatch_PrmPrmIntersection.def("NewLine", (opencascade::handle<IntPatch_Line> (IntPatch_PrmPrmIntersection::*)(const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer) const) &IntPatch_PrmPrmIntersection::NewLine, "Computes about <NbPoints> Intersection Points on the Line <IndexLine> between the Points of Index <LowPoint> and <HighPoint>.", py::arg("Caro1"), py::arg("Caro2"), py::arg("IndexLine"), py::arg("LowPoint"), py::arg("HighPoint"), py::arg("NbPoints"));
cls_IntPatch_PrmPrmIntersection.def("GrilleInteger", (Standard_Integer (IntPatch_PrmPrmIntersection::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer) const) &IntPatch_PrmPrmIntersection::GrilleInteger, "None", py::arg("ix"), py::arg("iy"), py::arg("iz"));
cls_IntPatch_PrmPrmIntersection.def("IntegerGrille", [](IntPatch_PrmPrmIntersection &self, const Standard_Integer t, Standard_Integer & ix, Standard_Integer & iy, Standard_Integer & iz){ self.IntegerGrille(t, ix, iy, iz); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &>(ix, iy, iz); }, "None", py::arg("t"), py::arg("ix"), py::arg("iy"), py::arg("iz"));
cls_IntPatch_PrmPrmIntersection.def("DansGrille", (Standard_Integer (IntPatch_PrmPrmIntersection::*)(const Standard_Integer) const) &IntPatch_PrmPrmIntersection::DansGrille, "None", py::arg("t"));
cls_IntPatch_PrmPrmIntersection.def("NbPointsGrille", (Standard_Integer (IntPatch_PrmPrmIntersection::*)() const) &IntPatch_PrmPrmIntersection::NbPointsGrille, "None");
cls_IntPatch_PrmPrmIntersection.def("RemplitLin", (void (IntPatch_PrmPrmIntersection::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, IntPatch_PrmPrmIntersection_T3Bits &) const) &IntPatch_PrmPrmIntersection::RemplitLin, "None", py::arg("x1"), py::arg("y1"), py::arg("z1"), py::arg("x2"), py::arg("y2"), py::arg("z2"), py::arg("Map"));
cls_IntPatch_PrmPrmIntersection.def("RemplitTri", (void (IntPatch_PrmPrmIntersection::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, IntPatch_PrmPrmIntersection_T3Bits &) const) &IntPatch_PrmPrmIntersection::RemplitTri, "None", py::arg("x1"), py::arg("y1"), py::arg("z1"), py::arg("x2"), py::arg("y2"), py::arg("z2"), py::arg("x3"), py::arg("y3"), py::arg("z3"), py::arg("Map"));
cls_IntPatch_PrmPrmIntersection.def("Remplit", (void (IntPatch_PrmPrmIntersection::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, IntPatch_PrmPrmIntersection_T3Bits &) const) &IntPatch_PrmPrmIntersection::Remplit, "None", py::arg("a"), py::arg("b"), py::arg("c"), py::arg("Map"));
cls_IntPatch_PrmPrmIntersection.def("CodeReject", (Standard_Integer (IntPatch_PrmPrmIntersection::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real) const) &IntPatch_PrmPrmIntersection::CodeReject, "None", py::arg("x1"), py::arg("y1"), py::arg("z1"), py::arg("x2"), py::arg("y2"), py::arg("z2"), py::arg("x3"), py::arg("y3"), py::arg("z3"));
cls_IntPatch_PrmPrmIntersection.def("PointDepart", (void (IntPatch_PrmPrmIntersection::*)(opencascade::handle<IntSurf_LineOn2S> &, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Integer, const Standard_Integer, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Integer, const Standard_Integer) const) &IntPatch_PrmPrmIntersection::PointDepart, "None", py::arg("LineOn2S"), py::arg("S1"), py::arg("SU1"), py::arg("SV1"), py::arg("S2"), py::arg("SU2"), py::arg("SV2"));

// Enums

}