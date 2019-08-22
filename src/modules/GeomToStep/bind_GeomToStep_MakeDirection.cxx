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
#include <gp_Dir.hxx>
#include <gp_Dir2d.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Direction.hxx>
#include <Geom2d_Direction.hxx>
#include <StepGeom_Direction.hxx>
#include <GeomToStep_MakeDirection.hxx>

void bind_GeomToStep_MakeDirection(py::module &mod){

py::class_<GeomToStep_MakeDirection, GeomToStep_Root> cls_GeomToStep_MakeDirection(mod, "GeomToStep_MakeDirection", "This class implements the mapping between classes Direction from Geom, Geom2d and Dir, Dir2d from gp, and the class Direction from StepGeom which describes a direction from Prostep.");

// Constructors
cls_GeomToStep_MakeDirection.def(py::init<const gp_Dir &>(), py::arg("D"));
cls_GeomToStep_MakeDirection.def(py::init<const gp_Dir2d &>(), py::arg("D"));
cls_GeomToStep_MakeDirection.def(py::init<const opencascade::handle<Geom_Direction> &>(), py::arg("D"));
cls_GeomToStep_MakeDirection.def(py::init<const opencascade::handle<Geom2d_Direction> &>(), py::arg("D"));

// Fields

// Methods
// cls_GeomToStep_MakeDirection.def_static("operator new_", (void * (*)(size_t)) &GeomToStep_MakeDirection::operator new, "None", py::arg("theSize"));
// cls_GeomToStep_MakeDirection.def_static("operator delete_", (void (*)(void *)) &GeomToStep_MakeDirection::operator delete, "None", py::arg("theAddress"));
// cls_GeomToStep_MakeDirection.def_static("operator new[]_", (void * (*)(size_t)) &GeomToStep_MakeDirection::operator new[], "None", py::arg("theSize"));
// cls_GeomToStep_MakeDirection.def_static("operator delete[]_", (void (*)(void *)) &GeomToStep_MakeDirection::operator delete[], "None", py::arg("theAddress"));
// cls_GeomToStep_MakeDirection.def_static("operator new_", (void * (*)(size_t, void *)) &GeomToStep_MakeDirection::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomToStep_MakeDirection.def_static("operator delete_", (void (*)(void *, void *)) &GeomToStep_MakeDirection::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomToStep_MakeDirection.def("Value", (const opencascade::handle<StepGeom_Direction> & (GeomToStep_MakeDirection::*)() const) &GeomToStep_MakeDirection::Value, "None");

// Enums

}