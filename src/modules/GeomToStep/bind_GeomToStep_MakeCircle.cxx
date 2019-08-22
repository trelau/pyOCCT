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
#include <gp_Circ.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Circle.hxx>
#include <Geom2d_Circle.hxx>
#include <StepGeom_Circle.hxx>
#include <GeomToStep_MakeCircle.hxx>

void bind_GeomToStep_MakeCircle(py::module &mod){

py::class_<GeomToStep_MakeCircle, GeomToStep_Root> cls_GeomToStep_MakeCircle(mod, "GeomToStep_MakeCircle", "This class implements the mapping between classes Circle from Geom, and Circ from gp, and the class Circle from StepGeom which describes a circle from Prostep.");

// Constructors
cls_GeomToStep_MakeCircle.def(py::init<const gp_Circ &>(), py::arg("C"));
cls_GeomToStep_MakeCircle.def(py::init<const opencascade::handle<Geom_Circle> &>(), py::arg("C"));
cls_GeomToStep_MakeCircle.def(py::init<const opencascade::handle<Geom2d_Circle> &>(), py::arg("C"));

// Fields

// Methods
// cls_GeomToStep_MakeCircle.def_static("operator new_", (void * (*)(size_t)) &GeomToStep_MakeCircle::operator new, "None", py::arg("theSize"));
// cls_GeomToStep_MakeCircle.def_static("operator delete_", (void (*)(void *)) &GeomToStep_MakeCircle::operator delete, "None", py::arg("theAddress"));
// cls_GeomToStep_MakeCircle.def_static("operator new[]_", (void * (*)(size_t)) &GeomToStep_MakeCircle::operator new[], "None", py::arg("theSize"));
// cls_GeomToStep_MakeCircle.def_static("operator delete[]_", (void (*)(void *)) &GeomToStep_MakeCircle::operator delete[], "None", py::arg("theAddress"));
// cls_GeomToStep_MakeCircle.def_static("operator new_", (void * (*)(size_t, void *)) &GeomToStep_MakeCircle::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomToStep_MakeCircle.def_static("operator delete_", (void (*)(void *, void *)) &GeomToStep_MakeCircle::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomToStep_MakeCircle.def("Value", (const opencascade::handle<StepGeom_Circle> & (GeomToStep_MakeCircle::*)() const) &GeomToStep_MakeCircle::Value, "None");

// Enums

}