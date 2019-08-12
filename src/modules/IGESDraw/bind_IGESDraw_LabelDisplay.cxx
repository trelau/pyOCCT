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
#include <IGESData_LabelDisplayEntity.hxx>
#include <Standard_Handle.hxx>
#include <IGESDraw_HArray1OfViewKindEntity.hxx>
#include <TColgp_HArray1OfXYZ.hxx>
#include <IGESDimen_HArray1OfLeaderArrow.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <IGESData_HArray1OfIGESEntity.hxx>
#include <Standard_TypeDef.hxx>
#include <IGESData_ViewKindEntity.hxx>
#include <gp_Pnt.hxx>
#include <IGESDimen_LeaderArrow.hxx>
#include <IGESData_IGESEntity.hxx>
#include <IGESDraw_LabelDisplay.hxx>
#include <Standard_Type.hxx>

void bind_IGESDraw_LabelDisplay(py::module &mod){

py::class_<IGESDraw_LabelDisplay, opencascade::handle<IGESDraw_LabelDisplay>, IGESData_LabelDisplayEntity> cls_IGESDraw_LabelDisplay(mod, "IGESDraw_LabelDisplay", "defines IGESLabelDisplay, Type <402> Form <5> in package IGESDraw");

// Constructors
cls_IGESDraw_LabelDisplay.def(py::init<>());

// Fields

// Methods
cls_IGESDraw_LabelDisplay.def("Init", (void (IGESDraw_LabelDisplay::*)(const opencascade::handle<IGESDraw_HArray1OfViewKindEntity> &, const opencascade::handle<TColgp_HArray1OfXYZ> &, const opencascade::handle<IGESDimen_HArray1OfLeaderArrow> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<IGESData_HArray1OfIGESEntity> &)) &IGESDraw_LabelDisplay::Init, "This method is used to set the fields of the class LabelDisplay - allViews : Pointers to View Entities - allTextLocations : Coordinates of text locations in the views - allLeaderEntities : Pointers to Leader Entities in the views - allLabelLevels : Entity label level numbers in the views - allDisplayedEntities : Pointers to the entities being displayed raises exception if Lengths of allViews, allTextLocations, allLeaderEntities, allLabelLevels and allDisplayedEntities are not same.", py::arg("allViews"), py::arg("allTextLocations"), py::arg("allLeaderEntities"), py::arg("allLabelLevels"), py::arg("allDisplayedEntities"));
cls_IGESDraw_LabelDisplay.def("NbLabels", (Standard_Integer (IGESDraw_LabelDisplay::*)() const) &IGESDraw_LabelDisplay::NbLabels, "returns the number of label placements in <me>");
cls_IGESDraw_LabelDisplay.def("ViewItem", (opencascade::handle<IGESData_ViewKindEntity> (IGESDraw_LabelDisplay::*)(const Standard_Integer) const) &IGESDraw_LabelDisplay::ViewItem, "returns the View entity indicated by ViewIndex raises an exception if ViewIndex <= 0 or ViewIndex > NbLabels().", py::arg("ViewIndex"));
cls_IGESDraw_LabelDisplay.def("TextLocation", (gp_Pnt (IGESDraw_LabelDisplay::*)(const Standard_Integer) const) &IGESDraw_LabelDisplay::TextLocation, "returns the 3d-Point coordinates of the text location, in the view indicated by ViewIndex raises an exception if ViewIndex <= 0 or ViewIndex > NbLabels().", py::arg("ViewIndex"));
cls_IGESDraw_LabelDisplay.def("LeaderEntity", (opencascade::handle<IGESDimen_LeaderArrow> (IGESDraw_LabelDisplay::*)(const Standard_Integer) const) &IGESDraw_LabelDisplay::LeaderEntity, "returns the Leader entity in the view indicated by ViewIndex raises an exception if ViewIndex <= 0 or ViewIndex > NbLabels().", py::arg("ViewIndex"));
cls_IGESDraw_LabelDisplay.def("LabelLevel", (Standard_Integer (IGESDraw_LabelDisplay::*)(const Standard_Integer) const) &IGESDraw_LabelDisplay::LabelLevel, "returns the Entity label level number in the view indicated by ViewIndex raises an exception if ViewIndex <= 0 or ViewIndex > NbLabels().", py::arg("ViewIndex"));
cls_IGESDraw_LabelDisplay.def("DisplayedEntity", (opencascade::handle<IGESData_IGESEntity> (IGESDraw_LabelDisplay::*)(const Standard_Integer) const) &IGESDraw_LabelDisplay::DisplayedEntity, "returns the entity indicated by EntityIndex raises an exception if EntityIndex <= 0 or EntityIndex > NbLabels().", py::arg("EntityIndex"));
cls_IGESDraw_LabelDisplay.def("TransformedTextLocation", (gp_Pnt (IGESDraw_LabelDisplay::*)(const Standard_Integer) const) &IGESDraw_LabelDisplay::TransformedTextLocation, "returns the transformed 3d-Point coordinates of the text location, in the view indicated by ViewIndex raises an exception if ViewIndex <= 0 or ViewIndex > NbLabels().", py::arg("ViewIndex"));
cls_IGESDraw_LabelDisplay.def_static("get_type_name_", (const char * (*)()) &IGESDraw_LabelDisplay::get_type_name, "None");
cls_IGESDraw_LabelDisplay.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDraw_LabelDisplay::get_type_descriptor, "None");
cls_IGESDraw_LabelDisplay.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDraw_LabelDisplay::*)() const) &IGESDraw_LabelDisplay::DynamicType, "None");

// Enums

}