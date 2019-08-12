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
#include <Adaptor3d_TopolTool.hxx>
#include <Standard_Handle.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Pnt.hxx>
#include <IntTools_TopolTool.hxx>
#include <Standard_Type.hxx>

void bind_IntTools_TopolTool(py::module &mod){

py::class_<IntTools_TopolTool, opencascade::handle<IntTools_TopolTool>, Adaptor3d_TopolTool> cls_IntTools_TopolTool(mod, "IntTools_TopolTool", "Class redefine methods of TopolTool from Adaptor3d concerning sample points");

// Constructors
cls_IntTools_TopolTool.def(py::init<>());
cls_IntTools_TopolTool.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &>(), py::arg("theSurface"));

// Fields

// Methods
cls_IntTools_TopolTool.def("Initialize", (void (IntTools_TopolTool::*)()) &IntTools_TopolTool::Initialize, "Redefined empty initializer");
cls_IntTools_TopolTool.def("Initialize", (void (IntTools_TopolTool::*)(const opencascade::handle<Adaptor3d_HSurface> &)) &IntTools_TopolTool::Initialize, "Initializes me by surface", py::arg("theSurface"));
cls_IntTools_TopolTool.def("ComputeSamplePoints", (void (IntTools_TopolTool::*)()) &IntTools_TopolTool::ComputeSamplePoints, "None");
cls_IntTools_TopolTool.def("NbSamplesU", (Standard_Integer (IntTools_TopolTool::*)()) &IntTools_TopolTool::NbSamplesU, "Computes the sample-points for the intersections algorithms");
cls_IntTools_TopolTool.def("NbSamplesV", (Standard_Integer (IntTools_TopolTool::*)()) &IntTools_TopolTool::NbSamplesV, "Computes the sample-points for the intersections algorithms");
cls_IntTools_TopolTool.def("NbSamples", (Standard_Integer (IntTools_TopolTool::*)()) &IntTools_TopolTool::NbSamples, "Computes the sample-points for the intersections algorithms");
cls_IntTools_TopolTool.def("SamplePoint", (void (IntTools_TopolTool::*)(const Standard_Integer, gp_Pnt2d &, gp_Pnt &)) &IntTools_TopolTool::SamplePoint, "Returns a 2d point from surface myS and a corresponded 3d point for given index. The index should be from 1 to NbSamples()", py::arg("Index"), py::arg("P2d"), py::arg("P3d"));
cls_IntTools_TopolTool.def("SamplePnts", (void (IntTools_TopolTool::*)(const Standard_Real, const Standard_Integer, const Standard_Integer)) &IntTools_TopolTool::SamplePnts, "compute the sample-points for the intersections algorithms by adaptive algorithm for BSpline surfaces. For other surfaces algorithm is the same as in method ComputeSamplePoints(), but only fill arrays of U and V sample parameters; theDefl is a requred deflection theNUmin, theNVmin are minimal nb points for U and V.", py::arg("theDefl"), py::arg("theNUmin"), py::arg("theNVmin"));
cls_IntTools_TopolTool.def_static("get_type_name_", (const char * (*)()) &IntTools_TopolTool::get_type_name, "None");
cls_IntTools_TopolTool.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IntTools_TopolTool::get_type_descriptor, "None");
cls_IntTools_TopolTool.def("DynamicType", (const opencascade::handle<Standard_Type> & (IntTools_TopolTool::*)() const) &IntTools_TopolTool::DynamicType, "None");

// Enums

}