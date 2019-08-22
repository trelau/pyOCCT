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
#include <gp_Pnt.hxx>
#include <BRepExtrema_Poly.hxx>

void bind_BRepExtrema_Poly(py::module &mod){

py::class_<BRepExtrema_Poly> cls_BRepExtrema_Poly(mod, "BRepExtrema_Poly", "None");

// Constructors

// Fields

// Methods
cls_BRepExtrema_Poly.def_static("Distance_", [](const TopoDS_Shape & S1, const TopoDS_Shape & S2, gp_Pnt & P1, gp_Pnt & P2, Standard_Real & dist){ Standard_Boolean rv = BRepExtrema_Poly::Distance(S1, S2, P1, P2, dist); return std::tuple<Standard_Boolean, Standard_Real &>(rv, dist); }, "returns Standard_True if OK.", py::arg("S1"), py::arg("S2"), py::arg("P1"), py::arg("P2"), py::arg("dist"));

// Enums

}