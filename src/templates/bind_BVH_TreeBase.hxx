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
#ifndef __BVH_TreeBase__
#define __BVH_TreeBase__

#include <BVH_Tree.hxx>
#include <BVH_Builder.hxx>
#include <BVH_Box.hxx>
#include <BVH_Types.hxx>
#include <Standard_OStream.hxx>
#include <Standard_TypeDef.hxx>

template <typename T, int N>
void bind_BVH_TreeBase(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<BVH_TreeBase<T, N>, opencascade::handle<BVH_TreeBase<T, N>>, BVH_TreeBaseTransient> cls_BVH_TreeBase(mod, name.c_str(), "Stores parameters of bounding volume hierarchy (BVH). Bounding volume hierarchy (BVH) organizes geometric objects in the tree based on spatial relationships. Each node in the tree contains an axis-aligned bounding box of all the objects below it. Bounding volume hierarchies are used in many algorithms to support efficient operations on the sets of geometric objects, such as collision detection, ray-tracing, searching of nearest objects, and view frustum culling.", local);

// Constructors
cls_BVH_TreeBase.def(py::init<>());

// Fields
cls_BVH_TreeBase.def_readwrite("myNodeInfoBuffer", &BVH_TreeBase<T, N>::myNodeInfoBuffer, "Array of node data records.");
cls_BVH_TreeBase.def_readwrite("myMinPointBuffer", &BVH_TreeBase<T, N>::myMinPointBuffer, "Array of node minimum points.");
cls_BVH_TreeBase.def_readwrite("myMaxPointBuffer", &BVH_TreeBase<T, N>::myMaxPointBuffer, "Array of node maximum points.");
cls_BVH_TreeBase.def_readwrite("myDepth", &BVH_TreeBase<T, N>::myDepth, "Current depth of BVH tree (set by builder).");

// Methods
cls_BVH_TreeBase.def("Depth", (int (BVH_TreeBase<T, N>::*)() const) &BVH_TreeBase<T, N>::Depth, "Returns depth (height) of BVH tree.");
cls_BVH_TreeBase.def("Length", (int (BVH_TreeBase<T, N>::*)() const) &BVH_TreeBase<T, N>::Length, "Returns total number of BVH tree nodes.");
cls_BVH_TreeBase.def("MinPoint", (typename BVH_TreeBase<T, N>::BVH_VecNt & (BVH_TreeBase<T, N>::*)(const int)) &BVH_TreeBase<T, N>::MinPoint, "Returns minimum point of the given node.", py::arg("theNodeIndex"));
cls_BVH_TreeBase.def("MaxPoint", (typename BVH_TreeBase<T, N>::BVH_VecNt & (BVH_TreeBase<T, N>::*)(const int)) &BVH_TreeBase<T, N>::MaxPoint, "Returns maximum point of the given node.", py::arg("theNodeIndex"));
cls_BVH_TreeBase.def("MinPoint", (const typename BVH_TreeBase<T, N>::BVH_VecNt & (BVH_TreeBase<T, N>::*)(const int) const) &BVH_TreeBase<T, N>::MinPoint, "Returns minimum point of the given node.", py::arg("theNodeIndex"));
cls_BVH_TreeBase.def("MaxPoint", (const typename BVH_TreeBase<T, N>::BVH_VecNt & (BVH_TreeBase<T, N>::*)(const int) const) &BVH_TreeBase<T, N>::MaxPoint, "Returns maximum point of the given node.", py::arg("theNodeIndex"));
cls_BVH_TreeBase.def("BegPrimitive", (int & (BVH_TreeBase<T, N>::*)(const int)) &BVH_TreeBase<T, N>::BegPrimitive, "Returns index of first primitive of the given leaf node.", py::arg("theNodeIndex"));
cls_BVH_TreeBase.def("EndPrimitive", (int & (BVH_TreeBase<T, N>::*)(const int)) &BVH_TreeBase<T, N>::EndPrimitive, "Returns index of last primitive of the given leaf node.", py::arg("theNodeIndex"));
cls_BVH_TreeBase.def("BegPrimitive", (int (BVH_TreeBase<T, N>::*)(const int) const) &BVH_TreeBase<T, N>::BegPrimitive, "Returns index of first primitive of the given leaf node.", py::arg("theNodeIndex"));
cls_BVH_TreeBase.def("EndPrimitive", (int (BVH_TreeBase<T, N>::*)(const int) const) &BVH_TreeBase<T, N>::EndPrimitive, "Returns index of last primitive of the given leaf node.", py::arg("theNodeIndex"));
cls_BVH_TreeBase.def("NbPrimitives", (int (BVH_TreeBase<T, N>::*)(const int) const) &BVH_TreeBase<T, N>::NbPrimitives, "Returns number of primitives in the given leaf node.", py::arg("theNodeIndex"));
cls_BVH_TreeBase.def("Level", (int & (BVH_TreeBase<T, N>::*)(const int)) &BVH_TreeBase<T, N>::Level, "Returns level (depth) of the given node.", py::arg("theNodeIndex"));
cls_BVH_TreeBase.def("Level", (int (BVH_TreeBase<T, N>::*)(const int) const) &BVH_TreeBase<T, N>::Level, "Returns level (depth) of the given node.", py::arg("theNodeIndex"));
cls_BVH_TreeBase.def("IsOuter", (bool (BVH_TreeBase<T, N>::*)(const int) const) &BVH_TreeBase<T, N>::IsOuter, "Checks whether the given node is outer.", py::arg("theNodeIndex"));
cls_BVH_TreeBase.def("NodeInfoBuffer", (BVH_Array4i & (BVH_TreeBase<T, N>::*)()) &BVH_TreeBase<T, N>::NodeInfoBuffer, "Returns array of node data records.");
cls_BVH_TreeBase.def("NodeInfoBuffer", (const BVH_Array4i & (BVH_TreeBase<T, N>::*)() const) &BVH_TreeBase<T, N>::NodeInfoBuffer, "Returns array of node data records.");
cls_BVH_TreeBase.def("MinPointBuffer", (typename BVH::ArrayType<T, N>::Type & (BVH_TreeBase<T, N>::*)()) &BVH_TreeBase<T, N>::MinPointBuffer, "Returns array of node minimum points.");
cls_BVH_TreeBase.def("MaxPointBuffer", (typename BVH::ArrayType<T, N>::Type & (BVH_TreeBase<T, N>::*)()) &BVH_TreeBase<T, N>::MaxPointBuffer, "Returns array of node maximum points.");
cls_BVH_TreeBase.def("MinPointBuffer", (const typename BVH::ArrayType<T, N>::Type & (BVH_TreeBase<T, N>::*)() const) &BVH_TreeBase<T, N>::MinPointBuffer, "Returns array of node minimum points.");
cls_BVH_TreeBase.def("MaxPointBuffer", (const typename BVH::ArrayType<T, N>::Type & (BVH_TreeBase<T, N>::*)() const) &BVH_TreeBase<T, N>::MaxPointBuffer, "Returns array of node maximum points.");
cls_BVH_TreeBase.def("DumpJson", [](BVH_TreeBase<T, N> &self, Standard_OStream & a0) -> void { return self.DumpJson(a0); });
cls_BVH_TreeBase.def("DumpJson", (void (BVH_TreeBase<T, N>::*)(Standard_OStream &, const Standard_Integer) const) &BVH_TreeBase<T, N>::DumpJson, "Dumps the content of me into the stream", py::arg("theOStream"), py::arg("theDepth"));
cls_BVH_TreeBase.def("DumpNode", (void (BVH_TreeBase<T, N>::*)(const int, Standard_OStream &, const Standard_Integer) const) &BVH_TreeBase<T, N>::DumpNode, "Dumps the content of node into the stream", py::arg("theNodeIndex"), py::arg("theOStream"), py::arg("theDepth"));

}

#endif