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
#include <StdObjMgt_MapOfInstantiators.hxx>
#include <StdDrivers.hxx>
#include <StdLDrivers_DocumentRetrievalDriver.hxx>
#include <Standard_Type.hxx>
#include <StdDrivers_DocumentRetrievalDriver.hxx>

PYBIND11_MODULE(StdDrivers, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.TDocStd");
	py::module::import("OCCT.StdObjMgt");
	py::module::import("OCCT.StdLDrivers");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\StdDrivers.hxx
	py::class_<StdDrivers, std::unique_ptr<StdDrivers, Deleter<StdDrivers>>> cls_StdDrivers(mod, "StdDrivers", "None");
	cls_StdDrivers.def(py::init<>());
	cls_StdDrivers.def_static("Factory_", (opencascade::handle<Standard_Transient> (*)(const Standard_GUID &)) &StdDrivers::Factory, "Depending from the ID, returns a list of storage or retrieval attribute drivers. Used for plugin", py::arg("aGUID"));
	cls_StdDrivers.def_static("DefineFormat_", (void (*)(const opencascade::handle<TDocStd_Application> &)) &StdDrivers::DefineFormat, "Defines format 'MDTV-Standard' and registers its retrieval driver in the specified application", py::arg("theApp"));
	cls_StdDrivers.def_static("BindTypes_", (void (*)(StdObjMgt_MapOfInstantiators &)) &StdDrivers::BindTypes, "Register types.", py::arg("theMap"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\StdDrivers_DocumentRetrievalDriver.hxx
	py::class_<StdDrivers_DocumentRetrievalDriver, opencascade::handle<StdDrivers_DocumentRetrievalDriver>, StdLDrivers_DocumentRetrievalDriver> cls_StdDrivers_DocumentRetrievalDriver(mod, "StdDrivers_DocumentRetrievalDriver", "retrieval driver of a Part document");
	cls_StdDrivers_DocumentRetrievalDriver.def_static("get_type_name_", (const char * (*)()) &StdDrivers_DocumentRetrievalDriver::get_type_name, "None");
	cls_StdDrivers_DocumentRetrievalDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StdDrivers_DocumentRetrievalDriver::get_type_descriptor, "None");
	cls_StdDrivers_DocumentRetrievalDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (StdDrivers_DocumentRetrievalDriver::*)() const ) &StdDrivers_DocumentRetrievalDriver::DynamicType, "None");


}
