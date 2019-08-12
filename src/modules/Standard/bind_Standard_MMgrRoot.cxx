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
#include <Standard_TypeDef.hxx>
#include <Standard_MMgrRoot.hxx>

void bind_Standard_MMgrRoot(py::module &mod){

py::class_<Standard_MMgrRoot, std::unique_ptr<Standard_MMgrRoot, Deleter<Standard_MMgrRoot>>> cls_Standard_MMgrRoot(mod, "Standard_MMgrRoot", "Root class for Open CASCADE mmemory managers. Defines only abstract interface functions.");

// Fields

// Methods
cls_Standard_MMgrRoot.def("Allocate", (Standard_Address (Standard_MMgrRoot::*)(const Standard_Size)) &Standard_MMgrRoot::Allocate, "Allocate specified number of bytes. The actually allocated space should be rounded up to double word size (4 bytes), as this is expected by implementation of some classes in OCC (e.g. TCollection_AsciiString)", py::arg("theSize"));
cls_Standard_MMgrRoot.def("Reallocate", (Standard_Address (Standard_MMgrRoot::*)(Standard_Address, const Standard_Size)) &Standard_MMgrRoot::Reallocate, "Reallocate previously allocated memory to contain at least theSize bytes. In case of success, new pointer is returned.", py::arg("thePtr"), py::arg("theSize"));
cls_Standard_MMgrRoot.def("Free", (void (Standard_MMgrRoot::*)(Standard_Address)) &Standard_MMgrRoot::Free, "Frees previously allocated memory at specified address.", py::arg("thePtr"));
cls_Standard_MMgrRoot.def("Purge", [](Standard_MMgrRoot &self) -> Standard_Integer { return self.Purge(); });
cls_Standard_MMgrRoot.def("Purge", (Standard_Integer (Standard_MMgrRoot::*)(Standard_Boolean)) &Standard_MMgrRoot::Purge, "Purge internally cached unused memory blocks (if any) by releasing them to the operating system. Must return non-zero if some memory has been actually released, or zero otherwise.", py::arg("isDestroyed"));

// Enums

}