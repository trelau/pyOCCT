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
#include <BRepLib_Command.hxx>

void bind_BRepLib_Command(py::module &mod){

py::class_<BRepLib_Command> cls_BRepLib_Command(mod, "BRepLib_Command", "Root class for all commands in BRepLib.");

// Constructors

// Fields

// Methods
// cls_BRepLib_Command.def_static("operator new_", (void * (*)(size_t)) &BRepLib_Command::operator new, "None", py::arg("theSize"));
// cls_BRepLib_Command.def_static("operator delete_", (void (*)(void *)) &BRepLib_Command::operator delete, "None", py::arg("theAddress"));
// cls_BRepLib_Command.def_static("operator new[]_", (void * (*)(size_t)) &BRepLib_Command::operator new[], "None", py::arg("theSize"));
// cls_BRepLib_Command.def_static("operator delete[]_", (void (*)(void *)) &BRepLib_Command::operator delete[], "None", py::arg("theAddress"));
// cls_BRepLib_Command.def_static("operator new_", (void * (*)(size_t, void *)) &BRepLib_Command::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepLib_Command.def_static("operator delete_", (void (*)(void *, void *)) &BRepLib_Command::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepLib_Command.def("IsDone", (Standard_Boolean (BRepLib_Command::*)() const) &BRepLib_Command::IsDone, "None");
cls_BRepLib_Command.def("Check", (void (BRepLib_Command::*)() const) &BRepLib_Command::Check, "Raises NotDone if done is false.");

// Enums

}