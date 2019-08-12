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
#include <gp_XYZ.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <gp_Vec.hxx>
#include <IGESGeom_OffsetSurface.hxx>
#include <Standard_Type.hxx>

void bind_IGESGeom_OffsetSurface(py::module &mod){

py::class_<IGESGeom_OffsetSurface, opencascade::handle<IGESGeom_OffsetSurface>, IGESData_IGESEntity> cls_IGESGeom_OffsetSurface(mod, "IGESGeom_OffsetSurface", "defines IGESOffsetSurface, Type <140> Form <0> in package IGESGeom An offset surface is a surface defined in terms of an already existing surface.If S(u, v) is a parametrised regular surface and N(u, v) is a differential field of unit normal vectors defined on the whole surface, and 'd' a fixed non zero real number, then offset surface to S is a parametrised surface S(u, v) given by O(u, v) = S(u, v) + d * N(u, v); u1 <= u <= u2; v1 <= v <= v2;");

// Constructors
cls_IGESGeom_OffsetSurface.def(py::init<>());

// Fields

// Methods
cls_IGESGeom_OffsetSurface.def("Init", (void (IGESGeom_OffsetSurface::*)(const gp_XYZ &, const Standard_Real, const opencascade::handle<IGESData_IGESEntity> &)) &IGESGeom_OffsetSurface::Init, "This method is used to set the fields of the class OffsetSurface - anIndicator : Offset indicator - aDistance : Offset distance - aSurface : Surface that is offset", py::arg("anIndicatoR"), py::arg("aDistance"), py::arg("aSurface"));
cls_IGESGeom_OffsetSurface.def("OffsetIndicator", (gp_Vec (IGESGeom_OffsetSurface::*)() const) &IGESGeom_OffsetSurface::OffsetIndicator, "returns the offset indicator");
cls_IGESGeom_OffsetSurface.def("TransformedOffsetIndicator", (gp_Vec (IGESGeom_OffsetSurface::*)() const) &IGESGeom_OffsetSurface::TransformedOffsetIndicator, "returns the offset indicator after applying Transf. Matrix");
cls_IGESGeom_OffsetSurface.def("Distance", (Standard_Real (IGESGeom_OffsetSurface::*)() const) &IGESGeom_OffsetSurface::Distance, "returns the distance by which surface is offset");
cls_IGESGeom_OffsetSurface.def("Surface", (opencascade::handle<IGESData_IGESEntity> (IGESGeom_OffsetSurface::*)() const) &IGESGeom_OffsetSurface::Surface, "returns the surface that has been offset");
cls_IGESGeom_OffsetSurface.def_static("get_type_name_", (const char * (*)()) &IGESGeom_OffsetSurface::get_type_name, "None");
cls_IGESGeom_OffsetSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESGeom_OffsetSurface::get_type_descriptor, "None");
cls_IGESGeom_OffsetSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESGeom_OffsetSurface::*)() const) &IGESGeom_OffsetSurface::DynamicType, "None");

// Enums

}