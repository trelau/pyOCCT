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
#include <Geom_Surface.hxx>
#include <Standard_Handle.hxx>
#include <TColGeom_HArray2OfSurface.hxx>
#include <ShapeExtend_Parametrisation.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <Standard_TypeDef.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Trsf2d.hxx>
#include <gp_Trsf.hxx>
#include <Geom_Geometry.hxx>
#include <Geom_Curve.hxx>
#include <GeomAbs_Shape.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <ShapeExtend_CompositeSurface.hxx>
#include <Standard_Type.hxx>

void bind_ShapeExtend_CompositeSurface(py::module &mod){

py::class_<ShapeExtend_CompositeSurface, opencascade::handle<ShapeExtend_CompositeSurface>, Geom_Surface> cls_ShapeExtend_CompositeSurface(mod, "ShapeExtend_CompositeSurface", "Composite surface is represented by a grid of surfaces (patches) connected geometrically. Patches may have different parametrisation ranges, but they should be parametrised in the same manner so that parameter of each patch (u,v) can be converted to global parameter on the whole surface (U,V) with help of linear transformation:");

// Constructors
cls_ShapeExtend_CompositeSurface.def(py::init<>());
cls_ShapeExtend_CompositeSurface.def(py::init<const opencascade::handle<TColGeom_HArray2OfSurface> &>(), py::arg("GridSurf"));
cls_ShapeExtend_CompositeSurface.def(py::init<const opencascade::handle<TColGeom_HArray2OfSurface> &, const ShapeExtend_Parametrisation>(), py::arg("GridSurf"), py::arg("param"));
cls_ShapeExtend_CompositeSurface.def(py::init<const opencascade::handle<TColGeom_HArray2OfSurface> &, const TColStd_Array1OfReal &, const TColStd_Array1OfReal &>(), py::arg("GridSurf"), py::arg("UJoints"), py::arg("VJoints"));

// Fields

// Methods
cls_ShapeExtend_CompositeSurface.def("Init", [](ShapeExtend_CompositeSurface &self, const opencascade::handle<TColGeom_HArray2OfSurface> & a0) -> Standard_Boolean { return self.Init(a0); });
cls_ShapeExtend_CompositeSurface.def("Init", (Standard_Boolean (ShapeExtend_CompositeSurface::*)(const opencascade::handle<TColGeom_HArray2OfSurface> &, const ShapeExtend_Parametrisation)) &ShapeExtend_CompositeSurface::Init, "Initializes by a grid of surfaces. All the Surfaces of the grid must have geometrical connectivity as stated above. If geometrical connectivity is not satisfied, method returns False. However, class is initialized even in that case.", py::arg("GridSurf"), py::arg("param"));
cls_ShapeExtend_CompositeSurface.def("Init", (Standard_Boolean (ShapeExtend_CompositeSurface::*)(const opencascade::handle<TColGeom_HArray2OfSurface> &, const TColStd_Array1OfReal &, const TColStd_Array1OfReal &)) &ShapeExtend_CompositeSurface::Init, "Initializes by a grid of surfaces with given global parametrisation defined by UJoints and VJoints arrays, each having langth equal to number of patches in corresponding direction + 1. Global joint values should be sorted in increasing order. All the Surfaces of the grid must have geometrical connectivity as stated above. If geometrical connectivity is not satisfied, method returns False. However, class is initialized even in that case.", py::arg("GridSurf"), py::arg("UJoints"), py::arg("VJoints"));
cls_ShapeExtend_CompositeSurface.def("NbUPatches", (Standard_Integer (ShapeExtend_CompositeSurface::*)() const) &ShapeExtend_CompositeSurface::NbUPatches, "Returns number of patches in U direction.");
cls_ShapeExtend_CompositeSurface.def("NbVPatches", (Standard_Integer (ShapeExtend_CompositeSurface::*)() const) &ShapeExtend_CompositeSurface::NbVPatches, "Returns number of patches in V direction.");
cls_ShapeExtend_CompositeSurface.def("Patch", (const opencascade::handle<Geom_Surface> & (ShapeExtend_CompositeSurface::*)(const Standard_Integer, const Standard_Integer) const) &ShapeExtend_CompositeSurface::Patch, "Returns one surface patch", py::arg("i"), py::arg("j"));
cls_ShapeExtend_CompositeSurface.def("Patches", (const opencascade::handle<TColGeom_HArray2OfSurface> & (ShapeExtend_CompositeSurface::*)() const) &ShapeExtend_CompositeSurface::Patches, "Returns grid of surfaces");
cls_ShapeExtend_CompositeSurface.def("UJointValues", (opencascade::handle<TColStd_HArray1OfReal> (ShapeExtend_CompositeSurface::*)() const) &ShapeExtend_CompositeSurface::UJointValues, "Returns the array of U values corresponding to joint points between patches as well as to start and end points, which define global parametrisation of the surface");
cls_ShapeExtend_CompositeSurface.def("VJointValues", (opencascade::handle<TColStd_HArray1OfReal> (ShapeExtend_CompositeSurface::*)() const) &ShapeExtend_CompositeSurface::VJointValues, "Returns the array of V values corresponding to joint points between patches as well as to start and end points, which define global parametrisation of the surface");
cls_ShapeExtend_CompositeSurface.def("UJointValue", (Standard_Real (ShapeExtend_CompositeSurface::*)(const Standard_Integer) const) &ShapeExtend_CompositeSurface::UJointValue, "Returns i-th joint value in U direction (1-st is global Umin, (NbUPatches()+1)-th is global Umax on the composite surface)", py::arg("i"));
cls_ShapeExtend_CompositeSurface.def("VJointValue", (Standard_Real (ShapeExtend_CompositeSurface::*)(const Standard_Integer) const) &ShapeExtend_CompositeSurface::VJointValue, "Returns j-th joint value in V direction (1-st is global Vmin, (NbVPatches()+1)-th is global Vmax on the composite surface)", py::arg("j"));
cls_ShapeExtend_CompositeSurface.def("SetUJointValues", (Standard_Boolean (ShapeExtend_CompositeSurface::*)(const TColStd_Array1OfReal &)) &ShapeExtend_CompositeSurface::SetUJointValues, "Sets the array of U values corresponding to joint points, which define global parametrisation of the surface. Number of values in array should be equal to NbUPatches()+1. All the values should be sorted in increasing order. If this is not satisfied, does nothing and returns False.", py::arg("UJoints"));
cls_ShapeExtend_CompositeSurface.def("SetVJointValues", (Standard_Boolean (ShapeExtend_CompositeSurface::*)(const TColStd_Array1OfReal &)) &ShapeExtend_CompositeSurface::SetVJointValues, "Sets the array of V values corresponding to joint points, which define global parametrisation of the surface Number of values in array should be equal to NbVPatches()+1. All the values should be sorted in increasing order. If this is not satisfied, does nothing and returns False.", py::arg("VJoints"));
cls_ShapeExtend_CompositeSurface.def("SetUFirstValue", (void (ShapeExtend_CompositeSurface::*)(const Standard_Real)) &ShapeExtend_CompositeSurface::SetUFirstValue, "Changes starting value for global U parametrisation (all other joint values are shifted accordingly)", py::arg("UFirst"));
cls_ShapeExtend_CompositeSurface.def("SetVFirstValue", (void (ShapeExtend_CompositeSurface::*)(const Standard_Real)) &ShapeExtend_CompositeSurface::SetVFirstValue, "Changes starting value for global V parametrisation (all other joint values are shifted accordingly)", py::arg("VFirst"));
cls_ShapeExtend_CompositeSurface.def("LocateUParameter", (Standard_Integer (ShapeExtend_CompositeSurface::*)(const Standard_Real) const) &ShapeExtend_CompositeSurface::LocateUParameter, "Returns number of col that contains given (global) parameter", py::arg("U"));
cls_ShapeExtend_CompositeSurface.def("LocateVParameter", (Standard_Integer (ShapeExtend_CompositeSurface::*)(const Standard_Real) const) &ShapeExtend_CompositeSurface::LocateVParameter, "Returns number of row that contains given (global) parameter", py::arg("V"));
cls_ShapeExtend_CompositeSurface.def("LocateUVPoint", [](ShapeExtend_CompositeSurface &self, const gp_Pnt2d & pnt, Standard_Integer & i, Standard_Integer & j){ self.LocateUVPoint(pnt, i, j); return std::tuple<Standard_Integer &, Standard_Integer &>(i, j); }, "Returns number of row and col of surface that contains given point", py::arg("pnt"), py::arg("i"), py::arg("j"));
cls_ShapeExtend_CompositeSurface.def("Patch", (const opencascade::handle<Geom_Surface> & (ShapeExtend_CompositeSurface::*)(const Standard_Real, const Standard_Real) const) &ShapeExtend_CompositeSurface::Patch, "Returns one surface patch that contains given (global) parameters", py::arg("U"), py::arg("V"));
cls_ShapeExtend_CompositeSurface.def("Patch", (const opencascade::handle<Geom_Surface> & (ShapeExtend_CompositeSurface::*)(const gp_Pnt2d &) const) &ShapeExtend_CompositeSurface::Patch, "Returns one surface patch that contains given point", py::arg("pnt"));
cls_ShapeExtend_CompositeSurface.def("ULocalToGlobal", (Standard_Real (ShapeExtend_CompositeSurface::*)(const Standard_Integer, const Standard_Integer, const Standard_Real) const) &ShapeExtend_CompositeSurface::ULocalToGlobal, "Converts local parameter u on patch i,j to global parameter U", py::arg("i"), py::arg("j"), py::arg("u"));
cls_ShapeExtend_CompositeSurface.def("VLocalToGlobal", (Standard_Real (ShapeExtend_CompositeSurface::*)(const Standard_Integer, const Standard_Integer, const Standard_Real) const) &ShapeExtend_CompositeSurface::VLocalToGlobal, "Converts local parameter v on patch i,j to global parameter V", py::arg("i"), py::arg("j"), py::arg("v"));
cls_ShapeExtend_CompositeSurface.def("LocalToGlobal", (gp_Pnt2d (ShapeExtend_CompositeSurface::*)(const Standard_Integer, const Standard_Integer, const gp_Pnt2d &) const) &ShapeExtend_CompositeSurface::LocalToGlobal, "Converts local parameters uv on patch i,j to global parameters UV", py::arg("i"), py::arg("j"), py::arg("uv"));
cls_ShapeExtend_CompositeSurface.def("UGlobalToLocal", (Standard_Real (ShapeExtend_CompositeSurface::*)(const Standard_Integer, const Standard_Integer, const Standard_Real) const) &ShapeExtend_CompositeSurface::UGlobalToLocal, "Converts global parameter U to local parameter u on patch i,j", py::arg("i"), py::arg("j"), py::arg("U"));
cls_ShapeExtend_CompositeSurface.def("VGlobalToLocal", (Standard_Real (ShapeExtend_CompositeSurface::*)(const Standard_Integer, const Standard_Integer, const Standard_Real) const) &ShapeExtend_CompositeSurface::VGlobalToLocal, "Converts global parameter V to local parameter v on patch i,j", py::arg("i"), py::arg("j"), py::arg("V"));
cls_ShapeExtend_CompositeSurface.def("GlobalToLocal", (gp_Pnt2d (ShapeExtend_CompositeSurface::*)(const Standard_Integer, const Standard_Integer, const gp_Pnt2d &) const) &ShapeExtend_CompositeSurface::GlobalToLocal, "Converts global parameters UV to local parameters uv on patch i,j", py::arg("i"), py::arg("j"), py::arg("UV"));
cls_ShapeExtend_CompositeSurface.def("GlobalToLocalTransformation", [](ShapeExtend_CompositeSurface &self, const Standard_Integer i, const Standard_Integer j, Standard_Real & uFact, gp_Trsf2d & Trsf){ Standard_Boolean rv = self.GlobalToLocalTransformation(i, j, uFact, Trsf); return std::tuple<Standard_Boolean, Standard_Real &>(rv, uFact); }, "Computes transformation operator and uFactor descrinbing affine transformation required to convert global parameters on composite surface to local parameters on patch (i,j): uv = ( uFactor, 1. ) X Trsf * UV; NOTE: Thus Trsf contains shift and scale by V, scale by U is stored in uFact. Returns True if transformation is not an identity", py::arg("i"), py::arg("j"), py::arg("uFact"), py::arg("Trsf"));
cls_ShapeExtend_CompositeSurface.def("Transform", (void (ShapeExtend_CompositeSurface::*)(const gp_Trsf &)) &ShapeExtend_CompositeSurface::Transform, "Applies transformation to all the patches", py::arg("T"));
cls_ShapeExtend_CompositeSurface.def("Copy", (opencascade::handle<Geom_Geometry> (ShapeExtend_CompositeSurface::*)() const) &ShapeExtend_CompositeSurface::Copy, "Returns a copy of the surface");
cls_ShapeExtend_CompositeSurface.def("UReverse", (void (ShapeExtend_CompositeSurface::*)()) &ShapeExtend_CompositeSurface::UReverse, "NOT IMPLEMENTED (does nothing)");
cls_ShapeExtend_CompositeSurface.def("UReversedParameter", (Standard_Real (ShapeExtend_CompositeSurface::*)(const Standard_Real) const) &ShapeExtend_CompositeSurface::UReversedParameter, "Returns U", py::arg("U"));
cls_ShapeExtend_CompositeSurface.def("VReverse", (void (ShapeExtend_CompositeSurface::*)()) &ShapeExtend_CompositeSurface::VReverse, "NOT IMPLEMENTED (does nothing)");
cls_ShapeExtend_CompositeSurface.def("VReversedParameter", (Standard_Real (ShapeExtend_CompositeSurface::*)(const Standard_Real) const) &ShapeExtend_CompositeSurface::VReversedParameter, "Returns V", py::arg("V"));
cls_ShapeExtend_CompositeSurface.def("Bounds", [](ShapeExtend_CompositeSurface &self, Standard_Real & U1, Standard_Real & U2, Standard_Real & V1, Standard_Real & V2){ self.Bounds(U1, U2, V1, V2); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(U1, U2, V1, V2); }, "Returns the parametric bounds of grid", py::arg("U1"), py::arg("U2"), py::arg("V1"), py::arg("V2"));
cls_ShapeExtend_CompositeSurface.def("IsUClosed", (Standard_Boolean (ShapeExtend_CompositeSurface::*)() const) &ShapeExtend_CompositeSurface::IsUClosed, "Returns True if grid is closed in U direction (i.e. connected with Precision::Confusion)");
cls_ShapeExtend_CompositeSurface.def("IsVClosed", (Standard_Boolean (ShapeExtend_CompositeSurface::*)() const) &ShapeExtend_CompositeSurface::IsVClosed, "Returns True if grid is closed in V direction (i.e. connected with Precision::Confusion)");
cls_ShapeExtend_CompositeSurface.def("IsUPeriodic", (Standard_Boolean (ShapeExtend_CompositeSurface::*)() const) &ShapeExtend_CompositeSurface::IsUPeriodic, "Returns False");
cls_ShapeExtend_CompositeSurface.def("IsVPeriodic", (Standard_Boolean (ShapeExtend_CompositeSurface::*)() const) &ShapeExtend_CompositeSurface::IsVPeriodic, "Returns False");
cls_ShapeExtend_CompositeSurface.def("UIso", (opencascade::handle<Geom_Curve> (ShapeExtend_CompositeSurface::*)(const Standard_Real) const) &ShapeExtend_CompositeSurface::UIso, "NOT IMPLEMENTED (returns Null curve)", py::arg("U"));
cls_ShapeExtend_CompositeSurface.def("VIso", (opencascade::handle<Geom_Curve> (ShapeExtend_CompositeSurface::*)(const Standard_Real) const) &ShapeExtend_CompositeSurface::VIso, "NOT IMPLEMENTED (returns Null curve)", py::arg("V"));
cls_ShapeExtend_CompositeSurface.def("Continuity", (GeomAbs_Shape (ShapeExtend_CompositeSurface::*)() const) &ShapeExtend_CompositeSurface::Continuity, "returns C0");
cls_ShapeExtend_CompositeSurface.def("IsCNu", (Standard_Boolean (ShapeExtend_CompositeSurface::*)(const Standard_Integer) const) &ShapeExtend_CompositeSurface::IsCNu, "returns True if N <=0", py::arg("N"));
cls_ShapeExtend_CompositeSurface.def("IsCNv", (Standard_Boolean (ShapeExtend_CompositeSurface::*)(const Standard_Integer) const) &ShapeExtend_CompositeSurface::IsCNv, "returns True if N <=0", py::arg("N"));
cls_ShapeExtend_CompositeSurface.def("D0", (void (ShapeExtend_CompositeSurface::*)(const Standard_Real, const Standard_Real, gp_Pnt &) const) &ShapeExtend_CompositeSurface::D0, "Computes the point of parameter U,V on the grid.", py::arg("U"), py::arg("V"), py::arg("P"));
cls_ShapeExtend_CompositeSurface.def("D1", (void (ShapeExtend_CompositeSurface::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const) &ShapeExtend_CompositeSurface::D1, "Computes the point P and the first derivatives in the directions U and V at this point.", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"));
cls_ShapeExtend_CompositeSurface.def("D2", (void (ShapeExtend_CompositeSurface::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const) &ShapeExtend_CompositeSurface::D2, "Computes the point P, the first and the second derivatives in the directions U and V at this point.", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"), py::arg("D2U"), py::arg("D2V"), py::arg("D2UV"));
cls_ShapeExtend_CompositeSurface.def("D3", (void (ShapeExtend_CompositeSurface::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const) &ShapeExtend_CompositeSurface::D3, "Computes the point P, the first,the second and the third derivatives in the directions U and V at this point.", py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"), py::arg("D2U"), py::arg("D2V"), py::arg("D2UV"), py::arg("D3U"), py::arg("D3V"), py::arg("D3UUV"), py::arg("D3UVV"));
cls_ShapeExtend_CompositeSurface.def("DN", (gp_Vec (ShapeExtend_CompositeSurface::*)(const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer) const) &ShapeExtend_CompositeSurface::DN, "Computes the derivative of order Nu in the direction U and Nv in the direction V at the point P(U, V).", py::arg("U"), py::arg("V"), py::arg("Nu"), py::arg("Nv"));
cls_ShapeExtend_CompositeSurface.def("Value", (gp_Pnt (ShapeExtend_CompositeSurface::*)(const gp_Pnt2d &) const) &ShapeExtend_CompositeSurface::Value, "Computes the point of parameter pnt on the grid.", py::arg("pnt"));
cls_ShapeExtend_CompositeSurface.def("ComputeJointValues", [](ShapeExtend_CompositeSurface &self) -> void { return self.ComputeJointValues(); });
cls_ShapeExtend_CompositeSurface.def("ComputeJointValues", (void (ShapeExtend_CompositeSurface::*)(const ShapeExtend_Parametrisation)) &ShapeExtend_CompositeSurface::ComputeJointValues, "Computes Joint values according to parameter", py::arg("param"));
cls_ShapeExtend_CompositeSurface.def("CheckConnectivity", (Standard_Boolean (ShapeExtend_CompositeSurface::*)(const Standard_Real)) &ShapeExtend_CompositeSurface::CheckConnectivity, "Checks geometrical connectivity of the patches, including closedness (sets fields muUClosed and myVClosed)", py::arg("prec"));
cls_ShapeExtend_CompositeSurface.def_static("get_type_name_", (const char * (*)()) &ShapeExtend_CompositeSurface::get_type_name, "None");
cls_ShapeExtend_CompositeSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeExtend_CompositeSurface::get_type_descriptor, "None");
cls_ShapeExtend_CompositeSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeExtend_CompositeSurface::*)() const) &ShapeExtend_CompositeSurface::DynamicType, "None");

// Enums

}