#include <pyOCCT_Common.hpp>

#include <PCDM_RetrievalDriver.hxx>
#include <Standard_Handle.hxx>
#include <CDM_Document.hxx>
#include <TCollection_ExtendedString.hxx>
#include <CDM_Application.hxx>
#include <Standard_IStream.hxx>
#include <Storage_Data.hxx>
#include <XmlMDF_ADriverTable.hxx>
#include <CDM_MessageDriver.hxx>
#include <Standard_Type.hxx>
#include <XmlLDrivers_DocumentRetrievalDriver.hxx>
#include <TCollection_AsciiString.hxx>
#include <XmlLDrivers_NamespaceDef.hxx>
#include <NCollection_BaseSequence.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_Sequence.hxx>
#include <Standard_TypeDef.hxx>
#include <XmlLDrivers_SequenceOfNamespaceDef.hxx>
#include <PCDM_StorageDriver.hxx>
#include <Standard_OStream.hxx>
#include <XmlLDrivers_DocumentStorageDriver.hxx>
#include <Standard_Transient.hxx>
#include <Standard_GUID.hxx>
#include <TDocStd_Application.hxx>
#include <XmlLDrivers.hxx>
#include <NCollection_Templates.hpp>

PYBIND11_MODULE(XmlLDrivers, mod) {

	// IMPORT
	py::module::import("OCCT.PCDM");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.CDM");
	py::module::import("OCCT.TCollection");
	py::module::import("OCCT.Storage");
	py::module::import("OCCT.XmlMDF");
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.TDocStd");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\XmlLDrivers_DocumentRetrievalDriver.hxx
	py::class_<XmlLDrivers_DocumentRetrievalDriver, opencascade::handle<XmlLDrivers_DocumentRetrievalDriver>, PCDM_RetrievalDriver> cls_XmlLDrivers_DocumentRetrievalDriver(mod, "XmlLDrivers_DocumentRetrievalDriver", "None");
	cls_XmlLDrivers_DocumentRetrievalDriver.def(py::init<>());
	cls_XmlLDrivers_DocumentRetrievalDriver.def("CreateDocument", (opencascade::handle<CDM_Document> (XmlLDrivers_DocumentRetrievalDriver::*)()) &XmlLDrivers_DocumentRetrievalDriver::CreateDocument, "None");
	cls_XmlLDrivers_DocumentRetrievalDriver.def("Read", (void (XmlLDrivers_DocumentRetrievalDriver::*)(const TCollection_ExtendedString &, const opencascade::handle<CDM_Document> &, const opencascade::handle<CDM_Application> &)) &XmlLDrivers_DocumentRetrievalDriver::Read, "None", py::arg("theFileName"), py::arg("theNewDocument"), py::arg("theApplication"));
	cls_XmlLDrivers_DocumentRetrievalDriver.def("Read", (void (XmlLDrivers_DocumentRetrievalDriver::*)(Standard_IStream &, const opencascade::handle<Storage_Data> &, const opencascade::handle<CDM_Document> &, const opencascade::handle<CDM_Application> &)) &XmlLDrivers_DocumentRetrievalDriver::Read, "None", py::arg("theIStream"), py::arg("theStorageData"), py::arg("theDoc"), py::arg("theApplication"));
	cls_XmlLDrivers_DocumentRetrievalDriver.def("AttributeDrivers", (opencascade::handle<XmlMDF_ADriverTable> (XmlLDrivers_DocumentRetrievalDriver::*)(const opencascade::handle<CDM_MessageDriver> &)) &XmlLDrivers_DocumentRetrievalDriver::AttributeDrivers, "None", py::arg("theMsgDriver"));
	cls_XmlLDrivers_DocumentRetrievalDriver.def_static("get_type_name_", (const char * (*)()) &XmlLDrivers_DocumentRetrievalDriver::get_type_name, "None");
	cls_XmlLDrivers_DocumentRetrievalDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlLDrivers_DocumentRetrievalDriver::get_type_descriptor, "None");
	cls_XmlLDrivers_DocumentRetrievalDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlLDrivers_DocumentRetrievalDriver::*)() const ) &XmlLDrivers_DocumentRetrievalDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\XmlLDrivers_NamespaceDef.hxx
	py::class_<XmlLDrivers_NamespaceDef, std::unique_ptr<XmlLDrivers_NamespaceDef, Deleter<XmlLDrivers_NamespaceDef>>> cls_XmlLDrivers_NamespaceDef(mod, "XmlLDrivers_NamespaceDef", "None");
	cls_XmlLDrivers_NamespaceDef.def(py::init<>());
	cls_XmlLDrivers_NamespaceDef.def(py::init<const TCollection_AsciiString &, const TCollection_AsciiString &>(), py::arg("thePrefix"), py::arg("theURI"));
	cls_XmlLDrivers_NamespaceDef.def("Prefix", (const TCollection_AsciiString & (XmlLDrivers_NamespaceDef::*)() const ) &XmlLDrivers_NamespaceDef::Prefix, "None");
	cls_XmlLDrivers_NamespaceDef.def("URI", (const TCollection_AsciiString & (XmlLDrivers_NamespaceDef::*)() const ) &XmlLDrivers_NamespaceDef::URI, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\XmlLDrivers_DocumentStorageDriver.hxx
	py::class_<XmlLDrivers_DocumentStorageDriver, opencascade::handle<XmlLDrivers_DocumentStorageDriver>, PCDM_StorageDriver> cls_XmlLDrivers_DocumentStorageDriver(mod, "XmlLDrivers_DocumentStorageDriver", "None");
	cls_XmlLDrivers_DocumentStorageDriver.def(py::init<const TCollection_ExtendedString &>(), py::arg("theCopyright"));
	cls_XmlLDrivers_DocumentStorageDriver.def("Write", (void (XmlLDrivers_DocumentStorageDriver::*)(const opencascade::handle<CDM_Document> &, const TCollection_ExtendedString &)) &XmlLDrivers_DocumentStorageDriver::Write, "None", py::arg("theDocument"), py::arg("theFileName"));
	cls_XmlLDrivers_DocumentStorageDriver.def("Write", (void (XmlLDrivers_DocumentStorageDriver::*)(const opencascade::handle<CDM_Document> &, Standard_OStream &)) &XmlLDrivers_DocumentStorageDriver::Write, "None", py::arg("theDocument"), py::arg("theOStream"));
	cls_XmlLDrivers_DocumentStorageDriver.def("AttributeDrivers", (opencascade::handle<XmlMDF_ADriverTable> (XmlLDrivers_DocumentStorageDriver::*)(const opencascade::handle<CDM_MessageDriver> &)) &XmlLDrivers_DocumentStorageDriver::AttributeDrivers, "None", py::arg("theMsgDriver"));
	cls_XmlLDrivers_DocumentStorageDriver.def_static("get_type_name_", (const char * (*)()) &XmlLDrivers_DocumentStorageDriver::get_type_name, "None");
	cls_XmlLDrivers_DocumentStorageDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlLDrivers_DocumentStorageDriver::get_type_descriptor, "None");
	cls_XmlLDrivers_DocumentStorageDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlLDrivers_DocumentStorageDriver::*)() const ) &XmlLDrivers_DocumentStorageDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\XmlLDrivers.hxx
	py::class_<XmlLDrivers, std::unique_ptr<XmlLDrivers, Deleter<XmlLDrivers>>> cls_XmlLDrivers(mod, "XmlLDrivers", "None");
	cls_XmlLDrivers.def(py::init<>());
	cls_XmlLDrivers.def_static("Factory_", (const opencascade::handle<Standard_Transient> & (*)(const Standard_GUID &)) &XmlLDrivers::Factory, "None", py::arg("theGUID"));
	cls_XmlLDrivers.def_static("CreationDate_", (TCollection_AsciiString (*)()) &XmlLDrivers::CreationDate, "None");
	cls_XmlLDrivers.def_static("DefineFormat_", (void (*)(const opencascade::handle<TDocStd_Application> &)) &XmlLDrivers::DefineFormat, "Defines format 'XmlLOcaf' and registers its read and write drivers in the specified application", py::arg("theApp"));
	cls_XmlLDrivers.def_static("AttributeDrivers_", (opencascade::handle<XmlMDF_ADriverTable> (*)(const opencascade::handle<CDM_MessageDriver> &)) &XmlLDrivers::AttributeDrivers, "None", py::arg("theMsgDriver"));
	cls_XmlLDrivers.def_static("StorageVersion_", (int (*)()) &XmlLDrivers::StorageVersion, "None");
	cls_XmlLDrivers.def_static("SetStorageVersion_", (void (*)(const int)) &XmlLDrivers::SetStorageVersion, "None", py::arg("version"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\XmlLDrivers_SequenceOfNamespaceDef.hxx
	bind_NCollection_Sequence<XmlLDrivers_NamespaceDef>(mod, "XmlLDrivers_SequenceOfNamespaceDef");


}
