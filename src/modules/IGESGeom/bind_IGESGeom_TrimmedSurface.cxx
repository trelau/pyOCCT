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
#include <Standard_TypeDef.hxx>
#include <IGESGeom_CurveOnSurface.hxx>
#include <IGESGeom_HArray1OfCurveOnSurface.hxx>
#include <IGESGeom_TrimmedSurface.hxx>
#include <Standard_Type.hxx>

void bind_IGESGeom_TrimmedSurface(py::module &mod){

py::class_<IGESGeom_TrimmedSurface, opencascade::handle<IGESGeom_TrimmedSurface>, IGESData_IGESEntity> cls_IGESGeom_TrimmedSurface(mod, "IGESGeom_TrimmedSurface", "defines IGESTrimmedSurface, Type <144> Form <0> in package IGESGeom A simple closed curve in Euclidean plane divides the plane in to two disjoint, open connected components; one bounded, one unbounded. The bounded one is called the interior region to the curve. Unbounded component is called exterior region to the curve. The domain of the trimmed surface is defined as the interior of the outer boundaries and exterior of the inner boundaries and includes the boundary curves.");

// Constructors
cls_IGESGeom_TrimmedSurface.def(py::init<>());

// Fields

// Methods
cls_IGESGeom_TrimmedSurface.def("Init", (void (IGESGeom_TrimmedSurface::*)(const opencascade::handle<IGESData_IGESEntity> &, const Standard_Integer, const opencascade::handle<IGESGeom_CurveOnSurface> &, const opencascade::handle<IGESGeom_HArray1OfCurveOnSurface> &)) &IGESGeom_TrimmedSurface::Init, "This method is used to set the fields of the class TrimmedSurface - aSurface : Surface to be trimmed - aFlag : Outer boundary type False = The outer boundary is the boundary of rectangle D which is the domain of the surface to be trimmed True = otherwise - anOuter : Closed curve which constitutes outer boundary - allInners : Array of closed curves which constitute the inner boundary", py::arg("aSurface"), py::arg("aFlag"), py::arg("anOuter"), py::arg("allInners"));
cls_IGESGeom_TrimmedSurface.def("Surface", (opencascade::handle<IGESData_IGESEntity> (IGESGeom_TrimmedSurface::*)() const) &IGESGeom_TrimmedSurface::Surface, "returns the surface to be trimmed");
cls_IGESGeom_TrimmedSurface.def("HasOuterContour", (Standard_Boolean (IGESGeom_TrimmedSurface::*)() const) &IGESGeom_TrimmedSurface::HasOuterContour, "returns True if outer contour exists");
cls_IGESGeom_TrimmedSurface.def("OuterContour", (opencascade::handle<IGESGeom_CurveOnSurface> (IGESGeom_TrimmedSurface::*)() const) &IGESGeom_TrimmedSurface::OuterContour, "returns the outer contour of the trimmed surface");
cls_IGESGeom_TrimmedSurface.def("OuterBoundaryType", (Standard_Integer (IGESGeom_TrimmedSurface::*)() const) &IGESGeom_TrimmedSurface::OuterBoundaryType, "returns the outer contour type of the trimmed surface 0 : The outer boundary is the boundary of D 1 : otherwise");
cls_IGESGeom_TrimmedSurface.def("NbInnerContours", (Standard_Integer (IGESGeom_TrimmedSurface::*)() const) &IGESGeom_TrimmedSurface::NbInnerContours, "returns the number of inner boundaries");
cls_IGESGeom_TrimmedSurface.def("InnerContour", (opencascade::handle<IGESGeom_CurveOnSurface> (IGESGeom_TrimmedSurface::*)(const Standard_Integer) const) &IGESGeom_TrimmedSurface::InnerContour, "returns the Index'th inner contour raises exception if Index <= 0 or Index > NbInnerContours()", py::arg("Index"));
cls_IGESGeom_TrimmedSurface.def_static("get_type_name_", (const char * (*)()) &IGESGeom_TrimmedSurface::get_type_name, "None");
cls_IGESGeom_TrimmedSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESGeom_TrimmedSurface::get_type_descriptor, "None");
cls_IGESGeom_TrimmedSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESGeom_TrimmedSurface::*)() const) &IGESGeom_TrimmedSurface::DynamicType, "None");

// Enums

}