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
#include <TColStd_Array1OfInteger.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <Standard_Handle.hxx>
#include <Poly_PolygonOnTriangulation.hxx>
#include <Standard_TypeDef.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <Standard_Type.hxx>

void bind_Poly_PolygonOnTriangulation(py::module &mod){

py::class_<Poly_PolygonOnTriangulation, opencascade::handle<Poly_PolygonOnTriangulation>, Standard_Transient> cls_Poly_PolygonOnTriangulation(mod, "Poly_PolygonOnTriangulation", "This class provides a polygon in 3D space, based on the triangulation of a surface. It may be the approximate representation of a curve on the surface, or more generally the shape. A PolygonOnTriangulation is defined by a table of nodes. Each node is an index in the table of nodes specific to a triangulation, and represents a point on the surface. If the polygon is closed, the index of the point of closure is repeated at the end of the table of nodes. If the polygon is an approximate representation of a curve on a surface, you can associate with each of its nodes the value of the parameter of the corresponding point on the curve.represents a 3d Polygon");

// Constructors
cls_Poly_PolygonOnTriangulation.def(py::init<const TColStd_Array1OfInteger &>(), py::arg("Nodes"));
cls_Poly_PolygonOnTriangulation.def(py::init<const TColStd_Array1OfInteger &, const TColStd_Array1OfReal &>(), py::arg("Nodes"), py::arg("Parameters"));

// Fields

// Methods
cls_Poly_PolygonOnTriangulation.def("Copy", (opencascade::handle<Poly_PolygonOnTriangulation> (Poly_PolygonOnTriangulation::*)() const) &Poly_PolygonOnTriangulation::Copy, "Creates a copy of current polygon");
cls_Poly_PolygonOnTriangulation.def("Deflection", (Standard_Real (Poly_PolygonOnTriangulation::*)() const) &Poly_PolygonOnTriangulation::Deflection, "Returns the deflection of this polygon");
cls_Poly_PolygonOnTriangulation.def("Deflection", (void (Poly_PolygonOnTriangulation::*)(const Standard_Real)) &Poly_PolygonOnTriangulation::Deflection, "Sets the deflection of this polygon to D. See more on deflection in Poly_Polygones2D.", py::arg("D"));
cls_Poly_PolygonOnTriangulation.def("NbNodes", (Standard_Integer (Poly_PolygonOnTriangulation::*)() const) &Poly_PolygonOnTriangulation::NbNodes, "Returns the number of nodes for this polygon. Note: If the polygon is closed, the point of closure is repeated at the end of its table of nodes. Thus, on a closed triangle, the function NbNodes returns 4.");
cls_Poly_PolygonOnTriangulation.def("Nodes", (const TColStd_Array1OfInteger & (Poly_PolygonOnTriangulation::*)() const) &Poly_PolygonOnTriangulation::Nodes, "Returns the table of nodes for this polygon. A node value is an index in the table of nodes specific to an existing triangulation of a shape.");
cls_Poly_PolygonOnTriangulation.def("HasParameters", (Standard_Boolean (Poly_PolygonOnTriangulation::*)() const) &Poly_PolygonOnTriangulation::HasParameters, "Returns true if parameters are associated with the nodes in this polygon.");
cls_Poly_PolygonOnTriangulation.def("Parameters", (opencascade::handle<TColStd_HArray1OfReal> (Poly_PolygonOnTriangulation::*)() const) &Poly_PolygonOnTriangulation::Parameters, "Returns the table of the parameters associated with each node in this polygon. Warning Use the function HasParameters to check if parameters are associated with the nodes in this polygon.");
cls_Poly_PolygonOnTriangulation.def_static("get_type_name_", (const char * (*)()) &Poly_PolygonOnTriangulation::get_type_name, "None");
cls_Poly_PolygonOnTriangulation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Poly_PolygonOnTriangulation::get_type_descriptor, "None");
cls_Poly_PolygonOnTriangulation.def("DynamicType", (const opencascade::handle<Standard_Type> & (Poly_PolygonOnTriangulation::*)() const) &Poly_PolygonOnTriangulation::DynamicType, "None");

// Enums

}