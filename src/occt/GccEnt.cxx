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
#include <GccEnt_Position.hxx>
#include <NCollection_Array1.hxx>
#include <GccEnt_Array1OfPosition.hxx>
#include <Standard.hxx>
#include <Standard_OStream.hxx>
#include <Standard_TypeDef.hxx>
#include <GccEnt_QualifiedLin.hxx>
#include <gp_Lin2d.hxx>
#include <GccEnt_QualifiedCirc.hxx>
#include <gp_Circ2d.hxx>
#include <GccEnt.hxx>
#include <Standard_DomainError.hxx>
#include <Standard_Handle.hxx>
#include <GccEnt_BadQualifier.hxx>
#include <Standard_SStream.hxx>
#include <Standard_Std.hxx>
#include <Standard_Type.hxx>
#include <bind_NCollection_Array1.hxx>

PYBIND11_MODULE(GccEnt, mod) {

py::module::import("OCCT.NCollection");
py::module::import("OCCT.Standard");
py::module::import("OCCT.gp");

// ENUM: GCCENT_POSITION
py::enum_<GccEnt_Position>(mod, "GccEnt_Position", "Qualifies the position of a solution of a construction algorithm with respect to one of its arguments. This is one of the following: - GccEnt_unqualified: the position of the solution is undefined with respect to the argument, - GccEnt_enclosing: the solution encompasses the argument, - GccEnt_enclosed: the solution is encompassed by the argument, - GccEnt_outside: the solution and the argument are external to one another, - GccEnt_noqualifier: the value returned during a consultation of the qualifier when the argument is defined as GccEnt_unqualified. Note: the interior of a line or any open curve is defined as the left-hand side of the line or curve in relation to its orientation.")
	.value("GccEnt_unqualified", GccEnt_Position::GccEnt_unqualified)
	.value("GccEnt_enclosing", GccEnt_Position::GccEnt_enclosing)
	.value("GccEnt_enclosed", GccEnt_Position::GccEnt_enclosed)
	.value("GccEnt_outside", GccEnt_Position::GccEnt_outside)
	.value("GccEnt_noqualifier", GccEnt_Position::GccEnt_noqualifier)
	.export_values();


// TYPEDEF: GCCENT_ARRAY1OFPOSITION
bind_NCollection_Array1<GccEnt_Position>(mod, "GccEnt_Array1OfPosition", py::module_local(false));

// CLASS: GCCENT
py::class_<GccEnt> cls_GccEnt(mod, "GccEnt", "This package provides an implementation of the qualified entities useful to create 2d entities with geometric constraints. The qualifier explains which subfamily of solutions we want to obtain. It uses the following law: the matter/the interior side is at the left of the line, if we go from the beginning to the end. The qualifiers are: Enclosing : the solution(s) must enclose the argument. Enclosed : the solution(s) must be enclosed in the argument. Outside : both the solution(s) and the argument must be outside to each other. Unqualified : the position is undefined, so give all the solutions. The use of a qualifier is always required if such subfamilies exist. For example, it is not used for a point. Note: the interior of a curve is defined as the left-hand side of the curve in relation to its orientation.");

// Constructors
cls_GccEnt.def(py::init<>());

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

// CLASS: GCCENT_BADQUALIFIER
py::class_<GccEnt_BadQualifier, opencascade::handle<GccEnt_BadQualifier>, Standard_DomainError> cls_GccEnt_BadQualifier(mod, "GccEnt_BadQualifier", "None");

// Constructors
cls_GccEnt_BadQualifier.def(py::init<>());
cls_GccEnt_BadQualifier.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_GccEnt_BadQualifier.def_static("Raise_", (void (*)(const Standard_CString)) &GccEnt_BadQualifier::Raise, "None", py::arg("theMessage"));
cls_GccEnt_BadQualifier.def_static("Raise_", (void (*)(Standard_SStream &)) &GccEnt_BadQualifier::Raise, "None", py::arg("theMessage"));
cls_GccEnt_BadQualifier.def_static("NewInstance_", (opencascade::handle<GccEnt_BadQualifier> (*)(const Standard_CString)) &GccEnt_BadQualifier::NewInstance, "None", py::arg("theMessage"));
cls_GccEnt_BadQualifier.def_static("get_type_name_", (const char * (*)()) &GccEnt_BadQualifier::get_type_name, "None");
cls_GccEnt_BadQualifier.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GccEnt_BadQualifier::get_type_descriptor, "None");
cls_GccEnt_BadQualifier.def("DynamicType", (const opencascade::handle<Standard_Type> & (GccEnt_BadQualifier::*)() const) &GccEnt_BadQualifier::DynamicType, "None");

// CLASS: GCCENT_QUALIFIEDCIRC
py::class_<GccEnt_QualifiedCirc> cls_GccEnt_QualifiedCirc(mod, "GccEnt_QualifiedCirc", "Creates a qualified 2d Circle. A qualified 2D circle is a circle (gp_Circ2d circle) with a qualifier which specifies whether the solution of a construction algorithm using the qualified circle (as an argument): - encloses the circle, or - is enclosed by the circle, or - is built so that both the circle and it are external to one another, or - is undefined (all solutions apply).");

// Constructors
cls_GccEnt_QualifiedCirc.def(py::init<const gp_Circ2d &, const GccEnt_Position>(), py::arg("Qualified"), py::arg("Qualifier"));

// Methods
// cls_GccEnt_QualifiedCirc.def_static("operator new_", (void * (*)(size_t)) &GccEnt_QualifiedCirc::operator new, "None", py::arg("theSize"));
// cls_GccEnt_QualifiedCirc.def_static("operator delete_", (void (*)(void *)) &GccEnt_QualifiedCirc::operator delete, "None", py::arg("theAddress"));
// cls_GccEnt_QualifiedCirc.def_static("operator new[]_", (void * (*)(size_t)) &GccEnt_QualifiedCirc::operator new[], "None", py::arg("theSize"));
// cls_GccEnt_QualifiedCirc.def_static("operator delete[]_", (void (*)(void *)) &GccEnt_QualifiedCirc::operator delete[], "None", py::arg("theAddress"));
// cls_GccEnt_QualifiedCirc.def_static("operator new_", (void * (*)(size_t, void *)) &GccEnt_QualifiedCirc::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GccEnt_QualifiedCirc.def_static("operator delete_", (void (*)(void *, void *)) &GccEnt_QualifiedCirc::operator delete, "None", py::arg(""), py::arg(""));
cls_GccEnt_QualifiedCirc.def("Qualified", (gp_Circ2d (GccEnt_QualifiedCirc::*)() const) &GccEnt_QualifiedCirc::Qualified, "Returns a 2D circle to which the qualifier is assigned.");
cls_GccEnt_QualifiedCirc.def("Qualifier", (GccEnt_Position (GccEnt_QualifiedCirc::*)() const) &GccEnt_QualifiedCirc::Qualifier, "Returns - the qualifier of this qualified circle, if it is enclosing, enclosed or outside, or - GccEnt_noqualifier if it is unqualified.");
cls_GccEnt_QualifiedCirc.def("IsUnqualified", (Standard_Boolean (GccEnt_QualifiedCirc::*)() const) &GccEnt_QualifiedCirc::IsUnqualified, "Returns true if the Circ2d is Unqualified and false in the other cases.");
cls_GccEnt_QualifiedCirc.def("IsEnclosing", (Standard_Boolean (GccEnt_QualifiedCirc::*)() const) &GccEnt_QualifiedCirc::IsEnclosing, "Returns true if the solution computed by a construction algorithm using this qualified circle encloses the circle.");
cls_GccEnt_QualifiedCirc.def("IsEnclosed", (Standard_Boolean (GccEnt_QualifiedCirc::*)() const) &GccEnt_QualifiedCirc::IsEnclosed, "Returns true if the solution computed by a construction algorithm using this qualified circle is enclosed by the circle.");
cls_GccEnt_QualifiedCirc.def("IsOutside", (Standard_Boolean (GccEnt_QualifiedCirc::*)() const) &GccEnt_QualifiedCirc::IsOutside, "Returns true if both the solution computed by a construction algorithm using this qualified circle and the circle are external to one another.");

// CLASS: GCCENT_QUALIFIEDLIN
py::class_<GccEnt_QualifiedLin> cls_GccEnt_QualifiedLin(mod, "GccEnt_QualifiedLin", "Describes a qualified 2D line. A qualified 2D line is a line (gp_Lin2d line) with a qualifier which specifies whether the solution of a construction algorithm using the qualified line (as an argument): - is 'enclosed' by the line, or - is built so that both the line and it are external to one another, or - is undefined (all solutions apply). Note: the interior of a line is defined as the left-hand side of the line in relation to its orientation (i.e. when moving from the start to the end of the curve).");

// Constructors
cls_GccEnt_QualifiedLin.def(py::init<const gp_Lin2d &, const GccEnt_Position>(), py::arg("Qualified"), py::arg("Qualifier"));

// Methods
// cls_GccEnt_QualifiedLin.def_static("operator new_", (void * (*)(size_t)) &GccEnt_QualifiedLin::operator new, "None", py::arg("theSize"));
// cls_GccEnt_QualifiedLin.def_static("operator delete_", (void (*)(void *)) &GccEnt_QualifiedLin::operator delete, "None", py::arg("theAddress"));
// cls_GccEnt_QualifiedLin.def_static("operator new[]_", (void * (*)(size_t)) &GccEnt_QualifiedLin::operator new[], "None", py::arg("theSize"));
// cls_GccEnt_QualifiedLin.def_static("operator delete[]_", (void (*)(void *)) &GccEnt_QualifiedLin::operator delete[], "None", py::arg("theAddress"));
// cls_GccEnt_QualifiedLin.def_static("operator new_", (void * (*)(size_t, void *)) &GccEnt_QualifiedLin::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GccEnt_QualifiedLin.def_static("operator delete_", (void (*)(void *, void *)) &GccEnt_QualifiedLin::operator delete, "None", py::arg(""), py::arg(""));
cls_GccEnt_QualifiedLin.def("Qualified", (gp_Lin2d (GccEnt_QualifiedLin::*)() const) &GccEnt_QualifiedLin::Qualified, "Returns a 2D line to which the qualifier is assigned.");
cls_GccEnt_QualifiedLin.def("Qualifier", (GccEnt_Position (GccEnt_QualifiedLin::*)() const) &GccEnt_QualifiedLin::Qualifier, "Returns the qualifier of this qualified line, if it is 'enclosed' or 'outside', or - GccEnt_noqualifier if it is unqualified.");
cls_GccEnt_QualifiedLin.def("IsUnqualified", (Standard_Boolean (GccEnt_QualifiedLin::*)() const) &GccEnt_QualifiedLin::IsUnqualified, "Returns true if the solution is unqualified and false in the other cases.");
cls_GccEnt_QualifiedLin.def("IsEnclosed", (Standard_Boolean (GccEnt_QualifiedLin::*)() const) &GccEnt_QualifiedLin::IsEnclosed, "Returns true if the solution is Enclosed in the Lin2d and false in the other cases.");
cls_GccEnt_QualifiedLin.def("IsOutside", (Standard_Boolean (GccEnt_QualifiedLin::*)() const) &GccEnt_QualifiedLin::IsOutside, "Returns true if the solution is Outside the Lin2d and false in the other cases.");


}
