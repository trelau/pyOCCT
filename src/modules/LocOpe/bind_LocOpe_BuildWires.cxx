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
#include <Standard_Handle.hxx>
#include <LocOpe_WiresOnShape.hxx>
#include <Standard_TypeDef.hxx>
#include <LocOpe_BuildWires.hxx>

void bind_LocOpe_BuildWires(py::module &mod){

py::class_<LocOpe_BuildWires, std::unique_ptr<LocOpe_BuildWires>> cls_LocOpe_BuildWires(mod, "LocOpe_BuildWires", "None");

// Constructors
cls_LocOpe_BuildWires.def(py::init<>());
cls_LocOpe_BuildWires.def(py::init<const TopTools_ListOfShape &, const opencascade::handle<LocOpe_WiresOnShape> &>(), py::arg("Ledges"), py::arg("PW"));

// Fields

// Methods
// cls_LocOpe_BuildWires.def_static("operator new_", (void * (*)(size_t)) &LocOpe_BuildWires::operator new, "None", py::arg("theSize"));
// cls_LocOpe_BuildWires.def_static("operator delete_", (void (*)(void *)) &LocOpe_BuildWires::operator delete, "None", py::arg("theAddress"));
// cls_LocOpe_BuildWires.def_static("operator new[]_", (void * (*)(size_t)) &LocOpe_BuildWires::operator new[], "None", py::arg("theSize"));
// cls_LocOpe_BuildWires.def_static("operator delete[]_", (void (*)(void *)) &LocOpe_BuildWires::operator delete[], "None", py::arg("theAddress"));
// cls_LocOpe_BuildWires.def_static("operator new_", (void * (*)(size_t, void *)) &LocOpe_BuildWires::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_LocOpe_BuildWires.def_static("operator delete_", (void (*)(void *, void *)) &LocOpe_BuildWires::operator delete, "None", py::arg(""), py::arg(""));
cls_LocOpe_BuildWires.def("Perform", (void (LocOpe_BuildWires::*)(const TopTools_ListOfShape &, const opencascade::handle<LocOpe_WiresOnShape> &)) &LocOpe_BuildWires::Perform, "None", py::arg("Ledges"), py::arg("PW"));
cls_LocOpe_BuildWires.def("IsDone", (Standard_Boolean (LocOpe_BuildWires::*)() const) &LocOpe_BuildWires::IsDone, "None");
cls_LocOpe_BuildWires.def("Result", (const TopTools_ListOfShape & (LocOpe_BuildWires::*)() const) &LocOpe_BuildWires::Result, "None");

// Enums

}