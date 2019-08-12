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
#include <GeomToStep_Root.hxx>
#include <Standard.hxx>
#include <gp_Vec.hxx>
#include <gp_Vec2d.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Vector.hxx>
#include <Geom2d_Vector.hxx>
#include <StepGeom_Vector.hxx>
#include <GeomToStep_MakeVector.hxx>

void bind_GeomToStep_MakeVector(py::module &mod){

py::class_<GeomToStep_MakeVector, std::unique_ptr<GeomToStep_MakeVector, Deleter<GeomToStep_MakeVector>>, GeomToStep_Root> cls_GeomToStep_MakeVector(mod, "GeomToStep_MakeVector", "This class implements the mapping between classes Vector from Geom, Geom2d and Vec, Vec2d from gp, and the class Vector from StepGeom which describes a Vector from Prostep.");

// Constructors
cls_GeomToStep_MakeVector.def(py::init<const gp_Vec &>(), py::arg("V"));
cls_GeomToStep_MakeVector.def(py::init<const gp_Vec2d &>(), py::arg("V"));
cls_GeomToStep_MakeVector.def(py::init<const opencascade::handle<Geom_Vector> &>(), py::arg("V"));
cls_GeomToStep_MakeVector.def(py::init<const opencascade::handle<Geom2d_Vector> &>(), py::arg("V"));

// Fields

// Methods
// cls_GeomToStep_MakeVector.def_static("operator new_", (void * (*)(size_t)) &GeomToStep_MakeVector::operator new, "None", py::arg("theSize"));
// cls_GeomToStep_MakeVector.def_static("operator delete_", (void (*)(void *)) &GeomToStep_MakeVector::operator delete, "None", py::arg("theAddress"));
// cls_GeomToStep_MakeVector.def_static("operator new[]_", (void * (*)(size_t)) &GeomToStep_MakeVector::operator new[], "None", py::arg("theSize"));
// cls_GeomToStep_MakeVector.def_static("operator delete[]_", (void (*)(void *)) &GeomToStep_MakeVector::operator delete[], "None", py::arg("theAddress"));
// cls_GeomToStep_MakeVector.def_static("operator new_", (void * (*)(size_t, void *)) &GeomToStep_MakeVector::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomToStep_MakeVector.def_static("operator delete_", (void (*)(void *, void *)) &GeomToStep_MakeVector::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomToStep_MakeVector.def("Value", (const opencascade::handle<StepGeom_Vector> & (GeomToStep_MakeVector::*)() const) &GeomToStep_MakeVector::Value, "None");

// Enums

}