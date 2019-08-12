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
#include <StepData_SelectType.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Transient.hxx>
#include <StepData_SelectMember.hxx>
#include <StepElement_ElementVolume.hxx>
#include <StepElement_CurveEdge.hxx>
#include <StepElement_ElementAspect.hxx>

void bind_StepElement_ElementAspect(py::module &mod){

py::class_<StepElement_ElementAspect, std::unique_ptr<StepElement_ElementAspect, Deleter<StepElement_ElementAspect>>, StepData_SelectType> cls_StepElement_ElementAspect(mod, "StepElement_ElementAspect", "Representation of STEP SELECT type ElementAspect");

// Constructors
cls_StepElement_ElementAspect.def(py::init<>());

// Fields

// Methods
// cls_StepElement_ElementAspect.def_static("operator new_", (void * (*)(size_t)) &StepElement_ElementAspect::operator new, "None", py::arg("theSize"));
// cls_StepElement_ElementAspect.def_static("operator delete_", (void (*)(void *)) &StepElement_ElementAspect::operator delete, "None", py::arg("theAddress"));
// cls_StepElement_ElementAspect.def_static("operator new[]_", (void * (*)(size_t)) &StepElement_ElementAspect::operator new[], "None", py::arg("theSize"));
// cls_StepElement_ElementAspect.def_static("operator delete[]_", (void (*)(void *)) &StepElement_ElementAspect::operator delete[], "None", py::arg("theAddress"));
// cls_StepElement_ElementAspect.def_static("operator new_", (void * (*)(size_t, void *)) &StepElement_ElementAspect::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepElement_ElementAspect.def_static("operator delete_", (void (*)(void *, void *)) &StepElement_ElementAspect::operator delete, "None", py::arg(""), py::arg(""));
cls_StepElement_ElementAspect.def("CaseNum", (Standard_Integer (StepElement_ElementAspect::*)(const opencascade::handle<Standard_Transient> &) const) &StepElement_ElementAspect::CaseNum, "Recognizes a kind of ElementAspect select type return 0", py::arg("ent"));
cls_StepElement_ElementAspect.def("CaseMem", (Standard_Integer (StepElement_ElementAspect::*)(const opencascade::handle<StepData_SelectMember> &) const) &StepElement_ElementAspect::CaseMem, "Recognizes a items of select member ElementAspectMember 1 -> ElementVolume 2 -> Volume3dFace 3 -> Volume2dFace 4 -> Volume3dEdge 5 -> Volume2dEdge 6 -> Surface3dFace 7 -> Surface2dFace 8 -> Surface3dEdge 9 -> Surface2dEdge 10 -> CurveEdge 0 else", py::arg("ent"));
cls_StepElement_ElementAspect.def("NewMember", (opencascade::handle<StepData_SelectMember> (StepElement_ElementAspect::*)() const) &StepElement_ElementAspect::NewMember, "Returns a new select member the type ElementAspectMember");
cls_StepElement_ElementAspect.def("SetElementVolume", (void (StepElement_ElementAspect::*)(const StepElement_ElementVolume)) &StepElement_ElementAspect::SetElementVolume, "Set Value for ElementVolume", py::arg("aVal"));
cls_StepElement_ElementAspect.def("ElementVolume", (StepElement_ElementVolume (StepElement_ElementAspect::*)() const) &StepElement_ElementAspect::ElementVolume, "Returns Value as ElementVolume (or Null if another type)");
cls_StepElement_ElementAspect.def("SetVolume3dFace", (void (StepElement_ElementAspect::*)(const Standard_Integer)) &StepElement_ElementAspect::SetVolume3dFace, "Set Value for Volume3dFace", py::arg("aVal"));
cls_StepElement_ElementAspect.def("Volume3dFace", (Standard_Integer (StepElement_ElementAspect::*)() const) &StepElement_ElementAspect::Volume3dFace, "Returns Value as Volume3dFace (or Null if another type)");
cls_StepElement_ElementAspect.def("SetVolume2dFace", (void (StepElement_ElementAspect::*)(const Standard_Integer)) &StepElement_ElementAspect::SetVolume2dFace, "Set Value for Volume2dFace", py::arg("aVal"));
cls_StepElement_ElementAspect.def("Volume2dFace", (Standard_Integer (StepElement_ElementAspect::*)() const) &StepElement_ElementAspect::Volume2dFace, "Returns Value as Volume2dFace (or Null if another type)");
cls_StepElement_ElementAspect.def("SetVolume3dEdge", (void (StepElement_ElementAspect::*)(const Standard_Integer)) &StepElement_ElementAspect::SetVolume3dEdge, "Set Value for Volume3dEdge", py::arg("aVal"));
cls_StepElement_ElementAspect.def("Volume3dEdge", (Standard_Integer (StepElement_ElementAspect::*)() const) &StepElement_ElementAspect::Volume3dEdge, "Returns Value as Volume3dEdge (or Null if another type)");
cls_StepElement_ElementAspect.def("SetVolume2dEdge", (void (StepElement_ElementAspect::*)(const Standard_Integer)) &StepElement_ElementAspect::SetVolume2dEdge, "Set Value for Volume2dEdge", py::arg("aVal"));
cls_StepElement_ElementAspect.def("Volume2dEdge", (Standard_Integer (StepElement_ElementAspect::*)() const) &StepElement_ElementAspect::Volume2dEdge, "Returns Value as Volume2dEdge (or Null if another type)");
cls_StepElement_ElementAspect.def("SetSurface3dFace", (void (StepElement_ElementAspect::*)(const Standard_Integer)) &StepElement_ElementAspect::SetSurface3dFace, "Set Value for Surface3dFace", py::arg("aVal"));
cls_StepElement_ElementAspect.def("Surface3dFace", (Standard_Integer (StepElement_ElementAspect::*)() const) &StepElement_ElementAspect::Surface3dFace, "Returns Value as Surface3dFace (or Null if another type)");
cls_StepElement_ElementAspect.def("SetSurface2dFace", (void (StepElement_ElementAspect::*)(const Standard_Integer)) &StepElement_ElementAspect::SetSurface2dFace, "Set Value for Surface2dFace", py::arg("aVal"));
cls_StepElement_ElementAspect.def("Surface2dFace", (Standard_Integer (StepElement_ElementAspect::*)() const) &StepElement_ElementAspect::Surface2dFace, "Returns Value as Surface2dFace (or Null if another type)");
cls_StepElement_ElementAspect.def("SetSurface3dEdge", (void (StepElement_ElementAspect::*)(const Standard_Integer)) &StepElement_ElementAspect::SetSurface3dEdge, "Set Value for Surface3dEdge", py::arg("aVal"));
cls_StepElement_ElementAspect.def("Surface3dEdge", (Standard_Integer (StepElement_ElementAspect::*)() const) &StepElement_ElementAspect::Surface3dEdge, "Returns Value as Surface3dEdge (or Null if another type)");
cls_StepElement_ElementAspect.def("SetSurface2dEdge", (void (StepElement_ElementAspect::*)(const Standard_Integer)) &StepElement_ElementAspect::SetSurface2dEdge, "Set Value for Surface2dEdge", py::arg("aVal"));
cls_StepElement_ElementAspect.def("Surface2dEdge", (Standard_Integer (StepElement_ElementAspect::*)() const) &StepElement_ElementAspect::Surface2dEdge, "Returns Value as Surface2dEdge (or Null if another type)");
cls_StepElement_ElementAspect.def("SetCurveEdge", (void (StepElement_ElementAspect::*)(const StepElement_CurveEdge)) &StepElement_ElementAspect::SetCurveEdge, "Set Value for CurveEdge", py::arg("aVal"));
cls_StepElement_ElementAspect.def("CurveEdge", (StepElement_CurveEdge (StepElement_ElementAspect::*)() const) &StepElement_ElementAspect::CurveEdge, "Returns Value as CurveEdge (or Null if another type)");

// Enums

}