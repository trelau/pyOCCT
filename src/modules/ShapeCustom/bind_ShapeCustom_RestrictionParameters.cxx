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
#include <Standard_Transient.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <ShapeCustom_RestrictionParameters.hxx>
#include <Standard_Type.hxx>

void bind_ShapeCustom_RestrictionParameters(py::module &mod){

py::class_<ShapeCustom_RestrictionParameters, opencascade::handle<ShapeCustom_RestrictionParameters>, Standard_Transient> cls_ShapeCustom_RestrictionParameters(mod, "ShapeCustom_RestrictionParameters", "This class is axuluary tool which contains parameters for BSplineRestriction class.");

// Constructors
cls_ShapeCustom_RestrictionParameters.def(py::init<>());

// Fields

// Methods
cls_ShapeCustom_RestrictionParameters.def("GMaxDegree", (Standard_Integer & (ShapeCustom_RestrictionParameters::*)()) &ShapeCustom_RestrictionParameters::GMaxDegree, "Returns (modifiable) maximal degree of approximation.");
cls_ShapeCustom_RestrictionParameters.def("GMaxSeg", (Standard_Integer & (ShapeCustom_RestrictionParameters::*)()) &ShapeCustom_RestrictionParameters::GMaxSeg, "Returns (modifiable) maximal number of spans of approximation.");
cls_ShapeCustom_RestrictionParameters.def("ConvertPlane", (Standard_Boolean & (ShapeCustom_RestrictionParameters::*)()) &ShapeCustom_RestrictionParameters::ConvertPlane, "Sets flag for define if Plane converted to BSpline surface.");
cls_ShapeCustom_RestrictionParameters.def("ConvertBezierSurf", (Standard_Boolean & (ShapeCustom_RestrictionParameters::*)()) &ShapeCustom_RestrictionParameters::ConvertBezierSurf, "Sets flag for define if Bezier surface converted to BSpline surface.");
cls_ShapeCustom_RestrictionParameters.def("ConvertRevolutionSurf", (Standard_Boolean & (ShapeCustom_RestrictionParameters::*)()) &ShapeCustom_RestrictionParameters::ConvertRevolutionSurf, "Sets flag for define if surface of Revolution converted to BSpline surface.");
cls_ShapeCustom_RestrictionParameters.def("ConvertExtrusionSurf", (Standard_Boolean & (ShapeCustom_RestrictionParameters::*)()) &ShapeCustom_RestrictionParameters::ConvertExtrusionSurf, "Sets flag for define if surface of LinearExtrusion converted to BSpline surface.");
cls_ShapeCustom_RestrictionParameters.def("ConvertOffsetSurf", (Standard_Boolean & (ShapeCustom_RestrictionParameters::*)()) &ShapeCustom_RestrictionParameters::ConvertOffsetSurf, "Sets flag for define if Offset surface converted to BSpline surface.");
cls_ShapeCustom_RestrictionParameters.def("ConvertCylindricalSurf", (Standard_Boolean & (ShapeCustom_RestrictionParameters::*)()) &ShapeCustom_RestrictionParameters::ConvertCylindricalSurf, "Sets flag for define if cylindrical surface converted to BSpline surface.");
cls_ShapeCustom_RestrictionParameters.def("ConvertConicalSurf", (Standard_Boolean & (ShapeCustom_RestrictionParameters::*)()) &ShapeCustom_RestrictionParameters::ConvertConicalSurf, "Sets flag for define if conical surface converted to BSpline surface.");
cls_ShapeCustom_RestrictionParameters.def("ConvertToroidalSurf", (Standard_Boolean & (ShapeCustom_RestrictionParameters::*)()) &ShapeCustom_RestrictionParameters::ConvertToroidalSurf, "Sets flag for define if toroidal surface converted to BSpline surface.");
cls_ShapeCustom_RestrictionParameters.def("ConvertSphericalSurf", (Standard_Boolean & (ShapeCustom_RestrictionParameters::*)()) &ShapeCustom_RestrictionParameters::ConvertSphericalSurf, "Sets flag for define if spherical surface converted to BSpline surface.");
cls_ShapeCustom_RestrictionParameters.def("SegmentSurfaceMode", (Standard_Boolean & (ShapeCustom_RestrictionParameters::*)()) &ShapeCustom_RestrictionParameters::SegmentSurfaceMode, "Sets Segment mode for surface. If Segment is True surface is approximated in the bondaries of face lying on this surface.");
cls_ShapeCustom_RestrictionParameters.def("ConvertCurve3d", (Standard_Boolean & (ShapeCustom_RestrictionParameters::*)()) &ShapeCustom_RestrictionParameters::ConvertCurve3d, "Sets flag for define if 3d curve converted to BSpline curve.");
cls_ShapeCustom_RestrictionParameters.def("ConvertOffsetCurv3d", (Standard_Boolean & (ShapeCustom_RestrictionParameters::*)()) &ShapeCustom_RestrictionParameters::ConvertOffsetCurv3d, "Sets flag for define if Offset curve3d converted to BSpline surface.");
cls_ShapeCustom_RestrictionParameters.def("ConvertCurve2d", (Standard_Boolean & (ShapeCustom_RestrictionParameters::*)()) &ShapeCustom_RestrictionParameters::ConvertCurve2d, "Returns (modifiable) flag for define if 2d curve converted to BSpline curve.");
cls_ShapeCustom_RestrictionParameters.def("ConvertOffsetCurv2d", (Standard_Boolean & (ShapeCustom_RestrictionParameters::*)()) &ShapeCustom_RestrictionParameters::ConvertOffsetCurv2d, "Returns (modifiable) flag for define if Offset curve2d converted to BSpline surface.");
cls_ShapeCustom_RestrictionParameters.def_static("get_type_name_", (const char * (*)()) &ShapeCustom_RestrictionParameters::get_type_name, "None");
cls_ShapeCustom_RestrictionParameters.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeCustom_RestrictionParameters::get_type_descriptor, "None");
cls_ShapeCustom_RestrictionParameters.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeCustom_RestrictionParameters::*)() const) &ShapeCustom_RestrictionParameters::DynamicType, "None");

// Enums

}