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
#include <Geom2d_Curve.hxx>
#include <gp_Pnt2d.hxx>
#include <Standard_Handle.hxx>
#include <Geom2d_BoundedCurve.hxx>
#include <Standard_Type.hxx>

void bind_Geom2d_BoundedCurve(py::module &mod){

py::class_<Geom2d_BoundedCurve, opencascade::handle<Geom2d_BoundedCurve>, Geom2d_Curve> cls_Geom2d_BoundedCurve(mod, "Geom2d_BoundedCurve", "The abstract class BoundedCurve describes the common behavior of bounded curves in 2D space. A bounded curve is limited by two finite values of the parameter, termed respectively 'first parameter' and 'last parameter'. The 'first parameter' gives the 'start point' of the bounded curve, and the 'last parameter' gives the 'end point' of the bounded curve. The length of a bounded curve is finite. The Geom2d package provides three concrete classes of bounded curves: - two frequently used mathematical formulations of complex curves: - Geom2d_BezierCurve, - Geom2d_BSplineCurve, and - Geom2d_TrimmedCurve to trim a curve, i.e. to only take part of the curve limited by two values of the parameter of the basis curve.");

// Fields

// Methods
cls_Geom2d_BoundedCurve.def("EndPoint", (gp_Pnt2d (Geom2d_BoundedCurve::*)() const) &Geom2d_BoundedCurve::EndPoint, "Returns the end point of the curve. The end point is the value of the curve for the 'LastParameter' of the curve.");
cls_Geom2d_BoundedCurve.def("StartPoint", (gp_Pnt2d (Geom2d_BoundedCurve::*)() const) &Geom2d_BoundedCurve::StartPoint, "Returns the start point of the curve. The start point is the value of the curve for the 'FirstParameter' of the curve.");
cls_Geom2d_BoundedCurve.def_static("get_type_name_", (const char * (*)()) &Geom2d_BoundedCurve::get_type_name, "None");
cls_Geom2d_BoundedCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Geom2d_BoundedCurve::get_type_descriptor, "None");
cls_Geom2d_BoundedCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (Geom2d_BoundedCurve::*)() const) &Geom2d_BoundedCurve::DynamicType, "None");

// Enums

}