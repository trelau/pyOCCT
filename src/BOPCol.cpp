#include <pyOCCT_Common.hpp>

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
#include <ApproxInt_KnotTools.hxx>
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
#include <NCollection_Templates.hpp>

PYBIND11_MODULE(BOPCol, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.ApproxInt");
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

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_BaseAllocator.hxx
	other_mod = py::module::import("OCCT.IntSurf");
	if (py::hasattr(other_mod, "IntSurf_Allocator")) {
		mod.attr("BOPCol_BaseAllocator") = other_mod.attr("IntSurf_Allocator");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_ListOfShape.hxx
	other_mod = py::module::import("OCCT.TopoDS");
	if (py::hasattr(other_mod, "TopoDS_ListOfShape")) {
		mod.attr("BOPCol_ListOfShape") = other_mod.attr("TopoDS_ListOfShape");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_ListOfShape.hxx
	other_mod = py::module::import("OCCT.TopoDS");
	if (py::hasattr(other_mod, "TopoDS_ListIteratorOfListOfShape")) {
		mod.attr("BOPCol_ListIteratorOfListOfShape") = other_mod.attr("TopoDS_ListIteratorOfListOfShape");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_DataMapOfIntegerListOfShape.hxx
	other_mod = py::module::import("OCCT.TopTools");
	if (py::hasattr(other_mod, "TopTools_DataMapOfIntegerListOfShape")) {
		mod.attr("BOPCol_DataMapOfIntegerListOfShape") = other_mod.attr("TopTools_DataMapOfIntegerListOfShape");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_DataMapOfIntegerListOfShape.hxx
	other_mod = py::module::import("OCCT.TopTools");
	if (py::hasattr(other_mod, "TopTools_DataMapIteratorOfDataMapOfIntegerListOfShape")) {
		mod.attr("BOPCol_DataMapIteratorOfDataMapOfIntegerListOfShape") = other_mod.attr("TopTools_DataMapIteratorOfDataMapOfIntegerListOfShape");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_DataMapOfShapeReal.hxx
	other_mod = py::module::import("OCCT.TopTools");
	if (py::hasattr(other_mod, "TopTools_DataMapOfShapeReal")) {
		mod.attr("BOPCol_DataMapOfShapeReal") = other_mod.attr("TopTools_DataMapOfShapeReal");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_DataMapOfShapeReal.hxx
	other_mod = py::module::import("OCCT.TopTools");
	if (py::hasattr(other_mod, "TopTools_DataMapIteratorOfDataMapOfShapeReal")) {
		mod.attr("BOPCol_DataMapIteratorOfDataMapOfShapeReal") = other_mod.attr("TopTools_DataMapIteratorOfDataMapOfShapeReal");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_MapOfShape.hxx
	other_mod = py::module::import("OCCT.TopTools");
	if (py::hasattr(other_mod, "TopTools_MapOfShape")) {
		mod.attr("BOPCol_MapOfShape") = other_mod.attr("TopTools_MapOfShape");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_MapOfShape.hxx
	other_mod = py::module::import("OCCT.TopTools");
	if (py::hasattr(other_mod, "TopTools_MapIteratorOfMapOfShape")) {
		mod.attr("BOPCol_MapIteratorOfMapOfShape") = other_mod.attr("TopTools_MapIteratorOfMapOfShape");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_DataMapOfShapeListOfShape.hxx
	other_mod = py::module::import("OCCT.TopTools");
	if (py::hasattr(other_mod, "TopTools_DataMapOfShapeListOfShape")) {
		mod.attr("BOPCol_DataMapOfShapeListOfShape") = other_mod.attr("TopTools_DataMapOfShapeListOfShape");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_DataMapOfShapeListOfShape.hxx
	other_mod = py::module::import("OCCT.TopTools");
	if (py::hasattr(other_mod, "TopTools_DataMapIteratorOfDataMapOfShapeListOfShape")) {
		mod.attr("BOPCol_DataMapIteratorOfDataMapOfShapeListOfShape") = other_mod.attr("TopTools_DataMapIteratorOfDataMapOfShapeListOfShape");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_DataMapOfShapeShape.hxx
	other_mod = py::module::import("OCCT.TopTools");
	if (py::hasattr(other_mod, "TopTools_DataMapOfShapeShape")) {
		mod.attr("BOPCol_DataMapOfShapeShape") = other_mod.attr("TopTools_DataMapOfShapeShape");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_DataMapOfShapeShape.hxx
	other_mod = py::module::import("OCCT.TopTools");
	if (py::hasattr(other_mod, "TopTools_DataMapIteratorOfDataMapOfShapeShape")) {
		mod.attr("BOPCol_DataMapIteratorOfDataMapOfShapeShape") = other_mod.attr("TopTools_DataMapIteratorOfDataMapOfShapeShape");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_IndexedDataMapOfShapeListOfShape.hxx
	other_mod = py::module::import("OCCT.TopTools");
	if (py::hasattr(other_mod, "TopTools_IndexedDataMapOfShapeListOfShape")) {
		mod.attr("BOPCol_IndexedDataMapOfShapeListOfShape") = other_mod.attr("TopTools_IndexedDataMapOfShapeListOfShape");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_IndexedMapOfOrientedShape.hxx
	other_mod = py::module::import("OCCT.TopTools");
	if (py::hasattr(other_mod, "TopTools_IndexedMapOfOrientedShape")) {
		mod.attr("BOPCol_IndexedMapOfOrientedShape") = other_mod.attr("TopTools_IndexedMapOfOrientedShape");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_DataMapOfShapeInteger.hxx
	other_mod = py::module::import("OCCT.TopTools");
	if (py::hasattr(other_mod, "TopTools_DataMapOfShapeInteger")) {
		mod.attr("BOPCol_DataMapOfShapeInteger") = other_mod.attr("TopTools_DataMapOfShapeInteger");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_DataMapOfShapeInteger.hxx
	other_mod = py::module::import("OCCT.TopTools");
	if (py::hasattr(other_mod, "TopTools_DataMapIteratorOfDataMapOfShapeInteger")) {
		mod.attr("BOPCol_DataMapIteratorOfDataMapOfShapeInteger") = other_mod.attr("TopTools_DataMapIteratorOfDataMapOfShapeInteger");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_MapOfInteger.hxx
	other_mod = py::module::import("OCCT.TColStd");
	if (py::hasattr(other_mod, "TColStd_MapOfInteger")) {
		mod.attr("BOPCol_MapOfInteger") = other_mod.attr("TColStd_MapOfInteger");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_MapOfInteger.hxx
	other_mod = py::module::import("OCCT.TColStd");
	if (py::hasattr(other_mod, "TColStd_MapIteratorOfMapOfInteger")) {
		mod.attr("BOPCol_MapIteratorOfMapOfInteger") = other_mod.attr("TColStd_MapIteratorOfMapOfInteger");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_IndexedMapOfShape.hxx
	other_mod = py::module::import("OCCT.TopTools");
	if (py::hasattr(other_mod, "TopTools_IndexedMapOfShape")) {
		mod.attr("BOPCol_IndexedMapOfShape") = other_mod.attr("TopTools_IndexedMapOfShape");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_DataMapOfIntegerReal.hxx
	other_mod = py::module::import("OCCT.TColStd");
	if (py::hasattr(other_mod, "TColStd_DataMapOfIntegerReal")) {
		mod.attr("BOPCol_DataMapOfIntegerReal") = other_mod.attr("TColStd_DataMapOfIntegerReal");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_DataMapOfIntegerReal.hxx
	other_mod = py::module::import("OCCT.TColStd");
	if (py::hasattr(other_mod, "TColStd_DataMapIteratorOfDataMapOfIntegerReal")) {
		mod.attr("BOPCol_DataMapIteratorOfDataMapOfIntegerReal") = other_mod.attr("TColStd_DataMapIteratorOfDataMapOfIntegerReal");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_ListOfInteger.hxx
	other_mod = py::module::import("OCCT.TColStd");
	if (py::hasattr(other_mod, "TColStd_ListOfInteger")) {
		mod.attr("BOPCol_ListOfInteger") = other_mod.attr("TColStd_ListOfInteger");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_ListOfInteger.hxx
	other_mod = py::module::import("OCCT.TColStd");
	if (py::hasattr(other_mod, "TColStd_ListIteratorOfListOfInteger")) {
		mod.attr("BOPCol_ListIteratorOfListOfInteger") = other_mod.attr("TColStd_ListIteratorOfListOfInteger");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_ListOfInteger.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_DataMapOfIntegerInteger.hxx
	other_mod = py::module::import("OCCT.TColStd");
	if (py::hasattr(other_mod, "TColStd_DataMapOfIntegerInteger")) {
		mod.attr("BOPCol_DataMapOfIntegerInteger") = other_mod.attr("TColStd_DataMapOfIntegerInteger");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_DataMapOfIntegerInteger.hxx
	other_mod = py::module::import("OCCT.TColStd");
	if (py::hasattr(other_mod, "TColStd_DataMapIteratorOfDataMapOfIntegerInteger")) {
		mod.attr("BOPCol_DataMapIteratorOfDataMapOfIntegerInteger") = other_mod.attr("TColStd_DataMapIteratorOfDataMapOfIntegerInteger");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_DataMapOfIntegerListOfInteger.hxx
	other_mod = py::module::import("OCCT.TColStd");
	if (py::hasattr(other_mod, "TColStd_DataMapOfIntegerListOfInteger")) {
		mod.attr("BOPCol_DataMapOfIntegerListOfInteger") = other_mod.attr("TColStd_DataMapOfIntegerListOfInteger");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_DataMapOfIntegerListOfInteger.hxx
	other_mod = py::module::import("OCCT.TColStd");
	if (py::hasattr(other_mod, "TColStd_DataMapIteratorOfDataMapOfIntegerListOfInteger")) {
		mod.attr("BOPCol_DataMapIteratorOfDataMapOfIntegerListOfInteger") = other_mod.attr("TColStd_DataMapIteratorOfDataMapOfIntegerListOfInteger");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_IndexedDataMapOfShapeInteger.hxx
	bind_NCollection_IndexedDataMap<TopoDS_Shape, int, TopTools_ShapeMapHasher>(mod, "BOPCol_IndexedDataMapOfShapeInteger");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_IndexedDataMapOfShapeReal.hxx
	bind_NCollection_IndexedDataMap<TopoDS_Shape, double, TopTools_ShapeMapHasher>(mod, "BOPCol_IndexedDataMapOfShapeReal");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_ListOfListOfShape.hxx
	bind_NCollection_List<NCollection_List<TopoDS_Shape> >(mod, "BOPCol_ListOfListOfShape");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_ListOfListOfShape.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_DataMapOfShapeAddress.hxx
	bind_NCollection_DataMap<TopoDS_Shape, void *, TopTools_ShapeMapHasher>(mod, "BOPCol_DataMapOfShapeAddress");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_DataMapOfShapeAddress.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_DataMapOfTransientAddress.hxx
	bind_NCollection_DataMap<opencascade::handle<Standard_Transient>, void *, NCollection_DefaultHasher<opencascade::handle<Standard_Transient> > >(mod, "BOPCol_DataMapOfTransientAddress");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_DataMapOfTransientAddress.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_Box2DBndTree.hxx
	bind_NCollection_UBTree<int, Bnd_Box2d>(mod, "BOPCol_Box2DBndTree");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_BoxBndTree.hxx
	bind_NCollection_UBTree<int, Bnd_Box>(mod, "BOPCol_BoxBndTree");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_DataMapOfIntegerMapOfInteger.hxx
	bind_NCollection_DataMap<int, NCollection_Map<int, NCollection_DefaultHasher<int> >, NCollection_DefaultHasher<int> >(mod, "BOPCol_DataMapOfIntegerMapOfInteger");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_DataMapOfIntegerMapOfInteger.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_DataMapOfIntegerShape.hxx
	other_mod = py::module::import("OCCT.TopTools");
	if (py::hasattr(other_mod, "TopTools_DataMapOfIntegerShape")) {
		mod.attr("BOPCol_DataMapOfIntegerShape") = other_mod.attr("TopTools_DataMapOfIntegerShape");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_DataMapOfIntegerShape.hxx
	other_mod = py::module::import("OCCT.TopTools");
	if (py::hasattr(other_mod, "TopTools_DataMapIteratorOfDataMapOfIntegerShape")) {
		mod.attr("BOPCol_DataMapIteratorOfDataMapOfIntegerShape") = other_mod.attr("TopTools_DataMapIteratorOfDataMapOfIntegerShape");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_IndexedDataMapOfIntegerListOfInteger.hxx
	bind_NCollection_IndexedDataMap<int, NCollection_List<int>, NCollection_DefaultHasher<int> >(mod, "BOPCol_IndexedDataMapOfIntegerListOfInteger");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_IndexedDataMapOfShapeBox.hxx
	bind_NCollection_IndexedDataMap<TopoDS_Shape, Bnd_Box, TopTools_ShapeMapHasher>(mod, "BOPCol_IndexedDataMapOfShapeBox");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_IndexedDataMapOfShapeShape.hxx
	other_mod = py::module::import("OCCT.TopTools");
	if (py::hasattr(other_mod, "TopTools_IndexedDataMapOfShapeShape")) {
		mod.attr("BOPCol_IndexedDataMapOfShapeShape") = other_mod.attr("TopTools_IndexedDataMapOfShapeShape");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_IndexedMapOfInteger.hxx
	other_mod = py::module::import("OCCT.TColStd");
	if (py::hasattr(other_mod, "TColStd_IndexedMapOfInteger")) {
		mod.attr("BOPCol_IndexedMapOfInteger") = other_mod.attr("TColStd_IndexedMapOfInteger");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_MapOfOrientedShape.hxx
	other_mod = py::module::import("OCCT.TopTools");
	if (py::hasattr(other_mod, "TopTools_MapOfOrientedShape")) {
		mod.attr("BOPCol_MapOfOrientedShape") = other_mod.attr("TopTools_MapOfOrientedShape");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_MapOfOrientedShape.hxx
	other_mod = py::module::import("OCCT.TopTools");
	if (py::hasattr(other_mod, "TopTools_MapIteratorOfMapOfOrientedShape")) {
		mod.attr("BOPCol_MapIteratorOfMapOfOrientedShape") = other_mod.attr("TopTools_MapIteratorOfMapOfOrientedShape");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_PInteger.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_SequenceOfPnt2d.hxx
	other_mod = py::module::import("OCCT.TColgp");
	if (py::hasattr(other_mod, "TColgp_SequenceOfPnt2d")) {
		mod.attr("BOPCol_SequenceOfPnt2d") = other_mod.attr("TColgp_SequenceOfPnt2d");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_SequenceOfReal.hxx
	other_mod = py::module::import("OCCT.TColStd");
	if (py::hasattr(other_mod, "TColStd_SequenceOfReal")) {
		mod.attr("BOPCol_SequenceOfReal") = other_mod.attr("TColStd_SequenceOfReal");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\BOPCol_SequenceOfShape.hxx
	other_mod = py::module::import("OCCT.TopTools");
	if (py::hasattr(other_mod, "TopTools_SequenceOfShape")) {
		mod.attr("BOPCol_SequenceOfShape") = other_mod.attr("TopTools_SequenceOfShape");
	}


}
