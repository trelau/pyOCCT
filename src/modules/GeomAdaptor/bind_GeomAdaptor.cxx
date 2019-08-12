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
#include <Geom_Curve.hxx>
#include <Adaptor3d_Curve.hxx>
#include <Geom_Surface.hxx>
#include <Adaptor3d_Surface.hxx>
#include <Standard_TypeDef.hxx>
#include <GeomAdaptor_Curve.hxx>
#include <GeomAdaptor_Surface.hxx>
#include <GeomAdaptor_GHSurface.hxx>
#include <GeomAdaptor_HSurface.hxx>
#include <GeomAdaptor_GHCurve.hxx>
#include <GeomAdaptor_HCurve.hxx>
#include <GeomAdaptor.hxx>

void bind_GeomAdaptor(py::module &mod){

py::class_<GeomAdaptor, std::unique_ptr<GeomAdaptor, Deleter<GeomAdaptor>>> cls_GeomAdaptor(mod, "GeomAdaptor", "this package contains the geometric definition of curve and surface necessary to use algorithmes.");

// Constructors

// Fields

// Methods
// cls_GeomAdaptor.def_static("operator new_", (void * (*)(size_t)) &GeomAdaptor::operator new, "None", py::arg("theSize"));
// cls_GeomAdaptor.def_static("operator delete_", (void (*)(void *)) &GeomAdaptor::operator delete, "None", py::arg("theAddress"));
// cls_GeomAdaptor.def_static("operator new[]_", (void * (*)(size_t)) &GeomAdaptor::operator new[], "None", py::arg("theSize"));
// cls_GeomAdaptor.def_static("operator delete[]_", (void (*)(void *)) &GeomAdaptor::operator delete[], "None", py::arg("theAddress"));
// cls_GeomAdaptor.def_static("operator new_", (void * (*)(size_t, void *)) &GeomAdaptor::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomAdaptor.def_static("operator delete_", (void (*)(void *, void *)) &GeomAdaptor::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomAdaptor.def_static("MakeCurve_", (opencascade::handle<Geom_Curve> (*)(const Adaptor3d_Curve &)) &GeomAdaptor::MakeCurve, "Inherited from GHCurve. Provides a curve handled by reference. Build a Geom_Curve using the informations from the Curve from Adaptor3d", py::arg("C"));
cls_GeomAdaptor.def_static("MakeSurface_", [](const Adaptor3d_Surface & a0) -> opencascade::handle<Geom_Surface> { return GeomAdaptor::MakeSurface(a0); });
cls_GeomAdaptor.def_static("MakeSurface_", (opencascade::handle<Geom_Surface> (*)(const Adaptor3d_Surface &, const Standard_Boolean)) &GeomAdaptor::MakeSurface, "Build a Geom_Surface using the informations from the Surface from Adaptor3d", py::arg("theS"), py::arg("theTrimFlag"));

// Enums

}