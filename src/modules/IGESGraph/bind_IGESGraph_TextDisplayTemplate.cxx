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
#include <IGESData_IGESEntity.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <IGESGraph_TextFontDef.hxx>
#include <gp_XYZ.hxx>
#include <gp_Pnt.hxx>
#include <IGESGraph_TextDisplayTemplate.hxx>
#include <Standard_Type.hxx>

void bind_IGESGraph_TextDisplayTemplate(py::module &mod){

py::class_<IGESGraph_TextDisplayTemplate, opencascade::handle<IGESGraph_TextDisplayTemplate>, IGESData_IGESEntity> cls_IGESGraph_TextDisplayTemplate(mod, "IGESGraph_TextDisplayTemplate", "defines IGES TextDisplayTemplate Entity, Type <312>, form <0, 1> in package IGESGraph");

// Constructors
cls_IGESGraph_TextDisplayTemplate.def(py::init<>());

// Fields

// Methods
cls_IGESGraph_TextDisplayTemplate.def("Init", (void (IGESGraph_TextDisplayTemplate::*)(const Standard_Real, const Standard_Real, const Standard_Integer, const opencascade::handle<IGESGraph_TextFontDef> &, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer, const gp_XYZ &)) &IGESGraph_TextDisplayTemplate::Init, "This method is used to set the fields of the class TextDisplayTemplate - aWidth : Character box width - aHeight : Character box height - afontCode : Font code - aFontEntity : Text Font Definition Entity - aSlantAngle : Slant angle - aRotationAngle : Rotation angle - aMirrorFlag : Mirror Flag - aRotationFlag : Rotate internal text flag - aCorner : Lower left corner coordinates(Form No. 0), Increments from coordinates (Form No. 1)", py::arg("aWidth"), py::arg("aHeight"), py::arg("aFontCode"), py::arg("aFontEntity"), py::arg("aSlantAngle"), py::arg("aRotationAngle"), py::arg("aMirrorFlag"), py::arg("aRotationFlag"), py::arg("aCorner"));
cls_IGESGraph_TextDisplayTemplate.def("SetIncremental", (void (IGESGraph_TextDisplayTemplate::*)(const Standard_Boolean)) &IGESGraph_TextDisplayTemplate::SetIncremental, "Sets <me> to be Incremental (Form 1) if <mode> is True, or Basolute (Form 0) else", py::arg("mode"));
cls_IGESGraph_TextDisplayTemplate.def("IsIncremental", (Standard_Boolean (IGESGraph_TextDisplayTemplate::*)() const) &IGESGraph_TextDisplayTemplate::IsIncremental, "returns True if entity is Incremental (Form 1). False if entity is Absolute (Form 0).");
cls_IGESGraph_TextDisplayTemplate.def("BoxWidth", (Standard_Real (IGESGraph_TextDisplayTemplate::*)() const) &IGESGraph_TextDisplayTemplate::BoxWidth, "returns Character Box Width.");
cls_IGESGraph_TextDisplayTemplate.def("BoxHeight", (Standard_Real (IGESGraph_TextDisplayTemplate::*)() const) &IGESGraph_TextDisplayTemplate::BoxHeight, "returns Character Box Height.");
cls_IGESGraph_TextDisplayTemplate.def("IsFontEntity", (Standard_Boolean (IGESGraph_TextDisplayTemplate::*)() const) &IGESGraph_TextDisplayTemplate::IsFontEntity, "returns False if theFontEntity is Null, True otherwise.");
cls_IGESGraph_TextDisplayTemplate.def("FontCode", (Standard_Integer (IGESGraph_TextDisplayTemplate::*)() const) &IGESGraph_TextDisplayTemplate::FontCode, "returns the font code.");
cls_IGESGraph_TextDisplayTemplate.def("FontEntity", (opencascade::handle<IGESGraph_TextFontDef> (IGESGraph_TextDisplayTemplate::*)() const) &IGESGraph_TextDisplayTemplate::FontEntity, "returns Text Font Definition Entity used to define the font.");
cls_IGESGraph_TextDisplayTemplate.def("SlantAngle", (Standard_Real (IGESGraph_TextDisplayTemplate::*)() const) &IGESGraph_TextDisplayTemplate::SlantAngle, "returns slant angle of character in radians.");
cls_IGESGraph_TextDisplayTemplate.def("RotationAngle", (Standard_Real (IGESGraph_TextDisplayTemplate::*)() const) &IGESGraph_TextDisplayTemplate::RotationAngle, "returns Rotation angle of text block in radians.");
cls_IGESGraph_TextDisplayTemplate.def("MirrorFlag", (Standard_Integer (IGESGraph_TextDisplayTemplate::*)() const) &IGESGraph_TextDisplayTemplate::MirrorFlag, "returns Mirror flag Mirror flag : 0 = no mirroring. 1 = mirror axis perpendicular to text base line. 2 = mirror axis is text base line.");
cls_IGESGraph_TextDisplayTemplate.def("RotateFlag", (Standard_Integer (IGESGraph_TextDisplayTemplate::*)() const) &IGESGraph_TextDisplayTemplate::RotateFlag, "returns Rotate internal text flag. Rotate internal text flag : 0 = text horizontal. 1 = text vertical.");
cls_IGESGraph_TextDisplayTemplate.def("StartingCorner", (gp_Pnt (IGESGraph_TextDisplayTemplate::*)() const) &IGESGraph_TextDisplayTemplate::StartingCorner, "If IsIncremental() returns False, gets coordinates of lower left corner of first character box. If IsIncremental() returns True, gets increments from X, Y, Z coordinates found in parent entity.");
cls_IGESGraph_TextDisplayTemplate.def("TransformedStartingCorner", (gp_Pnt (IGESGraph_TextDisplayTemplate::*)() const) &IGESGraph_TextDisplayTemplate::TransformedStartingCorner, "If IsIncremental() returns False, gets coordinates of lower left corner of first character box. If IsIncremental() returns True, gets increments from X, Y, Z coordinates found in parent entity.");
cls_IGESGraph_TextDisplayTemplate.def_static("get_type_name_", (const char * (*)()) &IGESGraph_TextDisplayTemplate::get_type_name, "None");
cls_IGESGraph_TextDisplayTemplate.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESGraph_TextDisplayTemplate::get_type_descriptor, "None");
cls_IGESGraph_TextDisplayTemplate.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESGraph_TextDisplayTemplate::*)() const) &IGESGraph_TextDisplayTemplate::DynamicType, "None");

// Enums

}