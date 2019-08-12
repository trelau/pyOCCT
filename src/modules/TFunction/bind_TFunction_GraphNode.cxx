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
#include <Standard_Handle.hxx>
#include <TFunction_GraphNode.hxx>
#include <TDF_Label.hxx>
#include <Standard_GUID.hxx>
#include <Standard_TypeDef.hxx>
#include <TColStd_MapOfInteger.hxx>
#include <TFunction_ExecutionStatus.hxx>
#include <TDF_RelocationTable.hxx>
#include <TDF_DataSet.hxx>
#include <Standard_OStream.hxx>
#include <Standard_Type.hxx>

void bind_TFunction_GraphNode(py::module &mod){

py::class_<TFunction_GraphNode, opencascade::handle<TFunction_GraphNode>, TDF_Attribute> cls_TFunction_GraphNode(mod, "TFunction_GraphNode", "Provides links between functions.");

// Constructors
cls_TFunction_GraphNode.def(py::init<>());

// Fields

// Methods
cls_TFunction_GraphNode.def_static("Set_", (opencascade::handle<TFunction_GraphNode> (*)(const TDF_Label &)) &TFunction_GraphNode::Set, "Static methods ============== Finds or Creates a graph node attribute at the label <L>. Returns the attribute.", py::arg("L"));
cls_TFunction_GraphNode.def_static("GetID_", (const Standard_GUID & (*)()) &TFunction_GraphNode::GetID, "Returns the GUID for GraphNode attribute. Instant methods =============== Constructor (empty).");
cls_TFunction_GraphNode.def("AddPrevious", (Standard_Boolean (TFunction_GraphNode::*)(const Standard_Integer)) &TFunction_GraphNode::AddPrevious, "Defines a reference to the function as a previous one.", py::arg("funcID"));
cls_TFunction_GraphNode.def("AddPrevious", (Standard_Boolean (TFunction_GraphNode::*)(const TDF_Label &)) &TFunction_GraphNode::AddPrevious, "Defines a reference to the function as a previous one.", py::arg("func"));
cls_TFunction_GraphNode.def("RemovePrevious", (Standard_Boolean (TFunction_GraphNode::*)(const Standard_Integer)) &TFunction_GraphNode::RemovePrevious, "Removes a reference to the function as a previous one.", py::arg("funcID"));
cls_TFunction_GraphNode.def("RemovePrevious", (Standard_Boolean (TFunction_GraphNode::*)(const TDF_Label &)) &TFunction_GraphNode::RemovePrevious, "Removes a reference to the function as a previous one.", py::arg("func"));
cls_TFunction_GraphNode.def("GetPrevious", (const TColStd_MapOfInteger & (TFunction_GraphNode::*)() const) &TFunction_GraphNode::GetPrevious, "Returns a map of previous functions.");
cls_TFunction_GraphNode.def("RemoveAllPrevious", (void (TFunction_GraphNode::*)()) &TFunction_GraphNode::RemoveAllPrevious, "Clears a map of previous functions.");
cls_TFunction_GraphNode.def("AddNext", (Standard_Boolean (TFunction_GraphNode::*)(const Standard_Integer)) &TFunction_GraphNode::AddNext, "Defines a reference to the function as a next one.", py::arg("funcID"));
cls_TFunction_GraphNode.def("AddNext", (Standard_Boolean (TFunction_GraphNode::*)(const TDF_Label &)) &TFunction_GraphNode::AddNext, "Defines a reference to the function as a next one.", py::arg("func"));
cls_TFunction_GraphNode.def("RemoveNext", (Standard_Boolean (TFunction_GraphNode::*)(const Standard_Integer)) &TFunction_GraphNode::RemoveNext, "Removes a reference to the function as a next one.", py::arg("funcID"));
cls_TFunction_GraphNode.def("RemoveNext", (Standard_Boolean (TFunction_GraphNode::*)(const TDF_Label &)) &TFunction_GraphNode::RemoveNext, "Removes a reference to the function as a next one.", py::arg("func"));
cls_TFunction_GraphNode.def("GetNext", (const TColStd_MapOfInteger & (TFunction_GraphNode::*)() const) &TFunction_GraphNode::GetNext, "Returns a map of next functions.");
cls_TFunction_GraphNode.def("RemoveAllNext", (void (TFunction_GraphNode::*)()) &TFunction_GraphNode::RemoveAllNext, "Clears a map of next functions.");
cls_TFunction_GraphNode.def("GetStatus", (TFunction_ExecutionStatus (TFunction_GraphNode::*)() const) &TFunction_GraphNode::GetStatus, "Returns the execution status of the function.");
cls_TFunction_GraphNode.def("SetStatus", (void (TFunction_GraphNode::*)(const TFunction_ExecutionStatus)) &TFunction_GraphNode::SetStatus, "Defines an execution status for a function. Implementation of Attribute methods ===================================", py::arg("status"));
cls_TFunction_GraphNode.def("ID", (const Standard_GUID & (TFunction_GraphNode::*)() const) &TFunction_GraphNode::ID, "None");
cls_TFunction_GraphNode.def("Restore", (void (TFunction_GraphNode::*)(const opencascade::handle<TDF_Attribute> &)) &TFunction_GraphNode::Restore, "None", py::arg("with"));
cls_TFunction_GraphNode.def("Paste", (void (TFunction_GraphNode::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TFunction_GraphNode::Paste, "None", py::arg("into"), py::arg("RT"));
cls_TFunction_GraphNode.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TFunction_GraphNode::*)() const) &TFunction_GraphNode::NewEmpty, "None");
cls_TFunction_GraphNode.def("References", (void (TFunction_GraphNode::*)(const opencascade::handle<TDF_DataSet> &) const) &TFunction_GraphNode::References, "None", py::arg("aDataSet"));
cls_TFunction_GraphNode.def("Dump", (Standard_OStream & (TFunction_GraphNode::*)(Standard_OStream &) const) &TFunction_GraphNode::Dump, "None", py::arg("anOS"));
cls_TFunction_GraphNode.def_static("get_type_name_", (const char * (*)()) &TFunction_GraphNode::get_type_name, "None");
cls_TFunction_GraphNode.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TFunction_GraphNode::get_type_descriptor, "None");
cls_TFunction_GraphNode.def("DynamicType", (const opencascade::handle<Standard_Type> & (TFunction_GraphNode::*)() const) &TFunction_GraphNode::DynamicType, "None");

// Enums

}