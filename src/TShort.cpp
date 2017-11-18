#include <pyOCCT_Common.hpp>

#include <Standard_TypeDef.hxx>
#include <NCollection_Array1.hxx>
#include <TShort_Array1OfShortReal.hxx>
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_Type.hxx>
#include <TShort_HArray1OfShortReal.hxx>
#include <NCollection_Array2.hxx>
#include <TShort_Array2OfShortReal.hxx>
#include <TShort_HArray2OfShortReal.hxx>
#include <NCollection_BaseSequence.hxx>
#include <NCollection_Sequence.hxx>
#include <TShort_SequenceOfShortReal.hxx>
#include <TShort_HSequenceOfShortReal.hxx>
#include <NCollection_Templates.hpp>

PYBIND11_MODULE(TShort, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.NCollection");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\TShort_Array1OfShortReal.hxx
	bind_NCollection_Array1<float>(mod, "TShort_Array1OfShortReal");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TShort_Array2OfShortReal.hxx
	bind_NCollection_Array2<float>(mod, "TShort_Array2OfShortReal");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TShort_SequenceOfShortReal.hxx
	bind_NCollection_Sequence<float>(mod, "TShort_SequenceOfShortReal");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TShort_HArray1OfShortReal.hxx
	py::class_<TShort_HArray1OfShortReal, opencascade::handle<TShort_HArray1OfShortReal>, TShort_Array1OfShortReal, Standard_Transient> cls_TShort_HArray1OfShortReal(mod, "TShort_HArray1OfShortReal", "None");
	cls_TShort_HArray1OfShortReal.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TShort_HArray1OfShortReal.def(py::init<const Standard_Integer, const Standard_Integer, const TShort_Array1OfShortReal::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_TShort_HArray1OfShortReal.def(py::init<const TShort_Array1OfShortReal &>(), py::arg("theOther"));
	cls_TShort_HArray1OfShortReal.def("Array1", (const TShort_Array1OfShortReal & (TShort_HArray1OfShortReal::*)() const ) &TShort_HArray1OfShortReal::Array1, "None");
	cls_TShort_HArray1OfShortReal.def("ChangeArray1", (TShort_Array1OfShortReal & (TShort_HArray1OfShortReal::*)()) &TShort_HArray1OfShortReal::ChangeArray1, "None");
	cls_TShort_HArray1OfShortReal.def_static("get_type_name_", (const char * (*)()) &TShort_HArray1OfShortReal::get_type_name, "None");
	cls_TShort_HArray1OfShortReal.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TShort_HArray1OfShortReal::get_type_descriptor, "None");
	cls_TShort_HArray1OfShortReal.def("DynamicType", (const opencascade::handle<Standard_Type> & (TShort_HArray1OfShortReal::*)() const ) &TShort_HArray1OfShortReal::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TShort_HArray2OfShortReal.hxx
	py::class_<TShort_HArray2OfShortReal, opencascade::handle<TShort_HArray2OfShortReal>, TShort_Array2OfShortReal, Standard_Transient> cls_TShort_HArray2OfShortReal(mod, "TShort_HArray2OfShortReal", "None");
	cls_TShort_HArray2OfShortReal.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"));
	cls_TShort_HArray2OfShortReal.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const TShort_Array2OfShortReal::value_type &>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"), py::arg("theValue"));
	cls_TShort_HArray2OfShortReal.def(py::init<const TShort_Array2OfShortReal &>(), py::arg("theOther"));
	cls_TShort_HArray2OfShortReal.def("Array2", (const TShort_Array2OfShortReal & (TShort_HArray2OfShortReal::*)() const ) &TShort_HArray2OfShortReal::Array2, "None");
	cls_TShort_HArray2OfShortReal.def("ChangeArray2", (TShort_Array2OfShortReal & (TShort_HArray2OfShortReal::*)()) &TShort_HArray2OfShortReal::ChangeArray2, "None");
	cls_TShort_HArray2OfShortReal.def_static("get_type_name_", (const char * (*)()) &TShort_HArray2OfShortReal::get_type_name, "None");
	cls_TShort_HArray2OfShortReal.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TShort_HArray2OfShortReal::get_type_descriptor, "None");
	cls_TShort_HArray2OfShortReal.def("DynamicType", (const opencascade::handle<Standard_Type> & (TShort_HArray2OfShortReal::*)() const ) &TShort_HArray2OfShortReal::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TShort_HSequenceOfShortReal.hxx
	py::class_<TShort_HSequenceOfShortReal, opencascade::handle<TShort_HSequenceOfShortReal>, TShort_SequenceOfShortReal, Standard_Transient> cls_TShort_HSequenceOfShortReal(mod, "TShort_HSequenceOfShortReal", "None");
	cls_TShort_HSequenceOfShortReal.def(py::init<>());
	cls_TShort_HSequenceOfShortReal.def(py::init<const TShort_SequenceOfShortReal &>(), py::arg("theOther"));
	cls_TShort_HSequenceOfShortReal.def("Sequence", (const TShort_SequenceOfShortReal & (TShort_HSequenceOfShortReal::*)() const ) &TShort_HSequenceOfShortReal::Sequence, "None");
	cls_TShort_HSequenceOfShortReal.def("Append", (void (TShort_HSequenceOfShortReal::*)(const TShort_SequenceOfShortReal::value_type &)) &TShort_HSequenceOfShortReal::Append, "None", py::arg("theItem"));
	cls_TShort_HSequenceOfShortReal.def("Append", (void (TShort_HSequenceOfShortReal::*)(TShort_SequenceOfShortReal &)) &TShort_HSequenceOfShortReal::Append, "None", py::arg("theSequence"));
	cls_TShort_HSequenceOfShortReal.def("ChangeSequence", (TShort_SequenceOfShortReal & (TShort_HSequenceOfShortReal::*)()) &TShort_HSequenceOfShortReal::ChangeSequence, "None");
	cls_TShort_HSequenceOfShortReal.def_static("get_type_name_", (const char * (*)()) &TShort_HSequenceOfShortReal::get_type_name, "None");
	cls_TShort_HSequenceOfShortReal.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TShort_HSequenceOfShortReal::get_type_descriptor, "None");
	cls_TShort_HSequenceOfShortReal.def("DynamicType", (const opencascade::handle<Standard_Type> & (TShort_HSequenceOfShortReal::*)() const ) &TShort_HSequenceOfShortReal::DynamicType, "None");


}
