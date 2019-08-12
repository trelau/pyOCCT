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
#include <IGESData_HArray1OfIGESEntity.hxx>
#include <Standard_TypeDef.hxx>
#include <IGESData_IGESEntity.hxx>
#include <IGESDraw_ViewsVisible.hxx>
#include <Standard_Type.hxx>

void bind_IGESDraw_ViewsVisible(py::module &mod){

py::class_<IGESDraw_ViewsVisible, opencascade::handle<IGESDraw_ViewsVisible>, IGESData_ViewKindEntity> cls_IGESDraw_ViewsVisible(mod, "IGESDraw_ViewsVisible", "Defines IGESViewsVisible, Type <402>, Form <3> in package IGESDraw");

// Constructors
cls_IGESDraw_ViewsVisible.def(py::init<>());

// Fields

// Methods
cls_IGESDraw_ViewsVisible.def("Init", (void (IGESDraw_ViewsVisible::*)(const opencascade::handle<IGESDraw_HArray1OfViewKindEntity> &, const opencascade::handle<IGESData_HArray1OfIGESEntity> &)) &IGESDraw_ViewsVisible::Init, "This method is used to set the fields of the class ViewsVisible - allViewEntities : All View kind entities - allDisplayEntity : All entities whose display is specified", py::arg("allViewEntities"), py::arg("allDisplayEntity"));
cls_IGESDraw_ViewsVisible.def("InitImplied", (void (IGESDraw_ViewsVisible::*)(const opencascade::handle<IGESData_HArray1OfIGESEntity> &)) &IGESDraw_ViewsVisible::InitImplied, "Changes only the list of Displayed Entities (Null allowed)", py::arg("allDisplayEntity"));
cls_IGESDraw_ViewsVisible.def("IsSingle", (Standard_Boolean (IGESDraw_ViewsVisible::*)() const) &IGESDraw_ViewsVisible::IsSingle, "Returns False (for a complex view)");
cls_IGESDraw_ViewsVisible.def("NbViews", (Standard_Integer (IGESDraw_ViewsVisible::*)() const) &IGESDraw_ViewsVisible::NbViews, "returns the Number of views visible");
cls_IGESDraw_ViewsVisible.def("NbDisplayedEntities", (Standard_Integer (IGESDraw_ViewsVisible::*)() const) &IGESDraw_ViewsVisible::NbDisplayedEntities, "returns the number of entities displayed in the Views or zero if no Entities specified in these Views");
cls_IGESDraw_ViewsVisible.def("ViewItem", (opencascade::handle<IGESData_ViewKindEntity> (IGESDraw_ViewsVisible::*)(const Standard_Integer) const) &IGESDraw_ViewsVisible::ViewItem, "returns the Index'th ViewKindEntity Entity raises exception if Index <= 0 or Index > NbViewsVisible()", py::arg("Index"));
cls_IGESDraw_ViewsVisible.def("DisplayedEntity", (opencascade::handle<IGESData_IGESEntity> (IGESDraw_ViewsVisible::*)(const Standard_Integer) const) &IGESDraw_ViewsVisible::DisplayedEntity, "returns the Index'th entity whose display is being specified by this associativity instance raises exception if Index <= 0 or Index > NbEntityDisplayed()", py::arg("Index"));
cls_IGESDraw_ViewsVisible.def_static("get_type_name_", (const char * (*)()) &IGESDraw_ViewsVisible::get_type_name, "None");
cls_IGESDraw_ViewsVisible.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDraw_ViewsVisible::get_type_descriptor, "None");
cls_IGESDraw_ViewsVisible.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDraw_ViewsVisible::*)() const) &IGESDraw_ViewsVisible::DynamicType, "None");

// Enums

}