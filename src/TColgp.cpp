#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <Standard_TypeDef.hxx>
#include <NCollection_Array1.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_Type.hxx>
#include <TColgp_HArray1OfPnt2d.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <NCollection_Array2.hxx>
#include <TColgp_Array2OfPnt.hxx>
#include <TColgp_HArray2OfPnt.hxx>
#include <TColgp_Array2OfPnt2d.hxx>
#include <TColgp_HArray2OfPnt2d.hxx>
#include <TColgp_HArray1OfPnt.hxx>
#include <NCollection_BaseSequence.hxx>
#include <NCollection_Sequence.hxx>
#include <TColgp_SequenceOfPnt.hxx>
#include <TColgp_HSequenceOfPnt.hxx>
#include <TColgp_Array1OfDir.hxx>
#include <TColgp_HArray1OfDir.hxx>
#include <TColgp_Array1OfVec.hxx>
#include <TColgp_HArray1OfVec.hxx>
#include <TColgp_Array1OfVec2d.hxx>
#include <TColgp_HArray1OfVec2d.hxx>
#include <TColgp_SequenceOfArray1OfPnt2d.hxx>
#include <TColgp_Array2OfXYZ.hxx>
#include <TColgp_HArray2OfXYZ.hxx>
#include <TColgp_Array1OfXYZ.hxx>
#include <TColgp_SequenceOfXY.hxx>
#include <TColgp_SequenceOfXYZ.hxx>
#include <TColgp_SequenceOfPnt2d.hxx>
#include <TColgp_SequenceOfAx1.hxx>
#include <TColgp_HSequenceOfXY.hxx>
#include <TColgp_Array2OfVec.hxx>
#include <TColgp_Array1OfXY.hxx>
#include <TColgp_Array1OfCirc2d.hxx>
#include <TColgp_Array1OfLin2d.hxx>
#include <TColgp_SequenceOfVec.hxx>
#include <TColgp_HArray1OfXYZ.hxx>
#include <TColgp_HArray1OfXY.hxx>
#include <TColgp_HSequenceOfXYZ.hxx>
#include <TColgp_Array1OfDir2d.hxx>
#include <TColgp_HArray1OfDir2d.hxx>
#include <TColgp_HArray1OfLin2d.hxx>
#include <TColgp_HArray1OfCirc2d.hxx>
#include <TColgp_Array2OfDir.hxx>
#include <TColgp_HArray2OfDir.hxx>
#include <TColgp_HArray2OfVec.hxx>
#include <TColgp_Array2OfXY.hxx>
#include <TColgp_HArray2OfXY.hxx>
#include <TColgp_Array2OfDir2d.hxx>
#include <TColgp_HArray2OfDir2d.hxx>
#include <TColgp_Array2OfVec2d.hxx>
#include <TColgp_HArray2OfVec2d.hxx>
#include <TColgp_Array2OfLin2d.hxx>
#include <TColgp_HArray2OfLin2d.hxx>
#include <TColgp_Array2OfCirc2d.hxx>
#include <TColgp_HArray2OfCirc2d.hxx>
#include <TColgp_SequenceOfDir.hxx>
#include <TColgp_HSequenceOfDir.hxx>
#include <TColgp_HSequenceOfVec.hxx>
#include <TColgp_SequenceOfDir2d.hxx>
#include <TColgp_HSequenceOfDir2d.hxx>
#include <TColgp_HSequenceOfPnt2d.hxx>
#include <TColgp_SequenceOfVec2d.hxx>
#include <TColgp_HSequenceOfVec2d.hxx>

PYBIND11_MODULE(TColgp, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.NCollection");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<TColgp_Array1OfPnt2d, std::unique_ptr<TColgp_Array1OfPnt2d, Deleter<TColgp_Array1OfPnt2d>>> cls_TColgp_Array1OfPnt2d(mod, "TColgp_Array1OfPnt2d", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_TColgp_Array1OfPnt2d.def(py::init<>());
	cls_TColgp_Array1OfPnt2d.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColgp_Array1OfPnt2d.def(py::init([] (const TColgp_Array1OfPnt2d &other) {return new TColgp_Array1OfPnt2d(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_TColgp_Array1OfPnt2d.def(py::init<TColgp_Array1OfPnt2d &&>(), py::arg("theOther"));
	cls_TColgp_Array1OfPnt2d.def(py::init<const gp_Pnt2d &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_TColgp_Array1OfPnt2d.def("begin", (TColgp_Array1OfPnt2d::iterator (TColgp_Array1OfPnt2d::*)() const ) &TColgp_Array1OfPnt2d::begin, "Returns an iterator pointing to the first element in the array.");
	cls_TColgp_Array1OfPnt2d.def("end", (TColgp_Array1OfPnt2d::iterator (TColgp_Array1OfPnt2d::*)() const ) &TColgp_Array1OfPnt2d::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_TColgp_Array1OfPnt2d.def("cbegin", (TColgp_Array1OfPnt2d::const_iterator (TColgp_Array1OfPnt2d::*)() const ) &TColgp_Array1OfPnt2d::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_TColgp_Array1OfPnt2d.def("cend", (TColgp_Array1OfPnt2d::const_iterator (TColgp_Array1OfPnt2d::*)() const ) &TColgp_Array1OfPnt2d::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_TColgp_Array1OfPnt2d.def("Init", (void (TColgp_Array1OfPnt2d::*)(const gp_Pnt2d &)) &TColgp_Array1OfPnt2d::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_TColgp_Array1OfPnt2d.def("Size", (Standard_Integer (TColgp_Array1OfPnt2d::*)() const ) &TColgp_Array1OfPnt2d::Size, "Size query");
	cls_TColgp_Array1OfPnt2d.def("Length", (Standard_Integer (TColgp_Array1OfPnt2d::*)() const ) &TColgp_Array1OfPnt2d::Length, "Length query (the same)");
	cls_TColgp_Array1OfPnt2d.def("IsEmpty", (Standard_Boolean (TColgp_Array1OfPnt2d::*)() const ) &TColgp_Array1OfPnt2d::IsEmpty, "Return TRUE if array has zero length.");
	cls_TColgp_Array1OfPnt2d.def("Lower", (Standard_Integer (TColgp_Array1OfPnt2d::*)() const ) &TColgp_Array1OfPnt2d::Lower, "Lower bound");
	cls_TColgp_Array1OfPnt2d.def("Upper", (Standard_Integer (TColgp_Array1OfPnt2d::*)() const ) &TColgp_Array1OfPnt2d::Upper, "Upper bound");
	cls_TColgp_Array1OfPnt2d.def("IsDeletable", (Standard_Boolean (TColgp_Array1OfPnt2d::*)() const ) &TColgp_Array1OfPnt2d::IsDeletable, "myDeletable flag");
	cls_TColgp_Array1OfPnt2d.def("IsAllocated", (Standard_Boolean (TColgp_Array1OfPnt2d::*)() const ) &TColgp_Array1OfPnt2d::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_TColgp_Array1OfPnt2d.def("Assign", (TColgp_Array1OfPnt2d & (TColgp_Array1OfPnt2d::*)(const TColgp_Array1OfPnt2d &)) &TColgp_Array1OfPnt2d::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_TColgp_Array1OfPnt2d.def("Move", (TColgp_Array1OfPnt2d & (TColgp_Array1OfPnt2d::*)(TColgp_Array1OfPnt2d &&)) &TColgp_Array1OfPnt2d::Move, "Move assignment", py::arg("theOther"));
	cls_TColgp_Array1OfPnt2d.def("assign", (TColgp_Array1OfPnt2d & (TColgp_Array1OfPnt2d::*)(const TColgp_Array1OfPnt2d &)) &TColgp_Array1OfPnt2d::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_TColgp_Array1OfPnt2d.def("assign", (TColgp_Array1OfPnt2d & (TColgp_Array1OfPnt2d::*)(TColgp_Array1OfPnt2d &&)) &TColgp_Array1OfPnt2d::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_TColgp_Array1OfPnt2d.def("First", (const gp_Pnt2d & (TColgp_Array1OfPnt2d::*)() const ) &TColgp_Array1OfPnt2d::First, "Returns first element");
	cls_TColgp_Array1OfPnt2d.def("ChangeFirst", (gp_Pnt2d & (TColgp_Array1OfPnt2d::*)()) &TColgp_Array1OfPnt2d::ChangeFirst, "Returns first element");
	cls_TColgp_Array1OfPnt2d.def("Last", (const gp_Pnt2d & (TColgp_Array1OfPnt2d::*)() const ) &TColgp_Array1OfPnt2d::Last, "Returns last element");
	cls_TColgp_Array1OfPnt2d.def("ChangeLast", (gp_Pnt2d & (TColgp_Array1OfPnt2d::*)()) &TColgp_Array1OfPnt2d::ChangeLast, "Returns last element");
	cls_TColgp_Array1OfPnt2d.def("Value", (const gp_Pnt2d & (TColgp_Array1OfPnt2d::*)(const Standard_Integer) const ) &TColgp_Array1OfPnt2d::Value, "Constant value access", py::arg("theIndex"));
	cls_TColgp_Array1OfPnt2d.def("__call__", (const gp_Pnt2d & (TColgp_Array1OfPnt2d::*)(const Standard_Integer) const ) &TColgp_Array1OfPnt2d::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_TColgp_Array1OfPnt2d.def("ChangeValue", (gp_Pnt2d & (TColgp_Array1OfPnt2d::*)(const Standard_Integer)) &TColgp_Array1OfPnt2d::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_TColgp_Array1OfPnt2d.def("__call__", (gp_Pnt2d & (TColgp_Array1OfPnt2d::*)(const Standard_Integer)) &TColgp_Array1OfPnt2d::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_TColgp_Array1OfPnt2d.def("SetValue", (void (TColgp_Array1OfPnt2d::*)(const Standard_Integer, const gp_Pnt2d &)) &TColgp_Array1OfPnt2d::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_TColgp_Array1OfPnt2d.def("Resize", (void (TColgp_Array1OfPnt2d::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &TColgp_Array1OfPnt2d::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_TColgp_Array1OfPnt2d.def("__iter__", [](const TColgp_Array1OfPnt2d &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array2.hxx
	py::class_<TColgp_Array2OfPnt, std::unique_ptr<TColgp_Array2OfPnt, Deleter<TColgp_Array2OfPnt>>> cls_TColgp_Array2OfPnt(mod, "TColgp_Array2OfPnt", "Purpose: The class Array2 represents bi-dimensional arrays of fixed size known at run time. The ranges of indices are user defined.");
	cls_TColgp_Array2OfPnt.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLower"), py::arg("theRowUpper"), py::arg("theColLower"), py::arg("theColUpper"));
	cls_TColgp_Array2OfPnt.def(py::init([] (const TColgp_Array2OfPnt &other) {return new TColgp_Array2OfPnt(other);}), "Copy constructor", py::arg("other"));
	cls_TColgp_Array2OfPnt.def(py::init<const gp_Pnt &, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theRowLower"), py::arg("theRowUpper"), py::arg("theColLower"), py::arg("theColUpper"));
	cls_TColgp_Array2OfPnt.def("Init", (void (TColgp_Array2OfPnt::*)(const gp_Pnt &)) &TColgp_Array2OfPnt::Init, "Initialise the values", py::arg("theValue"));
	cls_TColgp_Array2OfPnt.def("Size", (Standard_Integer (TColgp_Array2OfPnt::*)() const ) &TColgp_Array2OfPnt::Size, "Size (number of items)");
	cls_TColgp_Array2OfPnt.def("Length", (Standard_Integer (TColgp_Array2OfPnt::*)() const ) &TColgp_Array2OfPnt::Length, "Length (number of items)");
	cls_TColgp_Array2OfPnt.def("RowLength", (Standard_Integer (TColgp_Array2OfPnt::*)() const ) &TColgp_Array2OfPnt::RowLength, "Returns length of the row, i.e. number of columns");
	cls_TColgp_Array2OfPnt.def("ColLength", (Standard_Integer (TColgp_Array2OfPnt::*)() const ) &TColgp_Array2OfPnt::ColLength, "Returns length of the column, i.e. number of rows");
	cls_TColgp_Array2OfPnt.def("LowerRow", (Standard_Integer (TColgp_Array2OfPnt::*)() const ) &TColgp_Array2OfPnt::LowerRow, "LowerRow");
	cls_TColgp_Array2OfPnt.def("UpperRow", (Standard_Integer (TColgp_Array2OfPnt::*)() const ) &TColgp_Array2OfPnt::UpperRow, "UpperRow");
	cls_TColgp_Array2OfPnt.def("LowerCol", (Standard_Integer (TColgp_Array2OfPnt::*)() const ) &TColgp_Array2OfPnt::LowerCol, "LowerCol");
	cls_TColgp_Array2OfPnt.def("UpperCol", (Standard_Integer (TColgp_Array2OfPnt::*)() const ) &TColgp_Array2OfPnt::UpperCol, "UpperCol");
	cls_TColgp_Array2OfPnt.def("IsDeletable", (Standard_Boolean (TColgp_Array2OfPnt::*)() const ) &TColgp_Array2OfPnt::IsDeletable, "myDeletable flag");
	cls_TColgp_Array2OfPnt.def("Assign", (TColgp_Array2OfPnt & (TColgp_Array2OfPnt::*)(const TColgp_Array2OfPnt &)) &TColgp_Array2OfPnt::Assign, "Assignment", py::arg("theOther"));
	cls_TColgp_Array2OfPnt.def("assign", (TColgp_Array2OfPnt & (TColgp_Array2OfPnt::*)(const TColgp_Array2OfPnt &)) &TColgp_Array2OfPnt::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_TColgp_Array2OfPnt.def("Value", (const gp_Pnt & (TColgp_Array2OfPnt::*)(const Standard_Integer, const Standard_Integer) const ) &TColgp_Array2OfPnt::Value, "Constant value access", py::arg("theRow"), py::arg("theCol"));
	cls_TColgp_Array2OfPnt.def("__call__", (const gp_Pnt & (TColgp_Array2OfPnt::*)(const Standard_Integer, const Standard_Integer) const ) &TColgp_Array2OfPnt::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theRow"), py::arg("theCol"));
	cls_TColgp_Array2OfPnt.def("ChangeValue", (gp_Pnt & (TColgp_Array2OfPnt::*)(const Standard_Integer, const Standard_Integer)) &TColgp_Array2OfPnt::ChangeValue, "Variable value access", py::arg("theRow"), py::arg("theCol"));
	cls_TColgp_Array2OfPnt.def("__call__", (gp_Pnt & (TColgp_Array2OfPnt::*)(const Standard_Integer, const Standard_Integer)) &TColgp_Array2OfPnt::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theRow"), py::arg("theCol"));
	cls_TColgp_Array2OfPnt.def("SetValue", (void (TColgp_Array2OfPnt::*)(const Standard_Integer, const Standard_Integer, const gp_Pnt &)) &TColgp_Array2OfPnt::SetValue, "SetValue", py::arg("theRow"), py::arg("theCol"), py::arg("theItem"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array2.hxx
	py::class_<TColgp_Array2OfPnt2d, std::unique_ptr<TColgp_Array2OfPnt2d, Deleter<TColgp_Array2OfPnt2d>>> cls_TColgp_Array2OfPnt2d(mod, "TColgp_Array2OfPnt2d", "Purpose: The class Array2 represents bi-dimensional arrays of fixed size known at run time. The ranges of indices are user defined.");
	cls_TColgp_Array2OfPnt2d.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLower"), py::arg("theRowUpper"), py::arg("theColLower"), py::arg("theColUpper"));
	cls_TColgp_Array2OfPnt2d.def(py::init([] (const TColgp_Array2OfPnt2d &other) {return new TColgp_Array2OfPnt2d(other);}), "Copy constructor", py::arg("other"));
	cls_TColgp_Array2OfPnt2d.def(py::init<const gp_Pnt2d &, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theRowLower"), py::arg("theRowUpper"), py::arg("theColLower"), py::arg("theColUpper"));
	cls_TColgp_Array2OfPnt2d.def("Init", (void (TColgp_Array2OfPnt2d::*)(const gp_Pnt2d &)) &TColgp_Array2OfPnt2d::Init, "Initialise the values", py::arg("theValue"));
	cls_TColgp_Array2OfPnt2d.def("Size", (Standard_Integer (TColgp_Array2OfPnt2d::*)() const ) &TColgp_Array2OfPnt2d::Size, "Size (number of items)");
	cls_TColgp_Array2OfPnt2d.def("Length", (Standard_Integer (TColgp_Array2OfPnt2d::*)() const ) &TColgp_Array2OfPnt2d::Length, "Length (number of items)");
	cls_TColgp_Array2OfPnt2d.def("RowLength", (Standard_Integer (TColgp_Array2OfPnt2d::*)() const ) &TColgp_Array2OfPnt2d::RowLength, "Returns length of the row, i.e. number of columns");
	cls_TColgp_Array2OfPnt2d.def("ColLength", (Standard_Integer (TColgp_Array2OfPnt2d::*)() const ) &TColgp_Array2OfPnt2d::ColLength, "Returns length of the column, i.e. number of rows");
	cls_TColgp_Array2OfPnt2d.def("LowerRow", (Standard_Integer (TColgp_Array2OfPnt2d::*)() const ) &TColgp_Array2OfPnt2d::LowerRow, "LowerRow");
	cls_TColgp_Array2OfPnt2d.def("UpperRow", (Standard_Integer (TColgp_Array2OfPnt2d::*)() const ) &TColgp_Array2OfPnt2d::UpperRow, "UpperRow");
	cls_TColgp_Array2OfPnt2d.def("LowerCol", (Standard_Integer (TColgp_Array2OfPnt2d::*)() const ) &TColgp_Array2OfPnt2d::LowerCol, "LowerCol");
	cls_TColgp_Array2OfPnt2d.def("UpperCol", (Standard_Integer (TColgp_Array2OfPnt2d::*)() const ) &TColgp_Array2OfPnt2d::UpperCol, "UpperCol");
	cls_TColgp_Array2OfPnt2d.def("IsDeletable", (Standard_Boolean (TColgp_Array2OfPnt2d::*)() const ) &TColgp_Array2OfPnt2d::IsDeletable, "myDeletable flag");
	cls_TColgp_Array2OfPnt2d.def("Assign", (TColgp_Array2OfPnt2d & (TColgp_Array2OfPnt2d::*)(const TColgp_Array2OfPnt2d &)) &TColgp_Array2OfPnt2d::Assign, "Assignment", py::arg("theOther"));
	cls_TColgp_Array2OfPnt2d.def("assign", (TColgp_Array2OfPnt2d & (TColgp_Array2OfPnt2d::*)(const TColgp_Array2OfPnt2d &)) &TColgp_Array2OfPnt2d::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_TColgp_Array2OfPnt2d.def("Value", (const gp_Pnt2d & (TColgp_Array2OfPnt2d::*)(const Standard_Integer, const Standard_Integer) const ) &TColgp_Array2OfPnt2d::Value, "Constant value access", py::arg("theRow"), py::arg("theCol"));
	cls_TColgp_Array2OfPnt2d.def("__call__", (const gp_Pnt2d & (TColgp_Array2OfPnt2d::*)(const Standard_Integer, const Standard_Integer) const ) &TColgp_Array2OfPnt2d::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theRow"), py::arg("theCol"));
	cls_TColgp_Array2OfPnt2d.def("ChangeValue", (gp_Pnt2d & (TColgp_Array2OfPnt2d::*)(const Standard_Integer, const Standard_Integer)) &TColgp_Array2OfPnt2d::ChangeValue, "Variable value access", py::arg("theRow"), py::arg("theCol"));
	cls_TColgp_Array2OfPnt2d.def("__call__", (gp_Pnt2d & (TColgp_Array2OfPnt2d::*)(const Standard_Integer, const Standard_Integer)) &TColgp_Array2OfPnt2d::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theRow"), py::arg("theCol"));
	cls_TColgp_Array2OfPnt2d.def("SetValue", (void (TColgp_Array2OfPnt2d::*)(const Standard_Integer, const Standard_Integer, const gp_Pnt2d &)) &TColgp_Array2OfPnt2d::SetValue, "SetValue", py::arg("theRow"), py::arg("theCol"), py::arg("theItem"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<TColgp_Array1OfPnt, std::unique_ptr<TColgp_Array1OfPnt, Deleter<TColgp_Array1OfPnt>>> cls_TColgp_Array1OfPnt(mod, "TColgp_Array1OfPnt", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_TColgp_Array1OfPnt.def(py::init<>());
	cls_TColgp_Array1OfPnt.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColgp_Array1OfPnt.def(py::init([] (const TColgp_Array1OfPnt &other) {return new TColgp_Array1OfPnt(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_TColgp_Array1OfPnt.def(py::init<TColgp_Array1OfPnt &&>(), py::arg("theOther"));
	cls_TColgp_Array1OfPnt.def(py::init<const gp_Pnt &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_TColgp_Array1OfPnt.def("begin", (TColgp_Array1OfPnt::iterator (TColgp_Array1OfPnt::*)() const ) &TColgp_Array1OfPnt::begin, "Returns an iterator pointing to the first element in the array.");
	cls_TColgp_Array1OfPnt.def("end", (TColgp_Array1OfPnt::iterator (TColgp_Array1OfPnt::*)() const ) &TColgp_Array1OfPnt::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_TColgp_Array1OfPnt.def("cbegin", (TColgp_Array1OfPnt::const_iterator (TColgp_Array1OfPnt::*)() const ) &TColgp_Array1OfPnt::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_TColgp_Array1OfPnt.def("cend", (TColgp_Array1OfPnt::const_iterator (TColgp_Array1OfPnt::*)() const ) &TColgp_Array1OfPnt::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_TColgp_Array1OfPnt.def("Init", (void (TColgp_Array1OfPnt::*)(const gp_Pnt &)) &TColgp_Array1OfPnt::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_TColgp_Array1OfPnt.def("Size", (Standard_Integer (TColgp_Array1OfPnt::*)() const ) &TColgp_Array1OfPnt::Size, "Size query");
	cls_TColgp_Array1OfPnt.def("Length", (Standard_Integer (TColgp_Array1OfPnt::*)() const ) &TColgp_Array1OfPnt::Length, "Length query (the same)");
	cls_TColgp_Array1OfPnt.def("IsEmpty", (Standard_Boolean (TColgp_Array1OfPnt::*)() const ) &TColgp_Array1OfPnt::IsEmpty, "Return TRUE if array has zero length.");
	cls_TColgp_Array1OfPnt.def("Lower", (Standard_Integer (TColgp_Array1OfPnt::*)() const ) &TColgp_Array1OfPnt::Lower, "Lower bound");
	cls_TColgp_Array1OfPnt.def("Upper", (Standard_Integer (TColgp_Array1OfPnt::*)() const ) &TColgp_Array1OfPnt::Upper, "Upper bound");
	cls_TColgp_Array1OfPnt.def("IsDeletable", (Standard_Boolean (TColgp_Array1OfPnt::*)() const ) &TColgp_Array1OfPnt::IsDeletable, "myDeletable flag");
	cls_TColgp_Array1OfPnt.def("IsAllocated", (Standard_Boolean (TColgp_Array1OfPnt::*)() const ) &TColgp_Array1OfPnt::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_TColgp_Array1OfPnt.def("Assign", (TColgp_Array1OfPnt & (TColgp_Array1OfPnt::*)(const TColgp_Array1OfPnt &)) &TColgp_Array1OfPnt::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_TColgp_Array1OfPnt.def("Move", (TColgp_Array1OfPnt & (TColgp_Array1OfPnt::*)(TColgp_Array1OfPnt &&)) &TColgp_Array1OfPnt::Move, "Move assignment", py::arg("theOther"));
	cls_TColgp_Array1OfPnt.def("assign", (TColgp_Array1OfPnt & (TColgp_Array1OfPnt::*)(const TColgp_Array1OfPnt &)) &TColgp_Array1OfPnt::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_TColgp_Array1OfPnt.def("assign", (TColgp_Array1OfPnt & (TColgp_Array1OfPnt::*)(TColgp_Array1OfPnt &&)) &TColgp_Array1OfPnt::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_TColgp_Array1OfPnt.def("First", (const gp_Pnt & (TColgp_Array1OfPnt::*)() const ) &TColgp_Array1OfPnt::First, "Returns first element");
	cls_TColgp_Array1OfPnt.def("ChangeFirst", (gp_Pnt & (TColgp_Array1OfPnt::*)()) &TColgp_Array1OfPnt::ChangeFirst, "Returns first element");
	cls_TColgp_Array1OfPnt.def("Last", (const gp_Pnt & (TColgp_Array1OfPnt::*)() const ) &TColgp_Array1OfPnt::Last, "Returns last element");
	cls_TColgp_Array1OfPnt.def("ChangeLast", (gp_Pnt & (TColgp_Array1OfPnt::*)()) &TColgp_Array1OfPnt::ChangeLast, "Returns last element");
	cls_TColgp_Array1OfPnt.def("Value", (const gp_Pnt & (TColgp_Array1OfPnt::*)(const Standard_Integer) const ) &TColgp_Array1OfPnt::Value, "Constant value access", py::arg("theIndex"));
	cls_TColgp_Array1OfPnt.def("__call__", (const gp_Pnt & (TColgp_Array1OfPnt::*)(const Standard_Integer) const ) &TColgp_Array1OfPnt::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_TColgp_Array1OfPnt.def("ChangeValue", (gp_Pnt & (TColgp_Array1OfPnt::*)(const Standard_Integer)) &TColgp_Array1OfPnt::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_TColgp_Array1OfPnt.def("__call__", (gp_Pnt & (TColgp_Array1OfPnt::*)(const Standard_Integer)) &TColgp_Array1OfPnt::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_TColgp_Array1OfPnt.def("SetValue", (void (TColgp_Array1OfPnt::*)(const Standard_Integer, const gp_Pnt &)) &TColgp_Array1OfPnt::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_TColgp_Array1OfPnt.def("Resize", (void (TColgp_Array1OfPnt::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &TColgp_Array1OfPnt::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_TColgp_Array1OfPnt.def("__iter__", [](const TColgp_Array1OfPnt &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<TColgp_SequenceOfPnt, std::unique_ptr<TColgp_SequenceOfPnt, Deleter<TColgp_SequenceOfPnt>>, NCollection_BaseSequence> cls_TColgp_SequenceOfPnt(mod, "TColgp_SequenceOfPnt", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_TColgp_SequenceOfPnt.def(py::init<>());
	cls_TColgp_SequenceOfPnt.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_TColgp_SequenceOfPnt.def(py::init([] (const TColgp_SequenceOfPnt &other) {return new TColgp_SequenceOfPnt(other);}), "Copy constructor", py::arg("other"));
	cls_TColgp_SequenceOfPnt.def("begin", (TColgp_SequenceOfPnt::iterator (TColgp_SequenceOfPnt::*)() const ) &TColgp_SequenceOfPnt::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_TColgp_SequenceOfPnt.def("end", (TColgp_SequenceOfPnt::iterator (TColgp_SequenceOfPnt::*)() const ) &TColgp_SequenceOfPnt::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_TColgp_SequenceOfPnt.def("cbegin", (TColgp_SequenceOfPnt::const_iterator (TColgp_SequenceOfPnt::*)() const ) &TColgp_SequenceOfPnt::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_TColgp_SequenceOfPnt.def("cend", (TColgp_SequenceOfPnt::const_iterator (TColgp_SequenceOfPnt::*)() const ) &TColgp_SequenceOfPnt::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_TColgp_SequenceOfPnt.def("Size", (Standard_Integer (TColgp_SequenceOfPnt::*)() const ) &TColgp_SequenceOfPnt::Size, "Number of items");
	cls_TColgp_SequenceOfPnt.def("Length", (Standard_Integer (TColgp_SequenceOfPnt::*)() const ) &TColgp_SequenceOfPnt::Length, "Number of items");
	cls_TColgp_SequenceOfPnt.def("Lower", (Standard_Integer (TColgp_SequenceOfPnt::*)() const ) &TColgp_SequenceOfPnt::Lower, "Method for consistency with other collections.");
	cls_TColgp_SequenceOfPnt.def("Upper", (Standard_Integer (TColgp_SequenceOfPnt::*)() const ) &TColgp_SequenceOfPnt::Upper, "Method for consistency with other collections.");
	cls_TColgp_SequenceOfPnt.def("IsEmpty", (Standard_Boolean (TColgp_SequenceOfPnt::*)() const ) &TColgp_SequenceOfPnt::IsEmpty, "Empty query");
	cls_TColgp_SequenceOfPnt.def("Reverse", (void (TColgp_SequenceOfPnt::*)()) &TColgp_SequenceOfPnt::Reverse, "Reverse sequence");
	cls_TColgp_SequenceOfPnt.def("Exchange", (void (TColgp_SequenceOfPnt::*)(const Standard_Integer, const Standard_Integer)) &TColgp_SequenceOfPnt::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_TColgp_SequenceOfPnt.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_SequenceOfPnt::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_TColgp_SequenceOfPnt.def("Clear", [](TColgp_SequenceOfPnt &self) -> void { return self.Clear(); });
	cls_TColgp_SequenceOfPnt.def("Clear", (void (TColgp_SequenceOfPnt::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_SequenceOfPnt::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_TColgp_SequenceOfPnt.def("Assign", (TColgp_SequenceOfPnt & (TColgp_SequenceOfPnt::*)(const TColgp_SequenceOfPnt &)) &TColgp_SequenceOfPnt::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TColgp_SequenceOfPnt.def("assign", (TColgp_SequenceOfPnt & (TColgp_SequenceOfPnt::*)(const TColgp_SequenceOfPnt &)) &TColgp_SequenceOfPnt::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_TColgp_SequenceOfPnt.def("Remove", (void (TColgp_SequenceOfPnt::*)(TColgp_SequenceOfPnt::Iterator &)) &TColgp_SequenceOfPnt::Remove, "Remove one item", py::arg("thePosition"));
	cls_TColgp_SequenceOfPnt.def("Remove", (void (TColgp_SequenceOfPnt::*)(const Standard_Integer)) &TColgp_SequenceOfPnt::Remove, "Remove one item", py::arg("theIndex"));
	cls_TColgp_SequenceOfPnt.def("Remove", (void (TColgp_SequenceOfPnt::*)(const Standard_Integer, const Standard_Integer)) &TColgp_SequenceOfPnt::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_TColgp_SequenceOfPnt.def("Append", (void (TColgp_SequenceOfPnt::*)(const gp_Pnt &)) &TColgp_SequenceOfPnt::Append, "Append one item", py::arg("theItem"));
	cls_TColgp_SequenceOfPnt.def("Append", (void (TColgp_SequenceOfPnt::*)(TColgp_SequenceOfPnt &)) &TColgp_SequenceOfPnt::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_TColgp_SequenceOfPnt.def("Prepend", (void (TColgp_SequenceOfPnt::*)(const gp_Pnt &)) &TColgp_SequenceOfPnt::Prepend, "Prepend one item", py::arg("theItem"));
	cls_TColgp_SequenceOfPnt.def("Prepend", (void (TColgp_SequenceOfPnt::*)(TColgp_SequenceOfPnt &)) &TColgp_SequenceOfPnt::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_TColgp_SequenceOfPnt.def("InsertBefore", (void (TColgp_SequenceOfPnt::*)(const Standard_Integer, const gp_Pnt &)) &TColgp_SequenceOfPnt::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_TColgp_SequenceOfPnt.def("InsertBefore", (void (TColgp_SequenceOfPnt::*)(const Standard_Integer, TColgp_SequenceOfPnt &)) &TColgp_SequenceOfPnt::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColgp_SequenceOfPnt.def("InsertAfter", (void (TColgp_SequenceOfPnt::*)(TColgp_SequenceOfPnt::Iterator &, const gp_Pnt &)) &TColgp_SequenceOfPnt::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_TColgp_SequenceOfPnt.def("InsertAfter", (void (TColgp_SequenceOfPnt::*)(const Standard_Integer, TColgp_SequenceOfPnt &)) &TColgp_SequenceOfPnt::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColgp_SequenceOfPnt.def("InsertAfter", (void (TColgp_SequenceOfPnt::*)(const Standard_Integer, const gp_Pnt &)) &TColgp_SequenceOfPnt::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_TColgp_SequenceOfPnt.def("Split", (void (TColgp_SequenceOfPnt::*)(const Standard_Integer, TColgp_SequenceOfPnt &)) &TColgp_SequenceOfPnt::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColgp_SequenceOfPnt.def("First", (const gp_Pnt & (TColgp_SequenceOfPnt::*)() const ) &TColgp_SequenceOfPnt::First, "First item access");
	cls_TColgp_SequenceOfPnt.def("ChangeFirst", (gp_Pnt & (TColgp_SequenceOfPnt::*)()) &TColgp_SequenceOfPnt::ChangeFirst, "First item access");
	cls_TColgp_SequenceOfPnt.def("Last", (const gp_Pnt & (TColgp_SequenceOfPnt::*)() const ) &TColgp_SequenceOfPnt::Last, "Last item access");
	cls_TColgp_SequenceOfPnt.def("ChangeLast", (gp_Pnt & (TColgp_SequenceOfPnt::*)()) &TColgp_SequenceOfPnt::ChangeLast, "Last item access");
	cls_TColgp_SequenceOfPnt.def("Value", (const gp_Pnt & (TColgp_SequenceOfPnt::*)(const Standard_Integer) const ) &TColgp_SequenceOfPnt::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_TColgp_SequenceOfPnt.def("__call__", (const gp_Pnt & (TColgp_SequenceOfPnt::*)(const Standard_Integer) const ) &TColgp_SequenceOfPnt::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_TColgp_SequenceOfPnt.def("ChangeValue", (gp_Pnt & (TColgp_SequenceOfPnt::*)(const Standard_Integer)) &TColgp_SequenceOfPnt::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_TColgp_SequenceOfPnt.def("__call__", (gp_Pnt & (TColgp_SequenceOfPnt::*)(const Standard_Integer)) &TColgp_SequenceOfPnt::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_TColgp_SequenceOfPnt.def("SetValue", (void (TColgp_SequenceOfPnt::*)(const Standard_Integer, const gp_Pnt &)) &TColgp_SequenceOfPnt::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_TColgp_SequenceOfPnt.def("__iter__", [](const TColgp_SequenceOfPnt &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<TColgp_Array1OfDir, std::unique_ptr<TColgp_Array1OfDir, Deleter<TColgp_Array1OfDir>>> cls_TColgp_Array1OfDir(mod, "TColgp_Array1OfDir", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_TColgp_Array1OfDir.def(py::init<>());
	cls_TColgp_Array1OfDir.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColgp_Array1OfDir.def(py::init([] (const TColgp_Array1OfDir &other) {return new TColgp_Array1OfDir(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_TColgp_Array1OfDir.def(py::init<TColgp_Array1OfDir &&>(), py::arg("theOther"));
	cls_TColgp_Array1OfDir.def(py::init<const gp_Dir &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_TColgp_Array1OfDir.def("begin", (TColgp_Array1OfDir::iterator (TColgp_Array1OfDir::*)() const ) &TColgp_Array1OfDir::begin, "Returns an iterator pointing to the first element in the array.");
	cls_TColgp_Array1OfDir.def("end", (TColgp_Array1OfDir::iterator (TColgp_Array1OfDir::*)() const ) &TColgp_Array1OfDir::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_TColgp_Array1OfDir.def("cbegin", (TColgp_Array1OfDir::const_iterator (TColgp_Array1OfDir::*)() const ) &TColgp_Array1OfDir::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_TColgp_Array1OfDir.def("cend", (TColgp_Array1OfDir::const_iterator (TColgp_Array1OfDir::*)() const ) &TColgp_Array1OfDir::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_TColgp_Array1OfDir.def("Init", (void (TColgp_Array1OfDir::*)(const gp_Dir &)) &TColgp_Array1OfDir::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_TColgp_Array1OfDir.def("Size", (Standard_Integer (TColgp_Array1OfDir::*)() const ) &TColgp_Array1OfDir::Size, "Size query");
	cls_TColgp_Array1OfDir.def("Length", (Standard_Integer (TColgp_Array1OfDir::*)() const ) &TColgp_Array1OfDir::Length, "Length query (the same)");
	cls_TColgp_Array1OfDir.def("IsEmpty", (Standard_Boolean (TColgp_Array1OfDir::*)() const ) &TColgp_Array1OfDir::IsEmpty, "Return TRUE if array has zero length.");
	cls_TColgp_Array1OfDir.def("Lower", (Standard_Integer (TColgp_Array1OfDir::*)() const ) &TColgp_Array1OfDir::Lower, "Lower bound");
	cls_TColgp_Array1OfDir.def("Upper", (Standard_Integer (TColgp_Array1OfDir::*)() const ) &TColgp_Array1OfDir::Upper, "Upper bound");
	cls_TColgp_Array1OfDir.def("IsDeletable", (Standard_Boolean (TColgp_Array1OfDir::*)() const ) &TColgp_Array1OfDir::IsDeletable, "myDeletable flag");
	cls_TColgp_Array1OfDir.def("IsAllocated", (Standard_Boolean (TColgp_Array1OfDir::*)() const ) &TColgp_Array1OfDir::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_TColgp_Array1OfDir.def("Assign", (TColgp_Array1OfDir & (TColgp_Array1OfDir::*)(const TColgp_Array1OfDir &)) &TColgp_Array1OfDir::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_TColgp_Array1OfDir.def("Move", (TColgp_Array1OfDir & (TColgp_Array1OfDir::*)(TColgp_Array1OfDir &&)) &TColgp_Array1OfDir::Move, "Move assignment", py::arg("theOther"));
	cls_TColgp_Array1OfDir.def("assign", (TColgp_Array1OfDir & (TColgp_Array1OfDir::*)(const TColgp_Array1OfDir &)) &TColgp_Array1OfDir::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_TColgp_Array1OfDir.def("assign", (TColgp_Array1OfDir & (TColgp_Array1OfDir::*)(TColgp_Array1OfDir &&)) &TColgp_Array1OfDir::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_TColgp_Array1OfDir.def("First", (const gp_Dir & (TColgp_Array1OfDir::*)() const ) &TColgp_Array1OfDir::First, "Returns first element");
	cls_TColgp_Array1OfDir.def("ChangeFirst", (gp_Dir & (TColgp_Array1OfDir::*)()) &TColgp_Array1OfDir::ChangeFirst, "Returns first element");
	cls_TColgp_Array1OfDir.def("Last", (const gp_Dir & (TColgp_Array1OfDir::*)() const ) &TColgp_Array1OfDir::Last, "Returns last element");
	cls_TColgp_Array1OfDir.def("ChangeLast", (gp_Dir & (TColgp_Array1OfDir::*)()) &TColgp_Array1OfDir::ChangeLast, "Returns last element");
	cls_TColgp_Array1OfDir.def("Value", (const gp_Dir & (TColgp_Array1OfDir::*)(const Standard_Integer) const ) &TColgp_Array1OfDir::Value, "Constant value access", py::arg("theIndex"));
	cls_TColgp_Array1OfDir.def("__call__", (const gp_Dir & (TColgp_Array1OfDir::*)(const Standard_Integer) const ) &TColgp_Array1OfDir::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_TColgp_Array1OfDir.def("ChangeValue", (gp_Dir & (TColgp_Array1OfDir::*)(const Standard_Integer)) &TColgp_Array1OfDir::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_TColgp_Array1OfDir.def("__call__", (gp_Dir & (TColgp_Array1OfDir::*)(const Standard_Integer)) &TColgp_Array1OfDir::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_TColgp_Array1OfDir.def("SetValue", (void (TColgp_Array1OfDir::*)(const Standard_Integer, const gp_Dir &)) &TColgp_Array1OfDir::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_TColgp_Array1OfDir.def("Resize", (void (TColgp_Array1OfDir::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &TColgp_Array1OfDir::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_TColgp_Array1OfDir.def("__iter__", [](const TColgp_Array1OfDir &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<TColgp_Array1OfVec, std::unique_ptr<TColgp_Array1OfVec, Deleter<TColgp_Array1OfVec>>> cls_TColgp_Array1OfVec(mod, "TColgp_Array1OfVec", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_TColgp_Array1OfVec.def(py::init<>());
	cls_TColgp_Array1OfVec.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColgp_Array1OfVec.def(py::init([] (const TColgp_Array1OfVec &other) {return new TColgp_Array1OfVec(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_TColgp_Array1OfVec.def(py::init<TColgp_Array1OfVec &&>(), py::arg("theOther"));
	cls_TColgp_Array1OfVec.def(py::init<const gp_Vec &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_TColgp_Array1OfVec.def("begin", (TColgp_Array1OfVec::iterator (TColgp_Array1OfVec::*)() const ) &TColgp_Array1OfVec::begin, "Returns an iterator pointing to the first element in the array.");
	cls_TColgp_Array1OfVec.def("end", (TColgp_Array1OfVec::iterator (TColgp_Array1OfVec::*)() const ) &TColgp_Array1OfVec::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_TColgp_Array1OfVec.def("cbegin", (TColgp_Array1OfVec::const_iterator (TColgp_Array1OfVec::*)() const ) &TColgp_Array1OfVec::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_TColgp_Array1OfVec.def("cend", (TColgp_Array1OfVec::const_iterator (TColgp_Array1OfVec::*)() const ) &TColgp_Array1OfVec::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_TColgp_Array1OfVec.def("Init", (void (TColgp_Array1OfVec::*)(const gp_Vec &)) &TColgp_Array1OfVec::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_TColgp_Array1OfVec.def("Size", (Standard_Integer (TColgp_Array1OfVec::*)() const ) &TColgp_Array1OfVec::Size, "Size query");
	cls_TColgp_Array1OfVec.def("Length", (Standard_Integer (TColgp_Array1OfVec::*)() const ) &TColgp_Array1OfVec::Length, "Length query (the same)");
	cls_TColgp_Array1OfVec.def("IsEmpty", (Standard_Boolean (TColgp_Array1OfVec::*)() const ) &TColgp_Array1OfVec::IsEmpty, "Return TRUE if array has zero length.");
	cls_TColgp_Array1OfVec.def("Lower", (Standard_Integer (TColgp_Array1OfVec::*)() const ) &TColgp_Array1OfVec::Lower, "Lower bound");
	cls_TColgp_Array1OfVec.def("Upper", (Standard_Integer (TColgp_Array1OfVec::*)() const ) &TColgp_Array1OfVec::Upper, "Upper bound");
	cls_TColgp_Array1OfVec.def("IsDeletable", (Standard_Boolean (TColgp_Array1OfVec::*)() const ) &TColgp_Array1OfVec::IsDeletable, "myDeletable flag");
	cls_TColgp_Array1OfVec.def("IsAllocated", (Standard_Boolean (TColgp_Array1OfVec::*)() const ) &TColgp_Array1OfVec::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_TColgp_Array1OfVec.def("Assign", (TColgp_Array1OfVec & (TColgp_Array1OfVec::*)(const TColgp_Array1OfVec &)) &TColgp_Array1OfVec::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_TColgp_Array1OfVec.def("Move", (TColgp_Array1OfVec & (TColgp_Array1OfVec::*)(TColgp_Array1OfVec &&)) &TColgp_Array1OfVec::Move, "Move assignment", py::arg("theOther"));
	cls_TColgp_Array1OfVec.def("assign", (TColgp_Array1OfVec & (TColgp_Array1OfVec::*)(const TColgp_Array1OfVec &)) &TColgp_Array1OfVec::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_TColgp_Array1OfVec.def("assign", (TColgp_Array1OfVec & (TColgp_Array1OfVec::*)(TColgp_Array1OfVec &&)) &TColgp_Array1OfVec::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_TColgp_Array1OfVec.def("First", (const gp_Vec & (TColgp_Array1OfVec::*)() const ) &TColgp_Array1OfVec::First, "Returns first element");
	cls_TColgp_Array1OfVec.def("ChangeFirst", (gp_Vec & (TColgp_Array1OfVec::*)()) &TColgp_Array1OfVec::ChangeFirst, "Returns first element");
	cls_TColgp_Array1OfVec.def("Last", (const gp_Vec & (TColgp_Array1OfVec::*)() const ) &TColgp_Array1OfVec::Last, "Returns last element");
	cls_TColgp_Array1OfVec.def("ChangeLast", (gp_Vec & (TColgp_Array1OfVec::*)()) &TColgp_Array1OfVec::ChangeLast, "Returns last element");
	cls_TColgp_Array1OfVec.def("Value", (const gp_Vec & (TColgp_Array1OfVec::*)(const Standard_Integer) const ) &TColgp_Array1OfVec::Value, "Constant value access", py::arg("theIndex"));
	cls_TColgp_Array1OfVec.def("__call__", (const gp_Vec & (TColgp_Array1OfVec::*)(const Standard_Integer) const ) &TColgp_Array1OfVec::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_TColgp_Array1OfVec.def("ChangeValue", (gp_Vec & (TColgp_Array1OfVec::*)(const Standard_Integer)) &TColgp_Array1OfVec::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_TColgp_Array1OfVec.def("__call__", (gp_Vec & (TColgp_Array1OfVec::*)(const Standard_Integer)) &TColgp_Array1OfVec::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_TColgp_Array1OfVec.def("SetValue", (void (TColgp_Array1OfVec::*)(const Standard_Integer, const gp_Vec &)) &TColgp_Array1OfVec::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_TColgp_Array1OfVec.def("Resize", (void (TColgp_Array1OfVec::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &TColgp_Array1OfVec::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_TColgp_Array1OfVec.def("__iter__", [](const TColgp_Array1OfVec &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<TColgp_Array1OfVec2d, std::unique_ptr<TColgp_Array1OfVec2d, Deleter<TColgp_Array1OfVec2d>>> cls_TColgp_Array1OfVec2d(mod, "TColgp_Array1OfVec2d", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_TColgp_Array1OfVec2d.def(py::init<>());
	cls_TColgp_Array1OfVec2d.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColgp_Array1OfVec2d.def(py::init([] (const TColgp_Array1OfVec2d &other) {return new TColgp_Array1OfVec2d(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_TColgp_Array1OfVec2d.def(py::init<TColgp_Array1OfVec2d &&>(), py::arg("theOther"));
	cls_TColgp_Array1OfVec2d.def(py::init<const gp_Vec2d &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_TColgp_Array1OfVec2d.def("begin", (TColgp_Array1OfVec2d::iterator (TColgp_Array1OfVec2d::*)() const ) &TColgp_Array1OfVec2d::begin, "Returns an iterator pointing to the first element in the array.");
	cls_TColgp_Array1OfVec2d.def("end", (TColgp_Array1OfVec2d::iterator (TColgp_Array1OfVec2d::*)() const ) &TColgp_Array1OfVec2d::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_TColgp_Array1OfVec2d.def("cbegin", (TColgp_Array1OfVec2d::const_iterator (TColgp_Array1OfVec2d::*)() const ) &TColgp_Array1OfVec2d::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_TColgp_Array1OfVec2d.def("cend", (TColgp_Array1OfVec2d::const_iterator (TColgp_Array1OfVec2d::*)() const ) &TColgp_Array1OfVec2d::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_TColgp_Array1OfVec2d.def("Init", (void (TColgp_Array1OfVec2d::*)(const gp_Vec2d &)) &TColgp_Array1OfVec2d::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_TColgp_Array1OfVec2d.def("Size", (Standard_Integer (TColgp_Array1OfVec2d::*)() const ) &TColgp_Array1OfVec2d::Size, "Size query");
	cls_TColgp_Array1OfVec2d.def("Length", (Standard_Integer (TColgp_Array1OfVec2d::*)() const ) &TColgp_Array1OfVec2d::Length, "Length query (the same)");
	cls_TColgp_Array1OfVec2d.def("IsEmpty", (Standard_Boolean (TColgp_Array1OfVec2d::*)() const ) &TColgp_Array1OfVec2d::IsEmpty, "Return TRUE if array has zero length.");
	cls_TColgp_Array1OfVec2d.def("Lower", (Standard_Integer (TColgp_Array1OfVec2d::*)() const ) &TColgp_Array1OfVec2d::Lower, "Lower bound");
	cls_TColgp_Array1OfVec2d.def("Upper", (Standard_Integer (TColgp_Array1OfVec2d::*)() const ) &TColgp_Array1OfVec2d::Upper, "Upper bound");
	cls_TColgp_Array1OfVec2d.def("IsDeletable", (Standard_Boolean (TColgp_Array1OfVec2d::*)() const ) &TColgp_Array1OfVec2d::IsDeletable, "myDeletable flag");
	cls_TColgp_Array1OfVec2d.def("IsAllocated", (Standard_Boolean (TColgp_Array1OfVec2d::*)() const ) &TColgp_Array1OfVec2d::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_TColgp_Array1OfVec2d.def("Assign", (TColgp_Array1OfVec2d & (TColgp_Array1OfVec2d::*)(const TColgp_Array1OfVec2d &)) &TColgp_Array1OfVec2d::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_TColgp_Array1OfVec2d.def("Move", (TColgp_Array1OfVec2d & (TColgp_Array1OfVec2d::*)(TColgp_Array1OfVec2d &&)) &TColgp_Array1OfVec2d::Move, "Move assignment", py::arg("theOther"));
	cls_TColgp_Array1OfVec2d.def("assign", (TColgp_Array1OfVec2d & (TColgp_Array1OfVec2d::*)(const TColgp_Array1OfVec2d &)) &TColgp_Array1OfVec2d::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_TColgp_Array1OfVec2d.def("assign", (TColgp_Array1OfVec2d & (TColgp_Array1OfVec2d::*)(TColgp_Array1OfVec2d &&)) &TColgp_Array1OfVec2d::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_TColgp_Array1OfVec2d.def("First", (const gp_Vec2d & (TColgp_Array1OfVec2d::*)() const ) &TColgp_Array1OfVec2d::First, "Returns first element");
	cls_TColgp_Array1OfVec2d.def("ChangeFirst", (gp_Vec2d & (TColgp_Array1OfVec2d::*)()) &TColgp_Array1OfVec2d::ChangeFirst, "Returns first element");
	cls_TColgp_Array1OfVec2d.def("Last", (const gp_Vec2d & (TColgp_Array1OfVec2d::*)() const ) &TColgp_Array1OfVec2d::Last, "Returns last element");
	cls_TColgp_Array1OfVec2d.def("ChangeLast", (gp_Vec2d & (TColgp_Array1OfVec2d::*)()) &TColgp_Array1OfVec2d::ChangeLast, "Returns last element");
	cls_TColgp_Array1OfVec2d.def("Value", (const gp_Vec2d & (TColgp_Array1OfVec2d::*)(const Standard_Integer) const ) &TColgp_Array1OfVec2d::Value, "Constant value access", py::arg("theIndex"));
	cls_TColgp_Array1OfVec2d.def("__call__", (const gp_Vec2d & (TColgp_Array1OfVec2d::*)(const Standard_Integer) const ) &TColgp_Array1OfVec2d::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_TColgp_Array1OfVec2d.def("ChangeValue", (gp_Vec2d & (TColgp_Array1OfVec2d::*)(const Standard_Integer)) &TColgp_Array1OfVec2d::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_TColgp_Array1OfVec2d.def("__call__", (gp_Vec2d & (TColgp_Array1OfVec2d::*)(const Standard_Integer)) &TColgp_Array1OfVec2d::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_TColgp_Array1OfVec2d.def("SetValue", (void (TColgp_Array1OfVec2d::*)(const Standard_Integer, const gp_Vec2d &)) &TColgp_Array1OfVec2d::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_TColgp_Array1OfVec2d.def("Resize", (void (TColgp_Array1OfVec2d::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &TColgp_Array1OfVec2d::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_TColgp_Array1OfVec2d.def("__iter__", [](const TColgp_Array1OfVec2d &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array2.hxx
	py::class_<TColgp_Array2OfXYZ, std::unique_ptr<TColgp_Array2OfXYZ, Deleter<TColgp_Array2OfXYZ>>> cls_TColgp_Array2OfXYZ(mod, "TColgp_Array2OfXYZ", "Purpose: The class Array2 represents bi-dimensional arrays of fixed size known at run time. The ranges of indices are user defined.");
	cls_TColgp_Array2OfXYZ.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLower"), py::arg("theRowUpper"), py::arg("theColLower"), py::arg("theColUpper"));
	cls_TColgp_Array2OfXYZ.def(py::init([] (const TColgp_Array2OfXYZ &other) {return new TColgp_Array2OfXYZ(other);}), "Copy constructor", py::arg("other"));
	cls_TColgp_Array2OfXYZ.def(py::init<const gp_XYZ &, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theRowLower"), py::arg("theRowUpper"), py::arg("theColLower"), py::arg("theColUpper"));
	cls_TColgp_Array2OfXYZ.def("Init", (void (TColgp_Array2OfXYZ::*)(const gp_XYZ &)) &TColgp_Array2OfXYZ::Init, "Initialise the values", py::arg("theValue"));
	cls_TColgp_Array2OfXYZ.def("Size", (Standard_Integer (TColgp_Array2OfXYZ::*)() const ) &TColgp_Array2OfXYZ::Size, "Size (number of items)");
	cls_TColgp_Array2OfXYZ.def("Length", (Standard_Integer (TColgp_Array2OfXYZ::*)() const ) &TColgp_Array2OfXYZ::Length, "Length (number of items)");
	cls_TColgp_Array2OfXYZ.def("RowLength", (Standard_Integer (TColgp_Array2OfXYZ::*)() const ) &TColgp_Array2OfXYZ::RowLength, "Returns length of the row, i.e. number of columns");
	cls_TColgp_Array2OfXYZ.def("ColLength", (Standard_Integer (TColgp_Array2OfXYZ::*)() const ) &TColgp_Array2OfXYZ::ColLength, "Returns length of the column, i.e. number of rows");
	cls_TColgp_Array2OfXYZ.def("LowerRow", (Standard_Integer (TColgp_Array2OfXYZ::*)() const ) &TColgp_Array2OfXYZ::LowerRow, "LowerRow");
	cls_TColgp_Array2OfXYZ.def("UpperRow", (Standard_Integer (TColgp_Array2OfXYZ::*)() const ) &TColgp_Array2OfXYZ::UpperRow, "UpperRow");
	cls_TColgp_Array2OfXYZ.def("LowerCol", (Standard_Integer (TColgp_Array2OfXYZ::*)() const ) &TColgp_Array2OfXYZ::LowerCol, "LowerCol");
	cls_TColgp_Array2OfXYZ.def("UpperCol", (Standard_Integer (TColgp_Array2OfXYZ::*)() const ) &TColgp_Array2OfXYZ::UpperCol, "UpperCol");
	cls_TColgp_Array2OfXYZ.def("IsDeletable", (Standard_Boolean (TColgp_Array2OfXYZ::*)() const ) &TColgp_Array2OfXYZ::IsDeletable, "myDeletable flag");
	cls_TColgp_Array2OfXYZ.def("Assign", (TColgp_Array2OfXYZ & (TColgp_Array2OfXYZ::*)(const TColgp_Array2OfXYZ &)) &TColgp_Array2OfXYZ::Assign, "Assignment", py::arg("theOther"));
	cls_TColgp_Array2OfXYZ.def("assign", (TColgp_Array2OfXYZ & (TColgp_Array2OfXYZ::*)(const TColgp_Array2OfXYZ &)) &TColgp_Array2OfXYZ::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_TColgp_Array2OfXYZ.def("Value", (const gp_XYZ & (TColgp_Array2OfXYZ::*)(const Standard_Integer, const Standard_Integer) const ) &TColgp_Array2OfXYZ::Value, "Constant value access", py::arg("theRow"), py::arg("theCol"));
	cls_TColgp_Array2OfXYZ.def("__call__", (const gp_XYZ & (TColgp_Array2OfXYZ::*)(const Standard_Integer, const Standard_Integer) const ) &TColgp_Array2OfXYZ::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theRow"), py::arg("theCol"));
	cls_TColgp_Array2OfXYZ.def("ChangeValue", (gp_XYZ & (TColgp_Array2OfXYZ::*)(const Standard_Integer, const Standard_Integer)) &TColgp_Array2OfXYZ::ChangeValue, "Variable value access", py::arg("theRow"), py::arg("theCol"));
	cls_TColgp_Array2OfXYZ.def("__call__", (gp_XYZ & (TColgp_Array2OfXYZ::*)(const Standard_Integer, const Standard_Integer)) &TColgp_Array2OfXYZ::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theRow"), py::arg("theCol"));
	cls_TColgp_Array2OfXYZ.def("SetValue", (void (TColgp_Array2OfXYZ::*)(const Standard_Integer, const Standard_Integer, const gp_XYZ &)) &TColgp_Array2OfXYZ::SetValue, "SetValue", py::arg("theRow"), py::arg("theCol"), py::arg("theItem"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<TColgp_SequenceOfXY, std::unique_ptr<TColgp_SequenceOfXY, Deleter<TColgp_SequenceOfXY>>, NCollection_BaseSequence> cls_TColgp_SequenceOfXY(mod, "TColgp_SequenceOfXY", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_TColgp_SequenceOfXY.def(py::init<>());
	cls_TColgp_SequenceOfXY.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_TColgp_SequenceOfXY.def(py::init([] (const TColgp_SequenceOfXY &other) {return new TColgp_SequenceOfXY(other);}), "Copy constructor", py::arg("other"));
	cls_TColgp_SequenceOfXY.def("begin", (TColgp_SequenceOfXY::iterator (TColgp_SequenceOfXY::*)() const ) &TColgp_SequenceOfXY::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_TColgp_SequenceOfXY.def("end", (TColgp_SequenceOfXY::iterator (TColgp_SequenceOfXY::*)() const ) &TColgp_SequenceOfXY::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_TColgp_SequenceOfXY.def("cbegin", (TColgp_SequenceOfXY::const_iterator (TColgp_SequenceOfXY::*)() const ) &TColgp_SequenceOfXY::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_TColgp_SequenceOfXY.def("cend", (TColgp_SequenceOfXY::const_iterator (TColgp_SequenceOfXY::*)() const ) &TColgp_SequenceOfXY::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_TColgp_SequenceOfXY.def("Size", (Standard_Integer (TColgp_SequenceOfXY::*)() const ) &TColgp_SequenceOfXY::Size, "Number of items");
	cls_TColgp_SequenceOfXY.def("Length", (Standard_Integer (TColgp_SequenceOfXY::*)() const ) &TColgp_SequenceOfXY::Length, "Number of items");
	cls_TColgp_SequenceOfXY.def("Lower", (Standard_Integer (TColgp_SequenceOfXY::*)() const ) &TColgp_SequenceOfXY::Lower, "Method for consistency with other collections.");
	cls_TColgp_SequenceOfXY.def("Upper", (Standard_Integer (TColgp_SequenceOfXY::*)() const ) &TColgp_SequenceOfXY::Upper, "Method for consistency with other collections.");
	cls_TColgp_SequenceOfXY.def("IsEmpty", (Standard_Boolean (TColgp_SequenceOfXY::*)() const ) &TColgp_SequenceOfXY::IsEmpty, "Empty query");
	cls_TColgp_SequenceOfXY.def("Reverse", (void (TColgp_SequenceOfXY::*)()) &TColgp_SequenceOfXY::Reverse, "Reverse sequence");
	cls_TColgp_SequenceOfXY.def("Exchange", (void (TColgp_SequenceOfXY::*)(const Standard_Integer, const Standard_Integer)) &TColgp_SequenceOfXY::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_TColgp_SequenceOfXY.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_SequenceOfXY::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_TColgp_SequenceOfXY.def("Clear", [](TColgp_SequenceOfXY &self) -> void { return self.Clear(); });
	cls_TColgp_SequenceOfXY.def("Clear", (void (TColgp_SequenceOfXY::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_SequenceOfXY::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_TColgp_SequenceOfXY.def("Assign", (TColgp_SequenceOfXY & (TColgp_SequenceOfXY::*)(const TColgp_SequenceOfXY &)) &TColgp_SequenceOfXY::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TColgp_SequenceOfXY.def("assign", (TColgp_SequenceOfXY & (TColgp_SequenceOfXY::*)(const TColgp_SequenceOfXY &)) &TColgp_SequenceOfXY::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_TColgp_SequenceOfXY.def("Remove", (void (TColgp_SequenceOfXY::*)(TColgp_SequenceOfXY::Iterator &)) &TColgp_SequenceOfXY::Remove, "Remove one item", py::arg("thePosition"));
	cls_TColgp_SequenceOfXY.def("Remove", (void (TColgp_SequenceOfXY::*)(const Standard_Integer)) &TColgp_SequenceOfXY::Remove, "Remove one item", py::arg("theIndex"));
	cls_TColgp_SequenceOfXY.def("Remove", (void (TColgp_SequenceOfXY::*)(const Standard_Integer, const Standard_Integer)) &TColgp_SequenceOfXY::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_TColgp_SequenceOfXY.def("Append", (void (TColgp_SequenceOfXY::*)(const gp_XY &)) &TColgp_SequenceOfXY::Append, "Append one item", py::arg("theItem"));
	cls_TColgp_SequenceOfXY.def("Append", (void (TColgp_SequenceOfXY::*)(TColgp_SequenceOfXY &)) &TColgp_SequenceOfXY::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_TColgp_SequenceOfXY.def("Prepend", (void (TColgp_SequenceOfXY::*)(const gp_XY &)) &TColgp_SequenceOfXY::Prepend, "Prepend one item", py::arg("theItem"));
	cls_TColgp_SequenceOfXY.def("Prepend", (void (TColgp_SequenceOfXY::*)(TColgp_SequenceOfXY &)) &TColgp_SequenceOfXY::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_TColgp_SequenceOfXY.def("InsertBefore", (void (TColgp_SequenceOfXY::*)(const Standard_Integer, const gp_XY &)) &TColgp_SequenceOfXY::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_TColgp_SequenceOfXY.def("InsertBefore", (void (TColgp_SequenceOfXY::*)(const Standard_Integer, TColgp_SequenceOfXY &)) &TColgp_SequenceOfXY::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColgp_SequenceOfXY.def("InsertAfter", (void (TColgp_SequenceOfXY::*)(TColgp_SequenceOfXY::Iterator &, const gp_XY &)) &TColgp_SequenceOfXY::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_TColgp_SequenceOfXY.def("InsertAfter", (void (TColgp_SequenceOfXY::*)(const Standard_Integer, TColgp_SequenceOfXY &)) &TColgp_SequenceOfXY::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColgp_SequenceOfXY.def("InsertAfter", (void (TColgp_SequenceOfXY::*)(const Standard_Integer, const gp_XY &)) &TColgp_SequenceOfXY::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_TColgp_SequenceOfXY.def("Split", (void (TColgp_SequenceOfXY::*)(const Standard_Integer, TColgp_SequenceOfXY &)) &TColgp_SequenceOfXY::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColgp_SequenceOfXY.def("First", (const gp_XY & (TColgp_SequenceOfXY::*)() const ) &TColgp_SequenceOfXY::First, "First item access");
	cls_TColgp_SequenceOfXY.def("ChangeFirst", (gp_XY & (TColgp_SequenceOfXY::*)()) &TColgp_SequenceOfXY::ChangeFirst, "First item access");
	cls_TColgp_SequenceOfXY.def("Last", (const gp_XY & (TColgp_SequenceOfXY::*)() const ) &TColgp_SequenceOfXY::Last, "Last item access");
	cls_TColgp_SequenceOfXY.def("ChangeLast", (gp_XY & (TColgp_SequenceOfXY::*)()) &TColgp_SequenceOfXY::ChangeLast, "Last item access");
	cls_TColgp_SequenceOfXY.def("Value", (const gp_XY & (TColgp_SequenceOfXY::*)(const Standard_Integer) const ) &TColgp_SequenceOfXY::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_TColgp_SequenceOfXY.def("__call__", (const gp_XY & (TColgp_SequenceOfXY::*)(const Standard_Integer) const ) &TColgp_SequenceOfXY::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_TColgp_SequenceOfXY.def("ChangeValue", (gp_XY & (TColgp_SequenceOfXY::*)(const Standard_Integer)) &TColgp_SequenceOfXY::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_TColgp_SequenceOfXY.def("__call__", (gp_XY & (TColgp_SequenceOfXY::*)(const Standard_Integer)) &TColgp_SequenceOfXY::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_TColgp_SequenceOfXY.def("SetValue", (void (TColgp_SequenceOfXY::*)(const Standard_Integer, const gp_XY &)) &TColgp_SequenceOfXY::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_TColgp_SequenceOfXY.def("__iter__", [](const TColgp_SequenceOfXY &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<TColgp_Array1OfXYZ, std::unique_ptr<TColgp_Array1OfXYZ, Deleter<TColgp_Array1OfXYZ>>> cls_TColgp_Array1OfXYZ(mod, "TColgp_Array1OfXYZ", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_TColgp_Array1OfXYZ.def(py::init<>());
	cls_TColgp_Array1OfXYZ.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColgp_Array1OfXYZ.def(py::init([] (const TColgp_Array1OfXYZ &other) {return new TColgp_Array1OfXYZ(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_TColgp_Array1OfXYZ.def(py::init<TColgp_Array1OfXYZ &&>(), py::arg("theOther"));
	cls_TColgp_Array1OfXYZ.def(py::init<const gp_XYZ &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_TColgp_Array1OfXYZ.def("begin", (TColgp_Array1OfXYZ::iterator (TColgp_Array1OfXYZ::*)() const ) &TColgp_Array1OfXYZ::begin, "Returns an iterator pointing to the first element in the array.");
	cls_TColgp_Array1OfXYZ.def("end", (TColgp_Array1OfXYZ::iterator (TColgp_Array1OfXYZ::*)() const ) &TColgp_Array1OfXYZ::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_TColgp_Array1OfXYZ.def("cbegin", (TColgp_Array1OfXYZ::const_iterator (TColgp_Array1OfXYZ::*)() const ) &TColgp_Array1OfXYZ::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_TColgp_Array1OfXYZ.def("cend", (TColgp_Array1OfXYZ::const_iterator (TColgp_Array1OfXYZ::*)() const ) &TColgp_Array1OfXYZ::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_TColgp_Array1OfXYZ.def("Init", (void (TColgp_Array1OfXYZ::*)(const gp_XYZ &)) &TColgp_Array1OfXYZ::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_TColgp_Array1OfXYZ.def("Size", (Standard_Integer (TColgp_Array1OfXYZ::*)() const ) &TColgp_Array1OfXYZ::Size, "Size query");
	cls_TColgp_Array1OfXYZ.def("Length", (Standard_Integer (TColgp_Array1OfXYZ::*)() const ) &TColgp_Array1OfXYZ::Length, "Length query (the same)");
	cls_TColgp_Array1OfXYZ.def("IsEmpty", (Standard_Boolean (TColgp_Array1OfXYZ::*)() const ) &TColgp_Array1OfXYZ::IsEmpty, "Return TRUE if array has zero length.");
	cls_TColgp_Array1OfXYZ.def("Lower", (Standard_Integer (TColgp_Array1OfXYZ::*)() const ) &TColgp_Array1OfXYZ::Lower, "Lower bound");
	cls_TColgp_Array1OfXYZ.def("Upper", (Standard_Integer (TColgp_Array1OfXYZ::*)() const ) &TColgp_Array1OfXYZ::Upper, "Upper bound");
	cls_TColgp_Array1OfXYZ.def("IsDeletable", (Standard_Boolean (TColgp_Array1OfXYZ::*)() const ) &TColgp_Array1OfXYZ::IsDeletable, "myDeletable flag");
	cls_TColgp_Array1OfXYZ.def("IsAllocated", (Standard_Boolean (TColgp_Array1OfXYZ::*)() const ) &TColgp_Array1OfXYZ::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_TColgp_Array1OfXYZ.def("Assign", (TColgp_Array1OfXYZ & (TColgp_Array1OfXYZ::*)(const TColgp_Array1OfXYZ &)) &TColgp_Array1OfXYZ::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_TColgp_Array1OfXYZ.def("Move", (TColgp_Array1OfXYZ & (TColgp_Array1OfXYZ::*)(TColgp_Array1OfXYZ &&)) &TColgp_Array1OfXYZ::Move, "Move assignment", py::arg("theOther"));
	cls_TColgp_Array1OfXYZ.def("assign", (TColgp_Array1OfXYZ & (TColgp_Array1OfXYZ::*)(const TColgp_Array1OfXYZ &)) &TColgp_Array1OfXYZ::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_TColgp_Array1OfXYZ.def("assign", (TColgp_Array1OfXYZ & (TColgp_Array1OfXYZ::*)(TColgp_Array1OfXYZ &&)) &TColgp_Array1OfXYZ::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_TColgp_Array1OfXYZ.def("First", (const gp_XYZ & (TColgp_Array1OfXYZ::*)() const ) &TColgp_Array1OfXYZ::First, "Returns first element");
	cls_TColgp_Array1OfXYZ.def("ChangeFirst", (gp_XYZ & (TColgp_Array1OfXYZ::*)()) &TColgp_Array1OfXYZ::ChangeFirst, "Returns first element");
	cls_TColgp_Array1OfXYZ.def("Last", (const gp_XYZ & (TColgp_Array1OfXYZ::*)() const ) &TColgp_Array1OfXYZ::Last, "Returns last element");
	cls_TColgp_Array1OfXYZ.def("ChangeLast", (gp_XYZ & (TColgp_Array1OfXYZ::*)()) &TColgp_Array1OfXYZ::ChangeLast, "Returns last element");
	cls_TColgp_Array1OfXYZ.def("Value", (const gp_XYZ & (TColgp_Array1OfXYZ::*)(const Standard_Integer) const ) &TColgp_Array1OfXYZ::Value, "Constant value access", py::arg("theIndex"));
	cls_TColgp_Array1OfXYZ.def("__call__", (const gp_XYZ & (TColgp_Array1OfXYZ::*)(const Standard_Integer) const ) &TColgp_Array1OfXYZ::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_TColgp_Array1OfXYZ.def("ChangeValue", (gp_XYZ & (TColgp_Array1OfXYZ::*)(const Standard_Integer)) &TColgp_Array1OfXYZ::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_TColgp_Array1OfXYZ.def("__call__", (gp_XYZ & (TColgp_Array1OfXYZ::*)(const Standard_Integer)) &TColgp_Array1OfXYZ::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_TColgp_Array1OfXYZ.def("SetValue", (void (TColgp_Array1OfXYZ::*)(const Standard_Integer, const gp_XYZ &)) &TColgp_Array1OfXYZ::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_TColgp_Array1OfXYZ.def("Resize", (void (TColgp_Array1OfXYZ::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &TColgp_Array1OfXYZ::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_TColgp_Array1OfXYZ.def("__iter__", [](const TColgp_Array1OfXYZ &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<TColgp_Array1OfXY, std::unique_ptr<TColgp_Array1OfXY, Deleter<TColgp_Array1OfXY>>> cls_TColgp_Array1OfXY(mod, "TColgp_Array1OfXY", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_TColgp_Array1OfXY.def(py::init<>());
	cls_TColgp_Array1OfXY.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColgp_Array1OfXY.def(py::init([] (const TColgp_Array1OfXY &other) {return new TColgp_Array1OfXY(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_TColgp_Array1OfXY.def(py::init<TColgp_Array1OfXY &&>(), py::arg("theOther"));
	cls_TColgp_Array1OfXY.def(py::init<const gp_XY &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_TColgp_Array1OfXY.def("begin", (TColgp_Array1OfXY::iterator (TColgp_Array1OfXY::*)() const ) &TColgp_Array1OfXY::begin, "Returns an iterator pointing to the first element in the array.");
	cls_TColgp_Array1OfXY.def("end", (TColgp_Array1OfXY::iterator (TColgp_Array1OfXY::*)() const ) &TColgp_Array1OfXY::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_TColgp_Array1OfXY.def("cbegin", (TColgp_Array1OfXY::const_iterator (TColgp_Array1OfXY::*)() const ) &TColgp_Array1OfXY::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_TColgp_Array1OfXY.def("cend", (TColgp_Array1OfXY::const_iterator (TColgp_Array1OfXY::*)() const ) &TColgp_Array1OfXY::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_TColgp_Array1OfXY.def("Init", (void (TColgp_Array1OfXY::*)(const gp_XY &)) &TColgp_Array1OfXY::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_TColgp_Array1OfXY.def("Size", (Standard_Integer (TColgp_Array1OfXY::*)() const ) &TColgp_Array1OfXY::Size, "Size query");
	cls_TColgp_Array1OfXY.def("Length", (Standard_Integer (TColgp_Array1OfXY::*)() const ) &TColgp_Array1OfXY::Length, "Length query (the same)");
	cls_TColgp_Array1OfXY.def("IsEmpty", (Standard_Boolean (TColgp_Array1OfXY::*)() const ) &TColgp_Array1OfXY::IsEmpty, "Return TRUE if array has zero length.");
	cls_TColgp_Array1OfXY.def("Lower", (Standard_Integer (TColgp_Array1OfXY::*)() const ) &TColgp_Array1OfXY::Lower, "Lower bound");
	cls_TColgp_Array1OfXY.def("Upper", (Standard_Integer (TColgp_Array1OfXY::*)() const ) &TColgp_Array1OfXY::Upper, "Upper bound");
	cls_TColgp_Array1OfXY.def("IsDeletable", (Standard_Boolean (TColgp_Array1OfXY::*)() const ) &TColgp_Array1OfXY::IsDeletable, "myDeletable flag");
	cls_TColgp_Array1OfXY.def("IsAllocated", (Standard_Boolean (TColgp_Array1OfXY::*)() const ) &TColgp_Array1OfXY::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_TColgp_Array1OfXY.def("Assign", (TColgp_Array1OfXY & (TColgp_Array1OfXY::*)(const TColgp_Array1OfXY &)) &TColgp_Array1OfXY::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_TColgp_Array1OfXY.def("Move", (TColgp_Array1OfXY & (TColgp_Array1OfXY::*)(TColgp_Array1OfXY &&)) &TColgp_Array1OfXY::Move, "Move assignment", py::arg("theOther"));
	cls_TColgp_Array1OfXY.def("assign", (TColgp_Array1OfXY & (TColgp_Array1OfXY::*)(const TColgp_Array1OfXY &)) &TColgp_Array1OfXY::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_TColgp_Array1OfXY.def("assign", (TColgp_Array1OfXY & (TColgp_Array1OfXY::*)(TColgp_Array1OfXY &&)) &TColgp_Array1OfXY::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_TColgp_Array1OfXY.def("First", (const gp_XY & (TColgp_Array1OfXY::*)() const ) &TColgp_Array1OfXY::First, "Returns first element");
	cls_TColgp_Array1OfXY.def("ChangeFirst", (gp_XY & (TColgp_Array1OfXY::*)()) &TColgp_Array1OfXY::ChangeFirst, "Returns first element");
	cls_TColgp_Array1OfXY.def("Last", (const gp_XY & (TColgp_Array1OfXY::*)() const ) &TColgp_Array1OfXY::Last, "Returns last element");
	cls_TColgp_Array1OfXY.def("ChangeLast", (gp_XY & (TColgp_Array1OfXY::*)()) &TColgp_Array1OfXY::ChangeLast, "Returns last element");
	cls_TColgp_Array1OfXY.def("Value", (const gp_XY & (TColgp_Array1OfXY::*)(const Standard_Integer) const ) &TColgp_Array1OfXY::Value, "Constant value access", py::arg("theIndex"));
	cls_TColgp_Array1OfXY.def("__call__", (const gp_XY & (TColgp_Array1OfXY::*)(const Standard_Integer) const ) &TColgp_Array1OfXY::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_TColgp_Array1OfXY.def("ChangeValue", (gp_XY & (TColgp_Array1OfXY::*)(const Standard_Integer)) &TColgp_Array1OfXY::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_TColgp_Array1OfXY.def("__call__", (gp_XY & (TColgp_Array1OfXY::*)(const Standard_Integer)) &TColgp_Array1OfXY::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_TColgp_Array1OfXY.def("SetValue", (void (TColgp_Array1OfXY::*)(const Standard_Integer, const gp_XY &)) &TColgp_Array1OfXY::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_TColgp_Array1OfXY.def("Resize", (void (TColgp_Array1OfXY::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &TColgp_Array1OfXY::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_TColgp_Array1OfXY.def("__iter__", [](const TColgp_Array1OfXY &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<TColgp_SequenceOfXYZ, std::unique_ptr<TColgp_SequenceOfXYZ, Deleter<TColgp_SequenceOfXYZ>>, NCollection_BaseSequence> cls_TColgp_SequenceOfXYZ(mod, "TColgp_SequenceOfXYZ", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_TColgp_SequenceOfXYZ.def(py::init<>());
	cls_TColgp_SequenceOfXYZ.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_TColgp_SequenceOfXYZ.def(py::init([] (const TColgp_SequenceOfXYZ &other) {return new TColgp_SequenceOfXYZ(other);}), "Copy constructor", py::arg("other"));
	cls_TColgp_SequenceOfXYZ.def("begin", (TColgp_SequenceOfXYZ::iterator (TColgp_SequenceOfXYZ::*)() const ) &TColgp_SequenceOfXYZ::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_TColgp_SequenceOfXYZ.def("end", (TColgp_SequenceOfXYZ::iterator (TColgp_SequenceOfXYZ::*)() const ) &TColgp_SequenceOfXYZ::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_TColgp_SequenceOfXYZ.def("cbegin", (TColgp_SequenceOfXYZ::const_iterator (TColgp_SequenceOfXYZ::*)() const ) &TColgp_SequenceOfXYZ::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_TColgp_SequenceOfXYZ.def("cend", (TColgp_SequenceOfXYZ::const_iterator (TColgp_SequenceOfXYZ::*)() const ) &TColgp_SequenceOfXYZ::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_TColgp_SequenceOfXYZ.def("Size", (Standard_Integer (TColgp_SequenceOfXYZ::*)() const ) &TColgp_SequenceOfXYZ::Size, "Number of items");
	cls_TColgp_SequenceOfXYZ.def("Length", (Standard_Integer (TColgp_SequenceOfXYZ::*)() const ) &TColgp_SequenceOfXYZ::Length, "Number of items");
	cls_TColgp_SequenceOfXYZ.def("Lower", (Standard_Integer (TColgp_SequenceOfXYZ::*)() const ) &TColgp_SequenceOfXYZ::Lower, "Method for consistency with other collections.");
	cls_TColgp_SequenceOfXYZ.def("Upper", (Standard_Integer (TColgp_SequenceOfXYZ::*)() const ) &TColgp_SequenceOfXYZ::Upper, "Method for consistency with other collections.");
	cls_TColgp_SequenceOfXYZ.def("IsEmpty", (Standard_Boolean (TColgp_SequenceOfXYZ::*)() const ) &TColgp_SequenceOfXYZ::IsEmpty, "Empty query");
	cls_TColgp_SequenceOfXYZ.def("Reverse", (void (TColgp_SequenceOfXYZ::*)()) &TColgp_SequenceOfXYZ::Reverse, "Reverse sequence");
	cls_TColgp_SequenceOfXYZ.def("Exchange", (void (TColgp_SequenceOfXYZ::*)(const Standard_Integer, const Standard_Integer)) &TColgp_SequenceOfXYZ::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_TColgp_SequenceOfXYZ.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_SequenceOfXYZ::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_TColgp_SequenceOfXYZ.def("Clear", [](TColgp_SequenceOfXYZ &self) -> void { return self.Clear(); });
	cls_TColgp_SequenceOfXYZ.def("Clear", (void (TColgp_SequenceOfXYZ::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_SequenceOfXYZ::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_TColgp_SequenceOfXYZ.def("Assign", (TColgp_SequenceOfXYZ & (TColgp_SequenceOfXYZ::*)(const TColgp_SequenceOfXYZ &)) &TColgp_SequenceOfXYZ::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TColgp_SequenceOfXYZ.def("assign", (TColgp_SequenceOfXYZ & (TColgp_SequenceOfXYZ::*)(const TColgp_SequenceOfXYZ &)) &TColgp_SequenceOfXYZ::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_TColgp_SequenceOfXYZ.def("Remove", (void (TColgp_SequenceOfXYZ::*)(TColgp_SequenceOfXYZ::Iterator &)) &TColgp_SequenceOfXYZ::Remove, "Remove one item", py::arg("thePosition"));
	cls_TColgp_SequenceOfXYZ.def("Remove", (void (TColgp_SequenceOfXYZ::*)(const Standard_Integer)) &TColgp_SequenceOfXYZ::Remove, "Remove one item", py::arg("theIndex"));
	cls_TColgp_SequenceOfXYZ.def("Remove", (void (TColgp_SequenceOfXYZ::*)(const Standard_Integer, const Standard_Integer)) &TColgp_SequenceOfXYZ::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_TColgp_SequenceOfXYZ.def("Append", (void (TColgp_SequenceOfXYZ::*)(const gp_XYZ &)) &TColgp_SequenceOfXYZ::Append, "Append one item", py::arg("theItem"));
	cls_TColgp_SequenceOfXYZ.def("Append", (void (TColgp_SequenceOfXYZ::*)(TColgp_SequenceOfXYZ &)) &TColgp_SequenceOfXYZ::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_TColgp_SequenceOfXYZ.def("Prepend", (void (TColgp_SequenceOfXYZ::*)(const gp_XYZ &)) &TColgp_SequenceOfXYZ::Prepend, "Prepend one item", py::arg("theItem"));
	cls_TColgp_SequenceOfXYZ.def("Prepend", (void (TColgp_SequenceOfXYZ::*)(TColgp_SequenceOfXYZ &)) &TColgp_SequenceOfXYZ::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_TColgp_SequenceOfXYZ.def("InsertBefore", (void (TColgp_SequenceOfXYZ::*)(const Standard_Integer, const gp_XYZ &)) &TColgp_SequenceOfXYZ::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_TColgp_SequenceOfXYZ.def("InsertBefore", (void (TColgp_SequenceOfXYZ::*)(const Standard_Integer, TColgp_SequenceOfXYZ &)) &TColgp_SequenceOfXYZ::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColgp_SequenceOfXYZ.def("InsertAfter", (void (TColgp_SequenceOfXYZ::*)(TColgp_SequenceOfXYZ::Iterator &, const gp_XYZ &)) &TColgp_SequenceOfXYZ::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_TColgp_SequenceOfXYZ.def("InsertAfter", (void (TColgp_SequenceOfXYZ::*)(const Standard_Integer, TColgp_SequenceOfXYZ &)) &TColgp_SequenceOfXYZ::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColgp_SequenceOfXYZ.def("InsertAfter", (void (TColgp_SequenceOfXYZ::*)(const Standard_Integer, const gp_XYZ &)) &TColgp_SequenceOfXYZ::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_TColgp_SequenceOfXYZ.def("Split", (void (TColgp_SequenceOfXYZ::*)(const Standard_Integer, TColgp_SequenceOfXYZ &)) &TColgp_SequenceOfXYZ::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColgp_SequenceOfXYZ.def("First", (const gp_XYZ & (TColgp_SequenceOfXYZ::*)() const ) &TColgp_SequenceOfXYZ::First, "First item access");
	cls_TColgp_SequenceOfXYZ.def("ChangeFirst", (gp_XYZ & (TColgp_SequenceOfXYZ::*)()) &TColgp_SequenceOfXYZ::ChangeFirst, "First item access");
	cls_TColgp_SequenceOfXYZ.def("Last", (const gp_XYZ & (TColgp_SequenceOfXYZ::*)() const ) &TColgp_SequenceOfXYZ::Last, "Last item access");
	cls_TColgp_SequenceOfXYZ.def("ChangeLast", (gp_XYZ & (TColgp_SequenceOfXYZ::*)()) &TColgp_SequenceOfXYZ::ChangeLast, "Last item access");
	cls_TColgp_SequenceOfXYZ.def("Value", (const gp_XYZ & (TColgp_SequenceOfXYZ::*)(const Standard_Integer) const ) &TColgp_SequenceOfXYZ::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_TColgp_SequenceOfXYZ.def("__call__", (const gp_XYZ & (TColgp_SequenceOfXYZ::*)(const Standard_Integer) const ) &TColgp_SequenceOfXYZ::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_TColgp_SequenceOfXYZ.def("ChangeValue", (gp_XYZ & (TColgp_SequenceOfXYZ::*)(const Standard_Integer)) &TColgp_SequenceOfXYZ::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_TColgp_SequenceOfXYZ.def("__call__", (gp_XYZ & (TColgp_SequenceOfXYZ::*)(const Standard_Integer)) &TColgp_SequenceOfXYZ::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_TColgp_SequenceOfXYZ.def("SetValue", (void (TColgp_SequenceOfXYZ::*)(const Standard_Integer, const gp_XYZ &)) &TColgp_SequenceOfXYZ::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_TColgp_SequenceOfXYZ.def("__iter__", [](const TColgp_SequenceOfXYZ &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<TColgp_Array1OfDir2d, std::unique_ptr<TColgp_Array1OfDir2d, Deleter<TColgp_Array1OfDir2d>>> cls_TColgp_Array1OfDir2d(mod, "TColgp_Array1OfDir2d", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_TColgp_Array1OfDir2d.def(py::init<>());
	cls_TColgp_Array1OfDir2d.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColgp_Array1OfDir2d.def(py::init([] (const TColgp_Array1OfDir2d &other) {return new TColgp_Array1OfDir2d(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_TColgp_Array1OfDir2d.def(py::init<TColgp_Array1OfDir2d &&>(), py::arg("theOther"));
	cls_TColgp_Array1OfDir2d.def(py::init<const gp_Dir2d &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_TColgp_Array1OfDir2d.def("begin", (TColgp_Array1OfDir2d::iterator (TColgp_Array1OfDir2d::*)() const ) &TColgp_Array1OfDir2d::begin, "Returns an iterator pointing to the first element in the array.");
	cls_TColgp_Array1OfDir2d.def("end", (TColgp_Array1OfDir2d::iterator (TColgp_Array1OfDir2d::*)() const ) &TColgp_Array1OfDir2d::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_TColgp_Array1OfDir2d.def("cbegin", (TColgp_Array1OfDir2d::const_iterator (TColgp_Array1OfDir2d::*)() const ) &TColgp_Array1OfDir2d::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_TColgp_Array1OfDir2d.def("cend", (TColgp_Array1OfDir2d::const_iterator (TColgp_Array1OfDir2d::*)() const ) &TColgp_Array1OfDir2d::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_TColgp_Array1OfDir2d.def("Init", (void (TColgp_Array1OfDir2d::*)(const gp_Dir2d &)) &TColgp_Array1OfDir2d::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_TColgp_Array1OfDir2d.def("Size", (Standard_Integer (TColgp_Array1OfDir2d::*)() const ) &TColgp_Array1OfDir2d::Size, "Size query");
	cls_TColgp_Array1OfDir2d.def("Length", (Standard_Integer (TColgp_Array1OfDir2d::*)() const ) &TColgp_Array1OfDir2d::Length, "Length query (the same)");
	cls_TColgp_Array1OfDir2d.def("IsEmpty", (Standard_Boolean (TColgp_Array1OfDir2d::*)() const ) &TColgp_Array1OfDir2d::IsEmpty, "Return TRUE if array has zero length.");
	cls_TColgp_Array1OfDir2d.def("Lower", (Standard_Integer (TColgp_Array1OfDir2d::*)() const ) &TColgp_Array1OfDir2d::Lower, "Lower bound");
	cls_TColgp_Array1OfDir2d.def("Upper", (Standard_Integer (TColgp_Array1OfDir2d::*)() const ) &TColgp_Array1OfDir2d::Upper, "Upper bound");
	cls_TColgp_Array1OfDir2d.def("IsDeletable", (Standard_Boolean (TColgp_Array1OfDir2d::*)() const ) &TColgp_Array1OfDir2d::IsDeletable, "myDeletable flag");
	cls_TColgp_Array1OfDir2d.def("IsAllocated", (Standard_Boolean (TColgp_Array1OfDir2d::*)() const ) &TColgp_Array1OfDir2d::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_TColgp_Array1OfDir2d.def("Assign", (TColgp_Array1OfDir2d & (TColgp_Array1OfDir2d::*)(const TColgp_Array1OfDir2d &)) &TColgp_Array1OfDir2d::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_TColgp_Array1OfDir2d.def("Move", (TColgp_Array1OfDir2d & (TColgp_Array1OfDir2d::*)(TColgp_Array1OfDir2d &&)) &TColgp_Array1OfDir2d::Move, "Move assignment", py::arg("theOther"));
	cls_TColgp_Array1OfDir2d.def("assign", (TColgp_Array1OfDir2d & (TColgp_Array1OfDir2d::*)(const TColgp_Array1OfDir2d &)) &TColgp_Array1OfDir2d::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_TColgp_Array1OfDir2d.def("assign", (TColgp_Array1OfDir2d & (TColgp_Array1OfDir2d::*)(TColgp_Array1OfDir2d &&)) &TColgp_Array1OfDir2d::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_TColgp_Array1OfDir2d.def("First", (const gp_Dir2d & (TColgp_Array1OfDir2d::*)() const ) &TColgp_Array1OfDir2d::First, "Returns first element");
	cls_TColgp_Array1OfDir2d.def("ChangeFirst", (gp_Dir2d & (TColgp_Array1OfDir2d::*)()) &TColgp_Array1OfDir2d::ChangeFirst, "Returns first element");
	cls_TColgp_Array1OfDir2d.def("Last", (const gp_Dir2d & (TColgp_Array1OfDir2d::*)() const ) &TColgp_Array1OfDir2d::Last, "Returns last element");
	cls_TColgp_Array1OfDir2d.def("ChangeLast", (gp_Dir2d & (TColgp_Array1OfDir2d::*)()) &TColgp_Array1OfDir2d::ChangeLast, "Returns last element");
	cls_TColgp_Array1OfDir2d.def("Value", (const gp_Dir2d & (TColgp_Array1OfDir2d::*)(const Standard_Integer) const ) &TColgp_Array1OfDir2d::Value, "Constant value access", py::arg("theIndex"));
	cls_TColgp_Array1OfDir2d.def("__call__", (const gp_Dir2d & (TColgp_Array1OfDir2d::*)(const Standard_Integer) const ) &TColgp_Array1OfDir2d::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_TColgp_Array1OfDir2d.def("ChangeValue", (gp_Dir2d & (TColgp_Array1OfDir2d::*)(const Standard_Integer)) &TColgp_Array1OfDir2d::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_TColgp_Array1OfDir2d.def("__call__", (gp_Dir2d & (TColgp_Array1OfDir2d::*)(const Standard_Integer)) &TColgp_Array1OfDir2d::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_TColgp_Array1OfDir2d.def("SetValue", (void (TColgp_Array1OfDir2d::*)(const Standard_Integer, const gp_Dir2d &)) &TColgp_Array1OfDir2d::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_TColgp_Array1OfDir2d.def("Resize", (void (TColgp_Array1OfDir2d::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &TColgp_Array1OfDir2d::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_TColgp_Array1OfDir2d.def("__iter__", [](const TColgp_Array1OfDir2d &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<TColgp_Array1OfLin2d, std::unique_ptr<TColgp_Array1OfLin2d, Deleter<TColgp_Array1OfLin2d>>> cls_TColgp_Array1OfLin2d(mod, "TColgp_Array1OfLin2d", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_TColgp_Array1OfLin2d.def(py::init<>());
	cls_TColgp_Array1OfLin2d.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColgp_Array1OfLin2d.def(py::init([] (const TColgp_Array1OfLin2d &other) {return new TColgp_Array1OfLin2d(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_TColgp_Array1OfLin2d.def(py::init<TColgp_Array1OfLin2d &&>(), py::arg("theOther"));
	cls_TColgp_Array1OfLin2d.def(py::init<const gp_Lin2d &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_TColgp_Array1OfLin2d.def("begin", (TColgp_Array1OfLin2d::iterator (TColgp_Array1OfLin2d::*)() const ) &TColgp_Array1OfLin2d::begin, "Returns an iterator pointing to the first element in the array.");
	cls_TColgp_Array1OfLin2d.def("end", (TColgp_Array1OfLin2d::iterator (TColgp_Array1OfLin2d::*)() const ) &TColgp_Array1OfLin2d::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_TColgp_Array1OfLin2d.def("cbegin", (TColgp_Array1OfLin2d::const_iterator (TColgp_Array1OfLin2d::*)() const ) &TColgp_Array1OfLin2d::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_TColgp_Array1OfLin2d.def("cend", (TColgp_Array1OfLin2d::const_iterator (TColgp_Array1OfLin2d::*)() const ) &TColgp_Array1OfLin2d::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_TColgp_Array1OfLin2d.def("Init", (void (TColgp_Array1OfLin2d::*)(const gp_Lin2d &)) &TColgp_Array1OfLin2d::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_TColgp_Array1OfLin2d.def("Size", (Standard_Integer (TColgp_Array1OfLin2d::*)() const ) &TColgp_Array1OfLin2d::Size, "Size query");
	cls_TColgp_Array1OfLin2d.def("Length", (Standard_Integer (TColgp_Array1OfLin2d::*)() const ) &TColgp_Array1OfLin2d::Length, "Length query (the same)");
	cls_TColgp_Array1OfLin2d.def("IsEmpty", (Standard_Boolean (TColgp_Array1OfLin2d::*)() const ) &TColgp_Array1OfLin2d::IsEmpty, "Return TRUE if array has zero length.");
	cls_TColgp_Array1OfLin2d.def("Lower", (Standard_Integer (TColgp_Array1OfLin2d::*)() const ) &TColgp_Array1OfLin2d::Lower, "Lower bound");
	cls_TColgp_Array1OfLin2d.def("Upper", (Standard_Integer (TColgp_Array1OfLin2d::*)() const ) &TColgp_Array1OfLin2d::Upper, "Upper bound");
	cls_TColgp_Array1OfLin2d.def("IsDeletable", (Standard_Boolean (TColgp_Array1OfLin2d::*)() const ) &TColgp_Array1OfLin2d::IsDeletable, "myDeletable flag");
	cls_TColgp_Array1OfLin2d.def("IsAllocated", (Standard_Boolean (TColgp_Array1OfLin2d::*)() const ) &TColgp_Array1OfLin2d::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_TColgp_Array1OfLin2d.def("Assign", (TColgp_Array1OfLin2d & (TColgp_Array1OfLin2d::*)(const TColgp_Array1OfLin2d &)) &TColgp_Array1OfLin2d::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_TColgp_Array1OfLin2d.def("Move", (TColgp_Array1OfLin2d & (TColgp_Array1OfLin2d::*)(TColgp_Array1OfLin2d &&)) &TColgp_Array1OfLin2d::Move, "Move assignment", py::arg("theOther"));
	cls_TColgp_Array1OfLin2d.def("assign", (TColgp_Array1OfLin2d & (TColgp_Array1OfLin2d::*)(const TColgp_Array1OfLin2d &)) &TColgp_Array1OfLin2d::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_TColgp_Array1OfLin2d.def("assign", (TColgp_Array1OfLin2d & (TColgp_Array1OfLin2d::*)(TColgp_Array1OfLin2d &&)) &TColgp_Array1OfLin2d::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_TColgp_Array1OfLin2d.def("First", (const gp_Lin2d & (TColgp_Array1OfLin2d::*)() const ) &TColgp_Array1OfLin2d::First, "Returns first element");
	cls_TColgp_Array1OfLin2d.def("ChangeFirst", (gp_Lin2d & (TColgp_Array1OfLin2d::*)()) &TColgp_Array1OfLin2d::ChangeFirst, "Returns first element");
	cls_TColgp_Array1OfLin2d.def("Last", (const gp_Lin2d & (TColgp_Array1OfLin2d::*)() const ) &TColgp_Array1OfLin2d::Last, "Returns last element");
	cls_TColgp_Array1OfLin2d.def("ChangeLast", (gp_Lin2d & (TColgp_Array1OfLin2d::*)()) &TColgp_Array1OfLin2d::ChangeLast, "Returns last element");
	cls_TColgp_Array1OfLin2d.def("Value", (const gp_Lin2d & (TColgp_Array1OfLin2d::*)(const Standard_Integer) const ) &TColgp_Array1OfLin2d::Value, "Constant value access", py::arg("theIndex"));
	cls_TColgp_Array1OfLin2d.def("__call__", (const gp_Lin2d & (TColgp_Array1OfLin2d::*)(const Standard_Integer) const ) &TColgp_Array1OfLin2d::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_TColgp_Array1OfLin2d.def("ChangeValue", (gp_Lin2d & (TColgp_Array1OfLin2d::*)(const Standard_Integer)) &TColgp_Array1OfLin2d::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_TColgp_Array1OfLin2d.def("__call__", (gp_Lin2d & (TColgp_Array1OfLin2d::*)(const Standard_Integer)) &TColgp_Array1OfLin2d::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_TColgp_Array1OfLin2d.def("SetValue", (void (TColgp_Array1OfLin2d::*)(const Standard_Integer, const gp_Lin2d &)) &TColgp_Array1OfLin2d::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_TColgp_Array1OfLin2d.def("Resize", (void (TColgp_Array1OfLin2d::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &TColgp_Array1OfLin2d::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_TColgp_Array1OfLin2d.def("__iter__", [](const TColgp_Array1OfLin2d &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array1.hxx
	py::class_<TColgp_Array1OfCirc2d, std::unique_ptr<TColgp_Array1OfCirc2d, Deleter<TColgp_Array1OfCirc2d>>> cls_TColgp_Array1OfCirc2d(mod, "TColgp_Array1OfCirc2d", "Purpose: The class Array1 represents unidimensional arrays of fixed size known at run time. The range of the index is user defined. An array1 can be constructed with a 'C array'. This functionality is useful to call methods expecting an Array1. It allows to carry the bounds inside the arrays.");
	cls_TColgp_Array1OfCirc2d.def(py::init<>());
	cls_TColgp_Array1OfCirc2d.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColgp_Array1OfCirc2d.def(py::init([] (const TColgp_Array1OfCirc2d &other) {return new TColgp_Array1OfCirc2d(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_TColgp_Array1OfCirc2d.def(py::init<TColgp_Array1OfCirc2d &&>(), py::arg("theOther"));
	cls_TColgp_Array1OfCirc2d.def(py::init<const gp_Circ2d &, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theLower"), py::arg("theUpper"));
	cls_TColgp_Array1OfCirc2d.def("begin", (TColgp_Array1OfCirc2d::iterator (TColgp_Array1OfCirc2d::*)() const ) &TColgp_Array1OfCirc2d::begin, "Returns an iterator pointing to the first element in the array.");
	cls_TColgp_Array1OfCirc2d.def("end", (TColgp_Array1OfCirc2d::iterator (TColgp_Array1OfCirc2d::*)() const ) &TColgp_Array1OfCirc2d::end, "Returns an iterator referring to the past-the-end element in the array.");
	cls_TColgp_Array1OfCirc2d.def("cbegin", (TColgp_Array1OfCirc2d::const_iterator (TColgp_Array1OfCirc2d::*)() const ) &TColgp_Array1OfCirc2d::cbegin, "Returns a const iterator pointing to the first element in the array.");
	cls_TColgp_Array1OfCirc2d.def("cend", (TColgp_Array1OfCirc2d::const_iterator (TColgp_Array1OfCirc2d::*)() const ) &TColgp_Array1OfCirc2d::cend, "Returns a const iterator referring to the past-the-end element in the array.");
	cls_TColgp_Array1OfCirc2d.def("Init", (void (TColgp_Array1OfCirc2d::*)(const gp_Circ2d &)) &TColgp_Array1OfCirc2d::Init, "Initialise the items with theValue", py::arg("theValue"));
	cls_TColgp_Array1OfCirc2d.def("Size", (Standard_Integer (TColgp_Array1OfCirc2d::*)() const ) &TColgp_Array1OfCirc2d::Size, "Size query");
	cls_TColgp_Array1OfCirc2d.def("Length", (Standard_Integer (TColgp_Array1OfCirc2d::*)() const ) &TColgp_Array1OfCirc2d::Length, "Length query (the same)");
	cls_TColgp_Array1OfCirc2d.def("IsEmpty", (Standard_Boolean (TColgp_Array1OfCirc2d::*)() const ) &TColgp_Array1OfCirc2d::IsEmpty, "Return TRUE if array has zero length.");
	cls_TColgp_Array1OfCirc2d.def("Lower", (Standard_Integer (TColgp_Array1OfCirc2d::*)() const ) &TColgp_Array1OfCirc2d::Lower, "Lower bound");
	cls_TColgp_Array1OfCirc2d.def("Upper", (Standard_Integer (TColgp_Array1OfCirc2d::*)() const ) &TColgp_Array1OfCirc2d::Upper, "Upper bound");
	cls_TColgp_Array1OfCirc2d.def("IsDeletable", (Standard_Boolean (TColgp_Array1OfCirc2d::*)() const ) &TColgp_Array1OfCirc2d::IsDeletable, "myDeletable flag");
	cls_TColgp_Array1OfCirc2d.def("IsAllocated", (Standard_Boolean (TColgp_Array1OfCirc2d::*)() const ) &TColgp_Array1OfCirc2d::IsAllocated, "IsAllocated flag - for naming compatibility");
	cls_TColgp_Array1OfCirc2d.def("Assign", (TColgp_Array1OfCirc2d & (TColgp_Array1OfCirc2d::*)(const TColgp_Array1OfCirc2d &)) &TColgp_Array1OfCirc2d::Assign, "Assignment", py::arg("theOther"));
	// FIXME cls_TColgp_Array1OfCirc2d.def("Move", (TColgp_Array1OfCirc2d & (TColgp_Array1OfCirc2d::*)(TColgp_Array1OfCirc2d &&)) &TColgp_Array1OfCirc2d::Move, "Move assignment", py::arg("theOther"));
	cls_TColgp_Array1OfCirc2d.def("assign", (TColgp_Array1OfCirc2d & (TColgp_Array1OfCirc2d::*)(const TColgp_Array1OfCirc2d &)) &TColgp_Array1OfCirc2d::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	// FIXME cls_TColgp_Array1OfCirc2d.def("assign", (TColgp_Array1OfCirc2d & (TColgp_Array1OfCirc2d::*)(TColgp_Array1OfCirc2d &&)) &TColgp_Array1OfCirc2d::operator=, py::is_operator(), "Move assignment operator.", py::arg("theOther"));
	cls_TColgp_Array1OfCirc2d.def("First", (const gp_Circ2d & (TColgp_Array1OfCirc2d::*)() const ) &TColgp_Array1OfCirc2d::First, "Returns first element");
	cls_TColgp_Array1OfCirc2d.def("ChangeFirst", (gp_Circ2d & (TColgp_Array1OfCirc2d::*)()) &TColgp_Array1OfCirc2d::ChangeFirst, "Returns first element");
	cls_TColgp_Array1OfCirc2d.def("Last", (const gp_Circ2d & (TColgp_Array1OfCirc2d::*)() const ) &TColgp_Array1OfCirc2d::Last, "Returns last element");
	cls_TColgp_Array1OfCirc2d.def("ChangeLast", (gp_Circ2d & (TColgp_Array1OfCirc2d::*)()) &TColgp_Array1OfCirc2d::ChangeLast, "Returns last element");
	cls_TColgp_Array1OfCirc2d.def("Value", (const gp_Circ2d & (TColgp_Array1OfCirc2d::*)(const Standard_Integer) const ) &TColgp_Array1OfCirc2d::Value, "Constant value access", py::arg("theIndex"));
	cls_TColgp_Array1OfCirc2d.def("__call__", (const gp_Circ2d & (TColgp_Array1OfCirc2d::*)(const Standard_Integer) const ) &TColgp_Array1OfCirc2d::operator(), py::is_operator(), "operator() - alias to Value", py::arg("theIndex"));
	cls_TColgp_Array1OfCirc2d.def("ChangeValue", (gp_Circ2d & (TColgp_Array1OfCirc2d::*)(const Standard_Integer)) &TColgp_Array1OfCirc2d::ChangeValue, "Variable value access", py::arg("theIndex"));
	cls_TColgp_Array1OfCirc2d.def("__call__", (gp_Circ2d & (TColgp_Array1OfCirc2d::*)(const Standard_Integer)) &TColgp_Array1OfCirc2d::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theIndex"));
	cls_TColgp_Array1OfCirc2d.def("SetValue", (void (TColgp_Array1OfCirc2d::*)(const Standard_Integer, const gp_Circ2d &)) &TColgp_Array1OfCirc2d::SetValue, "Set value", py::arg("theIndex"), py::arg("theItem"));
	cls_TColgp_Array1OfCirc2d.def("Resize", (void (TColgp_Array1OfCirc2d::*)(const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &TColgp_Array1OfCirc2d::Resize, "Resizes the array to specified bounds. No re-allocation will be done if length of array does not change, but existing values will not be discarded if theToCopyData set to FALSE.", py::arg("theLower"), py::arg("theUpper"), py::arg("theToCopyData"));
	cls_TColgp_Array1OfCirc2d.def("__iter__", [](const TColgp_Array1OfCirc2d &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array2.hxx
	py::class_<TColgp_Array2OfDir, std::unique_ptr<TColgp_Array2OfDir, Deleter<TColgp_Array2OfDir>>> cls_TColgp_Array2OfDir(mod, "TColgp_Array2OfDir", "Purpose: The class Array2 represents bi-dimensional arrays of fixed size known at run time. The ranges of indices are user defined.");
	cls_TColgp_Array2OfDir.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLower"), py::arg("theRowUpper"), py::arg("theColLower"), py::arg("theColUpper"));
	cls_TColgp_Array2OfDir.def(py::init([] (const TColgp_Array2OfDir &other) {return new TColgp_Array2OfDir(other);}), "Copy constructor", py::arg("other"));
	cls_TColgp_Array2OfDir.def(py::init<const gp_Dir &, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theRowLower"), py::arg("theRowUpper"), py::arg("theColLower"), py::arg("theColUpper"));
	cls_TColgp_Array2OfDir.def("Init", (void (TColgp_Array2OfDir::*)(const gp_Dir &)) &TColgp_Array2OfDir::Init, "Initialise the values", py::arg("theValue"));
	cls_TColgp_Array2OfDir.def("Size", (Standard_Integer (TColgp_Array2OfDir::*)() const ) &TColgp_Array2OfDir::Size, "Size (number of items)");
	cls_TColgp_Array2OfDir.def("Length", (Standard_Integer (TColgp_Array2OfDir::*)() const ) &TColgp_Array2OfDir::Length, "Length (number of items)");
	cls_TColgp_Array2OfDir.def("RowLength", (Standard_Integer (TColgp_Array2OfDir::*)() const ) &TColgp_Array2OfDir::RowLength, "Returns length of the row, i.e. number of columns");
	cls_TColgp_Array2OfDir.def("ColLength", (Standard_Integer (TColgp_Array2OfDir::*)() const ) &TColgp_Array2OfDir::ColLength, "Returns length of the column, i.e. number of rows");
	cls_TColgp_Array2OfDir.def("LowerRow", (Standard_Integer (TColgp_Array2OfDir::*)() const ) &TColgp_Array2OfDir::LowerRow, "LowerRow");
	cls_TColgp_Array2OfDir.def("UpperRow", (Standard_Integer (TColgp_Array2OfDir::*)() const ) &TColgp_Array2OfDir::UpperRow, "UpperRow");
	cls_TColgp_Array2OfDir.def("LowerCol", (Standard_Integer (TColgp_Array2OfDir::*)() const ) &TColgp_Array2OfDir::LowerCol, "LowerCol");
	cls_TColgp_Array2OfDir.def("UpperCol", (Standard_Integer (TColgp_Array2OfDir::*)() const ) &TColgp_Array2OfDir::UpperCol, "UpperCol");
	cls_TColgp_Array2OfDir.def("IsDeletable", (Standard_Boolean (TColgp_Array2OfDir::*)() const ) &TColgp_Array2OfDir::IsDeletable, "myDeletable flag");
	cls_TColgp_Array2OfDir.def("Assign", (TColgp_Array2OfDir & (TColgp_Array2OfDir::*)(const TColgp_Array2OfDir &)) &TColgp_Array2OfDir::Assign, "Assignment", py::arg("theOther"));
	cls_TColgp_Array2OfDir.def("assign", (TColgp_Array2OfDir & (TColgp_Array2OfDir::*)(const TColgp_Array2OfDir &)) &TColgp_Array2OfDir::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_TColgp_Array2OfDir.def("Value", (const gp_Dir & (TColgp_Array2OfDir::*)(const Standard_Integer, const Standard_Integer) const ) &TColgp_Array2OfDir::Value, "Constant value access", py::arg("theRow"), py::arg("theCol"));
	cls_TColgp_Array2OfDir.def("__call__", (const gp_Dir & (TColgp_Array2OfDir::*)(const Standard_Integer, const Standard_Integer) const ) &TColgp_Array2OfDir::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theRow"), py::arg("theCol"));
	cls_TColgp_Array2OfDir.def("ChangeValue", (gp_Dir & (TColgp_Array2OfDir::*)(const Standard_Integer, const Standard_Integer)) &TColgp_Array2OfDir::ChangeValue, "Variable value access", py::arg("theRow"), py::arg("theCol"));
	cls_TColgp_Array2OfDir.def("__call__", (gp_Dir & (TColgp_Array2OfDir::*)(const Standard_Integer, const Standard_Integer)) &TColgp_Array2OfDir::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theRow"), py::arg("theCol"));
	cls_TColgp_Array2OfDir.def("SetValue", (void (TColgp_Array2OfDir::*)(const Standard_Integer, const Standard_Integer, const gp_Dir &)) &TColgp_Array2OfDir::SetValue, "SetValue", py::arg("theRow"), py::arg("theCol"), py::arg("theItem"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array2.hxx
	py::class_<TColgp_Array2OfVec, std::unique_ptr<TColgp_Array2OfVec, Deleter<TColgp_Array2OfVec>>> cls_TColgp_Array2OfVec(mod, "TColgp_Array2OfVec", "Purpose: The class Array2 represents bi-dimensional arrays of fixed size known at run time. The ranges of indices are user defined.");
	cls_TColgp_Array2OfVec.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLower"), py::arg("theRowUpper"), py::arg("theColLower"), py::arg("theColUpper"));
	cls_TColgp_Array2OfVec.def(py::init([] (const TColgp_Array2OfVec &other) {return new TColgp_Array2OfVec(other);}), "Copy constructor", py::arg("other"));
	cls_TColgp_Array2OfVec.def(py::init<const gp_Vec &, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theRowLower"), py::arg("theRowUpper"), py::arg("theColLower"), py::arg("theColUpper"));
	cls_TColgp_Array2OfVec.def("Init", (void (TColgp_Array2OfVec::*)(const gp_Vec &)) &TColgp_Array2OfVec::Init, "Initialise the values", py::arg("theValue"));
	cls_TColgp_Array2OfVec.def("Size", (Standard_Integer (TColgp_Array2OfVec::*)() const ) &TColgp_Array2OfVec::Size, "Size (number of items)");
	cls_TColgp_Array2OfVec.def("Length", (Standard_Integer (TColgp_Array2OfVec::*)() const ) &TColgp_Array2OfVec::Length, "Length (number of items)");
	cls_TColgp_Array2OfVec.def("RowLength", (Standard_Integer (TColgp_Array2OfVec::*)() const ) &TColgp_Array2OfVec::RowLength, "Returns length of the row, i.e. number of columns");
	cls_TColgp_Array2OfVec.def("ColLength", (Standard_Integer (TColgp_Array2OfVec::*)() const ) &TColgp_Array2OfVec::ColLength, "Returns length of the column, i.e. number of rows");
	cls_TColgp_Array2OfVec.def("LowerRow", (Standard_Integer (TColgp_Array2OfVec::*)() const ) &TColgp_Array2OfVec::LowerRow, "LowerRow");
	cls_TColgp_Array2OfVec.def("UpperRow", (Standard_Integer (TColgp_Array2OfVec::*)() const ) &TColgp_Array2OfVec::UpperRow, "UpperRow");
	cls_TColgp_Array2OfVec.def("LowerCol", (Standard_Integer (TColgp_Array2OfVec::*)() const ) &TColgp_Array2OfVec::LowerCol, "LowerCol");
	cls_TColgp_Array2OfVec.def("UpperCol", (Standard_Integer (TColgp_Array2OfVec::*)() const ) &TColgp_Array2OfVec::UpperCol, "UpperCol");
	cls_TColgp_Array2OfVec.def("IsDeletable", (Standard_Boolean (TColgp_Array2OfVec::*)() const ) &TColgp_Array2OfVec::IsDeletable, "myDeletable flag");
	cls_TColgp_Array2OfVec.def("Assign", (TColgp_Array2OfVec & (TColgp_Array2OfVec::*)(const TColgp_Array2OfVec &)) &TColgp_Array2OfVec::Assign, "Assignment", py::arg("theOther"));
	cls_TColgp_Array2OfVec.def("assign", (TColgp_Array2OfVec & (TColgp_Array2OfVec::*)(const TColgp_Array2OfVec &)) &TColgp_Array2OfVec::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_TColgp_Array2OfVec.def("Value", (const gp_Vec & (TColgp_Array2OfVec::*)(const Standard_Integer, const Standard_Integer) const ) &TColgp_Array2OfVec::Value, "Constant value access", py::arg("theRow"), py::arg("theCol"));
	cls_TColgp_Array2OfVec.def("__call__", (const gp_Vec & (TColgp_Array2OfVec::*)(const Standard_Integer, const Standard_Integer) const ) &TColgp_Array2OfVec::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theRow"), py::arg("theCol"));
	cls_TColgp_Array2OfVec.def("ChangeValue", (gp_Vec & (TColgp_Array2OfVec::*)(const Standard_Integer, const Standard_Integer)) &TColgp_Array2OfVec::ChangeValue, "Variable value access", py::arg("theRow"), py::arg("theCol"));
	cls_TColgp_Array2OfVec.def("__call__", (gp_Vec & (TColgp_Array2OfVec::*)(const Standard_Integer, const Standard_Integer)) &TColgp_Array2OfVec::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theRow"), py::arg("theCol"));
	cls_TColgp_Array2OfVec.def("SetValue", (void (TColgp_Array2OfVec::*)(const Standard_Integer, const Standard_Integer, const gp_Vec &)) &TColgp_Array2OfVec::SetValue, "SetValue", py::arg("theRow"), py::arg("theCol"), py::arg("theItem"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array2.hxx
	py::class_<TColgp_Array2OfXY, std::unique_ptr<TColgp_Array2OfXY, Deleter<TColgp_Array2OfXY>>> cls_TColgp_Array2OfXY(mod, "TColgp_Array2OfXY", "Purpose: The class Array2 represents bi-dimensional arrays of fixed size known at run time. The ranges of indices are user defined.");
	cls_TColgp_Array2OfXY.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLower"), py::arg("theRowUpper"), py::arg("theColLower"), py::arg("theColUpper"));
	cls_TColgp_Array2OfXY.def(py::init([] (const TColgp_Array2OfXY &other) {return new TColgp_Array2OfXY(other);}), "Copy constructor", py::arg("other"));
	cls_TColgp_Array2OfXY.def(py::init<const gp_XY &, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theRowLower"), py::arg("theRowUpper"), py::arg("theColLower"), py::arg("theColUpper"));
	cls_TColgp_Array2OfXY.def("Init", (void (TColgp_Array2OfXY::*)(const gp_XY &)) &TColgp_Array2OfXY::Init, "Initialise the values", py::arg("theValue"));
	cls_TColgp_Array2OfXY.def("Size", (Standard_Integer (TColgp_Array2OfXY::*)() const ) &TColgp_Array2OfXY::Size, "Size (number of items)");
	cls_TColgp_Array2OfXY.def("Length", (Standard_Integer (TColgp_Array2OfXY::*)() const ) &TColgp_Array2OfXY::Length, "Length (number of items)");
	cls_TColgp_Array2OfXY.def("RowLength", (Standard_Integer (TColgp_Array2OfXY::*)() const ) &TColgp_Array2OfXY::RowLength, "Returns length of the row, i.e. number of columns");
	cls_TColgp_Array2OfXY.def("ColLength", (Standard_Integer (TColgp_Array2OfXY::*)() const ) &TColgp_Array2OfXY::ColLength, "Returns length of the column, i.e. number of rows");
	cls_TColgp_Array2OfXY.def("LowerRow", (Standard_Integer (TColgp_Array2OfXY::*)() const ) &TColgp_Array2OfXY::LowerRow, "LowerRow");
	cls_TColgp_Array2OfXY.def("UpperRow", (Standard_Integer (TColgp_Array2OfXY::*)() const ) &TColgp_Array2OfXY::UpperRow, "UpperRow");
	cls_TColgp_Array2OfXY.def("LowerCol", (Standard_Integer (TColgp_Array2OfXY::*)() const ) &TColgp_Array2OfXY::LowerCol, "LowerCol");
	cls_TColgp_Array2OfXY.def("UpperCol", (Standard_Integer (TColgp_Array2OfXY::*)() const ) &TColgp_Array2OfXY::UpperCol, "UpperCol");
	cls_TColgp_Array2OfXY.def("IsDeletable", (Standard_Boolean (TColgp_Array2OfXY::*)() const ) &TColgp_Array2OfXY::IsDeletable, "myDeletable flag");
	cls_TColgp_Array2OfXY.def("Assign", (TColgp_Array2OfXY & (TColgp_Array2OfXY::*)(const TColgp_Array2OfXY &)) &TColgp_Array2OfXY::Assign, "Assignment", py::arg("theOther"));
	cls_TColgp_Array2OfXY.def("assign", (TColgp_Array2OfXY & (TColgp_Array2OfXY::*)(const TColgp_Array2OfXY &)) &TColgp_Array2OfXY::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_TColgp_Array2OfXY.def("Value", (const gp_XY & (TColgp_Array2OfXY::*)(const Standard_Integer, const Standard_Integer) const ) &TColgp_Array2OfXY::Value, "Constant value access", py::arg("theRow"), py::arg("theCol"));
	cls_TColgp_Array2OfXY.def("__call__", (const gp_XY & (TColgp_Array2OfXY::*)(const Standard_Integer, const Standard_Integer) const ) &TColgp_Array2OfXY::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theRow"), py::arg("theCol"));
	cls_TColgp_Array2OfXY.def("ChangeValue", (gp_XY & (TColgp_Array2OfXY::*)(const Standard_Integer, const Standard_Integer)) &TColgp_Array2OfXY::ChangeValue, "Variable value access", py::arg("theRow"), py::arg("theCol"));
	cls_TColgp_Array2OfXY.def("__call__", (gp_XY & (TColgp_Array2OfXY::*)(const Standard_Integer, const Standard_Integer)) &TColgp_Array2OfXY::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theRow"), py::arg("theCol"));
	cls_TColgp_Array2OfXY.def("SetValue", (void (TColgp_Array2OfXY::*)(const Standard_Integer, const Standard_Integer, const gp_XY &)) &TColgp_Array2OfXY::SetValue, "SetValue", py::arg("theRow"), py::arg("theCol"), py::arg("theItem"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array2.hxx
	py::class_<TColgp_Array2OfDir2d, std::unique_ptr<TColgp_Array2OfDir2d, Deleter<TColgp_Array2OfDir2d>>> cls_TColgp_Array2OfDir2d(mod, "TColgp_Array2OfDir2d", "Purpose: The class Array2 represents bi-dimensional arrays of fixed size known at run time. The ranges of indices are user defined.");
	cls_TColgp_Array2OfDir2d.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLower"), py::arg("theRowUpper"), py::arg("theColLower"), py::arg("theColUpper"));
	cls_TColgp_Array2OfDir2d.def(py::init([] (const TColgp_Array2OfDir2d &other) {return new TColgp_Array2OfDir2d(other);}), "Copy constructor", py::arg("other"));
	cls_TColgp_Array2OfDir2d.def(py::init<const gp_Dir2d &, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theRowLower"), py::arg("theRowUpper"), py::arg("theColLower"), py::arg("theColUpper"));
	cls_TColgp_Array2OfDir2d.def("Init", (void (TColgp_Array2OfDir2d::*)(const gp_Dir2d &)) &TColgp_Array2OfDir2d::Init, "Initialise the values", py::arg("theValue"));
	cls_TColgp_Array2OfDir2d.def("Size", (Standard_Integer (TColgp_Array2OfDir2d::*)() const ) &TColgp_Array2OfDir2d::Size, "Size (number of items)");
	cls_TColgp_Array2OfDir2d.def("Length", (Standard_Integer (TColgp_Array2OfDir2d::*)() const ) &TColgp_Array2OfDir2d::Length, "Length (number of items)");
	cls_TColgp_Array2OfDir2d.def("RowLength", (Standard_Integer (TColgp_Array2OfDir2d::*)() const ) &TColgp_Array2OfDir2d::RowLength, "Returns length of the row, i.e. number of columns");
	cls_TColgp_Array2OfDir2d.def("ColLength", (Standard_Integer (TColgp_Array2OfDir2d::*)() const ) &TColgp_Array2OfDir2d::ColLength, "Returns length of the column, i.e. number of rows");
	cls_TColgp_Array2OfDir2d.def("LowerRow", (Standard_Integer (TColgp_Array2OfDir2d::*)() const ) &TColgp_Array2OfDir2d::LowerRow, "LowerRow");
	cls_TColgp_Array2OfDir2d.def("UpperRow", (Standard_Integer (TColgp_Array2OfDir2d::*)() const ) &TColgp_Array2OfDir2d::UpperRow, "UpperRow");
	cls_TColgp_Array2OfDir2d.def("LowerCol", (Standard_Integer (TColgp_Array2OfDir2d::*)() const ) &TColgp_Array2OfDir2d::LowerCol, "LowerCol");
	cls_TColgp_Array2OfDir2d.def("UpperCol", (Standard_Integer (TColgp_Array2OfDir2d::*)() const ) &TColgp_Array2OfDir2d::UpperCol, "UpperCol");
	cls_TColgp_Array2OfDir2d.def("IsDeletable", (Standard_Boolean (TColgp_Array2OfDir2d::*)() const ) &TColgp_Array2OfDir2d::IsDeletable, "myDeletable flag");
	cls_TColgp_Array2OfDir2d.def("Assign", (TColgp_Array2OfDir2d & (TColgp_Array2OfDir2d::*)(const TColgp_Array2OfDir2d &)) &TColgp_Array2OfDir2d::Assign, "Assignment", py::arg("theOther"));
	cls_TColgp_Array2OfDir2d.def("assign", (TColgp_Array2OfDir2d & (TColgp_Array2OfDir2d::*)(const TColgp_Array2OfDir2d &)) &TColgp_Array2OfDir2d::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_TColgp_Array2OfDir2d.def("Value", (const gp_Dir2d & (TColgp_Array2OfDir2d::*)(const Standard_Integer, const Standard_Integer) const ) &TColgp_Array2OfDir2d::Value, "Constant value access", py::arg("theRow"), py::arg("theCol"));
	cls_TColgp_Array2OfDir2d.def("__call__", (const gp_Dir2d & (TColgp_Array2OfDir2d::*)(const Standard_Integer, const Standard_Integer) const ) &TColgp_Array2OfDir2d::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theRow"), py::arg("theCol"));
	cls_TColgp_Array2OfDir2d.def("ChangeValue", (gp_Dir2d & (TColgp_Array2OfDir2d::*)(const Standard_Integer, const Standard_Integer)) &TColgp_Array2OfDir2d::ChangeValue, "Variable value access", py::arg("theRow"), py::arg("theCol"));
	cls_TColgp_Array2OfDir2d.def("__call__", (gp_Dir2d & (TColgp_Array2OfDir2d::*)(const Standard_Integer, const Standard_Integer)) &TColgp_Array2OfDir2d::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theRow"), py::arg("theCol"));
	cls_TColgp_Array2OfDir2d.def("SetValue", (void (TColgp_Array2OfDir2d::*)(const Standard_Integer, const Standard_Integer, const gp_Dir2d &)) &TColgp_Array2OfDir2d::SetValue, "SetValue", py::arg("theRow"), py::arg("theCol"), py::arg("theItem"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array2.hxx
	py::class_<TColgp_Array2OfVec2d, std::unique_ptr<TColgp_Array2OfVec2d, Deleter<TColgp_Array2OfVec2d>>> cls_TColgp_Array2OfVec2d(mod, "TColgp_Array2OfVec2d", "Purpose: The class Array2 represents bi-dimensional arrays of fixed size known at run time. The ranges of indices are user defined.");
	cls_TColgp_Array2OfVec2d.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLower"), py::arg("theRowUpper"), py::arg("theColLower"), py::arg("theColUpper"));
	cls_TColgp_Array2OfVec2d.def(py::init([] (const TColgp_Array2OfVec2d &other) {return new TColgp_Array2OfVec2d(other);}), "Copy constructor", py::arg("other"));
	cls_TColgp_Array2OfVec2d.def(py::init<const gp_Vec2d &, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theRowLower"), py::arg("theRowUpper"), py::arg("theColLower"), py::arg("theColUpper"));
	cls_TColgp_Array2OfVec2d.def("Init", (void (TColgp_Array2OfVec2d::*)(const gp_Vec2d &)) &TColgp_Array2OfVec2d::Init, "Initialise the values", py::arg("theValue"));
	cls_TColgp_Array2OfVec2d.def("Size", (Standard_Integer (TColgp_Array2OfVec2d::*)() const ) &TColgp_Array2OfVec2d::Size, "Size (number of items)");
	cls_TColgp_Array2OfVec2d.def("Length", (Standard_Integer (TColgp_Array2OfVec2d::*)() const ) &TColgp_Array2OfVec2d::Length, "Length (number of items)");
	cls_TColgp_Array2OfVec2d.def("RowLength", (Standard_Integer (TColgp_Array2OfVec2d::*)() const ) &TColgp_Array2OfVec2d::RowLength, "Returns length of the row, i.e. number of columns");
	cls_TColgp_Array2OfVec2d.def("ColLength", (Standard_Integer (TColgp_Array2OfVec2d::*)() const ) &TColgp_Array2OfVec2d::ColLength, "Returns length of the column, i.e. number of rows");
	cls_TColgp_Array2OfVec2d.def("LowerRow", (Standard_Integer (TColgp_Array2OfVec2d::*)() const ) &TColgp_Array2OfVec2d::LowerRow, "LowerRow");
	cls_TColgp_Array2OfVec2d.def("UpperRow", (Standard_Integer (TColgp_Array2OfVec2d::*)() const ) &TColgp_Array2OfVec2d::UpperRow, "UpperRow");
	cls_TColgp_Array2OfVec2d.def("LowerCol", (Standard_Integer (TColgp_Array2OfVec2d::*)() const ) &TColgp_Array2OfVec2d::LowerCol, "LowerCol");
	cls_TColgp_Array2OfVec2d.def("UpperCol", (Standard_Integer (TColgp_Array2OfVec2d::*)() const ) &TColgp_Array2OfVec2d::UpperCol, "UpperCol");
	cls_TColgp_Array2OfVec2d.def("IsDeletable", (Standard_Boolean (TColgp_Array2OfVec2d::*)() const ) &TColgp_Array2OfVec2d::IsDeletable, "myDeletable flag");
	cls_TColgp_Array2OfVec2d.def("Assign", (TColgp_Array2OfVec2d & (TColgp_Array2OfVec2d::*)(const TColgp_Array2OfVec2d &)) &TColgp_Array2OfVec2d::Assign, "Assignment", py::arg("theOther"));
	cls_TColgp_Array2OfVec2d.def("assign", (TColgp_Array2OfVec2d & (TColgp_Array2OfVec2d::*)(const TColgp_Array2OfVec2d &)) &TColgp_Array2OfVec2d::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_TColgp_Array2OfVec2d.def("Value", (const gp_Vec2d & (TColgp_Array2OfVec2d::*)(const Standard_Integer, const Standard_Integer) const ) &TColgp_Array2OfVec2d::Value, "Constant value access", py::arg("theRow"), py::arg("theCol"));
	cls_TColgp_Array2OfVec2d.def("__call__", (const gp_Vec2d & (TColgp_Array2OfVec2d::*)(const Standard_Integer, const Standard_Integer) const ) &TColgp_Array2OfVec2d::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theRow"), py::arg("theCol"));
	cls_TColgp_Array2OfVec2d.def("ChangeValue", (gp_Vec2d & (TColgp_Array2OfVec2d::*)(const Standard_Integer, const Standard_Integer)) &TColgp_Array2OfVec2d::ChangeValue, "Variable value access", py::arg("theRow"), py::arg("theCol"));
	cls_TColgp_Array2OfVec2d.def("__call__", (gp_Vec2d & (TColgp_Array2OfVec2d::*)(const Standard_Integer, const Standard_Integer)) &TColgp_Array2OfVec2d::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theRow"), py::arg("theCol"));
	cls_TColgp_Array2OfVec2d.def("SetValue", (void (TColgp_Array2OfVec2d::*)(const Standard_Integer, const Standard_Integer, const gp_Vec2d &)) &TColgp_Array2OfVec2d::SetValue, "SetValue", py::arg("theRow"), py::arg("theCol"), py::arg("theItem"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array2.hxx
	py::class_<TColgp_Array2OfLin2d, std::unique_ptr<TColgp_Array2OfLin2d, Deleter<TColgp_Array2OfLin2d>>> cls_TColgp_Array2OfLin2d(mod, "TColgp_Array2OfLin2d", "Purpose: The class Array2 represents bi-dimensional arrays of fixed size known at run time. The ranges of indices are user defined.");
	cls_TColgp_Array2OfLin2d.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLower"), py::arg("theRowUpper"), py::arg("theColLower"), py::arg("theColUpper"));
	cls_TColgp_Array2OfLin2d.def(py::init([] (const TColgp_Array2OfLin2d &other) {return new TColgp_Array2OfLin2d(other);}), "Copy constructor", py::arg("other"));
	cls_TColgp_Array2OfLin2d.def(py::init<const gp_Lin2d &, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theRowLower"), py::arg("theRowUpper"), py::arg("theColLower"), py::arg("theColUpper"));
	cls_TColgp_Array2OfLin2d.def("Init", (void (TColgp_Array2OfLin2d::*)(const gp_Lin2d &)) &TColgp_Array2OfLin2d::Init, "Initialise the values", py::arg("theValue"));
	cls_TColgp_Array2OfLin2d.def("Size", (Standard_Integer (TColgp_Array2OfLin2d::*)() const ) &TColgp_Array2OfLin2d::Size, "Size (number of items)");
	cls_TColgp_Array2OfLin2d.def("Length", (Standard_Integer (TColgp_Array2OfLin2d::*)() const ) &TColgp_Array2OfLin2d::Length, "Length (number of items)");
	cls_TColgp_Array2OfLin2d.def("RowLength", (Standard_Integer (TColgp_Array2OfLin2d::*)() const ) &TColgp_Array2OfLin2d::RowLength, "Returns length of the row, i.e. number of columns");
	cls_TColgp_Array2OfLin2d.def("ColLength", (Standard_Integer (TColgp_Array2OfLin2d::*)() const ) &TColgp_Array2OfLin2d::ColLength, "Returns length of the column, i.e. number of rows");
	cls_TColgp_Array2OfLin2d.def("LowerRow", (Standard_Integer (TColgp_Array2OfLin2d::*)() const ) &TColgp_Array2OfLin2d::LowerRow, "LowerRow");
	cls_TColgp_Array2OfLin2d.def("UpperRow", (Standard_Integer (TColgp_Array2OfLin2d::*)() const ) &TColgp_Array2OfLin2d::UpperRow, "UpperRow");
	cls_TColgp_Array2OfLin2d.def("LowerCol", (Standard_Integer (TColgp_Array2OfLin2d::*)() const ) &TColgp_Array2OfLin2d::LowerCol, "LowerCol");
	cls_TColgp_Array2OfLin2d.def("UpperCol", (Standard_Integer (TColgp_Array2OfLin2d::*)() const ) &TColgp_Array2OfLin2d::UpperCol, "UpperCol");
	cls_TColgp_Array2OfLin2d.def("IsDeletable", (Standard_Boolean (TColgp_Array2OfLin2d::*)() const ) &TColgp_Array2OfLin2d::IsDeletable, "myDeletable flag");
	cls_TColgp_Array2OfLin2d.def("Assign", (TColgp_Array2OfLin2d & (TColgp_Array2OfLin2d::*)(const TColgp_Array2OfLin2d &)) &TColgp_Array2OfLin2d::Assign, "Assignment", py::arg("theOther"));
	cls_TColgp_Array2OfLin2d.def("assign", (TColgp_Array2OfLin2d & (TColgp_Array2OfLin2d::*)(const TColgp_Array2OfLin2d &)) &TColgp_Array2OfLin2d::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_TColgp_Array2OfLin2d.def("Value", (const gp_Lin2d & (TColgp_Array2OfLin2d::*)(const Standard_Integer, const Standard_Integer) const ) &TColgp_Array2OfLin2d::Value, "Constant value access", py::arg("theRow"), py::arg("theCol"));
	cls_TColgp_Array2OfLin2d.def("__call__", (const gp_Lin2d & (TColgp_Array2OfLin2d::*)(const Standard_Integer, const Standard_Integer) const ) &TColgp_Array2OfLin2d::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theRow"), py::arg("theCol"));
	cls_TColgp_Array2OfLin2d.def("ChangeValue", (gp_Lin2d & (TColgp_Array2OfLin2d::*)(const Standard_Integer, const Standard_Integer)) &TColgp_Array2OfLin2d::ChangeValue, "Variable value access", py::arg("theRow"), py::arg("theCol"));
	cls_TColgp_Array2OfLin2d.def("__call__", (gp_Lin2d & (TColgp_Array2OfLin2d::*)(const Standard_Integer, const Standard_Integer)) &TColgp_Array2OfLin2d::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theRow"), py::arg("theCol"));
	cls_TColgp_Array2OfLin2d.def("SetValue", (void (TColgp_Array2OfLin2d::*)(const Standard_Integer, const Standard_Integer, const gp_Lin2d &)) &TColgp_Array2OfLin2d::SetValue, "SetValue", py::arg("theRow"), py::arg("theCol"), py::arg("theItem"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Array2.hxx
	py::class_<TColgp_Array2OfCirc2d, std::unique_ptr<TColgp_Array2OfCirc2d, Deleter<TColgp_Array2OfCirc2d>>> cls_TColgp_Array2OfCirc2d(mod, "TColgp_Array2OfCirc2d", "Purpose: The class Array2 represents bi-dimensional arrays of fixed size known at run time. The ranges of indices are user defined.");
	cls_TColgp_Array2OfCirc2d.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLower"), py::arg("theRowUpper"), py::arg("theColLower"), py::arg("theColUpper"));
	cls_TColgp_Array2OfCirc2d.def(py::init([] (const TColgp_Array2OfCirc2d &other) {return new TColgp_Array2OfCirc2d(other);}), "Copy constructor", py::arg("other"));
	cls_TColgp_Array2OfCirc2d.def(py::init<const gp_Circ2d &, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theBegin"), py::arg("theRowLower"), py::arg("theRowUpper"), py::arg("theColLower"), py::arg("theColUpper"));
	cls_TColgp_Array2OfCirc2d.def("Init", (void (TColgp_Array2OfCirc2d::*)(const gp_Circ2d &)) &TColgp_Array2OfCirc2d::Init, "Initialise the values", py::arg("theValue"));
	cls_TColgp_Array2OfCirc2d.def("Size", (Standard_Integer (TColgp_Array2OfCirc2d::*)() const ) &TColgp_Array2OfCirc2d::Size, "Size (number of items)");
	cls_TColgp_Array2OfCirc2d.def("Length", (Standard_Integer (TColgp_Array2OfCirc2d::*)() const ) &TColgp_Array2OfCirc2d::Length, "Length (number of items)");
	cls_TColgp_Array2OfCirc2d.def("RowLength", (Standard_Integer (TColgp_Array2OfCirc2d::*)() const ) &TColgp_Array2OfCirc2d::RowLength, "Returns length of the row, i.e. number of columns");
	cls_TColgp_Array2OfCirc2d.def("ColLength", (Standard_Integer (TColgp_Array2OfCirc2d::*)() const ) &TColgp_Array2OfCirc2d::ColLength, "Returns length of the column, i.e. number of rows");
	cls_TColgp_Array2OfCirc2d.def("LowerRow", (Standard_Integer (TColgp_Array2OfCirc2d::*)() const ) &TColgp_Array2OfCirc2d::LowerRow, "LowerRow");
	cls_TColgp_Array2OfCirc2d.def("UpperRow", (Standard_Integer (TColgp_Array2OfCirc2d::*)() const ) &TColgp_Array2OfCirc2d::UpperRow, "UpperRow");
	cls_TColgp_Array2OfCirc2d.def("LowerCol", (Standard_Integer (TColgp_Array2OfCirc2d::*)() const ) &TColgp_Array2OfCirc2d::LowerCol, "LowerCol");
	cls_TColgp_Array2OfCirc2d.def("UpperCol", (Standard_Integer (TColgp_Array2OfCirc2d::*)() const ) &TColgp_Array2OfCirc2d::UpperCol, "UpperCol");
	cls_TColgp_Array2OfCirc2d.def("IsDeletable", (Standard_Boolean (TColgp_Array2OfCirc2d::*)() const ) &TColgp_Array2OfCirc2d::IsDeletable, "myDeletable flag");
	cls_TColgp_Array2OfCirc2d.def("Assign", (TColgp_Array2OfCirc2d & (TColgp_Array2OfCirc2d::*)(const TColgp_Array2OfCirc2d &)) &TColgp_Array2OfCirc2d::Assign, "Assignment", py::arg("theOther"));
	cls_TColgp_Array2OfCirc2d.def("assign", (TColgp_Array2OfCirc2d & (TColgp_Array2OfCirc2d::*)(const TColgp_Array2OfCirc2d &)) &TColgp_Array2OfCirc2d::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_TColgp_Array2OfCirc2d.def("Value", (const gp_Circ2d & (TColgp_Array2OfCirc2d::*)(const Standard_Integer, const Standard_Integer) const ) &TColgp_Array2OfCirc2d::Value, "Constant value access", py::arg("theRow"), py::arg("theCol"));
	cls_TColgp_Array2OfCirc2d.def("__call__", (const gp_Circ2d & (TColgp_Array2OfCirc2d::*)(const Standard_Integer, const Standard_Integer) const ) &TColgp_Array2OfCirc2d::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theRow"), py::arg("theCol"));
	cls_TColgp_Array2OfCirc2d.def("ChangeValue", (gp_Circ2d & (TColgp_Array2OfCirc2d::*)(const Standard_Integer, const Standard_Integer)) &TColgp_Array2OfCirc2d::ChangeValue, "Variable value access", py::arg("theRow"), py::arg("theCol"));
	cls_TColgp_Array2OfCirc2d.def("__call__", (gp_Circ2d & (TColgp_Array2OfCirc2d::*)(const Standard_Integer, const Standard_Integer)) &TColgp_Array2OfCirc2d::operator(), py::is_operator(), "operator() - alias to ChangeValue", py::arg("theRow"), py::arg("theCol"));
	cls_TColgp_Array2OfCirc2d.def("SetValue", (void (TColgp_Array2OfCirc2d::*)(const Standard_Integer, const Standard_Integer, const gp_Circ2d &)) &TColgp_Array2OfCirc2d::SetValue, "SetValue", py::arg("theRow"), py::arg("theCol"), py::arg("theItem"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<TColgp_SequenceOfDir, std::unique_ptr<TColgp_SequenceOfDir, Deleter<TColgp_SequenceOfDir>>, NCollection_BaseSequence> cls_TColgp_SequenceOfDir(mod, "TColgp_SequenceOfDir", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_TColgp_SequenceOfDir.def(py::init<>());
	cls_TColgp_SequenceOfDir.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_TColgp_SequenceOfDir.def(py::init([] (const TColgp_SequenceOfDir &other) {return new TColgp_SequenceOfDir(other);}), "Copy constructor", py::arg("other"));
	cls_TColgp_SequenceOfDir.def("begin", (TColgp_SequenceOfDir::iterator (TColgp_SequenceOfDir::*)() const ) &TColgp_SequenceOfDir::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_TColgp_SequenceOfDir.def("end", (TColgp_SequenceOfDir::iterator (TColgp_SequenceOfDir::*)() const ) &TColgp_SequenceOfDir::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_TColgp_SequenceOfDir.def("cbegin", (TColgp_SequenceOfDir::const_iterator (TColgp_SequenceOfDir::*)() const ) &TColgp_SequenceOfDir::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_TColgp_SequenceOfDir.def("cend", (TColgp_SequenceOfDir::const_iterator (TColgp_SequenceOfDir::*)() const ) &TColgp_SequenceOfDir::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_TColgp_SequenceOfDir.def("Size", (Standard_Integer (TColgp_SequenceOfDir::*)() const ) &TColgp_SequenceOfDir::Size, "Number of items");
	cls_TColgp_SequenceOfDir.def("Length", (Standard_Integer (TColgp_SequenceOfDir::*)() const ) &TColgp_SequenceOfDir::Length, "Number of items");
	cls_TColgp_SequenceOfDir.def("Lower", (Standard_Integer (TColgp_SequenceOfDir::*)() const ) &TColgp_SequenceOfDir::Lower, "Method for consistency with other collections.");
	cls_TColgp_SequenceOfDir.def("Upper", (Standard_Integer (TColgp_SequenceOfDir::*)() const ) &TColgp_SequenceOfDir::Upper, "Method for consistency with other collections.");
	cls_TColgp_SequenceOfDir.def("IsEmpty", (Standard_Boolean (TColgp_SequenceOfDir::*)() const ) &TColgp_SequenceOfDir::IsEmpty, "Empty query");
	cls_TColgp_SequenceOfDir.def("Reverse", (void (TColgp_SequenceOfDir::*)()) &TColgp_SequenceOfDir::Reverse, "Reverse sequence");
	cls_TColgp_SequenceOfDir.def("Exchange", (void (TColgp_SequenceOfDir::*)(const Standard_Integer, const Standard_Integer)) &TColgp_SequenceOfDir::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_TColgp_SequenceOfDir.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_SequenceOfDir::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_TColgp_SequenceOfDir.def("Clear", [](TColgp_SequenceOfDir &self) -> void { return self.Clear(); });
	cls_TColgp_SequenceOfDir.def("Clear", (void (TColgp_SequenceOfDir::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_SequenceOfDir::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_TColgp_SequenceOfDir.def("Assign", (TColgp_SequenceOfDir & (TColgp_SequenceOfDir::*)(const TColgp_SequenceOfDir &)) &TColgp_SequenceOfDir::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TColgp_SequenceOfDir.def("assign", (TColgp_SequenceOfDir & (TColgp_SequenceOfDir::*)(const TColgp_SequenceOfDir &)) &TColgp_SequenceOfDir::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_TColgp_SequenceOfDir.def("Remove", (void (TColgp_SequenceOfDir::*)(TColgp_SequenceOfDir::Iterator &)) &TColgp_SequenceOfDir::Remove, "Remove one item", py::arg("thePosition"));
	cls_TColgp_SequenceOfDir.def("Remove", (void (TColgp_SequenceOfDir::*)(const Standard_Integer)) &TColgp_SequenceOfDir::Remove, "Remove one item", py::arg("theIndex"));
	cls_TColgp_SequenceOfDir.def("Remove", (void (TColgp_SequenceOfDir::*)(const Standard_Integer, const Standard_Integer)) &TColgp_SequenceOfDir::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_TColgp_SequenceOfDir.def("Append", (void (TColgp_SequenceOfDir::*)(const gp_Dir &)) &TColgp_SequenceOfDir::Append, "Append one item", py::arg("theItem"));
	cls_TColgp_SequenceOfDir.def("Append", (void (TColgp_SequenceOfDir::*)(TColgp_SequenceOfDir &)) &TColgp_SequenceOfDir::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_TColgp_SequenceOfDir.def("Prepend", (void (TColgp_SequenceOfDir::*)(const gp_Dir &)) &TColgp_SequenceOfDir::Prepend, "Prepend one item", py::arg("theItem"));
	cls_TColgp_SequenceOfDir.def("Prepend", (void (TColgp_SequenceOfDir::*)(TColgp_SequenceOfDir &)) &TColgp_SequenceOfDir::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_TColgp_SequenceOfDir.def("InsertBefore", (void (TColgp_SequenceOfDir::*)(const Standard_Integer, const gp_Dir &)) &TColgp_SequenceOfDir::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_TColgp_SequenceOfDir.def("InsertBefore", (void (TColgp_SequenceOfDir::*)(const Standard_Integer, TColgp_SequenceOfDir &)) &TColgp_SequenceOfDir::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColgp_SequenceOfDir.def("InsertAfter", (void (TColgp_SequenceOfDir::*)(TColgp_SequenceOfDir::Iterator &, const gp_Dir &)) &TColgp_SequenceOfDir::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_TColgp_SequenceOfDir.def("InsertAfter", (void (TColgp_SequenceOfDir::*)(const Standard_Integer, TColgp_SequenceOfDir &)) &TColgp_SequenceOfDir::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColgp_SequenceOfDir.def("InsertAfter", (void (TColgp_SequenceOfDir::*)(const Standard_Integer, const gp_Dir &)) &TColgp_SequenceOfDir::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_TColgp_SequenceOfDir.def("Split", (void (TColgp_SequenceOfDir::*)(const Standard_Integer, TColgp_SequenceOfDir &)) &TColgp_SequenceOfDir::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColgp_SequenceOfDir.def("First", (const gp_Dir & (TColgp_SequenceOfDir::*)() const ) &TColgp_SequenceOfDir::First, "First item access");
	cls_TColgp_SequenceOfDir.def("ChangeFirst", (gp_Dir & (TColgp_SequenceOfDir::*)()) &TColgp_SequenceOfDir::ChangeFirst, "First item access");
	cls_TColgp_SequenceOfDir.def("Last", (const gp_Dir & (TColgp_SequenceOfDir::*)() const ) &TColgp_SequenceOfDir::Last, "Last item access");
	cls_TColgp_SequenceOfDir.def("ChangeLast", (gp_Dir & (TColgp_SequenceOfDir::*)()) &TColgp_SequenceOfDir::ChangeLast, "Last item access");
	cls_TColgp_SequenceOfDir.def("Value", (const gp_Dir & (TColgp_SequenceOfDir::*)(const Standard_Integer) const ) &TColgp_SequenceOfDir::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_TColgp_SequenceOfDir.def("__call__", (const gp_Dir & (TColgp_SequenceOfDir::*)(const Standard_Integer) const ) &TColgp_SequenceOfDir::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_TColgp_SequenceOfDir.def("ChangeValue", (gp_Dir & (TColgp_SequenceOfDir::*)(const Standard_Integer)) &TColgp_SequenceOfDir::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_TColgp_SequenceOfDir.def("__call__", (gp_Dir & (TColgp_SequenceOfDir::*)(const Standard_Integer)) &TColgp_SequenceOfDir::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_TColgp_SequenceOfDir.def("SetValue", (void (TColgp_SequenceOfDir::*)(const Standard_Integer, const gp_Dir &)) &TColgp_SequenceOfDir::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_TColgp_SequenceOfDir.def("__iter__", [](const TColgp_SequenceOfDir &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<TColgp_SequenceOfVec, std::unique_ptr<TColgp_SequenceOfVec, Deleter<TColgp_SequenceOfVec>>, NCollection_BaseSequence> cls_TColgp_SequenceOfVec(mod, "TColgp_SequenceOfVec", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_TColgp_SequenceOfVec.def(py::init<>());
	cls_TColgp_SequenceOfVec.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_TColgp_SequenceOfVec.def(py::init([] (const TColgp_SequenceOfVec &other) {return new TColgp_SequenceOfVec(other);}), "Copy constructor", py::arg("other"));
	cls_TColgp_SequenceOfVec.def("begin", (TColgp_SequenceOfVec::iterator (TColgp_SequenceOfVec::*)() const ) &TColgp_SequenceOfVec::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_TColgp_SequenceOfVec.def("end", (TColgp_SequenceOfVec::iterator (TColgp_SequenceOfVec::*)() const ) &TColgp_SequenceOfVec::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_TColgp_SequenceOfVec.def("cbegin", (TColgp_SequenceOfVec::const_iterator (TColgp_SequenceOfVec::*)() const ) &TColgp_SequenceOfVec::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_TColgp_SequenceOfVec.def("cend", (TColgp_SequenceOfVec::const_iterator (TColgp_SequenceOfVec::*)() const ) &TColgp_SequenceOfVec::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_TColgp_SequenceOfVec.def("Size", (Standard_Integer (TColgp_SequenceOfVec::*)() const ) &TColgp_SequenceOfVec::Size, "Number of items");
	cls_TColgp_SequenceOfVec.def("Length", (Standard_Integer (TColgp_SequenceOfVec::*)() const ) &TColgp_SequenceOfVec::Length, "Number of items");
	cls_TColgp_SequenceOfVec.def("Lower", (Standard_Integer (TColgp_SequenceOfVec::*)() const ) &TColgp_SequenceOfVec::Lower, "Method for consistency with other collections.");
	cls_TColgp_SequenceOfVec.def("Upper", (Standard_Integer (TColgp_SequenceOfVec::*)() const ) &TColgp_SequenceOfVec::Upper, "Method for consistency with other collections.");
	cls_TColgp_SequenceOfVec.def("IsEmpty", (Standard_Boolean (TColgp_SequenceOfVec::*)() const ) &TColgp_SequenceOfVec::IsEmpty, "Empty query");
	cls_TColgp_SequenceOfVec.def("Reverse", (void (TColgp_SequenceOfVec::*)()) &TColgp_SequenceOfVec::Reverse, "Reverse sequence");
	cls_TColgp_SequenceOfVec.def("Exchange", (void (TColgp_SequenceOfVec::*)(const Standard_Integer, const Standard_Integer)) &TColgp_SequenceOfVec::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_TColgp_SequenceOfVec.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_SequenceOfVec::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_TColgp_SequenceOfVec.def("Clear", [](TColgp_SequenceOfVec &self) -> void { return self.Clear(); });
	cls_TColgp_SequenceOfVec.def("Clear", (void (TColgp_SequenceOfVec::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_SequenceOfVec::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_TColgp_SequenceOfVec.def("Assign", (TColgp_SequenceOfVec & (TColgp_SequenceOfVec::*)(const TColgp_SequenceOfVec &)) &TColgp_SequenceOfVec::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TColgp_SequenceOfVec.def("assign", (TColgp_SequenceOfVec & (TColgp_SequenceOfVec::*)(const TColgp_SequenceOfVec &)) &TColgp_SequenceOfVec::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_TColgp_SequenceOfVec.def("Remove", (void (TColgp_SequenceOfVec::*)(TColgp_SequenceOfVec::Iterator &)) &TColgp_SequenceOfVec::Remove, "Remove one item", py::arg("thePosition"));
	cls_TColgp_SequenceOfVec.def("Remove", (void (TColgp_SequenceOfVec::*)(const Standard_Integer)) &TColgp_SequenceOfVec::Remove, "Remove one item", py::arg("theIndex"));
	cls_TColgp_SequenceOfVec.def("Remove", (void (TColgp_SequenceOfVec::*)(const Standard_Integer, const Standard_Integer)) &TColgp_SequenceOfVec::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_TColgp_SequenceOfVec.def("Append", (void (TColgp_SequenceOfVec::*)(const gp_Vec &)) &TColgp_SequenceOfVec::Append, "Append one item", py::arg("theItem"));
	cls_TColgp_SequenceOfVec.def("Append", (void (TColgp_SequenceOfVec::*)(TColgp_SequenceOfVec &)) &TColgp_SequenceOfVec::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_TColgp_SequenceOfVec.def("Prepend", (void (TColgp_SequenceOfVec::*)(const gp_Vec &)) &TColgp_SequenceOfVec::Prepend, "Prepend one item", py::arg("theItem"));
	cls_TColgp_SequenceOfVec.def("Prepend", (void (TColgp_SequenceOfVec::*)(TColgp_SequenceOfVec &)) &TColgp_SequenceOfVec::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_TColgp_SequenceOfVec.def("InsertBefore", (void (TColgp_SequenceOfVec::*)(const Standard_Integer, const gp_Vec &)) &TColgp_SequenceOfVec::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_TColgp_SequenceOfVec.def("InsertBefore", (void (TColgp_SequenceOfVec::*)(const Standard_Integer, TColgp_SequenceOfVec &)) &TColgp_SequenceOfVec::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColgp_SequenceOfVec.def("InsertAfter", (void (TColgp_SequenceOfVec::*)(TColgp_SequenceOfVec::Iterator &, const gp_Vec &)) &TColgp_SequenceOfVec::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_TColgp_SequenceOfVec.def("InsertAfter", (void (TColgp_SequenceOfVec::*)(const Standard_Integer, TColgp_SequenceOfVec &)) &TColgp_SequenceOfVec::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColgp_SequenceOfVec.def("InsertAfter", (void (TColgp_SequenceOfVec::*)(const Standard_Integer, const gp_Vec &)) &TColgp_SequenceOfVec::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_TColgp_SequenceOfVec.def("Split", (void (TColgp_SequenceOfVec::*)(const Standard_Integer, TColgp_SequenceOfVec &)) &TColgp_SequenceOfVec::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColgp_SequenceOfVec.def("First", (const gp_Vec & (TColgp_SequenceOfVec::*)() const ) &TColgp_SequenceOfVec::First, "First item access");
	cls_TColgp_SequenceOfVec.def("ChangeFirst", (gp_Vec & (TColgp_SequenceOfVec::*)()) &TColgp_SequenceOfVec::ChangeFirst, "First item access");
	cls_TColgp_SequenceOfVec.def("Last", (const gp_Vec & (TColgp_SequenceOfVec::*)() const ) &TColgp_SequenceOfVec::Last, "Last item access");
	cls_TColgp_SequenceOfVec.def("ChangeLast", (gp_Vec & (TColgp_SequenceOfVec::*)()) &TColgp_SequenceOfVec::ChangeLast, "Last item access");
	cls_TColgp_SequenceOfVec.def("Value", (const gp_Vec & (TColgp_SequenceOfVec::*)(const Standard_Integer) const ) &TColgp_SequenceOfVec::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_TColgp_SequenceOfVec.def("__call__", (const gp_Vec & (TColgp_SequenceOfVec::*)(const Standard_Integer) const ) &TColgp_SequenceOfVec::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_TColgp_SequenceOfVec.def("ChangeValue", (gp_Vec & (TColgp_SequenceOfVec::*)(const Standard_Integer)) &TColgp_SequenceOfVec::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_TColgp_SequenceOfVec.def("__call__", (gp_Vec & (TColgp_SequenceOfVec::*)(const Standard_Integer)) &TColgp_SequenceOfVec::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_TColgp_SequenceOfVec.def("SetValue", (void (TColgp_SequenceOfVec::*)(const Standard_Integer, const gp_Vec &)) &TColgp_SequenceOfVec::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_TColgp_SequenceOfVec.def("__iter__", [](const TColgp_SequenceOfVec &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<TColgp_SequenceOfDir2d, std::unique_ptr<TColgp_SequenceOfDir2d, Deleter<TColgp_SequenceOfDir2d>>, NCollection_BaseSequence> cls_TColgp_SequenceOfDir2d(mod, "TColgp_SequenceOfDir2d", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_TColgp_SequenceOfDir2d.def(py::init<>());
	cls_TColgp_SequenceOfDir2d.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_TColgp_SequenceOfDir2d.def(py::init([] (const TColgp_SequenceOfDir2d &other) {return new TColgp_SequenceOfDir2d(other);}), "Copy constructor", py::arg("other"));
	cls_TColgp_SequenceOfDir2d.def("begin", (TColgp_SequenceOfDir2d::iterator (TColgp_SequenceOfDir2d::*)() const ) &TColgp_SequenceOfDir2d::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_TColgp_SequenceOfDir2d.def("end", (TColgp_SequenceOfDir2d::iterator (TColgp_SequenceOfDir2d::*)() const ) &TColgp_SequenceOfDir2d::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_TColgp_SequenceOfDir2d.def("cbegin", (TColgp_SequenceOfDir2d::const_iterator (TColgp_SequenceOfDir2d::*)() const ) &TColgp_SequenceOfDir2d::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_TColgp_SequenceOfDir2d.def("cend", (TColgp_SequenceOfDir2d::const_iterator (TColgp_SequenceOfDir2d::*)() const ) &TColgp_SequenceOfDir2d::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_TColgp_SequenceOfDir2d.def("Size", (Standard_Integer (TColgp_SequenceOfDir2d::*)() const ) &TColgp_SequenceOfDir2d::Size, "Number of items");
	cls_TColgp_SequenceOfDir2d.def("Length", (Standard_Integer (TColgp_SequenceOfDir2d::*)() const ) &TColgp_SequenceOfDir2d::Length, "Number of items");
	cls_TColgp_SequenceOfDir2d.def("Lower", (Standard_Integer (TColgp_SequenceOfDir2d::*)() const ) &TColgp_SequenceOfDir2d::Lower, "Method for consistency with other collections.");
	cls_TColgp_SequenceOfDir2d.def("Upper", (Standard_Integer (TColgp_SequenceOfDir2d::*)() const ) &TColgp_SequenceOfDir2d::Upper, "Method for consistency with other collections.");
	cls_TColgp_SequenceOfDir2d.def("IsEmpty", (Standard_Boolean (TColgp_SequenceOfDir2d::*)() const ) &TColgp_SequenceOfDir2d::IsEmpty, "Empty query");
	cls_TColgp_SequenceOfDir2d.def("Reverse", (void (TColgp_SequenceOfDir2d::*)()) &TColgp_SequenceOfDir2d::Reverse, "Reverse sequence");
	cls_TColgp_SequenceOfDir2d.def("Exchange", (void (TColgp_SequenceOfDir2d::*)(const Standard_Integer, const Standard_Integer)) &TColgp_SequenceOfDir2d::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_TColgp_SequenceOfDir2d.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_SequenceOfDir2d::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_TColgp_SequenceOfDir2d.def("Clear", [](TColgp_SequenceOfDir2d &self) -> void { return self.Clear(); });
	cls_TColgp_SequenceOfDir2d.def("Clear", (void (TColgp_SequenceOfDir2d::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_SequenceOfDir2d::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_TColgp_SequenceOfDir2d.def("Assign", (TColgp_SequenceOfDir2d & (TColgp_SequenceOfDir2d::*)(const TColgp_SequenceOfDir2d &)) &TColgp_SequenceOfDir2d::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TColgp_SequenceOfDir2d.def("assign", (TColgp_SequenceOfDir2d & (TColgp_SequenceOfDir2d::*)(const TColgp_SequenceOfDir2d &)) &TColgp_SequenceOfDir2d::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_TColgp_SequenceOfDir2d.def("Remove", (void (TColgp_SequenceOfDir2d::*)(TColgp_SequenceOfDir2d::Iterator &)) &TColgp_SequenceOfDir2d::Remove, "Remove one item", py::arg("thePosition"));
	cls_TColgp_SequenceOfDir2d.def("Remove", (void (TColgp_SequenceOfDir2d::*)(const Standard_Integer)) &TColgp_SequenceOfDir2d::Remove, "Remove one item", py::arg("theIndex"));
	cls_TColgp_SequenceOfDir2d.def("Remove", (void (TColgp_SequenceOfDir2d::*)(const Standard_Integer, const Standard_Integer)) &TColgp_SequenceOfDir2d::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_TColgp_SequenceOfDir2d.def("Append", (void (TColgp_SequenceOfDir2d::*)(const gp_Dir2d &)) &TColgp_SequenceOfDir2d::Append, "Append one item", py::arg("theItem"));
	cls_TColgp_SequenceOfDir2d.def("Append", (void (TColgp_SequenceOfDir2d::*)(TColgp_SequenceOfDir2d &)) &TColgp_SequenceOfDir2d::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_TColgp_SequenceOfDir2d.def("Prepend", (void (TColgp_SequenceOfDir2d::*)(const gp_Dir2d &)) &TColgp_SequenceOfDir2d::Prepend, "Prepend one item", py::arg("theItem"));
	cls_TColgp_SequenceOfDir2d.def("Prepend", (void (TColgp_SequenceOfDir2d::*)(TColgp_SequenceOfDir2d &)) &TColgp_SequenceOfDir2d::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_TColgp_SequenceOfDir2d.def("InsertBefore", (void (TColgp_SequenceOfDir2d::*)(const Standard_Integer, const gp_Dir2d &)) &TColgp_SequenceOfDir2d::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_TColgp_SequenceOfDir2d.def("InsertBefore", (void (TColgp_SequenceOfDir2d::*)(const Standard_Integer, TColgp_SequenceOfDir2d &)) &TColgp_SequenceOfDir2d::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColgp_SequenceOfDir2d.def("InsertAfter", (void (TColgp_SequenceOfDir2d::*)(TColgp_SequenceOfDir2d::Iterator &, const gp_Dir2d &)) &TColgp_SequenceOfDir2d::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_TColgp_SequenceOfDir2d.def("InsertAfter", (void (TColgp_SequenceOfDir2d::*)(const Standard_Integer, TColgp_SequenceOfDir2d &)) &TColgp_SequenceOfDir2d::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColgp_SequenceOfDir2d.def("InsertAfter", (void (TColgp_SequenceOfDir2d::*)(const Standard_Integer, const gp_Dir2d &)) &TColgp_SequenceOfDir2d::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_TColgp_SequenceOfDir2d.def("Split", (void (TColgp_SequenceOfDir2d::*)(const Standard_Integer, TColgp_SequenceOfDir2d &)) &TColgp_SequenceOfDir2d::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColgp_SequenceOfDir2d.def("First", (const gp_Dir2d & (TColgp_SequenceOfDir2d::*)() const ) &TColgp_SequenceOfDir2d::First, "First item access");
	cls_TColgp_SequenceOfDir2d.def("ChangeFirst", (gp_Dir2d & (TColgp_SequenceOfDir2d::*)()) &TColgp_SequenceOfDir2d::ChangeFirst, "First item access");
	cls_TColgp_SequenceOfDir2d.def("Last", (const gp_Dir2d & (TColgp_SequenceOfDir2d::*)() const ) &TColgp_SequenceOfDir2d::Last, "Last item access");
	cls_TColgp_SequenceOfDir2d.def("ChangeLast", (gp_Dir2d & (TColgp_SequenceOfDir2d::*)()) &TColgp_SequenceOfDir2d::ChangeLast, "Last item access");
	cls_TColgp_SequenceOfDir2d.def("Value", (const gp_Dir2d & (TColgp_SequenceOfDir2d::*)(const Standard_Integer) const ) &TColgp_SequenceOfDir2d::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_TColgp_SequenceOfDir2d.def("__call__", (const gp_Dir2d & (TColgp_SequenceOfDir2d::*)(const Standard_Integer) const ) &TColgp_SequenceOfDir2d::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_TColgp_SequenceOfDir2d.def("ChangeValue", (gp_Dir2d & (TColgp_SequenceOfDir2d::*)(const Standard_Integer)) &TColgp_SequenceOfDir2d::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_TColgp_SequenceOfDir2d.def("__call__", (gp_Dir2d & (TColgp_SequenceOfDir2d::*)(const Standard_Integer)) &TColgp_SequenceOfDir2d::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_TColgp_SequenceOfDir2d.def("SetValue", (void (TColgp_SequenceOfDir2d::*)(const Standard_Integer, const gp_Dir2d &)) &TColgp_SequenceOfDir2d::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_TColgp_SequenceOfDir2d.def("__iter__", [](const TColgp_SequenceOfDir2d &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<TColgp_SequenceOfPnt2d, std::unique_ptr<TColgp_SequenceOfPnt2d, Deleter<TColgp_SequenceOfPnt2d>>, NCollection_BaseSequence> cls_TColgp_SequenceOfPnt2d(mod, "TColgp_SequenceOfPnt2d", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_TColgp_SequenceOfPnt2d.def(py::init<>());
	cls_TColgp_SequenceOfPnt2d.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_TColgp_SequenceOfPnt2d.def(py::init([] (const TColgp_SequenceOfPnt2d &other) {return new TColgp_SequenceOfPnt2d(other);}), "Copy constructor", py::arg("other"));
	cls_TColgp_SequenceOfPnt2d.def("begin", (TColgp_SequenceOfPnt2d::iterator (TColgp_SequenceOfPnt2d::*)() const ) &TColgp_SequenceOfPnt2d::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_TColgp_SequenceOfPnt2d.def("end", (TColgp_SequenceOfPnt2d::iterator (TColgp_SequenceOfPnt2d::*)() const ) &TColgp_SequenceOfPnt2d::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_TColgp_SequenceOfPnt2d.def("cbegin", (TColgp_SequenceOfPnt2d::const_iterator (TColgp_SequenceOfPnt2d::*)() const ) &TColgp_SequenceOfPnt2d::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_TColgp_SequenceOfPnt2d.def("cend", (TColgp_SequenceOfPnt2d::const_iterator (TColgp_SequenceOfPnt2d::*)() const ) &TColgp_SequenceOfPnt2d::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_TColgp_SequenceOfPnt2d.def("Size", (Standard_Integer (TColgp_SequenceOfPnt2d::*)() const ) &TColgp_SequenceOfPnt2d::Size, "Number of items");
	cls_TColgp_SequenceOfPnt2d.def("Length", (Standard_Integer (TColgp_SequenceOfPnt2d::*)() const ) &TColgp_SequenceOfPnt2d::Length, "Number of items");
	cls_TColgp_SequenceOfPnt2d.def("Lower", (Standard_Integer (TColgp_SequenceOfPnt2d::*)() const ) &TColgp_SequenceOfPnt2d::Lower, "Method for consistency with other collections.");
	cls_TColgp_SequenceOfPnt2d.def("Upper", (Standard_Integer (TColgp_SequenceOfPnt2d::*)() const ) &TColgp_SequenceOfPnt2d::Upper, "Method for consistency with other collections.");
	cls_TColgp_SequenceOfPnt2d.def("IsEmpty", (Standard_Boolean (TColgp_SequenceOfPnt2d::*)() const ) &TColgp_SequenceOfPnt2d::IsEmpty, "Empty query");
	cls_TColgp_SequenceOfPnt2d.def("Reverse", (void (TColgp_SequenceOfPnt2d::*)()) &TColgp_SequenceOfPnt2d::Reverse, "Reverse sequence");
	cls_TColgp_SequenceOfPnt2d.def("Exchange", (void (TColgp_SequenceOfPnt2d::*)(const Standard_Integer, const Standard_Integer)) &TColgp_SequenceOfPnt2d::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_TColgp_SequenceOfPnt2d.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_SequenceOfPnt2d::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_TColgp_SequenceOfPnt2d.def("Clear", [](TColgp_SequenceOfPnt2d &self) -> void { return self.Clear(); });
	cls_TColgp_SequenceOfPnt2d.def("Clear", (void (TColgp_SequenceOfPnt2d::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_SequenceOfPnt2d::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_TColgp_SequenceOfPnt2d.def("Assign", (TColgp_SequenceOfPnt2d & (TColgp_SequenceOfPnt2d::*)(const TColgp_SequenceOfPnt2d &)) &TColgp_SequenceOfPnt2d::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TColgp_SequenceOfPnt2d.def("assign", (TColgp_SequenceOfPnt2d & (TColgp_SequenceOfPnt2d::*)(const TColgp_SequenceOfPnt2d &)) &TColgp_SequenceOfPnt2d::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_TColgp_SequenceOfPnt2d.def("Remove", (void (TColgp_SequenceOfPnt2d::*)(TColgp_SequenceOfPnt2d::Iterator &)) &TColgp_SequenceOfPnt2d::Remove, "Remove one item", py::arg("thePosition"));
	cls_TColgp_SequenceOfPnt2d.def("Remove", (void (TColgp_SequenceOfPnt2d::*)(const Standard_Integer)) &TColgp_SequenceOfPnt2d::Remove, "Remove one item", py::arg("theIndex"));
	cls_TColgp_SequenceOfPnt2d.def("Remove", (void (TColgp_SequenceOfPnt2d::*)(const Standard_Integer, const Standard_Integer)) &TColgp_SequenceOfPnt2d::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_TColgp_SequenceOfPnt2d.def("Append", (void (TColgp_SequenceOfPnt2d::*)(const gp_Pnt2d &)) &TColgp_SequenceOfPnt2d::Append, "Append one item", py::arg("theItem"));
	cls_TColgp_SequenceOfPnt2d.def("Append", (void (TColgp_SequenceOfPnt2d::*)(TColgp_SequenceOfPnt2d &)) &TColgp_SequenceOfPnt2d::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_TColgp_SequenceOfPnt2d.def("Prepend", (void (TColgp_SequenceOfPnt2d::*)(const gp_Pnt2d &)) &TColgp_SequenceOfPnt2d::Prepend, "Prepend one item", py::arg("theItem"));
	cls_TColgp_SequenceOfPnt2d.def("Prepend", (void (TColgp_SequenceOfPnt2d::*)(TColgp_SequenceOfPnt2d &)) &TColgp_SequenceOfPnt2d::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_TColgp_SequenceOfPnt2d.def("InsertBefore", (void (TColgp_SequenceOfPnt2d::*)(const Standard_Integer, const gp_Pnt2d &)) &TColgp_SequenceOfPnt2d::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_TColgp_SequenceOfPnt2d.def("InsertBefore", (void (TColgp_SequenceOfPnt2d::*)(const Standard_Integer, TColgp_SequenceOfPnt2d &)) &TColgp_SequenceOfPnt2d::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColgp_SequenceOfPnt2d.def("InsertAfter", (void (TColgp_SequenceOfPnt2d::*)(TColgp_SequenceOfPnt2d::Iterator &, const gp_Pnt2d &)) &TColgp_SequenceOfPnt2d::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_TColgp_SequenceOfPnt2d.def("InsertAfter", (void (TColgp_SequenceOfPnt2d::*)(const Standard_Integer, TColgp_SequenceOfPnt2d &)) &TColgp_SequenceOfPnt2d::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColgp_SequenceOfPnt2d.def("InsertAfter", (void (TColgp_SequenceOfPnt2d::*)(const Standard_Integer, const gp_Pnt2d &)) &TColgp_SequenceOfPnt2d::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_TColgp_SequenceOfPnt2d.def("Split", (void (TColgp_SequenceOfPnt2d::*)(const Standard_Integer, TColgp_SequenceOfPnt2d &)) &TColgp_SequenceOfPnt2d::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColgp_SequenceOfPnt2d.def("First", (const gp_Pnt2d & (TColgp_SequenceOfPnt2d::*)() const ) &TColgp_SequenceOfPnt2d::First, "First item access");
	cls_TColgp_SequenceOfPnt2d.def("ChangeFirst", (gp_Pnt2d & (TColgp_SequenceOfPnt2d::*)()) &TColgp_SequenceOfPnt2d::ChangeFirst, "First item access");
	cls_TColgp_SequenceOfPnt2d.def("Last", (const gp_Pnt2d & (TColgp_SequenceOfPnt2d::*)() const ) &TColgp_SequenceOfPnt2d::Last, "Last item access");
	cls_TColgp_SequenceOfPnt2d.def("ChangeLast", (gp_Pnt2d & (TColgp_SequenceOfPnt2d::*)()) &TColgp_SequenceOfPnt2d::ChangeLast, "Last item access");
	cls_TColgp_SequenceOfPnt2d.def("Value", (const gp_Pnt2d & (TColgp_SequenceOfPnt2d::*)(const Standard_Integer) const ) &TColgp_SequenceOfPnt2d::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_TColgp_SequenceOfPnt2d.def("__call__", (const gp_Pnt2d & (TColgp_SequenceOfPnt2d::*)(const Standard_Integer) const ) &TColgp_SequenceOfPnt2d::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_TColgp_SequenceOfPnt2d.def("ChangeValue", (gp_Pnt2d & (TColgp_SequenceOfPnt2d::*)(const Standard_Integer)) &TColgp_SequenceOfPnt2d::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_TColgp_SequenceOfPnt2d.def("__call__", (gp_Pnt2d & (TColgp_SequenceOfPnt2d::*)(const Standard_Integer)) &TColgp_SequenceOfPnt2d::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_TColgp_SequenceOfPnt2d.def("SetValue", (void (TColgp_SequenceOfPnt2d::*)(const Standard_Integer, const gp_Pnt2d &)) &TColgp_SequenceOfPnt2d::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_TColgp_SequenceOfPnt2d.def("__iter__", [](const TColgp_SequenceOfPnt2d &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<TColgp_SequenceOfVec2d, std::unique_ptr<TColgp_SequenceOfVec2d, Deleter<TColgp_SequenceOfVec2d>>, NCollection_BaseSequence> cls_TColgp_SequenceOfVec2d(mod, "TColgp_SequenceOfVec2d", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_TColgp_SequenceOfVec2d.def(py::init<>());
	cls_TColgp_SequenceOfVec2d.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_TColgp_SequenceOfVec2d.def(py::init([] (const TColgp_SequenceOfVec2d &other) {return new TColgp_SequenceOfVec2d(other);}), "Copy constructor", py::arg("other"));
	cls_TColgp_SequenceOfVec2d.def("begin", (TColgp_SequenceOfVec2d::iterator (TColgp_SequenceOfVec2d::*)() const ) &TColgp_SequenceOfVec2d::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_TColgp_SequenceOfVec2d.def("end", (TColgp_SequenceOfVec2d::iterator (TColgp_SequenceOfVec2d::*)() const ) &TColgp_SequenceOfVec2d::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_TColgp_SequenceOfVec2d.def("cbegin", (TColgp_SequenceOfVec2d::const_iterator (TColgp_SequenceOfVec2d::*)() const ) &TColgp_SequenceOfVec2d::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_TColgp_SequenceOfVec2d.def("cend", (TColgp_SequenceOfVec2d::const_iterator (TColgp_SequenceOfVec2d::*)() const ) &TColgp_SequenceOfVec2d::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_TColgp_SequenceOfVec2d.def("Size", (Standard_Integer (TColgp_SequenceOfVec2d::*)() const ) &TColgp_SequenceOfVec2d::Size, "Number of items");
	cls_TColgp_SequenceOfVec2d.def("Length", (Standard_Integer (TColgp_SequenceOfVec2d::*)() const ) &TColgp_SequenceOfVec2d::Length, "Number of items");
	cls_TColgp_SequenceOfVec2d.def("Lower", (Standard_Integer (TColgp_SequenceOfVec2d::*)() const ) &TColgp_SequenceOfVec2d::Lower, "Method for consistency with other collections.");
	cls_TColgp_SequenceOfVec2d.def("Upper", (Standard_Integer (TColgp_SequenceOfVec2d::*)() const ) &TColgp_SequenceOfVec2d::Upper, "Method for consistency with other collections.");
	cls_TColgp_SequenceOfVec2d.def("IsEmpty", (Standard_Boolean (TColgp_SequenceOfVec2d::*)() const ) &TColgp_SequenceOfVec2d::IsEmpty, "Empty query");
	cls_TColgp_SequenceOfVec2d.def("Reverse", (void (TColgp_SequenceOfVec2d::*)()) &TColgp_SequenceOfVec2d::Reverse, "Reverse sequence");
	cls_TColgp_SequenceOfVec2d.def("Exchange", (void (TColgp_SequenceOfVec2d::*)(const Standard_Integer, const Standard_Integer)) &TColgp_SequenceOfVec2d::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_TColgp_SequenceOfVec2d.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_SequenceOfVec2d::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_TColgp_SequenceOfVec2d.def("Clear", [](TColgp_SequenceOfVec2d &self) -> void { return self.Clear(); });
	cls_TColgp_SequenceOfVec2d.def("Clear", (void (TColgp_SequenceOfVec2d::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_SequenceOfVec2d::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_TColgp_SequenceOfVec2d.def("Assign", (TColgp_SequenceOfVec2d & (TColgp_SequenceOfVec2d::*)(const TColgp_SequenceOfVec2d &)) &TColgp_SequenceOfVec2d::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TColgp_SequenceOfVec2d.def("assign", (TColgp_SequenceOfVec2d & (TColgp_SequenceOfVec2d::*)(const TColgp_SequenceOfVec2d &)) &TColgp_SequenceOfVec2d::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_TColgp_SequenceOfVec2d.def("Remove", (void (TColgp_SequenceOfVec2d::*)(TColgp_SequenceOfVec2d::Iterator &)) &TColgp_SequenceOfVec2d::Remove, "Remove one item", py::arg("thePosition"));
	cls_TColgp_SequenceOfVec2d.def("Remove", (void (TColgp_SequenceOfVec2d::*)(const Standard_Integer)) &TColgp_SequenceOfVec2d::Remove, "Remove one item", py::arg("theIndex"));
	cls_TColgp_SequenceOfVec2d.def("Remove", (void (TColgp_SequenceOfVec2d::*)(const Standard_Integer, const Standard_Integer)) &TColgp_SequenceOfVec2d::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_TColgp_SequenceOfVec2d.def("Append", (void (TColgp_SequenceOfVec2d::*)(const gp_Vec2d &)) &TColgp_SequenceOfVec2d::Append, "Append one item", py::arg("theItem"));
	cls_TColgp_SequenceOfVec2d.def("Append", (void (TColgp_SequenceOfVec2d::*)(TColgp_SequenceOfVec2d &)) &TColgp_SequenceOfVec2d::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_TColgp_SequenceOfVec2d.def("Prepend", (void (TColgp_SequenceOfVec2d::*)(const gp_Vec2d &)) &TColgp_SequenceOfVec2d::Prepend, "Prepend one item", py::arg("theItem"));
	cls_TColgp_SequenceOfVec2d.def("Prepend", (void (TColgp_SequenceOfVec2d::*)(TColgp_SequenceOfVec2d &)) &TColgp_SequenceOfVec2d::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_TColgp_SequenceOfVec2d.def("InsertBefore", (void (TColgp_SequenceOfVec2d::*)(const Standard_Integer, const gp_Vec2d &)) &TColgp_SequenceOfVec2d::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_TColgp_SequenceOfVec2d.def("InsertBefore", (void (TColgp_SequenceOfVec2d::*)(const Standard_Integer, TColgp_SequenceOfVec2d &)) &TColgp_SequenceOfVec2d::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColgp_SequenceOfVec2d.def("InsertAfter", (void (TColgp_SequenceOfVec2d::*)(TColgp_SequenceOfVec2d::Iterator &, const gp_Vec2d &)) &TColgp_SequenceOfVec2d::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_TColgp_SequenceOfVec2d.def("InsertAfter", (void (TColgp_SequenceOfVec2d::*)(const Standard_Integer, TColgp_SequenceOfVec2d &)) &TColgp_SequenceOfVec2d::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColgp_SequenceOfVec2d.def("InsertAfter", (void (TColgp_SequenceOfVec2d::*)(const Standard_Integer, const gp_Vec2d &)) &TColgp_SequenceOfVec2d::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_TColgp_SequenceOfVec2d.def("Split", (void (TColgp_SequenceOfVec2d::*)(const Standard_Integer, TColgp_SequenceOfVec2d &)) &TColgp_SequenceOfVec2d::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColgp_SequenceOfVec2d.def("First", (const gp_Vec2d & (TColgp_SequenceOfVec2d::*)() const ) &TColgp_SequenceOfVec2d::First, "First item access");
	cls_TColgp_SequenceOfVec2d.def("ChangeFirst", (gp_Vec2d & (TColgp_SequenceOfVec2d::*)()) &TColgp_SequenceOfVec2d::ChangeFirst, "First item access");
	cls_TColgp_SequenceOfVec2d.def("Last", (const gp_Vec2d & (TColgp_SequenceOfVec2d::*)() const ) &TColgp_SequenceOfVec2d::Last, "Last item access");
	cls_TColgp_SequenceOfVec2d.def("ChangeLast", (gp_Vec2d & (TColgp_SequenceOfVec2d::*)()) &TColgp_SequenceOfVec2d::ChangeLast, "Last item access");
	cls_TColgp_SequenceOfVec2d.def("Value", (const gp_Vec2d & (TColgp_SequenceOfVec2d::*)(const Standard_Integer) const ) &TColgp_SequenceOfVec2d::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_TColgp_SequenceOfVec2d.def("__call__", (const gp_Vec2d & (TColgp_SequenceOfVec2d::*)(const Standard_Integer) const ) &TColgp_SequenceOfVec2d::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_TColgp_SequenceOfVec2d.def("ChangeValue", (gp_Vec2d & (TColgp_SequenceOfVec2d::*)(const Standard_Integer)) &TColgp_SequenceOfVec2d::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_TColgp_SequenceOfVec2d.def("__call__", (gp_Vec2d & (TColgp_SequenceOfVec2d::*)(const Standard_Integer)) &TColgp_SequenceOfVec2d::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_TColgp_SequenceOfVec2d.def("SetValue", (void (TColgp_SequenceOfVec2d::*)(const Standard_Integer, const gp_Vec2d &)) &TColgp_SequenceOfVec2d::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_TColgp_SequenceOfVec2d.def("__iter__", [](const TColgp_SequenceOfVec2d &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_HArray1OfPnt2d.hxx
	py::class_<TColgp_HArray1OfPnt2d, opencascade::handle<TColgp_HArray1OfPnt2d>, TColgp_Array1OfPnt2d, Standard_Transient> cls_TColgp_HArray1OfPnt2d(mod, "TColgp_HArray1OfPnt2d", "None");
	cls_TColgp_HArray1OfPnt2d.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColgp_HArray1OfPnt2d.def(py::init<const Standard_Integer, const Standard_Integer, const TColgp_Array1OfPnt2d::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_TColgp_HArray1OfPnt2d.def(py::init<const TColgp_Array1OfPnt2d &>(), py::arg("theOther"));
	cls_TColgp_HArray1OfPnt2d.def("Array1", (const TColgp_Array1OfPnt2d & (TColgp_HArray1OfPnt2d::*)() const ) &TColgp_HArray1OfPnt2d::Array1, "None");
	cls_TColgp_HArray1OfPnt2d.def("ChangeArray1", (TColgp_Array1OfPnt2d & (TColgp_HArray1OfPnt2d::*)()) &TColgp_HArray1OfPnt2d::ChangeArray1, "None");
	cls_TColgp_HArray1OfPnt2d.def_static("get_type_name_", (const char * (*)()) &TColgp_HArray1OfPnt2d::get_type_name, "None");
	cls_TColgp_HArray1OfPnt2d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HArray1OfPnt2d::get_type_descriptor, "None");
	cls_TColgp_HArray1OfPnt2d.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HArray1OfPnt2d::*)() const ) &TColgp_HArray1OfPnt2d::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_HArray1OfPnt.hxx
	py::class_<TColgp_HArray1OfPnt, opencascade::handle<TColgp_HArray1OfPnt>, TColgp_Array1OfPnt, Standard_Transient> cls_TColgp_HArray1OfPnt(mod, "TColgp_HArray1OfPnt", "None");
	cls_TColgp_HArray1OfPnt.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColgp_HArray1OfPnt.def(py::init<const Standard_Integer, const Standard_Integer, const TColgp_Array1OfPnt::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_TColgp_HArray1OfPnt.def(py::init<const TColgp_Array1OfPnt &>(), py::arg("theOther"));
	cls_TColgp_HArray1OfPnt.def("Array1", (const TColgp_Array1OfPnt & (TColgp_HArray1OfPnt::*)() const ) &TColgp_HArray1OfPnt::Array1, "None");
	cls_TColgp_HArray1OfPnt.def("ChangeArray1", (TColgp_Array1OfPnt & (TColgp_HArray1OfPnt::*)()) &TColgp_HArray1OfPnt::ChangeArray1, "None");
	cls_TColgp_HArray1OfPnt.def_static("get_type_name_", (const char * (*)()) &TColgp_HArray1OfPnt::get_type_name, "None");
	cls_TColgp_HArray1OfPnt.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HArray1OfPnt::get_type_descriptor, "None");
	cls_TColgp_HArray1OfPnt.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HArray1OfPnt::*)() const ) &TColgp_HArray1OfPnt::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_HArray2OfPnt.hxx
	py::class_<TColgp_HArray2OfPnt, opencascade::handle<TColgp_HArray2OfPnt>, TColgp_Array2OfPnt, Standard_Transient> cls_TColgp_HArray2OfPnt(mod, "TColgp_HArray2OfPnt", "None");
	cls_TColgp_HArray2OfPnt.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"));
	cls_TColgp_HArray2OfPnt.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const TColgp_Array2OfPnt::value_type &>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"), py::arg("theValue"));
	cls_TColgp_HArray2OfPnt.def(py::init<const TColgp_Array2OfPnt &>(), py::arg("theOther"));
	cls_TColgp_HArray2OfPnt.def("Array2", (const TColgp_Array2OfPnt & (TColgp_HArray2OfPnt::*)() const ) &TColgp_HArray2OfPnt::Array2, "None");
	cls_TColgp_HArray2OfPnt.def("ChangeArray2", (TColgp_Array2OfPnt & (TColgp_HArray2OfPnt::*)()) &TColgp_HArray2OfPnt::ChangeArray2, "None");
	cls_TColgp_HArray2OfPnt.def_static("get_type_name_", (const char * (*)()) &TColgp_HArray2OfPnt::get_type_name, "None");
	cls_TColgp_HArray2OfPnt.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HArray2OfPnt::get_type_descriptor, "None");
	cls_TColgp_HArray2OfPnt.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HArray2OfPnt::*)() const ) &TColgp_HArray2OfPnt::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_HArray2OfPnt2d.hxx
	py::class_<TColgp_HArray2OfPnt2d, opencascade::handle<TColgp_HArray2OfPnt2d>, TColgp_Array2OfPnt2d, Standard_Transient> cls_TColgp_HArray2OfPnt2d(mod, "TColgp_HArray2OfPnt2d", "None");
	cls_TColgp_HArray2OfPnt2d.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"));
	cls_TColgp_HArray2OfPnt2d.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const TColgp_Array2OfPnt2d::value_type &>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"), py::arg("theValue"));
	cls_TColgp_HArray2OfPnt2d.def(py::init<const TColgp_Array2OfPnt2d &>(), py::arg("theOther"));
	cls_TColgp_HArray2OfPnt2d.def("Array2", (const TColgp_Array2OfPnt2d & (TColgp_HArray2OfPnt2d::*)() const ) &TColgp_HArray2OfPnt2d::Array2, "None");
	cls_TColgp_HArray2OfPnt2d.def("ChangeArray2", (TColgp_Array2OfPnt2d & (TColgp_HArray2OfPnt2d::*)()) &TColgp_HArray2OfPnt2d::ChangeArray2, "None");
	cls_TColgp_HArray2OfPnt2d.def_static("get_type_name_", (const char * (*)()) &TColgp_HArray2OfPnt2d::get_type_name, "None");
	cls_TColgp_HArray2OfPnt2d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HArray2OfPnt2d::get_type_descriptor, "None");
	cls_TColgp_HArray2OfPnt2d.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HArray2OfPnt2d::*)() const ) &TColgp_HArray2OfPnt2d::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_HSequenceOfPnt.hxx
	py::class_<TColgp_HSequenceOfPnt, opencascade::handle<TColgp_HSequenceOfPnt>, TColgp_SequenceOfPnt, Standard_Transient> cls_TColgp_HSequenceOfPnt(mod, "TColgp_HSequenceOfPnt", "None");
	cls_TColgp_HSequenceOfPnt.def(py::init<>());
	cls_TColgp_HSequenceOfPnt.def(py::init<const TColgp_SequenceOfPnt &>(), py::arg("theOther"));
	cls_TColgp_HSequenceOfPnt.def("Sequence", (const TColgp_SequenceOfPnt & (TColgp_HSequenceOfPnt::*)() const ) &TColgp_HSequenceOfPnt::Sequence, "None");
	cls_TColgp_HSequenceOfPnt.def("Append", (void (TColgp_HSequenceOfPnt::*)(const TColgp_SequenceOfPnt::value_type &)) &TColgp_HSequenceOfPnt::Append, "None", py::arg("theItem"));
	cls_TColgp_HSequenceOfPnt.def("Append", (void (TColgp_HSequenceOfPnt::*)(TColgp_SequenceOfPnt &)) &TColgp_HSequenceOfPnt::Append, "None", py::arg("theSequence"));
	cls_TColgp_HSequenceOfPnt.def("ChangeSequence", (TColgp_SequenceOfPnt & (TColgp_HSequenceOfPnt::*)()) &TColgp_HSequenceOfPnt::ChangeSequence, "None");
	cls_TColgp_HSequenceOfPnt.def_static("get_type_name_", (const char * (*)()) &TColgp_HSequenceOfPnt::get_type_name, "None");
	cls_TColgp_HSequenceOfPnt.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HSequenceOfPnt::get_type_descriptor, "None");
	cls_TColgp_HSequenceOfPnt.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HSequenceOfPnt::*)() const ) &TColgp_HSequenceOfPnt::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_HArray1OfDir.hxx
	py::class_<TColgp_HArray1OfDir, opencascade::handle<TColgp_HArray1OfDir>, TColgp_Array1OfDir, Standard_Transient> cls_TColgp_HArray1OfDir(mod, "TColgp_HArray1OfDir", "None");
	cls_TColgp_HArray1OfDir.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColgp_HArray1OfDir.def(py::init<const Standard_Integer, const Standard_Integer, const TColgp_Array1OfDir::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_TColgp_HArray1OfDir.def(py::init<const TColgp_Array1OfDir &>(), py::arg("theOther"));
	cls_TColgp_HArray1OfDir.def("Array1", (const TColgp_Array1OfDir & (TColgp_HArray1OfDir::*)() const ) &TColgp_HArray1OfDir::Array1, "None");
	cls_TColgp_HArray1OfDir.def("ChangeArray1", (TColgp_Array1OfDir & (TColgp_HArray1OfDir::*)()) &TColgp_HArray1OfDir::ChangeArray1, "None");
	cls_TColgp_HArray1OfDir.def_static("get_type_name_", (const char * (*)()) &TColgp_HArray1OfDir::get_type_name, "None");
	cls_TColgp_HArray1OfDir.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HArray1OfDir::get_type_descriptor, "None");
	cls_TColgp_HArray1OfDir.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HArray1OfDir::*)() const ) &TColgp_HArray1OfDir::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_HArray1OfVec.hxx
	py::class_<TColgp_HArray1OfVec, opencascade::handle<TColgp_HArray1OfVec>, TColgp_Array1OfVec, Standard_Transient> cls_TColgp_HArray1OfVec(mod, "TColgp_HArray1OfVec", "None");
	cls_TColgp_HArray1OfVec.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColgp_HArray1OfVec.def(py::init<const Standard_Integer, const Standard_Integer, const TColgp_Array1OfVec::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_TColgp_HArray1OfVec.def(py::init<const TColgp_Array1OfVec &>(), py::arg("theOther"));
	cls_TColgp_HArray1OfVec.def("Array1", (const TColgp_Array1OfVec & (TColgp_HArray1OfVec::*)() const ) &TColgp_HArray1OfVec::Array1, "None");
	cls_TColgp_HArray1OfVec.def("ChangeArray1", (TColgp_Array1OfVec & (TColgp_HArray1OfVec::*)()) &TColgp_HArray1OfVec::ChangeArray1, "None");
	cls_TColgp_HArray1OfVec.def_static("get_type_name_", (const char * (*)()) &TColgp_HArray1OfVec::get_type_name, "None");
	cls_TColgp_HArray1OfVec.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HArray1OfVec::get_type_descriptor, "None");
	cls_TColgp_HArray1OfVec.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HArray1OfVec::*)() const ) &TColgp_HArray1OfVec::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_HArray1OfVec2d.hxx
	py::class_<TColgp_HArray1OfVec2d, opencascade::handle<TColgp_HArray1OfVec2d>, TColgp_Array1OfVec2d, Standard_Transient> cls_TColgp_HArray1OfVec2d(mod, "TColgp_HArray1OfVec2d", "None");
	cls_TColgp_HArray1OfVec2d.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColgp_HArray1OfVec2d.def(py::init<const Standard_Integer, const Standard_Integer, const TColgp_Array1OfVec2d::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_TColgp_HArray1OfVec2d.def(py::init<const TColgp_Array1OfVec2d &>(), py::arg("theOther"));
	cls_TColgp_HArray1OfVec2d.def("Array1", (const TColgp_Array1OfVec2d & (TColgp_HArray1OfVec2d::*)() const ) &TColgp_HArray1OfVec2d::Array1, "None");
	cls_TColgp_HArray1OfVec2d.def("ChangeArray1", (TColgp_Array1OfVec2d & (TColgp_HArray1OfVec2d::*)()) &TColgp_HArray1OfVec2d::ChangeArray1, "None");
	cls_TColgp_HArray1OfVec2d.def_static("get_type_name_", (const char * (*)()) &TColgp_HArray1OfVec2d::get_type_name, "None");
	cls_TColgp_HArray1OfVec2d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HArray1OfVec2d::get_type_descriptor, "None");
	cls_TColgp_HArray1OfVec2d.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HArray1OfVec2d::*)() const ) &TColgp_HArray1OfVec2d::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<TColgp_SequenceOfArray1OfPnt2d, std::unique_ptr<TColgp_SequenceOfArray1OfPnt2d, Deleter<TColgp_SequenceOfArray1OfPnt2d>>, NCollection_BaseSequence> cls_TColgp_SequenceOfArray1OfPnt2d(mod, "TColgp_SequenceOfArray1OfPnt2d", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_TColgp_SequenceOfArray1OfPnt2d.def(py::init<>());
	cls_TColgp_SequenceOfArray1OfPnt2d.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_TColgp_SequenceOfArray1OfPnt2d.def(py::init([] (const TColgp_SequenceOfArray1OfPnt2d &other) {return new TColgp_SequenceOfArray1OfPnt2d(other);}), "Copy constructor", py::arg("other"));
	cls_TColgp_SequenceOfArray1OfPnt2d.def("begin", (TColgp_SequenceOfArray1OfPnt2d::iterator (TColgp_SequenceOfArray1OfPnt2d::*)() const ) &TColgp_SequenceOfArray1OfPnt2d::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_TColgp_SequenceOfArray1OfPnt2d.def("end", (TColgp_SequenceOfArray1OfPnt2d::iterator (TColgp_SequenceOfArray1OfPnt2d::*)() const ) &TColgp_SequenceOfArray1OfPnt2d::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_TColgp_SequenceOfArray1OfPnt2d.def("cbegin", (TColgp_SequenceOfArray1OfPnt2d::const_iterator (TColgp_SequenceOfArray1OfPnt2d::*)() const ) &TColgp_SequenceOfArray1OfPnt2d::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_TColgp_SequenceOfArray1OfPnt2d.def("cend", (TColgp_SequenceOfArray1OfPnt2d::const_iterator (TColgp_SequenceOfArray1OfPnt2d::*)() const ) &TColgp_SequenceOfArray1OfPnt2d::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_TColgp_SequenceOfArray1OfPnt2d.def("Size", (Standard_Integer (TColgp_SequenceOfArray1OfPnt2d::*)() const ) &TColgp_SequenceOfArray1OfPnt2d::Size, "Number of items");
	cls_TColgp_SequenceOfArray1OfPnt2d.def("Length", (Standard_Integer (TColgp_SequenceOfArray1OfPnt2d::*)() const ) &TColgp_SequenceOfArray1OfPnt2d::Length, "Number of items");
	cls_TColgp_SequenceOfArray1OfPnt2d.def("Lower", (Standard_Integer (TColgp_SequenceOfArray1OfPnt2d::*)() const ) &TColgp_SequenceOfArray1OfPnt2d::Lower, "Method for consistency with other collections.");
	cls_TColgp_SequenceOfArray1OfPnt2d.def("Upper", (Standard_Integer (TColgp_SequenceOfArray1OfPnt2d::*)() const ) &TColgp_SequenceOfArray1OfPnt2d::Upper, "Method for consistency with other collections.");
	cls_TColgp_SequenceOfArray1OfPnt2d.def("IsEmpty", (Standard_Boolean (TColgp_SequenceOfArray1OfPnt2d::*)() const ) &TColgp_SequenceOfArray1OfPnt2d::IsEmpty, "Empty query");
	cls_TColgp_SequenceOfArray1OfPnt2d.def("Reverse", (void (TColgp_SequenceOfArray1OfPnt2d::*)()) &TColgp_SequenceOfArray1OfPnt2d::Reverse, "Reverse sequence");
	cls_TColgp_SequenceOfArray1OfPnt2d.def("Exchange", (void (TColgp_SequenceOfArray1OfPnt2d::*)(const Standard_Integer, const Standard_Integer)) &TColgp_SequenceOfArray1OfPnt2d::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_TColgp_SequenceOfArray1OfPnt2d.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_SequenceOfArray1OfPnt2d::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_TColgp_SequenceOfArray1OfPnt2d.def("Clear", [](TColgp_SequenceOfArray1OfPnt2d &self) -> void { return self.Clear(); });
	cls_TColgp_SequenceOfArray1OfPnt2d.def("Clear", (void (TColgp_SequenceOfArray1OfPnt2d::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_SequenceOfArray1OfPnt2d::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_TColgp_SequenceOfArray1OfPnt2d.def("Assign", (TColgp_SequenceOfArray1OfPnt2d & (TColgp_SequenceOfArray1OfPnt2d::*)(const TColgp_SequenceOfArray1OfPnt2d &)) &TColgp_SequenceOfArray1OfPnt2d::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TColgp_SequenceOfArray1OfPnt2d.def("assign", (TColgp_SequenceOfArray1OfPnt2d & (TColgp_SequenceOfArray1OfPnt2d::*)(const TColgp_SequenceOfArray1OfPnt2d &)) &TColgp_SequenceOfArray1OfPnt2d::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_TColgp_SequenceOfArray1OfPnt2d.def("Remove", (void (TColgp_SequenceOfArray1OfPnt2d::*)(TColgp_SequenceOfArray1OfPnt2d::Iterator &)) &TColgp_SequenceOfArray1OfPnt2d::Remove, "Remove one item", py::arg("thePosition"));
	cls_TColgp_SequenceOfArray1OfPnt2d.def("Remove", (void (TColgp_SequenceOfArray1OfPnt2d::*)(const Standard_Integer)) &TColgp_SequenceOfArray1OfPnt2d::Remove, "Remove one item", py::arg("theIndex"));
	cls_TColgp_SequenceOfArray1OfPnt2d.def("Remove", (void (TColgp_SequenceOfArray1OfPnt2d::*)(const Standard_Integer, const Standard_Integer)) &TColgp_SequenceOfArray1OfPnt2d::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_TColgp_SequenceOfArray1OfPnt2d.def("Append", (void (TColgp_SequenceOfArray1OfPnt2d::*)(const opencascade::handle<TColgp_HArray1OfPnt2d> &)) &TColgp_SequenceOfArray1OfPnt2d::Append, "Append one item", py::arg("theItem"));
	cls_TColgp_SequenceOfArray1OfPnt2d.def("Append", (void (TColgp_SequenceOfArray1OfPnt2d::*)(TColgp_SequenceOfArray1OfPnt2d &)) &TColgp_SequenceOfArray1OfPnt2d::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_TColgp_SequenceOfArray1OfPnt2d.def("Prepend", (void (TColgp_SequenceOfArray1OfPnt2d::*)(const opencascade::handle<TColgp_HArray1OfPnt2d> &)) &TColgp_SequenceOfArray1OfPnt2d::Prepend, "Prepend one item", py::arg("theItem"));
	cls_TColgp_SequenceOfArray1OfPnt2d.def("Prepend", (void (TColgp_SequenceOfArray1OfPnt2d::*)(TColgp_SequenceOfArray1OfPnt2d &)) &TColgp_SequenceOfArray1OfPnt2d::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_TColgp_SequenceOfArray1OfPnt2d.def("InsertBefore", (void (TColgp_SequenceOfArray1OfPnt2d::*)(const Standard_Integer, const opencascade::handle<TColgp_HArray1OfPnt2d> &)) &TColgp_SequenceOfArray1OfPnt2d::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_TColgp_SequenceOfArray1OfPnt2d.def("InsertBefore", (void (TColgp_SequenceOfArray1OfPnt2d::*)(const Standard_Integer, TColgp_SequenceOfArray1OfPnt2d &)) &TColgp_SequenceOfArray1OfPnt2d::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColgp_SequenceOfArray1OfPnt2d.def("InsertAfter", (void (TColgp_SequenceOfArray1OfPnt2d::*)(TColgp_SequenceOfArray1OfPnt2d::Iterator &, const opencascade::handle<TColgp_HArray1OfPnt2d> &)) &TColgp_SequenceOfArray1OfPnt2d::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_TColgp_SequenceOfArray1OfPnt2d.def("InsertAfter", (void (TColgp_SequenceOfArray1OfPnt2d::*)(const Standard_Integer, TColgp_SequenceOfArray1OfPnt2d &)) &TColgp_SequenceOfArray1OfPnt2d::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColgp_SequenceOfArray1OfPnt2d.def("InsertAfter", (void (TColgp_SequenceOfArray1OfPnt2d::*)(const Standard_Integer, const opencascade::handle<TColgp_HArray1OfPnt2d> &)) &TColgp_SequenceOfArray1OfPnt2d::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_TColgp_SequenceOfArray1OfPnt2d.def("Split", (void (TColgp_SequenceOfArray1OfPnt2d::*)(const Standard_Integer, TColgp_SequenceOfArray1OfPnt2d &)) &TColgp_SequenceOfArray1OfPnt2d::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColgp_SequenceOfArray1OfPnt2d.def("First", (const opencascade::handle<TColgp_HArray1OfPnt2d> & (TColgp_SequenceOfArray1OfPnt2d::*)() const ) &TColgp_SequenceOfArray1OfPnt2d::First, "First item access");
	cls_TColgp_SequenceOfArray1OfPnt2d.def("ChangeFirst", (opencascade::handle<TColgp_HArray1OfPnt2d> & (TColgp_SequenceOfArray1OfPnt2d::*)()) &TColgp_SequenceOfArray1OfPnt2d::ChangeFirst, "First item access");
	cls_TColgp_SequenceOfArray1OfPnt2d.def("Last", (const opencascade::handle<TColgp_HArray1OfPnt2d> & (TColgp_SequenceOfArray1OfPnt2d::*)() const ) &TColgp_SequenceOfArray1OfPnt2d::Last, "Last item access");
	cls_TColgp_SequenceOfArray1OfPnt2d.def("ChangeLast", (opencascade::handle<TColgp_HArray1OfPnt2d> & (TColgp_SequenceOfArray1OfPnt2d::*)()) &TColgp_SequenceOfArray1OfPnt2d::ChangeLast, "Last item access");
	cls_TColgp_SequenceOfArray1OfPnt2d.def("Value", (const opencascade::handle<TColgp_HArray1OfPnt2d> & (TColgp_SequenceOfArray1OfPnt2d::*)(const Standard_Integer) const ) &TColgp_SequenceOfArray1OfPnt2d::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_TColgp_SequenceOfArray1OfPnt2d.def("__call__", (const opencascade::handle<TColgp_HArray1OfPnt2d> & (TColgp_SequenceOfArray1OfPnt2d::*)(const Standard_Integer) const ) &TColgp_SequenceOfArray1OfPnt2d::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_TColgp_SequenceOfArray1OfPnt2d.def("ChangeValue", (opencascade::handle<TColgp_HArray1OfPnt2d> & (TColgp_SequenceOfArray1OfPnt2d::*)(const Standard_Integer)) &TColgp_SequenceOfArray1OfPnt2d::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_TColgp_SequenceOfArray1OfPnt2d.def("__call__", (opencascade::handle<TColgp_HArray1OfPnt2d> & (TColgp_SequenceOfArray1OfPnt2d::*)(const Standard_Integer)) &TColgp_SequenceOfArray1OfPnt2d::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_TColgp_SequenceOfArray1OfPnt2d.def("SetValue", (void (TColgp_SequenceOfArray1OfPnt2d::*)(const Standard_Integer, const opencascade::handle<TColgp_HArray1OfPnt2d> &)) &TColgp_SequenceOfArray1OfPnt2d::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_TColgp_SequenceOfArray1OfPnt2d.def("__iter__", [](const TColgp_SequenceOfArray1OfPnt2d &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_HArray2OfXYZ.hxx
	py::class_<TColgp_HArray2OfXYZ, opencascade::handle<TColgp_HArray2OfXYZ>, TColgp_Array2OfXYZ, Standard_Transient> cls_TColgp_HArray2OfXYZ(mod, "TColgp_HArray2OfXYZ", "None");
	cls_TColgp_HArray2OfXYZ.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"));
	cls_TColgp_HArray2OfXYZ.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const TColgp_Array2OfXYZ::value_type &>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"), py::arg("theValue"));
	cls_TColgp_HArray2OfXYZ.def(py::init<const TColgp_Array2OfXYZ &>(), py::arg("theOther"));
	cls_TColgp_HArray2OfXYZ.def("Array2", (const TColgp_Array2OfXYZ & (TColgp_HArray2OfXYZ::*)() const ) &TColgp_HArray2OfXYZ::Array2, "None");
	cls_TColgp_HArray2OfXYZ.def("ChangeArray2", (TColgp_Array2OfXYZ & (TColgp_HArray2OfXYZ::*)()) &TColgp_HArray2OfXYZ::ChangeArray2, "None");
	cls_TColgp_HArray2OfXYZ.def_static("get_type_name_", (const char * (*)()) &TColgp_HArray2OfXYZ::get_type_name, "None");
	cls_TColgp_HArray2OfXYZ.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HArray2OfXYZ::get_type_descriptor, "None");
	cls_TColgp_HArray2OfXYZ.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HArray2OfXYZ::*)() const ) &TColgp_HArray2OfXYZ::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_HArray1OfXYZ.hxx
	py::class_<TColgp_HArray1OfXYZ, opencascade::handle<TColgp_HArray1OfXYZ>, TColgp_Array1OfXYZ, Standard_Transient> cls_TColgp_HArray1OfXYZ(mod, "TColgp_HArray1OfXYZ", "None");
	cls_TColgp_HArray1OfXYZ.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColgp_HArray1OfXYZ.def(py::init<const Standard_Integer, const Standard_Integer, const TColgp_Array1OfXYZ::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_TColgp_HArray1OfXYZ.def(py::init<const TColgp_Array1OfXYZ &>(), py::arg("theOther"));
	cls_TColgp_HArray1OfXYZ.def("Array1", (const TColgp_Array1OfXYZ & (TColgp_HArray1OfXYZ::*)() const ) &TColgp_HArray1OfXYZ::Array1, "None");
	cls_TColgp_HArray1OfXYZ.def("ChangeArray1", (TColgp_Array1OfXYZ & (TColgp_HArray1OfXYZ::*)()) &TColgp_HArray1OfXYZ::ChangeArray1, "None");
	cls_TColgp_HArray1OfXYZ.def_static("get_type_name_", (const char * (*)()) &TColgp_HArray1OfXYZ::get_type_name, "None");
	cls_TColgp_HArray1OfXYZ.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HArray1OfXYZ::get_type_descriptor, "None");
	cls_TColgp_HArray1OfXYZ.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HArray1OfXYZ::*)() const ) &TColgp_HArray1OfXYZ::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_HSequenceOfXY.hxx
	py::class_<TColgp_HSequenceOfXY, opencascade::handle<TColgp_HSequenceOfXY>, TColgp_SequenceOfXY, Standard_Transient> cls_TColgp_HSequenceOfXY(mod, "TColgp_HSequenceOfXY", "None");
	cls_TColgp_HSequenceOfXY.def(py::init<>());
	cls_TColgp_HSequenceOfXY.def(py::init<const TColgp_SequenceOfXY &>(), py::arg("theOther"));
	cls_TColgp_HSequenceOfXY.def("Sequence", (const TColgp_SequenceOfXY & (TColgp_HSequenceOfXY::*)() const ) &TColgp_HSequenceOfXY::Sequence, "None");
	cls_TColgp_HSequenceOfXY.def("Append", (void (TColgp_HSequenceOfXY::*)(const TColgp_SequenceOfXY::value_type &)) &TColgp_HSequenceOfXY::Append, "None", py::arg("theItem"));
	cls_TColgp_HSequenceOfXY.def("Append", (void (TColgp_HSequenceOfXY::*)(TColgp_SequenceOfXY &)) &TColgp_HSequenceOfXY::Append, "None", py::arg("theSequence"));
	cls_TColgp_HSequenceOfXY.def("ChangeSequence", (TColgp_SequenceOfXY & (TColgp_HSequenceOfXY::*)()) &TColgp_HSequenceOfXY::ChangeSequence, "None");
	cls_TColgp_HSequenceOfXY.def_static("get_type_name_", (const char * (*)()) &TColgp_HSequenceOfXY::get_type_name, "None");
	cls_TColgp_HSequenceOfXY.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HSequenceOfXY::get_type_descriptor, "None");
	cls_TColgp_HSequenceOfXY.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HSequenceOfXY::*)() const ) &TColgp_HSequenceOfXY::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_HSequenceOfXYZ.hxx
	py::class_<TColgp_HSequenceOfXYZ, opencascade::handle<TColgp_HSequenceOfXYZ>, TColgp_SequenceOfXYZ, Standard_Transient> cls_TColgp_HSequenceOfXYZ(mod, "TColgp_HSequenceOfXYZ", "None");
	cls_TColgp_HSequenceOfXYZ.def(py::init<>());
	cls_TColgp_HSequenceOfXYZ.def(py::init<const TColgp_SequenceOfXYZ &>(), py::arg("theOther"));
	cls_TColgp_HSequenceOfXYZ.def("Sequence", (const TColgp_SequenceOfXYZ & (TColgp_HSequenceOfXYZ::*)() const ) &TColgp_HSequenceOfXYZ::Sequence, "None");
	cls_TColgp_HSequenceOfXYZ.def("Append", (void (TColgp_HSequenceOfXYZ::*)(const TColgp_SequenceOfXYZ::value_type &)) &TColgp_HSequenceOfXYZ::Append, "None", py::arg("theItem"));
	cls_TColgp_HSequenceOfXYZ.def("Append", (void (TColgp_HSequenceOfXYZ::*)(TColgp_SequenceOfXYZ &)) &TColgp_HSequenceOfXYZ::Append, "None", py::arg("theSequence"));
	cls_TColgp_HSequenceOfXYZ.def("ChangeSequence", (TColgp_SequenceOfXYZ & (TColgp_HSequenceOfXYZ::*)()) &TColgp_HSequenceOfXYZ::ChangeSequence, "None");
	cls_TColgp_HSequenceOfXYZ.def_static("get_type_name_", (const char * (*)()) &TColgp_HSequenceOfXYZ::get_type_name, "None");
	cls_TColgp_HSequenceOfXYZ.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HSequenceOfXYZ::get_type_descriptor, "None");
	cls_TColgp_HSequenceOfXYZ.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HSequenceOfXYZ::*)() const ) &TColgp_HSequenceOfXYZ::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_HSequenceOfPnt2d.hxx
	py::class_<TColgp_HSequenceOfPnt2d, opencascade::handle<TColgp_HSequenceOfPnt2d>, TColgp_SequenceOfPnt2d, Standard_Transient> cls_TColgp_HSequenceOfPnt2d(mod, "TColgp_HSequenceOfPnt2d", "None");
	cls_TColgp_HSequenceOfPnt2d.def(py::init<>());
	cls_TColgp_HSequenceOfPnt2d.def(py::init<const TColgp_SequenceOfPnt2d &>(), py::arg("theOther"));
	cls_TColgp_HSequenceOfPnt2d.def("Sequence", (const TColgp_SequenceOfPnt2d & (TColgp_HSequenceOfPnt2d::*)() const ) &TColgp_HSequenceOfPnt2d::Sequence, "None");
	cls_TColgp_HSequenceOfPnt2d.def("Append", (void (TColgp_HSequenceOfPnt2d::*)(const TColgp_SequenceOfPnt2d::value_type &)) &TColgp_HSequenceOfPnt2d::Append, "None", py::arg("theItem"));
	cls_TColgp_HSequenceOfPnt2d.def("Append", (void (TColgp_HSequenceOfPnt2d::*)(TColgp_SequenceOfPnt2d &)) &TColgp_HSequenceOfPnt2d::Append, "None", py::arg("theSequence"));
	cls_TColgp_HSequenceOfPnt2d.def("ChangeSequence", (TColgp_SequenceOfPnt2d & (TColgp_HSequenceOfPnt2d::*)()) &TColgp_HSequenceOfPnt2d::ChangeSequence, "None");
	cls_TColgp_HSequenceOfPnt2d.def_static("get_type_name_", (const char * (*)()) &TColgp_HSequenceOfPnt2d::get_type_name, "None");
	cls_TColgp_HSequenceOfPnt2d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HSequenceOfPnt2d::get_type_descriptor, "None");
	cls_TColgp_HSequenceOfPnt2d.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HSequenceOfPnt2d::*)() const ) &TColgp_HSequenceOfPnt2d::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<TColgp_SequenceOfAx1, std::unique_ptr<TColgp_SequenceOfAx1, Deleter<TColgp_SequenceOfAx1>>, NCollection_BaseSequence> cls_TColgp_SequenceOfAx1(mod, "TColgp_SequenceOfAx1", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_TColgp_SequenceOfAx1.def(py::init<>());
	cls_TColgp_SequenceOfAx1.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_TColgp_SequenceOfAx1.def(py::init([] (const TColgp_SequenceOfAx1 &other) {return new TColgp_SequenceOfAx1(other);}), "Copy constructor", py::arg("other"));
	cls_TColgp_SequenceOfAx1.def("begin", (TColgp_SequenceOfAx1::iterator (TColgp_SequenceOfAx1::*)() const ) &TColgp_SequenceOfAx1::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_TColgp_SequenceOfAx1.def("end", (TColgp_SequenceOfAx1::iterator (TColgp_SequenceOfAx1::*)() const ) &TColgp_SequenceOfAx1::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_TColgp_SequenceOfAx1.def("cbegin", (TColgp_SequenceOfAx1::const_iterator (TColgp_SequenceOfAx1::*)() const ) &TColgp_SequenceOfAx1::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_TColgp_SequenceOfAx1.def("cend", (TColgp_SequenceOfAx1::const_iterator (TColgp_SequenceOfAx1::*)() const ) &TColgp_SequenceOfAx1::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_TColgp_SequenceOfAx1.def("Size", (Standard_Integer (TColgp_SequenceOfAx1::*)() const ) &TColgp_SequenceOfAx1::Size, "Number of items");
	cls_TColgp_SequenceOfAx1.def("Length", (Standard_Integer (TColgp_SequenceOfAx1::*)() const ) &TColgp_SequenceOfAx1::Length, "Number of items");
	cls_TColgp_SequenceOfAx1.def("Lower", (Standard_Integer (TColgp_SequenceOfAx1::*)() const ) &TColgp_SequenceOfAx1::Lower, "Method for consistency with other collections.");
	cls_TColgp_SequenceOfAx1.def("Upper", (Standard_Integer (TColgp_SequenceOfAx1::*)() const ) &TColgp_SequenceOfAx1::Upper, "Method for consistency with other collections.");
	cls_TColgp_SequenceOfAx1.def("IsEmpty", (Standard_Boolean (TColgp_SequenceOfAx1::*)() const ) &TColgp_SequenceOfAx1::IsEmpty, "Empty query");
	cls_TColgp_SequenceOfAx1.def("Reverse", (void (TColgp_SequenceOfAx1::*)()) &TColgp_SequenceOfAx1::Reverse, "Reverse sequence");
	cls_TColgp_SequenceOfAx1.def("Exchange", (void (TColgp_SequenceOfAx1::*)(const Standard_Integer, const Standard_Integer)) &TColgp_SequenceOfAx1::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_TColgp_SequenceOfAx1.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_SequenceOfAx1::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_TColgp_SequenceOfAx1.def("Clear", [](TColgp_SequenceOfAx1 &self) -> void { return self.Clear(); });
	cls_TColgp_SequenceOfAx1.def("Clear", (void (TColgp_SequenceOfAx1::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_SequenceOfAx1::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_TColgp_SequenceOfAx1.def("Assign", (TColgp_SequenceOfAx1 & (TColgp_SequenceOfAx1::*)(const TColgp_SequenceOfAx1 &)) &TColgp_SequenceOfAx1::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_TColgp_SequenceOfAx1.def("assign", (TColgp_SequenceOfAx1 & (TColgp_SequenceOfAx1::*)(const TColgp_SequenceOfAx1 &)) &TColgp_SequenceOfAx1::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_TColgp_SequenceOfAx1.def("Remove", (void (TColgp_SequenceOfAx1::*)(TColgp_SequenceOfAx1::Iterator &)) &TColgp_SequenceOfAx1::Remove, "Remove one item", py::arg("thePosition"));
	cls_TColgp_SequenceOfAx1.def("Remove", (void (TColgp_SequenceOfAx1::*)(const Standard_Integer)) &TColgp_SequenceOfAx1::Remove, "Remove one item", py::arg("theIndex"));
	cls_TColgp_SequenceOfAx1.def("Remove", (void (TColgp_SequenceOfAx1::*)(const Standard_Integer, const Standard_Integer)) &TColgp_SequenceOfAx1::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_TColgp_SequenceOfAx1.def("Append", (void (TColgp_SequenceOfAx1::*)(const gp_Ax1 &)) &TColgp_SequenceOfAx1::Append, "Append one item", py::arg("theItem"));
	cls_TColgp_SequenceOfAx1.def("Append", (void (TColgp_SequenceOfAx1::*)(TColgp_SequenceOfAx1 &)) &TColgp_SequenceOfAx1::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_TColgp_SequenceOfAx1.def("Prepend", (void (TColgp_SequenceOfAx1::*)(const gp_Ax1 &)) &TColgp_SequenceOfAx1::Prepend, "Prepend one item", py::arg("theItem"));
	cls_TColgp_SequenceOfAx1.def("Prepend", (void (TColgp_SequenceOfAx1::*)(TColgp_SequenceOfAx1 &)) &TColgp_SequenceOfAx1::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_TColgp_SequenceOfAx1.def("InsertBefore", (void (TColgp_SequenceOfAx1::*)(const Standard_Integer, const gp_Ax1 &)) &TColgp_SequenceOfAx1::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_TColgp_SequenceOfAx1.def("InsertBefore", (void (TColgp_SequenceOfAx1::*)(const Standard_Integer, TColgp_SequenceOfAx1 &)) &TColgp_SequenceOfAx1::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColgp_SequenceOfAx1.def("InsertAfter", (void (TColgp_SequenceOfAx1::*)(TColgp_SequenceOfAx1::Iterator &, const gp_Ax1 &)) &TColgp_SequenceOfAx1::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_TColgp_SequenceOfAx1.def("InsertAfter", (void (TColgp_SequenceOfAx1::*)(const Standard_Integer, TColgp_SequenceOfAx1 &)) &TColgp_SequenceOfAx1::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColgp_SequenceOfAx1.def("InsertAfter", (void (TColgp_SequenceOfAx1::*)(const Standard_Integer, const gp_Ax1 &)) &TColgp_SequenceOfAx1::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_TColgp_SequenceOfAx1.def("Split", (void (TColgp_SequenceOfAx1::*)(const Standard_Integer, TColgp_SequenceOfAx1 &)) &TColgp_SequenceOfAx1::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_TColgp_SequenceOfAx1.def("First", (const gp_Ax1 & (TColgp_SequenceOfAx1::*)() const ) &TColgp_SequenceOfAx1::First, "First item access");
	cls_TColgp_SequenceOfAx1.def("ChangeFirst", (gp_Ax1 & (TColgp_SequenceOfAx1::*)()) &TColgp_SequenceOfAx1::ChangeFirst, "First item access");
	cls_TColgp_SequenceOfAx1.def("Last", (const gp_Ax1 & (TColgp_SequenceOfAx1::*)() const ) &TColgp_SequenceOfAx1::Last, "Last item access");
	cls_TColgp_SequenceOfAx1.def("ChangeLast", (gp_Ax1 & (TColgp_SequenceOfAx1::*)()) &TColgp_SequenceOfAx1::ChangeLast, "Last item access");
	cls_TColgp_SequenceOfAx1.def("Value", (const gp_Ax1 & (TColgp_SequenceOfAx1::*)(const Standard_Integer) const ) &TColgp_SequenceOfAx1::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_TColgp_SequenceOfAx1.def("__call__", (const gp_Ax1 & (TColgp_SequenceOfAx1::*)(const Standard_Integer) const ) &TColgp_SequenceOfAx1::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_TColgp_SequenceOfAx1.def("ChangeValue", (gp_Ax1 & (TColgp_SequenceOfAx1::*)(const Standard_Integer)) &TColgp_SequenceOfAx1::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_TColgp_SequenceOfAx1.def("__call__", (gp_Ax1 & (TColgp_SequenceOfAx1::*)(const Standard_Integer)) &TColgp_SequenceOfAx1::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_TColgp_SequenceOfAx1.def("SetValue", (void (TColgp_SequenceOfAx1::*)(const Standard_Integer, const gp_Ax1 &)) &TColgp_SequenceOfAx1::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_TColgp_SequenceOfAx1.def("__iter__", [](const TColgp_SequenceOfAx1 &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_HArray2OfVec.hxx
	py::class_<TColgp_HArray2OfVec, opencascade::handle<TColgp_HArray2OfVec>, TColgp_Array2OfVec, Standard_Transient> cls_TColgp_HArray2OfVec(mod, "TColgp_HArray2OfVec", "None");
	cls_TColgp_HArray2OfVec.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"));
	cls_TColgp_HArray2OfVec.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const TColgp_Array2OfVec::value_type &>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"), py::arg("theValue"));
	cls_TColgp_HArray2OfVec.def(py::init<const TColgp_Array2OfVec &>(), py::arg("theOther"));
	cls_TColgp_HArray2OfVec.def("Array2", (const TColgp_Array2OfVec & (TColgp_HArray2OfVec::*)() const ) &TColgp_HArray2OfVec::Array2, "None");
	cls_TColgp_HArray2OfVec.def("ChangeArray2", (TColgp_Array2OfVec & (TColgp_HArray2OfVec::*)()) &TColgp_HArray2OfVec::ChangeArray2, "None");
	cls_TColgp_HArray2OfVec.def_static("get_type_name_", (const char * (*)()) &TColgp_HArray2OfVec::get_type_name, "None");
	cls_TColgp_HArray2OfVec.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HArray2OfVec::get_type_descriptor, "None");
	cls_TColgp_HArray2OfVec.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HArray2OfVec::*)() const ) &TColgp_HArray2OfVec::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_HArray1OfXY.hxx
	py::class_<TColgp_HArray1OfXY, opencascade::handle<TColgp_HArray1OfXY>, TColgp_Array1OfXY, Standard_Transient> cls_TColgp_HArray1OfXY(mod, "TColgp_HArray1OfXY", "None");
	cls_TColgp_HArray1OfXY.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColgp_HArray1OfXY.def(py::init<const Standard_Integer, const Standard_Integer, const TColgp_Array1OfXY::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_TColgp_HArray1OfXY.def(py::init<const TColgp_Array1OfXY &>(), py::arg("theOther"));
	cls_TColgp_HArray1OfXY.def("Array1", (const TColgp_Array1OfXY & (TColgp_HArray1OfXY::*)() const ) &TColgp_HArray1OfXY::Array1, "None");
	cls_TColgp_HArray1OfXY.def("ChangeArray1", (TColgp_Array1OfXY & (TColgp_HArray1OfXY::*)()) &TColgp_HArray1OfXY::ChangeArray1, "None");
	cls_TColgp_HArray1OfXY.def_static("get_type_name_", (const char * (*)()) &TColgp_HArray1OfXY::get_type_name, "None");
	cls_TColgp_HArray1OfXY.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HArray1OfXY::get_type_descriptor, "None");
	cls_TColgp_HArray1OfXY.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HArray1OfXY::*)() const ) &TColgp_HArray1OfXY::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_HArray1OfCirc2d.hxx
	py::class_<TColgp_HArray1OfCirc2d, opencascade::handle<TColgp_HArray1OfCirc2d>, TColgp_Array1OfCirc2d, Standard_Transient> cls_TColgp_HArray1OfCirc2d(mod, "TColgp_HArray1OfCirc2d", "None");
	cls_TColgp_HArray1OfCirc2d.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColgp_HArray1OfCirc2d.def(py::init<const Standard_Integer, const Standard_Integer, const TColgp_Array1OfCirc2d::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_TColgp_HArray1OfCirc2d.def(py::init<const TColgp_Array1OfCirc2d &>(), py::arg("theOther"));
	cls_TColgp_HArray1OfCirc2d.def("Array1", (const TColgp_Array1OfCirc2d & (TColgp_HArray1OfCirc2d::*)() const ) &TColgp_HArray1OfCirc2d::Array1, "None");
	cls_TColgp_HArray1OfCirc2d.def("ChangeArray1", (TColgp_Array1OfCirc2d & (TColgp_HArray1OfCirc2d::*)()) &TColgp_HArray1OfCirc2d::ChangeArray1, "None");
	cls_TColgp_HArray1OfCirc2d.def_static("get_type_name_", (const char * (*)()) &TColgp_HArray1OfCirc2d::get_type_name, "None");
	cls_TColgp_HArray1OfCirc2d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HArray1OfCirc2d::get_type_descriptor, "None");
	cls_TColgp_HArray1OfCirc2d.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HArray1OfCirc2d::*)() const ) &TColgp_HArray1OfCirc2d::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_HArray1OfLin2d.hxx
	py::class_<TColgp_HArray1OfLin2d, opencascade::handle<TColgp_HArray1OfLin2d>, TColgp_Array1OfLin2d, Standard_Transient> cls_TColgp_HArray1OfLin2d(mod, "TColgp_HArray1OfLin2d", "None");
	cls_TColgp_HArray1OfLin2d.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColgp_HArray1OfLin2d.def(py::init<const Standard_Integer, const Standard_Integer, const TColgp_Array1OfLin2d::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_TColgp_HArray1OfLin2d.def(py::init<const TColgp_Array1OfLin2d &>(), py::arg("theOther"));
	cls_TColgp_HArray1OfLin2d.def("Array1", (const TColgp_Array1OfLin2d & (TColgp_HArray1OfLin2d::*)() const ) &TColgp_HArray1OfLin2d::Array1, "None");
	cls_TColgp_HArray1OfLin2d.def("ChangeArray1", (TColgp_Array1OfLin2d & (TColgp_HArray1OfLin2d::*)()) &TColgp_HArray1OfLin2d::ChangeArray1, "None");
	cls_TColgp_HArray1OfLin2d.def_static("get_type_name_", (const char * (*)()) &TColgp_HArray1OfLin2d::get_type_name, "None");
	cls_TColgp_HArray1OfLin2d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HArray1OfLin2d::get_type_descriptor, "None");
	cls_TColgp_HArray1OfLin2d.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HArray1OfLin2d::*)() const ) &TColgp_HArray1OfLin2d::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_HSequenceOfVec.hxx
	py::class_<TColgp_HSequenceOfVec, opencascade::handle<TColgp_HSequenceOfVec>, TColgp_SequenceOfVec, Standard_Transient> cls_TColgp_HSequenceOfVec(mod, "TColgp_HSequenceOfVec", "None");
	cls_TColgp_HSequenceOfVec.def(py::init<>());
	cls_TColgp_HSequenceOfVec.def(py::init<const TColgp_SequenceOfVec &>(), py::arg("theOther"));
	cls_TColgp_HSequenceOfVec.def("Sequence", (const TColgp_SequenceOfVec & (TColgp_HSequenceOfVec::*)() const ) &TColgp_HSequenceOfVec::Sequence, "None");
	cls_TColgp_HSequenceOfVec.def("Append", (void (TColgp_HSequenceOfVec::*)(const TColgp_SequenceOfVec::value_type &)) &TColgp_HSequenceOfVec::Append, "None", py::arg("theItem"));
	cls_TColgp_HSequenceOfVec.def("Append", (void (TColgp_HSequenceOfVec::*)(TColgp_SequenceOfVec &)) &TColgp_HSequenceOfVec::Append, "None", py::arg("theSequence"));
	cls_TColgp_HSequenceOfVec.def("ChangeSequence", (TColgp_SequenceOfVec & (TColgp_HSequenceOfVec::*)()) &TColgp_HSequenceOfVec::ChangeSequence, "None");
	cls_TColgp_HSequenceOfVec.def_static("get_type_name_", (const char * (*)()) &TColgp_HSequenceOfVec::get_type_name, "None");
	cls_TColgp_HSequenceOfVec.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HSequenceOfVec::get_type_descriptor, "None");
	cls_TColgp_HSequenceOfVec.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HSequenceOfVec::*)() const ) &TColgp_HSequenceOfVec::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_HArray1OfDir2d.hxx
	py::class_<TColgp_HArray1OfDir2d, opencascade::handle<TColgp_HArray1OfDir2d>, TColgp_Array1OfDir2d, Standard_Transient> cls_TColgp_HArray1OfDir2d(mod, "TColgp_HArray1OfDir2d", "None");
	cls_TColgp_HArray1OfDir2d.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColgp_HArray1OfDir2d.def(py::init<const Standard_Integer, const Standard_Integer, const TColgp_Array1OfDir2d::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_TColgp_HArray1OfDir2d.def(py::init<const TColgp_Array1OfDir2d &>(), py::arg("theOther"));
	cls_TColgp_HArray1OfDir2d.def("Array1", (const TColgp_Array1OfDir2d & (TColgp_HArray1OfDir2d::*)() const ) &TColgp_HArray1OfDir2d::Array1, "None");
	cls_TColgp_HArray1OfDir2d.def("ChangeArray1", (TColgp_Array1OfDir2d & (TColgp_HArray1OfDir2d::*)()) &TColgp_HArray1OfDir2d::ChangeArray1, "None");
	cls_TColgp_HArray1OfDir2d.def_static("get_type_name_", (const char * (*)()) &TColgp_HArray1OfDir2d::get_type_name, "None");
	cls_TColgp_HArray1OfDir2d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HArray1OfDir2d::get_type_descriptor, "None");
	cls_TColgp_HArray1OfDir2d.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HArray1OfDir2d::*)() const ) &TColgp_HArray1OfDir2d::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_HArray2OfDir.hxx
	py::class_<TColgp_HArray2OfDir, opencascade::handle<TColgp_HArray2OfDir>, TColgp_Array2OfDir, Standard_Transient> cls_TColgp_HArray2OfDir(mod, "TColgp_HArray2OfDir", "None");
	cls_TColgp_HArray2OfDir.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"));
	cls_TColgp_HArray2OfDir.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const TColgp_Array2OfDir::value_type &>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"), py::arg("theValue"));
	cls_TColgp_HArray2OfDir.def(py::init<const TColgp_Array2OfDir &>(), py::arg("theOther"));
	cls_TColgp_HArray2OfDir.def("Array2", (const TColgp_Array2OfDir & (TColgp_HArray2OfDir::*)() const ) &TColgp_HArray2OfDir::Array2, "None");
	cls_TColgp_HArray2OfDir.def("ChangeArray2", (TColgp_Array2OfDir & (TColgp_HArray2OfDir::*)()) &TColgp_HArray2OfDir::ChangeArray2, "None");
	cls_TColgp_HArray2OfDir.def_static("get_type_name_", (const char * (*)()) &TColgp_HArray2OfDir::get_type_name, "None");
	cls_TColgp_HArray2OfDir.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HArray2OfDir::get_type_descriptor, "None");
	cls_TColgp_HArray2OfDir.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HArray2OfDir::*)() const ) &TColgp_HArray2OfDir::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_HArray2OfXY.hxx
	py::class_<TColgp_HArray2OfXY, opencascade::handle<TColgp_HArray2OfXY>, TColgp_Array2OfXY, Standard_Transient> cls_TColgp_HArray2OfXY(mod, "TColgp_HArray2OfXY", "None");
	cls_TColgp_HArray2OfXY.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"));
	cls_TColgp_HArray2OfXY.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const TColgp_Array2OfXY::value_type &>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"), py::arg("theValue"));
	cls_TColgp_HArray2OfXY.def(py::init<const TColgp_Array2OfXY &>(), py::arg("theOther"));
	cls_TColgp_HArray2OfXY.def("Array2", (const TColgp_Array2OfXY & (TColgp_HArray2OfXY::*)() const ) &TColgp_HArray2OfXY::Array2, "None");
	cls_TColgp_HArray2OfXY.def("ChangeArray2", (TColgp_Array2OfXY & (TColgp_HArray2OfXY::*)()) &TColgp_HArray2OfXY::ChangeArray2, "None");
	cls_TColgp_HArray2OfXY.def_static("get_type_name_", (const char * (*)()) &TColgp_HArray2OfXY::get_type_name, "None");
	cls_TColgp_HArray2OfXY.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HArray2OfXY::get_type_descriptor, "None");
	cls_TColgp_HArray2OfXY.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HArray2OfXY::*)() const ) &TColgp_HArray2OfXY::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_HArray2OfDir2d.hxx
	py::class_<TColgp_HArray2OfDir2d, opencascade::handle<TColgp_HArray2OfDir2d>, TColgp_Array2OfDir2d, Standard_Transient> cls_TColgp_HArray2OfDir2d(mod, "TColgp_HArray2OfDir2d", "None");
	cls_TColgp_HArray2OfDir2d.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"));
	cls_TColgp_HArray2OfDir2d.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const TColgp_Array2OfDir2d::value_type &>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"), py::arg("theValue"));
	cls_TColgp_HArray2OfDir2d.def(py::init<const TColgp_Array2OfDir2d &>(), py::arg("theOther"));
	cls_TColgp_HArray2OfDir2d.def("Array2", (const TColgp_Array2OfDir2d & (TColgp_HArray2OfDir2d::*)() const ) &TColgp_HArray2OfDir2d::Array2, "None");
	cls_TColgp_HArray2OfDir2d.def("ChangeArray2", (TColgp_Array2OfDir2d & (TColgp_HArray2OfDir2d::*)()) &TColgp_HArray2OfDir2d::ChangeArray2, "None");
	cls_TColgp_HArray2OfDir2d.def_static("get_type_name_", (const char * (*)()) &TColgp_HArray2OfDir2d::get_type_name, "None");
	cls_TColgp_HArray2OfDir2d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HArray2OfDir2d::get_type_descriptor, "None");
	cls_TColgp_HArray2OfDir2d.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HArray2OfDir2d::*)() const ) &TColgp_HArray2OfDir2d::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_HArray2OfVec2d.hxx
	py::class_<TColgp_HArray2OfVec2d, opencascade::handle<TColgp_HArray2OfVec2d>, TColgp_Array2OfVec2d, Standard_Transient> cls_TColgp_HArray2OfVec2d(mod, "TColgp_HArray2OfVec2d", "None");
	cls_TColgp_HArray2OfVec2d.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"));
	cls_TColgp_HArray2OfVec2d.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const TColgp_Array2OfVec2d::value_type &>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"), py::arg("theValue"));
	cls_TColgp_HArray2OfVec2d.def(py::init<const TColgp_Array2OfVec2d &>(), py::arg("theOther"));
	cls_TColgp_HArray2OfVec2d.def("Array2", (const TColgp_Array2OfVec2d & (TColgp_HArray2OfVec2d::*)() const ) &TColgp_HArray2OfVec2d::Array2, "None");
	cls_TColgp_HArray2OfVec2d.def("ChangeArray2", (TColgp_Array2OfVec2d & (TColgp_HArray2OfVec2d::*)()) &TColgp_HArray2OfVec2d::ChangeArray2, "None");
	cls_TColgp_HArray2OfVec2d.def_static("get_type_name_", (const char * (*)()) &TColgp_HArray2OfVec2d::get_type_name, "None");
	cls_TColgp_HArray2OfVec2d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HArray2OfVec2d::get_type_descriptor, "None");
	cls_TColgp_HArray2OfVec2d.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HArray2OfVec2d::*)() const ) &TColgp_HArray2OfVec2d::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_HArray2OfLin2d.hxx
	py::class_<TColgp_HArray2OfLin2d, opencascade::handle<TColgp_HArray2OfLin2d>, TColgp_Array2OfLin2d, Standard_Transient> cls_TColgp_HArray2OfLin2d(mod, "TColgp_HArray2OfLin2d", "None");
	cls_TColgp_HArray2OfLin2d.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"));
	cls_TColgp_HArray2OfLin2d.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const TColgp_Array2OfLin2d::value_type &>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"), py::arg("theValue"));
	cls_TColgp_HArray2OfLin2d.def(py::init<const TColgp_Array2OfLin2d &>(), py::arg("theOther"));
	cls_TColgp_HArray2OfLin2d.def("Array2", (const TColgp_Array2OfLin2d & (TColgp_HArray2OfLin2d::*)() const ) &TColgp_HArray2OfLin2d::Array2, "None");
	cls_TColgp_HArray2OfLin2d.def("ChangeArray2", (TColgp_Array2OfLin2d & (TColgp_HArray2OfLin2d::*)()) &TColgp_HArray2OfLin2d::ChangeArray2, "None");
	cls_TColgp_HArray2OfLin2d.def_static("get_type_name_", (const char * (*)()) &TColgp_HArray2OfLin2d::get_type_name, "None");
	cls_TColgp_HArray2OfLin2d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HArray2OfLin2d::get_type_descriptor, "None");
	cls_TColgp_HArray2OfLin2d.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HArray2OfLin2d::*)() const ) &TColgp_HArray2OfLin2d::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_HArray2OfCirc2d.hxx
	py::class_<TColgp_HArray2OfCirc2d, opencascade::handle<TColgp_HArray2OfCirc2d>, TColgp_Array2OfCirc2d, Standard_Transient> cls_TColgp_HArray2OfCirc2d(mod, "TColgp_HArray2OfCirc2d", "None");
	cls_TColgp_HArray2OfCirc2d.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"));
	cls_TColgp_HArray2OfCirc2d.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const TColgp_Array2OfCirc2d::value_type &>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"), py::arg("theValue"));
	cls_TColgp_HArray2OfCirc2d.def(py::init<const TColgp_Array2OfCirc2d &>(), py::arg("theOther"));
	cls_TColgp_HArray2OfCirc2d.def("Array2", (const TColgp_Array2OfCirc2d & (TColgp_HArray2OfCirc2d::*)() const ) &TColgp_HArray2OfCirc2d::Array2, "None");
	cls_TColgp_HArray2OfCirc2d.def("ChangeArray2", (TColgp_Array2OfCirc2d & (TColgp_HArray2OfCirc2d::*)()) &TColgp_HArray2OfCirc2d::ChangeArray2, "None");
	cls_TColgp_HArray2OfCirc2d.def_static("get_type_name_", (const char * (*)()) &TColgp_HArray2OfCirc2d::get_type_name, "None");
	cls_TColgp_HArray2OfCirc2d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HArray2OfCirc2d::get_type_descriptor, "None");
	cls_TColgp_HArray2OfCirc2d.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HArray2OfCirc2d::*)() const ) &TColgp_HArray2OfCirc2d::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_HSequenceOfDir.hxx
	py::class_<TColgp_HSequenceOfDir, opencascade::handle<TColgp_HSequenceOfDir>, TColgp_SequenceOfDir, Standard_Transient> cls_TColgp_HSequenceOfDir(mod, "TColgp_HSequenceOfDir", "None");
	cls_TColgp_HSequenceOfDir.def(py::init<>());
	cls_TColgp_HSequenceOfDir.def(py::init<const TColgp_SequenceOfDir &>(), py::arg("theOther"));
	cls_TColgp_HSequenceOfDir.def("Sequence", (const TColgp_SequenceOfDir & (TColgp_HSequenceOfDir::*)() const ) &TColgp_HSequenceOfDir::Sequence, "None");
	cls_TColgp_HSequenceOfDir.def("Append", (void (TColgp_HSequenceOfDir::*)(const TColgp_SequenceOfDir::value_type &)) &TColgp_HSequenceOfDir::Append, "None", py::arg("theItem"));
	cls_TColgp_HSequenceOfDir.def("Append", (void (TColgp_HSequenceOfDir::*)(TColgp_SequenceOfDir &)) &TColgp_HSequenceOfDir::Append, "None", py::arg("theSequence"));
	cls_TColgp_HSequenceOfDir.def("ChangeSequence", (TColgp_SequenceOfDir & (TColgp_HSequenceOfDir::*)()) &TColgp_HSequenceOfDir::ChangeSequence, "None");
	cls_TColgp_HSequenceOfDir.def_static("get_type_name_", (const char * (*)()) &TColgp_HSequenceOfDir::get_type_name, "None");
	cls_TColgp_HSequenceOfDir.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HSequenceOfDir::get_type_descriptor, "None");
	cls_TColgp_HSequenceOfDir.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HSequenceOfDir::*)() const ) &TColgp_HSequenceOfDir::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_HSequenceOfDir2d.hxx
	py::class_<TColgp_HSequenceOfDir2d, opencascade::handle<TColgp_HSequenceOfDir2d>, TColgp_SequenceOfDir2d, Standard_Transient> cls_TColgp_HSequenceOfDir2d(mod, "TColgp_HSequenceOfDir2d", "None");
	cls_TColgp_HSequenceOfDir2d.def(py::init<>());
	cls_TColgp_HSequenceOfDir2d.def(py::init<const TColgp_SequenceOfDir2d &>(), py::arg("theOther"));
	cls_TColgp_HSequenceOfDir2d.def("Sequence", (const TColgp_SequenceOfDir2d & (TColgp_HSequenceOfDir2d::*)() const ) &TColgp_HSequenceOfDir2d::Sequence, "None");
	cls_TColgp_HSequenceOfDir2d.def("Append", (void (TColgp_HSequenceOfDir2d::*)(const TColgp_SequenceOfDir2d::value_type &)) &TColgp_HSequenceOfDir2d::Append, "None", py::arg("theItem"));
	cls_TColgp_HSequenceOfDir2d.def("Append", (void (TColgp_HSequenceOfDir2d::*)(TColgp_SequenceOfDir2d &)) &TColgp_HSequenceOfDir2d::Append, "None", py::arg("theSequence"));
	cls_TColgp_HSequenceOfDir2d.def("ChangeSequence", (TColgp_SequenceOfDir2d & (TColgp_HSequenceOfDir2d::*)()) &TColgp_HSequenceOfDir2d::ChangeSequence, "None");
	cls_TColgp_HSequenceOfDir2d.def_static("get_type_name_", (const char * (*)()) &TColgp_HSequenceOfDir2d::get_type_name, "None");
	cls_TColgp_HSequenceOfDir2d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HSequenceOfDir2d::get_type_descriptor, "None");
	cls_TColgp_HSequenceOfDir2d.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HSequenceOfDir2d::*)() const ) &TColgp_HSequenceOfDir2d::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_HSequenceOfVec2d.hxx
	py::class_<TColgp_HSequenceOfVec2d, opencascade::handle<TColgp_HSequenceOfVec2d>, TColgp_SequenceOfVec2d, Standard_Transient> cls_TColgp_HSequenceOfVec2d(mod, "TColgp_HSequenceOfVec2d", "None");
	cls_TColgp_HSequenceOfVec2d.def(py::init<>());
	cls_TColgp_HSequenceOfVec2d.def(py::init<const TColgp_SequenceOfVec2d &>(), py::arg("theOther"));
	cls_TColgp_HSequenceOfVec2d.def("Sequence", (const TColgp_SequenceOfVec2d & (TColgp_HSequenceOfVec2d::*)() const ) &TColgp_HSequenceOfVec2d::Sequence, "None");
	cls_TColgp_HSequenceOfVec2d.def("Append", (void (TColgp_HSequenceOfVec2d::*)(const TColgp_SequenceOfVec2d::value_type &)) &TColgp_HSequenceOfVec2d::Append, "None", py::arg("theItem"));
	cls_TColgp_HSequenceOfVec2d.def("Append", (void (TColgp_HSequenceOfVec2d::*)(TColgp_SequenceOfVec2d &)) &TColgp_HSequenceOfVec2d::Append, "None", py::arg("theSequence"));
	cls_TColgp_HSequenceOfVec2d.def("ChangeSequence", (TColgp_SequenceOfVec2d & (TColgp_HSequenceOfVec2d::*)()) &TColgp_HSequenceOfVec2d::ChangeSequence, "None");
	cls_TColgp_HSequenceOfVec2d.def_static("get_type_name_", (const char * (*)()) &TColgp_HSequenceOfVec2d::get_type_name, "None");
	cls_TColgp_HSequenceOfVec2d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HSequenceOfVec2d::get_type_descriptor, "None");
	cls_TColgp_HSequenceOfVec2d.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HSequenceOfVec2d::*)() const ) &TColgp_HSequenceOfVec2d::DynamicType, "None");


}
