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
#include <TCollection_HAsciiString.hxx>
#include <IGESData_HArray1OfIGESEntity.hxx>
#include <IGESGraph_TextDisplayTemplate.hxx>
#include <IGESDraw_HArray1OfConnectPoint.hxx>
#include <IGESDraw_ConnectPoint.hxx>
#include <IGESDraw_NetworkSubfigureDef.hxx>
#include <Standard_Type.hxx>

void bind_IGESDraw_NetworkSubfigureDef(py::module &mod){

py::class_<IGESDraw_NetworkSubfigureDef, opencascade::handle<IGESDraw_NetworkSubfigureDef>, IGESData_IGESEntity> cls_IGESDraw_NetworkSubfigureDef(mod, "IGESDraw_NetworkSubfigureDef", "defines IGESNetworkSubfigureDef, Type <320> Form Number <0> in package IGESDraw");

// Constructors
cls_IGESDraw_NetworkSubfigureDef.def(py::init<>());

// Fields

// Methods
cls_IGESDraw_NetworkSubfigureDef.def("Init", (void (IGESDraw_NetworkSubfigureDef::*)(const Standard_Integer, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<IGESData_HArray1OfIGESEntity> &, const Standard_Integer, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<IGESGraph_TextDisplayTemplate> &, const opencascade::handle<IGESDraw_HArray1OfConnectPoint> &)) &IGESDraw_NetworkSubfigureDef::Init, "This method is used to set fields of the class NetworkSubfigureDef - aDepth : Depth of Subfigure (indicating the amount of nesting) - aName : Subfigure Name - allEntities : Associated subfigures Entities exclusive of primary reference designator and Control Points. - aTypeFlag : Type flag determines which Entity belongs in which design (Logical design or Physical design) - aDesignator : Designator HAsciiString and its Template - allPointEntities : Associated Connect Point Entities", py::arg("aDepth"), py::arg("aName"), py::arg("allEntities"), py::arg("aTypeFlag"), py::arg("aDesignator"), py::arg("aTemplate"), py::arg("allPointEntities"));
cls_IGESDraw_NetworkSubfigureDef.def("Depth", (Standard_Integer (IGESDraw_NetworkSubfigureDef::*)() const) &IGESDraw_NetworkSubfigureDef::Depth, "returns Depth of Subfigure(indication the amount of nesting) Note : The Depth is inclusive of both Network Subfigure Definition Entity and the Ordinary Subfigure Definition Entity. Thus, the two may be nested.");
cls_IGESDraw_NetworkSubfigureDef.def("Name", (opencascade::handle<TCollection_HAsciiString> (IGESDraw_NetworkSubfigureDef::*)() const) &IGESDraw_NetworkSubfigureDef::Name, "returns the Subfigure Name");
cls_IGESDraw_NetworkSubfigureDef.def("NbEntities", (Standard_Integer (IGESDraw_NetworkSubfigureDef::*)() const) &IGESDraw_NetworkSubfigureDef::NbEntities, "returns Number of Associated(child) entries in subfigure exclusive of primary reference designator and Control Points");
cls_IGESDraw_NetworkSubfigureDef.def("Entity", (opencascade::handle<IGESData_IGESEntity> (IGESDraw_NetworkSubfigureDef::*)(const Standard_Integer) const) &IGESDraw_NetworkSubfigureDef::Entity, "returns the Index'th IGESEntity in subfigure exclusive of primary reference designator and Control Points raises exception if Index <=0 or Index > NbEntities()", py::arg("Index"));
cls_IGESDraw_NetworkSubfigureDef.def("TypeFlag", (Standard_Integer (IGESDraw_NetworkSubfigureDef::*)() const) &IGESDraw_NetworkSubfigureDef::TypeFlag, "return value = 0 : Not Specified = 1 : Logical design = 2 : Physical design");
cls_IGESDraw_NetworkSubfigureDef.def("Designator", (opencascade::handle<TCollection_HAsciiString> (IGESDraw_NetworkSubfigureDef::*)() const) &IGESDraw_NetworkSubfigureDef::Designator, "returns Primary Reference Designator");
cls_IGESDraw_NetworkSubfigureDef.def("HasDesignatorTemplate", (Standard_Boolean (IGESDraw_NetworkSubfigureDef::*)() const) &IGESDraw_NetworkSubfigureDef::HasDesignatorTemplate, "returns True if Text Display Template is specified for primary designator else returns False");
cls_IGESDraw_NetworkSubfigureDef.def("DesignatorTemplate", (opencascade::handle<IGESGraph_TextDisplayTemplate> (IGESDraw_NetworkSubfigureDef::*)() const) &IGESDraw_NetworkSubfigureDef::DesignatorTemplate, "if Text Display Template specified then return TextDisplayTemplate else return NULL Handle");
cls_IGESDraw_NetworkSubfigureDef.def("NbPointEntities", (Standard_Integer (IGESDraw_NetworkSubfigureDef::*)() const) &IGESDraw_NetworkSubfigureDef::NbPointEntities, "returns the Number Of Associated(child) Connect Point Entities");
cls_IGESDraw_NetworkSubfigureDef.def("HasPointEntity", (Standard_Boolean (IGESDraw_NetworkSubfigureDef::*)(const Standard_Integer) const) &IGESDraw_NetworkSubfigureDef::HasPointEntity, "returns True is Index'th Associated Connect Point Entity is present else returns False raises exception if Index is out of bound", py::arg("Index"));
cls_IGESDraw_NetworkSubfigureDef.def("PointEntity", (opencascade::handle<IGESDraw_ConnectPoint> (IGESDraw_NetworkSubfigureDef::*)(const Standard_Integer) const) &IGESDraw_NetworkSubfigureDef::PointEntity, "returns the Index'th Associated Connect Point Entity raises exception if Index <= 0 or Index > NbPointEntities()", py::arg("Index"));
cls_IGESDraw_NetworkSubfigureDef.def_static("get_type_name_", (const char * (*)()) &IGESDraw_NetworkSubfigureDef::get_type_name, "None");
cls_IGESDraw_NetworkSubfigureDef.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDraw_NetworkSubfigureDef::get_type_descriptor, "None");
cls_IGESDraw_NetworkSubfigureDef.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDraw_NetworkSubfigureDef::*)() const) &IGESDraw_NetworkSubfigureDef::DynamicType, "None");

// Enums

}