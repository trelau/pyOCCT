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
#include <gp_Pln.hxx>
#include <GeomLib_IsPlanarSurface.hxx>

void bind_GeomLib_IsPlanarSurface(py::module &mod){

py::class_<GeomLib_IsPlanarSurface, std::unique_ptr<GeomLib_IsPlanarSurface, Deleter<GeomLib_IsPlanarSurface>>> cls_GeomLib_IsPlanarSurface(mod, "GeomLib_IsPlanarSurface", "Find if a surface is a planar surface.");

// Constructors
cls_GeomLib_IsPlanarSurface.def(py::init<const opencascade::handle<Geom_Surface> &>(), py::arg("S"));
cls_GeomLib_IsPlanarSurface.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Real>(), py::arg("S"), py::arg("Tol"));

// Fields

// Methods
// cls_GeomLib_IsPlanarSurface.def_static("operator new_", (void * (*)(size_t)) &GeomLib_IsPlanarSurface::operator new, "None", py::arg("theSize"));
// cls_GeomLib_IsPlanarSurface.def_static("operator delete_", (void (*)(void *)) &GeomLib_IsPlanarSurface::operator delete, "None", py::arg("theAddress"));
// cls_GeomLib_IsPlanarSurface.def_static("operator new[]_", (void * (*)(size_t)) &GeomLib_IsPlanarSurface::operator new[], "None", py::arg("theSize"));
// cls_GeomLib_IsPlanarSurface.def_static("operator delete[]_", (void (*)(void *)) &GeomLib_IsPlanarSurface::operator delete[], "None", py::arg("theAddress"));
// cls_GeomLib_IsPlanarSurface.def_static("operator new_", (void * (*)(size_t, void *)) &GeomLib_IsPlanarSurface::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomLib_IsPlanarSurface.def_static("operator delete_", (void (*)(void *, void *)) &GeomLib_IsPlanarSurface::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomLib_IsPlanarSurface.def("IsPlanar", (Standard_Boolean (GeomLib_IsPlanarSurface::*)() const) &GeomLib_IsPlanarSurface::IsPlanar, "Return if the Surface is a plan");
cls_GeomLib_IsPlanarSurface.def("Plan", (const gp_Pln & (GeomLib_IsPlanarSurface::*)() const) &GeomLib_IsPlanarSurface::Plan, "Return the plan definition");

// Enums

}