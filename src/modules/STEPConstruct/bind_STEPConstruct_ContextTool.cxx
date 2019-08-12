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
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <StepData_StepModel.hxx>
#include <StepBasic_ApplicationProtocolDefinition.hxx>
#include <Standard_TypeDef.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepGeom_Axis2Placement3d.hxx>
#include <STEPConstruct_AP203Context.hxx>
#include <TColStd_HSequenceOfTransient.hxx>
#include <STEPConstruct_Part.hxx>
#include <STEPConstruct_Assembly.hxx>
#include <TColStd_SequenceOfInteger.hxx>
#include <STEPConstruct_ContextTool.hxx>

void bind_STEPConstruct_ContextTool(py::module &mod){

py::class_<STEPConstruct_ContextTool, std::unique_ptr<STEPConstruct_ContextTool, Deleter<STEPConstruct_ContextTool>>> cls_STEPConstruct_ContextTool(mod, "STEPConstruct_ContextTool", "Maintains global context tool for writing. Gives access to Product Definition Context (one per Model) Maintains ApplicationProtocolDefinition entity (common for all products) Also maintains context specific for AP203 and provides set of methods to work with various STEP constructs as required by Actor");

// Constructors
cls_STEPConstruct_ContextTool.def(py::init<>());
cls_STEPConstruct_ContextTool.def(py::init<const opencascade::handle<StepData_StepModel> &>(), py::arg("aStepModel"));

// Fields

// Methods
// cls_STEPConstruct_ContextTool.def_static("operator new_", (void * (*)(size_t)) &STEPConstruct_ContextTool::operator new, "None", py::arg("theSize"));
// cls_STEPConstruct_ContextTool.def_static("operator delete_", (void (*)(void *)) &STEPConstruct_ContextTool::operator delete, "None", py::arg("theAddress"));
// cls_STEPConstruct_ContextTool.def_static("operator new[]_", (void * (*)(size_t)) &STEPConstruct_ContextTool::operator new[], "None", py::arg("theSize"));
// cls_STEPConstruct_ContextTool.def_static("operator delete[]_", (void (*)(void *)) &STEPConstruct_ContextTool::operator delete[], "None", py::arg("theAddress"));
// cls_STEPConstruct_ContextTool.def_static("operator new_", (void * (*)(size_t, void *)) &STEPConstruct_ContextTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_STEPConstruct_ContextTool.def_static("operator delete_", (void (*)(void *, void *)) &STEPConstruct_ContextTool::operator delete, "None", py::arg(""), py::arg(""));
cls_STEPConstruct_ContextTool.def("SetModel", (void (STEPConstruct_ContextTool::*)(const opencascade::handle<StepData_StepModel> &)) &STEPConstruct_ContextTool::SetModel, "Initialize ApplicationProtocolDefinition by the first entity of that type found in the model", py::arg("aStepModel"));
cls_STEPConstruct_ContextTool.def("GetAPD", (opencascade::handle<StepBasic_ApplicationProtocolDefinition> (STEPConstruct_ContextTool::*)()) &STEPConstruct_ContextTool::GetAPD, "None");
cls_STEPConstruct_ContextTool.def("AddAPD", [](STEPConstruct_ContextTool &self) -> void { return self.AddAPD(); });
cls_STEPConstruct_ContextTool.def("AddAPD", (void (STEPConstruct_ContextTool::*)(const Standard_Boolean)) &STEPConstruct_ContextTool::AddAPD, "None", py::arg("enforce"));
cls_STEPConstruct_ContextTool.def("IsAP203", (Standard_Boolean (STEPConstruct_ContextTool::*)() const) &STEPConstruct_ContextTool::IsAP203, "Returns True if APD.schema_name is config_control_design");
cls_STEPConstruct_ContextTool.def("IsAP214", (Standard_Boolean (STEPConstruct_ContextTool::*)() const) &STEPConstruct_ContextTool::IsAP214, "Returns True if APD.schema_name is automotive_design");
cls_STEPConstruct_ContextTool.def("IsAP242", (Standard_Boolean (STEPConstruct_ContextTool::*)() const) &STEPConstruct_ContextTool::IsAP242, "Returns True if APD.schema_name is ap242_managed_model_based_3d_engineering");
cls_STEPConstruct_ContextTool.def("GetACstatus", (opencascade::handle<TCollection_HAsciiString> (STEPConstruct_ContextTool::*)()) &STEPConstruct_ContextTool::GetACstatus, "None");
cls_STEPConstruct_ContextTool.def("GetACschemaName", (opencascade::handle<TCollection_HAsciiString> (STEPConstruct_ContextTool::*)()) &STEPConstruct_ContextTool::GetACschemaName, "None");
cls_STEPConstruct_ContextTool.def("GetACyear", (Standard_Integer (STEPConstruct_ContextTool::*)()) &STEPConstruct_ContextTool::GetACyear, "None");
cls_STEPConstruct_ContextTool.def("GetACname", (opencascade::handle<TCollection_HAsciiString> (STEPConstruct_ContextTool::*)()) &STEPConstruct_ContextTool::GetACname, "None");
cls_STEPConstruct_ContextTool.def("SetACstatus", (void (STEPConstruct_ContextTool::*)(const opencascade::handle<TCollection_HAsciiString> &)) &STEPConstruct_ContextTool::SetACstatus, "None", py::arg("status"));
cls_STEPConstruct_ContextTool.def("SetACschemaName", (void (STEPConstruct_ContextTool::*)(const opencascade::handle<TCollection_HAsciiString> &)) &STEPConstruct_ContextTool::SetACschemaName, "None", py::arg("schemaName"));
cls_STEPConstruct_ContextTool.def("SetACyear", (void (STEPConstruct_ContextTool::*)(const Standard_Integer)) &STEPConstruct_ContextTool::SetACyear, "None", py::arg("year"));
cls_STEPConstruct_ContextTool.def("SetACname", (void (STEPConstruct_ContextTool::*)(const opencascade::handle<TCollection_HAsciiString> &)) &STEPConstruct_ContextTool::SetACname, "None", py::arg("name"));
cls_STEPConstruct_ContextTool.def("GetDefaultAxis", (opencascade::handle<StepGeom_Axis2Placement3d> (STEPConstruct_ContextTool::*)()) &STEPConstruct_ContextTool::GetDefaultAxis, "Returns a default axis placement");
cls_STEPConstruct_ContextTool.def("AP203Context", (STEPConstruct_AP203Context & (STEPConstruct_ContextTool::*)()) &STEPConstruct_ContextTool::AP203Context, "Returns tool which maintains context specific for AP203");
cls_STEPConstruct_ContextTool.def("Level", (Standard_Integer (STEPConstruct_ContextTool::*)() const) &STEPConstruct_ContextTool::Level, "Returns current assembly level");
cls_STEPConstruct_ContextTool.def("NextLevel", (void (STEPConstruct_ContextTool::*)()) &STEPConstruct_ContextTool::NextLevel, "None");
cls_STEPConstruct_ContextTool.def("PrevLevel", (void (STEPConstruct_ContextTool::*)()) &STEPConstruct_ContextTool::PrevLevel, "None");
cls_STEPConstruct_ContextTool.def("SetLevel", (void (STEPConstruct_ContextTool::*)(const Standard_Integer)) &STEPConstruct_ContextTool::SetLevel, "Changes current assembly level", py::arg("lev"));
cls_STEPConstruct_ContextTool.def("Index", (Standard_Integer (STEPConstruct_ContextTool::*)() const) &STEPConstruct_ContextTool::Index, "Returns current index of assembly component on current level");
cls_STEPConstruct_ContextTool.def("NextIndex", (void (STEPConstruct_ContextTool::*)()) &STEPConstruct_ContextTool::NextIndex, "None");
cls_STEPConstruct_ContextTool.def("PrevIndex", (void (STEPConstruct_ContextTool::*)()) &STEPConstruct_ContextTool::PrevIndex, "None");
cls_STEPConstruct_ContextTool.def("SetIndex", (void (STEPConstruct_ContextTool::*)(const Standard_Integer)) &STEPConstruct_ContextTool::SetIndex, "Changes current index of assembly component on current level", py::arg("ind"));
cls_STEPConstruct_ContextTool.def("GetProductName", (opencascade::handle<TCollection_HAsciiString> (STEPConstruct_ContextTool::*)() const) &STEPConstruct_ContextTool::GetProductName, "Generates a product name basing on write.step.product.name parameter and current position in the assembly structure");
cls_STEPConstruct_ContextTool.def("GetRootsForPart", (opencascade::handle<TColStd_HSequenceOfTransient> (STEPConstruct_ContextTool::*)(const STEPConstruct_Part &)) &STEPConstruct_ContextTool::GetRootsForPart, "Produces and returns a full list of root entities required for part identified by SDRTool (including SDR itself)", py::arg("SDRTool"));
cls_STEPConstruct_ContextTool.def("GetRootsForAssemblyLink", (opencascade::handle<TColStd_HSequenceOfTransient> (STEPConstruct_ContextTool::*)(const STEPConstruct_Assembly &)) &STEPConstruct_ContextTool::GetRootsForAssemblyLink, "Produces and returns a full list of root entities required for assembly link identified by assembly (including NAUO and CDSR)", py::arg("assembly"));

// Enums

}