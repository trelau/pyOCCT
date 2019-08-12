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
#include <Standard_Handle.hxx>
#include <PrsMgr_Presentation.hxx>
#include <Standard_TypeDef.hxx>
#include <PrsMgr_ModedPresentation.hxx>

void bind_PrsMgr_ModedPresentation(py::module &mod){

py::class_<PrsMgr_ModedPresentation, std::unique_ptr<PrsMgr_ModedPresentation, Deleter<PrsMgr_ModedPresentation>>> cls_PrsMgr_ModedPresentation(mod, "PrsMgr_ModedPresentation", "None");

// Constructors
cls_PrsMgr_ModedPresentation.def(py::init<>());
cls_PrsMgr_ModedPresentation.def(py::init<const opencascade::handle<PrsMgr_Presentation> &, const Standard_Integer>(), py::arg("thePrs"), py::arg("theMode"));

// Fields

// Methods
// cls_PrsMgr_ModedPresentation.def_static("operator new_", (void * (*)(size_t)) &PrsMgr_ModedPresentation::operator new, "None", py::arg("theSize"));
// cls_PrsMgr_ModedPresentation.def_static("operator delete_", (void (*)(void *)) &PrsMgr_ModedPresentation::operator delete, "None", py::arg("theAddress"));
// cls_PrsMgr_ModedPresentation.def_static("operator new[]_", (void * (*)(size_t)) &PrsMgr_ModedPresentation::operator new[], "None", py::arg("theSize"));
// cls_PrsMgr_ModedPresentation.def_static("operator delete[]_", (void (*)(void *)) &PrsMgr_ModedPresentation::operator delete[], "None", py::arg("theAddress"));
// cls_PrsMgr_ModedPresentation.def_static("operator new_", (void * (*)(size_t, void *)) &PrsMgr_ModedPresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_PrsMgr_ModedPresentation.def_static("operator delete_", (void (*)(void *, void *)) &PrsMgr_ModedPresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_PrsMgr_ModedPresentation.def("Presentation", (const opencascade::handle<PrsMgr_Presentation> & (PrsMgr_ModedPresentation::*)() const) &PrsMgr_ModedPresentation::Presentation, "None");
cls_PrsMgr_ModedPresentation.def("Mode", (Standard_Integer (PrsMgr_ModedPresentation::*)() const) &PrsMgr_ModedPresentation::Mode, "None");

// Enums

}