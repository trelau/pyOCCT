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
#include <Poly_CoherentTriPtr.hxx>
#include <Poly_CoherentTriangle.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>

void bind_Poly_CoherentTriPtr(py::module &mod){

py::class_<Poly_CoherentTriPtr> cls_Poly_CoherentTriPtr(mod, "Poly_CoherentTriPtr", "Implementation of both list node for Poly_CoherentTriangle type and round double-linked list of these nodes.");

// Constructors
// cls_Poly_CoherentTriPtr.def(py::init<const Poly_CoherentTriangle &>(), py::arg("theTri"));

// Fields

// Methods
// cls_Poly_CoherentTriPtr.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &Poly_CoherentTriPtr::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_Poly_CoherentTriPtr.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &Poly_CoherentTriPtr::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_Poly_CoherentTriPtr.def("GetTriangle", (const Poly_CoherentTriangle & (Poly_CoherentTriPtr::*)() const) &Poly_CoherentTriPtr::GetTriangle, "Query the stored pointer to Triangle.");
cls_Poly_CoherentTriPtr.def("SetTriangle", (void (Poly_CoherentTriPtr::*)(const Poly_CoherentTriangle *)) &Poly_CoherentTriPtr::SetTriangle, "Initialize this instance with a pointer to triangle.", py::arg("pTri"));
cls_Poly_CoherentTriPtr.def("Next", (Poly_CoherentTriPtr & (Poly_CoherentTriPtr::*)() const) &Poly_CoherentTriPtr::Next, "Query the next pointer in the list.");
cls_Poly_CoherentTriPtr.def("Previous", (Poly_CoherentTriPtr & (Poly_CoherentTriPtr::*)() const) &Poly_CoherentTriPtr::Previous, "Query the previous pointer in the list.");
cls_Poly_CoherentTriPtr.def("Append", (void (Poly_CoherentTriPtr::*)(const Poly_CoherentTriangle *, const opencascade::handle<NCollection_BaseAllocator> &)) &Poly_CoherentTriPtr::Append, "Append a pointer to triangle into the list after the current instance.", py::arg("pTri"), py::arg("theA"));
cls_Poly_CoherentTriPtr.def("Prepend", (void (Poly_CoherentTriPtr::*)(const Poly_CoherentTriangle *, const opencascade::handle<NCollection_BaseAllocator> &)) &Poly_CoherentTriPtr::Prepend, "Prepend a pointer to triangle into the list before the current instance.", py::arg("pTri"), py::arg("theA"));
cls_Poly_CoherentTriPtr.def_static("Remove_", (void (*)(Poly_CoherentTriPtr *, const opencascade::handle<NCollection_BaseAllocator> &)) &Poly_CoherentTriPtr::Remove, "Remove a pointer to triangle from its list.", py::arg("thePtr"), py::arg("theA"));
cls_Poly_CoherentTriPtr.def_static("RemoveList_", (void (*)(Poly_CoherentTriPtr *, const opencascade::handle<NCollection_BaseAllocator> &)) &Poly_CoherentTriPtr::RemoveList, "Remove the list containing the given pointer to triangle.", py::arg("thePtr"), py::arg(""));

// Enums

}