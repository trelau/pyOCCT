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
#include <StepGeom_CurveBoundedSurface.hxx>
#include <Transfer_TransientProcess.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Face.hxx>
#include <StepToTopoDS_TranslateCurveBoundedSurface.hxx>

void bind_StepToTopoDS_TranslateCurveBoundedSurface(py::module &mod){

py::class_<StepToTopoDS_TranslateCurveBoundedSurface, std::unique_ptr<StepToTopoDS_TranslateCurveBoundedSurface, Deleter<StepToTopoDS_TranslateCurveBoundedSurface>>, StepToTopoDS_Root> cls_StepToTopoDS_TranslateCurveBoundedSurface(mod, "StepToTopoDS_TranslateCurveBoundedSurface", "Translate curve_bounded_surface into TopoDS_Face");

// Constructors
cls_StepToTopoDS_TranslateCurveBoundedSurface.def(py::init<>());
cls_StepToTopoDS_TranslateCurveBoundedSurface.def(py::init<const opencascade::handle<StepGeom_CurveBoundedSurface> &, const opencascade::handle<Transfer_TransientProcess> &>(), py::arg("CBS"), py::arg("TP"));

// Fields

// Methods
// cls_StepToTopoDS_TranslateCurveBoundedSurface.def_static("operator new_", (void * (*)(size_t)) &StepToTopoDS_TranslateCurveBoundedSurface::operator new, "None", py::arg("theSize"));
// cls_StepToTopoDS_TranslateCurveBoundedSurface.def_static("operator delete_", (void (*)(void *)) &StepToTopoDS_TranslateCurveBoundedSurface::operator delete, "None", py::arg("theAddress"));
// cls_StepToTopoDS_TranslateCurveBoundedSurface.def_static("operator new[]_", (void * (*)(size_t)) &StepToTopoDS_TranslateCurveBoundedSurface::operator new[], "None", py::arg("theSize"));
// cls_StepToTopoDS_TranslateCurveBoundedSurface.def_static("operator delete[]_", (void (*)(void *)) &StepToTopoDS_TranslateCurveBoundedSurface::operator delete[], "None", py::arg("theAddress"));
// cls_StepToTopoDS_TranslateCurveBoundedSurface.def_static("operator new_", (void * (*)(size_t, void *)) &StepToTopoDS_TranslateCurveBoundedSurface::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepToTopoDS_TranslateCurveBoundedSurface.def_static("operator delete_", (void (*)(void *, void *)) &StepToTopoDS_TranslateCurveBoundedSurface::operator delete, "None", py::arg(""), py::arg(""));
cls_StepToTopoDS_TranslateCurveBoundedSurface.def("Init", (Standard_Boolean (StepToTopoDS_TranslateCurveBoundedSurface::*)(const opencascade::handle<StepGeom_CurveBoundedSurface> &, const opencascade::handle<Transfer_TransientProcess> &)) &StepToTopoDS_TranslateCurveBoundedSurface::Init, "Translate surface", py::arg("CBS"), py::arg("TP"));
cls_StepToTopoDS_TranslateCurveBoundedSurface.def("Value", (const TopoDS_Face & (StepToTopoDS_TranslateCurveBoundedSurface::*)() const) &StepToTopoDS_TranslateCurveBoundedSurface::Value, "Returns result of last translation or null wire if failed.");

// Enums

}