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
#include <TDF_Attribute.hxx>
#include <Standard_GUID.hxx>
#include <Standard_Handle.hxx>
#include <XCAFDoc_Color.hxx>
#include <TDF_Label.hxx>
#include <Quantity_Color.hxx>
#include <Quantity_ColorRGBA.hxx>
#include <Quantity_NameOfColor.hxx>
#include <Standard_TypeDef.hxx>
#include <TDF_RelocationTable.hxx>
#include <Standard_Type.hxx>

void bind_XCAFDoc_Color(py::module &mod){

py::class_<XCAFDoc_Color, opencascade::handle<XCAFDoc_Color>, TDF_Attribute> cls_XCAFDoc_Color(mod, "XCAFDoc_Color", "attribute to store color");

// Constructors
cls_XCAFDoc_Color.def(py::init<>());

// Fields

// Methods
cls_XCAFDoc_Color.def_static("GetID_", (const Standard_GUID & (*)()) &XCAFDoc_Color::GetID, "None");
cls_XCAFDoc_Color.def_static("Set_", (opencascade::handle<XCAFDoc_Color> (*)(const TDF_Label &, const Quantity_Color &)) &XCAFDoc_Color::Set, "None", py::arg("label"), py::arg("C"));
cls_XCAFDoc_Color.def_static("Set_", (opencascade::handle<XCAFDoc_Color> (*)(const TDF_Label &, const Quantity_ColorRGBA &)) &XCAFDoc_Color::Set, "None", py::arg("label"), py::arg("C"));
cls_XCAFDoc_Color.def_static("Set_", (opencascade::handle<XCAFDoc_Color> (*)(const TDF_Label &, const Quantity_NameOfColor)) &XCAFDoc_Color::Set, "None", py::arg("label"), py::arg("C"));
cls_XCAFDoc_Color.def_static("Set_", [](const TDF_Label & a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3) -> opencascade::handle<XCAFDoc_Color> { return XCAFDoc_Color::Set(a0, a1, a2, a3); });
cls_XCAFDoc_Color.def_static("Set_", (opencascade::handle<XCAFDoc_Color> (*)(const TDF_Label &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &XCAFDoc_Color::Set, "Find, or create, a Color attribute and set it's value the Color attribute is returned.", py::arg("label"), py::arg("R"), py::arg("G"), py::arg("B"), py::arg("alpha"));
cls_XCAFDoc_Color.def("Set", (void (XCAFDoc_Color::*)(const Quantity_Color &)) &XCAFDoc_Color::Set, "None", py::arg("C"));
cls_XCAFDoc_Color.def("Set", (void (XCAFDoc_Color::*)(const Quantity_ColorRGBA &)) &XCAFDoc_Color::Set, "None", py::arg("C"));
cls_XCAFDoc_Color.def("Set", (void (XCAFDoc_Color::*)(const Quantity_NameOfColor)) &XCAFDoc_Color::Set, "None", py::arg("C"));
cls_XCAFDoc_Color.def("Set", [](XCAFDoc_Color &self, const Standard_Real a0, const Standard_Real a1, const Standard_Real a2) -> void { return self.Set(a0, a1, a2); });
cls_XCAFDoc_Color.def("Set", (void (XCAFDoc_Color::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &XCAFDoc_Color::Set, "None", py::arg("R"), py::arg("G"), py::arg("B"), py::arg("alpha"));
cls_XCAFDoc_Color.def("GetColor", (const Quantity_Color & (XCAFDoc_Color::*)() const) &XCAFDoc_Color::GetColor, "None");
cls_XCAFDoc_Color.def("GetColorRGBA", (const Quantity_ColorRGBA & (XCAFDoc_Color::*)() const) &XCAFDoc_Color::GetColorRGBA, "None");
cls_XCAFDoc_Color.def("GetNOC", (Quantity_NameOfColor (XCAFDoc_Color::*)() const) &XCAFDoc_Color::GetNOC, "None");
cls_XCAFDoc_Color.def("GetRGB", [](XCAFDoc_Color &self, Standard_Real & R, Standard_Real & G, Standard_Real & B){ self.GetRGB(R, G, B); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(R, G, B); }, "None", py::arg("R"), py::arg("G"), py::arg("B"));
cls_XCAFDoc_Color.def("GetAlpha", (Standard_ShortReal (XCAFDoc_Color::*)() const) &XCAFDoc_Color::GetAlpha, "None");
cls_XCAFDoc_Color.def("ID", (const Standard_GUID & (XCAFDoc_Color::*)() const) &XCAFDoc_Color::ID, "None");
cls_XCAFDoc_Color.def("Restore", (void (XCAFDoc_Color::*)(const opencascade::handle<TDF_Attribute> &)) &XCAFDoc_Color::Restore, "None", py::arg("With"));
cls_XCAFDoc_Color.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XCAFDoc_Color::*)() const) &XCAFDoc_Color::NewEmpty, "None");
cls_XCAFDoc_Color.def("Paste", (void (XCAFDoc_Color::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &XCAFDoc_Color::Paste, "None", py::arg("Into"), py::arg("RT"));
cls_XCAFDoc_Color.def_static("get_type_name_", (const char * (*)()) &XCAFDoc_Color::get_type_name, "None");
cls_XCAFDoc_Color.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFDoc_Color::get_type_descriptor, "None");
cls_XCAFDoc_Color.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFDoc_Color::*)() const) &XCAFDoc_Color::DynamicType, "None");

// Enums

}