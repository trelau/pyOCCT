#include <pyOCCT_Common.hpp>

#include <gp_XYZ.hxx>
#include <gp_XY.hxx>

#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Type.hxx>
#include <NCollection_StlIterator.hxx>
#include <NCollection_Array1.hxx>
#include <NCollection_Vec2.hxx>
#include <NCollection_Vec3.hxx>
#include <NCollection_Vec4.hxx>
#include <NCollection_Mat4.hxx>
#include <NCollection_Array2.hxx>
#include <NCollection_BaseSequence.hxx>
#include <NCollection_Sequence.hxx>
#include <NCollection_Buffer.hxx>
#include <NCollection_ListNode.hxx>
#include <NCollection_BaseList.hxx>
#include <NCollection_List.hxx>
#include <NCollection_BaseVector.hxx>
#include <NCollection_Vector.hxx>
#include <NCollection_BaseMap.hxx>
#include <Standard_OStream.hxx>
#include <NCollection_DataMap.hxx>
#include <NCollection_Map.hxx>
#include <NCollection_IndexedMap.hxx>
#include <NCollection_IndexedDataMap.hxx>
#include <NCollection_Handle.hxx>
#include <NCollection_DoubleMap.hxx>
#include <NCollection_UBTree.hxx>
#include <NCollection_IncAllocator.hxx>
#include <NCollection_CellFilter.hxx>
#include <NCollection_UBTreeFiller.hxx>
#include <NCollection_EBTree.hxx>
#include <NCollection_StdAllocator.hxx>
#include <NCollection_UtfIterator.hxx>
#include <NCollection_UtfString.hxx>
#include <NCollection_String.hxx>
#include <NCollection_AccAllocator.hxx>
#include <NCollection_AlignedAllocator.hxx>
#include <NCollection_HeapAllocator.hxx>
#include <NCollection_SparseArrayBase.hxx>
#include <NCollection_SparseArray.hxx>
#include <NCollection_WinHeapAllocator.hxx>
#include <NCollection_Templates.hpp>

PYBIND11_MODULE(NCollection, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_CellFilter.hxx
	py::enum_<NCollection_CellFilter_Action>(mod, "NCollection_CellFilter_Action", "Auxiliary enumeration serving as responce from method Inspect")
		.value("CellFilter_Keep", NCollection_CellFilter_Action::CellFilter_Keep)
		.value("CellFilter_Purge", NCollection_CellFilter_Action::CellFilter_Purge)
		.export_values();

	// FUNCTIONS
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_BaseVector.hxx
	mod.def("GetCapacity", (Standard_Integer (*)(const Standard_Integer)) &GetCapacity, "None", py::arg("theIncrement"));


	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_BaseAllocator.hxx
	py::class_<NCollection_BaseAllocator, opencascade::handle<NCollection_BaseAllocator>, Standard_Transient> cls_NCollection_BaseAllocator(mod, "NCollection_BaseAllocator", "Purpose: Basic class for memory allocation wizards. Defines the interface for devising different allocators firstly to be used by collections of NCollection, though it it is not deferred. It allocates/frees the memory through Standard procedures, thus it is unnecessary (and sometimes injurious) to have more than one such allocator. To avoid creation of multiple objects the constructors were maid inaccessible. To create the BaseAllocator use the method CommonBaseAllocator. Note that this object is managed by Handle.");
	cls_NCollection_BaseAllocator.def("Allocate", (void * (NCollection_BaseAllocator::*)(const size_t)) &NCollection_BaseAllocator::Allocate, "None", py::arg("size"));
	cls_NCollection_BaseAllocator.def("Free", (void (NCollection_BaseAllocator::*)(void *)) &NCollection_BaseAllocator::Free, "None", py::arg("anAddress"));
	cls_NCollection_BaseAllocator.def_static("CommonBaseAllocator_", (const opencascade::handle<NCollection_BaseAllocator> & (*)()) &NCollection_BaseAllocator::CommonBaseAllocator, "CommonBaseAllocator This method is designed to have the only one BaseAllocator (to avoid useless copying of collections). However one can use operator new to create more BaseAllocators, but it is injurious.");
	cls_NCollection_BaseAllocator.def_static("StandardCallBack_", (void (*)(const Standard_Boolean, const Standard_Address, const Standard_Size, const Standard_Size)) &NCollection_BaseAllocator::StandardCallBack, "Callback function to register alloc/free calls", py::arg("theIsAlloc"), py::arg("theStorage"), py::arg("theRoundSize"), py::arg("theSize"));
	cls_NCollection_BaseAllocator.def_static("PrintMemUsageStatistics_", (void (*)()) &NCollection_BaseAllocator::PrintMemUsageStatistics, "Prints memory usage statistics cumulated by StandardCallBack");
	cls_NCollection_BaseAllocator.def_static("get_type_name_", (const char * (*)()) &NCollection_BaseAllocator::get_type_name, "None");
	cls_NCollection_BaseAllocator.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &NCollection_BaseAllocator::get_type_descriptor, "None");
	cls_NCollection_BaseAllocator.def("DynamicType", (const opencascade::handle<Standard_Type> & (NCollection_BaseAllocator::*)() const ) &NCollection_BaseAllocator::DynamicType, "None");

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_BaseSequence.hxx
	py::class_<NCollection_SeqNode, std::unique_ptr<NCollection_SeqNode, Deleter<NCollection_SeqNode>>> cls_NCollection_SeqNode(mod, "NCollection_SeqNode", "None");
	cls_NCollection_SeqNode.def(py::init<>());
	cls_NCollection_SeqNode.def("Next", (NCollection_SeqNode * (NCollection_SeqNode::*)() const ) &NCollection_SeqNode::Next, "None");
	cls_NCollection_SeqNode.def("Previous", (NCollection_SeqNode * (NCollection_SeqNode::*)() const ) &NCollection_SeqNode::Previous, "None");
	cls_NCollection_SeqNode.def("SetNext", (void (NCollection_SeqNode::*)(NCollection_SeqNode *)) &NCollection_SeqNode::SetNext, "None", py::arg("theNext"));
	cls_NCollection_SeqNode.def("SetPrevious", (void (NCollection_SeqNode::*)(NCollection_SeqNode *)) &NCollection_SeqNode::SetPrevious, "None", py::arg("thePrev"));
	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_BaseSequence.hxx
	py::class_<NCollection_BaseSequence, std::unique_ptr<NCollection_BaseSequence, py::nodelete>> cls_NCollection_BaseSequence(mod, "NCollection_BaseSequence", "Purpose: This is a base class for the Sequence. It deals with an indexed bidirectional list of NCollection_SeqNode's.");
	cls_NCollection_BaseSequence.def("IsEmpty", (Standard_Boolean (NCollection_BaseSequence::*)() const ) &NCollection_BaseSequence::IsEmpty, "None");
	cls_NCollection_BaseSequence.def("Length", (Standard_Integer (NCollection_BaseSequence::*)() const ) &NCollection_BaseSequence::Length, "None");
	cls_NCollection_BaseSequence.def("Allocator", (const opencascade::handle<NCollection_BaseAllocator> & (NCollection_BaseSequence::*)() const ) &NCollection_BaseSequence::Allocator, "Returns attached allocator");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Buffer.hxx
	py::class_<NCollection_Buffer, opencascade::handle<NCollection_Buffer>, Standard_Transient> cls_NCollection_Buffer(mod, "NCollection_Buffer", "Low-level buffer object.");
	cls_NCollection_Buffer.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAlloc"));
	cls_NCollection_Buffer.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &, const Standard_Size>(), py::arg("theAlloc"), py::arg("theSize"));
	cls_NCollection_Buffer.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &, const Standard_Size, Standard_Byte *>(), py::arg("theAlloc"), py::arg("theSize"), py::arg("theData"));
	cls_NCollection_Buffer.def("Data", (const Standard_Byte * (NCollection_Buffer::*)() const ) &NCollection_Buffer::Data, "Returns buffer data");
	cls_NCollection_Buffer.def("ChangeData", (Standard_Byte * (NCollection_Buffer::*)()) &NCollection_Buffer::ChangeData, "Returns buffer data");
	cls_NCollection_Buffer.def("IsEmpty", (bool (NCollection_Buffer::*)() const ) &NCollection_Buffer::IsEmpty, "Returns true if buffer is not allocated");
	cls_NCollection_Buffer.def("Size", (Standard_Size (NCollection_Buffer::*)() const ) &NCollection_Buffer::Size, "Return buffer length in bytes.");
	cls_NCollection_Buffer.def("Allocator", (const opencascade::handle<NCollection_BaseAllocator> & (NCollection_Buffer::*)() const ) &NCollection_Buffer::Allocator, "Returns buffer allocator");
	cls_NCollection_Buffer.def("SetAllocator", (void (NCollection_Buffer::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &NCollection_Buffer::SetAllocator, "Assign new buffer allocator with de-allocation of buffer.", py::arg("theAlloc"));
	cls_NCollection_Buffer.def("Allocate", (bool (NCollection_Buffer::*)(const Standard_Size)) &NCollection_Buffer::Allocate, "Allocate the buffer.", py::arg("theSize"));
	cls_NCollection_Buffer.def("Free", (void (NCollection_Buffer::*)()) &NCollection_Buffer::Free, "De-allocate buffer.");
	cls_NCollection_Buffer.def_static("get_type_name_", (const char * (*)()) &NCollection_Buffer::get_type_name, "None");
	cls_NCollection_Buffer.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &NCollection_Buffer::get_type_descriptor, "None");
	cls_NCollection_Buffer.def("DynamicType", (const opencascade::handle<Standard_Type> & (NCollection_Buffer::*)() const ) &NCollection_Buffer::DynamicType, "None");

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_ListNode.hxx
	py::class_<NCollection_ListNode, std::unique_ptr<NCollection_ListNode, Deleter<NCollection_ListNode>>> cls_NCollection_ListNode(mod, "NCollection_ListNode", "Purpose: This class is used to represent a node in the BaseList and BaseMap.");
	cls_NCollection_ListNode.def(py::init<NCollection_ListNode *>(), py::arg("theNext"));
	cls_NCollection_ListNode.def("Next", (NCollection_ListNode *& (NCollection_ListNode::*)()) &NCollection_ListNode::Next, "Next pointer access");
	cls_NCollection_ListNode.def("Next", (NCollection_ListNode * (NCollection_ListNode::*)() const ) &NCollection_ListNode::Next, "Next pointer const access");
	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_BaseList.hxx
	py::class_<NCollection_BaseList, std::unique_ptr<NCollection_BaseList, Deleter<NCollection_BaseList>>> cls_NCollection_BaseList(mod, "NCollection_BaseList", "None");
	cls_NCollection_BaseList.def("Extent", (Standard_Integer (NCollection_BaseList::*)() const ) &NCollection_BaseList::Extent, "None");
	cls_NCollection_BaseList.def("IsEmpty", (Standard_Boolean (NCollection_BaseList::*)() const ) &NCollection_BaseList::IsEmpty, "None");
	cls_NCollection_BaseList.def("Allocator", (const opencascade::handle<NCollection_BaseAllocator> & (NCollection_BaseList::*)() const ) &NCollection_BaseList::Allocator, "Returns attached allocator");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_BaseVector.hxx
	py::class_<NCollection_BaseVector, std::unique_ptr<NCollection_BaseVector, py::nodelete>> cls_NCollection_BaseVector(mod, "NCollection_BaseVector", "Class NCollection_BaseVector - base for NCollection_Vector template");
	cls_NCollection_BaseVector.def("Clear", (void (NCollection_BaseVector::*)()) &NCollection_BaseVector::Clear, "Empty the vector of its objects");
	cls_NCollection_BaseVector.def("SetIncrement", (void (NCollection_BaseVector::*)(const Standard_Integer)) &NCollection_BaseVector::SetIncrement, "None", py::arg("aIncrement"));
	cls_NCollection_BaseVector.def("Allocator", (const opencascade::handle<NCollection_BaseAllocator> & (NCollection_BaseVector::*)() const ) &NCollection_BaseVector::Allocator, "Returns attached allocator");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_BaseMap.hxx
	py::class_<NCollection_BaseMap, std::unique_ptr<NCollection_BaseMap, py::nodelete>> cls_NCollection_BaseMap(mod, "NCollection_BaseMap", "Purpose: This is a base class for all Maps: Map DataMap DoubleMap IndexedMap IndexedDataMap Provides utilitites for managing the buckets.");
	cls_NCollection_BaseMap.def("NbBuckets", (Standard_Integer (NCollection_BaseMap::*)() const ) &NCollection_BaseMap::NbBuckets, "NbBuckets");
	cls_NCollection_BaseMap.def("Extent", (Standard_Integer (NCollection_BaseMap::*)() const ) &NCollection_BaseMap::Extent, "Extent");
	cls_NCollection_BaseMap.def("IsEmpty", (Standard_Boolean (NCollection_BaseMap::*)() const ) &NCollection_BaseMap::IsEmpty, "IsEmpty");
	cls_NCollection_BaseMap.def("Statistics", (void (NCollection_BaseMap::*)(Standard_OStream &) const ) &NCollection_BaseMap::Statistics, "Statistics", py::arg("S"));
	cls_NCollection_BaseMap.def("Allocator", (const opencascade::handle<NCollection_BaseAllocator> & (NCollection_BaseMap::*)() const ) &NCollection_BaseMap::Allocator, "Returns attached allocator");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_IncAllocator.hxx
	py::class_<NCollection_IncAllocator, opencascade::handle<NCollection_IncAllocator>, NCollection_BaseAllocator> cls_NCollection_IncAllocator(mod, "NCollection_IncAllocator", "Class NCollection_IncAllocator - incremental memory allocator. This class allocates memory on request returning the pointer to an allocated block. This memory is never returned to the system until the allocator is destroyed.");
	cls_NCollection_IncAllocator.def(py::init<>());
	cls_NCollection_IncAllocator.def(py::init<const size_t>(), py::arg("theBlockSize"));
	cls_NCollection_IncAllocator.def("Allocate", (void * (NCollection_IncAllocator::*)(const size_t)) &NCollection_IncAllocator::Allocate, "Allocate memory with given size. Returns NULL on failure", py::arg("size"));
	cls_NCollection_IncAllocator.def("Free", (void (NCollection_IncAllocator::*)(void *)) &NCollection_IncAllocator::Free, "Free a previously allocated memory. Does nothing", py::arg("anAddress"));
	cls_NCollection_IncAllocator.def("GetMemSize", (size_t (NCollection_IncAllocator::*)() const ) &NCollection_IncAllocator::GetMemSize, "Diagnostic method, returns the total allocated size");
	cls_NCollection_IncAllocator.def("Reallocate", (void * (NCollection_IncAllocator::*)(void *, const size_t, const size_t)) &NCollection_IncAllocator::Reallocate, "Reallocation: it is always allowed but is only efficient with the last allocated item", py::arg("anAddress"), py::arg("oldSize"), py::arg("newSize"));
	cls_NCollection_IncAllocator.def("Reset", [](NCollection_IncAllocator &self) -> void { return self.Reset(); });
	cls_NCollection_IncAllocator.def("Reset", (void (NCollection_IncAllocator::*)(const Standard_Boolean)) &NCollection_IncAllocator::Reset, "Re-initialize the allocator so that the next Allocate call should start allocating in the very begining as though the allocator is just constructed. Warning: make sure that all previously allocated data are no more used in your code!", py::arg("doReleaseMem"));
	cls_NCollection_IncAllocator.def_static("get_type_name_", (const char * (*)()) &NCollection_IncAllocator::get_type_name, "None");
	cls_NCollection_IncAllocator.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &NCollection_IncAllocator::get_type_descriptor, "None");
	cls_NCollection_IncAllocator.def("DynamicType", (const opencascade::handle<Standard_Type> & (NCollection_IncAllocator::*)() const ) &NCollection_IncAllocator::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_CellFilter.hxx
	py::class_<NCollection_CellFilter_InspectorXYZ, std::unique_ptr<NCollection_CellFilter_InspectorXYZ, Deleter<NCollection_CellFilter_InspectorXYZ>>> cls_NCollection_CellFilter_InspectorXYZ(mod, "NCollection_CellFilter_InspectorXYZ", "None");
	cls_NCollection_CellFilter_InspectorXYZ.def(py::init<>());
	cls_NCollection_CellFilter_InspectorXYZ.def_static("Coord_", (Standard_Real (*)(int, const NCollection_CellFilter_InspectorXYZ::Point &)) &NCollection_CellFilter_InspectorXYZ::Coord, "Access to co-ordinate", py::arg("i"), py::arg("thePnt"));
	cls_NCollection_CellFilter_InspectorXYZ.def("Shift", (NCollection_CellFilter_InspectorXYZ::Point (NCollection_CellFilter_InspectorXYZ::*)(const NCollection_CellFilter_InspectorXYZ::Point &, Standard_Real) const ) &NCollection_CellFilter_InspectorXYZ::Shift, "Auxiliary method to shift point by each coordinate on given value; useful for preparing a points range for Inspect with tolerance", py::arg("thePnt"), py::arg("theTol"));
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_CellFilter.hxx
	cls_NCollection_CellFilter_InspectorXYZ.attr("Dimension") = py::cast(int(NCollection_CellFilter_InspectorXYZ::Dimension));


	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_CellFilter.hxx
	py::class_<NCollection_CellFilter_InspectorXY, std::unique_ptr<NCollection_CellFilter_InspectorXY, Deleter<NCollection_CellFilter_InspectorXY>>> cls_NCollection_CellFilter_InspectorXY(mod, "NCollection_CellFilter_InspectorXY", "None");
	cls_NCollection_CellFilter_InspectorXY.def(py::init<>());
	cls_NCollection_CellFilter_InspectorXY.def_static("Coord_", (Standard_Real (*)(int, const NCollection_CellFilter_InspectorXY::Point &)) &NCollection_CellFilter_InspectorXY::Coord, "Access to co-ordinate", py::arg("i"), py::arg("thePnt"));
	cls_NCollection_CellFilter_InspectorXY.def("Shift", (NCollection_CellFilter_InspectorXY::Point (NCollection_CellFilter_InspectorXY::*)(const NCollection_CellFilter_InspectorXY::Point &, Standard_Real) const ) &NCollection_CellFilter_InspectorXY::Shift, "Auxiliary method to shift point by each coordinate on given value; useful for preparing a points range for Inspect with tolerance", py::arg("thePnt"), py::arg("theTol"));
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_CellFilter.hxx
	cls_NCollection_CellFilter_InspectorXY.attr("Dimension") = py::cast(int(NCollection_CellFilter_InspectorXY::Dimension));


	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_StdAllocator.hxx
	py::class_<NCollection_StdAllocator<void>, std::unique_ptr<NCollection_StdAllocator<void>, Deleter<NCollection_StdAllocator<void>>>> cls_NCollection_StdAllocator_void(mod, "NCollection_StdAllocator_void", "Implements specialization NCollection_StdAllocator<void>. Specialization is of low value and should normally be avoided in favor of a typed specialization.");
	cls_NCollection_StdAllocator_void.def(py::init<>());
	cls_NCollection_StdAllocator_void.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAlloc"));
	cls_NCollection_StdAllocator_void.def(py::init([] (const NCollection_StdAllocator<void> &other) {return new NCollection_StdAllocator<void>(other);}), "Copy constructor", py::arg("other"));
	cls_NCollection_StdAllocator_void.def("Allocator", (const opencascade::handle<NCollection_BaseAllocator> & (NCollection_StdAllocator<void>::*)() const ) &NCollection_StdAllocator<void>::Allocator, "Returns an underlying NCollection_BaseAllocator instance. Returns an object specified in the constructor.");
	cls_NCollection_StdAllocator_void.def("assign", (NCollection_StdAllocator<void> & (NCollection_StdAllocator<void>::*)(const NCollection_StdAllocator<void> &)) &NCollection_StdAllocator<void>::operator=, py::is_operator(), "Assignment operator", py::arg("X"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_UtfString.lxx
	py::class_<NCollection_UtfStringTool, std::unique_ptr<NCollection_UtfStringTool, Deleter<NCollection_UtfStringTool>>> cls_NCollection_UtfStringTool(mod, "NCollection_UtfStringTool", "Auxiliary convertion tool.");
	cls_NCollection_UtfStringTool.def(py::init<>());
	cls_NCollection_UtfStringTool.def("FromLocale", (wchar_t * (NCollection_UtfStringTool::*)(const char *)) &NCollection_UtfStringTool::FromLocale, "Convert the string from current locale into UNICODE (wide characters) using system APIs. Returned pointer will be released by this tool.", py::arg("theString"));
	cls_NCollection_UtfStringTool.def_static("ToLocale_", (bool (*)(const wchar_t *, char *, const Standard_Integer)) &NCollection_UtfStringTool::ToLocale, "Convert the UNICODE (wide characters) string into locale using system APIs.", py::arg("theWideString"), py::arg("theBuffer"), py::arg("theSizeBytes"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_AccAllocator.hxx
	py::class_<NCollection_AccAllocator, opencascade::handle<NCollection_AccAllocator>, NCollection_BaseAllocator> cls_NCollection_AccAllocator(mod, "NCollection_AccAllocator", "Class NCollection_AccAllocator - accumulating memory allocator. This class allocates memory on request returning the pointer to the allocated space. The allocation units are grouped in blocks requested from the system as required. This memory is returned to the system when all allocations in a block are freed.");
	cls_NCollection_AccAllocator.def(py::init<>());
	cls_NCollection_AccAllocator.def(py::init<const size_t>(), py::arg("theBlockSize"));
	cls_NCollection_AccAllocator.def("Allocate", (void * (NCollection_AccAllocator::*)(const size_t)) &NCollection_AccAllocator::Allocate, "Allocate memory with given size", py::arg("theSize"));
	cls_NCollection_AccAllocator.def("Free", (void (NCollection_AccAllocator::*)(void *)) &NCollection_AccAllocator::Free, "Free a previously allocated memory; memory is returned to the OS when all allocations in some block are freed", py::arg("theAddress"));
	cls_NCollection_AccAllocator.def_static("get_type_name_", (const char * (*)()) &NCollection_AccAllocator::get_type_name, "None");
	cls_NCollection_AccAllocator.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &NCollection_AccAllocator::get_type_descriptor, "None");
	cls_NCollection_AccAllocator.def("DynamicType", (const opencascade::handle<Standard_Type> & (NCollection_AccAllocator::*)() const ) &NCollection_AccAllocator::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_AlignedAllocator.hxx
	py::class_<NCollection_AlignedAllocator, opencascade::handle<NCollection_AlignedAllocator>, NCollection_BaseAllocator> cls_NCollection_AlignedAllocator(mod, "NCollection_AlignedAllocator", "NCollection allocator with managed memory alignment capabilities.");
	cls_NCollection_AlignedAllocator.def(py::init<const size_t>(), py::arg("theAlignment"));
	cls_NCollection_AlignedAllocator.def("Allocate", (void * (NCollection_AlignedAllocator::*)(const size_t)) &NCollection_AlignedAllocator::Allocate, "Allocate memory with given size. Returns NULL on failure.", py::arg("theSize"));
	cls_NCollection_AlignedAllocator.def("Free", (void (NCollection_AlignedAllocator::*)(void *)) &NCollection_AlignedAllocator::Free, "Free a previously allocated memory.", py::arg("thePtr"));
	cls_NCollection_AlignedAllocator.def_static("get_type_name_", (const char * (*)()) &NCollection_AlignedAllocator::get_type_name, "None");
	cls_NCollection_AlignedAllocator.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &NCollection_AlignedAllocator::get_type_descriptor, "None");
	cls_NCollection_AlignedAllocator.def("DynamicType", (const opencascade::handle<Standard_Type> & (NCollection_AlignedAllocator::*)() const ) &NCollection_AlignedAllocator::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_HeapAllocator.hxx
	py::class_<NCollection_HeapAllocator, opencascade::handle<NCollection_HeapAllocator>, NCollection_BaseAllocator> cls_NCollection_HeapAllocator(mod, "NCollection_HeapAllocator", "Allocator that uses the global dynamic heap (malloc / free).");
	cls_NCollection_HeapAllocator.def("Allocate", (void * (NCollection_HeapAllocator::*)(const Standard_Size)) &NCollection_HeapAllocator::Allocate, "None", py::arg("theSize"));
	cls_NCollection_HeapAllocator.def("Free", (void (NCollection_HeapAllocator::*)(void *)) &NCollection_HeapAllocator::Free, "None", py::arg("anAddress"));
	cls_NCollection_HeapAllocator.def_static("GlobalHeapAllocator_", (const opencascade::handle<NCollection_HeapAllocator> & (*)()) &NCollection_HeapAllocator::GlobalHeapAllocator, "None");
	cls_NCollection_HeapAllocator.def_static("get_type_name_", (const char * (*)()) &NCollection_HeapAllocator::get_type_name, "None");
	cls_NCollection_HeapAllocator.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &NCollection_HeapAllocator::get_type_descriptor, "None");
	cls_NCollection_HeapAllocator.def("DynamicType", (const opencascade::handle<Standard_Type> & (NCollection_HeapAllocator::*)() const ) &NCollection_HeapAllocator::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_SparseArrayBase.hxx
	py::class_<NCollection_SparseArrayBase, std::unique_ptr<NCollection_SparseArrayBase, py::nodelete>> cls_NCollection_SparseArrayBase(mod, "NCollection_SparseArrayBase", "Base class for NCollection_SparseArray; provides non-template implementation of general mechanics of block allocation, items creation / deletion etc.");
	cls_NCollection_SparseArrayBase.def("Clear", (void (NCollection_SparseArrayBase::*)()) &NCollection_SparseArrayBase::Clear, "Clears all the data");
	cls_NCollection_SparseArrayBase.def("Size", (Standard_Size (NCollection_SparseArrayBase::*)() const ) &NCollection_SparseArrayBase::Size, "Returns number of currently contained items");
	cls_NCollection_SparseArrayBase.def("HasValue", (Standard_Boolean (NCollection_SparseArrayBase::*)(const Standard_Size) const ) &NCollection_SparseArrayBase::HasValue, "Check whether the value at given index is set", py::arg("theIndex"));
	cls_NCollection_SparseArrayBase.def("UnsetValue", (Standard_Boolean (NCollection_SparseArrayBase::*)(const Standard_Size)) &NCollection_SparseArrayBase::UnsetValue, "Deletes the item from the array; returns True if that item was defined", py::arg("theIndex"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_WinHeapAllocator.hxx
	py::class_<NCollection_WinHeapAllocator, opencascade::handle<NCollection_WinHeapAllocator>, NCollection_BaseAllocator> cls_NCollection_WinHeapAllocator(mod, "NCollection_WinHeapAllocator", "This memory allocator creates dedicated heap for allocations. This technics available only on Windows platform (no alternative on Unix systems). It may be used to take control over memory fragmentation because on destruction ALL allocated memory will be released to the system.");
	cls_NCollection_WinHeapAllocator.def(py::init<>());
	cls_NCollection_WinHeapAllocator.def(py::init<const size_t>(), py::arg("theInitSizeBytes"));
	cls_NCollection_WinHeapAllocator.def("Allocate", (void * (NCollection_WinHeapAllocator::*)(const Standard_Size)) &NCollection_WinHeapAllocator::Allocate, "Allocate memory", py::arg("theSize"));
	cls_NCollection_WinHeapAllocator.def("Free", (void (NCollection_WinHeapAllocator::*)(void *)) &NCollection_WinHeapAllocator::Free, "Release memory", py::arg("theAddress"));
	cls_NCollection_WinHeapAllocator.def_static("get_type_name_", (const char * (*)()) &NCollection_WinHeapAllocator::get_type_name, "None");
	cls_NCollection_WinHeapAllocator.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &NCollection_WinHeapAllocator::get_type_descriptor, "None");
	cls_NCollection_WinHeapAllocator.def("DynamicType", (const opencascade::handle<Standard_Type> & (NCollection_WinHeapAllocator::*)() const ) &NCollection_WinHeapAllocator::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_BaseSequence.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_BaseList.hxx
	if (py::hasattr(mod, "NCollection_DelMapNode")) {
		mod.attr("NCollection_DelListNode") = mod.attr("NCollection_DelMapNode");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_BaseMap.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_UtfIterator.hxx
	bind_NCollection_UtfIterator<char>(mod, "NCollection_Utf8Iter");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_UtfIterator.hxx
	bind_NCollection_UtfIterator<char16_t>(mod, "NCollection_Utf16Iter");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_UtfIterator.hxx
	bind_NCollection_UtfIterator<char32_t>(mod, "NCollection_Utf32Iter");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_UtfIterator.hxx
	bind_NCollection_UtfIterator<wchar_t>(mod, "NCollection_UtfWideIter");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_UtfString.hxx
	if (py::hasattr(mod, "NCollection_String")) {
		mod.attr("NCollection_Utf8String") = mod.attr("NCollection_String");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_UtfString.hxx
	bind_NCollection_UtfString<char16_t>(mod, "NCollection_Utf16String");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_UtfString.hxx
	bind_NCollection_UtfString<char32_t>(mod, "NCollection_Utf32String");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_UtfString.hxx
	bind_NCollection_UtfString<wchar_t>(mod, "NCollection_UtfWideString");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_String.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_SparseArrayBase.hxx
	other_mod = py::module::import("OCCT.Standard");
	if (py::hasattr(other_mod, "Standard_Size")) {
		mod.attr("Standard_Size") = other_mod.attr("Standard_Size");
	}


}
