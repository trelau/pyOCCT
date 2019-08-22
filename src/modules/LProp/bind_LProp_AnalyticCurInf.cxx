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
#include <Standard.hxx>
#include <GeomAbs_CurveType.hxx>
#include <Standard_TypeDef.hxx>
#include <LProp_CurAndInf.hxx>
#include <LProp_AnalyticCurInf.hxx>

void bind_LProp_AnalyticCurInf(py::module &mod){

py::class_<LProp_AnalyticCurInf> cls_LProp_AnalyticCurInf(mod, "LProp_AnalyticCurInf", "Computes the locals extremas of curvature of a gp curve Remark : a gp curve has not inflection.");

// Constructors
cls_LProp_AnalyticCurInf.def(py::init<>());

// Fields

// Methods
// cls_LProp_AnalyticCurInf.def_static("operator new_", (void * (*)(size_t)) &LProp_AnalyticCurInf::operator new, "None", py::arg("theSize"));
// cls_LProp_AnalyticCurInf.def_static("operator delete_", (void (*)(void *)) &LProp_AnalyticCurInf::operator delete, "None", py::arg("theAddress"));
// cls_LProp_AnalyticCurInf.def_static("operator new[]_", (void * (*)(size_t)) &LProp_AnalyticCurInf::operator new[], "None", py::arg("theSize"));
// cls_LProp_AnalyticCurInf.def_static("operator delete[]_", (void (*)(void *)) &LProp_AnalyticCurInf::operator delete[], "None", py::arg("theAddress"));
// cls_LProp_AnalyticCurInf.def_static("operator new_", (void * (*)(size_t, void *)) &LProp_AnalyticCurInf::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_LProp_AnalyticCurInf.def_static("operator delete_", (void (*)(void *, void *)) &LProp_AnalyticCurInf::operator delete, "None", py::arg(""), py::arg(""));
cls_LProp_AnalyticCurInf.def("Perform", (void (LProp_AnalyticCurInf::*)(const GeomAbs_CurveType, const Standard_Real, const Standard_Real, LProp_CurAndInf &)) &LProp_AnalyticCurInf::Perform, "None", py::arg("T"), py::arg("UFirst"), py::arg("ULast"), py::arg("Result"));

// Enums

}