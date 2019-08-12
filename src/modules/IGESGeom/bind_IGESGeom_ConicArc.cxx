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
#include <IGESData_IGESEntity.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_XY.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Pnt.hxx>
#include <gp_Dir.hxx>
#include <Standard_Handle.hxx>
#include <IGESGeom_ConicArc.hxx>
#include <Standard_Type.hxx>

void bind_IGESGeom_ConicArc(py::module &mod){

py::class_<IGESGeom_ConicArc, opencascade::handle<IGESGeom_ConicArc>, IGESData_IGESEntity> cls_IGESGeom_ConicArc(mod, "IGESGeom_ConicArc", "defines IGESConicArc, Type <104> Form <0-3> in package IGESGeom A conic arc is a bounded connected portion of a parent conic curve which consists of more than one point. The parent conic curve is either an ellipse, a parabola, or a hyperbola. The definition space coordinate system is always chosen so that the conic arc lies in a plane either coincident with or parallel to XT, YT plane. Within such a plane a conic is defined by the six coefficients in the following equation. A*XT^2 + B*XT*YT + C*YT^2 + D*XT + E*YT + F = 0");

// Constructors
cls_IGESGeom_ConicArc.def(py::init<>());

// Fields

// Methods
cls_IGESGeom_ConicArc.def("Init", (void (IGESGeom_ConicArc::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const gp_XY &, const gp_XY &)) &IGESGeom_ConicArc::Init, "This method is used to set the fields of the class ConicalArc - A, B, C, D, E, F : Coefficients of the equation defining conic arc - ZT : Parallel ZT displacement of the arc from XT, YT plane. - aStart : Starting point of the conic arc - anEnd : End point of the conic arc", py::arg("A"), py::arg("B"), py::arg("C"), py::arg("D"), py::arg("E"), py::arg("F"), py::arg("ZT"), py::arg("aStart"), py::arg("anEnd"));
cls_IGESGeom_ConicArc.def("OwnCorrect", (Standard_Boolean (IGESGeom_ConicArc::*)()) &IGESGeom_ConicArc::OwnCorrect, "sets the Form Number equal to ComputedFormNumber, returns True if changed");
cls_IGESGeom_ConicArc.def("ComputedFormNumber", (Standard_Integer (IGESGeom_ConicArc::*)() const) &IGESGeom_ConicArc::ComputedFormNumber, "Computes the Form Number according to the equation 1 for Ellipse, 2 for Hyperbola, 3 for Parabola");
cls_IGESGeom_ConicArc.def("Equation", [](IGESGeom_ConicArc &self, Standard_Real & A, Standard_Real & B, Standard_Real & C, Standard_Real & D, Standard_Real & E, Standard_Real & F){ self.Equation(A, B, C, D, E, F); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(A, B, C, D, E, F); }, "None", py::arg("A"), py::arg("B"), py::arg("C"), py::arg("D"), py::arg("E"), py::arg("F"));
cls_IGESGeom_ConicArc.def("ZPlane", (Standard_Real (IGESGeom_ConicArc::*)() const) &IGESGeom_ConicArc::ZPlane, "returns the Z displacement of the arc from XT, YT plane");
cls_IGESGeom_ConicArc.def("StartPoint", (gp_Pnt2d (IGESGeom_ConicArc::*)() const) &IGESGeom_ConicArc::StartPoint, "returns the starting point of the arc");
cls_IGESGeom_ConicArc.def("TransformedStartPoint", (gp_Pnt (IGESGeom_ConicArc::*)() const) &IGESGeom_ConicArc::TransformedStartPoint, "returns the starting point of the arc after applying Transf. Matrix");
cls_IGESGeom_ConicArc.def("EndPoint", (gp_Pnt2d (IGESGeom_ConicArc::*)() const) &IGESGeom_ConicArc::EndPoint, "returns the end point of the arc");
cls_IGESGeom_ConicArc.def("TransformedEndPoint", (gp_Pnt (IGESGeom_ConicArc::*)() const) &IGESGeom_ConicArc::TransformedEndPoint, "returns the end point of the arc after applying Transf. Matrix");
cls_IGESGeom_ConicArc.def("IsFromEllipse", (Standard_Boolean (IGESGeom_ConicArc::*)() const) &IGESGeom_ConicArc::IsFromEllipse, "returns True if parent conic curve is an ellipse");
cls_IGESGeom_ConicArc.def("IsFromParabola", (Standard_Boolean (IGESGeom_ConicArc::*)() const) &IGESGeom_ConicArc::IsFromParabola, "returns True if parent conic curve is a parabola");
cls_IGESGeom_ConicArc.def("IsFromHyperbola", (Standard_Boolean (IGESGeom_ConicArc::*)() const) &IGESGeom_ConicArc::IsFromHyperbola, "returns True if parent conic curve is a hyperbola");
cls_IGESGeom_ConicArc.def("IsClosed", (Standard_Boolean (IGESGeom_ConicArc::*)() const) &IGESGeom_ConicArc::IsClosed, "returns True if StartPoint = EndPoint");
cls_IGESGeom_ConicArc.def("Axis", (gp_Dir (IGESGeom_ConicArc::*)() const) &IGESGeom_ConicArc::Axis, "Z-Axis of conic (i.e. [0,0,1])");
cls_IGESGeom_ConicArc.def("TransformedAxis", (gp_Dir (IGESGeom_ConicArc::*)() const) &IGESGeom_ConicArc::TransformedAxis, "Z-Axis after applying Trans. Matrix");
cls_IGESGeom_ConicArc.def("Definition", [](IGESGeom_ConicArc &self, gp_Pnt & Center, gp_Dir & MainAxis, Standard_Real & rmin, Standard_Real & rmax){ self.Definition(Center, MainAxis, rmin, rmax); return std::tuple<Standard_Real &, Standard_Real &>(rmin, rmax); }, "Returns a Definition computed from equation, easier to use <Center> : the center of the the conic (meaningless for a parabola) (defined with Z displacement) <MainAxis> : the Main Axis of the conic (for a Circle, arbitrary the X Axis) <Rmin,Rmax> : Minor and Major Radii of the conic For a Circle, Rmin = Rmax, For a Parabola, Rmin = Rmax = the Focal Warning : the basic definition (by equation) is not very stable, limit cases may be approximative", py::arg("Center"), py::arg("MainAxis"), py::arg("rmin"), py::arg("rmax"));
cls_IGESGeom_ConicArc.def("TransformedDefinition", [](IGESGeom_ConicArc &self, gp_Pnt & Center, gp_Dir & MainAxis, Standard_Real & rmin, Standard_Real & rmax){ self.TransformedDefinition(Center, MainAxis, rmin, rmax); return std::tuple<Standard_Real &, Standard_Real &>(rmin, rmax); }, "Same as Definition, but the Location is applied on the Center and the MainAxis", py::arg("Center"), py::arg("MainAxis"), py::arg("rmin"), py::arg("rmax"));
cls_IGESGeom_ConicArc.def("ComputedDefinition", [](IGESGeom_ConicArc &self, Standard_Real & Xcen, Standard_Real & Ycen, Standard_Real & Xax, Standard_Real & Yax, Standard_Real & Rmin, Standard_Real & Rmax){ self.ComputedDefinition(Xcen, Ycen, Xax, Yax, Rmin, Rmax); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(Xcen, Ycen, Xax, Yax, Rmin, Rmax); }, "Computes and returns the coordinates of the definition of a comic from its equation. Used by Definition & TransformedDefinition, or may be called directly if needed", py::arg("Xcen"), py::arg("Ycen"), py::arg("Xax"), py::arg("Yax"), py::arg("Rmin"), py::arg("Rmax"));
cls_IGESGeom_ConicArc.def_static("get_type_name_", (const char * (*)()) &IGESGeom_ConicArc::get_type_name, "None");
cls_IGESGeom_ConicArc.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESGeom_ConicArc::get_type_descriptor, "None");
cls_IGESGeom_ConicArc.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESGeom_ConicArc::*)() const) &IGESGeom_ConicArc::DynamicType, "None");

// Enums

}