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
#include <Geom_Surface.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Face.hxx>
#include <Geom_Curve.hxx>
#include <Draft_FaceInfo.hxx>

void bind_Draft_FaceInfo(py::module &mod){

py::class_<Draft_FaceInfo, std::unique_ptr<Draft_FaceInfo, Deleter<Draft_FaceInfo>>> cls_Draft_FaceInfo(mod, "Draft_FaceInfo", "None");

// Constructors
cls_Draft_FaceInfo.def(py::init<>());
cls_Draft_FaceInfo.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Boolean>(), py::arg("S"), py::arg("HasNewGeometry"));

// Fields

// Methods
// cls_Draft_FaceInfo.def_static("operator new_", (void * (*)(size_t)) &Draft_FaceInfo::operator new, "None", py::arg("theSize"));
// cls_Draft_FaceInfo.def_static("operator delete_", (void (*)(void *)) &Draft_FaceInfo::operator delete, "None", py::arg("theAddress"));
// cls_Draft_FaceInfo.def_static("operator new[]_", (void * (*)(size_t)) &Draft_FaceInfo::operator new[], "None", py::arg("theSize"));
// cls_Draft_FaceInfo.def_static("operator delete[]_", (void (*)(void *)) &Draft_FaceInfo::operator delete[], "None", py::arg("theAddress"));
// cls_Draft_FaceInfo.def_static("operator new_", (void * (*)(size_t, void *)) &Draft_FaceInfo::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Draft_FaceInfo.def_static("operator delete_", (void (*)(void *, void *)) &Draft_FaceInfo::operator delete, "None", py::arg(""), py::arg(""));
cls_Draft_FaceInfo.def("RootFace", (void (Draft_FaceInfo::*)(const TopoDS_Face &)) &Draft_FaceInfo::RootFace, "None", py::arg("F"));
cls_Draft_FaceInfo.def("NewGeometry", (Standard_Boolean (Draft_FaceInfo::*)() const) &Draft_FaceInfo::NewGeometry, "None");
cls_Draft_FaceInfo.def("Add", (void (Draft_FaceInfo::*)(const TopoDS_Face &)) &Draft_FaceInfo::Add, "None", py::arg("F"));
cls_Draft_FaceInfo.def("FirstFace", (const TopoDS_Face & (Draft_FaceInfo::*)() const) &Draft_FaceInfo::FirstFace, "None");
cls_Draft_FaceInfo.def("SecondFace", (const TopoDS_Face & (Draft_FaceInfo::*)() const) &Draft_FaceInfo::SecondFace, "None");
cls_Draft_FaceInfo.def("Geometry", (const opencascade::handle<Geom_Surface> & (Draft_FaceInfo::*)() const) &Draft_FaceInfo::Geometry, "None");
cls_Draft_FaceInfo.def("ChangeGeometry", (opencascade::handle<Geom_Surface> & (Draft_FaceInfo::*)()) &Draft_FaceInfo::ChangeGeometry, "None");
cls_Draft_FaceInfo.def("RootFace", (const TopoDS_Face & (Draft_FaceInfo::*)() const) &Draft_FaceInfo::RootFace, "None");
cls_Draft_FaceInfo.def("ChangeCurve", (opencascade::handle<Geom_Curve> & (Draft_FaceInfo::*)()) &Draft_FaceInfo::ChangeCurve, "None");
cls_Draft_FaceInfo.def("Curve", (const opencascade::handle<Geom_Curve> & (Draft_FaceInfo::*)() const) &Draft_FaceInfo::Curve, "None");

// Enums

}