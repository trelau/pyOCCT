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
#include <TopTools_ListOfShape.hxx>
#include <TopoDS_Shape.hxx>
#include <LocOpe_BuildShape.hxx>

void bind_LocOpe_BuildShape(py::module &mod){

py::class_<LocOpe_BuildShape, std::unique_ptr<LocOpe_BuildShape>> cls_LocOpe_BuildShape(mod, "LocOpe_BuildShape", "None");

// Constructors
cls_LocOpe_BuildShape.def(py::init<>());
cls_LocOpe_BuildShape.def(py::init<const TopTools_ListOfShape &>(), py::arg("L"));

// Fields

// Methods
// cls_LocOpe_BuildShape.def_static("operator new_", (void * (*)(size_t)) &LocOpe_BuildShape::operator new, "None", py::arg("theSize"));
// cls_LocOpe_BuildShape.def_static("operator delete_", (void (*)(void *)) &LocOpe_BuildShape::operator delete, "None", py::arg("theAddress"));
// cls_LocOpe_BuildShape.def_static("operator new[]_", (void * (*)(size_t)) &LocOpe_BuildShape::operator new[], "None", py::arg("theSize"));
// cls_LocOpe_BuildShape.def_static("operator delete[]_", (void (*)(void *)) &LocOpe_BuildShape::operator delete[], "None", py::arg("theAddress"));
// cls_LocOpe_BuildShape.def_static("operator new_", (void * (*)(size_t, void *)) &LocOpe_BuildShape::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_LocOpe_BuildShape.def_static("operator delete_", (void (*)(void *, void *)) &LocOpe_BuildShape::operator delete, "None", py::arg(""), py::arg(""));
cls_LocOpe_BuildShape.def("Perform", (void (LocOpe_BuildShape::*)(const TopTools_ListOfShape &)) &LocOpe_BuildShape::Perform, "Builds shape(s) from the list <L>. Uses only the faces of <L>.", py::arg("L"));
cls_LocOpe_BuildShape.def("Shape", (const TopoDS_Shape & (LocOpe_BuildShape::*)() const) &LocOpe_BuildShape::Shape, "None");

// Enums

}