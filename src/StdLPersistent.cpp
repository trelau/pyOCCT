#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <NCollection_Array1.hxx>
#include <Standard_Handle.hxx>
#include <StdObjMgt_Persistent.hxx>
#include <Standard_Transient.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_Type.hxx>
#include <StdLPersistent_HArray1.hxx>
#include <StdObjMgt_WriteData.hxx>
#include <NCollection_Array2.hxx>
#include <StdLPersistent_HArray2.hxx>
#include <StdObjMgt_MapOfInstantiators.hxx>
#include <StdLPersistent.hxx>
#include <StdLPersistent_Collection.hxx>
#include <StdObjMgt_ReadData.hxx>
#include <TDF_Data.hxx>
#include <StdLPersistent_Data.hxx>
#include <StdLPersistent_HString.hxx>
#include <StdLPersistent_Dependency.hxx>
#include <TDocStd_Document.hxx>
#include <StdLPersistent_Document.hxx>
#include <StdObjMgt_Attribute.hxx>
#include <TFunction_Function.hxx>
#include <StdLPersistent_Function.hxx>
#include <TDataStd_NamedData.hxx>
#include <StdLPersistent_NamedData.hxx>
#include <TDataStd_Real.hxx>
#include <StdLPersistent_Real.hxx>
#include <TDF_Attribute.hxx>
#include <StdLPersistent_TreeNode.hxx>
#include <StdLPersistent_Value.hxx>
#include <TDataStd_Variable.hxx>
#include <StdLPersistent_Variable.hxx>
#include <StdLPersistent_Void.hxx>
#include <TDocStd_XLink.hxx>
#include <StdLPersistent_XLink.hxx>

PYBIND11_MODULE(StdLPersistent, mod) {

	// IMPORT
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.StdObjMgt");
	py::module::import("OCCT.TDF");
	py::module::import("OCCT.TDocStd");
	py::module::import("OCCT.TFunction");
	py::module::import("OCCT.TDataStd");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS
	// C:\Miniconda\envs\occt\Library\include\opencascade\StdLPersistent_HArray1.hxx
	mod.def("operator>>", (StdObjMgt_WriteData & (*)(StdObjMgt_WriteData &, const Standard_Byte &)) &operator>>, "None", py::arg("theWriteData"), py::arg("theByte"));


	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\StdLPersistent_HArray1.hxx
	py::class_<StdLPersistent_HArray1OfPersistent, opencascade::handle<StdLPersistent_HArray1OfPersistent>, NCollection_Array1<opencascade::handle<StdObjMgt_Persistent> >, Standard_Transient> cls_StdLPersistent_HArray1OfPersistent(mod, "StdLPersistent_HArray1OfPersistent", "None");
	cls_StdLPersistent_HArray1OfPersistent.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StdLPersistent_HArray1OfPersistent.def(py::init<const Standard_Integer, const Standard_Integer, const NCollection_Array1<opencascade::handle<StdObjMgt_Persistent> >::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_StdLPersistent_HArray1OfPersistent.def(py::init<const NCollection_Array1<opencascade::handle<StdObjMgt_Persistent> > &>(), py::arg("theOther"));
	cls_StdLPersistent_HArray1OfPersistent.def("Array1", (const NCollection_Array1<opencascade::handle<StdObjMgt_Persistent> > & (StdLPersistent_HArray1OfPersistent::*)() const ) &StdLPersistent_HArray1OfPersistent::Array1, "None");
	cls_StdLPersistent_HArray1OfPersistent.def("ChangeArray1", (NCollection_Array1<opencascade::handle<StdObjMgt_Persistent> > & (StdLPersistent_HArray1OfPersistent::*)()) &StdLPersistent_HArray1OfPersistent::ChangeArray1, "None");
	cls_StdLPersistent_HArray1OfPersistent.def_static("get_type_name_", (const char * (*)()) &StdLPersistent_HArray1OfPersistent::get_type_name, "None");
	cls_StdLPersistent_HArray1OfPersistent.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StdLPersistent_HArray1OfPersistent::get_type_descriptor, "None");
	cls_StdLPersistent_HArray1OfPersistent.def("DynamicType", (const opencascade::handle<Standard_Type> & (StdLPersistent_HArray1OfPersistent::*)() const ) &StdLPersistent_HArray1OfPersistent::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StdLPersistent_HArray1.hxx
	py::class_<StdLPersistent_HArray1, std::unique_ptr<StdLPersistent_HArray1, Deleter<StdLPersistent_HArray1>>> cls_StdLPersistent_HArray1(mod, "StdLPersistent_HArray1", "None");
	cls_StdLPersistent_HArray1.def(py::init<>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\StdLPersistent_HArray2.hxx
	py::class_<StdLPersistent_HArray2OfPersistent, opencascade::handle<StdLPersistent_HArray2OfPersistent>, NCollection_Array2<opencascade::handle<StdObjMgt_Persistent> >, Standard_Transient> cls_StdLPersistent_HArray2OfPersistent(mod, "StdLPersistent_HArray2OfPersistent", "None");
	cls_StdLPersistent_HArray2OfPersistent.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"));
	cls_StdLPersistent_HArray2OfPersistent.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const NCollection_Array2<opencascade::handle<StdObjMgt_Persistent> >::value_type &>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"), py::arg("theValue"));
	cls_StdLPersistent_HArray2OfPersistent.def(py::init<const NCollection_Array2<opencascade::handle<StdObjMgt_Persistent> > &>(), py::arg("theOther"));
	cls_StdLPersistent_HArray2OfPersistent.def("Array2", (const NCollection_Array2<opencascade::handle<StdObjMgt_Persistent> > & (StdLPersistent_HArray2OfPersistent::*)() const ) &StdLPersistent_HArray2OfPersistent::Array2, "None");
	cls_StdLPersistent_HArray2OfPersistent.def("ChangeArray2", (NCollection_Array2<opencascade::handle<StdObjMgt_Persistent> > & (StdLPersistent_HArray2OfPersistent::*)()) &StdLPersistent_HArray2OfPersistent::ChangeArray2, "None");
	cls_StdLPersistent_HArray2OfPersistent.def_static("get_type_name_", (const char * (*)()) &StdLPersistent_HArray2OfPersistent::get_type_name, "None");
	cls_StdLPersistent_HArray2OfPersistent.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StdLPersistent_HArray2OfPersistent::get_type_descriptor, "None");
	cls_StdLPersistent_HArray2OfPersistent.def("DynamicType", (const opencascade::handle<Standard_Type> & (StdLPersistent_HArray2OfPersistent::*)() const ) &StdLPersistent_HArray2OfPersistent::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StdLPersistent_HArray2.hxx
	py::class_<StdLPersistent_HArray2, std::unique_ptr<StdLPersistent_HArray2, Deleter<StdLPersistent_HArray2>>> cls_StdLPersistent_HArray2(mod, "StdLPersistent_HArray2", "None");
	cls_StdLPersistent_HArray2.def(py::init<>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\StdLPersistent.hxx
	py::class_<StdLPersistent, std::unique_ptr<StdLPersistent, Deleter<StdLPersistent>>> cls_StdLPersistent(mod, "StdLPersistent", "None");
	cls_StdLPersistent.def(py::init<>());
	cls_StdLPersistent.def_static("BindTypes_", (void (*)(StdObjMgt_MapOfInstantiators &)) &StdLPersistent::BindTypes, "Register types.", py::arg("theMap"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\StdLPersistent_Collection.hxx
	py::class_<StdLPersistent_Collection, std::unique_ptr<StdLPersistent_Collection, Deleter<StdLPersistent_Collection>>> cls_StdLPersistent_Collection(mod, "StdLPersistent_Collection", "None");
	cls_StdLPersistent_Collection.def(py::init<>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\StdLPersistent_Data.hxx
	py::class_<StdLPersistent_Data, opencascade::handle<StdLPersistent_Data>, StdObjMgt_Persistent> cls_StdLPersistent_Data(mod, "StdLPersistent_Data", "None");
	cls_StdLPersistent_Data.def("Read", (void (StdLPersistent_Data::*)(StdObjMgt_ReadData &)) &StdLPersistent_Data::Read, "Read persistent data from a file.", py::arg("theReadData"));
	cls_StdLPersistent_Data.def("Write", (void (StdLPersistent_Data::*)(StdObjMgt_WriteData &) const ) &StdLPersistent_Data::Write, "Write persistent data to a file.", py::arg("theWriteData"));
	cls_StdLPersistent_Data.def("PChildren", (void (StdLPersistent_Data::*)(StdObjMgt_Persistent::SequenceOfPersistent &) const ) &StdLPersistent_Data::PChildren, "Gets persistent child objects", py::arg("theChildren"));
	cls_StdLPersistent_Data.def("PName", (Standard_CString (StdLPersistent_Data::*)() const ) &StdLPersistent_Data::PName, "Returns persistent type name");
	cls_StdLPersistent_Data.def("Import", (opencascade::handle<TDF_Data> (StdLPersistent_Data::*)() const ) &StdLPersistent_Data::Import, "Import transient data from the persistent data.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StdLPersistent_HString.hxx
	py::class_<StdLPersistent_HString, std::unique_ptr<StdLPersistent_HString, Deleter<StdLPersistent_HString>>> cls_StdLPersistent_HString(mod, "StdLPersistent_HString", "None");
	cls_StdLPersistent_HString.def(py::init<>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\StdLPersistent_Dependency.hxx
	py::class_<StdLPersistent_Dependency, std::unique_ptr<StdLPersistent_Dependency, Deleter<StdLPersistent_Dependency>>> cls_StdLPersistent_Dependency(mod, "StdLPersistent_Dependency", "None");
	cls_StdLPersistent_Dependency.def(py::init<>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\StdLPersistent_Document.hxx
	py::class_<StdLPersistent_Document, opencascade::handle<StdLPersistent_Document>, StdObjMgt_Persistent> cls_StdLPersistent_Document(mod, "StdLPersistent_Document", "None");
	cls_StdLPersistent_Document.def("Read", (void (StdLPersistent_Document::*)(StdObjMgt_ReadData &)) &StdLPersistent_Document::Read, "Read persistent data from a file.", py::arg("theReadData"));
	cls_StdLPersistent_Document.def("Write", (void (StdLPersistent_Document::*)(StdObjMgt_WriteData &) const ) &StdLPersistent_Document::Write, "Read persistent data from a file.", py::arg("theWriteData"));
	cls_StdLPersistent_Document.def("PChildren", (void (StdLPersistent_Document::*)(StdObjMgt_Persistent::SequenceOfPersistent &) const ) &StdLPersistent_Document::PChildren, "Gets persistent child objects", py::arg(""));
	cls_StdLPersistent_Document.def("PName", (Standard_CString (StdLPersistent_Document::*)() const ) &StdLPersistent_Document::PName, "Returns persistent type name");
	cls_StdLPersistent_Document.def("ImportDocument", (void (StdLPersistent_Document::*)(const opencascade::handle<TDocStd_Document> &) const ) &StdLPersistent_Document::ImportDocument, "Import transient document from the persistent data.", py::arg("theDocument"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\StdLPersistent_Function.hxx
	py::class_<StdLPersistent_Function, std::unique_ptr<StdLPersistent_Function, Deleter<StdLPersistent_Function>>, StdObjMgt_Attribute<TFunction_Function>> cls_StdLPersistent_Function(mod, "StdLPersistent_Function", "None");
	cls_StdLPersistent_Function.def(py::init<>());
	cls_StdLPersistent_Function.def("Read", (void (StdLPersistent_Function::*)(StdObjMgt_ReadData &)) &StdLPersistent_Function::Read, "Read persistent data from a file.", py::arg("theReadData"));
	cls_StdLPersistent_Function.def("Write", (void (StdLPersistent_Function::*)(StdObjMgt_WriteData &) const ) &StdLPersistent_Function::Write, "Write persistent data to a file.", py::arg("theWriteData"));
	cls_StdLPersistent_Function.def("PChildren", (void (StdLPersistent_Function::*)(StdObjMgt_Persistent::SequenceOfPersistent &) const ) &StdLPersistent_Function::PChildren, "Gets persistent child objects", py::arg(""));
	cls_StdLPersistent_Function.def("PName", (Standard_CString (StdLPersistent_Function::*)() const ) &StdLPersistent_Function::PName, "Returns persistent type name");
	cls_StdLPersistent_Function.def("Import", (void (StdLPersistent_Function::*)(const opencascade::handle<TFunction_Function> &) const ) &StdLPersistent_Function::Import, "Import transient attribuite from the persistent data.", py::arg("theAttribute"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\StdLPersistent_NamedData.hxx
	py::class_<StdLPersistent_NamedData, std::unique_ptr<StdLPersistent_NamedData, Deleter<StdLPersistent_NamedData>>, StdObjMgt_Attribute<TDataStd_NamedData>> cls_StdLPersistent_NamedData(mod, "StdLPersistent_NamedData", "None");
	cls_StdLPersistent_NamedData.def(py::init<>());
	cls_StdLPersistent_NamedData.def("Read", (void (StdLPersistent_NamedData::*)(StdObjMgt_ReadData &)) &StdLPersistent_NamedData::Read, "Read persistent data from a file.", py::arg("theReadData"));
	cls_StdLPersistent_NamedData.def("Write", (void (StdLPersistent_NamedData::*)(StdObjMgt_WriteData &) const ) &StdLPersistent_NamedData::Write, "Write persistent data to a file.", py::arg("theWriteData"));
	cls_StdLPersistent_NamedData.def("PChildren", (void (StdLPersistent_NamedData::*)(StdObjMgt_Persistent::SequenceOfPersistent &) const ) &StdLPersistent_NamedData::PChildren, "Gets persistent child objects", py::arg(""));
	cls_StdLPersistent_NamedData.def("PName", (Standard_CString (StdLPersistent_NamedData::*)() const ) &StdLPersistent_NamedData::PName, "Returns persistent type name");
	cls_StdLPersistent_NamedData.def("Import", (void (StdLPersistent_NamedData::*)(const opencascade::handle<TDataStd_NamedData> &) const ) &StdLPersistent_NamedData::Import, "Import transient attribuite from the persistent data.", py::arg("theAttribute"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\StdLPersistent_Real.hxx
	py::class_<StdLPersistent_Real, std::unique_ptr<StdLPersistent_Real, Deleter<StdLPersistent_Real>>, StdObjMgt_Attribute<TDataStd_Real>> cls_StdLPersistent_Real(mod, "StdLPersistent_Real", "None");
	cls_StdLPersistent_Real.def(py::init<>());
	cls_StdLPersistent_Real.def("Read", (void (StdLPersistent_Real::*)(StdObjMgt_ReadData &)) &StdLPersistent_Real::Read, "Read persistent data from a file.", py::arg("theReadData"));
	cls_StdLPersistent_Real.def("Write", (void (StdLPersistent_Real::*)(StdObjMgt_WriteData &) const ) &StdLPersistent_Real::Write, "Write persistent data from a file.", py::arg("theWriteData"));
	cls_StdLPersistent_Real.def("PChildren", (void (StdLPersistent_Real::*)(StdObjMgt_Persistent::SequenceOfPersistent &) const ) &StdLPersistent_Real::PChildren, "Gets persistent child objects", py::arg(""));
	cls_StdLPersistent_Real.def("PName", (Standard_CString (StdLPersistent_Real::*)() const ) &StdLPersistent_Real::PName, "Returns persistent type name");
	cls_StdLPersistent_Real.def("Import", (void (StdLPersistent_Real::*)(const opencascade::handle<TDataStd_Real> &) const ) &StdLPersistent_Real::Import, "Import transient attribuite from the persistent data.", py::arg("theAttribute"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\StdLPersistent_TreeNode.hxx
	py::class_<StdLPersistent_TreeNode, opencascade::handle<StdLPersistent_TreeNode>> cls_StdLPersistent_TreeNode(mod, "StdLPersistent_TreeNode", "None");
	cls_StdLPersistent_TreeNode.def("Read", (void (StdLPersistent_TreeNode::*)(StdObjMgt_ReadData &)) &StdLPersistent_TreeNode::Read, "Read persistent data from a file.", py::arg("theReadData"));
	cls_StdLPersistent_TreeNode.def("Write", (void (StdLPersistent_TreeNode::*)(StdObjMgt_WriteData &) const ) &StdLPersistent_TreeNode::Write, "Write persistent data to a file.", py::arg("theWriteData"));
	cls_StdLPersistent_TreeNode.def("PChildren", (void (StdLPersistent_TreeNode::*)(StdObjMgt_Persistent::SequenceOfPersistent &) const ) &StdLPersistent_TreeNode::PChildren, "Gets persistent child objects", py::arg(""));
	cls_StdLPersistent_TreeNode.def("PName", (Standard_CString (StdLPersistent_TreeNode::*)() const ) &StdLPersistent_TreeNode::PName, "Returns persistent type name");
	cls_StdLPersistent_TreeNode.def("CreateAttribute", (opencascade::handle<TDF_Attribute> (StdLPersistent_TreeNode::*)()) &StdLPersistent_TreeNode::CreateAttribute, "Create an empty transient attribuite");
	cls_StdLPersistent_TreeNode.def("ImportAttribute", (void (StdLPersistent_TreeNode::*)()) &StdLPersistent_TreeNode::ImportAttribute, "Import transient attribuite from the persistent data.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StdLPersistent_Value.hxx
	py::class_<StdLPersistent_Value, std::unique_ptr<StdLPersistent_Value, Deleter<StdLPersistent_Value>>> cls_StdLPersistent_Value(mod, "StdLPersistent_Value", "None");
	cls_StdLPersistent_Value.def(py::init<>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\StdLPersistent_Variable.hxx
	py::class_<StdLPersistent_Variable, std::unique_ptr<StdLPersistent_Variable, Deleter<StdLPersistent_Variable>>, StdObjMgt_Attribute<TDataStd_Variable>> cls_StdLPersistent_Variable(mod, "StdLPersistent_Variable", "None");
	cls_StdLPersistent_Variable.def(py::init<>());
	cls_StdLPersistent_Variable.def("Read", (void (StdLPersistent_Variable::*)(StdObjMgt_ReadData &)) &StdLPersistent_Variable::Read, "Read persistent data from a file.", py::arg("theReadData"));
	cls_StdLPersistent_Variable.def("Write", (void (StdLPersistent_Variable::*)(StdObjMgt_WriteData &) const ) &StdLPersistent_Variable::Write, "Write persistent data to a file.", py::arg("theWriteData"));
	cls_StdLPersistent_Variable.def("PChildren", (void (StdLPersistent_Variable::*)(StdObjMgt_Persistent::SequenceOfPersistent &) const ) &StdLPersistent_Variable::PChildren, "Gets persistent child objects", py::arg("theChildren"));
	cls_StdLPersistent_Variable.def("PName", (Standard_CString (StdLPersistent_Variable::*)() const ) &StdLPersistent_Variable::PName, "Returns persistent type name");
	cls_StdLPersistent_Variable.def("Import", (void (StdLPersistent_Variable::*)(const opencascade::handle<TDataStd_Variable> &) const ) &StdLPersistent_Variable::Import, "Import transient attribuite from the persistent data.", py::arg("theAttribute"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\StdLPersistent_Void.hxx
	py::class_<StdLPersistent_Void, std::unique_ptr<StdLPersistent_Void, Deleter<StdLPersistent_Void>>> cls_StdLPersistent_Void(mod, "StdLPersistent_Void", "None");
	cls_StdLPersistent_Void.def(py::init<>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\StdLPersistent_XLink.hxx
	py::class_<StdLPersistent_XLink, std::unique_ptr<StdLPersistent_XLink, Deleter<StdLPersistent_XLink>>, StdObjMgt_Attribute<TDocStd_XLink>> cls_StdLPersistent_XLink(mod, "StdLPersistent_XLink", "None");
	cls_StdLPersistent_XLink.def(py::init<>());
	cls_StdLPersistent_XLink.def("Read", (void (StdLPersistent_XLink::*)(StdObjMgt_ReadData &)) &StdLPersistent_XLink::Read, "Read persistent data from a file.", py::arg("theReadData"));
	cls_StdLPersistent_XLink.def("Write", (void (StdLPersistent_XLink::*)(StdObjMgt_WriteData &) const ) &StdLPersistent_XLink::Write, "Write persistent data to a file.", py::arg("theWriteData"));
	cls_StdLPersistent_XLink.def("PChildren", (void (StdLPersistent_XLink::*)(StdObjMgt_Persistent::SequenceOfPersistent &) const ) &StdLPersistent_XLink::PChildren, "Gets persistent child objects", py::arg("theChildren"));
	cls_StdLPersistent_XLink.def("PName", (Standard_CString (StdLPersistent_XLink::*)() const ) &StdLPersistent_XLink::PName, "Returns persistent type name");
	cls_StdLPersistent_XLink.def("Import", (void (StdLPersistent_XLink::*)(const opencascade::handle<TDocStd_XLink> &) const ) &StdLPersistent_XLink::Import, "Import transient attribuite from the persistent data.", py::arg("theAttribute"));


}
