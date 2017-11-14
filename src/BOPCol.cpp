#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <Standard_Handle.hxx>
#include <BOPCol_BaseAllocator.hxx>
#include <NCollection_BaseList.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_List.hxx>
#include <Standard_TypeDef.hxx>
#include <BOPCol_ListOfShape.hxx>
#include <NCollection_BaseMap.hxx>
#include <NCollection_DataMap.hxx>
#include <BOPCol_DataMapOfIntegerListOfShape.hxx>
#include <BOPCol_DataMapOfShapeReal.hxx>
#include <NCollection_Map.hxx>
#include <BOPCol_MapOfShape.hxx>
#include <BOPCol_DataMapOfShapeListOfShape.hxx>
#include <BOPCol_DataMapOfShapeShape.hxx>
#include <NCollection_IndexedDataMap.hxx>
#include <BOPCol_IndexedDataMapOfShapeListOfShape.hxx>
#include <NCollection_IndexedMap.hxx>
#include <BOPCol_IndexedMapOfOrientedShape.hxx>
#include <BOPCol_DataMapOfShapeInteger.hxx>
#include <BOPCol_MapOfInteger.hxx>
#include <BOPCol_IndexedMapOfShape.hxx>
#include <BOPCol_DataMapOfIntegerReal.hxx>
#include <BOPCol_ListOfInteger.hxx>
#include <BOPCol_DataMapOfIntegerInteger.hxx>
#include <BOPCol_DataMapOfIntegerListOfInteger.hxx>
#include <BOPCol_IndexedDataMapOfShapeInteger.hxx>
#include <BOPCol_IndexedDataMapOfShapeReal.hxx>
#include <BOPCol_ListOfListOfShape.hxx>
#include <BOPCol_DataMapOfShapeAddress.hxx>
#include <BOPCol_DataMapOfTransientAddress.hxx>
#include <NCollection_UBTree.hxx>
#include <BOPCol_Box2DBndTree.hxx>
#include <Bnd_Box2d.hxx>
#include <BOPCol_BoxBndTree.hxx>
#include <Bnd_Box.hxx>
#include <BOPCol_DataMapOfIntegerMapOfInteger.hxx>
#include <BOPCol_DataMapOfIntegerShape.hxx>
#include <BOPCol_IndexedDataMapOfIntegerListOfInteger.hxx>
#include <BOPCol_IndexedDataMapOfShapeBox.hxx>
#include <BOPCol_IndexedDataMapOfShapeShape.hxx>
#include <BOPCol_IndexedMapOfInteger.hxx>
#include <BOPCol_MapOfOrientedShape.hxx>
#include <BOPCol_PInteger.hxx>
#include <NCollection_BaseSequence.hxx>
#include <NCollection_Sequence.hxx>
#include <BOPCol_SequenceOfPnt2d.hxx>
#include <BOPCol_SequenceOfReal.hxx>
#include <BOPCol_SequenceOfShape.hxx>

PYBIND11_MODULE(BOPCol, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.Bnd");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// Callback for BOPCol_Box2DBndTreeSelector.
	class PyCallback_BOPCol_Box2DBndTreeSelector : public BOPCol_Box2DBndTreeSelector {
	public:
		using BOPCol_Box2DBndTreeSelector::BOPCol_Box2DBndTreeSelector;

		Standard_Boolean Accept(const int & a0) override { PYBIND11_OVERLOAD_PURE(Standard_Boolean, BOPCol_Box2DBndTreeSelector, Accept, a0); }
	};

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_Box2DBndTree.hxx
	py::class_<BOPCol_Box2DBndTreeSelector, std::unique_ptr<BOPCol_Box2DBndTreeSelector, Deleter<BOPCol_Box2DBndTreeSelector>>, PyCallback_BOPCol_Box2DBndTreeSelector> cls_BOPCol_Box2DBndTreeSelector(mod, "BOPCol_Box2DBndTreeSelector", "None");
	cls_BOPCol_Box2DBndTreeSelector.def(py::init<>());
	cls_BOPCol_Box2DBndTreeSelector.def("Reject", (Standard_Boolean (BOPCol_Box2DBndTreeSelector::*)(const Bnd_Box2d &) const ) &BOPCol_Box2DBndTreeSelector::Reject, "None", py::arg(""));
	cls_BOPCol_Box2DBndTreeSelector.def("Accept", (Standard_Boolean (BOPCol_Box2DBndTreeSelector::*)(const Standard_Integer &)) &BOPCol_Box2DBndTreeSelector::Accept, "None", py::arg(""));
	cls_BOPCol_Box2DBndTreeSelector.def("Clear", (void (BOPCol_Box2DBndTreeSelector::*)()) &BOPCol_Box2DBndTreeSelector::Clear, "None");
	cls_BOPCol_Box2DBndTreeSelector.def("SetBox", (void (BOPCol_Box2DBndTreeSelector::*)(const Bnd_Box2d &)) &BOPCol_Box2DBndTreeSelector::SetBox, "None", py::arg(""));
	cls_BOPCol_Box2DBndTreeSelector.def("Indices", (const BOPCol_ListOfInteger & (BOPCol_Box2DBndTreeSelector::*)() const ) &BOPCol_Box2DBndTreeSelector::Indices, "None");

	// Callback for BOPCol_BoxBndTreeSelector.
	class PyCallback_BOPCol_BoxBndTreeSelector : public BOPCol_BoxBndTreeSelector {
	public:
		using BOPCol_BoxBndTreeSelector::BOPCol_BoxBndTreeSelector;

		Standard_Boolean Accept(const int & a0) override { PYBIND11_OVERLOAD_PURE(Standard_Boolean, BOPCol_BoxBndTreeSelector, Accept, a0); }
	};

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_BoxBndTree.hxx
	py::class_<BOPCol_BoxBndTreeSelector, std::unique_ptr<BOPCol_BoxBndTreeSelector, Deleter<BOPCol_BoxBndTreeSelector>>, PyCallback_BOPCol_BoxBndTreeSelector> cls_BOPCol_BoxBndTreeSelector(mod, "BOPCol_BoxBndTreeSelector", "None");
	cls_BOPCol_BoxBndTreeSelector.def(py::init<>());
	cls_BOPCol_BoxBndTreeSelector.def("Reject", (Standard_Boolean (BOPCol_BoxBndTreeSelector::*)(const Bnd_Box &) const ) &BOPCol_BoxBndTreeSelector::Reject, "None", py::arg(""));
	cls_BOPCol_BoxBndTreeSelector.def("Accept", (Standard_Boolean (BOPCol_BoxBndTreeSelector::*)(const Standard_Integer &)) &BOPCol_BoxBndTreeSelector::Accept, "None", py::arg(""));
	cls_BOPCol_BoxBndTreeSelector.def("Clear", (void (BOPCol_BoxBndTreeSelector::*)()) &BOPCol_BoxBndTreeSelector::Clear, "None");
	cls_BOPCol_BoxBndTreeSelector.def("SetBox", (void (BOPCol_BoxBndTreeSelector::*)(const Bnd_Box &)) &BOPCol_BoxBndTreeSelector::SetBox, "None", py::arg(""));
	cls_BOPCol_BoxBndTreeSelector.def("Indices", (const BOPCol_ListOfInteger & (BOPCol_BoxBndTreeSelector::*)() const ) &BOPCol_BoxBndTreeSelector::Indices, "None");

	other_mod = py::module::import("OCCT.IntSurf");
	if (py::hasattr(other_mod, "IntSurf_Allocator")) {
		mod.attr("BOPCol_BaseAllocator") = other_mod.attr("IntSurf_Allocator");
	}

	other_mod = py::module::import("OCCT.TopoDS");
	if (py::hasattr(other_mod, "TopoDS_ListOfShape")) {
		mod.attr("BOPCol_ListOfShape") = other_mod.attr("TopoDS_ListOfShape");
	}

	other_mod = py::module::import("OCCT.TopoDS");
	if (py::hasattr(other_mod, "TopoDS_ListIteratorOfListOfShape")) {
		mod.attr("BOPCol_ListIteratorOfListOfShape") = other_mod.attr("TopoDS_ListIteratorOfListOfShape");
	}

	other_mod = py::module::import("OCCT.TopTools");
	if (py::hasattr(other_mod, "TopTools_DataMapOfIntegerListOfShape")) {
		mod.attr("BOPCol_DataMapOfIntegerListOfShape") = other_mod.attr("TopTools_DataMapOfIntegerListOfShape");
	}

	other_mod = py::module::import("OCCT.TopTools");
	if (py::hasattr(other_mod, "TopTools_DataMapIteratorOfDataMapOfIntegerListOfShape")) {
		mod.attr("BOPCol_DataMapIteratorOfDataMapOfIntegerListOfShape") = other_mod.attr("TopTools_DataMapIteratorOfDataMapOfIntegerListOfShape");
	}

	other_mod = py::module::import("OCCT.TopTools");
	if (py::hasattr(other_mod, "TopTools_DataMapOfShapeReal")) {
		mod.attr("BOPCol_DataMapOfShapeReal") = other_mod.attr("TopTools_DataMapOfShapeReal");
	}

	other_mod = py::module::import("OCCT.TopTools");
	if (py::hasattr(other_mod, "TopTools_DataMapIteratorOfDataMapOfShapeReal")) {
		mod.attr("BOPCol_DataMapIteratorOfDataMapOfShapeReal") = other_mod.attr("TopTools_DataMapIteratorOfDataMapOfShapeReal");
	}

	other_mod = py::module::import("OCCT.TopTools");
	if (py::hasattr(other_mod, "TopTools_MapOfShape")) {
		mod.attr("BOPCol_MapOfShape") = other_mod.attr("TopTools_MapOfShape");
	}

	other_mod = py::module::import("OCCT.TopTools");
	if (py::hasattr(other_mod, "TopTools_MapIteratorOfMapOfShape")) {
		mod.attr("BOPCol_MapIteratorOfMapOfShape") = other_mod.attr("TopTools_MapIteratorOfMapOfShape");
	}

	other_mod = py::module::import("OCCT.TopTools");
	if (py::hasattr(other_mod, "TopTools_DataMapOfShapeListOfShape")) {
		mod.attr("BOPCol_DataMapOfShapeListOfShape") = other_mod.attr("TopTools_DataMapOfShapeListOfShape");
	}

	other_mod = py::module::import("OCCT.TopTools");
	if (py::hasattr(other_mod, "TopTools_DataMapIteratorOfDataMapOfShapeListOfShape")) {
		mod.attr("BOPCol_DataMapIteratorOfDataMapOfShapeListOfShape") = other_mod.attr("TopTools_DataMapIteratorOfDataMapOfShapeListOfShape");
	}

	other_mod = py::module::import("OCCT.TopTools");
	if (py::hasattr(other_mod, "TopTools_DataMapOfShapeShape")) {
		mod.attr("BOPCol_DataMapOfShapeShape") = other_mod.attr("TopTools_DataMapOfShapeShape");
	}

	other_mod = py::module::import("OCCT.TopTools");
	if (py::hasattr(other_mod, "TopTools_DataMapIteratorOfDataMapOfShapeShape")) {
		mod.attr("BOPCol_DataMapIteratorOfDataMapOfShapeShape") = other_mod.attr("TopTools_DataMapIteratorOfDataMapOfShapeShape");
	}

	other_mod = py::module::import("OCCT.TopTools");
	if (py::hasattr(other_mod, "TopTools_IndexedDataMapOfShapeListOfShape")) {
		mod.attr("BOPCol_IndexedDataMapOfShapeListOfShape") = other_mod.attr("TopTools_IndexedDataMapOfShapeListOfShape");
	}

	other_mod = py::module::import("OCCT.TopTools");
	if (py::hasattr(other_mod, "TopTools_IndexedMapOfOrientedShape")) {
		mod.attr("BOPCol_IndexedMapOfOrientedShape") = other_mod.attr("TopTools_IndexedMapOfOrientedShape");
	}

	other_mod = py::module::import("OCCT.TopTools");
	if (py::hasattr(other_mod, "TopTools_DataMapOfShapeInteger")) {
		mod.attr("BOPCol_DataMapOfShapeInteger") = other_mod.attr("TopTools_DataMapOfShapeInteger");
	}

	other_mod = py::module::import("OCCT.TopTools");
	if (py::hasattr(other_mod, "TopTools_DataMapIteratorOfDataMapOfShapeInteger")) {
		mod.attr("BOPCol_DataMapIteratorOfDataMapOfShapeInteger") = other_mod.attr("TopTools_DataMapIteratorOfDataMapOfShapeInteger");
	}

	other_mod = py::module::import("OCCT.TColStd");
	if (py::hasattr(other_mod, "TColStd_MapOfInteger")) {
		mod.attr("BOPCol_MapOfInteger") = other_mod.attr("TColStd_MapOfInteger");
	}

	other_mod = py::module::import("OCCT.TColStd");
	if (py::hasattr(other_mod, "TColStd_MapIteratorOfMapOfInteger")) {
		mod.attr("BOPCol_MapIteratorOfMapOfInteger") = other_mod.attr("TColStd_MapIteratorOfMapOfInteger");
	}

	other_mod = py::module::import("OCCT.TopTools");
	if (py::hasattr(other_mod, "TopTools_IndexedMapOfShape")) {
		mod.attr("BOPCol_IndexedMapOfShape") = other_mod.attr("TopTools_IndexedMapOfShape");
	}

	other_mod = py::module::import("OCCT.TColStd");
	if (py::hasattr(other_mod, "TColStd_DataMapOfIntegerReal")) {
		mod.attr("BOPCol_DataMapOfIntegerReal") = other_mod.attr("TColStd_DataMapOfIntegerReal");
	}

	other_mod = py::module::import("OCCT.TColStd");
	if (py::hasattr(other_mod, "TColStd_DataMapIteratorOfDataMapOfIntegerReal")) {
		mod.attr("BOPCol_DataMapIteratorOfDataMapOfIntegerReal") = other_mod.attr("TColStd_DataMapIteratorOfDataMapOfIntegerReal");
	}

	other_mod = py::module::import("OCCT.TColStd");
	if (py::hasattr(other_mod, "TColStd_ListOfInteger")) {
		mod.attr("BOPCol_ListOfInteger") = other_mod.attr("TColStd_ListOfInteger");
	}

	other_mod = py::module::import("OCCT.TColStd");
	if (py::hasattr(other_mod, "TColStd_ListIteratorOfListOfInteger")) {
		mod.attr("BOPCol_ListIteratorOfListOfInteger") = other_mod.attr("TColStd_ListIteratorOfListOfInteger");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_ListOfInteger.hxx
	other_mod = py::module::import("OCCT.TColStd");
	if (py::hasattr(other_mod, "TColStd_DataMapOfIntegerInteger")) {
		mod.attr("BOPCol_DataMapOfIntegerInteger") = other_mod.attr("TColStd_DataMapOfIntegerInteger");
	}

	other_mod = py::module::import("OCCT.TColStd");
	if (py::hasattr(other_mod, "TColStd_DataMapIteratorOfDataMapOfIntegerInteger")) {
		mod.attr("BOPCol_DataMapIteratorOfDataMapOfIntegerInteger") = other_mod.attr("TColStd_DataMapIteratorOfDataMapOfIntegerInteger");
	}

	other_mod = py::module::import("OCCT.TColStd");
	if (py::hasattr(other_mod, "TColStd_DataMapOfIntegerListOfInteger")) {
		mod.attr("BOPCol_DataMapOfIntegerListOfInteger") = other_mod.attr("TColStd_DataMapOfIntegerListOfInteger");
	}

	other_mod = py::module::import("OCCT.TColStd");
	if (py::hasattr(other_mod, "TColStd_DataMapIteratorOfDataMapOfIntegerListOfInteger")) {
		mod.attr("BOPCol_DataMapIteratorOfDataMapOfIntegerListOfInteger") = other_mod.attr("TColStd_DataMapIteratorOfDataMapOfIntegerListOfInteger");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_IndexedDataMap.hxx
	py::class_<BOPCol_IndexedDataMapOfShapeInteger, std::unique_ptr<BOPCol_IndexedDataMapOfShapeInteger, Deleter<BOPCol_IndexedDataMapOfShapeInteger>>, NCollection_BaseMap> cls_BOPCol_IndexedDataMapOfShapeInteger(mod, "BOPCol_IndexedDataMapOfShapeInteger", "Purpose: An indexed map is used to store keys and to bind an index to them. Each new key stored in the map gets an index. Index are incremented as keys are stored in the map. A key can be found by the index and an index by the key. No key but the last can be removed so the indices are in the range 1.. Extent. An Item is stored with each key.");
	cls_BOPCol_IndexedDataMapOfShapeInteger.def(py::init<>());
	cls_BOPCol_IndexedDataMapOfShapeInteger.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_BOPCol_IndexedDataMapOfShapeInteger.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_BOPCol_IndexedDataMapOfShapeInteger.def(py::init([] (const BOPCol_IndexedDataMapOfShapeInteger &other) {return new BOPCol_IndexedDataMapOfShapeInteger(other);}), "Copy constructor", py::arg("other"));
	cls_BOPCol_IndexedDataMapOfShapeInteger.def("begin", (BOPCol_IndexedDataMapOfShapeInteger::iterator (BOPCol_IndexedDataMapOfShapeInteger::*)() const ) &BOPCol_IndexedDataMapOfShapeInteger::begin, "Returns an iterator pointing to the first element in the map.");
	cls_BOPCol_IndexedDataMapOfShapeInteger.def("end", (BOPCol_IndexedDataMapOfShapeInteger::iterator (BOPCol_IndexedDataMapOfShapeInteger::*)() const ) &BOPCol_IndexedDataMapOfShapeInteger::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_BOPCol_IndexedDataMapOfShapeInteger.def("cbegin", (BOPCol_IndexedDataMapOfShapeInteger::const_iterator (BOPCol_IndexedDataMapOfShapeInteger::*)() const ) &BOPCol_IndexedDataMapOfShapeInteger::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_BOPCol_IndexedDataMapOfShapeInteger.def("cend", (BOPCol_IndexedDataMapOfShapeInteger::const_iterator (BOPCol_IndexedDataMapOfShapeInteger::*)() const ) &BOPCol_IndexedDataMapOfShapeInteger::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_BOPCol_IndexedDataMapOfShapeInteger.def("Exchange", (void (BOPCol_IndexedDataMapOfShapeInteger::*)(BOPCol_IndexedDataMapOfShapeInteger &)) &BOPCol_IndexedDataMapOfShapeInteger::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_BOPCol_IndexedDataMapOfShapeInteger.def("Assign", (BOPCol_IndexedDataMapOfShapeInteger & (BOPCol_IndexedDataMapOfShapeInteger::*)(const BOPCol_IndexedDataMapOfShapeInteger &)) &BOPCol_IndexedDataMapOfShapeInteger::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_BOPCol_IndexedDataMapOfShapeInteger.def("assign", (BOPCol_IndexedDataMapOfShapeInteger & (BOPCol_IndexedDataMapOfShapeInteger::*)(const BOPCol_IndexedDataMapOfShapeInteger &)) &BOPCol_IndexedDataMapOfShapeInteger::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_BOPCol_IndexedDataMapOfShapeInteger.def("ReSize", (void (BOPCol_IndexedDataMapOfShapeInteger::*)(const Standard_Integer)) &BOPCol_IndexedDataMapOfShapeInteger::ReSize, "ReSize", py::arg("N"));
	cls_BOPCol_IndexedDataMapOfShapeInteger.def("Add", (Standard_Integer (BOPCol_IndexedDataMapOfShapeInteger::*)(const TopoDS_Shape &, const Standard_Integer &)) &BOPCol_IndexedDataMapOfShapeInteger::Add, "Add", py::arg("theKey1"), py::arg("theItem"));
	cls_BOPCol_IndexedDataMapOfShapeInteger.def("Contains", (Standard_Boolean (BOPCol_IndexedDataMapOfShapeInteger::*)(const TopoDS_Shape &) const ) &BOPCol_IndexedDataMapOfShapeInteger::Contains, "Contains", py::arg("theKey1"));
	cls_BOPCol_IndexedDataMapOfShapeInteger.def("Substitute", (void (BOPCol_IndexedDataMapOfShapeInteger::*)(const Standard_Integer, const TopoDS_Shape &, const Standard_Integer &)) &BOPCol_IndexedDataMapOfShapeInteger::Substitute, "Substitute", py::arg("theIndex"), py::arg("theKey1"), py::arg("theItem"));
	cls_BOPCol_IndexedDataMapOfShapeInteger.def("Swap", (void (BOPCol_IndexedDataMapOfShapeInteger::*)(const Standard_Integer, const Standard_Integer)) &BOPCol_IndexedDataMapOfShapeInteger::Swap, "Swaps two elements with the given indices.", py::arg("theIndex1"), py::arg("theIndex2"));
	cls_BOPCol_IndexedDataMapOfShapeInteger.def("RemoveLast", (void (BOPCol_IndexedDataMapOfShapeInteger::*)()) &BOPCol_IndexedDataMapOfShapeInteger::RemoveLast, "RemoveLast");
	cls_BOPCol_IndexedDataMapOfShapeInteger.def("RemoveFromIndex", (void (BOPCol_IndexedDataMapOfShapeInteger::*)(const Standard_Integer)) &BOPCol_IndexedDataMapOfShapeInteger::RemoveFromIndex, "Remove the key of the given index. Caution! The index of the last key can be changed.", py::arg("theKey2"));
	cls_BOPCol_IndexedDataMapOfShapeInteger.def("RemoveKey", (void (BOPCol_IndexedDataMapOfShapeInteger::*)(const TopoDS_Shape &)) &BOPCol_IndexedDataMapOfShapeInteger::RemoveKey, "Remove the given key. Caution! The index of the last key can be changed.", py::arg("theKey1"));
	cls_BOPCol_IndexedDataMapOfShapeInteger.def("FindKey", (const TopoDS_Shape & (BOPCol_IndexedDataMapOfShapeInteger::*)(const Standard_Integer) const ) &BOPCol_IndexedDataMapOfShapeInteger::FindKey, "FindKey", py::arg("theKey2"));
	cls_BOPCol_IndexedDataMapOfShapeInteger.def("FindFromIndex", (const Standard_Integer & (BOPCol_IndexedDataMapOfShapeInteger::*)(const Standard_Integer) const ) &BOPCol_IndexedDataMapOfShapeInteger::FindFromIndex, "FindFromIndex", py::arg("theKey2"));
	cls_BOPCol_IndexedDataMapOfShapeInteger.def("__call__", (const Standard_Integer & (BOPCol_IndexedDataMapOfShapeInteger::*)(const Standard_Integer) const ) &BOPCol_IndexedDataMapOfShapeInteger::operator(), py::is_operator(), "operator ()", py::arg("theKey2"));
	cls_BOPCol_IndexedDataMapOfShapeInteger.def("ChangeFromIndex", (Standard_Integer & (BOPCol_IndexedDataMapOfShapeInteger::*)(const Standard_Integer)) &BOPCol_IndexedDataMapOfShapeInteger::ChangeFromIndex, "ChangeFromIndex", py::arg("theKey2"));
	cls_BOPCol_IndexedDataMapOfShapeInteger.def("__call__", (Standard_Integer & (BOPCol_IndexedDataMapOfShapeInteger::*)(const Standard_Integer)) &BOPCol_IndexedDataMapOfShapeInteger::operator(), py::is_operator(), "operator ()", py::arg("theKey2"));
	cls_BOPCol_IndexedDataMapOfShapeInteger.def("FindIndex", (Standard_Integer (BOPCol_IndexedDataMapOfShapeInteger::*)(const TopoDS_Shape &) const ) &BOPCol_IndexedDataMapOfShapeInteger::FindIndex, "FindIndex", py::arg("theKey1"));
	cls_BOPCol_IndexedDataMapOfShapeInteger.def("FindFromKey", (const Standard_Integer & (BOPCol_IndexedDataMapOfShapeInteger::*)(const TopoDS_Shape &) const ) &BOPCol_IndexedDataMapOfShapeInteger::FindFromKey, "FindFromKey", py::arg("theKey1"));
	cls_BOPCol_IndexedDataMapOfShapeInteger.def("ChangeFromKey", (Standard_Integer & (BOPCol_IndexedDataMapOfShapeInteger::*)(const TopoDS_Shape &)) &BOPCol_IndexedDataMapOfShapeInteger::ChangeFromKey, "ChangeFromKey", py::arg("theKey1"));
	// FIXME cls_BOPCol_IndexedDataMapOfShapeInteger.def("Seek", (const Standard_Integer * (BOPCol_IndexedDataMapOfShapeInteger::*)(const TopoDS_Shape &) const ) &BOPCol_IndexedDataMapOfShapeInteger::Seek, "Seek returns pointer to Item by Key. Returns NULL if Key was not found.", py::arg("theKey1"));
	// FIXME cls_BOPCol_IndexedDataMapOfShapeInteger.def("ChangeSeek", (Standard_Integer * (BOPCol_IndexedDataMapOfShapeInteger::*)(const TopoDS_Shape &)) &BOPCol_IndexedDataMapOfShapeInteger::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL if Key was not found.", py::arg("theKey1"));
	cls_BOPCol_IndexedDataMapOfShapeInteger.def("FindFromKey", (Standard_Boolean (BOPCol_IndexedDataMapOfShapeInteger::*)(const TopoDS_Shape &, Standard_Integer &) const ) &BOPCol_IndexedDataMapOfShapeInteger::FindFromKey, "Find value for key with copying.", py::arg("theKey1"), py::arg("theValue"));
	cls_BOPCol_IndexedDataMapOfShapeInteger.def("Clear", [](BOPCol_IndexedDataMapOfShapeInteger &self) -> void { return self.Clear(); });
	cls_BOPCol_IndexedDataMapOfShapeInteger.def("Clear", (void (BOPCol_IndexedDataMapOfShapeInteger::*)(const Standard_Boolean)) &BOPCol_IndexedDataMapOfShapeInteger::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_BOPCol_IndexedDataMapOfShapeInteger.def("Clear", (void (BOPCol_IndexedDataMapOfShapeInteger::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &BOPCol_IndexedDataMapOfShapeInteger::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_BOPCol_IndexedDataMapOfShapeInteger.def("Size", (Standard_Integer (BOPCol_IndexedDataMapOfShapeInteger::*)() const ) &BOPCol_IndexedDataMapOfShapeInteger::Size, "Size");
	cls_BOPCol_IndexedDataMapOfShapeInteger.def("__iter__", [](const BOPCol_IndexedDataMapOfShapeInteger &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_IndexedDataMap.hxx
	py::class_<BOPCol_IndexedDataMapOfShapeReal, std::unique_ptr<BOPCol_IndexedDataMapOfShapeReal, Deleter<BOPCol_IndexedDataMapOfShapeReal>>, NCollection_BaseMap> cls_BOPCol_IndexedDataMapOfShapeReal(mod, "BOPCol_IndexedDataMapOfShapeReal", "Purpose: An indexed map is used to store keys and to bind an index to them. Each new key stored in the map gets an index. Index are incremented as keys are stored in the map. A key can be found by the index and an index by the key. No key but the last can be removed so the indices are in the range 1.. Extent. An Item is stored with each key.");
	cls_BOPCol_IndexedDataMapOfShapeReal.def(py::init<>());
	cls_BOPCol_IndexedDataMapOfShapeReal.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_BOPCol_IndexedDataMapOfShapeReal.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_BOPCol_IndexedDataMapOfShapeReal.def(py::init([] (const BOPCol_IndexedDataMapOfShapeReal &other) {return new BOPCol_IndexedDataMapOfShapeReal(other);}), "Copy constructor", py::arg("other"));
	cls_BOPCol_IndexedDataMapOfShapeReal.def("begin", (BOPCol_IndexedDataMapOfShapeReal::iterator (BOPCol_IndexedDataMapOfShapeReal::*)() const ) &BOPCol_IndexedDataMapOfShapeReal::begin, "Returns an iterator pointing to the first element in the map.");
	cls_BOPCol_IndexedDataMapOfShapeReal.def("end", (BOPCol_IndexedDataMapOfShapeReal::iterator (BOPCol_IndexedDataMapOfShapeReal::*)() const ) &BOPCol_IndexedDataMapOfShapeReal::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_BOPCol_IndexedDataMapOfShapeReal.def("cbegin", (BOPCol_IndexedDataMapOfShapeReal::const_iterator (BOPCol_IndexedDataMapOfShapeReal::*)() const ) &BOPCol_IndexedDataMapOfShapeReal::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_BOPCol_IndexedDataMapOfShapeReal.def("cend", (BOPCol_IndexedDataMapOfShapeReal::const_iterator (BOPCol_IndexedDataMapOfShapeReal::*)() const ) &BOPCol_IndexedDataMapOfShapeReal::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_BOPCol_IndexedDataMapOfShapeReal.def("Exchange", (void (BOPCol_IndexedDataMapOfShapeReal::*)(BOPCol_IndexedDataMapOfShapeReal &)) &BOPCol_IndexedDataMapOfShapeReal::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_BOPCol_IndexedDataMapOfShapeReal.def("Assign", (BOPCol_IndexedDataMapOfShapeReal & (BOPCol_IndexedDataMapOfShapeReal::*)(const BOPCol_IndexedDataMapOfShapeReal &)) &BOPCol_IndexedDataMapOfShapeReal::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_BOPCol_IndexedDataMapOfShapeReal.def("assign", (BOPCol_IndexedDataMapOfShapeReal & (BOPCol_IndexedDataMapOfShapeReal::*)(const BOPCol_IndexedDataMapOfShapeReal &)) &BOPCol_IndexedDataMapOfShapeReal::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_BOPCol_IndexedDataMapOfShapeReal.def("ReSize", (void (BOPCol_IndexedDataMapOfShapeReal::*)(const Standard_Integer)) &BOPCol_IndexedDataMapOfShapeReal::ReSize, "ReSize", py::arg("N"));
	cls_BOPCol_IndexedDataMapOfShapeReal.def("Add", (Standard_Integer (BOPCol_IndexedDataMapOfShapeReal::*)(const TopoDS_Shape &, const Standard_Real &)) &BOPCol_IndexedDataMapOfShapeReal::Add, "Add", py::arg("theKey1"), py::arg("theItem"));
	cls_BOPCol_IndexedDataMapOfShapeReal.def("Contains", (Standard_Boolean (BOPCol_IndexedDataMapOfShapeReal::*)(const TopoDS_Shape &) const ) &BOPCol_IndexedDataMapOfShapeReal::Contains, "Contains", py::arg("theKey1"));
	cls_BOPCol_IndexedDataMapOfShapeReal.def("Substitute", (void (BOPCol_IndexedDataMapOfShapeReal::*)(const Standard_Integer, const TopoDS_Shape &, const Standard_Real &)) &BOPCol_IndexedDataMapOfShapeReal::Substitute, "Substitute", py::arg("theIndex"), py::arg("theKey1"), py::arg("theItem"));
	cls_BOPCol_IndexedDataMapOfShapeReal.def("Swap", (void (BOPCol_IndexedDataMapOfShapeReal::*)(const Standard_Integer, const Standard_Integer)) &BOPCol_IndexedDataMapOfShapeReal::Swap, "Swaps two elements with the given indices.", py::arg("theIndex1"), py::arg("theIndex2"));
	cls_BOPCol_IndexedDataMapOfShapeReal.def("RemoveLast", (void (BOPCol_IndexedDataMapOfShapeReal::*)()) &BOPCol_IndexedDataMapOfShapeReal::RemoveLast, "RemoveLast");
	cls_BOPCol_IndexedDataMapOfShapeReal.def("RemoveFromIndex", (void (BOPCol_IndexedDataMapOfShapeReal::*)(const Standard_Integer)) &BOPCol_IndexedDataMapOfShapeReal::RemoveFromIndex, "Remove the key of the given index. Caution! The index of the last key can be changed.", py::arg("theKey2"));
	cls_BOPCol_IndexedDataMapOfShapeReal.def("RemoveKey", (void (BOPCol_IndexedDataMapOfShapeReal::*)(const TopoDS_Shape &)) &BOPCol_IndexedDataMapOfShapeReal::RemoveKey, "Remove the given key. Caution! The index of the last key can be changed.", py::arg("theKey1"));
	cls_BOPCol_IndexedDataMapOfShapeReal.def("FindKey", (const TopoDS_Shape & (BOPCol_IndexedDataMapOfShapeReal::*)(const Standard_Integer) const ) &BOPCol_IndexedDataMapOfShapeReal::FindKey, "FindKey", py::arg("theKey2"));
	cls_BOPCol_IndexedDataMapOfShapeReal.def("FindFromIndex", (const Standard_Real & (BOPCol_IndexedDataMapOfShapeReal::*)(const Standard_Integer) const ) &BOPCol_IndexedDataMapOfShapeReal::FindFromIndex, "FindFromIndex", py::arg("theKey2"));
	cls_BOPCol_IndexedDataMapOfShapeReal.def("__call__", (const Standard_Real & (BOPCol_IndexedDataMapOfShapeReal::*)(const Standard_Integer) const ) &BOPCol_IndexedDataMapOfShapeReal::operator(), py::is_operator(), "operator ()", py::arg("theKey2"));
	cls_BOPCol_IndexedDataMapOfShapeReal.def("ChangeFromIndex", (Standard_Real & (BOPCol_IndexedDataMapOfShapeReal::*)(const Standard_Integer)) &BOPCol_IndexedDataMapOfShapeReal::ChangeFromIndex, "ChangeFromIndex", py::arg("theKey2"));
	cls_BOPCol_IndexedDataMapOfShapeReal.def("__call__", (Standard_Real & (BOPCol_IndexedDataMapOfShapeReal::*)(const Standard_Integer)) &BOPCol_IndexedDataMapOfShapeReal::operator(), py::is_operator(), "operator ()", py::arg("theKey2"));
	cls_BOPCol_IndexedDataMapOfShapeReal.def("FindIndex", (Standard_Integer (BOPCol_IndexedDataMapOfShapeReal::*)(const TopoDS_Shape &) const ) &BOPCol_IndexedDataMapOfShapeReal::FindIndex, "FindIndex", py::arg("theKey1"));
	cls_BOPCol_IndexedDataMapOfShapeReal.def("FindFromKey", (const Standard_Real & (BOPCol_IndexedDataMapOfShapeReal::*)(const TopoDS_Shape &) const ) &BOPCol_IndexedDataMapOfShapeReal::FindFromKey, "FindFromKey", py::arg("theKey1"));
	cls_BOPCol_IndexedDataMapOfShapeReal.def("ChangeFromKey", (Standard_Real & (BOPCol_IndexedDataMapOfShapeReal::*)(const TopoDS_Shape &)) &BOPCol_IndexedDataMapOfShapeReal::ChangeFromKey, "ChangeFromKey", py::arg("theKey1"));
	// FIXME cls_BOPCol_IndexedDataMapOfShapeReal.def("Seek", (const Standard_Real * (BOPCol_IndexedDataMapOfShapeReal::*)(const TopoDS_Shape &) const ) &BOPCol_IndexedDataMapOfShapeReal::Seek, "Seek returns pointer to Item by Key. Returns NULL if Key was not found.", py::arg("theKey1"));
	// FIXME cls_BOPCol_IndexedDataMapOfShapeReal.def("ChangeSeek", (Standard_Real * (BOPCol_IndexedDataMapOfShapeReal::*)(const TopoDS_Shape &)) &BOPCol_IndexedDataMapOfShapeReal::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL if Key was not found.", py::arg("theKey1"));
	cls_BOPCol_IndexedDataMapOfShapeReal.def("FindFromKey", (Standard_Boolean (BOPCol_IndexedDataMapOfShapeReal::*)(const TopoDS_Shape &, Standard_Real &) const ) &BOPCol_IndexedDataMapOfShapeReal::FindFromKey, "Find value for key with copying.", py::arg("theKey1"), py::arg("theValue"));
	cls_BOPCol_IndexedDataMapOfShapeReal.def("Clear", [](BOPCol_IndexedDataMapOfShapeReal &self) -> void { return self.Clear(); });
	cls_BOPCol_IndexedDataMapOfShapeReal.def("Clear", (void (BOPCol_IndexedDataMapOfShapeReal::*)(const Standard_Boolean)) &BOPCol_IndexedDataMapOfShapeReal::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_BOPCol_IndexedDataMapOfShapeReal.def("Clear", (void (BOPCol_IndexedDataMapOfShapeReal::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &BOPCol_IndexedDataMapOfShapeReal::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_BOPCol_IndexedDataMapOfShapeReal.def("Size", (Standard_Integer (BOPCol_IndexedDataMapOfShapeReal::*)() const ) &BOPCol_IndexedDataMapOfShapeReal::Size, "Size");
	cls_BOPCol_IndexedDataMapOfShapeReal.def("__iter__", [](const BOPCol_IndexedDataMapOfShapeReal &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_List.hxx
	py::class_<BOPCol_ListOfListOfShape, std::unique_ptr<BOPCol_ListOfListOfShape, Deleter<BOPCol_ListOfListOfShape>>, NCollection_BaseList> cls_BOPCol_ListOfListOfShape(mod, "BOPCol_ListOfListOfShape", "Purpose: Simple list to link items together keeping the first and the last one. Inherits BaseList, adding the data item to each node.");
	cls_BOPCol_ListOfListOfShape.def(py::init<>());
	cls_BOPCol_ListOfListOfShape.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_BOPCol_ListOfListOfShape.def(py::init([] (const BOPCol_ListOfListOfShape &other) {return new BOPCol_ListOfListOfShape(other);}), "Copy constructor", py::arg("other"));
	cls_BOPCol_ListOfListOfShape.def("begin", (BOPCol_ListOfListOfShape::iterator (BOPCol_ListOfListOfShape::*)() const ) &BOPCol_ListOfListOfShape::begin, "Returns an iterator pointing to the first element in the list.");
	cls_BOPCol_ListOfListOfShape.def("end", (BOPCol_ListOfListOfShape::iterator (BOPCol_ListOfListOfShape::*)() const ) &BOPCol_ListOfListOfShape::end, "Returns an iterator referring to the past-the-end element in the list.");
	cls_BOPCol_ListOfListOfShape.def("cbegin", (BOPCol_ListOfListOfShape::const_iterator (BOPCol_ListOfListOfShape::*)() const ) &BOPCol_ListOfListOfShape::cbegin, "Returns a const iterator pointing to the first element in the list.");
	cls_BOPCol_ListOfListOfShape.def("cend", (BOPCol_ListOfListOfShape::const_iterator (BOPCol_ListOfListOfShape::*)() const ) &BOPCol_ListOfListOfShape::cend, "Returns a const iterator referring to the past-the-end element in the list.");
	cls_BOPCol_ListOfListOfShape.def("Size", (Standard_Integer (BOPCol_ListOfListOfShape::*)() const ) &BOPCol_ListOfListOfShape::Size, "Size - Number of items");
	cls_BOPCol_ListOfListOfShape.def("Assign", (BOPCol_ListOfListOfShape & (BOPCol_ListOfListOfShape::*)(const BOPCol_ListOfListOfShape &)) &BOPCol_ListOfListOfShape::Assign, "Replace this list by the items of another list (theOther parameter). This method does not change the internal allocator.", py::arg("theOther"));
	cls_BOPCol_ListOfListOfShape.def("assign", (BOPCol_ListOfListOfShape & (BOPCol_ListOfListOfShape::*)(const BOPCol_ListOfListOfShape &)) &BOPCol_ListOfListOfShape::operator=, py::is_operator(), "Replacement operator", py::arg("theOther"));
	cls_BOPCol_ListOfListOfShape.def("Clear", [](BOPCol_ListOfListOfShape &self) -> void { return self.Clear(); });
	cls_BOPCol_ListOfListOfShape.def("Clear", (void (BOPCol_ListOfListOfShape::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &BOPCol_ListOfListOfShape::Clear, "Clear this list", py::arg("theAllocator"));
	cls_BOPCol_ListOfListOfShape.def("First", (const BOPCol_ListOfShape & (BOPCol_ListOfListOfShape::*)() const ) &BOPCol_ListOfListOfShape::First, "First item");
	cls_BOPCol_ListOfListOfShape.def("First", (BOPCol_ListOfShape & (BOPCol_ListOfListOfShape::*)()) &BOPCol_ListOfListOfShape::First, "First item (non-const)");
	cls_BOPCol_ListOfListOfShape.def("Last", (const BOPCol_ListOfShape & (BOPCol_ListOfListOfShape::*)() const ) &BOPCol_ListOfListOfShape::Last, "Last item");
	cls_BOPCol_ListOfListOfShape.def("Last", (BOPCol_ListOfShape & (BOPCol_ListOfListOfShape::*)()) &BOPCol_ListOfListOfShape::Last, "Last item (non-const)");
	cls_BOPCol_ListOfListOfShape.def("Append", (BOPCol_ListOfShape & (BOPCol_ListOfListOfShape::*)(const BOPCol_ListOfShape &)) &BOPCol_ListOfListOfShape::Append, "Append one item at the end", py::arg("theItem"));
	cls_BOPCol_ListOfListOfShape.def("Append", (void (BOPCol_ListOfListOfShape::*)(const BOPCol_ListOfShape &, BOPCol_ListOfListOfShape::Iterator &)) &BOPCol_ListOfListOfShape::Append, "Append one item at the end and output iterator pointing at the appended item", py::arg("theItem"), py::arg("theIter"));
	cls_BOPCol_ListOfListOfShape.def("Append", (void (BOPCol_ListOfListOfShape::*)(BOPCol_ListOfListOfShape &)) &BOPCol_ListOfListOfShape::Append, "Append another list at the end", py::arg("theOther"));
	cls_BOPCol_ListOfListOfShape.def("Prepend", (BOPCol_ListOfShape & (BOPCol_ListOfListOfShape::*)(const BOPCol_ListOfShape &)) &BOPCol_ListOfListOfShape::Prepend, "Prepend one item at the beginning", py::arg("theItem"));
	cls_BOPCol_ListOfListOfShape.def("Prepend", (void (BOPCol_ListOfListOfShape::*)(BOPCol_ListOfListOfShape &)) &BOPCol_ListOfListOfShape::Prepend, "Prepend another list at the beginning", py::arg("theOther"));
	cls_BOPCol_ListOfListOfShape.def("RemoveFirst", (void (BOPCol_ListOfListOfShape::*)()) &BOPCol_ListOfListOfShape::RemoveFirst, "RemoveFirst item");
	cls_BOPCol_ListOfListOfShape.def("Remove", (void (BOPCol_ListOfListOfShape::*)(BOPCol_ListOfListOfShape::Iterator &)) &BOPCol_ListOfListOfShape::Remove, "Remove item pointed by iterator theIter; theIter is then set to the next item", py::arg("theIter"));
	cls_BOPCol_ListOfListOfShape.def("InsertBefore", (BOPCol_ListOfShape & (BOPCol_ListOfListOfShape::*)(const BOPCol_ListOfShape &, BOPCol_ListOfListOfShape::Iterator &)) &BOPCol_ListOfListOfShape::InsertBefore, "InsertBefore", py::arg("theItem"), py::arg("theIter"));
	cls_BOPCol_ListOfListOfShape.def("InsertBefore", (void (BOPCol_ListOfListOfShape::*)(BOPCol_ListOfListOfShape &, BOPCol_ListOfListOfShape::Iterator &)) &BOPCol_ListOfListOfShape::InsertBefore, "InsertBefore", py::arg("theOther"), py::arg("theIter"));
	cls_BOPCol_ListOfListOfShape.def("InsertAfter", (BOPCol_ListOfShape & (BOPCol_ListOfListOfShape::*)(const BOPCol_ListOfShape &, BOPCol_ListOfListOfShape::Iterator &)) &BOPCol_ListOfListOfShape::InsertAfter, "InsertAfter", py::arg("theItem"), py::arg("theIter"));
	cls_BOPCol_ListOfListOfShape.def("InsertAfter", (void (BOPCol_ListOfListOfShape::*)(BOPCol_ListOfListOfShape &, BOPCol_ListOfListOfShape::Iterator &)) &BOPCol_ListOfListOfShape::InsertAfter, "InsertAfter", py::arg("theOther"), py::arg("theIter"));
	cls_BOPCol_ListOfListOfShape.def("Reverse", (void (BOPCol_ListOfListOfShape::*)()) &BOPCol_ListOfListOfShape::Reverse, "Reverse the list");
	cls_BOPCol_ListOfListOfShape.def("__iter__", [](const BOPCol_ListOfListOfShape &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_TListIterator.hxx
	py::class_<BOPCol_ListIteratorOfListOfListOfShape, std::unique_ptr<BOPCol_ListIteratorOfListOfListOfShape, Deleter<BOPCol_ListIteratorOfListOfListOfShape>>> cls_BOPCol_ListIteratorOfListOfListOfShape(mod, "BOPCol_ListIteratorOfListOfListOfShape", "Purpose: This Iterator class iterates on BaseList of TListNode and is instantiated in List/Set/Queue/Stack Remark: TListIterator is internal class");
	cls_BOPCol_ListIteratorOfListOfListOfShape.def(py::init<>());
	cls_BOPCol_ListIteratorOfListOfListOfShape.def(py::init<const NCollection_BaseList &>(), py::arg("theList"));
	cls_BOPCol_ListIteratorOfListOfListOfShape.def("More", (Standard_Boolean (BOPCol_ListIteratorOfListOfListOfShape::*)() const ) &BOPCol_ListIteratorOfListOfListOfShape::More, "Check end");
	cls_BOPCol_ListIteratorOfListOfListOfShape.def("Next", (void (BOPCol_ListIteratorOfListOfListOfShape::*)()) &BOPCol_ListIteratorOfListOfListOfShape::Next, "Make step");
	cls_BOPCol_ListIteratorOfListOfListOfShape.def("Value", (const NCollection_List<TopoDS_Shape> & (BOPCol_ListIteratorOfListOfListOfShape::*)() const ) &BOPCol_ListIteratorOfListOfListOfShape::Value, "Constant Value access");
	cls_BOPCol_ListIteratorOfListOfListOfShape.def("Value", (NCollection_List<TopoDS_Shape> & (BOPCol_ListIteratorOfListOfListOfShape::*)()) &BOPCol_ListIteratorOfListOfListOfShape::Value, "Non-const Value access");
	cls_BOPCol_ListIteratorOfListOfListOfShape.def("ChangeValue", (NCollection_List<TopoDS_Shape> & (BOPCol_ListIteratorOfListOfListOfShape::*)() const ) &BOPCol_ListIteratorOfListOfListOfShape::ChangeValue, "Non-const Value access");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<BOPCol_DataMapOfShapeAddress, std::unique_ptr<BOPCol_DataMapOfShapeAddress, Deleter<BOPCol_DataMapOfShapeAddress>>, NCollection_BaseMap> cls_BOPCol_DataMapOfShapeAddress(mod, "BOPCol_DataMapOfShapeAddress", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_BOPCol_DataMapOfShapeAddress.def(py::init<>());
	cls_BOPCol_DataMapOfShapeAddress.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_BOPCol_DataMapOfShapeAddress.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_BOPCol_DataMapOfShapeAddress.def(py::init([] (const BOPCol_DataMapOfShapeAddress &other) {return new BOPCol_DataMapOfShapeAddress(other);}), "Copy constructor", py::arg("other"));
	cls_BOPCol_DataMapOfShapeAddress.def("begin", (BOPCol_DataMapOfShapeAddress::iterator (BOPCol_DataMapOfShapeAddress::*)() const ) &BOPCol_DataMapOfShapeAddress::begin, "Returns an iterator pointing to the first element in the map.");
	cls_BOPCol_DataMapOfShapeAddress.def("end", (BOPCol_DataMapOfShapeAddress::iterator (BOPCol_DataMapOfShapeAddress::*)() const ) &BOPCol_DataMapOfShapeAddress::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_BOPCol_DataMapOfShapeAddress.def("cbegin", (BOPCol_DataMapOfShapeAddress::const_iterator (BOPCol_DataMapOfShapeAddress::*)() const ) &BOPCol_DataMapOfShapeAddress::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_BOPCol_DataMapOfShapeAddress.def("cend", (BOPCol_DataMapOfShapeAddress::const_iterator (BOPCol_DataMapOfShapeAddress::*)() const ) &BOPCol_DataMapOfShapeAddress::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_BOPCol_DataMapOfShapeAddress.def("Exchange", (void (BOPCol_DataMapOfShapeAddress::*)(BOPCol_DataMapOfShapeAddress &)) &BOPCol_DataMapOfShapeAddress::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_BOPCol_DataMapOfShapeAddress.def("Assign", (BOPCol_DataMapOfShapeAddress & (BOPCol_DataMapOfShapeAddress::*)(const BOPCol_DataMapOfShapeAddress &)) &BOPCol_DataMapOfShapeAddress::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_BOPCol_DataMapOfShapeAddress.def("assign", (BOPCol_DataMapOfShapeAddress & (BOPCol_DataMapOfShapeAddress::*)(const BOPCol_DataMapOfShapeAddress &)) &BOPCol_DataMapOfShapeAddress::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_BOPCol_DataMapOfShapeAddress.def("ReSize", (void (BOPCol_DataMapOfShapeAddress::*)(const Standard_Integer)) &BOPCol_DataMapOfShapeAddress::ReSize, "ReSize", py::arg("N"));
	cls_BOPCol_DataMapOfShapeAddress.def("Bind", (Standard_Boolean (BOPCol_DataMapOfShapeAddress::*)(const TopoDS_Shape &, const Standard_Address &)) &BOPCol_DataMapOfShapeAddress::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_BOPCol_DataMapOfShapeAddress.def("Bound", (Standard_Address * (BOPCol_DataMapOfShapeAddress::*)(const TopoDS_Shape &, const Standard_Address &)) &BOPCol_DataMapOfShapeAddress::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_BOPCol_DataMapOfShapeAddress.def("IsBound", (Standard_Boolean (BOPCol_DataMapOfShapeAddress::*)(const TopoDS_Shape &) const ) &BOPCol_DataMapOfShapeAddress::IsBound, "IsBound", py::arg("theKey"));
	cls_BOPCol_DataMapOfShapeAddress.def("UnBind", (Standard_Boolean (BOPCol_DataMapOfShapeAddress::*)(const TopoDS_Shape &)) &BOPCol_DataMapOfShapeAddress::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_BOPCol_DataMapOfShapeAddress.def("Seek", (const Standard_Address * (BOPCol_DataMapOfShapeAddress::*)(const TopoDS_Shape &) const ) &BOPCol_DataMapOfShapeAddress::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_BOPCol_DataMapOfShapeAddress.def("Find", (const Standard_Address & (BOPCol_DataMapOfShapeAddress::*)(const TopoDS_Shape &) const ) &BOPCol_DataMapOfShapeAddress::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_BOPCol_DataMapOfShapeAddress.def("Find", (Standard_Boolean (BOPCol_DataMapOfShapeAddress::*)(const TopoDS_Shape &, Standard_Address &) const ) &BOPCol_DataMapOfShapeAddress::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_BOPCol_DataMapOfShapeAddress.def("__call__", (const Standard_Address & (BOPCol_DataMapOfShapeAddress::*)(const TopoDS_Shape &) const ) &BOPCol_DataMapOfShapeAddress::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_BOPCol_DataMapOfShapeAddress.def("ChangeSeek", (Standard_Address * (BOPCol_DataMapOfShapeAddress::*)(const TopoDS_Shape &)) &BOPCol_DataMapOfShapeAddress::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_BOPCol_DataMapOfShapeAddress.def("ChangeFind", (Standard_Address & (BOPCol_DataMapOfShapeAddress::*)(const TopoDS_Shape &)) &BOPCol_DataMapOfShapeAddress::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_BOPCol_DataMapOfShapeAddress.def("__call__", (Standard_Address & (BOPCol_DataMapOfShapeAddress::*)(const TopoDS_Shape &)) &BOPCol_DataMapOfShapeAddress::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_BOPCol_DataMapOfShapeAddress.def("Clear", [](BOPCol_DataMapOfShapeAddress &self) -> void { return self.Clear(); });
	cls_BOPCol_DataMapOfShapeAddress.def("Clear", (void (BOPCol_DataMapOfShapeAddress::*)(const Standard_Boolean)) &BOPCol_DataMapOfShapeAddress::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_BOPCol_DataMapOfShapeAddress.def("Clear", (void (BOPCol_DataMapOfShapeAddress::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &BOPCol_DataMapOfShapeAddress::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_BOPCol_DataMapOfShapeAddress.def("Size", (Standard_Integer (BOPCol_DataMapOfShapeAddress::*)() const ) &BOPCol_DataMapOfShapeAddress::Size, "Size");
	cls_BOPCol_DataMapOfShapeAddress.def("__iter__", [](const BOPCol_DataMapOfShapeAddress &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_DataMapOfShapeAddress.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<BOPCol_DataMapOfTransientAddress, std::unique_ptr<BOPCol_DataMapOfTransientAddress, Deleter<BOPCol_DataMapOfTransientAddress>>, NCollection_BaseMap> cls_BOPCol_DataMapOfTransientAddress(mod, "BOPCol_DataMapOfTransientAddress", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_BOPCol_DataMapOfTransientAddress.def(py::init<>());
	cls_BOPCol_DataMapOfTransientAddress.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_BOPCol_DataMapOfTransientAddress.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_BOPCol_DataMapOfTransientAddress.def(py::init([] (const BOPCol_DataMapOfTransientAddress &other) {return new BOPCol_DataMapOfTransientAddress(other);}), "Copy constructor", py::arg("other"));
	cls_BOPCol_DataMapOfTransientAddress.def("begin", (BOPCol_DataMapOfTransientAddress::iterator (BOPCol_DataMapOfTransientAddress::*)() const ) &BOPCol_DataMapOfTransientAddress::begin, "Returns an iterator pointing to the first element in the map.");
	cls_BOPCol_DataMapOfTransientAddress.def("end", (BOPCol_DataMapOfTransientAddress::iterator (BOPCol_DataMapOfTransientAddress::*)() const ) &BOPCol_DataMapOfTransientAddress::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_BOPCol_DataMapOfTransientAddress.def("cbegin", (BOPCol_DataMapOfTransientAddress::const_iterator (BOPCol_DataMapOfTransientAddress::*)() const ) &BOPCol_DataMapOfTransientAddress::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_BOPCol_DataMapOfTransientAddress.def("cend", (BOPCol_DataMapOfTransientAddress::const_iterator (BOPCol_DataMapOfTransientAddress::*)() const ) &BOPCol_DataMapOfTransientAddress::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_BOPCol_DataMapOfTransientAddress.def("Exchange", (void (BOPCol_DataMapOfTransientAddress::*)(BOPCol_DataMapOfTransientAddress &)) &BOPCol_DataMapOfTransientAddress::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_BOPCol_DataMapOfTransientAddress.def("Assign", (BOPCol_DataMapOfTransientAddress & (BOPCol_DataMapOfTransientAddress::*)(const BOPCol_DataMapOfTransientAddress &)) &BOPCol_DataMapOfTransientAddress::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_BOPCol_DataMapOfTransientAddress.def("assign", (BOPCol_DataMapOfTransientAddress & (BOPCol_DataMapOfTransientAddress::*)(const BOPCol_DataMapOfTransientAddress &)) &BOPCol_DataMapOfTransientAddress::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_BOPCol_DataMapOfTransientAddress.def("ReSize", (void (BOPCol_DataMapOfTransientAddress::*)(const Standard_Integer)) &BOPCol_DataMapOfTransientAddress::ReSize, "ReSize", py::arg("N"));
	cls_BOPCol_DataMapOfTransientAddress.def("Bind", (Standard_Boolean (BOPCol_DataMapOfTransientAddress::*)(const opencascade::handle<Standard_Transient> &, const Standard_Address &)) &BOPCol_DataMapOfTransientAddress::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_BOPCol_DataMapOfTransientAddress.def("Bound", (Standard_Address * (BOPCol_DataMapOfTransientAddress::*)(const opencascade::handle<Standard_Transient> &, const Standard_Address &)) &BOPCol_DataMapOfTransientAddress::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_BOPCol_DataMapOfTransientAddress.def("IsBound", (Standard_Boolean (BOPCol_DataMapOfTransientAddress::*)(const opencascade::handle<Standard_Transient> &) const ) &BOPCol_DataMapOfTransientAddress::IsBound, "IsBound", py::arg("theKey"));
	cls_BOPCol_DataMapOfTransientAddress.def("UnBind", (Standard_Boolean (BOPCol_DataMapOfTransientAddress::*)(const opencascade::handle<Standard_Transient> &)) &BOPCol_DataMapOfTransientAddress::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_BOPCol_DataMapOfTransientAddress.def("Seek", (const Standard_Address * (BOPCol_DataMapOfTransientAddress::*)(const opencascade::handle<Standard_Transient> &) const ) &BOPCol_DataMapOfTransientAddress::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_BOPCol_DataMapOfTransientAddress.def("Find", (const Standard_Address & (BOPCol_DataMapOfTransientAddress::*)(const opencascade::handle<Standard_Transient> &) const ) &BOPCol_DataMapOfTransientAddress::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_BOPCol_DataMapOfTransientAddress.def("Find", (Standard_Boolean (BOPCol_DataMapOfTransientAddress::*)(const opencascade::handle<Standard_Transient> &, Standard_Address &) const ) &BOPCol_DataMapOfTransientAddress::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_BOPCol_DataMapOfTransientAddress.def("__call__", (const Standard_Address & (BOPCol_DataMapOfTransientAddress::*)(const opencascade::handle<Standard_Transient> &) const ) &BOPCol_DataMapOfTransientAddress::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_BOPCol_DataMapOfTransientAddress.def("ChangeSeek", (Standard_Address * (BOPCol_DataMapOfTransientAddress::*)(const opencascade::handle<Standard_Transient> &)) &BOPCol_DataMapOfTransientAddress::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_BOPCol_DataMapOfTransientAddress.def("ChangeFind", (Standard_Address & (BOPCol_DataMapOfTransientAddress::*)(const opencascade::handle<Standard_Transient> &)) &BOPCol_DataMapOfTransientAddress::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_BOPCol_DataMapOfTransientAddress.def("__call__", (Standard_Address & (BOPCol_DataMapOfTransientAddress::*)(const opencascade::handle<Standard_Transient> &)) &BOPCol_DataMapOfTransientAddress::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_BOPCol_DataMapOfTransientAddress.def("Clear", [](BOPCol_DataMapOfTransientAddress &self) -> void { return self.Clear(); });
	cls_BOPCol_DataMapOfTransientAddress.def("Clear", (void (BOPCol_DataMapOfTransientAddress::*)(const Standard_Boolean)) &BOPCol_DataMapOfTransientAddress::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_BOPCol_DataMapOfTransientAddress.def("Clear", (void (BOPCol_DataMapOfTransientAddress::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &BOPCol_DataMapOfTransientAddress::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_BOPCol_DataMapOfTransientAddress.def("Size", (Standard_Integer (BOPCol_DataMapOfTransientAddress::*)() const ) &BOPCol_DataMapOfTransientAddress::Size, "Size");
	cls_BOPCol_DataMapOfTransientAddress.def("__iter__", [](const BOPCol_DataMapOfTransientAddress &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_DataMapOfTransientAddress.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_UBTree.hxx
	py::class_<BOPCol_Box2DBndTree, std::unique_ptr<BOPCol_Box2DBndTree, Deleter<BOPCol_Box2DBndTree>>> cls_BOPCol_Box2DBndTree(mod, "BOPCol_Box2DBndTree", "The algorithm of unbalanced binary tree of overlapped bounding boxes.");
	cls_BOPCol_Box2DBndTree.def(py::init<>());
	cls_BOPCol_Box2DBndTree.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_BOPCol_Box2DBndTree.def("Add", (Standard_Boolean (BOPCol_Box2DBndTree::*)(const Standard_Integer &, const Bnd_Box2d &)) &BOPCol_Box2DBndTree::Add, "Update the tree with a new object and its bounding box.", py::arg("theObj"), py::arg("theBnd"));
	cls_BOPCol_Box2DBndTree.def("Select", (Standard_Integer (BOPCol_Box2DBndTree::*)(BOPCol_Box2DBndTree::Selector &) const ) &BOPCol_Box2DBndTree::Select, "Searches in the tree all objects conforming to the given selector. return Number of objects accepted", py::arg("theSelector"));
	cls_BOPCol_Box2DBndTree.def("Clear", [](BOPCol_Box2DBndTree &self) -> void { return self.Clear(); });
	cls_BOPCol_Box2DBndTree.def("Clear", (void (BOPCol_Box2DBndTree::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &BOPCol_Box2DBndTree::Clear, "Clears the contents of the tree.", py::arg("aNewAlloc"));
	cls_BOPCol_Box2DBndTree.def("IsEmpty", (Standard_Boolean (BOPCol_Box2DBndTree::*)() const ) &BOPCol_Box2DBndTree::IsEmpty, "None");
	cls_BOPCol_Box2DBndTree.def("Root", (const BOPCol_Box2DBndTree::TreeNode & (BOPCol_Box2DBndTree::*)() const ) &BOPCol_Box2DBndTree::Root, "Returns the root node of the tree");
	cls_BOPCol_Box2DBndTree.def("Allocator", (const opencascade::handle<NCollection_BaseAllocator> & (BOPCol_Box2DBndTree::*)() const ) &BOPCol_Box2DBndTree::Allocator, "Recommended to be used only in sub-classes.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_UBTree.hxx
	py::class_<BOPCol_BoxBndTree, std::unique_ptr<BOPCol_BoxBndTree, Deleter<BOPCol_BoxBndTree>>> cls_BOPCol_BoxBndTree(mod, "BOPCol_BoxBndTree", "The algorithm of unbalanced binary tree of overlapped bounding boxes.");
	cls_BOPCol_BoxBndTree.def(py::init<>());
	cls_BOPCol_BoxBndTree.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAllocator"));
	cls_BOPCol_BoxBndTree.def("Add", (Standard_Boolean (BOPCol_BoxBndTree::*)(const Standard_Integer &, const Bnd_Box &)) &BOPCol_BoxBndTree::Add, "Update the tree with a new object and its bounding box.", py::arg("theObj"), py::arg("theBnd"));
	cls_BOPCol_BoxBndTree.def("Select", (Standard_Integer (BOPCol_BoxBndTree::*)(BOPCol_BoxBndTree::Selector &) const ) &BOPCol_BoxBndTree::Select, "Searches in the tree all objects conforming to the given selector. return Number of objects accepted", py::arg("theSelector"));
	cls_BOPCol_BoxBndTree.def("Clear", [](BOPCol_BoxBndTree &self) -> void { return self.Clear(); });
	cls_BOPCol_BoxBndTree.def("Clear", (void (BOPCol_BoxBndTree::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &BOPCol_BoxBndTree::Clear, "Clears the contents of the tree.", py::arg("aNewAlloc"));
	cls_BOPCol_BoxBndTree.def("IsEmpty", (Standard_Boolean (BOPCol_BoxBndTree::*)() const ) &BOPCol_BoxBndTree::IsEmpty, "None");
	cls_BOPCol_BoxBndTree.def("Root", (const BOPCol_BoxBndTree::TreeNode & (BOPCol_BoxBndTree::*)() const ) &BOPCol_BoxBndTree::Root, "Returns the root node of the tree");
	cls_BOPCol_BoxBndTree.def("Allocator", (const opencascade::handle<NCollection_BaseAllocator> & (BOPCol_BoxBndTree::*)() const ) &BOPCol_BoxBndTree::Allocator, "Recommended to be used only in sub-classes.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_DataMap.hxx
	py::class_<BOPCol_DataMapOfIntegerMapOfInteger, std::unique_ptr<BOPCol_DataMapOfIntegerMapOfInteger, Deleter<BOPCol_DataMapOfIntegerMapOfInteger>>, NCollection_BaseMap> cls_BOPCol_DataMapOfIntegerMapOfInteger(mod, "BOPCol_DataMapOfIntegerMapOfInteger", "Purpose: The DataMap is a Map to store keys with associated Items. See Map from NCollection for a discussion about the number of buckets.");
	cls_BOPCol_DataMapOfIntegerMapOfInteger.def(py::init<>());
	cls_BOPCol_DataMapOfIntegerMapOfInteger.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_BOPCol_DataMapOfIntegerMapOfInteger.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_BOPCol_DataMapOfIntegerMapOfInteger.def(py::init([] (const BOPCol_DataMapOfIntegerMapOfInteger &other) {return new BOPCol_DataMapOfIntegerMapOfInteger(other);}), "Copy constructor", py::arg("other"));
	cls_BOPCol_DataMapOfIntegerMapOfInteger.def("begin", (BOPCol_DataMapOfIntegerMapOfInteger::iterator (BOPCol_DataMapOfIntegerMapOfInteger::*)() const ) &BOPCol_DataMapOfIntegerMapOfInteger::begin, "Returns an iterator pointing to the first element in the map.");
	cls_BOPCol_DataMapOfIntegerMapOfInteger.def("end", (BOPCol_DataMapOfIntegerMapOfInteger::iterator (BOPCol_DataMapOfIntegerMapOfInteger::*)() const ) &BOPCol_DataMapOfIntegerMapOfInteger::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_BOPCol_DataMapOfIntegerMapOfInteger.def("cbegin", (BOPCol_DataMapOfIntegerMapOfInteger::const_iterator (BOPCol_DataMapOfIntegerMapOfInteger::*)() const ) &BOPCol_DataMapOfIntegerMapOfInteger::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_BOPCol_DataMapOfIntegerMapOfInteger.def("cend", (BOPCol_DataMapOfIntegerMapOfInteger::const_iterator (BOPCol_DataMapOfIntegerMapOfInteger::*)() const ) &BOPCol_DataMapOfIntegerMapOfInteger::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_BOPCol_DataMapOfIntegerMapOfInteger.def("Exchange", (void (BOPCol_DataMapOfIntegerMapOfInteger::*)(BOPCol_DataMapOfIntegerMapOfInteger &)) &BOPCol_DataMapOfIntegerMapOfInteger::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_BOPCol_DataMapOfIntegerMapOfInteger.def("Assign", (BOPCol_DataMapOfIntegerMapOfInteger & (BOPCol_DataMapOfIntegerMapOfInteger::*)(const BOPCol_DataMapOfIntegerMapOfInteger &)) &BOPCol_DataMapOfIntegerMapOfInteger::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_BOPCol_DataMapOfIntegerMapOfInteger.def("assign", (BOPCol_DataMapOfIntegerMapOfInteger & (BOPCol_DataMapOfIntegerMapOfInteger::*)(const BOPCol_DataMapOfIntegerMapOfInteger &)) &BOPCol_DataMapOfIntegerMapOfInteger::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_BOPCol_DataMapOfIntegerMapOfInteger.def("ReSize", (void (BOPCol_DataMapOfIntegerMapOfInteger::*)(const Standard_Integer)) &BOPCol_DataMapOfIntegerMapOfInteger::ReSize, "ReSize", py::arg("N"));
	cls_BOPCol_DataMapOfIntegerMapOfInteger.def("Bind", (Standard_Boolean (BOPCol_DataMapOfIntegerMapOfInteger::*)(const Standard_Integer &, const BOPCol_MapOfInteger &)) &BOPCol_DataMapOfIntegerMapOfInteger::Bind, "Bind binds Item to Key in map. Returns Standard_True if Key was not exist in the map. If the Key was already bound, the Item will be rebinded and Standard_False will be returned.", py::arg("theKey"), py::arg("theItem"));
	// FIXME cls_BOPCol_DataMapOfIntegerMapOfInteger.def("Bound", (BOPCol_MapOfInteger * (BOPCol_DataMapOfIntegerMapOfInteger::*)(const Standard_Integer &, const BOPCol_MapOfInteger &)) &BOPCol_DataMapOfIntegerMapOfInteger::Bound, "Bound binds Item to Key in map. Returns modifiable Item", py::arg("theKey"), py::arg("theItem"));
	cls_BOPCol_DataMapOfIntegerMapOfInteger.def("IsBound", (Standard_Boolean (BOPCol_DataMapOfIntegerMapOfInteger::*)(const Standard_Integer &) const ) &BOPCol_DataMapOfIntegerMapOfInteger::IsBound, "IsBound", py::arg("theKey"));
	cls_BOPCol_DataMapOfIntegerMapOfInteger.def("UnBind", (Standard_Boolean (BOPCol_DataMapOfIntegerMapOfInteger::*)(const Standard_Integer &)) &BOPCol_DataMapOfIntegerMapOfInteger::UnBind, "UnBind removes Item Key pair from map", py::arg("theKey"));
	// FIXME cls_BOPCol_DataMapOfIntegerMapOfInteger.def("Seek", (const BOPCol_MapOfInteger * (BOPCol_DataMapOfIntegerMapOfInteger::*)(const Standard_Integer &) const ) &BOPCol_DataMapOfIntegerMapOfInteger::Seek, "Seek returns pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	// FIXME cls_BOPCol_DataMapOfIntegerMapOfInteger.def("Find", (const BOPCol_MapOfInteger & (BOPCol_DataMapOfIntegerMapOfInteger::*)(const Standard_Integer &) const ) &BOPCol_DataMapOfIntegerMapOfInteger::Find, "Find returns the Item for Key. Raises if Key was not bound", py::arg("theKey"));
	// FIXME cls_BOPCol_DataMapOfIntegerMapOfInteger.def("Find", (Standard_Boolean (BOPCol_DataMapOfIntegerMapOfInteger::*)(const Standard_Integer &, BOPCol_MapOfInteger &) const ) &BOPCol_DataMapOfIntegerMapOfInteger::Find, "Find Item for key with copying.", py::arg("theKey"), py::arg("theValue"));
	cls_BOPCol_DataMapOfIntegerMapOfInteger.def("__call__", (const BOPCol_MapOfInteger & (BOPCol_DataMapOfIntegerMapOfInteger::*)(const Standard_Integer &) const ) &BOPCol_DataMapOfIntegerMapOfInteger::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	// FIXME cls_BOPCol_DataMapOfIntegerMapOfInteger.def("ChangeSeek", (BOPCol_MapOfInteger * (BOPCol_DataMapOfIntegerMapOfInteger::*)(const Standard_Integer &)) &BOPCol_DataMapOfIntegerMapOfInteger::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL is Key was not bound.", py::arg("theKey"));
	cls_BOPCol_DataMapOfIntegerMapOfInteger.def("ChangeFind", (BOPCol_MapOfInteger & (BOPCol_DataMapOfIntegerMapOfInteger::*)(const Standard_Integer &)) &BOPCol_DataMapOfIntegerMapOfInteger::ChangeFind, "ChangeFind returns mofifiable Item by Key. Raises if Key was not bound", py::arg("theKey"));
	cls_BOPCol_DataMapOfIntegerMapOfInteger.def("__call__", (BOPCol_MapOfInteger & (BOPCol_DataMapOfIntegerMapOfInteger::*)(const Standard_Integer &)) &BOPCol_DataMapOfIntegerMapOfInteger::operator(), py::is_operator(), "operator ()", py::arg("theKey"));
	cls_BOPCol_DataMapOfIntegerMapOfInteger.def("Clear", [](BOPCol_DataMapOfIntegerMapOfInteger &self) -> void { return self.Clear(); });
	cls_BOPCol_DataMapOfIntegerMapOfInteger.def("Clear", (void (BOPCol_DataMapOfIntegerMapOfInteger::*)(const Standard_Boolean)) &BOPCol_DataMapOfIntegerMapOfInteger::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_BOPCol_DataMapOfIntegerMapOfInteger.def("Clear", (void (BOPCol_DataMapOfIntegerMapOfInteger::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &BOPCol_DataMapOfIntegerMapOfInteger::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_BOPCol_DataMapOfIntegerMapOfInteger.def("Size", (Standard_Integer (BOPCol_DataMapOfIntegerMapOfInteger::*)() const ) &BOPCol_DataMapOfIntegerMapOfInteger::Size, "Size");
	cls_BOPCol_DataMapOfIntegerMapOfInteger.def("__iter__", [](const BOPCol_DataMapOfIntegerMapOfInteger &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_DataMapOfIntegerMapOfInteger.hxx
	other_mod = py::module::import("OCCT.TopTools");
	if (py::hasattr(other_mod, "TopTools_DataMapOfIntegerShape")) {
		mod.attr("BOPCol_DataMapOfIntegerShape") = other_mod.attr("TopTools_DataMapOfIntegerShape");
	}

	other_mod = py::module::import("OCCT.TopTools");
	if (py::hasattr(other_mod, "TopTools_DataMapIteratorOfDataMapOfIntegerShape")) {
		mod.attr("BOPCol_DataMapIteratorOfDataMapOfIntegerShape") = other_mod.attr("TopTools_DataMapIteratorOfDataMapOfIntegerShape");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_IndexedDataMap.hxx
	py::class_<BOPCol_IndexedDataMapOfIntegerListOfInteger, std::unique_ptr<BOPCol_IndexedDataMapOfIntegerListOfInteger, Deleter<BOPCol_IndexedDataMapOfIntegerListOfInteger>>, NCollection_BaseMap> cls_BOPCol_IndexedDataMapOfIntegerListOfInteger(mod, "BOPCol_IndexedDataMapOfIntegerListOfInteger", "Purpose: An indexed map is used to store keys and to bind an index to them. Each new key stored in the map gets an index. Index are incremented as keys are stored in the map. A key can be found by the index and an index by the key. No key but the last can be removed so the indices are in the range 1.. Extent. An Item is stored with each key.");
	cls_BOPCol_IndexedDataMapOfIntegerListOfInteger.def(py::init<>());
	cls_BOPCol_IndexedDataMapOfIntegerListOfInteger.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_BOPCol_IndexedDataMapOfIntegerListOfInteger.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_BOPCol_IndexedDataMapOfIntegerListOfInteger.def(py::init([] (const BOPCol_IndexedDataMapOfIntegerListOfInteger &other) {return new BOPCol_IndexedDataMapOfIntegerListOfInteger(other);}), "Copy constructor", py::arg("other"));
	cls_BOPCol_IndexedDataMapOfIntegerListOfInteger.def("begin", (BOPCol_IndexedDataMapOfIntegerListOfInteger::iterator (BOPCol_IndexedDataMapOfIntegerListOfInteger::*)() const ) &BOPCol_IndexedDataMapOfIntegerListOfInteger::begin, "Returns an iterator pointing to the first element in the map.");
	cls_BOPCol_IndexedDataMapOfIntegerListOfInteger.def("end", (BOPCol_IndexedDataMapOfIntegerListOfInteger::iterator (BOPCol_IndexedDataMapOfIntegerListOfInteger::*)() const ) &BOPCol_IndexedDataMapOfIntegerListOfInteger::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_BOPCol_IndexedDataMapOfIntegerListOfInteger.def("cbegin", (BOPCol_IndexedDataMapOfIntegerListOfInteger::const_iterator (BOPCol_IndexedDataMapOfIntegerListOfInteger::*)() const ) &BOPCol_IndexedDataMapOfIntegerListOfInteger::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_BOPCol_IndexedDataMapOfIntegerListOfInteger.def("cend", (BOPCol_IndexedDataMapOfIntegerListOfInteger::const_iterator (BOPCol_IndexedDataMapOfIntegerListOfInteger::*)() const ) &BOPCol_IndexedDataMapOfIntegerListOfInteger::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_BOPCol_IndexedDataMapOfIntegerListOfInteger.def("Exchange", (void (BOPCol_IndexedDataMapOfIntegerListOfInteger::*)(BOPCol_IndexedDataMapOfIntegerListOfInteger &)) &BOPCol_IndexedDataMapOfIntegerListOfInteger::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_BOPCol_IndexedDataMapOfIntegerListOfInteger.def("Assign", (BOPCol_IndexedDataMapOfIntegerListOfInteger & (BOPCol_IndexedDataMapOfIntegerListOfInteger::*)(const BOPCol_IndexedDataMapOfIntegerListOfInteger &)) &BOPCol_IndexedDataMapOfIntegerListOfInteger::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_BOPCol_IndexedDataMapOfIntegerListOfInteger.def("assign", (BOPCol_IndexedDataMapOfIntegerListOfInteger & (BOPCol_IndexedDataMapOfIntegerListOfInteger::*)(const BOPCol_IndexedDataMapOfIntegerListOfInteger &)) &BOPCol_IndexedDataMapOfIntegerListOfInteger::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_BOPCol_IndexedDataMapOfIntegerListOfInteger.def("ReSize", (void (BOPCol_IndexedDataMapOfIntegerListOfInteger::*)(const Standard_Integer)) &BOPCol_IndexedDataMapOfIntegerListOfInteger::ReSize, "ReSize", py::arg("N"));
	cls_BOPCol_IndexedDataMapOfIntegerListOfInteger.def("Add", (Standard_Integer (BOPCol_IndexedDataMapOfIntegerListOfInteger::*)(const Standard_Integer &, const BOPCol_ListOfInteger &)) &BOPCol_IndexedDataMapOfIntegerListOfInteger::Add, "Add", py::arg("theKey1"), py::arg("theItem"));
	cls_BOPCol_IndexedDataMapOfIntegerListOfInteger.def("Contains", (Standard_Boolean (BOPCol_IndexedDataMapOfIntegerListOfInteger::*)(const Standard_Integer &) const ) &BOPCol_IndexedDataMapOfIntegerListOfInteger::Contains, "Contains", py::arg("theKey1"));
	cls_BOPCol_IndexedDataMapOfIntegerListOfInteger.def("Substitute", (void (BOPCol_IndexedDataMapOfIntegerListOfInteger::*)(const Standard_Integer, const Standard_Integer &, const BOPCol_ListOfInteger &)) &BOPCol_IndexedDataMapOfIntegerListOfInteger::Substitute, "Substitute", py::arg("theIndex"), py::arg("theKey1"), py::arg("theItem"));
	cls_BOPCol_IndexedDataMapOfIntegerListOfInteger.def("Swap", (void (BOPCol_IndexedDataMapOfIntegerListOfInteger::*)(const Standard_Integer, const Standard_Integer)) &BOPCol_IndexedDataMapOfIntegerListOfInteger::Swap, "Swaps two elements with the given indices.", py::arg("theIndex1"), py::arg("theIndex2"));
	cls_BOPCol_IndexedDataMapOfIntegerListOfInteger.def("RemoveLast", (void (BOPCol_IndexedDataMapOfIntegerListOfInteger::*)()) &BOPCol_IndexedDataMapOfIntegerListOfInteger::RemoveLast, "RemoveLast");
	cls_BOPCol_IndexedDataMapOfIntegerListOfInteger.def("RemoveFromIndex", (void (BOPCol_IndexedDataMapOfIntegerListOfInteger::*)(const Standard_Integer)) &BOPCol_IndexedDataMapOfIntegerListOfInteger::RemoveFromIndex, "Remove the key of the given index. Caution! The index of the last key can be changed.", py::arg("theKey2"));
	cls_BOPCol_IndexedDataMapOfIntegerListOfInteger.def("RemoveKey", (void (BOPCol_IndexedDataMapOfIntegerListOfInteger::*)(const Standard_Integer &)) &BOPCol_IndexedDataMapOfIntegerListOfInteger::RemoveKey, "Remove the given key. Caution! The index of the last key can be changed.", py::arg("theKey1"));
	cls_BOPCol_IndexedDataMapOfIntegerListOfInteger.def("FindKey", (const Standard_Integer & (BOPCol_IndexedDataMapOfIntegerListOfInteger::*)(const Standard_Integer) const ) &BOPCol_IndexedDataMapOfIntegerListOfInteger::FindKey, "FindKey", py::arg("theKey2"));
	cls_BOPCol_IndexedDataMapOfIntegerListOfInteger.def("FindFromIndex", (const BOPCol_ListOfInteger & (BOPCol_IndexedDataMapOfIntegerListOfInteger::*)(const Standard_Integer) const ) &BOPCol_IndexedDataMapOfIntegerListOfInteger::FindFromIndex, "FindFromIndex", py::arg("theKey2"));
	cls_BOPCol_IndexedDataMapOfIntegerListOfInteger.def("__call__", (const BOPCol_ListOfInteger & (BOPCol_IndexedDataMapOfIntegerListOfInteger::*)(const Standard_Integer) const ) &BOPCol_IndexedDataMapOfIntegerListOfInteger::operator(), py::is_operator(), "operator ()", py::arg("theKey2"));
	cls_BOPCol_IndexedDataMapOfIntegerListOfInteger.def("ChangeFromIndex", (BOPCol_ListOfInteger & (BOPCol_IndexedDataMapOfIntegerListOfInteger::*)(const Standard_Integer)) &BOPCol_IndexedDataMapOfIntegerListOfInteger::ChangeFromIndex, "ChangeFromIndex", py::arg("theKey2"));
	cls_BOPCol_IndexedDataMapOfIntegerListOfInteger.def("__call__", (BOPCol_ListOfInteger & (BOPCol_IndexedDataMapOfIntegerListOfInteger::*)(const Standard_Integer)) &BOPCol_IndexedDataMapOfIntegerListOfInteger::operator(), py::is_operator(), "operator ()", py::arg("theKey2"));
	cls_BOPCol_IndexedDataMapOfIntegerListOfInteger.def("FindIndex", (Standard_Integer (BOPCol_IndexedDataMapOfIntegerListOfInteger::*)(const Standard_Integer &) const ) &BOPCol_IndexedDataMapOfIntegerListOfInteger::FindIndex, "FindIndex", py::arg("theKey1"));
	cls_BOPCol_IndexedDataMapOfIntegerListOfInteger.def("FindFromKey", (const BOPCol_ListOfInteger & (BOPCol_IndexedDataMapOfIntegerListOfInteger::*)(const Standard_Integer &) const ) &BOPCol_IndexedDataMapOfIntegerListOfInteger::FindFromKey, "FindFromKey", py::arg("theKey1"));
	cls_BOPCol_IndexedDataMapOfIntegerListOfInteger.def("ChangeFromKey", (BOPCol_ListOfInteger & (BOPCol_IndexedDataMapOfIntegerListOfInteger::*)(const Standard_Integer &)) &BOPCol_IndexedDataMapOfIntegerListOfInteger::ChangeFromKey, "ChangeFromKey", py::arg("theKey1"));
	// FIXME cls_BOPCol_IndexedDataMapOfIntegerListOfInteger.def("Seek", (const BOPCol_ListOfInteger * (BOPCol_IndexedDataMapOfIntegerListOfInteger::*)(const Standard_Integer &) const ) &BOPCol_IndexedDataMapOfIntegerListOfInteger::Seek, "Seek returns pointer to Item by Key. Returns NULL if Key was not found.", py::arg("theKey1"));
	// FIXME cls_BOPCol_IndexedDataMapOfIntegerListOfInteger.def("ChangeSeek", (BOPCol_ListOfInteger * (BOPCol_IndexedDataMapOfIntegerListOfInteger::*)(const Standard_Integer &)) &BOPCol_IndexedDataMapOfIntegerListOfInteger::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL if Key was not found.", py::arg("theKey1"));
	cls_BOPCol_IndexedDataMapOfIntegerListOfInteger.def("FindFromKey", (Standard_Boolean (BOPCol_IndexedDataMapOfIntegerListOfInteger::*)(const Standard_Integer &, BOPCol_ListOfInteger &) const ) &BOPCol_IndexedDataMapOfIntegerListOfInteger::FindFromKey, "Find value for key with copying.", py::arg("theKey1"), py::arg("theValue"));
	cls_BOPCol_IndexedDataMapOfIntegerListOfInteger.def("Clear", [](BOPCol_IndexedDataMapOfIntegerListOfInteger &self) -> void { return self.Clear(); });
	cls_BOPCol_IndexedDataMapOfIntegerListOfInteger.def("Clear", (void (BOPCol_IndexedDataMapOfIntegerListOfInteger::*)(const Standard_Boolean)) &BOPCol_IndexedDataMapOfIntegerListOfInteger::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_BOPCol_IndexedDataMapOfIntegerListOfInteger.def("Clear", (void (BOPCol_IndexedDataMapOfIntegerListOfInteger::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &BOPCol_IndexedDataMapOfIntegerListOfInteger::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_BOPCol_IndexedDataMapOfIntegerListOfInteger.def("Size", (Standard_Integer (BOPCol_IndexedDataMapOfIntegerListOfInteger::*)() const ) &BOPCol_IndexedDataMapOfIntegerListOfInteger::Size, "Size");
	cls_BOPCol_IndexedDataMapOfIntegerListOfInteger.def("__iter__", [](const BOPCol_IndexedDataMapOfIntegerListOfInteger &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_IndexedDataMap.hxx
	py::class_<BOPCol_IndexedDataMapOfShapeBox, std::unique_ptr<BOPCol_IndexedDataMapOfShapeBox, Deleter<BOPCol_IndexedDataMapOfShapeBox>>, NCollection_BaseMap> cls_BOPCol_IndexedDataMapOfShapeBox(mod, "BOPCol_IndexedDataMapOfShapeBox", "Purpose: An indexed map is used to store keys and to bind an index to them. Each new key stored in the map gets an index. Index are incremented as keys are stored in the map. A key can be found by the index and an index by the key. No key but the last can be removed so the indices are in the range 1.. Extent. An Item is stored with each key.");
	cls_BOPCol_IndexedDataMapOfShapeBox.def(py::init<>());
	cls_BOPCol_IndexedDataMapOfShapeBox.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_BOPCol_IndexedDataMapOfShapeBox.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_BOPCol_IndexedDataMapOfShapeBox.def(py::init([] (const BOPCol_IndexedDataMapOfShapeBox &other) {return new BOPCol_IndexedDataMapOfShapeBox(other);}), "Copy constructor", py::arg("other"));
	cls_BOPCol_IndexedDataMapOfShapeBox.def("begin", (BOPCol_IndexedDataMapOfShapeBox::iterator (BOPCol_IndexedDataMapOfShapeBox::*)() const ) &BOPCol_IndexedDataMapOfShapeBox::begin, "Returns an iterator pointing to the first element in the map.");
	cls_BOPCol_IndexedDataMapOfShapeBox.def("end", (BOPCol_IndexedDataMapOfShapeBox::iterator (BOPCol_IndexedDataMapOfShapeBox::*)() const ) &BOPCol_IndexedDataMapOfShapeBox::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_BOPCol_IndexedDataMapOfShapeBox.def("cbegin", (BOPCol_IndexedDataMapOfShapeBox::const_iterator (BOPCol_IndexedDataMapOfShapeBox::*)() const ) &BOPCol_IndexedDataMapOfShapeBox::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_BOPCol_IndexedDataMapOfShapeBox.def("cend", (BOPCol_IndexedDataMapOfShapeBox::const_iterator (BOPCol_IndexedDataMapOfShapeBox::*)() const ) &BOPCol_IndexedDataMapOfShapeBox::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_BOPCol_IndexedDataMapOfShapeBox.def("Exchange", (void (BOPCol_IndexedDataMapOfShapeBox::*)(BOPCol_IndexedDataMapOfShapeBox &)) &BOPCol_IndexedDataMapOfShapeBox::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_BOPCol_IndexedDataMapOfShapeBox.def("Assign", (BOPCol_IndexedDataMapOfShapeBox & (BOPCol_IndexedDataMapOfShapeBox::*)(const BOPCol_IndexedDataMapOfShapeBox &)) &BOPCol_IndexedDataMapOfShapeBox::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_BOPCol_IndexedDataMapOfShapeBox.def("assign", (BOPCol_IndexedDataMapOfShapeBox & (BOPCol_IndexedDataMapOfShapeBox::*)(const BOPCol_IndexedDataMapOfShapeBox &)) &BOPCol_IndexedDataMapOfShapeBox::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_BOPCol_IndexedDataMapOfShapeBox.def("ReSize", (void (BOPCol_IndexedDataMapOfShapeBox::*)(const Standard_Integer)) &BOPCol_IndexedDataMapOfShapeBox::ReSize, "ReSize", py::arg("N"));
	cls_BOPCol_IndexedDataMapOfShapeBox.def("Add", (Standard_Integer (BOPCol_IndexedDataMapOfShapeBox::*)(const TopoDS_Shape &, const Bnd_Box &)) &BOPCol_IndexedDataMapOfShapeBox::Add, "Add", py::arg("theKey1"), py::arg("theItem"));
	cls_BOPCol_IndexedDataMapOfShapeBox.def("Contains", (Standard_Boolean (BOPCol_IndexedDataMapOfShapeBox::*)(const TopoDS_Shape &) const ) &BOPCol_IndexedDataMapOfShapeBox::Contains, "Contains", py::arg("theKey1"));
	cls_BOPCol_IndexedDataMapOfShapeBox.def("Substitute", (void (BOPCol_IndexedDataMapOfShapeBox::*)(const Standard_Integer, const TopoDS_Shape &, const Bnd_Box &)) &BOPCol_IndexedDataMapOfShapeBox::Substitute, "Substitute", py::arg("theIndex"), py::arg("theKey1"), py::arg("theItem"));
	cls_BOPCol_IndexedDataMapOfShapeBox.def("Swap", (void (BOPCol_IndexedDataMapOfShapeBox::*)(const Standard_Integer, const Standard_Integer)) &BOPCol_IndexedDataMapOfShapeBox::Swap, "Swaps two elements with the given indices.", py::arg("theIndex1"), py::arg("theIndex2"));
	cls_BOPCol_IndexedDataMapOfShapeBox.def("RemoveLast", (void (BOPCol_IndexedDataMapOfShapeBox::*)()) &BOPCol_IndexedDataMapOfShapeBox::RemoveLast, "RemoveLast");
	cls_BOPCol_IndexedDataMapOfShapeBox.def("RemoveFromIndex", (void (BOPCol_IndexedDataMapOfShapeBox::*)(const Standard_Integer)) &BOPCol_IndexedDataMapOfShapeBox::RemoveFromIndex, "Remove the key of the given index. Caution! The index of the last key can be changed.", py::arg("theKey2"));
	cls_BOPCol_IndexedDataMapOfShapeBox.def("RemoveKey", (void (BOPCol_IndexedDataMapOfShapeBox::*)(const TopoDS_Shape &)) &BOPCol_IndexedDataMapOfShapeBox::RemoveKey, "Remove the given key. Caution! The index of the last key can be changed.", py::arg("theKey1"));
	cls_BOPCol_IndexedDataMapOfShapeBox.def("FindKey", (const TopoDS_Shape & (BOPCol_IndexedDataMapOfShapeBox::*)(const Standard_Integer) const ) &BOPCol_IndexedDataMapOfShapeBox::FindKey, "FindKey", py::arg("theKey2"));
	cls_BOPCol_IndexedDataMapOfShapeBox.def("FindFromIndex", (const Bnd_Box & (BOPCol_IndexedDataMapOfShapeBox::*)(const Standard_Integer) const ) &BOPCol_IndexedDataMapOfShapeBox::FindFromIndex, "FindFromIndex", py::arg("theKey2"));
	cls_BOPCol_IndexedDataMapOfShapeBox.def("__call__", (const Bnd_Box & (BOPCol_IndexedDataMapOfShapeBox::*)(const Standard_Integer) const ) &BOPCol_IndexedDataMapOfShapeBox::operator(), py::is_operator(), "operator ()", py::arg("theKey2"));
	cls_BOPCol_IndexedDataMapOfShapeBox.def("ChangeFromIndex", (Bnd_Box & (BOPCol_IndexedDataMapOfShapeBox::*)(const Standard_Integer)) &BOPCol_IndexedDataMapOfShapeBox::ChangeFromIndex, "ChangeFromIndex", py::arg("theKey2"));
	cls_BOPCol_IndexedDataMapOfShapeBox.def("__call__", (Bnd_Box & (BOPCol_IndexedDataMapOfShapeBox::*)(const Standard_Integer)) &BOPCol_IndexedDataMapOfShapeBox::operator(), py::is_operator(), "operator ()", py::arg("theKey2"));
	cls_BOPCol_IndexedDataMapOfShapeBox.def("FindIndex", (Standard_Integer (BOPCol_IndexedDataMapOfShapeBox::*)(const TopoDS_Shape &) const ) &BOPCol_IndexedDataMapOfShapeBox::FindIndex, "FindIndex", py::arg("theKey1"));
	cls_BOPCol_IndexedDataMapOfShapeBox.def("FindFromKey", (const Bnd_Box & (BOPCol_IndexedDataMapOfShapeBox::*)(const TopoDS_Shape &) const ) &BOPCol_IndexedDataMapOfShapeBox::FindFromKey, "FindFromKey", py::arg("theKey1"));
	cls_BOPCol_IndexedDataMapOfShapeBox.def("ChangeFromKey", (Bnd_Box & (BOPCol_IndexedDataMapOfShapeBox::*)(const TopoDS_Shape &)) &BOPCol_IndexedDataMapOfShapeBox::ChangeFromKey, "ChangeFromKey", py::arg("theKey1"));
	// FIXME cls_BOPCol_IndexedDataMapOfShapeBox.def("Seek", (const Bnd_Box * (BOPCol_IndexedDataMapOfShapeBox::*)(const TopoDS_Shape &) const ) &BOPCol_IndexedDataMapOfShapeBox::Seek, "Seek returns pointer to Item by Key. Returns NULL if Key was not found.", py::arg("theKey1"));
	// FIXME cls_BOPCol_IndexedDataMapOfShapeBox.def("ChangeSeek", (Bnd_Box * (BOPCol_IndexedDataMapOfShapeBox::*)(const TopoDS_Shape &)) &BOPCol_IndexedDataMapOfShapeBox::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL if Key was not found.", py::arg("theKey1"));
	cls_BOPCol_IndexedDataMapOfShapeBox.def("FindFromKey", (Standard_Boolean (BOPCol_IndexedDataMapOfShapeBox::*)(const TopoDS_Shape &, Bnd_Box &) const ) &BOPCol_IndexedDataMapOfShapeBox::FindFromKey, "Find value for key with copying.", py::arg("theKey1"), py::arg("theValue"));
	cls_BOPCol_IndexedDataMapOfShapeBox.def("Clear", [](BOPCol_IndexedDataMapOfShapeBox &self) -> void { return self.Clear(); });
	cls_BOPCol_IndexedDataMapOfShapeBox.def("Clear", (void (BOPCol_IndexedDataMapOfShapeBox::*)(const Standard_Boolean)) &BOPCol_IndexedDataMapOfShapeBox::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_BOPCol_IndexedDataMapOfShapeBox.def("Clear", (void (BOPCol_IndexedDataMapOfShapeBox::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &BOPCol_IndexedDataMapOfShapeBox::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_BOPCol_IndexedDataMapOfShapeBox.def("Size", (Standard_Integer (BOPCol_IndexedDataMapOfShapeBox::*)() const ) &BOPCol_IndexedDataMapOfShapeBox::Size, "Size");
	cls_BOPCol_IndexedDataMapOfShapeBox.def("__iter__", [](const BOPCol_IndexedDataMapOfShapeBox &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	other_mod = py::module::import("OCCT.TopTools");
	if (py::hasattr(other_mod, "TopTools_IndexedDataMapOfShapeShape")) {
		mod.attr("BOPCol_IndexedDataMapOfShapeShape") = other_mod.attr("TopTools_IndexedDataMapOfShapeShape");
	}

	other_mod = py::module::import("OCCT.TColStd");
	if (py::hasattr(other_mod, "TColStd_IndexedMapOfInteger")) {
		mod.attr("BOPCol_IndexedMapOfInteger") = other_mod.attr("TColStd_IndexedMapOfInteger");
	}

	other_mod = py::module::import("OCCT.TopTools");
	if (py::hasattr(other_mod, "TopTools_MapOfOrientedShape")) {
		mod.attr("BOPCol_MapOfOrientedShape") = other_mod.attr("TopTools_MapOfOrientedShape");
	}

	other_mod = py::module::import("OCCT.TopTools");
	if (py::hasattr(other_mod, "TopTools_MapIteratorOfMapOfOrientedShape")) {
		mod.attr("BOPCol_MapIteratorOfMapOfOrientedShape") = other_mod.attr("TopTools_MapIteratorOfMapOfOrientedShape");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_PInteger.hxx
	other_mod = py::module::import("OCCT.TColgp");
	if (py::hasattr(other_mod, "TColgp_SequenceOfPnt2d")) {
		mod.attr("BOPCol_SequenceOfPnt2d") = other_mod.attr("TColgp_SequenceOfPnt2d");
	}

	other_mod = py::module::import("OCCT.TColStd");
	if (py::hasattr(other_mod, "TColStd_SequenceOfReal")) {
		mod.attr("BOPCol_SequenceOfReal") = other_mod.attr("TColStd_SequenceOfReal");
	}

	other_mod = py::module::import("OCCT.TopTools");
	if (py::hasattr(other_mod, "TopTools_SequenceOfShape")) {
		mod.attr("BOPCol_SequenceOfShape") = other_mod.attr("TopTools_SequenceOfShape");
	}


}
