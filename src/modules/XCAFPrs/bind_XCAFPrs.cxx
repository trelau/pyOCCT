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
#include <TDF_Label.hxx>
#include <TopLoc_Location.hxx>
#include <XCAFPrs_IndexedDataMapOfShapeStyle.hxx>
#include <Quantity_ColorRGBA.hxx>
#include <Standard_TypeDef.hxx>
#include <XCAFPrs_Driver.hxx>
#include <XCAFPrs_Style.hxx>
#include <XCAFPrs.hxx>

void bind_XCAFPrs(py::module &mod){

py::class_<XCAFPrs> cls_XCAFPrs(mod, "XCAFPrs", "Presentation (visualiation, selection etc.) tools for DECAF documents");

// Constructors

// Fields

// Methods
// cls_XCAFPrs.def_static("operator new_", (void * (*)(size_t)) &XCAFPrs::operator new, "None", py::arg("theSize"));
// cls_XCAFPrs.def_static("operator delete_", (void (*)(void *)) &XCAFPrs::operator delete, "None", py::arg("theAddress"));
// cls_XCAFPrs.def_static("operator new[]_", (void * (*)(size_t)) &XCAFPrs::operator new[], "None", py::arg("theSize"));
// cls_XCAFPrs.def_static("operator delete[]_", (void (*)(void *)) &XCAFPrs::operator delete[], "None", py::arg("theAddress"));
// cls_XCAFPrs.def_static("operator new_", (void * (*)(size_t, void *)) &XCAFPrs::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_XCAFPrs.def_static("operator delete_", (void (*)(void *, void *)) &XCAFPrs::operator delete, "None", py::arg(""), py::arg(""));
cls_XCAFPrs.def_static("CollectStyleSettings_", [](const TDF_Label & a0, const TopLoc_Location & a1, XCAFPrs_IndexedDataMapOfShapeStyle & a2) -> void { return XCAFPrs::CollectStyleSettings(a0, a1, a2); });
cls_XCAFPrs.def_static("CollectStyleSettings_", (void (*)(const TDF_Label &, const TopLoc_Location &, XCAFPrs_IndexedDataMapOfShapeStyle &, const Quantity_ColorRGBA &)) &XCAFPrs::CollectStyleSettings, "Collect styles defined for shape on label L and its components and subshapes and fills a map of shape - style correspondence The location <loc> is for internal use, it should be Null location for external call", py::arg("L"), py::arg("loc"), py::arg("settings"), py::arg("theLayerColor"));
cls_XCAFPrs.def_static("SetViewNameMode_", (void (*)(const Standard_Boolean)) &XCAFPrs::SetViewNameMode, "Set ViewNameMode for indicate display names or not.", py::arg("viewNameMode"));
cls_XCAFPrs.def_static("GetViewNameMode_", (Standard_Boolean (*)()) &XCAFPrs::GetViewNameMode, "None");

// Enums

}