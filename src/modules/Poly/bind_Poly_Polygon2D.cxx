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
#include <TColgp_Array1OfPnt2d.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Poly_Polygon2D.hxx>
#include <Standard_Type.hxx>

void bind_Poly_Polygon2D(py::module &mod){

py::class_<Poly_Polygon2D, opencascade::handle<Poly_Polygon2D>, Standard_Transient> cls_Poly_Polygon2D(mod, "Poly_Polygon2D", "Provides a polygon in 2D space (for example, in the parametric space of a surface). It is generally an approximate representation of a curve. A Polygon2D is defined by a table of nodes. Each node is a 2D point. If the polygon is closed, the point of closure is repeated at the end of the table of nodes.");

// Constructors
cls_Poly_Polygon2D.def(py::init<const TColgp_Array1OfPnt2d &>(), py::arg("Nodes"));

// Fields

// Methods
cls_Poly_Polygon2D.def("Deflection", (Standard_Real (Poly_Polygon2D::*)() const) &Poly_Polygon2D::Deflection, "Returns the deflection of this polygon. Deflection is used in cases where the polygon is an approximate representation of a curve. Deflection represents the maximum distance permitted between any point on the curve and the corresponding point on the polygon. By default the deflection value is equal to 0. An algorithm using this 2D polygon with a deflection value equal to 0 considers that it is working with a true polygon and not with an approximate representation of a curve. The Deflection function is used to modify the deflection value of this polygon. The deflection value can be used by any algorithm working with 2D polygons. For example: - An algorithm may use a unique deflection value for all its polygons. In this case it is not necessary to use the Deflection function. - Or an algorithm may want to attach a different deflection to each polygon. In this case, the Deflection function is used to set a value on each polygon, and later to fetch the value.");
cls_Poly_Polygon2D.def("Deflection", (void (Poly_Polygon2D::*)(const Standard_Real)) &Poly_Polygon2D::Deflection, "Sets the deflection of this polygon to D", py::arg("D"));
cls_Poly_Polygon2D.def("NbNodes", (Standard_Integer (Poly_Polygon2D::*)() const) &Poly_Polygon2D::NbNodes, "Returns the number of nodes in this polygon. Note: If the polygon is closed, the point of closure is repeated at the end of its table of nodes. Thus, on a closed triangle, the function NbNodes returns 4.");
cls_Poly_Polygon2D.def("Nodes", (const TColgp_Array1OfPnt2d & (Poly_Polygon2D::*)() const) &Poly_Polygon2D::Nodes, "Returns the table of nodes for this polygon.");
cls_Poly_Polygon2D.def_static("get_type_name_", (const char * (*)()) &Poly_Polygon2D::get_type_name, "None");
cls_Poly_Polygon2D.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Poly_Polygon2D::get_type_descriptor, "None");
cls_Poly_Polygon2D.def("DynamicType", (const opencascade::handle<Standard_Type> & (Poly_Polygon2D::*)() const) &Poly_Polygon2D::DynamicType, "None");

// Enums

}