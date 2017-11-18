#include <pyOCCT_Common.hpp>

#include <gp_XY.hxx>
#include <gp_XYZ.hxx>

#include <BVH_Constants.hxx>
#include <BVH_Types.hxx>
#include <BVH_Box.hxx>
#include <Standard_TypeDef.hxx>
#include <BVH_Builder.hxx>
#include <BVH_Set.hxx>
#include <BVH_Tree.hxx>
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Type.hxx>
#include <BVH_Properties.hxx>
#include <BVH_Object.hxx>
#include <BVH_ObjectSet.hxx>
#include <BVH_BuildQueue.hxx>
#include <BVH_BuildThread.hxx>
#include <BVH_QueueBuilder.hxx>
#include <BVH_PrimitiveSet3d.hxx>
#include <BVH_Geometry.hxx>
#include <BVH_DistanceField.hxx>
#include <BVH_PrimitiveSet.hxx>
#include <BVH_RadixSorter.hxx>
#include <BVH_Sorter.hxx>
#include <NCollection_Array1.hxx>
#include <BVH_BinnedBuilder.hxx>
#include <NCollection_Templates.hpp>
#include <BVH_Templates.hpp>

PYBIND11_MODULE(BVH, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.NCollection");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_Constants.hxx
	mod.attr("BVH_Constants_MaxTreeDepth") = py::cast(int(BVH_Constants_MaxTreeDepth));
	mod.attr("BVH_Constants_LeafNodeSizeSingle") = py::cast(int(BVH_Constants_LeafNodeSizeSingle));
	mod.attr("BVH_Constants_LeafNodeSizeAverage") = py::cast(int(BVH_Constants_LeafNodeSizeAverage));
	mod.attr("BVH_Constants_LeafNodeSizeDefault") = py::cast(int(BVH_Constants_LeafNodeSizeDefault));
	mod.attr("BVH_Constants_LeafNodeSizeSmall") = py::cast(int(BVH_Constants_LeafNodeSizeSmall));
	mod.attr("BVH_Constants_NbBinsOptimal") = py::cast(int(BVH_Constants_NbBinsOptimal));
	mod.attr("BVH_Constants_NbBinsBest") = py::cast(int(BVH_Constants_NbBinsBest));


	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_Tree.hxx
	py::class_<BVH_TreeBaseTransient, opencascade::handle<BVH_TreeBaseTransient>, Standard_Transient> cls_BVH_TreeBaseTransient(mod, "BVH_TreeBaseTransient", "A non-template class for using as base for BVH_TreeBase (just to have a named base class).");
	cls_BVH_TreeBaseTransient.def_static("get_type_name_", (const char * (*)()) &BVH_TreeBaseTransient::get_type_name, "None");
	cls_BVH_TreeBaseTransient.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BVH_TreeBaseTransient::get_type_descriptor, "None");
	cls_BVH_TreeBaseTransient.def("DynamicType", (const opencascade::handle<Standard_Type> & (BVH_TreeBaseTransient::*)() const ) &BVH_TreeBaseTransient::DynamicType, "None");

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_Tree.hxx
	py::class_<BVH_QuadTree, std::unique_ptr<BVH_QuadTree, Deleter<BVH_QuadTree>>> cls_BVH_QuadTree(mod, "BVH_QuadTree", "Type corresponding to quad BVH.");
	cls_BVH_QuadTree.def(py::init<>());
	*/

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_Tree.hxx
	py::class_<BVH_BinaryTree, std::unique_ptr<BVH_BinaryTree, Deleter<BVH_BinaryTree>>> cls_BVH_BinaryTree(mod, "BVH_BinaryTree", "Type corresponding to binary BVH.");
	cls_BVH_BinaryTree.def(py::init<>());
	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_Builder.hxx
	py::class_<BVH_BuilderTransient, opencascade::handle<BVH_BuilderTransient>, Standard_Transient> cls_BVH_BuilderTransient(mod, "BVH_BuilderTransient", "A non-template class for using as base for BVH_Builder (just to have a named base class).");
	cls_BVH_BuilderTransient.def_static("get_type_name_", (const char * (*)()) &BVH_BuilderTransient::get_type_name, "None");
	cls_BVH_BuilderTransient.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BVH_BuilderTransient::get_type_descriptor, "None");
	cls_BVH_BuilderTransient.def("DynamicType", (const opencascade::handle<Standard_Type> & (BVH_BuilderTransient::*)() const ) &BVH_BuilderTransient::DynamicType, "None");
	cls_BVH_BuilderTransient.def("MaxTreeDepth", (Standard_Integer (BVH_BuilderTransient::*)() const ) &BVH_BuilderTransient::MaxTreeDepth, "Returns the maximum depth of constructed BVH.");
	cls_BVH_BuilderTransient.def("LeafNodeSize", (Standard_Integer (BVH_BuilderTransient::*)() const ) &BVH_BuilderTransient::LeafNodeSize, "Returns the maximum number of sub-elements in the leaf.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_Properties.hxx
	py::class_<BVH_Properties, opencascade::handle<BVH_Properties>, Standard_Transient> cls_BVH_Properties(mod, "BVH_Properties", "Abstract properties of geometric object.");
	cls_BVH_Properties.def_static("get_type_name_", (const char * (*)()) &BVH_Properties::get_type_name, "None");
	cls_BVH_Properties.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BVH_Properties::get_type_descriptor, "None");
	cls_BVH_Properties.def("DynamicType", (const opencascade::handle<Standard_Type> & (BVH_Properties::*)() const ) &BVH_Properties::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_Object.hxx
	py::class_<BVH_ObjectTransient, opencascade::handle<BVH_ObjectTransient>, Standard_Transient> cls_BVH_ObjectTransient(mod, "BVH_ObjectTransient", "A non-template class for using as base for BVH_Object (just to have a named base class).");
	cls_BVH_ObjectTransient.def_static("get_type_name_", (const char * (*)()) &BVH_ObjectTransient::get_type_name, "None");
	cls_BVH_ObjectTransient.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BVH_ObjectTransient::get_type_descriptor, "None");
	cls_BVH_ObjectTransient.def("DynamicType", (const opencascade::handle<Standard_Type> & (BVH_ObjectTransient::*)() const ) &BVH_ObjectTransient::DynamicType, "None");
	cls_BVH_ObjectTransient.def("Properties", (const opencascade::handle<BVH_Properties> & (BVH_ObjectTransient::*)() const ) &BVH_ObjectTransient::Properties, "Returns properties of the geometric object.");
	cls_BVH_ObjectTransient.def("SetProperties", (void (BVH_ObjectTransient::*)(const opencascade::handle<BVH_Properties> &)) &BVH_ObjectTransient::SetProperties, "Sets properties of the geometric object.", py::arg("theProperties"));
	cls_BVH_ObjectTransient.def("IsDirty", (Standard_Boolean (BVH_ObjectTransient::*)() const ) &BVH_ObjectTransient::IsDirty, "Returns TRUE if object state should be updated.");
	cls_BVH_ObjectTransient.def("MarkDirty", (void (BVH_ObjectTransient::*)()) &BVH_ObjectTransient::MarkDirty, "Marks object state as outdated (needs BVH rebuilding).");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_BuildQueue.hxx
	py::class_<BVH_BuildQueue, std::unique_ptr<BVH_BuildQueue, Deleter<BVH_BuildQueue>>> cls_BVH_BuildQueue(mod, "BVH_BuildQueue", "Command-queue for parallel building of BVH nodes.");
	cls_BVH_BuildQueue.def(py::init<>());
	cls_BVH_BuildQueue.def("Size", (Standard_Integer (BVH_BuildQueue::*)()) &BVH_BuildQueue::Size, "Returns current size of BVH build queue.");
	cls_BVH_BuildQueue.def("Enqueue", (void (BVH_BuildQueue::*)(const Standard_Integer &)) &BVH_BuildQueue::Enqueue, "Enqueues new work-item onto BVH build queue.", py::arg("theNode"));
	cls_BVH_BuildQueue.def("Fetch", (Standard_Integer (BVH_BuildQueue::*)(Standard_Boolean &)) &BVH_BuildQueue::Fetch, "Fetches first work-item from BVH build queue.", py::arg("wasBusy"));
	cls_BVH_BuildQueue.def("HasBusyThreads", (Standard_Boolean (BVH_BuildQueue::*)()) &BVH_BuildQueue::HasBusyThreads, "Checks if there are active build threads.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_BuildThread.hxx
	py::class_<BVH_BuildTool, std::unique_ptr<BVH_BuildTool, Deleter<BVH_BuildTool>>> cls_BVH_BuildTool(mod, "BVH_BuildTool", "Tool object to call BVH builder subroutines.");
	cls_BVH_BuildTool.def("Perform", (void (BVH_BuildTool::*)(const Standard_Integer)) &BVH_BuildTool::Perform, "Performs splitting of the given BVH node.", py::arg("theNode"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_BuildThread.hxx
	py::class_<BVH_BuildThread, opencascade::handle<BVH_BuildThread>, Standard_Transient> cls_BVH_BuildThread(mod, "BVH_BuildThread", "Wrapper for BVH build thread.");
	cls_BVH_BuildThread.def(py::init<BVH_BuildTool &, BVH_BuildQueue &>(), py::arg("theBuildTool"), py::arg("theBuildQueue"));
	cls_BVH_BuildThread.def("Run", (void (BVH_BuildThread::*)()) &BVH_BuildThread::Run, "Starts execution of BVH build thread.");
	cls_BVH_BuildThread.def("Wait", (void (BVH_BuildThread::*)()) &BVH_BuildThread::Wait, "Waits till the thread finishes execution.");
	cls_BVH_BuildThread.def_static("get_type_name_", (const char * (*)()) &BVH_BuildThread::get_type_name, "None");
	cls_BVH_BuildThread.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BVH_BuildThread::get_type_descriptor, "None");
	cls_BVH_BuildThread.def("DynamicType", (const opencascade::handle<Standard_Type> & (BVH_BuildThread::*)() const ) &BVH_BuildThread::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_Types.hxx
	bind_NCollection_Vec2<int>(mod, "BVH_Vec2i");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_Types.hxx
	bind_NCollection_Vec3<int>(mod, "BVH_Vec3i");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_Types.hxx
	bind_NCollection_Vec4<int>(mod, "BVH_Vec4i");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_Types.hxx
	// FIXME bind_std::vector<NCollection_Vec2<int>, std::allocator<NCollection_Vec2<int> > >(mod, "BVH_Array2i");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_Types.hxx
	// FIXME bind_std::vector<NCollection_Vec3<int>, std::allocator<NCollection_Vec3<int> > >(mod, "BVH_Array3i");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_Types.hxx
	// FIXME bind_std::vector<NCollection_Vec4<int>, std::allocator<NCollection_Vec4<int> > >(mod, "BVH_Array4i");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_Types.hxx
	bind_NCollection_Vec2<float>(mod, "BVH_Vec2f");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_Types.hxx
	bind_NCollection_Vec3<float>(mod, "BVH_Vec3f");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_Types.hxx
	bind_NCollection_Vec4<float>(mod, "BVH_Vec4f");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_Types.hxx
	// FIXME bind_std::vector<NCollection_Vec2<float>, std::allocator<NCollection_Vec2<float> > >(mod, "BVH_Array2f");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_Types.hxx
	// FIXME bind_std::vector<NCollection_Vec3<float>, std::allocator<NCollection_Vec3<float> > >(mod, "BVH_Array3f");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_Types.hxx
	// FIXME bind_std::vector<NCollection_Vec4<float>, std::allocator<NCollection_Vec4<float> > >(mod, "BVH_Array4f");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_Types.hxx
	bind_NCollection_Vec2<double>(mod, "BVH_Vec2d");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_Types.hxx
	bind_NCollection_Vec3<double>(mod, "BVH_Vec3d");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_Types.hxx
	bind_NCollection_Vec4<double>(mod, "BVH_Vec4d");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_Types.hxx
	// FIXME bind_std::vector<NCollection_Vec2<double>, std::allocator<NCollection_Vec2<double> > >(mod, "BVH_Array2d");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_Types.hxx
	// FIXME bind_std::vector<NCollection_Vec3<double>, std::allocator<NCollection_Vec3<double> > >(mod, "BVH_Array3d");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_Types.hxx
	// FIXME bind_std::vector<NCollection_Vec4<double>, std::allocator<NCollection_Vec4<double> > >(mod, "BVH_Array4d");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_Types.hxx
	bind_NCollection_Mat4<float>(mod, "BVH_Mat4f");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_Types.hxx
	bind_NCollection_Mat4<double>(mod, "BVH_Mat4d");

	// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_PrimitiveSet3d.hxx
	bind_BVH_PrimitiveSet<double, 3>(mod, "BVH_PrimitiveSet3d");

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_RadixSorter.hxx
	// FIXME bind_std::pair<int, int>(mod, "BVH_EncodedLink");

	*/


}
