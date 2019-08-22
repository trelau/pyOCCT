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
#include <BOPDS_Interf.hxx>
#include <Standard_TypeDef.hxx>
#include <BOPDS_VectorOfCurve.hxx>
#include <BOPDS_VectorOfPoint.hxx>

void bind_BOPDS_InterfFF(py::module &mod){

py::class_<BOPDS_InterfFF, BOPDS_Interf> cls_BOPDS_InterfFF(mod, "BOPDS_InterfFF", "None");

// Constructors
cls_BOPDS_InterfFF.def(py::init<>());

// Fields

// Methods
cls_BOPDS_InterfFF.def("Init", (void (BOPDS_InterfFF::*)(const Standard_Integer, const Standard_Integer)) &BOPDS_InterfFF::Init, "Initializer", py::arg("theNbCurves"), py::arg("theNbPoints"));
cls_BOPDS_InterfFF.def("SetTangentFaces", (void (BOPDS_InterfFF::*)(const Standard_Boolean)) &BOPDS_InterfFF::SetTangentFaces, "Modifier Sets the flag of whether the faces are tangent", py::arg("theFlag"));
cls_BOPDS_InterfFF.def("TangentFaces", (Standard_Boolean (BOPDS_InterfFF::*)() const) &BOPDS_InterfFF::TangentFaces, "Selector Returns the flag whether the faces are tangent");
cls_BOPDS_InterfFF.def("Curves", (const BOPDS_VectorOfCurve & (BOPDS_InterfFF::*)() const) &BOPDS_InterfFF::Curves, "Selector Returns the intersection curves");
cls_BOPDS_InterfFF.def("ChangeCurves", (BOPDS_VectorOfCurve & (BOPDS_InterfFF::*)()) &BOPDS_InterfFF::ChangeCurves, "Selector/Modifier Returns the intersection curves");
cls_BOPDS_InterfFF.def("Points", (const BOPDS_VectorOfPoint & (BOPDS_InterfFF::*)() const) &BOPDS_InterfFF::Points, "Selector Returns the intersection points");
cls_BOPDS_InterfFF.def("ChangePoints", (BOPDS_VectorOfPoint & (BOPDS_InterfFF::*)()) &BOPDS_InterfFF::ChangePoints, "Selector/Modifier Returns the intersection points");

// Enums

}