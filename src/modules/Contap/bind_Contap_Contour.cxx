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
#include <gp_Vec.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <Standard_Handle.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <Adaptor3d_TopolTool.hxx>
#include <Contap_Line.hxx>
#include <Contap_SurfFunction.hxx>
#include <Contap_TheSequenceOfLine.hxx>
#include <Contap_TheSearch.hxx>
#include <Contap_TheSearchInside.hxx>
#include <Contap_ArcFunction.hxx>
#include <Contap_Contour.hxx>

void bind_Contap_Contour(py::module &mod){

py::class_<Contap_Contour, std::unique_ptr<Contap_Contour, Deleter<Contap_Contour>>> cls_Contap_Contour(mod, "Contap_Contour", "None");

// Constructors
cls_Contap_Contour.def(py::init<>());
cls_Contap_Contour.def(py::init<const gp_Vec &>(), py::arg("Direction"));
cls_Contap_Contour.def(py::init<const gp_Vec &, const Standard_Real>(), py::arg("Direction"), py::arg("Angle"));
cls_Contap_Contour.def(py::init<const gp_Pnt &>(), py::arg("Eye"));
cls_Contap_Contour.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const gp_Vec &>(), py::arg("Surf"), py::arg("Domain"), py::arg("Direction"));
cls_Contap_Contour.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const gp_Vec &, const Standard_Real>(), py::arg("Surf"), py::arg("Domain"), py::arg("Direction"), py::arg("Angle"));
cls_Contap_Contour.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const gp_Pnt &>(), py::arg("Surf"), py::arg("Domain"), py::arg("Eye"));

// Fields

// Methods
// cls_Contap_Contour.def_static("operator new_", (void * (*)(size_t)) &Contap_Contour::operator new, "None", py::arg("theSize"));
// cls_Contap_Contour.def_static("operator delete_", (void (*)(void *)) &Contap_Contour::operator delete, "None", py::arg("theAddress"));
// cls_Contap_Contour.def_static("operator new[]_", (void * (*)(size_t)) &Contap_Contour::operator new[], "None", py::arg("theSize"));
// cls_Contap_Contour.def_static("operator delete[]_", (void (*)(void *)) &Contap_Contour::operator delete[], "None", py::arg("theAddress"));
// cls_Contap_Contour.def_static("operator new_", (void * (*)(size_t, void *)) &Contap_Contour::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Contap_Contour.def_static("operator delete_", (void (*)(void *, void *)) &Contap_Contour::operator delete, "None", py::arg(""), py::arg(""));
cls_Contap_Contour.def("Perform", (void (Contap_Contour::*)(const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &)) &Contap_Contour::Perform, "Creates the contour in a given direction.", py::arg("Surf"), py::arg("Domain"));
cls_Contap_Contour.def("Perform", (void (Contap_Contour::*)(const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const gp_Vec &)) &Contap_Contour::Perform, "Creates the contour in a given direction.", py::arg("Surf"), py::arg("Domain"), py::arg("Direction"));
cls_Contap_Contour.def("Perform", (void (Contap_Contour::*)(const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const gp_Vec &, const Standard_Real)) &Contap_Contour::Perform, "Creates the contour in a given direction.", py::arg("Surf"), py::arg("Domain"), py::arg("Direction"), py::arg("Angle"));
cls_Contap_Contour.def("Perform", (void (Contap_Contour::*)(const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const gp_Pnt &)) &Contap_Contour::Perform, "Creates the contour for a perspective view.", py::arg("Surf"), py::arg("Domain"), py::arg("Eye"));
cls_Contap_Contour.def("Init", (void (Contap_Contour::*)(const gp_Vec &)) &Contap_Contour::Init, "None", py::arg("Direction"));
cls_Contap_Contour.def("Init", (void (Contap_Contour::*)(const gp_Vec &, const Standard_Real)) &Contap_Contour::Init, "None", py::arg("Direction"), py::arg("Angle"));
cls_Contap_Contour.def("Init", (void (Contap_Contour::*)(const gp_Pnt &)) &Contap_Contour::Init, "None", py::arg("Eye"));
cls_Contap_Contour.def("IsDone", (Standard_Boolean (Contap_Contour::*)() const) &Contap_Contour::IsDone, "None");
cls_Contap_Contour.def("IsEmpty", (Standard_Boolean (Contap_Contour::*)() const) &Contap_Contour::IsEmpty, "Returns true if the is no line.");
cls_Contap_Contour.def("NbLines", (Standard_Integer (Contap_Contour::*)() const) &Contap_Contour::NbLines, "None");
cls_Contap_Contour.def("Line", (const Contap_Line & (Contap_Contour::*)(const Standard_Integer) const) &Contap_Contour::Line, "None", py::arg("Index"));
cls_Contap_Contour.def("SurfaceFunction", (Contap_SurfFunction & (Contap_Contour::*)()) &Contap_Contour::SurfaceFunction, "Returns a reference on the internal SurfaceFunction. This is used to compute tangents on the lines.");

// Enums

}