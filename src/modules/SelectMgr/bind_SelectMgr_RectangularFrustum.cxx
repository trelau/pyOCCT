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
#include <Graphic3d_SequenceOfHClipPlane.hxx>
#include <NCollection_Vector.hxx>
#include <gp_Vec.hxx>
#include <SelectMgr_RectangularFrustum.hxx>
#include <SelectMgr_ViewClipRange.hxx>

void bind_SelectMgr_RectangularFrustum(py::module &mod){

bind_SelectMgr_Frustum<4>(mod, "Select_Mgr_Frustum4", py::module_local());

py::class_<SelectMgr_RectangularFrustum, opencascade::handle<SelectMgr_RectangularFrustum>, SelectMgr_Frustum<4>> cls_SelectMgr_RectangularFrustum(mod, "SelectMgr_RectangularFrustum", "This class contains representation of rectangular selecting frustum, created in case of point and box selection, and algorithms for overlap detection between selecting frustum and sensitive entities. The principle of frustum calculation: - for point selection: on a near view frustum plane rectangular neighborhood of user-picked point is created according to the pixel tolerance given and then this rectangle is projected onto far view frustum plane. This rectangles define the parallel bases of selecting frustum; - for box selection: box points are projected onto near and far view frustum planes. These 2 projected rectangles define parallel bases of selecting frustum. Overlap detection tests are implemented according to the terms of separating axis theorem (SAT).");

// Constructors
cls_SelectMgr_RectangularFrustum.def(py::init<>());

// Fields

// Methods
cls_SelectMgr_RectangularFrustum.def("Build", (void (SelectMgr_RectangularFrustum::*)(const gp_Pnt2d &)) &SelectMgr_RectangularFrustum::Build, "Builds volume according to the point and given pixel tolerance", py::arg("thePoint"));
cls_SelectMgr_RectangularFrustum.def("Build", (void (SelectMgr_RectangularFrustum::*)(const gp_Pnt2d &, const gp_Pnt2d &)) &SelectMgr_RectangularFrustum::Build, "Builds volume according to the selected rectangle", py::arg("theMinPnt"), py::arg("theMaxPnt"));
cls_SelectMgr_RectangularFrustum.def("ScaleAndTransform", (opencascade::handle<SelectMgr_BaseFrustum> (SelectMgr_RectangularFrustum::*)(const Standard_Integer, const gp_GTrsf &) const) &SelectMgr_RectangularFrustum::ScaleAndTransform, "IMPORTANT: Scaling makes sense only for frustum built on a single point! Note that this method does not perform any checks on type of the frustum. Returns a copy of the frustum resized according to the scale factor given and transforms it using the matrix given. There are no default parameters, but in case if: - transformation only is needed: must be initialized as any negative value; - scale only is needed: must be set to gp_Identity.", py::arg("theScaleFactor"), py::arg("theTrsf"));
cls_SelectMgr_RectangularFrustum.def("Overlaps", [](SelectMgr_RectangularFrustum &self, const SelectMgr_Vec3 & theBoxMin, const SelectMgr_Vec3 & theBoxMax, Standard_Real & theDepth){ Standard_Boolean rv = self.Overlaps(theBoxMin, theBoxMax, theDepth); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theDepth); }, "SAT intersection test between defined volume and given axis-aligned box", py::arg("theBoxMin"), py::arg("theBoxMax"), py::arg("theDepth"));
cls_SelectMgr_RectangularFrustum.def("Overlaps", [](SelectMgr_RectangularFrustum &self, const SelectMgr_Vec3 & theBoxMin, const SelectMgr_Vec3 & theBoxMax, Standard_Boolean * theInside){ Standard_Boolean rv = self.Overlaps(theBoxMin, theBoxMax, theInside); return std::tuple<Standard_Boolean, Standard_Boolean *>(rv, theInside); }, "Returns true if selecting volume is overlapped by axis-aligned bounding box with minimum corner at point theMinPt and maximum at point theMaxPt", py::arg("theBoxMin"), py::arg("theBoxMax"), py::arg("theInside"));
cls_SelectMgr_RectangularFrustum.def("Overlaps", [](SelectMgr_RectangularFrustum &self, const gp_Pnt & thePnt, Standard_Real & theDepth){ Standard_Boolean rv = self.Overlaps(thePnt, theDepth); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theDepth); }, "Intersection test between defined volume and given point", py::arg("thePnt"), py::arg("theDepth"));
cls_SelectMgr_RectangularFrustum.def("Overlaps", (Standard_Boolean (SelectMgr_RectangularFrustum::*)(const gp_Pnt &)) &SelectMgr_RectangularFrustum::Overlaps, "Intersection test between defined volume and given point", py::arg("thePnt"));
cls_SelectMgr_RectangularFrustum.def("Overlaps", [](SelectMgr_RectangularFrustum &self, const TColgp_Array1OfPnt & theArrayOfPnts, Select3D_TypeOfSensitivity theSensType, Standard_Real & theDepth){ Standard_Boolean rv = self.Overlaps(theArrayOfPnts, theSensType, theDepth); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theDepth); }, "SAT intersection test between defined volume and given ordered set of points, representing line segments. The test may be considered of interior part or boundary line defined by segments depending on given sensitivity type", py::arg("theArrayOfPnts"), py::arg("theSensType"), py::arg("theDepth"));
cls_SelectMgr_RectangularFrustum.def("Overlaps", [](SelectMgr_RectangularFrustum &self, const gp_Pnt & thePnt1, const gp_Pnt & thePnt2, Standard_Real & theDepth){ Standard_Boolean rv = self.Overlaps(thePnt1, thePnt2, theDepth); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theDepth); }, "Checks if line segment overlaps selecting frustum", py::arg("thePnt1"), py::arg("thePnt2"), py::arg("theDepth"));
cls_SelectMgr_RectangularFrustum.def("Overlaps", [](SelectMgr_RectangularFrustum &self, const gp_Pnt & thePnt1, const gp_Pnt & thePnt2, const gp_Pnt & thePnt3, Select3D_TypeOfSensitivity theSensType, Standard_Real & theDepth){ Standard_Boolean rv = self.Overlaps(thePnt1, thePnt2, thePnt3, theSensType, theDepth); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theDepth); }, "SAT intersection test between defined volume and given triangle. The test may be considered of interior part or boundary line defined by triangle vertices depending on given sensitivity type", py::arg("thePnt1"), py::arg("thePnt2"), py::arg("thePnt3"), py::arg("theSensType"), py::arg("theDepth"));
cls_SelectMgr_RectangularFrustum.def("DistToGeometryCenter", (Standard_Real (SelectMgr_RectangularFrustum::*)(const gp_Pnt &)) &SelectMgr_RectangularFrustum::DistToGeometryCenter, "Measures distance between 3d projection of user-picked screen point and given point theCOG", py::arg("theCOG"));
cls_SelectMgr_RectangularFrustum.def("DetectedPoint", (gp_Pnt (SelectMgr_RectangularFrustum::*)(const Standard_Real) const) &SelectMgr_RectangularFrustum::DetectedPoint, "Calculates the point on a view ray that was detected during the run of selection algo by given depth", py::arg("theDepth"));
cls_SelectMgr_RectangularFrustum.def("IsClipped", (Standard_Boolean (SelectMgr_RectangularFrustum::*)(const Graphic3d_SequenceOfHClipPlane &, const Standard_Real)) &SelectMgr_RectangularFrustum::IsClipped, "Checks if the point of sensitive in which selection was detected belongs to the region defined by clipping planes", py::arg("thePlanes"), py::arg("theDepth"));
cls_SelectMgr_RectangularFrustum.def("SetViewClipping", (void (SelectMgr_RectangularFrustum::*)(const opencascade::handle<Graphic3d_SequenceOfHClipPlane> &)) &SelectMgr_RectangularFrustum::SetViewClipping, "Valid for point selection only! Computes depth range for global (defined for the whole view) clipping planes.", py::arg("thePlanes"));
cls_SelectMgr_RectangularFrustum.def("SetViewClippingEnabled", (Standard_Boolean (SelectMgr_RectangularFrustum::*)(const Standard_Boolean)) &SelectMgr_RectangularFrustum::SetViewClippingEnabled, "Set if view clipping plane is enabled or not.", py::arg("theToEnable"));
cls_SelectMgr_RectangularFrustum.def("GetVertices", (const gp_Pnt * (SelectMgr_RectangularFrustum::*)() const) &SelectMgr_RectangularFrustum::GetVertices, "A set of helper functions that return rectangular selecting frustum data");
cls_SelectMgr_RectangularFrustum.def("GetNearPnt", (const gp_Pnt & (SelectMgr_RectangularFrustum::*)() const) &SelectMgr_RectangularFrustum::GetNearPnt, "Returns projection of 2d mouse picked point or projection of center of 2d rectangle (for point and rectangular selection correspondingly) onto near view frustum plane");
cls_SelectMgr_RectangularFrustum.def("GetFarPnt", (const gp_Pnt & (SelectMgr_RectangularFrustum::*)() const) &SelectMgr_RectangularFrustum::GetFarPnt, "Returns projection of 2d mouse picked point or projection of center of 2d rectangle (for point and rectangular selection correspondingly) onto far view frustum plane");
cls_SelectMgr_RectangularFrustum.def("GetPlanes", (void (SelectMgr_RectangularFrustum::*)(NCollection_Vector<SelectMgr_Vec4> &) const) &SelectMgr_RectangularFrustum::GetPlanes, "Stores plane equation coefficients (in the following form: Ax + By + Cz + D = 0) to the given vector", py::arg("thePlaneEquations"));

// Enums

}