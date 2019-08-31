/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC
Copyright (C) 2019 Trevor Laughlin and the pyOCCT contributors

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/
#include <pyOCCT_Common.hxx>
#include <NCollection_List.hxx>
#include <TopoDS_Shape.hxx>
#include <TopTools_ListOfShape.hxx>
#include <NCollection_DataMap.hxx>
#include <Standard_TypeDef.hxx>
#include <TColStd_MapIntegerHasher.hxx>
#include <TopTools_DataMapOfIntegerListOfShape.hxx>
#include <Standard.hxx>
#include <TopTools_ShapeMapHasher.hxx>
#include <NCollection_Map.hxx>
#include <TopTools_MapOfShape.hxx>
#include <NCollection_IndexedMap.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <NCollection_IndexedDataMap.hxx>
#include <TopTools_IndexedDataMapOfShapeListOfShape.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <TopTools_DataMapOfShapeShape.hxx>
#include <Bnd_Box.hxx>
#include <TopTools_DataMapOfShapeBox.hxx>
#include <TopTools_OrientedShapeMapHasher.hxx>
#include <TopTools_IndexedMapOfOrientedShape.hxx>
#include <TopTools_DataMapOfShapeInteger.hxx>
#include <TopTools_IndexedDataMapOfShapeReal.hxx>
#include <TopTools_ListOfListOfShape.hxx>
#include <TopTools_DataMapOfOrientedShapeInteger.hxx>
#include <TopTools_IndexedDataMapOfShapeShape.hxx>
#include <NCollection_Sequence.hxx>
#include <TopTools_SequenceOfShape.hxx>
#include <TColStd_ListOfInteger.hxx>
#include <TopTools_DataMapOfShapeListOfInteger.hxx>
#include <NCollection_Array1.hxx>
#include <TopTools_Array1OfShape.hxx>
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <TopTools_HArray1OfShape.hxx>
#include <Standard_Type.hxx>
#include <NCollection_Array2.hxx>
#include <TopTools_Array2OfShape.hxx>
#include <TopTools_HArray2OfShape.hxx>
#include <TopTools_DataMapOfIntegerShape.hxx>
#include <TopTools_DataMapOfShapeReal.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <Standard_Mutex.hxx>
#include <TopTools_MutexForShapeProvider.hxx>
#include <TopoDS_TShape.hxx>
#include <TopTools_HSequenceOfShape.hxx>
#include <TopLoc_Location.hxx>
#include <Standard_OStream.hxx>
#include <Standard_IStream.hxx>
#include <Message_ProgressIndicator.hxx>
#include <TopLoc_IndexedMapOfLocation.hxx>
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
#include <bind_NCollection_List.hxx>
#include <bind_NCollection_TListIterator.hxx>
#include <bind_NCollection_DataMap.hxx>
#include <bind_NCollection_Map.hxx>
#include <bind_NCollection_IndexedMap.hxx>
#include <bind_NCollection_IndexedDataMap.hxx>
#include <bind_NCollection_Sequence.hxx>
#include <bind_NCollection_Array1.hxx>
#include <bind_NCollection_Array2.hxx>

PYBIND11_MODULE(TopTools, mod) {

py::module::import("OCCT.NCollection");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.Standard");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.Bnd");
py::module::import("OCCT.TopAbs");
py::module::import("OCCT.TopLoc");
py::module::import("OCCT.Message");
py::module::import("OCCT.TCollection");

// TYPEDEF: TOPTOOLS_LISTOFSHAPE
bind_NCollection_List<TopoDS_Shape>(mod, "TopTools_ListOfShape", py::module_local());

// TYPEDEF: TOPTOOLS_LISTITERATOROFLISTOFSHAPE
bind_NCollection_TListIterator<TopoDS_Shape>(mod, "TopTools_ListIteratorOfListOfShape", py::module_local());

// TYPEDEF: TOPTOOLS_DATAMAPOFINTEGERLISTOFSHAPE
bind_NCollection_DataMap<int, NCollection_List<TopoDS_Shape>, NCollection_DefaultHasher<int> >(mod, "TopTools_DataMapOfIntegerListOfShape", py::module_local(false));

// TYPEDEF: TOPTOOLS_DATAMAPITERATOROFDATAMAPOFINTEGERLISTOFSHAPE

// CLASS: TOPTOOLS_SHAPEMAPHASHER
py::class_<TopTools_ShapeMapHasher> cls_TopTools_ShapeMapHasher(mod, "TopTools_ShapeMapHasher", "Hash tool, used for generating maps of shapes in topology.");

// Methods
// cls_TopTools_ShapeMapHasher.def_static("operator new_", (void * (*)(size_t)) &TopTools_ShapeMapHasher::operator new, "None", py::arg("theSize"));
// cls_TopTools_ShapeMapHasher.def_static("operator delete_", (void (*)(void *)) &TopTools_ShapeMapHasher::operator delete, "None", py::arg("theAddress"));
// cls_TopTools_ShapeMapHasher.def_static("operator new[]_", (void * (*)(size_t)) &TopTools_ShapeMapHasher::operator new[], "None", py::arg("theSize"));
// cls_TopTools_ShapeMapHasher.def_static("operator delete[]_", (void (*)(void *)) &TopTools_ShapeMapHasher::operator delete[], "None", py::arg("theAddress"));
// cls_TopTools_ShapeMapHasher.def_static("operator new_", (void * (*)(size_t, void *)) &TopTools_ShapeMapHasher::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopTools_ShapeMapHasher.def_static("operator delete_", (void (*)(void *, void *)) &TopTools_ShapeMapHasher::operator delete, "None", py::arg(""), py::arg(""));
cls_TopTools_ShapeMapHasher.def_static("HashCode_", (Standard_Integer (*)(const TopoDS_Shape &, const Standard_Integer)) &TopTools_ShapeMapHasher::HashCode, "Returns a HasCode value for the Key <K> in the range 0..Upper.", py::arg("S"), py::arg("Upper"));
cls_TopTools_ShapeMapHasher.def_static("IsEqual_", (Standard_Boolean (*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopTools_ShapeMapHasher::IsEqual, "Returns True when the two keys are the same. Two same keys must have the same hashcode, the contrary is not necessary.", py::arg("S1"), py::arg("S2"));

// TYPEDEF: TOPTOOLS_MAPOFSHAPE
bind_NCollection_Map<TopoDS_Shape, TopTools_ShapeMapHasher>(mod, "TopTools_MapOfShape", py::module_local(false));

// TYPEDEF: TOPTOOLS_MAPITERATOROFMAPOFSHAPE
py::class_<NCollection_Map<TopoDS_Shape, TopTools_ShapeMapHasher>::Iterator, NCollection_BaseMap::Iterator> cls_NCollection_Map_TopTools_MapIteratorOfMapOfShape(mod, "TopTools_MapIteratorOfMapOfShape", "Implementation of the Iterator interface.");

// Constructors
cls_NCollection_Map_TopTools_MapIteratorOfMapOfShape.def(py::init<>());
cls_NCollection_Map_TopTools_MapIteratorOfMapOfShape.def(py::init<const NCollection_Map<TopoDS_Shape, TopTools_ShapeMapHasher> &>(), py::arg("theMap"));

// Methods
cls_NCollection_Map_TopTools_MapIteratorOfMapOfShape.def("More", (Standard_Boolean (NCollection_Map<TopoDS_Shape, TopTools_ShapeMapHasher>::Iterator::*)() const) &NCollection_Map<TopoDS_Shape, TopTools_ShapeMapHasher>::Iterator::More, "Query if the end of collection is reached by iterator");
cls_NCollection_Map_TopTools_MapIteratorOfMapOfShape.def("Next", (void (NCollection_Map<TopoDS_Shape, TopTools_ShapeMapHasher>::Iterator::*)()) &NCollection_Map<TopoDS_Shape, TopTools_ShapeMapHasher>::Iterator::Next, "Make a step along the collection");
cls_NCollection_Map_TopTools_MapIteratorOfMapOfShape.def("Value", (const TopoDS_Shape & (NCollection_Map<TopoDS_Shape, TopTools_ShapeMapHasher>::Iterator::*)() const) &NCollection_Map<TopoDS_Shape, TopTools_ShapeMapHasher>::Iterator::Value, "Value inquiry");
cls_NCollection_Map_TopTools_MapIteratorOfMapOfShape.def("Key", (const TopoDS_Shape & (NCollection_Map<TopoDS_Shape, TopTools_ShapeMapHasher>::Iterator::*)() const) &NCollection_Map<TopoDS_Shape, TopTools_ShapeMapHasher>::Iterator::Key, "Key");

// TYPEDEF: TOPTOOLS_INDEXEDMAPOFSHAPE
bind_NCollection_IndexedMap<TopoDS_Shape, TopTools_ShapeMapHasher>(mod, "TopTools_IndexedMapOfShape", py::module_local(false));

// TYPEDEF: TOPTOOLS_INDEXEDDATAMAPOFSHAPELISTOFSHAPE
bind_NCollection_IndexedDataMap<TopoDS_Shape, NCollection_List<TopoDS_Shape>, TopTools_ShapeMapHasher>(mod, "TopTools_IndexedDataMapOfShapeListOfShape", py::module_local(false));

// TYPEDEF: TOPTOOLS_DATAMAPOFSHAPELISTOFSHAPE
bind_NCollection_DataMap<TopoDS_Shape, NCollection_List<TopoDS_Shape>, TopTools_ShapeMapHasher>(mod, "TopTools_DataMapOfShapeListOfShape", py::module_local(false));

// TYPEDEF: TOPTOOLS_DATAMAPITERATOROFDATAMAPOFSHAPELISTOFSHAPE

// TYPEDEF: TOPTOOLS_DATAMAPOFSHAPESHAPE
bind_NCollection_DataMap<TopoDS_Shape, TopoDS_Shape, TopTools_ShapeMapHasher>(mod, "TopTools_DataMapOfShapeShape", py::module_local(false));

// TYPEDEF: TOPTOOLS_DATAMAPITERATOROFDATAMAPOFSHAPESHAPE

// TYPEDEF: TOPTOOLS_DATAMAPOFSHAPEBOX
bind_NCollection_DataMap<TopoDS_Shape, Bnd_Box, TopTools_ShapeMapHasher>(mod, "TopTools_DataMapOfShapeBox", py::module_local(false));

// TYPEDEF: TOPTOOLS_DATAMAPITERATOROFDATAMAPOFSHAPEBOX

// CLASS: TOPTOOLS_ORIENTEDSHAPEMAPHASHER
py::class_<TopTools_OrientedShapeMapHasher> cls_TopTools_OrientedShapeMapHasher(mod, "TopTools_OrientedShapeMapHasher", "None");

// Methods
// cls_TopTools_OrientedShapeMapHasher.def_static("operator new_", (void * (*)(size_t)) &TopTools_OrientedShapeMapHasher::operator new, "None", py::arg("theSize"));
// cls_TopTools_OrientedShapeMapHasher.def_static("operator delete_", (void (*)(void *)) &TopTools_OrientedShapeMapHasher::operator delete, "None", py::arg("theAddress"));
// cls_TopTools_OrientedShapeMapHasher.def_static("operator new[]_", (void * (*)(size_t)) &TopTools_OrientedShapeMapHasher::operator new[], "None", py::arg("theSize"));
// cls_TopTools_OrientedShapeMapHasher.def_static("operator delete[]_", (void (*)(void *)) &TopTools_OrientedShapeMapHasher::operator delete[], "None", py::arg("theAddress"));
// cls_TopTools_OrientedShapeMapHasher.def_static("operator new_", (void * (*)(size_t, void *)) &TopTools_OrientedShapeMapHasher::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopTools_OrientedShapeMapHasher.def_static("operator delete_", (void (*)(void *, void *)) &TopTools_OrientedShapeMapHasher::operator delete, "None", py::arg(""), py::arg(""));
cls_TopTools_OrientedShapeMapHasher.def_static("HashCode_", (Standard_Integer (*)(const TopoDS_Shape &, const Standard_Integer)) &TopTools_OrientedShapeMapHasher::HashCode, "Returns a HasCode value for the Key <K> in the range 0..Upper.", py::arg("S"), py::arg("Upper"));
cls_TopTools_OrientedShapeMapHasher.def_static("IsEqual_", (Standard_Boolean (*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopTools_OrientedShapeMapHasher::IsEqual, "Returns True when the two keys are equal. Two same keys must have the same hashcode, the contrary is not necessary.", py::arg("S1"), py::arg("S2"));

// TYPEDEF: TOPTOOLS_INDEXEDMAPOFORIENTEDSHAPE
bind_NCollection_IndexedMap<TopoDS_Shape, TopTools_OrientedShapeMapHasher>(mod, "TopTools_IndexedMapOfOrientedShape", py::module_local(false));

// TYPEDEF: TOPTOOLS_DATAMAPOFSHAPEINTEGER
bind_NCollection_DataMap<TopoDS_Shape, int, TopTools_ShapeMapHasher>(mod, "TopTools_DataMapOfShapeInteger", py::module_local(false));

// TYPEDEF: TOPTOOLS_DATAMAPITERATOROFDATAMAPOFSHAPEINTEGER

// TYPEDEF: TOPTOOLS_INDEXEDDATAMAPOFSHAPEREAL
bind_NCollection_IndexedDataMap<TopoDS_Shape, double, TopTools_ShapeMapHasher>(mod, "TopTools_IndexedDataMapOfShapeReal", py::module_local(false));

// TYPEDEF: TOPTOOLS_LISTOFLISTOFSHAPE
bind_NCollection_List<NCollection_List<TopoDS_Shape> >(mod, "TopTools_ListOfListOfShape", py::module_local(false));

// TYPEDEF: TOPTOOLS_LISTITERATOROFLISTOFLISTOFSHAPE
bind_NCollection_TListIterator<NCollection_List<TopoDS_Shape> >(mod, "TopTools_ListIteratorOfListOfListOfShape", py::module_local(false));

// TYPEDEF: TOPTOOLS_DATAMAPOFORIENTEDSHAPEINTEGER
bind_NCollection_DataMap<TopoDS_Shape, int, TopTools_OrientedShapeMapHasher>(mod, "TopTools_DataMapOfOrientedShapeInteger", py::module_local(false));

// TYPEDEF: TOPTOOLS_DATAMAPITERATOROFDATAMAPOFORIENTEDSHAPEINTEGER

// TYPEDEF: TOPTOOLS_INDEXEDDATAMAPOFSHAPESHAPE
bind_NCollection_IndexedDataMap<TopoDS_Shape, TopoDS_Shape, TopTools_ShapeMapHasher>(mod, "TopTools_IndexedDataMapOfShapeShape", py::module_local(false));

// TYPEDEF: TOPTOOLS_SEQUENCEOFSHAPE
bind_NCollection_Sequence<TopoDS_Shape>(mod, "TopTools_SequenceOfShape", py::module_local(false));

// TYPEDEF: TOPTOOLS_DATAMAPOFSHAPELISTOFINTEGER
bind_NCollection_DataMap<TopoDS_Shape, NCollection_List<int>, TopTools_ShapeMapHasher>(mod, "TopTools_DataMapOfShapeListOfInteger", py::module_local(false));

// TYPEDEF: TOPTOOLS_DATAMAPITERATOROFDATAMAPOFSHAPELISTOFINTEGER

// TYPEDEF: TOPTOOLS_ARRAY1OFSHAPE
bind_NCollection_Array1<TopoDS_Shape>(mod, "TopTools_Array1OfShape", py::module_local(false));

// CLASS: TOPTOOLS_HARRAY1OFSHAPE
py::class_<TopTools_HArray1OfShape, opencascade::handle<TopTools_HArray1OfShape>, Standard_Transient> cls_TopTools_HArray1OfShape(mod, "TopTools_HArray1OfShape", "None", py::multiple_inheritance());

// Constructors
cls_TopTools_HArray1OfShape.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_TopTools_HArray1OfShape.def(py::init<const Standard_Integer, const Standard_Integer, const TopTools_Array1OfShape::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_TopTools_HArray1OfShape.def(py::init<const TopTools_Array1OfShape &>(), py::arg("theOther"));

// Methods
// cls_TopTools_HArray1OfShape.def_static("operator new_", (void * (*)(size_t)) &TopTools_HArray1OfShape::operator new, "None", py::arg("theSize"));
// cls_TopTools_HArray1OfShape.def_static("operator delete_", (void (*)(void *)) &TopTools_HArray1OfShape::operator delete, "None", py::arg("theAddress"));
// cls_TopTools_HArray1OfShape.def_static("operator new[]_", (void * (*)(size_t)) &TopTools_HArray1OfShape::operator new[], "None", py::arg("theSize"));
// cls_TopTools_HArray1OfShape.def_static("operator delete[]_", (void (*)(void *)) &TopTools_HArray1OfShape::operator delete[], "None", py::arg("theAddress"));
// cls_TopTools_HArray1OfShape.def_static("operator new_", (void * (*)(size_t, void *)) &TopTools_HArray1OfShape::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopTools_HArray1OfShape.def_static("operator delete_", (void (*)(void *, void *)) &TopTools_HArray1OfShape::operator delete, "None", py::arg(""), py::arg(""));
// cls_TopTools_HArray1OfShape.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &TopTools_HArray1OfShape::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_TopTools_HArray1OfShape.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &TopTools_HArray1OfShape::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_TopTools_HArray1OfShape.def("Array1", (const TopTools_Array1OfShape & (TopTools_HArray1OfShape::*)() const) &TopTools_HArray1OfShape::Array1, "None");
cls_TopTools_HArray1OfShape.def("ChangeArray1", (TopTools_Array1OfShape & (TopTools_HArray1OfShape::*)()) &TopTools_HArray1OfShape::ChangeArray1, "None");
cls_TopTools_HArray1OfShape.def_static("get_type_name_", (const char * (*)()) &TopTools_HArray1OfShape::get_type_name, "None");
cls_TopTools_HArray1OfShape.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopTools_HArray1OfShape::get_type_descriptor, "None");
cls_TopTools_HArray1OfShape.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopTools_HArray1OfShape::*)() const) &TopTools_HArray1OfShape::DynamicType, "None");

// TYPEDEF: TOPTOOLS_ARRAY2OFSHAPE
bind_NCollection_Array2<TopoDS_Shape>(mod, "TopTools_Array2OfShape", py::module_local(false));

// CLASS: TOPTOOLS_HARRAY2OFSHAPE
py::class_<TopTools_HArray2OfShape, opencascade::handle<TopTools_HArray2OfShape>, Standard_Transient> cls_TopTools_HArray2OfShape(mod, "TopTools_HArray2OfShape", "None", py::multiple_inheritance());

// Constructors
cls_TopTools_HArray2OfShape.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"));
cls_TopTools_HArray2OfShape.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const TopTools_Array2OfShape::value_type &>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"), py::arg("theValue"));
cls_TopTools_HArray2OfShape.def(py::init<const TopTools_Array2OfShape &>(), py::arg("theOther"));

// Methods
// cls_TopTools_HArray2OfShape.def_static("operator new_", (void * (*)(size_t)) &TopTools_HArray2OfShape::operator new, "None", py::arg("theSize"));
// cls_TopTools_HArray2OfShape.def_static("operator delete_", (void (*)(void *)) &TopTools_HArray2OfShape::operator delete, "None", py::arg("theAddress"));
// cls_TopTools_HArray2OfShape.def_static("operator new[]_", (void * (*)(size_t)) &TopTools_HArray2OfShape::operator new[], "None", py::arg("theSize"));
// cls_TopTools_HArray2OfShape.def_static("operator delete[]_", (void (*)(void *)) &TopTools_HArray2OfShape::operator delete[], "None", py::arg("theAddress"));
// cls_TopTools_HArray2OfShape.def_static("operator new_", (void * (*)(size_t, void *)) &TopTools_HArray2OfShape::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopTools_HArray2OfShape.def_static("operator delete_", (void (*)(void *, void *)) &TopTools_HArray2OfShape::operator delete, "None", py::arg(""), py::arg(""));
// cls_TopTools_HArray2OfShape.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &TopTools_HArray2OfShape::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_TopTools_HArray2OfShape.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &TopTools_HArray2OfShape::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_TopTools_HArray2OfShape.def("Array2", (const TopTools_Array2OfShape & (TopTools_HArray2OfShape::*)() const) &TopTools_HArray2OfShape::Array2, "None");
cls_TopTools_HArray2OfShape.def("ChangeArray2", (TopTools_Array2OfShape & (TopTools_HArray2OfShape::*)()) &TopTools_HArray2OfShape::ChangeArray2, "None");
cls_TopTools_HArray2OfShape.def_static("get_type_name_", (const char * (*)()) &TopTools_HArray2OfShape::get_type_name, "None");
cls_TopTools_HArray2OfShape.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopTools_HArray2OfShape::get_type_descriptor, "None");
cls_TopTools_HArray2OfShape.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopTools_HArray2OfShape::*)() const) &TopTools_HArray2OfShape::DynamicType, "None");

// TYPEDEF: TOPTOOLS_DATAMAPOFINTEGERSHAPE
bind_NCollection_DataMap<int, TopoDS_Shape, NCollection_DefaultHasher<int> >(mod, "TopTools_DataMapOfIntegerShape", py::module_local(false));

// TYPEDEF: TOPTOOLS_DATAMAPITERATOROFDATAMAPOFINTEGERSHAPE

// TYPEDEF: TOPTOOLS_DATAMAPOFSHAPEREAL
bind_NCollection_DataMap<TopoDS_Shape, double, TopTools_ShapeMapHasher>(mod, "TopTools_DataMapOfShapeReal", py::module_local(false));

// TYPEDEF: TOPTOOLS_DATAMAPITERATOROFDATAMAPOFSHAPEREAL

// CLASS: TOPTOOLS_MUTEXFORSHAPEPROVIDER
py::class_<TopTools_MutexForShapeProvider> cls_TopTools_MutexForShapeProvider(mod, "TopTools_MutexForShapeProvider", "Class TopTools_MutexForShapeProvider This class is used to create and store mutexes associated with shapes.");

// Constructors
cls_TopTools_MutexForShapeProvider.def(py::init<>());

// Methods
cls_TopTools_MutexForShapeProvider.def("CreateMutexesForSubShapes", (void (TopTools_MutexForShapeProvider::*)(const TopoDS_Shape &, const TopAbs_ShapeEnum)) &TopTools_MutexForShapeProvider::CreateMutexesForSubShapes, "Creates and associates mutexes with each sub-shape of type theType in theShape.", py::arg("theShape"), py::arg("theType"));
cls_TopTools_MutexForShapeProvider.def("CreateMutexForShape", (void (TopTools_MutexForShapeProvider::*)(const TopoDS_Shape &)) &TopTools_MutexForShapeProvider::CreateMutexForShape, "Creates and associates mutex with theShape", py::arg("theShape"));
cls_TopTools_MutexForShapeProvider.def("GetMutex", (Standard_Mutex * (TopTools_MutexForShapeProvider::*)(const TopoDS_Shape &) const) &TopTools_MutexForShapeProvider::GetMutex, "Returns pointer to mutex associated with theShape. In case when mutex not found returns NULL.", py::arg("theShape"));
cls_TopTools_MutexForShapeProvider.def("RemoveAllMutexes", (void (TopTools_MutexForShapeProvider::*)()) &TopTools_MutexForShapeProvider::RemoveAllMutexes, "Removes all mutexes");

// CLASS: TOPTOOLS_HSEQUENCEOFSHAPE
py::class_<TopTools_HSequenceOfShape, opencascade::handle<TopTools_HSequenceOfShape>, Standard_Transient> cls_TopTools_HSequenceOfShape(mod, "TopTools_HSequenceOfShape", "None", py::multiple_inheritance());

// Constructors
cls_TopTools_HSequenceOfShape.def(py::init<>());
cls_TopTools_HSequenceOfShape.def(py::init<const TopTools_SequenceOfShape &>(), py::arg("theOther"));

// Methods
// cls_TopTools_HSequenceOfShape.def_static("operator new_", (void * (*)(size_t)) &TopTools_HSequenceOfShape::operator new, "None", py::arg("theSize"));
// cls_TopTools_HSequenceOfShape.def_static("operator delete_", (void (*)(void *)) &TopTools_HSequenceOfShape::operator delete, "None", py::arg("theAddress"));
// cls_TopTools_HSequenceOfShape.def_static("operator new[]_", (void * (*)(size_t)) &TopTools_HSequenceOfShape::operator new[], "None", py::arg("theSize"));
// cls_TopTools_HSequenceOfShape.def_static("operator delete[]_", (void (*)(void *)) &TopTools_HSequenceOfShape::operator delete[], "None", py::arg("theAddress"));
// cls_TopTools_HSequenceOfShape.def_static("operator new_", (void * (*)(size_t, void *)) &TopTools_HSequenceOfShape::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopTools_HSequenceOfShape.def_static("operator delete_", (void (*)(void *, void *)) &TopTools_HSequenceOfShape::operator delete, "None", py::arg(""), py::arg(""));
// cls_TopTools_HSequenceOfShape.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &TopTools_HSequenceOfShape::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_TopTools_HSequenceOfShape.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &TopTools_HSequenceOfShape::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_TopTools_HSequenceOfShape.def("Sequence", (const TopTools_SequenceOfShape & (TopTools_HSequenceOfShape::*)() const) &TopTools_HSequenceOfShape::Sequence, "None");
cls_TopTools_HSequenceOfShape.def("Append", (void (TopTools_HSequenceOfShape::*)(const TopTools_SequenceOfShape::value_type &)) &TopTools_HSequenceOfShape::Append, "None", py::arg("theItem"));
cls_TopTools_HSequenceOfShape.def("Append", (void (TopTools_HSequenceOfShape::*)(TopTools_SequenceOfShape &)) &TopTools_HSequenceOfShape::Append, "None", py::arg("theSequence"));
cls_TopTools_HSequenceOfShape.def("ChangeSequence", (TopTools_SequenceOfShape & (TopTools_HSequenceOfShape::*)()) &TopTools_HSequenceOfShape::ChangeSequence, "None");
cls_TopTools_HSequenceOfShape.def_static("get_type_name_", (const char * (*)()) &TopTools_HSequenceOfShape::get_type_name, "None");
cls_TopTools_HSequenceOfShape.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopTools_HSequenceOfShape::get_type_descriptor, "None");
cls_TopTools_HSequenceOfShape.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopTools_HSequenceOfShape::*)() const) &TopTools_HSequenceOfShape::DynamicType, "None");

// CLASS: TOPTOOLS_LOCATIONSET
py::class_<TopTools_LocationSet> cls_TopTools_LocationSet(mod, "TopTools_LocationSet", "The class LocationSet stores a set of location in a relocatable state.");

// Constructors
cls_TopTools_LocationSet.def(py::init<>());

// Methods
// cls_TopTools_LocationSet.def_static("operator new_", (void * (*)(size_t)) &TopTools_LocationSet::operator new, "None", py::arg("theSize"));
// cls_TopTools_LocationSet.def_static("operator delete_", (void (*)(void *)) &TopTools_LocationSet::operator delete, "None", py::arg("theAddress"));
// cls_TopTools_LocationSet.def_static("operator new[]_", (void * (*)(size_t)) &TopTools_LocationSet::operator new[], "None", py::arg("theSize"));
// cls_TopTools_LocationSet.def_static("operator delete[]_", (void (*)(void *)) &TopTools_LocationSet::operator delete[], "None", py::arg("theAddress"));
// cls_TopTools_LocationSet.def_static("operator new_", (void * (*)(size_t, void *)) &TopTools_LocationSet::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopTools_LocationSet.def_static("operator delete_", (void (*)(void *, void *)) &TopTools_LocationSet::operator delete, "None", py::arg(""), py::arg(""));
cls_TopTools_LocationSet.def("Clear", (void (TopTools_LocationSet::*)()) &TopTools_LocationSet::Clear, "Clears the content of the set.");
cls_TopTools_LocationSet.def("Add", (Standard_Integer (TopTools_LocationSet::*)(const TopLoc_Location &)) &TopTools_LocationSet::Add, "Incorporate a new Location in the set and returns its index.", py::arg("L"));
cls_TopTools_LocationSet.def("Location", (const TopLoc_Location & (TopTools_LocationSet::*)(const Standard_Integer) const) &TopTools_LocationSet::Location, "Returns the location of index <I>.", py::arg("I"));
cls_TopTools_LocationSet.def("Index", (Standard_Integer (TopTools_LocationSet::*)(const TopLoc_Location &) const) &TopTools_LocationSet::Index, "Returns the index of <L>.", py::arg("L"));
cls_TopTools_LocationSet.def("Dump", (void (TopTools_LocationSet::*)(Standard_OStream &) const) &TopTools_LocationSet::Dump, "Dumps the content of me on the stream <OS>.", py::arg("OS"));
cls_TopTools_LocationSet.def("Write", (void (TopTools_LocationSet::*)(Standard_OStream &) const) &TopTools_LocationSet::Write, "Writes the content of me on the stream <OS> in a format that can be read back by Read.", py::arg("OS"));
cls_TopTools_LocationSet.def("Read", (void (TopTools_LocationSet::*)(Standard_IStream &)) &TopTools_LocationSet::Read, "Reads the content of me from the stream <IS>. me is first cleared.", py::arg("IS"));
cls_TopTools_LocationSet.def("SetProgress", (void (TopTools_LocationSet::*)(const opencascade::handle<Message_ProgressIndicator> &)) &TopTools_LocationSet::SetProgress, "None", py::arg("PR"));
cls_TopTools_LocationSet.def("GetProgress", (opencascade::handle<Message_ProgressIndicator> (TopTools_LocationSet::*)() const) &TopTools_LocationSet::GetProgress, "None");

// CLASS: TOPTOOLS_SHAPESET
py::class_<TopTools_ShapeSet> cls_TopTools_ShapeSet(mod, "TopTools_ShapeSet", "A ShapeSets contains a Shape and all its sub-shapes and locations. It can be dump, write and read.");

// Constructors
cls_TopTools_ShapeSet.def(py::init<>());

// Methods
// cls_TopTools_ShapeSet.def_static("operator new_", (void * (*)(size_t)) &TopTools_ShapeSet::operator new, "None", py::arg("theSize"));
// cls_TopTools_ShapeSet.def_static("operator delete_", (void (*)(void *)) &TopTools_ShapeSet::operator delete, "None", py::arg("theAddress"));
// cls_TopTools_ShapeSet.def_static("operator new[]_", (void * (*)(size_t)) &TopTools_ShapeSet::operator new[], "None", py::arg("theSize"));
// cls_TopTools_ShapeSet.def_static("operator delete[]_", (void (*)(void *)) &TopTools_ShapeSet::operator delete[], "None", py::arg("theAddress"));
// cls_TopTools_ShapeSet.def_static("operator new_", (void * (*)(size_t, void *)) &TopTools_ShapeSet::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopTools_ShapeSet.def_static("operator delete_", (void (*)(void *, void *)) &TopTools_ShapeSet::operator delete, "None", py::arg(""), py::arg(""));
cls_TopTools_ShapeSet.def("SetFormatNb", (void (TopTools_ShapeSet::*)(const Standard_Integer)) &TopTools_ShapeSet::SetFormatNb, "None", py::arg("theFormatNb"));
cls_TopTools_ShapeSet.def("FormatNb", (Standard_Integer (TopTools_ShapeSet::*)() const) &TopTools_ShapeSet::FormatNb, "two formats available for the moment: First: does not write CurveOnSurface UV Points into the file on reading calls Check() method. Second: stores CurveOnSurface UV Points. On reading format is recognized from Version string.");
cls_TopTools_ShapeSet.def("Clear", (void (TopTools_ShapeSet::*)()) &TopTools_ShapeSet::Clear, "Clears the content of the set. This method can be redefined.");
cls_TopTools_ShapeSet.def("Add", (Standard_Integer (TopTools_ShapeSet::*)(const TopoDS_Shape &)) &TopTools_ShapeSet::Add, "Stores <S> and its sub-shape. Returns the index of <S>. The method AddGeometry is called on each sub-shape.", py::arg("S"));
cls_TopTools_ShapeSet.def("Shape", (const TopoDS_Shape & (TopTools_ShapeSet::*)(const Standard_Integer) const) &TopTools_ShapeSet::Shape, "Returns the sub-shape of index <I>.", py::arg("I"));
cls_TopTools_ShapeSet.def("Index", (Standard_Integer (TopTools_ShapeSet::*)(const TopoDS_Shape &) const) &TopTools_ShapeSet::Index, "Returns the index of <S>.", py::arg("S"));
cls_TopTools_ShapeSet.def("Locations", (const TopTools_LocationSet & (TopTools_ShapeSet::*)() const) &TopTools_ShapeSet::Locations, "None");
cls_TopTools_ShapeSet.def("ChangeLocations", (TopTools_LocationSet & (TopTools_ShapeSet::*)()) &TopTools_ShapeSet::ChangeLocations, "None");
cls_TopTools_ShapeSet.def("DumpExtent", (Standard_OStream & (TopTools_ShapeSet::*)(Standard_OStream &) const) &TopTools_ShapeSet::DumpExtent, "Dumps the number of objects in me on the stream <OS>. (Number of shapes of each type)", py::arg("OS"));
cls_TopTools_ShapeSet.def("DumpExtent", (void (TopTools_ShapeSet::*)(TCollection_AsciiString &) const) &TopTools_ShapeSet::DumpExtent, "Dumps the number of objects in me in the string S (Number of shapes of each type)", py::arg("S"));
cls_TopTools_ShapeSet.def("Dump", (void (TopTools_ShapeSet::*)(Standard_OStream &) const) &TopTools_ShapeSet::Dump, "Dumps the content of me on the stream <OS>.", py::arg("OS"));
cls_TopTools_ShapeSet.def("Write", (void (TopTools_ShapeSet::*)(Standard_OStream &)) &TopTools_ShapeSet::Write, "Writes the content of me on the stream <OS> in a format that can be read back by Read.", py::arg("OS"));
cls_TopTools_ShapeSet.def("Read", (void (TopTools_ShapeSet::*)(Standard_IStream &)) &TopTools_ShapeSet::Read, "Reads the content of me from the stream <IS>. me is first cleared.", py::arg("IS"));
cls_TopTools_ShapeSet.def("Dump", (void (TopTools_ShapeSet::*)(const TopoDS_Shape &, Standard_OStream &) const) &TopTools_ShapeSet::Dump, "Dumps on <OS> the shape <S>. Dumps the orientation, the index of the TShape and the index of the Location.", py::arg("S"), py::arg("OS"));
cls_TopTools_ShapeSet.def("Write", (void (TopTools_ShapeSet::*)(const TopoDS_Shape &, Standard_OStream &) const) &TopTools_ShapeSet::Write, "Writes on <OS> the shape <S>. Writes the orientation, the index of the TShape and the index of the Location.", py::arg("S"), py::arg("OS"));
cls_TopTools_ShapeSet.def("Read", (void (TopTools_ShapeSet::*)(TopoDS_Shape &, Standard_IStream &) const) &TopTools_ShapeSet::Read, "Reads from <IS> a shape and returns it in S.", py::arg("S"), py::arg("IS"));
cls_TopTools_ShapeSet.def("AddGeometry", (void (TopTools_ShapeSet::*)(const TopoDS_Shape &)) &TopTools_ShapeSet::AddGeometry, "Stores the geometry of <S>.", py::arg("S"));
cls_TopTools_ShapeSet.def("DumpGeometry", (void (TopTools_ShapeSet::*)(Standard_OStream &) const) &TopTools_ShapeSet::DumpGeometry, "Dumps the geometry of me on the stream <OS>.", py::arg("OS"));
cls_TopTools_ShapeSet.def("WriteGeometry", (void (TopTools_ShapeSet::*)(Standard_OStream &)) &TopTools_ShapeSet::WriteGeometry, "Writes the geometry of me on the stream <OS> in a format that can be read back by Read.", py::arg("OS"));
cls_TopTools_ShapeSet.def("ReadGeometry", (void (TopTools_ShapeSet::*)(Standard_IStream &)) &TopTools_ShapeSet::ReadGeometry, "Reads the geometry of me from the stream <IS>.", py::arg("IS"));
cls_TopTools_ShapeSet.def("DumpGeometry", (void (TopTools_ShapeSet::*)(const TopoDS_Shape &, Standard_OStream &) const) &TopTools_ShapeSet::DumpGeometry, "Dumps the geometry of <S> on the stream <OS>.", py::arg("S"), py::arg("OS"));
cls_TopTools_ShapeSet.def("WriteGeometry", (void (TopTools_ShapeSet::*)(const TopoDS_Shape &, Standard_OStream &) const) &TopTools_ShapeSet::WriteGeometry, "Writes the geometry of <S> on the stream <OS> in a format that can be read back by Read.", py::arg("S"), py::arg("OS"));
cls_TopTools_ShapeSet.def("ReadGeometry", (void (TopTools_ShapeSet::*)(const TopAbs_ShapeEnum, Standard_IStream &, TopoDS_Shape &)) &TopTools_ShapeSet::ReadGeometry, "Reads the geometry of a shape of type <T> from the stream <IS> and returns it in <S>.", py::arg("T"), py::arg("IS"), py::arg("S"));
cls_TopTools_ShapeSet.def("AddShapes", (void (TopTools_ShapeSet::*)(TopoDS_Shape &, const TopoDS_Shape &)) &TopTools_ShapeSet::AddShapes, "Inserts the shape <S2> in the shape <S1>. This method must be redefined to use the correct builder.", py::arg("S1"), py::arg("S2"));
cls_TopTools_ShapeSet.def("Check", (void (TopTools_ShapeSet::*)(const TopAbs_ShapeEnum, TopoDS_Shape &)) &TopTools_ShapeSet::Check, "This method is called after each new completed shape. <T> is the type. <S> is the shape. In this class it does nothing, but it gives the opportunity in derived classes to perform extra treatment on shapes.", py::arg("T"), py::arg("S"));
cls_TopTools_ShapeSet.def("NbShapes", (Standard_Integer (TopTools_ShapeSet::*)() const) &TopTools_ShapeSet::NbShapes, "Returns number of shapes read from file.");
cls_TopTools_ShapeSet.def("SetProgress", (void (TopTools_ShapeSet::*)(const opencascade::handle<Message_ProgressIndicator> &)) &TopTools_ShapeSet::SetProgress, "None", py::arg("PR"));
cls_TopTools_ShapeSet.def("GetProgress", (opencascade::handle<Message_ProgressIndicator> (TopTools_ShapeSet::*)() const) &TopTools_ShapeSet::GetProgress, "None");

// TYPEDEF: TOPTOOLS_ARRAY1OFLISTOFSHAPE
bind_NCollection_Array1<NCollection_List<TopoDS_Shape> >(mod, "TopTools_Array1OfListOfShape", py::module_local(false));

// CLASS: TOPTOOLS_HARRAY1OFLISTOFSHAPE
py::class_<TopTools_HArray1OfListOfShape, opencascade::handle<TopTools_HArray1OfListOfShape>, Standard_Transient> cls_TopTools_HArray1OfListOfShape(mod, "TopTools_HArray1OfListOfShape", "None", py::multiple_inheritance());

// Constructors
cls_TopTools_HArray1OfListOfShape.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_TopTools_HArray1OfListOfShape.def(py::init<const Standard_Integer, const Standard_Integer, const TopTools_Array1OfListOfShape::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_TopTools_HArray1OfListOfShape.def(py::init<const TopTools_Array1OfListOfShape &>(), py::arg("theOther"));

// Methods
// cls_TopTools_HArray1OfListOfShape.def_static("operator new_", (void * (*)(size_t)) &TopTools_HArray1OfListOfShape::operator new, "None", py::arg("theSize"));
// cls_TopTools_HArray1OfListOfShape.def_static("operator delete_", (void (*)(void *)) &TopTools_HArray1OfListOfShape::operator delete, "None", py::arg("theAddress"));
// cls_TopTools_HArray1OfListOfShape.def_static("operator new[]_", (void * (*)(size_t)) &TopTools_HArray1OfListOfShape::operator new[], "None", py::arg("theSize"));
// cls_TopTools_HArray1OfListOfShape.def_static("operator delete[]_", (void (*)(void *)) &TopTools_HArray1OfListOfShape::operator delete[], "None", py::arg("theAddress"));
// cls_TopTools_HArray1OfListOfShape.def_static("operator new_", (void * (*)(size_t, void *)) &TopTools_HArray1OfListOfShape::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopTools_HArray1OfListOfShape.def_static("operator delete_", (void (*)(void *, void *)) &TopTools_HArray1OfListOfShape::operator delete, "None", py::arg(""), py::arg(""));
// cls_TopTools_HArray1OfListOfShape.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &TopTools_HArray1OfListOfShape::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_TopTools_HArray1OfListOfShape.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &TopTools_HArray1OfListOfShape::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_TopTools_HArray1OfListOfShape.def("Array1", (const TopTools_Array1OfListOfShape & (TopTools_HArray1OfListOfShape::*)() const) &TopTools_HArray1OfListOfShape::Array1, "None");
cls_TopTools_HArray1OfListOfShape.def("ChangeArray1", (TopTools_Array1OfListOfShape & (TopTools_HArray1OfListOfShape::*)()) &TopTools_HArray1OfListOfShape::ChangeArray1, "None");
cls_TopTools_HArray1OfListOfShape.def_static("get_type_name_", (const char * (*)()) &TopTools_HArray1OfListOfShape::get_type_name, "None");
cls_TopTools_HArray1OfListOfShape.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopTools_HArray1OfListOfShape::get_type_descriptor, "None");
cls_TopTools_HArray1OfListOfShape.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopTools_HArray1OfListOfShape::*)() const) &TopTools_HArray1OfListOfShape::DynamicType, "None");

// TYPEDEF: TOPTOOLS_INDEXEDDATAMAPOFSHAPEADDRESS
bind_NCollection_IndexedDataMap<TopoDS_Shape, void *, TopTools_ShapeMapHasher>(mod, "TopTools_IndexedDataMapOfShapeAddress", py::module_local(false));

// CLASS: TOPTOOLS
py::class_<TopTools> cls_TopTools(mod, "TopTools", "The TopTools package provides utilities for the topological data structure.");

// Methods
// cls_TopTools.def_static("operator new_", (void * (*)(size_t)) &TopTools::operator new, "None", py::arg("theSize"));
// cls_TopTools.def_static("operator delete_", (void (*)(void *)) &TopTools::operator delete, "None", py::arg("theAddress"));
// cls_TopTools.def_static("operator new[]_", (void * (*)(size_t)) &TopTools::operator new[], "None", py::arg("theSize"));
// cls_TopTools.def_static("operator delete[]_", (void (*)(void *)) &TopTools::operator delete[], "None", py::arg("theAddress"));
// cls_TopTools.def_static("operator new_", (void * (*)(size_t, void *)) &TopTools::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopTools.def_static("operator delete_", (void (*)(void *, void *)) &TopTools::operator delete, "None", py::arg(""), py::arg(""));
cls_TopTools.def_static("Dump_", (void (*)(const TopoDS_Shape &, Standard_OStream &)) &TopTools::Dump, "A set of Shapes. Can be dump, wrote or read. Dumps the topological structure of <Sh> on the stream <S>.", py::arg("Sh"), py::arg("S"));
cls_TopTools.def_static("Dummy_", (void (*)(const Standard_Integer)) &TopTools::Dummy, "This is to bypass an extraction bug. It will force the inclusion of Standard_Integer.hxx itself including Standard_OStream.hxx at the correct position.", py::arg("I"));

// TYPEDEF: TOPTOOLS_DATAMAPOFORIENTEDSHAPESHAPE
bind_NCollection_DataMap<TopoDS_Shape, TopoDS_Shape, TopTools_OrientedShapeMapHasher>(mod, "TopTools_DataMapOfOrientedShapeShape", py::module_local(false));

// TYPEDEF: TOPTOOLS_DATAMAPITERATOROFDATAMAPOFORIENTEDSHAPESHAPE

// TYPEDEF: TOPTOOLS_DATAMAPOFSHAPESEQUENCEOFSHAPE
bind_NCollection_DataMap<TopoDS_Shape, NCollection_Sequence<TopoDS_Shape>, TopTools_ShapeMapHasher>(mod, "TopTools_DataMapOfShapeSequenceOfShape", py::module_local(false));

// TYPEDEF: TOPTOOLS_DATAMAPITERATOROFDATAMAPOFSHAPESEQUENCEOFSHAPE

// TYPEDEF: TOPTOOLS_LOCATIONSETPTR

// TYPEDEF: TOPTOOLS_MAPOFORIENTEDSHAPE
bind_NCollection_Map<TopoDS_Shape, TopTools_OrientedShapeMapHasher>(mod, "TopTools_MapOfOrientedShape", py::module_local(false));

// TYPEDEF: TOPTOOLS_MAPITERATOROFMAPOFORIENTEDSHAPE


}
