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
#include <TopoDS_Face.hxx>
#include <TopoDS_Shell.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <ShapeFix_FaceConnect.hxx>

void bind_ShapeFix_FaceConnect(py::module &mod){

py::class_<ShapeFix_FaceConnect, std::unique_ptr<ShapeFix_FaceConnect>> cls_ShapeFix_FaceConnect(mod, "ShapeFix_FaceConnect", "Rebuilds connectivity between faces in shell");

// Constructors
cls_ShapeFix_FaceConnect.def(py::init<>());

// Fields

// Methods
// cls_ShapeFix_FaceConnect.def_static("operator new_", (void * (*)(size_t)) &ShapeFix_FaceConnect::operator new, "None", py::arg("theSize"));
// cls_ShapeFix_FaceConnect.def_static("operator delete_", (void (*)(void *)) &ShapeFix_FaceConnect::operator delete, "None", py::arg("theAddress"));
// cls_ShapeFix_FaceConnect.def_static("operator new[]_", (void * (*)(size_t)) &ShapeFix_FaceConnect::operator new[], "None", py::arg("theSize"));
// cls_ShapeFix_FaceConnect.def_static("operator delete[]_", (void (*)(void *)) &ShapeFix_FaceConnect::operator delete[], "None", py::arg("theAddress"));
// cls_ShapeFix_FaceConnect.def_static("operator new_", (void * (*)(size_t, void *)) &ShapeFix_FaceConnect::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ShapeFix_FaceConnect.def_static("operator delete_", (void (*)(void *, void *)) &ShapeFix_FaceConnect::operator delete, "None", py::arg(""), py::arg(""));
cls_ShapeFix_FaceConnect.def("Add", (Standard_Boolean (ShapeFix_FaceConnect::*)(const TopoDS_Face &, const TopoDS_Face &)) &ShapeFix_FaceConnect::Add, "None", py::arg("aFirst"), py::arg("aSecond"));
cls_ShapeFix_FaceConnect.def("Build", (TopoDS_Shell (ShapeFix_FaceConnect::*)(const TopoDS_Shell &, const Standard_Real, const Standard_Real)) &ShapeFix_FaceConnect::Build, "None", py::arg("shell"), py::arg("sewtoler"), py::arg("fixtoler"));
cls_ShapeFix_FaceConnect.def("Clear", (void (ShapeFix_FaceConnect::*)()) &ShapeFix_FaceConnect::Clear, "Clears internal data structure");

// Enums

}