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
#include <Geom2dAdaptor_Curve.hxx>
#include <Standard_TypeDef.hxx>
#include <HatchGen_ErrorStatus.hxx>
#include <HatchGen_PointOnHatching.hxx>
#include <HatchGen_Domain.hxx>
#include <gp_Pnt2d.hxx>
#include <HatchGen_PointsOnHatching.hxx>
#include <HatchGen_Domains.hxx>
#include <Geom2dHatch_Hatching.hxx>

void bind_Geom2dHatch_Hatching(py::module &mod){

py::class_<Geom2dHatch_Hatching, std::unique_ptr<Geom2dHatch_Hatching>> cls_Geom2dHatch_Hatching(mod, "Geom2dHatch_Hatching", "None");

// Constructors
cls_Geom2dHatch_Hatching.def(py::init<>());
cls_Geom2dHatch_Hatching.def(py::init<const Geom2dAdaptor_Curve &>(), py::arg("Curve"));

// Fields

// Methods
// cls_Geom2dHatch_Hatching.def_static("operator new_", (void * (*)(size_t)) &Geom2dHatch_Hatching::operator new, "None", py::arg("theSize"));
// cls_Geom2dHatch_Hatching.def_static("operator delete_", (void (*)(void *)) &Geom2dHatch_Hatching::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dHatch_Hatching.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dHatch_Hatching::operator new[], "None", py::arg("theSize"));
// cls_Geom2dHatch_Hatching.def_static("operator delete[]_", (void (*)(void *)) &Geom2dHatch_Hatching::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dHatch_Hatching.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dHatch_Hatching::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dHatch_Hatching.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dHatch_Hatching::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dHatch_Hatching.def("Curve", (const Geom2dAdaptor_Curve & (Geom2dHatch_Hatching::*)() const) &Geom2dHatch_Hatching::Curve, "Returns the curve associated to the hatching.");
cls_Geom2dHatch_Hatching.def("ChangeCurve", (Geom2dAdaptor_Curve & (Geom2dHatch_Hatching::*)()) &Geom2dHatch_Hatching::ChangeCurve, "Returns the curve associated to the hatching.");
cls_Geom2dHatch_Hatching.def("TrimDone", (void (Geom2dHatch_Hatching::*)(const Standard_Boolean)) &Geom2dHatch_Hatching::TrimDone, "Sets the flag about the trimming computations to the given value.", py::arg("Flag"));
cls_Geom2dHatch_Hatching.def("TrimDone", (Standard_Boolean (Geom2dHatch_Hatching::*)() const) &Geom2dHatch_Hatching::TrimDone, "Returns the flag about the trimming computations.");
cls_Geom2dHatch_Hatching.def("TrimFailed", (void (Geom2dHatch_Hatching::*)(const Standard_Boolean)) &Geom2dHatch_Hatching::TrimFailed, "Sets the flag about the trimming failure to the given value.", py::arg("Flag"));
cls_Geom2dHatch_Hatching.def("TrimFailed", (Standard_Boolean (Geom2dHatch_Hatching::*)() const) &Geom2dHatch_Hatching::TrimFailed, "Returns the flag about the trimming failure.");
cls_Geom2dHatch_Hatching.def("IsDone", (void (Geom2dHatch_Hatching::*)(const Standard_Boolean)) &Geom2dHatch_Hatching::IsDone, "Sets the flag about the domains computation to the given value.", py::arg("Flag"));
cls_Geom2dHatch_Hatching.def("IsDone", (Standard_Boolean (Geom2dHatch_Hatching::*)() const) &Geom2dHatch_Hatching::IsDone, "Returns the flag about the domains computation.");
cls_Geom2dHatch_Hatching.def("Status", (void (Geom2dHatch_Hatching::*)(const HatchGen_ErrorStatus)) &Geom2dHatch_Hatching::Status, "Sets the error status.", py::arg("theStatus"));
cls_Geom2dHatch_Hatching.def("Status", (HatchGen_ErrorStatus (Geom2dHatch_Hatching::*)() const) &Geom2dHatch_Hatching::Status, "Returns the error status.");
cls_Geom2dHatch_Hatching.def("AddPoint", (void (Geom2dHatch_Hatching::*)(const HatchGen_PointOnHatching &, const Standard_Real)) &Geom2dHatch_Hatching::AddPoint, "Adds an intersection point to the hatching.", py::arg("Point"), py::arg("Confusion"));
cls_Geom2dHatch_Hatching.def("NbPoints", (Standard_Integer (Geom2dHatch_Hatching::*)() const) &Geom2dHatch_Hatching::NbPoints, "Returns the number of intersection points of the hatching.");
cls_Geom2dHatch_Hatching.def("Point", (const HatchGen_PointOnHatching & (Geom2dHatch_Hatching::*)(const Standard_Integer) const) &Geom2dHatch_Hatching::Point, "Returns the Index-th intersection point of the hatching. The exception OutOfRange is raised if Index < 1 or Index > NbPoints.", py::arg("Index"));
cls_Geom2dHatch_Hatching.def("ChangePoint", (HatchGen_PointOnHatching & (Geom2dHatch_Hatching::*)(const Standard_Integer)) &Geom2dHatch_Hatching::ChangePoint, "Returns the Index-th intersection point of the hatching. The exception OutOfRange is raised if Index < 1 or Index > NbPoints.", py::arg("Index"));
cls_Geom2dHatch_Hatching.def("RemPoint", (void (Geom2dHatch_Hatching::*)(const Standard_Integer)) &Geom2dHatch_Hatching::RemPoint, "Removes the Index-th intersection point of the hatching. The exception OutOfRange is raised if Index < 1 or Index > NbPoints.", py::arg("Index"));
cls_Geom2dHatch_Hatching.def("ClrPoints", (void (Geom2dHatch_Hatching::*)()) &Geom2dHatch_Hatching::ClrPoints, "Removes all the intersection points of the hatching.");
cls_Geom2dHatch_Hatching.def("AddDomain", (void (Geom2dHatch_Hatching::*)(const HatchGen_Domain &)) &Geom2dHatch_Hatching::AddDomain, "Adds a domain to the hatching.", py::arg("Domain"));
cls_Geom2dHatch_Hatching.def("NbDomains", (Standard_Integer (Geom2dHatch_Hatching::*)() const) &Geom2dHatch_Hatching::NbDomains, "Returns the number of domains of the hatching.");
cls_Geom2dHatch_Hatching.def("Domain", (const HatchGen_Domain & (Geom2dHatch_Hatching::*)(const Standard_Integer) const) &Geom2dHatch_Hatching::Domain, "Returns the Index-th domain of the hatching. The exception OutOfRange is raised if Index < 1 or Index > NbDomains.", py::arg("Index"));
cls_Geom2dHatch_Hatching.def("RemDomain", (void (Geom2dHatch_Hatching::*)(const Standard_Integer)) &Geom2dHatch_Hatching::RemDomain, "Removes the Index-th domain of the hatching. The exception OutOfRange is raised if Index < 1 or Index > NbDomains.", py::arg("Index"));
cls_Geom2dHatch_Hatching.def("ClrDomains", (void (Geom2dHatch_Hatching::*)()) &Geom2dHatch_Hatching::ClrDomains, "Removes all the domains of the hatching.");
cls_Geom2dHatch_Hatching.def("ClassificationPoint", (gp_Pnt2d (Geom2dHatch_Hatching::*)() const) &Geom2dHatch_Hatching::ClassificationPoint, "Returns a point on the curve. This point will be used for the classification.");

// Enums

}