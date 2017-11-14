#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <Hatch_LineForm.hxx>
#include <gp_Lin2d.hxx>
#include <Standard_TypeDef.hxx>
#include <Hatch_Line.hxx>
#include <gp_Dir2d.hxx>
#include <gp_Pnt2d.hxx>
#include <Hatch_Hatcher.hxx>
#include <Hatch_Parameter.hxx>
#include <NCollection_BaseSequence.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_Sequence.hxx>
#include <Hatch_SequenceOfParameter.hxx>
#include <Hatch_SequenceOfLine.hxx>

PYBIND11_MODULE(Hatch, mod) {

	// IMPORT
	py::module::import("OCCT.gp");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.NCollection");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\Hatch_LineForm.hxx
	py::enum_<Hatch_LineForm>(mod, "Hatch_LineForm", "Form of a trimmed line")
		.value("Hatch_XLINE", Hatch_LineForm::Hatch_XLINE)
		.value("Hatch_YLINE", Hatch_LineForm::Hatch_YLINE)
		.value("Hatch_ANYLINE", Hatch_LineForm::Hatch_ANYLINE)
		.export_values();

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\Hatch_Line.hxx
	py::class_<Hatch_Line, std::unique_ptr<Hatch_Line, Deleter<Hatch_Line>>> cls_Hatch_Line(mod, "Hatch_Line", "Stores a Line in the Hatcher. Represented by :");
	cls_Hatch_Line.def(py::init<>());
	cls_Hatch_Line.def(py::init<const gp_Lin2d &, const Hatch_LineForm>(), py::arg("L"), py::arg("T"));
	cls_Hatch_Line.def("AddIntersection", (void (Hatch_Line::*)(const Standard_Real, const Standard_Boolean, const Standard_Integer, const Standard_Real, const Standard_Real)) &Hatch_Line::AddIntersection, "Insert a new intersection in the sorted list.", py::arg("Par1"), py::arg("Start"), py::arg("Index"), py::arg("Par2"), py::arg("theToler"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Hatch_Hatcher.hxx
	py::class_<Hatch_Hatcher, std::unique_ptr<Hatch_Hatcher, Deleter<Hatch_Hatcher>>> cls_Hatch_Hatcher(mod, "Hatch_Hatcher", "The Hatcher is an algorithm to compute cross hatchings in a 2d plane. It is mainly dedicated to display purpose.");
	cls_Hatch_Hatcher.def(py::init<const Standard_Real>(), py::arg("Tol"));
	cls_Hatch_Hatcher.def(py::init<const Standard_Real, const Standard_Boolean>(), py::arg("Tol"), py::arg("Oriented"));
	cls_Hatch_Hatcher.def("Tolerance", (void (Hatch_Hatcher::*)(const Standard_Real)) &Hatch_Hatcher::Tolerance, "None", py::arg("Tol"));
	cls_Hatch_Hatcher.def("Tolerance", (Standard_Real (Hatch_Hatcher::*)() const ) &Hatch_Hatcher::Tolerance, "None");
	cls_Hatch_Hatcher.def("AddLine", [](Hatch_Hatcher &self, const gp_Lin2d & a0) -> void { return self.AddLine(a0); }, py::arg("L"));
	cls_Hatch_Hatcher.def("AddLine", (void (Hatch_Hatcher::*)(const gp_Lin2d &, const Hatch_LineForm)) &Hatch_Hatcher::AddLine, "Add a line <L> to be trimmed. <T> the type is only kept from information. It is not used in the computation.", py::arg("L"), py::arg("T"));
	cls_Hatch_Hatcher.def("AddLine", (void (Hatch_Hatcher::*)(const gp_Dir2d &, const Standard_Real)) &Hatch_Hatcher::AddLine, "Add an infinite line on direction <D> at distance <Dist> from the origin to be trimmed. <Dist> may be negative.", py::arg("D"), py::arg("Dist"));
	cls_Hatch_Hatcher.def("AddXLine", (void (Hatch_Hatcher::*)(const Standard_Real)) &Hatch_Hatcher::AddXLine, "Add an infinite line parallel to the Y-axis at abciss <X>.", py::arg("X"));
	cls_Hatch_Hatcher.def("AddYLine", (void (Hatch_Hatcher::*)(const Standard_Real)) &Hatch_Hatcher::AddYLine, "Add an infinite line parallel to the X-axis at ordinate <Y>.", py::arg("Y"));
	cls_Hatch_Hatcher.def("Trim", [](Hatch_Hatcher &self, const gp_Lin2d & a0) -> void { return self.Trim(a0); }, py::arg("L"));
	cls_Hatch_Hatcher.def("Trim", (void (Hatch_Hatcher::*)(const gp_Lin2d &, const Standard_Integer)) &Hatch_Hatcher::Trim, "Trims the lines at intersections with <L>.", py::arg("L"), py::arg("Index"));
	cls_Hatch_Hatcher.def("Trim", [](Hatch_Hatcher &self, const gp_Lin2d & a0, const Standard_Real a1, const Standard_Real a2) -> void { return self.Trim(a0, a1, a2); }, py::arg("L"), py::arg("Start"), py::arg("End"));
	cls_Hatch_Hatcher.def("Trim", (void (Hatch_Hatcher::*)(const gp_Lin2d &, const Standard_Real, const Standard_Real, const Standard_Integer)) &Hatch_Hatcher::Trim, "Trims the lines at intersections with <L> in the parameter range <Start>, <End>", py::arg("L"), py::arg("Start"), py::arg("End"), py::arg("Index"));
	cls_Hatch_Hatcher.def("Trim", [](Hatch_Hatcher &self, const gp_Pnt2d & a0, const gp_Pnt2d & a1) -> void { return self.Trim(a0, a1); }, py::arg("P1"), py::arg("P2"));
	cls_Hatch_Hatcher.def("Trim", (void (Hatch_Hatcher::*)(const gp_Pnt2d &, const gp_Pnt2d &, const Standard_Integer)) &Hatch_Hatcher::Trim, "Trims the line at intersection with the oriented segment P1,P2.", py::arg("P1"), py::arg("P2"), py::arg("Index"));
	cls_Hatch_Hatcher.def("NbIntervals", (Standard_Integer (Hatch_Hatcher::*)() const ) &Hatch_Hatcher::NbIntervals, "Returns the total number of intervals on all the lines.");
	cls_Hatch_Hatcher.def("NbLines", (Standard_Integer (Hatch_Hatcher::*)() const ) &Hatch_Hatcher::NbLines, "Returns the number of lines.");
	cls_Hatch_Hatcher.def("Line", (const gp_Lin2d & (Hatch_Hatcher::*)(const Standard_Integer) const ) &Hatch_Hatcher::Line, "Returns the line of index <I>.", py::arg("I"));
	cls_Hatch_Hatcher.def("LineForm", (Hatch_LineForm (Hatch_Hatcher::*)(const Standard_Integer) const ) &Hatch_Hatcher::LineForm, "Returns the type of the line of index <I>.", py::arg("I"));
	cls_Hatch_Hatcher.def("IsXLine", (Standard_Boolean (Hatch_Hatcher::*)(const Standard_Integer) const ) &Hatch_Hatcher::IsXLine, "Returns True if the line of index <I> has a constant X value.", py::arg("I"));
	cls_Hatch_Hatcher.def("IsYLine", (Standard_Boolean (Hatch_Hatcher::*)(const Standard_Integer) const ) &Hatch_Hatcher::IsYLine, "Returns True if the line of index <I> has a constant Y value.", py::arg("I"));
	cls_Hatch_Hatcher.def("Coordinate", (Standard_Real (Hatch_Hatcher::*)(const Standard_Integer) const ) &Hatch_Hatcher::Coordinate, "Returns the X or Y coordinate of the line of index <I> if it is a X or a Y line.", py::arg("I"));
	cls_Hatch_Hatcher.def("NbIntervals", (Standard_Integer (Hatch_Hatcher::*)(const Standard_Integer) const ) &Hatch_Hatcher::NbIntervals, "Returns the number of intervals on line of index <I>.", py::arg("I"));
	cls_Hatch_Hatcher.def("Start", (Standard_Real (Hatch_Hatcher::*)(const Standard_Integer, const Standard_Integer) const ) &Hatch_Hatcher::Start, "Returns the first parameter of interval <J> on line <I>.", py::arg("I"), py::arg("J"));
	cls_Hatch_Hatcher.def("StartIndex", (void (Hatch_Hatcher::*)(const Standard_Integer, const Standard_Integer, Standard_Integer &, Standard_Real &) const ) &Hatch_Hatcher::StartIndex, "Returns the first Index and Par2 of interval <J> on line <I>.", py::arg("I"), py::arg("J"), py::arg("Index"), py::arg("Par2"));
	cls_Hatch_Hatcher.def("End", (Standard_Real (Hatch_Hatcher::*)(const Standard_Integer, const Standard_Integer) const ) &Hatch_Hatcher::End, "Returns the last parameter of interval <J> on line <I>.", py::arg("I"), py::arg("J"));
	cls_Hatch_Hatcher.def("EndIndex", (void (Hatch_Hatcher::*)(const Standard_Integer, const Standard_Integer, Standard_Integer &, Standard_Real &) const ) &Hatch_Hatcher::EndIndex, "Returns the last Index and Par2 of interval <J> on line <I>.", py::arg("I"), py::arg("J"), py::arg("Index"), py::arg("Par2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Hatch_Parameter.hxx
	py::class_<Hatch_Parameter, std::unique_ptr<Hatch_Parameter, Deleter<Hatch_Parameter>>> cls_Hatch_Parameter(mod, "Hatch_Parameter", "Stores an intersection on a line represented by :");
	cls_Hatch_Parameter.def(py::init<>());
	cls_Hatch_Parameter.def(py::init<const Standard_Real, const Standard_Boolean>(), py::arg("Par1"), py::arg("Start"));
	cls_Hatch_Parameter.def(py::init<const Standard_Real, const Standard_Boolean, const Standard_Integer>(), py::arg("Par1"), py::arg("Start"), py::arg("Index"));
	cls_Hatch_Parameter.def(py::init<const Standard_Real, const Standard_Boolean, const Standard_Integer, const Standard_Real>(), py::arg("Par1"), py::arg("Start"), py::arg("Index"), py::arg("Par2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<Hatch_SequenceOfParameter, std::unique_ptr<Hatch_SequenceOfParameter, Deleter<Hatch_SequenceOfParameter>>, NCollection_BaseSequence> cls_Hatch_SequenceOfParameter(mod, "Hatch_SequenceOfParameter", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_Hatch_SequenceOfParameter.def(py::init<>());
	cls_Hatch_SequenceOfParameter.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_Hatch_SequenceOfParameter.def(py::init([] (const Hatch_SequenceOfParameter &other) {return new Hatch_SequenceOfParameter(other);}), "Copy constructor", py::arg("other"));
	cls_Hatch_SequenceOfParameter.def("begin", (Hatch_SequenceOfParameter::iterator (Hatch_SequenceOfParameter::*)() const ) &Hatch_SequenceOfParameter::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_Hatch_SequenceOfParameter.def("end", (Hatch_SequenceOfParameter::iterator (Hatch_SequenceOfParameter::*)() const ) &Hatch_SequenceOfParameter::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_Hatch_SequenceOfParameter.def("cbegin", (Hatch_SequenceOfParameter::const_iterator (Hatch_SequenceOfParameter::*)() const ) &Hatch_SequenceOfParameter::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_Hatch_SequenceOfParameter.def("cend", (Hatch_SequenceOfParameter::const_iterator (Hatch_SequenceOfParameter::*)() const ) &Hatch_SequenceOfParameter::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_Hatch_SequenceOfParameter.def("Size", (Standard_Integer (Hatch_SequenceOfParameter::*)() const ) &Hatch_SequenceOfParameter::Size, "Number of items");
	cls_Hatch_SequenceOfParameter.def("Length", (Standard_Integer (Hatch_SequenceOfParameter::*)() const ) &Hatch_SequenceOfParameter::Length, "Number of items");
	cls_Hatch_SequenceOfParameter.def("Lower", (Standard_Integer (Hatch_SequenceOfParameter::*)() const ) &Hatch_SequenceOfParameter::Lower, "Method for consistency with other collections.");
	cls_Hatch_SequenceOfParameter.def("Upper", (Standard_Integer (Hatch_SequenceOfParameter::*)() const ) &Hatch_SequenceOfParameter::Upper, "Method for consistency with other collections.");
	cls_Hatch_SequenceOfParameter.def("IsEmpty", (Standard_Boolean (Hatch_SequenceOfParameter::*)() const ) &Hatch_SequenceOfParameter::IsEmpty, "Empty query");
	cls_Hatch_SequenceOfParameter.def("Reverse", (void (Hatch_SequenceOfParameter::*)()) &Hatch_SequenceOfParameter::Reverse, "Reverse sequence");
	cls_Hatch_SequenceOfParameter.def("Exchange", (void (Hatch_SequenceOfParameter::*)(const Standard_Integer, const Standard_Integer)) &Hatch_SequenceOfParameter::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_Hatch_SequenceOfParameter.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &Hatch_SequenceOfParameter::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_Hatch_SequenceOfParameter.def("Clear", [](Hatch_SequenceOfParameter &self) -> void { return self.Clear(); });
	cls_Hatch_SequenceOfParameter.def("Clear", (void (Hatch_SequenceOfParameter::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &Hatch_SequenceOfParameter::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_Hatch_SequenceOfParameter.def("Assign", (Hatch_SequenceOfParameter & (Hatch_SequenceOfParameter::*)(const Hatch_SequenceOfParameter &)) &Hatch_SequenceOfParameter::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_Hatch_SequenceOfParameter.def("assign", (Hatch_SequenceOfParameter & (Hatch_SequenceOfParameter::*)(const Hatch_SequenceOfParameter &)) &Hatch_SequenceOfParameter::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_Hatch_SequenceOfParameter.def("Remove", (void (Hatch_SequenceOfParameter::*)(Hatch_SequenceOfParameter::Iterator &)) &Hatch_SequenceOfParameter::Remove, "Remove one item", py::arg("thePosition"));
	cls_Hatch_SequenceOfParameter.def("Remove", (void (Hatch_SequenceOfParameter::*)(const Standard_Integer)) &Hatch_SequenceOfParameter::Remove, "Remove one item", py::arg("theIndex"));
	cls_Hatch_SequenceOfParameter.def("Remove", (void (Hatch_SequenceOfParameter::*)(const Standard_Integer, const Standard_Integer)) &Hatch_SequenceOfParameter::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_Hatch_SequenceOfParameter.def("Append", (void (Hatch_SequenceOfParameter::*)(const Hatch_Parameter &)) &Hatch_SequenceOfParameter::Append, "Append one item", py::arg("theItem"));
	cls_Hatch_SequenceOfParameter.def("Append", (void (Hatch_SequenceOfParameter::*)(Hatch_SequenceOfParameter &)) &Hatch_SequenceOfParameter::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_Hatch_SequenceOfParameter.def("Prepend", (void (Hatch_SequenceOfParameter::*)(const Hatch_Parameter &)) &Hatch_SequenceOfParameter::Prepend, "Prepend one item", py::arg("theItem"));
	cls_Hatch_SequenceOfParameter.def("Prepend", (void (Hatch_SequenceOfParameter::*)(Hatch_SequenceOfParameter &)) &Hatch_SequenceOfParameter::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_Hatch_SequenceOfParameter.def("InsertBefore", (void (Hatch_SequenceOfParameter::*)(const Standard_Integer, const Hatch_Parameter &)) &Hatch_SequenceOfParameter::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_Hatch_SequenceOfParameter.def("InsertBefore", (void (Hatch_SequenceOfParameter::*)(const Standard_Integer, Hatch_SequenceOfParameter &)) &Hatch_SequenceOfParameter::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_Hatch_SequenceOfParameter.def("InsertAfter", (void (Hatch_SequenceOfParameter::*)(Hatch_SequenceOfParameter::Iterator &, const Hatch_Parameter &)) &Hatch_SequenceOfParameter::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_Hatch_SequenceOfParameter.def("InsertAfter", (void (Hatch_SequenceOfParameter::*)(const Standard_Integer, Hatch_SequenceOfParameter &)) &Hatch_SequenceOfParameter::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_Hatch_SequenceOfParameter.def("InsertAfter", (void (Hatch_SequenceOfParameter::*)(const Standard_Integer, const Hatch_Parameter &)) &Hatch_SequenceOfParameter::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_Hatch_SequenceOfParameter.def("Split", (void (Hatch_SequenceOfParameter::*)(const Standard_Integer, Hatch_SequenceOfParameter &)) &Hatch_SequenceOfParameter::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_Hatch_SequenceOfParameter.def("First", (const Hatch_Parameter & (Hatch_SequenceOfParameter::*)() const ) &Hatch_SequenceOfParameter::First, "First item access");
	cls_Hatch_SequenceOfParameter.def("ChangeFirst", (Hatch_Parameter & (Hatch_SequenceOfParameter::*)()) &Hatch_SequenceOfParameter::ChangeFirst, "First item access");
	cls_Hatch_SequenceOfParameter.def("Last", (const Hatch_Parameter & (Hatch_SequenceOfParameter::*)() const ) &Hatch_SequenceOfParameter::Last, "Last item access");
	cls_Hatch_SequenceOfParameter.def("ChangeLast", (Hatch_Parameter & (Hatch_SequenceOfParameter::*)()) &Hatch_SequenceOfParameter::ChangeLast, "Last item access");
	cls_Hatch_SequenceOfParameter.def("Value", (const Hatch_Parameter & (Hatch_SequenceOfParameter::*)(const Standard_Integer) const ) &Hatch_SequenceOfParameter::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_Hatch_SequenceOfParameter.def("__call__", (const Hatch_Parameter & (Hatch_SequenceOfParameter::*)(const Standard_Integer) const ) &Hatch_SequenceOfParameter::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_Hatch_SequenceOfParameter.def("ChangeValue", (Hatch_Parameter & (Hatch_SequenceOfParameter::*)(const Standard_Integer)) &Hatch_SequenceOfParameter::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_Hatch_SequenceOfParameter.def("__call__", (Hatch_Parameter & (Hatch_SequenceOfParameter::*)(const Standard_Integer)) &Hatch_SequenceOfParameter::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_Hatch_SequenceOfParameter.def("SetValue", (void (Hatch_SequenceOfParameter::*)(const Standard_Integer, const Hatch_Parameter &)) &Hatch_SequenceOfParameter::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_Hatch_SequenceOfParameter.def("__iter__", [](const Hatch_SequenceOfParameter &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<Hatch_SequenceOfLine, std::unique_ptr<Hatch_SequenceOfLine, Deleter<Hatch_SequenceOfLine>>, NCollection_BaseSequence> cls_Hatch_SequenceOfLine(mod, "Hatch_SequenceOfLine", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_Hatch_SequenceOfLine.def(py::init<>());
	cls_Hatch_SequenceOfLine.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_Hatch_SequenceOfLine.def(py::init([] (const Hatch_SequenceOfLine &other) {return new Hatch_SequenceOfLine(other);}), "Copy constructor", py::arg("other"));
	cls_Hatch_SequenceOfLine.def("begin", (Hatch_SequenceOfLine::iterator (Hatch_SequenceOfLine::*)() const ) &Hatch_SequenceOfLine::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_Hatch_SequenceOfLine.def("end", (Hatch_SequenceOfLine::iterator (Hatch_SequenceOfLine::*)() const ) &Hatch_SequenceOfLine::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_Hatch_SequenceOfLine.def("cbegin", (Hatch_SequenceOfLine::const_iterator (Hatch_SequenceOfLine::*)() const ) &Hatch_SequenceOfLine::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_Hatch_SequenceOfLine.def("cend", (Hatch_SequenceOfLine::const_iterator (Hatch_SequenceOfLine::*)() const ) &Hatch_SequenceOfLine::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_Hatch_SequenceOfLine.def("Size", (Standard_Integer (Hatch_SequenceOfLine::*)() const ) &Hatch_SequenceOfLine::Size, "Number of items");
	cls_Hatch_SequenceOfLine.def("Length", (Standard_Integer (Hatch_SequenceOfLine::*)() const ) &Hatch_SequenceOfLine::Length, "Number of items");
	cls_Hatch_SequenceOfLine.def("Lower", (Standard_Integer (Hatch_SequenceOfLine::*)() const ) &Hatch_SequenceOfLine::Lower, "Method for consistency with other collections.");
	cls_Hatch_SequenceOfLine.def("Upper", (Standard_Integer (Hatch_SequenceOfLine::*)() const ) &Hatch_SequenceOfLine::Upper, "Method for consistency with other collections.");
	cls_Hatch_SequenceOfLine.def("IsEmpty", (Standard_Boolean (Hatch_SequenceOfLine::*)() const ) &Hatch_SequenceOfLine::IsEmpty, "Empty query");
	cls_Hatch_SequenceOfLine.def("Reverse", (void (Hatch_SequenceOfLine::*)()) &Hatch_SequenceOfLine::Reverse, "Reverse sequence");
	cls_Hatch_SequenceOfLine.def("Exchange", (void (Hatch_SequenceOfLine::*)(const Standard_Integer, const Standard_Integer)) &Hatch_SequenceOfLine::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_Hatch_SequenceOfLine.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &Hatch_SequenceOfLine::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_Hatch_SequenceOfLine.def("Clear", [](Hatch_SequenceOfLine &self) -> void { return self.Clear(); });
	cls_Hatch_SequenceOfLine.def("Clear", (void (Hatch_SequenceOfLine::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &Hatch_SequenceOfLine::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_Hatch_SequenceOfLine.def("Assign", (Hatch_SequenceOfLine & (Hatch_SequenceOfLine::*)(const Hatch_SequenceOfLine &)) &Hatch_SequenceOfLine::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_Hatch_SequenceOfLine.def("assign", (Hatch_SequenceOfLine & (Hatch_SequenceOfLine::*)(const Hatch_SequenceOfLine &)) &Hatch_SequenceOfLine::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_Hatch_SequenceOfLine.def("Remove", (void (Hatch_SequenceOfLine::*)(Hatch_SequenceOfLine::Iterator &)) &Hatch_SequenceOfLine::Remove, "Remove one item", py::arg("thePosition"));
	cls_Hatch_SequenceOfLine.def("Remove", (void (Hatch_SequenceOfLine::*)(const Standard_Integer)) &Hatch_SequenceOfLine::Remove, "Remove one item", py::arg("theIndex"));
	cls_Hatch_SequenceOfLine.def("Remove", (void (Hatch_SequenceOfLine::*)(const Standard_Integer, const Standard_Integer)) &Hatch_SequenceOfLine::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_Hatch_SequenceOfLine.def("Append", (void (Hatch_SequenceOfLine::*)(const Hatch_Line &)) &Hatch_SequenceOfLine::Append, "Append one item", py::arg("theItem"));
	cls_Hatch_SequenceOfLine.def("Append", (void (Hatch_SequenceOfLine::*)(Hatch_SequenceOfLine &)) &Hatch_SequenceOfLine::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_Hatch_SequenceOfLine.def("Prepend", (void (Hatch_SequenceOfLine::*)(const Hatch_Line &)) &Hatch_SequenceOfLine::Prepend, "Prepend one item", py::arg("theItem"));
	cls_Hatch_SequenceOfLine.def("Prepend", (void (Hatch_SequenceOfLine::*)(Hatch_SequenceOfLine &)) &Hatch_SequenceOfLine::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_Hatch_SequenceOfLine.def("InsertBefore", (void (Hatch_SequenceOfLine::*)(const Standard_Integer, const Hatch_Line &)) &Hatch_SequenceOfLine::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_Hatch_SequenceOfLine.def("InsertBefore", (void (Hatch_SequenceOfLine::*)(const Standard_Integer, Hatch_SequenceOfLine &)) &Hatch_SequenceOfLine::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_Hatch_SequenceOfLine.def("InsertAfter", (void (Hatch_SequenceOfLine::*)(Hatch_SequenceOfLine::Iterator &, const Hatch_Line &)) &Hatch_SequenceOfLine::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_Hatch_SequenceOfLine.def("InsertAfter", (void (Hatch_SequenceOfLine::*)(const Standard_Integer, Hatch_SequenceOfLine &)) &Hatch_SequenceOfLine::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_Hatch_SequenceOfLine.def("InsertAfter", (void (Hatch_SequenceOfLine::*)(const Standard_Integer, const Hatch_Line &)) &Hatch_SequenceOfLine::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_Hatch_SequenceOfLine.def("Split", (void (Hatch_SequenceOfLine::*)(const Standard_Integer, Hatch_SequenceOfLine &)) &Hatch_SequenceOfLine::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_Hatch_SequenceOfLine.def("First", (const Hatch_Line & (Hatch_SequenceOfLine::*)() const ) &Hatch_SequenceOfLine::First, "First item access");
	cls_Hatch_SequenceOfLine.def("ChangeFirst", (Hatch_Line & (Hatch_SequenceOfLine::*)()) &Hatch_SequenceOfLine::ChangeFirst, "First item access");
	cls_Hatch_SequenceOfLine.def("Last", (const Hatch_Line & (Hatch_SequenceOfLine::*)() const ) &Hatch_SequenceOfLine::Last, "Last item access");
	cls_Hatch_SequenceOfLine.def("ChangeLast", (Hatch_Line & (Hatch_SequenceOfLine::*)()) &Hatch_SequenceOfLine::ChangeLast, "Last item access");
	cls_Hatch_SequenceOfLine.def("Value", (const Hatch_Line & (Hatch_SequenceOfLine::*)(const Standard_Integer) const ) &Hatch_SequenceOfLine::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_Hatch_SequenceOfLine.def("__call__", (const Hatch_Line & (Hatch_SequenceOfLine::*)(const Standard_Integer) const ) &Hatch_SequenceOfLine::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_Hatch_SequenceOfLine.def("ChangeValue", (Hatch_Line & (Hatch_SequenceOfLine::*)(const Standard_Integer)) &Hatch_SequenceOfLine::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_Hatch_SequenceOfLine.def("__call__", (Hatch_Line & (Hatch_SequenceOfLine::*)(const Standard_Integer)) &Hatch_SequenceOfLine::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_Hatch_SequenceOfLine.def("SetValue", (void (Hatch_SequenceOfLine::*)(const Standard_Integer, const Hatch_Line &)) &Hatch_SequenceOfLine::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_Hatch_SequenceOfLine.def("__iter__", [](const Hatch_SequenceOfLine &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());


}
