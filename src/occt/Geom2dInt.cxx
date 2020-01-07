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
#include <gp_Lin2d.hxx>
#include <IntRes2d_Domain.hxx>
#include <Adaptor2d_Curve2d.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Circ2d.hxx>
#include <gp_Elips2d.hxx>
#include <gp_Parab2d.hxx>
#include <gp_Hypr2d.hxx>
#include <IntCurve_IConicTool.hxx>
#include <Geom2dInt_TheIntConicCurveOfGInter.hxx>
#include <gp_Pnt2d.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <Geom2dInt_TheIntersectorOfTheIntConicCurveOfGInter.hxx>
#include <IntCurve_IntConicConic.hxx>
#include <Geom2dInt_IntConicCurveOfGInter.hxx>
#include <Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter.hxx>
#include <Geom2dInt_TheIntPCurvePCurveOfGInter.hxx>
#include <Geom2dInt_GInter.hxx>
#include <math_FunctionSetWithDerivatives.hxx>
#include <math_Vector.hxx>
#include <math_Matrix.hxx>
#include <Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter.hxx>
#include <Geom2dInt_ExactIntersectionPointOfTheIntPCurvePCurveOfGInter.hxx>
#include <GeomAbs_CurveType.hxx>
#include <gp_Vec2d.hxx>
#include <Geom2dInt_Geom2dCurveTool.hxx>
#include <math_FunctionWithDerivative.hxx>
#include <Geom2dInt_MyImpParToolOfTheIntersectorOfTheIntConicCurveOfGInter.hxx>
#include <Extrema_POnCurv2d.hxx>
#include <TColStd_SequenceOfReal.hxx>
#include <TColStd_SequenceOfInteger.hxx>
#include <Extrema_SequenceOfPOnCurv2d.hxx>
#include <Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter.hxx>
#include <Geom2dInt_TheCurveLocatorOfTheProjPCurOfGInter.hxx>
#include <Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter.hxx>
#include <Intf_Polygon2d.hxx>
#include <Bnd_Box2d.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <Geom2dInt_TheProjPCurOfGInter.hxx>

PYBIND11_MODULE(Geom2dInt, mod) {

py::module::import("OCCT.IntRes2d");
py::module::import("OCCT.Standard");
py::module::import("OCCT.gp");
py::module::import("OCCT.Adaptor2d");
py::module::import("OCCT.IntCurve");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.math");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.Extrema");
py::module::import("OCCT.Intf");
py::module::import("OCCT.Bnd");
py::module::import("OCCT.TColgp");

// CLASS: GEOM2DINT_THEINTCONICCURVEOFGINTER
py::class_<Geom2dInt_TheIntConicCurveOfGInter, IntRes2d_Intersection> cls_Geom2dInt_TheIntConicCurveOfGInter(mod, "Geom2dInt_TheIntConicCurveOfGInter", "None");

// Constructors
cls_Geom2dInt_TheIntConicCurveOfGInter.def(py::init<>());
cls_Geom2dInt_TheIntConicCurveOfGInter.def(py::init<const gp_Lin2d &, const IntRes2d_Domain &, const Adaptor2d_Curve2d &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("D1"), py::arg("PCurve"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));
cls_Geom2dInt_TheIntConicCurveOfGInter.def(py::init<const gp_Circ2d &, const IntRes2d_Domain &, const Adaptor2d_Curve2d &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("D1"), py::arg("PCurve"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));
cls_Geom2dInt_TheIntConicCurveOfGInter.def(py::init<const gp_Elips2d &, const IntRes2d_Domain &, const Adaptor2d_Curve2d &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real>(), py::arg("E"), py::arg("D1"), py::arg("PCurve"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));
cls_Geom2dInt_TheIntConicCurveOfGInter.def(py::init<const gp_Parab2d &, const IntRes2d_Domain &, const Adaptor2d_Curve2d &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real>(), py::arg("Prb"), py::arg("D1"), py::arg("PCurve"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));
cls_Geom2dInt_TheIntConicCurveOfGInter.def(py::init<const gp_Hypr2d &, const IntRes2d_Domain &, const Adaptor2d_Curve2d &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real>(), py::arg("H"), py::arg("D1"), py::arg("PCurve"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));

// Methods
// cls_Geom2dInt_TheIntConicCurveOfGInter.def_static("operator new_", (void * (*)(size_t)) &Geom2dInt_TheIntConicCurveOfGInter::operator new, "None", py::arg("theSize"));
// cls_Geom2dInt_TheIntConicCurveOfGInter.def_static("operator delete_", (void (*)(void *)) &Geom2dInt_TheIntConicCurveOfGInter::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dInt_TheIntConicCurveOfGInter.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dInt_TheIntConicCurveOfGInter::operator new[], "None", py::arg("theSize"));
// cls_Geom2dInt_TheIntConicCurveOfGInter.def_static("operator delete[]_", (void (*)(void *)) &Geom2dInt_TheIntConicCurveOfGInter::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dInt_TheIntConicCurveOfGInter.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dInt_TheIntConicCurveOfGInter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dInt_TheIntConicCurveOfGInter.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dInt_TheIntConicCurveOfGInter::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dInt_TheIntConicCurveOfGInter.def("Perform", (void (Geom2dInt_TheIntConicCurveOfGInter::*)(const gp_Lin2d &, const IntRes2d_Domain &, const Adaptor2d_Curve2d &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real)) &Geom2dInt_TheIntConicCurveOfGInter::Perform, "Intersection between a line and a parametric curve.", py::arg("L"), py::arg("D1"), py::arg("PCurve"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));
cls_Geom2dInt_TheIntConicCurveOfGInter.def("Perform", (void (Geom2dInt_TheIntConicCurveOfGInter::*)(const gp_Circ2d &, const IntRes2d_Domain &, const Adaptor2d_Curve2d &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real)) &Geom2dInt_TheIntConicCurveOfGInter::Perform, "Intersection between a line and a parametric curve.", py::arg("C"), py::arg("D1"), py::arg("PCurve"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));
cls_Geom2dInt_TheIntConicCurveOfGInter.def("Perform", (void (Geom2dInt_TheIntConicCurveOfGInter::*)(const gp_Elips2d &, const IntRes2d_Domain &, const Adaptor2d_Curve2d &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real)) &Geom2dInt_TheIntConicCurveOfGInter::Perform, "Intersection between an ellipse and a parametric curve.", py::arg("E"), py::arg("D1"), py::arg("PCurve"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));
cls_Geom2dInt_TheIntConicCurveOfGInter.def("Perform", (void (Geom2dInt_TheIntConicCurveOfGInter::*)(const gp_Parab2d &, const IntRes2d_Domain &, const Adaptor2d_Curve2d &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real)) &Geom2dInt_TheIntConicCurveOfGInter::Perform, "Intersection between a parabola and a parametric curve.", py::arg("Prb"), py::arg("D1"), py::arg("PCurve"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));
cls_Geom2dInt_TheIntConicCurveOfGInter.def("Perform", (void (Geom2dInt_TheIntConicCurveOfGInter::*)(const gp_Hypr2d &, const IntRes2d_Domain &, const Adaptor2d_Curve2d &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real)) &Geom2dInt_TheIntConicCurveOfGInter::Perform, "Intersection between the main branch of an hyperbola and a parametric curve.", py::arg("H"), py::arg("D1"), py::arg("PCurve"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));

// CLASS: GEOM2DINT_THEINTERSECTOROFTHEINTCONICCURVEOFGINTER
py::class_<Geom2dInt_TheIntersectorOfTheIntConicCurveOfGInter, IntRes2d_Intersection> cls_Geom2dInt_TheIntersectorOfTheIntConicCurveOfGInter(mod, "Geom2dInt_TheIntersectorOfTheIntConicCurveOfGInter", "None");

// Constructors
cls_Geom2dInt_TheIntersectorOfTheIntConicCurveOfGInter.def(py::init<>());
cls_Geom2dInt_TheIntersectorOfTheIntConicCurveOfGInter.def(py::init<const IntCurve_IConicTool &, const IntRes2d_Domain &, const Adaptor2d_Curve2d &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real>(), py::arg("ITool"), py::arg("Dom1"), py::arg("PCurve"), py::arg("Dom2"), py::arg("TolConf"), py::arg("Tol"));

// Methods
// cls_Geom2dInt_TheIntersectorOfTheIntConicCurveOfGInter.def_static("operator new_", (void * (*)(size_t)) &Geom2dInt_TheIntersectorOfTheIntConicCurveOfGInter::operator new, "None", py::arg("theSize"));
// cls_Geom2dInt_TheIntersectorOfTheIntConicCurveOfGInter.def_static("operator delete_", (void (*)(void *)) &Geom2dInt_TheIntersectorOfTheIntConicCurveOfGInter::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dInt_TheIntersectorOfTheIntConicCurveOfGInter.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dInt_TheIntersectorOfTheIntConicCurveOfGInter::operator new[], "None", py::arg("theSize"));
// cls_Geom2dInt_TheIntersectorOfTheIntConicCurveOfGInter.def_static("operator delete[]_", (void (*)(void *)) &Geom2dInt_TheIntersectorOfTheIntConicCurveOfGInter::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dInt_TheIntersectorOfTheIntConicCurveOfGInter.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dInt_TheIntersectorOfTheIntConicCurveOfGInter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dInt_TheIntersectorOfTheIntConicCurveOfGInter.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dInt_TheIntersectorOfTheIntConicCurveOfGInter::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dInt_TheIntersectorOfTheIntConicCurveOfGInter.def("Perform", (void (Geom2dInt_TheIntersectorOfTheIntConicCurveOfGInter::*)(const IntCurve_IConicTool &, const IntRes2d_Domain &, const Adaptor2d_Curve2d &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real)) &Geom2dInt_TheIntersectorOfTheIntConicCurveOfGInter::Perform, "Intersection between an implicit curve and a parametrised curve. The exception ConstructionError is raised if the domain of the parametrised curve does not verify HasFirstPoint and HasLastPoint return True.", py::arg("ITool"), py::arg("Dom1"), py::arg("PCurve"), py::arg("Dom2"), py::arg("TolConf"), py::arg("Tol"));
cls_Geom2dInt_TheIntersectorOfTheIntConicCurveOfGInter.def("FindU", (Standard_Real (Geom2dInt_TheIntersectorOfTheIntConicCurveOfGInter::*)(const Standard_Real, gp_Pnt2d &, const Adaptor2d_Curve2d &, const IntCurve_IConicTool &) const) &Geom2dInt_TheIntersectorOfTheIntConicCurveOfGInter::FindU, "None", py::arg("parameter"), py::arg("point"), py::arg("TheParCurev"), py::arg("IntCurve_IConicTool"));
cls_Geom2dInt_TheIntersectorOfTheIntConicCurveOfGInter.def("FindV", (Standard_Real (Geom2dInt_TheIntersectorOfTheIntConicCurveOfGInter::*)(const Standard_Real, gp_Pnt2d &, const IntCurve_IConicTool &, const Adaptor2d_Curve2d &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real, const Standard_Real) const) &Geom2dInt_TheIntersectorOfTheIntConicCurveOfGInter::FindV, "None", py::arg("parameter"), py::arg("point"), py::arg("IntCurve_IConicTool"), py::arg("ParCurve"), py::arg("TheParCurveDomain"), py::arg("V0"), py::arg("V1"), py::arg("Tolerance"));
cls_Geom2dInt_TheIntersectorOfTheIntConicCurveOfGInter.def("And_Domaine_Objet1_Intersections", [](Geom2dInt_TheIntersectorOfTheIntConicCurveOfGInter &self, const IntCurve_IConicTool & IntCurve_IConicTool, const Adaptor2d_Curve2d & TheParCurve, const IntRes2d_Domain & TheImpCurveDomain, const IntRes2d_Domain & TheParCurveDomain, Standard_Integer & NbResultats, TColStd_Array1OfReal & Inter2_And_Domain2, TColStd_Array1OfReal & Inter1, TColStd_Array1OfReal & Resultat1, TColStd_Array1OfReal & Resultat2, const Standard_Real EpsNul){ self.And_Domaine_Objet1_Intersections(IntCurve_IConicTool, TheParCurve, TheImpCurveDomain, TheParCurveDomain, NbResultats, Inter2_And_Domain2, Inter1, Resultat1, Resultat2, EpsNul); return NbResultats; }, "None", py::arg("IntCurve_IConicTool"), py::arg("TheParCurve"), py::arg("TheImpCurveDomain"), py::arg("TheParCurveDomain"), py::arg("NbResultats"), py::arg("Inter2_And_Domain2"), py::arg("Inter1"), py::arg("Resultat1"), py::arg("Resultat2"), py::arg("EpsNul"));

// CLASS: GEOM2DINT_INTCONICCURVEOFGINTER
py::class_<Geom2dInt_IntConicCurveOfGInter, IntRes2d_Intersection> cls_Geom2dInt_IntConicCurveOfGInter(mod, "Geom2dInt_IntConicCurveOfGInter", "None");

// Constructors
cls_Geom2dInt_IntConicCurveOfGInter.def(py::init<>());
cls_Geom2dInt_IntConicCurveOfGInter.def(py::init<const gp_Lin2d &, const IntRes2d_Domain &, const Adaptor2d_Curve2d &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("D1"), py::arg("PCurve"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));
cls_Geom2dInt_IntConicCurveOfGInter.def(py::init<const gp_Circ2d &, const IntRes2d_Domain &, const Adaptor2d_Curve2d &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("D1"), py::arg("PCurve"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));
cls_Geom2dInt_IntConicCurveOfGInter.def(py::init<const gp_Elips2d &, const IntRes2d_Domain &, const Adaptor2d_Curve2d &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real>(), py::arg("E"), py::arg("D1"), py::arg("PCurve"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));
cls_Geom2dInt_IntConicCurveOfGInter.def(py::init<const gp_Parab2d &, const IntRes2d_Domain &, const Adaptor2d_Curve2d &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real>(), py::arg("Prb"), py::arg("D1"), py::arg("PCurve"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));
cls_Geom2dInt_IntConicCurveOfGInter.def(py::init<const gp_Hypr2d &, const IntRes2d_Domain &, const Adaptor2d_Curve2d &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real>(), py::arg("H"), py::arg("D1"), py::arg("PCurve"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));

// Methods
// cls_Geom2dInt_IntConicCurveOfGInter.def_static("operator new_", (void * (*)(size_t)) &Geom2dInt_IntConicCurveOfGInter::operator new, "None", py::arg("theSize"));
// cls_Geom2dInt_IntConicCurveOfGInter.def_static("operator delete_", (void (*)(void *)) &Geom2dInt_IntConicCurveOfGInter::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dInt_IntConicCurveOfGInter.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dInt_IntConicCurveOfGInter::operator new[], "None", py::arg("theSize"));
// cls_Geom2dInt_IntConicCurveOfGInter.def_static("operator delete[]_", (void (*)(void *)) &Geom2dInt_IntConicCurveOfGInter::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dInt_IntConicCurveOfGInter.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dInt_IntConicCurveOfGInter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dInt_IntConicCurveOfGInter.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dInt_IntConicCurveOfGInter::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dInt_IntConicCurveOfGInter.def("Perform", (void (Geom2dInt_IntConicCurveOfGInter::*)(const gp_Lin2d &, const IntRes2d_Domain &, const Adaptor2d_Curve2d &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real)) &Geom2dInt_IntConicCurveOfGInter::Perform, "Intersection between a line and a parametric curve.", py::arg("L"), py::arg("D1"), py::arg("PCurve"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));
cls_Geom2dInt_IntConicCurveOfGInter.def("Perform", (void (Geom2dInt_IntConicCurveOfGInter::*)(const gp_Circ2d &, const IntRes2d_Domain &, const Adaptor2d_Curve2d &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real)) &Geom2dInt_IntConicCurveOfGInter::Perform, "Intersection between a line and a parametric curve.", py::arg("C"), py::arg("D1"), py::arg("PCurve"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));
cls_Geom2dInt_IntConicCurveOfGInter.def("Perform", (void (Geom2dInt_IntConicCurveOfGInter::*)(const gp_Elips2d &, const IntRes2d_Domain &, const Adaptor2d_Curve2d &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real)) &Geom2dInt_IntConicCurveOfGInter::Perform, "Intersection between an ellipse and a parametric curve.", py::arg("E"), py::arg("D1"), py::arg("PCurve"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));
cls_Geom2dInt_IntConicCurveOfGInter.def("Perform", (void (Geom2dInt_IntConicCurveOfGInter::*)(const gp_Parab2d &, const IntRes2d_Domain &, const Adaptor2d_Curve2d &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real)) &Geom2dInt_IntConicCurveOfGInter::Perform, "Intersection between a parabola and a parametric curve.", py::arg("Prb"), py::arg("D1"), py::arg("PCurve"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));
cls_Geom2dInt_IntConicCurveOfGInter.def("Perform", (void (Geom2dInt_IntConicCurveOfGInter::*)(const gp_Hypr2d &, const IntRes2d_Domain &, const Adaptor2d_Curve2d &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real)) &Geom2dInt_IntConicCurveOfGInter::Perform, "Intersection between the main branch of an hyperbola and a parametric curve.", py::arg("H"), py::arg("D1"), py::arg("PCurve"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));

// CLASS: GEOM2DINT_THEINTPCURVEPCURVEOFGINTER
py::class_<Geom2dInt_TheIntPCurvePCurveOfGInter, IntRes2d_Intersection> cls_Geom2dInt_TheIntPCurvePCurveOfGInter(mod, "Geom2dInt_TheIntPCurvePCurveOfGInter", "None");

// Constructors
cls_Geom2dInt_TheIntPCurvePCurveOfGInter.def(py::init<>());

// Methods
// cls_Geom2dInt_TheIntPCurvePCurveOfGInter.def_static("operator new_", (void * (*)(size_t)) &Geom2dInt_TheIntPCurvePCurveOfGInter::operator new, "None", py::arg("theSize"));
// cls_Geom2dInt_TheIntPCurvePCurveOfGInter.def_static("operator delete_", (void (*)(void *)) &Geom2dInt_TheIntPCurvePCurveOfGInter::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dInt_TheIntPCurvePCurveOfGInter.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dInt_TheIntPCurvePCurveOfGInter::operator new[], "None", py::arg("theSize"));
// cls_Geom2dInt_TheIntPCurvePCurveOfGInter.def_static("operator delete[]_", (void (*)(void *)) &Geom2dInt_TheIntPCurvePCurveOfGInter::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dInt_TheIntPCurvePCurveOfGInter.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dInt_TheIntPCurvePCurveOfGInter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dInt_TheIntPCurvePCurveOfGInter.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dInt_TheIntPCurvePCurveOfGInter::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dInt_TheIntPCurvePCurveOfGInter.def("Perform", (void (Geom2dInt_TheIntPCurvePCurveOfGInter::*)(const Adaptor2d_Curve2d &, const IntRes2d_Domain &, const Adaptor2d_Curve2d &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real)) &Geom2dInt_TheIntPCurvePCurveOfGInter::Perform, "None", py::arg("Curve1"), py::arg("Domain1"), py::arg("Curve2"), py::arg("Domain2"), py::arg("TolConf"), py::arg("Tol"));
cls_Geom2dInt_TheIntPCurvePCurveOfGInter.def("Perform", (void (Geom2dInt_TheIntPCurvePCurveOfGInter::*)(const Adaptor2d_Curve2d &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real)) &Geom2dInt_TheIntPCurvePCurveOfGInter::Perform, "None", py::arg("Curve1"), py::arg("Domain1"), py::arg("TolConf"), py::arg("Tol"));
cls_Geom2dInt_TheIntPCurvePCurveOfGInter.def("SetMinNbSamples", (void (Geom2dInt_TheIntPCurvePCurveOfGInter::*)(const Standard_Integer)) &Geom2dInt_TheIntPCurvePCurveOfGInter::SetMinNbSamples, "Set / get minimum number of points in polygon for intersection.", py::arg("theMinNbSamples"));
cls_Geom2dInt_TheIntPCurvePCurveOfGInter.def("GetMinNbSamples", (Standard_Integer (Geom2dInt_TheIntPCurvePCurveOfGInter::*)() const) &Geom2dInt_TheIntPCurvePCurveOfGInter::GetMinNbSamples, "None");

// CLASS: GEOM2DINT_GINTER
py::class_<Geom2dInt_GInter, IntRes2d_Intersection> cls_Geom2dInt_GInter(mod, "Geom2dInt_GInter", "None");

// Constructors
cls_Geom2dInt_GInter.def(py::init<>());
cls_Geom2dInt_GInter.def(py::init<const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("TolConf"), py::arg("Tol"));
cls_Geom2dInt_GInter.def(py::init<const Adaptor2d_Curve2d &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("D"), py::arg("TolConf"), py::arg("Tol"));
cls_Geom2dInt_GInter.def(py::init<const Adaptor2d_Curve2d &, const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("TolConf"), py::arg("Tol"));
cls_Geom2dInt_GInter.def(py::init<const Adaptor2d_Curve2d &, const IntRes2d_Domain &, const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real>(), py::arg("C1"), py::arg("D1"), py::arg("C2"), py::arg("TolConf"), py::arg("Tol"));
cls_Geom2dInt_GInter.def(py::init<const Adaptor2d_Curve2d &, const Adaptor2d_Curve2d &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));
cls_Geom2dInt_GInter.def(py::init<const Adaptor2d_Curve2d &, const IntRes2d_Domain &, const Adaptor2d_Curve2d &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real>(), py::arg("C1"), py::arg("D1"), py::arg("C2"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));

// Methods
// cls_Geom2dInt_GInter.def_static("operator new_", (void * (*)(size_t)) &Geom2dInt_GInter::operator new, "None", py::arg("theSize"));
// cls_Geom2dInt_GInter.def_static("operator delete_", (void (*)(void *)) &Geom2dInt_GInter::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dInt_GInter.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dInt_GInter::operator new[], "None", py::arg("theSize"));
// cls_Geom2dInt_GInter.def_static("operator delete[]_", (void (*)(void *)) &Geom2dInt_GInter::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dInt_GInter.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dInt_GInter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dInt_GInter.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dInt_GInter::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dInt_GInter.def("Perform", (void (Geom2dInt_GInter::*)(const Adaptor2d_Curve2d &, const IntRes2d_Domain &, const Adaptor2d_Curve2d &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real)) &Geom2dInt_GInter::Perform, "Intersection between 2 curves.", py::arg("C1"), py::arg("D1"), py::arg("C2"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));
cls_Geom2dInt_GInter.def("Perform", (void (Geom2dInt_GInter::*)(const Adaptor2d_Curve2d &, const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real)) &Geom2dInt_GInter::Perform, "Intersection between 2 curves.", py::arg("C1"), py::arg("C2"), py::arg("TolConf"), py::arg("Tol"));
cls_Geom2dInt_GInter.def("Perform", (void (Geom2dInt_GInter::*)(const Adaptor2d_Curve2d &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real)) &Geom2dInt_GInter::Perform, "Intersection between 2 curves.", py::arg("C1"), py::arg("D1"), py::arg("TolConf"), py::arg("Tol"));
cls_Geom2dInt_GInter.def("Perform", (void (Geom2dInt_GInter::*)(const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real)) &Geom2dInt_GInter::Perform, "Intersection between 2 curves.", py::arg("C1"), py::arg("TolConf"), py::arg("Tol"));
cls_Geom2dInt_GInter.def("Perform", (void (Geom2dInt_GInter::*)(const Adaptor2d_Curve2d &, const IntRes2d_Domain &, const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real)) &Geom2dInt_GInter::Perform, "Intersection between 2 curves.", py::arg("C1"), py::arg("D1"), py::arg("C2"), py::arg("TolConf"), py::arg("Tol"));
cls_Geom2dInt_GInter.def("Perform", (void (Geom2dInt_GInter::*)(const Adaptor2d_Curve2d &, const Adaptor2d_Curve2d &, const IntRes2d_Domain &, const Standard_Real, const Standard_Real)) &Geom2dInt_GInter::Perform, "Intersection between 2 curves.", py::arg("C1"), py::arg("C2"), py::arg("D2"), py::arg("TolConf"), py::arg("Tol"));
cls_Geom2dInt_GInter.def("ComputeDomain", (IntRes2d_Domain (Geom2dInt_GInter::*)(const Adaptor2d_Curve2d &, const Standard_Real) const) &Geom2dInt_GInter::ComputeDomain, "Create a domain from a curve", py::arg("C1"), py::arg("TolDomain"));
cls_Geom2dInt_GInter.def("SetMinNbSamples", (void (Geom2dInt_GInter::*)(const Standard_Integer)) &Geom2dInt_GInter::SetMinNbSamples, "Set / get minimum number of points in polygon intersection.", py::arg("theMinNbSamples"));
cls_Geom2dInt_GInter.def("GetMinNbSamples", (Standard_Integer (Geom2dInt_GInter::*)() const) &Geom2dInt_GInter::GetMinNbSamples, "None");

// CLASS: GEOM2DINT_THEDISTBETWEENPCURVESOFTHEINTPCURVEPCURVEOFGINTER
py::class_<Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter, math_FunctionSetWithDerivatives> cls_Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter(mod, "Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter", "None");

// Constructors
cls_Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter.def(py::init<const Adaptor2d_Curve2d &, const Adaptor2d_Curve2d &>(), py::arg("curve1"), py::arg("curve2"));

// Methods
// cls_Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter.def_static("operator new_", (void * (*)(size_t)) &Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter::operator new, "None", py::arg("theSize"));
// cls_Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter.def_static("operator delete_", (void (*)(void *)) &Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter::operator new[], "None", py::arg("theSize"));
// cls_Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter.def_static("operator delete[]_", (void (*)(void *)) &Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter.def("NbVariables", (Standard_Integer (Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter::*)() const) &Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter::NbVariables, "returns 2.");
cls_Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter.def("NbEquations", (Standard_Integer (Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter::*)() const) &Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter::NbEquations, "returns 2.");
cls_Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter.def("Value", (Standard_Boolean (Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter::*)(const math_Vector &, math_Vector &)) &Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter::Value, "computes the values <F> of the Functions for the variable <X>. returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
cls_Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter.def("Derivatives", (Standard_Boolean (Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter::*)(const math_Vector &, math_Matrix &)) &Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter::Derivatives, "returns the values <D> of the derivatives for the variable <X>. returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("D"));
cls_Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter.def("Values", (Standard_Boolean (Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter::*)(const math_Vector &, math_Vector &, math_Matrix &)) &Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter::Values, "returns the values <F> of the functions and the derivatives <D> for the variable <X>. returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));

// CLASS: GEOM2DINT_EXACTINTERSECTIONPOINTOFTHEINTPCURVEPCURVEOFGINTER
py::class_<Geom2dInt_ExactIntersectionPointOfTheIntPCurvePCurveOfGInter> cls_Geom2dInt_ExactIntersectionPointOfTheIntPCurvePCurveOfGInter(mod, "Geom2dInt_ExactIntersectionPointOfTheIntPCurvePCurveOfGInter", "None");

// Constructors
cls_Geom2dInt_ExactIntersectionPointOfTheIntPCurvePCurveOfGInter.def(py::init<const Adaptor2d_Curve2d &, const Adaptor2d_Curve2d &, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("Tol"));

// Methods
// cls_Geom2dInt_ExactIntersectionPointOfTheIntPCurvePCurveOfGInter.def_static("operator new_", (void * (*)(size_t)) &Geom2dInt_ExactIntersectionPointOfTheIntPCurvePCurveOfGInter::operator new, "None", py::arg("theSize"));
// cls_Geom2dInt_ExactIntersectionPointOfTheIntPCurvePCurveOfGInter.def_static("operator delete_", (void (*)(void *)) &Geom2dInt_ExactIntersectionPointOfTheIntPCurvePCurveOfGInter::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dInt_ExactIntersectionPointOfTheIntPCurvePCurveOfGInter.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dInt_ExactIntersectionPointOfTheIntPCurvePCurveOfGInter::operator new[], "None", py::arg("theSize"));
// cls_Geom2dInt_ExactIntersectionPointOfTheIntPCurvePCurveOfGInter.def_static("operator delete[]_", (void (*)(void *)) &Geom2dInt_ExactIntersectionPointOfTheIntPCurvePCurveOfGInter::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dInt_ExactIntersectionPointOfTheIntPCurvePCurveOfGInter.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dInt_ExactIntersectionPointOfTheIntPCurvePCurveOfGInter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dInt_ExactIntersectionPointOfTheIntPCurvePCurveOfGInter.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dInt_ExactIntersectionPointOfTheIntPCurvePCurveOfGInter::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dInt_ExactIntersectionPointOfTheIntPCurvePCurveOfGInter.def("Perform", [](Geom2dInt_ExactIntersectionPointOfTheIntPCurvePCurveOfGInter &self, const Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter & Poly1, const Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter & Poly2, Standard_Integer & NumSegOn1, Standard_Integer & NumSegOn2, Standard_Real & ParamOnSeg1, Standard_Real & ParamOnSeg2){ self.Perform(Poly1, Poly2, NumSegOn1, NumSegOn2, ParamOnSeg1, ParamOnSeg2); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Real &, Standard_Real &>(NumSegOn1, NumSegOn2, ParamOnSeg1, ParamOnSeg2); }, "None", py::arg("Poly1"), py::arg("Poly2"), py::arg("NumSegOn1"), py::arg("NumSegOn2"), py::arg("ParamOnSeg1"), py::arg("ParamOnSeg2"));
cls_Geom2dInt_ExactIntersectionPointOfTheIntPCurvePCurveOfGInter.def("Perform", (void (Geom2dInt_ExactIntersectionPointOfTheIntPCurvePCurveOfGInter::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Geom2dInt_ExactIntersectionPointOfTheIntPCurvePCurveOfGInter::Perform, "None", py::arg("Uo"), py::arg("Vo"), py::arg("UInf"), py::arg("VInf"), py::arg("USup"), py::arg("VSup"));
cls_Geom2dInt_ExactIntersectionPointOfTheIntPCurvePCurveOfGInter.def("NbRoots", (Standard_Integer (Geom2dInt_ExactIntersectionPointOfTheIntPCurvePCurveOfGInter::*)() const) &Geom2dInt_ExactIntersectionPointOfTheIntPCurvePCurveOfGInter::NbRoots, "None");
cls_Geom2dInt_ExactIntersectionPointOfTheIntPCurvePCurveOfGInter.def("Roots", [](Geom2dInt_ExactIntersectionPointOfTheIntPCurvePCurveOfGInter &self, Standard_Real & U, Standard_Real & V){ self.Roots(U, V); return std::tuple<Standard_Real &, Standard_Real &>(U, V); }, "None", py::arg("U"), py::arg("V"));
cls_Geom2dInt_ExactIntersectionPointOfTheIntPCurvePCurveOfGInter.def("AnErrorOccurred", (Standard_Boolean (Geom2dInt_ExactIntersectionPointOfTheIntPCurvePCurveOfGInter::*)() const) &Geom2dInt_ExactIntersectionPointOfTheIntPCurvePCurveOfGInter::AnErrorOccurred, "None");

// CLASS: GEOM2DINT_GEOM2DCURVETOOL
py::class_<Geom2dInt_Geom2dCurveTool> cls_Geom2dInt_Geom2dCurveTool(mod, "Geom2dInt_Geom2dCurveTool", "This class provides a Geom2dCurveTool as < Geom2dCurveTool from IntCurve > from a Tool as < Geom2dCurveTool from Adaptor3d > .");

// Constructors
cls_Geom2dInt_Geom2dCurveTool.def(py::init<>());

// Methods
// cls_Geom2dInt_Geom2dCurveTool.def_static("operator new_", (void * (*)(size_t)) &Geom2dInt_Geom2dCurveTool::operator new, "None", py::arg("theSize"));
// cls_Geom2dInt_Geom2dCurveTool.def_static("operator delete_", (void (*)(void *)) &Geom2dInt_Geom2dCurveTool::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dInt_Geom2dCurveTool.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dInt_Geom2dCurveTool::operator new[], "None", py::arg("theSize"));
// cls_Geom2dInt_Geom2dCurveTool.def_static("operator delete[]_", (void (*)(void *)) &Geom2dInt_Geom2dCurveTool::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dInt_Geom2dCurveTool.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dInt_Geom2dCurveTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dInt_Geom2dCurveTool.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dInt_Geom2dCurveTool::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dInt_Geom2dCurveTool.def_static("GetType_", (GeomAbs_CurveType (*)(const Adaptor2d_Curve2d &)) &Geom2dInt_Geom2dCurveTool::GetType, "None", py::arg("C"));
// cls_Geom2dInt_Geom2dCurveTool.def_static("IsComposite_", (Standard_Boolean (*)(const Adaptor2d_Curve2d &)) &Geom2dInt_Geom2dCurveTool::IsComposite, "None", py::arg("C"));
cls_Geom2dInt_Geom2dCurveTool.def_static("Line_", (gp_Lin2d (*)(const Adaptor2d_Curve2d &)) &Geom2dInt_Geom2dCurveTool::Line, "Returns the Lin2d from gp corresponding to the curve C. This method is called only when TheType returns GeomAbs_Line.", py::arg("C"));
cls_Geom2dInt_Geom2dCurveTool.def_static("Circle_", (gp_Circ2d (*)(const Adaptor2d_Curve2d &)) &Geom2dInt_Geom2dCurveTool::Circle, "Returns the Circ2d from gp corresponding to the curve C. This method is called only when TheType returns GeomAbs_Circle.", py::arg("C"));
cls_Geom2dInt_Geom2dCurveTool.def_static("Ellipse_", (gp_Elips2d (*)(const Adaptor2d_Curve2d &)) &Geom2dInt_Geom2dCurveTool::Ellipse, "Returns the Elips2d from gp corresponding to the curve C. This method is called only when TheType returns GeomAbs_Ellipse.", py::arg("C"));
cls_Geom2dInt_Geom2dCurveTool.def_static("Parabola_", (gp_Parab2d (*)(const Adaptor2d_Curve2d &)) &Geom2dInt_Geom2dCurveTool::Parabola, "Returns the Parab2d from gp corresponding to the curve C. This method is called only when TheType returns GeomAbs_Parabola.", py::arg("C"));
cls_Geom2dInt_Geom2dCurveTool.def_static("Hyperbola_", (gp_Hypr2d (*)(const Adaptor2d_Curve2d &)) &Geom2dInt_Geom2dCurveTool::Hyperbola, "Returns the Hypr2d from gp corresponding to the curve C. This method is called only when TheType returns GeomAbs_Hyperbola.", py::arg("C"));
cls_Geom2dInt_Geom2dCurveTool.def_static("EpsX_", (Standard_Real (*)(const Adaptor2d_Curve2d &)) &Geom2dInt_Geom2dCurveTool::EpsX, "None", py::arg("C"));
cls_Geom2dInt_Geom2dCurveTool.def_static("EpsX_", (Standard_Real (*)(const Adaptor2d_Curve2d &, const Standard_Real)) &Geom2dInt_Geom2dCurveTool::EpsX, "None", py::arg("C"), py::arg("Eps_XYZ"));
cls_Geom2dInt_Geom2dCurveTool.def_static("NbSamples_", (Standard_Integer (*)(const Adaptor2d_Curve2d &)) &Geom2dInt_Geom2dCurveTool::NbSamples, "None", py::arg("C"));
cls_Geom2dInt_Geom2dCurveTool.def_static("NbSamples_", (Standard_Integer (*)(const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real)) &Geom2dInt_Geom2dCurveTool::NbSamples, "None", py::arg("C"), py::arg("U0"), py::arg("U1"));
cls_Geom2dInt_Geom2dCurveTool.def_static("FirstParameter_", (Standard_Real (*)(const Adaptor2d_Curve2d &)) &Geom2dInt_Geom2dCurveTool::FirstParameter, "None", py::arg("C"));
cls_Geom2dInt_Geom2dCurveTool.def_static("LastParameter_", (Standard_Real (*)(const Adaptor2d_Curve2d &)) &Geom2dInt_Geom2dCurveTool::LastParameter, "None", py::arg("C"));
cls_Geom2dInt_Geom2dCurveTool.def_static("Value_", (gp_Pnt2d (*)(const Adaptor2d_Curve2d &, const Standard_Real)) &Geom2dInt_Geom2dCurveTool::Value, "None", py::arg("C"), py::arg("X"));
cls_Geom2dInt_Geom2dCurveTool.def_static("D0_", (void (*)(const Adaptor2d_Curve2d &, const Standard_Real, gp_Pnt2d &)) &Geom2dInt_Geom2dCurveTool::D0, "None", py::arg("C"), py::arg("U"), py::arg("P"));
cls_Geom2dInt_Geom2dCurveTool.def_static("D1_", (void (*)(const Adaptor2d_Curve2d &, const Standard_Real, gp_Pnt2d &, gp_Vec2d &)) &Geom2dInt_Geom2dCurveTool::D1, "None", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("T"));
cls_Geom2dInt_Geom2dCurveTool.def_static("D2_", (void (*)(const Adaptor2d_Curve2d &, const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &)) &Geom2dInt_Geom2dCurveTool::D2, "None", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("T"), py::arg("N"));
cls_Geom2dInt_Geom2dCurveTool.def_static("D3_", (void (*)(const Adaptor2d_Curve2d &, const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &, gp_Vec2d &)) &Geom2dInt_Geom2dCurveTool::D3, "None", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("T"), py::arg("N"), py::arg("V"));
cls_Geom2dInt_Geom2dCurveTool.def_static("DN_", (gp_Vec2d (*)(const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Integer)) &Geom2dInt_Geom2dCurveTool::DN, "None", py::arg("C"), py::arg("U"), py::arg("N"));
cls_Geom2dInt_Geom2dCurveTool.def_static("NbIntervals_", (Standard_Integer (*)(const Adaptor2d_Curve2d &)) &Geom2dInt_Geom2dCurveTool::NbIntervals, "output the number of interval of continuity C2 of the curve", py::arg("C"));
cls_Geom2dInt_Geom2dCurveTool.def_static("Intervals_", (void (*)(const Adaptor2d_Curve2d &, TColStd_Array1OfReal &)) &Geom2dInt_Geom2dCurveTool::Intervals, "compute Tab.", py::arg("C"), py::arg("Tab"));
cls_Geom2dInt_Geom2dCurveTool.def_static("GetInterval_", [](const Adaptor2d_Curve2d & C, const Standard_Integer Index, const TColStd_Array1OfReal & Tab, Standard_Real & U1, Standard_Real & U2){ Geom2dInt_Geom2dCurveTool::GetInterval(C, Index, Tab, U1, U2); return std::tuple<Standard_Real &, Standard_Real &>(U1, U2); }, "output the bounds of interval of index <Index> used if Type == Composite.", py::arg("C"), py::arg("Index"), py::arg("Tab"), py::arg("U1"), py::arg("U2"));
cls_Geom2dInt_Geom2dCurveTool.def_static("Degree_", (Standard_Integer (*)(const Adaptor2d_Curve2d &)) &Geom2dInt_Geom2dCurveTool::Degree, "None", py::arg("C"));

// CLASS: GEOM2DINT_MYIMPPARTOOLOFTHEINTERSECTOROFTHEINTCONICCURVEOFGINTER
py::class_<Geom2dInt_MyImpParToolOfTheIntersectorOfTheIntConicCurveOfGInter, math_FunctionWithDerivative> cls_Geom2dInt_MyImpParToolOfTheIntersectorOfTheIntConicCurveOfGInter(mod, "Geom2dInt_MyImpParToolOfTheIntersectorOfTheIntConicCurveOfGInter", "None");

// Constructors
cls_Geom2dInt_MyImpParToolOfTheIntersectorOfTheIntConicCurveOfGInter.def(py::init<const IntCurve_IConicTool &, const Adaptor2d_Curve2d &>(), py::arg("IT"), py::arg("PC"));

// Methods
// cls_Geom2dInt_MyImpParToolOfTheIntersectorOfTheIntConicCurveOfGInter.def_static("operator new_", (void * (*)(size_t)) &Geom2dInt_MyImpParToolOfTheIntersectorOfTheIntConicCurveOfGInter::operator new, "None", py::arg("theSize"));
// cls_Geom2dInt_MyImpParToolOfTheIntersectorOfTheIntConicCurveOfGInter.def_static("operator delete_", (void (*)(void *)) &Geom2dInt_MyImpParToolOfTheIntersectorOfTheIntConicCurveOfGInter::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dInt_MyImpParToolOfTheIntersectorOfTheIntConicCurveOfGInter.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dInt_MyImpParToolOfTheIntersectorOfTheIntConicCurveOfGInter::operator new[], "None", py::arg("theSize"));
// cls_Geom2dInt_MyImpParToolOfTheIntersectorOfTheIntConicCurveOfGInter.def_static("operator delete[]_", (void (*)(void *)) &Geom2dInt_MyImpParToolOfTheIntersectorOfTheIntConicCurveOfGInter::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dInt_MyImpParToolOfTheIntersectorOfTheIntConicCurveOfGInter.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dInt_MyImpParToolOfTheIntersectorOfTheIntConicCurveOfGInter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dInt_MyImpParToolOfTheIntersectorOfTheIntConicCurveOfGInter.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dInt_MyImpParToolOfTheIntersectorOfTheIntConicCurveOfGInter::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dInt_MyImpParToolOfTheIntersectorOfTheIntConicCurveOfGInter.def("Value", [](Geom2dInt_MyImpParToolOfTheIntersectorOfTheIntConicCurveOfGInter &self, const Standard_Real Param, Standard_Real & F){ Standard_Boolean rv = self.Value(Param, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "Computes the value of the signed distance between the implicit curve and the point at parameter Param on the parametrised curve.", py::arg("Param"), py::arg("F"));
cls_Geom2dInt_MyImpParToolOfTheIntersectorOfTheIntConicCurveOfGInter.def("Derivative", [](Geom2dInt_MyImpParToolOfTheIntersectorOfTheIntConicCurveOfGInter &self, const Standard_Real Param, Standard_Real & D){ Standard_Boolean rv = self.Derivative(Param, D); return std::tuple<Standard_Boolean, Standard_Real &>(rv, D); }, "Computes the derivative of the previous function at parameter Param.", py::arg("Param"), py::arg("D"));
cls_Geom2dInt_MyImpParToolOfTheIntersectorOfTheIntConicCurveOfGInter.def("Values", [](Geom2dInt_MyImpParToolOfTheIntersectorOfTheIntConicCurveOfGInter &self, const Standard_Real Param, Standard_Real & F, Standard_Real & D){ Standard_Boolean rv = self.Values(Param, F, D); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, F, D); }, "Computes the value and the derivative of the function.", py::arg("Param"), py::arg("F"), py::arg("D"));

// CLASS: GEOM2DINT_PCLOCFOFTHELOCATEEXTPCOFTHEPROJPCUROFGINTER
py::class_<Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter, math_FunctionWithDerivative> cls_Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter(mod, "Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter", "None");

// Constructors
cls_Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter.def(py::init<>());
cls_Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter.def(py::init<const gp_Pnt2d &, const Adaptor2d_Curve2d &>(), py::arg("P"), py::arg("C"));

// Methods
// cls_Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter.def_static("operator new_", (void * (*)(size_t)) &Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter::operator new, "None", py::arg("theSize"));
// cls_Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter.def_static("operator delete_", (void (*)(void *)) &Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter::operator new[], "None", py::arg("theSize"));
// cls_Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter.def_static("operator delete[]_", (void (*)(void *)) &Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter.def("Initialize", (void (Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter::*)(const Adaptor2d_Curve2d &)) &Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter::Initialize, "sets the field mycurve of the function.", py::arg("C"));
cls_Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter.def("SetPoint", (void (Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter::*)(const gp_Pnt2d &)) &Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter::SetPoint, "sets the field P of the function.", py::arg("P"));
cls_Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter.def("Value", [](Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter &self, const Standard_Real U, Standard_Real & F){ Standard_Boolean rv = self.Value(U, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "Calculation of F(U).", py::arg("U"), py::arg("F"));
cls_Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter.def("Derivative", [](Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter &self, const Standard_Real U, Standard_Real & DF){ Standard_Boolean rv = self.Derivative(U, DF); return std::tuple<Standard_Boolean, Standard_Real &>(rv, DF); }, "Calculation of F'(U).", py::arg("U"), py::arg("DF"));
cls_Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter.def("Values", [](Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter &self, const Standard_Real U, Standard_Real & F, Standard_Real & DF){ Standard_Boolean rv = self.Values(U, F, DF); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, F, DF); }, "Calculation of F(U) and F'(U).", py::arg("U"), py::arg("F"), py::arg("DF"));
cls_Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter.def("GetStateNumber", (Standard_Integer (Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter::*)()) &Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter::GetStateNumber, "Save the found extremum.");
cls_Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter.def("NbExt", (Standard_Integer (Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter::*)() const) &Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter::NbExt, "Return the nunber of found extrema.");
cls_Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter.def("SquareDistance", (Standard_Real (Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter::*)(const Standard_Integer) const) &Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter::SquareDistance, "Returns the Nth distance.", py::arg("N"));
cls_Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter.def("IsMin", (Standard_Boolean (Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter::*)(const Standard_Integer) const) &Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter::IsMin, "Shows if the Nth distance is a minimum.", py::arg("N"));
cls_Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter.def("Point", (const Extrema_POnCurv2d & (Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter::*)(const Standard_Integer) const) &Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter::Point, "Returns the Nth extremum.", py::arg("N"));
cls_Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter.def("SubIntervalInitialize", (void (Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter::*)(const Standard_Real, const Standard_Real)) &Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter::SubIntervalInitialize, "Determines boundaries of subinterval for find of root.", py::arg("theUfirst"), py::arg("theUlast"));
cls_Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter.def("SearchOfTolerance", (Standard_Real (Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter::*)()) &Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter::SearchOfTolerance, "Computes a Tol value. If 1st derivative of curve |D1|<Tol, it is considered D1=0.");

// CLASS: GEOM2DINT_THECURVELOCATOROFTHEPROJPCUROFGINTER
py::class_<Geom2dInt_TheCurveLocatorOfTheProjPCurOfGInter> cls_Geom2dInt_TheCurveLocatorOfTheProjPCurOfGInter(mod, "Geom2dInt_TheCurveLocatorOfTheProjPCurOfGInter", "None");

// Constructors
cls_Geom2dInt_TheCurveLocatorOfTheProjPCurOfGInter.def(py::init<>());

// Methods
// cls_Geom2dInt_TheCurveLocatorOfTheProjPCurOfGInter.def_static("operator new_", (void * (*)(size_t)) &Geom2dInt_TheCurveLocatorOfTheProjPCurOfGInter::operator new, "None", py::arg("theSize"));
// cls_Geom2dInt_TheCurveLocatorOfTheProjPCurOfGInter.def_static("operator delete_", (void (*)(void *)) &Geom2dInt_TheCurveLocatorOfTheProjPCurOfGInter::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dInt_TheCurveLocatorOfTheProjPCurOfGInter.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dInt_TheCurveLocatorOfTheProjPCurOfGInter::operator new[], "None", py::arg("theSize"));
// cls_Geom2dInt_TheCurveLocatorOfTheProjPCurOfGInter.def_static("operator delete[]_", (void (*)(void *)) &Geom2dInt_TheCurveLocatorOfTheProjPCurOfGInter::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dInt_TheCurveLocatorOfTheProjPCurOfGInter.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dInt_TheCurveLocatorOfTheProjPCurOfGInter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dInt_TheCurveLocatorOfTheProjPCurOfGInter.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dInt_TheCurveLocatorOfTheProjPCurOfGInter::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dInt_TheCurveLocatorOfTheProjPCurOfGInter.def_static("Locate_", (void (*)(const gp_Pnt2d &, const Adaptor2d_Curve2d &, const Standard_Integer, Extrema_POnCurv2d &)) &Geom2dInt_TheCurveLocatorOfTheProjPCurOfGInter::Locate, "Among a set of points {C(ui),i=1,NbU}, locate the point P=C(uj) such that: distance(P,C) = Min{distance(P,C(ui))}", py::arg("P"), py::arg("C"), py::arg("NbU"), py::arg("Papp"));
cls_Geom2dInt_TheCurveLocatorOfTheProjPCurOfGInter.def_static("Locate_", (void (*)(const gp_Pnt2d &, const Adaptor2d_Curve2d &, const Standard_Integer, const Standard_Real, const Standard_Real, Extrema_POnCurv2d &)) &Geom2dInt_TheCurveLocatorOfTheProjPCurOfGInter::Locate, "Among a set of points {C(ui),i=1,NbU}, locate the point P=C(uj) such that: distance(P,C) = Min{distance(P,C(ui))} The research is done between umin and usup.", py::arg("P"), py::arg("C"), py::arg("NbU"), py::arg("Umin"), py::arg("Usup"), py::arg("Papp"));
// cls_Geom2dInt_TheCurveLocatorOfTheProjPCurOfGInter.def_static("Locate_", (void (*)(const Adaptor2d_Curve2d &, const Adaptor2d_Curve2d &, const Standard_Integer, const Standard_Integer, Extrema_POnCurv2d &, Extrema_POnCurv2d &)) &Geom2dInt_TheCurveLocatorOfTheProjPCurOfGInter::Locate, "Among two sets of points {C1(ui),i=1,NbU} and {C2(vj),j=1,NbV}, locate the two points P1=C1(uk) and P2=C2(vl) such that: distance(P1,P2) = Min {distance(C1(ui),C2(vj))}.", py::arg("C1"), py::arg("C2"), py::arg("NbU"), py::arg("NbV"), py::arg("Papp1"), py::arg("Papp2"));

// CLASS: GEOM2DINT_THELOCATEEXTPCOFTHEPROJPCUROFGINTER
py::class_<Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter> cls_Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter(mod, "Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter", "None");

// Constructors
cls_Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter.def(py::init<>());
cls_Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter.def(py::init<const gp_Pnt2d &, const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("C"), py::arg("U0"), py::arg("TolU"));
cls_Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter.def(py::init<const gp_Pnt2d &, const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("C"), py::arg("U0"), py::arg("Umin"), py::arg("Usup"), py::arg("TolU"));

// Methods
// cls_Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter.def_static("operator new_", (void * (*)(size_t)) &Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter::operator new, "None", py::arg("theSize"));
// cls_Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter.def_static("operator delete_", (void (*)(void *)) &Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter::operator new[], "None", py::arg("theSize"));
// cls_Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter.def_static("operator delete[]_", (void (*)(void *)) &Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter.def("Initialize", (void (Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter::*)(const Adaptor2d_Curve2d &, const Standard_Real, const Standard_Real, const Standard_Real)) &Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter::Initialize, "sets the fields of the algorithm.", py::arg("C"), py::arg("Umin"), py::arg("Usup"), py::arg("TolU"));
cls_Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter.def("Perform", (void (Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter::*)(const gp_Pnt2d &, const Standard_Real)) &Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter::Perform, "the algorithm is done with the point P. An exception is raised if the fields have not been initialized.", py::arg("P"), py::arg("U0"));
cls_Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter.def("IsDone", (Standard_Boolean (Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter::*)() const) &Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter::IsDone, "Returns True if the distance is found.");
cls_Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter.def("SquareDistance", (Standard_Real (Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter::*)() const) &Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter::SquareDistance, "Returns the value of the extremum square distance.");
cls_Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter.def("IsMin", (Standard_Boolean (Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter::*)() const) &Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter::IsMin, "Returns True if the extremum distance is a minimum.");
cls_Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter.def("Point", (const Extrema_POnCurv2d & (Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter::*)() const) &Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter::Point, "Returns the point of the extremum distance.");

// CLASS: GEOM2DINT_THEPOLYGON2DOFTHEINTPCURVEPCURVEOFGINTER
py::class_<Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter, Intf_Polygon2d> cls_Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter(mod, "Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter", "None");

// Constructors
cls_Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter.def(py::init<const Adaptor2d_Curve2d &, const Standard_Integer, const IntRes2d_Domain &, const Standard_Real>(), py::arg("Curve"), py::arg("NbPnt"), py::arg("Domain"), py::arg("Tol"));

// Methods
// cls_Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter.def_static("operator new_", (void * (*)(size_t)) &Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter::operator new, "None", py::arg("theSize"));
// cls_Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter.def_static("operator delete_", (void (*)(void *)) &Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter::operator new[], "None", py::arg("theSize"));
// cls_Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter.def_static("operator delete[]_", (void (*)(void *)) &Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter.def("ComputeWithBox", (void (Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter::*)(const Adaptor2d_Curve2d &, const Bnd_Box2d &)) &Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter::ComputeWithBox, "The current polygon is modified if most of the points of the polygon are are outside the box <OtherBox>. In this situation, bounds are computed to build a polygon inside or near the OtherBox.", py::arg("Curve"), py::arg("OtherBox"));
cls_Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter.def("DeflectionOverEstimation", (Standard_Real (Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter::*)() const) &Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter::DeflectionOverEstimation, "None");
cls_Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter.def("SetDeflectionOverEstimation", (void (Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter::*)(const Standard_Real)) &Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter::SetDeflectionOverEstimation, "None", py::arg("x"));
cls_Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter.def("Closed", (void (Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter::*)(const Standard_Boolean)) &Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter::Closed, "None", py::arg("clos"));
cls_Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter.def("Closed", (Standard_Boolean (Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter::*)() const) &Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter::Closed, "Returns True if the polyline is closed.");
cls_Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter.def("NbSegments", (Standard_Integer (Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter::*)() const) &Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter::NbSegments, "Give the number of Segments in the polyline.");
cls_Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter.def("Segment", (void (Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter::*)(const Standard_Integer, gp_Pnt2d &, gp_Pnt2d &) const) &Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter::Segment, "Returns the points of the segment <Index> in the Polygon.", py::arg("theIndex"), py::arg("theBegin"), py::arg("theEnd"));
cls_Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter.def("InfParameter", (Standard_Real (Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter::*)() const) &Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter::InfParameter, "Returns the parameter (On the curve) of the first point of the Polygon");
cls_Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter.def("SupParameter", (Standard_Real (Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter::*)() const) &Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter::SupParameter, "Returns the parameter (On the curve) of the last point of the Polygon");
cls_Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter.def("AutoIntersectionIsPossible", (Standard_Boolean (Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter::*)() const) &Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter::AutoIntersectionIsPossible, "None");
cls_Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter.def("ApproxParamOnCurve", (Standard_Real (Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter::*)(const Standard_Integer, const Standard_Real) const) &Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter::ApproxParamOnCurve, "Give an approximation of the parameter on the curve according to the discretization of the Curve.", py::arg("Index"), py::arg("ParamOnLine"));
cls_Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter.def("CalculRegion", (Standard_Integer (Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real) const) &Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter::CalculRegion, "None", py::arg("x"), py::arg("y"), py::arg("x1"), py::arg("x2"), py::arg("y1"), py::arg("y2"));
cls_Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter.def("Dump", (void (Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter::*)() const) &Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter::Dump, "None");

// CLASS: GEOM2DINT_THEPROJPCUROFGINTER
py::class_<Geom2dInt_TheProjPCurOfGInter> cls_Geom2dInt_TheProjPCurOfGInter(mod, "Geom2dInt_TheProjPCurOfGInter", "None");

// Constructors
cls_Geom2dInt_TheProjPCurOfGInter.def(py::init<>());

// Methods
// cls_Geom2dInt_TheProjPCurOfGInter.def_static("operator new_", (void * (*)(size_t)) &Geom2dInt_TheProjPCurOfGInter::operator new, "None", py::arg("theSize"));
// cls_Geom2dInt_TheProjPCurOfGInter.def_static("operator delete_", (void (*)(void *)) &Geom2dInt_TheProjPCurOfGInter::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dInt_TheProjPCurOfGInter.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dInt_TheProjPCurOfGInter::operator new[], "None", py::arg("theSize"));
// cls_Geom2dInt_TheProjPCurOfGInter.def_static("operator delete[]_", (void (*)(void *)) &Geom2dInt_TheProjPCurOfGInter::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dInt_TheProjPCurOfGInter.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dInt_TheProjPCurOfGInter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dInt_TheProjPCurOfGInter.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dInt_TheProjPCurOfGInter::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dInt_TheProjPCurOfGInter.def_static("FindParameter_", (Standard_Real (*)(const Adaptor2d_Curve2d &, const gp_Pnt2d &, const Standard_Real)) &Geom2dInt_TheProjPCurOfGInter::FindParameter, "Returns the parameter V of the point on the parametric curve corresponding to the Point Pnt. The Correspondance between Pnt and the point P(V) on the parametric curve must be coherent with the way of determination of the signed distance between a point and the implicit curve. Tol is the tolerance on the distance between a point and the parametrised curve. In that case, no bounds are given. The research of the rigth parameter has to be made on the natural parametric domain of the curve.", py::arg("C"), py::arg("Pnt"), py::arg("Tol"));
cls_Geom2dInt_TheProjPCurOfGInter.def_static("FindParameter_", (Standard_Real (*)(const Adaptor2d_Curve2d &, const gp_Pnt2d &, const Standard_Real, const Standard_Real, const Standard_Real)) &Geom2dInt_TheProjPCurOfGInter::FindParameter, "Returns the parameter V of the point on the parametric curve corresponding to the Point Pnt. The Correspondance between Pnt and the point P(V) on the parametric curve must be coherent with the way of determination of the signed distance between a point and the implicit curve. Tol is the tolerance on the distance between a point and the parametrised curve. LowParameter and HighParameter give the boundaries of the interval in wich the parameter certainly lies. These parameters are given to implement a more efficient algoritm. So, it is not necessary to check that the returned value verifies LowParameter <= Value <= HighParameter.", py::arg("C"), py::arg("Pnt"), py::arg("LowParameter"), py::arg("HighParameter"), py::arg("Tol"));


}
