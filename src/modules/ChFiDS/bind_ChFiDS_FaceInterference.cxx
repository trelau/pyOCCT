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
#include <Standard_TypeDef.hxx>
#include <TopAbs_Orientation.hxx>
#include <Standard_Handle.hxx>
#include <Geom2d_Curve.hxx>
#include <ChFiDS_FaceInterference.hxx>

void bind_ChFiDS_FaceInterference(py::module &mod){

py::class_<ChFiDS_FaceInterference, std::unique_ptr<ChFiDS_FaceInterference, Deleter<ChFiDS_FaceInterference>>> cls_ChFiDS_FaceInterference(mod, "ChFiDS_FaceInterference", "interference face/fillet");

// Constructors
cls_ChFiDS_FaceInterference.def(py::init<>());

// Fields

// Methods
// cls_ChFiDS_FaceInterference.def_static("operator new_", (void * (*)(size_t)) &ChFiDS_FaceInterference::operator new, "None", py::arg("theSize"));
// cls_ChFiDS_FaceInterference.def_static("operator delete_", (void (*)(void *)) &ChFiDS_FaceInterference::operator delete, "None", py::arg("theAddress"));
// cls_ChFiDS_FaceInterference.def_static("operator new[]_", (void * (*)(size_t)) &ChFiDS_FaceInterference::operator new[], "None", py::arg("theSize"));
// cls_ChFiDS_FaceInterference.def_static("operator delete[]_", (void (*)(void *)) &ChFiDS_FaceInterference::operator delete[], "None", py::arg("theAddress"));
// cls_ChFiDS_FaceInterference.def_static("operator new_", (void * (*)(size_t, void *)) &ChFiDS_FaceInterference::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ChFiDS_FaceInterference.def_static("operator delete_", (void (*)(void *, void *)) &ChFiDS_FaceInterference::operator delete, "None", py::arg(""), py::arg(""));
cls_ChFiDS_FaceInterference.def("SetInterference", (void (ChFiDS_FaceInterference::*)(const Standard_Integer, const TopAbs_Orientation, const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom2d_Curve> &)) &ChFiDS_FaceInterference::SetInterference, "None", py::arg("LineIndex"), py::arg("Trans"), py::arg("PCurv1"), py::arg("PCurv2"));
cls_ChFiDS_FaceInterference.def("SetTransition", (void (ChFiDS_FaceInterference::*)(const TopAbs_Orientation)) &ChFiDS_FaceInterference::SetTransition, "None", py::arg("Trans"));
cls_ChFiDS_FaceInterference.def("SetFirstParameter", (void (ChFiDS_FaceInterference::*)(const Standard_Real)) &ChFiDS_FaceInterference::SetFirstParameter, "None", py::arg("U1"));
cls_ChFiDS_FaceInterference.def("SetLastParameter", (void (ChFiDS_FaceInterference::*)(const Standard_Real)) &ChFiDS_FaceInterference::SetLastParameter, "None", py::arg("U1"));
cls_ChFiDS_FaceInterference.def("SetParameter", (void (ChFiDS_FaceInterference::*)(const Standard_Real, const Standard_Boolean)) &ChFiDS_FaceInterference::SetParameter, "None", py::arg("U1"), py::arg("IsFirst"));
cls_ChFiDS_FaceInterference.def("LineIndex", (Standard_Integer (ChFiDS_FaceInterference::*)() const) &ChFiDS_FaceInterference::LineIndex, "None");
cls_ChFiDS_FaceInterference.def("SetLineIndex", (void (ChFiDS_FaceInterference::*)(const Standard_Integer)) &ChFiDS_FaceInterference::SetLineIndex, "None", py::arg("I"));
cls_ChFiDS_FaceInterference.def("Transition", (TopAbs_Orientation (ChFiDS_FaceInterference::*)() const) &ChFiDS_FaceInterference::Transition, "None");
cls_ChFiDS_FaceInterference.def("PCurveOnFace", (const opencascade::handle<Geom2d_Curve> & (ChFiDS_FaceInterference::*)() const) &ChFiDS_FaceInterference::PCurveOnFace, "None");
cls_ChFiDS_FaceInterference.def("PCurveOnSurf", (const opencascade::handle<Geom2d_Curve> & (ChFiDS_FaceInterference::*)() const) &ChFiDS_FaceInterference::PCurveOnSurf, "None");
cls_ChFiDS_FaceInterference.def("ChangePCurveOnFace", (opencascade::handle<Geom2d_Curve> & (ChFiDS_FaceInterference::*)()) &ChFiDS_FaceInterference::ChangePCurveOnFace, "None");
cls_ChFiDS_FaceInterference.def("ChangePCurveOnSurf", (opencascade::handle<Geom2d_Curve> & (ChFiDS_FaceInterference::*)()) &ChFiDS_FaceInterference::ChangePCurveOnSurf, "None");
cls_ChFiDS_FaceInterference.def("FirstParameter", (Standard_Real (ChFiDS_FaceInterference::*)() const) &ChFiDS_FaceInterference::FirstParameter, "None");
cls_ChFiDS_FaceInterference.def("LastParameter", (Standard_Real (ChFiDS_FaceInterference::*)() const) &ChFiDS_FaceInterference::LastParameter, "None");
cls_ChFiDS_FaceInterference.def("Parameter", (Standard_Real (ChFiDS_FaceInterference::*)(const Standard_Boolean) const) &ChFiDS_FaceInterference::Parameter, "None", py::arg("IsFirst"));

// Enums

}