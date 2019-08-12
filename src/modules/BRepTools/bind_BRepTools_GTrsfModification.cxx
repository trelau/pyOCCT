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
#include <BRepTools_Modification.hxx>
#include <gp_GTrsf.hxx>
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
#include <GeomAbs_Shape.hxx>
#include <BRepTools_GTrsfModification.hxx>
#include <Standard_Type.hxx>

void bind_BRepTools_GTrsfModification(py::module &mod){

py::class_<BRepTools_GTrsfModification, opencascade::handle<BRepTools_GTrsfModification>, BRepTools_Modification> cls_BRepTools_GTrsfModification(mod, "BRepTools_GTrsfModification", "Defines a modification of the geometry by a GTrsf from gp. All methods return True and transform the geometry.");

// Constructors
cls_BRepTools_GTrsfModification.def(py::init<const gp_GTrsf &>(), py::arg("T"));

// Fields

// Methods
cls_BRepTools_GTrsfModification.def("GTrsf", (gp_GTrsf & (BRepTools_GTrsfModification::*)()) &BRepTools_GTrsfModification::GTrsf, "Gives an access on the GTrsf.");
cls_BRepTools_GTrsfModification.def("NewSurface", [](BRepTools_GTrsfModification &self, const TopoDS_Face & F, opencascade::handle<Geom_Surface> & S, TopLoc_Location & L, Standard_Real & Tol, Standard_Boolean & RevWires, Standard_Boolean & RevFace){ Standard_Boolean rv = self.NewSurface(F, S, L, Tol, RevWires, RevFace); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Boolean &, Standard_Boolean &>(rv, Tol, RevWires, RevFace); }, "Returns Standard_True if the face <F> has been modified. In this case, <S> is the new geometric support of the face, <L> the new location,<Tol> the new tolerance.<RevWires> has to be set to Standard_True when the modification reverses the normal of the surface.(the wires have to be reversed). <RevFace> has to be set to Standard_True if the orientation of the modified face changes in the shells which contain it. -- Here, <RevFace> will return Standard_True if the -- gp_Trsf is negative.", py::arg("F"), py::arg("S"), py::arg("L"), py::arg("Tol"), py::arg("RevWires"), py::arg("RevFace"));
cls_BRepTools_GTrsfModification.def("NewCurve", [](BRepTools_GTrsfModification &self, const TopoDS_Edge & E, opencascade::handle<Geom_Curve> & C, TopLoc_Location & L, Standard_Real & Tol){ Standard_Boolean rv = self.NewCurve(E, C, L, Tol); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Tol); }, "Returns Standard_True if the edge <E> has been modified. In this case, <C> is the new geometric support of the edge, <L> the new location, <Tol> the new tolerance. Otherwise, returns Standard_False, and <C>, <L>, <Tol> are not significant.", py::arg("E"), py::arg("C"), py::arg("L"), py::arg("Tol"));
cls_BRepTools_GTrsfModification.def("NewPoint", [](BRepTools_GTrsfModification &self, const TopoDS_Vertex & V, gp_Pnt & P, Standard_Real & Tol){ Standard_Boolean rv = self.NewPoint(V, P, Tol); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Tol); }, "Returns Standard_True if the vertex <V> has been modified. In this case, <P> is the new geometric support of the vertex, <Tol> the new tolerance. Otherwise, returns Standard_False, and <P>, <Tol> are not significant.", py::arg("V"), py::arg("P"), py::arg("Tol"));
cls_BRepTools_GTrsfModification.def("NewCurve2d", [](BRepTools_GTrsfModification &self, const TopoDS_Edge & E, const TopoDS_Face & F, const TopoDS_Edge & NewE, const TopoDS_Face & NewF, opencascade::handle<Geom2d_Curve> & C, Standard_Real & Tol){ Standard_Boolean rv = self.NewCurve2d(E, F, NewE, NewF, C, Tol); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Tol); }, "Returns Standard_True if the edge <E> has a new curve on surface on the face <F>.In this case, <C> is the new geometric support of the edge, <L> the new location, <Tol> the new tolerance. Otherwise, returns Standard_False, and <C>, <L>, <Tol> are not significant.", py::arg("E"), py::arg("F"), py::arg("NewE"), py::arg("NewF"), py::arg("C"), py::arg("Tol"));
cls_BRepTools_GTrsfModification.def("NewParameter", [](BRepTools_GTrsfModification &self, const TopoDS_Vertex & V, const TopoDS_Edge & E, Standard_Real & P, Standard_Real & Tol){ Standard_Boolean rv = self.NewParameter(V, E, P, Tol); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, P, Tol); }, "Returns Standard_True if the Vertex <V> has a new parameter on the edge <E>. In this case, <P> is the parameter, <Tol> the new tolerance. Otherwise, returns Standard_False, and <P>, <Tol> are not significant.", py::arg("V"), py::arg("E"), py::arg("P"), py::arg("Tol"));
cls_BRepTools_GTrsfModification.def("Continuity", (GeomAbs_Shape (BRepTools_GTrsfModification::*)(const TopoDS_Edge &, const TopoDS_Face &, const TopoDS_Face &, const TopoDS_Edge &, const TopoDS_Face &, const TopoDS_Face &)) &BRepTools_GTrsfModification::Continuity, "Returns the continuity of <NewE> between <NewF1> and <NewF2>.", py::arg("E"), py::arg("F1"), py::arg("F2"), py::arg("NewE"), py::arg("NewF1"), py::arg("NewF2"));
cls_BRepTools_GTrsfModification.def_static("get_type_name_", (const char * (*)()) &BRepTools_GTrsfModification::get_type_name, "None");
cls_BRepTools_GTrsfModification.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepTools_GTrsfModification::get_type_descriptor, "None");
cls_BRepTools_GTrsfModification.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepTools_GTrsfModification::*)() const) &BRepTools_GTrsfModification::DynamicType, "None");

// Enums

}