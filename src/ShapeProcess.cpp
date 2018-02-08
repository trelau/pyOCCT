/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC (info@laughlinresearch.com)

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
#include <pyOCCT_Common.hpp>

#include <Standard_Transient.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <ShapeProcess_Context.hxx>
#include <Standard_Type.hxx>
#include <ShapeProcess_Operator.hxx>
#include <Resource_Manager.hxx>
#include <TCollection_AsciiString.hxx>
#include <Message_Messenger.hxx>
#include <Message_ProgressIndicator.hxx>
#include <TopoDS_Shape.hxx>
#include <TopTools_DataMapOfShapeShape.hxx>
#include <ShapeExtend_MsgRegistrator.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <ShapeBuild_ReShape.hxx>
#include <BRepTools_Modifier.hxx>
#include <Message_Msg.hxx>
#include <Message_Gravity.hxx>
#include <GeomAbs_Shape.hxx>
#include <ShapeProcess_ShapeContext.hxx>
#include <ShapeProcess_OperFunc.hxx>
#include <ShapeProcess_UOperator.hxx>
#include <BRepTools_Modification.hxx>
#include <ShapeProcess_OperLibrary.hxx>
#include <ShapeProcess.hxx>

PYBIND11_MODULE(ShapeProcess, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.Resource");
	py::module::import("OCCT.TCollection");
	py::module::import("OCCT.Message");
	py::module::import("OCCT.TopoDS");
	py::module::import("OCCT.TopTools");
	py::module::import("OCCT.ShapeExtend");
	py::module::import("OCCT.TopAbs");
	py::module::import("OCCT.ShapeBuild");
	py::module::import("OCCT.BRepTools");
	py::module::import("OCCT.GeomAbs");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeProcess_Operator.hxx
	py::class_<ShapeProcess_Operator, opencascade::handle<ShapeProcess_Operator>, Standard_Transient> cls_ShapeProcess_Operator(mod, "ShapeProcess_Operator", "Abstract Operator class providing a tool to perform an operation on Context");
	cls_ShapeProcess_Operator.def("Perform", (Standard_Boolean (ShapeProcess_Operator::*)(const opencascade::handle<ShapeProcess_Context> &)) &ShapeProcess_Operator::Perform, "Performs operation and eventually records changes in the context", py::arg("context"));
	cls_ShapeProcess_Operator.def_static("get_type_name_", (const char * (*)()) &ShapeProcess_Operator::get_type_name, "None");
	cls_ShapeProcess_Operator.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeProcess_Operator::get_type_descriptor, "None");
	cls_ShapeProcess_Operator.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeProcess_Operator::*)() const ) &ShapeProcess_Operator::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeProcess_Context.hxx
	py::class_<ShapeProcess_Context, opencascade::handle<ShapeProcess_Context>, Standard_Transient> cls_ShapeProcess_Context(mod, "ShapeProcess_Context", "Provides convenient interface to resource file Allows to load resource file and get values of attributes starting from some scope, for example if scope is defined as 'ToV4' and requested parameter is 'exec.op', value of 'ToV4.exec.op' parameter from the resource file will be returned");
	cls_ShapeProcess_Context.def(py::init<>());
	cls_ShapeProcess_Context.def(py::init<const Standard_CString>(), py::arg("file"));
	cls_ShapeProcess_Context.def(py::init<const Standard_CString, const Standard_CString>(), py::arg("file"), py::arg("scope"));
	cls_ShapeProcess_Context.def("Init", [](ShapeProcess_Context &self, const Standard_CString a0) -> Standard_Boolean { return self.Init(a0); }, py::arg("file"));
	cls_ShapeProcess_Context.def("Init", (Standard_Boolean (ShapeProcess_Context::*)(const Standard_CString, const Standard_CString)) &ShapeProcess_Context::Init, "Initialises a tool by loading resource file and (if specified) sets starting scope Returns False if resource file not found", py::arg("file"), py::arg("scope"));
	cls_ShapeProcess_Context.def("LoadResourceManager", (opencascade::handle<Resource_Manager> (ShapeProcess_Context::*)(const Standard_CString)) &ShapeProcess_Context::LoadResourceManager, "Loading Resource_Manager object if this object not equal internal static Resource_Manager object or internal static Resource_Manager object is null", py::arg("file"));
	cls_ShapeProcess_Context.def("ResourceManager", (const opencascade::handle<Resource_Manager> & (ShapeProcess_Context::*)() const ) &ShapeProcess_Context::ResourceManager, "Returns internal Resource_Manager object");
	cls_ShapeProcess_Context.def("SetScope", (void (ShapeProcess_Context::*)(const Standard_CString)) &ShapeProcess_Context::SetScope, "Set a new (sub)scope", py::arg("scope"));
	cls_ShapeProcess_Context.def("UnSetScope", (void (ShapeProcess_Context::*)()) &ShapeProcess_Context::UnSetScope, "Go out of current scope");
	cls_ShapeProcess_Context.def("IsParamSet", (Standard_Boolean (ShapeProcess_Context::*)(const Standard_CString) const ) &ShapeProcess_Context::IsParamSet, "Returns True if parameter is defined in the resource file", py::arg("param"));
	cls_ShapeProcess_Context.def("GetReal", [](ShapeProcess_Context &self, const Standard_CString param, Standard_Real & val){ Standard_Boolean rv = self.GetReal(param, val); return std::tuple<Standard_Boolean, Standard_Real &>(rv, val); }, "None", py::arg("param"), py::arg("val"));
	cls_ShapeProcess_Context.def("GetInteger", [](ShapeProcess_Context &self, const Standard_CString param, Standard_Integer & val){ Standard_Boolean rv = self.GetInteger(param, val); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, val); }, "None", py::arg("param"), py::arg("val"));
	cls_ShapeProcess_Context.def("GetBoolean", [](ShapeProcess_Context &self, const Standard_CString param, Standard_Boolean & val){ Standard_Boolean rv = self.GetBoolean(param, val); return std::tuple<Standard_Boolean, Standard_Boolean &>(rv, val); }, "None", py::arg("param"), py::arg("val"));
	cls_ShapeProcess_Context.def("GetString", (Standard_Boolean (ShapeProcess_Context::*)(const Standard_CString, TCollection_AsciiString &) const ) &ShapeProcess_Context::GetString, "Get value of parameter as being of specific type Returns False if parameter is not defined or has a wrong type", py::arg("param"), py::arg("val"));
	cls_ShapeProcess_Context.def("RealVal", (Standard_Real (ShapeProcess_Context::*)(const Standard_CString, const Standard_Real) const ) &ShapeProcess_Context::RealVal, "None", py::arg("param"), py::arg("def"));
	cls_ShapeProcess_Context.def("IntegerVal", (Standard_Integer (ShapeProcess_Context::*)(const Standard_CString, const Standard_Integer) const ) &ShapeProcess_Context::IntegerVal, "None", py::arg("param"), py::arg("def"));
	cls_ShapeProcess_Context.def("BooleanVal", (Standard_Boolean (ShapeProcess_Context::*)(const Standard_CString, const Standard_Boolean) const ) &ShapeProcess_Context::BooleanVal, "None", py::arg("param"), py::arg("def"));
	cls_ShapeProcess_Context.def("StringVal", (Standard_CString (ShapeProcess_Context::*)(const Standard_CString, const Standard_CString) const ) &ShapeProcess_Context::StringVal, "Get value of parameter as being of specific type If parameter is not defined or does not have expected type, returns default value as specified", py::arg("param"), py::arg("def"));
	cls_ShapeProcess_Context.def("SetMessenger", (void (ShapeProcess_Context::*)(const opencascade::handle<Message_Messenger> &)) &ShapeProcess_Context::SetMessenger, "Sets Messenger used for outputting messages.", py::arg("messenger"));
	cls_ShapeProcess_Context.def("Messenger", (opencascade::handle<Message_Messenger> (ShapeProcess_Context::*)() const ) &ShapeProcess_Context::Messenger, "Returns Messenger used for outputting messages.");
	cls_ShapeProcess_Context.def("SetProgress", (void (ShapeProcess_Context::*)(const opencascade::handle<Message_ProgressIndicator> &)) &ShapeProcess_Context::SetProgress, "Sets Progress Indicator.", py::arg("theProgress"));
	cls_ShapeProcess_Context.def("Progress", (opencascade::handle<Message_ProgressIndicator> (ShapeProcess_Context::*)() const ) &ShapeProcess_Context::Progress, "Returns Progress Indicator.");
	cls_ShapeProcess_Context.def("SetTraceLevel", (void (ShapeProcess_Context::*)(const Standard_Integer)) &ShapeProcess_Context::SetTraceLevel, "Sets trace level used for outputting messages - 0: no trace at all - 1: errors - 2: errors and warnings - 3: all messages Default is 1 : Errors traced", py::arg("tracelev"));
	cls_ShapeProcess_Context.def("TraceLevel", (Standard_Integer (ShapeProcess_Context::*)() const ) &ShapeProcess_Context::TraceLevel, "Returns trace level used for outputting messages.");
	cls_ShapeProcess_Context.def_static("get_type_name_", (const char * (*)()) &ShapeProcess_Context::get_type_name, "None");
	cls_ShapeProcess_Context.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeProcess_Context::get_type_descriptor, "None");
	cls_ShapeProcess_Context.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeProcess_Context::*)() const ) &ShapeProcess_Context::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeProcess_ShapeContext.hxx
	py::class_<ShapeProcess_ShapeContext, opencascade::handle<ShapeProcess_ShapeContext>, ShapeProcess_Context> cls_ShapeProcess_ShapeContext(mod, "ShapeProcess_ShapeContext", "Extends Context to handle shapes Contains map of shape-shape, and messages attached to shapes");
	cls_ShapeProcess_ShapeContext.def(py::init<const Standard_CString>(), py::arg("file"));
	cls_ShapeProcess_ShapeContext.def(py::init<const Standard_CString, const Standard_CString>(), py::arg("file"), py::arg("seq"));
	cls_ShapeProcess_ShapeContext.def(py::init<const TopoDS_Shape &, const Standard_CString>(), py::arg("S"), py::arg("file"));
	cls_ShapeProcess_ShapeContext.def(py::init<const TopoDS_Shape &, const Standard_CString, const Standard_CString>(), py::arg("S"), py::arg("file"), py::arg("seq"));
	cls_ShapeProcess_ShapeContext.def("Init", (void (ShapeProcess_ShapeContext::*)(const TopoDS_Shape &)) &ShapeProcess_ShapeContext::Init, "Initializes tool by a new shape and clears all results", py::arg("S"));
	cls_ShapeProcess_ShapeContext.def("Shape", (const TopoDS_Shape & (ShapeProcess_ShapeContext::*)() const ) &ShapeProcess_ShapeContext::Shape, "Returns shape being processed");
	cls_ShapeProcess_ShapeContext.def("Result", (const TopoDS_Shape & (ShapeProcess_ShapeContext::*)() const ) &ShapeProcess_ShapeContext::Result, "Returns current result");
	cls_ShapeProcess_ShapeContext.def("Map", (const TopTools_DataMapOfShapeShape & (ShapeProcess_ShapeContext::*)() const ) &ShapeProcess_ShapeContext::Map, "Returns map of replacements shape -> shape This map is not recursive");
	cls_ShapeProcess_ShapeContext.def("Messages", (const opencascade::handle<ShapeExtend_MsgRegistrator> & (ShapeProcess_ShapeContext::*)() const ) &ShapeProcess_ShapeContext::Messages, "None");
	cls_ShapeProcess_ShapeContext.def("Messages", (opencascade::handle<ShapeExtend_MsgRegistrator> & (ShapeProcess_ShapeContext::*)()) &ShapeProcess_ShapeContext::Messages, "Returns messages recorded during shape processing It can be nullified before processing in order to avoid recording messages");
	cls_ShapeProcess_ShapeContext.def("SetDetalisation", (void (ShapeProcess_ShapeContext::*)(const TopAbs_ShapeEnum)) &ShapeProcess_ShapeContext::SetDetalisation, "None", py::arg("level"));
	cls_ShapeProcess_ShapeContext.def("GetDetalisation", (TopAbs_ShapeEnum (ShapeProcess_ShapeContext::*)() const ) &ShapeProcess_ShapeContext::GetDetalisation, "Set and get value for detalisation level Only shapes of types from TopoDS_COMPOUND and until specified detalisation level will be recorded in maps To cancel mapping, use TopAbs_SHAPE To force full mapping, use TopAbs_VERTEX The default level is TopAbs_FACE");
	cls_ShapeProcess_ShapeContext.def("SetResult", (void (ShapeProcess_ShapeContext::*)(const TopoDS_Shape &)) &ShapeProcess_ShapeContext::SetResult, "Sets a new result shape NOTE: this method should be used very carefully to keep consistency of modifications It is recommended to use RecordModification() methods with explicit definition of mapping from current result to a new one", py::arg("S"));
	cls_ShapeProcess_ShapeContext.def("RecordModification", [](ShapeProcess_ShapeContext &self, const TopTools_DataMapOfShapeShape & a0) -> void { return self.RecordModification(a0); }, py::arg("repl"));
	cls_ShapeProcess_ShapeContext.def("RecordModification", (void (ShapeProcess_ShapeContext::*)(const TopTools_DataMapOfShapeShape &, const opencascade::handle<ShapeExtend_MsgRegistrator> &)) &ShapeProcess_ShapeContext::RecordModification, "None", py::arg("repl"), py::arg("msg"));
	cls_ShapeProcess_ShapeContext.def("RecordModification", (void (ShapeProcess_ShapeContext::*)(const opencascade::handle<ShapeBuild_ReShape> &, const opencascade::handle<ShapeExtend_MsgRegistrator> &)) &ShapeProcess_ShapeContext::RecordModification, "None", py::arg("repl"), py::arg("msg"));
	cls_ShapeProcess_ShapeContext.def("RecordModification", (void (ShapeProcess_ShapeContext::*)(const opencascade::handle<ShapeBuild_ReShape> &)) &ShapeProcess_ShapeContext::RecordModification, "None", py::arg("repl"));
	cls_ShapeProcess_ShapeContext.def("RecordModification", [](ShapeProcess_ShapeContext &self, const TopoDS_Shape & a0, const BRepTools_Modifier & a1) -> void { return self.RecordModification(a0, a1); }, py::arg("sh"), py::arg("repl"));
	cls_ShapeProcess_ShapeContext.def("RecordModification", (void (ShapeProcess_ShapeContext::*)(const TopoDS_Shape &, const BRepTools_Modifier &, const opencascade::handle<ShapeExtend_MsgRegistrator> &)) &ShapeProcess_ShapeContext::RecordModification, "Records modifications and resets result accordingly NOTE: modification of resulting shape should be explicitly defined in the maps along with modifications of subshapes", py::arg("sh"), py::arg("repl"), py::arg("msg"));
	cls_ShapeProcess_ShapeContext.def("AddMessage", [](ShapeProcess_ShapeContext &self, const TopoDS_Shape & a0, const Message_Msg & a1) -> void { return self.AddMessage(a0, a1); }, py::arg("S"), py::arg("msg"));
	cls_ShapeProcess_ShapeContext.def("AddMessage", (void (ShapeProcess_ShapeContext::*)(const TopoDS_Shape &, const Message_Msg &, const Message_Gravity)) &ShapeProcess_ShapeContext::AddMessage, "Record a message for shape S Shape S should be one of subshapes of original shape (or whole one), but not one of intermediate shapes Records only if Message() is not Null", py::arg("S"), py::arg("msg"), py::arg("gravity"));
	cls_ShapeProcess_ShapeContext.def("GetContinuity", (Standard_Boolean (ShapeProcess_ShapeContext::*)(const Standard_CString, GeomAbs_Shape &) const ) &ShapeProcess_ShapeContext::GetContinuity, "Get value of parameter as being of the type GeomAbs_Shape Returns False if parameter is not defined or has a wrong type", py::arg("param"), py::arg("val"));
	cls_ShapeProcess_ShapeContext.def("ContinuityVal", (GeomAbs_Shape (ShapeProcess_ShapeContext::*)(const Standard_CString, const GeomAbs_Shape) const ) &ShapeProcess_ShapeContext::ContinuityVal, "Get value of parameter as being of the type GeomAbs_Shape If parameter is not defined or does not have expected type, returns default value as specified", py::arg("param"), py::arg("def"));
	cls_ShapeProcess_ShapeContext.def("PrintStatistics", (void (ShapeProcess_ShapeContext::*)() const ) &ShapeProcess_ShapeContext::PrintStatistics, "Prints statistics on Shape Processing onto the current Messenger.");
	cls_ShapeProcess_ShapeContext.def("SetNonManifold", (void (ShapeProcess_ShapeContext::*)(Standard_Boolean)) &ShapeProcess_ShapeContext::SetNonManifold, "Set NonManifold flag", py::arg("theNonManifold"));
	cls_ShapeProcess_ShapeContext.def("IsNonManifold", (Standard_Boolean (ShapeProcess_ShapeContext::*)()) &ShapeProcess_ShapeContext::IsNonManifold, "Get NonManifold flag");
	cls_ShapeProcess_ShapeContext.def_static("get_type_name_", (const char * (*)()) &ShapeProcess_ShapeContext::get_type_name, "None");
	cls_ShapeProcess_ShapeContext.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeProcess_ShapeContext::get_type_descriptor, "None");
	cls_ShapeProcess_ShapeContext.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeProcess_ShapeContext::*)() const ) &ShapeProcess_ShapeContext::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeProcess_UOperator.hxx
	py::class_<ShapeProcess_UOperator, opencascade::handle<ShapeProcess_UOperator>, ShapeProcess_Operator> cls_ShapeProcess_UOperator(mod, "ShapeProcess_UOperator", "Defines operator as container for static function OperFunc. This allows user to create new operators without creation of new classes");
	cls_ShapeProcess_UOperator.def(py::init<const ShapeProcess_OperFunc>(), py::arg("func"));
	cls_ShapeProcess_UOperator.def("Perform", (Standard_Boolean (ShapeProcess_UOperator::*)(const opencascade::handle<ShapeProcess_Context> &)) &ShapeProcess_UOperator::Perform, "Performs operation and records changes in the context", py::arg("context"));
	cls_ShapeProcess_UOperator.def_static("get_type_name_", (const char * (*)()) &ShapeProcess_UOperator::get_type_name, "None");
	cls_ShapeProcess_UOperator.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeProcess_UOperator::get_type_descriptor, "None");
	cls_ShapeProcess_UOperator.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeProcess_UOperator::*)() const ) &ShapeProcess_UOperator::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeProcess_OperLibrary.hxx
	py::class_<ShapeProcess_OperLibrary, std::unique_ptr<ShapeProcess_OperLibrary, Deleter<ShapeProcess_OperLibrary>>> cls_ShapeProcess_OperLibrary(mod, "ShapeProcess_OperLibrary", "Provides a set of following operators");
	cls_ShapeProcess_OperLibrary.def(py::init<>());
	cls_ShapeProcess_OperLibrary.def_static("Init_", (void (*)()) &ShapeProcess_OperLibrary::Init, "Registers all the operators");
	cls_ShapeProcess_OperLibrary.def_static("ApplyModifier_", [](const TopoDS_Shape & a0, const opencascade::handle<ShapeProcess_ShapeContext> & a1, const opencascade::handle<BRepTools_Modification> & a2, TopTools_DataMapOfShapeShape & a3) -> TopoDS_Shape { return ShapeProcess_OperLibrary::ApplyModifier(a0, a1, a2, a3); }, py::arg("S"), py::arg("context"), py::arg("M"), py::arg("map"));
	cls_ShapeProcess_OperLibrary.def_static("ApplyModifier_", [](const TopoDS_Shape & a0, const opencascade::handle<ShapeProcess_ShapeContext> & a1, const opencascade::handle<BRepTools_Modification> & a2, TopTools_DataMapOfShapeShape & a3, const opencascade::handle<ShapeExtend_MsgRegistrator> & a4) -> TopoDS_Shape { return ShapeProcess_OperLibrary::ApplyModifier(a0, a1, a2, a3, a4); }, py::arg("S"), py::arg("context"), py::arg("M"), py::arg("map"), py::arg("msg"));
	cls_ShapeProcess_OperLibrary.def_static("ApplyModifier_", (TopoDS_Shape (*)(const TopoDS_Shape &, const opencascade::handle<ShapeProcess_ShapeContext> &, const opencascade::handle<BRepTools_Modification> &, TopTools_DataMapOfShapeShape &, const opencascade::handle<ShapeExtend_MsgRegistrator> &, Standard_Boolean)) &ShapeProcess_OperLibrary::ApplyModifier, "Applies BRepTools_Modification to a shape, taking into account sharing of components of compounds. if theMutableInput vat is set to true then imput shape S can be modified during the modification process.", py::arg("S"), py::arg("context"), py::arg("M"), py::arg("map"), py::arg("msg"), py::arg("theMutableInput"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeProcess.hxx
	py::class_<ShapeProcess, std::unique_ptr<ShapeProcess, Deleter<ShapeProcess>>> cls_ShapeProcess(mod, "ShapeProcess", "Shape Processing module allows to define and apply general Shape Processing as a customizable sequence of Shape Healing operators. The customization is implemented via user-editable resource file which defines sequence of operators to be executed and their parameters.");
	cls_ShapeProcess.def(py::init<>());
	cls_ShapeProcess.def_static("RegisterOperator_", (Standard_Boolean (*)(const Standard_CString, const opencascade::handle<ShapeProcess_Operator> &)) &ShapeProcess::RegisterOperator, "Registers operator to make it visible for Performer", py::arg("name"), py::arg("op"));
	cls_ShapeProcess.def_static("FindOperator_", (Standard_Boolean (*)(const Standard_CString, opencascade::handle<ShapeProcess_Operator> &)) &ShapeProcess::FindOperator, "Finds operator by its name", py::arg("name"), py::arg("op"));
	cls_ShapeProcess.def_static("Perform_", (Standard_Boolean (*)(const opencascade::handle<ShapeProcess_Context> &, const Standard_CString)) &ShapeProcess::Perform, "Performs a specified sequence of operators on Context Resource file and other data should be already loaded to Context (including description of sequence seq)", py::arg("context"), py::arg("seq"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ShapeProcess_OperFunc.hxx

}
