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
#include <GeomToStep_Root.hxx>

void bind_GeomToStep_Root(py::module &mod){

py::class_<GeomToStep_Root, std::unique_ptr<GeomToStep_Root, Deleter<GeomToStep_Root>>> cls_GeomToStep_Root(mod, "GeomToStep_Root", "This class implements the common services for all classes of GeomToStep which report error.");

// Constructors

// Fields

// Methods
// cls_GeomToStep_Root.def_static("operator new_", (void * (*)(size_t)) &GeomToStep_Root::operator new, "None", py::arg("theSize"));
// cls_GeomToStep_Root.def_static("operator delete_", (void (*)(void *)) &GeomToStep_Root::operator delete, "None", py::arg("theAddress"));
// cls_GeomToStep_Root.def_static("operator new[]_", (void * (*)(size_t)) &GeomToStep_Root::operator new[], "None", py::arg("theSize"));
// cls_GeomToStep_Root.def_static("operator delete[]_", (void (*)(void *)) &GeomToStep_Root::operator delete[], "None", py::arg("theAddress"));
// cls_GeomToStep_Root.def_static("operator new_", (void * (*)(size_t, void *)) &GeomToStep_Root::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomToStep_Root.def_static("operator delete_", (void (*)(void *, void *)) &GeomToStep_Root::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomToStep_Root.def("IsDone", (Standard_Boolean (GeomToStep_Root::*)() const) &GeomToStep_Root::IsDone, "None");

// Enums

}