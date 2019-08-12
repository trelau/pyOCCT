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
#include <Geom2d_Curve.hxx>
#include <Adaptor2d_Curve2d.hxx>
#include <Geom2dAdaptor_Curve.hxx>
#include <Geom2dAdaptor_GHCurve.hxx>
#include <Geom2dAdaptor_HCurve.hxx>
#include <Geom2dAdaptor.hxx>

void bind_Geom2dAdaptor(py::module &mod){

py::class_<Geom2dAdaptor, std::unique_ptr<Geom2dAdaptor, Deleter<Geom2dAdaptor>>> cls_Geom2dAdaptor(mod, "Geom2dAdaptor", "this package contains the geometric definition of 2d curves compatible with the Adaptor package templates.");

// Constructors

// Fields

// Methods
// cls_Geom2dAdaptor.def_static("operator new_", (void * (*)(size_t)) &Geom2dAdaptor::operator new, "None", py::arg("theSize"));
// cls_Geom2dAdaptor.def_static("operator delete_", (void (*)(void *)) &Geom2dAdaptor::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dAdaptor.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dAdaptor::operator new[], "None", py::arg("theSize"));
// cls_Geom2dAdaptor.def_static("operator delete[]_", (void (*)(void *)) &Geom2dAdaptor::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dAdaptor.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dAdaptor::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dAdaptor.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dAdaptor::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dAdaptor.def_static("MakeCurve_", (opencascade::handle<Geom2d_Curve> (*)(const Adaptor2d_Curve2d &)) &Geom2dAdaptor::MakeCurve, "Inherited from GHCurve. Provides a curve handled by reference. Creates a 2d curve from a HCurve2d. This cannot process the OtherCurves.", py::arg("HC"));

// Enums

}