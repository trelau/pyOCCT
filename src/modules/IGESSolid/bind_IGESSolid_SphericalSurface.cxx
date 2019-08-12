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
#include <Standard_TypeDef.hxx>
#include <IGESGeom_Direction.hxx>
#include <gp_Pnt.hxx>
#include <IGESSolid_SphericalSurface.hxx>
#include <Standard_Type.hxx>

void bind_IGESSolid_SphericalSurface(py::module &mod){

py::class_<IGESSolid_SphericalSurface, opencascade::handle<IGESSolid_SphericalSurface>, IGESData_IGESEntity> cls_IGESSolid_SphericalSurface(mod, "IGESSolid_SphericalSurface", "defines SphericalSurface, Type <196> Form Number <0,1> in package IGESSolid Spherical surface is defined by a center and radius. In case of parametrised surface an axis and a reference direction is provided.");

// Constructors
cls_IGESSolid_SphericalSurface.def(py::init<>());

// Fields

// Methods
cls_IGESSolid_SphericalSurface.def("Init", (void (IGESSolid_SphericalSurface::*)(const opencascade::handle<IGESGeom_Point> &, const Standard_Real, const opencascade::handle<IGESGeom_Direction> &, const opencascade::handle<IGESGeom_Direction> &)) &IGESSolid_SphericalSurface::Init, "This method is used to set the fields of the class SphericalSurface - aCenter : the coordinates of the center point - aRadius : value of radius - anAxis : the direction of the axis Null in case of Unparametrised surface - aRefdir : the reference direction Null in case of Unparametrised surface", py::arg("aCenter"), py::arg("aRadius"), py::arg("anAxis"), py::arg("aRefdir"));
cls_IGESSolid_SphericalSurface.def("Center", (opencascade::handle<IGESGeom_Point> (IGESSolid_SphericalSurface::*)() const) &IGESSolid_SphericalSurface::Center, "returns the center of the spherical surface");
cls_IGESSolid_SphericalSurface.def("TransformedCenter", (gp_Pnt (IGESSolid_SphericalSurface::*)() const) &IGESSolid_SphericalSurface::TransformedCenter, "returns the center of the spherical surface after applying TransformationMatrix");
cls_IGESSolid_SphericalSurface.def("Radius", (Standard_Real (IGESSolid_SphericalSurface::*)() const) &IGESSolid_SphericalSurface::Radius, "returns the radius of the spherical surface");
cls_IGESSolid_SphericalSurface.def("Axis", (opencascade::handle<IGESGeom_Direction> (IGESSolid_SphericalSurface::*)() const) &IGESSolid_SphericalSurface::Axis, "returns the direction of the axis (Parametrised surface) Null is returned if the surface is not parametrised");
cls_IGESSolid_SphericalSurface.def("ReferenceDir", (opencascade::handle<IGESGeom_Direction> (IGESSolid_SphericalSurface::*)() const) &IGESSolid_SphericalSurface::ReferenceDir, "returns the reference direction (Parametrised surface) Null is returned if the surface is not parametrised");
cls_IGESSolid_SphericalSurface.def("IsParametrised", (Standard_Boolean (IGESSolid_SphericalSurface::*)() const) &IGESSolid_SphericalSurface::IsParametrised, "Returns True if the surface is parametrised, else False");
cls_IGESSolid_SphericalSurface.def_static("get_type_name_", (const char * (*)()) &IGESSolid_SphericalSurface::get_type_name, "None");
cls_IGESSolid_SphericalSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSolid_SphericalSurface::get_type_descriptor, "None");
cls_IGESSolid_SphericalSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSolid_SphericalSurface::*)() const) &IGESSolid_SphericalSurface::DynamicType, "None");

// Enums

}