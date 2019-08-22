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
#include <GeomPlate_Surface.hxx>
#include <AdvApp2Var_Criterion.hxx>
#include <Standard_TypeDef.hxx>
#include <GeomAbs_Shape.hxx>
#include <Geom_BSplineSurface.hxx>
#include <GeomPlate_MakeApprox.hxx>

void bind_GeomPlate_MakeApprox(py::module &mod){

py::class_<GeomPlate_MakeApprox> cls_GeomPlate_MakeApprox(mod, "GeomPlate_MakeApprox", "Allows you to convert a GeomPlate surface into a BSpline.");

// Constructors
cls_GeomPlate_MakeApprox.def(py::init<const opencascade::handle<GeomPlate_Surface> &, const AdvApp2Var_Criterion &, const Standard_Real, const Standard_Integer, const Standard_Integer>(), py::arg("SurfPlate"), py::arg("PlateCrit"), py::arg("Tol3d"), py::arg("Nbmax"), py::arg("dgmax"));
cls_GeomPlate_MakeApprox.def(py::init<const opencascade::handle<GeomPlate_Surface> &, const AdvApp2Var_Criterion &, const Standard_Real, const Standard_Integer, const Standard_Integer, const GeomAbs_Shape>(), py::arg("SurfPlate"), py::arg("PlateCrit"), py::arg("Tol3d"), py::arg("Nbmax"), py::arg("dgmax"), py::arg("Continuity"));
cls_GeomPlate_MakeApprox.def(py::init<const opencascade::handle<GeomPlate_Surface> &, const AdvApp2Var_Criterion &, const Standard_Real, const Standard_Integer, const Standard_Integer, const GeomAbs_Shape, const Standard_Real>(), py::arg("SurfPlate"), py::arg("PlateCrit"), py::arg("Tol3d"), py::arg("Nbmax"), py::arg("dgmax"), py::arg("Continuity"), py::arg("EnlargeCoeff"));
cls_GeomPlate_MakeApprox.def(py::init<const opencascade::handle<GeomPlate_Surface> &, const Standard_Real, const Standard_Integer, const Standard_Integer, const Standard_Real>(), py::arg("SurfPlate"), py::arg("Tol3d"), py::arg("Nbmax"), py::arg("dgmax"), py::arg("dmax"));
cls_GeomPlate_MakeApprox.def(py::init<const opencascade::handle<GeomPlate_Surface> &, const Standard_Real, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Integer>(), py::arg("SurfPlate"), py::arg("Tol3d"), py::arg("Nbmax"), py::arg("dgmax"), py::arg("dmax"), py::arg("CritOrder"));
cls_GeomPlate_MakeApprox.def(py::init<const opencascade::handle<GeomPlate_Surface> &, const Standard_Real, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Integer, const GeomAbs_Shape>(), py::arg("SurfPlate"), py::arg("Tol3d"), py::arg("Nbmax"), py::arg("dgmax"), py::arg("dmax"), py::arg("CritOrder"), py::arg("Continuity"));
cls_GeomPlate_MakeApprox.def(py::init<const opencascade::handle<GeomPlate_Surface> &, const Standard_Real, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Integer, const GeomAbs_Shape, const Standard_Real>(), py::arg("SurfPlate"), py::arg("Tol3d"), py::arg("Nbmax"), py::arg("dgmax"), py::arg("dmax"), py::arg("CritOrder"), py::arg("Continuity"), py::arg("EnlargeCoeff"));

// Fields

// Methods
// cls_GeomPlate_MakeApprox.def_static("operator new_", (void * (*)(size_t)) &GeomPlate_MakeApprox::operator new, "None", py::arg("theSize"));
// cls_GeomPlate_MakeApprox.def_static("operator delete_", (void (*)(void *)) &GeomPlate_MakeApprox::operator delete, "None", py::arg("theAddress"));
// cls_GeomPlate_MakeApprox.def_static("operator new[]_", (void * (*)(size_t)) &GeomPlate_MakeApprox::operator new[], "None", py::arg("theSize"));
// cls_GeomPlate_MakeApprox.def_static("operator delete[]_", (void (*)(void *)) &GeomPlate_MakeApprox::operator delete[], "None", py::arg("theAddress"));
// cls_GeomPlate_MakeApprox.def_static("operator new_", (void * (*)(size_t, void *)) &GeomPlate_MakeApprox::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomPlate_MakeApprox.def_static("operator delete_", (void (*)(void *, void *)) &GeomPlate_MakeApprox::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomPlate_MakeApprox.def("Surface", (opencascade::handle<Geom_BSplineSurface> (GeomPlate_MakeApprox::*)() const) &GeomPlate_MakeApprox::Surface, "Returns the BSpline surface extracted from the GeomPlate_MakeApprox object.");
cls_GeomPlate_MakeApprox.def("ApproxError", (Standard_Real (GeomPlate_MakeApprox::*)() const) &GeomPlate_MakeApprox::ApproxError, "Returns the error in computation of the approximation surface. This is the distance between the entire target BSpline surface and the entire original surface generated by BuildPlateSurface and converted by GeomPlate_Surface.");
cls_GeomPlate_MakeApprox.def("CriterionError", (Standard_Real (GeomPlate_MakeApprox::*)() const) &GeomPlate_MakeApprox::CriterionError, "Returns the criterion error in computation of the approximation surface. This is estimated relative to the curve and point constraints only.");

// Enums

}