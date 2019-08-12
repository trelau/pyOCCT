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
#include <GeomEvaluator_Surface.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Curve.hxx>
#include <gp_Dir.hxx>
#include <gp_Pnt.hxx>
#include <Adaptor3d_HCurve.hxx>
#include <gp_Ax1.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Vec.hxx>
#include <GeomEvaluator_SurfaceOfRevolution.hxx>
#include <Standard_Type.hxx>

void bind_GeomEvaluator_SurfaceOfRevolution(py::module &mod){

py::class_<GeomEvaluator_SurfaceOfRevolution, opencascade::handle<GeomEvaluator_SurfaceOfRevolution>, GeomEvaluator_Surface> cls_GeomEvaluator_SurfaceOfRevolution(mod, "GeomEvaluator_SurfaceOfRevolution", "Allows to calculate values and derivatives for surfaces of revolution");

// Constructors
cls_GeomEvaluator_SurfaceOfRevolution.def(py::init<const opencascade::handle<Geom_Curve> &, const gp_Dir &, const gp_Pnt &>(), py::arg("theBase"), py::arg("theRevolDir"), py::arg("theRevolLoc"));
cls_GeomEvaluator_SurfaceOfRevolution.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const gp_Dir &, const gp_Pnt &>(), py::arg("theBase"), py::arg("theRevolDir"), py::arg("theRevolLoc"));

// Fields

// Methods
cls_GeomEvaluator_SurfaceOfRevolution.def("SetDirection", (void (GeomEvaluator_SurfaceOfRevolution::*)(const gp_Dir &)) &GeomEvaluator_SurfaceOfRevolution::SetDirection, "Change direction of the axis of revolution", py::arg("theDirection"));
cls_GeomEvaluator_SurfaceOfRevolution.def("SetLocation", (void (GeomEvaluator_SurfaceOfRevolution::*)(const gp_Pnt &)) &GeomEvaluator_SurfaceOfRevolution::SetLocation, "Change location of the axis of revolution", py::arg("theLocation"));
cls_GeomEvaluator_SurfaceOfRevolution.def("SetAxis", (void (GeomEvaluator_SurfaceOfRevolution::*)(const gp_Ax1 &)) &GeomEvaluator_SurfaceOfRevolution::SetAxis, "Change the axis of revolution", py::arg("theAxis"));
cls_GeomEvaluator_SurfaceOfRevolution.def("D0", (void (GeomEvaluator_SurfaceOfRevolution::*)(const Standard_Real, const Standard_Real, gp_Pnt &) const) &GeomEvaluator_SurfaceOfRevolution::D0, "Value of surface", py::arg("theU"), py::arg("theV"), py::arg("theValue"));
cls_GeomEvaluator_SurfaceOfRevolution.def("D1", (void (GeomEvaluator_SurfaceOfRevolution::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const) &GeomEvaluator_SurfaceOfRevolution::D1, "Value and first derivatives of surface", py::arg("theU"), py::arg("theV"), py::arg("theValue"), py::arg("theD1U"), py::arg("theD1V"));
cls_GeomEvaluator_SurfaceOfRevolution.def("D2", (void (GeomEvaluator_SurfaceOfRevolution::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const) &GeomEvaluator_SurfaceOfRevolution::D2, "Value, first and second derivatives of surface", py::arg("theU"), py::arg("theV"), py::arg("theValue"), py::arg("theD1U"), py::arg("theD1V"), py::arg("theD2U"), py::arg("theD2V"), py::arg("theD2UV"));
cls_GeomEvaluator_SurfaceOfRevolution.def("D3", (void (GeomEvaluator_SurfaceOfRevolution::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const) &GeomEvaluator_SurfaceOfRevolution::D3, "Value, first, second and third derivatives of surface", py::arg("theU"), py::arg("theV"), py::arg("theValue"), py::arg("theD1U"), py::arg("theD1V"), py::arg("theD2U"), py::arg("theD2V"), py::arg("theD2UV"), py::arg("theD3U"), py::arg("theD3V"), py::arg("theD3UUV"), py::arg("theD3UVV"));
cls_GeomEvaluator_SurfaceOfRevolution.def("DN", (gp_Vec (GeomEvaluator_SurfaceOfRevolution::*)(const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer) const) &GeomEvaluator_SurfaceOfRevolution::DN, "Calculates N-th derivatives of surface, where N = theDerU + theDerV.", py::arg("theU"), py::arg("theV"), py::arg("theDerU"), py::arg("theDerV"));
cls_GeomEvaluator_SurfaceOfRevolution.def_static("get_type_name_", (const char * (*)()) &GeomEvaluator_SurfaceOfRevolution::get_type_name, "None");
cls_GeomEvaluator_SurfaceOfRevolution.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomEvaluator_SurfaceOfRevolution::get_type_descriptor, "None");
cls_GeomEvaluator_SurfaceOfRevolution.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomEvaluator_SurfaceOfRevolution::*)() const) &GeomEvaluator_SurfaceOfRevolution::DynamicType, "None");

// Enums

}