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
#include <gp_Pnt.hxx>
#include <IGESSolid_ToroidalSurface.hxx>
#include <Standard_Type.hxx>

void bind_IGESSolid_ToroidalSurface(py::module &mod){

py::class_<IGESSolid_ToroidalSurface, opencascade::handle<IGESSolid_ToroidalSurface>, IGESData_IGESEntity> cls_IGESSolid_ToroidalSurface(mod, "IGESSolid_ToroidalSurface", "defines ToroidalSurface, Type <198> Form Number <0,1> in package IGESSolid This entity is defined by the center point, the axis direction and the major and minor radii. In case of parametrised surface a reference direction is provided.");

// Constructors
cls_IGESSolid_ToroidalSurface.def(py::init<>());

// Fields

// Methods
cls_IGESSolid_ToroidalSurface.def("Init", (void (IGESSolid_ToroidalSurface::*)(const opencascade::handle<IGESGeom_Point> &, const opencascade::handle<IGESGeom_Direction> &, const Standard_Real, const Standard_Real, const opencascade::handle<IGESGeom_Direction> &)) &IGESSolid_ToroidalSurface::Init, "This method is used to set the fields of the class ToroidalSurface - aCenter : the center point coordinates - anAxis : the direction of the axis - majRadius : the major radius - minRadius : the minor radius - Refdir : the reference direction (parametrised) default Null for unparametrised surface", py::arg("aCenter"), py::arg("anAxis"), py::arg("majRadius"), py::arg("minRadius"), py::arg("Refdir"));
cls_IGESSolid_ToroidalSurface.def("Center", (opencascade::handle<IGESGeom_Point> (IGESSolid_ToroidalSurface::*)() const) &IGESSolid_ToroidalSurface::Center, "returns the center point coordinates of the surface");
cls_IGESSolid_ToroidalSurface.def("TransformedCenter", (gp_Pnt (IGESSolid_ToroidalSurface::*)() const) &IGESSolid_ToroidalSurface::TransformedCenter, "returns the center point coordinates of the surface after applying TransformationMatrix");
cls_IGESSolid_ToroidalSurface.def("Axis", (opencascade::handle<IGESGeom_Direction> (IGESSolid_ToroidalSurface::*)() const) &IGESSolid_ToroidalSurface::Axis, "returns the direction of the axis");
cls_IGESSolid_ToroidalSurface.def("MajorRadius", (Standard_Real (IGESSolid_ToroidalSurface::*)() const) &IGESSolid_ToroidalSurface::MajorRadius, "returns the major radius of the surface");
cls_IGESSolid_ToroidalSurface.def("MinorRadius", (Standard_Real (IGESSolid_ToroidalSurface::*)() const) &IGESSolid_ToroidalSurface::MinorRadius, "returns the minor radius of the surface");
cls_IGESSolid_ToroidalSurface.def("ReferenceDir", (opencascade::handle<IGESGeom_Direction> (IGESSolid_ToroidalSurface::*)() const) &IGESSolid_ToroidalSurface::ReferenceDir, "returns the reference direction (parametrised surface) Null is returned if the surface is not parametrised");
cls_IGESSolid_ToroidalSurface.def("IsParametrised", (Standard_Boolean (IGESSolid_ToroidalSurface::*)() const) &IGESSolid_ToroidalSurface::IsParametrised, "Returns True if the surface is parametrised, else False");
cls_IGESSolid_ToroidalSurface.def_static("get_type_name_", (const char * (*)()) &IGESSolid_ToroidalSurface::get_type_name, "None");
cls_IGESSolid_ToroidalSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSolid_ToroidalSurface::get_type_descriptor, "None");
cls_IGESSolid_ToroidalSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSolid_ToroidalSurface::*)() const) &IGESSolid_ToroidalSurface::DynamicType, "None");

// Enums

}