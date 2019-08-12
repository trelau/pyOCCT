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
#include <Adaptor3d_HCurve.hxx>
#include <Standard_TypeDef.hxx>
#include <GeomAbs_Shape.hxx>
#include <Adaptor2d_HCurve2d.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <Geom_BSplineCurve.hxx>
#include <Geom2d_BSplineCurve.hxx>
#include <Standard_OStream.hxx>
#include <Approx_CurvilinearParameter.hxx>

void bind_Approx_CurvilinearParameter(py::module &mod){

py::class_<Approx_CurvilinearParameter, std::unique_ptr<Approx_CurvilinearParameter, Deleter<Approx_CurvilinearParameter>>> cls_Approx_CurvilinearParameter(mod, "Approx_CurvilinearParameter", "Approximation of a Curve to make its parameter be its curvilinear abscissa If the curve is a curve on a surface S, C2D is the corresponding Pcurve, we considere the curve is given by its representation S(C2D(u)) If the curve is a curve on 2 surfaces S1 and S2 and C2D1 C2D2 are the two corresponding Pcurve, we considere the curve is given by its representation 1/2(S1(C2D1(u) + S2 (C2D2(u)))");

// Constructors
cls_Approx_CurvilinearParameter.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real, const GeomAbs_Shape, const Standard_Integer, const Standard_Integer>(), py::arg("C3D"), py::arg("Tol"), py::arg("Order"), py::arg("MaxDegree"), py::arg("MaxSegments"));
cls_Approx_CurvilinearParameter.def(py::init<const opencascade::handle<Adaptor2d_HCurve2d> &, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real, const GeomAbs_Shape, const Standard_Integer, const Standard_Integer>(), py::arg("C2D"), py::arg("Surf"), py::arg("Tol"), py::arg("Order"), py::arg("MaxDegree"), py::arg("MaxSegments"));
cls_Approx_CurvilinearParameter.def(py::init<const opencascade::handle<Adaptor2d_HCurve2d> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor2d_HCurve2d> &, const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real, const GeomAbs_Shape, const Standard_Integer, const Standard_Integer>(), py::arg("C2D1"), py::arg("Surf1"), py::arg("C2D2"), py::arg("Surf2"), py::arg("Tol"), py::arg("Order"), py::arg("MaxDegree"), py::arg("MaxSegments"));

// Fields

// Methods
// cls_Approx_CurvilinearParameter.def_static("operator new_", (void * (*)(size_t)) &Approx_CurvilinearParameter::operator new, "None", py::arg("theSize"));
// cls_Approx_CurvilinearParameter.def_static("operator delete_", (void (*)(void *)) &Approx_CurvilinearParameter::operator delete, "None", py::arg("theAddress"));
// cls_Approx_CurvilinearParameter.def_static("operator new[]_", (void * (*)(size_t)) &Approx_CurvilinearParameter::operator new[], "None", py::arg("theSize"));
// cls_Approx_CurvilinearParameter.def_static("operator delete[]_", (void (*)(void *)) &Approx_CurvilinearParameter::operator delete[], "None", py::arg("theAddress"));
// cls_Approx_CurvilinearParameter.def_static("operator new_", (void * (*)(size_t, void *)) &Approx_CurvilinearParameter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Approx_CurvilinearParameter.def_static("operator delete_", (void (*)(void *, void *)) &Approx_CurvilinearParameter::operator delete, "None", py::arg(""), py::arg(""));
cls_Approx_CurvilinearParameter.def("IsDone", (Standard_Boolean (Approx_CurvilinearParameter::*)() const) &Approx_CurvilinearParameter::IsDone, "None");
cls_Approx_CurvilinearParameter.def("HasResult", (Standard_Boolean (Approx_CurvilinearParameter::*)() const) &Approx_CurvilinearParameter::HasResult, "None");
cls_Approx_CurvilinearParameter.def("Curve3d", (opencascade::handle<Geom_BSplineCurve> (Approx_CurvilinearParameter::*)() const) &Approx_CurvilinearParameter::Curve3d, "returns the Bspline curve corresponding to the reparametrized 3D curve");
cls_Approx_CurvilinearParameter.def("MaxError3d", (Standard_Real (Approx_CurvilinearParameter::*)() const) &Approx_CurvilinearParameter::MaxError3d, "returns the maximum error on the reparametrized 3D curve");
cls_Approx_CurvilinearParameter.def("Curve2d1", (opencascade::handle<Geom2d_BSplineCurve> (Approx_CurvilinearParameter::*)() const) &Approx_CurvilinearParameter::Curve2d1, "returns the BsplineCurve representing the reparametrized 2D curve on the first surface (case of a curve on one or two surfaces)");
cls_Approx_CurvilinearParameter.def("MaxError2d1", (Standard_Real (Approx_CurvilinearParameter::*)() const) &Approx_CurvilinearParameter::MaxError2d1, "returns the maximum error on the first reparametrized 2D curve");
cls_Approx_CurvilinearParameter.def("Curve2d2", (opencascade::handle<Geom2d_BSplineCurve> (Approx_CurvilinearParameter::*)() const) &Approx_CurvilinearParameter::Curve2d2, "returns the BsplineCurve representing the reparametrized 2D curve on the second surface (case of a curve on two surfaces)");
cls_Approx_CurvilinearParameter.def("MaxError2d2", (Standard_Real (Approx_CurvilinearParameter::*)() const) &Approx_CurvilinearParameter::MaxError2d2, "returns the maximum error on the second reparametrized 2D curve");
cls_Approx_CurvilinearParameter.def("Dump", (void (Approx_CurvilinearParameter::*)(Standard_OStream &) const) &Approx_CurvilinearParameter::Dump, "print the maximum errors(s)", py::arg("o"));

// Enums

}