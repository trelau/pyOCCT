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
#include <Hatch_Line.hxx>
#include <Hatch_Hatcher.hxx>
#include <Hatch_Parameter.hxx>

void bind_Hatch_Parameter(py::module &mod){

py::class_<Hatch_Parameter, std::unique_ptr<Hatch_Parameter, Deleter<Hatch_Parameter>>> cls_Hatch_Parameter(mod, "Hatch_Parameter", "Stores an intersection on a line represented by :");

// Constructors
cls_Hatch_Parameter.def(py::init<>());
cls_Hatch_Parameter.def(py::init<const Standard_Real, const Standard_Boolean>(), py::arg("Par1"), py::arg("Start"));
cls_Hatch_Parameter.def(py::init<const Standard_Real, const Standard_Boolean, const Standard_Integer>(), py::arg("Par1"), py::arg("Start"), py::arg("Index"));
cls_Hatch_Parameter.def(py::init<const Standard_Real, const Standard_Boolean, const Standard_Integer, const Standard_Real>(), py::arg("Par1"), py::arg("Start"), py::arg("Index"), py::arg("Par2"));

// Fields

// Methods
// cls_Hatch_Parameter.def_static("operator new_", (void * (*)(size_t)) &Hatch_Parameter::operator new, "None", py::arg("theSize"));
// cls_Hatch_Parameter.def_static("operator delete_", (void (*)(void *)) &Hatch_Parameter::operator delete, "None", py::arg("theAddress"));
// cls_Hatch_Parameter.def_static("operator new[]_", (void * (*)(size_t)) &Hatch_Parameter::operator new[], "None", py::arg("theSize"));
// cls_Hatch_Parameter.def_static("operator delete[]_", (void (*)(void *)) &Hatch_Parameter::operator delete[], "None", py::arg("theAddress"));
// cls_Hatch_Parameter.def_static("operator new_", (void * (*)(size_t, void *)) &Hatch_Parameter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Hatch_Parameter.def_static("operator delete_", (void (*)(void *, void *)) &Hatch_Parameter::operator delete, "None", py::arg(""), py::arg(""));

// Enums

}