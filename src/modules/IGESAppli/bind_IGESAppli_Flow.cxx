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
#include <IGESData_HArray1OfIGESEntity.hxx>
#include <IGESDraw_HArray1OfConnectPoint.hxx>
#include <Interface_HArray1OfHAsciiString.hxx>
#include <IGESGraph_HArray1OfTextDisplayTemplate.hxx>
#include <IGESDraw_ConnectPoint.hxx>
#include <TCollection_HAsciiString.hxx>
#include <IGESGraph_TextDisplayTemplate.hxx>
#include <IGESAppli_Flow.hxx>
#include <Standard_Type.hxx>

void bind_IGESAppli_Flow(py::module &mod){

py::class_<IGESAppli_Flow, opencascade::handle<IGESAppli_Flow>, IGESData_IGESEntity> cls_IGESAppli_Flow(mod, "IGESAppli_Flow", "defines Flow, Type <402> Form <18> in package IGESAppli Represents a single signal or a single fluid flow path starting from a starting Connect Point Entity and including additional intermediate connect points.");

// Constructors
cls_IGESAppli_Flow.def(py::init<>());

// Fields

// Methods
cls_IGESAppli_Flow.def("Init", (void (IGESAppli_Flow::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const opencascade::handle<IGESData_HArray1OfIGESEntity> &, const opencascade::handle<IGESDraw_HArray1OfConnectPoint> &, const opencascade::handle<IGESData_HArray1OfIGESEntity> &, const opencascade::handle<Interface_HArray1OfHAsciiString> &, const opencascade::handle<IGESGraph_HArray1OfTextDisplayTemplate> &, const opencascade::handle<IGESData_HArray1OfIGESEntity> &)) &IGESAppli_Flow::Init, "This method is used to set the fields of the class Flow - nbContextFlags : Count of Context Flags, always = 2 - aFlowType : Type of Flow, default = 0 - aFuncFlag : Function Flag, default = 0 - allFlowAssocs : Flow Associativity Entities - allConnectPoints : Connect Point Entities - allJoins : Join Entities - allFlowNames : Flow Names - allTextDisps : Text Display Template Entities - allContFlowAssocs : Continuation Flow Associativity Entities", py::arg("nbContextFlags"), py::arg("aFlowType"), py::arg("aFuncFlag"), py::arg("allFlowAssocs"), py::arg("allConnectPoints"), py::arg("allJoins"), py::arg("allFlowNames"), py::arg("allTextDisps"), py::arg("allContFlowAssocs"));
cls_IGESAppli_Flow.def("OwnCorrect", (Standard_Boolean (IGESAppli_Flow::*)()) &IGESAppli_Flow::OwnCorrect, "forces NbContextFalgs to 2, returns True if changed");
cls_IGESAppli_Flow.def("NbContextFlags", (Standard_Integer (IGESAppli_Flow::*)() const) &IGESAppli_Flow::NbContextFlags, "returns number of Count of Context Flags, always = 2");
cls_IGESAppli_Flow.def("NbFlowAssociativities", (Standard_Integer (IGESAppli_Flow::*)() const) &IGESAppli_Flow::NbFlowAssociativities, "returns number of Flow Associativity Entities");
cls_IGESAppli_Flow.def("NbConnectPoints", (Standard_Integer (IGESAppli_Flow::*)() const) &IGESAppli_Flow::NbConnectPoints, "returns number of Connect Point Entities");
cls_IGESAppli_Flow.def("NbJoins", (Standard_Integer (IGESAppli_Flow::*)() const) &IGESAppli_Flow::NbJoins, "returns number of Join Entities");
cls_IGESAppli_Flow.def("NbFlowNames", (Standard_Integer (IGESAppli_Flow::*)() const) &IGESAppli_Flow::NbFlowNames, "returns number of Flow Names");
cls_IGESAppli_Flow.def("NbTextDisplayTemplates", (Standard_Integer (IGESAppli_Flow::*)() const) &IGESAppli_Flow::NbTextDisplayTemplates, "returns number of Text Display Template Entities");
cls_IGESAppli_Flow.def("NbContFlowAssociativities", (Standard_Integer (IGESAppli_Flow::*)() const) &IGESAppli_Flow::NbContFlowAssociativities, "returns number of Continuation Flow Associativity Entities");
cls_IGESAppli_Flow.def("TypeOfFlow", (Standard_Integer (IGESAppli_Flow::*)() const) &IGESAppli_Flow::TypeOfFlow, "returns Type of Flow = 0 : Not Specified (default) 1 : Logical 2 : Physical");
cls_IGESAppli_Flow.def("FunctionFlag", (Standard_Integer (IGESAppli_Flow::*)() const) &IGESAppli_Flow::FunctionFlag, "returns Function Flag = 0 : Not Specified (default) 1 : Electrical Signal 2 : Fluid Flow Path");
cls_IGESAppli_Flow.def("FlowAssociativity", (opencascade::handle<IGESData_IGESEntity> (IGESAppli_Flow::*)(const Standard_Integer) const) &IGESAppli_Flow::FlowAssociativity, "returns Flow Associativity Entity raises exception if Index <= 0 or Index > NbFlowAssociativities()", py::arg("Index"));
cls_IGESAppli_Flow.def("ConnectPoint", (opencascade::handle<IGESDraw_ConnectPoint> (IGESAppli_Flow::*)(const Standard_Integer) const) &IGESAppli_Flow::ConnectPoint, "returns Connect Point Entity raises exception if Index <= 0 or Index > NbConnectPoints()", py::arg("Index"));
cls_IGESAppli_Flow.def("Join", (opencascade::handle<IGESData_IGESEntity> (IGESAppli_Flow::*)(const Standard_Integer) const) &IGESAppli_Flow::Join, "returns Join Entity raises exception if Index <= 0 or Index > NbJoins()", py::arg("Index"));
cls_IGESAppli_Flow.def("FlowName", (opencascade::handle<TCollection_HAsciiString> (IGESAppli_Flow::*)(const Standard_Integer) const) &IGESAppli_Flow::FlowName, "returns Flow Name raises exception if Index <= 0 or Index > NbFlowNames()", py::arg("Index"));
cls_IGESAppli_Flow.def("TextDisplayTemplate", (opencascade::handle<IGESGraph_TextDisplayTemplate> (IGESAppli_Flow::*)(const Standard_Integer) const) &IGESAppli_Flow::TextDisplayTemplate, "returns Text Display Template Entity raises exception if Index <= 0 or Index > NbTextDisplayTemplates()", py::arg("Index"));
cls_IGESAppli_Flow.def("ContFlowAssociativity", (opencascade::handle<IGESData_IGESEntity> (IGESAppli_Flow::*)(const Standard_Integer) const) &IGESAppli_Flow::ContFlowAssociativity, "returns Continuation Flow Associativity Entity raises exception if Index <= 0 or Index > NbContFlowAssociativities()", py::arg("Index"));
cls_IGESAppli_Flow.def_static("get_type_name_", (const char * (*)()) &IGESAppli_Flow::get_type_name, "None");
cls_IGESAppli_Flow.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESAppli_Flow::get_type_descriptor, "None");
cls_IGESAppli_Flow.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESAppli_Flow::*)() const) &IGESAppli_Flow::DynamicType, "None");

// Enums

}