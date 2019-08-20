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
#include <Standard_MMgrOpt.hxx>
#include <Standard_Mutex.hxx>

void bind_Standard_MMgrOpt(py::module &mod){

py::class_<Standard_MMgrOpt, std::unique_ptr<Standard_MMgrOpt>, Standard_MMgrRoot> cls_Standard_MMgrOpt(mod, "Standard_MMgrOpt", "Open CASCADE memory manager optimized for speed.");

// Constructors
cls_Standard_MMgrOpt.def(py::init<>());
cls_Standard_MMgrOpt.def(py::init<const Standard_Boolean>(), py::arg("aClear"));
cls_Standard_MMgrOpt.def(py::init<const Standard_Boolean, const Standard_Boolean>(), py::arg("aClear"), py::arg("aMMap"));
cls_Standard_MMgrOpt.def(py::init<const Standard_Boolean, const Standard_Boolean, const Standard_Size>(), py::arg("aClear"), py::arg("aMMap"), py::arg("aCellSize"));
cls_Standard_MMgrOpt.def(py::init<const Standard_Boolean, const Standard_Boolean, const Standard_Size, const Standard_Integer>(), py::arg("aClear"), py::arg("aMMap"), py::arg("aCellSize"), py::arg("aNbPages"));
cls_Standard_MMgrOpt.def(py::init<const Standard_Boolean, const Standard_Boolean, const Standard_Size, const Standard_Integer, const Standard_Size>(), py::arg("aClear"), py::arg("aMMap"), py::arg("aCellSize"), py::arg("aNbPages"), py::arg("aThreshold"));

// Fields

// Methods
cls_Standard_MMgrOpt.def("Allocate", (Standard_Address (Standard_MMgrOpt::*)(const Standard_Size)) &Standard_MMgrOpt::Allocate, "Allocate aSize bytes; see class description above", py::arg("aSize"));
cls_Standard_MMgrOpt.def("Reallocate", (Standard_Address (Standard_MMgrOpt::*)(Standard_Address, const Standard_Size)) &Standard_MMgrOpt::Reallocate, "Reallocate previously allocated aPtr to a new size; new address is returned. In case that aPtr is null, the function behaves exactly as Allocate.", py::arg("thePtr"), py::arg("theSize"));
cls_Standard_MMgrOpt.def("Free", (void (Standard_MMgrOpt::*)(Standard_Address)) &Standard_MMgrOpt::Free, "Free previously allocated block. Note that block can not all blocks are released to the OS by this method (see class description)", py::arg("thePtr"));
cls_Standard_MMgrOpt.def("Purge", (Standard_Integer (Standard_MMgrOpt::*)(Standard_Boolean)) &Standard_MMgrOpt::Purge, "Release medium-sized blocks of memory in free lists to the system. Returns number of actually freed blocks", py::arg("isDestroyed"));
cls_Standard_MMgrOpt.def_static("SetCallBackFunction_", (void (*)(Standard_MMgrOpt::TPCallBackFunc)) &Standard_MMgrOpt::SetCallBackFunction, "Set the callback function. You may pass 0 there to turn off the callback. The callback function, if set, will be automatically called from within Allocate and Free methods.", py::arg("pFunc"));

// Enums

}