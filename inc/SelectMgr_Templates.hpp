#ifndef __SelectMgr_Templates_Header__
#define __SelectMgr_Templates_Header__

#include <pyOCCT_Common.hpp>

#include <SelectMgr_BaseFrustum.hxx>
#include <SelectMgr_Frustum.hxx>

// C:\Miniconda\envs\occt\Library\include\opencascade\SelectMgr_Frustum.hxx
template <int N>
void bind_SelectMgr_Frustum(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\SelectMgr_Frustum.hxx
	py::class_<SelectMgr_Frustum<N>, opencascade::handle<SelectMgr_Frustum<N>>, SelectMgr_BaseFrustum> cls(mod, name.c_str(), "This is an internal class containing representation of rectangular selecting frustum, created in case of point and box selection, and algorithms for overlap detection between selecting frustum and sensitive entities. The principle of frustum calculation: - for point selection: on a near view frustum plane rectangular neighborhood of user-picked point is created according to the pixel tolerance given and then this rectangle is projected onto far view frustum plane. This rectangles define the parallel bases of selecting frustum; - for box selection: box points are projected onto near and far view frustum planes. These 2 projected rectangles define parallel bases of selecting frustum. Overlap detection tests are implemented according to the terms of separating axis theorem (SAT). Vertex order: - for triangular frustum: V0_Near, V1_Near, V2_Near, V0_Far, V1_Far, V2_Far; - for rectangular frustum: LeftTopNear, LeftTopFar, LeftBottomNear,LeftBottomFar, RightTopNear, RightTopFar, RightBottomNear, RightBottomFar. Plane order in array: - for triangular frustum: V0V1, V1V2, V0V2, Near, Far; - for rectangular frustum: Top, Bottom, Left, Right, Near, Far. Uncollinear edge directions order: - for rectangular frustum: Horizontal, Vertical, LeftLower, RightLower, LeftUpper, RightUpper; - for triangular frustum: V0_Near - V0_Far, V1_Near - V1_Far, V2_Near - V2_Far, V1_Near - V0_Near, V2_Near - V1_Near, V2_Near - V0_Near.");
	cls.def(py::init<>());

};

#endif