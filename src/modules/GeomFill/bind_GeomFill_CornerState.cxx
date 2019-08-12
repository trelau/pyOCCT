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
#include <GeomFill_CornerState.hxx>

void bind_GeomFill_CornerState(py::module &mod){

py::class_<GeomFill_CornerState, std::unique_ptr<GeomFill_CornerState, Deleter<GeomFill_CornerState>>> cls_GeomFill_CornerState(mod, "GeomFill_CornerState", "Class (should be a structure) storing the informations about continuity, normals parallelism, coons conditions and bounds tangents angle on the corner of contour to be filled.");

// Constructors
cls_GeomFill_CornerState.def(py::init<>());

// Fields

// Methods
// cls_GeomFill_CornerState.def_static("operator new_", (void * (*)(size_t)) &GeomFill_CornerState::operator new, "None", py::arg("theSize"));
// cls_GeomFill_CornerState.def_static("operator delete_", (void (*)(void *)) &GeomFill_CornerState::operator delete, "None", py::arg("theAddress"));
// cls_GeomFill_CornerState.def_static("operator new[]_", (void * (*)(size_t)) &GeomFill_CornerState::operator new[], "None", py::arg("theSize"));
// cls_GeomFill_CornerState.def_static("operator delete[]_", (void (*)(void *)) &GeomFill_CornerState::operator delete[], "None", py::arg("theAddress"));
// cls_GeomFill_CornerState.def_static("operator new_", (void * (*)(size_t, void *)) &GeomFill_CornerState::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomFill_CornerState.def_static("operator delete_", (void (*)(void *, void *)) &GeomFill_CornerState::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomFill_CornerState.def("Gap", (Standard_Real (GeomFill_CornerState::*)() const) &GeomFill_CornerState::Gap, "None");
cls_GeomFill_CornerState.def("Gap", (void (GeomFill_CornerState::*)(const Standard_Real)) &GeomFill_CornerState::Gap, "None", py::arg("G"));
cls_GeomFill_CornerState.def("TgtAng", (Standard_Real (GeomFill_CornerState::*)() const) &GeomFill_CornerState::TgtAng, "None");
cls_GeomFill_CornerState.def("TgtAng", (void (GeomFill_CornerState::*)(const Standard_Real)) &GeomFill_CornerState::TgtAng, "None", py::arg("Ang"));
cls_GeomFill_CornerState.def("HasConstraint", (Standard_Boolean (GeomFill_CornerState::*)() const) &GeomFill_CornerState::HasConstraint, "None");
cls_GeomFill_CornerState.def("Constraint", (void (GeomFill_CornerState::*)()) &GeomFill_CornerState::Constraint, "None");
cls_GeomFill_CornerState.def("NorAng", (Standard_Real (GeomFill_CornerState::*)() const) &GeomFill_CornerState::NorAng, "None");
cls_GeomFill_CornerState.def("NorAng", (void (GeomFill_CornerState::*)(const Standard_Real)) &GeomFill_CornerState::NorAng, "None", py::arg("Ang"));
cls_GeomFill_CornerState.def("IsToKill", [](GeomFill_CornerState &self, Standard_Real & Scal){ Standard_Boolean rv = self.IsToKill(Scal); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Scal); }, "None", py::arg("Scal"));
cls_GeomFill_CornerState.def("DoKill", (void (GeomFill_CornerState::*)(const Standard_Real)) &GeomFill_CornerState::DoKill, "None", py::arg("Scal"));

// Enums

}