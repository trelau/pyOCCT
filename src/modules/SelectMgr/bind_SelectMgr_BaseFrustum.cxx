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
#include <Graphic3d_Camera.hxx>
#include <Graphic3d_Mat4d.hxx>
#include <Standard_TypeDef.hxx>
#include <Graphic3d_WorldViewProjState.hxx>
#include <SelectMgr_FrustumBuilder.hxx>
#include <gp_Pnt2d.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <SelectMgr_BaseFrustum.hxx>
#include <gp_GTrsf.hxx>
#include <SelectMgr_VectorTypes.hxx>
#include <gp_Pnt.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <Select3D_TypeOfSensitivity.hxx>
#include <Graphic3d_SequenceOfHClipPlane.hxx>
#include <NCollection_Vector.hxx>
#include <Standard_Type.hxx>

void bind_SelectMgr_BaseFrustum(py::module &mod){

py::class_<SelectMgr_BaseFrustum, opencascade::handle<SelectMgr_BaseFrustum>, Standard_Transient> cls_SelectMgr_BaseFrustum(mod, "SelectMgr_BaseFrustum", "This class is an interface for different types of selecting frustums, defining different selection types, like point, box or polyline selection. It contains signatures of functions for detection of overlap by sensitive entity and initializes some data for building the selecting frustum");

// Constructors
cls_SelectMgr_BaseFrustum.def(py::init<>());

// Fields

// Methods
cls_SelectMgr_BaseFrustum.def("Camera", (const opencascade::handle<Graphic3d_Camera> & (SelectMgr_BaseFrustum::*)() const) &SelectMgr_BaseFrustum::Camera, "Return camera definition.");
cls_SelectMgr_BaseFrustum.def("SetCamera", (void (SelectMgr_BaseFrustum::*)(const opencascade::handle<Graphic3d_Camera> &)) &SelectMgr_BaseFrustum::SetCamera, "Passes camera projection and orientation matrices to builder", py::arg("theCamera"));
cls_SelectMgr_BaseFrustum.def("SetCamera", [](SelectMgr_BaseFrustum &self, const Graphic3d_Mat4d & a0, const Graphic3d_Mat4d & a1, const Standard_Boolean a2) -> void { return self.SetCamera(a0, a1, a2); });
cls_SelectMgr_BaseFrustum.def("SetCamera", (void (SelectMgr_BaseFrustum::*)(const Graphic3d_Mat4d &, const Graphic3d_Mat4d &, const Standard_Boolean, const Graphic3d_WorldViewProjState &)) &SelectMgr_BaseFrustum::SetCamera, "Passes camera projection and orientation matrices to builder", py::arg("theProjection"), py::arg("theWorldView"), py::arg("theIsOrthographic"), py::arg("theWVPState"));
cls_SelectMgr_BaseFrustum.def("ProjectionMatrix", (const Graphic3d_Mat4d & (SelectMgr_BaseFrustum::*)() const) &SelectMgr_BaseFrustum::ProjectionMatrix, "Returns current camera projection transformation common for all selecting volumes");
cls_SelectMgr_BaseFrustum.def("WorldViewMatrix", (const Graphic3d_Mat4d & (SelectMgr_BaseFrustum::*)() const) &SelectMgr_BaseFrustum::WorldViewMatrix, "Returns current camera world view transformation common for all selecting volumes");
cls_SelectMgr_BaseFrustum.def("WorldViewProjState", (const Graphic3d_WorldViewProjState & (SelectMgr_BaseFrustum::*)() const) &SelectMgr_BaseFrustum::WorldViewProjState, "Returns current camera world view projection transformation state");
cls_SelectMgr_BaseFrustum.def("SetPixelTolerance", (void (SelectMgr_BaseFrustum::*)(const Standard_Integer)) &SelectMgr_BaseFrustum::SetPixelTolerance, "None", py::arg("theTol"));
cls_SelectMgr_BaseFrustum.def("SetWindowSize", (void (SelectMgr_BaseFrustum::*)(const Standard_Integer, const Standard_Integer)) &SelectMgr_BaseFrustum::SetWindowSize, "None", py::arg("theWidth"), py::arg("theHeight"));
cls_SelectMgr_BaseFrustum.def("WindowSize", [](SelectMgr_BaseFrustum &self, Standard_Integer & theWidth, Standard_Integer & theHeight){ self.WindowSize(theWidth, theHeight); return std::tuple<Standard_Integer &, Standard_Integer &>(theWidth, theHeight); }, "None", py::arg("theWidth"), py::arg("theHeight"));
cls_SelectMgr_BaseFrustum.def("SetViewport", (void (SelectMgr_BaseFrustum::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &SelectMgr_BaseFrustum::SetViewport, "Passes viewport parameters to builder", py::arg("theX"), py::arg("theY"), py::arg("theWidth"), py::arg("theHeight"));
cls_SelectMgr_BaseFrustum.def("SetBuilder", (void (SelectMgr_BaseFrustum::*)(const opencascade::handle<SelectMgr_FrustumBuilder> &)) &SelectMgr_BaseFrustum::SetBuilder, "Nullifies the builder created in the constructor and copies the pointer given", py::arg("theBuilder"));
cls_SelectMgr_BaseFrustum.def("Build", (void (SelectMgr_BaseFrustum::*)(const gp_Pnt2d &)) &SelectMgr_BaseFrustum::Build, "Builds volume according to the point and given pixel tolerance", py::arg(""));
cls_SelectMgr_BaseFrustum.def("Build", (void (SelectMgr_BaseFrustum::*)(const gp_Pnt2d &, const gp_Pnt2d &)) &SelectMgr_BaseFrustum::Build, "Builds volume according to the selected rectangle", py::arg(""), py::arg(""));
cls_SelectMgr_BaseFrustum.def("Build", (void (SelectMgr_BaseFrustum::*)(const gp_Pnt2d &, const gp_Pnt2d &, const gp_Pnt2d &)) &SelectMgr_BaseFrustum::Build, "Builds volume according to the triangle given", py::arg(""), py::arg(""), py::arg(""));
cls_SelectMgr_BaseFrustum.def("Build", (void (SelectMgr_BaseFrustum::*)(const TColgp_Array1OfPnt2d &)) &SelectMgr_BaseFrustum::Build, "Builds selecting volumes set according to polyline points", py::arg(""));
cls_SelectMgr_BaseFrustum.def("ScaleAndTransform", (opencascade::handle<SelectMgr_BaseFrustum> (SelectMgr_BaseFrustum::*)(const Standard_Integer, const gp_GTrsf &) const) &SelectMgr_BaseFrustum::ScaleAndTransform, "IMPORTANT: Scaling makes sense only for frustum built on a single point! Note that this method does not perform any checks on type of the frustum. Returns a copy of the frustum resized according to the scale factor given and transforms it using the matrix given. There are no default parameters, but in case if: - transformation only is needed: must be initialized as any negative value; - scale only is needed: must be set to gp_Identity.", py::arg(""), py::arg(""));
cls_SelectMgr_BaseFrustum.def("Overlaps", [](SelectMgr_BaseFrustum &self, const SelectMgr_Vec3 & theBoxMin, const SelectMgr_Vec3 & theBoxMax, Standard_Real & theDepth){ Standard_Boolean rv = self.Overlaps(theBoxMin, theBoxMax, theDepth); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theDepth); }, "SAT intersection test between defined volume and given axis-aligned box", py::arg("theBoxMin"), py::arg("theBoxMax"), py::arg("theDepth"));
cls_SelectMgr_BaseFrustum.def("Overlaps", [](SelectMgr_BaseFrustum &self, const SelectMgr_Vec3 & theBoxMin, const SelectMgr_Vec3 & theBoxMax, Standard_Boolean * theInside){ Standard_Boolean rv = self.Overlaps(theBoxMin, theBoxMax, theInside); return std::tuple<Standard_Boolean, Standard_Boolean *>(rv, theInside); }, "Returns true if selecting volume is overlapped by axis-aligned bounding box with minimum corner at point theMinPt and maximum at point theMaxPt", py::arg("theBoxMin"), py::arg("theBoxMax"), py::arg("theInside"));
cls_SelectMgr_BaseFrustum.def("Overlaps", [](SelectMgr_BaseFrustum &self, const gp_Pnt & thePnt, Standard_Real & theDepth){ Standard_Boolean rv = self.Overlaps(thePnt, theDepth); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theDepth); }, "Intersection test between defined volume and given point", py::arg("thePnt"), py::arg("theDepth"));
cls_SelectMgr_BaseFrustum.def("Overlaps", (Standard_Boolean (SelectMgr_BaseFrustum::*)(const gp_Pnt &)) &SelectMgr_BaseFrustum::Overlaps, "Intersection test between defined volume and given point Does not perform depth calculation, so this method is defined as helper function for inclusion test. Therefore, its implementation makes sense only for rectangular frustum with box selection mode activated.", py::arg("thePnt"));
cls_SelectMgr_BaseFrustum.def("Overlaps", [](SelectMgr_BaseFrustum &self, const TColgp_Array1OfPnt & theArrayOfPnts, Select3D_TypeOfSensitivity theSensType, Standard_Real & theDepth){ Standard_Boolean rv = self.Overlaps(theArrayOfPnts, theSensType, theDepth); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theDepth); }, "SAT intersection test between defined volume and given ordered set of points, representing line segments. The test may be considered of interior part or boundary line defined by segments depending on given sensitivity type", py::arg("theArrayOfPnts"), py::arg("theSensType"), py::arg("theDepth"));
cls_SelectMgr_BaseFrustum.def("Overlaps", [](SelectMgr_BaseFrustum &self, const gp_Pnt & thePnt1, const gp_Pnt & thePnt2, Standard_Real & theDepth){ Standard_Boolean rv = self.Overlaps(thePnt1, thePnt2, theDepth); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theDepth); }, "Checks if line segment overlaps selecting frustum", py::arg("thePnt1"), py::arg("thePnt2"), py::arg("theDepth"));
cls_SelectMgr_BaseFrustum.def("Overlaps", [](SelectMgr_BaseFrustum &self, const gp_Pnt & thePt1, const gp_Pnt & thePt2, const gp_Pnt & thePt3, Select3D_TypeOfSensitivity theSensType, Standard_Real & theDepth){ Standard_Boolean rv = self.Overlaps(thePt1, thePt2, thePt3, theSensType, theDepth); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theDepth); }, "SAT intersection test between defined volume and given triangle. The test may be considered of interior part or boundary line defined by triangle vertices depending on given sensitivity type", py::arg("thePt1"), py::arg("thePt2"), py::arg("thePt3"), py::arg("theSensType"), py::arg("theDepth"));
cls_SelectMgr_BaseFrustum.def("DistToGeometryCenter", (Standard_Real (SelectMgr_BaseFrustum::*)(const gp_Pnt &)) &SelectMgr_BaseFrustum::DistToGeometryCenter, "Measures distance between 3d projection of user-picked screen point and given point theCOG", py::arg("theCOG"));
cls_SelectMgr_BaseFrustum.def("DetectedPoint", (gp_Pnt (SelectMgr_BaseFrustum::*)(const Standard_Real) const) &SelectMgr_BaseFrustum::DetectedPoint, "None", py::arg("theDepth"));
cls_SelectMgr_BaseFrustum.def("IsClipped", (Standard_Boolean (SelectMgr_BaseFrustum::*)(const Graphic3d_SequenceOfHClipPlane &, const Standard_Real)) &SelectMgr_BaseFrustum::IsClipped, "Checks if the point of sensitive in which selection was detected belongs to the region defined by clipping planes", py::arg("thePlanes"), py::arg("theDepth"));
cls_SelectMgr_BaseFrustum.def("SetViewClipping", (void (SelectMgr_BaseFrustum::*)(const opencascade::handle<Graphic3d_SequenceOfHClipPlane> &)) &SelectMgr_BaseFrustum::SetViewClipping, "Valid for point selection only! Computes depth range for global (defined for the whole view) clipping planes.", py::arg(""));
cls_SelectMgr_BaseFrustum.def("SetViewClippingEnabled", (Standard_Boolean (SelectMgr_BaseFrustum::*)(const Standard_Boolean)) &SelectMgr_BaseFrustum::SetViewClippingEnabled, "Set if view clipping plane is enabled or not.", py::arg(""));
cls_SelectMgr_BaseFrustum.def("GetPlanes", (void (SelectMgr_BaseFrustum::*)(NCollection_Vector<SelectMgr_Vec4> &) const) &SelectMgr_BaseFrustum::GetPlanes, "Stores plane equation coefficients (in the following form: Ax + By + Cz + D = 0) to the given vector", py::arg("thePlaneEquations"));
cls_SelectMgr_BaseFrustum.def_static("get_type_name_", (const char * (*)()) &SelectMgr_BaseFrustum::get_type_name, "None");
cls_SelectMgr_BaseFrustum.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &SelectMgr_BaseFrustum::get_type_descriptor, "None");
cls_SelectMgr_BaseFrustum.def("DynamicType", (const opencascade::handle<Standard_Type> & (SelectMgr_BaseFrustum::*)() const) &SelectMgr_BaseFrustum::DynamicType, "None");

// Enums

}