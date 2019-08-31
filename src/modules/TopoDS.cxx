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
#include <Standard_TypeDef.hxx>
#include <TopoDS_Shape.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <TopoDS.hxx>
#include <Standard.hxx>
#include <TopLoc_Location.hxx>
#include <TopAbs_Orientation.hxx>
#include <Standard_Handle.hxx>
#include <TopoDS_TShape.hxx>
#include <NCollection_List.hxx>
#include <TopoDS_ListOfShape.hxx>
#include <Standard_Transient.hxx>
#include <TopoDS_Iterator.hxx>
#include <TopoDS_Builder.hxx>
#include <Standard_Type.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopoDS_Wire.hxx>
#include <TopoDS_Shell.hxx>
#include <TopoDS_Solid.hxx>
#include <TopoDS_CompSolid.hxx>
#include <TopoDS_Compound.hxx>
#include <TopoDS_HShape.hxx>
#include <TopoDS_TVertex.hxx>
#include <TopoDS_TEdge.hxx>
#include <TopoDS_TWire.hxx>
#include <TopoDS_TFace.hxx>
#include <TopoDS_TShell.hxx>
#include <TopoDS_TSolid.hxx>
#include <TopoDS_TCompSolid.hxx>
#include <TopoDS_TCompound.hxx>
#include <Message_Alert.hxx>
#include <TopoDS_AlertWithShape.hxx>
#include <Standard_DomainError.hxx>
#include <TopoDS_FrozenShape.hxx>
#include <Standard_SStream.hxx>
#include <TopoDS_LockedShape.hxx>
#include <TopoDS_UnCompatibleShapes.hxx>
#include <bind_NCollection_List.hxx>
#include <bind_NCollection_TListIterator.hxx>

PYBIND11_MODULE(TopoDS, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.TopAbs");
py::module::import("OCCT.TopLoc");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.Message");

// FUNCTION: HASHCODE
mod.def("HashCode", (Standard_Integer (*) (const TopoDS_Shape &, const Standard_Integer)) &HashCode, "None", py::arg("me"), py::arg("Upper"));

// FUNCTION: TOPODS_MISMATCH
mod.def("TopoDS_Mismatch", (Standard_Boolean (*) (const TopoDS_Shape &, const TopAbs_ShapeEnum)) &TopoDS_Mismatch, "None", py::arg("S"), py::arg("T"));

// CLASS: TOPODS_SHAPE
py::class_<TopoDS_Shape> cls_TopoDS_Shape(mod, "TopoDS_Shape", "Describes a shape which - references an underlying shape with the potential to be given a location and an orientation - has a location for the underlying shape, giving its placement in the local coordinate system - has an orientation for the underlying shape, in terms of its geometry (as opposed to orientation in relation to other shapes). Note: A Shape is empty if it references an underlying shape which has an empty list of shapes.");

// Constructors
cls_TopoDS_Shape.def(py::init<>());

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

// TYPEDEF: TOPODS_LISTOFSHAPE
bind_NCollection_List<TopoDS_Shape>(mod, "TopoDS_ListOfShape", py::module_local(false));

// TYPEDEF: TOPODS_LISTITERATOROFLISTOFSHAPE
bind_NCollection_TListIterator<TopoDS_Shape>(mod, "TopoDS_ListIteratorOfListOfShape", py::module_local(false));

// CLASS: TOPODS_TSHAPE
py::class_<TopoDS_TShape, opencascade::handle<TopoDS_TShape>, Standard_Transient> cls_TopoDS_TShape(mod, "TopoDS_TShape", "A TShape is a topological structure describing a set of points in a 2D or 3D space.");

// Methods
cls_TopoDS_TShape.def("Free", (Standard_Boolean (TopoDS_TShape::*)() const) &TopoDS_TShape::Free, "Returns the free flag.");
cls_TopoDS_TShape.def("Free", (void (TopoDS_TShape::*)(const Standard_Boolean)) &TopoDS_TShape::Free, "Sets the free flag.", py::arg("F"));
cls_TopoDS_TShape.def("Locked", (Standard_Boolean (TopoDS_TShape::*)() const) &TopoDS_TShape::Locked, "Returns the locked flag.");
cls_TopoDS_TShape.def("Locked", (void (TopoDS_TShape::*)(const Standard_Boolean)) &TopoDS_TShape::Locked, "Sets the locked flag.", py::arg("F"));
cls_TopoDS_TShape.def("Modified", (Standard_Boolean (TopoDS_TShape::*)() const) &TopoDS_TShape::Modified, "Returns the modification flag.");
cls_TopoDS_TShape.def("Modified", (void (TopoDS_TShape::*)(const Standard_Boolean)) &TopoDS_TShape::Modified, "Sets the modification flag.", py::arg("M"));
cls_TopoDS_TShape.def("Checked", (Standard_Boolean (TopoDS_TShape::*)() const) &TopoDS_TShape::Checked, "Returns the checked flag.");
cls_TopoDS_TShape.def("Checked", (void (TopoDS_TShape::*)(const Standard_Boolean)) &TopoDS_TShape::Checked, "Sets the checked flag.", py::arg("C"));
cls_TopoDS_TShape.def("Orientable", (Standard_Boolean (TopoDS_TShape::*)() const) &TopoDS_TShape::Orientable, "Returns the orientability flag.");
cls_TopoDS_TShape.def("Orientable", (void (TopoDS_TShape::*)(const Standard_Boolean)) &TopoDS_TShape::Orientable, "Sets the orientability flag.", py::arg("C"));
cls_TopoDS_TShape.def("Closed", (Standard_Boolean (TopoDS_TShape::*)() const) &TopoDS_TShape::Closed, "Returns the closedness flag.");
cls_TopoDS_TShape.def("Closed", (void (TopoDS_TShape::*)(const Standard_Boolean)) &TopoDS_TShape::Closed, "Sets the closedness flag.", py::arg("C"));
cls_TopoDS_TShape.def("Infinite", (Standard_Boolean (TopoDS_TShape::*)() const) &TopoDS_TShape::Infinite, "Returns the infinity flag.");
cls_TopoDS_TShape.def("Infinite", (void (TopoDS_TShape::*)(const Standard_Boolean)) &TopoDS_TShape::Infinite, "Sets the infinity flag.", py::arg("C"));
cls_TopoDS_TShape.def("Convex", (Standard_Boolean (TopoDS_TShape::*)() const) &TopoDS_TShape::Convex, "Returns the convexness flag.");
cls_TopoDS_TShape.def("Convex", (void (TopoDS_TShape::*)(const Standard_Boolean)) &TopoDS_TShape::Convex, "Sets the convexness flag.", py::arg("C"));
cls_TopoDS_TShape.def("ShapeType", (TopAbs_ShapeEnum (TopoDS_TShape::*)() const) &TopoDS_TShape::ShapeType, "Returns the type as a term of the ShapeEnum enum : VERTEX, EDGE, WIRE, FACE, ....");
cls_TopoDS_TShape.def("EmptyCopy", (opencascade::handle<TopoDS_TShape> (TopoDS_TShape::*)() const) &TopoDS_TShape::EmptyCopy, "Returns a copy of the TShape with no sub-shapes.");
cls_TopoDS_TShape.def_static("get_type_name_", (const char * (*)()) &TopoDS_TShape::get_type_name, "None");
cls_TopoDS_TShape.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopoDS_TShape::get_type_descriptor, "None");
cls_TopoDS_TShape.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopoDS_TShape::*)() const) &TopoDS_TShape::DynamicType, "None");

// CLASS: TOPODS_EDGE
py::class_<TopoDS_Edge, TopoDS_Shape> cls_TopoDS_Edge(mod, "TopoDS_Edge", "Describes an edge which - references an underlying edge with the potential to be given a location and an orientation - has a location for the underlying edge, giving its placement in the local coordinate system - has an orientation for the underlying edge, in terms of its geometry (as opposed to orientation in relation to other shapes).");

// Constructors
cls_TopoDS_Edge.def(py::init<>());

// Methods
// cls_TopoDS_Edge.def_static("operator new_", (void * (*)(size_t)) &TopoDS_Edge::operator new, "None", py::arg("theSize"));
// cls_TopoDS_Edge.def_static("operator delete_", (void (*)(void *)) &TopoDS_Edge::operator delete, "None", py::arg("theAddress"));
// cls_TopoDS_Edge.def_static("operator new[]_", (void * (*)(size_t)) &TopoDS_Edge::operator new[], "None", py::arg("theSize"));
// cls_TopoDS_Edge.def_static("operator delete[]_", (void (*)(void *)) &TopoDS_Edge::operator delete[], "None", py::arg("theAddress"));
// cls_TopoDS_Edge.def_static("operator new_", (void * (*)(size_t, void *)) &TopoDS_Edge::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopoDS_Edge.def_static("operator delete_", (void (*)(void *, void *)) &TopoDS_Edge::operator delete, "None", py::arg(""), py::arg(""));

// CLASS: TOPODS_FACE
py::class_<TopoDS_Face, TopoDS_Shape> cls_TopoDS_Face(mod, "TopoDS_Face", "Describes a face which - references an underlying face with the potential to be given a location and an orientation - has a location for the underlying face, giving its placement in the local coordinate system - has an orientation for the underlying face, in terms of its geometry (as opposed to orientation in relation to other shapes).");

// Constructors
cls_TopoDS_Face.def(py::init<>());

// Methods
// cls_TopoDS_Face.def_static("operator new_", (void * (*)(size_t)) &TopoDS_Face::operator new, "None", py::arg("theSize"));
// cls_TopoDS_Face.def_static("operator delete_", (void (*)(void *)) &TopoDS_Face::operator delete, "None", py::arg("theAddress"));
// cls_TopoDS_Face.def_static("operator new[]_", (void * (*)(size_t)) &TopoDS_Face::operator new[], "None", py::arg("theSize"));
// cls_TopoDS_Face.def_static("operator delete[]_", (void (*)(void *)) &TopoDS_Face::operator delete[], "None", py::arg("theAddress"));
// cls_TopoDS_Face.def_static("operator new_", (void * (*)(size_t, void *)) &TopoDS_Face::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopoDS_Face.def_static("operator delete_", (void (*)(void *, void *)) &TopoDS_Face::operator delete, "None", py::arg(""), py::arg(""));

// CLASS: TOPODS
py::class_<TopoDS> cls_TopoDS(mod, "TopoDS", "Provides methods to cast objects of class TopoDS_Shape to be onjects of more specialized sub-classes. Types are verified, thus in the example below, the first two blocks are correct but the third is rejected by the compiler.");

// Methods
// cls_TopoDS.def_static("operator new_", (void * (*)(size_t)) &TopoDS::operator new, "None", py::arg("theSize"));
// cls_TopoDS.def_static("operator delete_", (void (*)(void *)) &TopoDS::operator delete, "None", py::arg("theAddress"));
// cls_TopoDS.def_static("operator new[]_", (void * (*)(size_t)) &TopoDS::operator new[], "None", py::arg("theSize"));
// cls_TopoDS.def_static("operator delete[]_", (void (*)(void *)) &TopoDS::operator delete[], "None", py::arg("theAddress"));
// cls_TopoDS.def_static("operator new_", (void * (*)(size_t, void *)) &TopoDS::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopoDS.def_static("operator delete_", (void (*)(void *, void *)) &TopoDS::operator delete, "None", py::arg(""), py::arg(""));
cls_TopoDS.def_static("Vertex_", (const TopoDS_Vertex & (*)(const TopoDS_Shape &)) &TopoDS::Vertex, "Basic tool to access the data structure. Casts shape S to the more specialized return type, Vertex. Exceptions Standard_TypeMismatch if S cannot be cast to this return type.", py::arg("S"));
cls_TopoDS.def_static("Vertex_", (TopoDS_Vertex & (*)(TopoDS_Shape &)) &TopoDS::Vertex, "None", py::arg(""));
cls_TopoDS.def_static("Edge_", (const TopoDS_Edge & (*)(const TopoDS_Shape &)) &TopoDS::Edge, "Casts shape S to the more specialized return type, Edge Exceptions Standard_TypeMismatch if S cannot be cast to this return type.", py::arg("S"));
cls_TopoDS.def_static("Edge_", (TopoDS_Edge & (*)(TopoDS_Shape &)) &TopoDS::Edge, "None", py::arg(""));
cls_TopoDS.def_static("Wire_", (const TopoDS_Wire & (*)(const TopoDS_Shape &)) &TopoDS::Wire, "Casts shape S to the more specialized return type, Wire. Exceptions Standard_TypeMismatch if S cannot be cast to this return type.", py::arg("S"));
cls_TopoDS.def_static("Wire_", (TopoDS_Wire & (*)(TopoDS_Shape &)) &TopoDS::Wire, "None", py::arg(""));
cls_TopoDS.def_static("Face_", (const TopoDS_Face & (*)(const TopoDS_Shape &)) &TopoDS::Face, "Casts shape S to the more specialized return type, Face. Exceptions Standard_TypeMismatch if S cannot be cast to this return type.", py::arg("S"));
cls_TopoDS.def_static("Face_", (TopoDS_Face & (*)(TopoDS_Shape &)) &TopoDS::Face, "None", py::arg(""));
cls_TopoDS.def_static("Shell_", (const TopoDS_Shell & (*)(const TopoDS_Shape &)) &TopoDS::Shell, "Casts shape S to the more specialized return type, Shell. Exceptions Standard_TypeMismatch if S cannot be cast to this return type.", py::arg("S"));
cls_TopoDS.def_static("Shell_", (TopoDS_Shell & (*)(TopoDS_Shape &)) &TopoDS::Shell, "None", py::arg(""));
cls_TopoDS.def_static("Solid_", (const TopoDS_Solid & (*)(const TopoDS_Shape &)) &TopoDS::Solid, "Casts shape S to the more specialized return type, Solid. Exceptions Standard_TypeMismatch if S cannot be cast to this return type.", py::arg("S"));
cls_TopoDS.def_static("Solid_", (TopoDS_Solid & (*)(TopoDS_Shape &)) &TopoDS::Solid, "None", py::arg(""));
cls_TopoDS.def_static("CompSolid_", (const TopoDS_CompSolid & (*)(const TopoDS_Shape &)) &TopoDS::CompSolid, "Casts shape S to the more specialized return type, CompSolid. Exceptions Standard_TypeMismatch if S cannot be cast to this return type.", py::arg("S"));
cls_TopoDS.def_static("CompSolid_", (TopoDS_CompSolid & (*)(TopoDS_Shape &)) &TopoDS::CompSolid, "None", py::arg(""));
cls_TopoDS.def_static("Compound_", (const TopoDS_Compound & (*)(const TopoDS_Shape &)) &TopoDS::Compound, "Casts shape S to the more specialized return type, Compound. Exceptions Standard_TypeMismatch if S cannot be cast to this return type.", py::arg("S"));
cls_TopoDS.def_static("Compound_", (TopoDS_Compound & (*)(TopoDS_Shape &)) &TopoDS::Compound, "None", py::arg(""));

// CLASS: TOPODS_VERTEX
py::class_<TopoDS_Vertex, TopoDS_Shape> cls_TopoDS_Vertex(mod, "TopoDS_Vertex", "Describes a vertex which - references an underlying vertex with the potential to be given a location and an orientation - has a location for the underlying vertex, giving its placement in the local coordinate system - has an orientation for the underlying vertex, in terms of its geometry (as opposed to orientation in relation to other shapes).");

// Constructors
cls_TopoDS_Vertex.def(py::init<>());

// Methods
// cls_TopoDS_Vertex.def_static("operator new_", (void * (*)(size_t)) &TopoDS_Vertex::operator new, "None", py::arg("theSize"));
// cls_TopoDS_Vertex.def_static("operator delete_", (void (*)(void *)) &TopoDS_Vertex::operator delete, "None", py::arg("theAddress"));
// cls_TopoDS_Vertex.def_static("operator new[]_", (void * (*)(size_t)) &TopoDS_Vertex::operator new[], "None", py::arg("theSize"));
// cls_TopoDS_Vertex.def_static("operator delete[]_", (void (*)(void *)) &TopoDS_Vertex::operator delete[], "None", py::arg("theAddress"));
// cls_TopoDS_Vertex.def_static("operator new_", (void * (*)(size_t, void *)) &TopoDS_Vertex::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopoDS_Vertex.def_static("operator delete_", (void (*)(void *, void *)) &TopoDS_Vertex::operator delete, "None", py::arg(""), py::arg(""));

// CLASS: TOPODS_COMPOUND
py::class_<TopoDS_Compound, TopoDS_Shape> cls_TopoDS_Compound(mod, "TopoDS_Compound", "Describes a compound which - references an underlying compound with the potential to be given a location and an orientation - has a location for the underlying compound, giving its placement in the local coordinate system - has an orientation for the underlying compound, in terms of its geometry (as opposed to orientation in relation to other shapes). Casts shape S to the more specialized return type, Compound.");

// Constructors
cls_TopoDS_Compound.def(py::init<>());

// Methods
// cls_TopoDS_Compound.def_static("operator new_", (void * (*)(size_t)) &TopoDS_Compound::operator new, "None", py::arg("theSize"));
// cls_TopoDS_Compound.def_static("operator delete_", (void (*)(void *)) &TopoDS_Compound::operator delete, "None", py::arg("theAddress"));
// cls_TopoDS_Compound.def_static("operator new[]_", (void * (*)(size_t)) &TopoDS_Compound::operator new[], "None", py::arg("theSize"));
// cls_TopoDS_Compound.def_static("operator delete[]_", (void (*)(void *)) &TopoDS_Compound::operator delete[], "None", py::arg("theAddress"));
// cls_TopoDS_Compound.def_static("operator new_", (void * (*)(size_t, void *)) &TopoDS_Compound::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopoDS_Compound.def_static("operator delete_", (void (*)(void *, void *)) &TopoDS_Compound::operator delete, "None", py::arg(""), py::arg(""));

// CLASS: TOPODS_WIRE
py::class_<TopoDS_Wire, TopoDS_Shape> cls_TopoDS_Wire(mod, "TopoDS_Wire", "Describes a wire which - references an underlying wire with the potential to be given a location and an orientation - has a location for the underlying wire, giving its placement in the local coordinate system - has an orientation for the underlying wire, in terms of its geometry (as opposed to orientation in relation to other shapes).");

// Constructors
cls_TopoDS_Wire.def(py::init<>());

// Methods
// cls_TopoDS_Wire.def_static("operator new_", (void * (*)(size_t)) &TopoDS_Wire::operator new, "None", py::arg("theSize"));
// cls_TopoDS_Wire.def_static("operator delete_", (void (*)(void *)) &TopoDS_Wire::operator delete, "None", py::arg("theAddress"));
// cls_TopoDS_Wire.def_static("operator new[]_", (void * (*)(size_t)) &TopoDS_Wire::operator new[], "None", py::arg("theSize"));
// cls_TopoDS_Wire.def_static("operator delete[]_", (void (*)(void *)) &TopoDS_Wire::operator delete[], "None", py::arg("theAddress"));
// cls_TopoDS_Wire.def_static("operator new_", (void * (*)(size_t, void *)) &TopoDS_Wire::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopoDS_Wire.def_static("operator delete_", (void (*)(void *, void *)) &TopoDS_Wire::operator delete, "None", py::arg(""), py::arg(""));

// CLASS: TOPODS_BUILDER
py::class_<TopoDS_Builder> cls_TopoDS_Builder(mod, "TopoDS_Builder", "A Builder is used to create Topological Data Structures.It is the root of the Builder class hierarchy.");

// Methods
// cls_TopoDS_Builder.def_static("operator new_", (void * (*)(size_t)) &TopoDS_Builder::operator new, "None", py::arg("theSize"));
// cls_TopoDS_Builder.def_static("operator delete_", (void (*)(void *)) &TopoDS_Builder::operator delete, "None", py::arg("theAddress"));
// cls_TopoDS_Builder.def_static("operator new[]_", (void * (*)(size_t)) &TopoDS_Builder::operator new[], "None", py::arg("theSize"));
// cls_TopoDS_Builder.def_static("operator delete[]_", (void (*)(void *)) &TopoDS_Builder::operator delete[], "None", py::arg("theAddress"));
// cls_TopoDS_Builder.def_static("operator new_", (void * (*)(size_t, void *)) &TopoDS_Builder::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopoDS_Builder.def_static("operator delete_", (void (*)(void *, void *)) &TopoDS_Builder::operator delete, "None", py::arg(""), py::arg(""));
cls_TopoDS_Builder.def("MakeWire", (void (TopoDS_Builder::*)(TopoDS_Wire &) const) &TopoDS_Builder::MakeWire, "Make an empty Wire.", py::arg("W"));
cls_TopoDS_Builder.def("MakeShell", (void (TopoDS_Builder::*)(TopoDS_Shell &) const) &TopoDS_Builder::MakeShell, "Make an empty Shell.", py::arg("S"));
cls_TopoDS_Builder.def("MakeSolid", (void (TopoDS_Builder::*)(TopoDS_Solid &) const) &TopoDS_Builder::MakeSolid, "Make a Solid covering the whole 3D space.", py::arg("S"));
cls_TopoDS_Builder.def("MakeCompSolid", (void (TopoDS_Builder::*)(TopoDS_CompSolid &) const) &TopoDS_Builder::MakeCompSolid, "Make an empty Composite Solid.", py::arg("C"));
cls_TopoDS_Builder.def("MakeCompound", (void (TopoDS_Builder::*)(TopoDS_Compound &) const) &TopoDS_Builder::MakeCompound, "Make an empty Compound.", py::arg("C"));
cls_TopoDS_Builder.def("Add", (void (TopoDS_Builder::*)(TopoDS_Shape &, const TopoDS_Shape &) const) &TopoDS_Builder::Add, "Add the Shape C in the Shape S. Exceptions - TopoDS_FrozenShape if S is not free and cannot be modified. - TopoDS__UnCompatibleShapes if S and C are not compatible.", py::arg("S"), py::arg("C"));
cls_TopoDS_Builder.def("Remove", (void (TopoDS_Builder::*)(TopoDS_Shape &, const TopoDS_Shape &) const) &TopoDS_Builder::Remove, "Remove the Shape C from the Shape S. Exceptions TopoDS_FrozenShape if S is frozen and cannot be modified.", py::arg("S"), py::arg("C"));

// CLASS: TOPODS_TWIRE
py::class_<TopoDS_TWire, opencascade::handle<TopoDS_TWire>, TopoDS_TShape> cls_TopoDS_TWire(mod, "TopoDS_TWire", "A set of edges connected by their vertices.");

// Constructors
cls_TopoDS_TWire.def(py::init<>());

// Methods
cls_TopoDS_TWire.def("ShapeType", (TopAbs_ShapeEnum (TopoDS_TWire::*)() const) &TopoDS_TWire::ShapeType, "Returns WIRE.");
cls_TopoDS_TWire.def("EmptyCopy", (opencascade::handle<TopoDS_TShape> (TopoDS_TWire::*)() const) &TopoDS_TWire::EmptyCopy, "Returns an empty TWire.");
cls_TopoDS_TWire.def_static("get_type_name_", (const char * (*)()) &TopoDS_TWire::get_type_name, "None");
cls_TopoDS_TWire.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopoDS_TWire::get_type_descriptor, "None");
cls_TopoDS_TWire.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopoDS_TWire::*)() const) &TopoDS_TWire::DynamicType, "None");

// CLASS: TOPODS_TSHELL
py::class_<TopoDS_TShell, opencascade::handle<TopoDS_TShell>, TopoDS_TShape> cls_TopoDS_TShell(mod, "TopoDS_TShell", "A set of faces connected by their edges.");

// Constructors
cls_TopoDS_TShell.def(py::init<>());

// Methods
cls_TopoDS_TShell.def("ShapeType", (TopAbs_ShapeEnum (TopoDS_TShell::*)() const) &TopoDS_TShell::ShapeType, "Returns SHELL.");
cls_TopoDS_TShell.def("EmptyCopy", (opencascade::handle<TopoDS_TShape> (TopoDS_TShell::*)() const) &TopoDS_TShell::EmptyCopy, "Returns an empty TShell.");
cls_TopoDS_TShell.def_static("get_type_name_", (const char * (*)()) &TopoDS_TShell::get_type_name, "None");
cls_TopoDS_TShell.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopoDS_TShell::get_type_descriptor, "None");
cls_TopoDS_TShell.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopoDS_TShell::*)() const) &TopoDS_TShell::DynamicType, "None");

// CLASS: TOPODS_TSOLID
py::class_<TopoDS_TSolid, opencascade::handle<TopoDS_TSolid>, TopoDS_TShape> cls_TopoDS_TSolid(mod, "TopoDS_TSolid", "A Topological part of 3D space, bounded by shells, edges and vertices.");

// Constructors
cls_TopoDS_TSolid.def(py::init<>());

// Methods
cls_TopoDS_TSolid.def("ShapeType", (TopAbs_ShapeEnum (TopoDS_TSolid::*)() const) &TopoDS_TSolid::ShapeType, "returns SOLID.");
cls_TopoDS_TSolid.def("EmptyCopy", (opencascade::handle<TopoDS_TShape> (TopoDS_TSolid::*)() const) &TopoDS_TSolid::EmptyCopy, "Returns an empty TSolid.");
cls_TopoDS_TSolid.def_static("get_type_name_", (const char * (*)()) &TopoDS_TSolid::get_type_name, "None");
cls_TopoDS_TSolid.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopoDS_TSolid::get_type_descriptor, "None");
cls_TopoDS_TSolid.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopoDS_TSolid::*)() const) &TopoDS_TSolid::DynamicType, "None");

// CLASS: TOPODS_TCOMPSOLID
py::class_<TopoDS_TCompSolid, opencascade::handle<TopoDS_TCompSolid>, TopoDS_TShape> cls_TopoDS_TCompSolid(mod, "TopoDS_TCompSolid", "A set of solids connected by their faces.");

// Constructors
cls_TopoDS_TCompSolid.def(py::init<>());

// Methods
cls_TopoDS_TCompSolid.def("ShapeType", (TopAbs_ShapeEnum (TopoDS_TCompSolid::*)() const) &TopoDS_TCompSolid::ShapeType, "returns COMPSOLID");
cls_TopoDS_TCompSolid.def("EmptyCopy", (opencascade::handle<TopoDS_TShape> (TopoDS_TCompSolid::*)() const) &TopoDS_TCompSolid::EmptyCopy, "Returns an empty TCompSolid.");
cls_TopoDS_TCompSolid.def_static("get_type_name_", (const char * (*)()) &TopoDS_TCompSolid::get_type_name, "None");
cls_TopoDS_TCompSolid.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopoDS_TCompSolid::get_type_descriptor, "None");
cls_TopoDS_TCompSolid.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopoDS_TCompSolid::*)() const) &TopoDS_TCompSolid::DynamicType, "None");

// CLASS: TOPODS_TCOMPOUND
py::class_<TopoDS_TCompound, opencascade::handle<TopoDS_TCompound>, TopoDS_TShape> cls_TopoDS_TCompound(mod, "TopoDS_TCompound", "A TCompound is an all-purpose set of Shapes.");

// Constructors
cls_TopoDS_TCompound.def(py::init<>());

// Methods
cls_TopoDS_TCompound.def("ShapeType", (TopAbs_ShapeEnum (TopoDS_TCompound::*)() const) &TopoDS_TCompound::ShapeType, "Returns COMPOUND.");
cls_TopoDS_TCompound.def("EmptyCopy", (opencascade::handle<TopoDS_TShape> (TopoDS_TCompound::*)() const) &TopoDS_TCompound::EmptyCopy, "Returns an empty TCompound.");
cls_TopoDS_TCompound.def_static("get_type_name_", (const char * (*)()) &TopoDS_TCompound::get_type_name, "None");
cls_TopoDS_TCompound.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopoDS_TCompound::get_type_descriptor, "None");
cls_TopoDS_TCompound.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopoDS_TCompound::*)() const) &TopoDS_TCompound::DynamicType, "None");

// CLASS: TOPODS_SHELL
py::class_<TopoDS_Shell, TopoDS_Shape> cls_TopoDS_Shell(mod, "TopoDS_Shell", "Describes a shell which - references an underlying shell with the potential to be given a location and an orientation - has a location for the underlying shell, giving its placement in the local coordinate system - has an orientation for the underlying shell, in terms of its geometry (as opposed to orientation in relation to other shapes).");

// Constructors
cls_TopoDS_Shell.def(py::init<>());

// Methods
// cls_TopoDS_Shell.def_static("operator new_", (void * (*)(size_t)) &TopoDS_Shell::operator new, "None", py::arg("theSize"));
// cls_TopoDS_Shell.def_static("operator delete_", (void (*)(void *)) &TopoDS_Shell::operator delete, "None", py::arg("theAddress"));
// cls_TopoDS_Shell.def_static("operator new[]_", (void * (*)(size_t)) &TopoDS_Shell::operator new[], "None", py::arg("theSize"));
// cls_TopoDS_Shell.def_static("operator delete[]_", (void (*)(void *)) &TopoDS_Shell::operator delete[], "None", py::arg("theAddress"));
// cls_TopoDS_Shell.def_static("operator new_", (void * (*)(size_t, void *)) &TopoDS_Shell::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopoDS_Shell.def_static("operator delete_", (void (*)(void *, void *)) &TopoDS_Shell::operator delete, "None", py::arg(""), py::arg(""));

// CLASS: TOPODS_SOLID
py::class_<TopoDS_Solid, TopoDS_Shape> cls_TopoDS_Solid(mod, "TopoDS_Solid", "Describes a solid shape which - references an underlying solid shape with the potential to be given a location and an orientation - has a location for the underlying shape, giving its placement in the local coordinate system - has an orientation for the underlying shape, in terms of its geometry (as opposed to orientation in relation to other shapes).");

// Constructors
cls_TopoDS_Solid.def(py::init<>());

// Methods
// cls_TopoDS_Solid.def_static("operator new_", (void * (*)(size_t)) &TopoDS_Solid::operator new, "None", py::arg("theSize"));
// cls_TopoDS_Solid.def_static("operator delete_", (void (*)(void *)) &TopoDS_Solid::operator delete, "None", py::arg("theAddress"));
// cls_TopoDS_Solid.def_static("operator new[]_", (void * (*)(size_t)) &TopoDS_Solid::operator new[], "None", py::arg("theSize"));
// cls_TopoDS_Solid.def_static("operator delete[]_", (void (*)(void *)) &TopoDS_Solid::operator delete[], "None", py::arg("theAddress"));
// cls_TopoDS_Solid.def_static("operator new_", (void * (*)(size_t, void *)) &TopoDS_Solid::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopoDS_Solid.def_static("operator delete_", (void (*)(void *, void *)) &TopoDS_Solid::operator delete, "None", py::arg(""), py::arg(""));

// CLASS: TOPODS_COMPSOLID
py::class_<TopoDS_CompSolid, TopoDS_Shape> cls_TopoDS_CompSolid(mod, "TopoDS_CompSolid", "Describes a composite solid which - references an underlying composite solid with the potential to be given a location and an orientation - has a location for the underlying composite solid, giving its placement in the local coordinate system - has an orientation for the underlying composite solid, in terms of its geometry (as opposed to orientation in relation to other shapes). Casts shape S to the more specialized return type, CompSolid.");

// Constructors
cls_TopoDS_CompSolid.def(py::init<>());

// Methods
// cls_TopoDS_CompSolid.def_static("operator new_", (void * (*)(size_t)) &TopoDS_CompSolid::operator new, "None", py::arg("theSize"));
// cls_TopoDS_CompSolid.def_static("operator delete_", (void (*)(void *)) &TopoDS_CompSolid::operator delete, "None", py::arg("theAddress"));
// cls_TopoDS_CompSolid.def_static("operator new[]_", (void * (*)(size_t)) &TopoDS_CompSolid::operator new[], "None", py::arg("theSize"));
// cls_TopoDS_CompSolid.def_static("operator delete[]_", (void (*)(void *)) &TopoDS_CompSolid::operator delete[], "None", py::arg("theAddress"));
// cls_TopoDS_CompSolid.def_static("operator new_", (void * (*)(size_t, void *)) &TopoDS_CompSolid::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopoDS_CompSolid.def_static("operator delete_", (void (*)(void *, void *)) &TopoDS_CompSolid::operator delete, "None", py::arg(""), py::arg(""));

// CLASS: TOPODS_TFACE
py::class_<TopoDS_TFace, opencascade::handle<TopoDS_TFace>, TopoDS_TShape> cls_TopoDS_TFace(mod, "TopoDS_TFace", "A topological part of a surface or of the 2D space. The boundary is a set of wires and vertices.");

// Constructors
cls_TopoDS_TFace.def(py::init<>());

// Methods
cls_TopoDS_TFace.def("ShapeType", (TopAbs_ShapeEnum (TopoDS_TFace::*)() const) &TopoDS_TFace::ShapeType, "returns FACE.");
cls_TopoDS_TFace.def("EmptyCopy", (opencascade::handle<TopoDS_TShape> (TopoDS_TFace::*)() const) &TopoDS_TFace::EmptyCopy, "Returns an empty TFace.");
cls_TopoDS_TFace.def_static("get_type_name_", (const char * (*)()) &TopoDS_TFace::get_type_name, "None");
cls_TopoDS_TFace.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopoDS_TFace::get_type_descriptor, "None");
cls_TopoDS_TFace.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopoDS_TFace::*)() const) &TopoDS_TFace::DynamicType, "None");

// CLASS: TOPODS_TVERTEX
py::class_<TopoDS_TVertex, opencascade::handle<TopoDS_TVertex>, TopoDS_TShape> cls_TopoDS_TVertex(mod, "TopoDS_TVertex", "A Vertex is a topological point in two or three dimensions.");

// Methods
cls_TopoDS_TVertex.def("ShapeType", (TopAbs_ShapeEnum (TopoDS_TVertex::*)() const) &TopoDS_TVertex::ShapeType, "Returns VERTEX.");
cls_TopoDS_TVertex.def_static("get_type_name_", (const char * (*)()) &TopoDS_TVertex::get_type_name, "None");
cls_TopoDS_TVertex.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopoDS_TVertex::get_type_descriptor, "None");
cls_TopoDS_TVertex.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopoDS_TVertex::*)() const) &TopoDS_TVertex::DynamicType, "None");

// CLASS: TOPODS_ALERTWITHSHAPE
py::class_<TopoDS_AlertWithShape, opencascade::handle<TopoDS_AlertWithShape>, Message_Alert> cls_TopoDS_AlertWithShape(mod, "TopoDS_AlertWithShape", "Alert object storing TopoDS shape in its field");

// Constructors
cls_TopoDS_AlertWithShape.def(py::init<const TopoDS_Shape &>(), py::arg("theShape"));

// Methods
cls_TopoDS_AlertWithShape.def("GetShape", (const TopoDS_Shape & (TopoDS_AlertWithShape::*)() const) &TopoDS_AlertWithShape::GetShape, "Returns contained shape");
cls_TopoDS_AlertWithShape.def("SupportsMerge", (Standard_Boolean (TopoDS_AlertWithShape::*)() const) &TopoDS_AlertWithShape::SupportsMerge, "Returns false.");
cls_TopoDS_AlertWithShape.def("Merge", (Standard_Boolean (TopoDS_AlertWithShape::*)(const opencascade::handle<Message_Alert> &)) &TopoDS_AlertWithShape::Merge, "Returns false.", py::arg("theTarget"));
cls_TopoDS_AlertWithShape.def_static("get_type_name_", (const char * (*)()) &TopoDS_AlertWithShape::get_type_name, "None");
cls_TopoDS_AlertWithShape.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopoDS_AlertWithShape::get_type_descriptor, "None");
cls_TopoDS_AlertWithShape.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopoDS_AlertWithShape::*)() const) &TopoDS_AlertWithShape::DynamicType, "None");

// CLASS: TOPODS_ITERATOR
py::class_<TopoDS_Iterator> cls_TopoDS_Iterator(mod, "TopoDS_Iterator", "Iterates on the underlying shape underlying a given TopoDS_Shape object, providing access to its component sub-shapes. Each component shape is returned as a TopoDS_Shape with an orientation, and a compound of the original values and the relative values.");

// Constructors
cls_TopoDS_Iterator.def(py::init<>());
cls_TopoDS_Iterator.def(py::init<const TopoDS_Shape &>(), py::arg("S"));
cls_TopoDS_Iterator.def(py::init<const TopoDS_Shape &, const Standard_Boolean>(), py::arg("S"), py::arg("cumOri"));
cls_TopoDS_Iterator.def(py::init<const TopoDS_Shape &, const Standard_Boolean, const Standard_Boolean>(), py::arg("S"), py::arg("cumOri"), py::arg("cumLoc"));

// Methods
// cls_TopoDS_Iterator.def_static("operator new_", (void * (*)(size_t)) &TopoDS_Iterator::operator new, "None", py::arg("theSize"));
// cls_TopoDS_Iterator.def_static("operator delete_", (void (*)(void *)) &TopoDS_Iterator::operator delete, "None", py::arg("theAddress"));
// cls_TopoDS_Iterator.def_static("operator new[]_", (void * (*)(size_t)) &TopoDS_Iterator::operator new[], "None", py::arg("theSize"));
// cls_TopoDS_Iterator.def_static("operator delete[]_", (void (*)(void *)) &TopoDS_Iterator::operator delete[], "None", py::arg("theAddress"));
// cls_TopoDS_Iterator.def_static("operator new_", (void * (*)(size_t, void *)) &TopoDS_Iterator::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopoDS_Iterator.def_static("operator delete_", (void (*)(void *, void *)) &TopoDS_Iterator::operator delete, "None", py::arg(""), py::arg(""));
cls_TopoDS_Iterator.def("Initialize", [](TopoDS_Iterator &self, const TopoDS_Shape & a0) -> void { return self.Initialize(a0); });
cls_TopoDS_Iterator.def("Initialize", [](TopoDS_Iterator &self, const TopoDS_Shape & a0, const Standard_Boolean a1) -> void { return self.Initialize(a0, a1); });
cls_TopoDS_Iterator.def("Initialize", (void (TopoDS_Iterator::*)(const TopoDS_Shape &, const Standard_Boolean, const Standard_Boolean)) &TopoDS_Iterator::Initialize, "Initializes this iterator with shape S. Note: - If cumOri is true, the function composes all sub-shapes with the orientation of S. - If cumLoc is true, the function multiplies all sub-shapes by the location of S, i.e. it applies to each sub-shape the transformation that is associated with S.", py::arg("S"), py::arg("cumOri"), py::arg("cumLoc"));
cls_TopoDS_Iterator.def("More", (Standard_Boolean (TopoDS_Iterator::*)() const) &TopoDS_Iterator::More, "Returns true if there is another sub-shape in the shape which this iterator is scanning.");
cls_TopoDS_Iterator.def("Next", (void (TopoDS_Iterator::*)()) &TopoDS_Iterator::Next, "Moves on to the next sub-shape in the shape which this iterator is scanning. Exceptions Standard_NoMoreObject if there are no more sub-shapes in the shape.");
cls_TopoDS_Iterator.def("Value", (const TopoDS_Shape & (TopoDS_Iterator::*)() const) &TopoDS_Iterator::Value, "Returns the current sub-shape in the shape which this iterator is scanning. Exceptions Standard_NoSuchObject if there is no current sub-shape.");

// CLASS: TOPODS_TEDGE
py::class_<TopoDS_TEdge, opencascade::handle<TopoDS_TEdge>, TopoDS_TShape> cls_TopoDS_TEdge(mod, "TopoDS_TEdge", "A topological part of a curve in 2D or 3D, the boundary is a set of oriented Vertices.");

// Methods
cls_TopoDS_TEdge.def("ShapeType", (TopAbs_ShapeEnum (TopoDS_TEdge::*)() const) &TopoDS_TEdge::ShapeType, "Returns EDGE.");
cls_TopoDS_TEdge.def_static("get_type_name_", (const char * (*)()) &TopoDS_TEdge::get_type_name, "None");
cls_TopoDS_TEdge.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopoDS_TEdge::get_type_descriptor, "None");
cls_TopoDS_TEdge.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopoDS_TEdge::*)() const) &TopoDS_TEdge::DynamicType, "None");

// CLASS: TOPODS_FROZENSHAPE
py::class_<TopoDS_FrozenShape, opencascade::handle<TopoDS_FrozenShape>, Standard_DomainError> cls_TopoDS_FrozenShape(mod, "TopoDS_FrozenShape", "An attempt was made to modify a Shape already shared or protected.");

// Constructors
cls_TopoDS_FrozenShape.def(py::init<>());
cls_TopoDS_FrozenShape.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_TopoDS_FrozenShape.def_static("Raise_", (void (*)(const Standard_CString)) &TopoDS_FrozenShape::Raise, "None", py::arg("theMessage"));
cls_TopoDS_FrozenShape.def_static("Raise_", (void (*)(Standard_SStream &)) &TopoDS_FrozenShape::Raise, "None", py::arg("theMessage"));
cls_TopoDS_FrozenShape.def_static("NewInstance_", (opencascade::handle<TopoDS_FrozenShape> (*)(const Standard_CString)) &TopoDS_FrozenShape::NewInstance, "None", py::arg("theMessage"));
cls_TopoDS_FrozenShape.def_static("get_type_name_", (const char * (*)()) &TopoDS_FrozenShape::get_type_name, "None");
cls_TopoDS_FrozenShape.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopoDS_FrozenShape::get_type_descriptor, "None");
cls_TopoDS_FrozenShape.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopoDS_FrozenShape::*)() const) &TopoDS_FrozenShape::DynamicType, "None");

// CLASS: TOPODS_HSHAPE
py::class_<TopoDS_HShape, opencascade::handle<TopoDS_HShape>, Standard_Transient> cls_TopoDS_HShape(mod, "TopoDS_HShape", "Class to manipulate a Shape with handle.");

// Constructors
cls_TopoDS_HShape.def(py::init<>());
cls_TopoDS_HShape.def(py::init<const TopoDS_Shape &>(), py::arg("aShape"));

// Methods
cls_TopoDS_HShape.def("Shape", (void (TopoDS_HShape::*)(const TopoDS_Shape &)) &TopoDS_HShape::Shape, "Loads this shape with the shape aShape", py::arg("aShape"));
cls_TopoDS_HShape.def("Shape", (const TopoDS_Shape & (TopoDS_HShape::*)() const) &TopoDS_HShape::Shape, "Returns a reference to a constant TopoDS_Shape based on this shape.");
cls_TopoDS_HShape.def("ChangeShape", (TopoDS_Shape & (TopoDS_HShape::*)()) &TopoDS_HShape::ChangeShape, "Exchanges the TopoDS_Shape object defining this shape for another one referencing the same underlying shape Accesses the list of shapes within the underlying shape referenced by the TopoDS_Shape object. Returns a reference to a TopoDS_Shape based on this shape. The TopoDS_Shape can be modified.");
cls_TopoDS_HShape.def_static("get_type_name_", (const char * (*)()) &TopoDS_HShape::get_type_name, "None");
cls_TopoDS_HShape.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopoDS_HShape::get_type_descriptor, "None");
cls_TopoDS_HShape.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopoDS_HShape::*)() const) &TopoDS_HShape::DynamicType, "None");

// CLASS: TOPODS_LOCKEDSHAPE
py::class_<TopoDS_LockedShape, opencascade::handle<TopoDS_LockedShape>, Standard_DomainError> cls_TopoDS_LockedShape(mod, "TopoDS_LockedShape", "An attempt was made to modify a geometry of Shape already shared or protected.");

// Constructors
cls_TopoDS_LockedShape.def(py::init<>());
cls_TopoDS_LockedShape.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_TopoDS_LockedShape.def_static("Raise_", (void (*)(const Standard_CString)) &TopoDS_LockedShape::Raise, "None", py::arg("theMessage"));
cls_TopoDS_LockedShape.def_static("Raise_", (void (*)(Standard_SStream &)) &TopoDS_LockedShape::Raise, "None", py::arg("theMessage"));
cls_TopoDS_LockedShape.def_static("NewInstance_", (opencascade::handle<TopoDS_LockedShape> (*)(const Standard_CString)) &TopoDS_LockedShape::NewInstance, "None", py::arg("theMessage"));
cls_TopoDS_LockedShape.def_static("get_type_name_", (const char * (*)()) &TopoDS_LockedShape::get_type_name, "None");
cls_TopoDS_LockedShape.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopoDS_LockedShape::get_type_descriptor, "None");
cls_TopoDS_LockedShape.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopoDS_LockedShape::*)() const) &TopoDS_LockedShape::DynamicType, "None");

// CLASS: TOPODS_UNCOMPATIBLESHAPES
py::class_<TopoDS_UnCompatibleShapes, opencascade::handle<TopoDS_UnCompatibleShapes>, Standard_DomainError> cls_TopoDS_UnCompatibleShapes(mod, "TopoDS_UnCompatibleShapes", "An incorrect insertion was attempted.");

// Constructors
cls_TopoDS_UnCompatibleShapes.def(py::init<>());
cls_TopoDS_UnCompatibleShapes.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_TopoDS_UnCompatibleShapes.def_static("Raise_", (void (*)(const Standard_CString)) &TopoDS_UnCompatibleShapes::Raise, "None", py::arg("theMessage"));
cls_TopoDS_UnCompatibleShapes.def_static("Raise_", (void (*)(Standard_SStream &)) &TopoDS_UnCompatibleShapes::Raise, "None", py::arg("theMessage"));
cls_TopoDS_UnCompatibleShapes.def_static("NewInstance_", (opencascade::handle<TopoDS_UnCompatibleShapes> (*)(const Standard_CString)) &TopoDS_UnCompatibleShapes::NewInstance, "None", py::arg("theMessage"));
cls_TopoDS_UnCompatibleShapes.def_static("get_type_name_", (const char * (*)()) &TopoDS_UnCompatibleShapes::get_type_name, "None");
cls_TopoDS_UnCompatibleShapes.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopoDS_UnCompatibleShapes::get_type_descriptor, "None");
cls_TopoDS_UnCompatibleShapes.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopoDS_UnCompatibleShapes::*)() const) &TopoDS_UnCompatibleShapes::DynamicType, "None");


}
