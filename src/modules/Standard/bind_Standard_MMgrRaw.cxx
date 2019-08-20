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
#include <Standard_MMgrRoot.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_MMgrRaw.hxx>

void bind_Standard_MMgrRaw(py::module &mod){

py::class_<Standard_MMgrRaw, std::unique_ptr<Standard_MMgrRaw>, Standard_MMgrRoot> cls_Standard_MMgrRaw(mod, "Standard_MMgrRaw", "Implementation of raw OCC memory manager which uses standard C functions: malloc (or calloc), free and realloc without any optimization");

// Constructors
cls_Standard_MMgrRaw.def(py::init<>());
cls_Standard_MMgrRaw.def(py::init<const Standard_Boolean>(), py::arg("aClear"));

// Fields

// Methods
cls_Standard_MMgrRaw.def("Allocate", (Standard_Address (Standard_MMgrRaw::*)(const Standard_Size)) &Standard_MMgrRaw::Allocate, "Allocate aSize bytes", py::arg("aSize"));
cls_Standard_MMgrRaw.def("Reallocate", (Standard_Address (Standard_MMgrRaw::*)(Standard_Address, const Standard_Size)) &Standard_MMgrRaw::Reallocate, "Reallocate aPtr to the size aSize. The new pointer is returned.", py::arg("thePtr"), py::arg("theSize"));
cls_Standard_MMgrRaw.def("Free", (void (Standard_MMgrRaw::*)(Standard_Address)) &Standard_MMgrRaw::Free, "Free allocated memory. The pointer is nullified.", py::arg("thePtr"));

// Enums

}