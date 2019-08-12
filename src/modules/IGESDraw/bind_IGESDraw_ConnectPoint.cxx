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
#include <gp_XYZ.hxx>
#include <Standard_Handle.hxx>
#include <Standard_TypeDef.hxx>
#include <TCollection_HAsciiString.hxx>
#include <IGESGraph_TextDisplayTemplate.hxx>
#include <gp_Pnt.hxx>
#include <IGESDraw_ConnectPoint.hxx>
#include <Standard_Type.hxx>

void bind_IGESDraw_ConnectPoint(py::module &mod){

py::class_<IGESDraw_ConnectPoint, opencascade::handle<IGESDraw_ConnectPoint>, IGESData_IGESEntity> cls_IGESDraw_ConnectPoint(mod, "IGESDraw_ConnectPoint", "defines IGESConnectPoint, Type <132> Form Number <0> in package IGESDraw");

// Constructors
cls_IGESDraw_ConnectPoint.def(py::init<>());

// Fields

// Methods
cls_IGESDraw_ConnectPoint.def("Init", (void (IGESDraw_ConnectPoint::*)(const gp_XYZ &, const opencascade::handle<IGESData_IGESEntity> &, const Standard_Integer, const Standard_Integer, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<IGESGraph_TextDisplayTemplate> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<IGESGraph_TextDisplayTemplate> &, const Standard_Integer, const Standard_Integer, const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &)) &IGESDraw_ConnectPoint::Init, "This method is used to set the fields of the class ConnectPoint - aPoint : A Coordinate point - aDisplaySymbol : Display symbol Geometry - aTypeFlag : Type of the connection - aFunctionFlag : Function flag for the connection - aFunctionIdentifier : Connection Point Function Identifier - anIdentifierTemplate : Connection Point Function Template - aFunctionName : Connection Point Function Name - aFunctionTemplate : Connection Point Function Template - aPointIdentifier : Unique Connect Point Identifier - aFunctionCode : Connect Point Function Code - aSwapFlag : Connect Point Swap Flag - anOwnerSubfigure : Pointer to the 'Owner' Entity", py::arg("aPoint"), py::arg("aDisplaySymbol"), py::arg("aTypeFlag"), py::arg("aFunctionFlag"), py::arg("aFunctionIdentifier"), py::arg("anIdentifierTemplate"), py::arg("aFunctionName"), py::arg("aFunctionTemplate"), py::arg("aPointIdentifier"), py::arg("aFunctionCode"), py::arg("aSwapFlag"), py::arg("anOwnerSubfigure"));
cls_IGESDraw_ConnectPoint.def("Point", (gp_Pnt (IGESDraw_ConnectPoint::*)() const) &IGESDraw_ConnectPoint::Point, "returns the coordinate of the connection point");
cls_IGESDraw_ConnectPoint.def("TransformedPoint", (gp_Pnt (IGESDraw_ConnectPoint::*)() const) &IGESDraw_ConnectPoint::TransformedPoint, "returns the Transformed coordinate of the connection point");
cls_IGESDraw_ConnectPoint.def("HasDisplaySymbol", (Standard_Boolean (IGESDraw_ConnectPoint::*)() const) &IGESDraw_ConnectPoint::HasDisplaySymbol, "returns True if Display symbol is specified else returns False");
cls_IGESDraw_ConnectPoint.def("DisplaySymbol", (opencascade::handle<IGESData_IGESEntity> (IGESDraw_ConnectPoint::*)() const) &IGESDraw_ConnectPoint::DisplaySymbol, "if display symbol specified returns display symbol geometric entity else returns NULL Handle");
cls_IGESDraw_ConnectPoint.def("TypeFlag", (Standard_Integer (IGESDraw_ConnectPoint::*)() const) &IGESDraw_ConnectPoint::TypeFlag, "return value specifies a particular type of connection : Type Flag = 0 : Not Specified(default) 1 : Nonspecific logical point of connection 2 : Nonspecific physical point of connection 101 : Logical component pin 102 : Logical part connector 103 : Logical offpage connector 104 : Logical global signal connector 201 : Physical PWA surface mount pin 202 : Physical PWA blind pin 203 : Physical PWA thru-pin 5001-9999 : Implementor defined.");
cls_IGESDraw_ConnectPoint.def("FunctionFlag", (Standard_Integer (IGESDraw_ConnectPoint::*)() const) &IGESDraw_ConnectPoint::FunctionFlag, "returns Function Code that specifies a particular function for the ECO576 connection : e.g., Function Flag = 0 : Unspecified(default) = 1 : Electrical Signal = 2 : Fluid flow Signal");
cls_IGESDraw_ConnectPoint.def("FunctionIdentifier", (opencascade::handle<TCollection_HAsciiString> (IGESDraw_ConnectPoint::*)() const) &IGESDraw_ConnectPoint::FunctionIdentifier, "return HAsciiString identifying Pin Number or Nozzle Label etc.");
cls_IGESDraw_ConnectPoint.def("HasIdentifierTemplate", (Standard_Boolean (IGESDraw_ConnectPoint::*)() const) &IGESDraw_ConnectPoint::HasIdentifierTemplate, "returns True if Text Display Template is specified for Identifier else returns False");
cls_IGESDraw_ConnectPoint.def("IdentifierTemplate", (opencascade::handle<IGESGraph_TextDisplayTemplate> (IGESDraw_ConnectPoint::*)() const) &IGESDraw_ConnectPoint::IdentifierTemplate, "if Text Display Template for the Function Identifier is defined, returns TestDisplayTemplate else returns NULL Handle");
cls_IGESDraw_ConnectPoint.def("FunctionName", (opencascade::handle<TCollection_HAsciiString> (IGESDraw_ConnectPoint::*)() const) &IGESDraw_ConnectPoint::FunctionName, "returns Connection Point Function Name");
cls_IGESDraw_ConnectPoint.def("HasFunctionTemplate", (Standard_Boolean (IGESDraw_ConnectPoint::*)() const) &IGESDraw_ConnectPoint::HasFunctionTemplate, "returns True if Text Display Template is specified for Function Name else returns False");
cls_IGESDraw_ConnectPoint.def("FunctionTemplate", (opencascade::handle<IGESGraph_TextDisplayTemplate> (IGESDraw_ConnectPoint::*)() const) &IGESDraw_ConnectPoint::FunctionTemplate, "if Text Display Template for the Function Name is defined, returns TestDisplayTemplate else returns NULL Handle");
cls_IGESDraw_ConnectPoint.def("PointIdentifier", (Standard_Integer (IGESDraw_ConnectPoint::*)() const) &IGESDraw_ConnectPoint::PointIdentifier, "returns the Unique Connect Point Identifier");
cls_IGESDraw_ConnectPoint.def("FunctionCode", (Standard_Integer (IGESDraw_ConnectPoint::*)() const) &IGESDraw_ConnectPoint::FunctionCode, "returns the Connect Point Function Code");
cls_IGESDraw_ConnectPoint.def("SwapFlag", (Standard_Boolean (IGESDraw_ConnectPoint::*)() const) &IGESDraw_ConnectPoint::SwapFlag, "return value = 0 : Connect point may be swapped(default) = 1 : Connect point may not be swapped");
cls_IGESDraw_ConnectPoint.def("HasOwnerSubfigure", (Standard_Boolean (IGESDraw_ConnectPoint::*)() const) &IGESDraw_ConnectPoint::HasOwnerSubfigure, "returns True if Network Subfigure Instance/Definition Entity is specified else returns False");
cls_IGESDraw_ConnectPoint.def("OwnerSubfigure", (opencascade::handle<IGESData_IGESEntity> (IGESDraw_ConnectPoint::*)() const) &IGESDraw_ConnectPoint::OwnerSubfigure, "returns 'owner' Network Subfigure Instance Entity, or Network Subfigure Definition Entity, or NULL Handle.");
cls_IGESDraw_ConnectPoint.def_static("get_type_name_", (const char * (*)()) &IGESDraw_ConnectPoint::get_type_name, "None");
cls_IGESDraw_ConnectPoint.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDraw_ConnectPoint::get_type_descriptor, "None");
cls_IGESDraw_ConnectPoint.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDraw_ConnectPoint::*)() const) &IGESDraw_ConnectPoint::DynamicType, "None");

// Enums

}