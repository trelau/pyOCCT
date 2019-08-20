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
#include <Standard_Handle.hxx>
#include <Geom2d_Hyperbola.hxx>
#include <Geom_Hyperbola.hxx>
#include <StepGeom_Hyperbola.hxx>
#include <GeomToStep_MakeHyperbola.hxx>

void bind_GeomToStep_MakeHyperbola(py::module &mod){

py::class_<GeomToStep_MakeHyperbola, std::unique_ptr<GeomToStep_MakeHyperbola>, GeomToStep_Root> cls_GeomToStep_MakeHyperbola(mod, "GeomToStep_MakeHyperbola", "This class implements the mapping between the class Hyperbola from Geom and the class Hyperbola from StepGeom which describes a Hyperbola from ProSTEP");

// Constructors
cls_GeomToStep_MakeHyperbola.def(py::init<const opencascade::handle<Geom2d_Hyperbola> &>(), py::arg("C"));
cls_GeomToStep_MakeHyperbola.def(py::init<const opencascade::handle<Geom_Hyperbola> &>(), py::arg("C"));

// Fields

// Methods
// cls_GeomToStep_MakeHyperbola.def_static("operator new_", (void * (*)(size_t)) &GeomToStep_MakeHyperbola::operator new, "None", py::arg("theSize"));
// cls_GeomToStep_MakeHyperbola.def_static("operator delete_", (void (*)(void *)) &GeomToStep_MakeHyperbola::operator delete, "None", py::arg("theAddress"));
// cls_GeomToStep_MakeHyperbola.def_static("operator new[]_", (void * (*)(size_t)) &GeomToStep_MakeHyperbola::operator new[], "None", py::arg("theSize"));
// cls_GeomToStep_MakeHyperbola.def_static("operator delete[]_", (void (*)(void *)) &GeomToStep_MakeHyperbola::operator delete[], "None", py::arg("theAddress"));
// cls_GeomToStep_MakeHyperbola.def_static("operator new_", (void * (*)(size_t, void *)) &GeomToStep_MakeHyperbola::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomToStep_MakeHyperbola.def_static("operator delete_", (void (*)(void *, void *)) &GeomToStep_MakeHyperbola::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomToStep_MakeHyperbola.def("Value", (const opencascade::handle<StepGeom_Hyperbola> & (GeomToStep_MakeHyperbola::*)() const) &GeomToStep_MakeHyperbola::Value, "None");

// Enums

}