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
#include <GeomFill_TrihedronLaw.hxx>
#include <Standard_Handle.hxx>
#include <Adaptor3d_HCurve.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Vec.hxx>
#include <GeomAbs_Shape.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <GeomFill_DiscreteTrihedron.hxx>
#include <Standard_Type.hxx>
#include <gp_Pnt.hxx>
#include <GeomFill_HSequenceOfAx2.hxx>
#include <TColStd_HSequenceOfReal.hxx>
#include <GeomFill_Frenet.hxx>

void bind_GeomFill_DiscreteTrihedron(py::module &mod){

py::class_<GeomFill_DiscreteTrihedron, opencascade::handle<GeomFill_DiscreteTrihedron>, GeomFill_TrihedronLaw> cls_GeomFill_DiscreteTrihedron(mod, "GeomFill_DiscreteTrihedron", "Defined Discrete Trihedron Law. The requirement for path curve is only G1. The result is C0-continuous surface that can be later approximated to C1.");

// Constructors
cls_GeomFill_DiscreteTrihedron.def(py::init<>());

// Fields

// Methods
cls_GeomFill_DiscreteTrihedron.def("Copy", (opencascade::handle<GeomFill_TrihedronLaw> (GeomFill_DiscreteTrihedron::*)() const) &GeomFill_DiscreteTrihedron::Copy, "None");
cls_GeomFill_DiscreteTrihedron.def("Init", (void (GeomFill_DiscreteTrihedron::*)()) &GeomFill_DiscreteTrihedron::Init, "None");
cls_GeomFill_DiscreteTrihedron.def("SetCurve", (void (GeomFill_DiscreteTrihedron::*)(const opencascade::handle<Adaptor3d_HCurve> &)) &GeomFill_DiscreteTrihedron::SetCurve, "None", py::arg("C"));
cls_GeomFill_DiscreteTrihedron.def("D0", (Standard_Boolean (GeomFill_DiscreteTrihedron::*)(const Standard_Real, gp_Vec &, gp_Vec &, gp_Vec &)) &GeomFill_DiscreteTrihedron::D0, "compute Trihedron on curve at parameter <Param>", py::arg("Param"), py::arg("Tangent"), py::arg("Normal"), py::arg("BiNormal"));
cls_GeomFill_DiscreteTrihedron.def("D1", (Standard_Boolean (GeomFill_DiscreteTrihedron::*)(const Standard_Real, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &)) &GeomFill_DiscreteTrihedron::D1, "compute Trihedron and derivative Trihedron on curve at parameter <Param> Warning : It used only for C1 or C2 aproximation For the moment it returns null values for DTangent, DNormal and DBiNormal.", py::arg("Param"), py::arg("Tangent"), py::arg("DTangent"), py::arg("Normal"), py::arg("DNormal"), py::arg("BiNormal"), py::arg("DBiNormal"));
cls_GeomFill_DiscreteTrihedron.def("D2", (Standard_Boolean (GeomFill_DiscreteTrihedron::*)(const Standard_Real, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &)) &GeomFill_DiscreteTrihedron::D2, "compute Trihedron on curve first and seconde derivatives. Warning : It used only for C2 aproximation For the moment it returns null values for DTangent, DNormal DBiNormal, D2Tangent, D2Normal, D2BiNormal.", py::arg("Param"), py::arg("Tangent"), py::arg("DTangent"), py::arg("D2Tangent"), py::arg("Normal"), py::arg("DNormal"), py::arg("D2Normal"), py::arg("BiNormal"), py::arg("DBiNormal"), py::arg("D2BiNormal"));
cls_GeomFill_DiscreteTrihedron.def("NbIntervals", (Standard_Integer (GeomFill_DiscreteTrihedron::*)(const GeomAbs_Shape) const) &GeomFill_DiscreteTrihedron::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
cls_GeomFill_DiscreteTrihedron.def("Intervals", (void (GeomFill_DiscreteTrihedron::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &GeomFill_DiscreteTrihedron::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
cls_GeomFill_DiscreteTrihedron.def("GetAverageLaw", (void (GeomFill_DiscreteTrihedron::*)(gp_Vec &, gp_Vec &, gp_Vec &)) &GeomFill_DiscreteTrihedron::GetAverageLaw, "Get average value of Tangent(t) and Normal(t) it is usful to make fast approximation of rational surfaces.", py::arg("ATangent"), py::arg("ANormal"), py::arg("ABiNormal"));
cls_GeomFill_DiscreteTrihedron.def("IsConstant", (Standard_Boolean (GeomFill_DiscreteTrihedron::*)() const) &GeomFill_DiscreteTrihedron::IsConstant, "Say if the law is Constant.");
cls_GeomFill_DiscreteTrihedron.def("IsOnlyBy3dCurve", (Standard_Boolean (GeomFill_DiscreteTrihedron::*)() const) &GeomFill_DiscreteTrihedron::IsOnlyBy3dCurve, "Return True.");
cls_GeomFill_DiscreteTrihedron.def_static("get_type_name_", (const char * (*)()) &GeomFill_DiscreteTrihedron::get_type_name, "None");
cls_GeomFill_DiscreteTrihedron.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomFill_DiscreteTrihedron::get_type_descriptor, "None");
cls_GeomFill_DiscreteTrihedron.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomFill_DiscreteTrihedron::*)() const) &GeomFill_DiscreteTrihedron::DynamicType, "None");

// Enums

}