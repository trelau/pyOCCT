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
#include <IGESGeom_HArray1OfBoundary.hxx>
#include <IGESGeom_Boundary.hxx>
#include <IGESGeom_BoundedSurface.hxx>
#include <Standard_Type.hxx>

void bind_IGESGeom_BoundedSurface(py::module &mod){

py::class_<IGESGeom_BoundedSurface, opencascade::handle<IGESGeom_BoundedSurface>, IGESData_IGESEntity> cls_IGESGeom_BoundedSurface(mod, "IGESGeom_BoundedSurface", "defines BoundedSurface, Type <143> Form <0> in package IGESGeom A bounded surface is used to communicate trimmed surfaces. The surface and trimming curves are assumed to be represented parametrically.");

// Constructors
cls_IGESGeom_BoundedSurface.def(py::init<>());

// Fields

// Methods
cls_IGESGeom_BoundedSurface.def("Init", (void (IGESGeom_BoundedSurface::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, const opencascade::handle<IGESGeom_HArray1OfBoundary> &)) &IGESGeom_BoundedSurface::Init, "This method is used to set the fields of the class BoundedSurface - aType : Type of bounded surface representation - aSurface : Surface entity to be bounded - allBounds : Array of boundary entities", py::arg("aType"), py::arg("aSurface"), py::arg("allBounds"));
cls_IGESGeom_BoundedSurface.def("RepresentationType", (Standard_Integer (IGESGeom_BoundedSurface::*)() const) &IGESGeom_BoundedSurface::RepresentationType, "returns the type of Bounded surface representation 0 = The boundary entities may only reference model space curves 1 = The boundary entities may reference both model space curves and associated parameter space curve representations");
cls_IGESGeom_BoundedSurface.def("Surface", (opencascade::handle<IGESData_IGESEntity> (IGESGeom_BoundedSurface::*)() const) &IGESGeom_BoundedSurface::Surface, "returns the bounded surface");
cls_IGESGeom_BoundedSurface.def("NbBoundaries", (Standard_Integer (IGESGeom_BoundedSurface::*)() const) &IGESGeom_BoundedSurface::NbBoundaries, "returns the number of boundaries");
cls_IGESGeom_BoundedSurface.def("Boundary", (opencascade::handle<IGESGeom_Boundary> (IGESGeom_BoundedSurface::*)(const Standard_Integer) const) &IGESGeom_BoundedSurface::Boundary, "returns boundary entity raises exception if Index <= 0 or Index > NbBoundaries()", py::arg("Index"));
cls_IGESGeom_BoundedSurface.def_static("get_type_name_", (const char * (*)()) &IGESGeom_BoundedSurface::get_type_name, "None");
cls_IGESGeom_BoundedSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESGeom_BoundedSurface::get_type_descriptor, "None");
cls_IGESGeom_BoundedSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESGeom_BoundedSurface::*)() const) &IGESGeom_BoundedSurface::DynamicType, "None");

// Enums

}