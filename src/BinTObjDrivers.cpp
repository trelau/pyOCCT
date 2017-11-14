#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <Standard_Handle.hxx>
#include <Standard_Transient.hxx>
#include <Standard_GUID.hxx>
#include <TDocStd_Application.hxx>
#include <BinMDF_ADriverTable.hxx>
#include <CDM_MessageDriver.hxx>
#include <BinTObjDrivers.hxx>
#include <BinLDrivers_DocumentRetrievalDriver.hxx>
#include <Standard_Type.hxx>
#include <BinTObjDrivers_DocumentRetrievalDriver.hxx>
#include <BinLDrivers_DocumentStorageDriver.hxx>
#include <BinTObjDrivers_DocumentStorageDriver.hxx>
#include <BinMDF_ADriver.hxx>
#include <TDF_Attribute.hxx>
#include <Standard_TypeDef.hxx>
#include <BinObjMgt_Persistent.hxx>
#include <BinObjMgt_RRelocationTable.hxx>
#include <BinObjMgt_SRelocationTable.hxx>
#include <BinTObjDrivers_IntSparseArrayDriver.hxx>
#include <BinTObjDrivers_ModelDriver.hxx>
#include <BinTObjDrivers_ObjectDriver.hxx>
#include <BinTObjDrivers_ReferenceDriver.hxx>
#include <BinTObjDrivers_XYZDriver.hxx>

PYBIND11_MODULE(BinTObjDrivers, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.TDocStd");
	py::module::import("OCCT.BinMDF");
	py::module::import("OCCT.CDM");
	py::module::import("OCCT.BinLDrivers");
	py::module::import("OCCT.TDF");
	py::module::import("OCCT.BinObjMgt");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\BinTObjDrivers.hxx
	py::class_<BinTObjDrivers, std::unique_ptr<BinTObjDrivers, Deleter<BinTObjDrivers>>> cls_BinTObjDrivers(mod, "BinTObjDrivers", "Class for registering storage/retrieval drivers for TObj Bin persistence");
	cls_BinTObjDrivers.def(py::init<>());
	cls_BinTObjDrivers.def_static("Factory_", (const opencascade::handle<Standard_Transient> & (*)(const Standard_GUID &)) &BinTObjDrivers::Factory, "None", py::arg("aGUID"));
	cls_BinTObjDrivers.def_static("DefineFormat_", (void (*)(const opencascade::handle<TDocStd_Application> &)) &BinTObjDrivers::DefineFormat, "Defines format 'TObjBin' and registers its read and write drivers in the specified application", py::arg("theApp"));
	cls_BinTObjDrivers.def_static("AddDrivers_", (void (*)(const opencascade::handle<BinMDF_ADriverTable> &, const opencascade::handle<CDM_MessageDriver> &)) &BinTObjDrivers::AddDrivers, "None", py::arg("aDriverTable"), py::arg("aMsgDrv"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinTObjDrivers_DocumentRetrievalDriver.hxx
	py::class_<BinTObjDrivers_DocumentRetrievalDriver, opencascade::handle<BinTObjDrivers_DocumentRetrievalDriver>, BinLDrivers_DocumentRetrievalDriver> cls_BinTObjDrivers_DocumentRetrievalDriver(mod, "BinTObjDrivers_DocumentRetrievalDriver", "None");
	cls_BinTObjDrivers_DocumentRetrievalDriver.def(py::init<>());
	cls_BinTObjDrivers_DocumentRetrievalDriver.def("AttributeDrivers", (opencascade::handle<BinMDF_ADriverTable> (BinTObjDrivers_DocumentRetrievalDriver::*)(const opencascade::handle<CDM_MessageDriver> &)) &BinTObjDrivers_DocumentRetrievalDriver::AttributeDrivers, "None", py::arg("theMsgDriver"));
	cls_BinTObjDrivers_DocumentRetrievalDriver.def_static("get_type_name_", (const char * (*)()) &BinTObjDrivers_DocumentRetrievalDriver::get_type_name, "None");
	cls_BinTObjDrivers_DocumentRetrievalDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinTObjDrivers_DocumentRetrievalDriver::get_type_descriptor, "None");
	cls_BinTObjDrivers_DocumentRetrievalDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinTObjDrivers_DocumentRetrievalDriver::*)() const ) &BinTObjDrivers_DocumentRetrievalDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinTObjDrivers_DocumentStorageDriver.hxx
	py::class_<BinTObjDrivers_DocumentStorageDriver, opencascade::handle<BinTObjDrivers_DocumentStorageDriver>, BinLDrivers_DocumentStorageDriver> cls_BinTObjDrivers_DocumentStorageDriver(mod, "BinTObjDrivers_DocumentStorageDriver", "None");
	cls_BinTObjDrivers_DocumentStorageDriver.def(py::init<>());
	cls_BinTObjDrivers_DocumentStorageDriver.def("AttributeDrivers", (opencascade::handle<BinMDF_ADriverTable> (BinTObjDrivers_DocumentStorageDriver::*)(const opencascade::handle<CDM_MessageDriver> &)) &BinTObjDrivers_DocumentStorageDriver::AttributeDrivers, "None", py::arg("theMsgDriver"));
	cls_BinTObjDrivers_DocumentStorageDriver.def_static("get_type_name_", (const char * (*)()) &BinTObjDrivers_DocumentStorageDriver::get_type_name, "None");
	cls_BinTObjDrivers_DocumentStorageDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinTObjDrivers_DocumentStorageDriver::get_type_descriptor, "None");
	cls_BinTObjDrivers_DocumentStorageDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinTObjDrivers_DocumentStorageDriver::*)() const ) &BinTObjDrivers_DocumentStorageDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinTObjDrivers_IntSparseArrayDriver.hxx
	py::class_<BinTObjDrivers_IntSparseArrayDriver, opencascade::handle<BinTObjDrivers_IntSparseArrayDriver>, BinMDF_ADriver> cls_BinTObjDrivers_IntSparseArrayDriver(mod, "BinTObjDrivers_IntSparseArrayDriver", "None");
	cls_BinTObjDrivers_IntSparseArrayDriver.def(py::init<const opencascade::handle<CDM_MessageDriver> &>(), py::arg("theMessageDriver"));
	cls_BinTObjDrivers_IntSparseArrayDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinTObjDrivers_IntSparseArrayDriver::*)() const ) &BinTObjDrivers_IntSparseArrayDriver::NewEmpty, "None");
	cls_BinTObjDrivers_IntSparseArrayDriver.def("Paste", (Standard_Boolean (BinTObjDrivers_IntSparseArrayDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const ) &BinTObjDrivers_IntSparseArrayDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
	cls_BinTObjDrivers_IntSparseArrayDriver.def("Paste", (void (BinTObjDrivers_IntSparseArrayDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const ) &BinTObjDrivers_IntSparseArrayDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
	cls_BinTObjDrivers_IntSparseArrayDriver.def_static("get_type_name_", (const char * (*)()) &BinTObjDrivers_IntSparseArrayDriver::get_type_name, "None");
	cls_BinTObjDrivers_IntSparseArrayDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinTObjDrivers_IntSparseArrayDriver::get_type_descriptor, "None");
	cls_BinTObjDrivers_IntSparseArrayDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinTObjDrivers_IntSparseArrayDriver::*)() const ) &BinTObjDrivers_IntSparseArrayDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinTObjDrivers_ModelDriver.hxx
	py::class_<BinTObjDrivers_ModelDriver, opencascade::handle<BinTObjDrivers_ModelDriver>, BinMDF_ADriver> cls_BinTObjDrivers_ModelDriver(mod, "BinTObjDrivers_ModelDriver", "None");
	cls_BinTObjDrivers_ModelDriver.def(py::init<const opencascade::handle<CDM_MessageDriver> &>(), py::arg("theMessageDriver"));
	cls_BinTObjDrivers_ModelDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinTObjDrivers_ModelDriver::*)() const ) &BinTObjDrivers_ModelDriver::NewEmpty, "None");
	cls_BinTObjDrivers_ModelDriver.def("Paste", (Standard_Boolean (BinTObjDrivers_ModelDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const ) &BinTObjDrivers_ModelDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinTObjDrivers_ModelDriver.def("Paste", (void (BinTObjDrivers_ModelDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const ) &BinTObjDrivers_ModelDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinTObjDrivers_ModelDriver.def_static("get_type_name_", (const char * (*)()) &BinTObjDrivers_ModelDriver::get_type_name, "None");
	cls_BinTObjDrivers_ModelDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinTObjDrivers_ModelDriver::get_type_descriptor, "None");
	cls_BinTObjDrivers_ModelDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinTObjDrivers_ModelDriver::*)() const ) &BinTObjDrivers_ModelDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinTObjDrivers_ObjectDriver.hxx
	py::class_<BinTObjDrivers_ObjectDriver, opencascade::handle<BinTObjDrivers_ObjectDriver>, BinMDF_ADriver> cls_BinTObjDrivers_ObjectDriver(mod, "BinTObjDrivers_ObjectDriver", "None");
	cls_BinTObjDrivers_ObjectDriver.def(py::init<const opencascade::handle<CDM_MessageDriver> &>(), py::arg("theMessageDriver"));
	cls_BinTObjDrivers_ObjectDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinTObjDrivers_ObjectDriver::*)() const ) &BinTObjDrivers_ObjectDriver::NewEmpty, "None");
	cls_BinTObjDrivers_ObjectDriver.def("Paste", (Standard_Boolean (BinTObjDrivers_ObjectDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const ) &BinTObjDrivers_ObjectDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinTObjDrivers_ObjectDriver.def("Paste", (void (BinTObjDrivers_ObjectDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const ) &BinTObjDrivers_ObjectDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinTObjDrivers_ObjectDriver.def_static("get_type_name_", (const char * (*)()) &BinTObjDrivers_ObjectDriver::get_type_name, "None");
	cls_BinTObjDrivers_ObjectDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinTObjDrivers_ObjectDriver::get_type_descriptor, "None");
	cls_BinTObjDrivers_ObjectDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinTObjDrivers_ObjectDriver::*)() const ) &BinTObjDrivers_ObjectDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinTObjDrivers_ReferenceDriver.hxx
	py::class_<BinTObjDrivers_ReferenceDriver, opencascade::handle<BinTObjDrivers_ReferenceDriver>, BinMDF_ADriver> cls_BinTObjDrivers_ReferenceDriver(mod, "BinTObjDrivers_ReferenceDriver", "None");
	cls_BinTObjDrivers_ReferenceDriver.def(py::init<const opencascade::handle<CDM_MessageDriver> &>(), py::arg("theMessageDriver"));
	cls_BinTObjDrivers_ReferenceDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinTObjDrivers_ReferenceDriver::*)() const ) &BinTObjDrivers_ReferenceDriver::NewEmpty, "None");
	cls_BinTObjDrivers_ReferenceDriver.def("Paste", (Standard_Boolean (BinTObjDrivers_ReferenceDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const ) &BinTObjDrivers_ReferenceDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinTObjDrivers_ReferenceDriver.def("Paste", (void (BinTObjDrivers_ReferenceDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const ) &BinTObjDrivers_ReferenceDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinTObjDrivers_ReferenceDriver.def_static("get_type_name_", (const char * (*)()) &BinTObjDrivers_ReferenceDriver::get_type_name, "None");
	cls_BinTObjDrivers_ReferenceDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinTObjDrivers_ReferenceDriver::get_type_descriptor, "None");
	cls_BinTObjDrivers_ReferenceDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinTObjDrivers_ReferenceDriver::*)() const ) &BinTObjDrivers_ReferenceDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinTObjDrivers_XYZDriver.hxx
	py::class_<BinTObjDrivers_XYZDriver, opencascade::handle<BinTObjDrivers_XYZDriver>, BinMDF_ADriver> cls_BinTObjDrivers_XYZDriver(mod, "BinTObjDrivers_XYZDriver", "None");
	cls_BinTObjDrivers_XYZDriver.def(py::init<const opencascade::handle<CDM_MessageDriver> &>(), py::arg("theMessageDriver"));
	cls_BinTObjDrivers_XYZDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinTObjDrivers_XYZDriver::*)() const ) &BinTObjDrivers_XYZDriver::NewEmpty, "None");
	cls_BinTObjDrivers_XYZDriver.def("Paste", (Standard_Boolean (BinTObjDrivers_XYZDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const ) &BinTObjDrivers_XYZDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
	cls_BinTObjDrivers_XYZDriver.def("Paste", (void (BinTObjDrivers_XYZDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const ) &BinTObjDrivers_XYZDriver::Paste, "None", py::arg("theSource"), py::arg("theTarget"), py::arg("theRelocTable"));
	cls_BinTObjDrivers_XYZDriver.def_static("get_type_name_", (const char * (*)()) &BinTObjDrivers_XYZDriver::get_type_name, "None");
	cls_BinTObjDrivers_XYZDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinTObjDrivers_XYZDriver::get_type_descriptor, "None");
	cls_BinTObjDrivers_XYZDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinTObjDrivers_XYZDriver::*)() const ) &BinTObjDrivers_XYZDriver::DynamicType, "None");


}
