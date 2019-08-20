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
#include <Contap_ArcFunction.hxx>
#include <Standard_Handle.hxx>
#include <Adaptor3d_TopolTool.hxx>
#include <Standard_TypeDef.hxx>
#include <Contap_ThePathPointOfTheSearch.hxx>
#include <Contap_TheSegmentOfTheSearch.hxx>
#include <Contap_SequenceOfSegmentOfTheSearch.hxx>
#include <Contap_SequenceOfPathPointOfTheSearch.hxx>
#include <Contap_TheSearch.hxx>

void bind_Contap_TheSearch(py::module &mod){

py::class_<Contap_TheSearch, std::unique_ptr<Contap_TheSearch>> cls_Contap_TheSearch(mod, "Contap_TheSearch", "None");

// Constructors
cls_Contap_TheSearch.def(py::init<>());

// Fields

// Methods
// cls_Contap_TheSearch.def_static("operator new_", (void * (*)(size_t)) &Contap_TheSearch::operator new, "None", py::arg("theSize"));
// cls_Contap_TheSearch.def_static("operator delete_", (void (*)(void *)) &Contap_TheSearch::operator delete, "None", py::arg("theAddress"));
// cls_Contap_TheSearch.def_static("operator new[]_", (void * (*)(size_t)) &Contap_TheSearch::operator new[], "None", py::arg("theSize"));
// cls_Contap_TheSearch.def_static("operator delete[]_", (void (*)(void *)) &Contap_TheSearch::operator delete[], "None", py::arg("theAddress"));
// cls_Contap_TheSearch.def_static("operator new_", (void * (*)(size_t, void *)) &Contap_TheSearch::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Contap_TheSearch.def_static("operator delete_", (void (*)(void *, void *)) &Contap_TheSearch::operator delete, "None", py::arg(""), py::arg(""));
cls_Contap_TheSearch.def("Perform", [](Contap_TheSearch &self, Contap_ArcFunction & a0, const opencascade::handle<Adaptor3d_TopolTool> & a1, const Standard_Real a2, const Standard_Real a3) -> void { return self.Perform(a0, a1, a2, a3); });
cls_Contap_TheSearch.def("Perform", (void (Contap_TheSearch::*)(Contap_ArcFunction &, const opencascade::handle<Adaptor3d_TopolTool> &, const Standard_Real, const Standard_Real, const Standard_Boolean)) &Contap_TheSearch::Perform, "Algorithm to find the points and parts of curves of Domain (domain of of restriction of a surface) which verify F = 0. TolBoundary defines if a curve is on Q. TolTangency defines if a point is on Q.", py::arg("F"), py::arg("Domain"), py::arg("TolBoundary"), py::arg("TolTangency"), py::arg("RecheckOnRegularity"));
cls_Contap_TheSearch.def("IsDone", (Standard_Boolean (Contap_TheSearch::*)() const) &Contap_TheSearch::IsDone, "Returns True if the calculus was successful.");
cls_Contap_TheSearch.def("AllArcSolution", (Standard_Boolean (Contap_TheSearch::*)() const) &Contap_TheSearch::AllArcSolution, "Returns true if all arc of the Arcs are solution (inside the surface). An exception is raised if IsDone returns False.");
cls_Contap_TheSearch.def("NbPoints", (Standard_Integer (Contap_TheSearch::*)() const) &Contap_TheSearch::NbPoints, "Returns the number of resulting points. An exception is raised if IsDone returns False (NotDone).");
cls_Contap_TheSearch.def("Point", (const Contap_ThePathPointOfTheSearch & (Contap_TheSearch::*)(const Standard_Integer) const) &Contap_TheSearch::Point, "Returns the resulting point of range Index. The exception NotDone is raised if IsDone() returns False. The exception OutOfRange is raised if Index <= 0 or Index > NbPoints.", py::arg("Index"));
cls_Contap_TheSearch.def("NbSegments", (Standard_Integer (Contap_TheSearch::*)() const) &Contap_TheSearch::NbSegments, "Returns the number of the resulting segments. An exception is raised if IsDone returns False (NotDone).");
cls_Contap_TheSearch.def("Segment", (const Contap_TheSegmentOfTheSearch & (Contap_TheSearch::*)(const Standard_Integer) const) &Contap_TheSearch::Segment, "Returns the resulting segment of range Index. The exception NotDone is raised if IsDone() returns False. The exception OutOfRange is raised if Index <= 0 or Index > NbPoints.", py::arg("Index"));

// Enums

}