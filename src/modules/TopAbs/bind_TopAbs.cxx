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
#include <TopAbs_Orientation.hxx>
#include <Standard_OStream.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <TopAbs_State.hxx>
#include <Standard_TypeDef.hxx>
#include <TopAbs.hxx>

void bind_TopAbs(py::module &mod){

py::class_<TopAbs, std::unique_ptr<TopAbs>> cls_TopAbs(mod, "TopAbs", "This package gives resources for Topology oriented applications such as : Topological Data Structure, Topological Algorithms.");

// Constructors

// Fields

// Methods
// cls_TopAbs.def_static("operator new_", (void * (*)(size_t)) &TopAbs::operator new, "None", py::arg("theSize"));
// cls_TopAbs.def_static("operator delete_", (void (*)(void *)) &TopAbs::operator delete, "None", py::arg("theAddress"));
// cls_TopAbs.def_static("operator new[]_", (void * (*)(size_t)) &TopAbs::operator new[], "None", py::arg("theSize"));
// cls_TopAbs.def_static("operator delete[]_", (void (*)(void *)) &TopAbs::operator delete[], "None", py::arg("theAddress"));
// cls_TopAbs.def_static("operator new_", (void * (*)(size_t, void *)) &TopAbs::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopAbs.def_static("operator delete_", (void (*)(void *, void *)) &TopAbs::operator delete, "None", py::arg(""), py::arg(""));
cls_TopAbs.def_static("Compose_", (TopAbs_Orientation (*)(const TopAbs_Orientation, const TopAbs_Orientation)) &TopAbs::Compose, "Compose the Orientation <Or1> and <Or2>. This composition is not symmetric (if you switch <Or1> and <Or2> the result is different). It assumes that <Or1> is the Orientation of a Shape S1 containing a Shape S2 of Orientation Or2. The result is the cumulated orientation of S2 in S1. The composition law is :", py::arg("Or1"), py::arg("Or2"));
cls_TopAbs.def_static("Reverse_", (TopAbs_Orientation (*)(const TopAbs_Orientation)) &TopAbs::Reverse, "xchanges the interior/exterior status of the two sides. This is what happens when the sense of direction is reversed. The following rules apply:", py::arg("Or"));
cls_TopAbs.def_static("Complement_", (TopAbs_Orientation (*)(const TopAbs_Orientation)) &TopAbs::Complement, "Reverses the interior/exterior status of each side of the object. So, to take the complement of an object means to reverse the interior/exterior status of its boundary, i.e. inside becomes outside. The method returns the complementary orientation, following the rules in the table below: FORWARD REVERSED REVERSED FORWARD INTERNAL EXTERNAL EXTERNAL INTERNAL", py::arg("Or"));
cls_TopAbs.def_static("Print_", (Standard_OStream & (*)(const TopAbs_ShapeEnum, Standard_OStream &)) &TopAbs::Print, "Prints the name of Shape type as a String on the Stream.", py::arg("theShapeType"), py::arg("theStream"));
cls_TopAbs.def_static("Print_", (Standard_OStream & (*)(const TopAbs_Orientation, Standard_OStream &)) &TopAbs::Print, "Prints the name of the Orientation as a String on the Stream.", py::arg("theOrientation"), py::arg("theStream"));
cls_TopAbs.def_static("Print_", (Standard_OStream & (*)(const TopAbs_State, Standard_OStream &)) &TopAbs::Print, "Prints the name of the State <St> as a String on the Stream <S> and returns <S>.", py::arg("St"), py::arg("S"));
cls_TopAbs.def_static("ShapeTypeToString_", (Standard_CString (*)(TopAbs_ShapeEnum)) &TopAbs::ShapeTypeToString, "Returns the string name for a given shape type.", py::arg("theType"));
cls_TopAbs.def_static("ShapeTypeFromString_", (TopAbs_ShapeEnum (*)(Standard_CString)) &TopAbs::ShapeTypeFromString, "Returns the shape type from the given string identifier (using case-insensitive comparison).", py::arg("theTypeString"));
cls_TopAbs.def_static("ShapeTypeFromString_", (Standard_Boolean (*)(Standard_CString, TopAbs_ShapeEnum &)) &TopAbs::ShapeTypeFromString, "Determines the shape type from the given string identifier (using case-insensitive comparison).", py::arg("theTypeString"), py::arg("theType"));
cls_TopAbs.def_static("ShapeOrientationToString_", (Standard_CString (*)(TopAbs_Orientation)) &TopAbs::ShapeOrientationToString, "Returns the string name for a given shape orientation.", py::arg("theOrientation"));
cls_TopAbs.def_static("ShapeOrientationFromString_", (TopAbs_Orientation (*)(const Standard_CString)) &TopAbs::ShapeOrientationFromString, "Returns the shape orientation from the given string identifier (using case-insensitive comparison).", py::arg("theOrientationString"));
cls_TopAbs.def_static("ShapeOrientationFromString_", (Standard_Boolean (*)(const Standard_CString, TopAbs_Orientation &)) &TopAbs::ShapeOrientationFromString, "Determines the shape orientation from the given string identifier (using case-insensitive comparison).", py::arg("theOrientationString"), py::arg("theOrientation"));

// Enums

}