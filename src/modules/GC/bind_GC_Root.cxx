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
#include <gce_ErrorType.hxx>
#include <GC_Root.hxx>

void bind_GC_Root(py::module &mod){

py::class_<GC_Root, std::unique_ptr<GC_Root, Deleter<GC_Root>>> cls_GC_Root(mod, "GC_Root", "This class implements the common services for all classes of gce which report error.");

// Constructors

// Fields

// Methods
// cls_GC_Root.def_static("operator new_", (void * (*)(size_t)) &GC_Root::operator new, "None", py::arg("theSize"));
// cls_GC_Root.def_static("operator delete_", (void (*)(void *)) &GC_Root::operator delete, "None", py::arg("theAddress"));
// cls_GC_Root.def_static("operator new[]_", (void * (*)(size_t)) &GC_Root::operator new[], "None", py::arg("theSize"));
// cls_GC_Root.def_static("operator delete[]_", (void (*)(void *)) &GC_Root::operator delete[], "None", py::arg("theAddress"));
// cls_GC_Root.def_static("operator new_", (void * (*)(size_t, void *)) &GC_Root::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GC_Root.def_static("operator delete_", (void (*)(void *, void *)) &GC_Root::operator delete, "None", py::arg(""), py::arg(""));
cls_GC_Root.def("IsDone", (Standard_Boolean (GC_Root::*)() const) &GC_Root::IsDone, "Returns true if the construction is successful.");
cls_GC_Root.def("Status", (gce_ErrorType (GC_Root::*)() const) &GC_Root::Status, "Returns the status of the construction: - gce_Done, if the construction is successful, or - another value of the gce_ErrorType enumeration indicating why the construction failed.");

// Enums

}