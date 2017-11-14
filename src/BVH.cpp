#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <BVH_Constants.hxx>
#include <BVH_Types.hxx>
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Type.hxx>
#include <BVH_Tree.hxx>
#include <Standard_TypeDef.hxx>
#include <BVH_Builder.hxx>
#include <BVH_Properties.hxx>
#include <BVH_Object.hxx>
#include <BVH_BuildQueue.hxx>
#include <BVH_BuildThread.hxx>
#include <BVH_Set.hxx>
#include <BVH_Box.hxx>
#include <BVH_PrimitiveSet3d.hxx>
#include <BVH_RadixSorter.hxx>

PYBIND11_MODULE(BVH, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");

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

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Vec2.hxx
	py::class_<BVH_Vec2i, std::unique_ptr<BVH_Vec2i, Deleter<BVH_Vec2i>>> cls_BVH_Vec2i(mod, "BVH_Vec2i", "Defines the 2D-vector template. The main target for this class - to handle raw low-level arrays (from/to graphic driver etc.).");
	cls_BVH_Vec2i.def(py::init<>());
	cls_BVH_Vec2i.def(py::init<const int>(), py::arg("theXY"));
	cls_BVH_Vec2i.def(py::init<const int, const int>(), py::arg("theX"), py::arg("theY"));
	cls_BVH_Vec2i.def_static("Length_", (int (*)()) &BVH_Vec2i::Length, "Returns the number of components.");
	cls_BVH_Vec2i.def("SetValues", (void (BVH_Vec2i::*)(const int, const int)) &BVH_Vec2i::SetValues, "Assign new values to the vector.", py::arg("theX"), py::arg("theY"));
	cls_BVH_Vec2i.def("x", (int (BVH_Vec2i::*)() const ) &BVH_Vec2i::x, "Alias to 1st component as X coordinate in XY.");
	cls_BVH_Vec2i.def("y", (int (BVH_Vec2i::*)() const ) &BVH_Vec2i::y, "Alias to 2nd component as Y coordinate in XY.");
	cls_BVH_Vec2i.def("xy", (const BVH_Vec2i (BVH_Vec2i::*)() const ) &BVH_Vec2i::xy, "None");
	cls_BVH_Vec2i.def("yx", (const BVH_Vec2i (BVH_Vec2i::*)() const ) &BVH_Vec2i::yx, "None");
	cls_BVH_Vec2i.def("x", (int & (BVH_Vec2i::*)()) &BVH_Vec2i::x, "Alias to 1st component as X coordinate in XY.");
	cls_BVH_Vec2i.def("y", (int & (BVH_Vec2i::*)()) &BVH_Vec2i::y, "Alias to 2nd component as Y coordinate in XY.");
	cls_BVH_Vec2i.def("IsEqual", (bool (BVH_Vec2i::*)(const BVH_Vec2i &) const ) &BVH_Vec2i::IsEqual, "Check this vector with another vector for equality (without tolerance!).", py::arg("theOther"));
	cls_BVH_Vec2i.def("__eq__", (bool (BVH_Vec2i::*)(const BVH_Vec2i &)) &BVH_Vec2i::operator==, py::is_operator(), "Check this vector with another vector for equality (without tolerance!).", py::arg("theOther"));
	cls_BVH_Vec2i.def("__eq__", (bool (BVH_Vec2i::*)(const BVH_Vec2i &) const ) &BVH_Vec2i::operator==, py::is_operator(), "None", py::arg("theOther"));
	cls_BVH_Vec2i.def("__ne__", (bool (BVH_Vec2i::*)(const BVH_Vec2i &)) &BVH_Vec2i::operator!=, py::is_operator(), "Check this vector with another vector for non-equality (without tolerance!).", py::arg("theOther"));
	cls_BVH_Vec2i.def("__ne__", (bool (BVH_Vec2i::*)(const BVH_Vec2i &) const ) &BVH_Vec2i::operator!=, py::is_operator(), "None", py::arg("theOther"));
	cls_BVH_Vec2i.def("GetData", (const int * (BVH_Vec2i::*)() const ) &BVH_Vec2i::GetData, "Raw access to the data (for OpenGL exchange).");
	cls_BVH_Vec2i.def("ChangeData", (int * (BVH_Vec2i::*)()) &BVH_Vec2i::ChangeData, "None");
	cls_BVH_Vec2i.def("__iadd__", (BVH_Vec2i & (BVH_Vec2i::*)(const BVH_Vec2i &)) &BVH_Vec2i::operator+=, "Compute per-component summary.", py::arg("theAdd"));
	cls_BVH_Vec2i.def("__isub__", (BVH_Vec2i & (BVH_Vec2i::*)(const BVH_Vec2i &)) &BVH_Vec2i::operator-=, "Compute per-component subtraction.", py::arg("theDec"));
	cls_BVH_Vec2i.def("__sub__", (BVH_Vec2i (BVH_Vec2i::*)() const ) &BVH_Vec2i::operator-, py::is_operator(), "Unary -.");
	cls_BVH_Vec2i.def("__imul__", (BVH_Vec2i & (BVH_Vec2i::*)(const BVH_Vec2i &)) &BVH_Vec2i::operator*=, "Compute per-component multiplication.", py::arg("theRight"));
	cls_BVH_Vec2i.def("Multiply", (void (BVH_Vec2i::*)(const int)) &BVH_Vec2i::Multiply, "Compute per-component multiplication by scale factor.", py::arg("theFactor"));
	cls_BVH_Vec2i.def("Multiplied", (BVH_Vec2i (BVH_Vec2i::*)(const int) const ) &BVH_Vec2i::Multiplied, "Compute per-component multiplication by scale factor.", py::arg("theFactor"));
	cls_BVH_Vec2i.def("cwiseMin", (BVH_Vec2i (BVH_Vec2i::*)(const BVH_Vec2i &) const ) &BVH_Vec2i::cwiseMin, "Compute component-wise minimum of two vectors.", py::arg("theVec"));
	cls_BVH_Vec2i.def("cwiseMax", (BVH_Vec2i (BVH_Vec2i::*)(const BVH_Vec2i &) const ) &BVH_Vec2i::cwiseMax, "Compute component-wise maximum of two vectors.", py::arg("theVec"));
	cls_BVH_Vec2i.def("cwiseAbs", (BVH_Vec2i (BVH_Vec2i::*)() const ) &BVH_Vec2i::cwiseAbs, "Compute component-wise modulus of the vector.");
	cls_BVH_Vec2i.def("maxComp", (int (BVH_Vec2i::*)() const ) &BVH_Vec2i::maxComp, "Compute maximum component of the vector.");
	cls_BVH_Vec2i.def("minComp", (int (BVH_Vec2i::*)() const ) &BVH_Vec2i::minComp, "Compute minimum component of the vector.");
	cls_BVH_Vec2i.def("__imul__", (BVH_Vec2i & (BVH_Vec2i::*)(const int)) &BVH_Vec2i::operator*=, "Compute per-component multiplication by scale factor.", py::arg("theFactor"));
	cls_BVH_Vec2i.def("__itruediv__", (BVH_Vec2i & (BVH_Vec2i::*)(const int)) &BVH_Vec2i::operator/=, "Compute per-component division by scale factor.", py::arg("theInvFactor"));
	cls_BVH_Vec2i.def("__mul__", (BVH_Vec2i (BVH_Vec2i::*)(const int) const ) &BVH_Vec2i::operator*, py::is_operator(), "Compute per-component multiplication by scale factor.", py::arg("theFactor"));
	cls_BVH_Vec2i.def("__truediv__", (BVH_Vec2i (BVH_Vec2i::*)(const int) const ) &BVH_Vec2i::operator/, py::is_operator(), "Compute per-component division by scale factor.", py::arg("theInvFactor"));
	cls_BVH_Vec2i.def("Dot", (int (BVH_Vec2i::*)(const BVH_Vec2i &) const ) &BVH_Vec2i::Dot, "Computes the dot product.", py::arg("theOther"));
	cls_BVH_Vec2i.def("Modulus", (int (BVH_Vec2i::*)() const ) &BVH_Vec2i::Modulus, "Computes the vector modulus (magnitude, length).");
	cls_BVH_Vec2i.def("SquareModulus", (int (BVH_Vec2i::*)() const ) &BVH_Vec2i::SquareModulus, "Computes the square of vector modulus (magnitude, length). This method may be used for performance tricks.");
	cls_BVH_Vec2i.def_static("DX_", (BVH_Vec2i (*)()) &BVH_Vec2i::DX, "Constuct DX unit vector.");
	cls_BVH_Vec2i.def_static("DY_", (BVH_Vec2i (*)()) &BVH_Vec2i::DY, "Constuct DY unit vector.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Vec3.hxx
	py::class_<BVH_Vec3i, std::unique_ptr<BVH_Vec3i, Deleter<BVH_Vec3i>>> cls_BVH_Vec3i(mod, "BVH_Vec3i", "Generic 3-components vector. To be used as RGB color pixel or XYZ 3D-point. The main target for this class - to handle raw low-level arrays (from/to graphic driver etc.).");
	cls_BVH_Vec3i.def(py::init<>());
	cls_BVH_Vec3i.def(py::init<int>(), py::arg("theValue"));
	cls_BVH_Vec3i.def(py::init<const int, const int, const int>(), py::arg("theX"), py::arg("theY"), py::arg("theZ"));
	cls_BVH_Vec3i.def(py::init<const NCollection_Vec2<int> &>(), py::arg("theVec2"));
	cls_BVH_Vec3i.def_static("Length_", (int (*)()) &BVH_Vec3i::Length, "Returns the number of components.");
	cls_BVH_Vec3i.def("SetValues", (void (BVH_Vec3i::*)(const int, const int, const int)) &BVH_Vec3i::SetValues, "Assign new values to the vector.", py::arg("theX"), py::arg("theY"), py::arg("theZ"));
	cls_BVH_Vec3i.def("x", (int (BVH_Vec3i::*)() const ) &BVH_Vec3i::x, "Alias to 1st component as X coordinate in XYZ.");
	cls_BVH_Vec3i.def("r", (int (BVH_Vec3i::*)() const ) &BVH_Vec3i::r, "Alias to 1st component as RED channel in RGB.");
	cls_BVH_Vec3i.def("y", (int (BVH_Vec3i::*)() const ) &BVH_Vec3i::y, "Alias to 2nd component as Y coordinate in XYZ.");
	cls_BVH_Vec3i.def("g", (int (BVH_Vec3i::*)() const ) &BVH_Vec3i::g, "Alias to 2nd component as GREEN channel in RGB.");
	cls_BVH_Vec3i.def("z", (int (BVH_Vec3i::*)() const ) &BVH_Vec3i::z, "Alias to 3rd component as Z coordinate in XYZ.");
	cls_BVH_Vec3i.def("b", (int (BVH_Vec3i::*)() const ) &BVH_Vec3i::b, "Alias to 3rd component as BLUE channel in RGB.");
	cls_BVH_Vec3i.def("xy", (const NCollection_Vec2<int> (BVH_Vec3i::*)() const ) &BVH_Vec3i::xy, "None");
	cls_BVH_Vec3i.def("yx", (const NCollection_Vec2<int> (BVH_Vec3i::*)() const ) &BVH_Vec3i::yx, "None");
	cls_BVH_Vec3i.def("xz", (const NCollection_Vec2<int> (BVH_Vec3i::*)() const ) &BVH_Vec3i::xz, "None");
	cls_BVH_Vec3i.def("zx", (const NCollection_Vec2<int> (BVH_Vec3i::*)() const ) &BVH_Vec3i::zx, "None");
	cls_BVH_Vec3i.def("yz", (const NCollection_Vec2<int> (BVH_Vec3i::*)() const ) &BVH_Vec3i::yz, "None");
	cls_BVH_Vec3i.def("zy", (const NCollection_Vec2<int> (BVH_Vec3i::*)() const ) &BVH_Vec3i::zy, "None");
	cls_BVH_Vec3i.def("xyz", (const BVH_Vec3i (BVH_Vec3i::*)() const ) &BVH_Vec3i::xyz, "None");
	cls_BVH_Vec3i.def("xzy", (const BVH_Vec3i (BVH_Vec3i::*)() const ) &BVH_Vec3i::xzy, "None");
	cls_BVH_Vec3i.def("yxz", (const BVH_Vec3i (BVH_Vec3i::*)() const ) &BVH_Vec3i::yxz, "None");
	cls_BVH_Vec3i.def("yzx", (const BVH_Vec3i (BVH_Vec3i::*)() const ) &BVH_Vec3i::yzx, "None");
	cls_BVH_Vec3i.def("zyx", (const BVH_Vec3i (BVH_Vec3i::*)() const ) &BVH_Vec3i::zyx, "None");
	cls_BVH_Vec3i.def("zxy", (const BVH_Vec3i (BVH_Vec3i::*)() const ) &BVH_Vec3i::zxy, "None");
	cls_BVH_Vec3i.def("x", (int & (BVH_Vec3i::*)()) &BVH_Vec3i::x, "Alias to 1st component as X coordinate in XYZ.");
	cls_BVH_Vec3i.def("r", (int & (BVH_Vec3i::*)()) &BVH_Vec3i::r, "Alias to 1st component as RED channel in RGB.");
	cls_BVH_Vec3i.def("y", (int & (BVH_Vec3i::*)()) &BVH_Vec3i::y, "Alias to 2nd component as Y coordinate in XYZ.");
	cls_BVH_Vec3i.def("g", (int & (BVH_Vec3i::*)()) &BVH_Vec3i::g, "Alias to 2nd component as GREEN channel in RGB.");
	cls_BVH_Vec3i.def("z", (int & (BVH_Vec3i::*)()) &BVH_Vec3i::z, "Alias to 3rd component as Z coordinate in XYZ.");
	cls_BVH_Vec3i.def("b", (int & (BVH_Vec3i::*)()) &BVH_Vec3i::b, "Alias to 3rd component as BLUE channel in RGB.");
	cls_BVH_Vec3i.def("xy", (NCollection_Vec2<int> & (BVH_Vec3i::*)()) &BVH_Vec3i::xy, "Returns XY-components modifiable vector");
	cls_BVH_Vec3i.def("yz", (NCollection_Vec2<int> & (BVH_Vec3i::*)()) &BVH_Vec3i::yz, "Returns YZ-components modifiable vector");
	cls_BVH_Vec3i.def("IsEqual", (bool (BVH_Vec3i::*)(const BVH_Vec3i &) const ) &BVH_Vec3i::IsEqual, "Check this vector with another vector for equality (without tolerance!).", py::arg("theOther"));
	cls_BVH_Vec3i.def("__eq__", (bool (BVH_Vec3i::*)(const BVH_Vec3i &)) &BVH_Vec3i::operator==, py::is_operator(), "Check this vector with another vector for equality (without tolerance!).", py::arg("theOther"));
	cls_BVH_Vec3i.def("__eq__", (bool (BVH_Vec3i::*)(const BVH_Vec3i &) const ) &BVH_Vec3i::operator==, py::is_operator(), "None", py::arg("theOther"));
	cls_BVH_Vec3i.def("__ne__", (bool (BVH_Vec3i::*)(const BVH_Vec3i &)) &BVH_Vec3i::operator!=, py::is_operator(), "Check this vector with another vector for non-equality (without tolerance!).", py::arg("theOther"));
	cls_BVH_Vec3i.def("__ne__", (bool (BVH_Vec3i::*)(const BVH_Vec3i &) const ) &BVH_Vec3i::operator!=, py::is_operator(), "None", py::arg("theOther"));
	cls_BVH_Vec3i.def("GetData", (const int * (BVH_Vec3i::*)() const ) &BVH_Vec3i::GetData, "Raw access to the data (for OpenGL exchange).");
	cls_BVH_Vec3i.def("ChangeData", (int * (BVH_Vec3i::*)()) &BVH_Vec3i::ChangeData, "None");
	cls_BVH_Vec3i.def("__iadd__", (BVH_Vec3i & (BVH_Vec3i::*)(const BVH_Vec3i &)) &BVH_Vec3i::operator+=, "Compute per-component summary.", py::arg("theAdd"));
	cls_BVH_Vec3i.def("__sub__", (BVH_Vec3i (BVH_Vec3i::*)() const ) &BVH_Vec3i::operator-, py::is_operator(), "Unary -.");
	cls_BVH_Vec3i.def("__isub__", (BVH_Vec3i & (BVH_Vec3i::*)(const BVH_Vec3i &)) &BVH_Vec3i::operator-=, "Compute per-component subtraction.", py::arg("theDec"));
	cls_BVH_Vec3i.def("Multiply", (void (BVH_Vec3i::*)(const int)) &BVH_Vec3i::Multiply, "Compute per-component multiplication by scale factor.", py::arg("theFactor"));
	cls_BVH_Vec3i.def("__imul__", (BVH_Vec3i & (BVH_Vec3i::*)(const BVH_Vec3i &)) &BVH_Vec3i::operator*=, "Compute per-component multiplication.", py::arg("theRight"));
	cls_BVH_Vec3i.def("__imul__", (BVH_Vec3i & (BVH_Vec3i::*)(const int)) &BVH_Vec3i::operator*=, "Compute per-component multiplication by scale factor.", py::arg("theFactor"));
	cls_BVH_Vec3i.def("__mul__", (BVH_Vec3i (BVH_Vec3i::*)(const int) const ) &BVH_Vec3i::operator*, py::is_operator(), "Compute per-component multiplication by scale factor.", py::arg("theFactor"));
	cls_BVH_Vec3i.def("Multiplied", (BVH_Vec3i (BVH_Vec3i::*)(const int) const ) &BVH_Vec3i::Multiplied, "Compute per-component multiplication by scale factor.", py::arg("theFactor"));
	cls_BVH_Vec3i.def("cwiseMin", (BVH_Vec3i (BVH_Vec3i::*)(const BVH_Vec3i &) const ) &BVH_Vec3i::cwiseMin, "Compute component-wise minimum of two vectors.", py::arg("theVec"));
	cls_BVH_Vec3i.def("cwiseMax", (BVH_Vec3i (BVH_Vec3i::*)(const BVH_Vec3i &) const ) &BVH_Vec3i::cwiseMax, "Compute component-wise maximum of two vectors.", py::arg("theVec"));
	cls_BVH_Vec3i.def("cwiseAbs", (BVH_Vec3i (BVH_Vec3i::*)() const ) &BVH_Vec3i::cwiseAbs, "Compute component-wise modulus of the vector.");
	cls_BVH_Vec3i.def("maxComp", (int (BVH_Vec3i::*)() const ) &BVH_Vec3i::maxComp, "Compute maximum component of the vector.");
	cls_BVH_Vec3i.def("minComp", (int (BVH_Vec3i::*)() const ) &BVH_Vec3i::minComp, "Compute minimum component of the vector.");
	cls_BVH_Vec3i.def("__itruediv__", (BVH_Vec3i & (BVH_Vec3i::*)(const int)) &BVH_Vec3i::operator/=, "Compute per-component division by scale factor.", py::arg("theInvFactor"));
	cls_BVH_Vec3i.def("__truediv__", (BVH_Vec3i (BVH_Vec3i::*)(const int)) &BVH_Vec3i::operator/, py::is_operator(), "Compute per-component division by scale factor.", py::arg("theInvFactor"));
	cls_BVH_Vec3i.def("Dot", (int (BVH_Vec3i::*)(const BVH_Vec3i &) const ) &BVH_Vec3i::Dot, "Computes the dot product.", py::arg("theOther"));
	cls_BVH_Vec3i.def("Modulus", (int (BVH_Vec3i::*)() const ) &BVH_Vec3i::Modulus, "Computes the vector modulus (magnitude, length).");
	cls_BVH_Vec3i.def("SquareModulus", (int (BVH_Vec3i::*)() const ) &BVH_Vec3i::SquareModulus, "Computes the square of vector modulus (magnitude, length). This method may be used for performance tricks.");
	cls_BVH_Vec3i.def("Normalize", (void (BVH_Vec3i::*)()) &BVH_Vec3i::Normalize, "Normalize the vector.");
	cls_BVH_Vec3i.def("Normalized", (BVH_Vec3i (BVH_Vec3i::*)() const ) &BVH_Vec3i::Normalized, "Normalize the vector.");
	cls_BVH_Vec3i.def_static("Cross_", (BVH_Vec3i (*)(const BVH_Vec3i &, const BVH_Vec3i &)) &BVH_Vec3i::Cross, "Computes the cross product.", py::arg("theVec1"), py::arg("theVec2"));
	cls_BVH_Vec3i.def_static("GetLERP_", (BVH_Vec3i (*)(const BVH_Vec3i &, const BVH_Vec3i &, const int)) &BVH_Vec3i::GetLERP, "Compute linear interpolation between to vectors.", py::arg("theFrom"), py::arg("theTo"), py::arg("theT"));
	cls_BVH_Vec3i.def_static("DX_", (BVH_Vec3i (*)()) &BVH_Vec3i::DX, "Constuct DX unit vector.");
	cls_BVH_Vec3i.def_static("DY_", (BVH_Vec3i (*)()) &BVH_Vec3i::DY, "Constuct DY unit vector.");
	cls_BVH_Vec3i.def_static("DZ_", (BVH_Vec3i (*)()) &BVH_Vec3i::DZ, "Constuct DZ unit vector.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Vec4.hxx
	py::class_<BVH_Vec4i, std::unique_ptr<BVH_Vec4i, Deleter<BVH_Vec4i>>> cls_BVH_Vec4i(mod, "BVH_Vec4i", "Generic 4-components vector. To be used as RGBA color vector or XYZW 3D-point with special W-component for operations with projection / model view matrices. Use this class for 3D-points carefully because declared W-component may results in incorrect results if used without matrices.");
	cls_BVH_Vec4i.def(py::init<>());
	cls_BVH_Vec4i.def(py::init<const int>(), py::arg("theValue"));
	cls_BVH_Vec4i.def(py::init<const int, const int, const int, const int>(), py::arg("theX"), py::arg("theY"), py::arg("theZ"), py::arg("theW"));
	cls_BVH_Vec4i.def(py::init<const NCollection_Vec2<int> &>(), py::arg("theVec2"));
	cls_BVH_Vec4i.def(py::init<const NCollection_Vec3<int> &>(), py::arg("theVec3"));
	cls_BVH_Vec4i.def(py::init<const NCollection_Vec3<int> &, const int>(), py::arg("theVec3"), py::arg("theAlpha"));
	cls_BVH_Vec4i.def_static("Length_", (int (*)()) &BVH_Vec4i::Length, "Returns the number of components.");
	cls_BVH_Vec4i.def("SetValues", (void (BVH_Vec4i::*)(const int, const int, const int, const int)) &BVH_Vec4i::SetValues, "Assign new values to the vector.", py::arg("theX"), py::arg("theY"), py::arg("theZ"), py::arg("theW"));
	cls_BVH_Vec4i.def("x", (int (BVH_Vec4i::*)() const ) &BVH_Vec4i::x, "Alias to 1st component as X coordinate in XYZW.");
	cls_BVH_Vec4i.def("r", (int (BVH_Vec4i::*)() const ) &BVH_Vec4i::r, "Alias to 1st component as RED channel in RGBA.");
	cls_BVH_Vec4i.def("y", (int (BVH_Vec4i::*)() const ) &BVH_Vec4i::y, "Alias to 2nd component as Y coordinate in XYZW.");
	cls_BVH_Vec4i.def("g", (int (BVH_Vec4i::*)() const ) &BVH_Vec4i::g, "Alias to 2nd component as GREEN channel in RGBA.");
	cls_BVH_Vec4i.def("z", (int (BVH_Vec4i::*)() const ) &BVH_Vec4i::z, "Alias to 3rd component as Z coordinate in XYZW.");
	cls_BVH_Vec4i.def("b", (int (BVH_Vec4i::*)() const ) &BVH_Vec4i::b, "Alias to 3rd component as BLUE channel in RGBA.");
	cls_BVH_Vec4i.def("w", (int (BVH_Vec4i::*)() const ) &BVH_Vec4i::w, "Alias to 4th component as W coordinate in XYZW.");
	cls_BVH_Vec4i.def("a", (int (BVH_Vec4i::*)() const ) &BVH_Vec4i::a, "Alias to 4th component as ALPHA channel in RGBA.");
	cls_BVH_Vec4i.def("xy", (const NCollection_Vec2<int> (BVH_Vec4i::*)() const ) &BVH_Vec4i::xy, "None");
	cls_BVH_Vec4i.def("yx", (const NCollection_Vec2<int> (BVH_Vec4i::*)() const ) &BVH_Vec4i::yx, "None");
	cls_BVH_Vec4i.def("xz", (const NCollection_Vec2<int> (BVH_Vec4i::*)() const ) &BVH_Vec4i::xz, "None");
	cls_BVH_Vec4i.def("zx", (const NCollection_Vec2<int> (BVH_Vec4i::*)() const ) &BVH_Vec4i::zx, "None");
	cls_BVH_Vec4i.def("xw", (const NCollection_Vec2<int> (BVH_Vec4i::*)() const ) &BVH_Vec4i::xw, "None");
	cls_BVH_Vec4i.def("wx", (const NCollection_Vec2<int> (BVH_Vec4i::*)() const ) &BVH_Vec4i::wx, "None");
	cls_BVH_Vec4i.def("yz", (const NCollection_Vec2<int> (BVH_Vec4i::*)() const ) &BVH_Vec4i::yz, "None");
	cls_BVH_Vec4i.def("zy", (const NCollection_Vec2<int> (BVH_Vec4i::*)() const ) &BVH_Vec4i::zy, "None");
	cls_BVH_Vec4i.def("yw", (const NCollection_Vec2<int> (BVH_Vec4i::*)() const ) &BVH_Vec4i::yw, "None");
	cls_BVH_Vec4i.def("wy", (const NCollection_Vec2<int> (BVH_Vec4i::*)() const ) &BVH_Vec4i::wy, "None");
	cls_BVH_Vec4i.def("zw", (const NCollection_Vec2<int> (BVH_Vec4i::*)() const ) &BVH_Vec4i::zw, "None");
	cls_BVH_Vec4i.def("wz", (const NCollection_Vec2<int> (BVH_Vec4i::*)() const ) &BVH_Vec4i::wz, "None");
	cls_BVH_Vec4i.def("xyz", (const NCollection_Vec3<int> (BVH_Vec4i::*)() const ) &BVH_Vec4i::xyz, "None");
	cls_BVH_Vec4i.def("xzy", (const NCollection_Vec3<int> (BVH_Vec4i::*)() const ) &BVH_Vec4i::xzy, "None");
	cls_BVH_Vec4i.def("yxz", (const NCollection_Vec3<int> (BVH_Vec4i::*)() const ) &BVH_Vec4i::yxz, "None");
	cls_BVH_Vec4i.def("yzx", (const NCollection_Vec3<int> (BVH_Vec4i::*)() const ) &BVH_Vec4i::yzx, "None");
	cls_BVH_Vec4i.def("zyx", (const NCollection_Vec3<int> (BVH_Vec4i::*)() const ) &BVH_Vec4i::zyx, "None");
	cls_BVH_Vec4i.def("zxy", (const NCollection_Vec3<int> (BVH_Vec4i::*)() const ) &BVH_Vec4i::zxy, "None");
	cls_BVH_Vec4i.def("xyw", (const NCollection_Vec3<int> (BVH_Vec4i::*)() const ) &BVH_Vec4i::xyw, "None");
	cls_BVH_Vec4i.def("xwy", (const NCollection_Vec3<int> (BVH_Vec4i::*)() const ) &BVH_Vec4i::xwy, "None");
	cls_BVH_Vec4i.def("yxw", (const NCollection_Vec3<int> (BVH_Vec4i::*)() const ) &BVH_Vec4i::yxw, "None");
	cls_BVH_Vec4i.def("ywx", (const NCollection_Vec3<int> (BVH_Vec4i::*)() const ) &BVH_Vec4i::ywx, "None");
	cls_BVH_Vec4i.def("wyx", (const NCollection_Vec3<int> (BVH_Vec4i::*)() const ) &BVH_Vec4i::wyx, "None");
	cls_BVH_Vec4i.def("wxy", (const NCollection_Vec3<int> (BVH_Vec4i::*)() const ) &BVH_Vec4i::wxy, "None");
	cls_BVH_Vec4i.def("xzw", (const NCollection_Vec3<int> (BVH_Vec4i::*)() const ) &BVH_Vec4i::xzw, "None");
	cls_BVH_Vec4i.def("xwz", (const NCollection_Vec3<int> (BVH_Vec4i::*)() const ) &BVH_Vec4i::xwz, "None");
	cls_BVH_Vec4i.def("zxw", (const NCollection_Vec3<int> (BVH_Vec4i::*)() const ) &BVH_Vec4i::zxw, "None");
	cls_BVH_Vec4i.def("zwx", (const NCollection_Vec3<int> (BVH_Vec4i::*)() const ) &BVH_Vec4i::zwx, "None");
	cls_BVH_Vec4i.def("wzx", (const NCollection_Vec3<int> (BVH_Vec4i::*)() const ) &BVH_Vec4i::wzx, "None");
	cls_BVH_Vec4i.def("wxz", (const NCollection_Vec3<int> (BVH_Vec4i::*)() const ) &BVH_Vec4i::wxz, "None");
	cls_BVH_Vec4i.def("yzw", (const NCollection_Vec3<int> (BVH_Vec4i::*)() const ) &BVH_Vec4i::yzw, "None");
	cls_BVH_Vec4i.def("ywz", (const NCollection_Vec3<int> (BVH_Vec4i::*)() const ) &BVH_Vec4i::ywz, "None");
	cls_BVH_Vec4i.def("zyw", (const NCollection_Vec3<int> (BVH_Vec4i::*)() const ) &BVH_Vec4i::zyw, "None");
	cls_BVH_Vec4i.def("zwy", (const NCollection_Vec3<int> (BVH_Vec4i::*)() const ) &BVH_Vec4i::zwy, "None");
	cls_BVH_Vec4i.def("wzy", (const NCollection_Vec3<int> (BVH_Vec4i::*)() const ) &BVH_Vec4i::wzy, "None");
	cls_BVH_Vec4i.def("wyz", (const NCollection_Vec3<int> (BVH_Vec4i::*)() const ) &BVH_Vec4i::wyz, "None");
	cls_BVH_Vec4i.def("rgb", (const NCollection_Vec3<int> (BVH_Vec4i::*)() const ) &BVH_Vec4i::rgb, "None");
	cls_BVH_Vec4i.def("rbg", (const NCollection_Vec3<int> (BVH_Vec4i::*)() const ) &BVH_Vec4i::rbg, "None");
	cls_BVH_Vec4i.def("grb", (const NCollection_Vec3<int> (BVH_Vec4i::*)() const ) &BVH_Vec4i::grb, "None");
	cls_BVH_Vec4i.def("gbr", (const NCollection_Vec3<int> (BVH_Vec4i::*)() const ) &BVH_Vec4i::gbr, "None");
	cls_BVH_Vec4i.def("bgr", (const NCollection_Vec3<int> (BVH_Vec4i::*)() const ) &BVH_Vec4i::bgr, "None");
	cls_BVH_Vec4i.def("brg", (const NCollection_Vec3<int> (BVH_Vec4i::*)() const ) &BVH_Vec4i::brg, "None");
	cls_BVH_Vec4i.def("x", (int & (BVH_Vec4i::*)()) &BVH_Vec4i::x, "Alias to 1st component as X coordinate in XYZW.");
	cls_BVH_Vec4i.def("r", (int & (BVH_Vec4i::*)()) &BVH_Vec4i::r, "Alias to 1st component as RED channel in RGBA.");
	cls_BVH_Vec4i.def("y", (int & (BVH_Vec4i::*)()) &BVH_Vec4i::y, "Alias to 2nd component as Y coordinate in XYZW.");
	cls_BVH_Vec4i.def("g", (int & (BVH_Vec4i::*)()) &BVH_Vec4i::g, "Alias to 2nd component as GREEN channel in RGBA.");
	cls_BVH_Vec4i.def("z", (int & (BVH_Vec4i::*)()) &BVH_Vec4i::z, "Alias to 3rd component as Z coordinate in XYZW.");
	cls_BVH_Vec4i.def("b", (int & (BVH_Vec4i::*)()) &BVH_Vec4i::b, "Alias to 3rd component as BLUE channel in RGBA.");
	cls_BVH_Vec4i.def("w", (int & (BVH_Vec4i::*)()) &BVH_Vec4i::w, "Alias to 4th component as W coordinate in XYZW.");
	cls_BVH_Vec4i.def("a", (int & (BVH_Vec4i::*)()) &BVH_Vec4i::a, "Alias to 4th component as ALPHA channel in RGBA.");
	cls_BVH_Vec4i.def("xy", (NCollection_Vec2<int> & (BVH_Vec4i::*)()) &BVH_Vec4i::xy, "Returns XY-components modifiable vector");
	cls_BVH_Vec4i.def("yz", (NCollection_Vec2<int> & (BVH_Vec4i::*)()) &BVH_Vec4i::yz, "Returns YZ-components modifiable vector");
	cls_BVH_Vec4i.def("zw", (NCollection_Vec2<int> & (BVH_Vec4i::*)()) &BVH_Vec4i::zw, "Returns YZ-components modifiable vector");
	cls_BVH_Vec4i.def("xyz", (NCollection_Vec3<int> & (BVH_Vec4i::*)()) &BVH_Vec4i::xyz, "Returns XYZ-components modifiable vector");
	cls_BVH_Vec4i.def("yzw", (NCollection_Vec3<int> & (BVH_Vec4i::*)()) &BVH_Vec4i::yzw, "Returns YZW-components modifiable vector");
	cls_BVH_Vec4i.def("IsEqual", (bool (BVH_Vec4i::*)(const BVH_Vec4i &) const ) &BVH_Vec4i::IsEqual, "Check this vector with another vector for equality (without tolerance!).", py::arg("theOther"));
	cls_BVH_Vec4i.def("__eq__", (bool (BVH_Vec4i::*)(const BVH_Vec4i &)) &BVH_Vec4i::operator==, py::is_operator(), "Check this vector with another vector for equality (without tolerance!).", py::arg("theOther"));
	cls_BVH_Vec4i.def("__eq__", (bool (BVH_Vec4i::*)(const BVH_Vec4i &) const ) &BVH_Vec4i::operator==, py::is_operator(), "None", py::arg("theOther"));
	cls_BVH_Vec4i.def("__ne__", (bool (BVH_Vec4i::*)(const BVH_Vec4i &)) &BVH_Vec4i::operator!=, py::is_operator(), "Check this vector with another vector for non-equality (without tolerance!).", py::arg("theOther"));
	cls_BVH_Vec4i.def("__ne__", (bool (BVH_Vec4i::*)(const BVH_Vec4i &) const ) &BVH_Vec4i::operator!=, py::is_operator(), "None", py::arg("theOther"));
	cls_BVH_Vec4i.def("GetData", (const int * (BVH_Vec4i::*)() const ) &BVH_Vec4i::GetData, "Raw access to the data (for OpenGL exchange).");
	cls_BVH_Vec4i.def("ChangeData", (int * (BVH_Vec4i::*)()) &BVH_Vec4i::ChangeData, "None");
	cls_BVH_Vec4i.def("__iadd__", (BVH_Vec4i & (BVH_Vec4i::*)(const BVH_Vec4i &)) &BVH_Vec4i::operator+=, "Compute per-component summary.", py::arg("theAdd"));
	cls_BVH_Vec4i.def("__sub__", (BVH_Vec4i (BVH_Vec4i::*)() const ) &BVH_Vec4i::operator-, py::is_operator(), "Unary -.");
	cls_BVH_Vec4i.def("__isub__", (BVH_Vec4i & (BVH_Vec4i::*)(const BVH_Vec4i &)) &BVH_Vec4i::operator-=, "Compute per-component subtraction.", py::arg("theDec"));
	cls_BVH_Vec4i.def("__imul__", (BVH_Vec4i & (BVH_Vec4i::*)(const BVH_Vec4i &)) &BVH_Vec4i::operator*=, "Compute per-component multiplication.", py::arg("theRight"));
	cls_BVH_Vec4i.def("Multiply", (void (BVH_Vec4i::*)(const int)) &BVH_Vec4i::Multiply, "Compute per-component multiplication.", py::arg("theFactor"));
	cls_BVH_Vec4i.def("__imul__", (BVH_Vec4i & (BVH_Vec4i::*)(const int)) &BVH_Vec4i::operator*=, "Compute per-component multiplication.", py::arg("theFactor"));
	cls_BVH_Vec4i.def("__mul__", (BVH_Vec4i (BVH_Vec4i::*)(const int) const ) &BVH_Vec4i::operator*, py::is_operator(), "Compute per-component multiplication.", py::arg("theFactor"));
	cls_BVH_Vec4i.def("Multiplied", (BVH_Vec4i (BVH_Vec4i::*)(const int) const ) &BVH_Vec4i::Multiplied, "Compute per-component multiplication.", py::arg("theFactor"));
	cls_BVH_Vec4i.def("cwiseMin", (BVH_Vec4i (BVH_Vec4i::*)(const BVH_Vec4i &) const ) &BVH_Vec4i::cwiseMin, "Compute component-wise minimum of two vectors.", py::arg("theVec"));
	cls_BVH_Vec4i.def("cwiseMax", (BVH_Vec4i (BVH_Vec4i::*)(const BVH_Vec4i &) const ) &BVH_Vec4i::cwiseMax, "Compute component-wise maximum of two vectors.", py::arg("theVec"));
	cls_BVH_Vec4i.def("cwiseAbs", (BVH_Vec4i (BVH_Vec4i::*)() const ) &BVH_Vec4i::cwiseAbs, "Compute component-wise modulus of the vector.");
	cls_BVH_Vec4i.def("maxComp", (int (BVH_Vec4i::*)() const ) &BVH_Vec4i::maxComp, "Compute maximum component of the vector.");
	cls_BVH_Vec4i.def("minComp", (int (BVH_Vec4i::*)() const ) &BVH_Vec4i::minComp, "Compute minimum component of the vector.");
	cls_BVH_Vec4i.def("Dot", (int (BVH_Vec4i::*)(const BVH_Vec4i &) const ) &BVH_Vec4i::Dot, "Computes the dot product.", py::arg("theOther"));
	cls_BVH_Vec4i.def("__itruediv__", (BVH_Vec4i & (BVH_Vec4i::*)(const int)) &BVH_Vec4i::operator/=, "Compute per-component division by scale factor.", py::arg("theInvFactor"));
	cls_BVH_Vec4i.def("__truediv__", (BVH_Vec4i (BVH_Vec4i::*)(const int)) &BVH_Vec4i::operator/, py::is_operator(), "Compute per-component division by scale factor.", py::arg("theInvFactor"));

	/* FIXME
	// BVH_Array2i
	*/

	/* FIXME
	// BVH_Array3i
	*/

	/* FIXME
	// BVH_Array4i
	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Vec2.hxx
	py::class_<BVH_Vec2f, std::unique_ptr<BVH_Vec2f, Deleter<BVH_Vec2f>>> cls_BVH_Vec2f(mod, "BVH_Vec2f", "Defines the 2D-vector template. The main target for this class - to handle raw low-level arrays (from/to graphic driver etc.).");
	cls_BVH_Vec2f.def(py::init<>());
	cls_BVH_Vec2f.def(py::init<const float>(), py::arg("theXY"));
	cls_BVH_Vec2f.def(py::init<const float, const float>(), py::arg("theX"), py::arg("theY"));
	cls_BVH_Vec2f.def_static("Length_", (int (*)()) &BVH_Vec2f::Length, "Returns the number of components.");
	cls_BVH_Vec2f.def("SetValues", (void (BVH_Vec2f::*)(const float, const float)) &BVH_Vec2f::SetValues, "Assign new values to the vector.", py::arg("theX"), py::arg("theY"));
	cls_BVH_Vec2f.def("x", (float (BVH_Vec2f::*)() const ) &BVH_Vec2f::x, "Alias to 1st component as X coordinate in XY.");
	cls_BVH_Vec2f.def("y", (float (BVH_Vec2f::*)() const ) &BVH_Vec2f::y, "Alias to 2nd component as Y coordinate in XY.");
	cls_BVH_Vec2f.def("xy", (const BVH_Vec2f (BVH_Vec2f::*)() const ) &BVH_Vec2f::xy, "None");
	cls_BVH_Vec2f.def("yx", (const BVH_Vec2f (BVH_Vec2f::*)() const ) &BVH_Vec2f::yx, "None");
	cls_BVH_Vec2f.def("x", (float & (BVH_Vec2f::*)()) &BVH_Vec2f::x, "Alias to 1st component as X coordinate in XY.");
	cls_BVH_Vec2f.def("y", (float & (BVH_Vec2f::*)()) &BVH_Vec2f::y, "Alias to 2nd component as Y coordinate in XY.");
	cls_BVH_Vec2f.def("IsEqual", (bool (BVH_Vec2f::*)(const BVH_Vec2f &) const ) &BVH_Vec2f::IsEqual, "Check this vector with another vector for equality (without tolerance!).", py::arg("theOther"));
	cls_BVH_Vec2f.def("__eq__", (bool (BVH_Vec2f::*)(const BVH_Vec2f &)) &BVH_Vec2f::operator==, py::is_operator(), "Check this vector with another vector for equality (without tolerance!).", py::arg("theOther"));
	cls_BVH_Vec2f.def("__eq__", (bool (BVH_Vec2f::*)(const BVH_Vec2f &) const ) &BVH_Vec2f::operator==, py::is_operator(), "None", py::arg("theOther"));
	cls_BVH_Vec2f.def("__ne__", (bool (BVH_Vec2f::*)(const BVH_Vec2f &)) &BVH_Vec2f::operator!=, py::is_operator(), "Check this vector with another vector for non-equality (without tolerance!).", py::arg("theOther"));
	cls_BVH_Vec2f.def("__ne__", (bool (BVH_Vec2f::*)(const BVH_Vec2f &) const ) &BVH_Vec2f::operator!=, py::is_operator(), "None", py::arg("theOther"));
	cls_BVH_Vec2f.def("GetData", (const float * (BVH_Vec2f::*)() const ) &BVH_Vec2f::GetData, "Raw access to the data (for OpenGL exchange).");
	cls_BVH_Vec2f.def("ChangeData", (float * (BVH_Vec2f::*)()) &BVH_Vec2f::ChangeData, "None");
	cls_BVH_Vec2f.def("__iadd__", (BVH_Vec2f & (BVH_Vec2f::*)(const BVH_Vec2f &)) &BVH_Vec2f::operator+=, "Compute per-component summary.", py::arg("theAdd"));
	cls_BVH_Vec2f.def("__isub__", (BVH_Vec2f & (BVH_Vec2f::*)(const BVH_Vec2f &)) &BVH_Vec2f::operator-=, "Compute per-component subtraction.", py::arg("theDec"));
	cls_BVH_Vec2f.def("__sub__", (BVH_Vec2f (BVH_Vec2f::*)() const ) &BVH_Vec2f::operator-, py::is_operator(), "Unary -.");
	cls_BVH_Vec2f.def("__imul__", (BVH_Vec2f & (BVH_Vec2f::*)(const BVH_Vec2f &)) &BVH_Vec2f::operator*=, "Compute per-component multiplication.", py::arg("theRight"));
	cls_BVH_Vec2f.def("Multiply", (void (BVH_Vec2f::*)(const float)) &BVH_Vec2f::Multiply, "Compute per-component multiplication by scale factor.", py::arg("theFactor"));
	cls_BVH_Vec2f.def("Multiplied", (BVH_Vec2f (BVH_Vec2f::*)(const float) const ) &BVH_Vec2f::Multiplied, "Compute per-component multiplication by scale factor.", py::arg("theFactor"));
	cls_BVH_Vec2f.def("cwiseMin", (BVH_Vec2f (BVH_Vec2f::*)(const BVH_Vec2f &) const ) &BVH_Vec2f::cwiseMin, "Compute component-wise minimum of two vectors.", py::arg("theVec"));
	cls_BVH_Vec2f.def("cwiseMax", (BVH_Vec2f (BVH_Vec2f::*)(const BVH_Vec2f &) const ) &BVH_Vec2f::cwiseMax, "Compute component-wise maximum of two vectors.", py::arg("theVec"));
	cls_BVH_Vec2f.def("cwiseAbs", (BVH_Vec2f (BVH_Vec2f::*)() const ) &BVH_Vec2f::cwiseAbs, "Compute component-wise modulus of the vector.");
	cls_BVH_Vec2f.def("maxComp", (float (BVH_Vec2f::*)() const ) &BVH_Vec2f::maxComp, "Compute maximum component of the vector.");
	cls_BVH_Vec2f.def("minComp", (float (BVH_Vec2f::*)() const ) &BVH_Vec2f::minComp, "Compute minimum component of the vector.");
	cls_BVH_Vec2f.def("__imul__", (BVH_Vec2f & (BVH_Vec2f::*)(const float)) &BVH_Vec2f::operator*=, "Compute per-component multiplication by scale factor.", py::arg("theFactor"));
	cls_BVH_Vec2f.def("__itruediv__", (BVH_Vec2f & (BVH_Vec2f::*)(const float)) &BVH_Vec2f::operator/=, "Compute per-component division by scale factor.", py::arg("theInvFactor"));
	cls_BVH_Vec2f.def("__mul__", (BVH_Vec2f (BVH_Vec2f::*)(const float) const ) &BVH_Vec2f::operator*, py::is_operator(), "Compute per-component multiplication by scale factor.", py::arg("theFactor"));
	cls_BVH_Vec2f.def("__truediv__", (BVH_Vec2f (BVH_Vec2f::*)(const float) const ) &BVH_Vec2f::operator/, py::is_operator(), "Compute per-component division by scale factor.", py::arg("theInvFactor"));
	cls_BVH_Vec2f.def("Dot", (float (BVH_Vec2f::*)(const BVH_Vec2f &) const ) &BVH_Vec2f::Dot, "Computes the dot product.", py::arg("theOther"));
	cls_BVH_Vec2f.def("Modulus", (float (BVH_Vec2f::*)() const ) &BVH_Vec2f::Modulus, "Computes the vector modulus (magnitude, length).");
	cls_BVH_Vec2f.def("SquareModulus", (float (BVH_Vec2f::*)() const ) &BVH_Vec2f::SquareModulus, "Computes the square of vector modulus (magnitude, length). This method may be used for performance tricks.");
	cls_BVH_Vec2f.def_static("DX_", (BVH_Vec2f (*)()) &BVH_Vec2f::DX, "Constuct DX unit vector.");
	cls_BVH_Vec2f.def_static("DY_", (BVH_Vec2f (*)()) &BVH_Vec2f::DY, "Constuct DY unit vector.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Vec3.hxx
	py::class_<BVH_Vec3f, std::unique_ptr<BVH_Vec3f, Deleter<BVH_Vec3f>>> cls_BVH_Vec3f(mod, "BVH_Vec3f", "Generic 3-components vector. To be used as RGB color pixel or XYZ 3D-point. The main target for this class - to handle raw low-level arrays (from/to graphic driver etc.).");
	cls_BVH_Vec3f.def(py::init<>());
	cls_BVH_Vec3f.def(py::init<float>(), py::arg("theValue"));
	cls_BVH_Vec3f.def(py::init<const float, const float, const float>(), py::arg("theX"), py::arg("theY"), py::arg("theZ"));
	cls_BVH_Vec3f.def(py::init<const NCollection_Vec2<float> &>(), py::arg("theVec2"));
	cls_BVH_Vec3f.def_static("Length_", (int (*)()) &BVH_Vec3f::Length, "Returns the number of components.");
	cls_BVH_Vec3f.def("SetValues", (void (BVH_Vec3f::*)(const float, const float, const float)) &BVH_Vec3f::SetValues, "Assign new values to the vector.", py::arg("theX"), py::arg("theY"), py::arg("theZ"));
	cls_BVH_Vec3f.def("x", (float (BVH_Vec3f::*)() const ) &BVH_Vec3f::x, "Alias to 1st component as X coordinate in XYZ.");
	cls_BVH_Vec3f.def("r", (float (BVH_Vec3f::*)() const ) &BVH_Vec3f::r, "Alias to 1st component as RED channel in RGB.");
	cls_BVH_Vec3f.def("y", (float (BVH_Vec3f::*)() const ) &BVH_Vec3f::y, "Alias to 2nd component as Y coordinate in XYZ.");
	cls_BVH_Vec3f.def("g", (float (BVH_Vec3f::*)() const ) &BVH_Vec3f::g, "Alias to 2nd component as GREEN channel in RGB.");
	cls_BVH_Vec3f.def("z", (float (BVH_Vec3f::*)() const ) &BVH_Vec3f::z, "Alias to 3rd component as Z coordinate in XYZ.");
	cls_BVH_Vec3f.def("b", (float (BVH_Vec3f::*)() const ) &BVH_Vec3f::b, "Alias to 3rd component as BLUE channel in RGB.");
	cls_BVH_Vec3f.def("xy", (const NCollection_Vec2<float> (BVH_Vec3f::*)() const ) &BVH_Vec3f::xy, "None");
	cls_BVH_Vec3f.def("yx", (const NCollection_Vec2<float> (BVH_Vec3f::*)() const ) &BVH_Vec3f::yx, "None");
	cls_BVH_Vec3f.def("xz", (const NCollection_Vec2<float> (BVH_Vec3f::*)() const ) &BVH_Vec3f::xz, "None");
	cls_BVH_Vec3f.def("zx", (const NCollection_Vec2<float> (BVH_Vec3f::*)() const ) &BVH_Vec3f::zx, "None");
	cls_BVH_Vec3f.def("yz", (const NCollection_Vec2<float> (BVH_Vec3f::*)() const ) &BVH_Vec3f::yz, "None");
	cls_BVH_Vec3f.def("zy", (const NCollection_Vec2<float> (BVH_Vec3f::*)() const ) &BVH_Vec3f::zy, "None");
	cls_BVH_Vec3f.def("xyz", (const BVH_Vec3f (BVH_Vec3f::*)() const ) &BVH_Vec3f::xyz, "None");
	cls_BVH_Vec3f.def("xzy", (const BVH_Vec3f (BVH_Vec3f::*)() const ) &BVH_Vec3f::xzy, "None");
	cls_BVH_Vec3f.def("yxz", (const BVH_Vec3f (BVH_Vec3f::*)() const ) &BVH_Vec3f::yxz, "None");
	cls_BVH_Vec3f.def("yzx", (const BVH_Vec3f (BVH_Vec3f::*)() const ) &BVH_Vec3f::yzx, "None");
	cls_BVH_Vec3f.def("zyx", (const BVH_Vec3f (BVH_Vec3f::*)() const ) &BVH_Vec3f::zyx, "None");
	cls_BVH_Vec3f.def("zxy", (const BVH_Vec3f (BVH_Vec3f::*)() const ) &BVH_Vec3f::zxy, "None");
	cls_BVH_Vec3f.def("x", (float & (BVH_Vec3f::*)()) &BVH_Vec3f::x, "Alias to 1st component as X coordinate in XYZ.");
	cls_BVH_Vec3f.def("r", (float & (BVH_Vec3f::*)()) &BVH_Vec3f::r, "Alias to 1st component as RED channel in RGB.");
	cls_BVH_Vec3f.def("y", (float & (BVH_Vec3f::*)()) &BVH_Vec3f::y, "Alias to 2nd component as Y coordinate in XYZ.");
	cls_BVH_Vec3f.def("g", (float & (BVH_Vec3f::*)()) &BVH_Vec3f::g, "Alias to 2nd component as GREEN channel in RGB.");
	cls_BVH_Vec3f.def("z", (float & (BVH_Vec3f::*)()) &BVH_Vec3f::z, "Alias to 3rd component as Z coordinate in XYZ.");
	cls_BVH_Vec3f.def("b", (float & (BVH_Vec3f::*)()) &BVH_Vec3f::b, "Alias to 3rd component as BLUE channel in RGB.");
	cls_BVH_Vec3f.def("xy", (NCollection_Vec2<float> & (BVH_Vec3f::*)()) &BVH_Vec3f::xy, "Returns XY-components modifiable vector");
	cls_BVH_Vec3f.def("yz", (NCollection_Vec2<float> & (BVH_Vec3f::*)()) &BVH_Vec3f::yz, "Returns YZ-components modifiable vector");
	cls_BVH_Vec3f.def("IsEqual", (bool (BVH_Vec3f::*)(const BVH_Vec3f &) const ) &BVH_Vec3f::IsEqual, "Check this vector with another vector for equality (without tolerance!).", py::arg("theOther"));
	cls_BVH_Vec3f.def("__eq__", (bool (BVH_Vec3f::*)(const BVH_Vec3f &)) &BVH_Vec3f::operator==, py::is_operator(), "Check this vector with another vector for equality (without tolerance!).", py::arg("theOther"));
	cls_BVH_Vec3f.def("__eq__", (bool (BVH_Vec3f::*)(const BVH_Vec3f &) const ) &BVH_Vec3f::operator==, py::is_operator(), "None", py::arg("theOther"));
	cls_BVH_Vec3f.def("__ne__", (bool (BVH_Vec3f::*)(const BVH_Vec3f &)) &BVH_Vec3f::operator!=, py::is_operator(), "Check this vector with another vector for non-equality (without tolerance!).", py::arg("theOther"));
	cls_BVH_Vec3f.def("__ne__", (bool (BVH_Vec3f::*)(const BVH_Vec3f &) const ) &BVH_Vec3f::operator!=, py::is_operator(), "None", py::arg("theOther"));
	cls_BVH_Vec3f.def("GetData", (const float * (BVH_Vec3f::*)() const ) &BVH_Vec3f::GetData, "Raw access to the data (for OpenGL exchange).");
	cls_BVH_Vec3f.def("ChangeData", (float * (BVH_Vec3f::*)()) &BVH_Vec3f::ChangeData, "None");
	cls_BVH_Vec3f.def("__iadd__", (BVH_Vec3f & (BVH_Vec3f::*)(const BVH_Vec3f &)) &BVH_Vec3f::operator+=, "Compute per-component summary.", py::arg("theAdd"));
	cls_BVH_Vec3f.def("__sub__", (BVH_Vec3f (BVH_Vec3f::*)() const ) &BVH_Vec3f::operator-, py::is_operator(), "Unary -.");
	cls_BVH_Vec3f.def("__isub__", (BVH_Vec3f & (BVH_Vec3f::*)(const BVH_Vec3f &)) &BVH_Vec3f::operator-=, "Compute per-component subtraction.", py::arg("theDec"));
	cls_BVH_Vec3f.def("Multiply", (void (BVH_Vec3f::*)(const float)) &BVH_Vec3f::Multiply, "Compute per-component multiplication by scale factor.", py::arg("theFactor"));
	cls_BVH_Vec3f.def("__imul__", (BVH_Vec3f & (BVH_Vec3f::*)(const BVH_Vec3f &)) &BVH_Vec3f::operator*=, "Compute per-component multiplication.", py::arg("theRight"));
	cls_BVH_Vec3f.def("__imul__", (BVH_Vec3f & (BVH_Vec3f::*)(const float)) &BVH_Vec3f::operator*=, "Compute per-component multiplication by scale factor.", py::arg("theFactor"));
	cls_BVH_Vec3f.def("__mul__", (BVH_Vec3f (BVH_Vec3f::*)(const float) const ) &BVH_Vec3f::operator*, py::is_operator(), "Compute per-component multiplication by scale factor.", py::arg("theFactor"));
	cls_BVH_Vec3f.def("Multiplied", (BVH_Vec3f (BVH_Vec3f::*)(const float) const ) &BVH_Vec3f::Multiplied, "Compute per-component multiplication by scale factor.", py::arg("theFactor"));
	cls_BVH_Vec3f.def("cwiseMin", (BVH_Vec3f (BVH_Vec3f::*)(const BVH_Vec3f &) const ) &BVH_Vec3f::cwiseMin, "Compute component-wise minimum of two vectors.", py::arg("theVec"));
	cls_BVH_Vec3f.def("cwiseMax", (BVH_Vec3f (BVH_Vec3f::*)(const BVH_Vec3f &) const ) &BVH_Vec3f::cwiseMax, "Compute component-wise maximum of two vectors.", py::arg("theVec"));
	cls_BVH_Vec3f.def("cwiseAbs", (BVH_Vec3f (BVH_Vec3f::*)() const ) &BVH_Vec3f::cwiseAbs, "Compute component-wise modulus of the vector.");
	cls_BVH_Vec3f.def("maxComp", (float (BVH_Vec3f::*)() const ) &BVH_Vec3f::maxComp, "Compute maximum component of the vector.");
	cls_BVH_Vec3f.def("minComp", (float (BVH_Vec3f::*)() const ) &BVH_Vec3f::minComp, "Compute minimum component of the vector.");
	cls_BVH_Vec3f.def("__itruediv__", (BVH_Vec3f & (BVH_Vec3f::*)(const float)) &BVH_Vec3f::operator/=, "Compute per-component division by scale factor.", py::arg("theInvFactor"));
	cls_BVH_Vec3f.def("__truediv__", (BVH_Vec3f (BVH_Vec3f::*)(const float)) &BVH_Vec3f::operator/, py::is_operator(), "Compute per-component division by scale factor.", py::arg("theInvFactor"));
	cls_BVH_Vec3f.def("Dot", (float (BVH_Vec3f::*)(const BVH_Vec3f &) const ) &BVH_Vec3f::Dot, "Computes the dot product.", py::arg("theOther"));
	cls_BVH_Vec3f.def("Modulus", (float (BVH_Vec3f::*)() const ) &BVH_Vec3f::Modulus, "Computes the vector modulus (magnitude, length).");
	cls_BVH_Vec3f.def("SquareModulus", (float (BVH_Vec3f::*)() const ) &BVH_Vec3f::SquareModulus, "Computes the square of vector modulus (magnitude, length). This method may be used for performance tricks.");
	cls_BVH_Vec3f.def("Normalize", (void (BVH_Vec3f::*)()) &BVH_Vec3f::Normalize, "Normalize the vector.");
	cls_BVH_Vec3f.def("Normalized", (BVH_Vec3f (BVH_Vec3f::*)() const ) &BVH_Vec3f::Normalized, "Normalize the vector.");
	cls_BVH_Vec3f.def_static("Cross_", (BVH_Vec3f (*)(const BVH_Vec3f &, const BVH_Vec3f &)) &BVH_Vec3f::Cross, "Computes the cross product.", py::arg("theVec1"), py::arg("theVec2"));
	cls_BVH_Vec3f.def_static("GetLERP_", (BVH_Vec3f (*)(const BVH_Vec3f &, const BVH_Vec3f &, const float)) &BVH_Vec3f::GetLERP, "Compute linear interpolation between to vectors.", py::arg("theFrom"), py::arg("theTo"), py::arg("theT"));
	cls_BVH_Vec3f.def_static("DX_", (BVH_Vec3f (*)()) &BVH_Vec3f::DX, "Constuct DX unit vector.");
	cls_BVH_Vec3f.def_static("DY_", (BVH_Vec3f (*)()) &BVH_Vec3f::DY, "Constuct DY unit vector.");
	cls_BVH_Vec3f.def_static("DZ_", (BVH_Vec3f (*)()) &BVH_Vec3f::DZ, "Constuct DZ unit vector.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Vec4.hxx
	py::class_<BVH_Vec4f, std::unique_ptr<BVH_Vec4f, Deleter<BVH_Vec4f>>> cls_BVH_Vec4f(mod, "BVH_Vec4f", "Generic 4-components vector. To be used as RGBA color vector or XYZW 3D-point with special W-component for operations with projection / model view matrices. Use this class for 3D-points carefully because declared W-component may results in incorrect results if used without matrices.");
	cls_BVH_Vec4f.def(py::init<>());
	cls_BVH_Vec4f.def(py::init<const float>(), py::arg("theValue"));
	cls_BVH_Vec4f.def(py::init<const float, const float, const float, const float>(), py::arg("theX"), py::arg("theY"), py::arg("theZ"), py::arg("theW"));
	cls_BVH_Vec4f.def(py::init<const NCollection_Vec2<float> &>(), py::arg("theVec2"));
	cls_BVH_Vec4f.def(py::init<const NCollection_Vec3<float> &>(), py::arg("theVec3"));
	cls_BVH_Vec4f.def(py::init<const NCollection_Vec3<float> &, const float>(), py::arg("theVec3"), py::arg("theAlpha"));
	cls_BVH_Vec4f.def_static("Length_", (int (*)()) &BVH_Vec4f::Length, "Returns the number of components.");
	cls_BVH_Vec4f.def("SetValues", (void (BVH_Vec4f::*)(const float, const float, const float, const float)) &BVH_Vec4f::SetValues, "Assign new values to the vector.", py::arg("theX"), py::arg("theY"), py::arg("theZ"), py::arg("theW"));
	cls_BVH_Vec4f.def("x", (float (BVH_Vec4f::*)() const ) &BVH_Vec4f::x, "Alias to 1st component as X coordinate in XYZW.");
	cls_BVH_Vec4f.def("r", (float (BVH_Vec4f::*)() const ) &BVH_Vec4f::r, "Alias to 1st component as RED channel in RGBA.");
	cls_BVH_Vec4f.def("y", (float (BVH_Vec4f::*)() const ) &BVH_Vec4f::y, "Alias to 2nd component as Y coordinate in XYZW.");
	cls_BVH_Vec4f.def("g", (float (BVH_Vec4f::*)() const ) &BVH_Vec4f::g, "Alias to 2nd component as GREEN channel in RGBA.");
	cls_BVH_Vec4f.def("z", (float (BVH_Vec4f::*)() const ) &BVH_Vec4f::z, "Alias to 3rd component as Z coordinate in XYZW.");
	cls_BVH_Vec4f.def("b", (float (BVH_Vec4f::*)() const ) &BVH_Vec4f::b, "Alias to 3rd component as BLUE channel in RGBA.");
	cls_BVH_Vec4f.def("w", (float (BVH_Vec4f::*)() const ) &BVH_Vec4f::w, "Alias to 4th component as W coordinate in XYZW.");
	cls_BVH_Vec4f.def("a", (float (BVH_Vec4f::*)() const ) &BVH_Vec4f::a, "Alias to 4th component as ALPHA channel in RGBA.");
	cls_BVH_Vec4f.def("xy", (const NCollection_Vec2<float> (BVH_Vec4f::*)() const ) &BVH_Vec4f::xy, "None");
	cls_BVH_Vec4f.def("yx", (const NCollection_Vec2<float> (BVH_Vec4f::*)() const ) &BVH_Vec4f::yx, "None");
	cls_BVH_Vec4f.def("xz", (const NCollection_Vec2<float> (BVH_Vec4f::*)() const ) &BVH_Vec4f::xz, "None");
	cls_BVH_Vec4f.def("zx", (const NCollection_Vec2<float> (BVH_Vec4f::*)() const ) &BVH_Vec4f::zx, "None");
	cls_BVH_Vec4f.def("xw", (const NCollection_Vec2<float> (BVH_Vec4f::*)() const ) &BVH_Vec4f::xw, "None");
	cls_BVH_Vec4f.def("wx", (const NCollection_Vec2<float> (BVH_Vec4f::*)() const ) &BVH_Vec4f::wx, "None");
	cls_BVH_Vec4f.def("yz", (const NCollection_Vec2<float> (BVH_Vec4f::*)() const ) &BVH_Vec4f::yz, "None");
	cls_BVH_Vec4f.def("zy", (const NCollection_Vec2<float> (BVH_Vec4f::*)() const ) &BVH_Vec4f::zy, "None");
	cls_BVH_Vec4f.def("yw", (const NCollection_Vec2<float> (BVH_Vec4f::*)() const ) &BVH_Vec4f::yw, "None");
	cls_BVH_Vec4f.def("wy", (const NCollection_Vec2<float> (BVH_Vec4f::*)() const ) &BVH_Vec4f::wy, "None");
	cls_BVH_Vec4f.def("zw", (const NCollection_Vec2<float> (BVH_Vec4f::*)() const ) &BVH_Vec4f::zw, "None");
	cls_BVH_Vec4f.def("wz", (const NCollection_Vec2<float> (BVH_Vec4f::*)() const ) &BVH_Vec4f::wz, "None");
	cls_BVH_Vec4f.def("xyz", (const NCollection_Vec3<float> (BVH_Vec4f::*)() const ) &BVH_Vec4f::xyz, "None");
	cls_BVH_Vec4f.def("xzy", (const NCollection_Vec3<float> (BVH_Vec4f::*)() const ) &BVH_Vec4f::xzy, "None");
	cls_BVH_Vec4f.def("yxz", (const NCollection_Vec3<float> (BVH_Vec4f::*)() const ) &BVH_Vec4f::yxz, "None");
	cls_BVH_Vec4f.def("yzx", (const NCollection_Vec3<float> (BVH_Vec4f::*)() const ) &BVH_Vec4f::yzx, "None");
	cls_BVH_Vec4f.def("zyx", (const NCollection_Vec3<float> (BVH_Vec4f::*)() const ) &BVH_Vec4f::zyx, "None");
	cls_BVH_Vec4f.def("zxy", (const NCollection_Vec3<float> (BVH_Vec4f::*)() const ) &BVH_Vec4f::zxy, "None");
	cls_BVH_Vec4f.def("xyw", (const NCollection_Vec3<float> (BVH_Vec4f::*)() const ) &BVH_Vec4f::xyw, "None");
	cls_BVH_Vec4f.def("xwy", (const NCollection_Vec3<float> (BVH_Vec4f::*)() const ) &BVH_Vec4f::xwy, "None");
	cls_BVH_Vec4f.def("yxw", (const NCollection_Vec3<float> (BVH_Vec4f::*)() const ) &BVH_Vec4f::yxw, "None");
	cls_BVH_Vec4f.def("ywx", (const NCollection_Vec3<float> (BVH_Vec4f::*)() const ) &BVH_Vec4f::ywx, "None");
	cls_BVH_Vec4f.def("wyx", (const NCollection_Vec3<float> (BVH_Vec4f::*)() const ) &BVH_Vec4f::wyx, "None");
	cls_BVH_Vec4f.def("wxy", (const NCollection_Vec3<float> (BVH_Vec4f::*)() const ) &BVH_Vec4f::wxy, "None");
	cls_BVH_Vec4f.def("xzw", (const NCollection_Vec3<float> (BVH_Vec4f::*)() const ) &BVH_Vec4f::xzw, "None");
	cls_BVH_Vec4f.def("xwz", (const NCollection_Vec3<float> (BVH_Vec4f::*)() const ) &BVH_Vec4f::xwz, "None");
	cls_BVH_Vec4f.def("zxw", (const NCollection_Vec3<float> (BVH_Vec4f::*)() const ) &BVH_Vec4f::zxw, "None");
	cls_BVH_Vec4f.def("zwx", (const NCollection_Vec3<float> (BVH_Vec4f::*)() const ) &BVH_Vec4f::zwx, "None");
	cls_BVH_Vec4f.def("wzx", (const NCollection_Vec3<float> (BVH_Vec4f::*)() const ) &BVH_Vec4f::wzx, "None");
	cls_BVH_Vec4f.def("wxz", (const NCollection_Vec3<float> (BVH_Vec4f::*)() const ) &BVH_Vec4f::wxz, "None");
	cls_BVH_Vec4f.def("yzw", (const NCollection_Vec3<float> (BVH_Vec4f::*)() const ) &BVH_Vec4f::yzw, "None");
	cls_BVH_Vec4f.def("ywz", (const NCollection_Vec3<float> (BVH_Vec4f::*)() const ) &BVH_Vec4f::ywz, "None");
	cls_BVH_Vec4f.def("zyw", (const NCollection_Vec3<float> (BVH_Vec4f::*)() const ) &BVH_Vec4f::zyw, "None");
	cls_BVH_Vec4f.def("zwy", (const NCollection_Vec3<float> (BVH_Vec4f::*)() const ) &BVH_Vec4f::zwy, "None");
	cls_BVH_Vec4f.def("wzy", (const NCollection_Vec3<float> (BVH_Vec4f::*)() const ) &BVH_Vec4f::wzy, "None");
	cls_BVH_Vec4f.def("wyz", (const NCollection_Vec3<float> (BVH_Vec4f::*)() const ) &BVH_Vec4f::wyz, "None");
	cls_BVH_Vec4f.def("rgb", (const NCollection_Vec3<float> (BVH_Vec4f::*)() const ) &BVH_Vec4f::rgb, "None");
	cls_BVH_Vec4f.def("rbg", (const NCollection_Vec3<float> (BVH_Vec4f::*)() const ) &BVH_Vec4f::rbg, "None");
	cls_BVH_Vec4f.def("grb", (const NCollection_Vec3<float> (BVH_Vec4f::*)() const ) &BVH_Vec4f::grb, "None");
	cls_BVH_Vec4f.def("gbr", (const NCollection_Vec3<float> (BVH_Vec4f::*)() const ) &BVH_Vec4f::gbr, "None");
	cls_BVH_Vec4f.def("bgr", (const NCollection_Vec3<float> (BVH_Vec4f::*)() const ) &BVH_Vec4f::bgr, "None");
	cls_BVH_Vec4f.def("brg", (const NCollection_Vec3<float> (BVH_Vec4f::*)() const ) &BVH_Vec4f::brg, "None");
	cls_BVH_Vec4f.def("x", (float & (BVH_Vec4f::*)()) &BVH_Vec4f::x, "Alias to 1st component as X coordinate in XYZW.");
	cls_BVH_Vec4f.def("r", (float & (BVH_Vec4f::*)()) &BVH_Vec4f::r, "Alias to 1st component as RED channel in RGBA.");
	cls_BVH_Vec4f.def("y", (float & (BVH_Vec4f::*)()) &BVH_Vec4f::y, "Alias to 2nd component as Y coordinate in XYZW.");
	cls_BVH_Vec4f.def("g", (float & (BVH_Vec4f::*)()) &BVH_Vec4f::g, "Alias to 2nd component as GREEN channel in RGBA.");
	cls_BVH_Vec4f.def("z", (float & (BVH_Vec4f::*)()) &BVH_Vec4f::z, "Alias to 3rd component as Z coordinate in XYZW.");
	cls_BVH_Vec4f.def("b", (float & (BVH_Vec4f::*)()) &BVH_Vec4f::b, "Alias to 3rd component as BLUE channel in RGBA.");
	cls_BVH_Vec4f.def("w", (float & (BVH_Vec4f::*)()) &BVH_Vec4f::w, "Alias to 4th component as W coordinate in XYZW.");
	cls_BVH_Vec4f.def("a", (float & (BVH_Vec4f::*)()) &BVH_Vec4f::a, "Alias to 4th component as ALPHA channel in RGBA.");
	cls_BVH_Vec4f.def("xy", (NCollection_Vec2<float> & (BVH_Vec4f::*)()) &BVH_Vec4f::xy, "Returns XY-components modifiable vector");
	cls_BVH_Vec4f.def("yz", (NCollection_Vec2<float> & (BVH_Vec4f::*)()) &BVH_Vec4f::yz, "Returns YZ-components modifiable vector");
	cls_BVH_Vec4f.def("zw", (NCollection_Vec2<float> & (BVH_Vec4f::*)()) &BVH_Vec4f::zw, "Returns YZ-components modifiable vector");
	cls_BVH_Vec4f.def("xyz", (NCollection_Vec3<float> & (BVH_Vec4f::*)()) &BVH_Vec4f::xyz, "Returns XYZ-components modifiable vector");
	cls_BVH_Vec4f.def("yzw", (NCollection_Vec3<float> & (BVH_Vec4f::*)()) &BVH_Vec4f::yzw, "Returns YZW-components modifiable vector");
	cls_BVH_Vec4f.def("IsEqual", (bool (BVH_Vec4f::*)(const BVH_Vec4f &) const ) &BVH_Vec4f::IsEqual, "Check this vector with another vector for equality (without tolerance!).", py::arg("theOther"));
	cls_BVH_Vec4f.def("__eq__", (bool (BVH_Vec4f::*)(const BVH_Vec4f &)) &BVH_Vec4f::operator==, py::is_operator(), "Check this vector with another vector for equality (without tolerance!).", py::arg("theOther"));
	cls_BVH_Vec4f.def("__eq__", (bool (BVH_Vec4f::*)(const BVH_Vec4f &) const ) &BVH_Vec4f::operator==, py::is_operator(), "None", py::arg("theOther"));
	cls_BVH_Vec4f.def("__ne__", (bool (BVH_Vec4f::*)(const BVH_Vec4f &)) &BVH_Vec4f::operator!=, py::is_operator(), "Check this vector with another vector for non-equality (without tolerance!).", py::arg("theOther"));
	cls_BVH_Vec4f.def("__ne__", (bool (BVH_Vec4f::*)(const BVH_Vec4f &) const ) &BVH_Vec4f::operator!=, py::is_operator(), "None", py::arg("theOther"));
	cls_BVH_Vec4f.def("GetData", (const float * (BVH_Vec4f::*)() const ) &BVH_Vec4f::GetData, "Raw access to the data (for OpenGL exchange).");
	cls_BVH_Vec4f.def("ChangeData", (float * (BVH_Vec4f::*)()) &BVH_Vec4f::ChangeData, "None");
	cls_BVH_Vec4f.def("__iadd__", (BVH_Vec4f & (BVH_Vec4f::*)(const BVH_Vec4f &)) &BVH_Vec4f::operator+=, "Compute per-component summary.", py::arg("theAdd"));
	cls_BVH_Vec4f.def("__sub__", (BVH_Vec4f (BVH_Vec4f::*)() const ) &BVH_Vec4f::operator-, py::is_operator(), "Unary -.");
	cls_BVH_Vec4f.def("__isub__", (BVH_Vec4f & (BVH_Vec4f::*)(const BVH_Vec4f &)) &BVH_Vec4f::operator-=, "Compute per-component subtraction.", py::arg("theDec"));
	cls_BVH_Vec4f.def("__imul__", (BVH_Vec4f & (BVH_Vec4f::*)(const BVH_Vec4f &)) &BVH_Vec4f::operator*=, "Compute per-component multiplication.", py::arg("theRight"));
	cls_BVH_Vec4f.def("Multiply", (void (BVH_Vec4f::*)(const float)) &BVH_Vec4f::Multiply, "Compute per-component multiplication.", py::arg("theFactor"));
	cls_BVH_Vec4f.def("__imul__", (BVH_Vec4f & (BVH_Vec4f::*)(const float)) &BVH_Vec4f::operator*=, "Compute per-component multiplication.", py::arg("theFactor"));
	cls_BVH_Vec4f.def("__mul__", (BVH_Vec4f (BVH_Vec4f::*)(const float) const ) &BVH_Vec4f::operator*, py::is_operator(), "Compute per-component multiplication.", py::arg("theFactor"));
	cls_BVH_Vec4f.def("Multiplied", (BVH_Vec4f (BVH_Vec4f::*)(const float) const ) &BVH_Vec4f::Multiplied, "Compute per-component multiplication.", py::arg("theFactor"));
	cls_BVH_Vec4f.def("cwiseMin", (BVH_Vec4f (BVH_Vec4f::*)(const BVH_Vec4f &) const ) &BVH_Vec4f::cwiseMin, "Compute component-wise minimum of two vectors.", py::arg("theVec"));
	cls_BVH_Vec4f.def("cwiseMax", (BVH_Vec4f (BVH_Vec4f::*)(const BVH_Vec4f &) const ) &BVH_Vec4f::cwiseMax, "Compute component-wise maximum of two vectors.", py::arg("theVec"));
	cls_BVH_Vec4f.def("cwiseAbs", (BVH_Vec4f (BVH_Vec4f::*)() const ) &BVH_Vec4f::cwiseAbs, "Compute component-wise modulus of the vector.");
	cls_BVH_Vec4f.def("maxComp", (float (BVH_Vec4f::*)() const ) &BVH_Vec4f::maxComp, "Compute maximum component of the vector.");
	cls_BVH_Vec4f.def("minComp", (float (BVH_Vec4f::*)() const ) &BVH_Vec4f::minComp, "Compute minimum component of the vector.");
	cls_BVH_Vec4f.def("Dot", (float (BVH_Vec4f::*)(const BVH_Vec4f &) const ) &BVH_Vec4f::Dot, "Computes the dot product.", py::arg("theOther"));
	cls_BVH_Vec4f.def("__itruediv__", (BVH_Vec4f & (BVH_Vec4f::*)(const float)) &BVH_Vec4f::operator/=, "Compute per-component division by scale factor.", py::arg("theInvFactor"));
	cls_BVH_Vec4f.def("__truediv__", (BVH_Vec4f (BVH_Vec4f::*)(const float)) &BVH_Vec4f::operator/, py::is_operator(), "Compute per-component division by scale factor.", py::arg("theInvFactor"));

	/* FIXME
	// BVH_Array2f
	*/

	/* FIXME
	// BVH_Array3f
	*/

	/* FIXME
	// BVH_Array4f
	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Vec2.hxx
	py::class_<BVH_Vec2d, std::unique_ptr<BVH_Vec2d, Deleter<BVH_Vec2d>>> cls_BVH_Vec2d(mod, "BVH_Vec2d", "Defines the 2D-vector template. The main target for this class - to handle raw low-level arrays (from/to graphic driver etc.).");
	cls_BVH_Vec2d.def(py::init<>());
	cls_BVH_Vec2d.def(py::init<const double>(), py::arg("theXY"));
	cls_BVH_Vec2d.def(py::init<const double, const double>(), py::arg("theX"), py::arg("theY"));
	cls_BVH_Vec2d.def_static("Length_", (int (*)()) &BVH_Vec2d::Length, "Returns the number of components.");
	cls_BVH_Vec2d.def("SetValues", (void (BVH_Vec2d::*)(const double, const double)) &BVH_Vec2d::SetValues, "Assign new values to the vector.", py::arg("theX"), py::arg("theY"));
	cls_BVH_Vec2d.def("x", (double (BVH_Vec2d::*)() const ) &BVH_Vec2d::x, "Alias to 1st component as X coordinate in XY.");
	cls_BVH_Vec2d.def("y", (double (BVH_Vec2d::*)() const ) &BVH_Vec2d::y, "Alias to 2nd component as Y coordinate in XY.");
	cls_BVH_Vec2d.def("xy", (const BVH_Vec2d (BVH_Vec2d::*)() const ) &BVH_Vec2d::xy, "None");
	cls_BVH_Vec2d.def("yx", (const BVH_Vec2d (BVH_Vec2d::*)() const ) &BVH_Vec2d::yx, "None");
	cls_BVH_Vec2d.def("x", (double & (BVH_Vec2d::*)()) &BVH_Vec2d::x, "Alias to 1st component as X coordinate in XY.");
	cls_BVH_Vec2d.def("y", (double & (BVH_Vec2d::*)()) &BVH_Vec2d::y, "Alias to 2nd component as Y coordinate in XY.");
	cls_BVH_Vec2d.def("IsEqual", (bool (BVH_Vec2d::*)(const BVH_Vec2d &) const ) &BVH_Vec2d::IsEqual, "Check this vector with another vector for equality (without tolerance!).", py::arg("theOther"));
	cls_BVH_Vec2d.def("__eq__", (bool (BVH_Vec2d::*)(const BVH_Vec2d &)) &BVH_Vec2d::operator==, py::is_operator(), "Check this vector with another vector for equality (without tolerance!).", py::arg("theOther"));
	cls_BVH_Vec2d.def("__eq__", (bool (BVH_Vec2d::*)(const BVH_Vec2d &) const ) &BVH_Vec2d::operator==, py::is_operator(), "None", py::arg("theOther"));
	cls_BVH_Vec2d.def("__ne__", (bool (BVH_Vec2d::*)(const BVH_Vec2d &)) &BVH_Vec2d::operator!=, py::is_operator(), "Check this vector with another vector for non-equality (without tolerance!).", py::arg("theOther"));
	cls_BVH_Vec2d.def("__ne__", (bool (BVH_Vec2d::*)(const BVH_Vec2d &) const ) &BVH_Vec2d::operator!=, py::is_operator(), "None", py::arg("theOther"));
	cls_BVH_Vec2d.def("GetData", (const double * (BVH_Vec2d::*)() const ) &BVH_Vec2d::GetData, "Raw access to the data (for OpenGL exchange).");
	cls_BVH_Vec2d.def("ChangeData", (double * (BVH_Vec2d::*)()) &BVH_Vec2d::ChangeData, "None");
	cls_BVH_Vec2d.def("__iadd__", (BVH_Vec2d & (BVH_Vec2d::*)(const BVH_Vec2d &)) &BVH_Vec2d::operator+=, "Compute per-component summary.", py::arg("theAdd"));
	cls_BVH_Vec2d.def("__isub__", (BVH_Vec2d & (BVH_Vec2d::*)(const BVH_Vec2d &)) &BVH_Vec2d::operator-=, "Compute per-component subtraction.", py::arg("theDec"));
	cls_BVH_Vec2d.def("__sub__", (BVH_Vec2d (BVH_Vec2d::*)() const ) &BVH_Vec2d::operator-, py::is_operator(), "Unary -.");
	cls_BVH_Vec2d.def("__imul__", (BVH_Vec2d & (BVH_Vec2d::*)(const BVH_Vec2d &)) &BVH_Vec2d::operator*=, "Compute per-component multiplication.", py::arg("theRight"));
	cls_BVH_Vec2d.def("Multiply", (void (BVH_Vec2d::*)(const double)) &BVH_Vec2d::Multiply, "Compute per-component multiplication by scale factor.", py::arg("theFactor"));
	cls_BVH_Vec2d.def("Multiplied", (BVH_Vec2d (BVH_Vec2d::*)(const double) const ) &BVH_Vec2d::Multiplied, "Compute per-component multiplication by scale factor.", py::arg("theFactor"));
	cls_BVH_Vec2d.def("cwiseMin", (BVH_Vec2d (BVH_Vec2d::*)(const BVH_Vec2d &) const ) &BVH_Vec2d::cwiseMin, "Compute component-wise minimum of two vectors.", py::arg("theVec"));
	cls_BVH_Vec2d.def("cwiseMax", (BVH_Vec2d (BVH_Vec2d::*)(const BVH_Vec2d &) const ) &BVH_Vec2d::cwiseMax, "Compute component-wise maximum of two vectors.", py::arg("theVec"));
	cls_BVH_Vec2d.def("cwiseAbs", (BVH_Vec2d (BVH_Vec2d::*)() const ) &BVH_Vec2d::cwiseAbs, "Compute component-wise modulus of the vector.");
	cls_BVH_Vec2d.def("maxComp", (double (BVH_Vec2d::*)() const ) &BVH_Vec2d::maxComp, "Compute maximum component of the vector.");
	cls_BVH_Vec2d.def("minComp", (double (BVH_Vec2d::*)() const ) &BVH_Vec2d::minComp, "Compute minimum component of the vector.");
	cls_BVH_Vec2d.def("__imul__", (BVH_Vec2d & (BVH_Vec2d::*)(const double)) &BVH_Vec2d::operator*=, "Compute per-component multiplication by scale factor.", py::arg("theFactor"));
	cls_BVH_Vec2d.def("__itruediv__", (BVH_Vec2d & (BVH_Vec2d::*)(const double)) &BVH_Vec2d::operator/=, "Compute per-component division by scale factor.", py::arg("theInvFactor"));
	cls_BVH_Vec2d.def("__mul__", (BVH_Vec2d (BVH_Vec2d::*)(const double) const ) &BVH_Vec2d::operator*, py::is_operator(), "Compute per-component multiplication by scale factor.", py::arg("theFactor"));
	cls_BVH_Vec2d.def("__truediv__", (BVH_Vec2d (BVH_Vec2d::*)(const double) const ) &BVH_Vec2d::operator/, py::is_operator(), "Compute per-component division by scale factor.", py::arg("theInvFactor"));
	cls_BVH_Vec2d.def("Dot", (double (BVH_Vec2d::*)(const BVH_Vec2d &) const ) &BVH_Vec2d::Dot, "Computes the dot product.", py::arg("theOther"));
	cls_BVH_Vec2d.def("Modulus", (double (BVH_Vec2d::*)() const ) &BVH_Vec2d::Modulus, "Computes the vector modulus (magnitude, length).");
	cls_BVH_Vec2d.def("SquareModulus", (double (BVH_Vec2d::*)() const ) &BVH_Vec2d::SquareModulus, "Computes the square of vector modulus (magnitude, length). This method may be used for performance tricks.");
	cls_BVH_Vec2d.def_static("DX_", (BVH_Vec2d (*)()) &BVH_Vec2d::DX, "Constuct DX unit vector.");
	cls_BVH_Vec2d.def_static("DY_", (BVH_Vec2d (*)()) &BVH_Vec2d::DY, "Constuct DY unit vector.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Vec3.hxx
	py::class_<BVH_Vec3d, std::unique_ptr<BVH_Vec3d, Deleter<BVH_Vec3d>>> cls_BVH_Vec3d(mod, "BVH_Vec3d", "Generic 3-components vector. To be used as RGB color pixel or XYZ 3D-point. The main target for this class - to handle raw low-level arrays (from/to graphic driver etc.).");
	cls_BVH_Vec3d.def(py::init<>());
	cls_BVH_Vec3d.def(py::init<double>(), py::arg("theValue"));
	cls_BVH_Vec3d.def(py::init<const double, const double, const double>(), py::arg("theX"), py::arg("theY"), py::arg("theZ"));
	cls_BVH_Vec3d.def(py::init<const NCollection_Vec2<double> &>(), py::arg("theVec2"));
	cls_BVH_Vec3d.def_static("Length_", (int (*)()) &BVH_Vec3d::Length, "Returns the number of components.");
	cls_BVH_Vec3d.def("SetValues", (void (BVH_Vec3d::*)(const double, const double, const double)) &BVH_Vec3d::SetValues, "Assign new values to the vector.", py::arg("theX"), py::arg("theY"), py::arg("theZ"));
	cls_BVH_Vec3d.def("x", (double (BVH_Vec3d::*)() const ) &BVH_Vec3d::x, "Alias to 1st component as X coordinate in XYZ.");
	cls_BVH_Vec3d.def("r", (double (BVH_Vec3d::*)() const ) &BVH_Vec3d::r, "Alias to 1st component as RED channel in RGB.");
	cls_BVH_Vec3d.def("y", (double (BVH_Vec3d::*)() const ) &BVH_Vec3d::y, "Alias to 2nd component as Y coordinate in XYZ.");
	cls_BVH_Vec3d.def("g", (double (BVH_Vec3d::*)() const ) &BVH_Vec3d::g, "Alias to 2nd component as GREEN channel in RGB.");
	cls_BVH_Vec3d.def("z", (double (BVH_Vec3d::*)() const ) &BVH_Vec3d::z, "Alias to 3rd component as Z coordinate in XYZ.");
	cls_BVH_Vec3d.def("b", (double (BVH_Vec3d::*)() const ) &BVH_Vec3d::b, "Alias to 3rd component as BLUE channel in RGB.");
	cls_BVH_Vec3d.def("xy", (const NCollection_Vec2<double> (BVH_Vec3d::*)() const ) &BVH_Vec3d::xy, "None");
	cls_BVH_Vec3d.def("yx", (const NCollection_Vec2<double> (BVH_Vec3d::*)() const ) &BVH_Vec3d::yx, "None");
	cls_BVH_Vec3d.def("xz", (const NCollection_Vec2<double> (BVH_Vec3d::*)() const ) &BVH_Vec3d::xz, "None");
	cls_BVH_Vec3d.def("zx", (const NCollection_Vec2<double> (BVH_Vec3d::*)() const ) &BVH_Vec3d::zx, "None");
	cls_BVH_Vec3d.def("yz", (const NCollection_Vec2<double> (BVH_Vec3d::*)() const ) &BVH_Vec3d::yz, "None");
	cls_BVH_Vec3d.def("zy", (const NCollection_Vec2<double> (BVH_Vec3d::*)() const ) &BVH_Vec3d::zy, "None");
	cls_BVH_Vec3d.def("xyz", (const BVH_Vec3d (BVH_Vec3d::*)() const ) &BVH_Vec3d::xyz, "None");
	cls_BVH_Vec3d.def("xzy", (const BVH_Vec3d (BVH_Vec3d::*)() const ) &BVH_Vec3d::xzy, "None");
	cls_BVH_Vec3d.def("yxz", (const BVH_Vec3d (BVH_Vec3d::*)() const ) &BVH_Vec3d::yxz, "None");
	cls_BVH_Vec3d.def("yzx", (const BVH_Vec3d (BVH_Vec3d::*)() const ) &BVH_Vec3d::yzx, "None");
	cls_BVH_Vec3d.def("zyx", (const BVH_Vec3d (BVH_Vec3d::*)() const ) &BVH_Vec3d::zyx, "None");
	cls_BVH_Vec3d.def("zxy", (const BVH_Vec3d (BVH_Vec3d::*)() const ) &BVH_Vec3d::zxy, "None");
	cls_BVH_Vec3d.def("x", (double & (BVH_Vec3d::*)()) &BVH_Vec3d::x, "Alias to 1st component as X coordinate in XYZ.");
	cls_BVH_Vec3d.def("r", (double & (BVH_Vec3d::*)()) &BVH_Vec3d::r, "Alias to 1st component as RED channel in RGB.");
	cls_BVH_Vec3d.def("y", (double & (BVH_Vec3d::*)()) &BVH_Vec3d::y, "Alias to 2nd component as Y coordinate in XYZ.");
	cls_BVH_Vec3d.def("g", (double & (BVH_Vec3d::*)()) &BVH_Vec3d::g, "Alias to 2nd component as GREEN channel in RGB.");
	cls_BVH_Vec3d.def("z", (double & (BVH_Vec3d::*)()) &BVH_Vec3d::z, "Alias to 3rd component as Z coordinate in XYZ.");
	cls_BVH_Vec3d.def("b", (double & (BVH_Vec3d::*)()) &BVH_Vec3d::b, "Alias to 3rd component as BLUE channel in RGB.");
	cls_BVH_Vec3d.def("xy", (NCollection_Vec2<double> & (BVH_Vec3d::*)()) &BVH_Vec3d::xy, "Returns XY-components modifiable vector");
	cls_BVH_Vec3d.def("yz", (NCollection_Vec2<double> & (BVH_Vec3d::*)()) &BVH_Vec3d::yz, "Returns YZ-components modifiable vector");
	cls_BVH_Vec3d.def("IsEqual", (bool (BVH_Vec3d::*)(const BVH_Vec3d &) const ) &BVH_Vec3d::IsEqual, "Check this vector with another vector for equality (without tolerance!).", py::arg("theOther"));
	cls_BVH_Vec3d.def("__eq__", (bool (BVH_Vec3d::*)(const BVH_Vec3d &)) &BVH_Vec3d::operator==, py::is_operator(), "Check this vector with another vector for equality (without tolerance!).", py::arg("theOther"));
	cls_BVH_Vec3d.def("__eq__", (bool (BVH_Vec3d::*)(const BVH_Vec3d &) const ) &BVH_Vec3d::operator==, py::is_operator(), "None", py::arg("theOther"));
	cls_BVH_Vec3d.def("__ne__", (bool (BVH_Vec3d::*)(const BVH_Vec3d &)) &BVH_Vec3d::operator!=, py::is_operator(), "Check this vector with another vector for non-equality (without tolerance!).", py::arg("theOther"));
	cls_BVH_Vec3d.def("__ne__", (bool (BVH_Vec3d::*)(const BVH_Vec3d &) const ) &BVH_Vec3d::operator!=, py::is_operator(), "None", py::arg("theOther"));
	cls_BVH_Vec3d.def("GetData", (const double * (BVH_Vec3d::*)() const ) &BVH_Vec3d::GetData, "Raw access to the data (for OpenGL exchange).");
	cls_BVH_Vec3d.def("ChangeData", (double * (BVH_Vec3d::*)()) &BVH_Vec3d::ChangeData, "None");
	cls_BVH_Vec3d.def("__iadd__", (BVH_Vec3d & (BVH_Vec3d::*)(const BVH_Vec3d &)) &BVH_Vec3d::operator+=, "Compute per-component summary.", py::arg("theAdd"));
	cls_BVH_Vec3d.def("__sub__", (BVH_Vec3d (BVH_Vec3d::*)() const ) &BVH_Vec3d::operator-, py::is_operator(), "Unary -.");
	cls_BVH_Vec3d.def("__isub__", (BVH_Vec3d & (BVH_Vec3d::*)(const BVH_Vec3d &)) &BVH_Vec3d::operator-=, "Compute per-component subtraction.", py::arg("theDec"));
	cls_BVH_Vec3d.def("Multiply", (void (BVH_Vec3d::*)(const double)) &BVH_Vec3d::Multiply, "Compute per-component multiplication by scale factor.", py::arg("theFactor"));
	cls_BVH_Vec3d.def("__imul__", (BVH_Vec3d & (BVH_Vec3d::*)(const BVH_Vec3d &)) &BVH_Vec3d::operator*=, "Compute per-component multiplication.", py::arg("theRight"));
	cls_BVH_Vec3d.def("__imul__", (BVH_Vec3d & (BVH_Vec3d::*)(const double)) &BVH_Vec3d::operator*=, "Compute per-component multiplication by scale factor.", py::arg("theFactor"));
	cls_BVH_Vec3d.def("__mul__", (BVH_Vec3d (BVH_Vec3d::*)(const double) const ) &BVH_Vec3d::operator*, py::is_operator(), "Compute per-component multiplication by scale factor.", py::arg("theFactor"));
	cls_BVH_Vec3d.def("Multiplied", (BVH_Vec3d (BVH_Vec3d::*)(const double) const ) &BVH_Vec3d::Multiplied, "Compute per-component multiplication by scale factor.", py::arg("theFactor"));
	cls_BVH_Vec3d.def("cwiseMin", (BVH_Vec3d (BVH_Vec3d::*)(const BVH_Vec3d &) const ) &BVH_Vec3d::cwiseMin, "Compute component-wise minimum of two vectors.", py::arg("theVec"));
	cls_BVH_Vec3d.def("cwiseMax", (BVH_Vec3d (BVH_Vec3d::*)(const BVH_Vec3d &) const ) &BVH_Vec3d::cwiseMax, "Compute component-wise maximum of two vectors.", py::arg("theVec"));
	cls_BVH_Vec3d.def("cwiseAbs", (BVH_Vec3d (BVH_Vec3d::*)() const ) &BVH_Vec3d::cwiseAbs, "Compute component-wise modulus of the vector.");
	cls_BVH_Vec3d.def("maxComp", (double (BVH_Vec3d::*)() const ) &BVH_Vec3d::maxComp, "Compute maximum component of the vector.");
	cls_BVH_Vec3d.def("minComp", (double (BVH_Vec3d::*)() const ) &BVH_Vec3d::minComp, "Compute minimum component of the vector.");
	cls_BVH_Vec3d.def("__itruediv__", (BVH_Vec3d & (BVH_Vec3d::*)(const double)) &BVH_Vec3d::operator/=, "Compute per-component division by scale factor.", py::arg("theInvFactor"));
	cls_BVH_Vec3d.def("__truediv__", (BVH_Vec3d (BVH_Vec3d::*)(const double)) &BVH_Vec3d::operator/, py::is_operator(), "Compute per-component division by scale factor.", py::arg("theInvFactor"));
	cls_BVH_Vec3d.def("Dot", (double (BVH_Vec3d::*)(const BVH_Vec3d &) const ) &BVH_Vec3d::Dot, "Computes the dot product.", py::arg("theOther"));
	cls_BVH_Vec3d.def("Modulus", (double (BVH_Vec3d::*)() const ) &BVH_Vec3d::Modulus, "Computes the vector modulus (magnitude, length).");
	cls_BVH_Vec3d.def("SquareModulus", (double (BVH_Vec3d::*)() const ) &BVH_Vec3d::SquareModulus, "Computes the square of vector modulus (magnitude, length). This method may be used for performance tricks.");
	cls_BVH_Vec3d.def("Normalize", (void (BVH_Vec3d::*)()) &BVH_Vec3d::Normalize, "Normalize the vector.");
	cls_BVH_Vec3d.def("Normalized", (BVH_Vec3d (BVH_Vec3d::*)() const ) &BVH_Vec3d::Normalized, "Normalize the vector.");
	cls_BVH_Vec3d.def_static("Cross_", (BVH_Vec3d (*)(const BVH_Vec3d &, const BVH_Vec3d &)) &BVH_Vec3d::Cross, "Computes the cross product.", py::arg("theVec1"), py::arg("theVec2"));
	cls_BVH_Vec3d.def_static("GetLERP_", (BVH_Vec3d (*)(const BVH_Vec3d &, const BVH_Vec3d &, const double)) &BVH_Vec3d::GetLERP, "Compute linear interpolation between to vectors.", py::arg("theFrom"), py::arg("theTo"), py::arg("theT"));
	cls_BVH_Vec3d.def_static("DX_", (BVH_Vec3d (*)()) &BVH_Vec3d::DX, "Constuct DX unit vector.");
	cls_BVH_Vec3d.def_static("DY_", (BVH_Vec3d (*)()) &BVH_Vec3d::DY, "Constuct DY unit vector.");
	cls_BVH_Vec3d.def_static("DZ_", (BVH_Vec3d (*)()) &BVH_Vec3d::DZ, "Constuct DZ unit vector.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Vec4.hxx
	py::class_<BVH_Vec4d, std::unique_ptr<BVH_Vec4d, Deleter<BVH_Vec4d>>> cls_BVH_Vec4d(mod, "BVH_Vec4d", "Generic 4-components vector. To be used as RGBA color vector or XYZW 3D-point with special W-component for operations with projection / model view matrices. Use this class for 3D-points carefully because declared W-component may results in incorrect results if used without matrices.");
	cls_BVH_Vec4d.def(py::init<>());
	cls_BVH_Vec4d.def(py::init<const double>(), py::arg("theValue"));
	cls_BVH_Vec4d.def(py::init<const double, const double, const double, const double>(), py::arg("theX"), py::arg("theY"), py::arg("theZ"), py::arg("theW"));
	cls_BVH_Vec4d.def(py::init<const NCollection_Vec2<double> &>(), py::arg("theVec2"));
	cls_BVH_Vec4d.def(py::init<const NCollection_Vec3<double> &>(), py::arg("theVec3"));
	cls_BVH_Vec4d.def(py::init<const NCollection_Vec3<double> &, const double>(), py::arg("theVec3"), py::arg("theAlpha"));
	cls_BVH_Vec4d.def_static("Length_", (int (*)()) &BVH_Vec4d::Length, "Returns the number of components.");
	cls_BVH_Vec4d.def("SetValues", (void (BVH_Vec4d::*)(const double, const double, const double, const double)) &BVH_Vec4d::SetValues, "Assign new values to the vector.", py::arg("theX"), py::arg("theY"), py::arg("theZ"), py::arg("theW"));
	cls_BVH_Vec4d.def("x", (double (BVH_Vec4d::*)() const ) &BVH_Vec4d::x, "Alias to 1st component as X coordinate in XYZW.");
	cls_BVH_Vec4d.def("r", (double (BVH_Vec4d::*)() const ) &BVH_Vec4d::r, "Alias to 1st component as RED channel in RGBA.");
	cls_BVH_Vec4d.def("y", (double (BVH_Vec4d::*)() const ) &BVH_Vec4d::y, "Alias to 2nd component as Y coordinate in XYZW.");
	cls_BVH_Vec4d.def("g", (double (BVH_Vec4d::*)() const ) &BVH_Vec4d::g, "Alias to 2nd component as GREEN channel in RGBA.");
	cls_BVH_Vec4d.def("z", (double (BVH_Vec4d::*)() const ) &BVH_Vec4d::z, "Alias to 3rd component as Z coordinate in XYZW.");
	cls_BVH_Vec4d.def("b", (double (BVH_Vec4d::*)() const ) &BVH_Vec4d::b, "Alias to 3rd component as BLUE channel in RGBA.");
	cls_BVH_Vec4d.def("w", (double (BVH_Vec4d::*)() const ) &BVH_Vec4d::w, "Alias to 4th component as W coordinate in XYZW.");
	cls_BVH_Vec4d.def("a", (double (BVH_Vec4d::*)() const ) &BVH_Vec4d::a, "Alias to 4th component as ALPHA channel in RGBA.");
	cls_BVH_Vec4d.def("xy", (const NCollection_Vec2<double> (BVH_Vec4d::*)() const ) &BVH_Vec4d::xy, "None");
	cls_BVH_Vec4d.def("yx", (const NCollection_Vec2<double> (BVH_Vec4d::*)() const ) &BVH_Vec4d::yx, "None");
	cls_BVH_Vec4d.def("xz", (const NCollection_Vec2<double> (BVH_Vec4d::*)() const ) &BVH_Vec4d::xz, "None");
	cls_BVH_Vec4d.def("zx", (const NCollection_Vec2<double> (BVH_Vec4d::*)() const ) &BVH_Vec4d::zx, "None");
	cls_BVH_Vec4d.def("xw", (const NCollection_Vec2<double> (BVH_Vec4d::*)() const ) &BVH_Vec4d::xw, "None");
	cls_BVH_Vec4d.def("wx", (const NCollection_Vec2<double> (BVH_Vec4d::*)() const ) &BVH_Vec4d::wx, "None");
	cls_BVH_Vec4d.def("yz", (const NCollection_Vec2<double> (BVH_Vec4d::*)() const ) &BVH_Vec4d::yz, "None");
	cls_BVH_Vec4d.def("zy", (const NCollection_Vec2<double> (BVH_Vec4d::*)() const ) &BVH_Vec4d::zy, "None");
	cls_BVH_Vec4d.def("yw", (const NCollection_Vec2<double> (BVH_Vec4d::*)() const ) &BVH_Vec4d::yw, "None");
	cls_BVH_Vec4d.def("wy", (const NCollection_Vec2<double> (BVH_Vec4d::*)() const ) &BVH_Vec4d::wy, "None");
	cls_BVH_Vec4d.def("zw", (const NCollection_Vec2<double> (BVH_Vec4d::*)() const ) &BVH_Vec4d::zw, "None");
	cls_BVH_Vec4d.def("wz", (const NCollection_Vec2<double> (BVH_Vec4d::*)() const ) &BVH_Vec4d::wz, "None");
	cls_BVH_Vec4d.def("xyz", (const NCollection_Vec3<double> (BVH_Vec4d::*)() const ) &BVH_Vec4d::xyz, "None");
	cls_BVH_Vec4d.def("xzy", (const NCollection_Vec3<double> (BVH_Vec4d::*)() const ) &BVH_Vec4d::xzy, "None");
	cls_BVH_Vec4d.def("yxz", (const NCollection_Vec3<double> (BVH_Vec4d::*)() const ) &BVH_Vec4d::yxz, "None");
	cls_BVH_Vec4d.def("yzx", (const NCollection_Vec3<double> (BVH_Vec4d::*)() const ) &BVH_Vec4d::yzx, "None");
	cls_BVH_Vec4d.def("zyx", (const NCollection_Vec3<double> (BVH_Vec4d::*)() const ) &BVH_Vec4d::zyx, "None");
	cls_BVH_Vec4d.def("zxy", (const NCollection_Vec3<double> (BVH_Vec4d::*)() const ) &BVH_Vec4d::zxy, "None");
	cls_BVH_Vec4d.def("xyw", (const NCollection_Vec3<double> (BVH_Vec4d::*)() const ) &BVH_Vec4d::xyw, "None");
	cls_BVH_Vec4d.def("xwy", (const NCollection_Vec3<double> (BVH_Vec4d::*)() const ) &BVH_Vec4d::xwy, "None");
	cls_BVH_Vec4d.def("yxw", (const NCollection_Vec3<double> (BVH_Vec4d::*)() const ) &BVH_Vec4d::yxw, "None");
	cls_BVH_Vec4d.def("ywx", (const NCollection_Vec3<double> (BVH_Vec4d::*)() const ) &BVH_Vec4d::ywx, "None");
	cls_BVH_Vec4d.def("wyx", (const NCollection_Vec3<double> (BVH_Vec4d::*)() const ) &BVH_Vec4d::wyx, "None");
	cls_BVH_Vec4d.def("wxy", (const NCollection_Vec3<double> (BVH_Vec4d::*)() const ) &BVH_Vec4d::wxy, "None");
	cls_BVH_Vec4d.def("xzw", (const NCollection_Vec3<double> (BVH_Vec4d::*)() const ) &BVH_Vec4d::xzw, "None");
	cls_BVH_Vec4d.def("xwz", (const NCollection_Vec3<double> (BVH_Vec4d::*)() const ) &BVH_Vec4d::xwz, "None");
	cls_BVH_Vec4d.def("zxw", (const NCollection_Vec3<double> (BVH_Vec4d::*)() const ) &BVH_Vec4d::zxw, "None");
	cls_BVH_Vec4d.def("zwx", (const NCollection_Vec3<double> (BVH_Vec4d::*)() const ) &BVH_Vec4d::zwx, "None");
	cls_BVH_Vec4d.def("wzx", (const NCollection_Vec3<double> (BVH_Vec4d::*)() const ) &BVH_Vec4d::wzx, "None");
	cls_BVH_Vec4d.def("wxz", (const NCollection_Vec3<double> (BVH_Vec4d::*)() const ) &BVH_Vec4d::wxz, "None");
	cls_BVH_Vec4d.def("yzw", (const NCollection_Vec3<double> (BVH_Vec4d::*)() const ) &BVH_Vec4d::yzw, "None");
	cls_BVH_Vec4d.def("ywz", (const NCollection_Vec3<double> (BVH_Vec4d::*)() const ) &BVH_Vec4d::ywz, "None");
	cls_BVH_Vec4d.def("zyw", (const NCollection_Vec3<double> (BVH_Vec4d::*)() const ) &BVH_Vec4d::zyw, "None");
	cls_BVH_Vec4d.def("zwy", (const NCollection_Vec3<double> (BVH_Vec4d::*)() const ) &BVH_Vec4d::zwy, "None");
	cls_BVH_Vec4d.def("wzy", (const NCollection_Vec3<double> (BVH_Vec4d::*)() const ) &BVH_Vec4d::wzy, "None");
	cls_BVH_Vec4d.def("wyz", (const NCollection_Vec3<double> (BVH_Vec4d::*)() const ) &BVH_Vec4d::wyz, "None");
	cls_BVH_Vec4d.def("rgb", (const NCollection_Vec3<double> (BVH_Vec4d::*)() const ) &BVH_Vec4d::rgb, "None");
	cls_BVH_Vec4d.def("rbg", (const NCollection_Vec3<double> (BVH_Vec4d::*)() const ) &BVH_Vec4d::rbg, "None");
	cls_BVH_Vec4d.def("grb", (const NCollection_Vec3<double> (BVH_Vec4d::*)() const ) &BVH_Vec4d::grb, "None");
	cls_BVH_Vec4d.def("gbr", (const NCollection_Vec3<double> (BVH_Vec4d::*)() const ) &BVH_Vec4d::gbr, "None");
	cls_BVH_Vec4d.def("bgr", (const NCollection_Vec3<double> (BVH_Vec4d::*)() const ) &BVH_Vec4d::bgr, "None");
	cls_BVH_Vec4d.def("brg", (const NCollection_Vec3<double> (BVH_Vec4d::*)() const ) &BVH_Vec4d::brg, "None");
	cls_BVH_Vec4d.def("x", (double & (BVH_Vec4d::*)()) &BVH_Vec4d::x, "Alias to 1st component as X coordinate in XYZW.");
	cls_BVH_Vec4d.def("r", (double & (BVH_Vec4d::*)()) &BVH_Vec4d::r, "Alias to 1st component as RED channel in RGBA.");
	cls_BVH_Vec4d.def("y", (double & (BVH_Vec4d::*)()) &BVH_Vec4d::y, "Alias to 2nd component as Y coordinate in XYZW.");
	cls_BVH_Vec4d.def("g", (double & (BVH_Vec4d::*)()) &BVH_Vec4d::g, "Alias to 2nd component as GREEN channel in RGBA.");
	cls_BVH_Vec4d.def("z", (double & (BVH_Vec4d::*)()) &BVH_Vec4d::z, "Alias to 3rd component as Z coordinate in XYZW.");
	cls_BVH_Vec4d.def("b", (double & (BVH_Vec4d::*)()) &BVH_Vec4d::b, "Alias to 3rd component as BLUE channel in RGBA.");
	cls_BVH_Vec4d.def("w", (double & (BVH_Vec4d::*)()) &BVH_Vec4d::w, "Alias to 4th component as W coordinate in XYZW.");
	cls_BVH_Vec4d.def("a", (double & (BVH_Vec4d::*)()) &BVH_Vec4d::a, "Alias to 4th component as ALPHA channel in RGBA.");
	cls_BVH_Vec4d.def("xy", (NCollection_Vec2<double> & (BVH_Vec4d::*)()) &BVH_Vec4d::xy, "Returns XY-components modifiable vector");
	cls_BVH_Vec4d.def("yz", (NCollection_Vec2<double> & (BVH_Vec4d::*)()) &BVH_Vec4d::yz, "Returns YZ-components modifiable vector");
	cls_BVH_Vec4d.def("zw", (NCollection_Vec2<double> & (BVH_Vec4d::*)()) &BVH_Vec4d::zw, "Returns YZ-components modifiable vector");
	cls_BVH_Vec4d.def("xyz", (NCollection_Vec3<double> & (BVH_Vec4d::*)()) &BVH_Vec4d::xyz, "Returns XYZ-components modifiable vector");
	cls_BVH_Vec4d.def("yzw", (NCollection_Vec3<double> & (BVH_Vec4d::*)()) &BVH_Vec4d::yzw, "Returns YZW-components modifiable vector");
	cls_BVH_Vec4d.def("IsEqual", (bool (BVH_Vec4d::*)(const BVH_Vec4d &) const ) &BVH_Vec4d::IsEqual, "Check this vector with another vector for equality (without tolerance!).", py::arg("theOther"));
	cls_BVH_Vec4d.def("__eq__", (bool (BVH_Vec4d::*)(const BVH_Vec4d &)) &BVH_Vec4d::operator==, py::is_operator(), "Check this vector with another vector for equality (without tolerance!).", py::arg("theOther"));
	cls_BVH_Vec4d.def("__eq__", (bool (BVH_Vec4d::*)(const BVH_Vec4d &) const ) &BVH_Vec4d::operator==, py::is_operator(), "None", py::arg("theOther"));
	cls_BVH_Vec4d.def("__ne__", (bool (BVH_Vec4d::*)(const BVH_Vec4d &)) &BVH_Vec4d::operator!=, py::is_operator(), "Check this vector with another vector for non-equality (without tolerance!).", py::arg("theOther"));
	cls_BVH_Vec4d.def("__ne__", (bool (BVH_Vec4d::*)(const BVH_Vec4d &) const ) &BVH_Vec4d::operator!=, py::is_operator(), "None", py::arg("theOther"));
	cls_BVH_Vec4d.def("GetData", (const double * (BVH_Vec4d::*)() const ) &BVH_Vec4d::GetData, "Raw access to the data (for OpenGL exchange).");
	cls_BVH_Vec4d.def("ChangeData", (double * (BVH_Vec4d::*)()) &BVH_Vec4d::ChangeData, "None");
	cls_BVH_Vec4d.def("__iadd__", (BVH_Vec4d & (BVH_Vec4d::*)(const BVH_Vec4d &)) &BVH_Vec4d::operator+=, "Compute per-component summary.", py::arg("theAdd"));
	cls_BVH_Vec4d.def("__sub__", (BVH_Vec4d (BVH_Vec4d::*)() const ) &BVH_Vec4d::operator-, py::is_operator(), "Unary -.");
	cls_BVH_Vec4d.def("__isub__", (BVH_Vec4d & (BVH_Vec4d::*)(const BVH_Vec4d &)) &BVH_Vec4d::operator-=, "Compute per-component subtraction.", py::arg("theDec"));
	cls_BVH_Vec4d.def("__imul__", (BVH_Vec4d & (BVH_Vec4d::*)(const BVH_Vec4d &)) &BVH_Vec4d::operator*=, "Compute per-component multiplication.", py::arg("theRight"));
	cls_BVH_Vec4d.def("Multiply", (void (BVH_Vec4d::*)(const double)) &BVH_Vec4d::Multiply, "Compute per-component multiplication.", py::arg("theFactor"));
	cls_BVH_Vec4d.def("__imul__", (BVH_Vec4d & (BVH_Vec4d::*)(const double)) &BVH_Vec4d::operator*=, "Compute per-component multiplication.", py::arg("theFactor"));
	cls_BVH_Vec4d.def("__mul__", (BVH_Vec4d (BVH_Vec4d::*)(const double) const ) &BVH_Vec4d::operator*, py::is_operator(), "Compute per-component multiplication.", py::arg("theFactor"));
	cls_BVH_Vec4d.def("Multiplied", (BVH_Vec4d (BVH_Vec4d::*)(const double) const ) &BVH_Vec4d::Multiplied, "Compute per-component multiplication.", py::arg("theFactor"));
	cls_BVH_Vec4d.def("cwiseMin", (BVH_Vec4d (BVH_Vec4d::*)(const BVH_Vec4d &) const ) &BVH_Vec4d::cwiseMin, "Compute component-wise minimum of two vectors.", py::arg("theVec"));
	cls_BVH_Vec4d.def("cwiseMax", (BVH_Vec4d (BVH_Vec4d::*)(const BVH_Vec4d &) const ) &BVH_Vec4d::cwiseMax, "Compute component-wise maximum of two vectors.", py::arg("theVec"));
	cls_BVH_Vec4d.def("cwiseAbs", (BVH_Vec4d (BVH_Vec4d::*)() const ) &BVH_Vec4d::cwiseAbs, "Compute component-wise modulus of the vector.");
	cls_BVH_Vec4d.def("maxComp", (double (BVH_Vec4d::*)() const ) &BVH_Vec4d::maxComp, "Compute maximum component of the vector.");
	cls_BVH_Vec4d.def("minComp", (double (BVH_Vec4d::*)() const ) &BVH_Vec4d::minComp, "Compute minimum component of the vector.");
	cls_BVH_Vec4d.def("Dot", (double (BVH_Vec4d::*)(const BVH_Vec4d &) const ) &BVH_Vec4d::Dot, "Computes the dot product.", py::arg("theOther"));
	cls_BVH_Vec4d.def("__itruediv__", (BVH_Vec4d & (BVH_Vec4d::*)(const double)) &BVH_Vec4d::operator/=, "Compute per-component division by scale factor.", py::arg("theInvFactor"));
	cls_BVH_Vec4d.def("__truediv__", (BVH_Vec4d (BVH_Vec4d::*)(const double)) &BVH_Vec4d::operator/, py::is_operator(), "Compute per-component division by scale factor.", py::arg("theInvFactor"));

	/* FIXME
	// BVH_Array2d
	*/

	/* FIXME
	// BVH_Array3d
	*/

	/* FIXME
	// BVH_Array4d
	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Mat4.hxx
	py::class_<BVH_Mat4f, std::unique_ptr<BVH_Mat4f, Deleter<BVH_Mat4f>>> cls_BVH_Mat4f(mod, "BVH_Mat4f", "Generic matrix of 4 x 4 elements. To be used in conjunction with NCollection_Vec4 entities. Originally introduced for 3D space projection and orientation operations.");
	cls_BVH_Mat4f.def(py::init<>());
	cls_BVH_Mat4f.def_static("Rows_", (size_t (*)()) &BVH_Mat4f::Rows, "Get number of rows.");
	cls_BVH_Mat4f.def_static("Cols_", (size_t (*)()) &BVH_Mat4f::Cols, "Get number of columns.");
	cls_BVH_Mat4f.def("GetValue", (float (BVH_Mat4f::*)(const size_t, const size_t) const ) &BVH_Mat4f::GetValue, "Get element at the specified row and column.", py::arg("theRow"), py::arg("theCol"));
	cls_BVH_Mat4f.def("ChangeValue", (float & (BVH_Mat4f::*)(const size_t, const size_t)) &BVH_Mat4f::ChangeValue, "Access element at the specified row and column.", py::arg("theRow"), py::arg("theCol"));
	cls_BVH_Mat4f.def("SetValue", (void (BVH_Mat4f::*)(const size_t, const size_t, const float)) &BVH_Mat4f::SetValue, "Set value for the element specified by row and columns.", py::arg("theRow"), py::arg("theCol"), py::arg("theValue"));
	cls_BVH_Mat4f.def("GetRow", (NCollection_Vec4<float> (BVH_Mat4f::*)(const size_t) const ) &BVH_Mat4f::GetRow, "Get vector of elements for the specified row.", py::arg("theRow"));
	cls_BVH_Mat4f.def("SetRow", (void (BVH_Mat4f::*)(const size_t, const NCollection_Vec3<float> &)) &BVH_Mat4f::SetRow, "Change first 3 row values by the passed vector.", py::arg("theRow"), py::arg("theVec"));
	cls_BVH_Mat4f.def("SetRow", (void (BVH_Mat4f::*)(const size_t, const NCollection_Vec4<float> &)) &BVH_Mat4f::SetRow, "Set row values by the passed 4 element vector.", py::arg("theRow"), py::arg("theVec"));
	cls_BVH_Mat4f.def("GetColumn", (NCollection_Vec4<float> (BVH_Mat4f::*)(const size_t) const ) &BVH_Mat4f::GetColumn, "Get vector of elements for the specified column.", py::arg("theCol"));
	cls_BVH_Mat4f.def("SetColumn", (void (BVH_Mat4f::*)(const size_t, const NCollection_Vec3<float> &)) &BVH_Mat4f::SetColumn, "Change first 3 column values by the passed vector.", py::arg("theCol"), py::arg("theVec"));
	cls_BVH_Mat4f.def("SetColumn", (void (BVH_Mat4f::*)(const size_t, const NCollection_Vec4<float> &)) &BVH_Mat4f::SetColumn, "Set column values by the passed 4 element vector.", py::arg("theCol"), py::arg("theVec"));
	cls_BVH_Mat4f.def("GetDiagonal", (NCollection_Vec4<float> (BVH_Mat4f::*)() const ) &BVH_Mat4f::GetDiagonal, "Get vector of diagonal elements.");
	cls_BVH_Mat4f.def("SetDiagonal", (void (BVH_Mat4f::*)(const NCollection_Vec3<float> &)) &BVH_Mat4f::SetDiagonal, "Change first 3 elements of the diagonal matrix.", py::arg("theVec"));
	cls_BVH_Mat4f.def("SetDiagonal", (void (BVH_Mat4f::*)(const NCollection_Vec4<float> &)) &BVH_Mat4f::SetDiagonal, "Set diagonal elements of the matrix by the passed vector.", py::arg("theVec"));
	cls_BVH_Mat4f.def("InitIdentity", (void (BVH_Mat4f::*)()) &BVH_Mat4f::InitIdentity, "Initialize the identity matrix.");
	cls_BVH_Mat4f.def("IsIdentity", (bool (BVH_Mat4f::*)() const ) &BVH_Mat4f::IsIdentity, "Checks the matrix for identity.");
	cls_BVH_Mat4f.def("IsEqual", (bool (BVH_Mat4f::*)(const BVH_Mat4f &) const ) &BVH_Mat4f::IsEqual, "Check this matrix for equality with another matrix (without tolerance!).", py::arg("theOther"));
	cls_BVH_Mat4f.def("__eq__", (bool (BVH_Mat4f::*)(const BVH_Mat4f &)) &BVH_Mat4f::operator==, py::is_operator(), "Check this matrix for equality with another matrix (without tolerance!).", py::arg("theOther"));
	cls_BVH_Mat4f.def("__eq__", (bool (BVH_Mat4f::*)(const BVH_Mat4f &) const ) &BVH_Mat4f::operator==, py::is_operator(), "None", py::arg("theOther"));
	cls_BVH_Mat4f.def("__ne__", (bool (BVH_Mat4f::*)(const BVH_Mat4f &)) &BVH_Mat4f::operator!=, py::is_operator(), "Check this matrix for non-equality with another matrix (without tolerance!).", py::arg("theOther"));
	cls_BVH_Mat4f.def("__ne__", (bool (BVH_Mat4f::*)(const BVH_Mat4f &) const ) &BVH_Mat4f::operator!=, py::is_operator(), "None", py::arg("theOther"));
	cls_BVH_Mat4f.def("GetData", (const float * (BVH_Mat4f::*)() const ) &BVH_Mat4f::GetData, "Raw access to the data (for OpenGL exchange).");
	cls_BVH_Mat4f.def("ChangeData", (float * (BVH_Mat4f::*)()) &BVH_Mat4f::ChangeData, "None");
	cls_BVH_Mat4f.def("__mul__", (NCollection_Vec4<float> (BVH_Mat4f::*)(const NCollection_Vec4<float> &) const ) &BVH_Mat4f::operator*, py::is_operator(), "Multiply by the vector (M * V).", py::arg("theVec"));
	cls_BVH_Mat4f.def("Multiply", (BVH_Mat4f (BVH_Mat4f::*)(const BVH_Mat4f &, const BVH_Mat4f &)) &BVH_Mat4f::Multiply, "Compute matrix multiplication product: A * B.", py::arg("theMatA"), py::arg("theMatB"));
	cls_BVH_Mat4f.def("Multiply", (void (BVH_Mat4f::*)(const BVH_Mat4f &)) &BVH_Mat4f::Multiply, "Compute matrix multiplication.", py::arg("theMat"));
	cls_BVH_Mat4f.def("__imul__", (BVH_Mat4f & (BVH_Mat4f::*)(const BVH_Mat4f &)) &BVH_Mat4f::operator*=, "Multiply by the another matrix.", py::arg("theMat"));
	cls_BVH_Mat4f.def("__mul__", (BVH_Mat4f (BVH_Mat4f::*)(const BVH_Mat4f &) const ) &BVH_Mat4f::operator*, py::is_operator(), "Compute matrix multiplication product.", py::arg("theMat"));
	cls_BVH_Mat4f.def("Multiplied", (BVH_Mat4f (BVH_Mat4f::*)(const BVH_Mat4f &) const ) &BVH_Mat4f::Multiplied, "Compute matrix multiplication product.", py::arg("theMat"));
	cls_BVH_Mat4f.def("Multiply", (void (BVH_Mat4f::*)(const float)) &BVH_Mat4f::Multiply, "Compute per-component multiplication.", py::arg("theFactor"));
	cls_BVH_Mat4f.def("__imul__", (BVH_Mat4f & (BVH_Mat4f::*)(const float)) &BVH_Mat4f::operator*=, "Compute per-element multiplication.", py::arg("theFactor"));
	cls_BVH_Mat4f.def("__mul__", (BVH_Mat4f (BVH_Mat4f::*)(const float) const ) &BVH_Mat4f::operator*, py::is_operator(), "Compute per-element multiplication.", py::arg("theFactor"));
	cls_BVH_Mat4f.def("Multiplied", (BVH_Mat4f (BVH_Mat4f::*)(const float) const ) &BVH_Mat4f::Multiplied, "Compute per-element multiplication.", py::arg("theFactor"));
	cls_BVH_Mat4f.def("Translate", (void (BVH_Mat4f::*)(const NCollection_Vec3<float> &)) &BVH_Mat4f::Translate, "Translate the matrix on the passed vector.", py::arg("theVec"));
	cls_BVH_Mat4f.def("Transposed", (BVH_Mat4f (BVH_Mat4f::*)() const ) &BVH_Mat4f::Transposed, "Transpose the matrix.");
	cls_BVH_Mat4f.def("Transpose", (void (BVH_Mat4f::*)()) &BVH_Mat4f::Transpose, "Transpose the matrix.");
	cls_BVH_Mat4f.def("Inverted", (bool (BVH_Mat4f::*)(BVH_Mat4f &) const ) &BVH_Mat4f::Inverted, "Compute inverted matrix.", py::arg("theOutMx"));
	cls_BVH_Mat4f.def_static("Map_", (BVH_Mat4f & (*)(float *)) &BVH_Mat4f::Map, "Maps plain C array to matrix type.", py::arg("theData"));
	cls_BVH_Mat4f.def_static("Map_", (const BVH_Mat4f & (*)(const float *)) &BVH_Mat4f::Map, "Maps plain C array to matrix type.", py::arg("theData"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_Mat4.hxx
	py::class_<BVH_Mat4d, std::unique_ptr<BVH_Mat4d, Deleter<BVH_Mat4d>>> cls_BVH_Mat4d(mod, "BVH_Mat4d", "Generic matrix of 4 x 4 elements. To be used in conjunction with NCollection_Vec4 entities. Originally introduced for 3D space projection and orientation operations.");
	cls_BVH_Mat4d.def(py::init<>());
	cls_BVH_Mat4d.def_static("Rows_", (size_t (*)()) &BVH_Mat4d::Rows, "Get number of rows.");
	cls_BVH_Mat4d.def_static("Cols_", (size_t (*)()) &BVH_Mat4d::Cols, "Get number of columns.");
	cls_BVH_Mat4d.def("GetValue", (double (BVH_Mat4d::*)(const size_t, const size_t) const ) &BVH_Mat4d::GetValue, "Get element at the specified row and column.", py::arg("theRow"), py::arg("theCol"));
	cls_BVH_Mat4d.def("ChangeValue", (double & (BVH_Mat4d::*)(const size_t, const size_t)) &BVH_Mat4d::ChangeValue, "Access element at the specified row and column.", py::arg("theRow"), py::arg("theCol"));
	cls_BVH_Mat4d.def("SetValue", (void (BVH_Mat4d::*)(const size_t, const size_t, const double)) &BVH_Mat4d::SetValue, "Set value for the element specified by row and columns.", py::arg("theRow"), py::arg("theCol"), py::arg("theValue"));
	cls_BVH_Mat4d.def("GetRow", (NCollection_Vec4<double> (BVH_Mat4d::*)(const size_t) const ) &BVH_Mat4d::GetRow, "Get vector of elements for the specified row.", py::arg("theRow"));
	cls_BVH_Mat4d.def("SetRow", (void (BVH_Mat4d::*)(const size_t, const NCollection_Vec3<double> &)) &BVH_Mat4d::SetRow, "Change first 3 row values by the passed vector.", py::arg("theRow"), py::arg("theVec"));
	cls_BVH_Mat4d.def("SetRow", (void (BVH_Mat4d::*)(const size_t, const NCollection_Vec4<double> &)) &BVH_Mat4d::SetRow, "Set row values by the passed 4 element vector.", py::arg("theRow"), py::arg("theVec"));
	cls_BVH_Mat4d.def("GetColumn", (NCollection_Vec4<double> (BVH_Mat4d::*)(const size_t) const ) &BVH_Mat4d::GetColumn, "Get vector of elements for the specified column.", py::arg("theCol"));
	cls_BVH_Mat4d.def("SetColumn", (void (BVH_Mat4d::*)(const size_t, const NCollection_Vec3<double> &)) &BVH_Mat4d::SetColumn, "Change first 3 column values by the passed vector.", py::arg("theCol"), py::arg("theVec"));
	cls_BVH_Mat4d.def("SetColumn", (void (BVH_Mat4d::*)(const size_t, const NCollection_Vec4<double> &)) &BVH_Mat4d::SetColumn, "Set column values by the passed 4 element vector.", py::arg("theCol"), py::arg("theVec"));
	cls_BVH_Mat4d.def("GetDiagonal", (NCollection_Vec4<double> (BVH_Mat4d::*)() const ) &BVH_Mat4d::GetDiagonal, "Get vector of diagonal elements.");
	cls_BVH_Mat4d.def("SetDiagonal", (void (BVH_Mat4d::*)(const NCollection_Vec3<double> &)) &BVH_Mat4d::SetDiagonal, "Change first 3 elements of the diagonal matrix.", py::arg("theVec"));
	cls_BVH_Mat4d.def("SetDiagonal", (void (BVH_Mat4d::*)(const NCollection_Vec4<double> &)) &BVH_Mat4d::SetDiagonal, "Set diagonal elements of the matrix by the passed vector.", py::arg("theVec"));
	cls_BVH_Mat4d.def("InitIdentity", (void (BVH_Mat4d::*)()) &BVH_Mat4d::InitIdentity, "Initialize the identity matrix.");
	cls_BVH_Mat4d.def("IsIdentity", (bool (BVH_Mat4d::*)() const ) &BVH_Mat4d::IsIdentity, "Checks the matrix for identity.");
	cls_BVH_Mat4d.def("IsEqual", (bool (BVH_Mat4d::*)(const BVH_Mat4d &) const ) &BVH_Mat4d::IsEqual, "Check this matrix for equality with another matrix (without tolerance!).", py::arg("theOther"));
	cls_BVH_Mat4d.def("__eq__", (bool (BVH_Mat4d::*)(const BVH_Mat4d &)) &BVH_Mat4d::operator==, py::is_operator(), "Check this matrix for equality with another matrix (without tolerance!).", py::arg("theOther"));
	cls_BVH_Mat4d.def("__eq__", (bool (BVH_Mat4d::*)(const BVH_Mat4d &) const ) &BVH_Mat4d::operator==, py::is_operator(), "None", py::arg("theOther"));
	cls_BVH_Mat4d.def("__ne__", (bool (BVH_Mat4d::*)(const BVH_Mat4d &)) &BVH_Mat4d::operator!=, py::is_operator(), "Check this matrix for non-equality with another matrix (without tolerance!).", py::arg("theOther"));
	cls_BVH_Mat4d.def("__ne__", (bool (BVH_Mat4d::*)(const BVH_Mat4d &) const ) &BVH_Mat4d::operator!=, py::is_operator(), "None", py::arg("theOther"));
	cls_BVH_Mat4d.def("GetData", (const double * (BVH_Mat4d::*)() const ) &BVH_Mat4d::GetData, "Raw access to the data (for OpenGL exchange).");
	cls_BVH_Mat4d.def("ChangeData", (double * (BVH_Mat4d::*)()) &BVH_Mat4d::ChangeData, "None");
	cls_BVH_Mat4d.def("__mul__", (NCollection_Vec4<double> (BVH_Mat4d::*)(const NCollection_Vec4<double> &) const ) &BVH_Mat4d::operator*, py::is_operator(), "Multiply by the vector (M * V).", py::arg("theVec"));
	cls_BVH_Mat4d.def("Multiply", (BVH_Mat4d (BVH_Mat4d::*)(const BVH_Mat4d &, const BVH_Mat4d &)) &BVH_Mat4d::Multiply, "Compute matrix multiplication product: A * B.", py::arg("theMatA"), py::arg("theMatB"));
	cls_BVH_Mat4d.def("Multiply", (void (BVH_Mat4d::*)(const BVH_Mat4d &)) &BVH_Mat4d::Multiply, "Compute matrix multiplication.", py::arg("theMat"));
	cls_BVH_Mat4d.def("__imul__", (BVH_Mat4d & (BVH_Mat4d::*)(const BVH_Mat4d &)) &BVH_Mat4d::operator*=, "Multiply by the another matrix.", py::arg("theMat"));
	cls_BVH_Mat4d.def("__mul__", (BVH_Mat4d (BVH_Mat4d::*)(const BVH_Mat4d &) const ) &BVH_Mat4d::operator*, py::is_operator(), "Compute matrix multiplication product.", py::arg("theMat"));
	cls_BVH_Mat4d.def("Multiplied", (BVH_Mat4d (BVH_Mat4d::*)(const BVH_Mat4d &) const ) &BVH_Mat4d::Multiplied, "Compute matrix multiplication product.", py::arg("theMat"));
	cls_BVH_Mat4d.def("Multiply", (void (BVH_Mat4d::*)(const double)) &BVH_Mat4d::Multiply, "Compute per-component multiplication.", py::arg("theFactor"));
	cls_BVH_Mat4d.def("__imul__", (BVH_Mat4d & (BVH_Mat4d::*)(const double)) &BVH_Mat4d::operator*=, "Compute per-element multiplication.", py::arg("theFactor"));
	cls_BVH_Mat4d.def("__mul__", (BVH_Mat4d (BVH_Mat4d::*)(const double) const ) &BVH_Mat4d::operator*, py::is_operator(), "Compute per-element multiplication.", py::arg("theFactor"));
	cls_BVH_Mat4d.def("Multiplied", (BVH_Mat4d (BVH_Mat4d::*)(const double) const ) &BVH_Mat4d::Multiplied, "Compute per-element multiplication.", py::arg("theFactor"));
	cls_BVH_Mat4d.def("Translate", (void (BVH_Mat4d::*)(const NCollection_Vec3<double> &)) &BVH_Mat4d::Translate, "Translate the matrix on the passed vector.", py::arg("theVec"));
	cls_BVH_Mat4d.def("Transposed", (BVH_Mat4d (BVH_Mat4d::*)() const ) &BVH_Mat4d::Transposed, "Transpose the matrix.");
	cls_BVH_Mat4d.def("Transpose", (void (BVH_Mat4d::*)()) &BVH_Mat4d::Transpose, "Transpose the matrix.");
	cls_BVH_Mat4d.def("Inverted", (bool (BVH_Mat4d::*)(BVH_Mat4d &) const ) &BVH_Mat4d::Inverted, "Compute inverted matrix.", py::arg("theOutMx"));
	cls_BVH_Mat4d.def_static("Map_", (BVH_Mat4d & (*)(double *)) &BVH_Mat4d::Map, "Maps plain C array to matrix type.", py::arg("theData"));
	cls_BVH_Mat4d.def_static("Map_", (const BVH_Mat4d & (*)(const double *)) &BVH_Mat4d::Map, "Maps plain C array to matrix type.", py::arg("theData"));

	/* FIXME
	// BVH_PrimitiveSet3d
	*/

	/* FIXME
	// C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\include\utility
	py::class_<BVH_EncodedLink, std::unique_ptr<BVH_EncodedLink, Deleter<BVH_EncodedLink>>> cls_BVH_EncodedLink(mod, "BVH_EncodedLink", "None");
	cls_BVH_EncodedLink.def(py::init([] (const pair<Standard_Integer, Standard_Integer> &other) {return new BVH_EncodedLink(other);}), "Copy constructor", py::arg("other"));
	// FIXME cls_BVH_EncodedLink.def(py::init<pair<Standard_Integer, Standard_Integer> &&>(), py::arg(""));
	// FIXME cls_BVH_EncodedLink.def("assign", (std::BVH_EncodedLink::_Myt & (BVH_EncodedLink::*)(std::BVH_EncodedLink::_Myt &&)) &BVH_EncodedLink::operator=, py::is_operator(), "None", py::arg("_Right"));
	cls_BVH_EncodedLink.def("assign", (std::BVH_EncodedLink::_Myt & (BVH_EncodedLink::*)(const std::BVH_EncodedLink::_Myt &)) &BVH_EncodedLink::operator=, py::is_operator(), "None", py::arg("_Right"));
	cls_BVH_EncodedLink.def("swap", (void (BVH_EncodedLink::*)(std::BVH_EncodedLink::_Myt &)) &BVH_EncodedLink::swap, "None", py::arg("_Right"));

	*/


}
