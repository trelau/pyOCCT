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
#include <Adaptor3d_TopolTool.hxx>
#include <Standard_TypeDef.hxx>
#include <IntSurf_ListOfPntOn2S.hxx>
#include <IntPatch_Point.hxx>
#include <IntPatch_Line.hxx>
#include <IntPatch_SequenceOfLine.hxx>
#include <GeomAbs_SurfaceType.hxx>
#include <IntPatch_SequenceOfPoint.hxx>
#include <IntPatch_Intersection.hxx>

void bind_IntPatch_Intersection(py::module &mod){

py::class_<IntPatch_Intersection, std::unique_ptr<IntPatch_Intersection, Deleter<IntPatch_Intersection>>> cls_IntPatch_Intersection(mod, "IntPatch_Intersection", "This class provides a generic algorithm to intersect 2 surfaces.");

// Constructors
cls_IntPatch_Intersection.def(py::init<>());
cls_IntPatch_Intersection.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const Standard_Real, const Standard_Real>(), py::arg("S1"), py::arg("D1"), py::arg("S2"), py::arg("D2"), py::arg("TolArc"), py::arg("TolTang"));
cls_IntPatch_Intersection.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const Standard_Real, const Standard_Real>(), py::arg("S1"), py::arg("D1"), py::arg("TolArc"), py::arg("TolTang"));

// Fields

// Methods
// cls_IntPatch_Intersection.def_static("operator new_", (void * (*)(size_t)) &IntPatch_Intersection::operator new, "None", py::arg("theSize"));
// cls_IntPatch_Intersection.def_static("operator delete_", (void (*)(void *)) &IntPatch_Intersection::operator delete, "None", py::arg("theAddress"));
// cls_IntPatch_Intersection.def_static("operator new[]_", (void * (*)(size_t)) &IntPatch_Intersection::operator new[], "None", py::arg("theSize"));
// cls_IntPatch_Intersection.def_static("operator delete[]_", (void (*)(void *)) &IntPatch_Intersection::operator delete[], "None", py::arg("theAddress"));
// cls_IntPatch_Intersection.def_static("operator new_", (void * (*)(size_t, void *)) &IntPatch_Intersection::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntPatch_Intersection.def_static("operator delete_", (void (*)(void *, void *)) &IntPatch_Intersection::operator delete, "None", py::arg(""), py::arg(""));
cls_IntPatch_Intersection.def("SetTolerances", (void (IntPatch_Intersection::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &IntPatch_Intersection::SetTolerances, "Set the tolerances used by the algorithms: --- Implicit - Parametric --- Parametric - Parametric --- Implicit - Implicit", py::arg("TolArc"), py::arg("TolTang"), py::arg("UVMaxStep"), py::arg("Fleche"));
cls_IntPatch_Intersection.def("Perform", [](IntPatch_Intersection &self, const opencascade::handle<Adaptor3d_HSurface> & a0, const opencascade::handle<Adaptor3d_TopolTool> & a1, const opencascade::handle<Adaptor3d_HSurface> & a2, const opencascade::handle<Adaptor3d_TopolTool> & a3, const Standard_Real a4, const Standard_Real a5) -> void { return self.Perform(a0, a1, a2, a3, a4, a5); });
cls_IntPatch_Intersection.def("Perform", [](IntPatch_Intersection &self, const opencascade::handle<Adaptor3d_HSurface> & a0, const opencascade::handle<Adaptor3d_TopolTool> & a1, const opencascade::handle<Adaptor3d_HSurface> & a2, const opencascade::handle<Adaptor3d_TopolTool> & a3, const Standard_Real a4, const Standard_Real a5, const Standard_Boolean a6) -> void { return self.Perform(a0, a1, a2, a3, a4, a5, a6); });
cls_IntPatch_Intersection.def("Perform", [](IntPatch_Intersection &self, const opencascade::handle<Adaptor3d_HSurface> & a0, const opencascade::handle<Adaptor3d_TopolTool> & a1, const opencascade::handle<Adaptor3d_HSurface> & a2, const opencascade::handle<Adaptor3d_TopolTool> & a3, const Standard_Real a4, const Standard_Real a5, const Standard_Boolean a6, const Standard_Boolean a7) -> void { return self.Perform(a0, a1, a2, a3, a4, a5, a6, a7); });
cls_IntPatch_Intersection.def("Perform", (void (IntPatch_Intersection::*)(const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean)) &IntPatch_Intersection::Perform, "Flag theIsReqToKeepRLine has been entered only for compatibility with TopOpeBRep package. It shall be deleted after deleting TopOpeBRep. When intersection result returns IntPatch_RLine and another IntPatch_Line (not restriction) we (in case of theIsReqToKeepRLine==TRUE) will always keep both lines even if they are coincided. Flag theIsReqToPostWLProc has been entered only for compatibility with TopOpeBRep package. It shall be deleted after deleting TopOpeBRep. If theIsReqToPostWLProc == FALSE, then we will work with Walking-line obtained after intersection algorithm directly (wothout any post-processing).", py::arg("S1"), py::arg("D1"), py::arg("S2"), py::arg("D2"), py::arg("TolArc"), py::arg("TolTang"), py::arg("isGeomInt"), py::arg("theIsReqToKeepRLine"), py::arg("theIsReqToPostWLProc"));
cls_IntPatch_Intersection.def("Perform", [](IntPatch_Intersection &self, const opencascade::handle<Adaptor3d_HSurface> & a0, const opencascade::handle<Adaptor3d_TopolTool> & a1, const opencascade::handle<Adaptor3d_HSurface> & a2, const opencascade::handle<Adaptor3d_TopolTool> & a3, const Standard_Real a4, const Standard_Real a5, IntSurf_ListOfPntOn2S & a6) -> void { return self.Perform(a0, a1, a2, a3, a4, a5, a6); });
cls_IntPatch_Intersection.def("Perform", [](IntPatch_Intersection &self, const opencascade::handle<Adaptor3d_HSurface> & a0, const opencascade::handle<Adaptor3d_TopolTool> & a1, const opencascade::handle<Adaptor3d_HSurface> & a2, const opencascade::handle<Adaptor3d_TopolTool> & a3, const Standard_Real a4, const Standard_Real a5, IntSurf_ListOfPntOn2S & a6, const Standard_Boolean a7) -> void { return self.Perform(a0, a1, a2, a3, a4, a5, a6, a7); });
cls_IntPatch_Intersection.def("Perform", [](IntPatch_Intersection &self, const opencascade::handle<Adaptor3d_HSurface> & a0, const opencascade::handle<Adaptor3d_TopolTool> & a1, const opencascade::handle<Adaptor3d_HSurface> & a2, const opencascade::handle<Adaptor3d_TopolTool> & a3, const Standard_Real a4, const Standard_Real a5, IntSurf_ListOfPntOn2S & a6, const Standard_Boolean a7, const Standard_Boolean a8) -> void { return self.Perform(a0, a1, a2, a3, a4, a5, a6, a7, a8); });
cls_IntPatch_Intersection.def("Perform", (void (IntPatch_Intersection::*)(const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const Standard_Real, const Standard_Real, IntSurf_ListOfPntOn2S &, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean)) &IntPatch_Intersection::Perform, "If isGeomInt == Standard_False, then method Param-Param intersection will be used. Flag theIsReqToKeepRLine has been entered only for compatibility with TopOpeBRep package. It shall be deleted after deleting TopOpeBRep. When intersection result returns IntPatch_RLine and another IntPatch_Line (not restriction) we (in case of theIsReqToKeepRLine==TRUE) will always keep both lines even if they are coincided. Flag theIsReqToPostWLProc has been entered only for compatibility with TopOpeBRep package. It shall be deleted after deleting TopOpeBRep. If theIsReqToPostWLProc == FALSE, then we will work with Walking-line obtained after intersection algorithm directly (without any post-processing).", py::arg("S1"), py::arg("D1"), py::arg("S2"), py::arg("D2"), py::arg("TolArc"), py::arg("TolTang"), py::arg("LOfPnts"), py::arg("isGeomInt"), py::arg("theIsReqToKeepRLine"), py::arg("theIsReqToPostWLProc"));
cls_IntPatch_Intersection.def("Perform", (void (IntPatch_Intersection::*)(const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &IntPatch_Intersection::Perform, "Perform with start point", py::arg("S1"), py::arg("D1"), py::arg("S2"), py::arg("D2"), py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"), py::arg("TolArc"), py::arg("TolTang"));
cls_IntPatch_Intersection.def("Perform", (void (IntPatch_Intersection::*)(const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const Standard_Real, const Standard_Real)) &IntPatch_Intersection::Perform, "Uses for finding self-intersected surfaces.", py::arg("S1"), py::arg("D1"), py::arg("TolArc"), py::arg("TolTang"));
cls_IntPatch_Intersection.def("IsDone", (Standard_Boolean (IntPatch_Intersection::*)() const) &IntPatch_Intersection::IsDone, "Returns True if the calculus was successful.");
cls_IntPatch_Intersection.def("IsEmpty", (Standard_Boolean (IntPatch_Intersection::*)() const) &IntPatch_Intersection::IsEmpty, "Returns true if the is no intersection.");
cls_IntPatch_Intersection.def("TangentFaces", (Standard_Boolean (IntPatch_Intersection::*)() const) &IntPatch_Intersection::TangentFaces, "Returns True if the two patches are considered as entirely tangent, i-e every restriction arc of one patch is inside the geometric base of the other patch.");
cls_IntPatch_Intersection.def("OppositeFaces", (Standard_Boolean (IntPatch_Intersection::*)() const) &IntPatch_Intersection::OppositeFaces, "Returns True when the TangentFaces returns True and the normal vectors evaluated at a point on the first and the second surface are opposite. The exception DomainError is raised if TangentFaces returns False.");
cls_IntPatch_Intersection.def("NbPnts", (Standard_Integer (IntPatch_Intersection::*)() const) &IntPatch_Intersection::NbPnts, "Returns the number of 'single' points.");
cls_IntPatch_Intersection.def("Point", (const IntPatch_Point & (IntPatch_Intersection::*)(const Standard_Integer) const) &IntPatch_Intersection::Point, "Returns the point of range Index. An exception is raised if Index<=0 or Index>NbPnt.", py::arg("Index"));
cls_IntPatch_Intersection.def("NbLines", (Standard_Integer (IntPatch_Intersection::*)() const) &IntPatch_Intersection::NbLines, "Returns the number of intersection lines.");
cls_IntPatch_Intersection.def("Line", (const opencascade::handle<IntPatch_Line> & (IntPatch_Intersection::*)(const Standard_Integer) const) &IntPatch_Intersection::Line, "Returns the line of range Index. An exception is raised if Index<=0 or Index>NbLine.", py::arg("Index"));
cls_IntPatch_Intersection.def("SequenceOfLine", (const IntPatch_SequenceOfLine & (IntPatch_Intersection::*)() const) &IntPatch_Intersection::SequenceOfLine, "None");
cls_IntPatch_Intersection.def("Dump", (void (IntPatch_Intersection::*)(const Standard_Integer, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &) const) &IntPatch_Intersection::Dump, "Dump of each result line. Mode for more accurate dumps.", py::arg("Mode"), py::arg("S1"), py::arg("D1"), py::arg("S2"), py::arg("D2"));

// Enums

}