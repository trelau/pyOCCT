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
#include <Geom_Surface.hxx>
#include <Standard_TypeDef.hxx>
#include <Geom_OsculatingSurface.hxx>
#include <GeomAdaptor_HSurface.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <GeomEvaluator_OffsetSurface.hxx>
#include <Standard_Type.hxx>

void bind_GeomEvaluator_OffsetSurface(py::module &mod){

py::class_<GeomEvaluator_OffsetSurface, opencascade::handle<GeomEvaluator_OffsetSurface>, GeomEvaluator_Surface> cls_GeomEvaluator_OffsetSurface(mod, "GeomEvaluator_OffsetSurface", "Allows to calculate values and derivatives for offset surfaces");

// Constructors
cls_GeomEvaluator_OffsetSurface.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Real>(), py::arg("theBase"), py::arg("theOffset"));
cls_GeomEvaluator_OffsetSurface.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Real, const opencascade::handle<Geom_OsculatingSurface> &>(), py::arg("theBase"), py::arg("theOffset"), py::arg("theOscSurf"));
cls_GeomEvaluator_OffsetSurface.def(py::init<const opencascade::handle<GeomAdaptor_HSurface> &, const Standard_Real>(), py::arg("theBase"), py::arg("theOffset"));
cls_GeomEvaluator_OffsetSurface.def(py::init<const opencascade::handle<GeomAdaptor_HSurface> &, const Standard_Real, const opencascade::handle<Geom_OsculatingSurface> &>(), py::arg("theBase"), py::arg("theOffset"), py::arg("theOscSurf"));

// Fields

// Methods
cls_GeomEvaluator_OffsetSurface.def("SetOffsetValue", (void (GeomEvaluator_OffsetSurface::*)(Standard_Real)) &GeomEvaluator_OffsetSurface::SetOffsetValue, "Change the offset value", py::arg("theOffset"));
cls_GeomEvaluator_OffsetSurface.def("D0", (void (GeomEvaluator_OffsetSurface::*)(const Standard_Real, const Standard_Real, gp_Pnt &) const) &GeomEvaluator_OffsetSurface::D0, "Value of surface", py::arg("theU"), py::arg("theV"), py::arg("theValue"));
cls_GeomEvaluator_OffsetSurface.def("D1", (void (GeomEvaluator_OffsetSurface::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const) &GeomEvaluator_OffsetSurface::D1, "Value and first derivatives of surface", py::arg("theU"), py::arg("theV"), py::arg("theValue"), py::arg("theD1U"), py::arg("theD1V"));
cls_GeomEvaluator_OffsetSurface.def("D2", (void (GeomEvaluator_OffsetSurface::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const) &GeomEvaluator_OffsetSurface::D2, "Value, first and second derivatives of surface", py::arg("theU"), py::arg("theV"), py::arg("theValue"), py::arg("theD1U"), py::arg("theD1V"), py::arg("theD2U"), py::arg("theD2V"), py::arg("theD2UV"));
cls_GeomEvaluator_OffsetSurface.def("D3", (void (GeomEvaluator_OffsetSurface::*)(const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const) &GeomEvaluator_OffsetSurface::D3, "Value, first, second and third derivatives of surface", py::arg("theU"), py::arg("theV"), py::arg("theValue"), py::arg("theD1U"), py::arg("theD1V"), py::arg("theD2U"), py::arg("theD2V"), py::arg("theD2UV"), py::arg("theD3U"), py::arg("theD3V"), py::arg("theD3UUV"), py::arg("theD3UVV"));
cls_GeomEvaluator_OffsetSurface.def("DN", (gp_Vec (GeomEvaluator_OffsetSurface::*)(const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer) const) &GeomEvaluator_OffsetSurface::DN, "Calculates N-th derivatives of surface, where N = theDerU + theDerV.", py::arg("theU"), py::arg("theV"), py::arg("theDerU"), py::arg("theDerV"));
cls_GeomEvaluator_OffsetSurface.def_static("get_type_name_", (const char * (*)()) &GeomEvaluator_OffsetSurface::get_type_name, "None");
cls_GeomEvaluator_OffsetSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomEvaluator_OffsetSurface::get_type_descriptor, "None");
cls_GeomEvaluator_OffsetSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomEvaluator_OffsetSurface::*)() const) &GeomEvaluator_OffsetSurface::DynamicType, "None");

// Enums

}