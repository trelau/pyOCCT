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
#include <TColStd_ListOfInteger.hxx>
#include <Aspect_GenId.hxx>

void bind_Aspect_GenId(py::module &mod){

py::class_<Aspect_GenId, std::unique_ptr<Aspect_GenId, Deleter<Aspect_GenId>>> cls_Aspect_GenId(mod, "Aspect_GenId", "This class permits the creation and control of integer identifiers.");

// Constructors
cls_Aspect_GenId.def(py::init<>());
cls_Aspect_GenId.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLow"), py::arg("theUpper"));

// Fields

// Methods
// cls_Aspect_GenId.def_static("operator new_", (void * (*)(size_t)) &Aspect_GenId::operator new, "None", py::arg("theSize"));
// cls_Aspect_GenId.def_static("operator delete_", (void (*)(void *)) &Aspect_GenId::operator delete, "None", py::arg("theAddress"));
// cls_Aspect_GenId.def_static("operator new[]_", (void * (*)(size_t)) &Aspect_GenId::operator new[], "None", py::arg("theSize"));
// cls_Aspect_GenId.def_static("operator delete[]_", (void (*)(void *)) &Aspect_GenId::operator delete[], "None", py::arg("theAddress"));
// cls_Aspect_GenId.def_static("operator new_", (void * (*)(size_t, void *)) &Aspect_GenId::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Aspect_GenId.def_static("operator delete_", (void (*)(void *, void *)) &Aspect_GenId::operator delete, "None", py::arg(""), py::arg(""));
cls_Aspect_GenId.def("Free", (void (Aspect_GenId::*)()) &Aspect_GenId::Free, "Free all identifiers - make the whole range available again.");
cls_Aspect_GenId.def("Free", (void (Aspect_GenId::*)(const Standard_Integer)) &Aspect_GenId::Free, "Free specified identifier. Warning - method has no protection against double-freeing!", py::arg("theId"));
cls_Aspect_GenId.def("HasFree", (Standard_Boolean (Aspect_GenId::*)() const) &Aspect_GenId::HasFree, "Returns true if there are available identifiers in range.");
cls_Aspect_GenId.def("Available", (Standard_Integer (Aspect_GenId::*)() const) &Aspect_GenId::Available, "Returns the number of available identifiers.");
cls_Aspect_GenId.def("Lower", (Standard_Integer (Aspect_GenId::*)() const) &Aspect_GenId::Lower, "Returns the lower identifier in range.");
cls_Aspect_GenId.def("Next", (Standard_Integer (Aspect_GenId::*)()) &Aspect_GenId::Next, "Returns the next available identifier. Warning: Raises IdentDefinitionError if all identifiers are busy.");
cls_Aspect_GenId.def("Upper", (Standard_Integer (Aspect_GenId::*)() const) &Aspect_GenId::Upper, "Returns the upper identifier in range.");

// Enums

}