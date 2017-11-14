#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <LProp_Status.hxx>
#include <Standard_Failure.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_SStream.hxx>
#include <Standard_Handle.hxx>
#include <LProp_BadContinuity.hxx>
#include <Standard_Type.hxx>
#include <LProp_NotDefined.hxx>
#include <LProp_CIType.hxx>
#include <NCollection_BaseSequence.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_Sequence.hxx>
#include <LProp_SequenceOfCIType.hxx>
#include <LProp_CurAndInf.hxx>
#include <GeomAbs_CurveType.hxx>
#include <LProp_AnalyticCurInf.hxx>

PYBIND11_MODULE(LProp, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.GeomAbs");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\LProp_Status.hxx
	py::enum_<LProp_Status>(mod, "LProp_Status", "None")
		.value("LProp_Undecided", LProp_Status::LProp_Undecided)
		.value("LProp_Undefined", LProp_Status::LProp_Undefined)
		.value("LProp_Defined", LProp_Status::LProp_Defined)
		.value("LProp_Computed", LProp_Status::LProp_Computed)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\LProp_CIType.hxx
	py::enum_<LProp_CIType>(mod, "LProp_CIType", "Identifies the type of a particular point on a curve: - LProp_Inflection: a point of inflection - LProp_MinCur: a minimum of curvature - LProp_MaxCur: a maximum of curvature.")
		.value("LProp_Inflection", LProp_CIType::LProp_Inflection)
		.value("LProp_MinCur", LProp_CIType::LProp_MinCur)
		.value("LProp_MaxCur", LProp_CIType::LProp_MaxCur)
		.export_values();

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\LProp_BadContinuity.hxx
	py::class_<LProp_BadContinuity, opencascade::handle<LProp_BadContinuity>, Standard_Failure> cls_LProp_BadContinuity(mod, "LProp_BadContinuity", "None");
	cls_LProp_BadContinuity.def(py::init<>());
	cls_LProp_BadContinuity.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_LProp_BadContinuity.def_static("Raise_", (void (*)(const Standard_CString)) &LProp_BadContinuity::Raise, "None", py::arg("theMessage"));
	cls_LProp_BadContinuity.def_static("Raise_", (void (*)(Standard_SStream &)) &LProp_BadContinuity::Raise, "None", py::arg("theMessage"));
	cls_LProp_BadContinuity.def_static("NewInstance_", (opencascade::handle<LProp_BadContinuity> (*)(const Standard_CString)) &LProp_BadContinuity::NewInstance, "None", py::arg("theMessage"));
	cls_LProp_BadContinuity.def_static("get_type_name_", (const char * (*)()) &LProp_BadContinuity::get_type_name, "None");
	cls_LProp_BadContinuity.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &LProp_BadContinuity::get_type_descriptor, "None");
	cls_LProp_BadContinuity.def("DynamicType", (const opencascade::handle<Standard_Type> & (LProp_BadContinuity::*)() const ) &LProp_BadContinuity::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\LProp_NotDefined.hxx
	py::class_<LProp_NotDefined, opencascade::handle<LProp_NotDefined>, Standard_Failure> cls_LProp_NotDefined(mod, "LProp_NotDefined", "None");
	cls_LProp_NotDefined.def(py::init<>());
	cls_LProp_NotDefined.def(py::init<const Standard_CString>(), py::arg("theMessage"));
	cls_LProp_NotDefined.def_static("Raise_", (void (*)(const Standard_CString)) &LProp_NotDefined::Raise, "None", py::arg("theMessage"));
	cls_LProp_NotDefined.def_static("Raise_", (void (*)(Standard_SStream &)) &LProp_NotDefined::Raise, "None", py::arg("theMessage"));
	cls_LProp_NotDefined.def_static("NewInstance_", (opencascade::handle<LProp_NotDefined> (*)(const Standard_CString)) &LProp_NotDefined::NewInstance, "None", py::arg("theMessage"));
	cls_LProp_NotDefined.def_static("get_type_name_", (const char * (*)()) &LProp_NotDefined::get_type_name, "None");
	cls_LProp_NotDefined.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &LProp_NotDefined::get_type_descriptor, "None");
	cls_LProp_NotDefined.def("DynamicType", (const opencascade::handle<Standard_Type> & (LProp_NotDefined::*)() const ) &LProp_NotDefined::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\LProp_CurAndInf.hxx
	py::class_<LProp_CurAndInf, std::unique_ptr<LProp_CurAndInf, Deleter<LProp_CurAndInf>>> cls_LProp_CurAndInf(mod, "LProp_CurAndInf", "Stores the parameters of a curve 2d or 3d corresponding to the curvature's extremas and the Inflection's Points.");
	cls_LProp_CurAndInf.def(py::init<>());
	cls_LProp_CurAndInf.def("AddInflection", (void (LProp_CurAndInf::*)(const Standard_Real)) &LProp_CurAndInf::AddInflection, "None", py::arg("Param"));
	cls_LProp_CurAndInf.def("AddExtCur", (void (LProp_CurAndInf::*)(const Standard_Real, const Standard_Boolean)) &LProp_CurAndInf::AddExtCur, "None", py::arg("Param"), py::arg("IsMin"));
	cls_LProp_CurAndInf.def("Clear", (void (LProp_CurAndInf::*)()) &LProp_CurAndInf::Clear, "None");
	cls_LProp_CurAndInf.def("IsEmpty", (Standard_Boolean (LProp_CurAndInf::*)() const ) &LProp_CurAndInf::IsEmpty, "None");
	cls_LProp_CurAndInf.def("NbPoints", (Standard_Integer (LProp_CurAndInf::*)() const ) &LProp_CurAndInf::NbPoints, "Returns the number of points. The Points are stored to increasing parameter.");
	// FIXME cls_LProp_CurAndInf.def("Parameter", (Standard_Real (LProp_CurAndInf::*)(const Standard_Integer) const ) &LProp_CurAndInf::Parameter, "Returns the parameter of the Nth point. raises if N not in the range [1,NbPoints()]", py::arg("N"));
	// FIXME cls_LProp_CurAndInf.def("Type", (LProp_CIType (LProp_CurAndInf::*)(const Standard_Integer) const ) &LProp_CurAndInf::Type, "Returns - MinCur if the Nth parameter corresponds to a minimum of the radius of curvature. - MaxCur if the Nth parameter corresponds to a maximum of the radius of curvature. - Inflection if the parameter corresponds to a point of inflection. raises if N not in the range [1,NbPoints()]", py::arg("N"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\LProp_AnalyticCurInf.hxx
	py::class_<LProp_AnalyticCurInf, std::unique_ptr<LProp_AnalyticCurInf, Deleter<LProp_AnalyticCurInf>>> cls_LProp_AnalyticCurInf(mod, "LProp_AnalyticCurInf", "Computes the locals extremas of curvature of a gp curve Remark : a gp curve has not inflection.");
	cls_LProp_AnalyticCurInf.def(py::init<>());
	cls_LProp_AnalyticCurInf.def("Perform", (void (LProp_AnalyticCurInf::*)(const GeomAbs_CurveType, const Standard_Real, const Standard_Real, LProp_CurAndInf &)) &LProp_AnalyticCurInf::Perform, "None", py::arg("T"), py::arg("UFirst"), py::arg("ULast"), py::arg("Result"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<LProp_SequenceOfCIType, std::unique_ptr<LProp_SequenceOfCIType, Deleter<LProp_SequenceOfCIType>>, NCollection_BaseSequence> cls_LProp_SequenceOfCIType(mod, "LProp_SequenceOfCIType", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_LProp_SequenceOfCIType.def(py::init<>());
	cls_LProp_SequenceOfCIType.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_LProp_SequenceOfCIType.def(py::init([] (const LProp_SequenceOfCIType &other) {return new LProp_SequenceOfCIType(other);}), "Copy constructor", py::arg("other"));
	cls_LProp_SequenceOfCIType.def("begin", (LProp_SequenceOfCIType::iterator (LProp_SequenceOfCIType::*)() const ) &LProp_SequenceOfCIType::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_LProp_SequenceOfCIType.def("end", (LProp_SequenceOfCIType::iterator (LProp_SequenceOfCIType::*)() const ) &LProp_SequenceOfCIType::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_LProp_SequenceOfCIType.def("cbegin", (LProp_SequenceOfCIType::const_iterator (LProp_SequenceOfCIType::*)() const ) &LProp_SequenceOfCIType::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_LProp_SequenceOfCIType.def("cend", (LProp_SequenceOfCIType::const_iterator (LProp_SequenceOfCIType::*)() const ) &LProp_SequenceOfCIType::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_LProp_SequenceOfCIType.def("Size", (Standard_Integer (LProp_SequenceOfCIType::*)() const ) &LProp_SequenceOfCIType::Size, "Number of items");
	cls_LProp_SequenceOfCIType.def("Length", (Standard_Integer (LProp_SequenceOfCIType::*)() const ) &LProp_SequenceOfCIType::Length, "Number of items");
	cls_LProp_SequenceOfCIType.def("Lower", (Standard_Integer (LProp_SequenceOfCIType::*)() const ) &LProp_SequenceOfCIType::Lower, "Method for consistency with other collections.");
	cls_LProp_SequenceOfCIType.def("Upper", (Standard_Integer (LProp_SequenceOfCIType::*)() const ) &LProp_SequenceOfCIType::Upper, "Method for consistency with other collections.");
	cls_LProp_SequenceOfCIType.def("IsEmpty", (Standard_Boolean (LProp_SequenceOfCIType::*)() const ) &LProp_SequenceOfCIType::IsEmpty, "Empty query");
	cls_LProp_SequenceOfCIType.def("Reverse", (void (LProp_SequenceOfCIType::*)()) &LProp_SequenceOfCIType::Reverse, "Reverse sequence");
	cls_LProp_SequenceOfCIType.def("Exchange", (void (LProp_SequenceOfCIType::*)(const Standard_Integer, const Standard_Integer)) &LProp_SequenceOfCIType::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_LProp_SequenceOfCIType.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &LProp_SequenceOfCIType::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_LProp_SequenceOfCIType.def("Clear", [](LProp_SequenceOfCIType &self) -> void { return self.Clear(); });
	cls_LProp_SequenceOfCIType.def("Clear", (void (LProp_SequenceOfCIType::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &LProp_SequenceOfCIType::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_LProp_SequenceOfCIType.def("Assign", (LProp_SequenceOfCIType & (LProp_SequenceOfCIType::*)(const LProp_SequenceOfCIType &)) &LProp_SequenceOfCIType::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_LProp_SequenceOfCIType.def("assign", (LProp_SequenceOfCIType & (LProp_SequenceOfCIType::*)(const LProp_SequenceOfCIType &)) &LProp_SequenceOfCIType::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_LProp_SequenceOfCIType.def("Remove", (void (LProp_SequenceOfCIType::*)(LProp_SequenceOfCIType::Iterator &)) &LProp_SequenceOfCIType::Remove, "Remove one item", py::arg("thePosition"));
	cls_LProp_SequenceOfCIType.def("Remove", (void (LProp_SequenceOfCIType::*)(const Standard_Integer)) &LProp_SequenceOfCIType::Remove, "Remove one item", py::arg("theIndex"));
	cls_LProp_SequenceOfCIType.def("Remove", (void (LProp_SequenceOfCIType::*)(const Standard_Integer, const Standard_Integer)) &LProp_SequenceOfCIType::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_LProp_SequenceOfCIType.def("Append", (void (LProp_SequenceOfCIType::*)(const LProp_CIType &)) &LProp_SequenceOfCIType::Append, "Append one item", py::arg("theItem"));
	cls_LProp_SequenceOfCIType.def("Append", (void (LProp_SequenceOfCIType::*)(LProp_SequenceOfCIType &)) &LProp_SequenceOfCIType::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_LProp_SequenceOfCIType.def("Prepend", (void (LProp_SequenceOfCIType::*)(const LProp_CIType &)) &LProp_SequenceOfCIType::Prepend, "Prepend one item", py::arg("theItem"));
	cls_LProp_SequenceOfCIType.def("Prepend", (void (LProp_SequenceOfCIType::*)(LProp_SequenceOfCIType &)) &LProp_SequenceOfCIType::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_LProp_SequenceOfCIType.def("InsertBefore", (void (LProp_SequenceOfCIType::*)(const Standard_Integer, const LProp_CIType &)) &LProp_SequenceOfCIType::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_LProp_SequenceOfCIType.def("InsertBefore", (void (LProp_SequenceOfCIType::*)(const Standard_Integer, LProp_SequenceOfCIType &)) &LProp_SequenceOfCIType::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_LProp_SequenceOfCIType.def("InsertAfter", (void (LProp_SequenceOfCIType::*)(LProp_SequenceOfCIType::Iterator &, const LProp_CIType &)) &LProp_SequenceOfCIType::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_LProp_SequenceOfCIType.def("InsertAfter", (void (LProp_SequenceOfCIType::*)(const Standard_Integer, LProp_SequenceOfCIType &)) &LProp_SequenceOfCIType::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_LProp_SequenceOfCIType.def("InsertAfter", (void (LProp_SequenceOfCIType::*)(const Standard_Integer, const LProp_CIType &)) &LProp_SequenceOfCIType::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_LProp_SequenceOfCIType.def("Split", (void (LProp_SequenceOfCIType::*)(const Standard_Integer, LProp_SequenceOfCIType &)) &LProp_SequenceOfCIType::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_LProp_SequenceOfCIType.def("First", (const LProp_CIType & (LProp_SequenceOfCIType::*)() const ) &LProp_SequenceOfCIType::First, "First item access");
	cls_LProp_SequenceOfCIType.def("ChangeFirst", (LProp_CIType & (LProp_SequenceOfCIType::*)()) &LProp_SequenceOfCIType::ChangeFirst, "First item access");
	cls_LProp_SequenceOfCIType.def("Last", (const LProp_CIType & (LProp_SequenceOfCIType::*)() const ) &LProp_SequenceOfCIType::Last, "Last item access");
	cls_LProp_SequenceOfCIType.def("ChangeLast", (LProp_CIType & (LProp_SequenceOfCIType::*)()) &LProp_SequenceOfCIType::ChangeLast, "Last item access");
	cls_LProp_SequenceOfCIType.def("Value", (const LProp_CIType & (LProp_SequenceOfCIType::*)(const Standard_Integer) const ) &LProp_SequenceOfCIType::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_LProp_SequenceOfCIType.def("__call__", (const LProp_CIType & (LProp_SequenceOfCIType::*)(const Standard_Integer) const ) &LProp_SequenceOfCIType::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_LProp_SequenceOfCIType.def("ChangeValue", (LProp_CIType & (LProp_SequenceOfCIType::*)(const Standard_Integer)) &LProp_SequenceOfCIType::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_LProp_SequenceOfCIType.def("__call__", (LProp_CIType & (LProp_SequenceOfCIType::*)(const Standard_Integer)) &LProp_SequenceOfCIType::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_LProp_SequenceOfCIType.def("SetValue", (void (LProp_SequenceOfCIType::*)(const Standard_Integer, const LProp_CIType &)) &LProp_SequenceOfCIType::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_LProp_SequenceOfCIType.def("__iter__", [](const LProp_SequenceOfCIType &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());


}
