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
#include <TColgp_Array1OfPnt.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <Standard_Handle.hxx>
#include <Poly_Polygon3D.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Type.hxx>
#include <TColStd_HArray1OfReal.hxx>

void bind_Poly_Polygon3D(py::module &mod){

py::class_<Poly_Polygon3D, opencascade::handle<Poly_Polygon3D>, Standard_Transient> cls_Poly_Polygon3D(mod, "Poly_Polygon3D", "This class Provides a polygon in 3D space. It is generally an approximate representation of a curve. A Polygon3D is defined by a table of nodes. Each node is a 3D point. If the polygon is closed, the point of closure is repeated at the end of the table of nodes. If the polygon is an approximate representation of a curve, you can associate with each of its nodes the value of the parameter of the corresponding point on the curve.");

// Constructors
cls_Poly_Polygon3D.def(py::init<const TColgp_Array1OfPnt &>(), py::arg("Nodes"));
cls_Poly_Polygon3D.def(py::init<const TColgp_Array1OfPnt &, const TColStd_Array1OfReal &>(), py::arg("Nodes"), py::arg("Parameters"));

// Fields

// Methods
cls_Poly_Polygon3D.def("Copy", (opencascade::handle<Poly_Polygon3D> (Poly_Polygon3D::*)() const) &Poly_Polygon3D::Copy, "Creates a copy of current polygon");
cls_Poly_Polygon3D.def("Deflection", (Standard_Real (Poly_Polygon3D::*)() const) &Poly_Polygon3D::Deflection, "Returns the deflection of this polygon");
cls_Poly_Polygon3D.def("Deflection", (void (Poly_Polygon3D::*)(const Standard_Real)) &Poly_Polygon3D::Deflection, "Sets the deflection of this polygon to D. See more on deflection in Poly_Polygon2D", py::arg("D"));
cls_Poly_Polygon3D.def("NbNodes", (Standard_Integer (Poly_Polygon3D::*)() const) &Poly_Polygon3D::NbNodes, "Returns the number of nodes in this polygon. Note: If the polygon is closed, the point of closure is repeated at the end of its table of nodes. Thus, on a closed triangle the function NbNodes returns 4.");
cls_Poly_Polygon3D.def("Nodes", (const TColgp_Array1OfPnt & (Poly_Polygon3D::*)() const) &Poly_Polygon3D::Nodes, "Returns the table of nodes for this polygon.");
cls_Poly_Polygon3D.def("HasParameters", (Standard_Boolean (Poly_Polygon3D::*)() const) &Poly_Polygon3D::HasParameters, "Returns the table of the parameters associated with each node in this polygon. HasParameters function checks if parameters are associated with the nodes of this polygon.");
cls_Poly_Polygon3D.def("Parameters", (const TColStd_Array1OfReal & (Poly_Polygon3D::*)() const) &Poly_Polygon3D::Parameters, "Returns true if parameters are associated with the nodes in this polygon.");
cls_Poly_Polygon3D.def("ChangeParameters", (TColStd_Array1OfReal & (Poly_Polygon3D::*)() const) &Poly_Polygon3D::ChangeParameters, "Returns the table of the parameters associated with each node in this polygon. ChangeParameters function returnes the array as shared. Therefore if the table is selected by reference you can, by simply modifying it, directly modify the data structure of this polygon.");
cls_Poly_Polygon3D.def_static("get_type_name_", (const char * (*)()) &Poly_Polygon3D::get_type_name, "None");
cls_Poly_Polygon3D.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Poly_Polygon3D::get_type_descriptor, "None");
cls_Poly_Polygon3D.def("DynamicType", (const opencascade::handle<Standard_Type> & (Poly_Polygon3D::*)() const) &Poly_Polygon3D::DynamicType, "None");

// Enums

}