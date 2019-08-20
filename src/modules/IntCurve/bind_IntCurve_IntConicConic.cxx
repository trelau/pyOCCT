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
#include <Standard_TypeDef.hxx>
#include <gp_Circ2d.hxx>
#include <gp_Elips2d.hxx>
#include <gp_Parab2d.hxx>
#include <gp_Hypr2d.hxx>
#include <IntCurve_IntImpConicParConic.hxx>
#include <IntCurve_IntConicConic.hxx>

void bind_IntCurve_IntConicConic(py::module &mod){

py::class_<IntCurve_IntConicConic, std::unique_ptr<IntCurve_IntConicConic>, IntRes2d_Intersection> cls_IntCurve_IntConicConic(mod, "IntCurve_IntConicConic", "Provides methods to intersect two conics. The exception ConstructionError is raised in constructors or in Perform methods when a domain (Domain from IntRes2d) is not correct, i-e when a Circle (Circ2d from gp) or an Ellipse (i-e Elips2d from gp) do not have a closed domain (use the SetEquivalentParameters method for a domain on a circle or an ellipse).");

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

// Fields

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

// Enums

}