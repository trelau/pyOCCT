#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <BinMDF_ADriver.hxx>
#include <Standard_Handle.hxx>
#include <CDM_MessageDriver.hxx>
#include <TDF_Attribute.hxx>
#include <Standard_TypeDef.hxx>
#include <BinObjMgt_Persistent.hxx>
#include <BinObjMgt_RRelocationTable.hxx>
#include <BinObjMgt_SRelocationTable.hxx>
#include <Standard_Type.hxx>
#include <BinMDataStd_NameDriver.hxx>
#include <BinMDataStd_IntegerDriver.hxx>
#include <BinMDataStd_RealDriver.hxx>
#include <BinMDataStd_IntegerArrayDriver.hxx>
#include <BinMDataStd_RealArrayDriver.hxx>
#include <BinMDataStd_UAttributeDriver.hxx>
#include <BinMDataStd_DirectoryDriver.hxx>
#include <BinMDataStd_CommentDriver.hxx>
#include <BinMDataStd_VariableDriver.hxx>
#include <BinMDataStd_ExpressionDriver.hxx>
#include <BinMDataStd_RelationDriver.hxx>
#include <BinMDataStd_NoteBookDriver.hxx>
#include <BinMDataStd_TreeNodeDriver.hxx>
#include <BinMDataStd_ExtStringArrayDriver.hxx>
#include <BinMDataStd_TickDriver.hxx>
#include <BinMDataStd_AsciiStringDriver.hxx>
#include <BinMDataStd_IntPackedMapDriver.hxx>
#include <BinMDataStd_IntegerListDriver.hxx>
#include <BinMDataStd_RealListDriver.hxx>
#include <BinMDataStd_ExtStringListDriver.hxx>
#include <BinMDataStd_BooleanListDriver.hxx>
#include <BinMDataStd_ReferenceListDriver.hxx>
#include <BinMDataStd_BooleanArrayDriver.hxx>
#include <BinMDataStd_ReferenceArrayDriver.hxx>
#include <BinMDataStd_ByteArrayDriver.hxx>
#include <BinMDataStd_NamedDataDriver.hxx>
#include <BinMDF_ADriverTable.hxx>
#include <BinMDataStd.hxx>

PYBIND11_MODULE(BinMDataStd, mod) {

	// IMPORT
	py::module::import("OCCT.BinMDF");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.CDM");
	py::module::import("OCCT.TDF");
	py::module::import("OCCT.BinObjMgt");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\BinMDataStd_NameDriver.hxx
	py::class_<BinMDataStd_NameDriver, opencascade::handle<BinMDataStd_NameDriver>, BinMDF_ADriver> cls_BinMDataStd_NameDriver(mod, "BinMDataStd_NameDriver", "TDataStd_Name attribute Driver.");
	cls_BinMDataStd_NameDriver.def(py::init<const opencascade::handle<CDM_MessageDriver> &>(), py::arg("theMessageDriver"));
	cls_BinMDataStd_NameDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDataStd_NameDriver::*)() const ) &BinMDataStd_NameDriver::NewEmpty, "None");
	cls_BinMDataStd_NameDriver.def("Paste", (Standard_Boolean (BinMDataStd_NameDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const ) &BinMDataStd_NameDriver::Paste, "persistent -> transient (retrieve)", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataStd_NameDriver.def("Paste", (void (BinMDataStd_NameDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const ) &BinMDataStd_NameDriver::Paste, "transient -> persistent (store)", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataStd_NameDriver.def_static("get_type_name_", (const char * (*)()) &BinMDataStd_NameDriver::get_type_name, "None");
	cls_BinMDataStd_NameDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDataStd_NameDriver::get_type_descriptor, "None");
	cls_BinMDataStd_NameDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDataStd_NameDriver::*)() const ) &BinMDataStd_NameDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinMDataStd_IntegerDriver.hxx
	py::class_<BinMDataStd_IntegerDriver, opencascade::handle<BinMDataStd_IntegerDriver>, BinMDF_ADriver> cls_BinMDataStd_IntegerDriver(mod, "BinMDataStd_IntegerDriver", "Integer attribute Driver.");
	cls_BinMDataStd_IntegerDriver.def(py::init<const opencascade::handle<CDM_MessageDriver> &>(), py::arg("theMessageDriver"));
	cls_BinMDataStd_IntegerDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDataStd_IntegerDriver::*)() const ) &BinMDataStd_IntegerDriver::NewEmpty, "None");
	cls_BinMDataStd_IntegerDriver.def("Paste", (Standard_Boolean (BinMDataStd_IntegerDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const ) &BinMDataStd_IntegerDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataStd_IntegerDriver.def("Paste", (void (BinMDataStd_IntegerDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const ) &BinMDataStd_IntegerDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataStd_IntegerDriver.def_static("get_type_name_", (const char * (*)()) &BinMDataStd_IntegerDriver::get_type_name, "None");
	cls_BinMDataStd_IntegerDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDataStd_IntegerDriver::get_type_descriptor, "None");
	cls_BinMDataStd_IntegerDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDataStd_IntegerDriver::*)() const ) &BinMDataStd_IntegerDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinMDataStd_RealDriver.hxx
	py::class_<BinMDataStd_RealDriver, opencascade::handle<BinMDataStd_RealDriver>, BinMDF_ADriver> cls_BinMDataStd_RealDriver(mod, "BinMDataStd_RealDriver", "Real attribute Driver.");
	cls_BinMDataStd_RealDriver.def(py::init<const opencascade::handle<CDM_MessageDriver> &>(), py::arg("theMessageDriver"));
	cls_BinMDataStd_RealDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDataStd_RealDriver::*)() const ) &BinMDataStd_RealDriver::NewEmpty, "None");
	cls_BinMDataStd_RealDriver.def("Paste", (Standard_Boolean (BinMDataStd_RealDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const ) &BinMDataStd_RealDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataStd_RealDriver.def("Paste", (void (BinMDataStd_RealDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const ) &BinMDataStd_RealDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataStd_RealDriver.def_static("get_type_name_", (const char * (*)()) &BinMDataStd_RealDriver::get_type_name, "None");
	cls_BinMDataStd_RealDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDataStd_RealDriver::get_type_descriptor, "None");
	cls_BinMDataStd_RealDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDataStd_RealDriver::*)() const ) &BinMDataStd_RealDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinMDataStd_IntegerArrayDriver.hxx
	py::class_<BinMDataStd_IntegerArrayDriver, opencascade::handle<BinMDataStd_IntegerArrayDriver>, BinMDF_ADriver> cls_BinMDataStd_IntegerArrayDriver(mod, "BinMDataStd_IntegerArrayDriver", "Array of Integer attribute Driver.");
	cls_BinMDataStd_IntegerArrayDriver.def(py::init<const opencascade::handle<CDM_MessageDriver> &>(), py::arg("theMessageDriver"));
	cls_BinMDataStd_IntegerArrayDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDataStd_IntegerArrayDriver::*)() const ) &BinMDataStd_IntegerArrayDriver::NewEmpty, "None");
	cls_BinMDataStd_IntegerArrayDriver.def("Paste", (Standard_Boolean (BinMDataStd_IntegerArrayDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const ) &BinMDataStd_IntegerArrayDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataStd_IntegerArrayDriver.def("Paste", (void (BinMDataStd_IntegerArrayDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const ) &BinMDataStd_IntegerArrayDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataStd_IntegerArrayDriver.def_static("get_type_name_", (const char * (*)()) &BinMDataStd_IntegerArrayDriver::get_type_name, "None");
	cls_BinMDataStd_IntegerArrayDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDataStd_IntegerArrayDriver::get_type_descriptor, "None");
	cls_BinMDataStd_IntegerArrayDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDataStd_IntegerArrayDriver::*)() const ) &BinMDataStd_IntegerArrayDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinMDataStd_RealArrayDriver.hxx
	py::class_<BinMDataStd_RealArrayDriver, opencascade::handle<BinMDataStd_RealArrayDriver>, BinMDF_ADriver> cls_BinMDataStd_RealArrayDriver(mod, "BinMDataStd_RealArrayDriver", "Array of Real attribute Driver.");
	cls_BinMDataStd_RealArrayDriver.def(py::init<const opencascade::handle<CDM_MessageDriver> &>(), py::arg("theMessageDriver"));
	cls_BinMDataStd_RealArrayDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDataStd_RealArrayDriver::*)() const ) &BinMDataStd_RealArrayDriver::NewEmpty, "None");
	cls_BinMDataStd_RealArrayDriver.def("Paste", (Standard_Boolean (BinMDataStd_RealArrayDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const ) &BinMDataStd_RealArrayDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataStd_RealArrayDriver.def("Paste", (void (BinMDataStd_RealArrayDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const ) &BinMDataStd_RealArrayDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataStd_RealArrayDriver.def_static("get_type_name_", (const char * (*)()) &BinMDataStd_RealArrayDriver::get_type_name, "None");
	cls_BinMDataStd_RealArrayDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDataStd_RealArrayDriver::get_type_descriptor, "None");
	cls_BinMDataStd_RealArrayDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDataStd_RealArrayDriver::*)() const ) &BinMDataStd_RealArrayDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinMDataStd_UAttributeDriver.hxx
	py::class_<BinMDataStd_UAttributeDriver, opencascade::handle<BinMDataStd_UAttributeDriver>, BinMDF_ADriver> cls_BinMDataStd_UAttributeDriver(mod, "BinMDataStd_UAttributeDriver", "Attribute Driver.");
	cls_BinMDataStd_UAttributeDriver.def(py::init<const opencascade::handle<CDM_MessageDriver> &>(), py::arg("theMessageDriver"));
	cls_BinMDataStd_UAttributeDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDataStd_UAttributeDriver::*)() const ) &BinMDataStd_UAttributeDriver::NewEmpty, "None");
	cls_BinMDataStd_UAttributeDriver.def("Paste", (Standard_Boolean (BinMDataStd_UAttributeDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const ) &BinMDataStd_UAttributeDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataStd_UAttributeDriver.def("Paste", (void (BinMDataStd_UAttributeDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const ) &BinMDataStd_UAttributeDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataStd_UAttributeDriver.def_static("get_type_name_", (const char * (*)()) &BinMDataStd_UAttributeDriver::get_type_name, "None");
	cls_BinMDataStd_UAttributeDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDataStd_UAttributeDriver::get_type_descriptor, "None");
	cls_BinMDataStd_UAttributeDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDataStd_UAttributeDriver::*)() const ) &BinMDataStd_UAttributeDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinMDataStd_DirectoryDriver.hxx
	py::class_<BinMDataStd_DirectoryDriver, opencascade::handle<BinMDataStd_DirectoryDriver>, BinMDF_ADriver> cls_BinMDataStd_DirectoryDriver(mod, "BinMDataStd_DirectoryDriver", "Directory attribute Driver.");
	cls_BinMDataStd_DirectoryDriver.def(py::init<const opencascade::handle<CDM_MessageDriver> &>(), py::arg("theMessageDriver"));
	cls_BinMDataStd_DirectoryDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDataStd_DirectoryDriver::*)() const ) &BinMDataStd_DirectoryDriver::NewEmpty, "None");
	cls_BinMDataStd_DirectoryDriver.def("Paste", (Standard_Boolean (BinMDataStd_DirectoryDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const ) &BinMDataStd_DirectoryDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataStd_DirectoryDriver.def("Paste", (void (BinMDataStd_DirectoryDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const ) &BinMDataStd_DirectoryDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataStd_DirectoryDriver.def_static("get_type_name_", (const char * (*)()) &BinMDataStd_DirectoryDriver::get_type_name, "None");
	cls_BinMDataStd_DirectoryDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDataStd_DirectoryDriver::get_type_descriptor, "None");
	cls_BinMDataStd_DirectoryDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDataStd_DirectoryDriver::*)() const ) &BinMDataStd_DirectoryDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinMDataStd_CommentDriver.hxx
	py::class_<BinMDataStd_CommentDriver, opencascade::handle<BinMDataStd_CommentDriver>, BinMDF_ADriver> cls_BinMDataStd_CommentDriver(mod, "BinMDataStd_CommentDriver", "Attribute Driver.");
	cls_BinMDataStd_CommentDriver.def(py::init<const opencascade::handle<CDM_MessageDriver> &>(), py::arg("theMessageDriver"));
	cls_BinMDataStd_CommentDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDataStd_CommentDriver::*)() const ) &BinMDataStd_CommentDriver::NewEmpty, "None");
	cls_BinMDataStd_CommentDriver.def("Paste", (Standard_Boolean (BinMDataStd_CommentDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const ) &BinMDataStd_CommentDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataStd_CommentDriver.def("Paste", (void (BinMDataStd_CommentDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const ) &BinMDataStd_CommentDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataStd_CommentDriver.def_static("get_type_name_", (const char * (*)()) &BinMDataStd_CommentDriver::get_type_name, "None");
	cls_BinMDataStd_CommentDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDataStd_CommentDriver::get_type_descriptor, "None");
	cls_BinMDataStd_CommentDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDataStd_CommentDriver::*)() const ) &BinMDataStd_CommentDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinMDataStd_VariableDriver.hxx
	py::class_<BinMDataStd_VariableDriver, opencascade::handle<BinMDataStd_VariableDriver>, BinMDF_ADriver> cls_BinMDataStd_VariableDriver(mod, "BinMDataStd_VariableDriver", "Attribute Driver.");
	cls_BinMDataStd_VariableDriver.def(py::init<const opencascade::handle<CDM_MessageDriver> &>(), py::arg("theMessageDriver"));
	cls_BinMDataStd_VariableDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDataStd_VariableDriver::*)() const ) &BinMDataStd_VariableDriver::NewEmpty, "None");
	cls_BinMDataStd_VariableDriver.def("Paste", (Standard_Boolean (BinMDataStd_VariableDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const ) &BinMDataStd_VariableDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataStd_VariableDriver.def("Paste", (void (BinMDataStd_VariableDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const ) &BinMDataStd_VariableDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataStd_VariableDriver.def_static("get_type_name_", (const char * (*)()) &BinMDataStd_VariableDriver::get_type_name, "None");
	cls_BinMDataStd_VariableDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDataStd_VariableDriver::get_type_descriptor, "None");
	cls_BinMDataStd_VariableDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDataStd_VariableDriver::*)() const ) &BinMDataStd_VariableDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinMDataStd_ExpressionDriver.hxx
	py::class_<BinMDataStd_ExpressionDriver, opencascade::handle<BinMDataStd_ExpressionDriver>, BinMDF_ADriver> cls_BinMDataStd_ExpressionDriver(mod, "BinMDataStd_ExpressionDriver", "Attribute Driver.");
	cls_BinMDataStd_ExpressionDriver.def(py::init<const opencascade::handle<CDM_MessageDriver> &>(), py::arg("theMessageDriver"));
	cls_BinMDataStd_ExpressionDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDataStd_ExpressionDriver::*)() const ) &BinMDataStd_ExpressionDriver::NewEmpty, "None");
	cls_BinMDataStd_ExpressionDriver.def("Paste", (Standard_Boolean (BinMDataStd_ExpressionDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const ) &BinMDataStd_ExpressionDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataStd_ExpressionDriver.def("Paste", (void (BinMDataStd_ExpressionDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const ) &BinMDataStd_ExpressionDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataStd_ExpressionDriver.def_static("get_type_name_", (const char * (*)()) &BinMDataStd_ExpressionDriver::get_type_name, "None");
	cls_BinMDataStd_ExpressionDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDataStd_ExpressionDriver::get_type_descriptor, "None");
	cls_BinMDataStd_ExpressionDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDataStd_ExpressionDriver::*)() const ) &BinMDataStd_ExpressionDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinMDataStd_RelationDriver.hxx
	py::class_<BinMDataStd_RelationDriver, opencascade::handle<BinMDataStd_RelationDriver>, BinMDF_ADriver> cls_BinMDataStd_RelationDriver(mod, "BinMDataStd_RelationDriver", "Attribute Driver.");
	cls_BinMDataStd_RelationDriver.def(py::init<const opencascade::handle<CDM_MessageDriver> &>(), py::arg("theMessageDriver"));
	cls_BinMDataStd_RelationDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDataStd_RelationDriver::*)() const ) &BinMDataStd_RelationDriver::NewEmpty, "None");
	cls_BinMDataStd_RelationDriver.def("Paste", (Standard_Boolean (BinMDataStd_RelationDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const ) &BinMDataStd_RelationDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataStd_RelationDriver.def("Paste", (void (BinMDataStd_RelationDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const ) &BinMDataStd_RelationDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataStd_RelationDriver.def_static("get_type_name_", (const char * (*)()) &BinMDataStd_RelationDriver::get_type_name, "None");
	cls_BinMDataStd_RelationDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDataStd_RelationDriver::get_type_descriptor, "None");
	cls_BinMDataStd_RelationDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDataStd_RelationDriver::*)() const ) &BinMDataStd_RelationDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinMDataStd_NoteBookDriver.hxx
	py::class_<BinMDataStd_NoteBookDriver, opencascade::handle<BinMDataStd_NoteBookDriver>, BinMDF_ADriver> cls_BinMDataStd_NoteBookDriver(mod, "BinMDataStd_NoteBookDriver", "NoteBook attribute Driver.");
	cls_BinMDataStd_NoteBookDriver.def(py::init<const opencascade::handle<CDM_MessageDriver> &>(), py::arg("theMessageDriver"));
	cls_BinMDataStd_NoteBookDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDataStd_NoteBookDriver::*)() const ) &BinMDataStd_NoteBookDriver::NewEmpty, "None");
	cls_BinMDataStd_NoteBookDriver.def("Paste", (Standard_Boolean (BinMDataStd_NoteBookDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const ) &BinMDataStd_NoteBookDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataStd_NoteBookDriver.def("Paste", (void (BinMDataStd_NoteBookDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const ) &BinMDataStd_NoteBookDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataStd_NoteBookDriver.def_static("get_type_name_", (const char * (*)()) &BinMDataStd_NoteBookDriver::get_type_name, "None");
	cls_BinMDataStd_NoteBookDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDataStd_NoteBookDriver::get_type_descriptor, "None");
	cls_BinMDataStd_NoteBookDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDataStd_NoteBookDriver::*)() const ) &BinMDataStd_NoteBookDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinMDataStd_TreeNodeDriver.hxx
	py::class_<BinMDataStd_TreeNodeDriver, opencascade::handle<BinMDataStd_TreeNodeDriver>, BinMDF_ADriver> cls_BinMDataStd_TreeNodeDriver(mod, "BinMDataStd_TreeNodeDriver", "Attribute Driver.");
	cls_BinMDataStd_TreeNodeDriver.def(py::init<const opencascade::handle<CDM_MessageDriver> &>(), py::arg("theMessageDriver"));
	cls_BinMDataStd_TreeNodeDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDataStd_TreeNodeDriver::*)() const ) &BinMDataStd_TreeNodeDriver::NewEmpty, "None");
	cls_BinMDataStd_TreeNodeDriver.def("Paste", (Standard_Boolean (BinMDataStd_TreeNodeDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const ) &BinMDataStd_TreeNodeDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataStd_TreeNodeDriver.def("Paste", (void (BinMDataStd_TreeNodeDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const ) &BinMDataStd_TreeNodeDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataStd_TreeNodeDriver.def_static("get_type_name_", (const char * (*)()) &BinMDataStd_TreeNodeDriver::get_type_name, "None");
	cls_BinMDataStd_TreeNodeDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDataStd_TreeNodeDriver::get_type_descriptor, "None");
	cls_BinMDataStd_TreeNodeDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDataStd_TreeNodeDriver::*)() const ) &BinMDataStd_TreeNodeDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinMDataStd_ExtStringArrayDriver.hxx
	py::class_<BinMDataStd_ExtStringArrayDriver, opencascade::handle<BinMDataStd_ExtStringArrayDriver>, BinMDF_ADriver> cls_BinMDataStd_ExtStringArrayDriver(mod, "BinMDataStd_ExtStringArrayDriver", "Array of extended string attribute Driver.");
	cls_BinMDataStd_ExtStringArrayDriver.def(py::init<const opencascade::handle<CDM_MessageDriver> &>(), py::arg("theMessageDriver"));
	cls_BinMDataStd_ExtStringArrayDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDataStd_ExtStringArrayDriver::*)() const ) &BinMDataStd_ExtStringArrayDriver::NewEmpty, "None");
	cls_BinMDataStd_ExtStringArrayDriver.def("Paste", (Standard_Boolean (BinMDataStd_ExtStringArrayDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const ) &BinMDataStd_ExtStringArrayDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataStd_ExtStringArrayDriver.def("Paste", (void (BinMDataStd_ExtStringArrayDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const ) &BinMDataStd_ExtStringArrayDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataStd_ExtStringArrayDriver.def_static("get_type_name_", (const char * (*)()) &BinMDataStd_ExtStringArrayDriver::get_type_name, "None");
	cls_BinMDataStd_ExtStringArrayDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDataStd_ExtStringArrayDriver::get_type_descriptor, "None");
	cls_BinMDataStd_ExtStringArrayDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDataStd_ExtStringArrayDriver::*)() const ) &BinMDataStd_ExtStringArrayDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinMDataStd_TickDriver.hxx
	py::class_<BinMDataStd_TickDriver, opencascade::handle<BinMDataStd_TickDriver>, BinMDF_ADriver> cls_BinMDataStd_TickDriver(mod, "BinMDataStd_TickDriver", "Tick attribute driver.");
	cls_BinMDataStd_TickDriver.def(py::init<const opencascade::handle<CDM_MessageDriver> &>(), py::arg("theMessageDriver"));
	cls_BinMDataStd_TickDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDataStd_TickDriver::*)() const ) &BinMDataStd_TickDriver::NewEmpty, "None");
	cls_BinMDataStd_TickDriver.def("Paste", (Standard_Boolean (BinMDataStd_TickDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const ) &BinMDataStd_TickDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataStd_TickDriver.def("Paste", (void (BinMDataStd_TickDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const ) &BinMDataStd_TickDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataStd_TickDriver.def_static("get_type_name_", (const char * (*)()) &BinMDataStd_TickDriver::get_type_name, "None");
	cls_BinMDataStd_TickDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDataStd_TickDriver::get_type_descriptor, "None");
	cls_BinMDataStd_TickDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDataStd_TickDriver::*)() const ) &BinMDataStd_TickDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinMDataStd_AsciiStringDriver.hxx
	py::class_<BinMDataStd_AsciiStringDriver, opencascade::handle<BinMDataStd_AsciiStringDriver>, BinMDF_ADriver> cls_BinMDataStd_AsciiStringDriver(mod, "BinMDataStd_AsciiStringDriver", "TDataStd_AsciiString attribute Driver.");
	cls_BinMDataStd_AsciiStringDriver.def(py::init<const opencascade::handle<CDM_MessageDriver> &>(), py::arg("theMessageDriver"));
	cls_BinMDataStd_AsciiStringDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDataStd_AsciiStringDriver::*)() const ) &BinMDataStd_AsciiStringDriver::NewEmpty, "None");
	cls_BinMDataStd_AsciiStringDriver.def("Paste", (Standard_Boolean (BinMDataStd_AsciiStringDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const ) &BinMDataStd_AsciiStringDriver::Paste, "persistent -> transient (retrieve)", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataStd_AsciiStringDriver.def("Paste", (void (BinMDataStd_AsciiStringDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const ) &BinMDataStd_AsciiStringDriver::Paste, "transient -> persistent (store)", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataStd_AsciiStringDriver.def_static("get_type_name_", (const char * (*)()) &BinMDataStd_AsciiStringDriver::get_type_name, "None");
	cls_BinMDataStd_AsciiStringDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDataStd_AsciiStringDriver::get_type_descriptor, "None");
	cls_BinMDataStd_AsciiStringDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDataStd_AsciiStringDriver::*)() const ) &BinMDataStd_AsciiStringDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinMDataStd_IntPackedMapDriver.hxx
	py::class_<BinMDataStd_IntPackedMapDriver, opencascade::handle<BinMDataStd_IntPackedMapDriver>, BinMDF_ADriver> cls_BinMDataStd_IntPackedMapDriver(mod, "BinMDataStd_IntPackedMapDriver", "TDataStd_IntPackedMap attribute Driver.");
	cls_BinMDataStd_IntPackedMapDriver.def(py::init<const opencascade::handle<CDM_MessageDriver> &>(), py::arg("theMessageDriver"));
	cls_BinMDataStd_IntPackedMapDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDataStd_IntPackedMapDriver::*)() const ) &BinMDataStd_IntPackedMapDriver::NewEmpty, "None");
	cls_BinMDataStd_IntPackedMapDriver.def("Paste", (Standard_Boolean (BinMDataStd_IntPackedMapDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const ) &BinMDataStd_IntPackedMapDriver::Paste, "persistent -> transient (retrieve)", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataStd_IntPackedMapDriver.def("Paste", (void (BinMDataStd_IntPackedMapDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const ) &BinMDataStd_IntPackedMapDriver::Paste, "transient -> persistent (store)", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataStd_IntPackedMapDriver.def_static("get_type_name_", (const char * (*)()) &BinMDataStd_IntPackedMapDriver::get_type_name, "None");
	cls_BinMDataStd_IntPackedMapDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDataStd_IntPackedMapDriver::get_type_descriptor, "None");
	cls_BinMDataStd_IntPackedMapDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDataStd_IntPackedMapDriver::*)() const ) &BinMDataStd_IntPackedMapDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinMDataStd_IntegerListDriver.hxx
	py::class_<BinMDataStd_IntegerListDriver, opencascade::handle<BinMDataStd_IntegerListDriver>, BinMDF_ADriver> cls_BinMDataStd_IntegerListDriver(mod, "BinMDataStd_IntegerListDriver", "None");
	cls_BinMDataStd_IntegerListDriver.def(py::init<const opencascade::handle<CDM_MessageDriver> &>(), py::arg("theMessageDriver"));
	cls_BinMDataStd_IntegerListDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDataStd_IntegerListDriver::*)() const ) &BinMDataStd_IntegerListDriver::NewEmpty, "None");
	cls_BinMDataStd_IntegerListDriver.def("Paste", (Standard_Boolean (BinMDataStd_IntegerListDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const ) &BinMDataStd_IntegerListDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataStd_IntegerListDriver.def("Paste", (void (BinMDataStd_IntegerListDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const ) &BinMDataStd_IntegerListDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataStd_IntegerListDriver.def_static("get_type_name_", (const char * (*)()) &BinMDataStd_IntegerListDriver::get_type_name, "None");
	cls_BinMDataStd_IntegerListDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDataStd_IntegerListDriver::get_type_descriptor, "None");
	cls_BinMDataStd_IntegerListDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDataStd_IntegerListDriver::*)() const ) &BinMDataStd_IntegerListDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinMDataStd_RealListDriver.hxx
	py::class_<BinMDataStd_RealListDriver, opencascade::handle<BinMDataStd_RealListDriver>, BinMDF_ADriver> cls_BinMDataStd_RealListDriver(mod, "BinMDataStd_RealListDriver", "None");
	cls_BinMDataStd_RealListDriver.def(py::init<const opencascade::handle<CDM_MessageDriver> &>(), py::arg("theMessageDriver"));
	cls_BinMDataStd_RealListDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDataStd_RealListDriver::*)() const ) &BinMDataStd_RealListDriver::NewEmpty, "None");
	cls_BinMDataStd_RealListDriver.def("Paste", (Standard_Boolean (BinMDataStd_RealListDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const ) &BinMDataStd_RealListDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataStd_RealListDriver.def("Paste", (void (BinMDataStd_RealListDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const ) &BinMDataStd_RealListDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataStd_RealListDriver.def_static("get_type_name_", (const char * (*)()) &BinMDataStd_RealListDriver::get_type_name, "None");
	cls_BinMDataStd_RealListDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDataStd_RealListDriver::get_type_descriptor, "None");
	cls_BinMDataStd_RealListDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDataStd_RealListDriver::*)() const ) &BinMDataStd_RealListDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinMDataStd_ExtStringListDriver.hxx
	py::class_<BinMDataStd_ExtStringListDriver, opencascade::handle<BinMDataStd_ExtStringListDriver>, BinMDF_ADriver> cls_BinMDataStd_ExtStringListDriver(mod, "BinMDataStd_ExtStringListDriver", "None");
	cls_BinMDataStd_ExtStringListDriver.def(py::init<const opencascade::handle<CDM_MessageDriver> &>(), py::arg("theMessageDriver"));
	cls_BinMDataStd_ExtStringListDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDataStd_ExtStringListDriver::*)() const ) &BinMDataStd_ExtStringListDriver::NewEmpty, "None");
	cls_BinMDataStd_ExtStringListDriver.def("Paste", (Standard_Boolean (BinMDataStd_ExtStringListDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const ) &BinMDataStd_ExtStringListDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataStd_ExtStringListDriver.def("Paste", (void (BinMDataStd_ExtStringListDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const ) &BinMDataStd_ExtStringListDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataStd_ExtStringListDriver.def_static("get_type_name_", (const char * (*)()) &BinMDataStd_ExtStringListDriver::get_type_name, "None");
	cls_BinMDataStd_ExtStringListDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDataStd_ExtStringListDriver::get_type_descriptor, "None");
	cls_BinMDataStd_ExtStringListDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDataStd_ExtStringListDriver::*)() const ) &BinMDataStd_ExtStringListDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinMDataStd_BooleanListDriver.hxx
	py::class_<BinMDataStd_BooleanListDriver, opencascade::handle<BinMDataStd_BooleanListDriver>, BinMDF_ADriver> cls_BinMDataStd_BooleanListDriver(mod, "BinMDataStd_BooleanListDriver", "None");
	cls_BinMDataStd_BooleanListDriver.def(py::init<const opencascade::handle<CDM_MessageDriver> &>(), py::arg("theMessageDriver"));
	cls_BinMDataStd_BooleanListDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDataStd_BooleanListDriver::*)() const ) &BinMDataStd_BooleanListDriver::NewEmpty, "None");
	cls_BinMDataStd_BooleanListDriver.def("Paste", (Standard_Boolean (BinMDataStd_BooleanListDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const ) &BinMDataStd_BooleanListDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataStd_BooleanListDriver.def("Paste", (void (BinMDataStd_BooleanListDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const ) &BinMDataStd_BooleanListDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataStd_BooleanListDriver.def_static("get_type_name_", (const char * (*)()) &BinMDataStd_BooleanListDriver::get_type_name, "None");
	cls_BinMDataStd_BooleanListDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDataStd_BooleanListDriver::get_type_descriptor, "None");
	cls_BinMDataStd_BooleanListDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDataStd_BooleanListDriver::*)() const ) &BinMDataStd_BooleanListDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinMDataStd_ReferenceListDriver.hxx
	py::class_<BinMDataStd_ReferenceListDriver, opencascade::handle<BinMDataStd_ReferenceListDriver>, BinMDF_ADriver> cls_BinMDataStd_ReferenceListDriver(mod, "BinMDataStd_ReferenceListDriver", "None");
	cls_BinMDataStd_ReferenceListDriver.def(py::init<const opencascade::handle<CDM_MessageDriver> &>(), py::arg("theMessageDriver"));
	cls_BinMDataStd_ReferenceListDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDataStd_ReferenceListDriver::*)() const ) &BinMDataStd_ReferenceListDriver::NewEmpty, "None");
	cls_BinMDataStd_ReferenceListDriver.def("Paste", (Standard_Boolean (BinMDataStd_ReferenceListDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const ) &BinMDataStd_ReferenceListDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataStd_ReferenceListDriver.def("Paste", (void (BinMDataStd_ReferenceListDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const ) &BinMDataStd_ReferenceListDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataStd_ReferenceListDriver.def_static("get_type_name_", (const char * (*)()) &BinMDataStd_ReferenceListDriver::get_type_name, "None");
	cls_BinMDataStd_ReferenceListDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDataStd_ReferenceListDriver::get_type_descriptor, "None");
	cls_BinMDataStd_ReferenceListDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDataStd_ReferenceListDriver::*)() const ) &BinMDataStd_ReferenceListDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinMDataStd_BooleanArrayDriver.hxx
	py::class_<BinMDataStd_BooleanArrayDriver, opencascade::handle<BinMDataStd_BooleanArrayDriver>, BinMDF_ADriver> cls_BinMDataStd_BooleanArrayDriver(mod, "BinMDataStd_BooleanArrayDriver", "None");
	cls_BinMDataStd_BooleanArrayDriver.def(py::init<const opencascade::handle<CDM_MessageDriver> &>(), py::arg("theMessageDriver"));
	cls_BinMDataStd_BooleanArrayDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDataStd_BooleanArrayDriver::*)() const ) &BinMDataStd_BooleanArrayDriver::NewEmpty, "None");
	cls_BinMDataStd_BooleanArrayDriver.def("Paste", (Standard_Boolean (BinMDataStd_BooleanArrayDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const ) &BinMDataStd_BooleanArrayDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataStd_BooleanArrayDriver.def("Paste", (void (BinMDataStd_BooleanArrayDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const ) &BinMDataStd_BooleanArrayDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataStd_BooleanArrayDriver.def_static("get_type_name_", (const char * (*)()) &BinMDataStd_BooleanArrayDriver::get_type_name, "None");
	cls_BinMDataStd_BooleanArrayDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDataStd_BooleanArrayDriver::get_type_descriptor, "None");
	cls_BinMDataStd_BooleanArrayDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDataStd_BooleanArrayDriver::*)() const ) &BinMDataStd_BooleanArrayDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinMDataStd_ReferenceArrayDriver.hxx
	py::class_<BinMDataStd_ReferenceArrayDriver, opencascade::handle<BinMDataStd_ReferenceArrayDriver>, BinMDF_ADriver> cls_BinMDataStd_ReferenceArrayDriver(mod, "BinMDataStd_ReferenceArrayDriver", "None");
	cls_BinMDataStd_ReferenceArrayDriver.def(py::init<const opencascade::handle<CDM_MessageDriver> &>(), py::arg("theMessageDriver"));
	cls_BinMDataStd_ReferenceArrayDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDataStd_ReferenceArrayDriver::*)() const ) &BinMDataStd_ReferenceArrayDriver::NewEmpty, "None");
	cls_BinMDataStd_ReferenceArrayDriver.def("Paste", (Standard_Boolean (BinMDataStd_ReferenceArrayDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const ) &BinMDataStd_ReferenceArrayDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataStd_ReferenceArrayDriver.def("Paste", (void (BinMDataStd_ReferenceArrayDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const ) &BinMDataStd_ReferenceArrayDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataStd_ReferenceArrayDriver.def_static("get_type_name_", (const char * (*)()) &BinMDataStd_ReferenceArrayDriver::get_type_name, "None");
	cls_BinMDataStd_ReferenceArrayDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDataStd_ReferenceArrayDriver::get_type_descriptor, "None");
	cls_BinMDataStd_ReferenceArrayDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDataStd_ReferenceArrayDriver::*)() const ) &BinMDataStd_ReferenceArrayDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinMDataStd_ByteArrayDriver.hxx
	py::class_<BinMDataStd_ByteArrayDriver, opencascade::handle<BinMDataStd_ByteArrayDriver>, BinMDF_ADriver> cls_BinMDataStd_ByteArrayDriver(mod, "BinMDataStd_ByteArrayDriver", "None");
	cls_BinMDataStd_ByteArrayDriver.def(py::init<const opencascade::handle<CDM_MessageDriver> &>(), py::arg("theMessageDriver"));
	cls_BinMDataStd_ByteArrayDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDataStd_ByteArrayDriver::*)() const ) &BinMDataStd_ByteArrayDriver::NewEmpty, "None");
	cls_BinMDataStd_ByteArrayDriver.def("Paste", (Standard_Boolean (BinMDataStd_ByteArrayDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const ) &BinMDataStd_ByteArrayDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataStd_ByteArrayDriver.def("Paste", (void (BinMDataStd_ByteArrayDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const ) &BinMDataStd_ByteArrayDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataStd_ByteArrayDriver.def_static("get_type_name_", (const char * (*)()) &BinMDataStd_ByteArrayDriver::get_type_name, "None");
	cls_BinMDataStd_ByteArrayDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDataStd_ByteArrayDriver::get_type_descriptor, "None");
	cls_BinMDataStd_ByteArrayDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDataStd_ByteArrayDriver::*)() const ) &BinMDataStd_ByteArrayDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinMDataStd_NamedDataDriver.hxx
	py::class_<BinMDataStd_NamedDataDriver, opencascade::handle<BinMDataStd_NamedDataDriver>, BinMDF_ADriver> cls_BinMDataStd_NamedDataDriver(mod, "BinMDataStd_NamedDataDriver", "None");
	cls_BinMDataStd_NamedDataDriver.def(py::init<const opencascade::handle<CDM_MessageDriver> &>(), py::arg("theMessageDriver"));
	cls_BinMDataStd_NamedDataDriver.def("NewEmpty", (opencascade::handle<TDF_Attribute> (BinMDataStd_NamedDataDriver::*)() const ) &BinMDataStd_NamedDataDriver::NewEmpty, "None");
	cls_BinMDataStd_NamedDataDriver.def("Paste", (Standard_Boolean (BinMDataStd_NamedDataDriver::*)(const BinObjMgt_Persistent &, const opencascade::handle<TDF_Attribute> &, BinObjMgt_RRelocationTable &) const ) &BinMDataStd_NamedDataDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataStd_NamedDataDriver.def("Paste", (void (BinMDataStd_NamedDataDriver::*)(const opencascade::handle<TDF_Attribute> &, BinObjMgt_Persistent &, BinObjMgt_SRelocationTable &) const ) &BinMDataStd_NamedDataDriver::Paste, "None", py::arg("Source"), py::arg("Target"), py::arg("RelocTable"));
	cls_BinMDataStd_NamedDataDriver.def_static("get_type_name_", (const char * (*)()) &BinMDataStd_NamedDataDriver::get_type_name, "None");
	cls_BinMDataStd_NamedDataDriver.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BinMDataStd_NamedDataDriver::get_type_descriptor, "None");
	cls_BinMDataStd_NamedDataDriver.def("DynamicType", (const opencascade::handle<Standard_Type> & (BinMDataStd_NamedDataDriver::*)() const ) &BinMDataStd_NamedDataDriver::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BinMDataStd.hxx
	py::class_<BinMDataStd, std::unique_ptr<BinMDataStd, Deleter<BinMDataStd>>> cls_BinMDataStd(mod, "BinMDataStd", "Storage and Retrieval drivers for modelling attributes.");
	cls_BinMDataStd.def(py::init<>());
	cls_BinMDataStd.def_static("AddDrivers_", (void (*)(const opencascade::handle<BinMDF_ADriverTable> &, const opencascade::handle<CDM_MessageDriver> &)) &BinMDataStd::AddDrivers, "Adds the attribute drivers to <theDriverTable>.", py::arg("theDriverTable"), py::arg("aMsgDrv"));
	cls_BinMDataStd.def_static("SetDocumentVersion_", (void (*)(const Standard_Integer)) &BinMDataStd::SetDocumentVersion, "None", py::arg("DocVersion"));
	cls_BinMDataStd.def_static("DocumentVersion_", (Standard_Integer (*)()) &BinMDataStd::DocumentVersion, "None");


}
