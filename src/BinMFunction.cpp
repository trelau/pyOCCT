#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <BinMDF_ADriver.hxx>
#include <Standard_Handle.hxx>
#include <CDM_MessageDriver.hxx>
#include <TDF_Attribute.hxx>
#include <Standard_TypeDef.hxx>
#include <BinObjMgt_Persistent.hxx>
#include <BinObjMgt_RRelocationTable.hxx>
#include <BinObjMgt_SRelocationTable.hxx>
#include <Standard_Type.hxx>
#include <BinMFunction_FunctionDriver.hxx>
#include <BinMFunction_GraphNodeDriver.hxx>
#include <BinMFunction_ScopeDriver.hxx>
#include <BinMDF_ADriverTable.hxx>
#include <BinMFunction.hxx>

PYBIND11_MODULE(BinMFunction, mod) {

	// IMPORT
	py::module::import("OCCT.BinMDF");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.CDM");
	py::module::import("OCCT.TDF");
	py::module::import("OCCT.BinObjMgt");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\BinMFunction_FunctionDriver.hxx
	py::class_<BinMFunction_FunctionDriver, opencascade::handle<BinMFunction_FunctionDriver>, BinMDF_ADriver> cls_BinMFunction_FunctionDriver(mod, "BinMFunction_FunctionDriver", "Function attribute Driver.");
	cls_BinMFunction_FunctionDriver.def(py::init<const opencascade::handle<CDM_MessageDriver> &>(), py::arg("theMessageDriver"));
	cls_BinMFunction_FunctionDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMFunction_FunctionDriver::*)() const ) &BinMFunction_FunctionDriver::NewEmpty, "None");
	cls_BinMFunction_FunctionDriver.def("Paste", (Standard_Boolean (BinMFunction_FunctionDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const ) &BinMFunction_FunctionDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMFunction_FunctionDriver.def("Paste", (void (BinMFunction_FunctionDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const ) &BinMFunction_FunctionDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMFunction_FunctionDriver.def_static("get_type_name_", (const char * (*)()) &BinMFunction_FunctionDriver::get_type_name, "None");
	cls_BinMFunction_FunctionDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMFunction_FunctionDriver::get_type_descriptor, "None");
	cls_BinMFunction_FunctionDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMFunction_FunctionDriver::*)() const ) &BinMFunction_FunctionDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinMFunction_GraphNodeDriver.hxx
	py::class_<BinMFunction_GraphNodeDriver, opencascade::handle<BinMFunction_GraphNodeDriver>, BinMDF_ADriver> cls_BinMFunction_GraphNodeDriver(mod, "BinMFunction_GraphNodeDriver", "GraphNode attribute Driver.");
	cls_BinMFunction_GraphNodeDriver.def(py::init<const opencascade::handle<CDM_MessageDriver> &>(), py::arg("theMessageDriver"));
	cls_BinMFunction_GraphNodeDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMFunction_GraphNodeDriver::*)() const ) &BinMFunction_GraphNodeDriver::NewEmpty, "None");
	cls_BinMFunction_GraphNodeDriver.def("Paste", (Standard_Boolean (BinMFunction_GraphNodeDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const ) &BinMFunction_GraphNodeDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMFunction_GraphNodeDriver.def("Paste", (void (BinMFunction_GraphNodeDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const ) &BinMFunction_GraphNodeDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMFunction_GraphNodeDriver.def_static("get_type_name_", (const char * (*)()) &BinMFunction_GraphNodeDriver::get_type_name, "None");
	cls_BinMFunction_GraphNodeDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMFunction_GraphNodeDriver::get_type_descriptor, "None");
	cls_BinMFunction_GraphNodeDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMFunction_GraphNodeDriver::*)() const ) &BinMFunction_GraphNodeDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinMFunction_ScopeDriver.hxx
	py::class_<BinMFunction_ScopeDriver, opencascade::handle<BinMFunction_ScopeDriver>, BinMDF_ADriver> cls_BinMFunction_ScopeDriver(mod, "BinMFunction_ScopeDriver", "Scope attribute Driver.");
	cls_BinMFunction_ScopeDriver.def(py::init<const opencascade::handle<CDM_MessageDriver> &>(), py::arg("theMessageDriver"));
	cls_BinMFunction_ScopeDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMFunction_ScopeDriver::*)() const ) &BinMFunction_ScopeDriver::NewEmpty, "None");
	cls_BinMFunction_ScopeDriver.def("Paste", (Standard_Boolean (BinMFunction_ScopeDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const ) &BinMFunction_ScopeDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMFunction_ScopeDriver.def("Paste", (void (BinMFunction_ScopeDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const ) &BinMFunction_ScopeDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMFunction_ScopeDriver.def_static("get_type_name_", (const char * (*)()) &BinMFunction_ScopeDriver::get_type_name, "None");
	cls_BinMFunction_ScopeDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMFunction_ScopeDriver::get_type_descriptor, "None");
	cls_BinMFunction_ScopeDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMFunction_ScopeDriver::*)() const ) &BinMFunction_ScopeDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinMFunction.hxx
	py::class_<BinMFunction, std::unique_ptr<BinMFunction, Deleter<BinMFunction>>> cls_BinMFunction(mod, "BinMFunction", "Storage and Retrieval drivers for TFunction modelling attributes.");
	cls_BinMFunction.def(py::init<>());
	cls_BinMFunction.def_static("AddDrivers_", (void (*)(const opencascade::handle<BinMDF_ADriverTable> &, const opencascade::handle<CDM_MessageDriver> &)) &BinMFunction::AddDrivers, "Adds the attribute drivers to <theDriverTable>.", py::arg("theDriverTable"), py::arg("aMsgDrv"));


}
