#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <NCollection_DataMap.hxx>
#include <TCollection_AsciiString.hxx>
#include <StdObjMgt_Persistent.hxx>
#include <StdObjMgt_MapOfInstantiators.hxx>
#include <Storage_BaseDriver.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <StdObjMgt_ReadData.hxx>
#include <StdObjMgt_WriteData.hxx>
#include <Standard_Transient.hxx>
#include <TDocStd_Document.hxx>
#include <TDF_Attribute.hxx>
#include <TCollection_HAsciiString.hxx>
#include <TCollection_HExtendedString.hxx>
#include <TDF_Label.hxx>
#include <TDF_Data.hxx>
#include <StdObjMgt_SharedObject.hxx>
#include <Standard_GUID.hxx>
#include <NCollection_BaseMap.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <StdObjMgt_TransientPersistentMap.hxx>

PYBIND11_MODULE(StdObjMgt, mod) {

	// IMPORT
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.TCollection");
	py::module::import("OCCT.Storage");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.TDocStd");
	py::module::import("OCCT.TDF");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS
	// C:\Miniconda\envs\occt\Library\include\opencascade\StdObjMgt_ReadData.hxx
	mod.def("operator>>", (StdObjMgt_ReadData & (*)(StdObjMgt_ReadData::Object, Standard_GUID &)) &operator>>, "None", py::arg("theReadData"), py::arg("theGUID"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\StdObjMgt_WriteData.hxx
	mod.def("operator<<", (StdObjMgt_WriteData & (*)(StdObjMgt_WriteData::Object, const Standard_GUID &)) &operator<<, "None", py::arg("theWriteData"), py::arg("theGUID"));


	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\StdObjMgt_MapOfInstantiators.hxx
	py::class_<StdObjMgt_MapOfInstantiators, std::unique_ptr<StdObjMgt_MapOfInstantiators, Deleter<StdObjMgt_MapOfInstantiators>>, NCollection_DataMap<TCollection_AsciiString, StdObjMgt_Persistent::Instantiator, TCollection_AsciiString>> cls_StdObjMgt_MapOfInstantiators(mod, "StdObjMgt_MapOfInstantiators", "None");
	cls_StdObjMgt_MapOfInstantiators.def(py::init<>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\StdObjMgt_ReadData.hxx
	py::class_<StdObjMgt_ReadData, std::unique_ptr<StdObjMgt_ReadData, Deleter<StdObjMgt_ReadData>>> cls_StdObjMgt_ReadData(mod, "StdObjMgt_ReadData", "Auxiliary data used to read persistent objects from a file.");
	cls_StdObjMgt_ReadData.def(py::init<Storage_BaseDriver &, const Standard_Integer>(), py::arg("theDriver"), py::arg("theNumberOfObjects"));
	cls_StdObjMgt_ReadData.def("ReadPersistentObject", (void (StdObjMgt_ReadData::*)(const Standard_Integer)) &StdObjMgt_ReadData::ReadPersistentObject, "None", py::arg("theRef"));
	cls_StdObjMgt_ReadData.def("PersistentObject", (opencascade::handle<StdObjMgt_Persistent> (StdObjMgt_ReadData::*)(const Standard_Integer) const ) &StdObjMgt_ReadData::PersistentObject, "None", py::arg("theRef"));
	cls_StdObjMgt_ReadData.def("ReadReference", (opencascade::handle<StdObjMgt_Persistent> (StdObjMgt_ReadData::*)()) &StdObjMgt_ReadData::ReadReference, "None");
	cls_StdObjMgt_ReadData.def("operator>>", (StdObjMgt_ReadData & (StdObjMgt_ReadData::*)(opencascade::handle<StdObjMgt_Persistent> &)) &StdObjMgt_ReadData::operator>>, "None", py::arg("theTarget"));
	cls_StdObjMgt_ReadData.def("operator>>", (StdObjMgt_ReadData & (StdObjMgt_ReadData::*)(Standard_Character &)) &StdObjMgt_ReadData::operator>>, "None", py::arg("theValue"));
	cls_StdObjMgt_ReadData.def("operator>>", (StdObjMgt_ReadData & (StdObjMgt_ReadData::*)(Standard_ExtCharacter &)) &StdObjMgt_ReadData::operator>>, "None", py::arg("theValue"));
	cls_StdObjMgt_ReadData.def("operator>>", (StdObjMgt_ReadData & (StdObjMgt_ReadData::*)(Standard_Integer &)) &StdObjMgt_ReadData::operator>>, "None", py::arg("theValue"));
	cls_StdObjMgt_ReadData.def("operator>>", (StdObjMgt_ReadData & (StdObjMgt_ReadData::*)(Standard_Boolean &)) &StdObjMgt_ReadData::operator>>, "None", py::arg("theValue"));
	cls_StdObjMgt_ReadData.def("operator>>", (StdObjMgt_ReadData & (StdObjMgt_ReadData::*)(Standard_Real &)) &StdObjMgt_ReadData::operator>>, "None", py::arg("theValue"));
	cls_StdObjMgt_ReadData.def("operator>>", (StdObjMgt_ReadData & (StdObjMgt_ReadData::*)(Standard_ShortReal &)) &StdObjMgt_ReadData::operator>>, "None", py::arg("theValue"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\StdObjMgt_WriteData.hxx
	py::class_<StdObjMgt_WriteData, std::unique_ptr<StdObjMgt_WriteData, Deleter<StdObjMgt_WriteData>>> cls_StdObjMgt_WriteData(mod, "StdObjMgt_WriteData", "Auxiliary data used to write persistent objects to a file.");
	cls_StdObjMgt_WriteData.def(py::init<Storage_BaseDriver &>(), py::arg("theDriver"));
	cls_StdObjMgt_WriteData.def("WritePersistentObject", (void (StdObjMgt_WriteData::*)(const opencascade::handle<StdObjMgt_Persistent> &)) &StdObjMgt_WriteData::WritePersistentObject, "None", py::arg("thePersistent"));
	cls_StdObjMgt_WriteData.def("operator<<", (StdObjMgt_WriteData & (StdObjMgt_WriteData::*)(const opencascade::handle<StdObjMgt_Persistent> &)) &StdObjMgt_WriteData::operator<<, "None", py::arg("thePersistent"));
	cls_StdObjMgt_WriteData.def("operator<<", (StdObjMgt_WriteData & (StdObjMgt_WriteData::*)(const Standard_Character &)) &StdObjMgt_WriteData::operator<<, "None", py::arg("theValue"));
	cls_StdObjMgt_WriteData.def("operator<<", (StdObjMgt_WriteData & (StdObjMgt_WriteData::*)(const Standard_ExtCharacter &)) &StdObjMgt_WriteData::operator<<, "None", py::arg("theValue"));
	cls_StdObjMgt_WriteData.def("operator<<", (StdObjMgt_WriteData & (StdObjMgt_WriteData::*)(const Standard_Integer &)) &StdObjMgt_WriteData::operator<<, "None", py::arg("theValue"));
	cls_StdObjMgt_WriteData.def("operator<<", (StdObjMgt_WriteData & (StdObjMgt_WriteData::*)(const Standard_Boolean &)) &StdObjMgt_WriteData::operator<<, "None", py::arg("theValue"));
	cls_StdObjMgt_WriteData.def("operator<<", (StdObjMgt_WriteData & (StdObjMgt_WriteData::*)(const Standard_Real &)) &StdObjMgt_WriteData::operator<<, "None", py::arg("theValue"));
	cls_StdObjMgt_WriteData.def("operator<<", (StdObjMgt_WriteData & (StdObjMgt_WriteData::*)(const Standard_ShortReal &)) &StdObjMgt_WriteData::operator<<, "None", py::arg("theValue"));

	// Callback for StdObjMgt_Persistent.
	class PyCallback_StdObjMgt_Persistent : public StdObjMgt_Persistent {
	public:
		using StdObjMgt_Persistent::StdObjMgt_Persistent;

		void Read(StdObjMgt_ReadData & theReadData) override { PYBIND11_OVERLOAD_PURE(void, StdObjMgt_Persistent, Read, theReadData); }
		void Write(StdObjMgt_WriteData & theWriteData) const  override { PYBIND11_OVERLOAD_PURE(void, StdObjMgt_Persistent, Write, theWriteData); }
		void PChildren(StdObjMgt_Persistent::SequenceOfPersistent & a0) const  override { PYBIND11_OVERLOAD_PURE(void, StdObjMgt_Persistent, PChildren, a0); }
		Standard_CString PName() const  override { PYBIND11_OVERLOAD_PURE(Standard_CString, StdObjMgt_Persistent, PName, ); }
	};

	// C:\Miniconda\envs\occt\Library\include\opencascade\StdObjMgt_Persistent.hxx
	py::class_<StdObjMgt_Persistent, opencascade::handle<StdObjMgt_Persistent>, PyCallback_StdObjMgt_Persistent, Standard_Transient> cls_StdObjMgt_Persistent(mod, "StdObjMgt_Persistent", "Root class for a temporary persistent object that reads data from a file and then creates transient object using the data.");
	cls_StdObjMgt_Persistent.def(py::init<>());
	cls_StdObjMgt_Persistent.def("Read", (void (StdObjMgt_Persistent::*)(StdObjMgt_ReadData &)) &StdObjMgt_Persistent::Read, "Read persistent data from a file.", py::arg("theReadData"));
	cls_StdObjMgt_Persistent.def("Write", (void (StdObjMgt_Persistent::*)(StdObjMgt_WriteData &) const ) &StdObjMgt_Persistent::Write, "Write persistent data to a file.", py::arg("theWriteData"));
	cls_StdObjMgt_Persistent.def("PChildren", (void (StdObjMgt_Persistent::*)(StdObjMgt_Persistent::SequenceOfPersistent &) const ) &StdObjMgt_Persistent::PChildren, "Gets persistent child objects", py::arg(""));
	cls_StdObjMgt_Persistent.def("PName", (Standard_CString (StdObjMgt_Persistent::*)() const ) &StdObjMgt_Persistent::PName, "Returns persistent type name");
	cls_StdObjMgt_Persistent.def("ImportDocument", (void (StdObjMgt_Persistent::*)(const opencascade::handle<TDocStd_Document> &) const ) &StdObjMgt_Persistent::ImportDocument, "Import transient document from the persistent data (to be overriden by document class; does nothing by default for other classes).", py::arg("theDocument"));
	cls_StdObjMgt_Persistent.def("CreateAttribute", (opencascade::handle<TDF_Attribute> (StdObjMgt_Persistent::*)()) &StdObjMgt_Persistent::CreateAttribute, "Create an empty transient attribuite (to be overriden by attribute classes; does nothing and returns a null handle by default for other classes).");
	cls_StdObjMgt_Persistent.def("GetAttribute", (opencascade::handle<TDF_Attribute> (StdObjMgt_Persistent::*)() const ) &StdObjMgt_Persistent::GetAttribute, "Get transient attribuite for the persistent data (to be overriden by attribute classes; returns a null handle by default for non-attribute classes).");
	cls_StdObjMgt_Persistent.def("ImportAttribute", (void (StdObjMgt_Persistent::*)()) &StdObjMgt_Persistent::ImportAttribute, "Import transient attribuite from the persistent data (to be overriden by attribute classes; does nothing by default for non-attribute classes).");
	cls_StdObjMgt_Persistent.def("AsciiString", (opencascade::handle<TCollection_HAsciiString> (StdObjMgt_Persistent::*)() const ) &StdObjMgt_Persistent::AsciiString, "Get referenced ASCII string (to be overriden by ASCII string class; returns a null handle by default for other classes).");
	cls_StdObjMgt_Persistent.def("ExtString", (opencascade::handle<TCollection_HExtendedString> (StdObjMgt_Persistent::*)() const ) &StdObjMgt_Persistent::ExtString, "Get referenced extended string (to be overriden by extended string class; returns a null handle by default for other classes).");
	cls_StdObjMgt_Persistent.def("Label", (TDF_Label (StdObjMgt_Persistent::*)(const opencascade::handle<TDF_Data> &) const ) &StdObjMgt_Persistent::Label, "Get a label expressed by referenced extended string (to be overriden by extended string class; returns a null label by default for other classes).", py::arg("theDF"));
	cls_StdObjMgt_Persistent.def("TypeNum", (Standard_Integer (StdObjMgt_Persistent::*)() const ) &StdObjMgt_Persistent::TypeNum, "Returns the assigned persistent type number");
	cls_StdObjMgt_Persistent.def("TypeNum", (void (StdObjMgt_Persistent::*)(Standard_Integer)) &StdObjMgt_Persistent::TypeNum, "Assigns a persistent type number to the object", py::arg("theTypeNum"));
	cls_StdObjMgt_Persistent.def("RefNum", (Standard_Integer (StdObjMgt_Persistent::*)() const ) &StdObjMgt_Persistent::RefNum, "Returns the object reference number");
	cls_StdObjMgt_Persistent.def("RefNum", (void (StdObjMgt_Persistent::*)(Standard_Integer)) &StdObjMgt_Persistent::RefNum, "Sets an object reference number", py::arg("theRefNum"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\StdObjMgt_SharedObject.hxx
	py::class_<StdObjMgt_SharedObject, std::unique_ptr<StdObjMgt_SharedObject, Deleter<StdObjMgt_SharedObject>>> cls_StdObjMgt_SharedObject(mod, "StdObjMgt_SharedObject", "None");
	cls_StdObjMgt_SharedObject.def(py::init<>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\StdObjMgt_ReadData.hxx
	py::class_<StdObjMgt_ReadData::Object, std::unique_ptr<StdObjMgt_ReadData::Object, Deleter<StdObjMgt_ReadData::Object>>> cls_StdObjMgt_ReadData_Object(mod, "StdObjMgt_ReadData_Object", "None");
	cls_StdObjMgt_ReadData_Object.def(py::init<StdObjMgt_ReadData &>(), py::arg("theData"));
	cls_StdObjMgt_ReadData_Object.def(py::init([] (const StdObjMgt_ReadData::Object &other) {return new StdObjMgt_ReadData::Object(other);}), "Copy constructor", py::arg("other"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\StdObjMgt_WriteData.hxx
	py::class_<StdObjMgt_WriteData::Object, std::unique_ptr<StdObjMgt_WriteData::Object, Deleter<StdObjMgt_WriteData::Object>>> cls_StdObjMgt_WriteData_Object(mod, "StdObjMgt_WriteData_Object", "None");
	cls_StdObjMgt_WriteData_Object.def(py::init<StdObjMgt_WriteData &>(), py::arg("theData"));
	cls_StdObjMgt_WriteData_Object.def(py::init([] (const StdObjMgt_WriteData::Object &other) {return new StdObjMgt_WriteData::Object(other);}), "Copy constructor", py::arg("other"));

	/* FIXME
	// StdObjMgt_TransientPersistentMap
	*/


}
