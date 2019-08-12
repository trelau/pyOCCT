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
#include <TopOpeBRepDS_Interference.hxx>
#include <TopOpeBRepDS_Transition.hxx>
#include <TopOpeBRepDS_Kind.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Geom2d_Curve.hxx>
#include <TopOpeBRepDS_SurfaceCurveInterference.hxx>
#include <Standard_Type.hxx>

void bind_TopOpeBRepDS_SurfaceCurveInterference(py::module &mod){

py::class_<TopOpeBRepDS_SurfaceCurveInterference, opencascade::handle<TopOpeBRepDS_SurfaceCurveInterference>, TopOpeBRepDS_Interference> cls_TopOpeBRepDS_SurfaceCurveInterference(mod, "TopOpeBRepDS_SurfaceCurveInterference", "an interference with a 2d curve");

// Constructors
cls_TopOpeBRepDS_SurfaceCurveInterference.def(py::init<>());
cls_TopOpeBRepDS_SurfaceCurveInterference.def(py::init<const TopOpeBRepDS_Transition &, const TopOpeBRepDS_Kind, const Standard_Integer, const TopOpeBRepDS_Kind, const Standard_Integer, const opencascade::handle<Geom2d_Curve> &>(), py::arg("Transition"), py::arg("SupportType"), py::arg("Support"), py::arg("GeometryType"), py::arg("Geometry"), py::arg("PC"));
cls_TopOpeBRepDS_SurfaceCurveInterference.def(py::init<const opencascade::handle<TopOpeBRepDS_Interference> &>(), py::arg("I"));

// Fields

// Methods
cls_TopOpeBRepDS_SurfaceCurveInterference.def("PCurve", (const opencascade::handle<Geom2d_Curve> & (TopOpeBRepDS_SurfaceCurveInterference::*)() const) &TopOpeBRepDS_SurfaceCurveInterference::PCurve, "None");
cls_TopOpeBRepDS_SurfaceCurveInterference.def("PCurve", (void (TopOpeBRepDS_SurfaceCurveInterference::*)(const opencascade::handle<Geom2d_Curve> &)) &TopOpeBRepDS_SurfaceCurveInterference::PCurve, "None", py::arg("PC"));
cls_TopOpeBRepDS_SurfaceCurveInterference.def_static("get_type_name_", (const char * (*)()) &TopOpeBRepDS_SurfaceCurveInterference::get_type_name, "None");
cls_TopOpeBRepDS_SurfaceCurveInterference.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopOpeBRepDS_SurfaceCurveInterference::get_type_descriptor, "None");
cls_TopOpeBRepDS_SurfaceCurveInterference.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopOpeBRepDS_SurfaceCurveInterference::*)() const) &TopOpeBRepDS_SurfaceCurveInterference::DynamicType, "None");

// Enums

}