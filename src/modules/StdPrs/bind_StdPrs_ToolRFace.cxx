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
#include <BRepAdaptor_HSurface.hxx>
#include <Standard_TypeDef.hxx>
#include <Adaptor2d_Curve2dPtr.hxx>
#include <TopAbs_Orientation.hxx>
#include <TopoDS_Face.hxx>
#include <TopExp_Explorer.hxx>
#include <Geom2dAdaptor_Curve.hxx>
#include <StdPrs_ToolRFace.hxx>

void bind_StdPrs_ToolRFace(py::module &mod){

py::class_<StdPrs_ToolRFace, std::unique_ptr<StdPrs_ToolRFace, Deleter<StdPrs_ToolRFace>>> cls_StdPrs_ToolRFace(mod, "StdPrs_ToolRFace", "None");

// Constructors
cls_StdPrs_ToolRFace.def(py::init<>());
cls_StdPrs_ToolRFace.def(py::init<const opencascade::handle<BRepAdaptor_HSurface> &>(), py::arg("aSurface"));

// Fields

// Methods
// cls_StdPrs_ToolRFace.def_static("operator new_", (void * (*)(size_t)) &StdPrs_ToolRFace::operator new, "None", py::arg("theSize"));
// cls_StdPrs_ToolRFace.def_static("operator delete_", (void (*)(void *)) &StdPrs_ToolRFace::operator delete, "None", py::arg("theAddress"));
// cls_StdPrs_ToolRFace.def_static("operator new[]_", (void * (*)(size_t)) &StdPrs_ToolRFace::operator new[], "None", py::arg("theSize"));
// cls_StdPrs_ToolRFace.def_static("operator delete[]_", (void (*)(void *)) &StdPrs_ToolRFace::operator delete[], "None", py::arg("theAddress"));
// cls_StdPrs_ToolRFace.def_static("operator new_", (void * (*)(size_t, void *)) &StdPrs_ToolRFace::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StdPrs_ToolRFace.def_static("operator delete_", (void (*)(void *, void *)) &StdPrs_ToolRFace::operator delete, "None", py::arg(""), py::arg(""));
cls_StdPrs_ToolRFace.def("IsOriented", (Standard_Boolean (StdPrs_ToolRFace::*)() const) &StdPrs_ToolRFace::IsOriented, "None");
cls_StdPrs_ToolRFace.def("Init", (void (StdPrs_ToolRFace::*)()) &StdPrs_ToolRFace::Init, "None");
cls_StdPrs_ToolRFace.def("More", (Standard_Boolean (StdPrs_ToolRFace::*)() const) &StdPrs_ToolRFace::More, "None");
cls_StdPrs_ToolRFace.def("Next", (void (StdPrs_ToolRFace::*)()) &StdPrs_ToolRFace::Next, "None");
cls_StdPrs_ToolRFace.def("Value", (Adaptor2d_Curve2dPtr (StdPrs_ToolRFace::*)() const) &StdPrs_ToolRFace::Value, "None");
cls_StdPrs_ToolRFace.def("Orientation", (TopAbs_Orientation (StdPrs_ToolRFace::*)() const) &StdPrs_ToolRFace::Orientation, "None");

// Enums

}