/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC (info@laughlinresearch.com)

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
#ifndef __BVH_Templates_Header__
#define __BVH_Templates_Header__

#include <pyOCCT_Common.hpp>

#include <BVH_BinnedBuilder.hxx>
#include <BVH_QueueBuilder.hxx>
#include <Standard_TypeDef.hxx>
#include <BVH_Box.hxx>
#include <BVH_Builder.hxx>
#include <BVH_Set.hxx>
#include <BVH_Tree.hxx>
#include <BVH_Geometry.hxx>
#include <BVH_DistanceField.hxx>
#include <BVH_ObjectSet.hxx>
#include <Standard_Handle.hxx>
#include <BVH_LinearBuilder.hxx>
#include <BVH_Object.hxx>
#include <BVH_PrimitiveSet.hxx>
#include <BVH_Sorter.hxx>
#include <BVH_QuickSorter.hxx>
#include <NCollection_Array1.hxx>
#include <BVH_RadixSorter.hxx>
#include <BVH_SpatialMedianBuilder.hxx>
#include <BVH_SweepPlaneBuilder.hxx>
#include <BVH_Properties.hxx>
#include <BVH_Types.hxx>
#include <BVH_Triangulation.hxx>

// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_BinnedBuilder.hxx
template <typename T, int N>
void bind_BVH_Bin(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_BinnedBuilder.hxx
	py::class_<BVH_Bin<T, N>, std::unique_ptr<BVH_Bin<T, N>, Deleter<BVH_Bin<T, N>>>> cls(mod, name.c_str(), "Stores parameters of single bin (slice of AABB).");
	cls.def(py::init<>());

};

// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_BinnedBuilder.hxx
template <typename T, int N, int Bins>
void bind_BVH_BinnedBuilder(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_BinnedBuilder.hxx
	py::class_<BVH_BinnedBuilder<T, N, Bins>, opencascade::handle<BVH_BinnedBuilder<T, N, Bins>>, BVH_QueueBuilder<T, N>> cls(mod, name.c_str(), "Performs construction of BVH tree using binned SAH algorithm. Number of bins controls BVH quality in cost of construction time (greater - better). For optimal results, use 32 - 48 bins. However, reasonable performance is provided even for 4 - 8 bins (it is only 10-20% lower in comparison with optimal settings). Note that multiple threads can be used only with thread safe BVH primitive sets.");
	cls.def(py::init<>());
	cls.def(py::init<const Standard_Integer>(), py::arg("theLeafNodeSize"));
	cls.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLeafNodeSize"), py::arg("theMaxTreeDepth"));
	cls.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Boolean>(), py::arg("theLeafNodeSize"), py::arg("theMaxTreeDepth"), py::arg("theDoMainSplits"));
	cls.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Integer>(), py::arg("theLeafNodeSize"), py::arg("theMaxTreeDepth"), py::arg("theDoMainSplits"), py::arg("theNumOfThreads"));

};

// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_Box.hxx
template <typename T, int N>
void bind_BVH_Box(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_Box.hxx
	py::class_<BVH_Box<T, N>, std::unique_ptr<BVH_Box<T, N>, Deleter<BVH_Box<T, N>>>> cls(mod, name.c_str(), "Defines axis aligned bounding box (AABB) based on BVH vectors.");
	cls.def(py::init<>());
	cls.def(py::init<const typename BVH_Box<T, N>::BVH_VecNt &>(), py::arg("thePoint"));
	cls.def(py::init([] (const BVH_Box<T, N> &other) {return new BVH_Box<T, N>(other);}), "Copy constructor", py::arg("other"));
	cls.def(py::init<const typename BVH_Box<T, N>::BVH_VecNt &, const typename BVH_Box<T, N>::BVH_VecNt &>(), py::arg("theMinPoint"), py::arg("theMaxPoint"));
	cls.def("Clear", (void (BVH_Box<T, N>::*)()) &BVH_Box<T, N>::Clear, "Clears bounding box.");
	cls.def("IsValid", (Standard_Boolean (BVH_Box<T, N>::*)() const ) &BVH_Box<T, N>::IsValid, "Is bounding box valid?");
	cls.def("Add", (void (BVH_Box<T, N>::*)(const typename BVH_Box<T, N>::BVH_VecNt &)) &BVH_Box<T, N>::Add, "Appends new point to the bounding box.", py::arg("thePoint"));
	cls.def("Combine", (void (BVH_Box<T, N>::*)(const BVH_Box<T, N> &)) &BVH_Box<T, N>::Combine, "Combines bounding box with another one.", py::arg("theBox"));
	cls.def("CornerMin", (const typename BVH_Box<T, N>::BVH_VecNt & (BVH_Box<T, N>::*)() const ) &BVH_Box<T, N>::CornerMin, "Returns minimum point of bounding box.");
	cls.def("CornerMax", (const typename BVH_Box<T, N>::BVH_VecNt & (BVH_Box<T, N>::*)() const ) &BVH_Box<T, N>::CornerMax, "Returns maximum point of bounding box.");
	cls.def("CornerMin", (typename BVH_Box<T, N>::BVH_VecNt & (BVH_Box<T, N>::*)()) &BVH_Box<T, N>::CornerMin, "Returns minimum point of bounding box.");
	cls.def("CornerMax", (typename BVH_Box<T, N>::BVH_VecNt & (BVH_Box<T, N>::*)()) &BVH_Box<T, N>::CornerMax, "Returns maximum point of bounding box.");
	cls.def("Area", (T (BVH_Box<T, N>::*)() const ) &BVH_Box<T, N>::Area, "Returns surface area of bounding box. If the box is degenerated into line, returns the perimeter instead.");
	cls.def("Size", (typename BVH_Box<T, N>::BVH_VecNt (BVH_Box<T, N>::*)() const ) &BVH_Box<T, N>::Size, "Returns diagonal of bounding box.");
	cls.def("Center", (typename BVH_Box<T, N>::BVH_VecNt (BVH_Box<T, N>::*)() const ) &BVH_Box<T, N>::Center, "Returns center of bounding box.");
	cls.def("Center", (T (BVH_Box<T, N>::*)(const Standard_Integer) const ) &BVH_Box<T, N>::Center, "Returns center of bounding box along the given axis.", py::arg("theAxis"));

};

// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_Builder.hxx
template <typename T, int N>
void bind_BVH_Builder(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_Builder.hxx
	py::class_<BVH_Builder<T, N>, opencascade::handle<BVH_Builder<T, N>>, BVH_BuilderTransient> cls(mod, name.c_str(), "Performs construction of BVH tree using bounding boxes (AABBs) of abstract objects.");
	cls.def("Build", (void (BVH_Builder<T, N>::*)(BVH_Set<T, N> *, BVH_Tree<T, N> *, const BVH_Box<T, N> &) const ) &BVH_Builder<T, N>::Build, "Builds BVH using specific algorithm.", py::arg("theSet"), py::arg("theBVH"), py::arg("theBox"));

};

// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_DistanceField.hxx
template <typename T, int N>
void bind_BVH_DistanceField(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_DistanceField.hxx
	py::class_<BVH_DistanceField<T, N>, std::unique_ptr<BVH_DistanceField<T, N>, Deleter<BVH_DistanceField<T, N>>>> cls(mod, name.c_str(), "Tool object for building 3D distance field from the set of BVH triangulations. Distance field is a scalar field that measures the distance from a given point to some object, including optional information about the inside and outside of the structure. Distance fields are used as alternative surface representations (like polygons or NURBS).");
	cls.def(py::init<const Standard_Integer, const Standard_Boolean>(), py::arg("theMaximumSize"), py::arg("theComputeSign"));
	cls.def("Build", (Standard_Boolean (BVH_DistanceField<T, N>::*)(BVH_Geometry<T, N> &)) &BVH_DistanceField<T, N>::Build, "Builds 3D distance field from BVH geometry.", py::arg("theGeometry"));
	cls.def("PackedData", (const T * (BVH_DistanceField<T, N>::*)() const ) &BVH_DistanceField<T, N>::PackedData, "Returns packed voxel data.");
	cls.def("Voxel", (T & (BVH_DistanceField<T, N>::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer)) &BVH_DistanceField<T, N>::Voxel, "Returns distance value for the given voxel.", py::arg("theX"), py::arg("theY"), py::arg("theZ"));
	cls.def("Voxel", (T (BVH_DistanceField<T, N>::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer) const ) &BVH_DistanceField<T, N>::Voxel, "Returns distance value for the given voxel.", py::arg("theX"), py::arg("theY"), py::arg("theZ"));
	cls.def("DimensionX", (Standard_Integer (BVH_DistanceField<T, N>::*)() const ) &BVH_DistanceField<T, N>::DimensionX, "Returns size of voxel grid in X dimension.");
	cls.def("DimensionY", (Standard_Integer (BVH_DistanceField<T, N>::*)() const ) &BVH_DistanceField<T, N>::DimensionY, "Returns size of voxel grid in Y dimension.");
	cls.def("DimensionZ", (Standard_Integer (BVH_DistanceField<T, N>::*)() const ) &BVH_DistanceField<T, N>::DimensionZ, "Returns size of voxel grid in Z dimension.");
	cls.def("VoxelSize", (const typename BVH_DistanceField<T, N>::BVH_VecNt & (BVH_DistanceField<T, N>::*)() const ) &BVH_DistanceField<T, N>::VoxelSize, "Returns size of single voxel.");
	cls.def("CornerMin", (const typename BVH_DistanceField<T, N>::BVH_VecNt & (BVH_DistanceField<T, N>::*)() const ) &BVH_DistanceField<T, N>::CornerMin, "Returns minimum corner of voxel grid.");
	cls.def("CornerMax", (const typename BVH_DistanceField<T, N>::BVH_VecNt & (BVH_DistanceField<T, N>::*)() const ) &BVH_DistanceField<T, N>::CornerMax, "Returns maximum corner of voxel grid.");

};

// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_Geometry.hxx
template <typename T, int N>
void bind_BVH_Geometry(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_Geometry.hxx
	py::class_<BVH_Geometry<T, N>, std::unique_ptr<BVH_Geometry<T, N>, Deleter<BVH_Geometry<T, N>>>, BVH_ObjectSet<T, N>> cls(mod, name.c_str(), "BVH geometry as a set of abstract geometric objects organized with bounding volume hierarchy (BVH).");
	cls.def(py::init<>());
	cls.def(py::init<const opencascade::handle<BVH_Builder<T, N> > &>(), py::arg("theBuilder"));
	cls.def("IsDirty", (Standard_Boolean (BVH_Geometry<T, N>::*)() const ) &BVH_Geometry<T, N>::IsDirty, "Returns TRUE if geometry state should be updated.");
	cls.def("MarkDirty", (void (BVH_Geometry<T, N>::*)()) &BVH_Geometry<T, N>::MarkDirty, "Marks geometry as outdated.");
	cls.def("Box", (BVH_Box<T, N> (BVH_Geometry<T, N>::*)() const ) &BVH_Geometry<T, N>::Box, "Returns AABB of the whole geometry.");
	cls.def("BVH", (const opencascade::handle<BVH_Tree<T, N> > & (BVH_Geometry<T, N>::*)()) &BVH_Geometry<T, N>::BVH, "Returns BVH tree (and builds it if necessary).");
	cls.def("Builder", (const opencascade::handle<BVH_Builder<T, N> > & (BVH_Geometry<T, N>::*)() const ) &BVH_Geometry<T, N>::Builder, "Returns the method (builder) used to construct BVH.");
	cls.def("SetBuilder", (void (BVH_Geometry<T, N>::*)(const opencascade::handle<BVH_Builder<T, N> > &)) &BVH_Geometry<T, N>::SetBuilder, "Sets the method (builder) used to construct BVH.", py::arg("theBuilder"));

};

// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_LinearBuilder.hxx
template <typename T, int N>
void bind_BVH_LinearBuilder(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_LinearBuilder.hxx
	py::class_<BVH_LinearBuilder<T, N>, opencascade::handle<BVH_LinearBuilder<T, N>>, BVH_Builder<T, N>> cls(mod, name.c_str(), "Performs fast BVH construction using LBVH building approach. Algorithm uses spatial Morton codes to reduce the BVH construction problem to a sorting problem (radix sort -- O(N) complexity). This Linear Bounding Volume Hierarchy (LBVH) builder produces BVH trees of lower quality compared to SAH-based BVH builders but it is over an order of magnitude faster (up to 3M triangles per second).");
	cls.def(py::init<>());
	cls.def(py::init<const Standard_Integer>(), py::arg("theLeafNodeSize"));
	cls.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLeafNodeSize"), py::arg("theMaxTreeDepth"));
	cls.def("Build", (void (BVH_LinearBuilder<T, N>::*)(BVH_Set<T, N> *, BVH_Tree<T, N> *, const BVH_Box<T, N> &) const ) &BVH_LinearBuilder<T, N>::Build, "Builds BVH.", py::arg("theSet"), py::arg("theBVH"), py::arg("theBox"));

};

// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_Object.hxx
template <typename T, int N>
void bind_BVH_Object(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_Object.hxx
	py::class_<BVH_Object<T, N>, opencascade::handle<BVH_Object<T, N>>, BVH_ObjectTransient> cls(mod, name.c_str(), "Abstract geometric object bounded by BVH box.");
	cls.def(py::init<>());
	cls.def("Box", (BVH_Box<T, N> (BVH_Object<T, N>::*)() const ) &BVH_Object<T, N>::Box, "Returns AABB of the geometric object.");

};

// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_ObjectSet.hxx
template <typename T, int N>
void bind_BVH_ObjectSet(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_ObjectSet.hxx
	py::class_<BVH_ObjectSet<T, N>, std::unique_ptr<BVH_ObjectSet<T, N>, Deleter<BVH_ObjectSet<T, N>>>, BVH_Set<T, N>> cls(mod, name.c_str(), "Array of abstract entities (bounded by BVH boxes) to built BVH.");
	cls.def(py::init<>());
	cls.def("Clear", (void (BVH_ObjectSet<T, N>::*)()) &BVH_ObjectSet<T, N>::Clear, "Removes all geometric objects.");
	cls.def("Objects", (typename BVH_ObjectSet<T, N>::BVH_ObjectList & (BVH_ObjectSet<T, N>::*)()) &BVH_ObjectSet<T, N>::Objects, "Returns reference to the array of geometric objects.");
	cls.def("Objects", (const typename BVH_ObjectSet<T, N>::BVH_ObjectList & (BVH_ObjectSet<T, N>::*)() const ) &BVH_ObjectSet<T, N>::Objects, "Returns reference to the array of geometric objects.");
	cls.def("Size", (Standard_Integer (BVH_ObjectSet<T, N>::*)() const ) &BVH_ObjectSet<T, N>::Size, "Return total number of objects.");
	cls.def("Box", (BVH_Box<T, N> (BVH_ObjectSet<T, N>::*)(const Standard_Integer) const ) &BVH_ObjectSet<T, N>::Box, "Returns AABB of the given object.", py::arg("theIndex"));
	cls.def("Center", (T (BVH_ObjectSet<T, N>::*)(const Standard_Integer, const Standard_Integer) const ) &BVH_ObjectSet<T, N>::Center, "Returns centroid position along the given axis.", py::arg("theIndex"), py::arg("theAxis"));
	cls.def("Swap", (void (BVH_ObjectSet<T, N>::*)(const Standard_Integer, const Standard_Integer)) &BVH_ObjectSet<T, N>::Swap, "Performs transposing the two given objects in the set.", py::arg("theIndex1"), py::arg("theIndex2"));

};

// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_DistanceField.hxx
template <typename T, int N>
void bind_BVH_ParallelDistanceFieldBuilder(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_DistanceField.hxx
	py::class_<BVH_ParallelDistanceFieldBuilder<T, N>, std::unique_ptr<BVH_ParallelDistanceFieldBuilder<T, N>, Deleter<BVH_ParallelDistanceFieldBuilder<T, N>>>> cls(mod, name.c_str(), "None");
	cls.def(py::init<>());

};

// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_PrimitiveSet.hxx
template <typename T, int N>
void bind_BVH_PrimitiveSet(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_PrimitiveSet.hxx
	// FIXME Don't bind bases that are not registered
	// py::class_<BVH_PrimitiveSet<T, N>, opencascade::handle<BVH_PrimitiveSet<T, N>>, BVH_Object<T, N>, BVH_Set<T, N>> cls(mod, name.c_str(), "Set of abstract geometric primitives organized with bounding volume hierarchy (BVH). Unlike an object set, this collection is designed for storing structural elements of a single object (such as triangles in the object triangulation). Because there may be a large number of such elements, the implementations of this interface should be sufficiently optimized.");
	py::class_<BVH_PrimitiveSet<T, N>, opencascade::handle<BVH_PrimitiveSet<T, N>>> cls(mod, name.c_str(), "Set of abstract geometric primitives organized with bounding volume hierarchy (BVH). Unlike an object set, this collection is designed for storing structural elements of a single object (such as triangles in the object triangulation). Because there may be a large number of such elements, the implementations of this interface should be sufficiently optimized.");
	// FIXME cls.def(py::init<>());
	// FIXME cls.def(py::init<const opencascade::handle<BVH_Builder<T, N> > &>(), py::arg("theBuilder"));
	cls.def("Box", (BVH_Box<T, N> (BVH_PrimitiveSet<T, N>::*)() const ) &BVH_PrimitiveSet<T, N>::Box, "Returns AABB of primitive set.");
	cls.def("BVH", (const opencascade::handle<BVH_Tree<T, N> > & (BVH_PrimitiveSet<T, N>::*)()) &BVH_PrimitiveSet<T, N>::BVH, "Returns BVH tree (and builds it if necessary).");
	cls.def("Builder", (const opencascade::handle<BVH_Builder<T, N> > & (BVH_PrimitiveSet<T, N>::*)() const ) &BVH_PrimitiveSet<T, N>::Builder, "Returns the method (builder) used to construct BVH.");
	cls.def("SetBuilder", (void (BVH_PrimitiveSet<T, N>::*)(const opencascade::handle<BVH_Builder<T, N> > &)) &BVH_PrimitiveSet<T, N>::SetBuilder, "Sets the method (builder) used to construct BVH.", py::arg("theBuilder"));

};

// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_QueueBuilder.hxx
template <typename T, int N>
void bind_BVH_QueueBuilder(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_QueueBuilder.hxx
	py::class_<BVH_QueueBuilder<T, N>, opencascade::handle<BVH_QueueBuilder<T, N>>, BVH_Builder<T, N>> cls(mod, name.c_str(), "Abstract BVH builder based on the concept of work queue. Queue based BVH builders support parallelization with a fixed number of threads (maximum efficiency is achieved by setting the number of threads equal to the number of CPU cores plus one). Note that to support parallel mode, a corresponding BVH primitive set should provide thread safe implementations of interface functions (e.g., Swap, Box, Center). Otherwise, the results will be undefined.");
	cls.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLeafNodeSize"), py::arg("theMaxTreeDepth"));
	cls.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theLeafNodeSize"), py::arg("theMaxTreeDepth"), py::arg("theNumOfThreads"));
	cls.def("Build", (void (BVH_QueueBuilder<T, N>::*)(BVH_Set<T, N> *, BVH_Tree<T, N> *, const BVH_Box<T, N> &) const ) &BVH_QueueBuilder<T, N>::Build, "Builds BVH using specific algorithm.", py::arg("theSet"), py::arg("theBVH"), py::arg("theBox"));

};

// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_QuickSorter.hxx
template <typename T, int N>
void bind_BVH_QuickSorter(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_QuickSorter.hxx
	py::class_<BVH_QuickSorter<T, N>, std::unique_ptr<BVH_QuickSorter<T, N>, Deleter<BVH_QuickSorter<T, N>>>, BVH_Sorter<T, N>> cls(mod, name.c_str(), "Performs centroid-based sorting of abstract set along the given axis (X - 0, Y - 1, Z - 2) using quick sort.");
	cls.def(py::init<>());
	cls.def(py::init<const Standard_Integer>(), py::arg("theAxis"));
	cls.def("Perform", (void (BVH_QuickSorter<T, N>::*)(BVH_Set<T, N> *)) &BVH_QuickSorter<T, N>::Perform, "Sorts the set.", py::arg("theSet"));
	cls.def("Perform", (void (BVH_QuickSorter<T, N>::*)(BVH_Set<T, N> *, const Standard_Integer, const Standard_Integer)) &BVH_QuickSorter<T, N>::Perform, "Sorts the given (inclusive) range in the set.", py::arg("theSet"), py::arg("theStart"), py::arg("theFinal"));

};

// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_RadixSorter.hxx
template <typename T, int N>
void bind_BVH_RadixSorter(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_RadixSorter.hxx
	py::class_<BVH_RadixSorter<T, N>, std::unique_ptr<BVH_RadixSorter<T, N>, Deleter<BVH_RadixSorter<T, N>>>, BVH_Sorter<T, N>> cls(mod, name.c_str(), "Performs radix sort of a BVH primitive set using 10-bit Morton codes (or 1024 x 1024 x 1024 grid).");
	cls.def(py::init<const BVH_Box<T, N> &>(), py::arg("theBox"));
	cls.def("Perform", (void (BVH_RadixSorter<T, N>::*)(BVH_Set<T, N> *)) &BVH_RadixSorter<T, N>::Perform, "Sorts the set.", py::arg("theSet"));
	cls.def("Perform", (void (BVH_RadixSorter<T, N>::*)(BVH_Set<T, N> *, const Standard_Integer, const Standard_Integer)) &BVH_RadixSorter<T, N>::Perform, "Sorts the given (inclusive) range in the set.", py::arg("theSet"), py::arg("theStart"), py::arg("theFinal"));
	cls.def("EncodedLinks", (const NCollection_Array1<BVH_EncodedLink> & (BVH_RadixSorter<T, N>::*)() const ) &BVH_RadixSorter<T, N>::EncodedLinks, "Returns Morton codes assigned to BVH primitives.");

};

// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_Set.hxx
template <typename T, int N>
void bind_BVH_Set(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_Set.hxx
	py::class_<BVH_Set<T, N>, std::unique_ptr<BVH_Set<T, N>, Deleter<BVH_Set<T, N>>>> cls(mod, name.c_str(), "Set of abstract entities (bounded by BVH boxes). This is the minimal geometry interface needed to construct BVH.");
	cls.def(py::init<>());
	cls.def("Box", (BVH_Box<T, N> (BVH_Set<T, N>::*)() const ) &BVH_Set<T, N>::Box, "Returns AABB of the entire set of objects.");
	cls.def("Size", (Standard_Integer (BVH_Set<T, N>::*)() const ) &BVH_Set<T, N>::Size, "Returns total number of objects.");
	cls.def("Box", (BVH_Box<T, N> (BVH_Set<T, N>::*)(const Standard_Integer) const ) &BVH_Set<T, N>::Box, "Returns AABB of the given object.", py::arg("theIndex"));
	cls.def("Center", (T (BVH_Set<T, N>::*)(const Standard_Integer, const Standard_Integer) const ) &BVH_Set<T, N>::Center, "Returns centroid position along the given axis.", py::arg("theIndex"), py::arg("theAxis"));
	cls.def("Swap", (void (BVH_Set<T, N>::*)(const Standard_Integer, const Standard_Integer)) &BVH_Set<T, N>::Swap, "Performs transposing the two given objects in the set.", py::arg("theIndex1"), py::arg("theIndex2"));

};

// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_Sorter.hxx
template <typename T, int N>
void bind_BVH_Sorter(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_Sorter.hxx
	py::class_<BVH_Sorter<T, N>, std::unique_ptr<BVH_Sorter<T, N>, Deleter<BVH_Sorter<T, N>>>> cls(mod, name.c_str(), "Tool object to sort abstract primitive set.");
	cls.def("Perform", (void (BVH_Sorter<T, N>::*)(BVH_Set<T, N> *)) &BVH_Sorter<T, N>::Perform, "Sorts the set.", py::arg("theSet"));
	cls.def("Perform", (void (BVH_Sorter<T, N>::*)(BVH_Set<T, N> *, const Standard_Integer, const Standard_Integer)) &BVH_Sorter<T, N>::Perform, "Sorts the given (inclusive) range in the set.", py::arg("theSet"), py::arg("theStart"), py::arg("theFinal"));

};

// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_SpatialMedianBuilder.hxx
template <typename T, int N>
void bind_BVH_SpatialMedianBuilder(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_SpatialMedianBuilder.hxx
	py::class_<BVH_SpatialMedianBuilder<T, N>, opencascade::handle<BVH_SpatialMedianBuilder<T, N>>, BVH_BinnedBuilder<T, N, 2>> cls(mod, name.c_str(), "Performs building of BVH tree using spatial median split algorithm.");
	cls.def(py::init<>());
	cls.def(py::init<const Standard_Integer>(), py::arg("theLeafNodeSize"));
	cls.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLeafNodeSize"), py::arg("theMaxTreeDepth"));
	cls.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Boolean>(), py::arg("theLeafNodeSize"), py::arg("theMaxTreeDepth"), py::arg("theToUseMainAxis"));

};

// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_SweepPlaneBuilder.hxx
template <typename T, int N>
void bind_BVH_SweepPlaneBuilder(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_SweepPlaneBuilder.hxx
	py::class_<BVH_SweepPlaneBuilder<T, N>, opencascade::handle<BVH_SweepPlaneBuilder<T, N>>, BVH_QueueBuilder<T, N>> cls(mod, name.c_str(), "Performs building of BVH tree using sweep plane SAH algorithm.");
	cls.def(py::init<>());
	cls.def(py::init<const Standard_Integer>(), py::arg("theLeafNodeSize"));
	cls.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLeafNodeSize"), py::arg("theMaxTreeDepth"));
	cls.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theLeafNodeSize"), py::arg("theMaxTreeDepth"), py::arg("theNumOfThreads"));

};

// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_Properties.hxx
template <typename T, int N>
void bind_BVH_Transform(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_Properties.hxx
	py::class_<BVH_Transform<T, N>, opencascade::handle<BVH_Transform<T, N>>, BVH_Properties> cls(mod, name.c_str(), "Stores transform properties of geometric object.");
	cls.def(py::init<>());
	cls.def(py::init<const typename BVH_Transform<T, N>::BVH_MatNt &>(), py::arg("theTransform"));
	cls.def("Transform", (const typename BVH_Transform<T, N>::BVH_MatNt & (BVH_Transform<T, N>::*)() const ) &BVH_Transform<T, N>::Transform, "Returns transformation matrix.");
	cls.def("SetTransform", (void (BVH_Transform<T, N>::*)(const typename BVH_Transform<T, N>::BVH_MatNt &)) &BVH_Transform<T, N>::SetTransform, "Sets new transformation matrix.", py::arg("theTransform"));
	cls.def("Inversed", (const typename BVH_Transform<T, N>::BVH_MatNt & (BVH_Transform<T, N>::*)() const ) &BVH_Transform<T, N>::Inversed, "Returns inversed transformation matrix.");
	cls.def("Apply", (BVH_Box<T, N> (BVH_Transform<T, N>::*)(const BVH_Box<T, N> &) const ) &BVH_Transform<T, N>::Apply, "Applies transformation matrix to bounding box.", py::arg("theBox"));

};

// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_Tree.hxx
template <typename T, int N, typename Arity>
void bind_BVH_Tree(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_Tree.hxx
	py::class_<BVH_Tree<T, N, Arity>, std::unique_ptr<BVH_Tree<T, N, Arity>, Deleter<BVH_Tree<T, N, Arity>>>> cls(mod, name.c_str(), "BVH tree with given arity (2 or 4).");
	cls.def(py::init<>());

};

// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_Tree.hxx
template <typename T, int N>
void bind_BVH_TreeBase(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_Tree.hxx
	py::class_<BVH_TreeBase<T, N>, opencascade::handle<BVH_TreeBase<T, N>>, BVH_TreeBaseTransient> cls(mod, name.c_str(), "Stores parameters of bounding volume hierarchy (BVH). Bounding volume hierarchy (BVH) organizes geometric objects in the tree based on spatial relationships. Each node in the tree contains an axis-aligned bounding box of all the objects below it. Bounding volume hierarchies are used in many algorithms to support efficient operations on the sets of geometric objects, such as collision detection, ray-tracing, searching of nearest objects, and view frustum culling.");
	cls.def(py::init<>());
	cls.def("Depth", (int (BVH_TreeBase<T, N>::*)() const ) &BVH_TreeBase<T, N>::Depth, "Returns depth (height) of BVH tree.");
	cls.def("Length", (int (BVH_TreeBase<T, N>::*)() const ) &BVH_TreeBase<T, N>::Length, "Returns total number of BVH tree nodes.");
	cls.def("MinPoint", (typename BVH_TreeBase<T, N>::BVH_VecNt & (BVH_TreeBase<T, N>::*)(const int)) &BVH_TreeBase<T, N>::MinPoint, "Returns minimum point of the given node.", py::arg("theNodeIndex"));
	cls.def("MaxPoint", (typename BVH_TreeBase<T, N>::BVH_VecNt & (BVH_TreeBase<T, N>::*)(const int)) &BVH_TreeBase<T, N>::MaxPoint, "Returns maximum point of the given node.", py::arg("theNodeIndex"));
	cls.def("MinPoint", (const typename BVH_TreeBase<T, N>::BVH_VecNt & (BVH_TreeBase<T, N>::*)(const int) const ) &BVH_TreeBase<T, N>::MinPoint, "Returns minimum point of the given node.", py::arg("theNodeIndex"));
	cls.def("MaxPoint", (const typename BVH_TreeBase<T, N>::BVH_VecNt & (BVH_TreeBase<T, N>::*)(const int) const ) &BVH_TreeBase<T, N>::MaxPoint, "Returns maximum point of the given node.", py::arg("theNodeIndex"));
	cls.def("BegPrimitive", (int & (BVH_TreeBase<T, N>::*)(const int)) &BVH_TreeBase<T, N>::BegPrimitive, "Returns index of first primitive of the given leaf node.", py::arg("theNodeIndex"));
	cls.def("EndPrimitive", (int & (BVH_TreeBase<T, N>::*)(const int)) &BVH_TreeBase<T, N>::EndPrimitive, "Returns index of last primitive of the given leaf node.", py::arg("theNodeIndex"));
	cls.def("BegPrimitive", (int (BVH_TreeBase<T, N>::*)(const int) const ) &BVH_TreeBase<T, N>::BegPrimitive, "Returns index of first primitive of the given leaf node.", py::arg("theNodeIndex"));
	cls.def("EndPrimitive", (int (BVH_TreeBase<T, N>::*)(const int) const ) &BVH_TreeBase<T, N>::EndPrimitive, "Returns index of last primitive of the given leaf node.", py::arg("theNodeIndex"));
	cls.def("NbPrimitives", (int (BVH_TreeBase<T, N>::*)(const int) const ) &BVH_TreeBase<T, N>::NbPrimitives, "Returns number of primitives in the given leaf node.", py::arg("theNodeIndex"));
	cls.def("Level", (int & (BVH_TreeBase<T, N>::*)(const int)) &BVH_TreeBase<T, N>::Level, "Returns level (depth) of the given node.", py::arg("theNodeIndex"));
	cls.def("Level", (int (BVH_TreeBase<T, N>::*)(const int) const ) &BVH_TreeBase<T, N>::Level, "Returns level (depth) of the given node.", py::arg("theNodeIndex"));
	cls.def("IsOuter", (bool (BVH_TreeBase<T, N>::*)(const int) const ) &BVH_TreeBase<T, N>::IsOuter, "Checks whether the given node is outer.", py::arg("theNodeIndex"));
	cls.def("NodeInfoBuffer", (BVH_Array4i & (BVH_TreeBase<T, N>::*)()) &BVH_TreeBase<T, N>::NodeInfoBuffer, "Returns array of node data records.");
	cls.def("NodeInfoBuffer", (const BVH_Array4i & (BVH_TreeBase<T, N>::*)() const ) &BVH_TreeBase<T, N>::NodeInfoBuffer, "Returns array of node data records.");
	cls.def("MinPointBuffer", (typename BVH::ArrayType<T, N>::Type & (BVH_TreeBase<T, N>::*)()) &BVH_TreeBase<T, N>::MinPointBuffer, "Returns array of node minimum points.");
	cls.def("MaxPointBuffer", (typename BVH::ArrayType<T, N>::Type & (BVH_TreeBase<T, N>::*)()) &BVH_TreeBase<T, N>::MaxPointBuffer, "Returns array of node maximum points.");
	cls.def("MinPointBuffer", (const typename BVH::ArrayType<T, N>::Type & (BVH_TreeBase<T, N>::*)() const ) &BVH_TreeBase<T, N>::MinPointBuffer, "Returns array of node minimum points.");
	cls.def("MaxPointBuffer", (const typename BVH::ArrayType<T, N>::Type & (BVH_TreeBase<T, N>::*)() const ) &BVH_TreeBase<T, N>::MaxPointBuffer, "Returns array of node maximum points.");

};

// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_Triangulation.hxx
template <typename T, int N>
void bind_BVH_Triangulation(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\BVH_Triangulation.hxx
	// FIXME Don't bind unknown base type
	// py::class_<BVH_Triangulation<T, N>, opencascade::handle<BVH_Triangulation<T, N>>, BVH_PrimitiveSet<T, N>> cls(mod, name.c_str(), "Triangulation as an example of BVH primitive set.");
	py::class_<BVH_Triangulation<T, N>, opencascade::handle<BVH_Triangulation<T, N>>> cls(mod, name.c_str(), "Triangulation as an example of BVH primitive set.");
	cls.def(py::init<>());
	cls.def(py::init<const opencascade::handle<BVH_Builder<T, N> > &>(), py::arg("theBuilder"));
	cls.def("Size", (Standard_Integer (BVH_Triangulation<T, N>::*)() const ) &BVH_Triangulation<T, N>::Size, "Returns total number of triangles.");
	cls.def("Box", (BVH_Box<T, N> (BVH_Triangulation<T, N>::*)(const Standard_Integer) const ) &BVH_Triangulation<T, N>::Box, "Returns AABB of the given triangle.", py::arg("theIndex"));
	cls.def("Center", (T (BVH_Triangulation<T, N>::*)(const Standard_Integer, const Standard_Integer) const ) &BVH_Triangulation<T, N>::Center, "Returns centroid position along the given axis.", py::arg("theIndex"), py::arg("theAxis"));
	cls.def("Swap", (void (BVH_Triangulation<T, N>::*)(const Standard_Integer, const Standard_Integer)) &BVH_Triangulation<T, N>::Swap, "Performs transposing the two given triangles in the set.", py::arg("theIndex1"), py::arg("theIndex2"));

};

#endif
