#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <XmlMDF_ADriver.hxx>
#include <Standard_Handle.hxx>
#include <CDM_MessageDriver.hxx>
#include <TDF_Attribute.hxx>
#include <Standard_TypeDef.hxx>
#include <XmlObjMgt_Persistent.hxx>
#include <XmlObjMgt_RRelocationTable.hxx>
#include <XmlObjMgt_SRelocationTable.hxx>
#include <Standard_Type.hxx>
#include <XmlMDocStd_XLinkDriver.hxx>
#include <XmlMDF_ADriverTable.hxx>
#include <XmlMDocStd.hxx>

PYBIND11_MODULE(XmlMDocStd, mod) {

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
	// C:\Miniconda\envs\occt\Library\include\opencascade\XmlMDocStd_XLinkDriver.hxx
	py::class_<XmlMDocStd_XLinkDriver, opencascade::handle<XmlMDocStd_XLinkDriver>, XmlMDF_ADriver> cls_XmlMDocStd_XLinkDriver(mod, "XmlMDocStd_XLinkDriver", "Attribute Driver.");
	cls_XmlMDocStd_XLinkDriver.def(py::init<const opencascade::handle<CDM_MessageDriver> &>(), py::arg("theMessageDriver"));
	cls_XmlMDocStd_XLinkDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XmlMDocStd_XLinkDriver::*)() const ) &XmlMDocStd_XLinkDriver::NewEmpty, "None");
	cls_XmlMDocStd_XLinkDriver.def("Paste", (Standard_Boolean (XmlMDocStd_XLinkDriver::*)(const XmlObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, XmlObjMgt_RRelocationTable &) const ) &XmlMDocStd_XLinkDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_XmlMDocStd_XLinkDriver.def("Paste", (void (XmlMDocStd_XLinkDriver::*)(const opencascade::handle<TDF_Attribute> &, XmlObjMgt_Persistent &, XmlObjMgt_SRelocationTable &) const ) &XmlMDocStd_XLinkDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_XmlMDocStd_XLinkDriver.def_static("get_type_name_", (const char * (*)()) &XmlMDocStd_XLinkDriver::get_type_name, "None");
	cls_XmlMDocStd_XLinkDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XmlMDocStd_XLinkDriver::get_type_descriptor, "None");
	cls_XmlMDocStd_XLinkDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (XmlMDocStd_XLinkDriver::*)() const ) &XmlMDocStd_XLinkDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\XmlMDocStd.hxx
	py::class_<XmlMDocStd, std::unique_ptr<XmlMDocStd, Deleter<XmlMDocStd>>> cls_XmlMDocStd(mod, "XmlMDocStd", "Driver for TDocStd_XLink");
	cls_XmlMDocStd.def(py::init<>());
	cls_XmlMDocStd.def_static("AddDrivers_", (void (*)(const opencascade::handle<XmlMDF_ADriverTable> &, const opencascade::handle<CDM_MessageDriver> &)) &XmlMDocStd::AddDrivers, "Adds the attribute drivers to <aDriverTable>.", py::arg("aDriverTable"), py::arg("theMessageDriver"));


}
