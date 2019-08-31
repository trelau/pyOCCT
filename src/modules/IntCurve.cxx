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
#include <gp_Lin2d.hxx>
#include <gp_Circ2d.hxx>
#include <gp_Elips2d.hxx>
#include <gp_Parab2d.hxx>
#include <gp_Hypr2d.hxx>
#include <IntCurve_IntConicConic.hxx>
#include <gp_Vec2d.hxx>
#include <gp_Ax22d.hxx>
#include <GeomAbs_CurveType.hxx>
#include <gp_Trsf2d.hxx>
#include <IntCurve_IntConicConic_Tool.hxx>
#include <math_FunctionWithDerivative.hxx>
#include <IntCurve_MyImpParToolOfIntImpConicParConic.hxx>
#include <IntCurve_PConicTool.hxx>
#include <IntCurve_ProjectOnPConicTool.hxx>

PYBIND11_MODULE(IntCurve, mod) {

py::module::import("OCCT.IntRes2d");
py::module::import("OCCT.Standard");
py::module::import("OCCT.gp");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.math");

// CLASS: INTCURVE_INTIMPCONICPARCONIC
py::class_<IntCurve_IntImpConicParConic, IntRes2d_Intersection> cls_IntCurve_IntImpConicParConic(mod, "IntCurve_IntImpConicParConic", "None");

// Constructors
cls_IntCurve_IntImpConicParConic.def(py::init<>());
cls_IntCurve_IntImpConicParConic.def(py::init<const IntCurve_IConicTool &, const IntRes2d_Domain &, const IntCurve_PConic &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real>(), py::arg("ITool"), py::arg("Dom1"), py::arg("PCurve"), py::arg("Dom2"), py::arg("TolConf"), py::arg("Tol"));

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

// CLASS: INTCURVE_INTCONICCONIC
py::class_<IntCurve_IntConicConic, IntRes2d_Intersection> cls_IntCurve_IntConicConic(mod, "IntCurve_IntConicConic", "Provides methods to intersect two conics. The exception ConstructionError is raised in constructors or in Perform methods when a domain (Domain from IntRes2d) is not correct, i-e when a Circle (Circ2d from gp) or an Ellipse (i-e Elips2d from gp) do not have a closed domain (use the SetEquivalentParameters method for a domain on a circle or an ellipse).");

// Constructors
cls_IntCurve_IntConicConic.def(py::init<>());
cls_IntCurve_IntConicConic.def(py::init<const gp_Lin2d &, const IntRes2d_Domain &, const gp_Lin2d &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real>(), py::arg("L1"), py::arg("D1"), py::arg("L2"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));
cls_IntCurve_IntConicConic.def(py::init<const gp_Lin2d &, const IntRes2d_Domain &, const gp_Circ2d &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("DL"), py::arg("C"), py::arg("DC"), py::arg("TolConf"), py::arg("Tol"));
cls_IntCurve_IntConicConic.def(py::init<const gp_Lin2d &, const IntRes2d_Domain &, const gp_Elips2d &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("DL"), py::arg("E"), py::arg("DE"), py::arg("TolConf"), py::arg("Tol"));
cls_IntCurve_IntConicConic.def(py::init<const gp_Lin2d &, const IntRes2d_Domain &, const gp_Parab2d &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("DL"), py::arg("P"), py::arg("DP"), py::arg("TolConf"), py::arg("Tol"));
cls_IntCurve_IntConicConic.def(py::init<const gp_Lin2d &, const IntRes2d_Domain &, const gp_Hypr2d &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("DL"), py::arg("H"), py::arg("DH"), py::arg("TolConf"), py::arg("Tol"));
cls_IntCurve_IntConicConic.def(py::init<const gp_Circ2d &, const IntRes2d_Domain &, const gp_Circ2d &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real>(), py::arg("C1"), py::arg("D1"), py::arg("C2"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));
cls_IntCurve_IntConicConic.def(py::init<const gp_Circ2d &, const IntRes2d_Domain &, const gp_Elips2d &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("DC"), py::arg("E"), py::arg("DE"), py::arg("TolConf"), py::arg("Tol"));
cls_IntCurve_IntConicConic.def(py::init<const gp_Circ2d &, const IntRes2d_Domain &, const gp_Parab2d &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("DC"), py::arg("P"), py::arg("DP"), py::arg("TolConf"), py::arg("Tol"));
cls_IntCurve_IntConicConic.def(py::init<const gp_Circ2d &, const IntRes2d_Domain &, const gp_Hypr2d &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("DC"), py::arg("H"), py::arg("DH"), py::arg("TolConf"), py::arg("Tol"));
cls_IntCurve_IntConicConic.def(py::init<const gp_Elips2d &, const IntRes2d_Domain &, const gp_Elips2d &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real>(), py::arg("E1"), py::arg("D1"), py::arg("E2"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));
cls_IntCurve_IntConicConic.def(py::init<const gp_Elips2d &, const IntRes2d_Domain &, const gp_Parab2d &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real>(), py::arg("E"), py::arg("DE"), py::arg("P"), py::arg("DP"), py::arg("TolConf"), py::arg("Tol"));
cls_IntCurve_IntConicConic.def(py::init<const gp_Elips2d &, const IntRes2d_Domain &, const gp_Hypr2d &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real>(), py::arg("E"), py::arg("DE"), py::arg("H"), py::arg("DH"), py::arg("TolConf"), py::arg("Tol"));
cls_IntCurve_IntConicConic.def(py::init<const gp_Parab2d &, const IntRes2d_Domain &, const gp_Parab2d &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real>(), py::arg("P1"), py::arg("D1"), py::arg("P2"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));
cls_IntCurve_IntConicConic.def(py::init<const gp_Parab2d &, const IntRes2d_Domain &, const gp_Hypr2d &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("DP"), py::arg("H"), py::arg("DH"), py::arg("TolConf"), py::arg("Tol"));
cls_IntCurve_IntConicConic.def(py::init<const gp_Hypr2d &, const IntRes2d_Domain &, const gp_Hypr2d &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real>(), py::arg("H1"), py::arg("D1"), py::arg("H2"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));

// Methods
// cls_IntCurve_IntConicConic.def_static("operator new_", (void * (*)(size_t)) &IntCurve_IntConicConic::operator new, "None", py::arg("theSize"));
// cls_IntCurve_IntConicConic.def_static("operator delete_", (void (*)(void *)) &IntCurve_IntConicConic::operator delete, "None", py::arg("theAddress"));
// cls_IntCurve_IntConicConic.def_static("operator new[]_", (void * (*)(size_t)) &IntCurve_IntConicConic::operator new[], "None", py::arg("theSize"));
// cls_IntCurve_IntConicConic.def_static("operator delete[]_", (void (*)(void *)) &IntCurve_IntConicConic::operator delete[], "None", py::arg("theAddress"));
// cls_IntCurve_IntConicConic.def_static("operator new_", (void * (*)(size_t, void *)) &IntCurve_IntConicConic::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntCurve_IntConicConic.def_static("operator delete_", (void (*)(void *, void *)) &IntCurve_IntConicConic::operator delete, "None", py::arg(""), py::arg(""));
cls_IntCurve_IntConicConic.def("Perform", (void (IntCurve_IntConicConic::*)(const gp_Lin2d &, const IntRes2d_Domain &, const gp_Lin2d &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real)) &IntCurve_IntConicConic::Perform, "Intersection between 2 lines from gp.", py::arg("L1"), py::arg("D1"), py::arg("L2"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));
cls_IntCurve_IntConicConic.def("Perform", (void (IntCurve_IntConicConic::*)(const gp_Lin2d &, const IntRes2d_Domain &, const gp_Circ2d &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real)) &IntCurve_IntConicConic::Perform, "Intersection between a line and a circle. The exception ConstructionError is raised if the method IsClosed of the domain of the circle returns False.", py::arg("L"), py::arg("DL"), py::arg("C"), py::arg("DC"), py::arg("TolConf"), py::arg("Tol"));
cls_IntCurve_IntConicConic.def("Perform", (void (IntCurve_IntConicConic::*)(const gp_Lin2d &, const IntRes2d_Domain &, const gp_Elips2d &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real)) &IntCurve_IntConicConic::Perform, "Intersection between a line and an ellipse. The exception ConstructionError is raised if the method IsClosed of the domain of the ellipse returns False.", py::arg("L"), py::arg("DL"), py::arg("E"), py::arg("DE"), py::arg("TolConf"), py::arg("Tol"));
cls_IntCurve_IntConicConic.def("Perform", (void (IntCurve_IntConicConic::*)(const gp_Lin2d &, const IntRes2d_Domain &, const gp_Parab2d &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real)) &IntCurve_IntConicConic::Perform, "Intersection between a line and a parabola from gp.", py::arg("L"), py::arg("DL"), py::arg("P"), py::arg("DP"), py::arg("TolConf"), py::arg("Tol"));
cls_IntCurve_IntConicConic.def("Perform", (void (IntCurve_IntConicConic::*)(const gp_Lin2d &, const IntRes2d_Domain &, const gp_Hypr2d &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real)) &IntCurve_IntConicConic::Perform, "Intersection between a line and an hyperbola.", py::arg("L"), py::arg("DL"), py::arg("H"), py::arg("DH"), py::arg("TolConf"), py::arg("Tol"));
cls_IntCurve_IntConicConic.def("Perform", (void (IntCurve_IntConicConic::*)(const gp_Circ2d &, const IntRes2d_Domain &, const gp_Circ2d &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real)) &IntCurve_IntConicConic::Perform, "Intersection between 2 circles from gp. The exception ConstructionError is raised if the method IsClosed of the domain of one of the circle returns False.", py::arg("C1"), py::arg("D1"), py::arg("C2"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));
cls_IntCurve_IntConicConic.def("Perform", (void (IntCurve_IntConicConic::*)(const gp_Circ2d &, const IntRes2d_Domain &, const gp_Elips2d &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real)) &IntCurve_IntConicConic::Perform, "Intersection between a circle and an ellipse. The exception ConstructionError is raised if the method IsClosed of one the domain returns False.", py::arg("C"), py::arg("DC"), py::arg("E"), py::arg("DE"), py::arg("TolConf"), py::arg("Tol"));
cls_IntCurve_IntConicConic.def("Perform", (void (IntCurve_IntConicConic::*)(const gp_Circ2d &, const IntRes2d_Domain &, const gp_Parab2d &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real)) &IntCurve_IntConicConic::Perform, "Intersection between a circle and a parabola. The exception ConstructionError is raised if the method IsClosed of the domain of the circle returns False.", py::arg("C"), py::arg("DC"), py::arg("P"), py::arg("DP"), py::arg("TolConf"), py::arg("Tol"));
cls_IntCurve_IntConicConic.def("Perform", (void (IntCurve_IntConicConic::*)(const gp_Circ2d &, const IntRes2d_Domain &, const gp_Hypr2d &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real)) &IntCurve_IntConicConic::Perform, "Intersection between a circle and an hyperbola. The exception ConstructionError is raised if the method IsClosed of the domain of the circle returns False.", py::arg("C"), py::arg("DC"), py::arg("H"), py::arg("DH"), py::arg("TolConf"), py::arg("Tol"));
cls_IntCurve_IntConicConic.def("Perform", (void (IntCurve_IntConicConic::*)(const gp_Elips2d &, const IntRes2d_Domain &, const gp_Elips2d &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real)) &IntCurve_IntConicConic::Perform, "Intersection between 2 ellipses. The exception ConstructionError is raised if the method IsClosed of one of the domain returns False.", py::arg("E1"), py::arg("D1"), py::arg("E2"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));
cls_IntCurve_IntConicConic.def("Perform", (void (IntCurve_IntConicConic::*)(const gp_Elips2d &, const IntRes2d_Domain &, const gp_Parab2d &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real)) &IntCurve_IntConicConic::Perform, "Intersection between an ellipse and a parabola. The exception ConstructionError is raised if the method IsClosed of the domain of the ellipse returns False.", py::arg("E"), py::arg("DE"), py::arg("P"), py::arg("DP"), py::arg("TolConf"), py::arg("Tol"));
cls_IntCurve_IntConicConic.def("Perform", (void (IntCurve_IntConicConic::*)(const gp_Elips2d &, const IntRes2d_Domain &, const gp_Hypr2d &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real)) &IntCurve_IntConicConic::Perform, "Intersection between an ellipse and an hyperbola. The exception ConstructionError is raised if the method IsClosed of the domain of the ellipse returns False.", py::arg("E"), py::arg("DE"), py::arg("H"), py::arg("DH"), py::arg("TolConf"), py::arg("Tol"));
cls_IntCurve_IntConicConic.def("Perform", (void (IntCurve_IntConicConic::*)(const gp_Parab2d &, const IntRes2d_Domain &, const gp_Parab2d &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real)) &IntCurve_IntConicConic::Perform, "Intersection between 2 parabolas.", py::arg("P1"), py::arg("D1"), py::arg("P2"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));
cls_IntCurve_IntConicConic.def("Perform", (void (IntCurve_IntConicConic::*)(const gp_Parab2d &, const IntRes2d_Domain &, const gp_Hypr2d &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real)) &IntCurve_IntConicConic::Perform, "Intersection between a parabola and an hyperbola.", py::arg("P"), py::arg("DP"), py::arg("H"), py::arg("DH"), py::arg("TolConf"), py::arg("Tol"));
cls_IntCurve_IntConicConic.def("Perform", (void (IntCurve_IntConicConic::*)(const gp_Hypr2d &, const IntRes2d_Domain &, const gp_Hypr2d &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real)) &IntCurve_IntConicConic::Perform, "Intersection between 2 hyperbolas.", py::arg("H1"), py::arg("D1"), py::arg("H2"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));

// CLASS: INTCURVE_ICONICTOOL
py::class_<IntCurve_IConicTool> cls_IntCurve_IConicTool(mod, "IntCurve_IConicTool", "Implementation of the ImpTool from IntImpParGen for conics of gp.");

// Constructors
cls_IntCurve_IConicTool.def(py::init<>());
cls_IntCurve_IConicTool.def(py::init<const IntCurve_IConicTool &>(), py::arg("IT"));
cls_IntCurve_IConicTool.def(py::init<const gp_Elips2d &>(), py::arg("E"));
cls_IntCurve_IConicTool.def(py::init<const gp_Lin2d &>(), py::arg("L"));
cls_IntCurve_IConicTool.def(py::init<const gp_Circ2d &>(), py::arg("C"));
cls_IntCurve_IConicTool.def(py::init<const gp_Parab2d &>(), py::arg("P"));
cls_IntCurve_IConicTool.def(py::init<const gp_Hypr2d &>(), py::arg("H"));

// Methods
// cls_IntCurve_IConicTool.def_static("operator new_", (void * (*)(size_t)) &IntCurve_IConicTool::operator new, "None", py::arg("theSize"));
// cls_IntCurve_IConicTool.def_static("operator delete_", (void (*)(void *)) &IntCurve_IConicTool::operator delete, "None", py::arg("theAddress"));
// cls_IntCurve_IConicTool.def_static("operator new[]_", (void * (*)(size_t)) &IntCurve_IConicTool::operator new[], "None", py::arg("theSize"));
// cls_IntCurve_IConicTool.def_static("operator delete[]_", (void (*)(void *)) &IntCurve_IConicTool::operator delete[], "None", py::arg("theAddress"));
// cls_IntCurve_IConicTool.def_static("operator new_", (void * (*)(size_t, void *)) &IntCurve_IConicTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntCurve_IConicTool.def_static("operator delete_", (void (*)(void *, void *)) &IntCurve_IConicTool::operator delete, "None", py::arg(""), py::arg(""));
cls_IntCurve_IConicTool.def("Value", (gp_Pnt2d (IntCurve_IConicTool::*)(const Standard_Real) const) &IntCurve_IConicTool::Value, "None", py::arg("X"));
cls_IntCurve_IConicTool.def("D1", (void (IntCurve_IConicTool::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &) const) &IntCurve_IConicTool::D1, "None", py::arg("U"), py::arg("P"), py::arg("T"));
cls_IntCurve_IConicTool.def("D2", (void (IntCurve_IConicTool::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &) const) &IntCurve_IConicTool::D2, "None", py::arg("U"), py::arg("P"), py::arg("T"), py::arg("N"));
cls_IntCurve_IConicTool.def("Distance", (Standard_Real (IntCurve_IConicTool::*)(const gp_Pnt2d &) const) &IntCurve_IConicTool::Distance, "Computes the value of the signed distance between the point P and the implicit curve.", py::arg("P"));
cls_IntCurve_IConicTool.def("GradDistance", (gp_Vec2d (IntCurve_IConicTool::*)(const gp_Pnt2d &) const) &IntCurve_IConicTool::GradDistance, "Computes the Gradient of the Signed Distance between a point and the implicit curve, at the point P.", py::arg("P"));
cls_IntCurve_IConicTool.def("FindParameter", (Standard_Real (IntCurve_IConicTool::*)(const gp_Pnt2d &) const) &IntCurve_IConicTool::FindParameter, "Returns the parameter U of the point on the implicit curve corresponding to the point P. The correspondance between P and the point P(U) on the implicit curve must be coherent with the way of determination of the signed distance.", py::arg("P"));

// CLASS: INTCURVE_PCONIC
py::class_<IntCurve_PConic> cls_IntCurve_PConic(mod, "IntCurve_PConic", "This class represents a conic from gp as a parametric curve ( in order to be used by the class PConicTool from IntCurve).");

// Constructors
cls_IntCurve_PConic.def(py::init<const IntCurve_PConic &>(), py::arg("PC"));
cls_IntCurve_PConic.def(py::init<const gp_Elips2d &>(), py::arg("E"));
cls_IntCurve_PConic.def(py::init<const gp_Circ2d &>(), py::arg("C"));
cls_IntCurve_PConic.def(py::init<const gp_Parab2d &>(), py::arg("P"));
cls_IntCurve_PConic.def(py::init<const gp_Hypr2d &>(), py::arg("H"));
cls_IntCurve_PConic.def(py::init<const gp_Lin2d &>(), py::arg("L"));

// Methods
// cls_IntCurve_PConic.def_static("operator new_", (void * (*)(size_t)) &IntCurve_PConic::operator new, "None", py::arg("theSize"));
// cls_IntCurve_PConic.def_static("operator delete_", (void (*)(void *)) &IntCurve_PConic::operator delete, "None", py::arg("theAddress"));
// cls_IntCurve_PConic.def_static("operator new[]_", (void * (*)(size_t)) &IntCurve_PConic::operator new[], "None", py::arg("theSize"));
// cls_IntCurve_PConic.def_static("operator delete[]_", (void (*)(void *)) &IntCurve_PConic::operator delete[], "None", py::arg("theAddress"));
// cls_IntCurve_PConic.def_static("operator new_", (void * (*)(size_t, void *)) &IntCurve_PConic::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntCurve_PConic.def_static("operator delete_", (void (*)(void *, void *)) &IntCurve_PConic::operator delete, "None", py::arg(""), py::arg(""));
cls_IntCurve_PConic.def("SetEpsX", (void (IntCurve_PConic::*)(const Standard_Real)) &IntCurve_PConic::SetEpsX, "EpsX is a internal tolerance used in math algorithms, usually about 1e-10 (See FunctionAllRoots for more details)", py::arg("EpsDist"));
cls_IntCurve_PConic.def("SetAccuracy", (void (IntCurve_PConic::*)(const Standard_Integer)) &IntCurve_PConic::SetAccuracy, "Accuracy is the number of samples used to approximate the parametric curve on its domain.", py::arg("Nb"));
cls_IntCurve_PConic.def("Accuracy", (Standard_Integer (IntCurve_PConic::*)() const) &IntCurve_PConic::Accuracy, "None");
cls_IntCurve_PConic.def("EpsX", (Standard_Real (IntCurve_PConic::*)() const) &IntCurve_PConic::EpsX, "None");
cls_IntCurve_PConic.def("TypeCurve", (GeomAbs_CurveType (IntCurve_PConic::*)() const) &IntCurve_PConic::TypeCurve, "The Conics are manipulated as objects which only depend on three parameters : Axis and two Real from Standards. Type Curve is used to select the correct Conic.");
cls_IntCurve_PConic.def("Axis2", (const gp_Ax22d & (IntCurve_PConic::*)() const) &IntCurve_PConic::Axis2, "None");
cls_IntCurve_PConic.def("Param1", (Standard_Real (IntCurve_PConic::*)() const) &IntCurve_PConic::Param1, "None");
cls_IntCurve_PConic.def("Param2", (Standard_Real (IntCurve_PConic::*)() const) &IntCurve_PConic::Param2, "None");

// CLASS: INTERVAL
py::class_<Interval> cls_Interval(mod, "Interval", "None");

// Constructors
// cls_Interval.def(py::init<>());
// cls_Interval.def(py::init<const Standard_Real, const Standard_Real>(), py::arg("a"), py::arg("b"));
// cls_Interval.def(py::init<const IntRes2d_Domain &>(), py::arg("Domain"));
// cls_Interval.def(py::init<const Standard_Real, const Standard_Boolean, const Standard_Real, const Standard_Boolean>(), py::arg("a"), py::arg("hf"), py::arg("b"), py::arg("hl"));

// Fields
cls_Interval.def_readwrite("Binf", &Interval::Binf, "None");
cls_Interval.def_readwrite("Bsup", &Interval::Bsup, "None");
cls_Interval.def_readwrite("HasFirstBound", &Interval::HasFirstBound, "None");
cls_Interval.def_readwrite("HasLastBound", &Interval::HasLastBound, "None");
cls_Interval.def_readwrite("IsNull", &Interval::IsNull, "None");

// Methods
// cls_Interval.def("Length", (Standard_Real (Interval::*)()) &Interval::Length, "None");
// cls_Interval.def("IntersectionWithBounded", (Interval (Interval::*)(const Interval &)) &Interval::IntersectionWithBounded, "None", py::arg("Inter"));

// CLASS: PERIODICINTERVAL
py::class_<PeriodicInterval> cls_PeriodicInterval(mod, "PeriodicInterval", "None");

// Constructors
cls_PeriodicInterval.def(py::init<const IntRes2d_Domain &>(), py::arg("Domain"));
cls_PeriodicInterval.def(py::init<>());
cls_PeriodicInterval.def(py::init<const Standard_Real, const Standard_Real>(), py::arg("a"), py::arg("b"));

// Fields
cls_PeriodicInterval.def_readwrite("Binf", &PeriodicInterval::Binf, "None");
cls_PeriodicInterval.def_readwrite("Bsup", &PeriodicInterval::Bsup, "None");
cls_PeriodicInterval.def_readwrite("isnull", &PeriodicInterval::isnull, "None");

// Methods
cls_PeriodicInterval.def("SetNull", (void (PeriodicInterval::*)()) &PeriodicInterval::SetNull, "None");
cls_PeriodicInterval.def("IsNull", (Standard_Boolean (PeriodicInterval::*)()) &PeriodicInterval::IsNull, "None");
cls_PeriodicInterval.def("Complement", (void (PeriodicInterval::*)()) &PeriodicInterval::Complement, "None");
cls_PeriodicInterval.def("Length", (Standard_Real (PeriodicInterval::*)()) &PeriodicInterval::Length, "None");
cls_PeriodicInterval.def("SetValues", (void (PeriodicInterval::*)(const Standard_Real, const Standard_Real)) &PeriodicInterval::SetValues, "None", py::arg("a"), py::arg("b"));
cls_PeriodicInterval.def("Normalize", (void (PeriodicInterval::*)()) &PeriodicInterval::Normalize, "None");
// cls_PeriodicInterval.def("FirstIntersection", (PeriodicInterval (PeriodicInterval::*)(PeriodicInterval &)) &PeriodicInterval::FirstIntersection, "None", py::arg("I1"));
// cls_PeriodicInterval.def("SecondIntersection", (PeriodicInterval (PeriodicInterval::*)(PeriodicInterval &)) &PeriodicInterval::SecondIntersection, "None", py::arg("I2"));

// CLASS: INTCURVE_MYIMPPARTOOLOFINTIMPCONICPARCONIC
py::class_<IntCurve_MyImpParToolOfIntImpConicParConic, math_FunctionWithDerivative> cls_IntCurve_MyImpParToolOfIntImpConicParConic(mod, "IntCurve_MyImpParToolOfIntImpConicParConic", "None");

// Constructors
cls_IntCurve_MyImpParToolOfIntImpConicParConic.def(py::init<const IntCurve_IConicTool &, const IntCurve_PConic &>(), py::arg("IT"), py::arg("PC"));

// Methods
// cls_IntCurve_MyImpParToolOfIntImpConicParConic.def_static("operator new_", (void * (*)(size_t)) &IntCurve_MyImpParToolOfIntImpConicParConic::operator new, "None", py::arg("theSize"));
// cls_IntCurve_MyImpParToolOfIntImpConicParConic.def_static("operator delete_", (void (*)(void *)) &IntCurve_MyImpParToolOfIntImpConicParConic::operator delete, "None", py::arg("theAddress"));
// cls_IntCurve_MyImpParToolOfIntImpConicParConic.def_static("operator new[]_", (void * (*)(size_t)) &IntCurve_MyImpParToolOfIntImpConicParConic::operator new[], "None", py::arg("theSize"));
// cls_IntCurve_MyImpParToolOfIntImpConicParConic.def_static("operator delete[]_", (void (*)(void *)) &IntCurve_MyImpParToolOfIntImpConicParConic::operator delete[], "None", py::arg("theAddress"));
// cls_IntCurve_MyImpParToolOfIntImpConicParConic.def_static("operator new_", (void * (*)(size_t, void *)) &IntCurve_MyImpParToolOfIntImpConicParConic::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntCurve_MyImpParToolOfIntImpConicParConic.def_static("operator delete_", (void (*)(void *, void *)) &IntCurve_MyImpParToolOfIntImpConicParConic::operator delete, "None", py::arg(""), py::arg(""));
cls_IntCurve_MyImpParToolOfIntImpConicParConic.def("Value", [](IntCurve_MyImpParToolOfIntImpConicParConic &self, const Standard_Real Param, Standard_Real & F){ Standard_Boolean rv = self.Value(Param, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "Computes the value of the signed distance between the implicit curve and the point at parameter Param on the parametrised curve.", py::arg("Param"), py::arg("F"));
cls_IntCurve_MyImpParToolOfIntImpConicParConic.def("Derivative", [](IntCurve_MyImpParToolOfIntImpConicParConic &self, const Standard_Real Param, Standard_Real & D){ Standard_Boolean rv = self.Derivative(Param, D); return std::tuple<Standard_Boolean, Standard_Real &>(rv, D); }, "Computes the derivative of the previous function at parameter Param.", py::arg("Param"), py::arg("D"));
cls_IntCurve_MyImpParToolOfIntImpConicParConic.def("Values", [](IntCurve_MyImpParToolOfIntImpConicParConic &self, const Standard_Real Param, Standard_Real & F, Standard_Real & D){ Standard_Boolean rv = self.Values(Param, F, D); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, F, D); }, "Computes the value and the derivative of the function.", py::arg("Param"), py::arg("F"), py::arg("D"));

// CLASS: INTCURVE_PCONICTOOL
py::class_<IntCurve_PConicTool> cls_IntCurve_PConicTool(mod, "IntCurve_PConicTool", "Implementation of the ParTool from IntImpParGen for conics of gp, using the class PConic from IntCurve.");

// Methods
// cls_IntCurve_PConicTool.def_static("operator new_", (void * (*)(size_t)) &IntCurve_PConicTool::operator new, "None", py::arg("theSize"));
// cls_IntCurve_PConicTool.def_static("operator delete_", (void (*)(void *)) &IntCurve_PConicTool::operator delete, "None", py::arg("theAddress"));
// cls_IntCurve_PConicTool.def_static("operator new[]_", (void * (*)(size_t)) &IntCurve_PConicTool::operator new[], "None", py::arg("theSize"));
// cls_IntCurve_PConicTool.def_static("operator delete[]_", (void (*)(void *)) &IntCurve_PConicTool::operator delete[], "None", py::arg("theAddress"));
// cls_IntCurve_PConicTool.def_static("operator new_", (void * (*)(size_t, void *)) &IntCurve_PConicTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntCurve_PConicTool.def_static("operator delete_", (void (*)(void *, void *)) &IntCurve_PConicTool::operator delete, "None", py::arg(""), py::arg(""));
cls_IntCurve_PConicTool.def_static("EpsX_", (Standard_Real (*)(const IntCurve_PConic &)) &IntCurve_PConicTool::EpsX, "None", py::arg("C"));
cls_IntCurve_PConicTool.def_static("NbSamples_", (Standard_Integer (*)(const IntCurve_PConic &)) &IntCurve_PConicTool::NbSamples, "None", py::arg("C"));
cls_IntCurve_PConicTool.def_static("NbSamples_", (Standard_Integer (*)(const IntCurve_PConic &, const Standard_Real, const Standard_Real)) &IntCurve_PConicTool::NbSamples, "None", py::arg("C"), py::arg("U0"), py::arg("U1"));
cls_IntCurve_PConicTool.def_static("Value_", (gp_Pnt2d (*)(const IntCurve_PConic &, const Standard_Real)) &IntCurve_PConicTool::Value, "None", py::arg("C"), py::arg("X"));
cls_IntCurve_PConicTool.def_static("D1_", (void (*)(const IntCurve_PConic &, const Standard_Real, gp_Pnt2d &, gp_Vec2d &)) &IntCurve_PConicTool::D1, "None", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("T"));
cls_IntCurve_PConicTool.def_static("D2_", (void (*)(const IntCurve_PConic &, const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &)) &IntCurve_PConicTool::D2, "None", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("T"), py::arg("N"));

// CLASS: INTCURVE_PROJECTONPCONICTOOL
py::class_<IntCurve_ProjectOnPConicTool> cls_IntCurve_ProjectOnPConicTool(mod, "IntCurve_ProjectOnPConicTool", "This class provides a tool which computes the parameter of a point near a parametric conic.");

// Methods
// cls_IntCurve_ProjectOnPConicTool.def_static("operator new_", (void * (*)(size_t)) &IntCurve_ProjectOnPConicTool::operator new, "None", py::arg("theSize"));
// cls_IntCurve_ProjectOnPConicTool.def_static("operator delete_", (void (*)(void *)) &IntCurve_ProjectOnPConicTool::operator delete, "None", py::arg("theAddress"));
// cls_IntCurve_ProjectOnPConicTool.def_static("operator new[]_", (void * (*)(size_t)) &IntCurve_ProjectOnPConicTool::operator new[], "None", py::arg("theSize"));
// cls_IntCurve_ProjectOnPConicTool.def_static("operator delete[]_", (void (*)(void *)) &IntCurve_ProjectOnPConicTool::operator delete[], "None", py::arg("theAddress"));
// cls_IntCurve_ProjectOnPConicTool.def_static("operator new_", (void * (*)(size_t, void *)) &IntCurve_ProjectOnPConicTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntCurve_ProjectOnPConicTool.def_static("operator delete_", (void (*)(void *, void *)) &IntCurve_ProjectOnPConicTool::operator delete, "None", py::arg(""), py::arg(""));
cls_IntCurve_ProjectOnPConicTool.def_static("FindParameter_", (Standard_Real (*)(const IntCurve_PConic &, const gp_Pnt2d &, const Standard_Real)) &IntCurve_ProjectOnPConicTool::FindParameter, "Returns the parameter V of the point on the parametric curve corresponding to the Point Pnt. The Correspondance between Pnt and the point P(V) on the parametric curve must be coherent with the way of determination of the signed distance between a point and the implicit curve. Tol is the tolerance on the distance between a point and the parametrised curve. In that case, no bounds are given. The research of the rigth parameter has to be made on the natural parametric domain of the curve.", py::arg("C"), py::arg("Pnt"), py::arg("Tol"));
cls_IntCurve_ProjectOnPConicTool.def_static("FindParameter_", (Standard_Real (*)(const IntCurve_PConic &, const gp_Pnt2d &, const Standard_Real, const Standard_Real, const Standard_Real)) &IntCurve_ProjectOnPConicTool::FindParameter, "Returns the parameter V of the point on the parametric curve corresponding to the Point Pnt. The Correspondance between Pnt and the point P(V) on the parametric curve must be coherent with the way of determination of the signed distance between a point and the implicit curve. Tol is the tolerance on the distance between a point and the parametrised curve. LowParameter and HighParameter give the boundaries of the interval in wich the parameter certainly lies. These parameters are given to implement a more efficient algoritm. So, it is not necessary to check that the returned value verifies LowParameter <= Value <= HighParameter.", py::arg("C"), py::arg("Pnt"), py::arg("LowParameter"), py::arg("HighParameter"), py::arg("Tol"));


}
