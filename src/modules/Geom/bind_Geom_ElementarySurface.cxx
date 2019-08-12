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
#include <Geom_Surface.hxx>
#include <gp_Ax1.hxx>
#include <gp_Pnt.hxx>
#include <gp_Ax3.hxx>
#include <Standard_TypeDef.hxx>
#include <GeomAbs_Shape.hxx>
#include <Standard_Handle.hxx>
#include <Geom_ElementarySurface.hxx>
#include <Standard_Type.hxx>

void bind_Geom_ElementarySurface(py::module &mod){

py::class_<Geom_ElementarySurface, opencascade::handle<Geom_ElementarySurface>, Geom_Surface> cls_Geom_ElementarySurface(mod, "Geom_ElementarySurface", "Describes the common behavior of surfaces which have a simple parametric equation in a local coordinate system. The Geom package provides several implementations of concrete elementary surfaces: - the plane, and - four simple surfaces of revolution: the cylinder, the cone, the sphere and the torus. An elementary surface inherits the common behavior of Geom_Surface surfaces. Furthermore, it is located in 3D space by a coordinate system (a gp_Ax3 object) which is also its local coordinate system. Any elementary surface is oriented, i.e. the normal vector is always defined, and gives the same orientation to the surface, at any point on the surface. In topology this property is referred to as the 'outside region of the surface'. This orientation is related to the two parametric directions of the surface. Rotation of a surface around the 'main Axis' of its coordinate system, in the trigonometric sense given by the 'X Direction' and the 'Y Direction' of the coordinate system, defines the u parametric direction of that elementary surface of revolution. This is the default construction mode. It is also possible, however, to change the orientation of a surface by reversing one of the two parametric directions: use the UReverse or VReverse functions to change the orientation of the normal at any point on the surface. Warning The local coordinate system of an elementary surface is not necessarily direct: - if it is direct, the trigonometric sense defined by its 'main Direction' is the same as the trigonometric sense defined by its two vectors 'X Direction' and 'Y Direction': 'main Direction' = 'X Direction' ^ 'Y Direction' - if it is indirect, the two definitions of trigonometric sense are opposite: 'main Direction' = - 'X Direction' ^ 'Y Direction'");

// Fields

// Methods
cls_Geom_ElementarySurface.def("SetAxis", (void (Geom_ElementarySurface::*)(const gp_Ax1 &)) &Geom_ElementarySurface::SetAxis, "Changes the main axis (ZAxis) of the elementary surface.", py::arg("A1"));
cls_Geom_ElementarySurface.def("SetLocation", (void (Geom_ElementarySurface::*)(const gp_Pnt &)) &Geom_ElementarySurface::SetLocation, "Changes the location of the local coordinates system of the surface.", py::arg("Loc"));
cls_Geom_ElementarySurface.def("SetPosition", (void (Geom_ElementarySurface::*)(const gp_Ax3 &)) &Geom_ElementarySurface::SetPosition, "Changes the local coordinates system of the surface.", py::arg("A3"));
cls_Geom_ElementarySurface.def("Axis", (gp_Ax1 (Geom_ElementarySurface::*)() const) &Geom_ElementarySurface::Axis, "Returns the main axis of the surface (ZAxis).");
cls_Geom_ElementarySurface.def("Location", (gp_Pnt (Geom_ElementarySurface::*)() const) &Geom_ElementarySurface::Location, "Returns the location point of the local coordinate system of the surface.");
cls_Geom_ElementarySurface.def("Position", (const gp_Ax3 & (Geom_ElementarySurface::*)() const) &Geom_ElementarySurface::Position, "Returns the local coordinates system of the surface.");
cls_Geom_ElementarySurface.def("UReverse", (void (Geom_ElementarySurface::*)()) &Geom_ElementarySurface::UReverse, "Reverses the U parametric direction of the surface.");
cls_Geom_ElementarySurface.def("UReversedParameter", (Standard_Real (Geom_ElementarySurface::*)(const Standard_Real) const) &Geom_ElementarySurface::UReversedParameter, "Return the parameter on the Ureversed surface for the point of parameter U on <me>.", py::arg("U"));
cls_Geom_ElementarySurface.def("VReverse", (void (Geom_ElementarySurface::*)()) &Geom_ElementarySurface::VReverse, "Reverses the V parametric direction of the surface.");
cls_Geom_ElementarySurface.def("VReversedParameter", (Standard_Real (Geom_ElementarySurface::*)(const Standard_Real) const) &Geom_ElementarySurface::VReversedParameter, "Return the parameter on the Vreversed surface for the point of parameter V on <me>.", py::arg("V"));
cls_Geom_ElementarySurface.def("Continuity", (GeomAbs_Shape (Geom_ElementarySurface::*)() const) &Geom_ElementarySurface::Continuity, "Returns GeomAbs_CN, the global continuity of any elementary surface.");
cls_Geom_ElementarySurface.def("IsCNu", (Standard_Boolean (Geom_ElementarySurface::*)(const Standard_Integer) const) &Geom_ElementarySurface::IsCNu, "Returns True.", py::arg("N"));
cls_Geom_ElementarySurface.def("IsCNv", (Standard_Boolean (Geom_ElementarySurface::*)(const Standard_Integer) const) &Geom_ElementarySurface::IsCNv, "Returns True.", py::arg("N"));
cls_Geom_ElementarySurface.def_static("get_type_name_", (const char * (*)()) &Geom_ElementarySurface::get_type_name, "None");
cls_Geom_ElementarySurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Geom_ElementarySurface::get_type_descriptor, "None");
cls_Geom_ElementarySurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (Geom_ElementarySurface::*)() const) &Geom_ElementarySurface::DynamicType, "None");

// Enums

}