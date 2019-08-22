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
#include <StepToTopoDS_Root.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <StepGeom_CompositeCurve.hxx>
#include <Transfer_TransientProcess.hxx>
#include <StepGeom_Surface.hxx>
#include <Geom_Surface.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Wire.hxx>
#include <StepToTopoDS_TranslateCompositeCurve.hxx>

void bind_StepToTopoDS_TranslateCompositeCurve(py::module &mod){

py::class_<StepToTopoDS_TranslateCompositeCurve, StepToTopoDS_Root> cls_StepToTopoDS_TranslateCompositeCurve(mod, "StepToTopoDS_TranslateCompositeCurve", "Translate STEP entity composite_curve to TopoDS_Wire If surface is given, the curve is assumed to lie on that surface and in case if any segment of it is a curve_on_surface, the pcurve for that segment will be taken. Note: a segment of composite_curve may be itself composite_curve. Only one-level protection against cyclic references is implemented.");

// Constructors
cls_StepToTopoDS_TranslateCompositeCurve.def(py::init<>());
cls_StepToTopoDS_TranslateCompositeCurve.def(py::init<const opencascade::handle<StepGeom_CompositeCurve> &, const opencascade::handle<Transfer_TransientProcess> &>(), py::arg("CC"), py::arg("TP"));
cls_StepToTopoDS_TranslateCompositeCurve.def(py::init<const opencascade::handle<StepGeom_CompositeCurve> &, const opencascade::handle<Transfer_TransientProcess> &, const opencascade::handle<StepGeom_Surface> &, const opencascade::handle<Geom_Surface> &>(), py::arg("CC"), py::arg("TP"), py::arg("S"), py::arg("Surf"));

// Fields

// Methods
// cls_StepToTopoDS_TranslateCompositeCurve.def_static("operator new_", (void * (*)(size_t)) &StepToTopoDS_TranslateCompositeCurve::operator new, "None", py::arg("theSize"));
// cls_StepToTopoDS_TranslateCompositeCurve.def_static("operator delete_", (void (*)(void *)) &StepToTopoDS_TranslateCompositeCurve::operator delete, "None", py::arg("theAddress"));
// cls_StepToTopoDS_TranslateCompositeCurve.def_static("operator new[]_", (void * (*)(size_t)) &StepToTopoDS_TranslateCompositeCurve::operator new[], "None", py::arg("theSize"));
// cls_StepToTopoDS_TranslateCompositeCurve.def_static("operator delete[]_", (void (*)(void *)) &StepToTopoDS_TranslateCompositeCurve::operator delete[], "None", py::arg("theAddress"));
// cls_StepToTopoDS_TranslateCompositeCurve.def_static("operator new_", (void * (*)(size_t, void *)) &StepToTopoDS_TranslateCompositeCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepToTopoDS_TranslateCompositeCurve.def_static("operator delete_", (void (*)(void *, void *)) &StepToTopoDS_TranslateCompositeCurve::operator delete, "None", py::arg(""), py::arg(""));
cls_StepToTopoDS_TranslateCompositeCurve.def("Init", (Standard_Boolean (StepToTopoDS_TranslateCompositeCurve::*)(const opencascade::handle<StepGeom_CompositeCurve> &, const opencascade::handle<Transfer_TransientProcess> &)) &StepToTopoDS_TranslateCompositeCurve::Init, "Translates standalone composite_curve", py::arg("CC"), py::arg("TP"));
cls_StepToTopoDS_TranslateCompositeCurve.def("Init", (Standard_Boolean (StepToTopoDS_TranslateCompositeCurve::*)(const opencascade::handle<StepGeom_CompositeCurve> &, const opencascade::handle<Transfer_TransientProcess> &, const opencascade::handle<StepGeom_Surface> &, const opencascade::handle<Geom_Surface> &)) &StepToTopoDS_TranslateCompositeCurve::Init, "Translates composite_curve lying on surface", py::arg("CC"), py::arg("TP"), py::arg("S"), py::arg("Surf"));
cls_StepToTopoDS_TranslateCompositeCurve.def("Value", (const TopoDS_Wire & (StepToTopoDS_TranslateCompositeCurve::*)() const) &StepToTopoDS_TranslateCompositeCurve::Value, "Returns result of last translation or null wire if failed.");
cls_StepToTopoDS_TranslateCompositeCurve.def("IsInfiniteSegment", (Standard_Boolean (StepToTopoDS_TranslateCompositeCurve::*)() const) &StepToTopoDS_TranslateCompositeCurve::IsInfiniteSegment, "Returns True if composite_curve contains a segment with infinite parameters.");

// Enums

}