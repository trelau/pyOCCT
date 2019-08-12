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
#include <bind_SelectMgr_Frustum.hxx>
#include <SelectMgr_Frustum.hxx>
#include <gp_Pnt2d.hxx>
#include <Standard_Handle.hxx>
#include <SelectMgr_BaseFrustum.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_GTrsf.hxx>
#include <SelectMgr_VectorTypes.hxx>
#include <gp_Pnt.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <Select3D_TypeOfSensitivity.hxx>
#include <NCollection_Vector.hxx>
#include <SelectMgr_TriangularFrustum.hxx>
#include <Standard_Type.hxx>

void bind_SelectMgr_TriangularFrustum(py::module &mod){

bind_SelectMgr_Frustum<3>(mod, "Select_Mgr_Frustum3", py::module_local());

py::class_<SelectMgr_TriangularFrustum, opencascade::handle<SelectMgr_TriangularFrustum>, SelectMgr_Frustum<3>> cls_SelectMgr_TriangularFrustum(mod, "SelectMgr_TriangularFrustum", "This class contains representation of triangular selecting frustum, created in case of polyline selection, and algorithms for overlap detection between selecting frustum and sensitive entities. Overlap detection tests are implemented according to the terms of separating axis theorem (SAT).");

// Constructors
cls_SelectMgr_TriangularFrustum.def(py::init<>());

// Fields

// Methods
cls_SelectMgr_TriangularFrustum.def("Build", (void (SelectMgr_TriangularFrustum::*)(const gp_Pnt2d &, const gp_Pnt2d &, const gp_Pnt2d &)) &SelectMgr_TriangularFrustum::Build, "Creates new triangular frustum with bases of triangles with vertices theP1, theP2 and theP3 projections onto near and far view frustum planes (only for triangular frustums)", py::arg("theP1"), py::arg("theP2"), py::arg("theP3"));
cls_SelectMgr_TriangularFrustum.def("ScaleAndTransform", (opencascade::handle<SelectMgr_BaseFrustum> (SelectMgr_TriangularFrustum::*)(const Standard_Integer, const gp_GTrsf &) const) &SelectMgr_TriangularFrustum::ScaleAndTransform, "Returns a copy of the frustum transformed according to the matrix given", py::arg("theScale"), py::arg("theTrsf"));
cls_SelectMgr_TriangularFrustum.def("Overlaps", [](SelectMgr_TriangularFrustum &self, const SelectMgr_Vec3 & theMinPnt, const SelectMgr_Vec3 & theMaxPnt, Standard_Real & theDepth){ Standard_Boolean rv = self.Overlaps(theMinPnt, theMaxPnt, theDepth); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theDepth); }, "SAT intersection test between defined volume and given axis-aligned box", py::arg("theMinPnt"), py::arg("theMaxPnt"), py::arg("theDepth"));
cls_SelectMgr_TriangularFrustum.def("Overlaps", [](SelectMgr_TriangularFrustum &self, const SelectMgr_Vec3 & theMinPt, const SelectMgr_Vec3 & theMaxPt, Standard_Boolean * theInside){ Standard_Boolean rv = self.Overlaps(theMinPt, theMaxPt, theInside); return std::tuple<Standard_Boolean, Standard_Boolean *>(rv, theInside); }, "Returns true if selecting volume is overlapped by axis-aligned bounding box with minimum corner at point theMinPt and maximum at point theMaxPt", py::arg("theMinPt"), py::arg("theMaxPt"), py::arg("theInside"));
cls_SelectMgr_TriangularFrustum.def("Overlaps", [](SelectMgr_TriangularFrustum &self, const gp_Pnt & thePnt, Standard_Real & theDepth){ Standard_Boolean rv = self.Overlaps(thePnt, theDepth); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theDepth); }, "Intersection test between defined volume and given point", py::arg("thePnt"), py::arg("theDepth"));
cls_SelectMgr_TriangularFrustum.def("Overlaps", [](SelectMgr_TriangularFrustum &self, const TColgp_Array1OfPnt & theArrayOfPnts, Select3D_TypeOfSensitivity theSensType, Standard_Real & theDepth){ Standard_Boolean rv = self.Overlaps(theArrayOfPnts, theSensType, theDepth); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theDepth); }, "SAT intersection test between defined volume and given ordered set of points, representing line segments. The test may be considered of interior part or boundary line defined by segments depending on given sensitivity type", py::arg("theArrayOfPnts"), py::arg("theSensType"), py::arg("theDepth"));
cls_SelectMgr_TriangularFrustum.def("Overlaps", [](SelectMgr_TriangularFrustum &self, const gp_Pnt & thePnt1, const gp_Pnt & thePnt2, Standard_Real & theDepth){ Standard_Boolean rv = self.Overlaps(thePnt1, thePnt2, theDepth); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theDepth); }, "Checks if line segment overlaps selecting frustum", py::arg("thePnt1"), py::arg("thePnt2"), py::arg("theDepth"));
cls_SelectMgr_TriangularFrustum.def("Overlaps", [](SelectMgr_TriangularFrustum &self, const gp_Pnt & thePnt1, const gp_Pnt & thePnt2, const gp_Pnt & thePnt3, Select3D_TypeOfSensitivity theSensType, Standard_Real & theDepth){ Standard_Boolean rv = self.Overlaps(thePnt1, thePnt2, thePnt3, theSensType, theDepth); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theDepth); }, "SAT intersection test between defined volume and given triangle. The test may be considered of interior part or boundary line defined by triangle vertices depending on given sensitivity type", py::arg("thePnt1"), py::arg("thePnt2"), py::arg("thePnt3"), py::arg("theSensType"), py::arg("theDepth"));
cls_SelectMgr_TriangularFrustum.def("Clear", (void (SelectMgr_TriangularFrustum::*)()) &SelectMgr_TriangularFrustum::Clear, "Nullifies the handle to corresponding builder instance to prevent memory leaks");
cls_SelectMgr_TriangularFrustum.def("GetPlanes", (void (SelectMgr_TriangularFrustum::*)(NCollection_Vector<SelectMgr_Vec4> &) const) &SelectMgr_TriangularFrustum::GetPlanes, "Stores plane equation coefficients (in the following form: Ax + By + Cz + D = 0) to the given vector", py::arg("thePlaneEquations"));
cls_SelectMgr_TriangularFrustum.def_static("get_type_name_", (const char * (*)()) &SelectMgr_TriangularFrustum::get_type_name, "None");
cls_SelectMgr_TriangularFrustum.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &SelectMgr_TriangularFrustum::get_type_descriptor, "None");
cls_SelectMgr_TriangularFrustum.def("DynamicType", (const opencascade::handle<Standard_Type> & (SelectMgr_TriangularFrustum::*)() const) &SelectMgr_TriangularFrustum::DynamicType, "None");

// Enums

}