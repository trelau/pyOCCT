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
#include <Geom2d_Parabola.hxx>
#include <Geom_Parabola.hxx>
#include <StepGeom_Parabola.hxx>
#include <GeomToStep_MakeParabola.hxx>

void bind_GeomToStep_MakeParabola(py::module &mod){

py::class_<GeomToStep_MakeParabola, std::unique_ptr<GeomToStep_MakeParabola>, GeomToStep_Root> cls_GeomToStep_MakeParabola(mod, "GeomToStep_MakeParabola", "This class implements the mapping between the class Parabola from Geom and the class Parabola from StepGeom which describes a Parabola from ProSTEP");

// Constructors
cls_GeomToStep_MakeParabola.def(py::init<const opencascade::handle<Geom2d_Parabola> &>(), py::arg("C"));
cls_GeomToStep_MakeParabola.def(py::init<const opencascade::handle<Geom_Parabola> &>(), py::arg("C"));

// Fields

// Methods
// cls_GeomToStep_MakeParabola.def_static("operator new_", (void * (*)(size_t)) &GeomToStep_MakeParabola::operator new, "None", py::arg("theSize"));
// cls_GeomToStep_MakeParabola.def_static("operator delete_", (void (*)(void *)) &GeomToStep_MakeParabola::operator delete, "None", py::arg("theAddress"));
// cls_GeomToStep_MakeParabola.def_static("operator new[]_", (void * (*)(size_t)) &GeomToStep_MakeParabola::operator new[], "None", py::arg("theSize"));
// cls_GeomToStep_MakeParabola.def_static("operator delete[]_", (void (*)(void *)) &GeomToStep_MakeParabola::operator delete[], "None", py::arg("theAddress"));
// cls_GeomToStep_MakeParabola.def_static("operator new_", (void * (*)(size_t, void *)) &GeomToStep_MakeParabola::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomToStep_MakeParabola.def_static("operator delete_", (void (*)(void *, void *)) &GeomToStep_MakeParabola::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomToStep_MakeParabola.def("Value", (const opencascade::handle<StepGeom_Parabola> & (GeomToStep_MakeParabola::*)() const) &GeomToStep_MakeParabola::Value, "None");

// Enums

}