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
#include <ShapeUpgrade_SplitSurface.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <ShapeExtend_CompositeSurface.hxx>
#include <ShapeUpgrade_ConvertSurfaceToBezierBasis.hxx>
#include <Standard_Type.hxx>

void bind_ShapeUpgrade_ConvertSurfaceToBezierBasis(py::module &mod){

py::class_<ShapeUpgrade_ConvertSurfaceToBezierBasis, opencascade::handle<ShapeUpgrade_ConvertSurfaceToBezierBasis>, ShapeUpgrade_SplitSurface> cls_ShapeUpgrade_ConvertSurfaceToBezierBasis(mod, "ShapeUpgrade_ConvertSurfaceToBezierBasis", "Converts a plane, bspline surface, surface of revolution, surface of extrusion, offset surface to grid of bezier basis surface ( bezier surface, surface of revolution based on bezier curve, offset surface based on any previous type).");

// Constructors
cls_ShapeUpgrade_ConvertSurfaceToBezierBasis.def(py::init<>());

// Fields

// Methods
cls_ShapeUpgrade_ConvertSurfaceToBezierBasis.def("Build", (void (ShapeUpgrade_ConvertSurfaceToBezierBasis::*)(const Standard_Boolean)) &ShapeUpgrade_ConvertSurfaceToBezierBasis::Build, "Splits a list of beziers computed by Compute method according the split values and splitting parameters.", py::arg("Segment"));
cls_ShapeUpgrade_ConvertSurfaceToBezierBasis.def("Compute", (void (ShapeUpgrade_ConvertSurfaceToBezierBasis::*)(const Standard_Boolean)) &ShapeUpgrade_ConvertSurfaceToBezierBasis::Compute, "Converts surface into a grid of bezier based surfaces, and stores this grid.", py::arg("Segment"));
cls_ShapeUpgrade_ConvertSurfaceToBezierBasis.def("Segments", (opencascade::handle<ShapeExtend_CompositeSurface> (ShapeUpgrade_ConvertSurfaceToBezierBasis::*)() const) &ShapeUpgrade_ConvertSurfaceToBezierBasis::Segments, "Returns the grid of bezier based surfaces correspondent to original surface.");
cls_ShapeUpgrade_ConvertSurfaceToBezierBasis.def("SetPlaneMode", (void (ShapeUpgrade_ConvertSurfaceToBezierBasis::*)(const Standard_Boolean)) &ShapeUpgrade_ConvertSurfaceToBezierBasis::SetPlaneMode, "Sets mode for conversion Geom_Plane to Bezier", py::arg("mode"));
cls_ShapeUpgrade_ConvertSurfaceToBezierBasis.def("GetPlaneMode", (Standard_Boolean (ShapeUpgrade_ConvertSurfaceToBezierBasis::*)() const) &ShapeUpgrade_ConvertSurfaceToBezierBasis::GetPlaneMode, "Returns the Geom_Pline conversion mode.");
cls_ShapeUpgrade_ConvertSurfaceToBezierBasis.def("SetRevolutionMode", (void (ShapeUpgrade_ConvertSurfaceToBezierBasis::*)(const Standard_Boolean)) &ShapeUpgrade_ConvertSurfaceToBezierBasis::SetRevolutionMode, "Sets mode for conversion Geom_SurfaceOfRevolution to Bezier", py::arg("mode"));
cls_ShapeUpgrade_ConvertSurfaceToBezierBasis.def("GetRevolutionMode", (Standard_Boolean (ShapeUpgrade_ConvertSurfaceToBezierBasis::*)() const) &ShapeUpgrade_ConvertSurfaceToBezierBasis::GetRevolutionMode, "Returns the Geom_SurfaceOfRevolution conversion mode.");
cls_ShapeUpgrade_ConvertSurfaceToBezierBasis.def("SetExtrusionMode", (void (ShapeUpgrade_ConvertSurfaceToBezierBasis::*)(const Standard_Boolean)) &ShapeUpgrade_ConvertSurfaceToBezierBasis::SetExtrusionMode, "Sets mode for conversion Geom_SurfaceOfLinearExtrusion to Bezier", py::arg("mode"));
cls_ShapeUpgrade_ConvertSurfaceToBezierBasis.def("GetExtrusionMode", (Standard_Boolean (ShapeUpgrade_ConvertSurfaceToBezierBasis::*)() const) &ShapeUpgrade_ConvertSurfaceToBezierBasis::GetExtrusionMode, "Returns the Geom_SurfaceOfLinearExtrusion conversion mode.");
cls_ShapeUpgrade_ConvertSurfaceToBezierBasis.def("SetBSplineMode", (void (ShapeUpgrade_ConvertSurfaceToBezierBasis::*)(const Standard_Boolean)) &ShapeUpgrade_ConvertSurfaceToBezierBasis::SetBSplineMode, "Sets mode for conversion Geom_BSplineSurface to Bezier", py::arg("mode"));
cls_ShapeUpgrade_ConvertSurfaceToBezierBasis.def("GetBSplineMode", (Standard_Boolean (ShapeUpgrade_ConvertSurfaceToBezierBasis::*)() const) &ShapeUpgrade_ConvertSurfaceToBezierBasis::GetBSplineMode, "Returns the Geom_BSplineSurface conversion mode.");
cls_ShapeUpgrade_ConvertSurfaceToBezierBasis.def_static("get_type_name_", (const char * (*)()) &ShapeUpgrade_ConvertSurfaceToBezierBasis::get_type_name, "None");
cls_ShapeUpgrade_ConvertSurfaceToBezierBasis.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeUpgrade_ConvertSurfaceToBezierBasis::get_type_descriptor, "None");
cls_ShapeUpgrade_ConvertSurfaceToBezierBasis.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeUpgrade_ConvertSurfaceToBezierBasis::*)() const) &ShapeUpgrade_ConvertSurfaceToBezierBasis::DynamicType, "None");

// Enums

}