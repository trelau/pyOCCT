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
#include <IGESData_IGESEntity.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <IGESGeom_CurveOnSurface.hxx>
#include <Standard_Type.hxx>

void bind_IGESGeom_CurveOnSurface(py::module &mod){

py::class_<IGESGeom_CurveOnSurface, opencascade::handle<IGESGeom_CurveOnSurface>, IGESData_IGESEntity> cls_IGESGeom_CurveOnSurface(mod, "IGESGeom_CurveOnSurface", "defines IGESCurveOnSurface, Type <142> Form <0> in package IGESGeom A curve on a parametric surface entity associates a given curve with a surface and identifies the curve as lying on the surface.");

// Constructors
cls_IGESGeom_CurveOnSurface.def(py::init<>());

// Fields

// Methods
cls_IGESGeom_CurveOnSurface.def("Init", (void (IGESGeom_CurveOnSurface::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, const opencascade::handle<IGESData_IGESEntity> &, const opencascade::handle<IGESData_IGESEntity> &, const Standard_Integer)) &IGESGeom_CurveOnSurface::Init, "This method is used to set the fields of the class CurveOnSurface - aMode : Way the curve on the surface has been created - aSurface : Surface on which the curve lies - aCurveUV : Curve S (UV) - aCurve3D : Curve C (3D) - aPreference : 0 = Unspecified 1 = S o B is preferred 2 = C is preferred 3 = C and S o B are equally preferred", py::arg("aMode"), py::arg("aSurface"), py::arg("aCurveUV"), py::arg("aCurve3D"), py::arg("aPreference"));
cls_IGESGeom_CurveOnSurface.def("CreationMode", (Standard_Integer (IGESGeom_CurveOnSurface::*)() const) &IGESGeom_CurveOnSurface::CreationMode, "returns the mode in which the curve is created on the surface 0 = Unspecified 1 = Projection of a given curve on the surface 2 = Intersection of two surfaces 3 = Isoparametric curve, i.e:- either a `u` parametric or a `v` parametric curve");
cls_IGESGeom_CurveOnSurface.def("Surface", (opencascade::handle<IGESData_IGESEntity> (IGESGeom_CurveOnSurface::*)() const) &IGESGeom_CurveOnSurface::Surface, "returns the surface on which the curve lies");
cls_IGESGeom_CurveOnSurface.def("CurveUV", (opencascade::handle<IGESData_IGESEntity> (IGESGeom_CurveOnSurface::*)() const) &IGESGeom_CurveOnSurface::CurveUV, "returns curve S");
cls_IGESGeom_CurveOnSurface.def("Curve3D", (opencascade::handle<IGESData_IGESEntity> (IGESGeom_CurveOnSurface::*)() const) &IGESGeom_CurveOnSurface::Curve3D, "returns curve C");
cls_IGESGeom_CurveOnSurface.def("PreferenceMode", (Standard_Integer (IGESGeom_CurveOnSurface::*)() const) &IGESGeom_CurveOnSurface::PreferenceMode, "returns preference mode 0 = Unspecified 1 = S o B is preferred 2 = C is preferred 3 = C and S o B are equally preferred");
cls_IGESGeom_CurveOnSurface.def_static("get_type_name_", (const char * (*)()) &IGESGeom_CurveOnSurface::get_type_name, "None");
cls_IGESGeom_CurveOnSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESGeom_CurveOnSurface::get_type_descriptor, "None");
cls_IGESGeom_CurveOnSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESGeom_CurveOnSurface::*)() const) &IGESGeom_CurveOnSurface::DynamicType, "None");

// Enums

}