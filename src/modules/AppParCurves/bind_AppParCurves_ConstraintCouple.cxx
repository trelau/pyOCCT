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
#include <AppParCurves_Constraint.hxx>
#include <AppParCurves_ConstraintCouple.hxx>

void bind_AppParCurves_ConstraintCouple(py::module &mod){

py::class_<AppParCurves_ConstraintCouple> cls_AppParCurves_ConstraintCouple(mod, "AppParCurves_ConstraintCouple", "associates an index and a constraint for an object. This couple is used by AppDef_TheVariational when performing approximations.");

// Constructors
cls_AppParCurves_ConstraintCouple.def(py::init<>());
cls_AppParCurves_ConstraintCouple.def(py::init<const Standard_Integer, const AppParCurves_Constraint>(), py::arg("TheIndex"), py::arg("Cons"));

// Fields

// Methods
// cls_AppParCurves_ConstraintCouple.def_static("operator new_", (void * (*)(size_t)) &AppParCurves_ConstraintCouple::operator new, "None", py::arg("theSize"));
// cls_AppParCurves_ConstraintCouple.def_static("operator delete_", (void (*)(void *)) &AppParCurves_ConstraintCouple::operator delete, "None", py::arg("theAddress"));
// cls_AppParCurves_ConstraintCouple.def_static("operator new[]_", (void * (*)(size_t)) &AppParCurves_ConstraintCouple::operator new[], "None", py::arg("theSize"));
// cls_AppParCurves_ConstraintCouple.def_static("operator delete[]_", (void (*)(void *)) &AppParCurves_ConstraintCouple::operator delete[], "None", py::arg("theAddress"));
// cls_AppParCurves_ConstraintCouple.def_static("operator new_", (void * (*)(size_t, void *)) &AppParCurves_ConstraintCouple::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AppParCurves_ConstraintCouple.def_static("operator delete_", (void (*)(void *, void *)) &AppParCurves_ConstraintCouple::operator delete, "None", py::arg(""), py::arg(""));
cls_AppParCurves_ConstraintCouple.def("Index", (Standard_Integer (AppParCurves_ConstraintCouple::*)() const) &AppParCurves_ConstraintCouple::Index, "returns the index of the constraint object.");
cls_AppParCurves_ConstraintCouple.def("Constraint", (AppParCurves_Constraint (AppParCurves_ConstraintCouple::*)() const) &AppParCurves_ConstraintCouple::Constraint, "returns the constraint of the object.");
cls_AppParCurves_ConstraintCouple.def("SetIndex", (void (AppParCurves_ConstraintCouple::*)(const Standard_Integer)) &AppParCurves_ConstraintCouple::SetIndex, "Changes the index of the constraint object.", py::arg("TheIndex"));
cls_AppParCurves_ConstraintCouple.def("SetConstraint", (void (AppParCurves_ConstraintCouple::*)(const AppParCurves_Constraint)) &AppParCurves_ConstraintCouple::SetConstraint, "Changes the constraint of the object.", py::arg("Cons"));

// Enums

}