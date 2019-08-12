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
#include <Standard_Handle.hxx>
#include <IGESGeom_Point.hxx>
#include <IGESGeom_Direction.hxx>
#include <Standard_TypeDef.hxx>
#include <IGESSolid_ConicalSurface.hxx>
#include <Standard_Type.hxx>

void bind_IGESSolid_ConicalSurface(py::module &mod){

py::class_<IGESSolid_ConicalSurface, opencascade::handle<IGESSolid_ConicalSurface>, IGESData_IGESEntity> cls_IGESSolid_ConicalSurface(mod, "IGESSolid_ConicalSurface", "defines ConicalSurface, Type <194> Form Number <0,1> in package IGESSolid The right circular conical surface is defined by a point on the axis on the cone, the direction of the axis of the cone, the radius of the cone at the axis point and the cone semi-angle.");

// Constructors
cls_IGESSolid_ConicalSurface.def(py::init<>());

// Fields

// Methods
cls_IGESSolid_ConicalSurface.def("Init", (void (IGESSolid_ConicalSurface::*)(const opencascade::handle<IGESGeom_Point> &, const opencascade::handle<IGESGeom_Direction> &, const Standard_Real, const Standard_Real, const opencascade::handle<IGESGeom_Direction> &)) &IGESSolid_ConicalSurface::Init, "This method is used to set the fields of the class ConicalSurface - aLocation : Location of the point on axis - anAxis : Direction of the axis - aRadius : Radius at axis point - anAngle : Value of semi-angle in degrees (0<angle<90) - aRefdir : Reference direction (parametrised surface) Null if unparametrised surface.", py::arg("aLocation"), py::arg("anAxis"), py::arg("aRadius"), py::arg("anAngle"), py::arg("aRefdir"));
cls_IGESSolid_ConicalSurface.def("LocationPoint", (opencascade::handle<IGESGeom_Point> (IGESSolid_ConicalSurface::*)() const) &IGESSolid_ConicalSurface::LocationPoint, "returns the location of the point on the axis");
cls_IGESSolid_ConicalSurface.def("Axis", (opencascade::handle<IGESGeom_Direction> (IGESSolid_ConicalSurface::*)() const) &IGESSolid_ConicalSurface::Axis, "returns the direction of the axis");
cls_IGESSolid_ConicalSurface.def("Radius", (Standard_Real (IGESSolid_ConicalSurface::*)() const) &IGESSolid_ConicalSurface::Radius, "returns the radius at the axis point");
cls_IGESSolid_ConicalSurface.def("SemiAngle", (Standard_Real (IGESSolid_ConicalSurface::*)() const) &IGESSolid_ConicalSurface::SemiAngle, "returns the semi-angle value");
cls_IGESSolid_ConicalSurface.def("ReferenceDir", (opencascade::handle<IGESGeom_Direction> (IGESSolid_ConicalSurface::*)() const) &IGESSolid_ConicalSurface::ReferenceDir, "returns the reference direction of the conical surface in case of parametrised surface. For unparametrised surface it returns NULL.");
cls_IGESSolid_ConicalSurface.def("IsParametrised", (Standard_Boolean (IGESSolid_ConicalSurface::*)() const) &IGESSolid_ConicalSurface::IsParametrised, "returns True if Form no is 1 else false");
cls_IGESSolid_ConicalSurface.def_static("get_type_name_", (const char * (*)()) &IGESSolid_ConicalSurface::get_type_name, "None");
cls_IGESSolid_ConicalSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSolid_ConicalSurface::get_type_descriptor, "None");
cls_IGESSolid_ConicalSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSolid_ConicalSurface::*)() const) &IGESSolid_ConicalSurface::DynamicType, "None");

// Enums

}