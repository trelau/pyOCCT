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
#include <IntRes2d_Intersection.hxx>
#include <Standard.hxx>
#include <IntCurve_IConicTool.hxx>
#include <IntRes2d_Domain.hxx>
#include <IntCurve_PConic.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt2d.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <IntCurve_IntImpConicParConic.hxx>

void bind_IntCurve_IntImpConicParConic(py::module &mod){

py::class_<IntCurve_IntImpConicParConic, IntRes2d_Intersection> cls_IntCurve_IntImpConicParConic(mod, "IntCurve_IntImpConicParConic", "None");

// Constructors
cls_IntCurve_IntImpConicParConic.def(py::init<>());
cls_IntCurve_IntImpConicParConic.def(py::init<const IntCurve_IConicTool &, const IntRes2d_Domain &, const IntCurve_PConic &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real>(), py::arg("ITool"), py::arg("Dom1"), py::arg("PCurve"), py::arg("Dom2"), py::arg("TolConf"), py::arg("Tol"));

// Fields

// Methods
// cls_IntCurve_IntImpConicParConic.def_static("operator new_", (void * (*)(size_t)) &IntCurve_IntImpConicParConic::operator new, "None", py::arg("theSize"));
// cls_IntCurve_IntImpConicParConic.def_static("operator delete_", (void (*)(void *)) &IntCurve_IntImpConicParConic::operator delete, "None", py::arg("theAddress"));
// cls_IntCurve_IntImpConicParConic.def_static("operator new[]_", (void * (*)(size_t)) &IntCurve_IntImpConicParConic::operator new[], "None", py::arg("theSize"));
// cls_IntCurve_IntImpConicParConic.def_static("operator delete[]_", (void (*)(void *)) &IntCurve_IntImpConicParConic::operator delete[], "None", py::arg("theAddress"));
// cls_IntCurve_IntImpConicParConic.def_static("operator new_", (void * (*)(size_t, void *)) &IntCurve_IntImpConicParConic::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntCurve_IntImpConicParConic.def_static("operator delete_", (void (*)(void *, void *)) &IntCurve_IntImpConicParConic::operator delete, "None", py::arg(""), py::arg(""));
cls_IntCurve_IntImpConicParConic.def("Perform", (void (IntCurve_IntImpConicParConic::*)(const IntCurve_IConicTool &, const IntRes2d_Domain &, const IntCurve_PConic &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real)) &IntCurve_IntImpConicParConic::Perform, "Intersection between an implicit curve and a parametrised curve. The exception ConstructionError is raised if the domain of the parametrised curve does not verify HasFirstPoint and HasLastPoint return True.", py::arg("ITool"), py::arg("Dom1"), py::arg("PCurve"), py::arg("Dom2"), py::arg("TolConf"), py::arg("Tol"));
cls_IntCurve_IntImpConicParConic.def("FindU", (Standard_Real (IntCurve_IntImpConicParConic::*)(const Standard_Real, gp_Pnt2d &, const IntCurve_PConic &, const IntCurve_IConicTool &) const) &IntCurve_IntImpConicParConic::FindU, "None", py::arg("parameter"), py::arg("point"), py::arg("TheParCurev"), py::arg("TheImpTool"));
cls_IntCurve_IntImpConicParConic.def("FindV", (Standard_Real (IntCurve_IntImpConicParConic::*)(const Standard_Real, gp_Pnt2d &, const IntCurve_IConicTool &, const IntCurve_PConic &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real, const Standard_Real) const) &IntCurve_IntImpConicParConic::FindV, "None", py::arg("parameter"), py::arg("point"), py::arg("TheImpTool"), py::arg("ParCurve"), py::arg("TheParCurveDomain"), py::arg("V0"), py::arg("V1"), py::arg("Tolerance"));
cls_IntCurve_IntImpConicParConic.def("And_Domaine_Objet1_Intersections", [](IntCurve_IntImpConicParConic &self, const IntCurve_IConicTool & TheImpTool, const IntCurve_PConic & TheParCurve, const IntRes2d_Domain & TheImpCurveDomain, const IntRes2d_Domain & TheParCurveDomain, Standard_Integer & NbResultats, TColStd_Array1OfReal & Inter2_And_Domain2, TColStd_Array1OfReal & Inter1, TColStd_Array1OfReal & Resultat1, TColStd_Array1OfReal & Resultat2, const Standard_Real EpsNul){ self.And_Domaine_Objet1_Intersections(TheImpTool, TheParCurve, TheImpCurveDomain, TheParCurveDomain, NbResultats, Inter2_And_Domain2, Inter1, Resultat1, Resultat2, EpsNul); return NbResultats; }, "None", py::arg("TheImpTool"), py::arg("TheParCurve"), py::arg("TheImpCurveDomain"), py::arg("TheParCurveDomain"), py::arg("NbResultats"), py::arg("Inter2_And_Domain2"), py::arg("Inter1"), py::arg("Resultat1"), py::arg("Resultat2"), py::arg("EpsNul"));

// Enums

}