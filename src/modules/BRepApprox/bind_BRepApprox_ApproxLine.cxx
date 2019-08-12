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
#include <Standard_Handle.hxx>
#include <Geom_BSplineCurve.hxx>
#include <Geom2d_BSplineCurve.hxx>
#include <IntSurf_LineOn2S.hxx>
#include <Standard_TypeDef.hxx>
#include <IntSurf_PntOn2S.hxx>
#include <BRepApprox_ApproxLine.hxx>
#include <Standard_Type.hxx>

void bind_BRepApprox_ApproxLine(py::module &mod){

py::class_<BRepApprox_ApproxLine, opencascade::handle<BRepApprox_ApproxLine>, Standard_Transient> cls_BRepApprox_ApproxLine(mod, "BRepApprox_ApproxLine", "None");

// Constructors
cls_BRepApprox_ApproxLine.def(py::init<const opencascade::handle<Geom_BSplineCurve> &, const opencascade::handle<Geom2d_BSplineCurve> &, const opencascade::handle<Geom2d_BSplineCurve> &>(), py::arg("CurveXYZ"), py::arg("CurveUV1"), py::arg("CurveUV2"));
cls_BRepApprox_ApproxLine.def(py::init<const opencascade::handle<IntSurf_LineOn2S> &, const Standard_Boolean>(), py::arg("lin"), py::arg("Tang"));

// Fields

// Methods
cls_BRepApprox_ApproxLine.def("NbPnts", (Standard_Integer (BRepApprox_ApproxLine::*)() const) &BRepApprox_ApproxLine::NbPnts, "None");
cls_BRepApprox_ApproxLine.def("Point", (IntSurf_PntOn2S (BRepApprox_ApproxLine::*)(const Standard_Integer)) &BRepApprox_ApproxLine::Point, "None", py::arg("Index"));
cls_BRepApprox_ApproxLine.def_static("get_type_name_", (const char * (*)()) &BRepApprox_ApproxLine::get_type_name, "None");
cls_BRepApprox_ApproxLine.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepApprox_ApproxLine::get_type_descriptor, "None");
cls_BRepApprox_ApproxLine.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepApprox_ApproxLine::*)() const) &BRepApprox_ApproxLine::DynamicType, "None");

// Enums

}