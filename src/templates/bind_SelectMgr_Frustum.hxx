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
#pragma once

#include <pyOCCT_Common.hxx>
#include <SelectMgr_BaseFrustum.hxx>
#include <Standard_TypeDef.hxx>
#include <SelectMgr_VectorTypes.hxx>
#include <gp_Pnt.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <gp_Vec.hxx>
#include <gp_XYZ.hxx>
#include <SelectMgr_Frustum.hxx>

template <int N>
void bind_SelectMgr_Frustum(py::module &mod, std::string const &name, py::module_local const &local){

py::class_<SelectMgr_Frustum<N>, opencascade::handle<SelectMgr_Frustum<N>>, SelectMgr_BaseFrustum> cls_SelectMgr_Frustum(mod, name.c_str(), "This is an internal class containing representation of rectangular selecting frustum, created in case of point and box selection, and algorithms for overlap detection between selecting frustum and sensitive entities. The principle of frustum calculation: - for point selection: on a near view frustum plane rectangular neighborhood of user-picked point is created according to the pixel tolerance given and then this rectangle is projected onto far view frustum plane. This rectangles define the parallel bases of selecting frustum; - for box selection: box points are projected onto near and far view frustum planes. These 2 projected rectangles define parallel bases of selecting frustum. Overlap detection tests are implemented according to the terms of separating axis theorem (SAT). Vertex order: - for triangular frustum: V0_Near, V1_Near, V2_Near, V0_Far, V1_Far, V2_Far; - for rectangular frustum: LeftTopNear, LeftTopFar, LeftBottomNear,LeftBottomFar, RightTopNear, RightTopFar, RightBottomNear, RightBottomFar. Plane order in array: - for triangular frustum: V0V1, V1V2, V0V2, Near, Far; - for rectangular frustum: Top, Bottom, Left, Right, Near, Far. Uncollinear edge directions order: - for rectangular frustum: Horizontal, Vertical, LeftLower, RightLower, LeftUpper, RightUpper; - for triangular frustum: V0_Near - V0_Far, V1_Near - V1_Far, V2_Near - V2_Far, V1_Near - V0_Near, V2_Near - V1_Near, V2_Near - V0_Near.", local);

// Constructors
cls_SelectMgr_Frustum.def(py::init<>());

}
