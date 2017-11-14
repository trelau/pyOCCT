#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <gp_XYZ.hxx>
#include <gp_XY.hxx>

#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Type.hxx>
#include <NCollection_BaseSequence.hxx>
#include <NCollection_Buffer.hxx>
#include <NCollection_ListNode.hxx>
#include <NCollection_BaseList.hxx>
#include <NCollection_BaseVector.hxx>
#include <NCollection_BaseMap.hxx>
#include <Standard_OStream.hxx>
#include <NCollection_IncAllocator.hxx>
#include <NCollection_CellFilter.hxx>
#include <NCollection_StdAllocator.hxx>
#include <NCollection_UtfIterator.hxx>
#include <NCollection_UtfString.hxx>
#include <NCollection_String.hxx>
#include <NCollection_AccAllocator.hxx>
#include <NCollection_AlignedAllocator.hxx>
#include <NCollection_HeapAllocator.hxx>
#include <NCollection_SparseArrayBase.hxx>
#include <NCollection_WinHeapAllocator.hxx>

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
	// FIXME cls_NCollection_ListNode.def("Next", (NCollection_ListNode *& (NCollection_ListNode::*)()) &NCollection_ListNode::Next, "Next pointer access");
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
	py::class_<NCollection_CellFilter_InspectorXY, std::unique_ptr<NCollection_CellFilter_InspectorXY, Deleter<NCollection_CellFilter_InspectorXY>>> cls_NCollection_CellFilter_InspectorXY(mod, "NCollection_CellFilter_InspectorXY", "None");
	cls_NCollection_CellFilter_InspectorXY.def(py::init<>());
	cls_NCollection_CellFilter_InspectorXY.def_static("Coord_", (Standard_Real (*)(int, const NCollection_CellFilter_InspectorXY::Point &)) &NCollection_CellFilter_InspectorXY::Coord, "Access to co-ordinate", py::arg("i"), py::arg("thePnt"));
	cls_NCollection_CellFilter_InspectorXY.def("Shift", (NCollection_CellFilter_InspectorXY::Point (NCollection_CellFilter_InspectorXY::*)(const NCollection_CellFilter_InspectorXY::Point &, Standard_Real) const ) &NCollection_CellFilter_InspectorXY::Shift, "Auxiliary method to shift point by each coordinate on given value; useful for preparing a points range for Inspect with tolerance", py::arg("thePnt"), py::arg("theTol"));

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
	if (py::hasattr(mod, "NCollection_DelMapNode")) {
		mod.attr("NCollection_DelListNode") = mod.attr("NCollection_DelMapNode");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_BaseMap.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_UtfIterator.hxx
	py::class_<NCollection_Utf8Iter, std::unique_ptr<NCollection_Utf8Iter, Deleter<NCollection_Utf8Iter>>> cls_NCollection_Utf8Iter(mod, "NCollection_Utf8Iter", "Template class for Unicode strings support. It defines an iterator and provide correct way to read multi-byte text (UTF-8 and UTF-16) and convert it from one to another. The current value of iterator returned as UTF-32 Unicode code.");
	cls_NCollection_Utf8Iter.def(py::init<const Standard_Utf8Char *>(), py::arg("theString"));
	cls_NCollection_Utf8Iter.def("Init", (void (NCollection_Utf8Iter::*)(const Standard_Utf8Char *)) &NCollection_Utf8Iter::Init, "Initialize iterator within specified NULL-terminated string.", py::arg("theString"));
	cls_NCollection_Utf8Iter.def("plus_plus", (NCollection_Utf8Iter & (NCollection_Utf8Iter::*)()) &NCollection_Utf8Iter::operator++, py::is_operator(), "Pre-increment operator. Reads the next unicode character. Notice - no protection against overrun!");
	cls_NCollection_Utf8Iter.def("plus_plus", (NCollection_Utf8Iter (NCollection_Utf8Iter::*)(int)) &NCollection_Utf8Iter::operator++, py::is_operator(), "Post-increment operator. Notice - no protection against overrun!", py::arg(""));
	cls_NCollection_Utf8Iter.def("__eq__", (bool (NCollection_Utf8Iter::*)(const NCollection_Utf8Iter &) const ) &NCollection_Utf8Iter::operator==, py::is_operator(), "Equality operator.", py::arg("theRight"));
	cls_NCollection_Utf8Iter.def("IsValid", (bool (NCollection_Utf8Iter::*)() const ) &NCollection_Utf8Iter::IsValid, "Return true if Unicode symbol is within valid range.");
	cls_NCollection_Utf8Iter.def("__mul__", (Standard_Utf32Char (NCollection_Utf8Iter::*)() const ) &NCollection_Utf8Iter::operator*, py::is_operator(), "Dereference operator.");
	cls_NCollection_Utf8Iter.def("BufferHere", (const Standard_Utf8Char * (NCollection_Utf8Iter::*)() const ) &NCollection_Utf8Iter::BufferHere, "Buffer-fetching getter.");
	cls_NCollection_Utf8Iter.def("ChangeBufferHere", (Standard_Utf8Char * (NCollection_Utf8Iter::*)()) &NCollection_Utf8Iter::ChangeBufferHere, "Buffer-fetching getter. Dangerous! Iterator should be reinitialized on buffer change.");
	cls_NCollection_Utf8Iter.def("BufferNext", (const Standard_Utf8Char * (NCollection_Utf8Iter::*)() const ) &NCollection_Utf8Iter::BufferNext, "Buffer-fetching getter.");
	cls_NCollection_Utf8Iter.def("Index", (Standard_Integer (NCollection_Utf8Iter::*)() const ) &NCollection_Utf8Iter::Index, "Returns the index displacement from iterator intialization");
	cls_NCollection_Utf8Iter.def("AdvanceBytesUtf8", (Standard_Integer (NCollection_Utf8Iter::*)() const ) &NCollection_Utf8Iter::AdvanceBytesUtf8, "Returns the advance in bytes to store current symbol in UTF-8. 0 means an invalid symbol; 1-4 bytes are valid range.");
	cls_NCollection_Utf8Iter.def("AdvanceBytesUtf16", (Standard_Integer (NCollection_Utf8Iter::*)() const ) &NCollection_Utf8Iter::AdvanceBytesUtf16, "Returns the advance in bytes to store current symbol in UTF-16. 0 means an invalid symbol; 2 bytes is a general case; 4 bytes for surrogate pair.");
	cls_NCollection_Utf8Iter.def("AdvanceCodeUnitsUtf16", (Standard_Integer (NCollection_Utf8Iter::*)() const ) &NCollection_Utf8Iter::AdvanceCodeUnitsUtf16, "Returns the advance in bytes to store current symbol in UTF-16. 0 means an invalid symbol; 1 16-bit code unit is a general case; 2 16-bit code units for surrogate pair.");
	cls_NCollection_Utf8Iter.def("AdvanceBytesUtf32", (Standard_Integer (NCollection_Utf8Iter::*)() const ) &NCollection_Utf8Iter::AdvanceBytesUtf32, "Returns the advance in bytes to store current symbol in UTF-32. Always 4 bytes (method for consistency).");
	cls_NCollection_Utf8Iter.def("GetUtf8", (Standard_Utf8Char * (NCollection_Utf8Iter::*)(Standard_Utf8Char *) const ) &NCollection_Utf8Iter::GetUtf8, "Fill the UTF-8 buffer within current Unicode symbol. Use method AdvanceUtf8() to allocate buffer with enough size.", py::arg("theBuffer"));
	cls_NCollection_Utf8Iter.def("GetUtf8", (Standard_Utf8UChar * (NCollection_Utf8Iter::*)(Standard_Utf8UChar *) const ) &NCollection_Utf8Iter::GetUtf8, "None", py::arg("theBuffer"));
	cls_NCollection_Utf8Iter.def("GetUtf16", (Standard_Utf16Char * (NCollection_Utf8Iter::*)(Standard_Utf16Char *) const ) &NCollection_Utf8Iter::GetUtf16, "Fill the UTF-16 buffer within current Unicode symbol. Use method AdvanceUtf16() to allocate buffer with enough size.", py::arg("theBuffer"));
	cls_NCollection_Utf8Iter.def("GetUtf32", (Standard_Utf32Char * (NCollection_Utf8Iter::*)(Standard_Utf32Char *) const ) &NCollection_Utf8Iter::GetUtf32, "Fill the UTF-32 buffer within current Unicode symbol. Use method AdvanceUtf32() to allocate buffer with enough size.", py::arg("theBuffer"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_UtfIterator.hxx
	py::class_<NCollection_Utf16Iter, std::unique_ptr<NCollection_Utf16Iter, Deleter<NCollection_Utf16Iter>>> cls_NCollection_Utf16Iter(mod, "NCollection_Utf16Iter", "Template class for Unicode strings support. It defines an iterator and provide correct way to read multi-byte text (UTF-8 and UTF-16) and convert it from one to another. The current value of iterator returned as UTF-32 Unicode code.");
	cls_NCollection_Utf16Iter.def(py::init<const Standard_Utf16Char *>(), py::arg("theString"));
	cls_NCollection_Utf16Iter.def("Init", (void (NCollection_Utf16Iter::*)(const Standard_Utf16Char *)) &NCollection_Utf16Iter::Init, "Initialize iterator within specified NULL-terminated string.", py::arg("theString"));
	cls_NCollection_Utf16Iter.def("plus_plus", (NCollection_Utf16Iter & (NCollection_Utf16Iter::*)()) &NCollection_Utf16Iter::operator++, py::is_operator(), "Pre-increment operator. Reads the next unicode character. Notice - no protection against overrun!");
	cls_NCollection_Utf16Iter.def("plus_plus", (NCollection_Utf16Iter (NCollection_Utf16Iter::*)(int)) &NCollection_Utf16Iter::operator++, py::is_operator(), "Post-increment operator. Notice - no protection against overrun!", py::arg(""));
	cls_NCollection_Utf16Iter.def("__eq__", (bool (NCollection_Utf16Iter::*)(const NCollection_Utf16Iter &) const ) &NCollection_Utf16Iter::operator==, py::is_operator(), "Equality operator.", py::arg("theRight"));
	cls_NCollection_Utf16Iter.def("IsValid", (bool (NCollection_Utf16Iter::*)() const ) &NCollection_Utf16Iter::IsValid, "Return true if Unicode symbol is within valid range.");
	cls_NCollection_Utf16Iter.def("__mul__", (Standard_Utf32Char (NCollection_Utf16Iter::*)() const ) &NCollection_Utf16Iter::operator*, py::is_operator(), "Dereference operator.");
	cls_NCollection_Utf16Iter.def("BufferHere", (const Standard_Utf16Char * (NCollection_Utf16Iter::*)() const ) &NCollection_Utf16Iter::BufferHere, "Buffer-fetching getter.");
	cls_NCollection_Utf16Iter.def("ChangeBufferHere", (Standard_Utf16Char * (NCollection_Utf16Iter::*)()) &NCollection_Utf16Iter::ChangeBufferHere, "Buffer-fetching getter. Dangerous! Iterator should be reinitialized on buffer change.");
	cls_NCollection_Utf16Iter.def("BufferNext", (const Standard_Utf16Char * (NCollection_Utf16Iter::*)() const ) &NCollection_Utf16Iter::BufferNext, "Buffer-fetching getter.");
	cls_NCollection_Utf16Iter.def("Index", (Standard_Integer (NCollection_Utf16Iter::*)() const ) &NCollection_Utf16Iter::Index, "Returns the index displacement from iterator intialization");
	cls_NCollection_Utf16Iter.def("AdvanceBytesUtf8", (Standard_Integer (NCollection_Utf16Iter::*)() const ) &NCollection_Utf16Iter::AdvanceBytesUtf8, "Returns the advance in bytes to store current symbol in UTF-8. 0 means an invalid symbol; 1-4 bytes are valid range.");
	cls_NCollection_Utf16Iter.def("AdvanceBytesUtf16", (Standard_Integer (NCollection_Utf16Iter::*)() const ) &NCollection_Utf16Iter::AdvanceBytesUtf16, "Returns the advance in bytes to store current symbol in UTF-16. 0 means an invalid symbol; 2 bytes is a general case; 4 bytes for surrogate pair.");
	cls_NCollection_Utf16Iter.def("AdvanceCodeUnitsUtf16", (Standard_Integer (NCollection_Utf16Iter::*)() const ) &NCollection_Utf16Iter::AdvanceCodeUnitsUtf16, "Returns the advance in bytes to store current symbol in UTF-16. 0 means an invalid symbol; 1 16-bit code unit is a general case; 2 16-bit code units for surrogate pair.");
	cls_NCollection_Utf16Iter.def("AdvanceBytesUtf32", (Standard_Integer (NCollection_Utf16Iter::*)() const ) &NCollection_Utf16Iter::AdvanceBytesUtf32, "Returns the advance in bytes to store current symbol in UTF-32. Always 4 bytes (method for consistency).");
	cls_NCollection_Utf16Iter.def("GetUtf8", (Standard_Utf8Char * (NCollection_Utf16Iter::*)(Standard_Utf8Char *) const ) &NCollection_Utf16Iter::GetUtf8, "Fill the UTF-8 buffer within current Unicode symbol. Use method AdvanceUtf8() to allocate buffer with enough size.", py::arg("theBuffer"));
	cls_NCollection_Utf16Iter.def("GetUtf8", (Standard_Utf8UChar * (NCollection_Utf16Iter::*)(Standard_Utf8UChar *) const ) &NCollection_Utf16Iter::GetUtf8, "None", py::arg("theBuffer"));
	cls_NCollection_Utf16Iter.def("GetUtf16", (Standard_Utf16Char * (NCollection_Utf16Iter::*)(Standard_Utf16Char *) const ) &NCollection_Utf16Iter::GetUtf16, "Fill the UTF-16 buffer within current Unicode symbol. Use method AdvanceUtf16() to allocate buffer with enough size.", py::arg("theBuffer"));
	cls_NCollection_Utf16Iter.def("GetUtf32", (Standard_Utf32Char * (NCollection_Utf16Iter::*)(Standard_Utf32Char *) const ) &NCollection_Utf16Iter::GetUtf32, "Fill the UTF-32 buffer within current Unicode symbol. Use method AdvanceUtf32() to allocate buffer with enough size.", py::arg("theBuffer"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_UtfIterator.hxx
	py::class_<NCollection_Utf32Iter, std::unique_ptr<NCollection_Utf32Iter, Deleter<NCollection_Utf32Iter>>> cls_NCollection_Utf32Iter(mod, "NCollection_Utf32Iter", "Template class for Unicode strings support. It defines an iterator and provide correct way to read multi-byte text (UTF-8 and UTF-16) and convert it from one to another. The current value of iterator returned as UTF-32 Unicode code.");
	cls_NCollection_Utf32Iter.def(py::init<const Standard_Utf32Char *>(), py::arg("theString"));
	cls_NCollection_Utf32Iter.def("Init", (void (NCollection_Utf32Iter::*)(const Standard_Utf32Char *)) &NCollection_Utf32Iter::Init, "Initialize iterator within specified NULL-terminated string.", py::arg("theString"));
	cls_NCollection_Utf32Iter.def("plus_plus", (NCollection_Utf32Iter & (NCollection_Utf32Iter::*)()) &NCollection_Utf32Iter::operator++, py::is_operator(), "Pre-increment operator. Reads the next unicode character. Notice - no protection against overrun!");
	cls_NCollection_Utf32Iter.def("plus_plus", (NCollection_Utf32Iter (NCollection_Utf32Iter::*)(int)) &NCollection_Utf32Iter::operator++, py::is_operator(), "Post-increment operator. Notice - no protection against overrun!", py::arg(""));
	cls_NCollection_Utf32Iter.def("__eq__", (bool (NCollection_Utf32Iter::*)(const NCollection_Utf32Iter &) const ) &NCollection_Utf32Iter::operator==, py::is_operator(), "Equality operator.", py::arg("theRight"));
	cls_NCollection_Utf32Iter.def("IsValid", (bool (NCollection_Utf32Iter::*)() const ) &NCollection_Utf32Iter::IsValid, "Return true if Unicode symbol is within valid range.");
	cls_NCollection_Utf32Iter.def("__mul__", (Standard_Utf32Char (NCollection_Utf32Iter::*)() const ) &NCollection_Utf32Iter::operator*, py::is_operator(), "Dereference operator.");
	cls_NCollection_Utf32Iter.def("BufferHere", (const Standard_Utf32Char * (NCollection_Utf32Iter::*)() const ) &NCollection_Utf32Iter::BufferHere, "Buffer-fetching getter.");
	cls_NCollection_Utf32Iter.def("ChangeBufferHere", (Standard_Utf32Char * (NCollection_Utf32Iter::*)()) &NCollection_Utf32Iter::ChangeBufferHere, "Buffer-fetching getter. Dangerous! Iterator should be reinitialized on buffer change.");
	cls_NCollection_Utf32Iter.def("BufferNext", (const Standard_Utf32Char * (NCollection_Utf32Iter::*)() const ) &NCollection_Utf32Iter::BufferNext, "Buffer-fetching getter.");
	cls_NCollection_Utf32Iter.def("Index", (Standard_Integer (NCollection_Utf32Iter::*)() const ) &NCollection_Utf32Iter::Index, "Returns the index displacement from iterator intialization");
	cls_NCollection_Utf32Iter.def("AdvanceBytesUtf8", (Standard_Integer (NCollection_Utf32Iter::*)() const ) &NCollection_Utf32Iter::AdvanceBytesUtf8, "Returns the advance in bytes to store current symbol in UTF-8. 0 means an invalid symbol; 1-4 bytes are valid range.");
	cls_NCollection_Utf32Iter.def("AdvanceBytesUtf16", (Standard_Integer (NCollection_Utf32Iter::*)() const ) &NCollection_Utf32Iter::AdvanceBytesUtf16, "Returns the advance in bytes to store current symbol in UTF-16. 0 means an invalid symbol; 2 bytes is a general case; 4 bytes for surrogate pair.");
	cls_NCollection_Utf32Iter.def("AdvanceCodeUnitsUtf16", (Standard_Integer (NCollection_Utf32Iter::*)() const ) &NCollection_Utf32Iter::AdvanceCodeUnitsUtf16, "Returns the advance in bytes to store current symbol in UTF-16. 0 means an invalid symbol; 1 16-bit code unit is a general case; 2 16-bit code units for surrogate pair.");
	cls_NCollection_Utf32Iter.def("AdvanceBytesUtf32", (Standard_Integer (NCollection_Utf32Iter::*)() const ) &NCollection_Utf32Iter::AdvanceBytesUtf32, "Returns the advance in bytes to store current symbol in UTF-32. Always 4 bytes (method for consistency).");
	cls_NCollection_Utf32Iter.def("GetUtf8", (Standard_Utf8Char * (NCollection_Utf32Iter::*)(Standard_Utf8Char *) const ) &NCollection_Utf32Iter::GetUtf8, "Fill the UTF-8 buffer within current Unicode symbol. Use method AdvanceUtf8() to allocate buffer with enough size.", py::arg("theBuffer"));
	cls_NCollection_Utf32Iter.def("GetUtf8", (Standard_Utf8UChar * (NCollection_Utf32Iter::*)(Standard_Utf8UChar *) const ) &NCollection_Utf32Iter::GetUtf8, "None", py::arg("theBuffer"));
	cls_NCollection_Utf32Iter.def("GetUtf16", (Standard_Utf16Char * (NCollection_Utf32Iter::*)(Standard_Utf16Char *) const ) &NCollection_Utf32Iter::GetUtf16, "Fill the UTF-16 buffer within current Unicode symbol. Use method AdvanceUtf16() to allocate buffer with enough size.", py::arg("theBuffer"));
	cls_NCollection_Utf32Iter.def("GetUtf32", (Standard_Utf32Char * (NCollection_Utf32Iter::*)(Standard_Utf32Char *) const ) &NCollection_Utf32Iter::GetUtf32, "Fill the UTF-32 buffer within current Unicode symbol. Use method AdvanceUtf32() to allocate buffer with enough size.", py::arg("theBuffer"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_UtfIterator.hxx
	py::class_<NCollection_UtfWideIter, std::unique_ptr<NCollection_UtfWideIter, Deleter<NCollection_UtfWideIter>>> cls_NCollection_UtfWideIter(mod, "NCollection_UtfWideIter", "Template class for Unicode strings support. It defines an iterator and provide correct way to read multi-byte text (UTF-8 and UTF-16) and convert it from one to another. The current value of iterator returned as UTF-32 Unicode code.");
	cls_NCollection_UtfWideIter.def(py::init<const Standard_WideChar *>(), py::arg("theString"));
	cls_NCollection_UtfWideIter.def("Init", (void (NCollection_UtfWideIter::*)(const Standard_WideChar *)) &NCollection_UtfWideIter::Init, "Initialize iterator within specified NULL-terminated string.", py::arg("theString"));
	cls_NCollection_UtfWideIter.def("plus_plus", (NCollection_UtfWideIter & (NCollection_UtfWideIter::*)()) &NCollection_UtfWideIter::operator++, py::is_operator(), "Pre-increment operator. Reads the next unicode character. Notice - no protection against overrun!");
	cls_NCollection_UtfWideIter.def("plus_plus", (NCollection_UtfWideIter (NCollection_UtfWideIter::*)(int)) &NCollection_UtfWideIter::operator++, py::is_operator(), "Post-increment operator. Notice - no protection against overrun!", py::arg(""));
	cls_NCollection_UtfWideIter.def("__eq__", (bool (NCollection_UtfWideIter::*)(const NCollection_UtfWideIter &) const ) &NCollection_UtfWideIter::operator==, py::is_operator(), "Equality operator.", py::arg("theRight"));
	cls_NCollection_UtfWideIter.def("IsValid", (bool (NCollection_UtfWideIter::*)() const ) &NCollection_UtfWideIter::IsValid, "Return true if Unicode symbol is within valid range.");
	cls_NCollection_UtfWideIter.def("__mul__", (Standard_Utf32Char (NCollection_UtfWideIter::*)() const ) &NCollection_UtfWideIter::operator*, py::is_operator(), "Dereference operator.");
	cls_NCollection_UtfWideIter.def("BufferHere", (const Standard_WideChar * (NCollection_UtfWideIter::*)() const ) &NCollection_UtfWideIter::BufferHere, "Buffer-fetching getter.");
	cls_NCollection_UtfWideIter.def("ChangeBufferHere", (Standard_WideChar * (NCollection_UtfWideIter::*)()) &NCollection_UtfWideIter::ChangeBufferHere, "Buffer-fetching getter. Dangerous! Iterator should be reinitialized on buffer change.");
	cls_NCollection_UtfWideIter.def("BufferNext", (const Standard_WideChar * (NCollection_UtfWideIter::*)() const ) &NCollection_UtfWideIter::BufferNext, "Buffer-fetching getter.");
	cls_NCollection_UtfWideIter.def("Index", (Standard_Integer (NCollection_UtfWideIter::*)() const ) &NCollection_UtfWideIter::Index, "Returns the index displacement from iterator intialization");
	cls_NCollection_UtfWideIter.def("AdvanceBytesUtf8", (Standard_Integer (NCollection_UtfWideIter::*)() const ) &NCollection_UtfWideIter::AdvanceBytesUtf8, "Returns the advance in bytes to store current symbol in UTF-8. 0 means an invalid symbol; 1-4 bytes are valid range.");
	cls_NCollection_UtfWideIter.def("AdvanceBytesUtf16", (Standard_Integer (NCollection_UtfWideIter::*)() const ) &NCollection_UtfWideIter::AdvanceBytesUtf16, "Returns the advance in bytes to store current symbol in UTF-16. 0 means an invalid symbol; 2 bytes is a general case; 4 bytes for surrogate pair.");
	cls_NCollection_UtfWideIter.def("AdvanceCodeUnitsUtf16", (Standard_Integer (NCollection_UtfWideIter::*)() const ) &NCollection_UtfWideIter::AdvanceCodeUnitsUtf16, "Returns the advance in bytes to store current symbol in UTF-16. 0 means an invalid symbol; 1 16-bit code unit is a general case; 2 16-bit code units for surrogate pair.");
	cls_NCollection_UtfWideIter.def("AdvanceBytesUtf32", (Standard_Integer (NCollection_UtfWideIter::*)() const ) &NCollection_UtfWideIter::AdvanceBytesUtf32, "Returns the advance in bytes to store current symbol in UTF-32. Always 4 bytes (method for consistency).");
	cls_NCollection_UtfWideIter.def("GetUtf8", (Standard_Utf8Char * (NCollection_UtfWideIter::*)(Standard_Utf8Char *) const ) &NCollection_UtfWideIter::GetUtf8, "Fill the UTF-8 buffer within current Unicode symbol. Use method AdvanceUtf8() to allocate buffer with enough size.", py::arg("theBuffer"));
	cls_NCollection_UtfWideIter.def("GetUtf8", (Standard_Utf8UChar * (NCollection_UtfWideIter::*)(Standard_Utf8UChar *) const ) &NCollection_UtfWideIter::GetUtf8, "None", py::arg("theBuffer"));
	cls_NCollection_UtfWideIter.def("GetUtf16", (Standard_Utf16Char * (NCollection_UtfWideIter::*)(Standard_Utf16Char *) const ) &NCollection_UtfWideIter::GetUtf16, "Fill the UTF-16 buffer within current Unicode symbol. Use method AdvanceUtf16() to allocate buffer with enough size.", py::arg("theBuffer"));
	cls_NCollection_UtfWideIter.def("GetUtf32", (Standard_Utf32Char * (NCollection_UtfWideIter::*)(Standard_Utf32Char *) const ) &NCollection_UtfWideIter::GetUtf32, "Fill the UTF-32 buffer within current Unicode symbol. Use method AdvanceUtf32() to allocate buffer with enough size.", py::arg("theBuffer"));

	if (py::hasattr(mod, "NCollection_String")) {
		mod.attr("NCollection_Utf8String") = mod.attr("NCollection_String");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_UtfString.hxx
	py::class_<NCollection_Utf16String, std::unique_ptr<NCollection_Utf16String, Deleter<NCollection_Utf16String>>> cls_NCollection_Utf16String(mod, "NCollection_Utf16String", "This template class represent constant UTF-* string. String stored in memory continuously, always NULL-terminated and can be used as standard C-string using ToCString() method.");
	cls_NCollection_Utf16String.def(py::init<>());
	cls_NCollection_Utf16String.def(py::init([] (const NCollection_Utf16String &other) {return new NCollection_Utf16String(other);}), "Copy constructor", py::arg("other"));
	cls_NCollection_Utf16String.def(py::init<const char *>(), py::arg("theCopyUtf8"));
	cls_NCollection_Utf16String.def(py::init<const char *, const Standard_Integer>(), py::arg("theCopyUtf8"), py::arg("theLength"));
	cls_NCollection_Utf16String.def(py::init<const Standard_Utf16Char *>(), py::arg("theCopyUtf16"));
	cls_NCollection_Utf16String.def(py::init<const Standard_Utf16Char *, const Standard_Integer>(), py::arg("theCopyUtf16"), py::arg("theLength"));
	cls_NCollection_Utf16String.def(py::init<const Standard_Utf32Char *>(), py::arg("theCopyUtf32"));
	cls_NCollection_Utf16String.def(py::init<const Standard_Utf32Char *, const Standard_Integer>(), py::arg("theCopyUtf32"), py::arg("theLength"));
	cls_NCollection_Utf16String.def(py::init<const Standard_WideChar *>(), py::arg("theCopyUtfWide"));
	cls_NCollection_Utf16String.def(py::init<const Standard_WideChar *, const Standard_Integer>(), py::arg("theCopyUtfWide"), py::arg("theLength"));
	cls_NCollection_Utf16String.def("Iterator", (NCollection_UtfIterator<Standard_Utf16Char> (NCollection_Utf16String::*)() const ) &NCollection_Utf16String::Iterator, "None");
	cls_NCollection_Utf16String.def("Size", (Standard_Integer (NCollection_Utf16String::*)() const ) &NCollection_Utf16String::Size, "Returns the size of the buffer, excluding NULL-termination symbol");
	cls_NCollection_Utf16String.def("Length", (Standard_Integer (NCollection_Utf16String::*)() const ) &NCollection_Utf16String::Length, "Returns the length of the string in Unicode symbols");
	cls_NCollection_Utf16String.def("GetChar", (Standard_Utf32Char (NCollection_Utf16String::*)(const Standard_Integer) const ) &NCollection_Utf16String::GetChar, "Retrieve Unicode symbol at specified position. Warning! This is a slow access. Iterator should be used for consecutive parsing.", py::arg("theCharIndex"));
	cls_NCollection_Utf16String.def("GetCharBuffer", (const Standard_Utf16Char * (NCollection_Utf16String::*)(const Standard_Integer) const ) &NCollection_Utf16String::GetCharBuffer, "Retrieve string buffer at specified position. Warning! This is a slow access. Iterator should be used for consecutive parsing.", py::arg("theCharIndex"));
	cls_NCollection_Utf16String.def("__getitem__", (Standard_Utf32Char (NCollection_Utf16String::*)(const Standard_Integer) const ) &NCollection_Utf16String::operator[], py::is_operator(), "Retrieve Unicode symbol at specified position. Warning! This is a slow access. Iterator should be used for consecutive parsing.", py::arg("theCharIndex"));
	cls_NCollection_Utf16String.def("FromLocale", [](NCollection_Utf16String &self, const char * a0) -> void { return self.FromLocale(a0); }, py::arg("theString"));
	cls_NCollection_Utf16String.def("FromLocale", (void (NCollection_Utf16String::*)(const char *, const Standard_Integer)) &NCollection_Utf16String::FromLocale, "Copy from NULL-terminated multibyte string in system locale. You should avoid this function unless extreme necessity.", py::arg("theString"), py::arg("theLength"));
	cls_NCollection_Utf16String.def("IsEqual", (bool (NCollection_Utf16String::*)(const NCollection_Utf16String &) const ) &NCollection_Utf16String::IsEqual, "Compares this string with another one.", py::arg("theCompare"));
	cls_NCollection_Utf16String.def("SubString", (NCollection_Utf16String (NCollection_Utf16String::*)(const Standard_Integer, const Standard_Integer) const ) &NCollection_Utf16String::SubString, "Returns the substring.", py::arg("theStart"), py::arg("theEnd"));
	cls_NCollection_Utf16String.def("ToCString", (const Standard_Utf16Char * (NCollection_Utf16String::*)() const ) &NCollection_Utf16String::ToCString, "Returns NULL-terminated Unicode string. Should not be modifed or deleted!");
	cls_NCollection_Utf16String.def("ToUtf8", (const NCollection_UtfString<Standard_Utf8Char> (NCollection_Utf16String::*)() const ) &NCollection_Utf16String::ToUtf8, "Returns copy in UTF-8 format");
	cls_NCollection_Utf16String.def("ToUtf16", (const NCollection_UtfString<Standard_Utf16Char> (NCollection_Utf16String::*)() const ) &NCollection_Utf16String::ToUtf16, "Returns copy in UTF-16 format");
	cls_NCollection_Utf16String.def("ToUtf32", (const NCollection_UtfString<Standard_Utf32Char> (NCollection_Utf16String::*)() const ) &NCollection_Utf16String::ToUtf32, "Returns copy in UTF-32 format");
	cls_NCollection_Utf16String.def("ToUtfWide", (const NCollection_UtfString<Standard_WideChar> (NCollection_Utf16String::*)() const ) &NCollection_Utf16String::ToUtfWide, "Returns copy in wide format (UTF-16 on Windows and UTF-32 on Linux)");
	cls_NCollection_Utf16String.def("ToLocale", (bool (NCollection_Utf16String::*)(char *, const Standard_Integer) const ) &NCollection_Utf16String::ToLocale, "Converts the string into multibyte string. You should avoid this function unless extreme necessity.", py::arg("theBuffer"), py::arg("theSizeBytes"));
	cls_NCollection_Utf16String.def("IsEmpty", (bool (NCollection_Utf16String::*)() const ) &NCollection_Utf16String::IsEmpty, "Returns true if string is empty");
	cls_NCollection_Utf16String.def("Clear", (void (NCollection_Utf16String::*)()) &NCollection_Utf16String::Clear, "Zero string.");
	cls_NCollection_Utf16String.def("assign", (const NCollection_Utf16String & (NCollection_Utf16String::*)(const NCollection_Utf16String &)) &NCollection_Utf16String::operator=, py::is_operator(), "Copy from another string.", py::arg("theOther"));
	cls_NCollection_Utf16String.def("assign", (const NCollection_Utf16String & (NCollection_Utf16String::*)(const char *)) &NCollection_Utf16String::operator=, py::is_operator(), "Copy from UTF-8 NULL-terminated string.", py::arg("theStringUtf8"));
	cls_NCollection_Utf16String.def("assign", (const NCollection_Utf16String & (NCollection_Utf16String::*)(const Standard_WideChar *)) &NCollection_Utf16String::operator=, py::is_operator(), "Copy from wchar_t UTF NULL-terminated string.", py::arg("theStringUtfWide"));
	cls_NCollection_Utf16String.def("__iadd__", (NCollection_Utf16String & (NCollection_Utf16String::*)(const NCollection_Utf16String &)) &NCollection_Utf16String::operator+=, "Join strings.", py::arg("theAppend"));
	cls_NCollection_Utf16String.def("__eq__", (bool (NCollection_Utf16String::*)(const NCollection_Utf16String &) const ) &NCollection_Utf16String::operator==, py::is_operator(), "", py::arg("theCompare"));
	cls_NCollection_Utf16String.def("__ne__", (bool (NCollection_Utf16String::*)(const NCollection_Utf16String &) const ) &NCollection_Utf16String::operator!=, py::is_operator(), "None", py::arg("theCompare"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_UtfString.hxx
	py::class_<NCollection_Utf32String, std::unique_ptr<NCollection_Utf32String, Deleter<NCollection_Utf32String>>> cls_NCollection_Utf32String(mod, "NCollection_Utf32String", "This template class represent constant UTF-* string. String stored in memory continuously, always NULL-terminated and can be used as standard C-string using ToCString() method.");
	cls_NCollection_Utf32String.def(py::init<>());
	cls_NCollection_Utf32String.def(py::init([] (const NCollection_Utf32String &other) {return new NCollection_Utf32String(other);}), "Copy constructor", py::arg("other"));
	cls_NCollection_Utf32String.def(py::init<const char *>(), py::arg("theCopyUtf8"));
	cls_NCollection_Utf32String.def(py::init<const char *, const Standard_Integer>(), py::arg("theCopyUtf8"), py::arg("theLength"));
	cls_NCollection_Utf32String.def(py::init<const Standard_Utf16Char *>(), py::arg("theCopyUtf16"));
	cls_NCollection_Utf32String.def(py::init<const Standard_Utf16Char *, const Standard_Integer>(), py::arg("theCopyUtf16"), py::arg("theLength"));
	cls_NCollection_Utf32String.def(py::init<const Standard_Utf32Char *>(), py::arg("theCopyUtf32"));
	cls_NCollection_Utf32String.def(py::init<const Standard_Utf32Char *, const Standard_Integer>(), py::arg("theCopyUtf32"), py::arg("theLength"));
	cls_NCollection_Utf32String.def(py::init<const Standard_WideChar *>(), py::arg("theCopyUtfWide"));
	cls_NCollection_Utf32String.def(py::init<const Standard_WideChar *, const Standard_Integer>(), py::arg("theCopyUtfWide"), py::arg("theLength"));
	cls_NCollection_Utf32String.def("Iterator", (NCollection_UtfIterator<Standard_Utf32Char> (NCollection_Utf32String::*)() const ) &NCollection_Utf32String::Iterator, "None");
	cls_NCollection_Utf32String.def("Size", (Standard_Integer (NCollection_Utf32String::*)() const ) &NCollection_Utf32String::Size, "Returns the size of the buffer, excluding NULL-termination symbol");
	cls_NCollection_Utf32String.def("Length", (Standard_Integer (NCollection_Utf32String::*)() const ) &NCollection_Utf32String::Length, "Returns the length of the string in Unicode symbols");
	cls_NCollection_Utf32String.def("GetChar", (Standard_Utf32Char (NCollection_Utf32String::*)(const Standard_Integer) const ) &NCollection_Utf32String::GetChar, "Retrieve Unicode symbol at specified position. Warning! This is a slow access. Iterator should be used for consecutive parsing.", py::arg("theCharIndex"));
	cls_NCollection_Utf32String.def("GetCharBuffer", (const Standard_Utf32Char * (NCollection_Utf32String::*)(const Standard_Integer) const ) &NCollection_Utf32String::GetCharBuffer, "Retrieve string buffer at specified position. Warning! This is a slow access. Iterator should be used for consecutive parsing.", py::arg("theCharIndex"));
	cls_NCollection_Utf32String.def("__getitem__", (Standard_Utf32Char (NCollection_Utf32String::*)(const Standard_Integer) const ) &NCollection_Utf32String::operator[], py::is_operator(), "Retrieve Unicode symbol at specified position. Warning! This is a slow access. Iterator should be used for consecutive parsing.", py::arg("theCharIndex"));
	cls_NCollection_Utf32String.def("FromLocale", [](NCollection_Utf32String &self, const char * a0) -> void { return self.FromLocale(a0); }, py::arg("theString"));
	cls_NCollection_Utf32String.def("FromLocale", (void (NCollection_Utf32String::*)(const char *, const Standard_Integer)) &NCollection_Utf32String::FromLocale, "Copy from NULL-terminated multibyte string in system locale. You should avoid this function unless extreme necessity.", py::arg("theString"), py::arg("theLength"));
	cls_NCollection_Utf32String.def("IsEqual", (bool (NCollection_Utf32String::*)(const NCollection_Utf32String &) const ) &NCollection_Utf32String::IsEqual, "Compares this string with another one.", py::arg("theCompare"));
	cls_NCollection_Utf32String.def("SubString", (NCollection_Utf32String (NCollection_Utf32String::*)(const Standard_Integer, const Standard_Integer) const ) &NCollection_Utf32String::SubString, "Returns the substring.", py::arg("theStart"), py::arg("theEnd"));
	cls_NCollection_Utf32String.def("ToCString", (const Standard_Utf32Char * (NCollection_Utf32String::*)() const ) &NCollection_Utf32String::ToCString, "Returns NULL-terminated Unicode string. Should not be modifed or deleted!");
	cls_NCollection_Utf32String.def("ToUtf8", (const NCollection_UtfString<Standard_Utf8Char> (NCollection_Utf32String::*)() const ) &NCollection_Utf32String::ToUtf8, "Returns copy in UTF-8 format");
	cls_NCollection_Utf32String.def("ToUtf16", (const NCollection_UtfString<Standard_Utf16Char> (NCollection_Utf32String::*)() const ) &NCollection_Utf32String::ToUtf16, "Returns copy in UTF-16 format");
	cls_NCollection_Utf32String.def("ToUtf32", (const NCollection_UtfString<Standard_Utf32Char> (NCollection_Utf32String::*)() const ) &NCollection_Utf32String::ToUtf32, "Returns copy in UTF-32 format");
	cls_NCollection_Utf32String.def("ToUtfWide", (const NCollection_UtfString<Standard_WideChar> (NCollection_Utf32String::*)() const ) &NCollection_Utf32String::ToUtfWide, "Returns copy in wide format (UTF-16 on Windows and UTF-32 on Linux)");
	cls_NCollection_Utf32String.def("ToLocale", (bool (NCollection_Utf32String::*)(char *, const Standard_Integer) const ) &NCollection_Utf32String::ToLocale, "Converts the string into multibyte string. You should avoid this function unless extreme necessity.", py::arg("theBuffer"), py::arg("theSizeBytes"));
	cls_NCollection_Utf32String.def("IsEmpty", (bool (NCollection_Utf32String::*)() const ) &NCollection_Utf32String::IsEmpty, "Returns true if string is empty");
	cls_NCollection_Utf32String.def("Clear", (void (NCollection_Utf32String::*)()) &NCollection_Utf32String::Clear, "Zero string.");
	cls_NCollection_Utf32String.def("assign", (const NCollection_Utf32String & (NCollection_Utf32String::*)(const NCollection_Utf32String &)) &NCollection_Utf32String::operator=, py::is_operator(), "Copy from another string.", py::arg("theOther"));
	cls_NCollection_Utf32String.def("assign", (const NCollection_Utf32String & (NCollection_Utf32String::*)(const char *)) &NCollection_Utf32String::operator=, py::is_operator(), "Copy from UTF-8 NULL-terminated string.", py::arg("theStringUtf8"));
	cls_NCollection_Utf32String.def("assign", (const NCollection_Utf32String & (NCollection_Utf32String::*)(const Standard_WideChar *)) &NCollection_Utf32String::operator=, py::is_operator(), "Copy from wchar_t UTF NULL-terminated string.", py::arg("theStringUtfWide"));
	cls_NCollection_Utf32String.def("__iadd__", (NCollection_Utf32String & (NCollection_Utf32String::*)(const NCollection_Utf32String &)) &NCollection_Utf32String::operator+=, "Join strings.", py::arg("theAppend"));
	cls_NCollection_Utf32String.def("__eq__", (bool (NCollection_Utf32String::*)(const NCollection_Utf32String &) const ) &NCollection_Utf32String::operator==, py::is_operator(), "", py::arg("theCompare"));
	cls_NCollection_Utf32String.def("__ne__", (bool (NCollection_Utf32String::*)(const NCollection_Utf32String &) const ) &NCollection_Utf32String::operator!=, py::is_operator(), "None", py::arg("theCompare"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_UtfString.hxx
	py::class_<NCollection_UtfWideString, std::unique_ptr<NCollection_UtfWideString, Deleter<NCollection_UtfWideString>>> cls_NCollection_UtfWideString(mod, "NCollection_UtfWideString", "This template class represent constant UTF-* string. String stored in memory continuously, always NULL-terminated and can be used as standard C-string using ToCString() method.");
	cls_NCollection_UtfWideString.def(py::init<>());
	cls_NCollection_UtfWideString.def(py::init([] (const NCollection_UtfWideString &other) {return new NCollection_UtfWideString(other);}), "Copy constructor", py::arg("other"));
	cls_NCollection_UtfWideString.def(py::init<const char *>(), py::arg("theCopyUtf8"));
	cls_NCollection_UtfWideString.def(py::init<const char *, const Standard_Integer>(), py::arg("theCopyUtf8"), py::arg("theLength"));
	cls_NCollection_UtfWideString.def(py::init<const Standard_Utf16Char *>(), py::arg("theCopyUtf16"));
	cls_NCollection_UtfWideString.def(py::init<const Standard_Utf16Char *, const Standard_Integer>(), py::arg("theCopyUtf16"), py::arg("theLength"));
	cls_NCollection_UtfWideString.def(py::init<const Standard_Utf32Char *>(), py::arg("theCopyUtf32"));
	cls_NCollection_UtfWideString.def(py::init<const Standard_Utf32Char *, const Standard_Integer>(), py::arg("theCopyUtf32"), py::arg("theLength"));
	cls_NCollection_UtfWideString.def(py::init<const Standard_WideChar *>(), py::arg("theCopyUtfWide"));
	cls_NCollection_UtfWideString.def(py::init<const Standard_WideChar *, const Standard_Integer>(), py::arg("theCopyUtfWide"), py::arg("theLength"));
	cls_NCollection_UtfWideString.def("Iterator", (NCollection_UtfIterator<Standard_WideChar> (NCollection_UtfWideString::*)() const ) &NCollection_UtfWideString::Iterator, "None");
	cls_NCollection_UtfWideString.def("Size", (Standard_Integer (NCollection_UtfWideString::*)() const ) &NCollection_UtfWideString::Size, "Returns the size of the buffer, excluding NULL-termination symbol");
	cls_NCollection_UtfWideString.def("Length", (Standard_Integer (NCollection_UtfWideString::*)() const ) &NCollection_UtfWideString::Length, "Returns the length of the string in Unicode symbols");
	cls_NCollection_UtfWideString.def("GetChar", (Standard_Utf32Char (NCollection_UtfWideString::*)(const Standard_Integer) const ) &NCollection_UtfWideString::GetChar, "Retrieve Unicode symbol at specified position. Warning! This is a slow access. Iterator should be used for consecutive parsing.", py::arg("theCharIndex"));
	cls_NCollection_UtfWideString.def("GetCharBuffer", (const Standard_WideChar * (NCollection_UtfWideString::*)(const Standard_Integer) const ) &NCollection_UtfWideString::GetCharBuffer, "Retrieve string buffer at specified position. Warning! This is a slow access. Iterator should be used for consecutive parsing.", py::arg("theCharIndex"));
	cls_NCollection_UtfWideString.def("__getitem__", (Standard_Utf32Char (NCollection_UtfWideString::*)(const Standard_Integer) const ) &NCollection_UtfWideString::operator[], py::is_operator(), "Retrieve Unicode symbol at specified position. Warning! This is a slow access. Iterator should be used for consecutive parsing.", py::arg("theCharIndex"));
	cls_NCollection_UtfWideString.def("FromLocale", [](NCollection_UtfWideString &self, const char * a0) -> void { return self.FromLocale(a0); }, py::arg("theString"));
	cls_NCollection_UtfWideString.def("FromLocale", (void (NCollection_UtfWideString::*)(const char *, const Standard_Integer)) &NCollection_UtfWideString::FromLocale, "Copy from NULL-terminated multibyte string in system locale. You should avoid this function unless extreme necessity.", py::arg("theString"), py::arg("theLength"));
	cls_NCollection_UtfWideString.def("IsEqual", (bool (NCollection_UtfWideString::*)(const NCollection_UtfWideString &) const ) &NCollection_UtfWideString::IsEqual, "Compares this string with another one.", py::arg("theCompare"));
	cls_NCollection_UtfWideString.def("SubString", (NCollection_UtfWideString (NCollection_UtfWideString::*)(const Standard_Integer, const Standard_Integer) const ) &NCollection_UtfWideString::SubString, "Returns the substring.", py::arg("theStart"), py::arg("theEnd"));
	cls_NCollection_UtfWideString.def("ToCString", (const Standard_WideChar * (NCollection_UtfWideString::*)() const ) &NCollection_UtfWideString::ToCString, "Returns NULL-terminated Unicode string. Should not be modifed or deleted!");
	cls_NCollection_UtfWideString.def("ToUtf8", (const NCollection_UtfString<Standard_Utf8Char> (NCollection_UtfWideString::*)() const ) &NCollection_UtfWideString::ToUtf8, "Returns copy in UTF-8 format");
	cls_NCollection_UtfWideString.def("ToUtf16", (const NCollection_UtfString<Standard_Utf16Char> (NCollection_UtfWideString::*)() const ) &NCollection_UtfWideString::ToUtf16, "Returns copy in UTF-16 format");
	cls_NCollection_UtfWideString.def("ToUtf32", (const NCollection_UtfString<Standard_Utf32Char> (NCollection_UtfWideString::*)() const ) &NCollection_UtfWideString::ToUtf32, "Returns copy in UTF-32 format");
	cls_NCollection_UtfWideString.def("ToUtfWide", (const NCollection_UtfString<Standard_WideChar> (NCollection_UtfWideString::*)() const ) &NCollection_UtfWideString::ToUtfWide, "Returns copy in wide format (UTF-16 on Windows and UTF-32 on Linux)");
	cls_NCollection_UtfWideString.def("ToLocale", (bool (NCollection_UtfWideString::*)(char *, const Standard_Integer) const ) &NCollection_UtfWideString::ToLocale, "Converts the string into multibyte string. You should avoid this function unless extreme necessity.", py::arg("theBuffer"), py::arg("theSizeBytes"));
	cls_NCollection_UtfWideString.def("IsEmpty", (bool (NCollection_UtfWideString::*)() const ) &NCollection_UtfWideString::IsEmpty, "Returns true if string is empty");
	cls_NCollection_UtfWideString.def("Clear", (void (NCollection_UtfWideString::*)()) &NCollection_UtfWideString::Clear, "Zero string.");
	cls_NCollection_UtfWideString.def("assign", (const NCollection_UtfWideString & (NCollection_UtfWideString::*)(const NCollection_UtfWideString &)) &NCollection_UtfWideString::operator=, py::is_operator(), "Copy from another string.", py::arg("theOther"));
	cls_NCollection_UtfWideString.def("assign", (const NCollection_UtfWideString & (NCollection_UtfWideString::*)(const char *)) &NCollection_UtfWideString::operator=, py::is_operator(), "Copy from UTF-8 NULL-terminated string.", py::arg("theStringUtf8"));
	cls_NCollection_UtfWideString.def("assign", (const NCollection_UtfWideString & (NCollection_UtfWideString::*)(const Standard_WideChar *)) &NCollection_UtfWideString::operator=, py::is_operator(), "Copy from wchar_t UTF NULL-terminated string.", py::arg("theStringUtfWide"));
	cls_NCollection_UtfWideString.def("__iadd__", (NCollection_UtfWideString & (NCollection_UtfWideString::*)(const NCollection_UtfWideString &)) &NCollection_UtfWideString::operator+=, "Join strings.", py::arg("theAppend"));
	cls_NCollection_UtfWideString.def("__eq__", (bool (NCollection_UtfWideString::*)(const NCollection_UtfWideString &) const ) &NCollection_UtfWideString::operator==, py::is_operator(), "", py::arg("theCompare"));
	cls_NCollection_UtfWideString.def("__ne__", (bool (NCollection_UtfWideString::*)(const NCollection_UtfWideString &) const ) &NCollection_UtfWideString::operator!=, py::is_operator(), "None", py::arg("theCompare"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_UtfString.hxx
	py::class_<NCollection_String, std::unique_ptr<NCollection_String, Deleter<NCollection_String>>> cls_NCollection_String(mod, "NCollection_String", "This template class represent constant UTF-* string. String stored in memory continuously, always NULL-terminated and can be used as standard C-string using ToCString() method.");
	cls_NCollection_String.def(py::init<>());
	cls_NCollection_String.def(py::init([] (const NCollection_String &other) {return new NCollection_String(other);}), "Copy constructor", py::arg("other"));
	cls_NCollection_String.def(py::init<const char *>(), py::arg("theCopyUtf8"));
	cls_NCollection_String.def(py::init<const char *, const Standard_Integer>(), py::arg("theCopyUtf8"), py::arg("theLength"));
	cls_NCollection_String.def(py::init<const Standard_Utf16Char *>(), py::arg("theCopyUtf16"));
	cls_NCollection_String.def(py::init<const Standard_Utf16Char *, const Standard_Integer>(), py::arg("theCopyUtf16"), py::arg("theLength"));
	cls_NCollection_String.def(py::init<const Standard_Utf32Char *>(), py::arg("theCopyUtf32"));
	cls_NCollection_String.def(py::init<const Standard_Utf32Char *, const Standard_Integer>(), py::arg("theCopyUtf32"), py::arg("theLength"));
	cls_NCollection_String.def(py::init<const Standard_WideChar *>(), py::arg("theCopyUtfWide"));
	cls_NCollection_String.def(py::init<const Standard_WideChar *, const Standard_Integer>(), py::arg("theCopyUtfWide"), py::arg("theLength"));
	cls_NCollection_String.def("Iterator", (NCollection_UtfIterator<Standard_Utf8Char> (NCollection_String::*)() const ) &NCollection_String::Iterator, "None");
	cls_NCollection_String.def("Size", (Standard_Integer (NCollection_String::*)() const ) &NCollection_String::Size, "Returns the size of the buffer, excluding NULL-termination symbol");
	cls_NCollection_String.def("Length", (Standard_Integer (NCollection_String::*)() const ) &NCollection_String::Length, "Returns the length of the string in Unicode symbols");
	cls_NCollection_String.def("GetChar", (Standard_Utf32Char (NCollection_String::*)(const Standard_Integer) const ) &NCollection_String::GetChar, "Retrieve Unicode symbol at specified position. Warning! This is a slow access. Iterator should be used for consecutive parsing.", py::arg("theCharIndex"));
	cls_NCollection_String.def("GetCharBuffer", (const Standard_Utf8Char * (NCollection_String::*)(const Standard_Integer) const ) &NCollection_String::GetCharBuffer, "Retrieve string buffer at specified position. Warning! This is a slow access. Iterator should be used for consecutive parsing.", py::arg("theCharIndex"));
	cls_NCollection_String.def("__getitem__", (Standard_Utf32Char (NCollection_String::*)(const Standard_Integer) const ) &NCollection_String::operator[], py::is_operator(), "Retrieve Unicode symbol at specified position. Warning! This is a slow access. Iterator should be used for consecutive parsing.", py::arg("theCharIndex"));
	cls_NCollection_String.def("FromLocale", [](NCollection_String &self, const char * a0) -> void { return self.FromLocale(a0); }, py::arg("theString"));
	cls_NCollection_String.def("FromLocale", (void (NCollection_String::*)(const char *, const Standard_Integer)) &NCollection_String::FromLocale, "Copy from NULL-terminated multibyte string in system locale. You should avoid this function unless extreme necessity.", py::arg("theString"), py::arg("theLength"));
	cls_NCollection_String.def("IsEqual", (bool (NCollection_String::*)(const NCollection_String &) const ) &NCollection_String::IsEqual, "Compares this string with another one.", py::arg("theCompare"));
	cls_NCollection_String.def("SubString", (NCollection_String (NCollection_String::*)(const Standard_Integer, const Standard_Integer) const ) &NCollection_String::SubString, "Returns the substring.", py::arg("theStart"), py::arg("theEnd"));
	cls_NCollection_String.def("ToCString", (const Standard_Utf8Char * (NCollection_String::*)() const ) &NCollection_String::ToCString, "Returns NULL-terminated Unicode string. Should not be modifed or deleted!");
	cls_NCollection_String.def("ToUtf8", (const NCollection_UtfString<Standard_Utf8Char> (NCollection_String::*)() const ) &NCollection_String::ToUtf8, "Returns copy in UTF-8 format");
	cls_NCollection_String.def("ToUtf16", (const NCollection_UtfString<Standard_Utf16Char> (NCollection_String::*)() const ) &NCollection_String::ToUtf16, "Returns copy in UTF-16 format");
	cls_NCollection_String.def("ToUtf32", (const NCollection_UtfString<Standard_Utf32Char> (NCollection_String::*)() const ) &NCollection_String::ToUtf32, "Returns copy in UTF-32 format");
	cls_NCollection_String.def("ToUtfWide", (const NCollection_UtfString<Standard_WideChar> (NCollection_String::*)() const ) &NCollection_String::ToUtfWide, "Returns copy in wide format (UTF-16 on Windows and UTF-32 on Linux)");
	cls_NCollection_String.def("ToLocale", (bool (NCollection_String::*)(char *, const Standard_Integer) const ) &NCollection_String::ToLocale, "Converts the string into multibyte string. You should avoid this function unless extreme necessity.", py::arg("theBuffer"), py::arg("theSizeBytes"));
	cls_NCollection_String.def("IsEmpty", (bool (NCollection_String::*)() const ) &NCollection_String::IsEmpty, "Returns true if string is empty");
	cls_NCollection_String.def("Clear", (void (NCollection_String::*)()) &NCollection_String::Clear, "Zero string.");
	cls_NCollection_String.def("assign", (const NCollection_String & (NCollection_String::*)(const NCollection_String &)) &NCollection_String::operator=, py::is_operator(), "Copy from another string.", py::arg("theOther"));
	cls_NCollection_String.def("assign", (const NCollection_String & (NCollection_String::*)(const char *)) &NCollection_String::operator=, py::is_operator(), "Copy from UTF-8 NULL-terminated string.", py::arg("theStringUtf8"));
	cls_NCollection_String.def("assign", (const NCollection_String & (NCollection_String::*)(const Standard_WideChar *)) &NCollection_String::operator=, py::is_operator(), "Copy from wchar_t UTF NULL-terminated string.", py::arg("theStringUtfWide"));
	cls_NCollection_String.def("__iadd__", (NCollection_String & (NCollection_String::*)(const NCollection_String &)) &NCollection_String::operator+=, "Join strings.", py::arg("theAppend"));
	cls_NCollection_String.def("__eq__", (bool (NCollection_String::*)(const NCollection_String &) const ) &NCollection_String::operator==, py::is_operator(), "", py::arg("theCompare"));
	cls_NCollection_String.def("__ne__", (bool (NCollection_String::*)(const NCollection_String &) const ) &NCollection_String::operator!=, py::is_operator(), "None", py::arg("theCompare"));

	other_mod = py::module::import("OCCT.Standard");
	if (py::hasattr(other_mod, "Standard_Size")) {
		mod.attr("Standard_Size") = other_mod.attr("Standard_Size");
	}


}
