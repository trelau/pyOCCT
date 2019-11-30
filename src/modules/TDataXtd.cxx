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
#include <TDataXtd_GeometryEnum.hxx>
#include <TDataXtd_ConstraintEnum.hxx>
#include <TDF_Attribute.hxx>
#include <Standard_TypeDef.hxx>
#include <TDF_Label.hxx>
#include <Standard_Handle.hxx>
#include <TDataXtd_Shape.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_GUID.hxx>
#include <TDF_RelocationTable.hxx>
#include <TDF_DataSet.hxx>
#include <Standard_OStream.hxx>
#include <Standard_Std.hxx>
#include <Standard_Type.hxx>
#include <TDataXtd_Point.hxx>
#include <gp_Pnt.hxx>
#include <TDataXtd_Axis.hxx>
#include <gp_Lin.hxx>
#include <TDataXtd_Plane.hxx>
#include <gp_Pln.hxx>
#include <TDataXtd_Placement.hxx>
#include <TDataXtd_Geometry.hxx>
#include <TNaming_NamedShape.hxx>
#include <gp_Ax1.hxx>
#include <gp_Circ.hxx>
#include <gp_Elips.hxx>
#include <gp_Cylinder.hxx>
#include <TDataXtd_Position.hxx>
#include <TDataXtd_Constraint.hxx>
#include <TDataStd_Real.hxx>
#include <TDF_LabelList.hxx>
#include <NCollection_Array1.hxx>
#include <gp_Trsf.hxx>
#include <TDataXtd_Array1OfTrsf.hxx>
#include <TDataXtd_Pattern.hxx>
#include <TDataXtd_PatternStd.hxx>
#include <TDataStd_Integer.hxx>
#include <TDataXtd_Presentation.hxx>
#include <Quantity_NameOfColor.hxx>
#include <TColStd_ListOfInteger.hxx>
#include <Standard.hxx>
#include <TDF_IDList.hxx>
#include <TDataXtd_Triangulation.hxx>
#include <TDataXtd.hxx>
#include <Standard_Transient.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <TDataXtd_HArray1OfTrsf.hxx>
#include <Poly_Triangulation.hxx>
#include <gp_Pnt2d.hxx>
#include <Poly_Triangle.hxx>
#include <TShort_HArray1OfShortReal.hxx>
#include <gp_Dir.hxx>
#include <bind_NCollection_Array1.hxx>

PYBIND11_MODULE(TDataXtd, mod) {

py::module::import("OCCT.TDF");
py::module::import("OCCT.Standard");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.gp");
py::module::import("OCCT.TNaming");
py::module::import("OCCT.TDataStd");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.Quantity");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.Poly");
py::module::import("OCCT.TShort");

// ENUM: TDATAXTD_GEOMETRYENUM
py::enum_<TDataXtd_GeometryEnum>(mod, "TDataXtd_GeometryEnum", "The terms of this enumeration define the types of geometric shapes available.")
	.value("TDataXtd_ANY_GEOM", TDataXtd_GeometryEnum::TDataXtd_ANY_GEOM)
	.value("TDataXtd_POINT", TDataXtd_GeometryEnum::TDataXtd_POINT)
	.value("TDataXtd_LINE", TDataXtd_GeometryEnum::TDataXtd_LINE)
	.value("TDataXtd_CIRCLE", TDataXtd_GeometryEnum::TDataXtd_CIRCLE)
	.value("TDataXtd_ELLIPSE", TDataXtd_GeometryEnum::TDataXtd_ELLIPSE)
	.value("TDataXtd_SPLINE", TDataXtd_GeometryEnum::TDataXtd_SPLINE)
	.value("TDataXtd_PLANE", TDataXtd_GeometryEnum::TDataXtd_PLANE)
	.value("TDataXtd_CYLINDER", TDataXtd_GeometryEnum::TDataXtd_CYLINDER)
	.export_values();


// ENUM: TDATAXTD_CONSTRAINTENUM
py::enum_<TDataXtd_ConstraintEnum>(mod, "TDataXtd_ConstraintEnum", "The terms of this enumeration define the types of available constraint. ==================")
	.value("TDataXtd_RADIUS", TDataXtd_ConstraintEnum::TDataXtd_RADIUS)
	.value("TDataXtd_DIAMETER", TDataXtd_ConstraintEnum::TDataXtd_DIAMETER)
	.value("TDataXtd_MINOR_RADIUS", TDataXtd_ConstraintEnum::TDataXtd_MINOR_RADIUS)
	.value("TDataXtd_MAJOR_RADIUS", TDataXtd_ConstraintEnum::TDataXtd_MAJOR_RADIUS)
	.value("TDataXtd_TANGENT", TDataXtd_ConstraintEnum::TDataXtd_TANGENT)
	.value("TDataXtd_PARALLEL", TDataXtd_ConstraintEnum::TDataXtd_PARALLEL)
	.value("TDataXtd_PERPENDICULAR", TDataXtd_ConstraintEnum::TDataXtd_PERPENDICULAR)
	.value("TDataXtd_CONCENTRIC", TDataXtd_ConstraintEnum::TDataXtd_CONCENTRIC)
	.value("TDataXtd_COINCIDENT", TDataXtd_ConstraintEnum::TDataXtd_COINCIDENT)
	.value("TDataXtd_DISTANCE", TDataXtd_ConstraintEnum::TDataXtd_DISTANCE)
	.value("TDataXtd_ANGLE", TDataXtd_ConstraintEnum::TDataXtd_ANGLE)
	.value("TDataXtd_EQUAL_RADIUS", TDataXtd_ConstraintEnum::TDataXtd_EQUAL_RADIUS)
	.value("TDataXtd_SYMMETRY", TDataXtd_ConstraintEnum::TDataXtd_SYMMETRY)
	.value("TDataXtd_MIDPOINT", TDataXtd_ConstraintEnum::TDataXtd_MIDPOINT)
	.value("TDataXtd_EQUAL_DISTANCE", TDataXtd_ConstraintEnum::TDataXtd_EQUAL_DISTANCE)
	.value("TDataXtd_FIX", TDataXtd_ConstraintEnum::TDataXtd_FIX)
	.value("TDataXtd_RIGID", TDataXtd_ConstraintEnum::TDataXtd_RIGID)
	.value("TDataXtd_FROM", TDataXtd_ConstraintEnum::TDataXtd_FROM)
	.value("TDataXtd_AXIS", TDataXtd_ConstraintEnum::TDataXtd_AXIS)
	.value("TDataXtd_MATE", TDataXtd_ConstraintEnum::TDataXtd_MATE)
	.value("TDataXtd_ALIGN_FACES", TDataXtd_ConstraintEnum::TDataXtd_ALIGN_FACES)
	.value("TDataXtd_ALIGN_AXES", TDataXtd_ConstraintEnum::TDataXtd_ALIGN_AXES)
	.value("TDataXtd_AXES_ANGLE", TDataXtd_ConstraintEnum::TDataXtd_AXES_ANGLE)
	.value("TDataXtd_FACES_ANGLE", TDataXtd_ConstraintEnum::TDataXtd_FACES_ANGLE)
	.value("TDataXtd_ROUND", TDataXtd_ConstraintEnum::TDataXtd_ROUND)
	.value("TDataXtd_OFFSET", TDataXtd_ConstraintEnum::TDataXtd_OFFSET)
	.export_values();


// CLASS: TDATAXTD_SHAPE
py::class_<TDataXtd_Shape, opencascade::handle<TDataXtd_Shape>, TDF_Attribute> cls_TDataXtd_Shape(mod, "TDataXtd_Shape", "A Shape is associated in the framework with : a NamedShape attribute");

// Constructors
cls_TDataXtd_Shape.def(py::init<>());

// Methods
cls_TDataXtd_Shape.def_static("Find_", (Standard_Boolean (*)(const TDF_Label &, opencascade::handle<TDataXtd_Shape> &)) &TDataXtd_Shape::Find, "class methods ============= try to retrieve a Shape attribute at <current> label or in fathers label of <current>. Returns True if found and set <S>.", py::arg("current"), py::arg("S"));
cls_TDataXtd_Shape.def_static("New_", (opencascade::handle<TDataXtd_Shape> (*)(const TDF_Label &)) &TDataXtd_Shape::New, "Find, or create, a Shape attribute. the Shape attribute is returned. Raises if <label> has attribute.", py::arg("label"));
cls_TDataXtd_Shape.def_static("Set_", (opencascade::handle<TDataXtd_Shape> (*)(const TDF_Label &, const TopoDS_Shape &)) &TDataXtd_Shape::Set, "Create or update associated NamedShape attribute. the Shape attribute is returned.", py::arg("label"), py::arg("shape"));
cls_TDataXtd_Shape.def_static("Get_", (TopoDS_Shape (*)(const TDF_Label &)) &TDataXtd_Shape::Get, "the Shape from associated NamedShape attribute is returned.", py::arg("label"));
cls_TDataXtd_Shape.def_static("GetID_", (const Standard_GUID & (*)()) &TDataXtd_Shape::GetID, "Shape methods ============");
cls_TDataXtd_Shape.def("ID", (const Standard_GUID & (TDataXtd_Shape::*)() const) &TDataXtd_Shape::ID, "None");
cls_TDataXtd_Shape.def("Restore", (void (TDataXtd_Shape::*)(const opencascade::handle<TDF_Attribute> &)) &TDataXtd_Shape::Restore, "None", py::arg("with"));
cls_TDataXtd_Shape.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDataXtd_Shape::*)() const) &TDataXtd_Shape::NewEmpty, "None");
cls_TDataXtd_Shape.def("Paste", (void (TDataXtd_Shape::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDataXtd_Shape::Paste, "None", py::arg("into"), py::arg("RT"));
cls_TDataXtd_Shape.def("References", (void (TDataXtd_Shape::*)(const opencascade::handle<TDF_DataSet> &) const) &TDataXtd_Shape::References, "None", py::arg("DS"));
cls_TDataXtd_Shape.def("Dump", (Standard_OStream & (TDataXtd_Shape::*)(Standard_OStream &) const) &TDataXtd_Shape::Dump, "None", py::arg("anOS"));
cls_TDataXtd_Shape.def_static("get_type_name_", (const char * (*)()) &TDataXtd_Shape::get_type_name, "None");
cls_TDataXtd_Shape.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataXtd_Shape::get_type_descriptor, "None");
cls_TDataXtd_Shape.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataXtd_Shape::*)() const) &TDataXtd_Shape::DynamicType, "None");

// CLASS: TDATAXTD_POINT
py::class_<TDataXtd_Point, opencascade::handle<TDataXtd_Point>, TDF_Attribute> cls_TDataXtd_Point(mod, "TDataXtd_Point", "The basis to define a point attribute. The topological attribute must contain a vertex. You use this class to create reference points in a design.");

// Constructors
cls_TDataXtd_Point.def(py::init<>());

// Methods
cls_TDataXtd_Point.def_static("GetID_", (const Standard_GUID & (*)()) &TDataXtd_Point::GetID, "class methods =============");
cls_TDataXtd_Point.def_static("Set_", (opencascade::handle<TDataXtd_Point> (*)(const TDF_Label &)) &TDataXtd_Point::Set, "Sets the label Label as a point attribute. If no object is found, a point attribute is created.", py::arg("label"));
cls_TDataXtd_Point.def_static("Set_", (opencascade::handle<TDataXtd_Point> (*)(const TDF_Label &, const gp_Pnt &)) &TDataXtd_Point::Set, "Sets the label Label as a point attribute containing the point P. If no object is found, a point attribute is created. Point methods =============", py::arg("label"), py::arg("P"));
cls_TDataXtd_Point.def("ID", (const Standard_GUID & (TDataXtd_Point::*)() const) &TDataXtd_Point::ID, "None");
cls_TDataXtd_Point.def("Restore", (void (TDataXtd_Point::*)(const opencascade::handle<TDF_Attribute> &)) &TDataXtd_Point::Restore, "None", py::arg("With"));
cls_TDataXtd_Point.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDataXtd_Point::*)() const) &TDataXtd_Point::NewEmpty, "None");
cls_TDataXtd_Point.def("Paste", (void (TDataXtd_Point::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDataXtd_Point::Paste, "None", py::arg("Into"), py::arg("RT"));
cls_TDataXtd_Point.def("Dump", (Standard_OStream & (TDataXtd_Point::*)(Standard_OStream &) const) &TDataXtd_Point::Dump, "None", py::arg("anOS"));
cls_TDataXtd_Point.def_static("get_type_name_", (const char * (*)()) &TDataXtd_Point::get_type_name, "None");
cls_TDataXtd_Point.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataXtd_Point::get_type_descriptor, "None");
cls_TDataXtd_Point.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataXtd_Point::*)() const) &TDataXtd_Point::DynamicType, "None");

// CLASS: TDATAXTD_AXIS
py::class_<TDataXtd_Axis, opencascade::handle<TDataXtd_Axis>, TDF_Attribute> cls_TDataXtd_Axis(mod, "TDataXtd_Axis", "The basis to define an axis attribute.");

// Constructors
cls_TDataXtd_Axis.def(py::init<>());

// Methods
cls_TDataXtd_Axis.def_static("GetID_", (const Standard_GUID & (*)()) &TDataXtd_Axis::GetID, "class methods ============= Returns the GUID for an axis.");
cls_TDataXtd_Axis.def_static("Set_", (opencascade::handle<TDataXtd_Axis> (*)(const TDF_Label &)) &TDataXtd_Axis::Set, "Finds or creates an axis attribute defined by the label. In the case of a creation of an axis, a compatible named shape should already be associated with label. Exceptions Standard_NullObject if no compatible named shape is associated with the label.", py::arg("label"));
cls_TDataXtd_Axis.def_static("Set_", (opencascade::handle<TDataXtd_Axis> (*)(const TDF_Label &, const gp_Lin &)) &TDataXtd_Axis::Set, "Find, or create, an Axis attribute and set <P> as generated in the associated NamedShape. Axis methods ============", py::arg("label"), py::arg("L"));
cls_TDataXtd_Axis.def("ID", (const Standard_GUID & (TDataXtd_Axis::*)() const) &TDataXtd_Axis::ID, "None");
cls_TDataXtd_Axis.def("Restore", (void (TDataXtd_Axis::*)(const opencascade::handle<TDF_Attribute> &)) &TDataXtd_Axis::Restore, "None", py::arg("with"));
cls_TDataXtd_Axis.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDataXtd_Axis::*)() const) &TDataXtd_Axis::NewEmpty, "None");
cls_TDataXtd_Axis.def("Paste", (void (TDataXtd_Axis::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDataXtd_Axis::Paste, "None", py::arg("into"), py::arg("RT"));
cls_TDataXtd_Axis.def("Dump", (Standard_OStream & (TDataXtd_Axis::*)(Standard_OStream &) const) &TDataXtd_Axis::Dump, "None", py::arg("anOS"));
cls_TDataXtd_Axis.def_static("get_type_name_", (const char * (*)()) &TDataXtd_Axis::get_type_name, "None");
cls_TDataXtd_Axis.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataXtd_Axis::get_type_descriptor, "None");
cls_TDataXtd_Axis.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataXtd_Axis::*)() const) &TDataXtd_Axis::DynamicType, "None");

// CLASS: TDATAXTD_PLANE
py::class_<TDataXtd_Plane, opencascade::handle<TDataXtd_Plane>, TDF_Attribute> cls_TDataXtd_Plane(mod, "TDataXtd_Plane", "The basis to define a plane attribute. Warning: Use TDataXtd_Geometry attribute to retrieve the gp_Pln of the Plane attribute");

// Constructors
cls_TDataXtd_Plane.def(py::init<>());

// Methods
cls_TDataXtd_Plane.def_static("GetID_", (const Standard_GUID & (*)()) &TDataXtd_Plane::GetID, "class methods =============");
cls_TDataXtd_Plane.def_static("Set_", (opencascade::handle<TDataXtd_Plane> (*)(const TDF_Label &)) &TDataXtd_Plane::Set, "Finds or creates the plane attribute defined by the label label. Warning If you are creating the attribute with this syntax, a planar face should already be associated with label.", py::arg("label"));
cls_TDataXtd_Plane.def_static("Set_", (opencascade::handle<TDataXtd_Plane> (*)(const TDF_Label &, const gp_Pln &)) &TDataXtd_Plane::Set, "Finds, or creates, a Plane attribute and sets <P> as generated the associated NamedShape. Plane methods =============", py::arg("label"), py::arg("P"));
cls_TDataXtd_Plane.def("ID", (const Standard_GUID & (TDataXtd_Plane::*)() const) &TDataXtd_Plane::ID, "None");
cls_TDataXtd_Plane.def("Restore", (void (TDataXtd_Plane::*)(const opencascade::handle<TDF_Attribute> &)) &TDataXtd_Plane::Restore, "None", py::arg("With"));
cls_TDataXtd_Plane.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDataXtd_Plane::*)() const) &TDataXtd_Plane::NewEmpty, "None");
cls_TDataXtd_Plane.def("Paste", (void (TDataXtd_Plane::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDataXtd_Plane::Paste, "None", py::arg("Into"), py::arg("RT"));
cls_TDataXtd_Plane.def("Dump", (Standard_OStream & (TDataXtd_Plane::*)(Standard_OStream &) const) &TDataXtd_Plane::Dump, "None", py::arg("anOS"));
cls_TDataXtd_Plane.def_static("get_type_name_", (const char * (*)()) &TDataXtd_Plane::get_type_name, "None");
cls_TDataXtd_Plane.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataXtd_Plane::get_type_descriptor, "None");
cls_TDataXtd_Plane.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataXtd_Plane::*)() const) &TDataXtd_Plane::DynamicType, "None");

// CLASS: TDATAXTD_PLACEMENT
py::class_<TDataXtd_Placement, opencascade::handle<TDataXtd_Placement>, TDF_Attribute> cls_TDataXtd_Placement(mod, "TDataXtd_Placement", "None");

// Constructors
cls_TDataXtd_Placement.def(py::init<>());

// Methods
cls_TDataXtd_Placement.def_static("GetID_", (const Standard_GUID & (*)()) &TDataXtd_Placement::GetID, "class methods =============");
cls_TDataXtd_Placement.def_static("Set_", (opencascade::handle<TDataXtd_Placement> (*)(const TDF_Label &)) &TDataXtd_Placement::Set, "Find, or create, an Placement attribute. the Placement attribute is returned. Placement methods =================", py::arg("label"));
cls_TDataXtd_Placement.def("ID", (const Standard_GUID & (TDataXtd_Placement::*)() const) &TDataXtd_Placement::ID, "None");
cls_TDataXtd_Placement.def("Restore", (void (TDataXtd_Placement::*)(const opencascade::handle<TDF_Attribute> &)) &TDataXtd_Placement::Restore, "None", py::arg("With"));
cls_TDataXtd_Placement.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDataXtd_Placement::*)() const) &TDataXtd_Placement::NewEmpty, "None");
cls_TDataXtd_Placement.def("Paste", (void (TDataXtd_Placement::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDataXtd_Placement::Paste, "None", py::arg("Into"), py::arg("RT"));
cls_TDataXtd_Placement.def("Dump", (Standard_OStream & (TDataXtd_Placement::*)(Standard_OStream &) const) &TDataXtd_Placement::Dump, "None", py::arg("anOS"));
cls_TDataXtd_Placement.def_static("get_type_name_", (const char * (*)()) &TDataXtd_Placement::get_type_name, "None");
cls_TDataXtd_Placement.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataXtd_Placement::get_type_descriptor, "None");
cls_TDataXtd_Placement.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataXtd_Placement::*)() const) &TDataXtd_Placement::DynamicType, "None");

// CLASS: TDATAXTD_GEOMETRY
py::class_<TDataXtd_Geometry, opencascade::handle<TDataXtd_Geometry>, TDF_Attribute> cls_TDataXtd_Geometry(mod, "TDataXtd_Geometry", "This class is used to model construction geometry. The specific geometric construction of the attribute is defined by an element of the enumeration TDataXtd_GeometryEnum. This attribute may also be used to qualify underlying geometry of the associated NamedShape. for Constructuion element by example.");

// Constructors
cls_TDataXtd_Geometry.def(py::init<>());

// Methods
cls_TDataXtd_Geometry.def_static("Set_", (opencascade::handle<TDataXtd_Geometry> (*)(const TDF_Label &)) &TDataXtd_Geometry::Set, "API class methods ================= Finds, or creates, a Geometry attribute defined by the label label. The default type of geometry is the value ANY_GEOM of the enumeration TDataXtd_GeometryEnum. To specify another value of this enumeration, use the function SetType.", py::arg("label"));
cls_TDataXtd_Geometry.def_static("Type_", (TDataXtd_GeometryEnum (*)(const TDF_Label &)) &TDataXtd_Geometry::Type, "Returns the label L used to define the type of geometric construction for the geometry attribute.", py::arg("L"));
cls_TDataXtd_Geometry.def_static("Type_", (TDataXtd_GeometryEnum (*)(const opencascade::handle<TNaming_NamedShape> &)) &TDataXtd_Geometry::Type, "Returns the topological attribute S used to define the type of geometric construction for the geometry attribute.", py::arg("S"));
cls_TDataXtd_Geometry.def_static("Point_", (Standard_Boolean (*)(const TDF_Label &, gp_Pnt &)) &TDataXtd_Geometry::Point, "Returns the point attribute defined by the label L and the point G.", py::arg("L"), py::arg("G"));
cls_TDataXtd_Geometry.def_static("Point_", (Standard_Boolean (*)(const opencascade::handle<TNaming_NamedShape> &, gp_Pnt &)) &TDataXtd_Geometry::Point, "Returns the point attribute defined by the topological attribute S and the point G.", py::arg("S"), py::arg("G"));
cls_TDataXtd_Geometry.def_static("Axis_", (Standard_Boolean (*)(const TDF_Label &, gp_Ax1 &)) &TDataXtd_Geometry::Axis, "Returns the axis attribute defined by the label L and the axis G.", py::arg("L"), py::arg("G"));
cls_TDataXtd_Geometry.def_static("Axis_", (Standard_Boolean (*)(const opencascade::handle<TNaming_NamedShape> &, gp_Ax1 &)) &TDataXtd_Geometry::Axis, "Returns the axis attribute defined by the topological attribute S and the axis G.", py::arg("S"), py::arg("G"));
cls_TDataXtd_Geometry.def_static("Line_", (Standard_Boolean (*)(const TDF_Label &, gp_Lin &)) &TDataXtd_Geometry::Line, "Returns the line attribute defined by the label L and the line G.", py::arg("L"), py::arg("G"));
cls_TDataXtd_Geometry.def_static("Line_", (Standard_Boolean (*)(const opencascade::handle<TNaming_NamedShape> &, gp_Lin &)) &TDataXtd_Geometry::Line, "Returns the line attribute defined by the topological attribute S and the line G.", py::arg("S"), py::arg("G"));
cls_TDataXtd_Geometry.def_static("Circle_", (Standard_Boolean (*)(const TDF_Label &, gp_Circ &)) &TDataXtd_Geometry::Circle, "Returns the circle attribute defined by the label L and the circle G.", py::arg("L"), py::arg("G"));
cls_TDataXtd_Geometry.def_static("Circle_", (Standard_Boolean (*)(const opencascade::handle<TNaming_NamedShape> &, gp_Circ &)) &TDataXtd_Geometry::Circle, "Returns the circle attribute defined by the topological attribute S and the circle G.", py::arg("S"), py::arg("G"));
cls_TDataXtd_Geometry.def_static("Ellipse_", (Standard_Boolean (*)(const TDF_Label &, gp_Elips &)) &TDataXtd_Geometry::Ellipse, "Returns the ellipse attribute defined by the label L and the ellipse G.", py::arg("L"), py::arg("G"));
cls_TDataXtd_Geometry.def_static("Ellipse_", (Standard_Boolean (*)(const opencascade::handle<TNaming_NamedShape> &, gp_Elips &)) &TDataXtd_Geometry::Ellipse, "Returns the ellipse attribute defined by the topological attribute S and the ellipse G.", py::arg("S"), py::arg("G"));
cls_TDataXtd_Geometry.def_static("Plane_", (Standard_Boolean (*)(const TDF_Label &, gp_Pln &)) &TDataXtd_Geometry::Plane, "Returns the plane attribute defined by the label L and the plane G.", py::arg("L"), py::arg("G"));
cls_TDataXtd_Geometry.def_static("Plane_", (Standard_Boolean (*)(const opencascade::handle<TNaming_NamedShape> &, gp_Pln &)) &TDataXtd_Geometry::Plane, "Returns the plane attribute defined by the topological attribute S and the plane G.", py::arg("S"), py::arg("G"));
cls_TDataXtd_Geometry.def_static("Cylinder_", (Standard_Boolean (*)(const TDF_Label &, gp_Cylinder &)) &TDataXtd_Geometry::Cylinder, "Returns the cylinder attribute defined by the label L and the cylinder G.", py::arg("L"), py::arg("G"));
cls_TDataXtd_Geometry.def_static("Cylinder_", (Standard_Boolean (*)(const opencascade::handle<TNaming_NamedShape> &, gp_Cylinder &)) &TDataXtd_Geometry::Cylinder, "Returns the cylinder attribute defined by the topological attribute S and the cylinder G.", py::arg("S"), py::arg("G"));
cls_TDataXtd_Geometry.def_static("GetID_", (const Standard_GUID & (*)()) &TDataXtd_Geometry::GetID, "Returns the GUID for geometry attributes.");
cls_TDataXtd_Geometry.def("SetType", (void (TDataXtd_Geometry::*)(const TDataXtd_GeometryEnum)) &TDataXtd_Geometry::SetType, "Returns the type of geometric construction T of this attribute. T will be a value of the enumeration TDataXtd_GeometryEnum.", py::arg("T"));
cls_TDataXtd_Geometry.def("GetType", (TDataXtd_GeometryEnum (TDataXtd_Geometry::*)() const) &TDataXtd_Geometry::GetType, "Returns the type of geometric construction.");
cls_TDataXtd_Geometry.def("ID", (const Standard_GUID & (TDataXtd_Geometry::*)() const) &TDataXtd_Geometry::ID, "None");
cls_TDataXtd_Geometry.def("Restore", (void (TDataXtd_Geometry::*)(const opencascade::handle<TDF_Attribute> &)) &TDataXtd_Geometry::Restore, "None", py::arg("with"));
cls_TDataXtd_Geometry.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDataXtd_Geometry::*)() const) &TDataXtd_Geometry::NewEmpty, "None");
cls_TDataXtd_Geometry.def("Paste", (void (TDataXtd_Geometry::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDataXtd_Geometry::Paste, "None", py::arg("into"), py::arg("RT"));
cls_TDataXtd_Geometry.def("Dump", (Standard_OStream & (TDataXtd_Geometry::*)(Standard_OStream &) const) &TDataXtd_Geometry::Dump, "None", py::arg("anOS"));
cls_TDataXtd_Geometry.def_static("get_type_name_", (const char * (*)()) &TDataXtd_Geometry::get_type_name, "None");
cls_TDataXtd_Geometry.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataXtd_Geometry::get_type_descriptor, "None");
cls_TDataXtd_Geometry.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataXtd_Geometry::*)() const) &TDataXtd_Geometry::DynamicType, "None");

// CLASS: TDATAXTD_POSITION
py::class_<TDataXtd_Position, opencascade::handle<TDataXtd_Position>, TDF_Attribute> cls_TDataXtd_Position(mod, "TDataXtd_Position", "Position of a Label");

// Constructors
cls_TDataXtd_Position.def(py::init<>());

// Methods
cls_TDataXtd_Position.def_static("Set_", (void (*)(const TDF_Label &, const gp_Pnt &)) &TDataXtd_Position::Set, "Create if not found the TDataXtd_Position attribute set its position to <aPos>", py::arg("aLabel"), py::arg("aPos"));
cls_TDataXtd_Position.def_static("Set_", (opencascade::handle<TDataXtd_Position> (*)(const TDF_Label &)) &TDataXtd_Position::Set, "Find an existing, or create an empty, Position. the Position attribute is returned.", py::arg("aLabel"));
cls_TDataXtd_Position.def_static("Get_", (Standard_Boolean (*)(const TDF_Label &, gp_Pnt &)) &TDataXtd_Position::Get, "Search label <aLabel) for the TDataXtd_Position attribute and get its position if found returns True", py::arg("aLabel"), py::arg("aPos"));
cls_TDataXtd_Position.def("ID", (const Standard_GUID & (TDataXtd_Position::*)() const) &TDataXtd_Position::ID, "Returns the ID of the attribute.");
cls_TDataXtd_Position.def_static("GetID_", (const Standard_GUID & (*)()) &TDataXtd_Position::GetID, "Returns the ID of the attribute.");
cls_TDataXtd_Position.def("Restore", (void (TDataXtd_Position::*)(const opencascade::handle<TDF_Attribute> &)) &TDataXtd_Position::Restore, "Restores the contents from <anAttribute> into this one. It is used when aborting a transaction.", py::arg("anAttribute"));
cls_TDataXtd_Position.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDataXtd_Position::*)() const) &TDataXtd_Position::NewEmpty, "Returns an new empty attribute from the good end type. It is used by the copy algorithm.");
cls_TDataXtd_Position.def("Paste", (void (TDataXtd_Position::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDataXtd_Position::Paste, "This method is different from the 'Copy' one, because it is used when copying an attribute from a source structure into a target structure. This method pastes the current attribute to the label corresponding to the insertor. The pasted attribute may be a brand new one or a new version of the previous one.", py::arg("intoAttribute"), py::arg("aRelocTationable"));
cls_TDataXtd_Position.def("GetPosition", (const gp_Pnt & (TDataXtd_Position::*)() const) &TDataXtd_Position::GetPosition, "None");
cls_TDataXtd_Position.def("SetPosition", (void (TDataXtd_Position::*)(const gp_Pnt &)) &TDataXtd_Position::SetPosition, "None", py::arg("aPos"));
cls_TDataXtd_Position.def_static("get_type_name_", (const char * (*)()) &TDataXtd_Position::get_type_name, "None");
cls_TDataXtd_Position.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataXtd_Position::get_type_descriptor, "None");
cls_TDataXtd_Position.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataXtd_Position::*)() const) &TDataXtd_Position::DynamicType, "None");

// CLASS: TDATAXTD_CONSTRAINT
py::class_<TDataXtd_Constraint, opencascade::handle<TDataXtd_Constraint>, TDF_Attribute> cls_TDataXtd_Constraint(mod, "TDataXtd_Constraint", "The groundwork to define constraint attributes. The constraint attribute contains the following sorts of data: - Type whether the constraint attribute is a geometric constraint or a dimension - Value the real number value of a numeric constraint such as an angle or a radius - Geometries to identify the geometries underlying the topological attributes which define the constraint (up to 4) - Plane for 2D constraints.");

// Constructors
cls_TDataXtd_Constraint.def(py::init<>());

// Methods
cls_TDataXtd_Constraint.def_static("GetID_", (const Standard_GUID & (*)()) &TDataXtd_Constraint::GetID, "Returns the GUID for constraints.");
cls_TDataXtd_Constraint.def_static("Set_", (opencascade::handle<TDataXtd_Constraint> (*)(const TDF_Label &)) &TDataXtd_Constraint::Set, "Finds or creates the 2D constraint attribute defined by the planar topological attribute plane and the label label. Constraint methods ==================", py::arg("label"));
cls_TDataXtd_Constraint.def("Set", (void (TDataXtd_Constraint::*)(const TDataXtd_ConstraintEnum, const opencascade::handle<TNaming_NamedShape> &)) &TDataXtd_Constraint::Set, "Finds or creates the constraint attribute defined by the topological attribute G1 and the constraint type type.", py::arg("type"), py::arg("G1"));
cls_TDataXtd_Constraint.def("Set", (void (TDataXtd_Constraint::*)(const TDataXtd_ConstraintEnum, const opencascade::handle<TNaming_NamedShape> &, const opencascade::handle<TNaming_NamedShape> &)) &TDataXtd_Constraint::Set, "Finds or creates the constraint attribute defined by the topological attributes G1 and G2, and by the constraint type type.", py::arg("type"), py::arg("G1"), py::arg("G2"));
cls_TDataXtd_Constraint.def("Set", (void (TDataXtd_Constraint::*)(const TDataXtd_ConstraintEnum, const opencascade::handle<TNaming_NamedShape> &, const opencascade::handle<TNaming_NamedShape> &, const opencascade::handle<TNaming_NamedShape> &)) &TDataXtd_Constraint::Set, "Finds or creates the constraint attribute defined by the topological attributes G1, G2 and G3, and by the constraint type type.", py::arg("type"), py::arg("G1"), py::arg("G2"), py::arg("G3"));
cls_TDataXtd_Constraint.def("Set", (void (TDataXtd_Constraint::*)(const TDataXtd_ConstraintEnum, const opencascade::handle<TNaming_NamedShape> &, const opencascade::handle<TNaming_NamedShape> &, const opencascade::handle<TNaming_NamedShape> &, const opencascade::handle<TNaming_NamedShape> &)) &TDataXtd_Constraint::Set, "Finds or creates the constraint attribute defined by the topological attributes G1, G2, G3 and G4, and by the constraint type type. methods to read constraint fields =================================", py::arg("type"), py::arg("G1"), py::arg("G2"), py::arg("G3"), py::arg("G4"));
cls_TDataXtd_Constraint.def("Verified", (Standard_Boolean (TDataXtd_Constraint::*)() const) &TDataXtd_Constraint::Verified, "Returns true if this constraint attribute is valid. By default, true is returned. When the value of a dimension is changed or when a geometry is moved, false is returned until the solver sets it back to true.");
cls_TDataXtd_Constraint.def("GetType", (TDataXtd_ConstraintEnum (TDataXtd_Constraint::*)() const) &TDataXtd_Constraint::GetType, "Returns the type of constraint. This will be an element of the TDataXtd_ConstraintEnum enumeration.");
cls_TDataXtd_Constraint.def("IsPlanar", (Standard_Boolean (TDataXtd_Constraint::*)() const) &TDataXtd_Constraint::IsPlanar, "Returns true if this constraint attribute is two-dimensional.");
cls_TDataXtd_Constraint.def("GetPlane", (const opencascade::handle<TNaming_NamedShape> & (TDataXtd_Constraint::*)() const) &TDataXtd_Constraint::GetPlane, "Returns the topological attribute of the plane used for planar - i.e., 2D - constraints. This plane is attached to another label. If the constraint is not planar, in other words, 3D, this function will return a null handle.");
cls_TDataXtd_Constraint.def("IsDimension", (Standard_Boolean (TDataXtd_Constraint::*)() const) &TDataXtd_Constraint::IsDimension, "Returns true if this constraint attribute is a dimension, and therefore has a value.");
cls_TDataXtd_Constraint.def("GetValue", (const opencascade::handle<TDataStd_Real> & (TDataXtd_Constraint::*)() const) &TDataXtd_Constraint::GetValue, "Returns the value of a dimension. This value is a reference to a TDataStd_Real attribute. If the attribute is not a dimension, this value will be 0. Use IsDimension to test this condition.");
cls_TDataXtd_Constraint.def("NbGeometries", (Standard_Integer (TDataXtd_Constraint::*)() const) &TDataXtd_Constraint::NbGeometries, "Returns the number of geometry attributes in this constraint attribute. This number will be between 1 and 4.");
cls_TDataXtd_Constraint.def("GetGeometry", (opencascade::handle<TNaming_NamedShape> (TDataXtd_Constraint::*)(const Standard_Integer) const) &TDataXtd_Constraint::GetGeometry, "Returns the integer index Index used to access the array of the constraint or stored geometries of a dimension Index has a value between 1 and 4. methods to write constraint fields (use builder) ==================================", py::arg("Index"));
cls_TDataXtd_Constraint.def("ClearGeometries", (void (TDataXtd_Constraint::*)()) &TDataXtd_Constraint::ClearGeometries, "Removes the geometries involved in the constraint or dimension from the array of topological attributes where they are stored.");
cls_TDataXtd_Constraint.def("SetType", (void (TDataXtd_Constraint::*)(const TDataXtd_ConstraintEnum)) &TDataXtd_Constraint::SetType, "Finds or creates the type of constraint CTR.", py::arg("CTR"));
cls_TDataXtd_Constraint.def("SetPlane", (void (TDataXtd_Constraint::*)(const opencascade::handle<TNaming_NamedShape> &)) &TDataXtd_Constraint::SetPlane, "Finds or creates the plane of the 2D constraint attribute, defined by the planar topological attribute plane.", py::arg("plane"));
cls_TDataXtd_Constraint.def("SetValue", (void (TDataXtd_Constraint::*)(const opencascade::handle<TDataStd_Real> &)) &TDataXtd_Constraint::SetValue, "Finds or creates the real number value V of the dimension constraint attribute.", py::arg("V"));
cls_TDataXtd_Constraint.def("SetGeometry", (void (TDataXtd_Constraint::*)(const Standard_Integer, const opencascade::handle<TNaming_NamedShape> &)) &TDataXtd_Constraint::SetGeometry, "Finds or creates the underlying geometry of the constraint defined by the topological attribute G and the integer index Index.", py::arg("Index"), py::arg("G"));
cls_TDataXtd_Constraint.def("Verified", (void (TDataXtd_Constraint::*)(const Standard_Boolean)) &TDataXtd_Constraint::Verified, "Returns true if this constraint attribute defined by status is valid. By default, true is returned. When the value of a dimension is changed or when a geometry is moved, false is returned until the solver sets it back to true. If status is false, Verified is set to false.", py::arg("status"));
cls_TDataXtd_Constraint.def("Inverted", (void (TDataXtd_Constraint::*)(const Standard_Boolean)) &TDataXtd_Constraint::Inverted, "None", py::arg("status"));
cls_TDataXtd_Constraint.def("Inverted", (Standard_Boolean (TDataXtd_Constraint::*)() const) &TDataXtd_Constraint::Inverted, "None");
cls_TDataXtd_Constraint.def("Reversed", (void (TDataXtd_Constraint::*)(const Standard_Boolean)) &TDataXtd_Constraint::Reversed, "None", py::arg("status"));
cls_TDataXtd_Constraint.def("Reversed", (Standard_Boolean (TDataXtd_Constraint::*)() const) &TDataXtd_Constraint::Reversed, "None");
cls_TDataXtd_Constraint.def_static("CollectChildConstraints_", (void (*)(const TDF_Label &, TDF_LabelList &)) &TDataXtd_Constraint::CollectChildConstraints, "collects constraints on Childs for label <aLabel>", py::arg("aLabel"), py::arg("TheList"));
cls_TDataXtd_Constraint.def("ID", (const Standard_GUID & (TDataXtd_Constraint::*)() const) &TDataXtd_Constraint::ID, "None");
cls_TDataXtd_Constraint.def("Restore", (void (TDataXtd_Constraint::*)(const opencascade::handle<TDF_Attribute> &)) &TDataXtd_Constraint::Restore, "None", py::arg("With"));
cls_TDataXtd_Constraint.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDataXtd_Constraint::*)() const) &TDataXtd_Constraint::NewEmpty, "None");
cls_TDataXtd_Constraint.def("Paste", (void (TDataXtd_Constraint::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDataXtd_Constraint::Paste, "None", py::arg("Into"), py::arg("RT"));
cls_TDataXtd_Constraint.def("Dump", (Standard_OStream & (TDataXtd_Constraint::*)(Standard_OStream &) const) &TDataXtd_Constraint::Dump, "None", py::arg("anOS"));
cls_TDataXtd_Constraint.def("References", (void (TDataXtd_Constraint::*)(const opencascade::handle<TDF_DataSet> &) const) &TDataXtd_Constraint::References, "None", py::arg("DS"));
cls_TDataXtd_Constraint.def_static("get_type_name_", (const char * (*)()) &TDataXtd_Constraint::get_type_name, "None");
cls_TDataXtd_Constraint.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataXtd_Constraint::get_type_descriptor, "None");
cls_TDataXtd_Constraint.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataXtd_Constraint::*)() const) &TDataXtd_Constraint::DynamicType, "None");

// TYPEDEF: TDATAXTD_ARRAY1OFTRSF
bind_NCollection_Array1<gp_Trsf>(mod, "TDataXtd_Array1OfTrsf", py::module_local(false));

// CLASS: TDATAXTD_PATTERN
py::class_<TDataXtd_Pattern, opencascade::handle<TDataXtd_Pattern>, TDF_Attribute> cls_TDataXtd_Pattern(mod, "TDataXtd_Pattern", "a general pattern model");

// Methods
cls_TDataXtd_Pattern.def_static("GetID_", (const Standard_GUID & (*)()) &TDataXtd_Pattern::GetID, "None");
cls_TDataXtd_Pattern.def("ID", (const Standard_GUID & (TDataXtd_Pattern::*)() const) &TDataXtd_Pattern::ID, "Returns the ID of the attribute.");
cls_TDataXtd_Pattern.def("PatternID", (const Standard_GUID & (TDataXtd_Pattern::*)() const) &TDataXtd_Pattern::PatternID, "Returns the ID of the attribute.");
cls_TDataXtd_Pattern.def("NbTrsfs", (Standard_Integer (TDataXtd_Pattern::*)() const) &TDataXtd_Pattern::NbTrsfs, "Give the number of transformation");
cls_TDataXtd_Pattern.def("ComputeTrsfs", (void (TDataXtd_Pattern::*)(TDataXtd_Array1OfTrsf &) const) &TDataXtd_Pattern::ComputeTrsfs, "Give the transformations", py::arg("Trsfs"));
cls_TDataXtd_Pattern.def_static("get_type_name_", (const char * (*)()) &TDataXtd_Pattern::get_type_name, "None");
cls_TDataXtd_Pattern.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataXtd_Pattern::get_type_descriptor, "None");
cls_TDataXtd_Pattern.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataXtd_Pattern::*)() const) &TDataXtd_Pattern::DynamicType, "None");

// CLASS: TDATAXTD_PATTERNSTD
py::class_<TDataXtd_PatternStd, opencascade::handle<TDataXtd_PatternStd>, TDataXtd_Pattern> cls_TDataXtd_PatternStd(mod, "TDataXtd_PatternStd", "to create a PatternStd (LinearPattern, CircularPattern, RectangularPattern, RadialCircularPattern, MirrorPattern)");

// Constructors
cls_TDataXtd_PatternStd.def(py::init<>());

// Methods
cls_TDataXtd_PatternStd.def_static("GetPatternID_", (const Standard_GUID & (*)()) &TDataXtd_PatternStd::GetPatternID, "None");
cls_TDataXtd_PatternStd.def_static("Set_", (opencascade::handle<TDataXtd_PatternStd> (*)(const TDF_Label &)) &TDataXtd_PatternStd::Set, "Find, or create, a PatternStd attribute", py::arg("label"));
cls_TDataXtd_PatternStd.def("Signature", (void (TDataXtd_PatternStd::*)(const Standard_Integer)) &TDataXtd_PatternStd::Signature, "None", py::arg("signature"));
cls_TDataXtd_PatternStd.def("Axis1", (void (TDataXtd_PatternStd::*)(const opencascade::handle<TNaming_NamedShape> &)) &TDataXtd_PatternStd::Axis1, "None", py::arg("Axis1"));
cls_TDataXtd_PatternStd.def("Axis2", (void (TDataXtd_PatternStd::*)(const opencascade::handle<TNaming_NamedShape> &)) &TDataXtd_PatternStd::Axis2, "None", py::arg("Axis2"));
cls_TDataXtd_PatternStd.def("Axis1Reversed", (void (TDataXtd_PatternStd::*)(const Standard_Boolean)) &TDataXtd_PatternStd::Axis1Reversed, "None", py::arg("Axis1Reversed"));
cls_TDataXtd_PatternStd.def("Axis2Reversed", (void (TDataXtd_PatternStd::*)(const Standard_Boolean)) &TDataXtd_PatternStd::Axis2Reversed, "None", py::arg("Axis2Reversed"));
cls_TDataXtd_PatternStd.def("Value1", (void (TDataXtd_PatternStd::*)(const opencascade::handle<TDataStd_Real> &)) &TDataXtd_PatternStd::Value1, "None", py::arg("value"));
cls_TDataXtd_PatternStd.def("Value2", (void (TDataXtd_PatternStd::*)(const opencascade::handle<TDataStd_Real> &)) &TDataXtd_PatternStd::Value2, "None", py::arg("value"));
cls_TDataXtd_PatternStd.def("NbInstances1", (void (TDataXtd_PatternStd::*)(const opencascade::handle<TDataStd_Integer> &)) &TDataXtd_PatternStd::NbInstances1, "None", py::arg("NbInstances1"));
cls_TDataXtd_PatternStd.def("NbInstances2", (void (TDataXtd_PatternStd::*)(const opencascade::handle<TDataStd_Integer> &)) &TDataXtd_PatternStd::NbInstances2, "None", py::arg("NbInstances2"));
cls_TDataXtd_PatternStd.def("Mirror", (void (TDataXtd_PatternStd::*)(const opencascade::handle<TNaming_NamedShape> &)) &TDataXtd_PatternStd::Mirror, "None", py::arg("plane"));
cls_TDataXtd_PatternStd.def("Signature", (Standard_Integer (TDataXtd_PatternStd::*)() const) &TDataXtd_PatternStd::Signature, "None");
cls_TDataXtd_PatternStd.def("Axis1", (opencascade::handle<TNaming_NamedShape> (TDataXtd_PatternStd::*)() const) &TDataXtd_PatternStd::Axis1, "None");
cls_TDataXtd_PatternStd.def("Axis2", (opencascade::handle<TNaming_NamedShape> (TDataXtd_PatternStd::*)() const) &TDataXtd_PatternStd::Axis2, "None");
cls_TDataXtd_PatternStd.def("Axis1Reversed", (Standard_Boolean (TDataXtd_PatternStd::*)() const) &TDataXtd_PatternStd::Axis1Reversed, "None");
cls_TDataXtd_PatternStd.def("Axis2Reversed", (Standard_Boolean (TDataXtd_PatternStd::*)() const) &TDataXtd_PatternStd::Axis2Reversed, "None");
cls_TDataXtd_PatternStd.def("Value1", (opencascade::handle<TDataStd_Real> (TDataXtd_PatternStd::*)() const) &TDataXtd_PatternStd::Value1, "None");
cls_TDataXtd_PatternStd.def("Value2", (opencascade::handle<TDataStd_Real> (TDataXtd_PatternStd::*)() const) &TDataXtd_PatternStd::Value2, "None");
cls_TDataXtd_PatternStd.def("NbInstances1", (opencascade::handle<TDataStd_Integer> (TDataXtd_PatternStd::*)() const) &TDataXtd_PatternStd::NbInstances1, "None");
cls_TDataXtd_PatternStd.def("NbInstances2", (opencascade::handle<TDataStd_Integer> (TDataXtd_PatternStd::*)() const) &TDataXtd_PatternStd::NbInstances2, "None");
cls_TDataXtd_PatternStd.def("Mirror", (opencascade::handle<TNaming_NamedShape> (TDataXtd_PatternStd::*)() const) &TDataXtd_PatternStd::Mirror, "None");
cls_TDataXtd_PatternStd.def("NbTrsfs", (Standard_Integer (TDataXtd_PatternStd::*)() const) &TDataXtd_PatternStd::NbTrsfs, "None");
cls_TDataXtd_PatternStd.def("ComputeTrsfs", (void (TDataXtd_PatternStd::*)(TDataXtd_Array1OfTrsf &) const) &TDataXtd_PatternStd::ComputeTrsfs, "None", py::arg("Trsfs"));
cls_TDataXtd_PatternStd.def("PatternID", (const Standard_GUID & (TDataXtd_PatternStd::*)() const) &TDataXtd_PatternStd::PatternID, "None");
cls_TDataXtd_PatternStd.def("Restore", (void (TDataXtd_PatternStd::*)(const opencascade::handle<TDF_Attribute> &)) &TDataXtd_PatternStd::Restore, "None", py::arg("With"));
cls_TDataXtd_PatternStd.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDataXtd_PatternStd::*)() const) &TDataXtd_PatternStd::NewEmpty, "None");
cls_TDataXtd_PatternStd.def("Paste", (void (TDataXtd_PatternStd::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDataXtd_PatternStd::Paste, "None", py::arg("Into"), py::arg("RT"));
cls_TDataXtd_PatternStd.def("References", (void (TDataXtd_PatternStd::*)(const opencascade::handle<TDF_DataSet> &) const) &TDataXtd_PatternStd::References, "None", py::arg("aDataSet"));
cls_TDataXtd_PatternStd.def("Dump", (Standard_OStream & (TDataXtd_PatternStd::*)(Standard_OStream &) const) &TDataXtd_PatternStd::Dump, "None", py::arg("anOS"));
cls_TDataXtd_PatternStd.def_static("get_type_name_", (const char * (*)()) &TDataXtd_PatternStd::get_type_name, "None");
cls_TDataXtd_PatternStd.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataXtd_PatternStd::get_type_descriptor, "None");
cls_TDataXtd_PatternStd.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataXtd_PatternStd::*)() const) &TDataXtd_PatternStd::DynamicType, "None");

// CLASS: TDATAXTD_PRESENTATION
py::class_<TDataXtd_Presentation, opencascade::handle<TDataXtd_Presentation>, TDF_Attribute> cls_TDataXtd_Presentation(mod, "TDataXtd_Presentation", "Attribute containing parameters of presentation of the shape, e.g. the shape attached to the same label and displayed using TPrsStd tools (see TPrsStd_AISPresentation).");

// Constructors
cls_TDataXtd_Presentation.def(py::init<>());

// Methods
cls_TDataXtd_Presentation.def_static("Set_", (opencascade::handle<TDataXtd_Presentation> (*)(const TDF_Label &, const Standard_GUID &)) &TDataXtd_Presentation::Set, "Create if not found the TDataXtd_Presentation attribute and set its driver GUID", py::arg("theLabel"), py::arg("theDriverId"));
cls_TDataXtd_Presentation.def_static("Unset_", (void (*)(const TDF_Label &)) &TDataXtd_Presentation::Unset, "Remove attribute of this type from the label", py::arg("theLabel"));
cls_TDataXtd_Presentation.def("ID", (const Standard_GUID & (TDataXtd_Presentation::*)() const) &TDataXtd_Presentation::ID, "Returns the ID of the attribute.");
cls_TDataXtd_Presentation.def_static("GetID_", (const Standard_GUID & (*)()) &TDataXtd_Presentation::GetID, "Returns the ID of the attribute.");
cls_TDataXtd_Presentation.def("Restore", (void (TDataXtd_Presentation::*)(const opencascade::handle<TDF_Attribute> &)) &TDataXtd_Presentation::Restore, "Restores the contents from <anAttribute> into this one. It is used when aborting a transaction.", py::arg("anAttribute"));
cls_TDataXtd_Presentation.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDataXtd_Presentation::*)() const) &TDataXtd_Presentation::NewEmpty, "Returns an new empty attribute from the good end type. It is used by the copy algorithm.");
cls_TDataXtd_Presentation.def("Paste", (void (TDataXtd_Presentation::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDataXtd_Presentation::Paste, "This method is different from the 'Copy' one, because it is used when copying an attribute from a source structure into a target structure. This method pastes the current attribute to the label corresponding to the insertor. The pasted attribute may be a brand new one or a new version of the previous one.", py::arg("intoAttribute"), py::arg("aRelocTationable"));
cls_TDataXtd_Presentation.def("BackupCopy", (opencascade::handle<TDF_Attribute> (TDataXtd_Presentation::*)() const) &TDataXtd_Presentation::BackupCopy, "None");
cls_TDataXtd_Presentation.def_static("get_type_name_", (const char * (*)()) &TDataXtd_Presentation::get_type_name, "None");
cls_TDataXtd_Presentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataXtd_Presentation::get_type_descriptor, "None");
cls_TDataXtd_Presentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataXtd_Presentation::*)() const) &TDataXtd_Presentation::DynamicType, "None");
cls_TDataXtd_Presentation.def("GetDriverGUID", (Standard_GUID (TDataXtd_Presentation::*)() const) &TDataXtd_Presentation::GetDriverGUID, "Returns the GUID of the driver managing display of associated AIS object");
cls_TDataXtd_Presentation.def("SetDriverGUID", (void (TDataXtd_Presentation::*)(const Standard_GUID &)) &TDataXtd_Presentation::SetDriverGUID, "Sets the GUID of the driver managing display of associated AIS object", py::arg("theGUID"));
cls_TDataXtd_Presentation.def("IsDisplayed", (Standard_Boolean (TDataXtd_Presentation::*)() const) &TDataXtd_Presentation::IsDisplayed, "None");
cls_TDataXtd_Presentation.def("HasOwnMaterial", (Standard_Boolean (TDataXtd_Presentation::*)() const) &TDataXtd_Presentation::HasOwnMaterial, "None");
cls_TDataXtd_Presentation.def("HasOwnTransparency", (Standard_Boolean (TDataXtd_Presentation::*)() const) &TDataXtd_Presentation::HasOwnTransparency, "None");
cls_TDataXtd_Presentation.def("HasOwnColor", (Standard_Boolean (TDataXtd_Presentation::*)() const) &TDataXtd_Presentation::HasOwnColor, "None");
cls_TDataXtd_Presentation.def("HasOwnWidth", (Standard_Boolean (TDataXtd_Presentation::*)() const) &TDataXtd_Presentation::HasOwnWidth, "None");
cls_TDataXtd_Presentation.def("HasOwnMode", (Standard_Boolean (TDataXtd_Presentation::*)() const) &TDataXtd_Presentation::HasOwnMode, "None");
cls_TDataXtd_Presentation.def("HasOwnSelectionMode", (Standard_Boolean (TDataXtd_Presentation::*)() const) &TDataXtd_Presentation::HasOwnSelectionMode, "None");
cls_TDataXtd_Presentation.def("SetDisplayed", (void (TDataXtd_Presentation::*)(const Standard_Boolean)) &TDataXtd_Presentation::SetDisplayed, "None", py::arg("theIsDisplayed"));
cls_TDataXtd_Presentation.def("SetMaterialIndex", (void (TDataXtd_Presentation::*)(const Standard_Integer)) &TDataXtd_Presentation::SetMaterialIndex, "None", py::arg("theMaterialIndex"));
cls_TDataXtd_Presentation.def("SetTransparency", (void (TDataXtd_Presentation::*)(const Standard_Real)) &TDataXtd_Presentation::SetTransparency, "None", py::arg("theValue"));
cls_TDataXtd_Presentation.def("SetColor", (void (TDataXtd_Presentation::*)(const Quantity_NameOfColor)) &TDataXtd_Presentation::SetColor, "None", py::arg("theColor"));
cls_TDataXtd_Presentation.def("SetWidth", (void (TDataXtd_Presentation::*)(const Standard_Real)) &TDataXtd_Presentation::SetWidth, "None", py::arg("theWidth"));
cls_TDataXtd_Presentation.def("SetMode", (void (TDataXtd_Presentation::*)(const Standard_Integer)) &TDataXtd_Presentation::SetMode, "None", py::arg("theMode"));
cls_TDataXtd_Presentation.def("GetNbSelectionModes", (Standard_Integer (TDataXtd_Presentation::*)() const) &TDataXtd_Presentation::GetNbSelectionModes, "Returns the number of selection modes of the attribute. It starts with 1 .. GetNbSelectionModes().");
cls_TDataXtd_Presentation.def("SetSelectionMode", [](TDataXtd_Presentation &self, const Standard_Integer a0) -> void { return self.SetSelectionMode(a0); });
cls_TDataXtd_Presentation.def("SetSelectionMode", (void (TDataXtd_Presentation::*)(const Standard_Integer, const Standard_Boolean)) &TDataXtd_Presentation::SetSelectionMode, "Sets selection mode. If 'theTransaction' flag is OFF, modification of the attribute doesn't influence the transaction mechanism (the attribute doesn't participate in undo/redo because of this modification). Certainly, if any other data of the attribute is modified (display mode, color, ...), the attribute will be included into undo/redo.", py::arg("theSelectionMode"), py::arg("theTransaction"));
cls_TDataXtd_Presentation.def("AddSelectionMode", [](TDataXtd_Presentation &self, const Standard_Integer a0) -> void { return self.AddSelectionMode(a0); });
cls_TDataXtd_Presentation.def("AddSelectionMode", (void (TDataXtd_Presentation::*)(const Standard_Integer, const Standard_Boolean)) &TDataXtd_Presentation::AddSelectionMode, "None", py::arg("theSelectionMode"), py::arg("theTransaction"));
cls_TDataXtd_Presentation.def("MaterialIndex", (Standard_Integer (TDataXtd_Presentation::*)() const) &TDataXtd_Presentation::MaterialIndex, "None");
cls_TDataXtd_Presentation.def("Transparency", (Standard_Real (TDataXtd_Presentation::*)() const) &TDataXtd_Presentation::Transparency, "None");
cls_TDataXtd_Presentation.def("Color", (Quantity_NameOfColor (TDataXtd_Presentation::*)() const) &TDataXtd_Presentation::Color, "None");
cls_TDataXtd_Presentation.def("Width", (Standard_Real (TDataXtd_Presentation::*)() const) &TDataXtd_Presentation::Width, "None");
cls_TDataXtd_Presentation.def("Mode", (Standard_Integer (TDataXtd_Presentation::*)() const) &TDataXtd_Presentation::Mode, "None");
cls_TDataXtd_Presentation.def("SelectionMode", [](TDataXtd_Presentation &self) -> Standard_Integer { return self.SelectionMode(); });
cls_TDataXtd_Presentation.def("SelectionMode", (Standard_Integer (TDataXtd_Presentation::*)(const int) const) &TDataXtd_Presentation::SelectionMode, "None", py::arg("index"));
cls_TDataXtd_Presentation.def("UnsetMaterial", (void (TDataXtd_Presentation::*)()) &TDataXtd_Presentation::UnsetMaterial, "None");
cls_TDataXtd_Presentation.def("UnsetTransparency", (void (TDataXtd_Presentation::*)()) &TDataXtd_Presentation::UnsetTransparency, "None");
cls_TDataXtd_Presentation.def("UnsetColor", (void (TDataXtd_Presentation::*)()) &TDataXtd_Presentation::UnsetColor, "None");
cls_TDataXtd_Presentation.def("UnsetWidth", (void (TDataXtd_Presentation::*)()) &TDataXtd_Presentation::UnsetWidth, "None");
cls_TDataXtd_Presentation.def("UnsetMode", (void (TDataXtd_Presentation::*)()) &TDataXtd_Presentation::UnsetMode, "None");
cls_TDataXtd_Presentation.def("UnsetSelectionMode", (void (TDataXtd_Presentation::*)()) &TDataXtd_Presentation::UnsetSelectionMode, "None");

// CLASS: TDATAXTD
py::class_<TDataXtd> cls_TDataXtd(mod, "TDataXtd", "This package defines extension of standard attributes for modelling (mainly for work with geometry).");

// Constructors
cls_TDataXtd.def(py::init<>());

// Methods
// cls_TDataXtd.def_static("operator new_", (void * (*)(size_t)) &TDataXtd::operator new, "None", py::arg("theSize"));
// cls_TDataXtd.def_static("operator delete_", (void (*)(void *)) &TDataXtd::operator delete, "None", py::arg("theAddress"));
// cls_TDataXtd.def_static("operator new[]_", (void * (*)(size_t)) &TDataXtd::operator new[], "None", py::arg("theSize"));
// cls_TDataXtd.def_static("operator delete[]_", (void (*)(void *)) &TDataXtd::operator delete[], "None", py::arg("theAddress"));
// cls_TDataXtd.def_static("operator new_", (void * (*)(size_t, void *)) &TDataXtd::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TDataXtd.def_static("operator delete_", (void (*)(void *, void *)) &TDataXtd::operator delete, "None", py::arg(""), py::arg(""));
cls_TDataXtd.def_static("IDList_", (void (*)(TDF_IDList &)) &TDataXtd::IDList, "Appends to <anIDList> the list of the attributes IDs of this package. CAUTION: <anIDList> is NOT cleared before use. Print of TDataExt enumeration =============================", py::arg("anIDList"));
cls_TDataXtd.def_static("Print_", (Standard_OStream & (*)(const TDataXtd_GeometryEnum, Standard_OStream &)) &TDataXtd::Print, "Prints the name of the geometry dimension <GEO> as a String on the Stream <S> and returns <S>.", py::arg("GEO"), py::arg("S"));
cls_TDataXtd.def_static("Print_", (Standard_OStream & (*)(const TDataXtd_ConstraintEnum, Standard_OStream &)) &TDataXtd::Print, "Prints the name of the constraint <CTR> as a String on the Stream <S> and returns <S>.", py::arg("CTR"), py::arg("S"));

// CLASS: TDATAXTD_HARRAY1OFTRSF
py::class_<TDataXtd_HArray1OfTrsf, opencascade::handle<TDataXtd_HArray1OfTrsf>, Standard_Transient> cls_TDataXtd_HArray1OfTrsf(mod, "TDataXtd_HArray1OfTrsf", "None", py::multiple_inheritance());

// Constructors
cls_TDataXtd_HArray1OfTrsf.def(py::init<>());
cls_TDataXtd_HArray1OfTrsf.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_TDataXtd_HArray1OfTrsf.def(py::init<const Standard_Integer, const Standard_Integer, const TDataXtd_Array1OfTrsf::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_TDataXtd_HArray1OfTrsf.def(py::init<const TDataXtd_Array1OfTrsf &>(), py::arg("theOther"));

// Methods
// cls_TDataXtd_HArray1OfTrsf.def_static("operator new_", (void * (*)(size_t)) &TDataXtd_HArray1OfTrsf::operator new, "None", py::arg("theSize"));
// cls_TDataXtd_HArray1OfTrsf.def_static("operator delete_", (void (*)(void *)) &TDataXtd_HArray1OfTrsf::operator delete, "None", py::arg("theAddress"));
// cls_TDataXtd_HArray1OfTrsf.def_static("operator new[]_", (void * (*)(size_t)) &TDataXtd_HArray1OfTrsf::operator new[], "None", py::arg("theSize"));
// cls_TDataXtd_HArray1OfTrsf.def_static("operator delete[]_", (void (*)(void *)) &TDataXtd_HArray1OfTrsf::operator delete[], "None", py::arg("theAddress"));
// cls_TDataXtd_HArray1OfTrsf.def_static("operator new_", (void * (*)(size_t, void *)) &TDataXtd_HArray1OfTrsf::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TDataXtd_HArray1OfTrsf.def_static("operator delete_", (void (*)(void *, void *)) &TDataXtd_HArray1OfTrsf::operator delete, "None", py::arg(""), py::arg(""));
// cls_TDataXtd_HArray1OfTrsf.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &TDataXtd_HArray1OfTrsf::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_TDataXtd_HArray1OfTrsf.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &TDataXtd_HArray1OfTrsf::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_TDataXtd_HArray1OfTrsf.def("Array1", (const TDataXtd_Array1OfTrsf & (TDataXtd_HArray1OfTrsf::*)() const) &TDataXtd_HArray1OfTrsf::Array1, "None");
cls_TDataXtd_HArray1OfTrsf.def("ChangeArray1", (TDataXtd_Array1OfTrsf & (TDataXtd_HArray1OfTrsf::*)()) &TDataXtd_HArray1OfTrsf::ChangeArray1, "None");
cls_TDataXtd_HArray1OfTrsf.def_static("get_type_name_", (const char * (*)()) &TDataXtd_HArray1OfTrsf::get_type_name, "None");
cls_TDataXtd_HArray1OfTrsf.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataXtd_HArray1OfTrsf::get_type_descriptor, "None");
cls_TDataXtd_HArray1OfTrsf.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataXtd_HArray1OfTrsf::*)() const) &TDataXtd_HArray1OfTrsf::DynamicType, "None");

// CLASS: TDATAXTD_TRIANGULATION
py::class_<TDataXtd_Triangulation, opencascade::handle<TDataXtd_Triangulation>, TDF_Attribute> cls_TDataXtd_Triangulation(mod, "TDataXtd_Triangulation", "An Ocaf attribute containing a mesh (Poly_Triangulation). It duplicates all methods from Poly_Triangulation. It is highly recommended to modify the mesh through the methods of this attribute, but not directly via the underlying Poly_Triangulation object. In this case Undo/Redo will work fine and robust.");

// Constructors
cls_TDataXtd_Triangulation.def(py::init<>());

// Methods
cls_TDataXtd_Triangulation.def_static("GetID_", (const Standard_GUID & (*)()) &TDataXtd_Triangulation::GetID, "Returns the ID of the triangulation attribute.");
cls_TDataXtd_Triangulation.def_static("Set_", (opencascade::handle<TDataXtd_Triangulation> (*)(const TDF_Label &)) &TDataXtd_Triangulation::Set, "Finds or creates a triangulation attribute.", py::arg("theLabel"));
cls_TDataXtd_Triangulation.def_static("Set_", (opencascade::handle<TDataXtd_Triangulation> (*)(const TDF_Label &, const opencascade::handle<Poly_Triangulation> &)) &TDataXtd_Triangulation::Set, "Finds or creates a triangulation attribute. Initializes the attribute by a Poly_Triangulation object.", py::arg("theLabel"), py::arg("theTriangulation"));
cls_TDataXtd_Triangulation.def("Set", (void (TDataXtd_Triangulation::*)(const opencascade::handle<Poly_Triangulation> &)) &TDataXtd_Triangulation::Set, "Sets the triangulation.", py::arg("theTriangulation"));
cls_TDataXtd_Triangulation.def("Get", (const opencascade::handle<Poly_Triangulation> & (TDataXtd_Triangulation::*)() const) &TDataXtd_Triangulation::Get, "Returns the underlying triangulation.");
cls_TDataXtd_Triangulation.def("Deflection", (Standard_Real (TDataXtd_Triangulation::*)() const) &TDataXtd_Triangulation::Deflection, "Returns the deflection of this triangulation.");
cls_TDataXtd_Triangulation.def("Deflection", (void (TDataXtd_Triangulation::*)(const Standard_Real)) &TDataXtd_Triangulation::Deflection, "Sets the deflection of this triangulation to theDeflection. See more on deflection in Polygon2D", py::arg("theDeflection"));
cls_TDataXtd_Triangulation.def("RemoveUVNodes", (void (TDataXtd_Triangulation::*)()) &TDataXtd_Triangulation::RemoveUVNodes, "Deallocates the UV nodes.");
cls_TDataXtd_Triangulation.def("NbNodes", (Standard_Integer (TDataXtd_Triangulation::*)() const) &TDataXtd_Triangulation::NbNodes, "Returns the number of nodes for this triangulation.");
cls_TDataXtd_Triangulation.def("NbTriangles", (Standard_Integer (TDataXtd_Triangulation::*)() const) &TDataXtd_Triangulation::NbTriangles, "Returns the number of triangles for this triangulation.");
cls_TDataXtd_Triangulation.def("HasUVNodes", (Standard_Boolean (TDataXtd_Triangulation::*)() const) &TDataXtd_Triangulation::HasUVNodes, "Returns Standard_True if 2D nodes are associated with 3D nodes for this triangulation.");
cls_TDataXtd_Triangulation.def("Node", (const gp_Pnt & (TDataXtd_Triangulation::*)(const Standard_Integer) const) &TDataXtd_Triangulation::Node, "Returns node at the given index. Raises Standard_OutOfRange exception if theIndex is less than 1 or greater than NbNodes.", py::arg("theIndex"));
cls_TDataXtd_Triangulation.def("SetNode", (void (TDataXtd_Triangulation::*)(const Standard_Integer, const gp_Pnt &)) &TDataXtd_Triangulation::SetNode, "The method differs from Poly_Triangulation! Sets a node at the given index. Raises Standard_OutOfRange exception if theIndex is less than 1 or greater than NbNodes.", py::arg("theIndex"), py::arg("theNode"));
cls_TDataXtd_Triangulation.def("UVNode", (const gp_Pnt2d & (TDataXtd_Triangulation::*)(const Standard_Integer) const) &TDataXtd_Triangulation::UVNode, "Returns UVNode at the given index. Raises Standard_OutOfRange exception if theIndex is less than 1 or greater than NbNodes.", py::arg("theIndex"));
cls_TDataXtd_Triangulation.def("SetUVNode", (void (TDataXtd_Triangulation::*)(const Standard_Integer, const gp_Pnt2d &)) &TDataXtd_Triangulation::SetUVNode, "The method differs from Poly_Triangulation! Sets a UVNode at the given index. Raises Standard_OutOfRange exception if theIndex is less than 1 or greater than NbNodes.", py::arg("theIndex"), py::arg("theUVNode"));
cls_TDataXtd_Triangulation.def("Triangle", (const Poly_Triangle & (TDataXtd_Triangulation::*)(const Standard_Integer) const) &TDataXtd_Triangulation::Triangle, "Returns triangle at the given index. Raises Standard_OutOfRange exception if theIndex is less than 1 or greater than NbTriangles.", py::arg("theIndex"));
cls_TDataXtd_Triangulation.def("SetTriangle", (void (TDataXtd_Triangulation::*)(const Standard_Integer, const Poly_Triangle &)) &TDataXtd_Triangulation::SetTriangle, "The method differs from Poly_Triangulation! Sets a triangle at the given index. Raises Standard_OutOfRange exception if theIndex is less than 1 or greater than NbTriangles.", py::arg("theIndex"), py::arg("theTriangle"));
cls_TDataXtd_Triangulation.def("SetNormals", (void (TDataXtd_Triangulation::*)(const opencascade::handle<TShort_HArray1OfShortReal> &)) &TDataXtd_Triangulation::SetNormals, "Sets the table of node normals. Raises exception if length of theNormals != 3 * NbNodes", py::arg("theNormals"));
cls_TDataXtd_Triangulation.def("SetNormal", (void (TDataXtd_Triangulation::*)(const Standard_Integer, const gp_Dir &)) &TDataXtd_Triangulation::SetNormal, "Changes normal at the given index. Raises Standard_OutOfRange exception.", py::arg("theIndex"), py::arg("theNormal"));
cls_TDataXtd_Triangulation.def("HasNormals", (Standard_Boolean (TDataXtd_Triangulation::*)() const) &TDataXtd_Triangulation::HasNormals, "Returns Standard_True if nodal normals are defined.");
cls_TDataXtd_Triangulation.def("Normal", (const gp_Dir (TDataXtd_Triangulation::*)(const Standard_Integer) const) &TDataXtd_Triangulation::Normal, "Returns normal at the given index. Raises Standard_OutOfRange exception.", py::arg("theIndex"));
cls_TDataXtd_Triangulation.def("ID", (const Standard_GUID & (TDataXtd_Triangulation::*)() const) &TDataXtd_Triangulation::ID, "Inherited attribute methods");
cls_TDataXtd_Triangulation.def("Restore", (void (TDataXtd_Triangulation::*)(const opencascade::handle<TDF_Attribute> &)) &TDataXtd_Triangulation::Restore, "None", py::arg("theAttribute"));
cls_TDataXtd_Triangulation.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDataXtd_Triangulation::*)() const) &TDataXtd_Triangulation::NewEmpty, "None");
cls_TDataXtd_Triangulation.def("Paste", (void (TDataXtd_Triangulation::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDataXtd_Triangulation::Paste, "None", py::arg("Into"), py::arg("RT"));
cls_TDataXtd_Triangulation.def("Dump", (Standard_OStream & (TDataXtd_Triangulation::*)(Standard_OStream &) const) &TDataXtd_Triangulation::Dump, "None", py::arg("anOS"));
cls_TDataXtd_Triangulation.def_static("get_type_name_", (const char * (*)()) &TDataXtd_Triangulation::get_type_name, "None");
cls_TDataXtd_Triangulation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataXtd_Triangulation::get_type_descriptor, "None");
cls_TDataXtd_Triangulation.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataXtd_Triangulation::*)() const) &TDataXtd_Triangulation::DynamicType, "None");


}
