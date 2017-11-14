#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <BinLDrivers_DocumentStorageDriver.hxx>
#include <Standard_Handle.hxx>
#include <BinMDF_ADriverTable.hxx>
#include <CDM_MessageDriver.hxx>
#include <BinLDrivers_DocumentSection.hxx>
#include <Standard_OStream.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Type.hxx>
#include <BinDrivers_DocumentStorageDriver.hxx>
#include <BinLDrivers_DocumentRetrievalDriver.hxx>
#include <Standard_IStream.hxx>
#include <Storage_Position.hxx>
#include <BinDrivers_DocumentRetrievalDriver.hxx>
#include <Standard_Transient.hxx>
#include <Standard_GUID.hxx>
#include <TDocStd_Application.hxx>
#include <TCollection_AsciiString.hxx>
#include <BinDrivers.hxx>
#include <BinDrivers_Marker.hxx>

PYBIND11_MODULE(BinDrivers, mod) {

	// IMPORT
	py::module::import("OCCT.BinLDrivers");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.BinMDF");
	py::module::import("OCCT.CDM");
	py::module::import("OCCT.Storage");
	py::module::import("OCCT.TDocStd");
	py::module::import("OCCT.TCollection");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\BinDrivers_Marker.hxx
	py::enum_<BinDrivers_Marker>(mod, "BinDrivers_Marker", "None")
		.value("BinDrivers_ENDATTRLIST", BinDrivers_Marker::BinDrivers_ENDATTRLIST)
		.value("BinDrivers_ENDLABEL", BinDrivers_Marker::BinDrivers_ENDLABEL)
		.export_values();

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\BinDrivers_DocumentStorageDriver.hxx
	py::class_<BinDrivers_DocumentStorageDriver, opencascade::handle<BinDrivers_DocumentStorageDriver>, BinLDrivers_DocumentStorageDriver> cls_BinDrivers_DocumentStorageDriver(mod, "BinDrivers_DocumentStorageDriver", "persistent implemention of storage a document in a binary file");
	cls_BinDrivers_DocumentStorageDriver.def(py::init<>());
	cls_BinDrivers_DocumentStorageDriver.def("AttributeDrivers", (opencascade::handle<BinMDF_ADriverTable> (BinDrivers_DocumentStorageDriver::*)(const opencascade::handle<CDM_MessageDriver> &)) &BinDrivers_DocumentStorageDriver::AttributeDrivers, "None", py::arg("theMsgDriver"));
	cls_BinDrivers_DocumentStorageDriver.def("WriteShapeSection", (void (BinDrivers_DocumentStorageDriver::*)(BinLDrivers_DocumentSection &, Standard_OStream &)) &BinDrivers_DocumentStorageDriver::WriteShapeSection, "implements the procedure of writing a shape section to file", py::arg("theDocSection"), py::arg("theOS"));
	cls_BinDrivers_DocumentStorageDriver.def("IsWithTriangles", (Standard_Boolean (BinDrivers_DocumentStorageDriver::*)() const ) &BinDrivers_DocumentStorageDriver::IsWithTriangles, "Return true if shape should be stored with triangles.");
	cls_BinDrivers_DocumentStorageDriver.def("SetWithTriangles", (void (BinDrivers_DocumentStorageDriver::*)(const opencascade::handle<CDM_MessageDriver> &, const Standard_Boolean)) &BinDrivers_DocumentStorageDriver::SetWithTriangles, "Set if triangulation should be stored or not.", py::arg("theMessageDriver"), py::arg("theWithTriangulation"));
	cls_BinDrivers_DocumentStorageDriver.def_static("get_type_name_", (const char * (*)()) &BinDrivers_DocumentStorageDriver::get_type_name, "None");
	cls_BinDrivers_DocumentStorageDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinDrivers_DocumentStorageDriver::get_type_descriptor, "None");
	cls_BinDrivers_DocumentStorageDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinDrivers_DocumentStorageDriver::*)() const ) &BinDrivers_DocumentStorageDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinDrivers_DocumentRetrievalDriver.hxx
	py::class_<BinDrivers_DocumentRetrievalDriver, opencascade::handle<BinDrivers_DocumentRetrievalDriver>, BinLDrivers_DocumentRetrievalDriver> cls_BinDrivers_DocumentRetrievalDriver(mod, "BinDrivers_DocumentRetrievalDriver", "None");
	cls_BinDrivers_DocumentRetrievalDriver.def(py::init<>());
	cls_BinDrivers_DocumentRetrievalDriver.def("AttributeDrivers", (opencascade::handle<BinMDF_ADriverTable> (BinDrivers_DocumentRetrievalDriver::*)(const opencascade::handle<CDM_MessageDriver> &)) &BinDrivers_DocumentRetrievalDriver::AttributeDrivers, "None", py::arg("theMsgDriver"));
	cls_BinDrivers_DocumentRetrievalDriver.def("ReadShapeSection", [](BinDrivers_DocumentRetrievalDriver &self, BinLDrivers_DocumentSection & a0, Standard_IStream & a1) -> void { return self.ReadShapeSection(a0, a1); }, py::arg("theSection"), py::arg("theIS"));
	cls_BinDrivers_DocumentRetrievalDriver.def("ReadShapeSection", (void (BinDrivers_DocumentRetrievalDriver::*)(BinLDrivers_DocumentSection &, Standard_IStream &, const Standard_Boolean)) &BinDrivers_DocumentRetrievalDriver::ReadShapeSection, "None", py::arg("theSection"), py::arg("theIS"), py::arg("isMess"));
	cls_BinDrivers_DocumentRetrievalDriver.def("CheckShapeSection", (void (BinDrivers_DocumentRetrievalDriver::*)(const Storage_Position &, Standard_IStream &)) &BinDrivers_DocumentRetrievalDriver::CheckShapeSection, "None", py::arg("thePos"), py::arg("theIS"));
	cls_BinDrivers_DocumentRetrievalDriver.def("Clear", (void (BinDrivers_DocumentRetrievalDriver::*)()) &BinDrivers_DocumentRetrievalDriver::Clear, "Clears the NamedShape driver");
	cls_BinDrivers_DocumentRetrievalDriver.def("PropagateDocumentVersion", (void (BinDrivers_DocumentRetrievalDriver::*)(const Standard_Integer)) &BinDrivers_DocumentRetrievalDriver::PropagateDocumentVersion, "None", py::arg("theVersion"));
	cls_BinDrivers_DocumentRetrievalDriver.def_static("get_type_name_", (const char * (*)()) &BinDrivers_DocumentRetrievalDriver::get_type_name, "None");
	cls_BinDrivers_DocumentRetrievalDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinDrivers_DocumentRetrievalDriver::get_type_descriptor, "None");
	cls_BinDrivers_DocumentRetrievalDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinDrivers_DocumentRetrievalDriver::*)() const ) &BinDrivers_DocumentRetrievalDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinDrivers.hxx
	py::class_<BinDrivers, std::unique_ptr<BinDrivers, Deleter<BinDrivers>>> cls_BinDrivers(mod, "BinDrivers", "None");
	cls_BinDrivers.def(py::init<>());
	cls_BinDrivers.def_static("Factory_", (const opencascade::handle<Standard_Transient> & (*)(const Standard_GUID &)) &BinDrivers::Factory, "None", py::arg("theGUID"));
	cls_BinDrivers.def_static("DefineFormat_", (void (*)(const opencascade::handle<TDocStd_Application> &)) &BinDrivers::DefineFormat, "Defines format 'BinOcaf' and registers its read and write drivers in the specified application", py::arg("theApp"));
	cls_BinDrivers.def_static("AttributeDrivers_", (opencascade::handle<BinMDF_ADriverTable> (*)(const opencascade::handle<CDM_MessageDriver> &)) &BinDrivers::AttributeDrivers, "Creates the table of drivers of types supported", py::arg("MsgDrv"));
	cls_BinDrivers.def_static("StorageVersion_", (TCollection_AsciiString (*)()) &BinDrivers::StorageVersion, "returns '1'");


}
