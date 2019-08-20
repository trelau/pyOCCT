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
#include <Adaptor3d_HSurface.hxx>
#include <Adaptor3d_HCurve.hxx>
#include <Standard_TypeDef.hxx>
#include <Geom_BSplineCurve.hxx>
#include <ProjLib_ProjectOnSurface.hxx>

void bind_ProjLib_ProjectOnSurface(py::module &mod){

py::class_<ProjLib_ProjectOnSurface, std::unique_ptr<ProjLib_ProjectOnSurface>> cls_ProjLib_ProjectOnSurface(mod, "ProjLib_ProjectOnSurface", "Project a curve on a surface. The result ( a 3D Curve) will be an approximation");

// Constructors
cls_ProjLib_ProjectOnSurface.def(py::init<>());
cls_ProjLib_ProjectOnSurface.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &>(), py::arg("S"));

// Fields

// Methods
// cls_ProjLib_ProjectOnSurface.def_static("operator new_", (void * (*)(size_t)) &ProjLib_ProjectOnSurface::operator new, "None", py::arg("theSize"));
// cls_ProjLib_ProjectOnSurface.def_static("operator delete_", (void (*)(void *)) &ProjLib_ProjectOnSurface::operator delete, "None", py::arg("theAddress"));
// cls_ProjLib_ProjectOnSurface.def_static("operator new[]_", (void * (*)(size_t)) &ProjLib_ProjectOnSurface::operator new[], "None", py::arg("theSize"));
// cls_ProjLib_ProjectOnSurface.def_static("operator delete[]_", (void (*)(void *)) &ProjLib_ProjectOnSurface::operator delete[], "None", py::arg("theAddress"));
// cls_ProjLib_ProjectOnSurface.def_static("operator new_", (void * (*)(size_t, void *)) &ProjLib_ProjectOnSurface::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ProjLib_ProjectOnSurface.def_static("operator delete_", (void (*)(void *, void *)) &ProjLib_ProjectOnSurface::operator delete, "None", py::arg(""), py::arg(""));
// cls_ProjLib_ProjectOnSurface.def("Load", (void (ProjLib_ProjectOnSurface::*)(const opencascade::handle<Adaptor3d_HSurface> &)) &ProjLib_ProjectOnSurface::Load, "Set the Surface to <S>. To compute the projection, you have to Load the Curve.", py::arg("S"));
cls_ProjLib_ProjectOnSurface.def("Load", (void (ProjLib_ProjectOnSurface::*)(const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real)) &ProjLib_ProjectOnSurface::Load, "Compute the projection of the curve <C> on the Surface.", py::arg("C"), py::arg("Tolerance"));
cls_ProjLib_ProjectOnSurface.def("IsDone", (Standard_Boolean (ProjLib_ProjectOnSurface::*)() const) &ProjLib_ProjectOnSurface::IsDone, "None");
cls_ProjLib_ProjectOnSurface.def("BSpline", (opencascade::handle<Geom_BSplineCurve> (ProjLib_ProjectOnSurface::*)() const) &ProjLib_ProjectOnSurface::BSpline, "None");

// Enums

}