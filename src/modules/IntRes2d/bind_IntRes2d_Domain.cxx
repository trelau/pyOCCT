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
#include <gp_Pnt2d.hxx>
#include <Standard_TypeDef.hxx>
#include <IntRes2d_Domain.hxx>

void bind_IntRes2d_Domain(py::module &mod){

py::class_<IntRes2d_Domain> cls_IntRes2d_Domain(mod, "IntRes2d_Domain", "Definition of the domain of parameter on a 2d-curve. Most of the time, a domain is defined by two extremities. An extremity is made of : - a point in 2d-space (Pnt2d from gp), - a parameter on the curve, - a tolerance in the 2d-space. Sometimes, it can be made of 0 or 1 point ( for an infinite or semi-infinite line for example).");

// Constructors
cls_IntRes2d_Domain.def(py::init<>());
cls_IntRes2d_Domain.def(py::init<const gp_Pnt2d &, const Standard_Real, const Standard_Real, const gp_Pnt2d &, const Standard_Real, const Standard_Real>(), py::arg("Pnt1"), py::arg("Par1"), py::arg("Tol1"), py::arg("Pnt2"), py::arg("Par2"), py::arg("Tol2"));
cls_IntRes2d_Domain.def(py::init<const gp_Pnt2d &, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("Pnt"), py::arg("Par"), py::arg("Tol"), py::arg("First"));

// Fields

// Methods
// cls_IntRes2d_Domain.def_static("operator new_", (void * (*)(size_t)) &IntRes2d_Domain::operator new, "None", py::arg("theSize"));
// cls_IntRes2d_Domain.def_static("operator delete_", (void (*)(void *)) &IntRes2d_Domain::operator delete, "None", py::arg("theAddress"));
// cls_IntRes2d_Domain.def_static("operator new[]_", (void * (*)(size_t)) &IntRes2d_Domain::operator new[], "None", py::arg("theSize"));
// cls_IntRes2d_Domain.def_static("operator delete[]_", (void (*)(void *)) &IntRes2d_Domain::operator delete[], "None", py::arg("theAddress"));
// cls_IntRes2d_Domain.def_static("operator new_", (void * (*)(size_t, void *)) &IntRes2d_Domain::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntRes2d_Domain.def_static("operator delete_", (void (*)(void *, void *)) &IntRes2d_Domain::operator delete, "None", py::arg(""), py::arg(""));
cls_IntRes2d_Domain.def("SetValues", (void (IntRes2d_Domain::*)(const gp_Pnt2d &, const Standard_Real, const Standard_Real, const gp_Pnt2d &, const Standard_Real, const Standard_Real)) &IntRes2d_Domain::SetValues, "Sets the values for a bounded domain.", py::arg("Pnt1"), py::arg("Par1"), py::arg("Tol1"), py::arg("Pnt2"), py::arg("Par2"), py::arg("Tol2"));
cls_IntRes2d_Domain.def("SetValues", (void (IntRes2d_Domain::*)()) &IntRes2d_Domain::SetValues, "Sets the values for an infinite domain.");
cls_IntRes2d_Domain.def("SetValues", (void (IntRes2d_Domain::*)(const gp_Pnt2d &, const Standard_Real, const Standard_Real, const Standard_Boolean)) &IntRes2d_Domain::SetValues, "Sets the values for a semi-infinite domain.", py::arg("Pnt"), py::arg("Par"), py::arg("Tol"), py::arg("First"));
cls_IntRes2d_Domain.def("SetEquivalentParameters", (void (IntRes2d_Domain::*)(const Standard_Real, const Standard_Real)) &IntRes2d_Domain::SetEquivalentParameters, "Defines a closed domain.", py::arg("zero"), py::arg("period"));
cls_IntRes2d_Domain.def("HasFirstPoint", (Standard_Boolean (IntRes2d_Domain::*)() const) &IntRes2d_Domain::HasFirstPoint, "Returns True if the domain has a first point, i-e a point defining the lowest admitted parameter on the curve.");
cls_IntRes2d_Domain.def("FirstParameter", (Standard_Real (IntRes2d_Domain::*)() const) &IntRes2d_Domain::FirstParameter, "Returns the parameter of the first point of the domain The exception DomainError is raised if HasFirstPoint returns False.");
cls_IntRes2d_Domain.def("FirstPoint", (const gp_Pnt2d & (IntRes2d_Domain::*)() const) &IntRes2d_Domain::FirstPoint, "Returns the first point of the domain. The exception DomainError is raised if HasFirstPoint returns False.");
cls_IntRes2d_Domain.def("FirstTolerance", (Standard_Real (IntRes2d_Domain::*)() const) &IntRes2d_Domain::FirstTolerance, "Returns the tolerance of the first (left) bound. The exception DomainError is raised if HasFirstPoint returns False.");
cls_IntRes2d_Domain.def("HasLastPoint", (Standard_Boolean (IntRes2d_Domain::*)() const) &IntRes2d_Domain::HasLastPoint, "Returns True if the domain has a last point, i-e a point defining the highest admitted parameter on the curve.");
cls_IntRes2d_Domain.def("LastParameter", (Standard_Real (IntRes2d_Domain::*)() const) &IntRes2d_Domain::LastParameter, "Returns the parameter of the last point of the domain. The exception DomainError is raised if HasLastPoint returns False.");
cls_IntRes2d_Domain.def("LastPoint", (const gp_Pnt2d & (IntRes2d_Domain::*)() const) &IntRes2d_Domain::LastPoint, "Returns the last point of the domain. The exception DomainError is raised if HasLastPoint returns False.");
cls_IntRes2d_Domain.def("LastTolerance", (Standard_Real (IntRes2d_Domain::*)() const) &IntRes2d_Domain::LastTolerance, "Returns the tolerance of the last (right) bound. The exception DomainError is raised if HasLastPoint returns False.");
cls_IntRes2d_Domain.def("IsClosed", (Standard_Boolean (IntRes2d_Domain::*)() const) &IntRes2d_Domain::IsClosed, "Returns True if the domain is closed.");
cls_IntRes2d_Domain.def("EquivalentParameters", [](IntRes2d_Domain &self, Standard_Real & zero, Standard_Real & zeroplusperiod){ self.EquivalentParameters(zero, zeroplusperiod); return std::tuple<Standard_Real &, Standard_Real &>(zero, zeroplusperiod); }, "Returns Equivalent parameters if the domain is closed. Otherwise, the exception DomainError is raised.", py::arg("zero"), py::arg("zeroplusperiod"));

// Enums

}