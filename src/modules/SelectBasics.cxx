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
#include <SelectBasics_PickResult.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <NCollection_Vec3.hxx>
#include <Standard_Handle.hxx>
#include <TColgp_HArray1OfPnt.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <gp_Pnt2d.hxx>
#include <NCollection_Vector.hxx>
#include <NCollection_Vec4.hxx>
#include <SelectBasics_SelectingVolumeManager.hxx>
#include <SelectBasics.hxx>

PYBIND11_MODULE(SelectBasics, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.gp");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TColgp");

struct ImportSelect3D{
	ImportSelect3D() { py::module::import("OCCT.Select3D"); }
};

// CLASS: SELECTBASICS_PICKRESULT
py::class_<SelectBasics_PickResult> cls_SelectBasics_PickResult(mod, "SelectBasics_PickResult", "This structure provides unified access to the results of Matches() method in all sensitive entities, so that it defines a Depth (distance to the entity along picking ray) and a closest Point on entity.");

// Constructors
cls_SelectBasics_PickResult.def(py::init<>());
cls_SelectBasics_PickResult.def(py::init<Standard_Real, Standard_Real, const gp_Pnt &>(), py::arg("theDepth"), py::arg("theDistToCenter"), py::arg("theObjPickedPnt"));

// Methods
cls_SelectBasics_PickResult.def_static("Min_", (const SelectBasics_PickResult & (*)(const SelectBasics_PickResult &, const SelectBasics_PickResult &)) &SelectBasics_PickResult::Min, "Return closest result between two Pick Results according to Depth value.", py::arg("thePickResult1"), py::arg("thePickResult2"));
cls_SelectBasics_PickResult.def("IsValid", (Standard_Boolean (SelectBasics_PickResult::*)() const) &SelectBasics_PickResult::IsValid, "Return TRUE if result was been defined.");
cls_SelectBasics_PickResult.def("Invalidate", (void (SelectBasics_PickResult::*)()) &SelectBasics_PickResult::Invalidate, "Reset depth value.");
cls_SelectBasics_PickResult.def("Depth", (Standard_Real (SelectBasics_PickResult::*)() const) &SelectBasics_PickResult::Depth, "Return depth along picking ray.");
cls_SelectBasics_PickResult.def("SetDepth", (void (SelectBasics_PickResult::*)(Standard_Real)) &SelectBasics_PickResult::SetDepth, "Set depth along picking ray.", py::arg("theDepth"));
cls_SelectBasics_PickResult.def("HasPickedPoint", (Standard_Boolean (SelectBasics_PickResult::*)() const) &SelectBasics_PickResult::HasPickedPoint, "Return TRUE if Picked Point lying on detected entity was set.");
cls_SelectBasics_PickResult.def("PickedPoint", (const gp_Pnt & (SelectBasics_PickResult::*)() const) &SelectBasics_PickResult::PickedPoint, "Return picked point lying on detected entity. WARNING! Point is defined in local coordinate system and should be translated into World System before usage!");
cls_SelectBasics_PickResult.def("SetPickedPoint", (void (SelectBasics_PickResult::*)(const gp_Pnt &)) &SelectBasics_PickResult::SetPickedPoint, "Set picked point.", py::arg("theObjPickedPnt"));
cls_SelectBasics_PickResult.def("DistToGeomCenter", (Standard_Real (SelectBasics_PickResult::*)() const) &SelectBasics_PickResult::DistToGeomCenter, "Return distance to geometry center (auxiliary value for comparing results).");
cls_SelectBasics_PickResult.def("SetDistToGeomCenter", (void (SelectBasics_PickResult::*)(Standard_Real)) &SelectBasics_PickResult::SetDistToGeomCenter, "Set distance to geometry center.", py::arg("theDistToCenter"));

// CLASS: SELECTBASICS_SELECTINGVOLUMEMANAGER
py::class_<SelectBasics_SelectingVolumeManager> cls_SelectBasics_SelectingVolumeManager(mod, "SelectBasics_SelectingVolumeManager", "This class provides an interface for selecting volume manager, which is responsible for all overlap detection methods and calculation of minimum depth, distance to center of geometry and detected closest point on entity.");

// Methods
cls_SelectBasics_SelectingVolumeManager.def("GetActiveSelectionType", (Standard_Integer (SelectBasics_SelectingVolumeManager::*)() const) &SelectBasics_SelectingVolumeManager::GetActiveSelectionType, "None");
cls_SelectBasics_SelectingVolumeManager.def("Overlaps", (Standard_Boolean (SelectBasics_SelectingVolumeManager::*)(const NCollection_Vec3<Standard_Real> &, const NCollection_Vec3<Standard_Real> &, SelectBasics_PickResult &) const) &SelectBasics_SelectingVolumeManager::Overlaps, "Returns true if selecting volume is overlapped by box theBox", py::arg("theBoxMin"), py::arg("theBoxMax"), py::arg("thePickResult"));
cls_SelectBasics_SelectingVolumeManager.def("Overlaps", [](SelectBasics_SelectingVolumeManager &self, const NCollection_Vec3<Standard_Real> & theBoxMin, const NCollection_Vec3<Standard_Real> & theBoxMax, Standard_Boolean * theInside){ Standard_Boolean rv = self.Overlaps(theBoxMin, theBoxMax, theInside); return std::tuple<Standard_Boolean, Standard_Boolean *>(rv, theInside); }, "Returns true if selecting volume is overlapped by axis-aligned bounding box with minimum corner at point theMinPt and maximum at point theMaxPt", py::arg("theBoxMin"), py::arg("theBoxMax"), py::arg("theInside"));
cls_SelectBasics_SelectingVolumeManager.def("Overlaps", (Standard_Boolean (SelectBasics_SelectingVolumeManager::*)(const gp_Pnt &, SelectBasics_PickResult &) const) &SelectBasics_SelectingVolumeManager::Overlaps, "Returns true if selecting volume is overlapped by point thePnt", py::arg("thePnt"), py::arg("thePickResult"));
cls_SelectBasics_SelectingVolumeManager.def("Overlaps", (Standard_Boolean (SelectBasics_SelectingVolumeManager::*)(const gp_Pnt &) const) &SelectBasics_SelectingVolumeManager::Overlaps, "Returns true if selecting volume is overlapped by point thePnt. Does not perform depth calculation, so this method is defined as helper function for inclusion test.", py::arg("thePnt"));
cls_SelectBasics_SelectingVolumeManager.def("Overlaps", (Standard_Boolean (SelectBasics_SelectingVolumeManager::*)(const opencascade::handle<TColgp_HArray1OfPnt> &, Standard_Integer, SelectBasics_PickResult &) const) &SelectBasics_SelectingVolumeManager::Overlaps, "Returns true if selecting volume is overlapped by planar convex polygon, which points are stored in theArrayOfPts, taking into account sensitivity type theSensType", py::arg("theArrayOfPts"), py::arg("theSensType"), py::arg("thePickResult"));
cls_SelectBasics_SelectingVolumeManager.def("Overlaps", (Standard_Boolean (SelectBasics_SelectingVolumeManager::*)(const TColgp_Array1OfPnt &, Standard_Integer, SelectBasics_PickResult &) const) &SelectBasics_SelectingVolumeManager::Overlaps, "Returns true if selecting volume is overlapped by planar convex polygon, which points are stored in theArrayOfPts, taking into account sensitivity type theSensType", py::arg("theArrayOfPts"), py::arg("theSensType"), py::arg("thePickResult"));
cls_SelectBasics_SelectingVolumeManager.def("Overlaps", (Standard_Boolean (SelectBasics_SelectingVolumeManager::*)(const gp_Pnt &, const gp_Pnt &, SelectBasics_PickResult &) const) &SelectBasics_SelectingVolumeManager::Overlaps, "Returns true if selecting volume is overlapped by line segment with start point at thePt1 and end point at thePt2", py::arg("thePt1"), py::arg("thePt2"), py::arg("thePickResult"));
cls_SelectBasics_SelectingVolumeManager.def("Overlaps", (Standard_Boolean (SelectBasics_SelectingVolumeManager::*)(const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, Standard_Integer, SelectBasics_PickResult &) const) &SelectBasics_SelectingVolumeManager::Overlaps, "Returns true if selecting volume is overlapped by triangle with vertices thePt1, thePt2 and thePt3, taking into account sensitivity type theSensType", py::arg("thePt1"), py::arg("thePt2"), py::arg("thePt3"), py::arg("theSensType"), py::arg("thePickResult"));
cls_SelectBasics_SelectingVolumeManager.def("DistToGeometryCenter", (Standard_Real (SelectBasics_SelectingVolumeManager::*)(const gp_Pnt &) const) &SelectBasics_SelectingVolumeManager::DistToGeometryCenter, "Calculates distance from 3d projection of user-defined selection point to the given point theCOG", py::arg("theCOG"));
cls_SelectBasics_SelectingVolumeManager.def("DetectedPoint", (gp_Pnt (SelectBasics_SelectingVolumeManager::*)(const Standard_Real) const) &SelectBasics_SelectingVolumeManager::DetectedPoint, "None", py::arg("theDepth"));
cls_SelectBasics_SelectingVolumeManager.def("IsOverlapAllowed", (Standard_Boolean (SelectBasics_SelectingVolumeManager::*)() const) &SelectBasics_SelectingVolumeManager::IsOverlapAllowed, "None");
cls_SelectBasics_SelectingVolumeManager.def("GetNearPickedPnt", (gp_Pnt (SelectBasics_SelectingVolumeManager::*)() const) &SelectBasics_SelectingVolumeManager::GetNearPickedPnt, "Valid only for point and rectangular selection. Returns projection of 2d mouse picked point or projection of center of 2d rectangle (for point and rectangular selection correspondingly) onto near view frustum plane");
cls_SelectBasics_SelectingVolumeManager.def("GetFarPickedPnt", (gp_Pnt (SelectBasics_SelectingVolumeManager::*)() const) &SelectBasics_SelectingVolumeManager::GetFarPickedPnt, "Valid only for point and rectangular selection. Returns projection of 2d mouse picked point or projection of center of 2d rectangle (for point and rectangular selection correspondingly) onto far view frustum plane");
cls_SelectBasics_SelectingVolumeManager.def("GetMousePosition", (gp_Pnt2d (SelectBasics_SelectingVolumeManager::*)() const) &SelectBasics_SelectingVolumeManager::GetMousePosition, "Return mouse coordinates for Point selection mode.");
cls_SelectBasics_SelectingVolumeManager.def("GetPlanes", (void (SelectBasics_SelectingVolumeManager::*)(NCollection_Vector<NCollection_Vec4<Standard_Real> > &) const) &SelectBasics_SelectingVolumeManager::GetPlanes, "Stores plane equation coefficients (in the following form: Ax + By + Cz + D = 0) to the given vector", py::arg("thePlaneEquations"));

// Enums
py::enum_<SelectBasics_SelectingVolumeManager::SelectionType>(cls_SelectBasics_SelectingVolumeManager, "SelectionType", "Available selection types")
	.value("Point", SelectBasics_SelectingVolumeManager::SelectionType::Point)
	.value("Box", SelectBasics_SelectingVolumeManager::SelectionType::Box)
	.value("Polyline", SelectBasics_SelectingVolumeManager::SelectionType::Polyline)
	.value("Unknown", SelectBasics_SelectingVolumeManager::SelectionType::Unknown)
	.export_values();

// CLASS: SELECTBASICS
py::class_<SelectBasics> cls_SelectBasics(mod, "SelectBasics", "interface class for dynamic selection");

// Methods
cls_SelectBasics.def_static("MaxOwnerPriority_", (Standard_Integer (*)()) &SelectBasics::MaxOwnerPriority, "Structure to provide all-in-one result of selection of sensitive for 'Matches' method of Select3D_SensitiveEntity.");
cls_SelectBasics.def_static("MinOwnerPriority_", (Standard_Integer (*)()) &SelectBasics::MinOwnerPriority, "None");


}
