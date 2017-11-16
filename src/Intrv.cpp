#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <Intrv_Position.hxx>
#include <Standard_TypeDef.hxx>
#include <Intrv_Interval.hxx>
#include <NCollection_BaseSequence.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_Sequence.hxx>
#include <Intrv_SequenceOfInterval.hxx>
#include <Intrv_Intervals.hxx>

PYBIND11_MODULE(Intrv, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.NCollection");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\Intrv_Position.hxx
	py::enum_<Intrv_Position>(mod, "Intrv_Position", "None")
		.value("Intrv_Before", Intrv_Position::Intrv_Before)
		.value("Intrv_JustBefore", Intrv_Position::Intrv_JustBefore)
		.value("Intrv_OverlappingAtStart", Intrv_Position::Intrv_OverlappingAtStart)
		.value("Intrv_JustEnclosingAtEnd", Intrv_Position::Intrv_JustEnclosingAtEnd)
		.value("Intrv_Enclosing", Intrv_Position::Intrv_Enclosing)
		.value("Intrv_JustOverlappingAtStart", Intrv_Position::Intrv_JustOverlappingAtStart)
		.value("Intrv_Similar", Intrv_Position::Intrv_Similar)
		.value("Intrv_JustEnclosingAtStart", Intrv_Position::Intrv_JustEnclosingAtStart)
		.value("Intrv_Inside", Intrv_Position::Intrv_Inside)
		.value("Intrv_JustOverlappingAtEnd", Intrv_Position::Intrv_JustOverlappingAtEnd)
		.value("Intrv_OverlappingAtEnd", Intrv_Position::Intrv_OverlappingAtEnd)
		.value("Intrv_JustAfter", Intrv_Position::Intrv_JustAfter)
		.value("Intrv_After", Intrv_Position::Intrv_After)
		.export_values();

	// FUNCTIONS
	// C:\Miniconda\envs\occt\Library\include\opencascade\Intrv_Interval.lxx
	mod.def("AreFused", (Standard_Boolean (*)(const Standard_Real, const Standard_ShortReal, const Standard_Real, const Standard_ShortReal)) &AreFused, "None", py::arg("c1"), py::arg("t1"), py::arg("c2"), py::arg("t2"));


	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\Intrv_Interval.hxx
	py::class_<Intrv_Interval, std::unique_ptr<Intrv_Interval, Deleter<Intrv_Interval>>> cls_Intrv_Interval(mod, "Intrv_Interval", "**-----------**** Other ***---* IsBefore ***----------* IsJustBefore ***---------------* IsOverlappingAtStart ***------------------------* IsJustEnclosingAtEnd ***-----------------------------------* IsEnclosing ***----* IsJustOverlappingAtStart ***-------------* IsSimilar ***------------------------* IsJustEnclosingAtStart ***-* IsInside ***------* IsJustOverlappingAtEnd ***-----------------* IsOverlappingAtEnd ***--------* IsJustAfter ***---* IsAfter");
	cls_Intrv_Interval.def(py::init<>());
	cls_Intrv_Interval.def(py::init<const Standard_Real, const Standard_Real>(), py::arg("Start"), py::arg("End"));
	cls_Intrv_Interval.def(py::init<const Standard_Real, const Standard_ShortReal, const Standard_Real, const Standard_ShortReal>(), py::arg("Start"), py::arg("TolStart"), py::arg("End"), py::arg("TolEnd"));
	cls_Intrv_Interval.def("Start", (Standard_Real (Intrv_Interval::*)() const ) &Intrv_Interval::Start, "None");
	cls_Intrv_Interval.def("End", (Standard_Real (Intrv_Interval::*)() const ) &Intrv_Interval::End, "None");
	cls_Intrv_Interval.def("TolStart", (Standard_ShortReal (Intrv_Interval::*)() const ) &Intrv_Interval::TolStart, "None");
	cls_Intrv_Interval.def("TolEnd", (Standard_ShortReal (Intrv_Interval::*)() const ) &Intrv_Interval::TolEnd, "None");
	cls_Intrv_Interval.def("Bounds", (void (Intrv_Interval::*)(Standard_Real &, Standard_ShortReal &, Standard_Real &, Standard_ShortReal &) const ) &Intrv_Interval::Bounds, "None", py::arg("Start"), py::arg("TolStart"), py::arg("End"), py::arg("TolEnd"));
	cls_Intrv_Interval.def("SetStart", (void (Intrv_Interval::*)(const Standard_Real, const Standard_ShortReal)) &Intrv_Interval::SetStart, "None", py::arg("Start"), py::arg("TolStart"));
	cls_Intrv_Interval.def("FuseAtStart", (void (Intrv_Interval::*)(const Standard_Real, const Standard_ShortReal)) &Intrv_Interval::FuseAtStart, "****+****--------------------> Old one ****+****------------------------> New one to fuse <<< <<< ****+****------------------------> result", py::arg("Start"), py::arg("TolStart"));
	cls_Intrv_Interval.def("CutAtStart", (void (Intrv_Interval::*)(const Standard_Real, const Standard_ShortReal)) &Intrv_Interval::CutAtStart, "****+****-----------> Old one <----------**+** Tool for cutting >>> >>> ****+****-----------> result", py::arg("Start"), py::arg("TolStart"));
	cls_Intrv_Interval.def("SetEnd", (void (Intrv_Interval::*)(const Standard_Real, const Standard_ShortReal)) &Intrv_Interval::SetEnd, "None", py::arg("End"), py::arg("TolEnd"));
	cls_Intrv_Interval.def("FuseAtEnd", (void (Intrv_Interval::*)(const Standard_Real, const Standard_ShortReal)) &Intrv_Interval::FuseAtEnd, "<---------------------****+**** Old one <-----------------**+** New one to fuse >>> >>> <---------------------****+**** result", py::arg("End"), py::arg("TolEnd"));
	cls_Intrv_Interval.def("CutAtEnd", (void (Intrv_Interval::*)(const Standard_Real, const Standard_ShortReal)) &Intrv_Interval::CutAtEnd, "<-----****+**** Old one **+**------> Tool for cutting <<< <<< <-----****+**** result", py::arg("End"), py::arg("TolEnd"));
	cls_Intrv_Interval.def("IsProbablyEmpty", (Standard_Boolean (Intrv_Interval::*)() const ) &Intrv_Interval::IsProbablyEmpty, "True if myStart+myTolStart > myEnd-myTolEnd or if myEnd+myTolEnd > myStart-myTolStart");
	cls_Intrv_Interval.def("Position", (Intrv_Position (Intrv_Interval::*)(const Intrv_Interval &) const ) &Intrv_Interval::Position, "True if me is Before Other **-----------**** Other ***-----* Before ***------------* JustBefore ***-----------------* OverlappingAtStart ***--------------------------* JustEnclosingAtEnd ***-------------------------------------* Enclosing ***----* JustOverlappingAtStart ***-------------* Similar ***------------------------* JustEnclosingAtStart ***-* Inside ***------* JustOverlappingAtEnd ***-----------------* OverlappingAtEnd ***--------* JustAfter ***---* After", py::arg("Other"));
	cls_Intrv_Interval.def("IsBefore", (Standard_Boolean (Intrv_Interval::*)(const Intrv_Interval &) const ) &Intrv_Interval::IsBefore, "True if me is Before Other ***----------------** me **-----------**** Other", py::arg("Other"));
	cls_Intrv_Interval.def("IsAfter", (Standard_Boolean (Intrv_Interval::*)(const Intrv_Interval &) const ) &Intrv_Interval::IsAfter, "True if me is After Other **-----------**** me ***----------------** Other", py::arg("Other"));
	cls_Intrv_Interval.def("IsInside", (Standard_Boolean (Intrv_Interval::*)(const Intrv_Interval &) const ) &Intrv_Interval::IsInside, "True if me is Inside Other **-----------**** me ***--------------------------** Other", py::arg("Other"));
	cls_Intrv_Interval.def("IsEnclosing", (Standard_Boolean (Intrv_Interval::*)(const Intrv_Interval &) const ) &Intrv_Interval::IsEnclosing, "True if me is Enclosing Other ***----------------------------**** me ***------------------** Other", py::arg("Other"));
	cls_Intrv_Interval.def("IsJustEnclosingAtStart", (Standard_Boolean (Intrv_Interval::*)(const Intrv_Interval &) const ) &Intrv_Interval::IsJustEnclosingAtStart, "True if me is just Enclosing Other at start ***---------------------------**** me ***------------------** Other", py::arg("Other"));
	cls_Intrv_Interval.def("IsJustEnclosingAtEnd", (Standard_Boolean (Intrv_Interval::*)(const Intrv_Interval &) const ) &Intrv_Interval::IsJustEnclosingAtEnd, "True if me is just Enclosing Other at End ***----------------------------**** me ***-----------------**** Other", py::arg("Other"));
	cls_Intrv_Interval.def("IsJustBefore", (Standard_Boolean (Intrv_Interval::*)(const Intrv_Interval &) const ) &Intrv_Interval::IsJustBefore, "True if me is just before Other ***--------**** me ***-----------** Other", py::arg("Other"));
	cls_Intrv_Interval.def("IsJustAfter", (Standard_Boolean (Intrv_Interval::*)(const Intrv_Interval &) const ) &Intrv_Interval::IsJustAfter, "True if me is just after Other ****-------**** me ***-----------** Other", py::arg("Other"));
	cls_Intrv_Interval.def("IsOverlappingAtStart", (Standard_Boolean (Intrv_Interval::*)(const Intrv_Interval &) const ) &Intrv_Interval::IsOverlappingAtStart, "True if me is overlapping Other at start ***---------------*** me ***-----------** Other", py::arg("Other"));
	cls_Intrv_Interval.def("IsOverlappingAtEnd", (Standard_Boolean (Intrv_Interval::*)(const Intrv_Interval &) const ) &Intrv_Interval::IsOverlappingAtEnd, "True if me is overlapping Other at end ***-----------** me ***---------------*** Other", py::arg("Other"));
	cls_Intrv_Interval.def("IsJustOverlappingAtStart", (Standard_Boolean (Intrv_Interval::*)(const Intrv_Interval &) const ) &Intrv_Interval::IsJustOverlappingAtStart, "True if me is just overlapping Other at start ***-----------*** me ***------------------------** Other", py::arg("Other"));
	cls_Intrv_Interval.def("IsJustOverlappingAtEnd", (Standard_Boolean (Intrv_Interval::*)(const Intrv_Interval &) const ) &Intrv_Interval::IsJustOverlappingAtEnd, "True if me is just overlapping Other at end ***-----------* me ***------------------------** Other", py::arg("Other"));
	cls_Intrv_Interval.def("IsSimilar", (Standard_Boolean (Intrv_Interval::*)(const Intrv_Interval &) const ) &Intrv_Interval::IsSimilar, "True if me and Other have the same bounds *----------------*** me ***-----------------** Other", py::arg("Other"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Intrv_Intervals.hxx
	py::class_<Intrv_Intervals, std::unique_ptr<Intrv_Intervals, Deleter<Intrv_Intervals>>> cls_Intrv_Intervals(mod, "Intrv_Intervals", "The class Intervals is a sorted sequence of non overlapping Real Intervals.");
	cls_Intrv_Intervals.def(py::init<>());
	cls_Intrv_Intervals.def(py::init<const Intrv_Interval &>(), py::arg("Int"));
	cls_Intrv_Intervals.def(py::init([] (const Intrv_Intervals &other) {return new Intrv_Intervals(other);}), "Copy constructor", py::arg("other"));
	cls_Intrv_Intervals.def("Intersect", (void (Intrv_Intervals::*)(const Intrv_Interval &)) &Intrv_Intervals::Intersect, "Intersects the intervals with the interval <Tool>.", py::arg("Tool"));
	cls_Intrv_Intervals.def("Intersect", (void (Intrv_Intervals::*)(const Intrv_Intervals &)) &Intrv_Intervals::Intersect, "Intersects the intervals with the intervals in the sequence <Tool>.", py::arg("Tool"));
	cls_Intrv_Intervals.def("Subtract", (void (Intrv_Intervals::*)(const Intrv_Interval &)) &Intrv_Intervals::Subtract, "None", py::arg("Tool"));
	cls_Intrv_Intervals.def("Subtract", (void (Intrv_Intervals::*)(const Intrv_Intervals &)) &Intrv_Intervals::Subtract, "None", py::arg("Tool"));
	cls_Intrv_Intervals.def("Unite", (void (Intrv_Intervals::*)(const Intrv_Interval &)) &Intrv_Intervals::Unite, "None", py::arg("Tool"));
	cls_Intrv_Intervals.def("Unite", (void (Intrv_Intervals::*)(const Intrv_Intervals &)) &Intrv_Intervals::Unite, "None", py::arg("Tool"));
	cls_Intrv_Intervals.def("XUnite", (void (Intrv_Intervals::*)(const Intrv_Interval &)) &Intrv_Intervals::XUnite, "None", py::arg("Tool"));
	cls_Intrv_Intervals.def("XUnite", (void (Intrv_Intervals::*)(const Intrv_Intervals &)) &Intrv_Intervals::XUnite, "None", py::arg("Tool"));
	cls_Intrv_Intervals.def("NbIntervals", (Standard_Integer (Intrv_Intervals::*)() const ) &Intrv_Intervals::NbIntervals, "None");
	cls_Intrv_Intervals.def("Value", (const Intrv_Interval & (Intrv_Intervals::*)(const Standard_Integer) const ) &Intrv_Intervals::Value, "None", py::arg("Index"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Sequence.hxx
	py::class_<Intrv_SequenceOfInterval, std::unique_ptr<Intrv_SequenceOfInterval, Deleter<Intrv_SequenceOfInterval>>, NCollection_BaseSequence> cls_Intrv_SequenceOfInterval(mod, "Intrv_SequenceOfInterval", "Purpose: Definition of a sequence of elements indexed by an Integer in range of 1..n");
	cls_Intrv_SequenceOfInterval.def(py::init<>());
	cls_Intrv_SequenceOfInterval.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_Intrv_SequenceOfInterval.def(py::init([] (const Intrv_SequenceOfInterval &other) {return new Intrv_SequenceOfInterval(other);}), "Copy constructor", py::arg("other"));
	cls_Intrv_SequenceOfInterval.def("begin", (Intrv_SequenceOfInterval::iterator (Intrv_SequenceOfInterval::*)() const ) &Intrv_SequenceOfInterval::begin, "Returns an iterator pointing to the first element in the sequence.");
	cls_Intrv_SequenceOfInterval.def("end", (Intrv_SequenceOfInterval::iterator (Intrv_SequenceOfInterval::*)() const ) &Intrv_SequenceOfInterval::end, "Returns an iterator referring to the past-the-end element in the sequence.");
	cls_Intrv_SequenceOfInterval.def("cbegin", (Intrv_SequenceOfInterval::const_iterator (Intrv_SequenceOfInterval::*)() const ) &Intrv_SequenceOfInterval::cbegin, "Returns a const iterator pointing to the first element in the sequence.");
	cls_Intrv_SequenceOfInterval.def("cend", (Intrv_SequenceOfInterval::const_iterator (Intrv_SequenceOfInterval::*)() const ) &Intrv_SequenceOfInterval::cend, "Returns a const iterator referring to the past-the-end element in the sequence.");
	cls_Intrv_SequenceOfInterval.def("Size", (Standard_Integer (Intrv_SequenceOfInterval::*)() const ) &Intrv_SequenceOfInterval::Size, "Number of items");
	cls_Intrv_SequenceOfInterval.def("Length", (Standard_Integer (Intrv_SequenceOfInterval::*)() const ) &Intrv_SequenceOfInterval::Length, "Number of items");
	cls_Intrv_SequenceOfInterval.def("Lower", (Standard_Integer (Intrv_SequenceOfInterval::*)() const ) &Intrv_SequenceOfInterval::Lower, "Method for consistency with other collections.");
	cls_Intrv_SequenceOfInterval.def("Upper", (Standard_Integer (Intrv_SequenceOfInterval::*)() const ) &Intrv_SequenceOfInterval::Upper, "Method for consistency with other collections.");
	cls_Intrv_SequenceOfInterval.def("IsEmpty", (Standard_Boolean (Intrv_SequenceOfInterval::*)() const ) &Intrv_SequenceOfInterval::IsEmpty, "Empty query");
	cls_Intrv_SequenceOfInterval.def("Reverse", (void (Intrv_SequenceOfInterval::*)()) &Intrv_SequenceOfInterval::Reverse, "Reverse sequence");
	cls_Intrv_SequenceOfInterval.def("Exchange", (void (Intrv_SequenceOfInterval::*)(const Standard_Integer, const Standard_Integer)) &Intrv_SequenceOfInterval::Exchange, "Exchange two members", py::arg("I"), py::arg("J"));
	cls_Intrv_SequenceOfInterval.def_static("delNode_", (void (*)(NCollection_SeqNode *, opencascade::handle<NCollection_BaseAllocator> &)) &Intrv_SequenceOfInterval::delNode, "Static deleter to be passed to BaseSequence", py::arg("theNode"), py::arg("theAl"));
	cls_Intrv_SequenceOfInterval.def("Clear", [](Intrv_SequenceOfInterval &self) -> void { return self.Clear(); });
	cls_Intrv_SequenceOfInterval.def("Clear", (void (Intrv_SequenceOfInterval::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &Intrv_SequenceOfInterval::Clear, "Clear the items out, take a new allocator if non null", py::arg("theAllocator"));
	cls_Intrv_SequenceOfInterval.def("Assign", (Intrv_SequenceOfInterval & (Intrv_SequenceOfInterval::*)(const Intrv_SequenceOfInterval &)) &Intrv_SequenceOfInterval::Assign, "Replace this sequence by the items of theOther. This method does not change the internal allocator.", py::arg("theOther"));
	cls_Intrv_SequenceOfInterval.def("assign", (Intrv_SequenceOfInterval & (Intrv_SequenceOfInterval::*)(const Intrv_SequenceOfInterval &)) &Intrv_SequenceOfInterval::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_Intrv_SequenceOfInterval.def("Remove", (void (Intrv_SequenceOfInterval::*)(Intrv_SequenceOfInterval::Iterator &)) &Intrv_SequenceOfInterval::Remove, "Remove one item", py::arg("thePosition"));
	cls_Intrv_SequenceOfInterval.def("Remove", (void (Intrv_SequenceOfInterval::*)(const Standard_Integer)) &Intrv_SequenceOfInterval::Remove, "Remove one item", py::arg("theIndex"));
	cls_Intrv_SequenceOfInterval.def("Remove", (void (Intrv_SequenceOfInterval::*)(const Standard_Integer, const Standard_Integer)) &Intrv_SequenceOfInterval::Remove, "Remove range of items", py::arg("theFromIndex"), py::arg("theToIndex"));
	cls_Intrv_SequenceOfInterval.def("Append", (void (Intrv_SequenceOfInterval::*)(const Intrv_Interval &)) &Intrv_SequenceOfInterval::Append, "Append one item", py::arg("theItem"));
	cls_Intrv_SequenceOfInterval.def("Append", (void (Intrv_SequenceOfInterval::*)(Intrv_SequenceOfInterval &)) &Intrv_SequenceOfInterval::Append, "Append another sequence (making it empty)", py::arg("theSeq"));
	cls_Intrv_SequenceOfInterval.def("Prepend", (void (Intrv_SequenceOfInterval::*)(const Intrv_Interval &)) &Intrv_SequenceOfInterval::Prepend, "Prepend one item", py::arg("theItem"));
	cls_Intrv_SequenceOfInterval.def("Prepend", (void (Intrv_SequenceOfInterval::*)(Intrv_SequenceOfInterval &)) &Intrv_SequenceOfInterval::Prepend, "Prepend another sequence (making it empty)", py::arg("theSeq"));
	cls_Intrv_SequenceOfInterval.def("InsertBefore", (void (Intrv_SequenceOfInterval::*)(const Standard_Integer, const Intrv_Interval &)) &Intrv_SequenceOfInterval::InsertBefore, "InsertBefore theIndex theItem", py::arg("theIndex"), py::arg("theItem"));
	cls_Intrv_SequenceOfInterval.def("InsertBefore", (void (Intrv_SequenceOfInterval::*)(const Standard_Integer, Intrv_SequenceOfInterval &)) &Intrv_SequenceOfInterval::InsertBefore, "InsertBefore theIndex another sequence", py::arg("theIndex"), py::arg("theSeq"));
	cls_Intrv_SequenceOfInterval.def("InsertAfter", (void (Intrv_SequenceOfInterval::*)(Intrv_SequenceOfInterval::Iterator &, const Intrv_Interval &)) &Intrv_SequenceOfInterval::InsertAfter, "InsertAfter the position of iterator", py::arg("thePosition"), py::arg("theItem"));
	cls_Intrv_SequenceOfInterval.def("InsertAfter", (void (Intrv_SequenceOfInterval::*)(const Standard_Integer, Intrv_SequenceOfInterval &)) &Intrv_SequenceOfInterval::InsertAfter, "InsertAfter theIndex theItem", py::arg("theIndex"), py::arg("theSeq"));
	cls_Intrv_SequenceOfInterval.def("InsertAfter", (void (Intrv_SequenceOfInterval::*)(const Standard_Integer, const Intrv_Interval &)) &Intrv_SequenceOfInterval::InsertAfter, "InsertAfter theIndex another sequence", py::arg("theIndex"), py::arg("theItem"));
	cls_Intrv_SequenceOfInterval.def("Split", (void (Intrv_SequenceOfInterval::*)(const Standard_Integer, Intrv_SequenceOfInterval &)) &Intrv_SequenceOfInterval::Split, "Split in two sequences", py::arg("theIndex"), py::arg("theSeq"));
	cls_Intrv_SequenceOfInterval.def("First", (const Intrv_Interval & (Intrv_SequenceOfInterval::*)() const ) &Intrv_SequenceOfInterval::First, "First item access");
	cls_Intrv_SequenceOfInterval.def("ChangeFirst", (Intrv_Interval & (Intrv_SequenceOfInterval::*)()) &Intrv_SequenceOfInterval::ChangeFirst, "First item access");
	cls_Intrv_SequenceOfInterval.def("Last", (const Intrv_Interval & (Intrv_SequenceOfInterval::*)() const ) &Intrv_SequenceOfInterval::Last, "Last item access");
	cls_Intrv_SequenceOfInterval.def("ChangeLast", (Intrv_Interval & (Intrv_SequenceOfInterval::*)()) &Intrv_SequenceOfInterval::ChangeLast, "Last item access");
	cls_Intrv_SequenceOfInterval.def("Value", (const Intrv_Interval & (Intrv_SequenceOfInterval::*)(const Standard_Integer) const ) &Intrv_SequenceOfInterval::Value, "Constant item access by theIndex", py::arg("theIndex"));
	cls_Intrv_SequenceOfInterval.def("__call__", (const Intrv_Interval & (Intrv_SequenceOfInterval::*)(const Standard_Integer) const ) &Intrv_SequenceOfInterval::operator(), py::is_operator(), "Constant operator()", py::arg("theIndex"));
	cls_Intrv_SequenceOfInterval.def("ChangeValue", (Intrv_Interval & (Intrv_SequenceOfInterval::*)(const Standard_Integer)) &Intrv_SequenceOfInterval::ChangeValue, "Variable item access by theIndex", py::arg("theIndex"));
	cls_Intrv_SequenceOfInterval.def("__call__", (Intrv_Interval & (Intrv_SequenceOfInterval::*)(const Standard_Integer)) &Intrv_SequenceOfInterval::operator(), py::is_operator(), "Variable operator()", py::arg("theIndex"));
	cls_Intrv_SequenceOfInterval.def("SetValue", (void (Intrv_SequenceOfInterval::*)(const Standard_Integer, const Intrv_Interval &)) &Intrv_SequenceOfInterval::SetValue, "Set item value by theIndex", py::arg("theIndex"), py::arg("theItem"));
	cls_Intrv_SequenceOfInterval.def("__iter__", [](const Intrv_SequenceOfInterval &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());


}
