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
#include <IGESSolid_PlaneSurface.hxx>
#include <Standard_Type.hxx>

void bind_IGESSolid_PlaneSurface(py::module &mod){

py::class_<IGESSolid_PlaneSurface, opencascade::handle<IGESSolid_PlaneSurface>, IGESData_IGESEntity> cls_IGESSolid_PlaneSurface(mod, "IGESSolid_PlaneSurface", "defines PlaneSurface, Type <190> Form Number <0,1> in package IGESSolid A plane surface entity is defined by a point on the surface and a normal to it.");

// Constructors
cls_IGESSolid_PlaneSurface.def(py::init<>());

// Fields

// Methods
cls_IGESSolid_PlaneSurface.def("Init", (void (IGESSolid_PlaneSurface::*)(const opencascade::handle<IGESGeom_Point> &, const opencascade::handle<IGESGeom_Direction> &, const opencascade::handle<IGESGeom_Direction> &)) &IGESSolid_PlaneSurface::Init, "This method is used to set the fields of the class PlaneSurface - aLocation : the point on the surface - aNormal : the surface normal direction - refdir : the reference direction (default NULL) for unparameterised curves", py::arg("aLocation"), py::arg("aNormal"), py::arg("refdir"));
cls_IGESSolid_PlaneSurface.def("LocationPoint", (opencascade::handle<IGESGeom_Point> (IGESSolid_PlaneSurface::*)() const) &IGESSolid_PlaneSurface::LocationPoint, "returns the point on the surface");
cls_IGESSolid_PlaneSurface.def("Normal", (opencascade::handle<IGESGeom_Direction> (IGESSolid_PlaneSurface::*)() const) &IGESSolid_PlaneSurface::Normal, "returns the normal to the surface");
cls_IGESSolid_PlaneSurface.def("ReferenceDir", (opencascade::handle<IGESGeom_Direction> (IGESSolid_PlaneSurface::*)() const) &IGESSolid_PlaneSurface::ReferenceDir, "returns the reference direction (for parameterised curve) returns NULL for unparameterised curve");
cls_IGESSolid_PlaneSurface.def("IsParametrised", (Standard_Boolean (IGESSolid_PlaneSurface::*)() const) &IGESSolid_PlaneSurface::IsParametrised, "returns True if parameterised, else False");
cls_IGESSolid_PlaneSurface.def_static("get_type_name_", (const char * (*)()) &IGESSolid_PlaneSurface::get_type_name, "None");
cls_IGESSolid_PlaneSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSolid_PlaneSurface::get_type_descriptor, "None");
cls_IGESSolid_PlaneSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSolid_PlaneSurface::*)() const) &IGESSolid_PlaneSurface::DynamicType, "None");

// Enums

}