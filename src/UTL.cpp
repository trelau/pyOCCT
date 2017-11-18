#include <pyOCCT_Common.hpp>

#include <TCollection_ExtendedString.hxx>
#include <Standard_TypeDef.hxx>
#include <Storage_Error.hxx>
#include <Storage_BaseDriver.hxx>
#include <Storage_OpenMode.hxx>
#include <Standard_Handle.hxx>
#include <Storage_Data.hxx>
#include <OSD_Path.hxx>
#include <OSD_FileIterator.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_GUID.hxx>
#include <Resource_Manager.hxx>
#include <UTL.hxx>

PYBIND11_MODULE(UTL, mod) {

	// IMPORT
	py::module::import("OCCT.TCollection");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.Storage");
	py::module::import("OCCT.OSD");
	py::module::import("OCCT.Resource");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\UTL.hxx
	py::class_<UTL, std::unique_ptr<UTL, Deleter<UTL>>> cls_UTL(mod, "UTL", "None");
	cls_UTL.def(py::init<>());
	cls_UTL.def_static("xgetenv_", (TCollection_ExtendedString (*)(const Standard_CString)) &UTL::xgetenv, "None", py::arg("aCString"));
	cls_UTL.def_static("OpenFile_", (Storage_Error (*)(Storage_BaseDriver &, const TCollection_ExtendedString &, const Storage_OpenMode)) &UTL::OpenFile, "None", py::arg("aFile"), py::arg("aName"), py::arg("aMode"));
	cls_UTL.def_static("AddToUserInfo_", (void (*)(const opencascade::handle<Storage_Data> &, const TCollection_ExtendedString &)) &UTL::AddToUserInfo, "None", py::arg("aData"), py::arg("anInfo"));
	cls_UTL.def_static("Path_", (OSD_Path (*)(const TCollection_ExtendedString &)) &UTL::Path, "None", py::arg("aFileName"));
	cls_UTL.def_static("Disk_", (TCollection_ExtendedString (*)(const OSD_Path &)) &UTL::Disk, "None", py::arg("aPath"));
	cls_UTL.def_static("Trek_", (TCollection_ExtendedString (*)(const OSD_Path &)) &UTL::Trek, "None", py::arg("aPath"));
	cls_UTL.def_static("Name_", (TCollection_ExtendedString (*)(const OSD_Path &)) &UTL::Name, "None", py::arg("aPath"));
	cls_UTL.def_static("Extension_", (TCollection_ExtendedString (*)(const OSD_Path &)) &UTL::Extension, "None", py::arg("aPath"));
	cls_UTL.def_static("FileIterator_", (OSD_FileIterator (*)(const OSD_Path &, const TCollection_ExtendedString &)) &UTL::FileIterator, "None", py::arg("aPath"), py::arg("aMask"));
	cls_UTL.def_static("Extension_", (TCollection_ExtendedString (*)(const TCollection_ExtendedString &)) &UTL::Extension, "None", py::arg("aFileName"));
	cls_UTL.def_static("LocalHost_", (TCollection_ExtendedString (*)()) &UTL::LocalHost, "None");
	cls_UTL.def_static("ExtendedString_", (TCollection_ExtendedString (*)(const TCollection_AsciiString &)) &UTL::ExtendedString, "None", py::arg("anAsciiString"));
	cls_UTL.def_static("GUID_", (Standard_GUID (*)(const TCollection_ExtendedString &)) &UTL::GUID, "None", py::arg("anXString"));
	cls_UTL.def_static("Find_", (Standard_Boolean (*)(const opencascade::handle<Resource_Manager> &, const TCollection_ExtendedString &)) &UTL::Find, "None", py::arg("aResourceManager"), py::arg("aResourceName"));
	cls_UTL.def_static("Value_", (TCollection_ExtendedString (*)(const opencascade::handle<Resource_Manager> &, const TCollection_ExtendedString &)) &UTL::Value, "None", py::arg("aResourceManager"), py::arg("aResourceName"));
	cls_UTL.def_static("IntegerValue_", (Standard_Integer (*)(const TCollection_ExtendedString &)) &UTL::IntegerValue, "None", py::arg("anExtendedString"));
	cls_UTL.def_static("CString_", (Standard_CString (*)(const TCollection_ExtendedString &)) &UTL::CString, "None", py::arg("anExtendedString"));
	cls_UTL.def_static("IsReadOnly_", (Standard_Boolean (*)(const TCollection_ExtendedString &)) &UTL::IsReadOnly, "None", py::arg("aFileName"));


}
