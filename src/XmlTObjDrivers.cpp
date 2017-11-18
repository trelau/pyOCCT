#include <pyOCCT_Common.hpp>

#include <Standard_Handle.hxx>
#include <Standard_Transient.hxx>
#include <Standard_GUID.hxx>
#include <TDocStd_Application.hxx>
#include <XmlMDF_ADriverTable.hxx>
#include <CDM_MessageDriver.hxx>
#include <XmlTObjDrivers.hxx>
#include <XmlLDrivers_DocumentRetrievalDriver.hxx>
#include <Standard_Type.hxx>
#include <XmlTObjDrivers_DocumentRetrievalDriver.hxx>
#include <XmlLDrivers_DocumentStorageDriver.hxx>
#include <TCollection_ExtendedString.hxx>
#include <XmlTObjDrivers_DocumentStorageDriver.hxx>
#include <XmlMDF_ADriver.hxx>
#include <TDF_Attribute.hxx>
#include <Standard_TypeDef.hxx>
#include <XmlObjMgt_Persistent.hxx>
#include <XmlObjMgt_RRelocationTable.hxx>
#include <XmlObjMgt_SRelocationTable.hxx>
#include <XmlTObjDrivers_IntSparseArrayDriver.hxx>
#include <XmlTObjDrivers_ModelDriver.hxx>
#include <XmlTObjDrivers_ObjectDriver.hxx>
#include <XmlTObjDrivers_ReferenceDriver.hxx>
#include <XmlTObjDrivers_XYZDriver.hxx>

PYBIND11_MODULE(XmlTObjDrivers, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.TDocStd");
	py::module::import("OCCT.XmlMDF");
	py::module::import("OCCT.CDM");
	py::module::import("OCCT.XmlLDrivers");
	py::module::import("OCCT.TCollection");
	py::module::import("OCCT.TDF");
	py::module::import("OCCT.XmlObjMgt");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\XmlTObjDrivers.hxx
	py::class_<XmlTObjDrivers, std::unique_ptr<XmlTObjDrivers, Deleter<XmlTObjDrivers>>> cls_XmlTObjDrivers(mod, "XmlTObjDrivers", "Class for registering storage/retrieval drivers for TObj XML persistence");
	cls_XmlTObjDrivers.def(py::init<>());
	cls_XmlTObjDrivers.def_static("Factory_", (const opencascade::handle<Standard_Transient> & (*)(const Standard_GUID &)) &XmlTObjDrivers::Factory, "Returns a driver corresponding to <aGUID>. Used for plugin.", py::arg("aGUID"));
	cls_XmlTObjDrivers.def_static("DefineFormat_", (void (*)(const opencascade::handle<TDocStd_Application> &)) &XmlTObjDrivers::DefineFormat, "Defines format 'TObjXml' and registers its read and write drivers in the specified application", py::arg("theApp"));
	cls_XmlTObjDrivers.def_static("AddDrivers_", (void (*)(const opencascade::handle<XmlMDF_ADriverTable> &, const opencascade::handle<CDM_MessageDriver> &)) &XmlTObjDrivers::AddDrivers, "None", py::arg("aDriverTable"), py::arg("anMsgDrv"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\XmlTObjDrivers_DocumentRetrievalDriver.hxx
	py::class_<XmlTObjDrivers_DocumentRetrievalDriver, opencascade::handle<XmlTObjDrivers_DocumentRetrievalDriver>, XmlLDrivers_DocumentRetrievalDriver> cls_XmlTObjDrivers_DocumentRetrievalDriver(mod, "XmlTObjDrivers_DocumentRetrievalDriver", "None");
	cls_XmlTObjDrivers_DocumentRetrievalDriver.def(py::init<>());
	cls_XmlTObjDrivers_DocumentRetrievalDriver.def("AttributeDrivers", (opencascade::handle<XmlMDF_ADriverTable> (XmlTObjDrivers_DocumentRetrievalDriver::*)(const opencascade::handle<CDM_MessageDriver> &)) &XmlTObjDrivers_DocumentRetrievalDriver::AttributeDrivers, "None", py::arg("theMsgDriver"));
	cls_XmlTObjDrivers_DocumentRetrievalDriver.def_static("get_type_name_", (const char * (*)()) &XmlTObjDrivers_DocumentRetrievalDriver::get_type_name, "None");
	cls_XmlTObjDrivers_DocumentRetrievalDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlTObjDrivers_DocumentRetrievalDriver::get_type_descriptor, "None");
	cls_XmlTObjDrivers_DocumentRetrievalDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlTObjDrivers_DocumentRetrievalDriver::*)() const ) &XmlTObjDrivers_DocumentRetrievalDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\XmlTObjDrivers_DocumentStorageDriver.hxx
	py::class_<XmlTObjDrivers_DocumentStorageDriver, opencascade::handle<XmlTObjDrivers_DocumentStorageDriver>, XmlLDrivers_DocumentStorageDriver> cls_XmlTObjDrivers_DocumentStorageDriver(mod, "XmlTObjDrivers_DocumentStorageDriver", "None");
	cls_XmlTObjDrivers_DocumentStorageDriver.def(py::init<const TCollection_ExtendedString &>(), py::arg("theCopyright"));
	cls_XmlTObjDrivers_DocumentStorageDriver.def("AttributeDrivers", (opencascade::handle<XmlMDF_ADriverTable> (XmlTObjDrivers_DocumentStorageDriver::*)(const opencascade::handle<CDM_MessageDriver> &)) &XmlTObjDrivers_DocumentStorageDriver::AttributeDrivers, "None", py::arg("theMsgDriver"));
	cls_XmlTObjDrivers_DocumentStorageDriver.def_static("get_type_name_", (const char * (*)()) &XmlTObjDrivers_DocumentStorageDriver::get_type_name, "None");
	cls_XmlTObjDrivers_DocumentStorageDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlTObjDrivers_DocumentStorageDriver::get_type_descriptor, "None");
	cls_XmlTObjDrivers_DocumentStorageDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlTObjDrivers_DocumentStorageDriver::*)() const ) &XmlTObjDrivers_DocumentStorageDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\XmlTObjDrivers_IntSparseArrayDriver.hxx
	py::class_<XmlTObjDrivers_IntSparseArrayDriver, opencascade::handle<XmlTObjDrivers_IntSparseArrayDriver>, XmlMDF_ADriver> cls_XmlTObjDrivers_IntSparseArrayDriver(mod, "XmlTObjDrivers_IntSparseArrayDriver", "None");
	cls_XmlTObjDrivers_IntSparseArrayDriver.def(py::init<const opencascade::handle<CDM_MessageDriver> &>(), py::arg("theMessageDriver"));
	cls_XmlTObjDrivers_IntSparseArrayDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlTObjDrivers_IntSparseArrayDriver::*)() const ) &XmlTObjDrivers_IntSparseArrayDriver::NewEmpty, "None");
	cls_XmlTObjDrivers_IntSparseArrayDriver.def("Paste", (Standard_Boolean (XmlTObjDrivers_IntSparseArrayDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const ) &XmlTObjDrivers_IntSparseArrayDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
	cls_XmlTObjDrivers_IntSparseArrayDriver.def("Paste", (void (XmlTObjDrivers_IntSparseArrayDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const ) &XmlTObjDrivers_IntSparseArrayDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
	cls_XmlTObjDrivers_IntSparseArrayDriver.def_static("get_type_name_", (const char * (*)()) &XmlTObjDrivers_IntSparseArrayDriver::get_type_name, "None");
	cls_XmlTObjDrivers_IntSparseArrayDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlTObjDrivers_IntSparseArrayDriver::get_type_descriptor, "None");
	cls_XmlTObjDrivers_IntSparseArrayDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlTObjDrivers_IntSparseArrayDriver::*)() const ) &XmlTObjDrivers_IntSparseArrayDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\XmlTObjDrivers_ModelDriver.hxx
	py::class_<XmlTObjDrivers_ModelDriver, opencascade::handle<XmlTObjDrivers_ModelDriver>, XmlMDF_ADriver> cls_XmlTObjDrivers_ModelDriver(mod, "XmlTObjDrivers_ModelDriver", "None");
	cls_XmlTObjDrivers_ModelDriver.def(py::init<const opencascade::handle<CDM_MessageDriver> &>(), py::arg("theMessageDriver"));
	cls_XmlTObjDrivers_ModelDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlTObjDrivers_ModelDriver::*)() const ) &XmlTObjDrivers_ModelDriver::NewEmpty, "None");
	cls_XmlTObjDrivers_ModelDriver.def("Paste", (Standard_Boolean (XmlTObjDrivers_ModelDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const ) &XmlTObjDrivers_ModelDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_XmlTObjDrivers_ModelDriver.def("Paste", (void (XmlTObjDrivers_ModelDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const ) &XmlTObjDrivers_ModelDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_XmlTObjDrivers_ModelDriver.def_static("get_type_name_", (const char * (*)()) &XmlTObjDrivers_ModelDriver::get_type_name, "None");
	cls_XmlTObjDrivers_ModelDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlTObjDrivers_ModelDriver::get_type_descriptor, "None");
	cls_XmlTObjDrivers_ModelDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlTObjDrivers_ModelDriver::*)() const ) &XmlTObjDrivers_ModelDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\XmlTObjDrivers_ObjectDriver.hxx
	py::class_<XmlTObjDrivers_ObjectDriver, opencascade::handle<XmlTObjDrivers_ObjectDriver>, XmlMDF_ADriver> cls_XmlTObjDrivers_ObjectDriver(mod, "XmlTObjDrivers_ObjectDriver", "None");
	cls_XmlTObjDrivers_ObjectDriver.def(py::init<const opencascade::handle<CDM_MessageDriver> &>(), py::arg("theMessageDriver"));
	cls_XmlTObjDrivers_ObjectDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlTObjDrivers_ObjectDriver::*)() const ) &XmlTObjDrivers_ObjectDriver::NewEmpty, "None");
	cls_XmlTObjDrivers_ObjectDriver.def("Paste", (Standard_Boolean (XmlTObjDrivers_ObjectDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const ) &XmlTObjDrivers_ObjectDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_XmlTObjDrivers_ObjectDriver.def("Paste", (void (XmlTObjDrivers_ObjectDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const ) &XmlTObjDrivers_ObjectDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_XmlTObjDrivers_ObjectDriver.def_static("get_type_name_", (const char * (*)()) &XmlTObjDrivers_ObjectDriver::get_type_name, "None");
	cls_XmlTObjDrivers_ObjectDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlTObjDrivers_ObjectDriver::get_type_descriptor, "None");
	cls_XmlTObjDrivers_ObjectDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlTObjDrivers_ObjectDriver::*)() const ) &XmlTObjDrivers_ObjectDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\XmlTObjDrivers_ReferenceDriver.hxx
	py::class_<XmlTObjDrivers_ReferenceDriver, opencascade::handle<XmlTObjDrivers_ReferenceDriver>, XmlMDF_ADriver> cls_XmlTObjDrivers_ReferenceDriver(mod, "XmlTObjDrivers_ReferenceDriver", "None");
	cls_XmlTObjDrivers_ReferenceDriver.def(py::init<const opencascade::handle<CDM_MessageDriver> &>(), py::arg("theMessageDriver"));
	cls_XmlTObjDrivers_ReferenceDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlTObjDrivers_ReferenceDriver::*)() const ) &XmlTObjDrivers_ReferenceDriver::NewEmpty, "None");
	cls_XmlTObjDrivers_ReferenceDriver.def("Paste", (Standard_Boolean (XmlTObjDrivers_ReferenceDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const ) &XmlTObjDrivers_ReferenceDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_XmlTObjDrivers_ReferenceDriver.def("Paste", (void (XmlTObjDrivers_ReferenceDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const ) &XmlTObjDrivers_ReferenceDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_XmlTObjDrivers_ReferenceDriver.def_static("get_type_name_", (const char * (*)()) &XmlTObjDrivers_ReferenceDriver::get_type_name, "None");
	cls_XmlTObjDrivers_ReferenceDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlTObjDrivers_ReferenceDriver::get_type_descriptor, "None");
	cls_XmlTObjDrivers_ReferenceDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlTObjDrivers_ReferenceDriver::*)() const ) &XmlTObjDrivers_ReferenceDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\XmlTObjDrivers_XYZDriver.hxx
	py::class_<XmlTObjDrivers_XYZDriver, opencascade::handle<XmlTObjDrivers_XYZDriver>, XmlMDF_ADriver> cls_XmlTObjDrivers_XYZDriver(mod, "XmlTObjDrivers_XYZDriver", "None");
	cls_XmlTObjDrivers_XYZDriver.def(py::init<const opencascade::handle<CDM_MessageDriver> &>(), py::arg("theMessageDriver"));
	cls_XmlTObjDrivers_XYZDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlTObjDrivers_XYZDriver::*)() const ) &XmlTObjDrivers_XYZDriver::NewEmpty, "None");
	cls_XmlTObjDrivers_XYZDriver.def("Paste", (Standard_Boolean (XmlTObjDrivers_XYZDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const ) &XmlTObjDrivers_XYZDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_XmlTObjDrivers_XYZDriver.def("Paste", (void (XmlTObjDrivers_XYZDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const ) &XmlTObjDrivers_XYZDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_XmlTObjDrivers_XYZDriver.def_static("get_type_name_", (const char * (*)()) &XmlTObjDrivers_XYZDriver::get_type_name, "None");
	cls_XmlTObjDrivers_XYZDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlTObjDrivers_XYZDriver::get_type_descriptor, "None");
	cls_XmlTObjDrivers_XYZDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlTObjDrivers_XYZDriver::*)() const ) &XmlTObjDrivers_XYZDriver::DynamicType, "None");


}
