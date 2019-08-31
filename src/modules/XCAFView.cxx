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
#include <XCAFView_ProjectionType.hxx>
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <XCAFView_Object.hxx>
#include <TCollection_HAsciiString.hxx>
#include <gp_Pnt.hxx>
#include <gp_Dir.hxx>
#include <Standard_TypeDef.hxx>
#include <TColgp_HArray1OfPnt.hxx>
#include <Standard_Type.hxx>

PYBIND11_MODULE(XCAFView, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.gp");
py::module::import("OCCT.TColgp");

// ENUM: XCAFVIEW_PROJECTIONTYPE
py::enum_<XCAFView_ProjectionType>(mod, "XCAFView_ProjectionType", "Defines projection types of view")
	.value("XCAFView_ProjectionType_NoCamera", XCAFView_ProjectionType::XCAFView_ProjectionType_NoCamera)
	.value("XCAFView_ProjectionType_Parallel", XCAFView_ProjectionType::XCAFView_ProjectionType_Parallel)
	.value("XCAFView_ProjectionType_Central", XCAFView_ProjectionType::XCAFView_ProjectionType_Central)
	.export_values();


// CLASS: XCAFVIEW_OBJECT
py::class_<XCAFView_Object, opencascade::handle<XCAFView_Object>, Standard_Transient> cls_XCAFView_Object(mod, "XCAFView_Object", "Access object for saved view");

// Constructors
cls_XCAFView_Object.def(py::init<>());
cls_XCAFView_Object.def(py::init<const opencascade::handle<XCAFView_Object> &>(), py::arg("theObj"));

// Methods
cls_XCAFView_Object.def("SetName", (void (XCAFView_Object::*)(opencascade::handle<TCollection_HAsciiString>)) &XCAFView_Object::SetName, "None", py::arg("theName"));
cls_XCAFView_Object.def("Name", (opencascade::handle<TCollection_HAsciiString> (XCAFView_Object::*)()) &XCAFView_Object::Name, "None");
cls_XCAFView_Object.def("SetType", (void (XCAFView_Object::*)(XCAFView_ProjectionType)) &XCAFView_Object::SetType, "None", py::arg("theType"));
cls_XCAFView_Object.def("Type", (XCAFView_ProjectionType (XCAFView_Object::*)()) &XCAFView_Object::Type, "None");
cls_XCAFView_Object.def("SetProjectionPoint", (void (XCAFView_Object::*)(gp_Pnt)) &XCAFView_Object::SetProjectionPoint, "None", py::arg("thePoint"));
cls_XCAFView_Object.def("ProjectionPoint", (gp_Pnt (XCAFView_Object::*)()) &XCAFView_Object::ProjectionPoint, "None");
cls_XCAFView_Object.def("SetViewDirection", (void (XCAFView_Object::*)(gp_Dir)) &XCAFView_Object::SetViewDirection, "None", py::arg("theDirection"));
cls_XCAFView_Object.def("ViewDirection", (gp_Dir (XCAFView_Object::*)()) &XCAFView_Object::ViewDirection, "None");
cls_XCAFView_Object.def("SetUpDirection", (void (XCAFView_Object::*)(gp_Dir)) &XCAFView_Object::SetUpDirection, "None", py::arg("theDirection"));
cls_XCAFView_Object.def("UpDirection", (gp_Dir (XCAFView_Object::*)()) &XCAFView_Object::UpDirection, "None");
cls_XCAFView_Object.def("SetZoomFactor", (void (XCAFView_Object::*)(Standard_Real)) &XCAFView_Object::SetZoomFactor, "None", py::arg("theZoomFactor"));
cls_XCAFView_Object.def("ZoomFactor", (Standard_Real (XCAFView_Object::*)()) &XCAFView_Object::ZoomFactor, "None");
cls_XCAFView_Object.def("SetWindowHorizontalSize", (void (XCAFView_Object::*)(Standard_Real)) &XCAFView_Object::SetWindowHorizontalSize, "None", py::arg("theSize"));
cls_XCAFView_Object.def("WindowHorizontalSize", (Standard_Real (XCAFView_Object::*)()) &XCAFView_Object::WindowHorizontalSize, "None");
cls_XCAFView_Object.def("SetWindowVerticalSize", (void (XCAFView_Object::*)(Standard_Real)) &XCAFView_Object::SetWindowVerticalSize, "None", py::arg("theSize"));
cls_XCAFView_Object.def("WindowVerticalSize", (Standard_Real (XCAFView_Object::*)()) &XCAFView_Object::WindowVerticalSize, "None");
cls_XCAFView_Object.def("SetClippingExpression", (void (XCAFView_Object::*)(opencascade::handle<TCollection_HAsciiString>)) &XCAFView_Object::SetClippingExpression, "None", py::arg("theExpression"));
cls_XCAFView_Object.def("ClippingExpression", (opencascade::handle<TCollection_HAsciiString> (XCAFView_Object::*)()) &XCAFView_Object::ClippingExpression, "None");
cls_XCAFView_Object.def("UnsetFrontPlaneClipping", (void (XCAFView_Object::*)()) &XCAFView_Object::UnsetFrontPlaneClipping, "None");
cls_XCAFView_Object.def("HasFrontPlaneClipping", (Standard_Boolean (XCAFView_Object::*)()) &XCAFView_Object::HasFrontPlaneClipping, "None");
cls_XCAFView_Object.def("SetFrontPlaneDistance", (void (XCAFView_Object::*)(Standard_Real)) &XCAFView_Object::SetFrontPlaneDistance, "None", py::arg("theDistance"));
cls_XCAFView_Object.def("FrontPlaneDistance", (Standard_Real (XCAFView_Object::*)()) &XCAFView_Object::FrontPlaneDistance, "None");
cls_XCAFView_Object.def("UnsetBackPlaneClipping", (void (XCAFView_Object::*)()) &XCAFView_Object::UnsetBackPlaneClipping, "None");
cls_XCAFView_Object.def("HasBackPlaneClipping", (Standard_Boolean (XCAFView_Object::*)()) &XCAFView_Object::HasBackPlaneClipping, "None");
cls_XCAFView_Object.def("SetBackPlaneDistance", (void (XCAFView_Object::*)(Standard_Real)) &XCAFView_Object::SetBackPlaneDistance, "None", py::arg("theDistance"));
cls_XCAFView_Object.def("BackPlaneDistance", (Standard_Real (XCAFView_Object::*)()) &XCAFView_Object::BackPlaneDistance, "None");
cls_XCAFView_Object.def("SetViewVolumeSidesClipping", (void (XCAFView_Object::*)(Standard_Boolean)) &XCAFView_Object::SetViewVolumeSidesClipping, "None", py::arg("theViewVolumeSidesClipping"));
cls_XCAFView_Object.def("HasViewVolumeSidesClipping", (Standard_Boolean (XCAFView_Object::*)()) &XCAFView_Object::HasViewVolumeSidesClipping, "None");
cls_XCAFView_Object.def("CreateGDTPoints", (void (XCAFView_Object::*)(const Standard_Integer)) &XCAFView_Object::CreateGDTPoints, "None", py::arg("theLenght"));
cls_XCAFView_Object.def("HasGDTPoints", (Standard_Boolean (XCAFView_Object::*)()) &XCAFView_Object::HasGDTPoints, "None");
cls_XCAFView_Object.def("NbGDTPoints", (Standard_Integer (XCAFView_Object::*)()) &XCAFView_Object::NbGDTPoints, "None");
cls_XCAFView_Object.def("SetGDTPoint", (void (XCAFView_Object::*)(const Standard_Integer, const gp_Pnt)) &XCAFView_Object::SetGDTPoint, "None", py::arg("theIndex"), py::arg("thePoint"));
cls_XCAFView_Object.def("GDTPoint", (gp_Pnt (XCAFView_Object::*)(const Standard_Integer)) &XCAFView_Object::GDTPoint, "None", py::arg("theIndex"));
cls_XCAFView_Object.def_static("get_type_name_", (const char * (*)()) &XCAFView_Object::get_type_name, "None");
cls_XCAFView_Object.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFView_Object::get_type_descriptor, "None");
cls_XCAFView_Object.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFView_Object::*)() const) &XCAFView_Object::DynamicType, "None");


}
