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
#include <Standard_TypeDef.hxx>
#include <NCollection_Mat4.hxx>
#include <Graphic3d_Camera.hxx>
#include <Standard_Handle.hxx>
#include <gp_Pnt.hxx>
#include <gp_Dir.hxx>
#include <gp_XYZ.hxx>
#include <Bnd_Box.hxx>
#include <Graphic3d_CameraTile.hxx>
#include <gp_Trsf.hxx>
#include <gp_Pln.hxx>
#include <Graphic3d_WorldViewProjState.hxx>
#include <Graphic3d_Mat4d.hxx>
#include <Graphic3d_Mat4.hxx>
#include <NCollection_Vec3.hxx>
#include <Standard_Type.hxx>

void bind_Graphic3d_Camera(py::module &mod){

py::class_<Graphic3d_Camera, opencascade::handle<Graphic3d_Camera>, Standard_Transient> cls_Graphic3d_Camera(mod, "Graphic3d_Camera", "Camera class provides object-oriented approach to setting up projection and orientation properties of 3D view.");

// Constructors
cls_Graphic3d_Camera.def(py::init<>());
cls_Graphic3d_Camera.def(py::init<const opencascade::handle<Graphic3d_Camera> &>(), py::arg("theOther"));

// Fields

// Methods
cls_Graphic3d_Camera.def("CopyMappingData", (void (Graphic3d_Camera::*)(const opencascade::handle<Graphic3d_Camera> &)) &Graphic3d_Camera::CopyMappingData, "Initialize mapping related parameters from other camera handle.", py::arg("theOtherCamera"));
cls_Graphic3d_Camera.def("CopyOrientationData", (void (Graphic3d_Camera::*)(const opencascade::handle<Graphic3d_Camera> &)) &Graphic3d_Camera::CopyOrientationData, "Initialize orientation related parameters from other camera handle.", py::arg("theOtherCamera"));
cls_Graphic3d_Camera.def("Copy", (void (Graphic3d_Camera::*)(const opencascade::handle<Graphic3d_Camera> &)) &Graphic3d_Camera::Copy, "Copy properties of another camera.", py::arg("theOther"));
cls_Graphic3d_Camera.def("SetEye", (void (Graphic3d_Camera::*)(const gp_Pnt &)) &Graphic3d_Camera::SetEye, "Sets camera Eye position.", py::arg("theEye"));
cls_Graphic3d_Camera.def("Eye", (const gp_Pnt & (Graphic3d_Camera::*)() const) &Graphic3d_Camera::Eye, "Get camera Eye position.");
cls_Graphic3d_Camera.def("SetCenter", (void (Graphic3d_Camera::*)(const gp_Pnt &)) &Graphic3d_Camera::SetCenter, "Sets Center of the camera.", py::arg("theCenter"));
cls_Graphic3d_Camera.def("Center", (const gp_Pnt & (Graphic3d_Camera::*)() const) &Graphic3d_Camera::Center, "Get Center of the camera.");
cls_Graphic3d_Camera.def("SetUp", (void (Graphic3d_Camera::*)(const gp_Dir &)) &Graphic3d_Camera::SetUp, "Sets camera Up direction vector, orthogonal to camera direction.", py::arg("theUp"));
cls_Graphic3d_Camera.def("OrthogonalizeUp", (void (Graphic3d_Camera::*)()) &Graphic3d_Camera::OrthogonalizeUp, "Orthogonalize up direction vector.");
cls_Graphic3d_Camera.def("OrthogonalizedUp", (gp_Dir (Graphic3d_Camera::*)() const) &Graphic3d_Camera::OrthogonalizedUp, "Return a copy of orthogonalized up direction vector.");
cls_Graphic3d_Camera.def("Up", (const gp_Dir & (Graphic3d_Camera::*)() const) &Graphic3d_Camera::Up, "Get camera Up direction vector.");
cls_Graphic3d_Camera.def("SetAxialScale", (void (Graphic3d_Camera::*)(const gp_XYZ &)) &Graphic3d_Camera::SetAxialScale, "Set camera axial scale.", py::arg("theAxialScale"));
cls_Graphic3d_Camera.def("AxialScale", (const gp_XYZ & (Graphic3d_Camera::*)() const) &Graphic3d_Camera::AxialScale, "Get camera axial scale.");
cls_Graphic3d_Camera.def("SetDistance", (void (Graphic3d_Camera::*)(const Standard_Real)) &Graphic3d_Camera::SetDistance, "Set distance of Eye from camera Center.", py::arg("theDistance"));
cls_Graphic3d_Camera.def("Distance", (Standard_Real (Graphic3d_Camera::*)() const) &Graphic3d_Camera::Distance, "Get distance of Eye from camera Center.");
cls_Graphic3d_Camera.def("SetDirection", (void (Graphic3d_Camera::*)(const gp_Dir &)) &Graphic3d_Camera::SetDirection, "Sets camera look direction.", py::arg("theDir"));
cls_Graphic3d_Camera.def("Direction", (gp_Dir (Graphic3d_Camera::*)() const) &Graphic3d_Camera::Direction, "Get camera look direction.");
cls_Graphic3d_Camera.def("SetScale", (void (Graphic3d_Camera::*)(const Standard_Real)) &Graphic3d_Camera::SetScale, "Sets camera scale. For orthographic projection the scale factor corresponds to parallel scale of view mapping (i.e. size of viewport). For perspective camera scale is converted to distance. The scale specifies equal size of the view projection in both dimensions assuming that the aspect is 1.0. The projection height and width are specified with the scale and correspondingly multiplied by the aspect.", py::arg("theScale"));
cls_Graphic3d_Camera.def("Scale", (Standard_Real (Graphic3d_Camera::*)() const) &Graphic3d_Camera::Scale, "Get camera scale.");
cls_Graphic3d_Camera.def("SetProjectionType", (void (Graphic3d_Camera::*)(const Graphic3d_Camera::Projection)) &Graphic3d_Camera::SetProjectionType, "Change camera projection type. When switching to perspective projection from orthographic one, the ZNear and ZFar are reset to default values (0.001, 3000.0) if less than 0.0.", py::arg("theProjection"));
cls_Graphic3d_Camera.def("ProjectionType", (Graphic3d_Camera::Projection (Graphic3d_Camera::*)() const) &Graphic3d_Camera::ProjectionType, "Returns camera projection type.");
cls_Graphic3d_Camera.def("IsOrthographic", (Standard_Boolean (Graphic3d_Camera::*)() const) &Graphic3d_Camera::IsOrthographic, "Check that the camera projection is orthographic.");
cls_Graphic3d_Camera.def("IsStereo", (Standard_Boolean (Graphic3d_Camera::*)() const) &Graphic3d_Camera::IsStereo, "Check whether the camera projection is stereo. Please note that stereo rendering is now implemented with support of Quad buffering.");
cls_Graphic3d_Camera.def("SetFOVy", (void (Graphic3d_Camera::*)(const Standard_Real)) &Graphic3d_Camera::SetFOVy, "Set Field Of View (FOV) in y axis for perspective projection.", py::arg("theFOVy"));
cls_Graphic3d_Camera.def("FOVy", (Standard_Real (Graphic3d_Camera::*)() const) &Graphic3d_Camera::FOVy, "Get Field Of View (FOV) in y axis.");
cls_Graphic3d_Camera.def("ZFitAll", [](Graphic3d_Camera &self, const Standard_Real theScaleFactor, const Bnd_Box & theMinMax, const Bnd_Box & theGraphicBB, Standard_Real & theZNear, Standard_Real & theZFar){ bool rv = self.ZFitAll(theScaleFactor, theMinMax, theGraphicBB, theZNear, theZFar); return std::tuple<bool, Standard_Real &, Standard_Real &>(rv, theZNear, theZFar); }, "Estimate Z-min and Z-max planes of projection volume to match the displayed objects. The methods ensures that view volume will be close by depth range to the displayed objects. Fitting assumes that for orthogonal projection the view volume contains the displayed objects completely. For zoomed perspective view, the view volume is adjusted such that it contains the objects or their parts, located in front of the camera.", py::arg("theScaleFactor"), py::arg("theMinMax"), py::arg("theGraphicBB"), py::arg("theZNear"), py::arg("theZFar"));
cls_Graphic3d_Camera.def("ZFitAll", (void (Graphic3d_Camera::*)(const Standard_Real, const Bnd_Box &, const Bnd_Box &)) &Graphic3d_Camera::ZFitAll, "Change Z-min and Z-max planes of projection volume to match the displayed objects.", py::arg("theScaleFactor"), py::arg("theMinMax"), py::arg("theGraphicBB"));
cls_Graphic3d_Camera.def("SetZRange", (void (Graphic3d_Camera::*)(const Standard_Real, const Standard_Real)) &Graphic3d_Camera::SetZRange, "Change the Near and Far Z-clipping plane positions. For orthographic projection, theZNear, theZFar can be negative or positive. For perspective projection, only positive values are allowed. Program error exception is raised if non-positive values are specified for perspective projection or theZNear >= theZFar.", py::arg("theZNear"), py::arg("theZFar"));
cls_Graphic3d_Camera.def("ZNear", (Standard_Real (Graphic3d_Camera::*)() const) &Graphic3d_Camera::ZNear, "Get the Near Z-clipping plane position.");
cls_Graphic3d_Camera.def("ZFar", (Standard_Real (Graphic3d_Camera::*)() const) &Graphic3d_Camera::ZFar, "Get the Far Z-clipping plane position.");
cls_Graphic3d_Camera.def("SetAspect", (void (Graphic3d_Camera::*)(const Standard_Real)) &Graphic3d_Camera::SetAspect, "Changes width / height display ratio.", py::arg("theAspect"));
cls_Graphic3d_Camera.def("Aspect", (Standard_Real (Graphic3d_Camera::*)() const) &Graphic3d_Camera::Aspect, "Get camera display ratio.");
cls_Graphic3d_Camera.def("SetZFocus", (void (Graphic3d_Camera::*)(const Graphic3d_Camera::FocusType, const Standard_Real)) &Graphic3d_Camera::SetZFocus, "Sets stereographic focus distance.", py::arg("theType"), py::arg("theZFocus"));
cls_Graphic3d_Camera.def("ZFocus", (Standard_Real (Graphic3d_Camera::*)() const) &Graphic3d_Camera::ZFocus, "Get stereographic focus value.");
cls_Graphic3d_Camera.def("ZFocusType", (Graphic3d_Camera::FocusType (Graphic3d_Camera::*)() const) &Graphic3d_Camera::ZFocusType, "Get stereographic focus definition type.");
cls_Graphic3d_Camera.def("SetIOD", (void (Graphic3d_Camera::*)(const Graphic3d_Camera::IODType, const Standard_Real)) &Graphic3d_Camera::SetIOD, "Sets Intraocular distance.", py::arg("theType"), py::arg("theIOD"));
cls_Graphic3d_Camera.def("IOD", (Standard_Real (Graphic3d_Camera::*)() const) &Graphic3d_Camera::IOD, "Get Intraocular distance value.");
cls_Graphic3d_Camera.def("GetIODType", (Graphic3d_Camera::IODType (Graphic3d_Camera::*)() const) &Graphic3d_Camera::GetIODType, "Get Intraocular distance definition type.");
cls_Graphic3d_Camera.def("Tile", (const Graphic3d_CameraTile & (Graphic3d_Camera::*)() const) &Graphic3d_Camera::Tile, "Get current tile.");
cls_Graphic3d_Camera.def("SetTile", (void (Graphic3d_Camera::*)(const Graphic3d_CameraTile &)) &Graphic3d_Camera::SetTile, "Sets the Tile defining the drawing sub-area within View. Note that tile defining a region outside the view boundaries is also valid - use method Graphic3d_CameraTile::Cropped() to assign a cropped copy.", py::arg("theTile"));
cls_Graphic3d_Camera.def("Transform", (void (Graphic3d_Camera::*)(const gp_Trsf &)) &Graphic3d_Camera::Transform, "Transform orientation components of the camera: Eye, Up and Center points.", py::arg("theTrsf"));
cls_Graphic3d_Camera.def("ViewDimensions", (gp_XYZ (Graphic3d_Camera::*)() const) &Graphic3d_Camera::ViewDimensions, "Calculate view plane size at center (target) point and distance between ZFar and ZNear planes.");
cls_Graphic3d_Camera.def("ViewDimensions", (gp_XYZ (Graphic3d_Camera::*)(const Standard_Real) const) &Graphic3d_Camera::ViewDimensions, "Calculate view plane size at center point with specified Z offset and distance between ZFar and ZNear planes.", py::arg("theZValue"));
cls_Graphic3d_Camera.def("Frustum", (void (Graphic3d_Camera::*)(gp_Pln &, gp_Pln &, gp_Pln &, gp_Pln &, gp_Pln &, gp_Pln &) const) &Graphic3d_Camera::Frustum, "Calculate WCS frustum planes for the camera projection volume. Frustum is a convex volume determined by six planes directing inwards. The frustum planes are usually used as inputs for camera algorithms. Thus, if any changes to projection matrix calculation are necessary, the frustum planes calculation should be also touched.", py::arg("theLeft"), py::arg("theRight"), py::arg("theBottom"), py::arg("theTop"), py::arg("theNear"), py::arg("theFar"));
cls_Graphic3d_Camera.def("Project", (gp_Pnt (Graphic3d_Camera::*)(const gp_Pnt &) const) &Graphic3d_Camera::Project, "Project point from world coordinate space to normalized device coordinates (mapping).", py::arg("thePnt"));
cls_Graphic3d_Camera.def("UnProject", (gp_Pnt (Graphic3d_Camera::*)(const gp_Pnt &) const) &Graphic3d_Camera::UnProject, "Unproject point from normalized device coordinates to world coordinate space.", py::arg("thePnt"));
cls_Graphic3d_Camera.def("ConvertView2Proj", (gp_Pnt (Graphic3d_Camera::*)(const gp_Pnt &) const) &Graphic3d_Camera::ConvertView2Proj, "Convert point from view coordinate space to projection coordinate space.", py::arg("thePnt"));
cls_Graphic3d_Camera.def("ConvertProj2View", (gp_Pnt (Graphic3d_Camera::*)(const gp_Pnt &) const) &Graphic3d_Camera::ConvertProj2View, "Convert point from projection coordinate space to view coordinate space.", py::arg("thePnt"));
cls_Graphic3d_Camera.def("ConvertWorld2View", (gp_Pnt (Graphic3d_Camera::*)(const gp_Pnt &) const) &Graphic3d_Camera::ConvertWorld2View, "Convert point from world coordinate space to view coordinate space.", py::arg("thePnt"));
cls_Graphic3d_Camera.def("ConvertView2World", (gp_Pnt (Graphic3d_Camera::*)(const gp_Pnt &) const) &Graphic3d_Camera::ConvertView2World, "Convert point from view coordinate space to world coordinates.", py::arg("thePnt"));
cls_Graphic3d_Camera.def("WorldViewProjState", (const Graphic3d_WorldViewProjState & (Graphic3d_Camera::*)() const) &Graphic3d_Camera::WorldViewProjState, "Returns projection modification state of the camera.");
cls_Graphic3d_Camera.def("ProjectionState", (Standard_Size (Graphic3d_Camera::*)() const) &Graphic3d_Camera::ProjectionState, "Returns modification state of camera projection matrix");
cls_Graphic3d_Camera.def("WorldViewState", (Standard_Size (Graphic3d_Camera::*)() const) &Graphic3d_Camera::WorldViewState, "Returns modification state of camera world view transformation matrix.");
cls_Graphic3d_Camera.def("OrientationMatrix", (const Graphic3d_Mat4d & (Graphic3d_Camera::*)() const) &Graphic3d_Camera::OrientationMatrix, "Get orientation matrix.");
cls_Graphic3d_Camera.def("OrientationMatrixF", (const Graphic3d_Mat4 & (Graphic3d_Camera::*)() const) &Graphic3d_Camera::OrientationMatrixF, "Get orientation matrix of Standard_ShortReal precision.");
cls_Graphic3d_Camera.def("ProjectionMatrix", (const Graphic3d_Mat4d & (Graphic3d_Camera::*)() const) &Graphic3d_Camera::ProjectionMatrix, "Get monographic or middle point projection matrix used for monographic rendering and for point projection / unprojection.");
cls_Graphic3d_Camera.def("ProjectionMatrixF", (const Graphic3d_Mat4 & (Graphic3d_Camera::*)() const) &Graphic3d_Camera::ProjectionMatrixF, "Get monographic or middle point projection matrix of Standard_ShortReal precision used for monographic rendering and for point projection / unprojection.");
cls_Graphic3d_Camera.def("ProjectionStereoLeft", (const Graphic3d_Mat4d & (Graphic3d_Camera::*)() const) &Graphic3d_Camera::ProjectionStereoLeft, "Returns stereographic matrix computed for left eye. Please note that this method is used for rendering for Projection_Stereo.");
cls_Graphic3d_Camera.def("ProjectionStereoLeftF", (const Graphic3d_Mat4 & (Graphic3d_Camera::*)() const) &Graphic3d_Camera::ProjectionStereoLeftF, "Returns stereographic matrix of Standard_ShortReal precision computed for left eye. Please note that this method is used for rendering for Projection_Stereo.");
cls_Graphic3d_Camera.def("ProjectionStereoRight", (const Graphic3d_Mat4d & (Graphic3d_Camera::*)() const) &Graphic3d_Camera::ProjectionStereoRight, "Returns stereographic matrix computed for right eye. Please note that this method is used for rendering for Projection_Stereo.");
cls_Graphic3d_Camera.def("ProjectionStereoRightF", (const Graphic3d_Mat4 & (Graphic3d_Camera::*)() const) &Graphic3d_Camera::ProjectionStereoRightF, "Returns stereographic matrix of Standard_ShortReal precision computed for right eye. Please note that this method is used for rendering for Projection_Stereo.");
cls_Graphic3d_Camera.def("InvalidateProjection", (void (Graphic3d_Camera::*)()) &Graphic3d_Camera::InvalidateProjection, "Invalidate state of projection matrix. The matrix will be updated on request.");
cls_Graphic3d_Camera.def("InvalidateOrientation", (void (Graphic3d_Camera::*)()) &Graphic3d_Camera::InvalidateOrientation, "Invalidate orientation matrix. The matrix will be updated on request.");
cls_Graphic3d_Camera.def_static("get_type_name_", (const char * (*)()) &Graphic3d_Camera::get_type_name, "None");
cls_Graphic3d_Camera.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_Camera::get_type_descriptor, "None");
cls_Graphic3d_Camera.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_Camera::*)() const) &Graphic3d_Camera::DynamicType, "None");

// Enums
py::enum_<Graphic3d_Camera::Projection>(cls_Graphic3d_Camera, "Projection", "Enumerates supported monographic projections. - Projection_Orthographic : orthographic projection. - Projection_Perspective : perspective projection. - Projection_Stereo : stereographic projection. - Projection_MonoLeftEye : mono projection for stereo left eye. - Projection_MonoRightEye : mono projection for stereo right eye.")
	.value("Projection_Orthographic", Graphic3d_Camera::Projection::Projection_Orthographic)
	.value("Projection_Perspective", Graphic3d_Camera::Projection::Projection_Perspective)
	.value("Projection_Stereo", Graphic3d_Camera::Projection::Projection_Stereo)
	.value("Projection_MonoLeftEye", Graphic3d_Camera::Projection::Projection_MonoLeftEye)
	.value("Projection_MonoRightEye", Graphic3d_Camera::Projection::Projection_MonoRightEye)
	.export_values();
py::enum_<Graphic3d_Camera::FocusType>(cls_Graphic3d_Camera, "FocusType", "Enumerates approaches to define stereographic focus. - FocusType_Absolute : focus is specified as absolute value. - FocusType_Relative : focus is specified relative to (as coefficient of) camera focal length.")
	.value("FocusType_Absolute", Graphic3d_Camera::FocusType::FocusType_Absolute)
	.value("FocusType_Relative", Graphic3d_Camera::FocusType::FocusType_Relative)
	.export_values();
py::enum_<Graphic3d_Camera::IODType>(cls_Graphic3d_Camera, "IODType", "Enumerates approaches to define Intraocular distance. - IODType_Absolute : Intraocular distance is defined as absolute value. - IODType_Relative : Intraocular distance is defined relative to (as coefficient of) camera focal length.")
	.value("IODType_Absolute", Graphic3d_Camera::IODType::IODType_Absolute)
	.value("IODType_Relative", Graphic3d_Camera::IODType::IODType_Relative)
	.export_values();

}