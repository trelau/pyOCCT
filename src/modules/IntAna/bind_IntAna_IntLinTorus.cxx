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
#include <gp_Lin.hxx>
#include <gp_Torus.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <IntAna_IntLinTorus.hxx>

void bind_IntAna_IntLinTorus(py::module &mod){

py::class_<IntAna_IntLinTorus> cls_IntAna_IntLinTorus(mod, "IntAna_IntLinTorus", "Intersection between a line and a torus.");

// Constructors
cls_IntAna_IntLinTorus.def(py::init<>());
cls_IntAna_IntLinTorus.def(py::init<const gp_Lin &, const gp_Torus &>(), py::arg("L"), py::arg("T"));

// Fields

// Methods
// cls_IntAna_IntLinTorus.def_static("operator new_", (void * (*)(size_t)) &IntAna_IntLinTorus::operator new, "None", py::arg("theSize"));
// cls_IntAna_IntLinTorus.def_static("operator delete_", (void (*)(void *)) &IntAna_IntLinTorus::operator delete, "None", py::arg("theAddress"));
// cls_IntAna_IntLinTorus.def_static("operator new[]_", (void * (*)(size_t)) &IntAna_IntLinTorus::operator new[], "None", py::arg("theSize"));
// cls_IntAna_IntLinTorus.def_static("operator delete[]_", (void (*)(void *)) &IntAna_IntLinTorus::operator delete[], "None", py::arg("theAddress"));
// cls_IntAna_IntLinTorus.def_static("operator new_", (void * (*)(size_t, void *)) &IntAna_IntLinTorus::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntAna_IntLinTorus.def_static("operator delete_", (void (*)(void *, void *)) &IntAna_IntLinTorus::operator delete, "None", py::arg(""), py::arg(""));
cls_IntAna_IntLinTorus.def("Perform", (void (IntAna_IntLinTorus::*)(const gp_Lin &, const gp_Torus &)) &IntAna_IntLinTorus::Perform, "Intersects a line and a torus.", py::arg("L"), py::arg("T"));
cls_IntAna_IntLinTorus.def("IsDone", (Standard_Boolean (IntAna_IntLinTorus::*)() const) &IntAna_IntLinTorus::IsDone, "Returns True if the computation was successful.");
cls_IntAna_IntLinTorus.def("NbPoints", (Standard_Integer (IntAna_IntLinTorus::*)() const) &IntAna_IntLinTorus::NbPoints, "Returns the number of intersection points.");
cls_IntAna_IntLinTorus.def("Value", (const gp_Pnt & (IntAna_IntLinTorus::*)(const Standard_Integer) const) &IntAna_IntLinTorus::Value, "Returns the intersection point of range Index.", py::arg("Index"));
cls_IntAna_IntLinTorus.def("ParamOnLine", (Standard_Real (IntAna_IntLinTorus::*)(const Standard_Integer) const) &IntAna_IntLinTorus::ParamOnLine, "Returns the parameter on the line of the intersection point of range Index.", py::arg("Index"));
cls_IntAna_IntLinTorus.def("ParamOnTorus", [](IntAna_IntLinTorus &self, const Standard_Integer Index, Standard_Real & FI, Standard_Real & THETA){ self.ParamOnTorus(Index, FI, THETA); return std::tuple<Standard_Real &, Standard_Real &>(FI, THETA); }, "Returns the parameters on the torus of the intersection point of range Index.", py::arg("Index"), py::arg("FI"), py::arg("THETA"));

// Enums

}