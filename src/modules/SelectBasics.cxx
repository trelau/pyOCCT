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
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <SelectBasics_EntityOwner.hxx>
#include <Standard_Type.hxx>
#include <Standard_TypeDef.hxx>
#include <TopLoc_Location.hxx>
#include <NCollection_Vec3.hxx>
#include <gp_Pnt.hxx>
#include <TColgp_HArray1OfPnt.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <NCollection_Vector.hxx>
#include <NCollection_Vec4.hxx>
#include <SelectBasics_SelectingVolumeManager.hxx>
#include <SelectBasics_PickResult.hxx>
#include <SelectBasics_SensitiveEntity.hxx>
#include <Standard_ProgramError.hxx>
#include <Select3D_BndBox3d.hxx>
#include <gp_GTrsf.hxx>
#include <Standard.hxx>
#include <SelectBasics.hxx>

PYBIND11_MODULE(SelectBasics, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.TopLoc");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.gp");
py::module::import("OCCT.TColgp");

struct ImportSelect3D{
	ImportSelect3D() { py::module::import("OCCT.Select3D"); }
};

// CLASS: SELECTBASICS_ENTITYOWNER
py::class_<SelectBasics_EntityOwner, opencascade::handle<SelectBasics_EntityOwner>, Standard_Transient> cls_SelectBasics_EntityOwner(mod, "SelectBasics_EntityOwner", "defines an abstract owner of sensitive primitives. Owners are typically used to establish a connection between sensitive entities and high-level objects (e.g. presentations).");

// Methods
cls_SelectBasics_EntityOwner.def_static("get_type_name_", (const char * (*)()) &SelectBasics_EntityOwner::get_type_name, "None");
cls_SelectBasics_EntityOwner.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &SelectBasics_EntityOwner::get_type_descriptor, "None");
cls_SelectBasics_EntityOwner.def("DynamicType", (const opencascade::handle<Standard_Type> & (SelectBasics_EntityOwner::*)() const) &SelectBasics_EntityOwner::DynamicType, "None");
cls_SelectBasics_EntityOwner.def("SetPriority", (void (SelectBasics_EntityOwner::*)(const Standard_Integer)) &SelectBasics_EntityOwner::SetPriority, "sets the selectable priority of the owner", py::arg("thePriority"));
cls_SelectBasics_EntityOwner.def("Priority", (Standard_Integer (SelectBasics_EntityOwner::*)() const) &SelectBasics_EntityOwner::Priority, "None");
cls_SelectBasics_EntityOwner.def("HasLocation", (Standard_Boolean (SelectBasics_EntityOwner::*)() const) &SelectBasics_EntityOwner::HasLocation, "None");
cls_SelectBasics_EntityOwner.def("SetLocation", (void (SelectBasics_EntityOwner::*)(const TopLoc_Location &)) &SelectBasics_EntityOwner::SetLocation, "None", py::arg("aLoc"));
cls_SelectBasics_EntityOwner.def("ResetLocation", (void (SelectBasics_EntityOwner::*)()) &SelectBasics_EntityOwner::ResetLocation, "None");
cls_SelectBasics_EntityOwner.def("Location", (TopLoc_Location (SelectBasics_EntityOwner::*)() const) &SelectBasics_EntityOwner::Location, "None");
cls_SelectBasics_EntityOwner.def("Set", (void (SelectBasics_EntityOwner::*)(const Standard_Integer)) &SelectBasics_EntityOwner::Set, "sets the selectable priority of the owner", py::arg("thePriority"));

// CLASS: SELECTBASICS_SELECTINGVOLUMEMANAGER
py::class_<SelectBasics_SelectingVolumeManager> cls_SelectBasics_SelectingVolumeManager(mod, "SelectBasics_SelectingVolumeManager", "This class provides an interface for selecting volume manager, which is responsible for all overlap detection methods and calculation of minimum depth, distance to center of geometry and detected closest point on entity.");

// Methods
cls_SelectBasics_SelectingVolumeManager.def("GetActiveSelectionType", (Standard_Integer (SelectBasics_SelectingVolumeManager::*)() const) &SelectBasics_SelectingVolumeManager::GetActiveSelectionType, "None");
cls_SelectBasics_SelectingVolumeManager.def("Overlaps", [](SelectBasics_SelectingVolumeManager &self, const NCollection_Vec3<Standard_Real> & theBoxMin, const NCollection_Vec3<Standard_Real> & theBoxMax, Standard_Real & theDepth){ Standard_Boolean rv = self.Overlaps(theBoxMin, theBoxMax, theDepth); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theDepth); }, "Returns true if selecting volume is overlapped by box theBox", py::arg("theBoxMin"), py::arg("theBoxMax"), py::arg("theDepth"));
cls_SelectBasics_SelectingVolumeManager.def("Overlaps", [](SelectBasics_SelectingVolumeManager &self, const NCollection_Vec3<Standard_Real> & theBoxMin, const NCollection_Vec3<Standard_Real> & theBoxMax, Standard_Boolean * theInside){ Standard_Boolean rv = self.Overlaps(theBoxMin, theBoxMax, theInside); return std::tuple<Standard_Boolean, Standard_Boolean *>(rv, theInside); }, "Returns true if selecting volume is overlapped by axis-aligned bounding box with minimum corner at point theMinPt and maximum at point theMaxPt", py::arg("theBoxMin"), py::arg("theBoxMax"), py::arg("theInside"));
cls_SelectBasics_SelectingVolumeManager.def("Overlaps", [](SelectBasics_SelectingVolumeManager &self, const gp_Pnt & thePnt, Standard_Real & theDepth){ Standard_Boolean rv = self.Overlaps(thePnt, theDepth); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theDepth); }, "Returns true if selecting volume is overlapped by point thePnt", py::arg("thePnt"), py::arg("theDepth"));
cls_SelectBasics_SelectingVolumeManager.def("Overlaps", (Standard_Boolean (SelectBasics_SelectingVolumeManager::*)(const gp_Pnt &)) &SelectBasics_SelectingVolumeManager::Overlaps, "Returns true if selecting volume is overlapped by point thePnt. Does not perform depth calculation, so this method is defined as helper function for inclusion test.", py::arg("thePnt"));
cls_SelectBasics_SelectingVolumeManager.def("Overlaps", [](SelectBasics_SelectingVolumeManager &self, const opencascade::handle<TColgp_HArray1OfPnt> & theArrayOfPts, Standard_Integer theSensType, Standard_Real & theDepth){ Standard_Boolean rv = self.Overlaps(theArrayOfPts, theSensType, theDepth); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theDepth); }, "Returns true if selecting volume is overlapped by planar convex polygon, which points are stored in theArrayOfPts, taking into account sensitivity type theSensType", py::arg("theArrayOfPts"), py::arg("theSensType"), py::arg("theDepth"));
cls_SelectBasics_SelectingVolumeManager.def("Overlaps", [](SelectBasics_SelectingVolumeManager &self, const TColgp_Array1OfPnt & theArrayOfPts, Standard_Integer theSensType, Standard_Real & theDepth){ Standard_Boolean rv = self.Overlaps(theArrayOfPts, theSensType, theDepth); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theDepth); }, "Returns true if selecting volume is overlapped by planar convex polygon, which points are stored in theArrayOfPts, taking into account sensitivity type theSensType", py::arg("theArrayOfPts"), py::arg("theSensType"), py::arg("theDepth"));
cls_SelectBasics_SelectingVolumeManager.def("Overlaps", [](SelectBasics_SelectingVolumeManager &self, const gp_Pnt & thePt1, const gp_Pnt & thePt2, Standard_Real & theDepth){ Standard_Boolean rv = self.Overlaps(thePt1, thePt2, theDepth); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theDepth); }, "Returns true if selecting volume is overlapped by line segment with start point at thePt1 and end point at thePt2", py::arg("thePt1"), py::arg("thePt2"), py::arg("theDepth"));
cls_SelectBasics_SelectingVolumeManager.def("Overlaps", [](SelectBasics_SelectingVolumeManager &self, const gp_Pnt & thePt1, const gp_Pnt & thePt2, const gp_Pnt & thePt3, Standard_Integer theSensType, Standard_Real & theDepth){ Standard_Boolean rv = self.Overlaps(thePt1, thePt2, thePt3, theSensType, theDepth); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theDepth); }, "Returns true if selecting volume is overlapped by triangle with vertices thePt1, thePt2 and thePt3, taking into account sensitivity type theSensType", py::arg("thePt1"), py::arg("thePt2"), py::arg("thePt3"), py::arg("theSensType"), py::arg("theDepth"));
cls_SelectBasics_SelectingVolumeManager.def("DistToGeometryCenter", (Standard_Real (SelectBasics_SelectingVolumeManager::*)(const gp_Pnt &)) &SelectBasics_SelectingVolumeManager::DistToGeometryCenter, "Calculates distance from 3d projection of user-defined selection point to the given point theCOG", py::arg("theCOG"));
cls_SelectBasics_SelectingVolumeManager.def("DetectedPoint", (gp_Pnt (SelectBasics_SelectingVolumeManager::*)(const Standard_Real) const) &SelectBasics_SelectingVolumeManager::DetectedPoint, "None", py::arg("theDepth"));
cls_SelectBasics_SelectingVolumeManager.def("IsOverlapAllowed", (Standard_Boolean (SelectBasics_SelectingVolumeManager::*)() const) &SelectBasics_SelectingVolumeManager::IsOverlapAllowed, "None");
cls_SelectBasics_SelectingVolumeManager.def("GetNearPickedPnt", (gp_Pnt (SelectBasics_SelectingVolumeManager::*)() const) &SelectBasics_SelectingVolumeManager::GetNearPickedPnt, "Valid only for point and rectangular selection. Returns projection of 2d mouse picked point or projection of center of 2d rectangle (for point and rectangular selection correspondingly) onto near view frustum plane");
cls_SelectBasics_SelectingVolumeManager.def("GetFarPickedPnt", (gp_Pnt (SelectBasics_SelectingVolumeManager::*)() const) &SelectBasics_SelectingVolumeManager::GetFarPickedPnt, "Valid only for point and rectangular selection. Returns projection of 2d mouse picked point or projection of center of 2d rectangle (for point and rectangular selection correspondingly) onto far view frustum plane");
cls_SelectBasics_SelectingVolumeManager.def("GetPlanes", (void (SelectBasics_SelectingVolumeManager::*)(NCollection_Vector<NCollection_Vec4<Standard_Real> > &) const) &SelectBasics_SelectingVolumeManager::GetPlanes, "Stores plane equation coefficients (in the following form: Ax + By + Cz + D = 0) to the given vector", py::arg("thePlaneEquations"));

// Enums
py::enum_<SelectBasics_SelectingVolumeManager::SelectionType>(cls_SelectBasics_SelectingVolumeManager, "SelectionType", "Available selection types")
	.value("Point", SelectBasics_SelectingVolumeManager::SelectionType::Point)
	.value("Box", SelectBasics_SelectingVolumeManager::SelectionType::Box)
	.value("Polyline", SelectBasics_SelectingVolumeManager::SelectionType::Polyline)
	.value("Unknown", SelectBasics_SelectingVolumeManager::SelectionType::Unknown)
	.export_values();

// CLASS: SELECTBASICS_PICKRESULT
py::class_<SelectBasics_PickResult> cls_SelectBasics_PickResult(mod, "SelectBasics_PickResult", "This structure provides unified access to the results of Matches() method in all sensitive entities.");

// Constructors
cls_SelectBasics_PickResult.def(py::init<>());
cls_SelectBasics_PickResult.def(py::init<const Standard_Real, const Standard_Real>(), py::arg("theDepth"), py::arg("theDistToCenter"));

// Methods
cls_SelectBasics_PickResult.def("Depth", (Standard_Real (SelectBasics_PickResult::*)() const) &SelectBasics_PickResult::Depth, "None");
cls_SelectBasics_PickResult.def("DistToGeomCenter", (Standard_Real (SelectBasics_PickResult::*)() const) &SelectBasics_PickResult::DistToGeomCenter, "None");

// CLASS: SELECTBASICS_SENSITIVEENTITY
py::class_<SelectBasics_SensitiveEntity, opencascade::handle<SelectBasics_SensitiveEntity>, Standard_Transient> cls_SelectBasics_SensitiveEntity(mod, "SelectBasics_SensitiveEntity", "root class; the inheriting classes will be able to give sensitive Areas for the dynamic selection algorithms");

// Methods
cls_SelectBasics_SensitiveEntity.def_static("get_type_name_", (const char * (*)()) &SelectBasics_SensitiveEntity::get_type_name, "None");
cls_SelectBasics_SensitiveEntity.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &SelectBasics_SensitiveEntity::get_type_descriptor, "None");
cls_SelectBasics_SensitiveEntity.def("DynamicType", (const opencascade::handle<Standard_Type> & (SelectBasics_SensitiveEntity::*)() const) &SelectBasics_SensitiveEntity::DynamicType, "None");
cls_SelectBasics_SensitiveEntity.def("Set", (void (SelectBasics_SensitiveEntity::*)(const opencascade::handle<SelectBasics_EntityOwner> &)) &SelectBasics_SensitiveEntity::Set, "Sets owner of the entity", py::arg("theOwnerId"));
cls_SelectBasics_SensitiveEntity.def("OwnerId", (const opencascade::handle<SelectBasics_EntityOwner> & (SelectBasics_SensitiveEntity::*)() const) &SelectBasics_SensitiveEntity::OwnerId, "Returns pointer to owner of the entity");
cls_SelectBasics_SensitiveEntity.def("Matches", (Standard_Boolean (SelectBasics_SensitiveEntity::*)(SelectBasics_SelectingVolumeManager &, SelectBasics_PickResult &)) &SelectBasics_SensitiveEntity::Matches, "Checks whether the sensitive entity is overlapped by current selecting volume", py::arg("theMgr"), py::arg("thePickResult"));
cls_SelectBasics_SensitiveEntity.def("SensitivityFactor", (Standard_Integer (SelectBasics_SensitiveEntity::*)() const) &SelectBasics_SensitiveEntity::SensitivityFactor, "allows a better sensitivity for a specific entity in selection algorithms useful for small sized entities.");
cls_SelectBasics_SensitiveEntity.def("SetSensitivityFactor", (void (SelectBasics_SensitiveEntity::*)(const Standard_Integer)) &SelectBasics_SensitiveEntity::SetSensitivityFactor, "Allows to manage sensitivity of a particular sensitive entity", py::arg("theNewSens"));
cls_SelectBasics_SensitiveEntity.def("NbSubElements", (Standard_Integer (SelectBasics_SensitiveEntity::*)()) &SelectBasics_SensitiveEntity::NbSubElements, "Returns the number of sub-entities or elements in sensitive entity. Is used to determine if entity is complex and needs to pre-build BVH at the creation of sensitive entity step or is light-weighted so the tree can be build on demand with unnoticeable delay");
cls_SelectBasics_SensitiveEntity.def("BoundingBox", (Select3D_BndBox3d (SelectBasics_SensitiveEntity::*)()) &SelectBasics_SensitiveEntity::BoundingBox, "Returns bounding box of sensitive entity", py::call_guard<ImportSelect3D>());
cls_SelectBasics_SensitiveEntity.def("BVH", (void (SelectBasics_SensitiveEntity::*)()) &SelectBasics_SensitiveEntity::BVH, "Builds BVH tree for sensitive if it is needed");
cls_SelectBasics_SensitiveEntity.def("Clear", (void (SelectBasics_SensitiveEntity::*)()) &SelectBasics_SensitiveEntity::Clear, "Clears up all the resources and memory allocated");
cls_SelectBasics_SensitiveEntity.def("HasInitLocation", (Standard_Boolean (SelectBasics_SensitiveEntity::*)() const) &SelectBasics_SensitiveEntity::HasInitLocation, "Returns true if the shape corresponding to the entity has init location");
cls_SelectBasics_SensitiveEntity.def("InvInitLocation", (gp_GTrsf (SelectBasics_SensitiveEntity::*)() const) &SelectBasics_SensitiveEntity::InvInitLocation, "Returns inversed location transformation matrix if the shape corresponding to this entity has init location set. Otherwise, returns identity matrix.");

// CLASS: SELECTBASICS
py::class_<SelectBasics> cls_SelectBasics(mod, "SelectBasics", "interface class for dynamic selection");

// Methods
// cls_SelectBasics.def_static("operator new_", (void * (*)(size_t)) &SelectBasics::operator new, "None", py::arg("theSize"));
// cls_SelectBasics.def_static("operator delete_", (void (*)(void *)) &SelectBasics::operator delete, "None", py::arg("theAddress"));
// cls_SelectBasics.def_static("operator new[]_", (void * (*)(size_t)) &SelectBasics::operator new[], "None", py::arg("theSize"));
// cls_SelectBasics.def_static("operator delete[]_", (void (*)(void *)) &SelectBasics::operator delete[], "None", py::arg("theAddress"));
// cls_SelectBasics.def_static("operator new_", (void * (*)(size_t, void *)) &SelectBasics::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_SelectBasics.def_static("operator delete_", (void (*)(void *, void *)) &SelectBasics::operator delete, "None", py::arg(""), py::arg(""));
cls_SelectBasics.def_static("MaxOwnerPriority_", (Standard_Integer (*)()) &SelectBasics::MaxOwnerPriority, "Structure to provide all-in-one result of selection of sensitive for 'Matches' method of SelectBasics_SensitiveEntity.");
cls_SelectBasics.def_static("MinOwnerPriority_", (Standard_Integer (*)()) &SelectBasics::MinOwnerPriority, "None");


}
