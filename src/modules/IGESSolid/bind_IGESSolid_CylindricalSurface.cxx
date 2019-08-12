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
#include <IGESSolid_CylindricalSurface.hxx>
#include <Standard_Type.hxx>

void bind_IGESSolid_CylindricalSurface(py::module &mod){

py::class_<IGESSolid_CylindricalSurface, opencascade::handle<IGESSolid_CylindricalSurface>, IGESData_IGESEntity> cls_IGESSolid_CylindricalSurface(mod, "IGESSolid_CylindricalSurface", "defines CylindricalSurface, Type <192> Form Number <0,1> in package IGESSolid");

// Constructors
cls_IGESSolid_CylindricalSurface.def(py::init<>());

// Fields

// Methods
cls_IGESSolid_CylindricalSurface.def("Init", (void (IGESSolid_CylindricalSurface::*)(const opencascade::handle<IGESGeom_Point> &, const opencascade::handle<IGESGeom_Direction> &, const Standard_Real, const opencascade::handle<IGESGeom_Direction> &)) &IGESSolid_CylindricalSurface::Init, "This method is used to set the fields of the class CylindricalSurface - aLocation : the location of the point on axis - anAxis : the direction of the axis - aRadius : the radius at the axis point - aRefdir : the reference direction (parametrised surface) default NULL (unparametrised surface)", py::arg("aLocation"), py::arg("anAxis"), py::arg("aRadius"), py::arg("aRefdir"));
cls_IGESSolid_CylindricalSurface.def("LocationPoint", (opencascade::handle<IGESGeom_Point> (IGESSolid_CylindricalSurface::*)() const) &IGESSolid_CylindricalSurface::LocationPoint, "returns the point on the axis");
cls_IGESSolid_CylindricalSurface.def("Axis", (opencascade::handle<IGESGeom_Direction> (IGESSolid_CylindricalSurface::*)() const) &IGESSolid_CylindricalSurface::Axis, "returns the direction on the axis");
cls_IGESSolid_CylindricalSurface.def("Radius", (Standard_Real (IGESSolid_CylindricalSurface::*)() const) &IGESSolid_CylindricalSurface::Radius, "returns the radius at the axis point");
cls_IGESSolid_CylindricalSurface.def("IsParametrised", (Standard_Boolean (IGESSolid_CylindricalSurface::*)() const) &IGESSolid_CylindricalSurface::IsParametrised, "returns whether the surface is parametrised or not");
cls_IGESSolid_CylindricalSurface.def("ReferenceDir", (opencascade::handle<IGESGeom_Direction> (IGESSolid_CylindricalSurface::*)() const) &IGESSolid_CylindricalSurface::ReferenceDir, "returns the reference direction only for parametrised surface else returns NULL");
cls_IGESSolid_CylindricalSurface.def_static("get_type_name_", (const char * (*)()) &IGESSolid_CylindricalSurface::get_type_name, "None");
cls_IGESSolid_CylindricalSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSolid_CylindricalSurface::get_type_descriptor, "None");
cls_IGESSolid_CylindricalSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSolid_CylindricalSurface::*)() const) &IGESSolid_CylindricalSurface::DynamicType, "None");

// Enums

}