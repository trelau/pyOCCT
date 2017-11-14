#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <Standard_TypeDef.hxx>
#include <TopAbs_Orientation.hxx>
#include <TopBas_TestInterference.hxx>
#include <NCollection_BaseList.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_List.hxx>
#include <TopBas_ListOfTestInterference.hxx>

PYBIND11_MODULE(TopBas, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.TopAbs");
	py::module::import("OCCT.NCollection");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\TopBas_TestInterference.hxx
	py::class_<TopBas_TestInterference, std::unique_ptr<TopBas_TestInterference, Deleter<TopBas_TestInterference>>> cls_TopBas_TestInterference(mod, "TopBas_TestInterference", "None");
	cls_TopBas_TestInterference.def(py::init<>());
	cls_TopBas_TestInterference.def(py::init<const Standard_Real &, const Standard_Integer &, const TopAbs_Orientation, const TopAbs_Orientation, const TopAbs_Orientation>(), py::arg("Inters"), py::arg("Bound"), py::arg("Orient"), py::arg("Trans"), py::arg("BTrans"));
	cls_TopBas_TestInterference.def("Intersection", (void (TopBas_TestInterference::*)(const Standard_Real &)) &TopBas_TestInterference::Intersection, "None", py::arg("I"));
	cls_TopBas_TestInterference.def("Boundary", (void (TopBas_TestInterference::*)(const Standard_Integer &)) &TopBas_TestInterference::Boundary, "None", py::arg("B"));
	cls_TopBas_TestInterference.def("Orientation", (void (TopBas_TestInterference::*)(const TopAbs_Orientation)) &TopBas_TestInterference::Orientation, "None", py::arg("O"));
	cls_TopBas_TestInterference.def("Transition", (void (TopBas_TestInterference::*)(const TopAbs_Orientation)) &TopBas_TestInterference::Transition, "None", py::arg("Tr"));
	cls_TopBas_TestInterference.def("BoundaryTransition", (void (TopBas_TestInterference::*)(const TopAbs_Orientation)) &TopBas_TestInterference::BoundaryTransition, "None", py::arg("BTr"));
	cls_TopBas_TestInterference.def("Intersection", (const Standard_Real & (TopBas_TestInterference::*)() const ) &TopBas_TestInterference::Intersection, "None");
	cls_TopBas_TestInterference.def("ChangeIntersection", (Standard_Real & (TopBas_TestInterference::*)()) &TopBas_TestInterference::ChangeIntersection, "None");
	cls_TopBas_TestInterference.def("Boundary", (const Standard_Integer & (TopBas_TestInterference::*)() const ) &TopBas_TestInterference::Boundary, "None");
	cls_TopBas_TestInterference.def("ChangeBoundary", (Standard_Integer & (TopBas_TestInterference::*)()) &TopBas_TestInterference::ChangeBoundary, "None");
	cls_TopBas_TestInterference.def("Orientation", (TopAbs_Orientation (TopBas_TestInterference::*)() const ) &TopBas_TestInterference::Orientation, "None");
	cls_TopBas_TestInterference.def("Transition", (TopAbs_Orientation (TopBas_TestInterference::*)() const ) &TopBas_TestInterference::Transition, "None");
	cls_TopBas_TestInterference.def("BoundaryTransition", (TopAbs_Orientation (TopBas_TestInterference::*)() const ) &TopBas_TestInterference::BoundaryTransition, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_List.hxx
	py::class_<TopBas_ListOfTestInterference, std::unique_ptr<TopBas_ListOfTestInterference, Deleter<TopBas_ListOfTestInterference>>, NCollection_BaseList> cls_TopBas_ListOfTestInterference(mod, "TopBas_ListOfTestInterference", "Purpose: Simple list to link items together keeping the first and the last one. Inherits BaseList, adding the data item to each node.");
	cls_TopBas_ListOfTestInterference.def(py::init<>());
	cls_TopBas_ListOfTestInterference.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_TopBas_ListOfTestInterference.def(py::init([] (const TopBas_ListOfTestInterference &other) {return new TopBas_ListOfTestInterference(other);}), "Copy constructor", py::arg("other"));
	cls_TopBas_ListOfTestInterference.def("begin", (TopBas_ListOfTestInterference::iterator (TopBas_ListOfTestInterference::*)() const ) &TopBas_ListOfTestInterference::begin, "Returns an iterator pointing to the first element in the list.");
	cls_TopBas_ListOfTestInterference.def("end", (TopBas_ListOfTestInterference::iterator (TopBas_ListOfTestInterference::*)() const ) &TopBas_ListOfTestInterference::end, "Returns an iterator referring to the past-the-end element in the list.");
	cls_TopBas_ListOfTestInterference.def("cbegin", (TopBas_ListOfTestInterference::const_iterator (TopBas_ListOfTestInterference::*)() const ) &TopBas_ListOfTestInterference::cbegin, "Returns a const iterator pointing to the first element in the list.");
	cls_TopBas_ListOfTestInterference.def("cend", (TopBas_ListOfTestInterference::const_iterator (TopBas_ListOfTestInterference::*)() const ) &TopBas_ListOfTestInterference::cend, "Returns a const iterator referring to the past-the-end element in the list.");
	cls_TopBas_ListOfTestInterference.def("Size", (Standard_Integer (TopBas_ListOfTestInterference::*)() const ) &TopBas_ListOfTestInterference::Size, "Size - Number of items");
	cls_TopBas_ListOfTestInterference.def("Assign", (TopBas_ListOfTestInterference & (TopBas_ListOfTestInterference::*)(const TopBas_ListOfTestInterference &)) &TopBas_ListOfTestInterference::Assign, "Replace this list by the items of another list (theOther parameter). This method does not change the internal allocator.", py::arg("theOther"));
	cls_TopBas_ListOfTestInterference.def("assign", (TopBas_ListOfTestInterference & (TopBas_ListOfTestInterference::*)(const TopBas_ListOfTestInterference &)) &TopBas_ListOfTestInterference::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_TopBas_ListOfTestInterference.def("Clear", [](TopBas_ListOfTestInterference &self) -> void { return self.Clear(); });
	cls_TopBas_ListOfTestInterference.def("Clear", (void (TopBas_ListOfTestInterference::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &TopBas_ListOfTestInterference::Clear, "Clear this list", py::arg("theAllocator"));
	cls_TopBas_ListOfTestInterference.def("First", (const TopBas_TestInterference & (TopBas_ListOfTestInterference::*)() const ) &TopBas_ListOfTestInterference::First, "First item");
	cls_TopBas_ListOfTestInterference.def("First", (TopBas_TestInterference & (TopBas_ListOfTestInterference::*)()) &TopBas_ListOfTestInterference::First, "First item (non-const)");
	cls_TopBas_ListOfTestInterference.def("Last", (const TopBas_TestInterference & (TopBas_ListOfTestInterference::*)() const ) &TopBas_ListOfTestInterference::Last, "Last item");
	cls_TopBas_ListOfTestInterference.def("Last", (TopBas_TestInterference & (TopBas_ListOfTestInterference::*)()) &TopBas_ListOfTestInterference::Last, "Last item (non-const)");
	cls_TopBas_ListOfTestInterference.def("Append", (TopBas_TestInterference & (TopBas_ListOfTestInterference::*)(const TopBas_TestInterference &)) &TopBas_ListOfTestInterference::Append, "Append one item at the end", py::arg("theItem"));
	cls_TopBas_ListOfTestInterference.def("Append", (void (TopBas_ListOfTestInterference::*)(const TopBas_TestInterference &, TopBas_ListOfTestInterference::Iterator &)) &TopBas_ListOfTestInterference::Append, "Append one item at the end and output iterator pointing at the appended item", py::arg("theItem"), py::arg("theIter"));
	cls_TopBas_ListOfTestInterference.def("Append", (void (TopBas_ListOfTestInterference::*)(TopBas_ListOfTestInterference &)) &TopBas_ListOfTestInterference::Append, "Append another list at the end", py::arg("theOther"));
	cls_TopBas_ListOfTestInterference.def("Prepend", (TopBas_TestInterference & (TopBas_ListOfTestInterference::*)(const TopBas_TestInterference &)) &TopBas_ListOfTestInterference::Prepend, "Prepend one item at the beginning", py::arg("theItem"));
	cls_TopBas_ListOfTestInterference.def("Prepend", (void (TopBas_ListOfTestInterference::*)(TopBas_ListOfTestInterference &)) &TopBas_ListOfTestInterference::Prepend, "Prepend another list at the beginning", py::arg("theOther"));
	cls_TopBas_ListOfTestInterference.def("RemoveFirst", (void (TopBas_ListOfTestInterference::*)()) &TopBas_ListOfTestInterference::RemoveFirst, "RemoveFirst item");
	cls_TopBas_ListOfTestInterference.def("Remove", (void (TopBas_ListOfTestInterference::*)(TopBas_ListOfTestInterference::Iterator &)) &TopBas_ListOfTestInterference::Remove, "Remove item pointed by iterator theIter; theIter is then set to the next item", py::arg("theIter"));
	cls_TopBas_ListOfTestInterference.def("InsertBefore", (TopBas_TestInterference & (TopBas_ListOfTestInterference::*)(const TopBas_TestInterference &, TopBas_ListOfTestInterference::Iterator &)) &TopBas_ListOfTestInterference::InsertBefore, "InsertBefore", py::arg("theItem"), py::arg("theIter"));
	cls_TopBas_ListOfTestInterference.def("InsertBefore", (void (TopBas_ListOfTestInterference::*)(TopBas_ListOfTestInterference &, TopBas_ListOfTestInterference::Iterator &)) &TopBas_ListOfTestInterference::InsertBefore, "InsertBefore", py::arg("theOther"), py::arg("theIter"));
	cls_TopBas_ListOfTestInterference.def("InsertAfter", (TopBas_TestInterference & (TopBas_ListOfTestInterference::*)(const TopBas_TestInterference &, TopBas_ListOfTestInterference::Iterator &)) &TopBas_ListOfTestInterference::InsertAfter, "InsertAfter", py::arg("theItem"), py::arg("theIter"));
	cls_TopBas_ListOfTestInterference.def("InsertAfter", (void (TopBas_ListOfTestInterference::*)(TopBas_ListOfTestInterference &, TopBas_ListOfTestInterference::Iterator &)) &TopBas_ListOfTestInterference::InsertAfter, "InsertAfter", py::arg("theOther"), py::arg("theIter"));
	cls_TopBas_ListOfTestInterference.def("Reverse", (void (TopBas_ListOfTestInterference::*)()) &TopBas_ListOfTestInterference::Reverse, "Reverse the list");
	cls_TopBas_ListOfTestInterference.def("__iter__", [](const TopBas_ListOfTestInterference &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_TListIterator.hxx
	py::class_<TopBas_ListIteratorOfListOfTestInterference, std::unique_ptr<TopBas_ListIteratorOfListOfTestInterference, Deleter<TopBas_ListIteratorOfListOfTestInterference>>> cls_TopBas_ListIteratorOfListOfTestInterference(mod, "TopBas_ListIteratorOfListOfTestInterference", "Purpose: This Iterator class iterates on BaseList of TListNode and is instantiated in List/Set/Queue/Stack Remark: TListIterator is internal class");
	cls_TopBas_ListIteratorOfListOfTestInterference.def(py::init<>());
	cls_TopBas_ListIteratorOfListOfTestInterference.def(py::init<const NCollection_BaseList &>(), py::arg("theList"));
	cls_TopBas_ListIteratorOfListOfTestInterference.def("More", (Standard_Boolean (TopBas_ListIteratorOfListOfTestInterference::*)() const ) &TopBas_ListIteratorOfListOfTestInterference::More, "Check end");
	cls_TopBas_ListIteratorOfListOfTestInterference.def("Next", (void (TopBas_ListIteratorOfListOfTestInterference::*)()) &TopBas_ListIteratorOfListOfTestInterference::Next, "Make step");
	cls_TopBas_ListIteratorOfListOfTestInterference.def("Value", (const TopBas_TestInterference & (TopBas_ListIteratorOfListOfTestInterference::*)() const ) &TopBas_ListIteratorOfListOfTestInterference::Value, "Constant Value access");
	cls_TopBas_ListIteratorOfListOfTestInterference.def("Value", (TopBas_TestInterference & (TopBas_ListIteratorOfListOfTestInterference::*)()) &TopBas_ListIteratorOfListOfTestInterference::Value, "Non-const Value access");
	cls_TopBas_ListIteratorOfListOfTestInterference.def("ChangeValue", (TopBas_TestInterference & (TopBas_ListIteratorOfListOfTestInterference::*)() const ) &TopBas_ListIteratorOfListOfTestInterference::ChangeValue, "Non-const Value access");


}
