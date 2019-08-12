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
#include <Standard_Handle.hxx>
#include <Geom_BoundedSurface.hxx>
#include <Standard_Type.hxx>

void bind_Geom_BoundedSurface(py::module &mod){

py::class_<Geom_BoundedSurface, opencascade::handle<Geom_BoundedSurface>, Geom_Surface> cls_Geom_BoundedSurface(mod, "Geom_BoundedSurface", "The root class for bounded surfaces in 3D space. A bounded surface is defined by a rectangle in its 2D parametric space, i.e. - its u parameter, which ranges between two finite values u0 and u1, referred to as 'First u parameter' and 'Last u parameter' respectively, and - its v parameter, which ranges between two finite values v0 and v1, referred to as 'First v parameter' and the 'Last v parameter' respectively. The surface is limited by four curves which are the boundaries of the surface: - its u0 and u1 isoparametric curves in the u parametric direction, and - its v0 and v1 isoparametric curves in the v parametric direction. A bounded surface is finite. The common behavior of all bounded surfaces is described by the Geom_Surface class. The Geom package provides three concrete implementations of bounded surfaces: - Geom_BezierSurface, - Geom_BSplineSurface, and - Geom_RectangularTrimmedSurface. The first two of these implement well known mathematical definitions of complex surfaces, the third trims a surface using four isoparametric curves, i.e. it limits the variation of its parameters to a rectangle in 2D parametric space.");

// Fields

// Methods
cls_Geom_BoundedSurface.def_static("get_type_name_", (const char * (*)()) &Geom_BoundedSurface::get_type_name, "None");
cls_Geom_BoundedSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Geom_BoundedSurface::get_type_descriptor, "None");
cls_Geom_BoundedSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (Geom_BoundedSurface::*)() const) &Geom_BoundedSurface::DynamicType, "None");

// Enums

}