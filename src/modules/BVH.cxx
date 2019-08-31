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
#include <BVH_Types.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <BVH_Tree.hxx>
#include <Standard_Type.hxx>
#include <BVH_Builder.hxx>
#include <BVH_Properties.hxx>
#include <BVH_Object.hxx>
#include <NCollection_Sequence.hxx>
#include <Standard_Mutex.hxx>
#include <BVH_BuildQueue.hxx>
#include <BVH_BuildThread.hxx>
#include <OSD_Thread.hxx>
#include <BVH_PrimitiveSet.hxx>
#include <BVH_PrimitiveSet3d.hxx>
#include <BVH_RadixSorter.hxx>
#include <bind_NCollection_Vec2.hxx>
#include <bind_NCollection_Vec3.hxx>
#include <bind_NCollection_Vec4.hxx>
#include <bind_NCollection_Mat4.hxx>
#include <bind_BVH_PrimitiveSet.hxx>

PYBIND11_MAKE_OPAQUE(std::vector<NCollection_Vec2<int>, std::allocator<NCollection_Vec2<int> > >)
PYBIND11_MAKE_OPAQUE(std::vector<NCollection_Vec3<int>, std::allocator<NCollection_Vec3<int> > >)
PYBIND11_MAKE_OPAQUE(std::vector<NCollection_Vec4<int>, std::allocator<NCollection_Vec4<int> > >)
PYBIND11_MAKE_OPAQUE(std::vector<NCollection_Vec2<float>, std::allocator<NCollection_Vec2<float> > >)
PYBIND11_MAKE_OPAQUE(std::vector<NCollection_Vec3<float>, std::allocator<NCollection_Vec3<float> > >)
PYBIND11_MAKE_OPAQUE(std::vector<NCollection_Vec4<float>, std::allocator<NCollection_Vec4<float> > >)
PYBIND11_MAKE_OPAQUE(std::vector<NCollection_Vec2<double>, std::allocator<NCollection_Vec2<double> > >)
PYBIND11_MAKE_OPAQUE(std::vector<NCollection_Vec3<double>, std::allocator<NCollection_Vec3<double> > >)
PYBIND11_MAKE_OPAQUE(std::vector<NCollection_Vec4<double>, std::allocator<NCollection_Vec4<double> > >)

PYBIND11_MODULE(BVH, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.OSD");

// TYPEDEF: BVH_VEC2I
bind_NCollection_Vec2<int>(mod, "BVH_Vec2i", py::module_local());

// TYPEDEF: BVH_VEC3I
bind_NCollection_Vec3<int>(mod, "BVH_Vec3i", py::module_local());

// TYPEDEF: BVH_VEC4I
bind_NCollection_Vec4<int>(mod, "BVH_Vec4i", py::module_local());

// TYPEDEF: BVH_ARRAY2I
py::bind_vector<std::vector<NCollection_Vec2<int>, std::allocator<NCollection_Vec2<int> > >>(mod, "BVH_Array2i");

// TYPEDEF: BVH_ARRAY3I
py::bind_vector<std::vector<NCollection_Vec3<int>, std::allocator<NCollection_Vec3<int> > >>(mod, "BVH_Array3i");

// TYPEDEF: BVH_ARRAY4I
py::bind_vector<std::vector<NCollection_Vec4<int>, std::allocator<NCollection_Vec4<int> > >>(mod, "BVH_Array4i");

// TYPEDEF: BVH_VEC2F
bind_NCollection_Vec2<float>(mod, "BVH_Vec2f", py::module_local());

// TYPEDEF: BVH_VEC3F
bind_NCollection_Vec3<float>(mod, "BVH_Vec3f", py::module_local());

// TYPEDEF: BVH_VEC4F
bind_NCollection_Vec4<float>(mod, "BVH_Vec4f", py::module_local());

// TYPEDEF: BVH_ARRAY2F
py::bind_vector<std::vector<NCollection_Vec2<float>, std::allocator<NCollection_Vec2<float> > >>(mod, "BVH_Array2f");

// TYPEDEF: BVH_ARRAY3F
py::bind_vector<std::vector<NCollection_Vec3<float>, std::allocator<NCollection_Vec3<float> > >>(mod, "BVH_Array3f");

// TYPEDEF: BVH_ARRAY4F
py::bind_vector<std::vector<NCollection_Vec4<float>, std::allocator<NCollection_Vec4<float> > >>(mod, "BVH_Array4f");

// TYPEDEF: BVH_VEC2D
bind_NCollection_Vec2<double>(mod, "BVH_Vec2d", py::module_local());

// TYPEDEF: BVH_VEC3D
bind_NCollection_Vec3<double>(mod, "BVH_Vec3d", py::module_local());

// TYPEDEF: BVH_VEC4D
bind_NCollection_Vec4<double>(mod, "BVH_Vec4d", py::module_local());

// TYPEDEF: BVH_ARRAY2D
py::bind_vector<std::vector<NCollection_Vec2<double>, std::allocator<NCollection_Vec2<double> > >>(mod, "BVH_Array2d");

// TYPEDEF: BVH_ARRAY3D
py::bind_vector<std::vector<NCollection_Vec3<double>, std::allocator<NCollection_Vec3<double> > >>(mod, "BVH_Array3d");

// TYPEDEF: BVH_ARRAY4D
py::bind_vector<std::vector<NCollection_Vec4<double>, std::allocator<NCollection_Vec4<double> > >>(mod, "BVH_Array4d");

// TYPEDEF: BVH_MAT4F
bind_NCollection_Mat4<float>(mod, "BVH_Mat4f", py::module_local());

// TYPEDEF: BVH_MAT4D
bind_NCollection_Mat4<double>(mod, "BVH_Mat4d", py::module_local());

// CLASS: BVH_TREEBASETRANSIENT
py::class_<BVH_TreeBaseTransient, opencascade::handle<BVH_TreeBaseTransient>, Standard_Transient> cls_BVH_TreeBaseTransient(mod, "BVH_TreeBaseTransient", "A non-template class for using as base for BVH_TreeBase (just to have a named base class).");

// Methods
cls_BVH_TreeBaseTransient.def_static("get_type_name_", (const char * (*)()) &BVH_TreeBaseTransient::get_type_name, "None");
cls_BVH_TreeBaseTransient.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BVH_TreeBaseTransient::get_type_descriptor, "None");
cls_BVH_TreeBaseTransient.def("DynamicType", (const opencascade::handle<Standard_Type> & (BVH_TreeBaseTransient::*)() const) &BVH_TreeBaseTransient::DynamicType, "None");

// CLASS: BVH_QUADTREE

// CLASS: BVH_BINARYTREE

// CLASS: BVH_BUILDERTRANSIENT
py::class_<BVH_BuilderTransient, opencascade::handle<BVH_BuilderTransient>, Standard_Transient> cls_BVH_BuilderTransient(mod, "BVH_BuilderTransient", "A non-template class for using as base for BVH_Builder (just to have a named base class).");

// Methods
cls_BVH_BuilderTransient.def_static("get_type_name_", (const char * (*)()) &BVH_BuilderTransient::get_type_name, "None");
cls_BVH_BuilderTransient.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BVH_BuilderTransient::get_type_descriptor, "None");
cls_BVH_BuilderTransient.def("DynamicType", (const opencascade::handle<Standard_Type> & (BVH_BuilderTransient::*)() const) &BVH_BuilderTransient::DynamicType, "None");
cls_BVH_BuilderTransient.def("MaxTreeDepth", (Standard_Integer (BVH_BuilderTransient::*)() const) &BVH_BuilderTransient::MaxTreeDepth, "Returns the maximum depth of constructed BVH.");
cls_BVH_BuilderTransient.def("LeafNodeSize", (Standard_Integer (BVH_BuilderTransient::*)() const) &BVH_BuilderTransient::LeafNodeSize, "Returns the maximum number of sub-elements in the leaf.");

// CLASS: BVH_PROPERTIES
py::class_<BVH_Properties, opencascade::handle<BVH_Properties>, Standard_Transient> cls_BVH_Properties(mod, "BVH_Properties", "Abstract properties of geometric object.");

// Methods
cls_BVH_Properties.def_static("get_type_name_", (const char * (*)()) &BVH_Properties::get_type_name, "None");
cls_BVH_Properties.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BVH_Properties::get_type_descriptor, "None");
cls_BVH_Properties.def("DynamicType", (const opencascade::handle<Standard_Type> & (BVH_Properties::*)() const) &BVH_Properties::DynamicType, "None");

// CLASS: BVH_OBJECTTRANSIENT
py::class_<BVH_ObjectTransient, opencascade::handle<BVH_ObjectTransient>, Standard_Transient> cls_BVH_ObjectTransient(mod, "BVH_ObjectTransient", "A non-template class for using as base for BVH_Object (just to have a named base class).");

// Methods
cls_BVH_ObjectTransient.def_static("get_type_name_", (const char * (*)()) &BVH_ObjectTransient::get_type_name, "None");
cls_BVH_ObjectTransient.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BVH_ObjectTransient::get_type_descriptor, "None");
cls_BVH_ObjectTransient.def("DynamicType", (const opencascade::handle<Standard_Type> & (BVH_ObjectTransient::*)() const) &BVH_ObjectTransient::DynamicType, "None");
cls_BVH_ObjectTransient.def("Properties", (const opencascade::handle<BVH_Properties> & (BVH_ObjectTransient::*)() const) &BVH_ObjectTransient::Properties, "Returns properties of the geometric object.");
cls_BVH_ObjectTransient.def("SetProperties", (void (BVH_ObjectTransient::*)(const opencascade::handle<BVH_Properties> &)) &BVH_ObjectTransient::SetProperties, "Sets properties of the geometric object.", py::arg("theProperties"));
cls_BVH_ObjectTransient.def("IsDirty", (Standard_Boolean (BVH_ObjectTransient::*)() const) &BVH_ObjectTransient::IsDirty, "Returns TRUE if object state should be updated.");
cls_BVH_ObjectTransient.def("MarkDirty", (void (BVH_ObjectTransient::*)()) &BVH_ObjectTransient::MarkDirty, "Marks object state as outdated (needs BVH rebuilding).");

// CLASS: BVH_BUILDQUEUE
py::class_<BVH_BuildQueue> cls_BVH_BuildQueue(mod, "BVH_BuildQueue", "Command-queue for parallel building of BVH nodes.");

// Constructors
cls_BVH_BuildQueue.def(py::init<>());

// Methods
cls_BVH_BuildQueue.def("Size", (Standard_Integer (BVH_BuildQueue::*)()) &BVH_BuildQueue::Size, "Returns current size of BVH build queue.");
cls_BVH_BuildQueue.def("Enqueue", (void (BVH_BuildQueue::*)(const Standard_Integer &)) &BVH_BuildQueue::Enqueue, "Enqueues new work-item onto BVH build queue.", py::arg("theNode"));
cls_BVH_BuildQueue.def("Fetch", [](BVH_BuildQueue &self, Standard_Boolean & wasBusy){ Standard_Integer rv = self.Fetch(wasBusy); return std::tuple<Standard_Integer, Standard_Boolean &>(rv, wasBusy); }, "Fetches first work-item from BVH build queue.", py::arg("wasBusy"));
cls_BVH_BuildQueue.def("HasBusyThreads", (Standard_Boolean (BVH_BuildQueue::*)()) &BVH_BuildQueue::HasBusyThreads, "Checks if there are active build threads.");

// CLASS: BVH_BUILDTOOL
py::class_<BVH_BuildTool> cls_BVH_BuildTool(mod, "BVH_BuildTool", "Tool object to call BVH builder subroutines.");

// Methods
cls_BVH_BuildTool.def("Perform", (void (BVH_BuildTool::*)(const Standard_Integer)) &BVH_BuildTool::Perform, "Performs splitting of the given BVH node.", py::arg("theNode"));

// CLASS: BVH_BUILDTHREAD
py::class_<BVH_BuildThread, opencascade::handle<BVH_BuildThread>, Standard_Transient> cls_BVH_BuildThread(mod, "BVH_BuildThread", "Wrapper for BVH build thread.");

// Constructors
cls_BVH_BuildThread.def(py::init<BVH_BuildTool &, BVH_BuildQueue &>(), py::arg("theBuildTool"), py::arg("theBuildQueue"));

// Methods
cls_BVH_BuildThread.def("Run", (void (BVH_BuildThread::*)()) &BVH_BuildThread::Run, "Starts execution of BVH build thread.");
cls_BVH_BuildThread.def("Wait", (void (BVH_BuildThread::*)()) &BVH_BuildThread::Wait, "Waits till the thread finishes execution.");
cls_BVH_BuildThread.def_static("get_type_name_", (const char * (*)()) &BVH_BuildThread::get_type_name, "None");
cls_BVH_BuildThread.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BVH_BuildThread::get_type_descriptor, "None");
cls_BVH_BuildThread.def("DynamicType", (const opencascade::handle<Standard_Type> & (BVH_BuildThread::*)() const) &BVH_BuildThread::DynamicType, "None");

// TYPEDEF: BVH_PRIMITIVESET3D
bind_BVH_PrimitiveSet<double, 3>(mod, "BVH_PrimitiveSet3d", py::module_local(false));

// TYPEDEF: BVH_ENCODEDLINK
/*
bind_std::pair<int, int>(mod, "BVH_EncodedLink", py::module_local(false));
*/


}
