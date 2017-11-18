#include <pyOCCT_Common.hpp>

#include <BinMDF_ADriver.hxx>
#include <Standard_Handle.hxx>
#include <CDM_MessageDriver.hxx>
#include <TDF_Attribute.hxx>
#include <Standard_TypeDef.hxx>
#include <BinObjMgt_Persistent.hxx>
#include <BinObjMgt_RRelocationTable.hxx>
#include <BinObjMgt_SRelocationTable.hxx>
#include <Standard_IStream.hxx>
#include <Standard_OStream.hxx>
#include <BinTools_LocationSet.hxx>
#include <Standard_Type.hxx>
#include <BinMNaming_NamedShapeDriver.hxx>
#include <BinMNaming_NamingDriver.hxx>
#include <BinMDF_ADriverTable.hxx>
#include <BinMNaming.hxx>

PYBIND11_MODULE(BinMNaming, mod) {

	// IMPORT
	py::module::import("OCCT.BinMDF");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.CDM");
	py::module::import("OCCT.TDF");
	py::module::import("OCCT.BinObjMgt");
	py::module::import("OCCT.BinTools");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\BinMNaming_NamedShapeDriver.hxx
	py::class_<BinMNaming_NamedShapeDriver, opencascade::handle<BinMNaming_NamedShapeDriver>, BinMDF_ADriver> cls_BinMNaming_NamedShapeDriver(mod, "BinMNaming_NamedShapeDriver", "NamedShape Attribute Driver.");
	cls_BinMNaming_NamedShapeDriver.def(py::init<const opencascade::handle<CDM_MessageDriver> &>(), py::arg("theMessageDriver"));
	cls_BinMNaming_NamedShapeDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMNaming_NamedShapeDriver::*)() const ) &BinMNaming_NamedShapeDriver::NewEmpty, "None");
	cls_BinMNaming_NamedShapeDriver.def("Paste", (Standard_Boolean (BinMNaming_NamedShapeDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const ) &BinMNaming_NamedShapeDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMNaming_NamedShapeDriver.def("Paste", (void (BinMNaming_NamedShapeDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const ) &BinMNaming_NamedShapeDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMNaming_NamedShapeDriver.def("ReadShapeSection", (void (BinMNaming_NamedShapeDriver::*)(Standard_IStream &)) &BinMNaming_NamedShapeDriver::ReadShapeSection, "Input the shapes from Bin Document file", py::arg("theIS"));
	cls_BinMNaming_NamedShapeDriver.def("WriteShapeSection", (void (BinMNaming_NamedShapeDriver::*)(Standard_OStream &)) &BinMNaming_NamedShapeDriver::WriteShapeSection, "Output the shapes into Bin Document file", py::arg("theOS"));
	cls_BinMNaming_NamedShapeDriver.def("Clear", (void (BinMNaming_NamedShapeDriver::*)()) &BinMNaming_NamedShapeDriver::Clear, "Clear myShapeSet");
	cls_BinMNaming_NamedShapeDriver.def("IsWithTriangles", (Standard_Boolean (BinMNaming_NamedShapeDriver::*)() const ) &BinMNaming_NamedShapeDriver::IsWithTriangles, "Return true if shape should be stored with triangles.");
	cls_BinMNaming_NamedShapeDriver.def("SetWithTriangles", (void (BinMNaming_NamedShapeDriver::*)(const Standard_Boolean)) &BinMNaming_NamedShapeDriver::SetWithTriangles, "set whether to store triangulation", py::arg("isWithTriangles"));
	cls_BinMNaming_NamedShapeDriver.def("SetFormatNb", (void (BinMNaming_NamedShapeDriver::*)(const Standard_Integer)) &BinMNaming_NamedShapeDriver::SetFormatNb, "set the format of topology First : does not write CurveOnSurface UV Points into the file on reading calls Check() method. Second: stores CurveOnSurface UV Points.", py::arg("theFormat"));
	cls_BinMNaming_NamedShapeDriver.def("GetFormatNb", (Standard_Integer (BinMNaming_NamedShapeDriver::*)() const ) &BinMNaming_NamedShapeDriver::GetFormatNb, "get the format of topology");
	cls_BinMNaming_NamedShapeDriver.def("GetShapesLocations", (BinTools_LocationSet & (BinMNaming_NamedShapeDriver::*)()) &BinMNaming_NamedShapeDriver::GetShapesLocations, "get the format of topology");
	cls_BinMNaming_NamedShapeDriver.def_static("get_type_name_", (const char * (*)()) &BinMNaming_NamedShapeDriver::get_type_name, "None");
	cls_BinMNaming_NamedShapeDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMNaming_NamedShapeDriver::get_type_descriptor, "None");
	cls_BinMNaming_NamedShapeDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMNaming_NamedShapeDriver::*)() const ) &BinMNaming_NamedShapeDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinMNaming_NamingDriver.hxx
	py::class_<BinMNaming_NamingDriver, opencascade::handle<BinMNaming_NamingDriver>, BinMDF_ADriver> cls_BinMNaming_NamingDriver(mod, "BinMNaming_NamingDriver", "Naming Attribute Driver.");
	cls_BinMNaming_NamingDriver.def(py::init<const opencascade::handle<CDM_MessageDriver> &>(), py::arg("theMessageDriver"));
	cls_BinMNaming_NamingDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMNaming_NamingDriver::*)() const ) &BinMNaming_NamingDriver::NewEmpty, "None");
	cls_BinMNaming_NamingDriver.def("Paste", (Standard_Boolean (BinMNaming_NamingDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const ) &BinMNaming_NamingDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMNaming_NamingDriver.def("Paste", (void (BinMNaming_NamingDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const ) &BinMNaming_NamingDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMNaming_NamingDriver.def_static("get_type_name_", (const char * (*)()) &BinMNaming_NamingDriver::get_type_name, "None");
	cls_BinMNaming_NamingDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMNaming_NamingDriver::get_type_descriptor, "None");
	cls_BinMNaming_NamingDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMNaming_NamingDriver::*)() const ) &BinMNaming_NamingDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinMNaming.hxx
	py::class_<BinMNaming, std::unique_ptr<BinMNaming, Deleter<BinMNaming>>> cls_BinMNaming(mod, "BinMNaming", "Storage/Retrieval drivers for TNaming attributes");
	cls_BinMNaming.def(py::init<>());
	cls_BinMNaming.def_static("AddDrivers_", (void (*)(const opencascade::handle<BinMDF_ADriverTable> &, const opencascade::handle<CDM_MessageDriver> &)) &BinMNaming::AddDrivers, "Adds the attribute drivers to <theDriverTable>.", py::arg("theDriverTable"), py::arg("aMsgDrv"));
	cls_BinMNaming.def_static("SetDocumentVersion_", (void (*)(const Standard_Integer)) &BinMNaming::SetDocumentVersion, "None", py::arg("DocVersion"));
	cls_BinMNaming.def_static("DocumentVersion_", (Standard_Integer (*)()) &BinMNaming::DocumentVersion, "None");


}
