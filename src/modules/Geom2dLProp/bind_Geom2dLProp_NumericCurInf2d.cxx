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
#include <Standard_Handle.hxx>
#include <Geom2d_Curve.hxx>
#include <LProp_CurAndInf.hxx>
#include <Standard_TypeDef.hxx>
#include <Geom2dLProp_NumericCurInf2d.hxx>

void bind_Geom2dLProp_NumericCurInf2d(py::module &mod){

py::class_<Geom2dLProp_NumericCurInf2d, std::unique_ptr<Geom2dLProp_NumericCurInf2d>> cls_Geom2dLProp_NumericCurInf2d(mod, "Geom2dLProp_NumericCurInf2d", "Computes the locals extremas of curvature and the inflections of a bounded curve in 2d.");

// Constructors
cls_Geom2dLProp_NumericCurInf2d.def(py::init<>());

// Fields

// Methods
// cls_Geom2dLProp_NumericCurInf2d.def_static("operator new_", (void * (*)(size_t)) &Geom2dLProp_NumericCurInf2d::operator new, "None", py::arg("theSize"));
// cls_Geom2dLProp_NumericCurInf2d.def_static("operator delete_", (void (*)(void *)) &Geom2dLProp_NumericCurInf2d::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dLProp_NumericCurInf2d.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dLProp_NumericCurInf2d::operator new[], "None", py::arg("theSize"));
// cls_Geom2dLProp_NumericCurInf2d.def_static("operator delete[]_", (void (*)(void *)) &Geom2dLProp_NumericCurInf2d::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dLProp_NumericCurInf2d.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dLProp_NumericCurInf2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dLProp_NumericCurInf2d.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dLProp_NumericCurInf2d::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dLProp_NumericCurInf2d.def("PerformCurExt", (void (Geom2dLProp_NumericCurInf2d::*)(const opencascade::handle<Geom2d_Curve> &, LProp_CurAndInf &)) &Geom2dLProp_NumericCurInf2d::PerformCurExt, "Computes the locals extremas of curvature.", py::arg("C"), py::arg("Result"));
cls_Geom2dLProp_NumericCurInf2d.def("PerformInf", (void (Geom2dLProp_NumericCurInf2d::*)(const opencascade::handle<Geom2d_Curve> &, LProp_CurAndInf &)) &Geom2dLProp_NumericCurInf2d::PerformInf, "Computes the inflections.", py::arg("C"), py::arg("Result"));
cls_Geom2dLProp_NumericCurInf2d.def("PerformCurExt", (void (Geom2dLProp_NumericCurInf2d::*)(const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const Standard_Real, LProp_CurAndInf &)) &Geom2dLProp_NumericCurInf2d::PerformCurExt, "Computes the locals extremas of curvature. in the interval of parmeters [UMin,UMax].", py::arg("C"), py::arg("UMin"), py::arg("UMax"), py::arg("Result"));
cls_Geom2dLProp_NumericCurInf2d.def("PerformInf", (void (Geom2dLProp_NumericCurInf2d::*)(const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const Standard_Real, LProp_CurAndInf &)) &Geom2dLProp_NumericCurInf2d::PerformInf, "Computes the inflections in the interval of parmeters [UMin,UMax].", py::arg("C"), py::arg("UMin"), py::arg("UMax"), py::arg("Result"));
cls_Geom2dLProp_NumericCurInf2d.def("IsDone", (Standard_Boolean (Geom2dLProp_NumericCurInf2d::*)() const) &Geom2dLProp_NumericCurInf2d::IsDone, "True if the solutions are found.");

// Enums

}