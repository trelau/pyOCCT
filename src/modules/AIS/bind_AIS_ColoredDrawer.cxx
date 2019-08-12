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
#include <Prs3d_Drawer.hxx>
#include <Standard_Handle.hxx>
#include <AIS_ColoredDrawer.hxx>
#include <Standard_Type.hxx>
#include <Quantity_Color.hxx>
#include <Standard_TypeDef.hxx>

void bind_AIS_ColoredDrawer(py::module &mod){

py::class_<AIS_ColoredDrawer, opencascade::handle<AIS_ColoredDrawer>, Prs3d_Drawer> cls_AIS_ColoredDrawer(mod, "AIS_ColoredDrawer", "Customizable properties.");

// Constructors
cls_AIS_ColoredDrawer.def(py::init<const opencascade::handle<Prs3d_Drawer> &>(), py::arg("theLink"));

// Fields
cls_AIS_ColoredDrawer.def_readwrite("myIsHidden", &AIS_ColoredDrawer::myIsHidden, "");
cls_AIS_ColoredDrawer.def_readwrite("myHasOwnColor", &AIS_ColoredDrawer::myHasOwnColor, "None");
cls_AIS_ColoredDrawer.def_readwrite("myHasOwnWidth", &AIS_ColoredDrawer::myHasOwnWidth, "None");

// Methods
cls_AIS_ColoredDrawer.def_static("get_type_name_", (const char * (*)()) &AIS_ColoredDrawer::get_type_name, "None");
cls_AIS_ColoredDrawer.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_ColoredDrawer::get_type_descriptor, "None");
cls_AIS_ColoredDrawer.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_ColoredDrawer::*)() const) &AIS_ColoredDrawer::DynamicType, "None");
cls_AIS_ColoredDrawer.def("IsHidden", (bool (AIS_ColoredDrawer::*)() const) &AIS_ColoredDrawer::IsHidden, "None");
cls_AIS_ColoredDrawer.def("SetHidden", (void (AIS_ColoredDrawer::*)(const bool)) &AIS_ColoredDrawer::SetHidden, "None", py::arg("theToHide"));
cls_AIS_ColoredDrawer.def("HasOwnColor", (bool (AIS_ColoredDrawer::*)() const) &AIS_ColoredDrawer::HasOwnColor, "None");
cls_AIS_ColoredDrawer.def("UnsetOwnColor", (void (AIS_ColoredDrawer::*)()) &AIS_ColoredDrawer::UnsetOwnColor, "None");
cls_AIS_ColoredDrawer.def("SetOwnColor", (void (AIS_ColoredDrawer::*)(const Quantity_Color &)) &AIS_ColoredDrawer::SetOwnColor, "None", py::arg(""));
cls_AIS_ColoredDrawer.def("HasOwnWidth", (bool (AIS_ColoredDrawer::*)() const) &AIS_ColoredDrawer::HasOwnWidth, "None");
cls_AIS_ColoredDrawer.def("UnsetOwnWidth", (void (AIS_ColoredDrawer::*)()) &AIS_ColoredDrawer::UnsetOwnWidth, "None");
cls_AIS_ColoredDrawer.def("SetOwnWidth", (void (AIS_ColoredDrawer::*)(const Standard_Real)) &AIS_ColoredDrawer::SetOwnWidth, "None", py::arg(""));

// Enums

}