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
#include <SelectMgr_ViewClipRange.hxx>

void bind_SelectMgr_ViewClipRange(py::module &mod){

py::class_<SelectMgr_ViewClipRange, std::unique_ptr<SelectMgr_ViewClipRange>> cls_SelectMgr_ViewClipRange(mod, "SelectMgr_ViewClipRange", "Class for handling depth clipping range. It is used to perform checks in case if global (for the whole view) clipping planes are defined inside of SelectMgr_RectangularFrustum class methods.");

// Constructors
cls_SelectMgr_ViewClipRange.def(py::init<>());

// Fields

// Methods
cls_SelectMgr_ViewClipRange.def("Set", (void (SelectMgr_ViewClipRange::*)(const Standard_Real, const Standard_Real)) &SelectMgr_ViewClipRange::Set, "Sets boundaries and validates view clipping range", py::arg("theDepthMin"), py::arg("theDepthMax"));
cls_SelectMgr_ViewClipRange.def("IsValid", (Standard_Boolean (SelectMgr_ViewClipRange::*)() const) &SelectMgr_ViewClipRange::IsValid, "Returns true if clip range is set and depth of each matched primitive must be tested for satisfying the defined interval");
cls_SelectMgr_ViewClipRange.def("MaxDepth", (Standard_Real (SelectMgr_ViewClipRange::*)() const) &SelectMgr_ViewClipRange::MaxDepth, "Returns the upper bound of valid depth range");
cls_SelectMgr_ViewClipRange.def("MinDepth", (Standard_Real (SelectMgr_ViewClipRange::*)() const) &SelectMgr_ViewClipRange::MinDepth, "Returns the lower bound of valid depth range");
cls_SelectMgr_ViewClipRange.def("Clear", (void (SelectMgr_ViewClipRange::*)()) &SelectMgr_ViewClipRange::Clear, "Invalidates view clipping range");

// Enums

}