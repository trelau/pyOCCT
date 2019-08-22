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
#include <IGESDefs_Protocol.hxx>
#include <IGESDefs_AssociativityDef.hxx>
#include <IGESDefs_MacroDef.hxx>
#include <IGESDefs_UnitsData.hxx>
#include <IGESDefs_AttributeDef.hxx>
#include <IGESDefs_TabularData.hxx>
#include <IGESDefs_GenericData.hxx>
#include <IGESDefs_AttributeTable.hxx>
#include <IGESDefs_ToolAssociativityDef.hxx>
#include <IGESDefs_ToolMacroDef.hxx>
#include <IGESDefs_ToolUnitsData.hxx>
#include <IGESDefs_ToolAttributeDef.hxx>
#include <IGESDefs_ToolTabularData.hxx>
#include <IGESDefs_ToolGenericData.hxx>
#include <IGESDefs_ToolAttributeTable.hxx>
#include <IGESDefs_ReadWriteModule.hxx>
#include <IGESDefs_GeneralModule.hxx>
#include <IGESDefs_SpecificModule.hxx>
#include <IGESDefs_HArray1OfHArray1OfTextDisplayTemplate.hxx>
#include <IGESDefs.hxx>

void bind_IGESDefs(py::module &mod){

py::class_<IGESDefs> cls_IGESDefs(mod, "IGESDefs", "To embody general definitions of Entities (Parameters, Tables ...)");

// Constructors

// Fields

// Methods
// cls_IGESDefs.def_static("operator new_", (void * (*)(size_t)) &IGESDefs::operator new, "None", py::arg("theSize"));
// cls_IGESDefs.def_static("operator delete_", (void (*)(void *)) &IGESDefs::operator delete, "None", py::arg("theAddress"));
// cls_IGESDefs.def_static("operator new[]_", (void * (*)(size_t)) &IGESDefs::operator new[], "None", py::arg("theSize"));
// cls_IGESDefs.def_static("operator delete[]_", (void (*)(void *)) &IGESDefs::operator delete[], "None", py::arg("theAddress"));
// cls_IGESDefs.def_static("operator new_", (void * (*)(size_t, void *)) &IGESDefs::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESDefs.def_static("operator delete_", (void (*)(void *, void *)) &IGESDefs::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESDefs.def_static("Init_", (void (*)()) &IGESDefs::Init, "Prepares dynamic data (Protocol, Modules) for this package");
cls_IGESDefs.def_static("Protocol_", (opencascade::handle<IGESDefs_Protocol> (*)()) &IGESDefs::Protocol, "Returns the Protocol for this Package");

// Enums

}