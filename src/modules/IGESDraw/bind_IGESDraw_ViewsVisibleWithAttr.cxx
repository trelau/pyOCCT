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
#include <IGESData_ViewKindEntity.hxx>
#include <Standard_Handle.hxx>
#include <IGESDraw_HArray1OfViewKindEntity.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <IGESBasic_HArray1OfLineFontEntity.hxx>
#include <IGESGraph_HArray1OfColor.hxx>
#include <IGESData_HArray1OfIGESEntity.hxx>
#include <Standard_TypeDef.hxx>
#include <IGESData_LineFontEntity.hxx>
#include <IGESGraph_Color.hxx>
#include <IGESData_IGESEntity.hxx>
#include <IGESDraw_ViewsVisibleWithAttr.hxx>
#include <Standard_Type.hxx>

void bind_IGESDraw_ViewsVisibleWithAttr(py::module &mod){

py::class_<IGESDraw_ViewsVisibleWithAttr, opencascade::handle<IGESDraw_ViewsVisibleWithAttr>, IGESData_ViewKindEntity> cls_IGESDraw_ViewsVisibleWithAttr(mod, "IGESDraw_ViewsVisibleWithAttr", "defines IGESViewsVisibleWithAttr, Type <402>, Form <4> in package IGESDraw");

// Constructors
cls_IGESDraw_ViewsVisibleWithAttr.def(py::init<>());

// Fields

// Methods
cls_IGESDraw_ViewsVisibleWithAttr.def("Init", (void (IGESDraw_ViewsVisibleWithAttr::*)(const opencascade::handle<IGESDraw_HArray1OfViewKindEntity> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<IGESBasic_HArray1OfLineFontEntity> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<IGESGraph_HArray1OfColor> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<IGESData_HArray1OfIGESEntity> &)) &IGESDraw_ViewsVisibleWithAttr::Init, "This method is used to set fields of the class ViewsVisibleWithAttr - allViewEntities : All View kind entities - allLineFonts : All Line Font values or zero(0) - allLineDefinitions : Line Font Definition (if Line Font value = 0) - allColorValues : All Color values - allColorDefinitions : All Color Definition Entities - allLineWeights : All Line Weight values - allDisplayEntities : Entities which are member of this associativity raises exception if Lengths of allViewEntities, allLineFonts, allColorValues,allColorDefinitions, allLineWeights are not same", py::arg("allViewEntities"), py::arg("allLineFonts"), py::arg("allLineDefinitions"), py::arg("allColorValues"), py::arg("allColorDefinitions"), py::arg("allLineWeights"), py::arg("allDisplayEntities"));
cls_IGESDraw_ViewsVisibleWithAttr.def("InitImplied", (void (IGESDraw_ViewsVisibleWithAttr::*)(const opencascade::handle<IGESData_HArray1OfIGESEntity> &)) &IGESDraw_ViewsVisibleWithAttr::InitImplied, "Changes only the list of Displayed Entities (Null allowed)", py::arg("allDisplayEntity"));
cls_IGESDraw_ViewsVisibleWithAttr.def("IsSingle", (Standard_Boolean (IGESDraw_ViewsVisibleWithAttr::*)() const) &IGESDraw_ViewsVisibleWithAttr::IsSingle, "Returns False (for a complex view)");
cls_IGESDraw_ViewsVisibleWithAttr.def("NbViews", (Standard_Integer (IGESDraw_ViewsVisibleWithAttr::*)() const) &IGESDraw_ViewsVisibleWithAttr::NbViews, "returns the number of Views containing the view visible, line font, color number, and line weight information");
cls_IGESDraw_ViewsVisibleWithAttr.def("NbDisplayedEntities", (Standard_Integer (IGESDraw_ViewsVisibleWithAttr::*)() const) &IGESDraw_ViewsVisibleWithAttr::NbDisplayedEntities, "returns the number of entities which have this particular set of display characteristic, or zero if no Entities specified");
cls_IGESDraw_ViewsVisibleWithAttr.def("ViewItem", (opencascade::handle<IGESData_ViewKindEntity> (IGESDraw_ViewsVisibleWithAttr::*)(const Standard_Integer) const) &IGESDraw_ViewsVisibleWithAttr::ViewItem, "returns the Index'th ViewKindEntity entity raises exception if Index <= 0 or Index > NbViews()", py::arg("Index"));
cls_IGESDraw_ViewsVisibleWithAttr.def("LineFontValue", (Standard_Integer (IGESDraw_ViewsVisibleWithAttr::*)(const Standard_Integer) const) &IGESDraw_ViewsVisibleWithAttr::LineFontValue, "returns the Index'th Line font value or zero raises exception if Index <= 0 or Index > NbViews()", py::arg("Index"));
cls_IGESDraw_ViewsVisibleWithAttr.def("IsFontDefinition", (Standard_Boolean (IGESDraw_ViewsVisibleWithAttr::*)(const Standard_Integer) const) &IGESDraw_ViewsVisibleWithAttr::IsFontDefinition, "returns True if the Index'th Line Font Definition is specified else returns False raises exception if Index <= 0 or Index > NbViews()", py::arg("Index"));
cls_IGESDraw_ViewsVisibleWithAttr.def("FontDefinition", (opencascade::handle<IGESData_LineFontEntity> (IGESDraw_ViewsVisibleWithAttr::*)(const Standard_Integer) const) &IGESDraw_ViewsVisibleWithAttr::FontDefinition, "returns the Index'th Line Font Definition Entity or NULL(0) raises exception if Index <= 0 or Index > NbViews()", py::arg("Index"));
cls_IGESDraw_ViewsVisibleWithAttr.def("ColorValue", (Standard_Integer (IGESDraw_ViewsVisibleWithAttr::*)(const Standard_Integer) const) &IGESDraw_ViewsVisibleWithAttr::ColorValue, "returns the Index'th Color number value raises exception if Index <= 0 or Index > NbViews()", py::arg("Index"));
cls_IGESDraw_ViewsVisibleWithAttr.def("IsColorDefinition", (Standard_Boolean (IGESDraw_ViewsVisibleWithAttr::*)(const Standard_Integer) const) &IGESDraw_ViewsVisibleWithAttr::IsColorDefinition, "returns True if Index'th Color Definition is specified else returns False raises exception if Index <= 0 or Index > NbViews()", py::arg("Index"));
cls_IGESDraw_ViewsVisibleWithAttr.def("ColorDefinition", (opencascade::handle<IGESGraph_Color> (IGESDraw_ViewsVisibleWithAttr::*)(const Standard_Integer) const) &IGESDraw_ViewsVisibleWithAttr::ColorDefinition, "returns the Index'th Color Definition Entity raises exception if Index <= 0 or Index > NbViews()", py::arg("Index"));
cls_IGESDraw_ViewsVisibleWithAttr.def("LineWeightItem", (Standard_Integer (IGESDraw_ViewsVisibleWithAttr::*)(const Standard_Integer) const) &IGESDraw_ViewsVisibleWithAttr::LineWeightItem, "returns the Index'th Color Line Weight raises exception if Index <= 0 or Index > NbViews()", py::arg("Index"));
cls_IGESDraw_ViewsVisibleWithAttr.def("DisplayedEntity", (opencascade::handle<IGESData_IGESEntity> (IGESDraw_ViewsVisibleWithAttr::*)(const Standard_Integer) const) &IGESDraw_ViewsVisibleWithAttr::DisplayedEntity, "returns Index'th Display entity with this particular characteristics raises exception if Index <= 0 or Index > NbEntities()", py::arg("Index"));
cls_IGESDraw_ViewsVisibleWithAttr.def_static("get_type_name_", (const char * (*)()) &IGESDraw_ViewsVisibleWithAttr::get_type_name, "None");
cls_IGESDraw_ViewsVisibleWithAttr.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDraw_ViewsVisibleWithAttr::get_type_descriptor, "None");
cls_IGESDraw_ViewsVisibleWithAttr.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDraw_ViewsVisibleWithAttr::*)() const) &IGESDraw_ViewsVisibleWithAttr::DynamicType, "None");

// Enums

}