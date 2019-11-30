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
#include <TFunction_ExecutionStatus.hxx>
#include <TDF_Attribute.hxx>
#include <Standard_Handle.hxx>
#include <TFunction_Function.hxx>
#include <TDF_Label.hxx>
#include <Standard_GUID.hxx>
#include <Standard_TypeDef.hxx>
#include <TDF_RelocationTable.hxx>
#include <TDF_DataSet.hxx>
#include <Standard_OStream.hxx>
#include <Standard_Std.hxx>
#include <Standard_Type.hxx>
#include <Standard_Transient.hxx>
#include <TFunction_Logbook.hxx>
#include <TDF_LabelList.hxx>
#include <TFunction_Driver.hxx>
#include <NCollection_DataMap.hxx>
#include <TFunction_DataMapOfGUIDDriver.hxx>
#include <NCollection_Array1.hxx>
#include <TFunction_Array1OfDataMapOfGUIDDriver.hxx>
#include <TDF_LabelMapHasher.hxx>
#include <TFunction_DataMapOfLabelListOfLabel.hxx>
#include <NCollection_DoubleMap.hxx>
#include <TColStd_MapIntegerHasher.hxx>
#include <TFunction_DoubleMapOfIntegerLabel.hxx>
#include <Standard.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <TFunction_HArray1OfDataMapOfGUIDDriver.hxx>
#include <TFunction_DriverTable.hxx>
#include <TFunction_GraphNode.hxx>
#include <TColStd_MapOfInteger.hxx>
#include <TFunction_IFunction.hxx>
#include <TDF_LabelMap.hxx>
#include <TFunction_Scope.hxx>
#include <TFunction_Iterator.hxx>
#include <bind_NCollection_DataMap.hxx>
#include <bind_NCollection_Array1.hxx>
#include <bind_NCollection_DoubleMap.hxx>

PYBIND11_MODULE(TFunction, mod) {

py::module::import("OCCT.TDF");
py::module::import("OCCT.Standard");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TColStd");

// ENUM: TFUNCTION_EXECUTIONSTATUS
py::enum_<TFunction_ExecutionStatus>(mod, "TFunction_ExecutionStatus", "None")
	.value("TFunction_ES_WrongDefinition", TFunction_ExecutionStatus::TFunction_ES_WrongDefinition)
	.value("TFunction_ES_NotExecuted", TFunction_ExecutionStatus::TFunction_ES_NotExecuted)
	.value("TFunction_ES_Executing", TFunction_ExecutionStatus::TFunction_ES_Executing)
	.value("TFunction_ES_Succeeded", TFunction_ExecutionStatus::TFunction_ES_Succeeded)
	.value("TFunction_ES_Failed", TFunction_ExecutionStatus::TFunction_ES_Failed)
	.export_values();


// CLASS: TFUNCTION_FUNCTION
py::class_<TFunction_Function, opencascade::handle<TFunction_Function>, TDF_Attribute> cls_TFunction_Function(mod, "TFunction_Function", "Provides the following two services - a link to an evaluation driver - the means of providing a link between a function and an evaluation driver.");

// Constructors
cls_TFunction_Function.def(py::init<>());

// Methods
cls_TFunction_Function.def_static("Set_", (opencascade::handle<TFunction_Function> (*)(const TDF_Label &)) &TFunction_Function::Set, "Static methods: ============== Finds or Creates a function attribute on the label <L>. Returns the function attribute.", py::arg("L"));
cls_TFunction_Function.def_static("Set_", (opencascade::handle<TFunction_Function> (*)(const TDF_Label &, const Standard_GUID &)) &TFunction_Function::Set, "Finds or Creates a function attribute on the label <L>. Sets a driver ID to the function. Returns the function attribute.", py::arg("L"), py::arg("DriverID"));
cls_TFunction_Function.def_static("GetID_", (const Standard_GUID & (*)()) &TFunction_Function::GetID, "Returns the GUID for functions. Returns a function found on the label. Instance methods: ================");
cls_TFunction_Function.def("GetDriverGUID", (const Standard_GUID & (TFunction_Function::*)() const) &TFunction_Function::GetDriverGUID, "Returns the GUID for this function's driver.");
cls_TFunction_Function.def("SetDriverGUID", (void (TFunction_Function::*)(const Standard_GUID &)) &TFunction_Function::SetDriverGUID, "Sets the driver for this function as that indentified by the GUID guid.", py::arg("guid"));
cls_TFunction_Function.def("Failed", (Standard_Boolean (TFunction_Function::*)() const) &TFunction_Function::Failed, "Returns true if the execution failed");
cls_TFunction_Function.def("SetFailure", [](TFunction_Function &self) -> void { return self.SetFailure(); });
cls_TFunction_Function.def("SetFailure", (void (TFunction_Function::*)(const Standard_Integer)) &TFunction_Function::SetFailure, "Sets the failed index.", py::arg("mode"));
cls_TFunction_Function.def("GetFailure", (Standard_Integer (TFunction_Function::*)() const) &TFunction_Function::GetFailure, "Returns an index of failure if the execution of this function failed. If this integer value is 0, no failure has occurred. Implementation of Attribute methods: ===================================");
cls_TFunction_Function.def("ID", (const Standard_GUID & (TFunction_Function::*)() const) &TFunction_Function::ID, "None");
cls_TFunction_Function.def("Restore", (void (TFunction_Function::*)(const opencascade::handle<TDF_Attribute> &)) &TFunction_Function::Restore, "None", py::arg("with"));
cls_TFunction_Function.def("Paste", (void (TFunction_Function::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TFunction_Function::Paste, "None", py::arg("into"), py::arg("RT"));
cls_TFunction_Function.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TFunction_Function::*)() const) &TFunction_Function::NewEmpty, "None");
cls_TFunction_Function.def("References", (void (TFunction_Function::*)(const opencascade::handle<TDF_DataSet> &) const) &TFunction_Function::References, "None", py::arg("aDataSet"));
cls_TFunction_Function.def("Dump", (Standard_OStream & (TFunction_Function::*)(Standard_OStream &) const) &TFunction_Function::Dump, "None", py::arg("anOS"));
cls_TFunction_Function.def_static("get_type_name_", (const char * (*)()) &TFunction_Function::get_type_name, "None");
cls_TFunction_Function.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TFunction_Function::get_type_descriptor, "None");
cls_TFunction_Function.def("DynamicType", (const opencascade::handle<Standard_Type> & (TFunction_Function::*)() const) &TFunction_Function::DynamicType, "None");

// CLASS: TFUNCTION_DRIVER
py::class_<TFunction_Driver, opencascade::handle<TFunction_Driver>, Standard_Transient> cls_TFunction_Driver(mod, "TFunction_Driver", "This driver class provide services around function execution. One instance of this class is built for the whole session. The driver is bound to the DriverGUID in the DriverTable class. It allows you to create classes which inherit from this abstract class. These subclasses identify the various algorithms which can be applied to the data contained in the attributes of sub-labels of a model. A single instance of this class and each of its subclasses is built for the whole session.");

// Methods
cls_TFunction_Driver.def("Init", (void (TFunction_Driver::*)(const TDF_Label &)) &TFunction_Driver::Init, "Initializes the label L for this function prior to its execution.", py::arg("L"));
cls_TFunction_Driver.def("Label", (TDF_Label (TFunction_Driver::*)() const) &TFunction_Driver::Label, "Returns the label of the driver for this function.");
cls_TFunction_Driver.def("Validate", (void (TFunction_Driver::*)(opencascade::handle<TFunction_Logbook> &) const) &TFunction_Driver::Validate, "Validates labels of a function in <log>. This function is the one initialized in this function driver. Warning In regeneration mode, the solver must call this method even if the function is not executed. execution of function =====================", py::arg("log"));
cls_TFunction_Driver.def("MustExecute", (Standard_Boolean (TFunction_Driver::*)(const opencascade::handle<TFunction_Logbook> &) const) &TFunction_Driver::MustExecute, "Analyzes the labels in the logbook log. Returns true if attributes have been modified. If the function label itself has been modified, the function must be executed.", py::arg("log"));
cls_TFunction_Driver.def("Execute", (Standard_Integer (TFunction_Driver::*)(opencascade::handle<TFunction_Logbook> &) const) &TFunction_Driver::Execute, "Executes the function in this function driver and puts the impacted labels in the logbook log. arguments & results of functions ================================", py::arg("log"));
cls_TFunction_Driver.def("Arguments", (void (TFunction_Driver::*)(TDF_LabelList &) const) &TFunction_Driver::Arguments, "The method fills-in the list by labels, where the arguments of the function are located.", py::arg("args"));
cls_TFunction_Driver.def("Results", (void (TFunction_Driver::*)(TDF_LabelList &) const) &TFunction_Driver::Results, "The method fills-in the list by labels, where the results of the function are located.", py::arg("res"));
cls_TFunction_Driver.def_static("get_type_name_", (const char * (*)()) &TFunction_Driver::get_type_name, "None");
cls_TFunction_Driver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TFunction_Driver::get_type_descriptor, "None");
cls_TFunction_Driver.def("DynamicType", (const opencascade::handle<Standard_Type> & (TFunction_Driver::*)() const) &TFunction_Driver::DynamicType, "None");

// TYPEDEF: TFUNCTION_DATAMAPOFGUIDDRIVER
bind_NCollection_DataMap<Standard_GUID, opencascade::handle<TFunction_Driver>, Standard_GUID>(mod, "TFunction_DataMapOfGUIDDriver", py::module_local(false));

// TYPEDEF: TFUNCTION_DATAMAPITERATOROFDATAMAPOFGUIDDRIVER

// TYPEDEF: TFUNCTION_ARRAY1OFDATAMAPOFGUIDDRIVER
bind_NCollection_Array1<NCollection_DataMap<Standard_GUID, opencascade::handle<TFunction_Driver>, Standard_GUID> >(mod, "TFunction_Array1OfDataMapOfGUIDDriver", py::module_local(false));

// TYPEDEF: TFUNCTION_DATAMAPOFLABELLISTOFLABEL
bind_NCollection_DataMap<TDF_Label, NCollection_List<TDF_Label>, TDF_LabelMapHasher>(mod, "TFunction_DataMapOfLabelListOfLabel", py::module_local(false));

// TYPEDEF: TFUNCTION_DATAMAPITERATOROFDATAMAPOFLABELLISTOFLABEL

// TYPEDEF: TFUNCTION_DOUBLEMAPOFINTEGERLABEL
bind_NCollection_DoubleMap<int, TDF_Label, NCollection_DefaultHasher<int>, TDF_LabelMapHasher>(mod, "TFunction_DoubleMapOfIntegerLabel", py::module_local(false));

// TYPEDEF: TFUNCTION_DOUBLEMAPITERATOROFDOUBLEMAPOFINTEGERLABEL

// CLASS: TFUNCTION_HARRAY1OFDATAMAPOFGUIDDRIVER
py::class_<TFunction_HArray1OfDataMapOfGUIDDriver, opencascade::handle<TFunction_HArray1OfDataMapOfGUIDDriver>, Standard_Transient> cls_TFunction_HArray1OfDataMapOfGUIDDriver(mod, "TFunction_HArray1OfDataMapOfGUIDDriver", "None", py::multiple_inheritance());

// Constructors
cls_TFunction_HArray1OfDataMapOfGUIDDriver.def(py::init<>());
cls_TFunction_HArray1OfDataMapOfGUIDDriver.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_TFunction_HArray1OfDataMapOfGUIDDriver.def(py::init<const Standard_Integer, const Standard_Integer, const TFunction_Array1OfDataMapOfGUIDDriver::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_TFunction_HArray1OfDataMapOfGUIDDriver.def(py::init<const TFunction_Array1OfDataMapOfGUIDDriver &>(), py::arg("theOther"));

// Methods
// cls_TFunction_HArray1OfDataMapOfGUIDDriver.def_static("operator new_", (void * (*)(size_t)) &TFunction_HArray1OfDataMapOfGUIDDriver::operator new, "None", py::arg("theSize"));
// cls_TFunction_HArray1OfDataMapOfGUIDDriver.def_static("operator delete_", (void (*)(void *)) &TFunction_HArray1OfDataMapOfGUIDDriver::operator delete, "None", py::arg("theAddress"));
// cls_TFunction_HArray1OfDataMapOfGUIDDriver.def_static("operator new[]_", (void * (*)(size_t)) &TFunction_HArray1OfDataMapOfGUIDDriver::operator new[], "None", py::arg("theSize"));
// cls_TFunction_HArray1OfDataMapOfGUIDDriver.def_static("operator delete[]_", (void (*)(void *)) &TFunction_HArray1OfDataMapOfGUIDDriver::operator delete[], "None", py::arg("theAddress"));
// cls_TFunction_HArray1OfDataMapOfGUIDDriver.def_static("operator new_", (void * (*)(size_t, void *)) &TFunction_HArray1OfDataMapOfGUIDDriver::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TFunction_HArray1OfDataMapOfGUIDDriver.def_static("operator delete_", (void (*)(void *, void *)) &TFunction_HArray1OfDataMapOfGUIDDriver::operator delete, "None", py::arg(""), py::arg(""));
// cls_TFunction_HArray1OfDataMapOfGUIDDriver.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &TFunction_HArray1OfDataMapOfGUIDDriver::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_TFunction_HArray1OfDataMapOfGUIDDriver.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &TFunction_HArray1OfDataMapOfGUIDDriver::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_TFunction_HArray1OfDataMapOfGUIDDriver.def("Array1", (const TFunction_Array1OfDataMapOfGUIDDriver & (TFunction_HArray1OfDataMapOfGUIDDriver::*)() const) &TFunction_HArray1OfDataMapOfGUIDDriver::Array1, "None");
cls_TFunction_HArray1OfDataMapOfGUIDDriver.def("ChangeArray1", (TFunction_Array1OfDataMapOfGUIDDriver & (TFunction_HArray1OfDataMapOfGUIDDriver::*)()) &TFunction_HArray1OfDataMapOfGUIDDriver::ChangeArray1, "None");
cls_TFunction_HArray1OfDataMapOfGUIDDriver.def_static("get_type_name_", (const char * (*)()) &TFunction_HArray1OfDataMapOfGUIDDriver::get_type_name, "None");
cls_TFunction_HArray1OfDataMapOfGUIDDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TFunction_HArray1OfDataMapOfGUIDDriver::get_type_descriptor, "None");
cls_TFunction_HArray1OfDataMapOfGUIDDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (TFunction_HArray1OfDataMapOfGUIDDriver::*)() const) &TFunction_HArray1OfDataMapOfGUIDDriver::DynamicType, "None");

// CLASS: TFUNCTION_DRIVERTABLE
py::class_<TFunction_DriverTable, opencascade::handle<TFunction_DriverTable>, Standard_Transient> cls_TFunction_DriverTable(mod, "TFunction_DriverTable", "A container for instances of drivers. You create a new instance of TFunction_Driver and use the method AddDriver to load it into the driver table.");

// Constructors
cls_TFunction_DriverTable.def(py::init<>());

// Methods
cls_TFunction_DriverTable.def_static("Get_", (opencascade::handle<TFunction_DriverTable> (*)()) &TFunction_DriverTable::Get, "Returns the driver table. If a driver does not exist, creates it.");
cls_TFunction_DriverTable.def("AddDriver", [](TFunction_DriverTable &self, const Standard_GUID & a0, const opencascade::handle<TFunction_Driver> & a1) -> Standard_Boolean { return self.AddDriver(a0, a1); });
cls_TFunction_DriverTable.def("AddDriver", (Standard_Boolean (TFunction_DriverTable::*)(const Standard_GUID &, const opencascade::handle<TFunction_Driver> &, const Standard_Integer)) &TFunction_DriverTable::AddDriver, "Returns true if the driver has been added successfully to the driver table.", py::arg("guid"), py::arg("driver"), py::arg("thread"));
cls_TFunction_DriverTable.def("HasDriver", [](TFunction_DriverTable &self, const Standard_GUID & a0) -> Standard_Boolean { return self.HasDriver(a0); });
cls_TFunction_DriverTable.def("HasDriver", (Standard_Boolean (TFunction_DriverTable::*)(const Standard_GUID &, const Standard_Integer) const) &TFunction_DriverTable::HasDriver, "Returns true if the driver exists in the driver table.", py::arg("guid"), py::arg("thread"));
cls_TFunction_DriverTable.def("FindDriver", [](TFunction_DriverTable &self, const Standard_GUID & a0, opencascade::handle<TFunction_Driver> & a1) -> Standard_Boolean { return self.FindDriver(a0, a1); });
cls_TFunction_DriverTable.def("FindDriver", (Standard_Boolean (TFunction_DriverTable::*)(const Standard_GUID &, opencascade::handle<TFunction_Driver> &, const Standard_Integer) const) &TFunction_DriverTable::FindDriver, "Returns true if the driver was found.", py::arg("guid"), py::arg("driver"), py::arg("thread"));
cls_TFunction_DriverTable.def("Dump", (Standard_OStream & (TFunction_DriverTable::*)(Standard_OStream &) const) &TFunction_DriverTable::Dump, "None", py::arg("anOS"));
cls_TFunction_DriverTable.def("bits_left", (Standard_OStream & (TFunction_DriverTable::*)(Standard_OStream &) const) &TFunction_DriverTable::operator<<, py::is_operator(), "None", py::arg("anOS"));
cls_TFunction_DriverTable.def("RemoveDriver", [](TFunction_DriverTable &self, const Standard_GUID & a0) -> Standard_Boolean { return self.RemoveDriver(a0); });
cls_TFunction_DriverTable.def("RemoveDriver", (Standard_Boolean (TFunction_DriverTable::*)(const Standard_GUID &, const Standard_Integer)) &TFunction_DriverTable::RemoveDriver, "Removes a driver with the given GUID. Returns true if the driver has been removed successfully.", py::arg("guid"), py::arg("thread"));
cls_TFunction_DriverTable.def("Clear", (void (TFunction_DriverTable::*)()) &TFunction_DriverTable::Clear, "Removes all drivers. Returns true if the driver has been removed successfully.");
cls_TFunction_DriverTable.def_static("get_type_name_", (const char * (*)()) &TFunction_DriverTable::get_type_name, "None");
cls_TFunction_DriverTable.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TFunction_DriverTable::get_type_descriptor, "None");
cls_TFunction_DriverTable.def("DynamicType", (const opencascade::handle<Standard_Type> & (TFunction_DriverTable::*)() const) &TFunction_DriverTable::DynamicType, "None");

// CLASS: TFUNCTION_GRAPHNODE
py::class_<TFunction_GraphNode, opencascade::handle<TFunction_GraphNode>, TDF_Attribute> cls_TFunction_GraphNode(mod, "TFunction_GraphNode", "Provides links between functions.");

// Constructors
cls_TFunction_GraphNode.def(py::init<>());

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

// CLASS: TFUNCTION_IFUNCTION
py::class_<TFunction_IFunction> cls_TFunction_IFunction(mod, "TFunction_IFunction", "Interface class for usage of Function Mechanism");

// Constructors
cls_TFunction_IFunction.def(py::init<>());
cls_TFunction_IFunction.def(py::init<const TDF_Label &>(), py::arg("L"));

// Methods
// cls_TFunction_IFunction.def_static("operator new_", (void * (*)(size_t)) &TFunction_IFunction::operator new, "None", py::arg("theSize"));
// cls_TFunction_IFunction.def_static("operator delete_", (void (*)(void *)) &TFunction_IFunction::operator delete, "None", py::arg("theAddress"));
// cls_TFunction_IFunction.def_static("operator new[]_", (void * (*)(size_t)) &TFunction_IFunction::operator new[], "None", py::arg("theSize"));
// cls_TFunction_IFunction.def_static("operator delete[]_", (void (*)(void *)) &TFunction_IFunction::operator delete[], "None", py::arg("theAddress"));
// cls_TFunction_IFunction.def_static("operator new_", (void * (*)(size_t, void *)) &TFunction_IFunction::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TFunction_IFunction.def_static("operator delete_", (void (*)(void *, void *)) &TFunction_IFunction::operator delete, "None", py::arg(""), py::arg(""));
cls_TFunction_IFunction.def_static("NewFunction_", (Standard_Boolean (*)(const TDF_Label &, const Standard_GUID &)) &TFunction_IFunction::NewFunction, "Sets a new function attached to a label <L> with <ID>. It creates a new TFunction_Function attribute initialized by the <ID>, a new TFunction_GraphNode with an empty list of dependencies and the status equal to TFunction_ES_WrongDefinition. It registers the function in the scope of functions for this document.", py::arg("L"), py::arg("ID"));
cls_TFunction_IFunction.def_static("DeleteFunction_", (Standard_Boolean (*)(const TDF_Label &)) &TFunction_IFunction::DeleteFunction, "Deletes a function attached to a label <L>. It deletes a TFunction_Function attribute and a TFunction_GraphNode. It deletes the functions from the scope of function of this document.", py::arg("L"));
cls_TFunction_IFunction.def_static("UpdateDependencies_", (Standard_Boolean (*)(const TDF_Label &)) &TFunction_IFunction::UpdateDependencies, "Updates dependencies for all functions of the scope. It returns false in case of an error. An empty constructor.", py::arg("Access"));
cls_TFunction_IFunction.def("Init", (void (TFunction_IFunction::*)(const TDF_Label &)) &TFunction_IFunction::Init, "Initializes the interface by the label of function.", py::arg("L"));
cls_TFunction_IFunction.def("Label", (const TDF_Label & (TFunction_IFunction::*)() const) &TFunction_IFunction::Label, "Returns a label of the function.");
cls_TFunction_IFunction.def("UpdateDependencies", (Standard_Boolean (TFunction_IFunction::*)() const) &TFunction_IFunction::UpdateDependencies, "Updates the dependencies of this function only.");
cls_TFunction_IFunction.def("Arguments", (void (TFunction_IFunction::*)(TDF_LabelList &) const) &TFunction_IFunction::Arguments, "The method fills-in the list by labels, where the arguments of the function are located.", py::arg("args"));
cls_TFunction_IFunction.def("Results", (void (TFunction_IFunction::*)(TDF_LabelList &) const) &TFunction_IFunction::Results, "The method fills-in the list by labels, where the results of the function are located.", py::arg("res"));
cls_TFunction_IFunction.def("GetPrevious", (void (TFunction_IFunction::*)(TDF_LabelList &) const) &TFunction_IFunction::GetPrevious, "Returns a list of previous functions.", py::arg("prev"));
cls_TFunction_IFunction.def("GetNext", (void (TFunction_IFunction::*)(TDF_LabelList &) const) &TFunction_IFunction::GetNext, "Returns a list of next functions.", py::arg("prev"));
cls_TFunction_IFunction.def("GetStatus", (TFunction_ExecutionStatus (TFunction_IFunction::*)() const) &TFunction_IFunction::GetStatus, "Returns the execution status of the function.");
cls_TFunction_IFunction.def("SetStatus", (void (TFunction_IFunction::*)(const TFunction_ExecutionStatus) const) &TFunction_IFunction::SetStatus, "Defines an execution status for a function.", py::arg("status"));
cls_TFunction_IFunction.def("GetAllFunctions", (const TFunction_DoubleMapOfIntegerLabel & (TFunction_IFunction::*)() const) &TFunction_IFunction::GetAllFunctions, "Returns the scope of all functions.");
cls_TFunction_IFunction.def("GetLogbook", (opencascade::handle<TFunction_Logbook> (TFunction_IFunction::*)() const) &TFunction_IFunction::GetLogbook, "Returns the Logbook - keeper of modifications.");
cls_TFunction_IFunction.def("GetDriver", [](TFunction_IFunction &self) -> opencascade::handle<TFunction_Driver> { return self.GetDriver(); });
cls_TFunction_IFunction.def("GetDriver", (opencascade::handle<TFunction_Driver> (TFunction_IFunction::*)(const Standard_Integer) const) &TFunction_IFunction::GetDriver, "Returns a driver of the function.", py::arg("thread"));
cls_TFunction_IFunction.def("GetGraphNode", (opencascade::handle<TFunction_GraphNode> (TFunction_IFunction::*)() const) &TFunction_IFunction::GetGraphNode, "Returns a graph node of the function.");

// CLASS: TFUNCTION_ITERATOR
py::class_<TFunction_Iterator> cls_TFunction_Iterator(mod, "TFunction_Iterator", "Iterator of the graph of functions");

// Constructors
cls_TFunction_Iterator.def(py::init<>());
cls_TFunction_Iterator.def(py::init<const TDF_Label &>(), py::arg("Access"));

// Methods
// cls_TFunction_Iterator.def_static("operator new_", (void * (*)(size_t)) &TFunction_Iterator::operator new, "None", py::arg("theSize"));
// cls_TFunction_Iterator.def_static("operator delete_", (void (*)(void *)) &TFunction_Iterator::operator delete, "None", py::arg("theAddress"));
// cls_TFunction_Iterator.def_static("operator new[]_", (void * (*)(size_t)) &TFunction_Iterator::operator new[], "None", py::arg("theSize"));
// cls_TFunction_Iterator.def_static("operator delete[]_", (void (*)(void *)) &TFunction_Iterator::operator delete[], "None", py::arg("theAddress"));
// cls_TFunction_Iterator.def_static("operator new_", (void * (*)(size_t, void *)) &TFunction_Iterator::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TFunction_Iterator.def_static("operator delete_", (void (*)(void *, void *)) &TFunction_Iterator::operator delete, "None", py::arg(""), py::arg(""));
cls_TFunction_Iterator.def("Init", (void (TFunction_Iterator::*)(const TDF_Label &)) &TFunction_Iterator::Init, "Initializes the Iterator.", py::arg("Access"));
cls_TFunction_Iterator.def("SetUsageOfExecutionStatus", (void (TFunction_Iterator::*)(const Standard_Boolean)) &TFunction_Iterator::SetUsageOfExecutionStatus, "Defines the mode of iteration - usage or not of the execution status. If the iterator takes into account the execution status, the method ::Current() returns only 'not executed' functions while their status is not changed. If the iterator ignores the execution status, the method ::Current() returns the functions following their dependencies and ignoring the execution status.", py::arg("usage"));
cls_TFunction_Iterator.def("GetUsageOfExecutionStatus", (Standard_Boolean (TFunction_Iterator::*)() const) &TFunction_Iterator::GetUsageOfExecutionStatus, "Returns usage of execution status by the iterator.");
cls_TFunction_Iterator.def("GetMaxNbThreads", (Standard_Integer (TFunction_Iterator::*)() const) &TFunction_Iterator::GetMaxNbThreads, "Analyses the graph of dependencies and returns maximum number of threads may be used to calculate the model.");
cls_TFunction_Iterator.def("Current", (const TDF_LabelList & (TFunction_Iterator::*)() const) &TFunction_Iterator::Current, "Returns the current list of functions. If the iterator uses the execution status, the returned list contains only the functions with 'not executed' status.");
cls_TFunction_Iterator.def("More", (Standard_Boolean (TFunction_Iterator::*)() const) &TFunction_Iterator::More, "Returns false if the graph of functions is fully iterated.");
cls_TFunction_Iterator.def("Next", (void (TFunction_Iterator::*)()) &TFunction_Iterator::Next, "Switches the iterator to the next list of current functions.");
cls_TFunction_Iterator.def("GetStatus", (TFunction_ExecutionStatus (TFunction_Iterator::*)(const TDF_Label &) const) &TFunction_Iterator::GetStatus, "A help-function aimed to help the user to check the status of retrurned function. It calls TFunction_GraphNode::GetStatus() inside.", py::arg("func"));
cls_TFunction_Iterator.def("SetStatus", (void (TFunction_Iterator::*)(const TDF_Label &, const TFunction_ExecutionStatus) const) &TFunction_Iterator::SetStatus, "A help-function aimed to help the user to change the execution status of a function. It calls TFunction_GraphNode::SetStatus() inside.", py::arg("func"), py::arg("status"));
cls_TFunction_Iterator.def("Dump", (Standard_OStream & (TFunction_Iterator::*)(Standard_OStream &) const) &TFunction_Iterator::Dump, "None", py::arg("OS"));

// CLASS: TFUNCTION_LOGBOOK
py::class_<TFunction_Logbook, opencascade::handle<TFunction_Logbook>, TDF_Attribute> cls_TFunction_Logbook(mod, "TFunction_Logbook", "This class contains information which is written and read during the solving process. Information is divided in three groups.");

// Constructors
cls_TFunction_Logbook.def(py::init<>());

// Methods
cls_TFunction_Logbook.def_static("Set_", (opencascade::handle<TFunction_Logbook> (*)(const TDF_Label &)) &TFunction_Logbook::Set, "Finds or Creates a TFunction_Logbook attribute at the root label accessed by <Access>. Returns the attribute.", py::arg("Access"));
cls_TFunction_Logbook.def_static("GetID_", (const Standard_GUID & (*)()) &TFunction_Logbook::GetID, "Returns the GUID for logbook attribute.");
cls_TFunction_Logbook.def("Clear", (void (TFunction_Logbook::*)()) &TFunction_Logbook::Clear, "Clears this logbook to its default, empty state.");
cls_TFunction_Logbook.def("IsEmpty", (Standard_Boolean (TFunction_Logbook::*)() const) &TFunction_Logbook::IsEmpty, "None");
cls_TFunction_Logbook.def("SetTouched", (void (TFunction_Logbook::*)(const TDF_Label &)) &TFunction_Logbook::SetTouched, "Sets the label L as a touched label in this logbook. In other words, L is understood to have been modified by the end user.", py::arg("L"));
cls_TFunction_Logbook.def("SetImpacted", [](TFunction_Logbook &self, const TDF_Label & a0) -> void { return self.SetImpacted(a0); });
cls_TFunction_Logbook.def("SetImpacted", (void (TFunction_Logbook::*)(const TDF_Label &, const Standard_Boolean)) &TFunction_Logbook::SetImpacted, "Sets the label L as an impacted label in this logbook. This method is called by execution of the function driver.", py::arg("L"), py::arg("WithChildren"));
cls_TFunction_Logbook.def("SetValid", [](TFunction_Logbook &self, const TDF_Label & a0) -> void { return self.SetValid(a0); });
cls_TFunction_Logbook.def("SetValid", (void (TFunction_Logbook::*)(const TDF_Label &, const Standard_Boolean)) &TFunction_Logbook::SetValid, "Sets the label L as a valid label in this logbook.", py::arg("L"), py::arg("WithChildren"));
cls_TFunction_Logbook.def("SetValid", (void (TFunction_Logbook::*)(const TDF_LabelMap &)) &TFunction_Logbook::SetValid, "None", py::arg("Ls"));
cls_TFunction_Logbook.def("IsModified", [](TFunction_Logbook &self, const TDF_Label & a0) -> Standard_Boolean { return self.IsModified(a0); });
cls_TFunction_Logbook.def("IsModified", (Standard_Boolean (TFunction_Logbook::*)(const TDF_Label &, const Standard_Boolean) const) &TFunction_Logbook::IsModified, "Returns True if the label L is touched or impacted. This method is called by <TFunction_FunctionDriver::MustExecute>. If <WithChildren> is set to true, the method checks all the sublabels of <L> too.", py::arg("L"), py::arg("WithChildren"));
cls_TFunction_Logbook.def("GetTouched", (const TDF_LabelMap & (TFunction_Logbook::*)() const) &TFunction_Logbook::GetTouched, "Returns the map of touched labels in this logbook. A touched label is the one modified by the end user.");
cls_TFunction_Logbook.def("GetImpacted", (const TDF_LabelMap & (TFunction_Logbook::*)() const) &TFunction_Logbook::GetImpacted, "Returns the map of impacted labels contained in this logbook.");
cls_TFunction_Logbook.def("GetValid", (const TDF_LabelMap & (TFunction_Logbook::*)() const) &TFunction_Logbook::GetValid, "Returns the map of valid labels in this logbook.");
cls_TFunction_Logbook.def("GetValid", (void (TFunction_Logbook::*)(TDF_LabelMap &) const) &TFunction_Logbook::GetValid, "None", py::arg("Ls"));
cls_TFunction_Logbook.def("Done", (void (TFunction_Logbook::*)(const Standard_Boolean)) &TFunction_Logbook::Done, "Sets status of execution.", py::arg("status"));
cls_TFunction_Logbook.def("IsDone", (Standard_Boolean (TFunction_Logbook::*)() const) &TFunction_Logbook::IsDone, "Returns status of execution.");
cls_TFunction_Logbook.def("ID", (const Standard_GUID & (TFunction_Logbook::*)() const) &TFunction_Logbook::ID, "Returns the ID of the attribute.");
cls_TFunction_Logbook.def("Restore", (void (TFunction_Logbook::*)(const opencascade::handle<TDF_Attribute> &)) &TFunction_Logbook::Restore, "Undos (and redos) the attribute.", py::arg("with"));
cls_TFunction_Logbook.def("Paste", (void (TFunction_Logbook::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TFunction_Logbook::Paste, "Pastes the attribute to another label.", py::arg("into"), py::arg("RT"));
cls_TFunction_Logbook.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TFunction_Logbook::*)() const) &TFunction_Logbook::NewEmpty, "Returns a new empty instance of the attribute.");
cls_TFunction_Logbook.def("Dump", (Standard_OStream & (TFunction_Logbook::*)(Standard_OStream &) const) &TFunction_Logbook::Dump, "Prints th data of the attributes (touched, impacted and valid labels).", py::arg("anOS"));

// CLASS: TFUNCTION_SCOPE
py::class_<TFunction_Scope, opencascade::handle<TFunction_Scope>, TDF_Attribute> cls_TFunction_Scope(mod, "TFunction_Scope", "Keeps a scope of functions.");

// Constructors
cls_TFunction_Scope.def(py::init<>());

// Methods
cls_TFunction_Scope.def_static("Set_", (opencascade::handle<TFunction_Scope> (*)(const TDF_Label &)) &TFunction_Scope::Set, "Static methods ============== Finds or Creates a TFunction_Scope attribute at the root label accessed by <Access>. Returns the attribute.", py::arg("Access"));
cls_TFunction_Scope.def_static("GetID_", (const Standard_GUID & (*)()) &TFunction_Scope::GetID, "Returns the GUID for Scope attribute. Instant methods =============== Constructor (empty).");
cls_TFunction_Scope.def("AddFunction", (Standard_Boolean (TFunction_Scope::*)(const TDF_Label &)) &TFunction_Scope::AddFunction, "Adds a function to the scope of functions.", py::arg("L"));
cls_TFunction_Scope.def("RemoveFunction", (Standard_Boolean (TFunction_Scope::*)(const TDF_Label &)) &TFunction_Scope::RemoveFunction, "Removes a function from the scope of functions.", py::arg("L"));
cls_TFunction_Scope.def("RemoveFunction", (Standard_Boolean (TFunction_Scope::*)(const Standard_Integer)) &TFunction_Scope::RemoveFunction, "Removes a function from the scope of functions.", py::arg("ID"));
cls_TFunction_Scope.def("RemoveAllFunctions", (void (TFunction_Scope::*)()) &TFunction_Scope::RemoveAllFunctions, "Removes all functions from the scope of functions.");
cls_TFunction_Scope.def("HasFunction", (Standard_Boolean (TFunction_Scope::*)(const Standard_Integer) const) &TFunction_Scope::HasFunction, "Returns true if the function exists with such an ID.", py::arg("ID"));
cls_TFunction_Scope.def("HasFunction", (Standard_Boolean (TFunction_Scope::*)(const TDF_Label &) const) &TFunction_Scope::HasFunction, "Returns true if the label contains a function of this scope.", py::arg("L"));
cls_TFunction_Scope.def("GetFunction", (Standard_Integer (TFunction_Scope::*)(const TDF_Label &) const) &TFunction_Scope::GetFunction, "Returns an ID of the function.", py::arg("L"));
cls_TFunction_Scope.def("GetFunction", (const TDF_Label & (TFunction_Scope::*)(const Standard_Integer) const) &TFunction_Scope::GetFunction, "Returns the label of the function with this ID.", py::arg("ID"));
cls_TFunction_Scope.def("GetLogbook", (opencascade::handle<TFunction_Logbook> (TFunction_Scope::*)() const) &TFunction_Scope::GetLogbook, "Returns the Logbook used in TFunction_Driver methods. Implementation of Attribute methods ===================================");
cls_TFunction_Scope.def("ID", (const Standard_GUID & (TFunction_Scope::*)() const) &TFunction_Scope::ID, "None");
cls_TFunction_Scope.def("Restore", (void (TFunction_Scope::*)(const opencascade::handle<TDF_Attribute> &)) &TFunction_Scope::Restore, "None", py::arg("with"));
cls_TFunction_Scope.def("Paste", (void (TFunction_Scope::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TFunction_Scope::Paste, "None", py::arg("into"), py::arg("RT"));
cls_TFunction_Scope.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TFunction_Scope::*)() const) &TFunction_Scope::NewEmpty, "None");
cls_TFunction_Scope.def("Dump", (Standard_OStream & (TFunction_Scope::*)(Standard_OStream &) const) &TFunction_Scope::Dump, "None", py::arg("anOS"));
cls_TFunction_Scope.def("GetFunctions", (const TFunction_DoubleMapOfIntegerLabel & (TFunction_Scope::*)() const) &TFunction_Scope::GetFunctions, "Returns the scope of functions.");
cls_TFunction_Scope.def("ChangeFunctions", (TFunction_DoubleMapOfIntegerLabel & (TFunction_Scope::*)()) &TFunction_Scope::ChangeFunctions, "Returns the scope of functions for modification. Warning: Don't use this method if You are not sure what You do!");
cls_TFunction_Scope.def("SetFreeID", (void (TFunction_Scope::*)(const Standard_Integer)) &TFunction_Scope::SetFreeID, "None", py::arg("ID"));
cls_TFunction_Scope.def("GetFreeID", (Standard_Integer (TFunction_Scope::*)() const) &TFunction_Scope::GetFreeID, "None");
cls_TFunction_Scope.def_static("get_type_name_", (const char * (*)()) &TFunction_Scope::get_type_name, "None");
cls_TFunction_Scope.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TFunction_Scope::get_type_descriptor, "None");
cls_TFunction_Scope.def("DynamicType", (const opencascade::handle<Standard_Type> & (TFunction_Scope::*)() const) &TFunction_Scope::DynamicType, "None");


}
