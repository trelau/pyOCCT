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
#include <Geom2dHatch_Intersector.hxx>
#include <Standard_TypeDef.hxx>
#include <Geom2dAdaptor_Curve.hxx>
#include <TopAbs_Orientation.hxx>
#include <Standard_Handle.hxx>
#include <Geom2d_Curve.hxx>
#include <HatchGen_PointOnHatching.hxx>
#include <HatchGen_ErrorStatus.hxx>
#include <HatchGen_Domain.hxx>
#include <Geom2dHatch_Element.hxx>
#include <Geom2dHatch_Hatching.hxx>
#include <Geom2dHatch_Elements.hxx>
#include <Geom2dHatch_Hatchings.hxx>
#include <Geom2dHatch_Hatcher.hxx>

void bind_Geom2dHatch_Hatcher(py::module &mod){

py::class_<Geom2dHatch_Hatcher, std::unique_ptr<Geom2dHatch_Hatcher, Deleter<Geom2dHatch_Hatcher>>> cls_Geom2dHatch_Hatcher(mod, "Geom2dHatch_Hatcher", "None");

// Constructors
cls_Geom2dHatch_Hatcher.def(py::init<const Geom2dHatch_Intersector &, const Standard_Real, const Standard_Real>(), py::arg("Intersector"), py::arg("Confusion2d"), py::arg("Confusion3d"));
cls_Geom2dHatch_Hatcher.def(py::init<const Geom2dHatch_Intersector &, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("Intersector"), py::arg("Confusion2d"), py::arg("Confusion3d"), py::arg("KeepPnt"));
cls_Geom2dHatch_Hatcher.def(py::init<const Geom2dHatch_Intersector &, const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Boolean>(), py::arg("Intersector"), py::arg("Confusion2d"), py::arg("Confusion3d"), py::arg("KeepPnt"), py::arg("KeepSeg"));

// Fields

// Methods
// cls_Geom2dHatch_Hatcher.def_static("operator new_", (void * (*)(size_t)) &Geom2dHatch_Hatcher::operator new, "None", py::arg("theSize"));
// cls_Geom2dHatch_Hatcher.def_static("operator delete_", (void (*)(void *)) &Geom2dHatch_Hatcher::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dHatch_Hatcher.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dHatch_Hatcher::operator new[], "None", py::arg("theSize"));
// cls_Geom2dHatch_Hatcher.def_static("operator delete[]_", (void (*)(void *)) &Geom2dHatch_Hatcher::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dHatch_Hatcher.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dHatch_Hatcher::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dHatch_Hatcher.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dHatch_Hatcher::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dHatch_Hatcher.def("Intersector", (void (Geom2dHatch_Hatcher::*)(const Geom2dHatch_Intersector &)) &Geom2dHatch_Hatcher::Intersector, "Sets the associated intersector.", py::arg("Intersector"));
cls_Geom2dHatch_Hatcher.def("Intersector", (const Geom2dHatch_Intersector & (Geom2dHatch_Hatcher::*)()) &Geom2dHatch_Hatcher::Intersector, "Returns the associated intersector.");
cls_Geom2dHatch_Hatcher.def("ChangeIntersector", (Geom2dHatch_Intersector & (Geom2dHatch_Hatcher::*)()) &Geom2dHatch_Hatcher::ChangeIntersector, "Returns the associated intersector.");
cls_Geom2dHatch_Hatcher.def("Confusion2d", (void (Geom2dHatch_Hatcher::*)(const Standard_Real)) &Geom2dHatch_Hatcher::Confusion2d, "Sets the confusion tolerance.", py::arg("Confusion"));
cls_Geom2dHatch_Hatcher.def("Confusion2d", (Standard_Real (Geom2dHatch_Hatcher::*)() const) &Geom2dHatch_Hatcher::Confusion2d, "Returns the 2d confusion tolerance, i.e. the value under which two points are considered identical in the parametric space of the hatching.");
cls_Geom2dHatch_Hatcher.def("Confusion3d", (void (Geom2dHatch_Hatcher::*)(const Standard_Real)) &Geom2dHatch_Hatcher::Confusion3d, "Sets the confusion tolerance.", py::arg("Confusion"));
cls_Geom2dHatch_Hatcher.def("Confusion3d", (Standard_Real (Geom2dHatch_Hatcher::*)() const) &Geom2dHatch_Hatcher::Confusion3d, "Returns the 3d confusion tolerance, i.e. the value under which two points are considered identical in the 3d space of the hatching.");
cls_Geom2dHatch_Hatcher.def("KeepPoints", (void (Geom2dHatch_Hatcher::*)(const Standard_Boolean)) &Geom2dHatch_Hatcher::KeepPoints, "Sets the above flag.", py::arg("Keep"));
cls_Geom2dHatch_Hatcher.def("KeepPoints", (Standard_Boolean (Geom2dHatch_Hatcher::*)() const) &Geom2dHatch_Hatcher::KeepPoints, "Returns the flag about the points consideration.");
cls_Geom2dHatch_Hatcher.def("KeepSegments", (void (Geom2dHatch_Hatcher::*)(const Standard_Boolean)) &Geom2dHatch_Hatcher::KeepSegments, "Sets the above flag.", py::arg("Keep"));
cls_Geom2dHatch_Hatcher.def("KeepSegments", (Standard_Boolean (Geom2dHatch_Hatcher::*)() const) &Geom2dHatch_Hatcher::KeepSegments, "Returns the flag about the segments consideration.");
cls_Geom2dHatch_Hatcher.def("Clear", (void (Geom2dHatch_Hatcher::*)()) &Geom2dHatch_Hatcher::Clear, "Removes all the hatchings and all the elements.");
cls_Geom2dHatch_Hatcher.def("ElementCurve", (const Geom2dAdaptor_Curve & (Geom2dHatch_Hatcher::*)(const Standard_Integer) const) &Geom2dHatch_Hatcher::ElementCurve, "Returns the curve associated to the IndE-th element.", py::arg("IndE"));
cls_Geom2dHatch_Hatcher.def("AddElement", [](Geom2dHatch_Hatcher &self, const Geom2dAdaptor_Curve & a0) -> Standard_Integer { return self.AddElement(a0); });
cls_Geom2dHatch_Hatcher.def("AddElement", (Standard_Integer (Geom2dHatch_Hatcher::*)(const Geom2dAdaptor_Curve &, const TopAbs_Orientation)) &Geom2dHatch_Hatcher::AddElement, "Adds an element to the hatcher and returns its index.", py::arg("Curve"), py::arg("Orientation"));
cls_Geom2dHatch_Hatcher.def("AddElement", [](Geom2dHatch_Hatcher &self, const opencascade::handle<Geom2d_Curve> & a0) -> Standard_Integer { return self.AddElement(a0); });
cls_Geom2dHatch_Hatcher.def("AddElement", (Standard_Integer (Geom2dHatch_Hatcher::*)(const opencascade::handle<Geom2d_Curve> &, const TopAbs_Orientation)) &Geom2dHatch_Hatcher::AddElement, "Adds an element to the hatcher and returns its index.", py::arg("Curve"), py::arg("Orientation"));
cls_Geom2dHatch_Hatcher.def("RemElement", (void (Geom2dHatch_Hatcher::*)(const Standard_Integer)) &Geom2dHatch_Hatcher::RemElement, "Removes the IndE-th element from the hatcher.", py::arg("IndE"));
cls_Geom2dHatch_Hatcher.def("ClrElements", (void (Geom2dHatch_Hatcher::*)()) &Geom2dHatch_Hatcher::ClrElements, "Removes all the elements from the hatcher.");
cls_Geom2dHatch_Hatcher.def("HatchingCurve", (const Geom2dAdaptor_Curve & (Geom2dHatch_Hatcher::*)(const Standard_Integer) const) &Geom2dHatch_Hatcher::HatchingCurve, "Returns the curve associated to the IndH-th hatching.", py::arg("IndH"));
cls_Geom2dHatch_Hatcher.def("AddHatching", (Standard_Integer (Geom2dHatch_Hatcher::*)(const Geom2dAdaptor_Curve &)) &Geom2dHatch_Hatcher::AddHatching, "Adds a hatching to the hatcher and returns its index.", py::arg("Curve"));
cls_Geom2dHatch_Hatcher.def("RemHatching", (void (Geom2dHatch_Hatcher::*)(const Standard_Integer)) &Geom2dHatch_Hatcher::RemHatching, "Removes the IndH-th hatching from the hatcher.", py::arg("IndH"));
cls_Geom2dHatch_Hatcher.def("ClrHatchings", (void (Geom2dHatch_Hatcher::*)()) &Geom2dHatch_Hatcher::ClrHatchings, "Removes all the hatchings from the hatcher.");
cls_Geom2dHatch_Hatcher.def("NbPoints", (Standard_Integer (Geom2dHatch_Hatcher::*)(const Standard_Integer) const) &Geom2dHatch_Hatcher::NbPoints, "Returns the number of intersection points of the IndH-th hatching.", py::arg("IndH"));
cls_Geom2dHatch_Hatcher.def("Point", (const HatchGen_PointOnHatching & (Geom2dHatch_Hatcher::*)(const Standard_Integer, const Standard_Integer) const) &Geom2dHatch_Hatcher::Point, "Returns the IndP-th intersection point of the IndH-th hatching.", py::arg("IndH"), py::arg("IndP"));
cls_Geom2dHatch_Hatcher.def("Trim", (void (Geom2dHatch_Hatcher::*)()) &Geom2dHatch_Hatcher::Trim, "Trims all the hatchings of the hatcher by all the elements of the hatcher.");
cls_Geom2dHatch_Hatcher.def("Trim", (Standard_Integer (Geom2dHatch_Hatcher::*)(const Geom2dAdaptor_Curve &)) &Geom2dHatch_Hatcher::Trim, "Adds a hatching to the hatcher and trims it by the elements already given and returns its index.", py::arg("Curve"));
cls_Geom2dHatch_Hatcher.def("Trim", (void (Geom2dHatch_Hatcher::*)(const Standard_Integer)) &Geom2dHatch_Hatcher::Trim, "Trims the IndH-th hatching by the elements already given.", py::arg("IndH"));
cls_Geom2dHatch_Hatcher.def("ComputeDomains", (void (Geom2dHatch_Hatcher::*)()) &Geom2dHatch_Hatcher::ComputeDomains, "Computes the domains of all the hatchings.");
cls_Geom2dHatch_Hatcher.def("ComputeDomains", (void (Geom2dHatch_Hatcher::*)(const Standard_Integer)) &Geom2dHatch_Hatcher::ComputeDomains, "Computes the domains of the IndH-th hatching.", py::arg("IndH"));
cls_Geom2dHatch_Hatcher.def("TrimDone", (Standard_Boolean (Geom2dHatch_Hatcher::*)(const Standard_Integer) const) &Geom2dHatch_Hatcher::TrimDone, "Returns the fact that the intersections were computed for the IndH-th hatching.", py::arg("IndH"));
cls_Geom2dHatch_Hatcher.def("TrimFailed", (Standard_Boolean (Geom2dHatch_Hatcher::*)(const Standard_Integer) const) &Geom2dHatch_Hatcher::TrimFailed, "Returns the fact that the intersections failed for the IndH-th hatching.", py::arg("IndH"));
// cls_Geom2dHatch_Hatcher.def("IsDone", (Standard_Boolean (Geom2dHatch_Hatcher::*)() const) &Geom2dHatch_Hatcher::IsDone, "Returns the fact that the domains were computed for all the hatchings.");
cls_Geom2dHatch_Hatcher.def("IsDone", (Standard_Boolean (Geom2dHatch_Hatcher::*)(const Standard_Integer) const) &Geom2dHatch_Hatcher::IsDone, "Returns the fact that the domains were computed for the IndH-th hatching.", py::arg("IndH"));
cls_Geom2dHatch_Hatcher.def("Status", (HatchGen_ErrorStatus (Geom2dHatch_Hatcher::*)(const Standard_Integer) const) &Geom2dHatch_Hatcher::Status, "Returns the status about the IndH-th hatching.", py::arg("IndH"));
cls_Geom2dHatch_Hatcher.def("NbDomains", (Standard_Integer (Geom2dHatch_Hatcher::*)(const Standard_Integer) const) &Geom2dHatch_Hatcher::NbDomains, "Returns the number of domains of the IndH-th hatching. Only ONE 'INFINITE' domain means that the hatching is fully included in the contour defined by the elements.", py::arg("IndH"));
cls_Geom2dHatch_Hatcher.def("Domain", (const HatchGen_Domain & (Geom2dHatch_Hatcher::*)(const Standard_Integer, const Standard_Integer) const) &Geom2dHatch_Hatcher::Domain, "Returns the IDom-th domain of the IndH-th hatching.", py::arg("IndH"), py::arg("IDom"));
cls_Geom2dHatch_Hatcher.def("Dump", (void (Geom2dHatch_Hatcher::*)() const) &Geom2dHatch_Hatcher::Dump, "Dump the hatcher.");

// Enums

}