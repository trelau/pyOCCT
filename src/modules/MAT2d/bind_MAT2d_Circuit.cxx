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
#include <Standard_Transient.hxx>
#include <GeomAbs_JoinType.hxx>
#include <Standard_TypeDef.hxx>
#include <MAT2d_SequenceOfSequenceOfGeometry.hxx>
#include <TColStd_SequenceOfBoolean.hxx>
#include <Standard_Handle.hxx>
#include <Geom2d_Geometry.hxx>
#include <TColStd_SequenceOfInteger.hxx>
#include <MAT2d_Connexion.hxx>
#include <MAT2d_Circuit.hxx>
#include <Standard_Type.hxx>
#include <TColGeom2d_SequenceOfGeometry.hxx>
#include <MAT2d_BiInt.hxx>
#include <MAT2d_SequenceOfConnexion.hxx>
#include <MAT2d_MiniPath.hxx>
#include <MAT2d_DataMapOfIntegerConnexion.hxx>
#include <MAT2d_DataMapOfBiIntSequenceOfInteger.hxx>

void bind_MAT2d_Circuit(py::module &mod){

py::class_<MAT2d_Circuit, opencascade::handle<MAT2d_Circuit>, Standard_Transient> cls_MAT2d_Circuit(mod, "MAT2d_Circuit", "Constructs a circuit on a set of lines. EquiCircuit gives a Circuit passing by all the lines in a set and all the connexions of the minipath associated.");

// Constructors
cls_MAT2d_Circuit.def(py::init<>());
cls_MAT2d_Circuit.def(py::init<const GeomAbs_JoinType>(), py::arg("aJoinType"));
cls_MAT2d_Circuit.def(py::init<const GeomAbs_JoinType, const Standard_Boolean>(), py::arg("aJoinType"), py::arg("IsOpenResult"));

// Fields

// Methods
cls_MAT2d_Circuit.def("Perform", (void (MAT2d_Circuit::*)(MAT2d_SequenceOfSequenceOfGeometry &, const TColStd_SequenceOfBoolean &, const Standard_Integer, const Standard_Boolean)) &MAT2d_Circuit::Perform, "None", py::arg("aFigure"), py::arg("IsClosed"), py::arg("IndRefLine"), py::arg("Trigo"));
cls_MAT2d_Circuit.def("NumberOfItems", (Standard_Integer (MAT2d_Circuit::*)() const) &MAT2d_Circuit::NumberOfItems, "Returns the Number of Items .");
cls_MAT2d_Circuit.def("Value", (opencascade::handle<Geom2d_Geometry> (MAT2d_Circuit::*)(const Standard_Integer) const) &MAT2d_Circuit::Value, "Returns the item at position <Index> in <me>.", py::arg("Index"));
cls_MAT2d_Circuit.def("LineLength", (Standard_Integer (MAT2d_Circuit::*)(const Standard_Integer) const) &MAT2d_Circuit::LineLength, "Returns the number of items on the line <IndexLine>.", py::arg("IndexLine"));
cls_MAT2d_Circuit.def("RefToEqui", (const TColStd_SequenceOfInteger & (MAT2d_Circuit::*)(const Standard_Integer, const Standard_Integer) const) &MAT2d_Circuit::RefToEqui, "Returns the set of index of the items in <me>corresponding to the curve <IndCurve> on the line <IndLine> from the initial figure.", py::arg("IndLine"), py::arg("IndCurve"));
cls_MAT2d_Circuit.def("Connexion", (opencascade::handle<MAT2d_Connexion> (MAT2d_Circuit::*)(const Standard_Integer) const) &MAT2d_Circuit::Connexion, "Returns the Connexion on the item <Index> in me.", py::arg("Index"));
cls_MAT2d_Circuit.def("ConnexionOn", (Standard_Boolean (MAT2d_Circuit::*)(const Standard_Integer) const) &MAT2d_Circuit::ConnexionOn, "Returns <True> is there is a connexion on the item <Index> in <me>.", py::arg("Index"));
cls_MAT2d_Circuit.def_static("get_type_name_", (const char * (*)()) &MAT2d_Circuit::get_type_name, "None");
cls_MAT2d_Circuit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MAT2d_Circuit::get_type_descriptor, "None");
cls_MAT2d_Circuit.def("DynamicType", (const opencascade::handle<Standard_Type> & (MAT2d_Circuit::*)() const) &MAT2d_Circuit::DynamicType, "None");

// Enums

}