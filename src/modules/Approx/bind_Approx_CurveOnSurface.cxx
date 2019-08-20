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
#include <Adaptor2d_HCurve2d.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <Standard_TypeDef.hxx>
#include <GeomAbs_Shape.hxx>
#include <Geom_BSplineCurve.hxx>
#include <Geom2d_BSplineCurve.hxx>
#include <Approx_CurveOnSurface.hxx>

void bind_Approx_CurveOnSurface(py::module &mod){

py::class_<Approx_CurveOnSurface, std::unique_ptr<Approx_CurveOnSurface>> cls_Approx_CurveOnSurface(mod, "Approx_CurveOnSurface", "Approximation of curve on surface");

// Constructors
cls_Approx_CurveOnSurface.def(py::init<const opencascade::handle<Adaptor2d_HCurve2d> &, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real, const Standard_Real, const Standard_Real, const GeomAbs_Shape, const Standard_Integer, const Standard_Integer>(), py::arg("C2D"), py::arg("Surf"), py::arg("First"), py::arg("Last"), py::arg("Tol"), py::arg("Continuity"), py::arg("MaxDegree"), py::arg("MaxSegments"));
cls_Approx_CurveOnSurface.def(py::init<const opencascade::handle<Adaptor2d_HCurve2d> &, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real, const Standard_Real, const Standard_Real, const GeomAbs_Shape, const Standard_Integer, const Standard_Integer, const Standard_Boolean>(), py::arg("C2D"), py::arg("Surf"), py::arg("First"), py::arg("Last"), py::arg("Tol"), py::arg("Continuity"), py::arg("MaxDegree"), py::arg("MaxSegments"), py::arg("Only3d"));
cls_Approx_CurveOnSurface.def(py::init<const opencascade::handle<Adaptor2d_HCurve2d> &, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real, const Standard_Real, const Standard_Real, const GeomAbs_Shape, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Boolean>(), py::arg("C2D"), py::arg("Surf"), py::arg("First"), py::arg("Last"), py::arg("Tol"), py::arg("Continuity"), py::arg("MaxDegree"), py::arg("MaxSegments"), py::arg("Only3d"), py::arg("Only2d"));

// Fields

// Methods
// cls_Approx_CurveOnSurface.def_static("operator new_", (void * (*)(size_t)) &Approx_CurveOnSurface::operator new, "None", py::arg("theSize"));
// cls_Approx_CurveOnSurface.def_static("operator delete_", (void (*)(void *)) &Approx_CurveOnSurface::operator delete, "None", py::arg("theAddress"));
// cls_Approx_CurveOnSurface.def_static("operator new[]_", (void * (*)(size_t)) &Approx_CurveOnSurface::operator new[], "None", py::arg("theSize"));
// cls_Approx_CurveOnSurface.def_static("operator delete[]_", (void (*)(void *)) &Approx_CurveOnSurface::operator delete[], "None", py::arg("theAddress"));
// cls_Approx_CurveOnSurface.def_static("operator new_", (void * (*)(size_t, void *)) &Approx_CurveOnSurface::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Approx_CurveOnSurface.def_static("operator delete_", (void (*)(void *, void *)) &Approx_CurveOnSurface::operator delete, "None", py::arg(""), py::arg(""));
cls_Approx_CurveOnSurface.def("IsDone", (Standard_Boolean (Approx_CurveOnSurface::*)() const) &Approx_CurveOnSurface::IsDone, "None");
cls_Approx_CurveOnSurface.def("HasResult", (Standard_Boolean (Approx_CurveOnSurface::*)() const) &Approx_CurveOnSurface::HasResult, "None");
cls_Approx_CurveOnSurface.def("Curve3d", (opencascade::handle<Geom_BSplineCurve> (Approx_CurveOnSurface::*)() const) &Approx_CurveOnSurface::Curve3d, "None");
cls_Approx_CurveOnSurface.def("MaxError3d", (Standard_Real (Approx_CurveOnSurface::*)() const) &Approx_CurveOnSurface::MaxError3d, "None");
cls_Approx_CurveOnSurface.def("Curve2d", (opencascade::handle<Geom2d_BSplineCurve> (Approx_CurveOnSurface::*)() const) &Approx_CurveOnSurface::Curve2d, "None");
cls_Approx_CurveOnSurface.def("MaxError2dU", (Standard_Real (Approx_CurveOnSurface::*)() const) &Approx_CurveOnSurface::MaxError2dU, "None");
cls_Approx_CurveOnSurface.def("MaxError2dV", (Standard_Real (Approx_CurveOnSurface::*)() const) &Approx_CurveOnSurface::MaxError2dV, "returns the maximum errors relativly to the U component or the V component of the 2d Curve");

// Enums

}