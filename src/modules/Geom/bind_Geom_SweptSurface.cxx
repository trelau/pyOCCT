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
#include <GeomAbs_Shape.hxx>
#include <gp_Dir.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Curve.hxx>
#include <Geom_SweptSurface.hxx>
#include <Standard_Type.hxx>

void bind_Geom_SweptSurface(py::module &mod){

py::class_<Geom_SweptSurface, opencascade::handle<Geom_SweptSurface>, Geom_Surface> cls_Geom_SweptSurface(mod, "Geom_SweptSurface", "Describes the common behavior for surfaces constructed by sweeping a curve with another curve. The Geom package provides two concrete derived surfaces: surface of revolution (a revolved surface), and surface of linear extrusion (an extruded surface).");

// Fields

// Methods
cls_Geom_SweptSurface.def("Continuity", (GeomAbs_Shape (Geom_SweptSurface::*)() const) &Geom_SweptSurface::Continuity, "returns the continuity of the surface : C0 : only geometric continuity, C1 : continuity of the first derivative all along the surface, C2 : continuity of the second derivative all along the surface, C3 : continuity of the third derivative all along the surface, G1 : tangency continuity all along the surface, G2 : curvature continuity all along the surface, CN : the order of continuity is infinite.");
cls_Geom_SweptSurface.def("Direction", (const gp_Dir & (Geom_SweptSurface::*)() const) &Geom_SweptSurface::Direction, "Returns the reference direction of the swept surface. For a surface of revolution it is the direction of the revolution axis, for a surface of linear extrusion it is the direction of extrusion.");
cls_Geom_SweptSurface.def("BasisCurve", (opencascade::handle<Geom_Curve> (Geom_SweptSurface::*)() const) &Geom_SweptSurface::BasisCurve, "Returns the referenced curve of the surface. For a surface of revolution it is the revolution curve, for a surface of linear extrusion it is the extruded curve.");
cls_Geom_SweptSurface.def_static("get_type_name_", (const char * (*)()) &Geom_SweptSurface::get_type_name, "None");
cls_Geom_SweptSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Geom_SweptSurface::get_type_descriptor, "None");
cls_Geom_SweptSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (Geom_SweptSurface::*)() const) &Geom_SweptSurface::DynamicType, "None");

// Enums

}