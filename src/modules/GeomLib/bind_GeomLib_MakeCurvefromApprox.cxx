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
#include <AdvApprox_ApproxAFunction.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Geom2d_BSplineCurve.hxx>
#include <Geom_BSplineCurve.hxx>
#include <GeomLib_MakeCurvefromApprox.hxx>

void bind_GeomLib_MakeCurvefromApprox(py::module &mod){

py::class_<GeomLib_MakeCurvefromApprox> cls_GeomLib_MakeCurvefromApprox(mod, "GeomLib_MakeCurvefromApprox", "this class is used to construct the BSpline curve from an Approximation ( ApproxAFunction from AdvApprox).");

// Constructors
cls_GeomLib_MakeCurvefromApprox.def(py::init<const AdvApprox_ApproxAFunction &>(), py::arg("Approx"));

// Fields

// Methods
// cls_GeomLib_MakeCurvefromApprox.def_static("operator new_", (void * (*)(size_t)) &GeomLib_MakeCurvefromApprox::operator new, "None", py::arg("theSize"));
// cls_GeomLib_MakeCurvefromApprox.def_static("operator delete_", (void (*)(void *)) &GeomLib_MakeCurvefromApprox::operator delete, "None", py::arg("theAddress"));
// cls_GeomLib_MakeCurvefromApprox.def_static("operator new[]_", (void * (*)(size_t)) &GeomLib_MakeCurvefromApprox::operator new[], "None", py::arg("theSize"));
// cls_GeomLib_MakeCurvefromApprox.def_static("operator delete[]_", (void (*)(void *)) &GeomLib_MakeCurvefromApprox::operator delete[], "None", py::arg("theAddress"));
// cls_GeomLib_MakeCurvefromApprox.def_static("operator new_", (void * (*)(size_t, void *)) &GeomLib_MakeCurvefromApprox::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomLib_MakeCurvefromApprox.def_static("operator delete_", (void (*)(void *, void *)) &GeomLib_MakeCurvefromApprox::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomLib_MakeCurvefromApprox.def("IsDone", (Standard_Boolean (GeomLib_MakeCurvefromApprox::*)() const) &GeomLib_MakeCurvefromApprox::IsDone, "None");
cls_GeomLib_MakeCurvefromApprox.def("Nb1DSpaces", (Standard_Integer (GeomLib_MakeCurvefromApprox::*)() const) &GeomLib_MakeCurvefromApprox::Nb1DSpaces, "returns the number of 1D spaces of the Approx");
cls_GeomLib_MakeCurvefromApprox.def("Nb2DSpaces", (Standard_Integer (GeomLib_MakeCurvefromApprox::*)() const) &GeomLib_MakeCurvefromApprox::Nb2DSpaces, "returns the number of 3D spaces of the Approx");
cls_GeomLib_MakeCurvefromApprox.def("Nb3DSpaces", (Standard_Integer (GeomLib_MakeCurvefromApprox::*)() const) &GeomLib_MakeCurvefromApprox::Nb3DSpaces, "returns the number of 3D spaces of the Approx");
cls_GeomLib_MakeCurvefromApprox.def("Curve2d", (opencascade::handle<Geom2d_BSplineCurve> (GeomLib_MakeCurvefromApprox::*)(const Standard_Integer) const) &GeomLib_MakeCurvefromApprox::Curve2d, "returns a polynomial curve whose poles correspond to the Index2d 2D space if Index2d not in the Range [1,Nb2dSpaces] if the Approx is not Done", py::arg("Index2d"));
cls_GeomLib_MakeCurvefromApprox.def("Curve2dFromTwo1d", (opencascade::handle<Geom2d_BSplineCurve> (GeomLib_MakeCurvefromApprox::*)(const Standard_Integer, const Standard_Integer) const) &GeomLib_MakeCurvefromApprox::Curve2dFromTwo1d, "returns a 2D curve building it from the 1D curve in x at Index1d and y at Index2d amongst the 1D curves if Index1d not in the Range [1,Nb1dSpaces] if Index2d not in the Range [1,Nb1dSpaces] if the Approx is not Done", py::arg("Index1d"), py::arg("Index2d"));
cls_GeomLib_MakeCurvefromApprox.def("Curve2d", (opencascade::handle<Geom2d_BSplineCurve> (GeomLib_MakeCurvefromApprox::*)(const Standard_Integer, const Standard_Integer) const) &GeomLib_MakeCurvefromApprox::Curve2d, "returns a rational curve whose poles correspond to the index2d of the 2D space and whose weights correspond to one dimensional space of index 1d if Index1d not in the Range [1,Nb1dSpaces] if Index2d not in the Range [1,Nb2dSpaces] if the Approx is not Done", py::arg("Index1d"), py::arg("Index2d"));
cls_GeomLib_MakeCurvefromApprox.def("Curve", (opencascade::handle<Geom_BSplineCurve> (GeomLib_MakeCurvefromApprox::*)(const Standard_Integer) const) &GeomLib_MakeCurvefromApprox::Curve, "returns a polynomial curve whose poles correspond to the Index3D 3D space if Index3D not in the Range [1,Nb3dSpaces] if the Approx is not Done", py::arg("Index3d"));
cls_GeomLib_MakeCurvefromApprox.def("Curve", (opencascade::handle<Geom_BSplineCurve> (GeomLib_MakeCurvefromApprox::*)(const Standard_Integer, const Standard_Integer) const) &GeomLib_MakeCurvefromApprox::Curve, "returns a rational curve whose poles correspond to the index3D of the 3D space and whose weights correspond to the index1d 1D space. if Index1D not in the Range [1,Nb1dSpaces] if Index3D not in the Range [1,Nb3dSpaces] if the Approx is not Done", py::arg("Index1D"), py::arg("Index3D"));

// Enums

}