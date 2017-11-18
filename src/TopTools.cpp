#include <pyOCCT_Common.hpp>

#include <NCollection_BaseList.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_List.hxx>
#include <Standard_TypeDef.hxx>
#include <TopTools_ListOfShape.hxx>
#include <NCollection_BaseMap.hxx>
#include <NCollection_DataMap.hxx>
#include <TopTools_DataMapOfIntegerListOfShape.hxx>
#include <TopoDS_Shape.hxx>
#include <TopTools_ShapeMapHasher.hxx>
#include <NCollection_Map.hxx>
#include <TopTools_MapOfShape.hxx>
#include <NCollection_IndexedMap.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <NCollection_IndexedDataMap.hxx>
#include <TopTools_IndexedDataMapOfShapeListOfShape.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <TopTools_DataMapOfShapeShape.hxx>
#include <TopTools_OrientedShapeMapHasher.hxx>
#include <TopTools_IndexedMapOfOrientedShape.hxx>
#include <TopTools_DataMapOfShapeInteger.hxx>
#include <TopTools_DataMapOfOrientedShapeInteger.hxx>
#include <TopTools_IndexedDataMapOfShapeShape.hxx>
#include <NCollection_BaseSequence.hxx>
#include <NCollection_Sequence.hxx>
#include <TopTools_SequenceOfShape.hxx>
#include <TopTools_DataMapOfShapeListOfInteger.hxx>
#include <NCollection_Array1.hxx>
#include <TopTools_Array1OfShape.hxx>
#include <Standard_Transient.hxx>
#include <Standard_Type.hxx>
#include <TopTools_HArray1OfShape.hxx>
#include <NCollection_Array2.hxx>
#include <TopTools_Array2OfShape.hxx>
#include <TopTools_HArray2OfShape.hxx>
#include <TopTools_DataMapOfIntegerShape.hxx>
#include <TopTools_DataMapOfShapeReal.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <Standard_Mutex.hxx>
#include <TopTools_MutexForShapeProvider.hxx>
#include <TopTools_HSequenceOfShape.hxx>
#include <TopLoc_Location.hxx>
#include <Standard_OStream.hxx>
#include <Standard_IStream.hxx>
#include <Message_ProgressIndicator.hxx>
#include <TopTools_LocationSet.hxx>
#include <TCollection_AsciiString.hxx>
#include <TopTools_ShapeSet.hxx>
#include <TopTools_Array1OfListOfShape.hxx>
#include <TopTools_HArray1OfListOfShape.hxx>
#include <TopTools_IndexedDataMapOfShapeAddress.hxx>
#include <TopTools.hxx>
#include <TopTools_DataMapOfOrientedShapeShape.hxx>
#include <TopTools_DataMapOfShapeSequenceOfShape.hxx>
#include <TopTools_LocationSetPtr.hxx>
#include <TopTools_MapOfOrientedShape.hxx>
#include <NCollection_Templates.hpp>

PYBIND11_MODULE(TopTools, mod) {

	// IMPORT
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.TopoDS");
	py::module::import("OCCT.TopAbs");
	py::module::import("OCCT.TopLoc");
	py::module::import("OCCT.Message");
	py::module::import("OCCT.TCollection");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\TopTools_ShapeMapHasher.hxx
	py::class_<TopTools_ShapeMapHasher, std::unique_ptr<TopTools_ShapeMapHasher, Deleter<TopTools_ShapeMapHasher>>> cls_TopTools_ShapeMapHasher(mod, "TopTools_ShapeMapHasher", "Hash tool, used for generating maps of shapes in topology.");
	cls_TopTools_ShapeMapHasher.def(py::init<>());
	cls_TopTools_ShapeMapHasher.def_static("HashCode_", (Standard_Integer (*)(const TopoDS_Shape &, const Standard_Integer)) &TopTools_ShapeMapHasher::HashCode, "Returns a HasCode value for the Key <K> in the range 0..Upper.", py::arg("S"), py::arg("Upper"));
	cls_TopTools_ShapeMapHasher.def_static("IsEqual_", (Standard_Boolean (*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopTools_ShapeMapHasher::IsEqual, "Returns True when the two keys are the same. Two same keys must have the same hashcode, the contrary is not necessary.", py::arg("S1"), py::arg("S2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopTools_OrientedShapeMapHasher.hxx
	py::class_<TopTools_OrientedShapeMapHasher, std::unique_ptr<TopTools_OrientedShapeMapHasher, Deleter<TopTools_OrientedShapeMapHasher>>> cls_TopTools_OrientedShapeMapHasher(mod, "TopTools_OrientedShapeMapHasher", "None");
	cls_TopTools_OrientedShapeMapHasher.def(py::init<>());
	cls_TopTools_OrientedShapeMapHasher.def_static("HashCode_", (Standard_Integer (*)(const TopoDS_Shape &, const Standard_Integer)) &TopTools_OrientedShapeMapHasher::HashCode, "Returns a HasCode value for the Key <K> in the range 0..Upper.", py::arg("S"), py::arg("Upper"));
	cls_TopTools_OrientedShapeMapHasher.def_static("IsEqual_", (Standard_Boolean (*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopTools_OrientedShapeMapHasher::IsEqual, "Returns True when the two keys are equal. Two same keys must have the same hashcode, the contrary is not necessary.", py::arg("S1"), py::arg("S2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopTools_Array1OfShape.hxx
	bind_NCollection_Array1<TopoDS_Shape>(mod, "TopTools_Array1OfShape");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopTools_Array2OfShape.hxx
	bind_NCollection_Array2<TopoDS_Shape>(mod, "TopTools_Array2OfShape");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopTools_MutexForShapeProvider.hxx
	py::class_<TopTools_MutexForShapeProvider, std::unique_ptr<TopTools_MutexForShapeProvider, Deleter<TopTools_MutexForShapeProvider>>> cls_TopTools_MutexForShapeProvider(mod, "TopTools_MutexForShapeProvider", "Class TopTools_MutexForShapeProvider This class is used to create and store mutexes associated with shapes.");
	cls_TopTools_MutexForShapeProvider.def(py::init<>());
	cls_TopTools_MutexForShapeProvider.def("CreateMutexesForSubShapes", (void (TopTools_MutexForShapeProvider::*)(const TopoDS_Shape &, const TopAbs_ShapeEnum)) &TopTools_MutexForShapeProvider::CreateMutexesForSubShapes, "Creates and associates mutexes with each sub-shape of type theType in theShape.", py::arg("theShape"), py::arg("theType"));
	cls_TopTools_MutexForShapeProvider.def("CreateMutexForShape", (void (TopTools_MutexForShapeProvider::*)(const TopoDS_Shape &)) &TopTools_MutexForShapeProvider::CreateMutexForShape, "Creates and associates mutex with theShape", py::arg("theShape"));
	cls_TopTools_MutexForShapeProvider.def("GetMutex", (Standard_Mutex * (TopTools_MutexForShapeProvider::*)(const TopoDS_Shape &) const ) &TopTools_MutexForShapeProvider::GetMutex, "Returns pointer to mutex associated with theShape. In case when mutex not found returns NULL.", py::arg("theShape"));
	cls_TopTools_MutexForShapeProvider.def("RemoveAllMutexes", (void (TopTools_MutexForShapeProvider::*)()) &TopTools_MutexForShapeProvider::RemoveAllMutexes, "Removes all mutexes");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopTools_SequenceOfShape.hxx
	bind_NCollection_Sequence<TopoDS_Shape>(mod, "TopTools_SequenceOfShape");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopTools_LocationSet.hxx
	py::class_<TopTools_LocationSet, std::unique_ptr<TopTools_LocationSet, Deleter<TopTools_LocationSet>>> cls_TopTools_LocationSet(mod, "TopTools_LocationSet", "The class LocationSet stores a set of location in a relocatable state.");
	cls_TopTools_LocationSet.def(py::init<>());
	cls_TopTools_LocationSet.def("Clear", (void (TopTools_LocationSet::*)()) &TopTools_LocationSet::Clear, "Clears the content of the set.");
	cls_TopTools_LocationSet.def("Add", (Standard_Integer (TopTools_LocationSet::*)(const TopLoc_Location &)) &TopTools_LocationSet::Add, "Incorporate a new Location in the set and returns its index.", py::arg("L"));
	cls_TopTools_LocationSet.def("Location", (const TopLoc_Location & (TopTools_LocationSet::*)(const Standard_Integer) const ) &TopTools_LocationSet::Location, "Returns the location of index <I>.", py::arg("I"));
	cls_TopTools_LocationSet.def("Index", (Standard_Integer (TopTools_LocationSet::*)(const TopLoc_Location &) const ) &TopTools_LocationSet::Index, "Returns the index of <L>.", py::arg("L"));
	// FIXME cls_TopTools_LocationSet.def("Dump", (void (TopTools_LocationSet::*)(Standard_OStream &) const ) &TopTools_LocationSet::Dump, "Dumps the content of me on the stream <OS>.", py::arg("OS"));
	cls_TopTools_LocationSet.def("Write", (void (TopTools_LocationSet::*)(Standard_OStream &) const ) &TopTools_LocationSet::Write, "Writes the content of me on the stream <OS> in a format that can be read back by Read.", py::arg("OS"));
	cls_TopTools_LocationSet.def("Read", (void (TopTools_LocationSet::*)(Standard_IStream &)) &TopTools_LocationSet::Read, "Reads the content of me from the stream <IS>. me is first cleared.", py::arg("IS"));
	cls_TopTools_LocationSet.def("SetProgress", (void (TopTools_LocationSet::*)(const opencascade::handle<Message_ProgressIndicator> &)) &TopTools_LocationSet::SetProgress, "None", py::arg("PR"));
	cls_TopTools_LocationSet.def("GetProgress", (opencascade::handle<Message_ProgressIndicator> (TopTools_LocationSet::*)() const ) &TopTools_LocationSet::GetProgress, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopTools_ShapeSet.hxx
	py::class_<TopTools_ShapeSet, std::unique_ptr<TopTools_ShapeSet, Deleter<TopTools_ShapeSet>>> cls_TopTools_ShapeSet(mod, "TopTools_ShapeSet", "A ShapeSets contains a Shape and all its sub-shapes and locations. It can be dump, write and read.");
	cls_TopTools_ShapeSet.def(py::init<>());
	cls_TopTools_ShapeSet.def("SetFormatNb", (void (TopTools_ShapeSet::*)(const Standard_Integer)) &TopTools_ShapeSet::SetFormatNb, "None", py::arg("theFormatNb"));
	cls_TopTools_ShapeSet.def("FormatNb", (Standard_Integer (TopTools_ShapeSet::*)() const ) &TopTools_ShapeSet::FormatNb, "two formats available for the moment: First: does not write CurveOnSurface UV Points into the file on reading calls Check() method. Second: stores CurveOnSurface UV Points. On reading format is recognized from Version string.");
	cls_TopTools_ShapeSet.def("Clear", (void (TopTools_ShapeSet::*)()) &TopTools_ShapeSet::Clear, "Clears the content of the set. This method can be redefined.");
	cls_TopTools_ShapeSet.def("Add", (Standard_Integer (TopTools_ShapeSet::*)(const TopoDS_Shape &)) &TopTools_ShapeSet::Add, "Stores <S> and its sub-shape. Returns the index of <S>. The method AddGeometry is called on each sub-shape.", py::arg("S"));
	cls_TopTools_ShapeSet.def("Shape", (const TopoDS_Shape & (TopTools_ShapeSet::*)(const Standard_Integer) const ) &TopTools_ShapeSet::Shape, "Returns the sub-shape of index <I>.", py::arg("I"));
	cls_TopTools_ShapeSet.def("Index", (Standard_Integer (TopTools_ShapeSet::*)(const TopoDS_Shape &) const ) &TopTools_ShapeSet::Index, "Returns the index of <S>.", py::arg("S"));
	cls_TopTools_ShapeSet.def("Locations", (const TopTools_LocationSet & (TopTools_ShapeSet::*)() const ) &TopTools_ShapeSet::Locations, "None");
	cls_TopTools_ShapeSet.def("ChangeLocations", (TopTools_LocationSet & (TopTools_ShapeSet::*)()) &TopTools_ShapeSet::ChangeLocations, "None");
	cls_TopTools_ShapeSet.def("DumpExtent", (Standard_OStream & (TopTools_ShapeSet::*)(Standard_OStream &) const ) &TopTools_ShapeSet::DumpExtent, "Dumps the number of objects in me on the stream <OS>. (Number of shapes of each type)", py::arg("OS"));
	cls_TopTools_ShapeSet.def("DumpExtent", (void (TopTools_ShapeSet::*)(TCollection_AsciiString &) const ) &TopTools_ShapeSet::DumpExtent, "Dumps the number of objects in me in the string S (Number of shapes of each type)", py::arg("S"));
	// FIXME cls_TopTools_ShapeSet.def("Dump", (void (TopTools_ShapeSet::*)(Standard_OStream &) const ) &TopTools_ShapeSet::Dump, "Dumps the content of me on the stream <OS>.", py::arg("OS"));
	cls_TopTools_ShapeSet.def("Write", (void (TopTools_ShapeSet::*)(Standard_OStream &)) &TopTools_ShapeSet::Write, "Writes the content of me on the stream <OS> in a format that can be read back by Read.", py::arg("OS"));
	cls_TopTools_ShapeSet.def("Read", (void (TopTools_ShapeSet::*)(Standard_IStream &)) &TopTools_ShapeSet::Read, "Reads the content of me from the stream <IS>. me is first cleared.", py::arg("IS"));
	// FIXME cls_TopTools_ShapeSet.def("Dump", (void (TopTools_ShapeSet::*)(const TopoDS_Shape &, Standard_OStream &) const ) &TopTools_ShapeSet::Dump, "Dumps on <OS> the shape <S>. Dumps the orientation, the index of the TShape and the index of the Location.", py::arg("S"), py::arg("OS"));
	cls_TopTools_ShapeSet.def("Write", (void (TopTools_ShapeSet::*)(const TopoDS_Shape &, Standard_OStream &) const ) &TopTools_ShapeSet::Write, "Writes on <OS> the shape <S>. Writes the orientation, the index of the TShape and the index of the Location.", py::arg("S"), py::arg("OS"));
	cls_TopTools_ShapeSet.def("Read", (void (TopTools_ShapeSet::*)(TopoDS_Shape &, Standard_IStream &) const ) &TopTools_ShapeSet::Read, "Reads from <IS> a shape and returns it in S.", py::arg("S"), py::arg("IS"));
	cls_TopTools_ShapeSet.def("AddGeometry", (void (TopTools_ShapeSet::*)(const TopoDS_Shape &)) &TopTools_ShapeSet::AddGeometry, "Stores the geometry of <S>.", py::arg("S"));
	cls_TopTools_ShapeSet.def("DumpGeometry", (void (TopTools_ShapeSet::*)(Standard_OStream &) const ) &TopTools_ShapeSet::DumpGeometry, "Dumps the geometry of me on the stream <OS>.", py::arg("OS"));
	cls_TopTools_ShapeSet.def("WriteGeometry", (void (TopTools_ShapeSet::*)(Standard_OStream &)) &TopTools_ShapeSet::WriteGeometry, "Writes the geometry of me on the stream <OS> in a format that can be read back by Read.", py::arg("OS"));
	cls_TopTools_ShapeSet.def("ReadGeometry", (void (TopTools_ShapeSet::*)(Standard_IStream &)) &TopTools_ShapeSet::ReadGeometry, "Reads the geometry of me from the stream <IS>.", py::arg("IS"));
	cls_TopTools_ShapeSet.def("DumpGeometry", (void (TopTools_ShapeSet::*)(const TopoDS_Shape &, Standard_OStream &) const ) &TopTools_ShapeSet::DumpGeometry, "Dumps the geometry of <S> on the stream <OS>.", py::arg("S"), py::arg("OS"));
	cls_TopTools_ShapeSet.def("WriteGeometry", (void (TopTools_ShapeSet::*)(const TopoDS_Shape &, Standard_OStream &) const ) &TopTools_ShapeSet::WriteGeometry, "Writes the geometry of <S> on the stream <OS> in a format that can be read back by Read.", py::arg("S"), py::arg("OS"));
	cls_TopTools_ShapeSet.def("ReadGeometry", (void (TopTools_ShapeSet::*)(const TopAbs_ShapeEnum, Standard_IStream &, TopoDS_Shape &)) &TopTools_ShapeSet::ReadGeometry, "Reads the geometry of a shape of type <T> from the stream <IS> and returns it in <S>.", py::arg("T"), py::arg("IS"), py::arg("S"));
	cls_TopTools_ShapeSet.def("AddShapes", (void (TopTools_ShapeSet::*)(TopoDS_Shape &, const TopoDS_Shape &)) &TopTools_ShapeSet::AddShapes, "Inserts the shape <S2> in the shape <S1>. This method must be redefined to use the correct builder.", py::arg("S1"), py::arg("S2"));
	cls_TopTools_ShapeSet.def("Check", (void (TopTools_ShapeSet::*)(const TopAbs_ShapeEnum, TopoDS_Shape &)) &TopTools_ShapeSet::Check, "This method is called after each new completed shape. <T> is the type. <S> is the shape. In this class it does nothing, but it gives the opportunity in derived classes to perform extra treatment on shapes.", py::arg("T"), py::arg("S"));
	cls_TopTools_ShapeSet.def("NbShapes", (Standard_Integer (TopTools_ShapeSet::*)() const ) &TopTools_ShapeSet::NbShapes, "Returns number of shapes read from file.");
	cls_TopTools_ShapeSet.def("SetProgress", (void (TopTools_ShapeSet::*)(const opencascade::handle<Message_ProgressIndicator> &)) &TopTools_ShapeSet::SetProgress, "None", py::arg("PR"));
	cls_TopTools_ShapeSet.def("GetProgress", (opencascade::handle<Message_ProgressIndicator> (TopTools_ShapeSet::*)() const ) &TopTools_ShapeSet::GetProgress, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopTools_Array1OfListOfShape.hxx
	bind_NCollection_Array1<NCollection_List<TopoDS_Shape> >(mod, "TopTools_Array1OfListOfShape");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopTools.hxx
	py::class_<TopTools, std::unique_ptr<TopTools, Deleter<TopTools>>> cls_TopTools(mod, "TopTools", "The TopTools package provides utilities for the topological data structure.");
	cls_TopTools.def(py::init<>());
	// FIXME cls_TopTools.def_static("Dump_", (void (*)(const TopoDS_Shape &, Standard_OStream &)) &TopTools::Dump, "A set of Shapes. Can be dump, wrote or read. Dumps the topological structure of <Sh> on the stream <S>.", py::arg("Sh"), py::arg("S"));
	cls_TopTools.def_static("Dummy_", (void (*)(const Standard_Integer)) &TopTools::Dummy, "This is to bypass an extraction bug. It will force the inclusion of Standard_Integer.hxx itself including Standard_OStream.hxx at the correct position.", py::arg("I"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopTools_ListOfShape.hxx
	other_mod = py::module::import("OCCT.TopoDS");
	if (py::hasattr(other_mod, "TopoDS_ListOfShape")) {
		mod.attr("TopTools_ListOfShape") = other_mod.attr("TopoDS_ListOfShape");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopTools_ListOfShape.hxx
	other_mod = py::module::import("OCCT.TopoDS");
	if (py::hasattr(other_mod, "TopoDS_ListIteratorOfListOfShape")) {
		mod.attr("TopTools_ListIteratorOfListOfShape") = other_mod.attr("TopoDS_ListIteratorOfListOfShape");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopTools_DataMapOfIntegerListOfShape.hxx
	bind_NCollection_DataMap<int, NCollection_List<TopoDS_Shape>, NCollection_DefaultHasher<int> >(mod, "TopTools_DataMapOfIntegerListOfShape");

	/* FIXME

	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopTools_MapOfShape.hxx
	bind_NCollection_Map<TopoDS_Shape, TopTools_ShapeMapHasher>(mod, "TopTools_MapOfShape");

	/* FIXME

	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopTools_IndexedMapOfShape.hxx
	bind_NCollection_IndexedMap<TopoDS_Shape, TopTools_ShapeMapHasher>(mod, "TopTools_IndexedMapOfShape");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopTools_IndexedDataMapOfShapeListOfShape.hxx
	bind_NCollection_IndexedDataMap<TopoDS_Shape, NCollection_List<TopoDS_Shape>, TopTools_ShapeMapHasher>(mod, "TopTools_IndexedDataMapOfShapeListOfShape");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopTools_DataMapOfShapeListOfShape.hxx
	bind_NCollection_DataMap<TopoDS_Shape, NCollection_List<TopoDS_Shape>, TopTools_ShapeMapHasher>(mod, "TopTools_DataMapOfShapeListOfShape");

	/* FIXME

	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopTools_DataMapOfShapeShape.hxx
	bind_NCollection_DataMap<TopoDS_Shape, TopoDS_Shape, TopTools_ShapeMapHasher>(mod, "TopTools_DataMapOfShapeShape");

	/* FIXME

	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopTools_IndexedMapOfOrientedShape.hxx
	bind_NCollection_IndexedMap<TopoDS_Shape, TopTools_OrientedShapeMapHasher>(mod, "TopTools_IndexedMapOfOrientedShape");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopTools_DataMapOfShapeInteger.hxx
	bind_NCollection_DataMap<TopoDS_Shape, int, TopTools_ShapeMapHasher>(mod, "TopTools_DataMapOfShapeInteger");

	/* FIXME

	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopTools_DataMapOfOrientedShapeInteger.hxx
	bind_NCollection_DataMap<TopoDS_Shape, int, TopTools_OrientedShapeMapHasher>(mod, "TopTools_DataMapOfOrientedShapeInteger");

	/* FIXME

	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopTools_IndexedDataMapOfShapeShape.hxx
	bind_NCollection_IndexedDataMap<TopoDS_Shape, TopoDS_Shape, TopTools_ShapeMapHasher>(mod, "TopTools_IndexedDataMapOfShapeShape");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopTools_HSequenceOfShape.hxx
	py::class_<TopTools_HSequenceOfShape, opencascade::handle<TopTools_HSequenceOfShape>, TopTools_SequenceOfShape, Standard_Transient> cls_TopTools_HSequenceOfShape(mod, "TopTools_HSequenceOfShape", "None");
	cls_TopTools_HSequenceOfShape.def(py::init<>());
	cls_TopTools_HSequenceOfShape.def(py::init<const TopTools_SequenceOfShape &>(), py::arg("theOther"));
	cls_TopTools_HSequenceOfShape.def("Sequence", (const TopTools_SequenceOfShape & (TopTools_HSequenceOfShape::*)() const ) &TopTools_HSequenceOfShape::Sequence, "None");
	cls_TopTools_HSequenceOfShape.def("Append", (void (TopTools_HSequenceOfShape::*)(const TopTools_SequenceOfShape::value_type &)) &TopTools_HSequenceOfShape::Append, "None", py::arg("theItem"));
	cls_TopTools_HSequenceOfShape.def("Append", (void (TopTools_HSequenceOfShape::*)(TopTools_SequenceOfShape &)) &TopTools_HSequenceOfShape::Append, "None", py::arg("theSequence"));
	cls_TopTools_HSequenceOfShape.def("ChangeSequence", (TopTools_SequenceOfShape & (TopTools_HSequenceOfShape::*)()) &TopTools_HSequenceOfShape::ChangeSequence, "None");
	cls_TopTools_HSequenceOfShape.def_static("get_type_name_", (const char * (*)()) &TopTools_HSequenceOfShape::get_type_name, "None");
	cls_TopTools_HSequenceOfShape.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopTools_HSequenceOfShape::get_type_descriptor, "None");
	cls_TopTools_HSequenceOfShape.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopTools_HSequenceOfShape::*)() const ) &TopTools_HSequenceOfShape::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopTools_DataMapOfShapeListOfInteger.hxx
	bind_NCollection_DataMap<TopoDS_Shape, NCollection_List<int>, TopTools_ShapeMapHasher>(mod, "TopTools_DataMapOfShapeListOfInteger");

	/* FIXME

	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopTools_HArray1OfShape.hxx
	py::class_<TopTools_HArray1OfShape, opencascade::handle<TopTools_HArray1OfShape>, TopTools_Array1OfShape, Standard_Transient> cls_TopTools_HArray1OfShape(mod, "TopTools_HArray1OfShape", "None");
	cls_TopTools_HArray1OfShape.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TopTools_HArray1OfShape.def(py::init<const Standard_Integer, const Standard_Integer, const TopTools_Array1OfShape::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_TopTools_HArray1OfShape.def(py::init<const TopTools_Array1OfShape &>(), py::arg("theOther"));
	cls_TopTools_HArray1OfShape.def("Array1", (const TopTools_Array1OfShape & (TopTools_HArray1OfShape::*)() const ) &TopTools_HArray1OfShape::Array1, "None");
	cls_TopTools_HArray1OfShape.def("ChangeArray1", (TopTools_Array1OfShape & (TopTools_HArray1OfShape::*)()) &TopTools_HArray1OfShape::ChangeArray1, "None");
	cls_TopTools_HArray1OfShape.def_static("get_type_name_", (const char * (*)()) &TopTools_HArray1OfShape::get_type_name, "None");
	cls_TopTools_HArray1OfShape.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopTools_HArray1OfShape::get_type_descriptor, "None");
	cls_TopTools_HArray1OfShape.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopTools_HArray1OfShape::*)() const ) &TopTools_HArray1OfShape::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopTools_HArray2OfShape.hxx
	py::class_<TopTools_HArray2OfShape, opencascade::handle<TopTools_HArray2OfShape>, TopTools_Array2OfShape, Standard_Transient> cls_TopTools_HArray2OfShape(mod, "TopTools_HArray2OfShape", "None");
	cls_TopTools_HArray2OfShape.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"));
	cls_TopTools_HArray2OfShape.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const TopTools_Array2OfShape::value_type &>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"), py::arg("theValue"));
	cls_TopTools_HArray2OfShape.def(py::init<const TopTools_Array2OfShape &>(), py::arg("theOther"));
	cls_TopTools_HArray2OfShape.def("Array2", (const TopTools_Array2OfShape & (TopTools_HArray2OfShape::*)() const ) &TopTools_HArray2OfShape::Array2, "None");
	cls_TopTools_HArray2OfShape.def("ChangeArray2", (TopTools_Array2OfShape & (TopTools_HArray2OfShape::*)()) &TopTools_HArray2OfShape::ChangeArray2, "None");
	cls_TopTools_HArray2OfShape.def_static("get_type_name_", (const char * (*)()) &TopTools_HArray2OfShape::get_type_name, "None");
	cls_TopTools_HArray2OfShape.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopTools_HArray2OfShape::get_type_descriptor, "None");
	cls_TopTools_HArray2OfShape.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopTools_HArray2OfShape::*)() const ) &TopTools_HArray2OfShape::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopTools_DataMapOfIntegerShape.hxx
	bind_NCollection_DataMap<int, TopoDS_Shape, NCollection_DefaultHasher<int> >(mod, "TopTools_DataMapOfIntegerShape");

	/* FIXME

	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopTools_DataMapOfShapeReal.hxx
	bind_NCollection_DataMap<TopoDS_Shape, double, TopTools_ShapeMapHasher>(mod, "TopTools_DataMapOfShapeReal");

	/* FIXME

	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopTools_HArray1OfListOfShape.hxx
	py::class_<TopTools_HArray1OfListOfShape, opencascade::handle<TopTools_HArray1OfListOfShape>, TopTools_Array1OfListOfShape, Standard_Transient> cls_TopTools_HArray1OfListOfShape(mod, "TopTools_HArray1OfListOfShape", "None");
	cls_TopTools_HArray1OfListOfShape.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TopTools_HArray1OfListOfShape.def(py::init<const Standard_Integer, const Standard_Integer, const TopTools_Array1OfListOfShape::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_TopTools_HArray1OfListOfShape.def(py::init<const TopTools_Array1OfListOfShape &>(), py::arg("theOther"));
	cls_TopTools_HArray1OfListOfShape.def("Array1", (const TopTools_Array1OfListOfShape & (TopTools_HArray1OfListOfShape::*)() const ) &TopTools_HArray1OfListOfShape::Array1, "None");
	cls_TopTools_HArray1OfListOfShape.def("ChangeArray1", (TopTools_Array1OfListOfShape & (TopTools_HArray1OfListOfShape::*)()) &TopTools_HArray1OfListOfShape::ChangeArray1, "None");
	cls_TopTools_HArray1OfListOfShape.def_static("get_type_name_", (const char * (*)()) &TopTools_HArray1OfListOfShape::get_type_name, "None");
	cls_TopTools_HArray1OfListOfShape.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopTools_HArray1OfListOfShape::get_type_descriptor, "None");
	cls_TopTools_HArray1OfListOfShape.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopTools_HArray1OfListOfShape::*)() const ) &TopTools_HArray1OfListOfShape::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopTools_IndexedDataMapOfShapeAddress.hxx
	bind_NCollection_IndexedDataMap<TopoDS_Shape, void *, TopTools_ShapeMapHasher>(mod, "TopTools_IndexedDataMapOfShapeAddress");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopTools_DataMapOfOrientedShapeShape.hxx
	bind_NCollection_DataMap<TopoDS_Shape, TopoDS_Shape, TopTools_OrientedShapeMapHasher>(mod, "TopTools_DataMapOfOrientedShapeShape");

	/* FIXME

	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopTools_DataMapOfShapeSequenceOfShape.hxx
	bind_NCollection_DataMap<TopoDS_Shape, NCollection_Sequence<TopoDS_Shape>, TopTools_ShapeMapHasher>(mod, "TopTools_DataMapOfShapeSequenceOfShape");

	/* FIXME

	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopTools_LocationSetPtr.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\TopTools_MapOfOrientedShape.hxx
	bind_NCollection_Map<TopoDS_Shape, TopTools_OrientedShapeMapHasher>(mod, "TopTools_MapOfOrientedShape");

	/* FIXME

	*/


}
