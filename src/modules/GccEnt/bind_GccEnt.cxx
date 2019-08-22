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
#include <Standard_OStream.hxx>
#include <GccEnt_Position.hxx>
#include <Standard_TypeDef.hxx>
#include <GccEnt_QualifiedLin.hxx>
#include <gp_Lin2d.hxx>
#include <GccEnt_QualifiedCirc.hxx>
#include <gp_Circ2d.hxx>
#include <GccEnt.hxx>

void bind_GccEnt(py::module &mod){

py::class_<GccEnt> cls_GccEnt(mod, "GccEnt", "This package provides an implementation of the qualified entities useful to create 2d entities with geometric constraints. The qualifier explains which subfamily of solutions we want to obtain. It uses the following law: the matter/the interior side is at the left of the line, if we go from the beginning to the end. The qualifiers are: Enclosing : the solution(s) must enclose the argument. Enclosed : the solution(s) must be enclosed in the argument. Outside : both the solution(s) and the argument must be outside to each other. Unqualified : the position is undefined, so give all the solutions. The use of a qualifier is always required if such subfamilies exist. For example, it is not used for a point. Note: the interior of a curve is defined as the left-hand side of the curve in relation to its orientation.");

// Constructors

// Fields

// Methods
// cls_GccEnt.def_static("operator new_", (void * (*)(size_t)) &GccEnt::operator new, "None", py::arg("theSize"));
// cls_GccEnt.def_static("operator delete_", (void (*)(void *)) &GccEnt::operator delete, "None", py::arg("theAddress"));
// cls_GccEnt.def_static("operator new[]_", (void * (*)(size_t)) &GccEnt::operator new[], "None", py::arg("theSize"));
// cls_GccEnt.def_static("operator delete[]_", (void (*)(void *)) &GccEnt::operator delete[], "None", py::arg("theAddress"));
// cls_GccEnt.def_static("operator new_", (void * (*)(size_t, void *)) &GccEnt::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GccEnt.def_static("operator delete_", (void (*)(void *, void *)) &GccEnt::operator delete, "None", py::arg(""), py::arg(""));
cls_GccEnt.def_static("Print_", (Standard_OStream & (*)(const GccEnt_Position, Standard_OStream &)) &GccEnt::Print, "Prints the name of Position type as a String on the Stream.", py::arg("thePosition"), py::arg("theStream"));
cls_GccEnt.def_static("PositionToString_", (Standard_CString (*)(GccEnt_Position)) &GccEnt::PositionToString, "Returns the string name for a given position.", py::arg("thePosition"));
cls_GccEnt.def_static("PositionFromString_", (GccEnt_Position (*)(Standard_CString)) &GccEnt::PositionFromString, "Returns the position from the given string identifier (using case-insensitive comparison).", py::arg("thePositionString"));
cls_GccEnt.def_static("PositionFromString_", (Standard_Boolean (*)(Standard_CString, GccEnt_Position &)) &GccEnt::PositionFromString, "Determines the position from the given string identifier (using case-insensitive comparison).", py::arg("thePositionString"), py::arg("thePosition"));
cls_GccEnt.def_static("Unqualified_", (GccEnt_QualifiedLin (*)(const gp_Lin2d &)) &GccEnt::Unqualified, "Constructs a qualified line, so that the relative position to the circle or line of the solution computed by a construction algorithm using the qualified circle or line is not qualified, i.e. all solutions apply.", py::arg("Obj"));
cls_GccEnt.def_static("Unqualified_", (GccEnt_QualifiedCirc (*)(const gp_Circ2d &)) &GccEnt::Unqualified, "Constructs a qualified circle so that the relative position to the circle or line of the solution computed by a construction algorithm using the qualified circle or line is not qualified, i.e. all solutions apply.", py::arg("Obj"));
cls_GccEnt.def_static("Enclosing_", (GccEnt_QualifiedCirc (*)(const gp_Circ2d &)) &GccEnt::Enclosing, "Constructs such a qualified circle that the solution computed by a construction algorithm using the qualified circle encloses the circle.", py::arg("Obj"));
cls_GccEnt.def_static("Enclosed_", (GccEnt_QualifiedLin (*)(const gp_Lin2d &)) &GccEnt::Enclosed, "Constructs a qualified line, so that the solution computed by a construction algorithm using the qualified circle or line is enclosed by the circle or line.", py::arg("Obj"));
cls_GccEnt.def_static("Enclosed_", (GccEnt_QualifiedCirc (*)(const gp_Circ2d &)) &GccEnt::Enclosed, "Constructs a qualified circle so that the solution computed by a construction algorithm using the qualified circle or line is enclosed by the circle or line.", py::arg("Obj"));
cls_GccEnt.def_static("Outside_", (GccEnt_QualifiedLin (*)(const gp_Lin2d &)) &GccEnt::Outside, "Constructs a qualified line, so that the solution computed by a construction algorithm using the qualified circle or line and the circle or line are external to one another.", py::arg("Obj"));
cls_GccEnt.def_static("Outside_", (GccEnt_QualifiedCirc (*)(const gp_Circ2d &)) &GccEnt::Outside, "Constructs a qualified circle so that the solution computed by a construction algorithm using the qualified circle or line and the circle or line are external to one another.", py::arg("Obj"));

// Enums

}