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
#include <SelectBasics_PickResult.hxx>

void bind_SelectBasics_PickResult(py::module &mod){

py::class_<SelectBasics_PickResult, std::unique_ptr<SelectBasics_PickResult>> cls_SelectBasics_PickResult(mod, "SelectBasics_PickResult", "This structure provides unified access to the results of Matches() method in all sensitive entities.");

// Constructors
cls_SelectBasics_PickResult.def(py::init<>());
cls_SelectBasics_PickResult.def(py::init<const Standard_Real, const Standard_Real>(), py::arg("theDepth"), py::arg("theDistToCenter"));

// Fields

// Methods
cls_SelectBasics_PickResult.def("Depth", (Standard_Real (SelectBasics_PickResult::*)() const) &SelectBasics_PickResult::Depth, "None");
cls_SelectBasics_PickResult.def("DistToGeomCenter", (Standard_Real (SelectBasics_PickResult::*)() const) &SelectBasics_PickResult::DistToGeomCenter, "None");

// Enums

}