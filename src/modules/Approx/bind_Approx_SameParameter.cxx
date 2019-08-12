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
#include <Geom2d_Curve.hxx>
#include <Geom_Surface.hxx>
#include <Standard_TypeDef.hxx>
#include <Adaptor3d_HCurve.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <Adaptor2d_HCurve2d.hxx>
#include <Geom2d_BSplineCurve.hxx>
#include <Approx_SameParameter.hxx>

void bind_Approx_SameParameter(py::module &mod){

py::class_<Approx_SameParameter, std::unique_ptr<Approx_SameParameter, Deleter<Approx_SameParameter>>> cls_Approx_SameParameter(mod, "Approx_SameParameter", "Approximation of a PCurve on a surface to make its parameter be the same that the parameter of a given 3d reference curve.");

// Constructors
cls_Approx_SameParameter.def(py::init<const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const Standard_Real>(), py::arg("C3D"), py::arg("C2D"), py::arg("S"), py::arg("Tol"));
cls_Approx_SameParameter.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real>(), py::arg("C3D"), py::arg("C2D"), py::arg("S"), py::arg("Tol"));
cls_Approx_SameParameter.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Adaptor2d_HCurve2d> &, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real>(), py::arg("C3D"), py::arg("C2D"), py::arg("S"), py::arg("Tol"));

// Fields

// Methods
// cls_Approx_SameParameter.def_static("operator new_", (void * (*)(size_t)) &Approx_SameParameter::operator new, "None", py::arg("theSize"));
// cls_Approx_SameParameter.def_static("operator delete_", (void (*)(void *)) &Approx_SameParameter::operator delete, "None", py::arg("theAddress"));
// cls_Approx_SameParameter.def_static("operator new[]_", (void * (*)(size_t)) &Approx_SameParameter::operator new[], "None", py::arg("theSize"));
// cls_Approx_SameParameter.def_static("operator delete[]_", (void (*)(void *)) &Approx_SameParameter::operator delete[], "None", py::arg("theAddress"));
// cls_Approx_SameParameter.def_static("operator new_", (void * (*)(size_t, void *)) &Approx_SameParameter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Approx_SameParameter.def_static("operator delete_", (void (*)(void *, void *)) &Approx_SameParameter::operator delete, "None", py::arg(""), py::arg(""));
cls_Approx_SameParameter.def("IsDone", (Standard_Boolean (Approx_SameParameter::*)() const) &Approx_SameParameter::IsDone, "None");
cls_Approx_SameParameter.def("TolReached", (Standard_Real (Approx_SameParameter::*)() const) &Approx_SameParameter::TolReached, "None");
cls_Approx_SameParameter.def("IsSameParameter", (Standard_Boolean (Approx_SameParameter::*)() const) &Approx_SameParameter::IsSameParameter, "Tells whether the original data had already the same parameter up to the tolerance : in that case nothing is done.");
cls_Approx_SameParameter.def("Curve2d", (opencascade::handle<Geom2d_BSplineCurve> (Approx_SameParameter::*)() const) &Approx_SameParameter::Curve2d, "Returns the 2D curve that has the same parameter as the 3D curve once evaluated on the surface up to the specified tolerance");

// Enums

}