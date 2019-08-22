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
#include <Standard_TypeDef.hxx>
#include <TopLoc_Location.hxx>
#include <TopoDS_Shape.hxx>
#include <TopAbs_Orientation.hxx>
#include <Standard_Handle.hxx>
#include <TopoDS_TShape.hxx>
#include <TopAbs_ShapeEnum.hxx>

void bind_TopoDS_Shape(py::module &mod){

py::class_<TopoDS_Shape> cls_TopoDS_Shape(mod, "TopoDS_Shape", "Describes a shape which - references an underlying shape with the potential to be given a location and an orientation - has a location for the underlying shape, giving its placement in the local coordinate system - has an orientation for the underlying shape, in terms of its geometry (as opposed to orientation in relation to other shapes). Note: A Shape is empty if it references an underlying shape which has an empty list of shapes.");

// Constructors
cls_TopoDS_Shape.def(py::init<>());

// Fields

// Methods
// cls_TopoDS_Shape.def_static("operator new_", (void * (*)(size_t)) &TopoDS_Shape::operator new, "None", py::arg("theSize"));
// cls_TopoDS_Shape.def_static("operator delete_", (void (*)(void *)) &TopoDS_Shape::operator delete, "None", py::arg("theAddress"));
// cls_TopoDS_Shape.def_static("operator new[]_", (void * (*)(size_t)) &TopoDS_Shape::operator new[], "None", py::arg("theSize"));
// cls_TopoDS_Shape.def_static("operator delete[]_", (void (*)(void *)) &TopoDS_Shape::operator delete[], "None", py::arg("theAddress"));
// cls_TopoDS_Shape.def_static("operator new_", (void * (*)(size_t, void *)) &TopoDS_Shape::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopoDS_Shape.def_static("operator delete_", (void (*)(void *, void *)) &TopoDS_Shape::operator delete, "None", py::arg(""), py::arg(""));
cls_TopoDS_Shape.def("IsNull", (Standard_Boolean (TopoDS_Shape::*)() const) &TopoDS_Shape::IsNull, "Returns true if this shape is null. In other words, it references no underlying shape with the potential to be given a location and an orientation.");
cls_TopoDS_Shape.def("Nullify", (void (TopoDS_Shape::*)()) &TopoDS_Shape::Nullify, "Destroys the reference to the underlying shape stored in this shape. As a result, this shape becomes null.");
cls_TopoDS_Shape.def("Location", (const TopLoc_Location & (TopoDS_Shape::*)() const) &TopoDS_Shape::Location, "Returns the shape local coordinate system.");
cls_TopoDS_Shape.def("Location", (void (TopoDS_Shape::*)(const TopLoc_Location &)) &TopoDS_Shape::Location, "Sets the shape local coordinate system.", py::arg("Loc"));
cls_TopoDS_Shape.def("Located", (TopoDS_Shape (TopoDS_Shape::*)(const TopLoc_Location &) const) &TopoDS_Shape::Located, "Returns a shape similar to <me> with the local coordinate system set to <Loc>.", py::arg("Loc"));
cls_TopoDS_Shape.def("Orientation", (TopAbs_Orientation (TopoDS_Shape::*)() const) &TopoDS_Shape::Orientation, "Returns the shape orientation.");
cls_TopoDS_Shape.def("Orientation", (void (TopoDS_Shape::*)(const TopAbs_Orientation)) &TopoDS_Shape::Orientation, "Sets the shape orientation.", py::arg("Orient"));
cls_TopoDS_Shape.def("Oriented", (TopoDS_Shape (TopoDS_Shape::*)(const TopAbs_Orientation) const) &TopoDS_Shape::Oriented, "Returns a shape similar to <me> with the orientation set to <Or>.", py::arg("Or"));
cls_TopoDS_Shape.def("TShape", (const opencascade::handle<TopoDS_TShape> & (TopoDS_Shape::*)() const) &TopoDS_Shape::TShape, "None");
cls_TopoDS_Shape.def("ShapeType", (TopAbs_ShapeEnum (TopoDS_Shape::*)() const) &TopoDS_Shape::ShapeType, "Returns the value of the TopAbs_ShapeEnum enumeration that corresponds to this shape, for example VERTEX, EDGE, and so on. Exceptions Standard_NullObject if this shape is null.");
cls_TopoDS_Shape.def("Free", (Standard_Boolean (TopoDS_Shape::*)() const) &TopoDS_Shape::Free, "Returns the free flag.");
cls_TopoDS_Shape.def("Free", (void (TopoDS_Shape::*)(const Standard_Boolean)) &TopoDS_Shape::Free, "Sets the free flag.", py::arg("F"));
cls_TopoDS_Shape.def("Locked", (Standard_Boolean (TopoDS_Shape::*)() const) &TopoDS_Shape::Locked, "Returns the locked flag.");
cls_TopoDS_Shape.def("Locked", (void (TopoDS_Shape::*)(const Standard_Boolean)) &TopoDS_Shape::Locked, "Sets the locked flag.", py::arg("F"));
cls_TopoDS_Shape.def("Modified", (Standard_Boolean (TopoDS_Shape::*)() const) &TopoDS_Shape::Modified, "Returns the modification flag.");
cls_TopoDS_Shape.def("Modified", (void (TopoDS_Shape::*)(const Standard_Boolean)) &TopoDS_Shape::Modified, "Sets the modification flag.", py::arg("M"));
cls_TopoDS_Shape.def("Checked", (Standard_Boolean (TopoDS_Shape::*)() const) &TopoDS_Shape::Checked, "Returns the checked flag.");
cls_TopoDS_Shape.def("Checked", (void (TopoDS_Shape::*)(const Standard_Boolean)) &TopoDS_Shape::Checked, "Sets the checked flag.", py::arg("C"));
cls_TopoDS_Shape.def("Orientable", (Standard_Boolean (TopoDS_Shape::*)() const) &TopoDS_Shape::Orientable, "Returns the orientability flag.");
cls_TopoDS_Shape.def("Orientable", (void (TopoDS_Shape::*)(const Standard_Boolean)) &TopoDS_Shape::Orientable, "Sets the orientability flag.", py::arg("C"));
cls_TopoDS_Shape.def("Closed", (Standard_Boolean (TopoDS_Shape::*)() const) &TopoDS_Shape::Closed, "Returns the closedness flag.");
cls_TopoDS_Shape.def("Closed", (void (TopoDS_Shape::*)(const Standard_Boolean)) &TopoDS_Shape::Closed, "Sets the closedness flag.", py::arg("C"));
cls_TopoDS_Shape.def("Infinite", (Standard_Boolean (TopoDS_Shape::*)() const) &TopoDS_Shape::Infinite, "Returns the infinity flag.");
cls_TopoDS_Shape.def("Infinite", (void (TopoDS_Shape::*)(const Standard_Boolean)) &TopoDS_Shape::Infinite, "Sets the infinity flag.", py::arg("C"));
cls_TopoDS_Shape.def("Convex", (Standard_Boolean (TopoDS_Shape::*)() const) &TopoDS_Shape::Convex, "Returns the convexness flag.");
cls_TopoDS_Shape.def("Convex", (void (TopoDS_Shape::*)(const Standard_Boolean)) &TopoDS_Shape::Convex, "Sets the convexness flag.", py::arg("C"));
cls_TopoDS_Shape.def("Move", (void (TopoDS_Shape::*)(const TopLoc_Location &)) &TopoDS_Shape::Move, "Multiplies the Shape location by <position>.", py::arg("position"));
cls_TopoDS_Shape.def("Moved", (TopoDS_Shape (TopoDS_Shape::*)(const TopLoc_Location &) const) &TopoDS_Shape::Moved, "Returns a shape similar to <me> with a location multiplied by <position>.", py::arg("position"));
cls_TopoDS_Shape.def("Reverse", (void (TopoDS_Shape::*)()) &TopoDS_Shape::Reverse, "Reverses the orientation, using the Reverse method from the TopAbs package.");
cls_TopoDS_Shape.def("Reversed", (TopoDS_Shape (TopoDS_Shape::*)() const) &TopoDS_Shape::Reversed, "Returns a shape similar to <me> with the orientation reversed, using the Reverse method from the TopAbs package.");
cls_TopoDS_Shape.def("Complement", (void (TopoDS_Shape::*)()) &TopoDS_Shape::Complement, "Complements the orientation, using the Complement method from the TopAbs package.");
cls_TopoDS_Shape.def("Complemented", (TopoDS_Shape (TopoDS_Shape::*)() const) &TopoDS_Shape::Complemented, "Returns a shape similar to <me> with the orientation complemented, using the Complement method from the TopAbs package.");
cls_TopoDS_Shape.def("Compose", (void (TopoDS_Shape::*)(const TopAbs_Orientation)) &TopoDS_Shape::Compose, "Updates the Shape Orientation by composition with <Orient>, using the Compose method from the TopAbs package.", py::arg("Orient"));
cls_TopoDS_Shape.def("Composed", (TopoDS_Shape (TopoDS_Shape::*)(const TopAbs_Orientation) const) &TopoDS_Shape::Composed, "Returns a shape similar to <me> with the orientation composed with <Orient>, using the Compose method from the TopAbs package.", py::arg("Orient"));
cls_TopoDS_Shape.def("IsPartner", (Standard_Boolean (TopoDS_Shape::*)(const TopoDS_Shape &) const) &TopoDS_Shape::IsPartner, "Returns True if two shapes are partners, i.e. if they share the same TShape. Locations and Orientations may differ.", py::arg("other"));
cls_TopoDS_Shape.def("IsSame", (Standard_Boolean (TopoDS_Shape::*)(const TopoDS_Shape &) const) &TopoDS_Shape::IsSame, "Returns True if two shapes are same, i.e. if they share the same TShape with the same Locations. Orientations may differ.", py::arg("other"));
cls_TopoDS_Shape.def("IsEqual", (Standard_Boolean (TopoDS_Shape::*)(const TopoDS_Shape &) const) &TopoDS_Shape::IsEqual, "Returns True if two shapes are equal, i.e. if they share the same TShape with the same Locations and Orientations.", py::arg("other"));
cls_TopoDS_Shape.def("__eq__", (Standard_Boolean (TopoDS_Shape::*)(const TopoDS_Shape &) const) &TopoDS_Shape::operator==, py::is_operator(), "None", py::arg("other"));
cls_TopoDS_Shape.def("IsNotEqual", (Standard_Boolean (TopoDS_Shape::*)(const TopoDS_Shape &) const) &TopoDS_Shape::IsNotEqual, "Negation of the IsEqual method.", py::arg("other"));
cls_TopoDS_Shape.def("__ne__", (Standard_Boolean (TopoDS_Shape::*)(const TopoDS_Shape &) const) &TopoDS_Shape::operator!=, py::is_operator(), "None", py::arg("other"));
cls_TopoDS_Shape.def("HashCode", (Standard_Integer (TopoDS_Shape::*)(const Standard_Integer) const) &TopoDS_Shape::HashCode, "Returns a hashed value denoting <me>. This value is in the range 1..<Upper>. It is computed from the TShape and the Location. The Orientation is not used.", py::arg("Upper"));
cls_TopoDS_Shape.def("EmptyCopy", (void (TopoDS_Shape::*)()) &TopoDS_Shape::EmptyCopy, "Replace <me> by a new Shape with the same Orientation and Location and a new TShape with the same geometry and no sub-shapes.");
cls_TopoDS_Shape.def("EmptyCopied", (TopoDS_Shape (TopoDS_Shape::*)() const) &TopoDS_Shape::EmptyCopied, "Returns a new Shape with the same Orientation and Location and a new TShape with the same geometry and no sub-shapes.");
cls_TopoDS_Shape.def("TShape", (void (TopoDS_Shape::*)(const opencascade::handle<TopoDS_TShape> &)) &TopoDS_Shape::TShape, "None", py::arg("T"));

// Enums

}