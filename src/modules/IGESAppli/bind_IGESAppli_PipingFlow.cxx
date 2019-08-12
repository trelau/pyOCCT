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
#include <IGESAppli_PipingFlow.hxx>
#include <Standard_Type.hxx>

void bind_IGESAppli_PipingFlow(py::module &mod){

py::class_<IGESAppli_PipingFlow, opencascade::handle<IGESAppli_PipingFlow>, IGESData_IGESEntity> cls_IGESAppli_PipingFlow(mod, "IGESAppli_PipingFlow", "defines PipingFlow, Type <402> Form <20> in package IGESAppli Represents a single fluid flow path");

// Constructors
cls_IGESAppli_PipingFlow.def(py::init<>());

// Fields

// Methods
cls_IGESAppli_PipingFlow.def("Init", (void (IGESAppli_PipingFlow::*)(const Standard_Integer, const Standard_Integer, const opencascade::handle<IGESData_HArray1OfIGESEntity> &, const opencascade::handle<IGESDraw_HArray1OfConnectPoint> &, const opencascade::handle<IGESData_HArray1OfIGESEntity> &, const opencascade::handle<Interface_HArray1OfHAsciiString> &, const opencascade::handle<IGESGraph_HArray1OfTextDisplayTemplate> &, const opencascade::handle<IGESData_HArray1OfIGESEntity> &)) &IGESAppli_PipingFlow::Init, "This method is used to set the fields of the class PipingFlow - nbContextFlags : Count of Context Flags, always = 1 - aFlowType : Type of Flow, default = 0 - allFlowAssocs : PipingFlow Associativity Entities - allConnectPoints : Connect Point Entities - allJoins : Join Entities - allFlowNames : PipingFlow Names - allTextDispTs : Text Display Template Entities - allContFlowAssocs : Continuation Flow Associativity Entities", py::arg("nbContextFlags"), py::arg("aFlowType"), py::arg("allFlowAssocs"), py::arg("allConnectPoints"), py::arg("allJoins"), py::arg("allFlowNames"), py::arg("allTextDisps"), py::arg("allContFlowAssocs"));
cls_IGESAppli_PipingFlow.def("OwnCorrect", (Standard_Boolean (IGESAppli_PipingFlow::*)()) &IGESAppli_PipingFlow::OwnCorrect, "forces NbContextFalgs to 1, returns True if changed");
cls_IGESAppli_PipingFlow.def("NbContextFlags", (Standard_Integer (IGESAppli_PipingFlow::*)() const) &IGESAppli_PipingFlow::NbContextFlags, "returns number of Count of Context Flags, always = 1");
cls_IGESAppli_PipingFlow.def("NbFlowAssociativities", (Standard_Integer (IGESAppli_PipingFlow::*)() const) &IGESAppli_PipingFlow::NbFlowAssociativities, "returns number of Piping Flow Associativity Entities");
cls_IGESAppli_PipingFlow.def("NbConnectPoints", (Standard_Integer (IGESAppli_PipingFlow::*)() const) &IGESAppli_PipingFlow::NbConnectPoints, "returns number of Connect Point Entities");
cls_IGESAppli_PipingFlow.def("NbJoins", (Standard_Integer (IGESAppli_PipingFlow::*)() const) &IGESAppli_PipingFlow::NbJoins, "returns number of Join Entities");
cls_IGESAppli_PipingFlow.def("NbFlowNames", (Standard_Integer (IGESAppli_PipingFlow::*)() const) &IGESAppli_PipingFlow::NbFlowNames, "returns number of Flow Names");
cls_IGESAppli_PipingFlow.def("NbTextDisplayTemplates", (Standard_Integer (IGESAppli_PipingFlow::*)() const) &IGESAppli_PipingFlow::NbTextDisplayTemplates, "returns number of Text Display Template Entities");
cls_IGESAppli_PipingFlow.def("NbContFlowAssociativities", (Standard_Integer (IGESAppli_PipingFlow::*)() const) &IGESAppli_PipingFlow::NbContFlowAssociativities, "returns number of Continuation Piping Flow Associativities");
cls_IGESAppli_PipingFlow.def("TypeOfFlow", (Standard_Integer (IGESAppli_PipingFlow::*)() const) &IGESAppli_PipingFlow::TypeOfFlow, "returns Type of Flow = 0 : Not specified, 1 : Logical, 2 : Physical");
cls_IGESAppli_PipingFlow.def("FlowAssociativity", (opencascade::handle<IGESData_IGESEntity> (IGESAppli_PipingFlow::*)(const Standard_Integer) const) &IGESAppli_PipingFlow::FlowAssociativity, "returns Piping Flow Associativity Entity raises exception if Index <= 0 or Index > NbFlowAssociativities()", py::arg("Index"));
cls_IGESAppli_PipingFlow.def("ConnectPoint", (opencascade::handle<IGESDraw_ConnectPoint> (IGESAppli_PipingFlow::*)(const Standard_Integer) const) &IGESAppli_PipingFlow::ConnectPoint, "returns Connect Point Entity raises exception if Index <= 0 or Index > NbConnectPoints()", py::arg("Index"));
cls_IGESAppli_PipingFlow.def("Join", (opencascade::handle<IGESData_IGESEntity> (IGESAppli_PipingFlow::*)(const Standard_Integer) const) &IGESAppli_PipingFlow::Join, "returns Join Entity raises exception if Index <= 0 or Index > NbJoins()", py::arg("Index"));
cls_IGESAppli_PipingFlow.def("FlowName", (opencascade::handle<TCollection_HAsciiString> (IGESAppli_PipingFlow::*)(const Standard_Integer) const) &IGESAppli_PipingFlow::FlowName, "returns Flow Name raises exception if Index <= 0 or Index > NbFlowNames()", py::arg("Index"));
cls_IGESAppli_PipingFlow.def("TextDisplayTemplate", (opencascade::handle<IGESGraph_TextDisplayTemplate> (IGESAppli_PipingFlow::*)(const Standard_Integer) const) &IGESAppli_PipingFlow::TextDisplayTemplate, "returns Text Display Template Entity raises exception if Index <= 0 or Index > NbTextDisplayTemplates()", py::arg("Index"));
cls_IGESAppli_PipingFlow.def("ContFlowAssociativity", (opencascade::handle<IGESData_IGESEntity> (IGESAppli_PipingFlow::*)(const Standard_Integer) const) &IGESAppli_PipingFlow::ContFlowAssociativity, "returns Continuation Piping Flow Associativity Entity raises exception if Index <= 0 or Index > NbContFlowAssociativities()", py::arg("Index"));
cls_IGESAppli_PipingFlow.def_static("get_type_name_", (const char * (*)()) &IGESAppli_PipingFlow::get_type_name, "None");
cls_IGESAppli_PipingFlow.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESAppli_PipingFlow::get_type_descriptor, "None");
cls_IGESAppli_PipingFlow.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESAppli_PipingFlow::*)() const) &IGESAppli_PipingFlow::DynamicType, "None");

// Enums

}