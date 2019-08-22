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
#include <Standard_MMgrTBBalloc.hxx>

void bind_Standard_MMgrTBBalloc(py::module &mod){

py::class_<Standard_MMgrTBBalloc, Standard_MMgrRoot> cls_Standard_MMgrTBBalloc(mod, "Standard_MMgrTBBalloc", "Implementation of OCC memory manager which uses Intel TBB scalable allocator.");

// Constructors
cls_Standard_MMgrTBBalloc.def(py::init<>());
cls_Standard_MMgrTBBalloc.def(py::init<const Standard_Boolean>(), py::arg("aClear"));

// Fields

// Methods
cls_Standard_MMgrTBBalloc.def("Allocate", (Standard_Address (Standard_MMgrTBBalloc::*)(const Standard_Size)) &Standard_MMgrTBBalloc::Allocate, "Allocate aSize bytes", py::arg("aSize"));
cls_Standard_MMgrTBBalloc.def("Reallocate", (Standard_Address (Standard_MMgrTBBalloc::*)(Standard_Address, const Standard_Size)) &Standard_MMgrTBBalloc::Reallocate, "Reallocate aPtr to the size aSize. The new pointer is returned.", py::arg("thePtr"), py::arg("theSize"));
cls_Standard_MMgrTBBalloc.def("Free", (void (Standard_MMgrTBBalloc::*)(Standard_Address)) &Standard_MMgrTBBalloc::Free, "Free allocated memory", py::arg("thePtr"));

// Enums

}