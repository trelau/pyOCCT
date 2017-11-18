#include <pyOCCT_Common.hpp>

#include <PCDM_RetrievalDriver.hxx>
#include <Standard_Handle.hxx>
#include <CDM_Document.hxx>
#include <TCollection_ExtendedString.hxx>
#include <CDM_Application.hxx>
#include <Standard_IStream.hxx>
#include <Storage_Data.hxx>
#include <Standard_Type.hxx>
#include <StdLDrivers_DocumentRetrievalDriver.hxx>
#include <Standard_Transient.hxx>
#include <Standard_GUID.hxx>
#include <TDocStd_Application.hxx>
#include <StdObjMgt_MapOfInstantiators.hxx>
#include <StdLDrivers.hxx>

PYBIND11_MODULE(StdLDrivers, mod) {

	// IMPORT
	py::module::import("OCCT.PCDM");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.CDM");
	py::module::import("OCCT.TCollection");
	py::module::import("OCCT.Storage");
	py::module::import("OCCT.TDocStd");
	py::module::import("OCCT.StdObjMgt");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\StdLDrivers_DocumentRetrievalDriver.hxx
	py::class_<StdLDrivers_DocumentRetrievalDriver, opencascade::handle<StdLDrivers_DocumentRetrievalDriver>, PCDM_RetrievalDriver> cls_StdLDrivers_DocumentRetrievalDriver(mod, "StdLDrivers_DocumentRetrievalDriver", "retrieval driver of a Part document");
	cls_StdLDrivers_DocumentRetrievalDriver.def("CreateDocument", (opencascade::handle<CDM_Document> (StdLDrivers_DocumentRetrievalDriver::*)()) &StdLDrivers_DocumentRetrievalDriver::CreateDocument, "Create an empty TDocStd_Document.");
	cls_StdLDrivers_DocumentRetrievalDriver.def("Read", (void (StdLDrivers_DocumentRetrievalDriver::*)(const TCollection_ExtendedString &, const opencascade::handle<CDM_Document> &, const opencascade::handle<CDM_Application> &)) &StdLDrivers_DocumentRetrievalDriver::Read, "Retrieve the content of a file into a new document.", py::arg("theFileName"), py::arg("theNewDocument"), py::arg("theApplication"));
	cls_StdLDrivers_DocumentRetrievalDriver.def("Read", (void (StdLDrivers_DocumentRetrievalDriver::*)(Standard_IStream &, const opencascade::handle<Storage_Data> &, const opencascade::handle<CDM_Document> &, const opencascade::handle<CDM_Application> &)) &StdLDrivers_DocumentRetrievalDriver::Read, "Override pure virtual method (raises exception Standard_NotImplemented)", py::arg("theIStream"), py::arg("theStorageData"), py::arg("theDoc"), py::arg("theApplication"));
	cls_StdLDrivers_DocumentRetrievalDriver.def_static("get_type_name_", (const char * (*)()) &StdLDrivers_DocumentRetrievalDriver::get_type_name, "None");
	cls_StdLDrivers_DocumentRetrievalDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StdLDrivers_DocumentRetrievalDriver::get_type_descriptor, "None");
	cls_StdLDrivers_DocumentRetrievalDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (StdLDrivers_DocumentRetrievalDriver::*)() const ) &StdLDrivers_DocumentRetrievalDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StdLDrivers.hxx
	py::class_<StdLDrivers, std::unique_ptr<StdLDrivers, Deleter<StdLDrivers>>> cls_StdLDrivers(mod, "StdLDrivers", "None");
	cls_StdLDrivers.def(py::init<>());
	cls_StdLDrivers.def_static("Factory_", (opencascade::handle<Standard_Transient> (*)(const Standard_GUID &)) &StdLDrivers::Factory, "Depending from the ID, returns a list of storage or retrieval attribute drivers. Used for plugin", py::arg("aGUID"));
	cls_StdLDrivers.def_static("DefineFormat_", (void (*)(const opencascade::handle<TDocStd_Application> &)) &StdLDrivers::DefineFormat, "Defines format 'OCC-StdLite' and registers its retrieval driver in the specified application", py::arg("theApp"));
	cls_StdLDrivers.def_static("BindTypes_", (void (*)(StdObjMgt_MapOfInstantiators &)) &StdLDrivers::BindTypes, "Register types.", py::arg("theMap"));


}
