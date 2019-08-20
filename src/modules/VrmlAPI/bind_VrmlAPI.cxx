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
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <VrmlAPI_Writer.hxx>
#include <VrmlAPI.hxx>

void bind_VrmlAPI(py::module &mod){

py::class_<VrmlAPI, std::unique_ptr<VrmlAPI>> cls_VrmlAPI(mod, "VrmlAPI", "API for writing to VRML 1.0");

// Constructors

// Fields

// Methods
// cls_VrmlAPI.def_static("operator new_", (void * (*)(size_t)) &VrmlAPI::operator new, "None", py::arg("theSize"));
// cls_VrmlAPI.def_static("operator delete_", (void (*)(void *)) &VrmlAPI::operator delete, "None", py::arg("theAddress"));
// cls_VrmlAPI.def_static("operator new[]_", (void * (*)(size_t)) &VrmlAPI::operator new[], "None", py::arg("theSize"));
// cls_VrmlAPI.def_static("operator delete[]_", (void (*)(void *)) &VrmlAPI::operator delete[], "None", py::arg("theAddress"));
// cls_VrmlAPI.def_static("operator new_", (void * (*)(size_t, void *)) &VrmlAPI::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_VrmlAPI.def_static("operator delete_", (void (*)(void *, void *)) &VrmlAPI::operator delete, "None", py::arg(""), py::arg(""));
cls_VrmlAPI.def_static("Write_", [](const TopoDS_Shape & a0, const Standard_CString a1) -> void { return VrmlAPI::Write(a0, a1); });
cls_VrmlAPI.def_static("Write_", (void (*)(const TopoDS_Shape &, const Standard_CString, const Standard_Integer)) &VrmlAPI::Write, "With help of this class user can change parameters of writing. Converts the shape aShape to VRML format of the passed version and writes it to the file identified by aFileName using default parameters.", py::arg("aShape"), py::arg("aFileName"), py::arg("aVersion"));

// Enums

}