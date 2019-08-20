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
#include <IntCurve_PConic.hxx>
#include <gp_Elips2d.hxx>
#include <gp_Circ2d.hxx>
#include <gp_Parab2d.hxx>
#include <gp_Hypr2d.hxx>
#include <gp_Lin2d.hxx>
#include <Standard_TypeDef.hxx>
#include <GeomAbs_CurveType.hxx>
#include <gp_Ax22d.hxx>

void bind_IntCurve_PConic(py::module &mod){

py::class_<IntCurve_PConic, std::unique_ptr<IntCurve_PConic>> cls_IntCurve_PConic(mod, "IntCurve_PConic", "This class represents a conic from gp as a parametric curve ( in order to be used by the class PConicTool from IntCurve).");

// Constructors
cls_IntCurve_PConic.def(py::init<const IntCurve_PConic &>(), py::arg("PC"));
cls_IntCurve_PConic.def(py::init<const gp_Elips2d &>(), py::arg("E"));
cls_IntCurve_PConic.def(py::init<const gp_Circ2d &>(), py::arg("C"));
cls_IntCurve_PConic.def(py::init<const gp_Parab2d &>(), py::arg("P"));
cls_IntCurve_PConic.def(py::init<const gp_Hypr2d &>(), py::arg("H"));
cls_IntCurve_PConic.def(py::init<const gp_Lin2d &>(), py::arg("L"));

// Fields

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

// Enums

}