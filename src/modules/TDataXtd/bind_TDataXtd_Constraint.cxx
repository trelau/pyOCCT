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
#include <TDF_Attribute.hxx>
#include <Standard_GUID.hxx>
#include <Standard_Handle.hxx>
#include <TDataXtd_Constraint.hxx>
#include <TDF_Label.hxx>
#include <TDataXtd_ConstraintEnum.hxx>
#include <TNaming_NamedShape.hxx>
#include <Standard_TypeDef.hxx>
#include <TDataStd_Real.hxx>
#include <TDF_LabelList.hxx>
#include <TDF_RelocationTable.hxx>
#include <Standard_OStream.hxx>
#include <TDF_DataSet.hxx>
#include <Standard_Type.hxx>

void bind_TDataXtd_Constraint(py::module &mod){

py::class_<TDataXtd_Constraint, opencascade::handle<TDataXtd_Constraint>, TDF_Attribute> cls_TDataXtd_Constraint(mod, "TDataXtd_Constraint", "The groundwork to define constraint attributes. The constraint attribute contains the following sorts of data: - Type whether the constraint attribute is a geometric constraint or a dimension - Value the real number value of a numeric constraint such as an angle or a radius - Geometries to identify the geometries underlying the topological attributes which define the constraint (up to 4) - Plane for 2D constraints.");

// Constructors
cls_TDataXtd_Constraint.def(py::init<>());

// Fields

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

// Enums

}