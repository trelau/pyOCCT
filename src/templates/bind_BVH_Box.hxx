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
#ifndef __BVH_Box__
#define __BVH_Box__

#include <BVH_Types.hxx>
#include <BVH_Box.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_OStream.hxx>

template <typename T, int N>
void bind_BVH_Box(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<BVH_Box<T, N>> cls_BVH_Box(mod, name.c_str(), "Defines axis aligned bounding box (AABB) based on BVH vectors.", local);

// Constructors
cls_BVH_Box.def(py::init<>());
cls_BVH_Box.def(py::init<const typename BVH_Box<T, N>::BVH_VecNt &>(), py::arg("thePoint"));
cls_BVH_Box.def(py::init<const BVH_Box<T, N> &>(), py::arg("theBox"));
cls_BVH_Box.def(py::init<const typename BVH_Box<T, N>::BVH_VecNt &, const typename BVH_Box<T, N>::BVH_VecNt &>(), py::arg("theMinPoint"), py::arg("theMaxPoint"));

// Methods
cls_BVH_Box.def("Clear", (void (BVH_Box<T, N>::*)()) &BVH_Box<T, N>::Clear, "Clears bounding box.");
cls_BVH_Box.def("IsValid", (Standard_Boolean (BVH_Box<T, N>::*)() const) &BVH_Box<T, N>::IsValid, "Is bounding box valid?");
cls_BVH_Box.def("Add", (void (BVH_Box<T, N>::*)(const typename BVH_Box<T, N>::BVH_VecNt &)) &BVH_Box<T, N>::Add, "Appends new point to the bounding box.", py::arg("thePoint"));
cls_BVH_Box.def("Combine", (void (BVH_Box<T, N>::*)(const BVH_Box<T, N> &)) &BVH_Box<T, N>::Combine, "Combines bounding box with another one.", py::arg("theBox"));
cls_BVH_Box.def("CornerMin", (const typename BVH_Box<T, N>::BVH_VecNt & (BVH_Box<T, N>::*)() const) &BVH_Box<T, N>::CornerMin, "Returns minimum point of bounding box.");
cls_BVH_Box.def("CornerMax", (const typename BVH_Box<T, N>::BVH_VecNt & (BVH_Box<T, N>::*)() const) &BVH_Box<T, N>::CornerMax, "Returns maximum point of bounding box.");
cls_BVH_Box.def("CornerMin", (typename BVH_Box<T, N>::BVH_VecNt & (BVH_Box<T, N>::*)()) &BVH_Box<T, N>::CornerMin, "Returns minimum point of bounding box.");
cls_BVH_Box.def("CornerMax", (typename BVH_Box<T, N>::BVH_VecNt & (BVH_Box<T, N>::*)()) &BVH_Box<T, N>::CornerMax, "Returns maximum point of bounding box.");
cls_BVH_Box.def("Area", (T (BVH_Box<T, N>::*)() const) &BVH_Box<T, N>::Area, "Returns surface area of bounding box. If the box is degenerated into line, returns the perimeter instead.");
cls_BVH_Box.def("Size", (typename BVH_Box<T, N>::BVH_VecNt (BVH_Box<T, N>::*)() const) &BVH_Box<T, N>::Size, "Returns diagonal of bounding box.");
cls_BVH_Box.def("Center", (typename BVH_Box<T, N>::BVH_VecNt (BVH_Box<T, N>::*)() const) &BVH_Box<T, N>::Center, "Returns center of bounding box.");
cls_BVH_Box.def("Center", (T (BVH_Box<T, N>::*)(const Standard_Integer) const) &BVH_Box<T, N>::Center, "Returns center of bounding box along the given axis.", py::arg("theAxis"));
cls_BVH_Box.def("DumpJson", [](BVH_Box<T, N> &self, Standard_OStream & a0) -> void { return self.DumpJson(a0); });
cls_BVH_Box.def("DumpJson", (void (BVH_Box<T, N>::*)(Standard_OStream &, const Standard_Integer) const) &BVH_Box<T, N>::DumpJson, "Dumps the content of me into the stream", py::arg("theOStream"), py::arg("theDepth"));
cls_BVH_Box.def("IsOut", (Standard_Boolean (BVH_Box<T, N>::*)(const BVH_Box<T, N> &) const) &BVH_Box<T, N>::IsOut, "Checks if the Box is out of the other box.", py::arg("theOther"));
cls_BVH_Box.def("IsOut", (Standard_Boolean (BVH_Box<T, N>::*)(const typename BVH_Box<T, N>::BVH_VecNt &, const typename BVH_Box<T, N>::BVH_VecNt &) const) &BVH_Box<T, N>::IsOut, "Checks if the Box is out of the other box defined by two points.", py::arg("theMinPoint"), py::arg("theMaxPoint"));
cls_BVH_Box.def("Contains", [](BVH_Box<T, N> &self, const BVH_Box<T, N> & theOther, Standard_Boolean & hasOverlap){ Standard_Boolean rv = self.Contains(theOther, hasOverlap); return std::tuple<Standard_Boolean, Standard_Boolean &>(rv, hasOverlap); }, "Checks if the Box fully contains the other box.", py::arg("theOther"), py::arg("hasOverlap"));
cls_BVH_Box.def("Contains", [](BVH_Box<T, N> &self, const typename BVH_Box<T, N>::BVH_VecNt & theMinPoint, const typename BVH_Box<T, N>::BVH_VecNt & theMaxPoint, Standard_Boolean & hasOverlap){ Standard_Boolean rv = self.Contains(theMinPoint, theMaxPoint, hasOverlap); return std::tuple<Standard_Boolean, Standard_Boolean &>(rv, hasOverlap); }, "Checks if the Box is fully contains the other box.", py::arg("theMinPoint"), py::arg("theMaxPoint"), py::arg("hasOverlap"));
cls_BVH_Box.def("IsOut", (Standard_Boolean (BVH_Box<T, N>::*)(const typename BVH_Box<T, N>::BVH_VecNt &) const) &BVH_Box<T, N>::IsOut, "Checks if the Point is out of the box.", py::arg("thePoint"));

}

#endif