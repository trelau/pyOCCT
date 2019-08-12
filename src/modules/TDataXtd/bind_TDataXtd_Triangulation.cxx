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
#include <TDataXtd_Triangulation.hxx>
#include <TDF_Label.hxx>
#include <Poly_Triangulation.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <gp_Pnt2d.hxx>
#include <Poly_Triangle.hxx>
#include <TShort_HArray1OfShortReal.hxx>
#include <gp_Dir.hxx>
#include <TDF_RelocationTable.hxx>
#include <Standard_OStream.hxx>
#include <Standard_Type.hxx>

void bind_TDataXtd_Triangulation(py::module &mod){

py::class_<TDataXtd_Triangulation, opencascade::handle<TDataXtd_Triangulation>, TDF_Attribute> cls_TDataXtd_Triangulation(mod, "TDataXtd_Triangulation", "An Ocaf attribute containing a mesh (Poly_Triangulation). It duplicates all methods from Poly_Triangulation. It is highly recommended to modify the mesh through the methods of this attribute, but not directly via the underlying Poly_Triangulation object. In this case Undo/Redo will work fine and robust.");

// Constructors
cls_TDataXtd_Triangulation.def(py::init<>());

// Fields

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

// Enums

}