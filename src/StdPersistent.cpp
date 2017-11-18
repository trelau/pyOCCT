#include <pyOCCT_Common.hpp>

#include <StdPersistent_TopoDS.hxx>
#include <NCollection_Array1.hxx>
#include <StdObject_Shape.hxx>
#include <Standard_Transient.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_Type.hxx>
#include <StdPersistent_HArray1.hxx>
#include <StdObjMgt_MapOfInstantiators.hxx>
#include <StdPersistent.hxx>
#include <StdPersistent_DataXtd.hxx>
#include <StdObjMgt_Attribute.hxx>
#include <TDataXtd_Constraint.hxx>
#include <StdObjMgt_ReadData.hxx>
#include <StdObjMgt_WriteData.hxx>
#include <StdObjMgt_Persistent.hxx>
#include <StdPersistent_DataXtd_Constraint.hxx>
#include <TDataXtd_PatternStd.hxx>
#include <StdPersistent_DataXtd_PatternStd.hxx>
#include <StdPersistent_Naming.hxx>
#include <StdPersistent_PPrsStd.hxx>
#include <StdPersistent_TopLoc.hxx>
#include <TopLoc_Location.hxx>
#include <StdObjMgt_TransientPersistentMap.hxx>
#include <TopLoc_Datum3D.hxx>

PYBIND11_MODULE(StdPersistent, mod) {

	// IMPORT
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.StdObject");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.StdObjMgt");
	py::module::import("OCCT.TDataXtd");
	py::module::import("OCCT.TopLoc");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\StdPersistent_TopoDS.hxx
	py::class_<StdPersistent_TopoDS, std::unique_ptr<StdPersistent_TopoDS, Deleter<StdPersistent_TopoDS>>> cls_StdPersistent_TopoDS(mod, "StdPersistent_TopoDS", "None");
	cls_StdPersistent_TopoDS.def(py::init<>());

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\StdPersistent_HArray1.hxx
	py::class_<StdPersistent_HArray1OfShape1, opencascade::handle<StdPersistent_HArray1OfShape1>, NCollection_Array1<StdObject_Shape>, Standard_Transient> cls_StdPersistent_HArray1OfShape1(mod, "StdPersistent_HArray1OfShape1", "None");
	cls_StdPersistent_HArray1OfShape1.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StdPersistent_HArray1OfShape1.def(py::init<const Standard_Integer, const Standard_Integer, const NCollection_Array1<StdObject_Shape>::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_StdPersistent_HArray1OfShape1.def(py::init<const NCollection_Array1<StdObject_Shape> &>(), py::arg("theOther"));
	cls_StdPersistent_HArray1OfShape1.def("Array1", (const NCollection_Array1<StdObject_Shape> & (StdPersistent_HArray1OfShape1::*)() const ) &StdPersistent_HArray1OfShape1::Array1, "None");
	cls_StdPersistent_HArray1OfShape1.def("ChangeArray1", (NCollection_Array1<StdObject_Shape> & (StdPersistent_HArray1OfShape1::*)()) &StdPersistent_HArray1OfShape1::ChangeArray1, "None");
	cls_StdPersistent_HArray1OfShape1.def_static("get_type_name_", (const char * (*)()) &StdPersistent_HArray1OfShape1::get_type_name, "None");
	cls_StdPersistent_HArray1OfShape1.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StdPersistent_HArray1OfShape1::get_type_descriptor, "None");
	cls_StdPersistent_HArray1OfShape1.def("DynamicType", (const opencascade::handle<Standard_Type> & (StdPersistent_HArray1OfShape1::*)() const ) &StdPersistent_HArray1OfShape1::DynamicType, "None");
	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\StdPersistent_HArray1.hxx
	py::class_<StdPersistent_HArray1, std::unique_ptr<StdPersistent_HArray1, Deleter<StdPersistent_HArray1>>> cls_StdPersistent_HArray1(mod, "StdPersistent_HArray1", "None");
	cls_StdPersistent_HArray1.def(py::init<>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\StdPersistent.hxx
	py::class_<StdPersistent, std::unique_ptr<StdPersistent, Deleter<StdPersistent>>> cls_StdPersistent(mod, "StdPersistent", "None");
	cls_StdPersistent.def(py::init<>());
	cls_StdPersistent.def_static("BindTypes_", (void (*)(StdObjMgt_MapOfInstantiators &)) &StdPersistent::BindTypes, "Register types.", py::arg("theMap"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\StdPersistent_DataXtd.hxx
	py::class_<StdPersistent_DataXtd, std::unique_ptr<StdPersistent_DataXtd, Deleter<StdPersistent_DataXtd>>> cls_StdPersistent_DataXtd(mod, "StdPersistent_DataXtd", "None");
	cls_StdPersistent_DataXtd.def(py::init<>());

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\StdPersistent_DataXtd_Constraint.hxx
	py::class_<StdPersistent_DataXtd_Constraint, std::unique_ptr<StdPersistent_DataXtd_Constraint, Deleter<StdPersistent_DataXtd_Constraint>>, StdObjMgt_Attribute<TDataXtd_Constraint>> cls_StdPersistent_DataXtd_Constraint(mod, "StdPersistent_DataXtd_Constraint", "None");
	cls_StdPersistent_DataXtd_Constraint.def(py::init<>());
	cls_StdPersistent_DataXtd_Constraint.def("Read", (void (StdPersistent_DataXtd_Constraint::*)(StdObjMgt_ReadData &)) &StdPersistent_DataXtd_Constraint::Read, "Read persistent data from a file.", py::arg("theReadData"));
	cls_StdPersistent_DataXtd_Constraint.def("Write", (void (StdPersistent_DataXtd_Constraint::*)(StdObjMgt_WriteData &) const ) &StdPersistent_DataXtd_Constraint::Write, "Write persistent data to a file.", py::arg("theWriteData"));
	cls_StdPersistent_DataXtd_Constraint.def("PChildren", (void (StdPersistent_DataXtd_Constraint::*)(StdObjMgt_Persistent::SequenceOfPersistent &) const ) &StdPersistent_DataXtd_Constraint::PChildren, "Gets persistent child objects", py::arg("theChildren"));
	cls_StdPersistent_DataXtd_Constraint.def("PName", (Standard_CString (StdPersistent_DataXtd_Constraint::*)() const ) &StdPersistent_DataXtd_Constraint::PName, "Returns persistent type name");
	cls_StdPersistent_DataXtd_Constraint.def("Import", (void (StdPersistent_DataXtd_Constraint::*)(const opencascade::handle<TDataXtd_Constraint> &) const ) &StdPersistent_DataXtd_Constraint::Import, "Import transient attribuite from the persistent data.", py::arg("theAttribute"));
	*/

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\StdPersistent_DataXtd_PatternStd.hxx
	py::class_<StdPersistent_DataXtd_PatternStd, std::unique_ptr<StdPersistent_DataXtd_PatternStd, Deleter<StdPersistent_DataXtd_PatternStd>>, StdObjMgt_Attribute<TDataXtd_PatternStd>> cls_StdPersistent_DataXtd_PatternStd(mod, "StdPersistent_DataXtd_PatternStd", "None");
	cls_StdPersistent_DataXtd_PatternStd.def(py::init<>());
	cls_StdPersistent_DataXtd_PatternStd.def("Read", (void (StdPersistent_DataXtd_PatternStd::*)(StdObjMgt_ReadData &)) &StdPersistent_DataXtd_PatternStd::Read, "Read persistent data from a file.", py::arg("theReadData"));
	cls_StdPersistent_DataXtd_PatternStd.def("Write", (void (StdPersistent_DataXtd_PatternStd::*)(StdObjMgt_WriteData &)) &StdPersistent_DataXtd_PatternStd::Write, "Write persistent data to a file.", py::arg("theWriteData"));
	cls_StdPersistent_DataXtd_PatternStd.def("PChildren", (void (StdPersistent_DataXtd_PatternStd::*)(StdObjMgt_Persistent::SequenceOfPersistent &) const ) &StdPersistent_DataXtd_PatternStd::PChildren, "Gets persistent child objects", py::arg("theChildren"));
	cls_StdPersistent_DataXtd_PatternStd.def("PName", (Standard_CString (StdPersistent_DataXtd_PatternStd::*)() const ) &StdPersistent_DataXtd_PatternStd::PName, "Returns persistent type name");
	cls_StdPersistent_DataXtd_PatternStd.def("Import", (void (StdPersistent_DataXtd_PatternStd::*)(const opencascade::handle<TDataXtd_PatternStd> &) const ) &StdPersistent_DataXtd_PatternStd::Import, "Import transient attribuite from the persistent data.", py::arg("theAttribute"));
	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\StdPersistent_Naming.hxx
	py::class_<StdPersistent_Naming, std::unique_ptr<StdPersistent_Naming, Deleter<StdPersistent_Naming>>> cls_StdPersistent_Naming(mod, "StdPersistent_Naming", "None");
	cls_StdPersistent_Naming.def(py::init<>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\StdPersistent_PPrsStd.hxx
	py::class_<StdPersistent_PPrsStd, std::unique_ptr<StdPersistent_PPrsStd, Deleter<StdPersistent_PPrsStd>>> cls_StdPersistent_PPrsStd(mod, "StdPersistent_PPrsStd", "None");
	cls_StdPersistent_PPrsStd.def(py::init<>());

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\StdPersistent_TopLoc.hxx
	py::class_<StdPersistent_TopLoc, std::unique_ptr<StdPersistent_TopLoc, Deleter<StdPersistent_TopLoc>>> cls_StdPersistent_TopLoc(mod, "StdPersistent_TopLoc", "None");
	cls_StdPersistent_TopLoc.def(py::init<>());
	cls_StdPersistent_TopLoc.def_static("Translate_", (opencascade::handle<ItemLocation> (*)(const TopLoc_Location &, StdObjMgt_TransientPersistentMap &)) &StdPersistent_TopLoc::Translate, "None", py::arg("theLoc"), py::arg("theMap"));
	cls_StdPersistent_TopLoc.def_static("Translate_", (opencascade::handle<Datum3D> (*)(const opencascade::handle<TopLoc_Datum3D> &, StdObjMgt_TransientPersistentMap &)) &StdPersistent_TopLoc::Translate, "None", py::arg("theDatum"), py::arg("theMap"));
	*/


}
