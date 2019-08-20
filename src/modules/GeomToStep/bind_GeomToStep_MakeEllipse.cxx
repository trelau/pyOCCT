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
#include <gp_Elips.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Ellipse.hxx>
#include <Geom2d_Ellipse.hxx>
#include <StepGeom_Ellipse.hxx>
#include <GeomToStep_MakeEllipse.hxx>

void bind_GeomToStep_MakeEllipse(py::module &mod){

py::class_<GeomToStep_MakeEllipse, std::unique_ptr<GeomToStep_MakeEllipse>, GeomToStep_Root> cls_GeomToStep_MakeEllipse(mod, "GeomToStep_MakeEllipse", "This class implements the mapping between classes Ellipse from Geom, and Circ from gp, and the class Ellipse from StepGeom which describes a Ellipse from Prostep.");

// Constructors
cls_GeomToStep_MakeEllipse.def(py::init<const gp_Elips &>(), py::arg("C"));
cls_GeomToStep_MakeEllipse.def(py::init<const opencascade::handle<Geom_Ellipse> &>(), py::arg("C"));
cls_GeomToStep_MakeEllipse.def(py::init<const opencascade::handle<Geom2d_Ellipse> &>(), py::arg("C"));

// Fields

// Methods
// cls_GeomToStep_MakeEllipse.def_static("operator new_", (void * (*)(size_t)) &GeomToStep_MakeEllipse::operator new, "None", py::arg("theSize"));
// cls_GeomToStep_MakeEllipse.def_static("operator delete_", (void (*)(void *)) &GeomToStep_MakeEllipse::operator delete, "None", py::arg("theAddress"));
// cls_GeomToStep_MakeEllipse.def_static("operator new[]_", (void * (*)(size_t)) &GeomToStep_MakeEllipse::operator new[], "None", py::arg("theSize"));
// cls_GeomToStep_MakeEllipse.def_static("operator delete[]_", (void (*)(void *)) &GeomToStep_MakeEllipse::operator delete[], "None", py::arg("theAddress"));
// cls_GeomToStep_MakeEllipse.def_static("operator new_", (void * (*)(size_t, void *)) &GeomToStep_MakeEllipse::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomToStep_MakeEllipse.def_static("operator delete_", (void (*)(void *, void *)) &GeomToStep_MakeEllipse::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomToStep_MakeEllipse.def("Value", (const opencascade::handle<StepGeom_Ellipse> & (GeomToStep_MakeEllipse::*)() const) &GeomToStep_MakeEllipse::Value, "None");

// Enums

}