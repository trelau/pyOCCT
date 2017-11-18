#include <pyOCCT_Common.hpp>

#include <XmlMDF_ADriver.hxx>
#include <Standard_Handle.hxx>
#include <CDM_MessageDriver.hxx>
#include <TDF_Attribute.hxx>
#include <Standard_TypeDef.hxx>
#include <XmlObjMgt_Persistent.hxx>
#include <XmlObjMgt_RRelocationTable.hxx>
#include <XmlObjMgt_SRelocationTable.hxx>
#include <Standard_Type.hxx>
#include <XmlMFunction_FunctionDriver.hxx>
#include <XmlMFunction_ScopeDriver.hxx>
#include <XmlMFunction_GraphNodeDriver.hxx>
#include <XmlMDF_ADriverTable.hxx>
#include <XmlMFunction.hxx>

PYBIND11_MODULE(XmlMFunction, mod) {

	// IMPORT
	py::module::import("OCCT.XmlMDF");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.CDM");
	py::module::import("OCCT.TDF");
	py::module::import("OCCT.XmlObjMgt");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\XmlMFunction_FunctionDriver.hxx
	py::class_<XmlMFunction_FunctionDriver, opencascade::handle<XmlMFunction_FunctionDriver>, XmlMDF_ADriver> cls_XmlMFunction_FunctionDriver(mod, "XmlMFunction_FunctionDriver", "Attribute Driver.");
	cls_XmlMFunction_FunctionDriver.def(py::init<const opencascade::handle<CDM_MessageDriver> &>(), py::arg("theMessageDriver"));
	cls_XmlMFunction_FunctionDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMFunction_FunctionDriver::*)() const ) &XmlMFunction_FunctionDriver::NewEmpty, "None");
	cls_XmlMFunction_FunctionDriver.def("Paste", (Standard_Boolean (XmlMFunction_FunctionDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const ) &XmlMFunction_FunctionDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_XmlMFunction_FunctionDriver.def("Paste", (void (XmlMFunction_FunctionDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const ) &XmlMFunction_FunctionDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_XmlMFunction_FunctionDriver.def_static("get_type_name_", (const char * (*)()) &XmlMFunction_FunctionDriver::get_type_name, "None");
	cls_XmlMFunction_FunctionDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMFunction_FunctionDriver::get_type_descriptor, "None");
	cls_XmlMFunction_FunctionDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMFunction_FunctionDriver::*)() const ) &XmlMFunction_FunctionDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\XmlMFunction_ScopeDriver.hxx
	py::class_<XmlMFunction_ScopeDriver, opencascade::handle<XmlMFunction_ScopeDriver>, XmlMDF_ADriver> cls_XmlMFunction_ScopeDriver(mod, "XmlMFunction_ScopeDriver", "XML persistence driver for a scope of functions.");
	cls_XmlMFunction_ScopeDriver.def(py::init<const opencascade::handle<CDM_MessageDriver> &>(), py::arg("theMessageDriver"));
	cls_XmlMFunction_ScopeDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMFunction_ScopeDriver::*)() const ) &XmlMFunction_ScopeDriver::NewEmpty, "None");
	cls_XmlMFunction_ScopeDriver.def("Paste", (Standard_Boolean (XmlMFunction_ScopeDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const ) &XmlMFunction_ScopeDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_XmlMFunction_ScopeDriver.def("Paste", (void (XmlMFunction_ScopeDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const ) &XmlMFunction_ScopeDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_XmlMFunction_ScopeDriver.def_static("get_type_name_", (const char * (*)()) &XmlMFunction_ScopeDriver::get_type_name, "None");
	cls_XmlMFunction_ScopeDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMFunction_ScopeDriver::get_type_descriptor, "None");
	cls_XmlMFunction_ScopeDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMFunction_ScopeDriver::*)() const ) &XmlMFunction_ScopeDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\XmlMFunction_GraphNodeDriver.hxx
	py::class_<XmlMFunction_GraphNodeDriver, opencascade::handle<XmlMFunction_GraphNodeDriver>, XmlMDF_ADriver> cls_XmlMFunction_GraphNodeDriver(mod, "XmlMFunction_GraphNodeDriver", "XML persistence driver for dependencies of a function.");
	cls_XmlMFunction_GraphNodeDriver.def(py::init<const opencascade::handle<CDM_MessageDriver> &>(), py::arg("theMessageDriver"));
	cls_XmlMFunction_GraphNodeDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMFunction_GraphNodeDriver::*)() const ) &XmlMFunction_GraphNodeDriver::NewEmpty, "None");
	cls_XmlMFunction_GraphNodeDriver.def("Paste", (Standard_Boolean (XmlMFunction_GraphNodeDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const ) &XmlMFunction_GraphNodeDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_XmlMFunction_GraphNodeDriver.def("Paste", (void (XmlMFunction_GraphNodeDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const ) &XmlMFunction_GraphNodeDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_XmlMFunction_GraphNodeDriver.def_static("get_type_name_", (const char * (*)()) &XmlMFunction_GraphNodeDriver::get_type_name, "None");
	cls_XmlMFunction_GraphNodeDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMFunction_GraphNodeDriver::get_type_descriptor, "None");
	cls_XmlMFunction_GraphNodeDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMFunction_GraphNodeDriver::*)() const ) &XmlMFunction_GraphNodeDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\XmlMFunction.hxx
	py::class_<XmlMFunction, std::unique_ptr<XmlMFunction, Deleter<XmlMFunction>>> cls_XmlMFunction(mod, "XmlMFunction", "None");
	cls_XmlMFunction.def(py::init<>());
	cls_XmlMFunction.def_static("AddDrivers_", (void (*)(const opencascade::handle<XmlMDF_ADriverTable> &, const opencascade::handle<CDM_MessageDriver> &)) &XmlMFunction::AddDrivers, "Adds the attribute storage drivers to <aDriverTable>.", py::arg("aDriverTable"), py::arg("theMessageDriver"));


}
