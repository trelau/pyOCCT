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
#include <Standard_Handle.hxx>
#include <Poly_Triangulation.hxx>
#include <Standard_Type.hxx>
#include <Standard_TypeDef.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <Poly_Array1OfTriangle.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <gp_Pnt.hxx>
#include <gp_Pnt2d.hxx>
#include <Poly_Triangle.hxx>
#include <TShort_HArray1OfShortReal.hxx>
#include <TShort_Array1OfShortReal.hxx>
#include <gp_Dir.hxx>
#include <TColgp_HArray1OfPnt2d.hxx>

void bind_Poly_Triangulation(py::module &mod){

py::class_<Poly_Triangulation, opencascade::handle<Poly_Triangulation>, Standard_Transient> cls_Poly_Triangulation(mod, "Poly_Triangulation", "Provides a triangulation for a surface, a set of surfaces, or more generally a shape. A triangulation consists of an approximate representation of the actual shape, using a collection of points and triangles. The points are located on the surface. The edges of the triangles connect adjacent points with a straight line that approximates the true curve on the surface. A triangulation comprises: - A table of 3D nodes (3D points on the surface). - A table of triangles. Each triangle (Poly_Triangle object) comprises a triplet of indices in the table of 3D nodes specific to the triangulation. - A table of 2D nodes (2D points), parallel to the table of 3D nodes. This table is optional. If it exists, the coordinates of a 2D point are the (u, v) parameters of the corresponding 3D point on the surface approximated by the triangulation. - A deflection (optional), which maximizes the distance from a point on the surface to the corresponding point on its approximate triangulation. In many cases, algorithms do not need to work with the exact representation of a surface. A triangular representation induces simpler and more robust adjusting, faster performances, and the results are as good. This is a Transient class.");

// Constructors
cls_Poly_Triangulation.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Boolean>(), py::arg("nbNodes"), py::arg("nbTriangles"), py::arg("UVNodes"));
cls_Poly_Triangulation.def(py::init<const TColgp_Array1OfPnt &, const Poly_Array1OfTriangle &>(), py::arg("Nodes"), py::arg("Triangles"));
cls_Poly_Triangulation.def(py::init<const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt2d &, const Poly_Array1OfTriangle &>(), py::arg("Nodes"), py::arg("UVNodes"), py::arg("Triangles"));
cls_Poly_Triangulation.def(py::init<const opencascade::handle<Poly_Triangulation> &>(), py::arg("theTriangulation"));

// Fields

// Methods
cls_Poly_Triangulation.def_static("get_type_name_", (const char * (*)()) &Poly_Triangulation::get_type_name, "None");
cls_Poly_Triangulation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Poly_Triangulation::get_type_descriptor, "None");
cls_Poly_Triangulation.def("DynamicType", (const opencascade::handle<Standard_Type> & (Poly_Triangulation::*)() const) &Poly_Triangulation::DynamicType, "None");
cls_Poly_Triangulation.def("Copy", (opencascade::handle<Poly_Triangulation> (Poly_Triangulation::*)() const) &Poly_Triangulation::Copy, "Creates full copy of current triangulation");
cls_Poly_Triangulation.def("Deflection", (Standard_Real (Poly_Triangulation::*)() const) &Poly_Triangulation::Deflection, "Returns the deflection of this triangulation.");
cls_Poly_Triangulation.def("Deflection", (void (Poly_Triangulation::*)(const Standard_Real)) &Poly_Triangulation::Deflection, "Sets the deflection of this triangulation to theDeflection. See more on deflection in Polygon2D", py::arg("theDeflection"));
cls_Poly_Triangulation.def("RemoveUVNodes", (void (Poly_Triangulation::*)()) &Poly_Triangulation::RemoveUVNodes, "Deallocates the UV nodes.");
cls_Poly_Triangulation.def("NbNodes", (Standard_Integer (Poly_Triangulation::*)() const) &Poly_Triangulation::NbNodes, "Returns the number of nodes for this triangulation.");
cls_Poly_Triangulation.def("NbTriangles", (Standard_Integer (Poly_Triangulation::*)() const) &Poly_Triangulation::NbTriangles, "Returns the number of triangles for this triangulation.");
cls_Poly_Triangulation.def("HasUVNodes", (Standard_Boolean (Poly_Triangulation::*)() const) &Poly_Triangulation::HasUVNodes, "Returns Standard_True if 2D nodes are associated with 3D nodes for this triangulation.");
cls_Poly_Triangulation.def("Nodes", (const TColgp_Array1OfPnt & (Poly_Triangulation::*)() const) &Poly_Triangulation::Nodes, "Returns the table of 3D nodes (3D points) for this triangulation.");
cls_Poly_Triangulation.def("ChangeNodes", (TColgp_Array1OfPnt & (Poly_Triangulation::*)()) &Poly_Triangulation::ChangeNodes, "Returns the table of 3D nodes (3D points) for this triangulation. The returned array is shared. Therefore if the table is selected by reference, you can, by simply modifying it, directly modify the data structure of this triangulation.");
cls_Poly_Triangulation.def("Node", (const gp_Pnt & (Poly_Triangulation::*)(const Standard_Integer) const) &Poly_Triangulation::Node, "Returns node at the given index. Raises Standard_OutOfRange exception if theIndex is less than 1 or greater than NbNodes.", py::arg("theIndex"));
cls_Poly_Triangulation.def("ChangeNode", (gp_Pnt & (Poly_Triangulation::*)(const Standard_Integer)) &Poly_Triangulation::ChangeNode, "Give access to the node at the given index. Raises Standard_OutOfRange exception if theIndex is less than 1 or greater than NbNodes.", py::arg("theIndex"));
cls_Poly_Triangulation.def("UVNodes", (const TColgp_Array1OfPnt2d & (Poly_Triangulation::*)() const) &Poly_Triangulation::UVNodes, "Returns the table of 2D nodes (2D points) associated with each 3D node of this triangulation. The function HasUVNodes checks if 2D nodes are associated with the 3D nodes of this triangulation. Const reference on the 2d nodes values.");
cls_Poly_Triangulation.def("ChangeUVNodes", (TColgp_Array1OfPnt2d & (Poly_Triangulation::*)()) &Poly_Triangulation::ChangeUVNodes, "Returns the table of 2D nodes (2D points) associated with each 3D node of this triangulation. Function ChangeUVNodes shares the returned array. Therefore if the table is selected by reference, you can, by simply modifying it, directly modify the data structure of this triangulation.");
cls_Poly_Triangulation.def("UVNode", (const gp_Pnt2d & (Poly_Triangulation::*)(const Standard_Integer) const) &Poly_Triangulation::UVNode, "Returns UVNode at the given index. Raises Standard_OutOfRange exception if theIndex is less than 1 or greater than NbNodes.", py::arg("theIndex"));
cls_Poly_Triangulation.def("ChangeUVNode", (gp_Pnt2d & (Poly_Triangulation::*)(const Standard_Integer)) &Poly_Triangulation::ChangeUVNode, "Give access to the UVNode at the given index. Raises Standard_OutOfRange exception if theIndex is less than 1 or greater than NbNodes.", py::arg("theIndex"));
cls_Poly_Triangulation.def("Triangles", (const Poly_Array1OfTriangle & (Poly_Triangulation::*)() const) &Poly_Triangulation::Triangles, "Returns the table of triangles for this triangulation.");
cls_Poly_Triangulation.def("ChangeTriangles", (Poly_Array1OfTriangle & (Poly_Triangulation::*)()) &Poly_Triangulation::ChangeTriangles, "Returns the table of triangles for this triangulation. Function ChangeUVNodes shares the returned array. Therefore if the table is selected by reference, you can, by simply modifying it, directly modify the data structure of this triangulation.");
cls_Poly_Triangulation.def("Triangle", (const Poly_Triangle & (Poly_Triangulation::*)(const Standard_Integer) const) &Poly_Triangulation::Triangle, "Returns triangle at the given index. Raises Standard_OutOfRange exception if theIndex is less than 1 or greater than NbTriangles.", py::arg("theIndex"));
cls_Poly_Triangulation.def("ChangeTriangle", (Poly_Triangle & (Poly_Triangulation::*)(const Standard_Integer)) &Poly_Triangulation::ChangeTriangle, "Give access to the triangle at the given index. Raises Standard_OutOfRange exception if theIndex is less than 1 or greater than NbTriangles.", py::arg("theIndex"));
cls_Poly_Triangulation.def("SetNormals", (void (Poly_Triangulation::*)(const opencascade::handle<TShort_HArray1OfShortReal> &)) &Poly_Triangulation::SetNormals, "Sets the table of node normals. raises exception if length of theNormals != 3*NbNodes", py::arg("theNormals"));
cls_Poly_Triangulation.def("Normals", (const TShort_Array1OfShortReal & (Poly_Triangulation::*)() const) &Poly_Triangulation::Normals, "Returns the table of node normals.");
cls_Poly_Triangulation.def("ChangeNormals", (TShort_Array1OfShortReal & (Poly_Triangulation::*)()) &Poly_Triangulation::ChangeNormals, "Gives access to the table of node normals.");
cls_Poly_Triangulation.def("HasNormals", (Standard_Boolean (Poly_Triangulation::*)() const) &Poly_Triangulation::HasNormals, "Returns Standard_True if nodal normals are defined.");
cls_Poly_Triangulation.def("Normal", (gp_Dir (Poly_Triangulation::*)(const Standard_Integer) const) &Poly_Triangulation::Normal, "Returns normal at the given index. Raises Standard_OutOfRange exception.", py::arg("theIndex"));
cls_Poly_Triangulation.def("SetNormal", (void (Poly_Triangulation::*)(const Standard_Integer, const gp_Dir &)) &Poly_Triangulation::SetNormal, "Changes normal at the given index. Raises Standard_OutOfRange exception.", py::arg("theIndex"), py::arg("theNormal"));

// Enums

}