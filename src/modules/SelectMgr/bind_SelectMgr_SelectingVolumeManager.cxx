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
#include <SelectBasics_SelectingVolumeManager.hxx>
#include <Standard_TypeDef.hxx>
#include <SelectMgr_SelectingVolumeManager.hxx>
#include <gp_GTrsf.hxx>
#include <Standard_Handle.hxx>
#include <SelectMgr_FrustumBuilder.hxx>
#include <Graphic3d_Camera.hxx>
#include <Graphic3d_Mat4d.hxx>
#include <Graphic3d_WorldViewProjState.hxx>
#include <gp_Pnt2d.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <SelectMgr_VectorTypes.hxx>
#include <gp_Pnt.hxx>
#include <TColgp_HArray1OfPnt.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <Graphic3d_SequenceOfHClipPlane.hxx>
#include <SelectMgr_BaseFrustum.hxx>
#include <NCollection_Vector.hxx>

void bind_SelectMgr_SelectingVolumeManager(py::module &mod){

py::class_<SelectMgr_SelectingVolumeManager, std::unique_ptr<SelectMgr_SelectingVolumeManager>, SelectBasics_SelectingVolumeManager> cls_SelectMgr_SelectingVolumeManager(mod, "SelectMgr_SelectingVolumeManager", "This class is used to switch between active selecting volumes depending on selection type chosen by the user");

// Constructors
cls_SelectMgr_SelectingVolumeManager.def(py::init<>());
cls_SelectMgr_SelectingVolumeManager.def(py::init<Standard_Boolean>(), py::arg("theToAllocateFrustums"));

// Fields

// Methods
cls_SelectMgr_SelectingVolumeManager.def("ScaleAndTransform", [](SelectMgr_SelectingVolumeManager &self, const Standard_Integer a0, const gp_GTrsf & a1) -> SelectMgr_SelectingVolumeManager { return self.ScaleAndTransform(a0, a1); });
cls_SelectMgr_SelectingVolumeManager.def("ScaleAndTransform", (SelectMgr_SelectingVolumeManager (SelectMgr_SelectingVolumeManager::*)(const Standard_Integer, const gp_GTrsf &, const opencascade::handle<SelectMgr_FrustumBuilder> &) const) &SelectMgr_SelectingVolumeManager::ScaleAndTransform, "IMPORTANT: Scaling makes sense only for frustum built on a single point! Note that this method does not perform any checks on type of the frustum.", py::arg("theScaleFactor"), py::arg("theTrsf"), py::arg("theBuilder"));
cls_SelectMgr_SelectingVolumeManager.def("GetActiveSelectionType", (Standard_Integer (SelectMgr_SelectingVolumeManager::*)() const) &SelectMgr_SelectingVolumeManager::GetActiveSelectionType, "None");
cls_SelectMgr_SelectingVolumeManager.def("SetActiveSelectionType", (void (SelectMgr_SelectingVolumeManager::*)(const SelectBasics_SelectingVolumeManager::SelectionType &)) &SelectMgr_SelectingVolumeManager::SetActiveSelectionType, "None", py::arg("theType"));
cls_SelectMgr_SelectingVolumeManager.def("Camera", (const opencascade::handle<Graphic3d_Camera> & (SelectMgr_SelectingVolumeManager::*)() const) &SelectMgr_SelectingVolumeManager::Camera, "Returns current camera definition.");
cls_SelectMgr_SelectingVolumeManager.def("SetCamera", (void (SelectMgr_SelectingVolumeManager::*)(const opencascade::handle<Graphic3d_Camera>)) &SelectMgr_SelectingVolumeManager::SetCamera, "Updates camera projection and orientation matrices in all selecting volumes", py::arg("theCamera"));
cls_SelectMgr_SelectingVolumeManager.def("SetCamera", [](SelectMgr_SelectingVolumeManager &self, const Graphic3d_Mat4d & a0, const Graphic3d_Mat4d & a1, const Standard_Boolean a2) -> void { return self.SetCamera(a0, a1, a2); });
cls_SelectMgr_SelectingVolumeManager.def("SetCamera", (void (SelectMgr_SelectingVolumeManager::*)(const Graphic3d_Mat4d &, const Graphic3d_Mat4d &, const Standard_Boolean, const Graphic3d_WorldViewProjState &)) &SelectMgr_SelectingVolumeManager::SetCamera, "Updates camera projection and orientation matrices in all selecting volumes", py::arg("theProjection"), py::arg("theWorldView"), py::arg("theIsOrthographic"), py::arg("theWVPState"));
cls_SelectMgr_SelectingVolumeManager.def("ProjectionMatrix", (const Graphic3d_Mat4d & (SelectMgr_SelectingVolumeManager::*)() const) &SelectMgr_SelectingVolumeManager::ProjectionMatrix, "Returns current projection transformation common for all selecting volumes");
cls_SelectMgr_SelectingVolumeManager.def("WorldViewMatrix", (const Graphic3d_Mat4d & (SelectMgr_SelectingVolumeManager::*)() const) &SelectMgr_SelectingVolumeManager::WorldViewMatrix, "Returns current world view transformation common for all selecting volumes");
cls_SelectMgr_SelectingVolumeManager.def("WindowSize", [](SelectMgr_SelectingVolumeManager &self, Standard_Integer & theWidth, Standard_Integer & theHeight){ self.WindowSize(theWidth, theHeight); return std::tuple<Standard_Integer &, Standard_Integer &>(theWidth, theHeight); }, "None", py::arg("theWidth"), py::arg("theHeight"));
cls_SelectMgr_SelectingVolumeManager.def("WorldViewProjState", (const Graphic3d_WorldViewProjState & (SelectMgr_SelectingVolumeManager::*)() const) &SelectMgr_SelectingVolumeManager::WorldViewProjState, "Returns current camera world view projection transformation state common for all selecting volumes");
cls_SelectMgr_SelectingVolumeManager.def("SetViewport", (void (SelectMgr_SelectingVolumeManager::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &SelectMgr_SelectingVolumeManager::SetViewport, "Updates viewport in all selecting volumes", py::arg("theX"), py::arg("theY"), py::arg("theWidth"), py::arg("theHeight"));
cls_SelectMgr_SelectingVolumeManager.def("SetPixelTolerance", (void (SelectMgr_SelectingVolumeManager::*)(const Standard_Integer)) &SelectMgr_SelectingVolumeManager::SetPixelTolerance, "Updates pixel tolerance in all selecting volumes", py::arg("theTolerance"));
cls_SelectMgr_SelectingVolumeManager.def("SetWindowSize", (void (SelectMgr_SelectingVolumeManager::*)(const Standard_Integer, const Standard_Integer)) &SelectMgr_SelectingVolumeManager::SetWindowSize, "Updates window size in all selecting volumes", py::arg("theWidth"), py::arg("theHeight"));
cls_SelectMgr_SelectingVolumeManager.def("BuildSelectingVolume", (void (SelectMgr_SelectingVolumeManager::*)(const gp_Pnt2d &)) &SelectMgr_SelectingVolumeManager::BuildSelectingVolume, "Builds rectangular selecting frustum for point selection", py::arg("thePoint"));
cls_SelectMgr_SelectingVolumeManager.def("BuildSelectingVolume", (void (SelectMgr_SelectingVolumeManager::*)(const gp_Pnt2d &, const gp_Pnt2d &)) &SelectMgr_SelectingVolumeManager::BuildSelectingVolume, "Builds rectangular selecting frustum for box selection", py::arg("theMinPt"), py::arg("theMaxPt"));
cls_SelectMgr_SelectingVolumeManager.def("BuildSelectingVolume", (void (SelectMgr_SelectingVolumeManager::*)(const TColgp_Array1OfPnt2d &)) &SelectMgr_SelectingVolumeManager::BuildSelectingVolume, "Builds set of triangular selecting frustums for polyline selection", py::arg("thePoints"));
cls_SelectMgr_SelectingVolumeManager.def("Overlaps", [](SelectMgr_SelectingVolumeManager &self, const SelectMgr_Vec3 & theBoxMin, const SelectMgr_Vec3 & theBoxMax, Standard_Real & theDepth){ Standard_Boolean rv = self.Overlaps(theBoxMin, theBoxMax, theDepth); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theDepth); }, "SAT intersection test between defined volume and given axis-aligned box", py::arg("theBoxMin"), py::arg("theBoxMax"), py::arg("theDepth"));
cls_SelectMgr_SelectingVolumeManager.def("Overlaps", [](SelectMgr_SelectingVolumeManager &self, const SelectMgr_Vec3 & theBoxMin, const SelectMgr_Vec3 & theBoxMax, Standard_Boolean * theInside){ Standard_Boolean rv = self.Overlaps(theBoxMin, theBoxMax, theInside); return std::tuple<Standard_Boolean, Standard_Boolean *>(rv, theInside); }, "Returns true if selecting volume is overlapped by axis-aligned bounding box with minimum corner at point theMinPt and maximum at point theMaxPt", py::arg("theBoxMin"), py::arg("theBoxMax"), py::arg("theInside"));
cls_SelectMgr_SelectingVolumeManager.def("Overlaps", [](SelectMgr_SelectingVolumeManager &self, const gp_Pnt & thePnt, Standard_Real & theDepth){ Standard_Boolean rv = self.Overlaps(thePnt, theDepth); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theDepth); }, "Intersection test between defined volume and given point", py::arg("thePnt"), py::arg("theDepth"));
cls_SelectMgr_SelectingVolumeManager.def("Overlaps", (Standard_Boolean (SelectMgr_SelectingVolumeManager::*)(const gp_Pnt &)) &SelectMgr_SelectingVolumeManager::Overlaps, "Intersection test between defined volume and given point", py::arg("thePnt"));
cls_SelectMgr_SelectingVolumeManager.def("Overlaps", [](SelectMgr_SelectingVolumeManager &self, const opencascade::handle<TColgp_HArray1OfPnt> & theArrayOfPts, Standard_Integer theSensType, Standard_Real & theDepth){ Standard_Boolean rv = self.Overlaps(theArrayOfPts, theSensType, theDepth); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theDepth); }, "SAT intersection test between defined volume and given ordered set of points, representing line segments. The test may be considered of interior part or boundary line defined by segments depending on given sensitivity type", py::arg("theArrayOfPts"), py::arg("theSensType"), py::arg("theDepth"));
cls_SelectMgr_SelectingVolumeManager.def("Overlaps", [](SelectMgr_SelectingVolumeManager &self, const TColgp_Array1OfPnt & theArrayOfPts, Standard_Integer theSensType, Standard_Real & theDepth){ Standard_Boolean rv = self.Overlaps(theArrayOfPts, theSensType, theDepth); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theDepth); }, "SAT intersection test between defined volume and given ordered set of points, representing line segments. The test may be considered of interior part or boundary line defined by segments depending on given sensitivity type", py::arg("theArrayOfPts"), py::arg("theSensType"), py::arg("theDepth"));
cls_SelectMgr_SelectingVolumeManager.def("Overlaps", [](SelectMgr_SelectingVolumeManager &self, const gp_Pnt & thePnt1, const gp_Pnt & thePnt2, Standard_Real & theDepth){ Standard_Boolean rv = self.Overlaps(thePnt1, thePnt2, theDepth); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theDepth); }, "Checks if line segment overlaps selecting frustum", py::arg("thePnt1"), py::arg("thePnt2"), py::arg("theDepth"));
cls_SelectMgr_SelectingVolumeManager.def("Overlaps", [](SelectMgr_SelectingVolumeManager &self, const gp_Pnt & thePnt1, const gp_Pnt & thePnt2, const gp_Pnt & thePnt3, Standard_Integer theSensType, Standard_Real & theDepth){ Standard_Boolean rv = self.Overlaps(thePnt1, thePnt2, thePnt3, theSensType, theDepth); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theDepth); }, "SAT intersection test between defined volume and given triangle. The test may be considered of interior part or boundary line defined by triangle vertices depending on given sensitivity type", py::arg("thePnt1"), py::arg("thePnt2"), py::arg("thePnt3"), py::arg("theSensType"), py::arg("theDepth"));
cls_SelectMgr_SelectingVolumeManager.def("DistToGeometryCenter", (Standard_Real (SelectMgr_SelectingVolumeManager::*)(const gp_Pnt &)) &SelectMgr_SelectingVolumeManager::DistToGeometryCenter, "Measures distance between 3d projection of user-picked screen point and given point theCOG", py::arg("theCOG"));
cls_SelectMgr_SelectingVolumeManager.def("DetectedPoint", (gp_Pnt (SelectMgr_SelectingVolumeManager::*)(const Standard_Real) const) &SelectMgr_SelectingVolumeManager::DetectedPoint, "Calculates the point on a view ray that was detected during the run of selection algo by given depth. Throws exception if active selection type is not Point.", py::arg("theDepth"));
cls_SelectMgr_SelectingVolumeManager.def("IsClipped", (Standard_Boolean (SelectMgr_SelectingVolumeManager::*)(const Graphic3d_SequenceOfHClipPlane &, const Standard_Real &)) &SelectMgr_SelectingVolumeManager::IsClipped, "Checks if the point of sensitive in which selection was detected belongs to the region defined by clipping planes", py::arg("thePlanes"), py::arg("theDepth"));
cls_SelectMgr_SelectingVolumeManager.def("AllowOverlapDetection", (void (SelectMgr_SelectingVolumeManager::*)(const Standard_Boolean)) &SelectMgr_SelectingVolumeManager::AllowOverlapDetection, "Is used for rectangular selection only If theIsToAllow is false, only fully included sensitives will be detected, otherwise the algorithm will mark both included and overlapped entities as matched", py::arg("theIsToAllow"));
cls_SelectMgr_SelectingVolumeManager.def("IsOverlapAllowed", (Standard_Boolean (SelectMgr_SelectingVolumeManager::*)() const) &SelectMgr_SelectingVolumeManager::IsOverlapAllowed, "None");
cls_SelectMgr_SelectingVolumeManager.def("ViewClipping", (const opencascade::handle<Graphic3d_SequenceOfHClipPlane> & (SelectMgr_SelectingVolumeManager::*)() const) &SelectMgr_SelectingVolumeManager::ViewClipping, "Return view clipping planes.");
cls_SelectMgr_SelectingVolumeManager.def("SetViewClipping", (void (SelectMgr_SelectingVolumeManager::*)(const opencascade::handle<Graphic3d_SequenceOfHClipPlane> &)) &SelectMgr_SelectingVolumeManager::SetViewClipping, "Valid for point selection only! Computes depth range for global (defined for the whole view) clipping planes.", py::arg("thePlanes"));
cls_SelectMgr_SelectingVolumeManager.def("SetViewClippingEnabled", (Standard_Boolean (SelectMgr_SelectingVolumeManager::*)(const Standard_Boolean)) &SelectMgr_SelectingVolumeManager::SetViewClippingEnabled, "Set if view clipping plane is enabled or not.", py::arg("theToEnable"));
cls_SelectMgr_SelectingVolumeManager.def("GetVertices", (const gp_Pnt * (SelectMgr_SelectingVolumeManager::*)() const) &SelectMgr_SelectingVolumeManager::GetVertices, "A set of helper functions that return rectangular selecting frustum data");
cls_SelectMgr_SelectingVolumeManager.def("GetNearPickedPnt", (gp_Pnt (SelectMgr_SelectingVolumeManager::*)() const) &SelectMgr_SelectingVolumeManager::GetNearPickedPnt, "Valid only for point and rectangular selection. Returns projection of 2d mouse picked point or projection of center of 2d rectangle (for point and rectangular selection correspondingly) onto near view frustum plane");
cls_SelectMgr_SelectingVolumeManager.def("GetFarPickedPnt", (gp_Pnt (SelectMgr_SelectingVolumeManager::*)() const) &SelectMgr_SelectingVolumeManager::GetFarPickedPnt, "Valid only for point and rectangular selection. Returns projection of 2d mouse picked point or projection of center of 2d rectangle (for point and rectangular selection correspondingly) onto far view frustum plane");
cls_SelectMgr_SelectingVolumeManager.def("ActiveVolume", (opencascade::handle<SelectMgr_BaseFrustum> (SelectMgr_SelectingVolumeManager::*)() const) &SelectMgr_SelectingVolumeManager::ActiveVolume, "Returns active selecting volume that was built during last run of OCCT selection mechanism");
cls_SelectMgr_SelectingVolumeManager.def("GetPlanes", (void (SelectMgr_SelectingVolumeManager::*)(NCollection_Vector<SelectMgr_Vec4> &) const) &SelectMgr_SelectingVolumeManager::GetPlanes, "Stores plane equation coefficients (in the following form: Ax + By + Cz + D = 0) to the given vector", py::arg("thePlaneEquations"));

// Enums

}