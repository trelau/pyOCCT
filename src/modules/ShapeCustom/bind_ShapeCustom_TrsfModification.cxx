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
#include <BRepTools_TrsfModification.hxx>
#include <gp_Trsf.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Face.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Surface.hxx>
#include <TopLoc_Location.hxx>
#include <TopoDS_Edge.hxx>
#include <Geom_Curve.hxx>
#include <TopoDS_Vertex.hxx>
#include <gp_Pnt.hxx>
#include <Geom2d_Curve.hxx>
#include <ShapeCustom_TrsfModification.hxx>
#include <Standard_Type.hxx>

void bind_ShapeCustom_TrsfModification(py::module &mod){

py::class_<ShapeCustom_TrsfModification, opencascade::handle<ShapeCustom_TrsfModification>, BRepTools_TrsfModification> cls_ShapeCustom_TrsfModification(mod, "ShapeCustom_TrsfModification", "Complements BRepTools_TrsfModification to provide reversible scaling regarding tolerances. Uses actual tolerances (attached to the shapes) not ones returned by BRep_Tool::Tolerance to work with tolerances lower than Precision::Confusion.");

// Constructors
cls_ShapeCustom_TrsfModification.def(py::init<const gp_Trsf &>(), py::arg("T"));

// Fields

// Methods
cls_ShapeCustom_TrsfModification.def("NewSurface", [](ShapeCustom_TrsfModification &self, const TopoDS_Face & F, opencascade::handle<Geom_Surface> & S, TopLoc_Location & L, Standard_Real & Tol, Standard_Boolean & RevWires, Standard_Boolean & RevFace){ Standard_Boolean rv = self.NewSurface(F, S, L, Tol, RevWires, RevFace); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Boolean &, Standard_Boolean &>(rv, Tol, RevWires, RevFace); }, "Calls inherited method. Sets <Tol> as actual tolerance of <F> multiplied with scale factor.", py::arg("F"), py::arg("S"), py::arg("L"), py::arg("Tol"), py::arg("RevWires"), py::arg("RevFace"));
cls_ShapeCustom_TrsfModification.def("NewCurve", [](ShapeCustom_TrsfModification &self, const TopoDS_Edge & E, opencascade::handle<Geom_Curve> & C, TopLoc_Location & L, Standard_Real & Tol){ Standard_Boolean rv = self.NewCurve(E, C, L, Tol); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Tol); }, "Calls inherited method. Sets <Tol> as actual tolerance of <E> multiplied with scale factor.", py::arg("E"), py::arg("C"), py::arg("L"), py::arg("Tol"));
cls_ShapeCustom_TrsfModification.def("NewPoint", [](ShapeCustom_TrsfModification &self, const TopoDS_Vertex & V, gp_Pnt & P, Standard_Real & Tol){ Standard_Boolean rv = self.NewPoint(V, P, Tol); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Tol); }, "Calls inherited method. Sets <Tol> as actual tolerance of <V> multiplied with scale factor.", py::arg("V"), py::arg("P"), py::arg("Tol"));
cls_ShapeCustom_TrsfModification.def("NewCurve2d", [](ShapeCustom_TrsfModification &self, const TopoDS_Edge & E, const TopoDS_Face & F, const TopoDS_Edge & NewE, const TopoDS_Face & NewF, opencascade::handle<Geom2d_Curve> & C, Standard_Real & Tol){ Standard_Boolean rv = self.NewCurve2d(E, F, NewE, NewF, C, Tol); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Tol); }, "Calls inherited method. Sets <Tol> as actual tolerance of <E> multiplied with scale factor.", py::arg("E"), py::arg("F"), py::arg("NewE"), py::arg("NewF"), py::arg("C"), py::arg("Tol"));
cls_ShapeCustom_TrsfModification.def("NewParameter", [](ShapeCustom_TrsfModification &self, const TopoDS_Vertex & V, const TopoDS_Edge & E, Standard_Real & P, Standard_Real & Tol){ Standard_Boolean rv = self.NewParameter(V, E, P, Tol); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, P, Tol); }, "Calls inherited method. Sets <Tol> as actual tolerance of <V> multiplied with scale factor.", py::arg("V"), py::arg("E"), py::arg("P"), py::arg("Tol"));
cls_ShapeCustom_TrsfModification.def_static("get_type_name_", (const char * (*)()) &ShapeCustom_TrsfModification::get_type_name, "None");
cls_ShapeCustom_TrsfModification.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeCustom_TrsfModification::get_type_descriptor, "None");
cls_ShapeCustom_TrsfModification.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeCustom_TrsfModification::*)() const) &ShapeCustom_TrsfModification::DynamicType, "None");

// Enums

}